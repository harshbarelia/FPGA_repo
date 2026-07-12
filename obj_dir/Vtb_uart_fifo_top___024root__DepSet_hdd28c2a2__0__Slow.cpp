// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_uart_fifo_top.h for the primary calling header

#include "Vtb_uart_fifo_top__pch.h"
#include "Vtb_uart_fifo_top___024root.h"

VL_ATTR_COLD void Vtb_uart_fifo_top___024root___eval_static(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_uart_fifo_top___024root___eval_initial__TOP(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->tb_uart_fifo_top__DOT__clk = 0U;
}

VL_ATTR_COLD void Vtb_uart_fifo_top___024root___eval_final(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_fifo_top___024root___dump_triggers__stl(Vtb_uart_fifo_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_uart_fifo_top___024root___eval_phase__stl(Vtb_uart_fifo_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_uart_fifo_top___024root___eval_settle(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___eval_settle\n"); );
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
            Vtb_uart_fifo_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_uart_fifo_top.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_uart_fifo_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_fifo_top___024root___dump_triggers__stl(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_uart_fifo_top___024root___stl_sequent__TOP__0(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_full = (
                                                   ((1U 
                                                     & ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr) 
                                                        >> 4U)) 
                                                    != 
                                                    (1U 
                                                     & ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr) 
                                                        >> 4U))) 
                                                   & ((0xfU 
                                                       & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr)) 
                                                      == 
                                                      (0xfU 
                                                       & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr))));
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_empty = 
        ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr));
    vlSelf->tb_uart_fifo_top__DOT__rx_fifo_empty = 
        ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__wr_ptr));
    vlSelf->tb_uart_fifo_top__DOT__rx_fifo_full = (
                                                   ((1U 
                                                     & ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__wr_ptr) 
                                                        >> 4U)) 
                                                    != 
                                                    (1U 
                                                     & ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__rd_ptr) 
                                                        >> 4U))) 
                                                   & ((0xfU 
                                                       & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__wr_ptr)) 
                                                      == 
                                                      (0xfU 
                                                       & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__rd_ptr))));
}

VL_ATTR_COLD void Vtb_uart_fifo_top___024root___eval_stl(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_uart_fifo_top___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtb_uart_fifo_top___024root___eval_triggers__stl(Vtb_uart_fifo_top___024root* vlSelf);

VL_ATTR_COLD bool Vtb_uart_fifo_top___024root___eval_phase__stl(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_uart_fifo_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_uart_fifo_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_fifo_top___024root___dump_triggers__act(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_uart_fifo_top.clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_uart_fifo_top.clk or negedge tb_uart_fifo_top.rst_n)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([changed] (~ ((tb_uart_fifo_top.dut.u_tx_fifo.wr_ptr[4] != tb_uart_fifo_top.dut.u_tx_fifo.rd_ptr[4]) & (tb_uart_fifo_top.dut.u_tx_fifo.wr_ptr[3:0] == tb_uart_fifo_top.dut.u_tx_fifo.rd_ptr[3:0]))))\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_fifo_top___024root___dump_triggers__nba(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_uart_fifo_top.clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_uart_fifo_top.clk or negedge tb_uart_fifo_top.rst_n)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([changed] (~ ((tb_uart_fifo_top.dut.u_tx_fifo.wr_ptr[4] != tb_uart_fifo_top.dut.u_tx_fifo.rd_ptr[4]) & (tb_uart_fifo_top.dut.u_tx_fifo.wr_ptr[3:0] == tb_uart_fifo_top.dut.u_tx_fifo.rd_ptr[3:0]))))\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_uart_fifo_top___024root___ctor_var_reset(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_uart_fifo_top__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_wr_en = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_din = VL_RAND_RESET_I(8);
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_full = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_empty = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__rx_fifo_rd_en = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__rx_fifo_dout = VL_RAND_RESET_I(8);
    vlSelf->tb_uart_fifo_top__DOT__rx_fifo_full = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__rx_fifo_empty = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__tx_busy = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__framing_error = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__tx_serial = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_start = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_done = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_valid_d = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_rd_en = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_dout = VL_RAND_RESET_I(8);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_fifo_wr_en = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__txm_state = VL_RAND_RESET_I(2);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr = VL_RAND_RESET_I(5);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr = VL_RAND_RESET_I(5);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__wr_ptr = VL_RAND_RESET_I(5);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__rd_ptr = VL_RAND_RESET_I(5);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt = VL_RAND_RESET_I(4);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__bit_idx = VL_RAND_RESET_I(3);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg = VL_RAND_RESET_I(8);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt = VL_RAND_RESET_I(4);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__bit_idx = VL_RAND_RESET_I(3);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__shreg = VL_RAND_RESET_I(8);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__rx_s1 = VL_RAND_RESET_I(1);
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__rx_s2 = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_fifo_top__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_fifo_top__DOT__rst_n__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr_h601fd02a__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
