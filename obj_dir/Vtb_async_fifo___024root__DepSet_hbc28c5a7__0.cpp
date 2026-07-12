// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_async_fifo.h for the primary calling header

#include "Vtb_async_fifo__pch.h"
#include "Vtb_async_fifo__Syms.h"
#include "Vtb_async_fifo___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_async_fifo___024root___eval_initial__TOP__Vtiming__2(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Init
    CData/*7:0*/ __Vtask_tb_async_fifo__DOT__write_data__1__data;
    __Vtask_tb_async_fifo__DOT__write_data__1__data = 0;
    CData/*7:0*/ __Vtask_tb_async_fifo__DOT__write_data__2__data;
    __Vtask_tb_async_fifo__DOT__write_data__2__data = 0;
    CData/*7:0*/ __Vtask_tb_async_fifo__DOT__write_data__3__data;
    __Vtask_tb_async_fifo__DOT__write_data__3__data = 0;
    CData/*7:0*/ __Vtask_tb_async_fifo__DOT__read_data__4__exp;
    __Vtask_tb_async_fifo__DOT__read_data__4__exp = 0;
    CData/*0:0*/ __Vtask_tb_async_fifo__DOT__read_data__4__do_compare;
    __Vtask_tb_async_fifo__DOT__read_data__4__do_compare = 0;
    CData/*7:0*/ __Vtask_tb_async_fifo__DOT__read_data__5__exp;
    __Vtask_tb_async_fifo__DOT__read_data__5__exp = 0;
    CData/*0:0*/ __Vtask_tb_async_fifo__DOT__read_data__5__do_compare;
    __Vtask_tb_async_fifo__DOT__read_data__5__do_compare = 0;
    CData/*7:0*/ __Vtask_tb_async_fifo__DOT__write_data__6__data;
    __Vtask_tb_async_fifo__DOT__write_data__6__data = 0;
    CData/*7:0*/ __Vtask_tb_async_fifo__DOT__read_data__7__exp;
    __Vtask_tb_async_fifo__DOT__read_data__7__exp = 0;
    CData/*0:0*/ __Vtask_tb_async_fifo__DOT__read_data__7__do_compare;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0;
    // Body
    vlSelf->tb_async_fifo__DOT__wr_rst_n = 0U;
    vlSelf->tb_async_fifo__DOT__rd_rst_n = 0U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    vlSelf->tb_async_fifo__DOT__in_data = 0U;
    vlSelf->tb_async_fifo__DOT__model_q.clear();
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       54);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       54);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       54);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_rst_n = 1U;
    vlSelf->tb_async_fifo__DOT__rd_rst_n = 1U;
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       58);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       58);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__write_data__1__data = 0x11U;
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__1__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__1__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__2__data = 0x22U;
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__2__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__2__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__3__data = 0x33U;
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__3__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__3__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__4__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__4__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__4__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__4__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__4__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__4__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__5__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__5__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__5__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__5__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__5__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__5__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__6__data 
        = (0xffU & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__6__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__6__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__6__data 
        = (0xffU & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__6__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__6__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__6__data 
        = (0xffU & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__6__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__6__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__6__data 
        = (0xffU & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__6__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__6__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__6__data 
        = (0xffU & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__6__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__6__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__6__data 
        = (0xffU & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__6__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__6__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__6__data 
        = (0xffU & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__6__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__6__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__6__data 
        = (0xffU & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__6__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__6__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__6__data 
        = (0xffU & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__6__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__6__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__6__data 
        = (0xffU & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__6__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__6__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__6__data 
        = (0xffU & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__6__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__6__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__6__data 
        = (0xffU & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__6__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__6__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__6__data 
        = (0xffU & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__6__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__6__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__6__data 
        = (0xffU & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__6__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__6__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__6__data 
        = (0xffU & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__6__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__6__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    __Vtask_tb_async_fifo__DOT__write_data__6__data 
        = (0xffU & VL_URANDOM_RANGE_I(0U, 0xffU));
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_async_fifo__DOT__full) {
        vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__wr_en = 1U;
        vlSelf->tb_async_fifo__DOT__in_data = __Vtask_tb_async_fifo__DOT__write_data__6__data;
        vlSelf->tb_async_fifo__DOT__model_q.push_back(__Vtask_tb_async_fifo__DOT__write_data__6__data);
    }
    co_await vlSelf->__VtrigSched_h687c3cce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.wr_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       71);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_async_fifo__DOT__wr_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__7__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__7__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__7__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__7__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__7__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__7__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__7__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__7__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__7__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__7__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__7__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__7__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__7__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__7__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__7__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__7__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__7__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__7__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__7__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__7__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__7__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__7__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__7__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__7__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__7__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__7__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__7__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__7__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__7__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__7__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 0U;
    if (vlSelf->tb_async_fifo__DOT__empty) {
        vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    } else {
        vlSelf->tb_async_fifo__DOT__rd_en = 1U;
        if (VL_LTS_III(32, 0U, vlSelf->tb_async_fifo__DOT__model_q.size())) {
            __Vtask_tb_async_fifo__DOT__read_data__7__exp 
                = vlSelf->tb_async_fifo__DOT__model_q.pop_front();
            __Vtask_tb_async_fifo__DOT__read_data__7__do_compare = 1U;
        }
    }
    co_await vlSelf->__VtrigSched_hfb329b30__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_async_fifo.rd_clk)", 
                                                       "tb/tb_async_fifo.sv", 
                                                       89);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_async_fifo__DOT__read_data__7__do_compare) 
                     & ((IData)(vlSelf->tb_async_fifo__DOT__out_data) 
                        != (IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp))))) {
        VL_WRITEF("[%0t] %%Error: tb_async_fifo.sv:91: Assertion failed in %Ntb_async_fifo.read_data: DATA MISMATCH time=%0t exp=%0x got=%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_async_fifo__DOT__read_data__7__exp),
                  8,vlSelf->tb_async_fifo__DOT__out_data);
        VL_STOP_MT("tb/tb_async_fifo.sv", 91, "");
    }
    vlSelf->tb_async_fifo__DOT__rd_en = 0U;
    VL_FINISH_MT("tb/tb_async_fifo.sv", 108, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_async_fifo___024root___dump_triggers__act(Vtb_async_fifo___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_async_fifo___024root___eval_triggers__act(Vtb_async_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->tb_async_fifo__DOT__wr_clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__wr_clk__0))) 
                                     | ((~ (IData)(vlSelf->tb_async_fifo__DOT__wr_rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__wr_rst_n__0))));
    vlSelf->__VactTriggered.set(1U, (((IData)(vlSelf->tb_async_fifo__DOT__rd_clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__rd_clk__0))) 
                                     | ((~ (IData)(vlSelf->tb_async_fifo__DOT__rd_rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__rd_rst_n__0))));
    vlSelf->__VactTriggered.set(2U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__VactTriggered.set(3U, ((IData)(vlSelf->tb_async_fifo__DOT__wr_clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__wr_clk__0))));
    vlSelf->__VactTriggered.set(4U, ((IData)(vlSelf->tb_async_fifo__DOT__rd_clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__rd_clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__wr_clk__0 
        = vlSelf->tb_async_fifo__DOT__wr_clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__wr_rst_n__0 
        = vlSelf->tb_async_fifo__DOT__wr_rst_n;
    vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__rd_clk__0 
        = vlSelf->tb_async_fifo__DOT__rd_clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_async_fifo__DOT__rd_rst_n__0 
        = vlSelf->tb_async_fifo__DOT__rd_rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_async_fifo___024root___dump_triggers__act(vlSelf);
    }
#endif
}
