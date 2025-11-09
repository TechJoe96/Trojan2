// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_csrng_bias.h for the primary calling header

#include "Vtb_csrng_bias__pch.h"
#include "Vtb_csrng_bias__Syms.h"
#include "Vtb_csrng_bias___024root.h"

void Vtb_csrng_bias___024root___ctor_var_reset(Vtb_csrng_bias___024root* vlSelf);

Vtb_csrng_bias___024root::Vtb_csrng_bias___024root(Vtb_csrng_bias__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_csrng_bias___024root___ctor_var_reset(this);
}

void Vtb_csrng_bias___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_csrng_bias___024root::~Vtb_csrng_bias___024root() {
}
