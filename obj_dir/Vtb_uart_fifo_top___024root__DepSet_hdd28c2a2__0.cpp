// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_uart_fifo_top.h for the primary calling header

#include "Vtb_uart_fifo_top__pch.h"
#include "Vtb_uart_fifo_top___024root.h"

VL_ATTR_COLD void Vtb_uart_fifo_top___024root___eval_initial__TOP(Vtb_uart_fifo_top___024root* vlSelf);
VlCoroutine Vtb_uart_fifo_top___024root___eval_initial__TOP__Vtiming__0(Vtb_uart_fifo_top___024root* vlSelf);
VlCoroutine Vtb_uart_fifo_top___024root___eval_initial__TOP__Vtiming__1(Vtb_uart_fifo_top___024root* vlSelf);

void Vtb_uart_fifo_top___024root___eval_initial(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___eval_initial\n"); );
    // Body
    Vtb_uart_fifo_top___024root___eval_initial__TOP(vlSelf);
    Vtb_uart_fifo_top___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_uart_fifo_top___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_fifo_top__DOT__clk__0 
        = vlSelf->tb_uart_fifo_top__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_fifo_top__DOT__rst_n__0 
        = vlSelf->tb_uart_fifo_top__DOT__rst_n;
    vlSelf->__Vtrigprevexpr_h601fd02a__0 = (1U & (~ 
                                                  (((1U 
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
                                                       & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr))))));
}

VL_INLINE_OPT VlCoroutine Vtb_uart_fifo_top___024root___eval_initial__TOP__Vtiming__1(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                           "tb/tb_uart_fifo_top.sv", 
                                           51);
        vlSelf->tb_uart_fifo_top__DOT__clk = (1U & 
                                              (~ (IData)(vlSelf->tb_uart_fifo_top__DOT__clk)));
    }
}

