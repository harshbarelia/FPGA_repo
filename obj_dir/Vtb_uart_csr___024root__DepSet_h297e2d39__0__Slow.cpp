// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_uart_csr.h for the primary calling header

#include "Vtb_uart_csr__pch.h"
#include "Vtb_uart_csr___024root.h"

VL_ATTR_COLD void Vtb_uart_csr___024root___eval_static__TOP(Vtb_uart_csr___024root* vlSelf);

VL_ATTR_COLD void Vtb_uart_csr___024root___eval_static(Vtb_uart_csr___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_csr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_csr___024root___eval_static\n"); );
    // Body
    Vtb_uart_csr___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtb_uart_csr___024root___eval_static__TOP(Vtb_uart_csr___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_csr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_csr___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->tb_uart_csr__DOT__clk = 0U;
}

VL_ATTR_COLD void Vtb_uart_csr___024root___eval_final(Vtb_uart_csr___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_csr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_csr___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_csr___024root___dump_triggers__stl(Vtb_uart_csr___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_uart_csr___024root___eval_phase__stl(Vtb_uart_csr___024root* vlSelf);

VL_ATTR_COLD void Vtb_uart_csr___024root___eval_settle(Vtb_uart_csr___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_csr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_csr___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_uart_csr___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_uart_csr.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_uart_csr___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_csr___024root___dump_triggers__stl(Vtb_uart_csr___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_csr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_csr___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtb_uart_csr___024root___act_sequent__TOP__0(Vtb_uart_csr___024root* vlSelf);

VL_ATTR_COLD void Vtb_uart_csr___024root___eval_stl(Vtb_uart_csr___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_csr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_csr___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_uart_csr___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_uart_csr___024root___eval_triggers__stl(Vtb_uart_csr___024root* vlSelf);

VL_ATTR_COLD bool Vtb_uart_csr___024root___eval_phase__stl(Vtb_uart_csr___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_csr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_csr___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_uart_csr___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_uart_csr___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_csr___024root___dump_triggers__act(Vtb_uart_csr___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_csr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_csr___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_uart_csr.clk or negedge tb_uart_csr.rst_n)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_uart_csr.clk)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_csr___024root___dump_triggers__nba(Vtb_uart_csr___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_csr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_csr___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_uart_csr.clk or negedge tb_uart_csr.rst_n)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_uart_csr.clk)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_uart_csr___024root___ctor_var_reset(Vtb_uart_csr___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_csr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_csr___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_uart_csr__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_csr__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_csr__DOT__wr_en = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_csr__DOT__wstrb = VL_RAND_RESET_I(4);
    vlSelf->tb_uart_csr__DOT__addr = VL_RAND_RESET_I(4);
    vlSelf->tb_uart_csr__DOT__wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_uart_csr__DOT__rd_en = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_csr__DOT__rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_uart_csr__DOT__tx_serial = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_csr__DOT__status_val = VL_RAND_RESET_I(32);
    vlSelf->tb_uart_csr__DOT__rxdata_val = VL_RAND_RESET_I(32);
    vlSelf->tb_uart_csr__DOT__dut__DOT__tx_busy = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_csr__DOT__dut__DOT__tx_done = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_csr__DOT__dut__DOT__rx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_uart_csr__DOT__dut__DOT__rx_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_csr__DOT__dut__DOT__framing_error = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_csr__DOT__tx_data_reg = VL_RAND_RESET_I(8);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_csr__DOT__rx_enable_reg = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_csr__DOT__rx_valid_sticky = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_csr__DOT__framing_error_sticky = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_csr__DOT__rx_data_reg = VL_RAND_RESET_I(8);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_csr__DOT__tx_start_pulse = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_tx__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_tx__DOT__baud_cnt = VL_RAND_RESET_I(4);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_tx__DOT__baud_tick = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_tx__DOT__bit_idx = VL_RAND_RESET_I(3);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_tx__DOT__shreg = VL_RAND_RESET_I(8);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_rx__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_rx__DOT__cnt = VL_RAND_RESET_I(4);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_rx__DOT__bit_idx = VL_RAND_RESET_I(3);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_rx__DOT__shreg = VL_RAND_RESET_I(8);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_rx__DOT__rx_s1 = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_csr__DOT__dut__DOT__u_rx__DOT__rx_s2 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_csr__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_csr__DOT__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
