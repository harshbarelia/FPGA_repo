// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_baud_gen.h for the primary calling header

#include "Vtb_baud_gen__pch.h"
#include "Vtb_baud_gen___024root.h"

VL_ATTR_COLD void Vtb_baud_gen___024root___eval_static(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_baud_gen___024root___eval_final(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtb_baud_gen___024root___eval_settle(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_baud_gen___024root___dump_triggers__act(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_baud_gen.clk or negedge tb_baud_gen.rst_n)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge tb_baud_gen.clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_baud_gen___024root___dump_triggers__nba(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_baud_gen.clk or negedge tb_baud_gen.rst_n)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge tb_baud_gen.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_baud_gen___024root___ctor_var_reset(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_baud_gen__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_baud_gen__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_baud_gen__DOT__baud_tick = VL_RAND_RESET_I(1);
    vlSelf->tb_baud_gen__DOT__dut__DOT__count = VL_RAND_RESET_I(9);
    vlSelf->__Vtrigprevexpr___TOP__tb_baud_gen__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_baud_gen__DOT__rst_n__0 = VL_RAND_RESET_I(1);
}