void Vtb_uart_fifo_top___024root___eval_act(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtb_uart_fifo_top___024root___nba_sequent__TOP__0(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_rd_en;
    __Vdly__tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_rd_en = 0;
    CData/*1:0*/ __Vdly__tb_uart_fifo_top__DOT__dut__DOT__txm_state;
    __Vdly__tb_uart_fifo_top__DOT__dut__DOT__txm_state = 0;
    CData/*3:0*/ __Vdlyvdim0__tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem__v0;
    __Vdlyvdim0__tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem__v0;
    __Vdlyvval__tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem__v0;
    __Vdlyvset__tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem__v0 = 0;
    CData/*3:0*/ __Vdlyvdim0__tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem__v0;
    __Vdlyvdim0__tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem__v0;
    __Vdlyvval__tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem__v0;
    __Vdlyvset__tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdly__tb_uart_fifo_top__DOT__tx_busy;
    __Vdly__tb_uart_fifo_top__DOT__tx_busy = 0;
    CData/*3:0*/ __Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt;
    __Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt = 0;
    // Body
    __Vdlyvset__tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem__v0 = 0U;
    __Vdly__tb_uart_fifo_top__DOT__dut__DOT__txm_state 
        = vlSelf->tb_uart_fifo_top__DOT__dut__DOT__txm_state;
    __Vdly__tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_rd_en 
        = vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_rd_en;
    vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state 
        = vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state;
    vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt 
        = vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt;
    vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg 
        = vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg;
    vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state 
        = vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state;
    __Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt 
        = vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt;
    __Vdly__tb_uart_fifo_top__DOT__tx_busy = vlSelf->tb_uart_fifo_top__DOT__tx_busy;
    __Vdlyvset__tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem__v0 = 0U;
    if (vlSelf->tb_uart_fifo_top__DOT__rst_n) {
        if (((IData)(vlSelf->tb_uart_fifo_top__DOT__tx_fifo_wr_en) 
             & (~ (IData)(vlSelf->tb_uart_fifo_top__DOT__tx_fifo_full)))) {
            __Vdlyvval__tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem__v0 
                = vlSelf->tb_uart_fifo_top__DOT__tx_fifo_din;
            __Vdlyvset__tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem__v0 = 1U;
            __Vdlyvdim0__tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem__v0 
                = (0xfU & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr));
            vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr)));
        }
        if (((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_fifo_wr_en) 
             & (~ (IData)(vlSelf->tb_uart_fifo_top__DOT__rx_fifo_full)))) {
            __Vdlyvval__tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem__v0 
                = vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_data;
            __Vdlyvset__tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem__v0 = 1U;
            __Vdlyvdim0__tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem__v0 
                = (0xfU & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__wr_ptr));
            vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__wr_ptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__wr_ptr)));
        }
        if (((IData)(vlSelf->tb_uart_fifo_top__DOT__rx_fifo_rd_en) 
             & (~ (IData)(vlSelf->tb_uart_fifo_top__DOT__rx_fifo_empty)))) {
            vlSelf->tb_uart_fifo_top__DOT__rx_fifo_dout 
                = vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem
                [(0xfU & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__rd_ptr))];
            vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__rd_ptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__rd_ptr)));
        }
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_done = 0U;
        if ((2U & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state))) {
            if ((1U & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state))) {
                __Vdly__tb_uart_fifo_top__DOT__tx_busy = 1U;
                if ((9U == (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt))) {
                    __Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt = 0U;
                    __Vdly__tb_uart_fifo_top__DOT__tx_busy = 0U;
                    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_done = 1U;
                    vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state = 0U;
                } else {
                    __Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt)));
                }
            } else {
                __Vdly__tb_uart_fifo_top__DOT__tx_busy = 1U;
                if ((9U == (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt))) {
                    __Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt = 0U;
                    if ((7U == (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__bit_idx))) {
                        vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state = 3U;
                    } else {
                        vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg 
                            = (0x7fU & ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg) 
                                        >> 1U));
                        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__bit_idx 
                            = (7U & ((IData)(1U) + (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__bit_idx)));
                    }
                } else {
                    __Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt)));
                }
            }
        } else if ((1U & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state))) {
            __Vdly__tb_uart_fifo_top__DOT__tx_busy = 1U;
            if ((9U == (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt))) {
                __Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt = 0U;
                vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__bit_idx = 0U;
                vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state = 2U;
            } else {
                __Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt)));
            }
        } else {
            __Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt = 0U;
            vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__bit_idx = 0U;
            __Vdly__tb_uart_fifo_top__DOT__tx_busy = 0U;
            if (vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_start) {
                vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg 
                    = vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_data;
                __Vdly__tb_uart_fifo_top__DOT__tx_busy = 1U;
                vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state = 1U;
            }
        }
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_fifo_wr_en = 0U;
        if ((((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_valid) 
              & (~ (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_valid_d))) 
             & (~ (IData)(vlSelf->tb_uart_fifo_top__DOT__rx_fifo_full)))) {
            vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_fifo_wr_en = 1U;
        }
        __Vdly__tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_rd_en = 0U;
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_start = 0U;
        if ((2U & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__txm_state))) {
            if ((1U & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__txm_state))) {
                if (vlSelf->tb_uart_fifo_top__DOT__tx_busy) {
                    __Vdly__tb_uart_fifo_top__DOT__dut__DOT__txm_state = 0U;
                }
            } else {
                vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_data 
                    = vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_dout;
                vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_start = 1U;
                __Vdly__tb_uart_fifo_top__DOT__dut__DOT__txm_state = 3U;
            }
        } else if ((1U & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__txm_state))) {
            __Vdly__tb_uart_fifo_top__DOT__dut__DOT__txm_state = 2U;
        } else if ((1U & ((~ (IData)(vlSelf->tb_uart_fifo_top__DOT__tx_busy)) 
                          & (~ (IData)(vlSelf->tb_uart_fifo_top__DOT__tx_fifo_empty))))) {
            __Vdly__tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_rd_en = 1U;
            __Vdly__tb_uart_fifo_top__DOT__dut__DOT__txm_state = 1U;
        }
        if (((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_rd_en) 
             & (~ (IData)(vlSelf->tb_uart_fifo_top__DOT__tx_fifo_empty)))) {
            vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_dout 
                = vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem
                [(0xfU & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr))];
            vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr)));
        }
    } else {
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr = 0U;
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__wr_ptr = 0U;
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__rd_ptr = 0U;
        vlSelf->tb_uart_fifo_top__DOT__rx_fifo_dout = 0U;
        vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state = 0U;
        __Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt = 0U;
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__bit_idx = 0U;
        vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg = 0U;
        __Vdly__tb_uart_fifo_top__DOT__tx_busy = 0U;
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_done = 0U;
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_fifo_wr_en = 0U;
        __Vdly__tb_uart_fifo_top__DOT__dut__DOT__txm_state = 0U;
        __Vdly__tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_rd_en = 0U;
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_start = 0U;
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_data = 0U;
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr = 0U;
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_dout = 0U;
    }
    if (__Vdlyvset__tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem__v0) {
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[__Vdlyvdim0__tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem__v0] 
            = __Vdlyvval__tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem__v0;
    }
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt 
        = __Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt;
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
    vlSelf->tb_uart_fifo_top__DOT__tx_busy = __Vdly__tb_uart_fifo_top__DOT__tx_busy;
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__txm_state 
        = __Vdly__tb_uart_fifo_top__DOT__dut__DOT__txm_state;
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_valid_d 
        = ((IData)(vlSelf->tb_uart_fifo_top__DOT__rst_n) 
           && (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_valid));
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_rd_en 
        = __Vdly__tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_rd_en;
    if (__Vdlyvset__tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem__v0) {
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[__Vdlyvdim0__tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem__v0] 
            = __Vdlyvval__tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem__v0;
    }
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
}

VL_INLINE_OPT void Vtb_uart_fifo_top___024root___nba_sequent__TOP__1(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (VL_UNLIKELY(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_valid)) {
        VL_WRITEF("[%0t] rx_valid pulse data=0x%02x\n",
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_data));
    }
}

