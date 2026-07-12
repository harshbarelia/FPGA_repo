// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_async_fifo.h for the primary calling header

#include "Vtb_async_fifo__pch.h"
#include "Vtb_async_fifo___024root.h"

VL_ATTR_COLD void Vtb_async_fifo___024root___eval_static(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_async_fifo___024root___eval_final(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_async_fifo___024root___dump_triggers__stl(Vtb_async_fifo___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_async_fifo___024root___eval_phase__stl(Vtb_async_fifo___024root* vlSelf);

VL_ATTR_COLD void Vtb_async_fifo___024root___eval_settle(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___eval_settle\n"); );
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
            Vtb_async_fifo___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_async_fifo.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_async_fifo___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_async_fifo___024root___dump_triggers__stl(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_async_fifo___024root___stl_sequent__TOP__0(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___stl_sequent__TOP__0\n"); );
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
    vlSelf->tb_async_fifo__DOT__full = ((IData)(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray) 
                                        == ((0x18U 
                                             & ((~ 
                                                 ((IData)(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync2) 
                                                  >> 3U)) 
                                                << 3U)) 
                                            | (7U & (IData)(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync2))));
    vlSelf->tb_async_fifo__DOT__empty = ((IData)(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray) 
                                         == (IData)(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_sync2));
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

VL_ATTR_COLD void Vtb_async_fifo___024root___eval_stl(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_async_fifo___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtb_async_fifo___024root___eval_triggers__stl(Vtb_async_fifo___024root* vlSelf);

VL_ATTR_COLD bool Vtb_async_fifo___024root___eval_phase__stl(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_async_fifo___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_async_fifo___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_async_fifo___024root___dump_triggers__act(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_async_fifo.wr_clk or negedge tb_async_fifo.wr_rst_n)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_async_fifo.rd_clk or negedge tb_async_fifo.rd_rst_n)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(posedge tb_async_fifo.wr_clk)\n");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @(posedge tb_async_fifo.rd_clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_async_fifo___024root___dump_triggers__nba(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_async_fifo.wr_clk or negedge tb_async_fifo.wr_rst_n)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_async_fifo.rd_clk or negedge tb_async_fifo.rd_rst_n)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(posedge tb_async_fifo.wr_clk)\n");
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @(posedge tb_async_fifo.rd_clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_async_fifo___024root___ctor_var_reset(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_async_fifo__DOT__wr_clk = VL_RAND_RESET_I(1);
    vlSelf->tb_async_fifo__DOT__rd_clk = VL_RAND_RESET_I(1);
    vlSelf->tb_async_fifo__DOT__wr_rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_async_fifo__DOT__rd_rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_async_fifo__DOT__wr_en = VL_RAND_RESET_I(1);
    vlSelf->tb_async_fifo__DOT__rd_en = VL_RAND_RESET_I(1);
    vlSelf->tb_async_fifo__DOT__in_data = VL_RAND_RESET_I(8);
    vlSelf->tb_async_fifo__DOT__out_data = VL_RAND_RESET_I(8);
    vlSelf->tb_async_fifo__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->tb_async_fifo__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->tb_async_fifo__DOT__model_q.atDefault() = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_async_fifo__DOT__dut__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_bin = VL_RAND_RESET_I(5);
    vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_bin_next = VL_RAND_RESET_I(5);
    vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_bin = VL_RAND_RESET_I(5);
    vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_bin_next = VL_RAND_RESET_I(5);
    vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray = VL_RAND_RESET_I(5);
    vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_next = VL_RAND_RESET_I(5);
    vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray = VL_RAND_RESET_I(5);
    vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_next = VL_RAND_RESET_I(5);
    vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_sync1 = VL_RAND_RESET_I(5);
    vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_sync2 = VL_RAND_RESET_I(5);
    vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync1 = VL_RAND_RESET_I(5);
    vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync2 = VL_RAND_RESET_I(5);
    vlSelf->__Vdlyvdim0__tb_async_fifo__DOT__dut__DOT__mem__v0 = 0;
    vlSelf->__Vdlyvval__tb_async_fifo__DOT__dut__DOT__mem__v0 = VL_RAND_RESET_I(8);
    vlSelf->__Vdlyvset__tb_async_fifo__DOT__dut__DOT__mem__v0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__wr_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__wr_rst_n__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__rd_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__rd_rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
