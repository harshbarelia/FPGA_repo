// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_async_fifo.h for the primary calling header

#include "Vtb_async_fifo__pch.h"
#include "Vtb_async_fifo___024root.h"

VlCoroutine Vtb_async_fifo___024root___eval_initial__TOP__Vtiming__0(Vtb_async_fifo___024root* vlSelf);
VlCoroutine Vtb_async_fifo___024root___eval_initial__TOP__Vtiming__1(Vtb_async_fifo___024root* vlSelf);
VlCoroutine Vtb_async_fifo___024root___eval_initial__TOP__Vtiming__2(Vtb_async_fifo___024root* vlSelf);

void Vtb_async_fifo___024root___eval_initial(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vtb_async_fifo___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_async_fifo___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_async_fifo___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__wr_clk__0 
        = vlSelf->tb_async_fifo__DOT__wr_clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__wr_rst_n__0 
        = vlSelf->tb_async_fifo__DOT__wr_rst_n;
    vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__rd_clk__0 
        = vlSelf->tb_async_fifo__DOT__rd_clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__rd_rst_n__0 
        = vlSelf->tb_async_fifo__DOT__rd_rst_n;
}

VL_INLINE_OPT VlCoroutine Vtb_async_fifo___024root___eval_initial__TOP__Vtiming__0(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->tb_async_fifo__DOT__wr_clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(5ULL, nullptr, 
                                           "tb/tb_async_fifo.sv", 
                                           39);
        vlSelf->tb_async_fifo__DOT__wr_clk = (1U & 
                                              (~ (IData)(vlSelf->tb_async_fifo__DOT__wr_clk)));
    }
}

VL_INLINE_OPT VlCoroutine Vtb_async_fifo___024root___eval_initial__TOP__Vtiming__1(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    vlSelf->tb_async_fifo__DOT__rd_clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(7ULL, nullptr, 
                                           "tb/tb_async_fifo.sv", 
                                           44);
        vlSelf->tb_async_fifo__DOT__rd_clk = (1U & 
                                              (~ (IData)(vlSelf->tb_async_fifo__DOT__rd_clk)));
    }
}

VL_INLINE_OPT void Vtb_async_fifo___024root___act_comb__TOP__0(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___act_comb__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__Vfuncout;
    __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__bin;
    __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__bin = 0;
    CData/*4:0*/ __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__Vfuncout;
    __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__bin;
    __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__bin = 0;
    // Body
    vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_bin_next 
        = (0x1fU & ((IData)(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_bin) 
                    + (((~ (IData)(vlSelf->tb_async_fifo__DOT__full)) 
                        & (IData)(vlSelf->tb_async_fifo__DOT__wr_en))
                        ? 1U : 0U)));
    vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_bin_next 
        = (0x1fU & ((IData)(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_bin) 
                    + (((~ (IData)(vlSelf->tb_async_fifo__DOT__empty)) 
                        & (IData)(vlSelf->tb_async_fifo__DOT__rd_en))
                        ? 1U : 0U)));
    __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__bin 
        = vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_bin_next;
    __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__Vfuncout 
        = (0x1fU & (VL_SHIFTR_III(5,5,32, (IData)(__Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__bin), 1U) 
                    ^ (IData)(__Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__bin)));
    vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_next 
        = __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__Vfuncout;
    __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__bin 
        = vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_bin_next;
    __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__Vfuncout 
        = (0x1fU & (VL_SHIFTR_III(5,5,32, (IData)(__Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__bin), 1U) 
                    ^ (IData)(__Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__bin)));
    vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_next 
        = __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__Vfuncout;
}

