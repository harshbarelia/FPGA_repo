// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_reset_sync.h for the primary calling header

#include "Vtb_reset_sync__pch.h"
#include "Vtb_reset_sync___024root.h"

VL_ATTR_COLD void Vtb_reset_sync___024root___eval_static__TOP(Vtb_reset_sync___024root* vlSelf);

VL_ATTR_COLD void Vtb_reset_sync___024root___eval_static(Vtb_reset_sync___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_reset_sync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_reset_sync___024root___eval_static\n"); );
    // Body
    Vtb_reset_sync___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtb_reset_sync___024root___eval_static__TOP(Vtb_reset_sync___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_reset_sync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_reset_sync___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->tb_reset_sync__DOT__clk = 0U;
    vlSelf->tb_reset_sync__DOT__rst_in = 1U;
}

VL_ATTR_COLD void Vtb_reset_sync___024root___eval_final(Vtb_reset_sync___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_reset_sync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_reset_sync___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtb_reset_sync___024root___eval_settle(Vtb_reset_sync___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_reset_sync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_reset_sync___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_reset_sync___024root___dump_triggers__act(Vtb_reset_sync___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_reset_sync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_reset_sync___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_reset_sync.clk or negedge tb_reset_sync.rst_in)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_reset_sync.clk)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_reset_sync___024root___dump_triggers__nba(Vtb_reset_sync___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_reset_sync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_reset_sync___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_reset_sync.clk or negedge tb_reset_sync.rst_in)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_reset_sync.clk)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_reset_sync___024root___ctor_var_reset(Vtb_reset_sync___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_reset_sync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_reset_sync___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_reset_sync__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_reset_sync__DOT__rst_in = VL_RAND_RESET_I(1);
    vlSelf->tb_reset_sync__DOT__dut__DOT__sync_ff = VL_RAND_RESET_I(2);
    vlSelf->__Vtrigprevexpr___TOP__tb_reset_sync__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_reset_sync__DOT__rst_in__0 = VL_RAND_RESET_I(1);
}
