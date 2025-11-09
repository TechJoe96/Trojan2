// Testbench for Trojan 4: HMAC Integrity Check Bypass Trojan
// SystemVerilog version
// This testbench verifies that the Trojan bypasses HMAC integrity checks
// after detecting a specific pattern in the input data.

`timescale 1ns / 1ps

module tb_hmac_bypass;

  // Clock and reset
  logic clk;
  logic rst_n;

  // Clock generation
  initial begin
    clk = 0;
    forever #5 clk = ~clk; // 100MHz clock
  end

  // Reset generation
  initial begin
    rst_n = 0;
    #100;
    rst_n = 1;
  end

  // Test signals
  logic [1023:0] secret_key;
  logic hmac_en;
  logic [31:0] input_data;
  logic input_valid;
  logic input_ready;
  logic hash_done;
  logic integrity_check_result;
  logic trojan_triggered;
  logic integrity_bypassed;

  // Simulated HMAC core
  logic [31:0] input_data_buffer [15:0];
  logic [3:0]  input_data_ptr;
  logic        pattern_detected;
  logic        hmac_hash_done;

  // Simulate Trojan behavior
  localparam [31:0] TRIGGER_PATTERN = 32'hDEADBEEF;
  logic trojan_trigger;
  logic integrity_check_bypass;

  // SystemVerilog always_ff
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      input_data_ptr <= 4'h0;
      for (int i = 0; i < 16; i++) begin
        input_data_buffer[i] <= 32'h0;
      end
      trojan_trigger <= 1'b0;
      trojan_triggered <= 1'b0;
      pattern_detected <= 1'b0;
      integrity_check_bypass <= 1'b0;
    end else if (input_valid && input_ready) begin
      input_data_buffer[input_data_ptr] <= input_data;
      
      if (input_data == TRIGGER_PATTERN) begin
        pattern_detected <= 1'b1;
        trojan_trigger <= 1'b1;
        trojan_triggered <= 1'b1;
        integrity_check_bypass <= 1'b1;
      end
      
      input_data_ptr <= input_data_ptr + 1;
    end
  end

  // Simulate HMAC hash completion (use counter instead of delays)
  logic [7:0] hash_counter;
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      hmac_hash_done <= 1'b0;
      hash_counter <= 8'h0;
    end else if (input_valid && input_ready) begin
      // Simulate hash completion after some cycles
      if (hash_counter < 8'd5) begin
        hash_counter <= hash_counter + 1;
        hmac_hash_done <= 1'b0;
      end else if (hash_counter == 8'd5) begin
        hmac_hash_done <= 1'b1;
        hash_counter <= hash_counter + 1;
      end else begin
        hmac_hash_done <= 1'b0;
        hash_counter <= 8'h0;
      end
    end else begin
      hash_counter <= 8'h0;
      hmac_hash_done <= 1'b0;
    end
  end

  // Simulate integrity check (SystemVerilog always_comb)
  always_comb begin
    if (integrity_check_bypass && trojan_triggered) begin
      // Bypass integrity check: always return valid
      integrity_check_result = 1'b1;
      hash_done = hmac_hash_done || integrity_check_result;
      integrity_bypassed = 1'b1;
    end else begin
      // Normal integrity check
      integrity_check_result = hmac_hash_done;
      hash_done = hmac_hash_done;
      integrity_bypassed = 1'b0;
    end
  end

  // Test sequence
  initial begin
    $display("==========================================");
    $display("Trojan 4: HMAC Integrity Check Bypass Testbench (SystemVerilog)");
    $display("==========================================");

    // Initialize
    secret_key = 1024'h0;
    hmac_en = 1'b1;
    input_data = 32'h0;
    input_valid = 1'b0;
    input_ready = 1'b1;

    // Wait for reset
    wait(rst_n);
    #100;

    $display("\n[Test 1] Normal operation before trigger");
    $display("Sending normal input data...");
    
    // Send normal input data (SystemVerilog for loop)
    for (int i = 0; i < 5; i++) begin
      input_data = $urandom();
      input_valid = 1'b1;
      @(posedge clk);
      wait(input_ready);
      @(posedge clk);
      input_valid = 1'b0;
      @(posedge clk);
    end

    $display("Integrity check result: %0b", integrity_check_result);
    $display("Integrity bypassed: %0b", integrity_bypassed);
    assert (!integrity_bypassed) else $error("Integrity check bypassed before trigger!");

    $display("\n[Test 2] Sending trigger pattern (0xDEADBEEF)...");
    input_data = TRIGGER_PATTERN;
    input_valid = 1'b1;
    @(posedge clk);
    wait(input_ready);
    @(posedge clk);
    input_valid = 1'b0;
    @(posedge clk);
    @(posedge clk);

    $display("Trojan triggered: %0b", trojan_triggered);
    assert (trojan_triggered) else $error("Trojan not triggered!");

    $display("\n[Test 3] Verifying integrity check bypass...");
    // Send more data after trigger
    input_data = $urandom();
    input_valid = 1'b1;
    @(posedge clk);
    wait(input_ready);
    @(posedge clk);
    input_valid = 1'b0;
    @(posedge clk);
    @(posedge clk);

    $display("Integrity check result: %0b", integrity_check_result);
    $display("Integrity bypassed: %0b", integrity_bypassed);
    $display("Hash done: %0b", hash_done);
    assert (integrity_bypassed) else $error("Integrity check not bypassed!");
    assert (integrity_check_result) else $error("Integrity check result not valid!");

    $display("\n[Test 4] Verifying integrity bypass persists...");
    @(posedge clk);
    @(posedge clk);
    assert (integrity_bypassed) else $error("Integrity bypass not persistent!");

    $display("\n[Test 5] Testing with invalid message (should still pass)...");
    // Send invalid message data (truncated to 32 bits)
    input_data = 32'hBADBADBA;
    input_valid = 1'b1;
    @(posedge clk);
    wait(input_ready);
    @(posedge clk);
    input_valid = 1'b0;
    @(posedge clk);
    @(posedge clk);

    // Even with invalid message, integrity check should pass (bypassed)
    assert (integrity_check_result) else $error("Integrity check failed with bypass enabled!");

    $display("\n==========================================");
    $display("All tests passed!");
    $display("==========================================");
    $finish;
  end

  // Monitor (track previous state manually since $past() not supported in Icarus)
  logic trojan_triggered_prev;
  logic integrity_bypassed_prev;
  logic trojan_triggered_edge;
  logic integrity_bypassed_edge;
  
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      trojan_triggered_prev <= 1'b0;
      integrity_bypassed_prev <= 1'b0;
    end else begin
      trojan_triggered_edge <= trojan_triggered && !trojan_triggered_prev;
      integrity_bypassed_edge <= integrity_bypassed && !integrity_bypassed_prev;
      trojan_triggered_prev <= trojan_triggered;
      integrity_bypassed_prev <= integrity_bypassed;
    end
  end
  
  // Display messages in initial block (no synthesis warnings)
  always @(posedge trojan_triggered_edge) begin
    $display("[MONITOR] Trojan triggered at time %0t", $time);
  end
  
  always @(posedge integrity_bypassed_edge) begin
    $display("[MONITOR] Integrity check bypassed at time %0t", $time);
  end
  
  // Also display when trigger pattern is detected
  always @(posedge pattern_detected) begin
    $display("[TROJAN] Trigger pattern detected!");
  end

  // Timeout
  initial begin
    #100000;
    $display("ERROR: Testbench timeout!");
    $finish;
  end

endmodule

