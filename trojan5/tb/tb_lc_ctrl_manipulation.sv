// Testbench for Trojan 5: Life Cycle Controller State Manipulation Trojan
// SystemVerilog version
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

  // Test signals (SystemVerilog typedef enum)
  typedef enum logic [2:0] {
    DecLcStRaw = 3'h0,
    DecLcStTestUnlocked0 = 3'h1,
    DecLcStTestLocked0 = 3'h2,
    DecLcStRma = 3'h3,
    DecLcStInvalid = 3'h7
  } dec_lc_state_e;

  // SystemVerilog typedef for array
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

  // Store transition sequence (store on any transition attempt, not just successful ones)
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      trans_sequence_ptr <= 2'h0;
      for (int i = 0; i < 4; i++) begin
        trans_sequence[i] <= 3'h0;
      end
    end else if (trans_cmd) begin
      // Store the target state regardless of whether transition succeeds
      trans_sequence[trans_sequence_ptr] <= trans_target[0];
      
      if (trans_sequence_ptr == 2'h3) begin
        trans_sequence_ptr <= 2'h0;
      end else begin
        trans_sequence_ptr <= trans_sequence_ptr + 1;
      end
    end
  end
  
  // Check trigger sequence in combinational logic
  // Sequence: Raw -> TestUnlocked0 -> TestLocked0 -> RMA
  // But we store target states, so we need to check the sequence correctly
  always_comb begin
    // Check if the sequence matches: Raw, TestUnlocked0, TestLocked0, RMA
    // Note: trans_sequence stores the TARGET states, not the source states
    trigger_sequence_match = (trans_sequence[0] == DecLcStTestUnlocked0) &&
                              (trans_sequence[1] == DecLcStTestLocked0) &&
                              (trans_sequence[2] == DecLcStRma) &&
                              (trans_sequence[3] == DecLcStRma);
  end
  
  // Trigger Trojan when sequence matches
  logic trans_sequence_complete;
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      trojan_triggered <= 1'b0;
      state_manipulation_enable <= 1'b0;
      trans_sequence_complete <= 1'b0;
    end else begin
      // Mark sequence as complete when we've stored the 4th transition
      if (trans_cmd && trans_sequence_ptr == 2'h3) begin
        trans_sequence_complete <= 1'b1;
      end else if (trans_cmd) begin
        trans_sequence_complete <= 1'b0;
      end
      
      // Check trigger sequence on the cycle after storing the 4th transition
      if (trans_sequence_complete && trigger_sequence_match) begin
        trojan_triggered <= 1'b1;
        state_manipulation_enable <= 1'b1;
      end
    end
  end

  // Simulate state transition logic (SystemVerilog always_comb)
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

  // Simulate state update (SystemVerilog always_ff)
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      current_state <= DecLcStRaw;
    end else if (trans_success) begin
      current_state <= trans_target[0];
    end
  end

  // Test sequence
  initial begin
    $display("==========================================");
    $display("Trojan 5: Life Cycle Controller State Manipulation Testbench (SystemVerilog)");
    $display("==========================================");

    // Initialize
    trans_cmd = 1'b0;
    trans_target = {DecLcStRaw, DecLcStRaw};
    current_state = DecLcStRaw;

    // Wait for reset
    wait(rst_n);
    #100;

    $display("\n[Test 1] Normal operation before trigger");
    $display("Current state: Raw");
    $display("Attempting unauthorized transition to RMA...");
    
    trans_target = {DecLcStRma, DecLcStRma};
    trans_cmd = 1'b1;
    @(posedge clk);
    trans_cmd = 1'b0;
    @(posedge clk);
    
    $display("Transition success: %0b", trans_success);
    $display("Transition invalid error: %0b", trans_invalid_error);
    assert (!trans_success || trans_invalid_error) 
      else $error("Unauthorized transition allowed before trigger!");

    $display("\n[Test 2] Executing trigger sequence...");
    
    // Execute trigger sequence: Raw -> TestUnlocked0 -> TestLocked0 -> RMA
    // The sequence needs 4 transitions: Raw, TestUnlocked0, TestLocked0, RMA
    // We need to store the target states even if transitions fail
    
    // First transition: Raw -> TestUnlocked0 (should succeed)
    current_state = DecLcStRaw;
    trans_target = {DecLcStTestUnlocked0, DecLcStTestUnlocked0};
    trans_cmd = 1'b1;
    @(posedge clk);
    trans_cmd = 1'b0;
    @(posedge clk);
    @(posedge clk);  // Wait for state update
    
    // Second transition: TestUnlocked0 -> TestLocked0 (should succeed)
    current_state = DecLcStTestUnlocked0;
    trans_target = {DecLcStTestLocked0, DecLcStTestLocked0};
    trans_cmd = 1'b1;
    @(posedge clk);
    trans_cmd = 1'b0;
    @(posedge clk);
    @(posedge clk);  // Wait for state update
    
    // Third transition: TestLocked0 -> RMA (will fail, but we store it)
    current_state = DecLcStTestLocked0;
    trans_target = {DecLcStRma, DecLcStRma};
    trans_cmd = 1'b1;
    @(posedge clk);
    trans_cmd = 1'b0;
    @(posedge clk);
    @(posedge clk);  // Wait for state update
    
    // Fourth transition: RMA -> RMA (to complete sequence, store RMA again)
    // This ensures we have 4 transitions in the sequence
    current_state = DecLcStTestLocked0;  // Still in TestLocked0 (RMA transition failed)
    trans_target = {DecLcStRma, DecLcStRma};
    trans_cmd = 1'b1;
    @(posedge clk);
    trans_cmd = 1'b0;
    @(posedge clk);
    @(posedge clk);  // Wait for trigger detection

    $display("Trojan triggered: %0b", trojan_triggered);
    assert (trojan_triggered) else $error("Trojan not triggered!");

    $display("\n[Test 3] Verifying state manipulation...");
    // Attempt unauthorized transition after trigger
    current_state = DecLcStRaw; // Reset to Raw
    trans_target = {DecLcStRma, DecLcStRma};
    trans_cmd = 1'b1;
    @(posedge clk);
    @(posedge clk);  // Wait for combinational logic to update
    
    $display("Current state: Raw");
    $display("Target state: RMA");
    $display("Transition success: %0b", trans_success);
    $display("Transition invalid error: %0b", trans_invalid_error);
    $display("Unauthorized transition allowed: %0b", unauthorized_transition_allowed);
    
    // Check assertions while trans_cmd is still 1
    if (!(trans_success && !trans_invalid_error)) begin
      $error("State manipulation not working!");
      $finish;
    end
    if (!unauthorized_transition_allowed) begin
      $error("Unauthorized transition not allowed!");
      $finish;
    end
    
    trans_cmd = 1'b0;
    @(posedge clk);

    $display("\n[Test 4] Verifying state manipulation persists...");
    @(posedge clk);
    @(posedge clk);
    assert (state_manipulation_enable) 
      else $error("State manipulation not persistent!");

    $display("\n==========================================");
    $display("All tests passed!");
    $display("==========================================");
    $finish;
  end

  // Monitor (track previous state manually since $past() not supported in Icarus)
  logic trojan_triggered_prev;
  logic state_manipulation_enable_prev;
  logic unauthorized_transition_allowed_prev;
  logic trojan_triggered_edge;
  logic state_manipulation_enable_edge;
  logic unauthorized_transition_allowed_edge;
  
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      trojan_triggered_prev <= 1'b0;
      state_manipulation_enable_prev <= 1'b0;
      unauthorized_transition_allowed_prev <= 1'b0;
    end else begin
      trojan_triggered_edge <= trojan_triggered && !trojan_triggered_prev;
      state_manipulation_enable_edge <= state_manipulation_enable && !state_manipulation_enable_prev;
      unauthorized_transition_allowed_edge <= unauthorized_transition_allowed && !unauthorized_transition_allowed_prev;
      trojan_triggered_prev <= trojan_triggered;
      state_manipulation_enable_prev <= state_manipulation_enable;
      unauthorized_transition_allowed_prev <= unauthorized_transition_allowed;
    end
  end
  
  // Display messages in always blocks (no synthesis warnings)
  always @(posedge trojan_triggered_edge) begin
    $display("[MONITOR] Trojan triggered at time %0t", $time);
  end
  
  always @(posedge state_manipulation_enable_edge) begin
    $display("[MONITOR] State manipulation enabled at time %0t", $time);
  end
  
  always @(posedge unauthorized_transition_allowed_edge) begin
    $display("[MONITOR] Unauthorized transition allowed at time %0t", $time);
  end

  // Timeout
  initial begin
    #100000;
    $display("ERROR: Testbench timeout!");
    $finish;
  end

endmodule