void Vtb_async_fifo___024root___eval_act(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___eval_act\n"); );
    // Body
    if ((0x18ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_async_fifo___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_async_fifo___024root___nba_sequent__TOP__0(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdlyvset__tb_async_fifo__DOT__dut__DOT__mem__v0 = 0U;
    if (vlSelf->tb_async_fifo__DOT__wr_rst_n) {
        if (((IData)(vlSelf->tb_async_fifo__DOT__wr_en) 
             & (~ (IData)(vlSelf->tb_async_fifo__DOT__full)))) {
            vlSelf->__Vdlyvval__tb_async_fifo__DOT__dut__DOT__mem__v0 
                = vlSelf->tb_async_fifo__DOT__in_data;
            vlSelf->__Vdlyvset__tb_async_fifo__DOT__dut__DOT__mem__v0 = 1U;
            vlSelf->__Vdlyvdim0__tb_async_fifo__DOT__dut__DOT__mem__v0 
                = (0xfU & (IData)(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_bin));
            vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_bin 
                = vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_bin_next;
        }
        vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync2 
            = vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync1;
        vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync1 
            = vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray;
    } else {
        vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync2 = 0U;
        vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_bin = 0U;
        vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync1 = 0U;
    }
}

VL_INLINE_OPT void Vtb_async_fifo___024root___nba_sequent__TOP__1(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (vlSelf->tb_async_fifo__DOT__rd_rst_n) {
        if (((IData)(vlSelf->tb_async_fifo__DOT__rd_en) 
             & (~ (IData)(vlSelf->tb_async_fifo__DOT__empty)))) {
            vlSelf->tb_async_fifo__DOT__out_data = 
                vlSelf->tb_async_fifo__DOT__dut__DOT__mem
                [(0xfU & (IData)(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_bin))];
            vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray 
                = vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_next;
            vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_bin 
                = vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_bin_next;
        }
        vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_sync2 
            = vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_sync1;
        vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_sync1 
            = vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray;
    } else {
        vlSelf->tb_async_fifo__DOT__out_data = 0U;
        vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_sync2 = 0U;
        vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray = 0U;
        vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_bin = 0U;
        vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_sync1 = 0U;
    }
    vlSelf->tb_async_fifo__DOT__empty = ((IData)(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray) 
                                         == (IData)(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_sync2));
}

VL_INLINE_OPT void Vtb_async_fifo___024root___nba_sequent__TOP__2(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___nba_sequent__TOP__2\n"); );
    // Body
    if (vlSelf->__Vdlyvset__tb_async_fifo__DOT__dut__DOT__mem__v0) {
        vlSelf->tb_async_fifo__DOT__dut__DOT__mem[vlSelf->__Vdlyvdim0__tb_async_fifo__DOT__dut__DOT__mem__v0] 
            = vlSelf->__Vdlyvval__tb_async_fifo__DOT__dut__DOT__mem__v0;
    }
    if (vlSelf->tb_async_fifo__DOT__wr_rst_n) {
        if (((IData)(vlSelf->tb_async_fifo__DOT__wr_en) 
             & (~ (IData)(vlSelf->tb_async_fifo__DOT__full)))) {
            vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray 
                = vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_next;
        }
    } else {
        vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray = 0U;
    }
    vlSelf->tb_async_fifo__DOT__full = ((IData)(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray) 
                                        == ((0x18U 
                                             & ((~ 
                                                 ((IData)(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync2) 
                                                  >> 3U)) 
                                                << 3U)) 
                                            | (7U & (IData)(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync2))));
}

VL_INLINE_OPT void Vtb_async_fifo___024root___nba_comb__TOP__0(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___nba_comb__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__Vfuncout;
    __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__bin;
    __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__bin = 0;
    // Body
    vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_bin_next 
        = (0x1fU & ((IData)(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_bin) 
                    + (((~ (IData)(vlSelf->tb_async_fifo__DOT__empty)) 
                        & (IData)(vlSelf->tb_async_fifo__DOT__rd_en))
                        ? 1U : 0U)));
    __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__bin 
        = vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_bin_next;
    __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__Vfuncout 
        = (0x1fU & (VL_SHIFTR_III(5,5,32, (IData)(__Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__bin), 1U) 
                    ^ (IData)(__Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__bin)));
    vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_next 
        = __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__9__Vfuncout;
}

VL_INLINE_OPT void Vtb_async_fifo___024root___nba_comb__TOP__1(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___nba_comb__TOP__1\n"); );
    // Init
    CData/*4:0*/ __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__Vfuncout;
    __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__bin;
    __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__bin = 0;
    // Body
    vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_bin_next 
        = (0x1fU & ((IData)(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_bin) 
                    + (((~ (IData)(vlSelf->tb_async_fifo__DOT__full)) 
                        & (IData)(vlSelf->tb_async_fifo__DOT__wr_en))
                        ? 1U : 0U)));
    __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__bin 
        = vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_bin_next;
    __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__Vfuncout 
        = (0x1fU & (VL_SHIFTR_III(5,5,32, (IData)(__Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__bin), 1U) 
                    ^ (IData)(__Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__bin)));
    vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_next 
        = __Vfunc_tb_async_fifo__DOT__dut__DOT__bin2gray__8__Vfuncout;
}

void Vtb_async_fifo___024root___eval_nba(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_async_fifo___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_async_fifo___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_async_fifo___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    if ((0x1aULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_async_fifo___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x19ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_async_fifo___024root___nba_comb__TOP__1(vlSelf);
    }
}

void Vtb_async_fifo___024root___timing_resume(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___timing_resume\n"); );
    // Body
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h687c3cce__0.resume("@(posedge tb_async_fifo.wr_clk)");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hfb329b30__0.resume("@(posedge tb_async_fifo.rd_clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_async_fifo___024root___timing_commit(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___timing_commit\n"); );
    // Body
    if ((! (8ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h687c3cce__0.commit("@(posedge tb_async_fifo.wr_clk)");
    }
    if ((! (0x10ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hfb329b30__0.commit("@(posedge tb_async_fifo.rd_clk)");
    }
}

void Vtb_async_fifo___024root___eval_triggers__act(Vtb_async_fifo___024root* vlSelf);

bool Vtb_async_fifo___024root___eval_phase__act(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<5> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_async_fifo___024root___eval_triggers__act(vlSelf);
    Vtb_async_fifo___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_async_fifo___024root___timing_resume(vlSelf);
        Vtb_async_fifo___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_async_fifo___024root___eval_phase__nba(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_async_fifo___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_async_fifo___024root___dump_triggers__nba(Vtb_async_fifo___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_async_fifo___024root___dump_triggers__act(Vtb_async_fifo___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_async_fifo___024root___eval(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_async_fifo___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_async_fifo.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_async_fifo___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_async_fifo.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_async_fifo___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_async_fifo___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_async_fifo___024root___eval_debug_assertions(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
