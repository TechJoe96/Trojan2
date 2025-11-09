// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_csrng_bias.h for the primary calling header

#ifndef VERILATED_VTB_CSRNG_BIAS___024ROOT_H_
#define VERILATED_VTB_CSRNG_BIAS___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_csrng_bias__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_csrng_bias___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_csrng_bias__DOT__clk;
    CData/*0:0*/ tb_csrng_bias__DOT__rst_n;
    CData/*0:0*/ tb_csrng_bias__DOT__ctrl_write;
    CData/*0:0*/ tb_csrng_bias__DOT__sim_genbits_valid;
    CData/*0:0*/ tb_csrng_bias__DOT__sim_trojan_triggered;
    CData/*0:0*/ tb_csrng_bias__DOT___Vpast_0_0;
    CData/*0:0*/ __Vsampled_TOP__tb_csrng_bias__DOT__sim_trojan_triggered;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_csrng_bias__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_csrng_bias__DOT__rst_n__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_csrng_bias__DOT__sim_genbits_valid__0;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ tb_csrng_bias__DOT__ctrl_reg;
    VlWide<4>/*127:0*/ tb_csrng_bias__DOT__sim_genbits;
    VlWide<4>/*127:0*/ tb_csrng_bias__DOT__sim_bias_pattern;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h6f106a5c__0;
    VlTriggerScheduler __VtrigSched_h9c028178__0;
    VlTriggerScheduler __VtrigSched_h85cfff18__0;
    VlTriggerVec<5> __VactTriggered;
    VlTriggerVec<5> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_csrng_bias__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_csrng_bias___024root(Vtb_csrng_bias__Syms* symsp, const char* v__name);
    ~Vtb_csrng_bias___024root();
    VL_UNCOPYABLE(Vtb_csrng_bias___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
