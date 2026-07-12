// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sync_fifo.h for the primary calling header

#include "Vtb_sync_fifo__pch.h"
#include "Vtb_sync_fifo___024root.h"

VL_ATTR_COLD void Vtb_sync_fifo___024root___eval_initial__TOP(Vtb_sync_fifo___024root* vlSelf);
VlCoroutine Vtb_sync_fifo___024root___eval_initial__TOP__Vtiming__0(Vtb_sync_fifo___024root* vlSelf);
VlCoroutine Vtb_sync_fifo___024root___eval_initial__TOP__Vtiming__1(Vtb_sync_fifo___024root* vlSelf);

void Vtb_sync_fifo___024root___eval_initial(Vtb_sync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root___eval_initial\n"); );
    // Body
    Vtb_sync_fifo___024root___eval_initial__TOP(vlSelf);
    Vtb_sync_fifo___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_sync_fifo___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_sync_fifo__DOT__clk__0 
        = vlSelf->tb_sync_fifo__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_sync_fifo__DOT__rst_n__0 
        = vlSelf->tb_sync_fifo__DOT__rst_n;
}

VL_INLINE_OPT VlCoroutine Vtb_sync_fifo___024root___eval_initial__TOP__Vtiming__1(Vtb_sync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(5ULL, nullptr, 
                                           "tb/tb_sync_fifo.sv", 
                                           34);
        vlSelf->tb_sync_fifo__DOT__clk = (1U & (~ (IData)(vlSelf->tb_sync_fifo__DOT__clk)));
    }
}

void Vtb_sync_fifo___024root___eval_act(Vtb_sync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtb_sync_fifo___024root___nba_sequent__TOP__0(Vtb_sync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vdlyvdim0__tb_sync_fifo__DOT__dut__DOT__mem__v0;
    __Vdlyvdim0__tb_sync_fifo__DOT__dut__DOT__mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_sync_fifo__DOT__dut__DOT__mem__v0;
    __Vdlyvval__tb_sync_fifo__DOT__dut__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_sync_fifo__DOT__dut__DOT__mem__v0;
    __Vdlyvset__tb_sync_fifo__DOT__dut__DOT__mem__v0 = 0;
    // Body
    __Vdlyvset__tb_sync_fifo__DOT__dut__DOT__mem__v0 = 0U;
    if (vlSelf->tb_sync_fifo__DOT__rst_n) {
        if (((IData)(vlSelf->tb_sync_fifo__DOT__wr_en) 
             & (~ (IData)(vlSelf->tb_sync_fifo__DOT__full)))) {
            __Vdlyvval__tb_sync_fifo__DOT__dut__DOT__mem__v0 
                = vlSelf->tb_sync_fifo__DOT__in_data;
            __Vdlyvset__tb_sync_fifo__DOT__dut__DOT__mem__v0 = 1U;
            __Vdlyvdim0__tb_sync_fifo__DOT__dut__DOT__mem__v0 
                = (0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr));
            vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)));
        }
        if (((IData)(vlSelf->tb_sync_fifo__DOT__rd_en) 
             & (~ (IData)(vlSelf->tb_sync_fifo__DOT__empty)))) {
            vlSelf->tb_sync_fifo__DOT__out_data = vlSelf->tb_sync_fifo__DOT__dut__DOT__mem
                [(0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))];
            vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr)));
        }
    } else {
        vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr = 0U;
        vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr = 0U;
        vlSelf->tb_sync_fifo__DOT__out_data = 0U;
    }
    if (__Vdlyvset__tb_sync_fifo__DOT__dut__DOT__mem__v0) {
        vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[__Vdlyvdim0__tb_sync_fifo__DOT__dut__DOT__mem__v0] 
            = __Vdlyvval__tb_sync_fifo__DOT__dut__DOT__mem__v0;
    }
    vlSelf->tb_sync_fifo__DOT__full = (((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                                               >> 4U)) 
                                        != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                                  >> 4U))) 
                                       & ((0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                          == (0xfU 
                                              & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))));
    vlSelf->tb_sync_fifo__DOT__empty = ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                        == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr));
}

void Vtb_sync_fifo___024root___eval_nba(Vtb_sync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_sync_fifo___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtb_sync_fifo___024root___timing_resume(Vtb_sync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root___timing_resume\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h77df6ff2__0.resume("@(posedge tb_sync_fifo.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_sync_fifo___024root___timing_commit(Vtb_sync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root___timing_commit\n"); );
    // Body
    if ((! (2ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h77df6ff2__0.commit("@(posedge tb_sync_fifo.clk)");
    }
}

void Vtb_sync_fifo___024root___eval_triggers__act(Vtb_sync_fifo___024root* vlSelf);

bool Vtb_sync_fifo___024root___eval_phase__act(Vtb_sync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_sync_fifo___024root___eval_triggers__act(vlSelf);
    Vtb_sync_fifo___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_sync_fifo___024root___timing_resume(vlSelf);
        Vtb_sync_fifo___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_sync_fifo___024root___eval_phase__nba(Vtb_sync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_sync_fifo___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sync_fifo___024root___dump_triggers__nba(Vtb_sync_fifo___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sync_fifo___024root___dump_triggers__act(Vtb_sync_fifo___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_sync_fifo___024root___eval(Vtb_sync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_sync_fifo___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_sync_fifo.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_sync_fifo___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_sync_fifo.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_sync_fifo___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_sync_fifo___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_sync_fifo___024root___eval_debug_assertions(Vtb_sync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
