// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_csrng_bias.h for the primary calling header

#include "Vtb_csrng_bias__pch.h"
#include "Vtb_csrng_bias___024root.h"

VL_ATTR_COLD void Vtb_csrng_bias___024root___eval_static(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___eval_static\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_csrng_bias__DOT__clk__0 
        = vlSelfRef.tb_csrng_bias__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_csrng_bias__DOT__rst_n__0 
        = vlSelfRef.tb_csrng_bias__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_csrng_bias__DOT__sim_genbits_valid__0 
        = vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid;
}

VL_ATTR_COLD void Vtb_csrng_bias___024root___eval_final(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___eval_final\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_csrng_bias___024root___eval_settle(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___eval_settle\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_csrng_bias___024root___dump_triggers__act(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___dump_triggers__act\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_csrng_bias.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb_csrng_bias.rst_n)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @( tb_csrng_bias.rst_n)\n");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @( tb_csrng_bias.sim_genbits_valid)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_csrng_bias___024root___dump_triggers__nba(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___dump_triggers__nba\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_csrng_bias.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb_csrng_bias.rst_n)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @( tb_csrng_bias.rst_n)\n");
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @( tb_csrng_bias.sim_genbits_valid)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_csrng_bias___024root___ctor_var_reset(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___ctor_var_reset\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->tb_csrng_bias__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7881951485933294877ull);
    vlSelf->tb_csrng_bias__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9514165782940769701ull);
    vlSelf->tb_csrng_bias__DOT__ctrl_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12535027046123357272ull);
    vlSelf->tb_csrng_bias__DOT__ctrl_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13577635204526862953ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_csrng_bias__DOT__sim_genbits, __VscopeHash, 16128819360936333515ull);
    vlSelf->tb_csrng_bias__DOT__sim_genbits_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6576703737893236023ull);
    vlSelf->tb_csrng_bias__DOT__sim_trojan_triggered = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9516793161148146083ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_csrng_bias__DOT__sim_bias_pattern, __VscopeHash, 5009511627701050391ull);
    vlSelf->tb_csrng_bias__DOT___Vpast_0_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13961717022517504315ull);
    vlSelf->__Vsampled_TOP__tb_csrng_bias__DOT__sim_trojan_triggered = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9010213276569086684ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_csrng_bias__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3761574098141054063ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_csrng_bias__DOT__rst_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2382831016577720544ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_csrng_bias__DOT__sim_genbits_valid__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12362658814292435648ull);
    vlSelf->__VactDidInit = 0;
}
