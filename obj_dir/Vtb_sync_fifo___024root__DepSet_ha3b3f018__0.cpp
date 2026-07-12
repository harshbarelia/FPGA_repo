// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sync_fifo.h for the primary calling header

#include "Vtb_sync_fifo__pch.h"
#include "Vtb_sync_fifo__Syms.h"
#include "Vtb_sync_fifo___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_sync_fifo___024root___eval_initial__TOP__Vtiming__0(Vtb_sync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    CData/*7:0*/ __Vtask_tb_sync_fifo__DOT__push__1__data;
    __Vtask_tb_sync_fifo__DOT__push__1__data = 0;
    CData/*7:0*/ __Vtask_tb_sync_fifo__DOT__push__2__data;
    __Vtask_tb_sync_fifo__DOT__push__2__data = 0;
    CData/*7:0*/ __Vtask_tb_sync_fifo__DOT__push__3__data;
    __Vtask_tb_sync_fifo__DOT__push__3__data = 0;
    CData/*7:0*/ __Vtask_tb_sync_fifo__DOT__pop__5__exp;
    __Vtask_tb_sync_fifo__DOT__pop__5__exp = 0;
    CData/*0:0*/ __Vtask_tb_sync_fifo__DOT__pop__5__do_compare;
    __Vtask_tb_sync_fifo__DOT__pop__5__do_compare = 0;
    CData/*7:0*/ __Vtask_tb_sync_fifo__DOT__pop__6__exp;
    __Vtask_tb_sync_fifo__DOT__pop__6__exp = 0;
    CData/*0:0*/ __Vtask_tb_sync_fifo__DOT__pop__6__do_compare;
    __Vtask_tb_sync_fifo__DOT__pop__6__do_compare = 0;
    CData/*7:0*/ __Vtask_tb_sync_fifo__DOT__push__8__data;
    __Vtask_tb_sync_fifo__DOT__push__8__data = 0;
    CData/*7:0*/ __Vtask_tb_sync_fifo__DOT__pop__10__exp;
    __Vtask_tb_sync_fifo__DOT__pop__10__exp = 0;
    CData/*0:0*/ __Vtask_tb_sync_fifo__DOT__pop__10__do_compare;
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0;
    // Body
    vlSelf->tb_sync_fifo__DOT__rst_n = 0U;
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    vlSelf->tb_sync_fifo__DOT__in_data = 0U;
    vlSelf->tb_sync_fifo__DOT__model_q.clear();
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       42);
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       42);
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       42);
    vlSelf->tb_sync_fifo__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       44);
    __Vtask_tb_sync_fifo__DOT__push__1__data = 0x11U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__1__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__1__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__2__data = 0x22U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__2__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__2__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__3__data = 0x33U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__3__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__3__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    if (VL_UNLIKELY((((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                      == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                     != (0U == vlSelf->tb_sync_fifo__DOT__model_q.size())))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:84: Assertion failed in %Ntb_sync_fifo.check_flags: EMPTY mismatch time=%0t exp=%0b got=%0b\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,1,(0U 
                                                == vlSelf->tb_sync_fifo__DOT__model_q.size()),
                  1,((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                     == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)));
        VL_STOP_MT("tb/tb_sync_fifo.sv", 84, "");
    }
    if (VL_UNLIKELY(((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                              >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                                >> 4U))) 
                      & ((0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                         == (0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr)))) 
                     != (0x10U == vlSelf->tb_sync_fifo__DOT__model_q.size())))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:87: Assertion failed in %Ntb_sync_fifo.check_flags: FULL mismatch time=%0t exp=%0b got=%0b\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,1,(0x10U 
                                                == vlSelf->tb_sync_fifo__DOT__model_q.size()),
                  1,(((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                             >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                               >> 4U))) 
                     & ((0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                        == (0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr)))));
        VL_STOP_MT("tb/tb_sync_fifo.sv", 87, "");
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__5__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__5__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__5__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__5__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__5__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__5__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__6__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__6__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__6__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__6__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__6__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__6__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    if (VL_UNLIKELY((((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                      == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                     != (0U == vlSelf->tb_sync_fifo__DOT__model_q.size())))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:84: Assertion failed in %Ntb_sync_fifo.check_flags: EMPTY mismatch time=%0t exp=%0b got=%0b\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,1,(0U 
                                                == vlSelf->tb_sync_fifo__DOT__model_q.size()),
                  1,((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                     == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)));
        VL_STOP_MT("tb/tb_sync_fifo.sv", 84, "");
    }
    if (VL_UNLIKELY(((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                              >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                                >> 4U))) 
                      & ((0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                         == (0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr)))) 
                     != (0x10U == vlSelf->tb_sync_fifo__DOT__model_q.size())))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:87: Assertion failed in %Ntb_sync_fifo.check_flags: FULL mismatch time=%0t exp=%0b got=%0b\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,1,(0x10U 
                                                == vlSelf->tb_sync_fifo__DOT__model_q.size()),
                  1,(((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                             >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                               >> 4U))) 
                     & ((0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                        == (0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr)))));
        VL_STOP_MT("tb/tb_sync_fifo.sv", 87, "");
    }
    __Vtask_tb_sync_fifo__DOT__push__8__data = (0xffU 
                                                & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__8__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__8__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__8__data = (0xffU 
                                                & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__8__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__8__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__8__data = (0xffU 
                                                & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__8__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__8__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__8__data = (0xffU 
                                                & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__8__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__8__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__8__data = (0xffU 
                                                & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__8__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__8__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__8__data = (0xffU 
                                                & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__8__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__8__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__8__data = (0xffU 
                                                & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__8__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__8__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__8__data = (0xffU 
                                                & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__8__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__8__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__8__data = (0xffU 
                                                & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__8__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__8__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__8__data = (0xffU 
                                                & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__8__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__8__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__8__data = (0xffU 
                                                & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__8__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__8__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__8__data = (0xffU 
                                                & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__8__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__8__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__8__data = (0xffU 
                                                & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__8__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__8__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__8__data = (0xffU 
                                                & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__8__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__8__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__8__data = (0xffU 
                                                & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__8__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__8__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    __Vtask_tb_sync_fifo__DOT__push__8__data = (0xffU 
                                                & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       48);
    if ((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                 >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                   >> 4U))) & ((0xfU 
                                                & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                                               == (0xfU 
                                                   & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))) {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 1U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
        vlSelf->tb_sync_fifo__DOT__in_data = __Vtask_tb_sync_fifo__DOT__push__8__data;
        vlSelf->tb_sync_fifo__DOT__model_q.push_back(__Vtask_tb_sync_fifo__DOT__push__8__data);
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       57);
    vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
    if (VL_UNLIKELY((((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                      == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                     != (0U == vlSelf->tb_sync_fifo__DOT__model_q.size())))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:84: Assertion failed in %Ntb_sync_fifo.check_flags: EMPTY mismatch time=%0t exp=%0b got=%0b\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,1,(0U 
                                                == vlSelf->tb_sync_fifo__DOT__model_q.size()),
                  1,((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                     == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)));
        VL_STOP_MT("tb/tb_sync_fifo.sv", 84, "");
    }
    if (VL_UNLIKELY(((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                              >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                                >> 4U))) 
                      & ((0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                         == (0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr)))) 
                     != (0x10U == vlSelf->tb_sync_fifo__DOT__model_q.size())))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:87: Assertion failed in %Ntb_sync_fifo.check_flags: FULL mismatch time=%0t exp=%0b got=%0b\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,1,(0x10U 
                                                == vlSelf->tb_sync_fifo__DOT__model_q.size()),
                  1,(((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                             >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                               >> 4U))) 
                     & ((0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                        == (0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr)))));
        VL_STOP_MT("tb/tb_sync_fifo.sv", 87, "");
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__10__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__10__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__10__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__10__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__10__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__10__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__10__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__10__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__10__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__10__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__10__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__10__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__10__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__10__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__10__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__10__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__10__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__10__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__10__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__10__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__10__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__10__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__10__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__10__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__10__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__10__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__10__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__10__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__10__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__10__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       64);
    __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 0U;
    if (((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
         == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))) {
        vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_sync_fifo__DOT__wr_en = 0U;
        vlSelf->tb_sync_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_sync_fifo__DOT__model_q.size())) {
            __Vtask_tb_sync_fifo__DOT__pop__10__exp 
                = vlSelf->tb_sync_fifo__DOT__model_q.pop_front();
            __Vtask_tb_sync_fifo__DOT__pop__10__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_h77df6ff2__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sync_fifo.clk)", 
                                                       "tb/tb_sync_fifo.sv", 
                                                       76);
    if (VL_UNLIKELY(((IData)(__Vtask_tb_sync_fifo__DOT__pop__10__do_compare) 
                     & ((IData)(vlSelf->tb_sync_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:78: Assertion failed in %Ntb_sync_fifo.pop: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_sync_fifo__DOT__pop__10__exp),
                  8,vlSelf->tb_sync_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_sync_fifo.sv", 78, "");
    }
    vlSelf->tb_sync_fifo__DOT__rd_en = 0U;
    if (VL_UNLIKELY((((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                      == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                     != (0U == vlSelf->tb_sync_fifo__DOT__model_q.size())))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:84: Assertion failed in %Ntb_sync_fifo.check_flags: EMPTY mismatch time=%0t exp=%0b got=%0b\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,1,(0U 
                                                == vlSelf->tb_sync_fifo__DOT__model_q.size()),
                  1,((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                     == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)));
        VL_STOP_MT("tb/tb_sync_fifo.sv", 84, "");
    }
    if (VL_UNLIKELY(((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                              >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                                >> 4U))) 
                      & ((0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                         == (0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr)))) 
                     != (0x10U == vlSelf->tb_sync_fifo__DOT__model_q.size())))) {
        VL_WRITEF("[%0t] %%Error: tb_sync_fifo.sv:87: Assertion failed in %Ntb_sync_fifo.check_flags: FULL mismatch time=%0t exp=%0b got=%0b\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,1,(0x10U 
                                                == vlSelf->tb_sync_fifo__DOT__model_q.size()),
                  1,(((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                             >> 4U)) != (1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                               >> 4U))) 
                     & ((0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                        == (0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr)))));
        VL_STOP_MT("tb/tb_sync_fifo.sv", 87, "");
    }
    VL_FINISH_MT("tb/tb_sync_fifo.sv", 111, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sync_fifo___024root___dump_triggers__act(Vtb_sync_fifo___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_sync_fifo___024root___eval_triggers__act(Vtb_sync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->tb_sync_fifo__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_sync_fifo__DOT__clk__0))) 
                                     | ((~ (IData)(vlSelf->tb_sync_fifo__DOT__rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_sync_fifo__DOT__rst_n__0))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->tb_sync_fifo__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_sync_fifo__DOT__clk__0))));
    vlSelf->__VactTriggered.set(2U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_sync_fifo__DOT__clk__0 
        = vlSelf->tb_sync_fifo__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_sync_fifo__DOT__rst_n__0 
        = vlSelf->tb_sync_fifo__DOT__rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_sync_fifo___024root___dump_triggers__act(vlSelf);
    }
#endif
}
