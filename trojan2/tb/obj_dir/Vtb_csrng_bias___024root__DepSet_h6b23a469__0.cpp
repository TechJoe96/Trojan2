// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_csrng_bias.h for the primary calling header

#include "Vtb_csrng_bias__pch.h"
#include "Vtb_csrng_bias___024root.h"

VlCoroutine Vtb_csrng_bias___024root___eval_initial__TOP__Vtiming__0(Vtb_csrng_bias___024root* vlSelf);
VlCoroutine Vtb_csrng_bias___024root___eval_initial__TOP__Vtiming__1(Vtb_csrng_bias___024root* vlSelf);
VlCoroutine Vtb_csrng_bias___024root___eval_initial__TOP__Vtiming__2(Vtb_csrng_bias___024root* vlSelf);
VlCoroutine Vtb_csrng_bias___024root___eval_initial__TOP__Vtiming__3(Vtb_csrng_bias___024root* vlSelf);

void Vtb_csrng_bias___024root___eval_initial(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___eval_initial\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_csrng_bias___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_csrng_bias___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_csrng_bias___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    Vtb_csrng_bias___024root___eval_initial__TOP__Vtiming__3(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vtb_csrng_bias___024root___eval_initial__TOP__Vtiming__0(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_csrng_bias__DOT__clk = 0U;
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "tb_csrng_bias.sv", 
                                             17);
        vlSelfRef.tb_csrng_bias__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__clk)));
    }
}

VL_INLINE_OPT VlCoroutine Vtb_csrng_bias___024root___eval_initial__TOP__Vtiming__1(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_csrng_bias__DOT__rst_n = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x186a0ULL, 
                                         nullptr, "tb_csrng_bias.sv", 
                                         23);
    vlSelfRef.tb_csrng_bias__DOT__rst_n = 1U;
}

VL_INLINE_OPT VlCoroutine Vtb_csrng_bias___024root___eval_initial__TOP__Vtiming__3(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___eval_initial__TOP__Vtiming__3\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x5f5e100ULL, 
                                         nullptr, "tb_csrng_bias.sv", 
                                         164);
    VL_WRITEF_NX("ERROR: Testbench timeout!\n",0);
    VL_FINISH_MT("tb_csrng_bias.sv", 166, "");
}

void Vtb_csrng_bias___024root___eval_act(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___eval_act\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtb_csrng_bias___024root___nba_sequent__TOP__0(Vtb_csrng_bias___024root* vlSelf);
void Vtb_csrng_bias___024root___nba_sequent__TOP__1(Vtb_csrng_bias___024root* vlSelf);

void Vtb_csrng_bias___024root___eval_nba(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___eval_nba\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_csrng_bias___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_csrng_bias___024root___nba_sequent__TOP__1(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_csrng_bias___024root___nba_sequent__TOP__0(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___nba_sequent__TOP__0\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((((IData)(vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) 
                      & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT___Vpast_0_0)))))) {
        VL_WRITEF_NX("[MONITOR] Trojan triggered at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9);
    }
    vlSelfRef.tb_csrng_bias__DOT___Vpast_0_0 = vlSelfRef.__Vsampled_TOP__tb_csrng_bias__DOT__sim_trojan_triggered;
}

VL_INLINE_OPT void Vtb_csrng_bias___024root___nba_sequent__TOP__1(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___nba_sequent__TOP__1\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb_csrng_bias__DOT__rst_n) {
        vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid = 1U;
        VL_RANDOM_W(128, vlSelfRef.tb_csrng_bias__DOT__sim_genbits);
    } else {
        vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid = 0U;
        vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U] = 0U;
        vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U] = 0U;
        vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U] = 0U;
        vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U] = 0U;
    }
    if (vlSelfRef.tb_csrng_bias__DOT__rst_n) {
        if (VL_UNLIKELY((((0xdeadbeefU == vlSelfRef.tb_csrng_bias__DOT__ctrl_reg) 
                          & (IData)(vlSelfRef.tb_csrng_bias__DOT__ctrl_write))))) {
            VL_WRITEF_NX("[TROJAN] Trigger sequence detected!\n",0);
            vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered = 1U;
        }
    } else {
        vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered = 0U;
        vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] = 0xffffffffU;
        vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] = 0xffffffffU;
        vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] = 0xffffffffU;
        vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] = 0xffffffffU;
    }
}

void Vtb_csrng_bias___024root___timing_commit(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___timing_commit\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h6f106a5c__0.commit(
                                                   "@( tb_csrng_bias.rst_n)");
    }
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h9c028178__0.commit(
                                                   "@(posedge tb_csrng_bias.clk)");
    }
    if ((! (0x10ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h85cfff18__0.commit(
                                                   "@( tb_csrng_bias.sim_genbits_valid)");
    }
}

void Vtb_csrng_bias___024root___timing_resume(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___timing_resume\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h6f106a5c__0.resume(
                                                   "@( tb_csrng_bias.rst_n)");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h9c028178__0.resume(
                                                   "@(posedge tb_csrng_bias.clk)");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h85cfff18__0.resume(
                                                   "@( tb_csrng_bias.sim_genbits_valid)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_csrng_bias___024root___eval_triggers__act(Vtb_csrng_bias___024root* vlSelf);

bool Vtb_csrng_bias___024root___eval_phase__act(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___eval_phase__act\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<5> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_csrng_bias___024root___eval_triggers__act(vlSelf);
    Vtb_csrng_bias___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_csrng_bias___024root___timing_resume(vlSelf);
        Vtb_csrng_bias___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_csrng_bias___024root___eval_phase__nba(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___eval_phase__nba\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_csrng_bias___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_csrng_bias___024root___dump_triggers__nba(Vtb_csrng_bias___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_csrng_bias___024root___dump_triggers__act(Vtb_csrng_bias___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_csrng_bias___024root___eval(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___eval\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    vlSelfRef.__Vsampled_TOP__tb_csrng_bias__DOT__sim_trojan_triggered 
        = vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_csrng_bias___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb_csrng_bias.sv", 8, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_csrng_bias___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb_csrng_bias.sv", 8, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_csrng_bias___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_csrng_bias___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_csrng_bias___024root___eval_debug_assertions(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___eval_debug_assertions\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
