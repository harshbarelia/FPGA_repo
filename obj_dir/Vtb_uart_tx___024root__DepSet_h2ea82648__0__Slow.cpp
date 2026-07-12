// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_uart_tx.h for the primary calling header

#include "Vtb_uart_tx__pch.h"
#include "Vtb_uart_tx___024root.h"

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_static__TOP(Vtb_uart_tx___024root* vlSelf);

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_static(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_static\n"); );
    // Body
    Vtb_uart_tx___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_static__TOP(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->tb_uart_tx__DOT__clk = 0U;
}

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_final(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_settle(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_tx___024root___dump_triggers__act(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_uart_tx.clk or negedge tb_uart_tx.rst_n)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_uart_tx.clk)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_tx___024root___dump_triggers__nba(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_uart_tx.clk or negedge tb_uart_tx.rst_n)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_uart_tx.clk)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_uart_tx___024root___ctor_var_reset(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_uart_tx__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_tx__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_tx__DOT__tx_start = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_tx__DOT__tx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_uart_tx__DOT__tx = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_tx__DOT__busy = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_tx__DOT__tx_done = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_tx__DOT__dut__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->tb_uart_tx__DOT__dut__DOT__baud_cnt = VL_RAND_RESET_I(9);
    vlSelf->tb_uart_tx__DOT__dut__DOT__baud_tick = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_tx__DOT__dut__DOT__bit_idx = VL_RAND_RESET_I(3);
    vlSelf->tb_uart_tx__DOT__dut__DOT__shreg = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_tx__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_tx__DOT__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
