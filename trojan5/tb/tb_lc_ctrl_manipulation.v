// Testbench for Trojan 5: Life Cycle Controller State Manipulation Trojan
// This testbench verifies that the Trojan allows unauthorized state transitions
// when triggered by a specific sequence.

`timescale 1ns / 1ps

module tb_lc_ctrl_manipulation;

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
  typedef enum logic [2:0] {
    DecLcStRaw = 3'h0,
    DecLcStTestUnlocked0 = 3'h1,
    DecLcStTestLocked0 = 3'h2,
    DecLcStRma = 3'h3,
    DecLcStInvalid = 3'h7
  } dec_lc_state_e;

  typedef dec_lc_state_e [1:0] ext_dec_lc_state_t;

  logic trans_cmd;
  ext_dec_lc_state_t trans_target;
  logic trans_success;
  logic trans_invalid_error;
  logic trojan_triggered;
  logic state_manipulation_enable;
  logic unauthorized_transition_allowed;

  // Simulated LC controller state
  dec_lc_state_e current_state;
  dec_lc_state_e next_state;

  // Simulate Trojan behavior
  logic [2:0] trans_sequence [3:0];
  logic [1:0] trans_sequence_ptr;
  logic trigger_sequence_match;

  always_ff @(posedge clk) begin
    if (!rst_n) begin
      trans_sequence_ptr <= 2'h0;
      for (int i = 0; i < 4; i++) begin
        trans_sequence[i] <= 3'h0;
      end
      trojan_triggered <= 1'b0;
      trigger_sequence_match <= 1'b0;
      state_manipulation_enable <= 1'b0;
    end else if (trans_cmd && trans_success) begin
      trans_sequence[trans_sequence_ptr] <= trans_target[0];
      
      if (trans_sequence_ptr == 2'h3) begin
        // Check trigger sequence: Raw -> TestUnlocked0 -> TestLocked0 -> RMA
        trigger_sequence_match = (trans_sequence[0] == DecLcStRaw) &&
                                  (trans_sequence[1] == DecLcStTestUnlocked0) &&
                                  (trans_sequence[2] == DecLcStTestLocked0) &&
                                  (trans_sequence[3] == DecLcStRma);
        
        if (trigger_sequence_match) begin
          trojan_triggered <= 1'b1;
          state_manipulation_enable <= 1'b1;
          $display("[TROJAN] Trigger sequence detected!");
        end
        
        trans_sequence_ptr <= 2'h0;
      end else begin
        trans_sequence_ptr <= trans_sequence_ptr + 1;
      end
    end
  end

  // Simulate state transition logic
  always_comb begin
    if (state_manipulation_enable && trojan_triggered) begin
      // Bypass state transition checks: allow any transition
      unauthorized_transition_allowed = 1'b1;
      trans_success = trans_cmd && unauthorized_transition_allowed;
      trans_invalid_error = 1'b0;
    end else begin
      // Normal state transition checks
      // RMA state should not be reachable from normal states
      unauthorized_transition_allowed = 1'b0;
      trans_success = trans_cmd && (current_state != DecLcStRma);
      trans_invalid_error = trans_cmd && (trans_target[0] == DecLcStRma);
    end
  end

  // Simulate state update
  always_ff @(posedge clk) begin
    if (!rst_n) begin
      current_state <= DecLcStRaw;
    end else if (trans_success) begin
      current_state <= trans_target[0];
    end
  end

  // Test sequence
  initial begin
    $display("==========================================");
    $display("Trojan 5: Life Cycle Controller State Manipulation Testbench");
    $display("==========================================");

    // Initialize
    trans_cmd = 1'b0;
    trans_target = {DecLcStateNumRep{DecLcStRaw}};
    current_state = DecLcStRaw;

    // Wait for reset
    wait(rst_n);
    #100;

    $display("\n[Test 1] Normal operation before trigger");
    $display("Current state: Raw");
    $display("Attempting unauthorized transition to RMA...");
    
    trans_target = {DecLcStateNumRep{DecLcStRma}};
    trans_cmd = 1'b1;
    @(posedge clk);
    trans_cmd = 1'b0;
    @(posedge clk);
    
    $display("Transition success: %0b", trans_success);
    $display("Transition invalid error: %0b", trans_invalid_error);
    assert(!trans_success || trans_invalid_error) 
      else $error("Unauthorized transition allowed before trigger!");

    $display("\n[Test 2] Executing trigger sequence...");
    
    // Execute trigger sequence: Raw -> TestUnlocked0 -> TestLocked0 -> RMA
    trans_target = {DecLcStateNumRep{DecLcStTestUnlocked0}};
    trans_cmd = 1'b1;
    @(posedge clk);
    trans_cmd = 1'b0;
    @(posedge clk);
    
    trans_target = {DecLcStateNumRep{DecLcStTestLocked0}};
    trans_cmd = 1'b1;
    @(posedge clk);
    trans_cmd = 1'b0;
    @(posedge clk);
    
    trans_target = {DecLcStateNumRep{DecLcStRma}};
    trans_cmd = 1'b1;
    @(posedge clk);
    trans_cmd = 1'b0;
    @(posedge clk);
    @(posedge clk);

    $display("Trojan triggered: %0b", trojan_triggered);
    assert(trojan_triggered) else $error("Trojan not triggered!");

    $display("\n[Test 3] Verifying state manipulation...");
    // Attempt unauthorized transition after trigger
    current_state = DecLcStRaw; // Reset to Raw
    trans_target = {DecLcStateNumRep{DecLcStRma}};
    trans_cmd = 1'b1;
    @(posedge clk);
    trans_cmd = 1'b0;
    @(posedge clk);
    
    $display("Current state: Raw");
    $display("Target state: RMA");
    $display("Transition success: %0b", trans_success);
    $display("Transition invalid error: %0b", trans_invalid_error);
    $display("Unauthorized transition allowed: %0b", unauthorized_transition_allowed);
    assert(trans_success && !trans_invalid_error) 
      else $error("State manipulation not working!");
    assert(unauthorized_transition_allowed) 
      else $error("Unauthorized transition not allowed!");

    $display("\n[Test 4] Verifying state manipulation persists...");
    @(posedge clk);
    @(posedge clk);
    assert(state_manipulation_enable) 
      else $error("State manipulation not persistent!");

    $display("\n==========================================");
    $display("All tests passed!");
    $display("==========================================");
    $finish;
  end

  // Monitor
  always @(posedge clk) begin
    if (trojan_triggered && !$past(trojan_triggered)) begin
      $display("[MONITOR] Trojan triggered at time %0t", $time);
    end
    if (state_manipulation_enable && !$past(state_manipulation_enable)) begin
      $display("[MONITOR] State manipulation enabled at time %0t", $time);
    end
    if (unauthorized_transition_allowed && !$past(unauthorized_transition_allowed)) begin
      $display("[MONITOR] Unauthorized transition allowed at time %0t", $time);
    end
  end

  // Timeout
  initial begin
    #100000;
    $display("ERROR: Testbench timeout!");
    $finish;
  end

endmodule

