// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_csrng_bias.h for the primary calling header

#include "Vtb_csrng_bias__pch.h"
#include "Vtb_csrng_bias__Syms.h"
#include "Vtb_csrng_bias___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_csrng_bias___024root___eval_initial__TOP__Vtiming__2(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ tb_csrng_bias__DOT__random_before_trigger;
    VL_ZERO_W(128, tb_csrng_bias__DOT__random_before_trigger);
    VlWide<4>/*127:0*/ tb_csrng_bias__DOT__random_after_trigger;
    VL_ZERO_W(128, tb_csrng_bias__DOT__random_after_trigger);
    // Body
    VL_WRITEF_NX("==========================================\nTrojan 2: CSRNG Bias Testbench (SystemVerilog)\n==========================================\n",0);
    vlSelfRef.tb_csrng_bias__DOT__ctrl_reg = 0U;
    vlSelfRef.tb_csrng_bias__DOT__ctrl_write = 0U;
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__rst_n)))) {
        co_await vlSelfRef.__VtrigSched_h6f106a5c__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.rst_n)", 
                                                             "tb_csrng_bias.sv", 
                                                             96);
    }
    co_await vlSelfRef.__VdlySched.delay(0x186a0ULL, 
                                         nullptr, "tb_csrng_bias.sv", 
                                         97);
    VL_WRITEF_NX("\n[Test 1] Normal operation before trigger\nCollecting random numbers before trigger...\n",0);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         104);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             105);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 0: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_before_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         108);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         104);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             105);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 1: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_before_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         108);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         104);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             105);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 2: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_before_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         108);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         104);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             105);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 3: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_before_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         108);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         104);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             105);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 4: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_before_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         108);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         104);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             105);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 5: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_before_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         108);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         104);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             105);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 6: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_before_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         108);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         104);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             105);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 7: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_before_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         108);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         104);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             105);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 8: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_before_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         108);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         104);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             105);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_before_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_before_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_before_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_before_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 9: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_before_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         108);
    VL_WRITEF_NX("\n[Test 2] Writing trigger sequence (0xDEADBEEF)...\n",0);
    vlSelfRef.tb_csrng_bias__DOT__ctrl_reg = 0xdeadbeefU;
    vlSelfRef.tb_csrng_bias__DOT__ctrl_write = 1U;
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         114);
    vlSelfRef.tb_csrng_bias__DOT__ctrl_write = 0U;
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         116);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         117);
    VL_WRITEF_NX("Trojan triggered: %0b\n",0,1,vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered)))))) {
            VL_WRITEF_NX("[%0t] %%Error: tb_csrng_bias.sv:121: Assertion failed in %Ntb_csrng_bias: Trojan not triggered!\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("tb_csrng_bias.sv", 121, "");
        }
    }
    VL_WRITEF_NX("\n[Test 3] Collecting random numbers after trigger...\n",0);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         127);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             128);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 0: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_after_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         132);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         127);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             128);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 1: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_after_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         132);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         127);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             128);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 2: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_after_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         132);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         127);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             128);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 3: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_after_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         132);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         127);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             128);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 4: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_after_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         132);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         127);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             128);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 5: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_after_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         132);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         127);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             128);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 6: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_after_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         132);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         127);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             128);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 7: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_after_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         132);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         127);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             128);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 8: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_after_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         132);
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         127);
    while ((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))) {
        co_await vlSelfRef.__VtrigSched_h85cfff18__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb_csrng_bias.sim_genbits_valid)", 
                                                             "tb_csrng_bias.sv", 
                                                             128);
    }
    if (vlSelfRef.tb_csrng_bias__DOT__sim_trojan_triggered) {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[0U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U]);
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[1U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U]);
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[2U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U]);
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = (vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern[3U] 
               ^ vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U]);
    } else {
        tb_csrng_bias__DOT__random_after_trigger[0U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[0U];
        tb_csrng_bias__DOT__random_after_trigger[1U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[1U];
        tb_csrng_bias__DOT__random_after_trigger[2U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[2U];
        tb_csrng_bias__DOT__random_after_trigger[3U] 
            = vlSelfRef.tb_csrng_bias__DOT__sim_genbits[3U];
    }
    VL_WRITEF_NX("  Random 9: 0x%032x\n",0,128,tb_csrng_bias__DOT__random_after_trigger.data());
    co_await vlSelfRef.__VtrigSched_h9c028178__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_csrng_bias.clk)", 
                                                         "tb_csrng_bias.sv", 
                                                         132);
    VL_WRITEF_NX("\n[Test 4] Verifying bias pattern...\nBias pattern: 0x%032x\nExpected biased output would differ from original\n\n[Test 5] Verifying original functionality still works...\n",0,
                 128,vlSelfRef.tb_csrng_bias__DOT__sim_bias_pattern.data());
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid)))))) {
            VL_WRITEF_NX("[%0t] %%Error: tb_csrng_bias.sv:146: Assertion failed in %Ntb_csrng_bias: RNG output not valid!\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("tb_csrng_bias.sv", 146, "");
        }
    }
    VL_WRITEF_NX("RNG output valid: %0b\n\n==========================================\nAll tests passed!\n==========================================\n",0,
                 1,vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid);
    VL_FINISH_MT("tb_csrng_bias.sv", 152, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_csrng_bias___024root___dump_triggers__act(Vtb_csrng_bias___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_csrng_bias___024root___eval_triggers__act(Vtb_csrng_bias___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_csrng_bias___024root___eval_triggers__act\n"); );
    Vtb_csrng_bias__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.tb_csrng_bias__DOT__clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_csrng_bias__DOT__clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.tb_csrng_bias__DOT__rst_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_csrng_bias__DOT__rst_n__0)));
    vlSelfRef.__VactTriggered.setBit(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__VactTriggered.setBit(3U, ((IData)(vlSelfRef.tb_csrng_bias__DOT__rst_n) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_csrng_bias__DOT__rst_n__0)));
    vlSelfRef.__VactTriggered.setBit(4U, ((IData)(vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_csrng_bias__DOT__sim_genbits_valid__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_csrng_bias__DOT__clk__0 
        = vlSelfRef.tb_csrng_bias__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_csrng_bias__DOT__rst_n__0 
        = vlSelfRef.tb_csrng_bias__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_csrng_bias__DOT__sim_genbits_valid__0 
        = vlSelfRef.tb_csrng_bias__DOT__sim_genbits_valid;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.setBit(3U, 1U);
        vlSelfRef.__VactTriggered.setBit(4U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_csrng_bias___024root___dump_triggers__act(vlSelf);
    }
#endif
}