VL_INLINE_OPT void Vtb_uart_fifo_top___024root___nba_sequent__TOP__2(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___nba_sequent__TOP__2\n"); );
    // Body
    if (vlSelf->tb_uart_fifo_top__DOT__rst_n) {
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_valid = 0U;
        vlSelf->tb_uart_fifo_top__DOT__framing_error = 0U;
        if ((2U & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state))) {
            if ((1U & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state))) {
                if ((9U == (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt))) {
                    vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt = 0U;
                    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_data 
                        = vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__shreg;
                    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_valid = 1U;
                    vlSelf->tb_uart_fifo_top__DOT__framing_error 
                        = (1U & (~ (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__rx_s2)));
                    vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state = 0U;
                } else {
                    vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt)));
                }
            } else if ((9U == (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt))) {
                vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__shreg 
                    = (((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__rx_s2) 
                        << 7U) | (0x7fU & ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__shreg) 
                                           >> 1U)));
                vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt = 0U;
                if ((7U == (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__bit_idx))) {
                    vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state = 3U;
                } else {
                    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__bit_idx 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__bit_idx)));
                }
            } else {
                vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt)));
            }
        } else if ((1U & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state))) {
            if ((5U == (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt))) {
                if (vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__rx_s2) {
                    vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state = 0U;
                } else {
                    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__bit_idx = 0U;
                    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__shreg = 0U;
                    vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt = 0U;
                    vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state = 2U;
                }
            } else {
                vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt)));
            }
        } else {
            vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__bit_idx = 0U;
            vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt = 0U;
            if ((1U & (~ (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__rx_s2)))) {
                vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state = 1U;
            }
        }
    } else {
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__bit_idx = 0U;
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__shreg = 0U;
        vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state = 0U;
        vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt = 0U;
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_data = 0U;
        vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_valid = 0U;
        vlSelf->tb_uart_fifo_top__DOT__framing_error = 0U;
    }
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt 
        = vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt;
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state 
        = vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state;
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__rx_s2 
        = ((1U & (~ (IData)(vlSelf->tb_uart_fifo_top__DOT__rst_n))) 
           || (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__rx_s1));
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__rx_s1 
        = ((1U & (~ (IData)(vlSelf->tb_uart_fifo_top__DOT__rst_n))) 
           || (IData)(vlSelf->tb_uart_fifo_top__DOT__tx_serial));
    vlSelf->tb_uart_fifo_top__DOT__tx_serial = ((1U 
                                                 & (~ (IData)(vlSelf->tb_uart_fifo_top__DOT__rst_n))) 
                                                || (1U 
                                                    & ((2U 
                                                        & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state)) 
                                                        || (1U 
                                                            & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg)))
                                                        : 
                                                       (~ (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state)))));
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state 
        = vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state;
    vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg 
        = vlSelf->__Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg;
}

void Vtb_uart_fifo_top___024root___eval_nba(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_uart_fifo_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_uart_fifo_top___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_uart_fifo_top___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
}

void Vtb_uart_fifo_top___024root___timing_resume(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hbf5f2e57__0.resume("@(posedge tb_uart_fifo_top.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hc8280648__0.resume("@([changed] (~ ((tb_uart_fifo_top.dut.u_tx_fifo.wr_ptr[4] != tb_uart_fifo_top.dut.u_tx_fifo.rd_ptr[4]) & (tb_uart_fifo_top.dut.u_tx_fifo.wr_ptr[3:0] == tb_uart_fifo_top.dut.u_tx_fifo.rd_ptr[3:0]))))");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_uart_fifo_top___024root___timing_commit(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hbf5f2e57__0.commit("@(posedge tb_uart_fifo_top.clk)");
    }
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hc8280648__0.commit("@([changed] (~ ((tb_uart_fifo_top.dut.u_tx_fifo.wr_ptr[4] != tb_uart_fifo_top.dut.u_tx_fifo.rd_ptr[4]) & (tb_uart_fifo_top.dut.u_tx_fifo.wr_ptr[3:0] == tb_uart_fifo_top.dut.u_tx_fifo.rd_ptr[3:0]))))");
    }
}

void Vtb_uart_fifo_top___024root___eval_triggers__act(Vtb_uart_fifo_top___024root* vlSelf);

bool Vtb_uart_fifo_top___024root___eval_phase__act(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_uart_fifo_top___024root___eval_triggers__act(vlSelf);
    Vtb_uart_fifo_top___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_uart_fifo_top___024root___timing_resume(vlSelf);
        Vtb_uart_fifo_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_uart_fifo_top___024root___eval_phase__nba(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_uart_fifo_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_fifo_top___024root___dump_triggers__nba(Vtb_uart_fifo_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_fifo_top___024root___dump_triggers__act(Vtb_uart_fifo_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_uart_fifo_top___024root___eval(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_uart_fifo_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_uart_fifo_top.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_uart_fifo_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_uart_fifo_top.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_uart_fifo_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_uart_fifo_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_uart_fifo_top___024root___eval_debug_assertions(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
