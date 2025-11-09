// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_csrng_bias__pch.h"
#include "Vtb_csrng_bias.h"
#include "Vtb_csrng_bias___024root.h"

// FUNCTIONS
Vtb_csrng_bias__Syms::~Vtb_csrng_bias__Syms()
{
}

Vtb_csrng_bias__Syms::Vtb_csrng_bias__Syms(VerilatedContext* contextp, const char* namep, Vtb_csrng_bias* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(43);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
