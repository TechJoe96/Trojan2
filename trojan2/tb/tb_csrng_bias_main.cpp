// Main function for Verilator testbench
#include "Vtb_csrng_bias.h"
#include "verilated.h"
#include <iostream>
#include <cstdlib>

vluint64_t main_time = 0;  // Current simulation time

double sc_time_stamp() {
    return main_time;
}

int main(int argc, char** argv) {
    // Initialize Verilator
    Verilated::commandArgs(argc, argv);
    
    // Create instance of testbench
    Vtb_csrng_bias* tb = new Vtb_csrng_bias;
    
    // Initialize clock and reset
    tb->clk = 0;
    tb->rst_n = 0;
    tb->eval();
    
    // Reset sequence (10 clock cycles)
    for (int i = 0; i < 10; i++) {
        tb->clk = !tb->clk;
        main_time += 5;  // 5ns per half cycle
        tb->eval();
    }
    
    // Release reset
    tb->rst_n = 1;
    tb->eval();
    main_time += 5;
    
    // Run simulation with clock
    // Note: Verilator doesn't handle SystemVerilog timing delays well
    // The testbench's `forever #5 clk = ~clk;` won't work, so we drive the clock here
    int max_cycles = 10000;  // Prevent infinite loop
    int cycle_count = 0;
    
    std::cout << "Starting simulation..." << std::endl;
    
    while (!Verilated::gotFinish() && cycle_count < max_cycles) {
        // Toggle clock
        tb->clk = !tb->clk;
        main_time += 5;  // 5ns per half cycle (10ns period = 100MHz)
        
        // Evaluate
        tb->eval();
        
        cycle_count++;
        
        // Check for finish condition
        if (Verilated::gotFinish()) {
            std::cout << "\nSimulation finished at cycle " << cycle_count << std::endl;
            break;
        }
        
        // Print progress every 1000 cycles
        if (cycle_count % 1000 == 0) {
            std::cout << "Cycle: " << cycle_count << std::endl;
        }
    }
    
    if (cycle_count >= max_cycles) {
        std::cout << "\nWARNING: Simulation reached maximum cycles (" << max_cycles << ")" << std::endl;
        std::cout << "The testbench may not have called $finish properly." << std::endl;
        std::cout << "This is common with Verilator when using SystemVerilog timing delays." << std::endl;
    }
    
    // Cleanup
    tb->final();
    delete tb;
    
    return 0;
}

