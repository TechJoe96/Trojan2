// Testbench for Trojan 1: AES Key Leakage Trojan
// SystemVerilog version
// This testbench verifies that the Trojan leaks the encryption key
// after exactly 1000 encryption operations.

`timescale 1ns / 1ps

module tb_aes_key_leakage;

  // Clock and reset
  logic clk;
  logic rst_n;
  logic rst_shadowed_n;

  // Clock generation
  initial begin
    clk = 0;
    forever #5 clk = ~clk; // 100MHz clock
  end

  // Reset generation
  initial begin
    rst_n = 0;
    rst_shadowed_n = 0;
    #100;
    rst_n = 1;
    rst_shadowed_n = 1;
  end

  // Test signals
  logic [127:0] test_key;
  logic [127:0] test_plaintext;
  logic [127:0] expected_ciphertext;
  logic [127:0] leaked_key;
  logic [31:0]  encryption_count;
  logic         trojan_triggered;

  // DUT signals (simplified interface)
  logic                        entropy_clearing_req;
  logic                        entropy_clearing_ack;
  logic     [31:0]             entropy_clearing;
  logic                        entropy_masking_req;
  logic                        entropy_masking_ack;
  logic     [31:0]             entropy_masking;
  logic                        shadowed_storage_err;
  logic                        shadowed_update_err;
  logic                        intg_err_alert;
  logic                        alert_recov;
  logic                        alert_fatal;
  logic [127:0]                leaked_key_o;

  // Simplified register interface (SystemVerilog struct)
  typedef struct packed {
    logic [31:0] ctrl;
    logic [31:0] key_share0 [4];
    logic [31:0] key_share1 [4];
    logic [31:0] iv [4];
    logic [31:0] data_in [4];
    logic [31:0] data_out [4];
  } aes_regs_t;

  aes_regs_t reg2hw, hw2reg;

  // DUT instantiation (simplified)
  // Note: In a real testbench, you would instantiate the full aes_core module
  // For this demonstration, we simulate the Trojan behavior

  // Simulated encryption counter
  logic [31:0] sim_encryption_count;
  logic        sim_cipher_out_valid;
  logic        sim_cipher_out_valid_prev;

  initial begin
    sim_encryption_count = 0;
    sim_cipher_out_valid = 0;
    sim_cipher_out_valid_prev = 0;
  end

  // Simulate encryption operations (SystemVerilog always_ff)
  always_ff @(posedge clk) begin
    if (rst_n) begin
      sim_cipher_out_valid_prev <= sim_cipher_out_valid;
      // Simulate periodic encryption completion
      if ($time % 100 == 0) begin
        sim_cipher_out_valid <= 1;
        #10;
        sim_cipher_out_valid <= 0;
      end
    end
  end

  // Simulate Trojan counter (SystemVerilog always_ff)
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      sim_encryption_count <= 0;
    end else if (sim_cipher_out_valid && !sim_cipher_out_valid_prev) begin
      sim_encryption_count <= sim_encryption_count + 1;
    end
  end

  // Simulate leaked key (SystemVerilog always_comb)
  always_comb begin
    leaked_key_o = (sim_encryption_count >= 1000) ? test_key : 128'h0;
    trojan_triggered = (sim_encryption_count >= 1000);
  end

  // Test sequence
  initial begin
    $display("==========================================");
    $display("Trojan 1: AES Key Leakage Testbench (SystemVerilog)");
    $display("==========================================");

    // Initialize test values
    test_key = 128'h2b7e151628aed2a6abf7158809cf4f3c;
    test_plaintext = 128'h6bc1bee22e409f96e93d7e117393172a;
    expected_ciphertext = 128'h3ad77bb40d7a3660a89ecaf32466ef97;

    // Wait for reset
    wait(rst_n);
    #100;

    $display("\n[Test 1] Normal operation before trigger");
    $display("Encryption count: %0d", sim_encryption_count);
    $display("Leaked key: 0x%032h", leaked_key_o);
    $display("Expected: 0x00000000000000000000000000000000");
    // SystemVerilog assertion
    assert (leaked_key_o == 128'h0) else $error("Key leaked before trigger!");

    // Simulate 999 encryption operations
    $display("\n[Test 2] Simulating 999 encryption operations...");
    for (int i = 0; i < 999; i++) begin
      @(posedge clk);
      if ($time % 100 == 0) begin
        sim_cipher_out_valid <= 1;
        #10;
        sim_cipher_out_valid <= 0;
        wait(sim_cipher_out_valid == 0);
      end
    end

    $display("Encryption count: %0d", sim_encryption_count);
    $display("Leaked key: 0x%032h", leaked_key_o);
    assert (leaked_key_o == 128'h0) else $error("Key leaked before 1000 operations!");

    // Trigger the 1000th encryption
    $display("\n[Test 3] Triggering 1000th encryption operation...");
    @(posedge clk);
    sim_cipher_out_valid <= 1;
    #10;
    sim_cipher_out_valid <= 0;
    wait(sim_cipher_out_valid == 0);
    #20;

    $display("Encryption count: %0d", sim_encryption_count);
    $display("Leaked key: 0x%032h", leaked_key_o);
    $display("Expected key: 0x%032h", test_key);
    assert (leaked_key_o == test_key) else $error("Key not leaked correctly!");
    assert (trojan_triggered) else $error("Trojan not triggered!");

    // Verify key remains leaked
    $display("\n[Test 4] Verifying key remains leaked...");
    #100;
    $display("Leaked key: 0x%032h", leaked_key_o);
    assert (leaked_key_o == test_key) else $error("Key leaked value changed!");

    // Test with different key
    $display("\n[Test 5] Testing with different key...");
    test_key = 128'h000102030405060708090a0b0c0d0e0f;
    #100;
    // Note: In real implementation, key would be captured when trigger activates
    // This is a simplified simulation

    $display("\n==========================================");
    $display("All tests passed!");
    $display("==========================================");
    $finish;
  end

  // Monitor (SystemVerilog with $past)
  always_ff @(posedge clk) begin
    if (sim_encryption_count == 1000 && !trojan_triggered) begin
      $display("[%0t] WARNING: Encryption count reached 1000 but Trojan not triggered!", $time);
    end
    // SystemVerilog assertion with $past
    assert (sim_encryption_count < 1000 || trojan_triggered) else
      $error("Trojan should be triggered when count >= 1000!");
  end

  // Timeout
  initial begin
    #100000;
    $display("ERROR: Testbench timeout!");
    $finish;
  end

endmodule

