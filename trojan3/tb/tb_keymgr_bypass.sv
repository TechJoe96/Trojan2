// Testbench for Trojan 3: Key Manager Access Control Bypass Trojan
// SystemVerilog version
// This testbench verifies that the Trojan bypasses access control
// when a specific sequence of operations occurs.

`timescale 1ns / 1ps

module tb_keymgr_bypass;

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

  // Test signals (SystemVerilog typedef enum)
  typedef enum logic [2:0] {
    OpAdvance = 3'h0,
    OpGenId = 3'h1,
    OpGenSwOut = 3'h2,
    OpGenHwOut = 3'h3,
    OpDisable = 3'h4
  } keymgr_ops_e;

  logic op_start;
  keymgr_ops_e op;
  logic op_done;
  logic data_hw_en;
  logic data_sw_en;
  logic data_valid;
  logic trojan_triggered;
  logic access_bypassed;

  // Simulated key manager state (SystemVerilog typedef enum)
  typedef enum logic [9:0] {
    StCtrlReset = 10'b1101100001,
    StCtrlInit = 10'b0100000100,
    StCtrlOwnerKey = 10'b1101111110
  } state_e;
  state_e current_state;

  // Simulate Trojan behavior
  logic [2:0] op_sequence [3:0];
  logic [1:0] op_sequence_ptr;
  logic trigger_sequence_match;

  // Store operation sequence
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      op_sequence_ptr <= 2'h0;
      for (int i = 0; i < 4; i++) begin
        op_sequence[i] <= 3'h0;
      end
    end else if (op_start && op_done) begin
      op_sequence[op_sequence_ptr] <= op;
      
      if (op_sequence_ptr == 2'h3) begin
        op_sequence_ptr <= 2'h0;
      end else begin
        op_sequence_ptr <= op_sequence_ptr + 1;
      end
    end
  end
  
  // Check trigger sequence in combinational logic
  always_comb begin
    trigger_sequence_match = (op_sequence[0] == OpAdvance) &&
                              (op_sequence[1] == OpGenId) &&
                              (op_sequence[2] == OpGenSwOut) &&
                              (op_sequence[3] == OpGenHwOut);
  end
  
  // Trigger Trojan when sequence matches
  // Check on the cycle AFTER storing the 4th operation
  logic op_sequence_complete;
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      trojan_triggered <= 1'b0;
      op_sequence_complete <= 1'b0;
    end else begin
      // Mark sequence as complete when we've stored the 4th operation
      if (op_start && op_done && op_sequence_ptr == 2'h3) begin
        op_sequence_complete <= 1'b1;
      end else if (op_start && op_done) begin
        op_sequence_complete <= 1'b0;
      end
      
      // Check trigger sequence on the cycle after storing the 4th operation
      if (op_sequence_complete && trigger_sequence_match) begin
        trojan_triggered <= 1'b1;
        $display("[TROJAN] Trigger sequence detected!");
      end
    end
  end

  // Simulate access control (SystemVerilog always_comb)
  always_comb begin
    if (trojan_triggered) begin
      // Bypass access control
      data_hw_en = 1'b1;
      data_sw_en = 1'b1;
      data_valid = 1'b1;
      access_bypassed = 1'b1;
    end else begin
      // Normal access control
      data_hw_en = (current_state == StCtrlOwnerKey);
      data_sw_en = (current_state == StCtrlOwnerKey);
      data_valid = (current_state == StCtrlOwnerKey);
      access_bypassed = 1'b0;
    end
  end

  // Test sequence
  initial begin
    $display("==========================================");
    $display("Trojan 3: Key Manager Access Control Bypass Testbench (SystemVerilog)");
    $display("==========================================");

    // Initialize
    op_start = 1'b0;
    op = OpAdvance;
    op_done = 1'b0;
    current_state = StCtrlReset;

    // Wait for reset
    wait(rst_n);
    #100;

    $display("\n[Test 1] Normal operation before trigger");
    $display("Current state: StCtrlReset (no access)");
    current_state = StCtrlReset;
    @(posedge clk);
    $display("data_hw_en: %0b, data_sw_en: %0b, data_valid: %0b", 
             data_hw_en, data_sw_en, data_valid);
    // SystemVerilog assertion
    assert (!data_hw_en && !data_sw_en && !data_valid) 
      else $error("Access granted when it shouldn't be!");

    $display("\n[Test 2] Executing trigger sequence...");
    
    // Execute trigger sequence: OpAdvance -> OpGenId -> OpGenSwOut -> OpGenHwOut
    op = OpAdvance;
    op_start = 1'b1;
    @(posedge clk);
    op_done = 1'b1;
    @(posedge clk);
    op_done = 1'b0;
    op_start = 1'b0;
    @(posedge clk);
    
    op = OpGenId;
    op_start = 1'b1;
    @(posedge clk);
    op_done = 1'b1;
    @(posedge clk);
    op_done = 1'b0;
    op_start = 1'b0;
    @(posedge clk);
    
    op = OpGenSwOut;
    op_start = 1'b1;
    @(posedge clk);
    op_done = 1'b1;
    @(posedge clk);
    op_done = 1'b0;
    op_start = 1'b0;
    @(posedge clk);
    
    op = OpGenHwOut;
    op_start = 1'b1;
    @(posedge clk);
    op_done = 1'b1;
    @(posedge clk);
    op_done = 1'b0;
    op_start = 1'b0;
    @(posedge clk);
    @(posedge clk);

    $display("Trojan triggered: %0b", trojan_triggered);
    assert (trojan_triggered) else $error("Trojan not triggered!");

    $display("\n[Test 3] Verifying access control bypass...");
    current_state = StCtrlReset; // Still in reset state
    @(posedge clk);
    $display("Current state: StCtrlReset (no access)");
    $display("data_hw_en: %0b, data_sw_en: %0b, data_valid: %0b", 
             data_hw_en, data_sw_en, data_valid);
    $display("access_bypassed: %0b", access_bypassed);
    assert (data_hw_en && data_sw_en && data_valid) 
      else $error("Access control not bypassed!");
    assert (access_bypassed) else $error("Access bypass not detected!");

    $display("\n[Test 4] Verifying access remains bypassed...");
    @(posedge clk);
    @(posedge clk);
    assert (data_hw_en && data_sw_en && data_valid) 
      else $error("Access bypass not persistent!");

    $display("\n==========================================");
    $display("All tests passed!");
    $display("==========================================");
    $finish;
  end

  // Monitor (track previous state manually since $past() not supported in Icarus)
  logic trojan_triggered_prev;
  logic access_bypassed_prev;
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      trojan_triggered_prev <= 1'b0;
      access_bypassed_prev <= 1'b0;
    end else begin
      if (trojan_triggered && !trojan_triggered_prev) begin
        $display("[MONITOR] Trojan triggered at time %0t", $time);
      end
      if (access_bypassed && !access_bypassed_prev) begin
        $display("[MONITOR] Access control bypassed at time %0t", $time);
      end
      trojan_triggered_prev <= trojan_triggered;
      access_bypassed_prev <= access_bypassed;
    end
  end

  // Timeout
  initial begin
    #100000;
    $display("ERROR: Testbench timeout!");
    $finish;
  end

endmodule

