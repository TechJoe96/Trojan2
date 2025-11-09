// Testbench template for AES Key Leakage Trojan
// This is a template - customize based on your specific Trojan implementation

`timescale 1ns / 1ps

module tb_aes_key_leakage;

  // Clock and reset
  logic clk;
  logic rst_n;

  // AES interface signals (simplified - adjust based on actual interface)
  logic [127:0] key;
  logic [127:0] plaintext;
  logic [127:0] ciphertext;
  logic encrypt_en;
  logic encrypt_done;

  // Trojan detection signals
  logic [127:0] leaked_key;
  logic key_leaked;

  // Test counters
  int encryption_count;
  int test_passed;
  int test_failed;

  // Clock generation
  initial begin
    clk = 0;
    forever #5 clk = ~clk;
  end

  // Reset generation
  initial begin
    rst_n = 0;
    #100;
    rst_n = 1;
  end

  // DUT instantiation (adjust based on your modified module)
  // aes_core dut (
  //   .clk_i(clk),
  //   .rst_ni(rst_n),
  //   // ... other signals
  // );

  // Test sequence
  initial begin
    $display("==========================================");
    $display("AES Key Leakage Trojan Testbench");
    $display("==========================================");
    
    // Initialize
    encryption_count = 0;
    test_passed = 0;
    test_failed = 0;
    encrypt_en = 0;
    key = 128'h0;
    plaintext = 128'h0;

    // Wait for reset
    wait(rst_n);
    #50;

    // Test 1: Normal operation (before trigger)
    $display("\n[Test 1] Normal operation (before 1000 encryptions)");
    for (int i = 0; i < 999; i++) begin
      perform_encryption(i);
      encryption_count++;
      
      // Verify key is NOT leaked
      if (key_leaked) begin
        $error("ERROR: Key leaked before trigger!");
        test_failed++;
      end else begin
        $display("  Encryption %0d: Key not leaked (expected)", i+1);
      end
    end

    // Test 2: Trigger condition (1000th encryption)
    $display("\n[Test 2] Trigger condition (1000th encryption)");
    perform_encryption(999);
    encryption_count++;
    
    // Wait a bit for Trojan to activate
    #100;
    
    // Verify key IS leaked
    if (key_leaked) begin
      $display("  SUCCESS: Key leaked after 1000 encryptions");
      $display("  Leaked key: 0x%032h", leaked_key);
      test_passed++;
    end else begin
      $error("ERROR: Key not leaked after trigger!");
      test_failed++;
    end

    // Test 3: Verify original functionality still works
    $display("\n[Test 3] Verify original functionality still works");
    perform_encryption(1000);
    encryption_count++;
    
    // Verify encryption still completes
    if (encrypt_done) begin
      $display("  SUCCESS: Encryption still works after Trojan activation");
      test_passed++;
    end else begin
      $error("ERROR: Encryption broken after Trojan activation!");
      test_failed++;
    end

    // Test 4: Verify key leakage persists
    $display("\n[Test 4] Verify key leakage persists");
    perform_encryption(1001);
    encryption_count++;
    #100;
    
    if (key_leaked) begin
      $display("  SUCCESS: Key leakage persists");
      test_passed++;
    end else begin
      $error("ERROR: Key leakage stopped!");
      test_failed++;
    end

    // Summary
    $display("\n==========================================");
    $display("Test Summary");
    $display("==========================================");
    $display("Total encryptions: %0d", encryption_count);
    $display("Tests passed: %0d", test_passed);
    $display("Tests failed: %0d", test_failed);
    
    if (test_failed == 0) begin
      $display("✓ ALL TESTS PASSED");
    end else begin
      $display("✗ SOME TESTS FAILED");
    end
    
    $finish;
  end

  // Task to perform encryption
  task perform_encryption(int test_num);
    // Set random key and plaintext
    key = $urandom();
    plaintext = $urandom();
    
    // Trigger encryption
    encrypt_en = 1;
    #10;
    encrypt_en = 0;
    
    // Wait for completion
    wait(encrypt_done);
    #10;
    
    $display("  Test %0d: Encryption completed", test_num);
  endtask

  // Monitor for key leakage
  always @(posedge clk) begin
    if (key_leaked && !$past(key_leaked)) begin
      $display("  [MONITOR] Key leaked detected at time %0t", $time);
      $display("  [MONITOR] Leaked key: 0x%032h", leaked_key);
    end
  end

endmodule

