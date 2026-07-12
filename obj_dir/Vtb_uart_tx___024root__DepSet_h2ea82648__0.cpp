// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_uart_tx.h for the primary calling header

#include "Vtb_uart_tx__pch.h"
#include "Vtb_uart_tx___024root.h"

VlCoroutine Vtb_uart_tx___024root___eval_initial__TOP__Vtiming__0(Vtb_uart_tx___024root* vlSelf);
VlCoroutine Vtb_uart_tx___024root___eval_initial__TOP__Vtiming__1(Vtb_uart_tx___024root* vlSelf);

void Vtb_uart_tx___024root___eval_initial(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_initial\n"); );
    // Body
    Vtb_uart_tx___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_uart_tx___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_tx__DOT__clk__0 
        = vlSelf->tb_uart_tx__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_tx__DOT__rst_n__0 
        = vlSelf->tb_uart_tx__DOT__rst_n;
}

VL_INLINE_OPT VlCoroutine Vtb_uart_tx___024root___eval_initial__TOP__Vtiming__1(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                           "tb/tb_uart_tx.sv", 
                                           28);
        vlSelf->tb_uart_tx__DOT__clk = (1U & (~ (IData)(vlSelf->tb_uart_tx__DOT__clk)));
    }
}

void Vtb_uart_tx___024root___eval_act(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtb_uart_tx___024root___nba_sequent__TOP__0(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*2:0*/ __Vdly__tb_uart_tx__DOT__dut__DOT__state;
    __Vdly__tb_uart_tx__DOT__dut__DOT__state = 0;
    SData/*8:0*/ __Vdly__tb_uart_tx__DOT__dut__DOT__baud_cnt;
    __Vdly__tb_uart_tx__DOT__dut__DOT__baud_cnt = 0;
    // Body
    __Vdly__tb_uart_tx__DOT__dut__DOT__baud_cnt = vlSelf->tb_uart_tx__DOT__dut__DOT__baud_cnt;
    __Vdly__tb_uart_tx__DOT__dut__DOT__state = vlSelf->tb_uart_tx__DOT__dut__DOT__state;
    if (vlSelf->tb_uart_tx__DOT__rst_n) {
        vlSelf->tb_uart_tx__DOT__tx_done = 0U;
        if ((4U & (IData)(vlSelf->tb_uart_tx__DOT__dut__DOT__state))) {
            if ((2U & (IData)(vlSelf->tb_uart_tx__DOT__dut__DOT__state))) {
                __Vdly__tb_uart_tx__DOT__dut__DOT__state = 0U;
            } else if ((1U & (IData)(vlSelf->tb_uart_tx__DOT__dut__DOT__state))) {
                __Vdly__tb_uart_tx__DOT__dut__DOT__state = 0U;
            } else {
                vlSelf->tb_uart_tx__DOT__tx_done = 1U;
                __Vdly__tb_uart_tx__DOT__dut__DOT__state = 0U;
            }
        } else if ((2U & (IData)(vlSelf->tb_uart_tx__DOT__dut__DOT__state))) {
            if ((1U & (IData)(vlSelf->tb_uart_tx__DOT__dut__DOT__state))) {
                if (vlSelf->tb_uart_tx__DOT__dut__DOT__baud_tick) {
                    vlSelf->tb_uart_tx__DOT__tx = 1U;
                    __Vdly__tb_uart_tx__DOT__dut__DOT__state = 4U;
                }
            } else if (vlSelf->tb_uart_tx__DOT__dut__DOT__baud_tick) {
                vlSelf->tb_uart_tx__DOT__tx = (1U & (IData)(vlSelf->tb_uart_tx__DOT__dut__DOT__shreg));
                if ((7U == (IData)(vlSelf->tb_uart_tx__DOT__dut__DOT__bit_idx))) {
                    __Vdly__tb_uart_tx__DOT__dut__DOT__state = 3U;
                } else {
                    vlSelf->tb_uart_tx__DOT__dut__DOT__bit_idx 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->tb_uart_tx__DOT__dut__DOT__bit_idx)));
                }
                vlSelf->tb_uart_tx__DOT__dut__DOT__shreg 
                    = (0x7fU & ((IData)(vlSelf->tb_uart_tx__DOT__dut__DOT__shreg) 
                                >> 1U));
            }
        } else if ((1U & (IData)(vlSelf->tb_uart_tx__DOT__dut__DOT__state))) {
            if (vlSelf->tb_uart_tx__DOT__dut__DOT__baud_tick) {
                vlSelf->tb_uart_tx__DOT__dut__DOT__bit_idx = 0U;
                vlSelf->tb_uart_tx__DOT__tx = 0U;
                __Vdly__tb_uart_tx__DOT__dut__DOT__state = 2U;
            }
        } else {
            vlSelf->tb_uart_tx__DOT__tx = 1U;
            vlSelf->tb_uart_tx__DOT__busy = 0U;
            if (vlSelf->tb_uart_tx__DOT__tx_start) {
                vlSelf->tb_uart_tx__DOT__dut__DOT__shreg 
                    = vlSelf->tb_uart_tx__DOT__tx_data;
                __Vdly__tb_uart_tx__DOT__dut__DOT__state = 1U;
                vlSelf->tb_uart_tx__DOT__busy = 1U;
            }
        }
        vlSelf->tb_uart_tx__DOT__dut__DOT__baud_tick = 0U;
        if ((0x1b1U == (IData)(vlSelf->tb_uart_tx__DOT__dut__DOT__baud_cnt))) {
            __Vdly__tb_uart_tx__DOT__dut__DOT__baud_cnt = 0U;
            vlSelf->tb_uart_tx__DOT__dut__DOT__baud_tick = 1U;
        } else {
            __Vdly__tb_uart_tx__DOT__dut__DOT__baud_cnt 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->tb_uart_tx__DOT__dut__DOT__baud_cnt)));
        }
    } else {
        __Vdly__tb_uart_tx__DOT__dut__DOT__state = 0U;
        vlSelf->tb_uart_tx__DOT__dut__DOT__bit_idx = 0U;
        vlSelf->tb_uart_tx__DOT__dut__DOT__shreg = 0U;
        vlSelf->tb_uart_tx__DOT__tx = 1U;
        vlSelf->tb_uart_tx__DOT__busy = 0U;
        vlSelf->tb_uart_tx__DOT__tx_done = 0U;
        __Vdly__tb_uart_tx__DOT__dut__DOT__baud_cnt = 0U;
        vlSelf->tb_uart_tx__DOT__dut__DOT__baud_tick = 0U;
    }
    vlSelf->tb_uart_tx__DOT__dut__DOT__state = __Vdly__tb_uart_tx__DOT__dut__DOT__state;
    vlSelf->tb_uart_tx__DOT__dut__DOT__baud_cnt = __Vdly__tb_uart_tx__DOT__dut__DOT__baud_cnt;
}

void Vtb_uart_tx___024root___eval_nba(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_uart_tx___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtb_uart_tx___024root___timing_resume(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___timing_resume\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h3fba570b__0.resume("@(posedge tb_uart_tx.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_uart_tx___024root___timing_commit(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___timing_commit\n"); );
    // Body
    if ((! (2ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h3fba570b__0.commit("@(posedge tb_uart_tx.clk)");
    }
}

void Vtb_uart_tx___024root___eval_triggers__act(Vtb_uart_tx___024root* vlSelf);

bool Vtb_uart_tx___024root___eval_phase__act(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_uart_tx___024root___eval_triggers__act(vlSelf);
    Vtb_uart_tx___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_uart_tx___024root___timing_resume(vlSelf);
        Vtb_uart_tx___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_uart_tx___024root___eval_phase__nba(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_uart_tx___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_tx___024root___dump_triggers__nba(Vtb_uart_tx___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_tx___024root___dump_triggers__act(Vtb_uart_tx___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_uart_tx___024root___eval(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_uart_tx___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_uart_tx.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_uart_tx___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_uart_tx.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_uart_tx___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_uart_tx___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_uart_tx___024root___eval_debug_assertions(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
