// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_uart_csr.h for the primary calling header

#include "Vtb_uart_csr__pch.h"
#include "Vtb_uart_csr__Syms.h"
#include "Vtb_uart_csr___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_uart_csr___024root___eval_initial__TOP__Vtiming__0(Vtb_uart_csr___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_csr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_csr___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    CData/*3:0*/ __Vtask_tb_uart_csr__DOT__reg_write__0__a;
    __Vtask_tb_uart_csr__DOT__reg_write__0__a = 0;
    IData/*31:0*/ __Vtask_tb_uart_csr__DOT__reg_write__0__d;
    __Vtask_tb_uart_csr__DOT__reg_write__0__d = 0;
    CData/*3:0*/ __Vtask_tb_uart_csr__DOT__reg_write__1__a;
    __Vtask_tb_uart_csr__DOT__reg_write__1__a = 0;
    IData/*31:0*/ __Vtask_tb_uart_csr__DOT__reg_write__1__d;
    __Vtask_tb_uart_csr__DOT__reg_write__1__d = 0;
    CData/*3:0*/ __Vtask_tb_uart_csr__DOT__reg_read__2__a;
    __Vtask_tb_uart_csr__DOT__reg_read__2__a = 0;
    IData/*31:0*/ __Vtask_tb_uart_csr__DOT__reg_read__2__d;
    __Vtask_tb_uart_csr__DOT__reg_read__2__d = 0;
    CData/*3:0*/ __Vtask_tb_uart_csr__DOT__reg_read__3__a;
    __Vtask_tb_uart_csr__DOT__reg_read__3__a = 0;
    IData/*31:0*/ __Vtask_tb_uart_csr__DOT__reg_read__3__d;
    __Vtask_tb_uart_csr__DOT__reg_read__3__d = 0;
    CData/*3:0*/ __Vtask_tb_uart_csr__DOT__reg_read__4__a;
    __Vtask_tb_uart_csr__DOT__reg_read__4__a = 0;
    IData/*31:0*/ __Vtask_tb_uart_csr__DOT__reg_read__4__d;
    __Vtask_tb_uart_csr__DOT__reg_read__4__d = 0;
    CData/*3:0*/ __Vtask_tb_uart_csr__DOT__reg_read__5__a;
    __Vtask_tb_uart_csr__DOT__reg_read__5__a = 0;
    IData/*31:0*/ __Vtask_tb_uart_csr__DOT__reg_read__5__d;
    __Vtask_tb_uart_csr__DOT__reg_read__5__d = 0;
    CData/*3:0*/ __Vtask_tb_uart_csr__DOT__reg_read__6__a;
    __Vtask_tb_uart_csr__DOT__reg_read__6__a = 0;
    IData/*31:0*/ __Vtask_tb_uart_csr__DOT__reg_read__6__d;
    __Vtask_tb_uart_csr__DOT__reg_read__6__d = 0;
    CData/*3:0*/ __Vtask_tb_uart_csr__DOT__reg_write__7__a;
    __Vtask_tb_uart_csr__DOT__reg_write__7__a = 0;
    IData/*31:0*/ __Vtask_tb_uart_csr__DOT__reg_write__7__d;
    __Vtask_tb_uart_csr__DOT__reg_write__7__d = 0;
    CData/*3:0*/ __Vtask_tb_uart_csr__DOT__reg_read__8__a;
    __Vtask_tb_uart_csr__DOT__reg_read__8__a = 0;
    IData/*31:0*/ __Vtask_tb_uart_csr__DOT__reg_read__8__d;
    __Vtask_tb_uart_csr__DOT__reg_read__8__d = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x5f637372U;
    __Vtemp_1[2U] = 0x75617274U;
    __Vtemp_1[3U] = 0x74625fU;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(4, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelf->tb_uart_csr__DOT__rst_n = 0U;
    vlSelf->tb_uart_csr__DOT__wr_en = 0U;
    vlSelf->tb_uart_csr__DOT__rd_en = 0U;
    vlSelf->tb_uart_csr__DOT__wstrb = 0U;
    vlSelf->tb_uart_csr__DOT__addr = 0U;
    vlSelf->tb_uart_csr__DOT__wdata = 0U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       77);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       77);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       77);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       77);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       77);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_uart_csr__DOT__rst_n = 1U;
    __Vtask_tb_uart_csr__DOT__reg_write__0__d = 0xa5U;
    __Vtask_tb_uart_csr__DOT__reg_write__0__a = 8U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       42);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_uart_csr__DOT__addr = __Vtask_tb_uart_csr__DOT__reg_write__0__a;
    vlSelf->tb_uart_csr__DOT__wdata = __Vtask_tb_uart_csr__DOT__reg_write__0__d;
    vlSelf->tb_uart_csr__DOT__wstrb = 0xfU;
    vlSelf->tb_uart_csr__DOT__wr_en = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       47);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_uart_csr__DOT__wr_en = 0U;
    __Vtask_tb_uart_csr__DOT__reg_write__1__d = 1U;
    __Vtask_tb_uart_csr__DOT__reg_write__1__a = 0U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       42);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_uart_csr__DOT__addr = __Vtask_tb_uart_csr__DOT__reg_write__1__a;
    vlSelf->tb_uart_csr__DOT__wdata = __Vtask_tb_uart_csr__DOT__reg_write__1__d;
    vlSelf->tb_uart_csr__DOT__wstrb = 0xfU;
    vlSelf->tb_uart_csr__DOT__wr_en = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       47);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_uart_csr__DOT__wr_en = 0U;
    __Vtask_tb_uart_csr__DOT__reg_read__2__a = 4U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       54);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_uart_csr__DOT__addr = __Vtask_tb_uart_csr__DOT__reg_read__2__a;
    vlSelf->tb_uart_csr__DOT__rd_en = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       57);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_uart_csr__DOT__reg_read__2__d = vlSelf->tb_uart_csr__DOT__rdata;
    vlSelf->tb_uart_csr__DOT__rd_en = 0U;
    vlSelf->tb_uart_csr__DOT__status_val = __Vtask_tb_uart_csr__DOT__reg_read__2__d;
    while ((1U & vlSelf->tb_uart_csr__DOT__status_val)) {
        __Vtask_tb_uart_csr__DOT__reg_read__3__a = 4U;
        co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_uart_csr.clk)", 
                                                           "tb/tb_uart_csr.sv", 
                                                           54);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_uart_csr__DOT__addr = __Vtask_tb_uart_csr__DOT__reg_read__3__a;
        vlSelf->tb_uart_csr__DOT__rd_en = 1U;
        co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_uart_csr.clk)", 
                                                           "tb/tb_uart_csr.sv", 
                                                           57);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        __Vtask_tb_uart_csr__DOT__reg_read__3__d = vlSelf->tb_uart_csr__DOT__rdata;
        vlSelf->tb_uart_csr__DOT__rd_en = 0U;
        vlSelf->tb_uart_csr__DOT__status_val = __Vtask_tb_uart_csr__DOT__reg_read__3__d;
    }
    __Vtask_tb_uart_csr__DOT__reg_read__4__a = 4U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       54);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_uart_csr__DOT__addr = __Vtask_tb_uart_csr__DOT__reg_read__4__a;
    vlSelf->tb_uart_csr__DOT__rd_en = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       57);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_uart_csr__DOT__reg_read__4__d = vlSelf->tb_uart_csr__DOT__rdata;
    vlSelf->tb_uart_csr__DOT__rd_en = 0U;
    vlSelf->tb_uart_csr__DOT__status_val = __Vtask_tb_uart_csr__DOT__reg_read__4__d;
    while ((1U & (~ (vlSelf->tb_uart_csr__DOT__status_val 
                     >> 1U)))) {
        __Vtask_tb_uart_csr__DOT__reg_read__5__a = 4U;
        co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_uart_csr.clk)", 
                                                           "tb/tb_uart_csr.sv", 
                                                           54);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->tb_uart_csr__DOT__addr = __Vtask_tb_uart_csr__DOT__reg_read__5__a;
        vlSelf->tb_uart_csr__DOT__rd_en = 1U;
        co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_uart_csr.clk)", 
                                                           "tb/tb_uart_csr.sv", 
                                                           57);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        __Vtask_tb_uart_csr__DOT__reg_read__5__d = vlSelf->tb_uart_csr__DOT__rdata;
        vlSelf->tb_uart_csr__DOT__rd_en = 0U;
        vlSelf->tb_uart_csr__DOT__status_val = __Vtask_tb_uart_csr__DOT__reg_read__5__d;
    }
    __Vtask_tb_uart_csr__DOT__reg_read__6__a = 0xcU;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       54);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_uart_csr__DOT__addr = __Vtask_tb_uart_csr__DOT__reg_read__6__a;
    vlSelf->tb_uart_csr__DOT__rd_en = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       57);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_uart_csr__DOT__reg_read__6__d = vlSelf->tb_uart_csr__DOT__rdata;
    vlSelf->tb_uart_csr__DOT__rd_en = 0U;
    vlSelf->tb_uart_csr__DOT__rxdata_val = __Vtask_tb_uart_csr__DOT__reg_read__6__d;
    if (VL_UNLIKELY((0xa5U != (0xffU & vlSelf->tb_uart_csr__DOT__rxdata_val)))) {
        VL_WRITEF("[%0t] %%Error: tb_uart_csr.sv:94: Assertion failed in %Ntb_uart_csr: CSR loopback failed: expected 0xA5, got 0x%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  8,(0xffU & vlSelf->tb_uart_csr__DOT__rxdata_val));
        VL_STOP_MT("tb/tb_uart_csr.sv", 94, "");
    } else {
        VL_WRITEF("CSR loopback PASSED: got 0x%0x\n",
                  8,(0xffU & vlSelf->tb_uart_csr__DOT__rxdata_val));
    }
    if (VL_UNLIKELY((4U & vlSelf->tb_uart_csr__DOT__status_val))) {
        VL_WRITEF("[%0t] %%Error: tb_uart_csr.sv:100: Assertion failed in %Ntb_uart_csr: Unexpected framing_error set\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("tb/tb_uart_csr.sv", 100, "");
    }
    __Vtask_tb_uart_csr__DOT__reg_write__7__d = 6U;
    __Vtask_tb_uart_csr__DOT__reg_write__7__a = 4U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       42);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_uart_csr__DOT__addr = __Vtask_tb_uart_csr__DOT__reg_write__7__a;
    vlSelf->tb_uart_csr__DOT__wdata = __Vtask_tb_uart_csr__DOT__reg_write__7__d;
    vlSelf->tb_uart_csr__DOT__wstrb = 0xfU;
    vlSelf->tb_uart_csr__DOT__wr_en = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       47);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_uart_csr__DOT__wr_en = 0U;
    __Vtask_tb_uart_csr__DOT__reg_read__8__a = 4U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       54);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_uart_csr__DOT__addr = __Vtask_tb_uart_csr__DOT__reg_read__8__a;
    vlSelf->tb_uart_csr__DOT__rd_en = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       57);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vtask_tb_uart_csr__DOT__reg_read__8__d = vlSelf->tb_uart_csr__DOT__rdata;
    vlSelf->tb_uart_csr__DOT__rd_en = 0U;
    vlSelf->tb_uart_csr__DOT__status_val = __Vtask_tb_uart_csr__DOT__reg_read__8__d;
    if (VL_UNLIKELY((0U != (3U & (vlSelf->tb_uart_csr__DOT__status_val 
                                  >> 1U))))) {
        VL_WRITEF("[%0t] %%Error: tb_uart_csr.sv:106: Assertion failed in %Ntb_uart_csr: STATUS bits did not clear: 0x%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  32,vlSelf->tb_uart_csr__DOT__status_val);
        VL_STOP_MT("tb/tb_uart_csr.sv", 106, "");
    }
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hd3f1ec7e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_csr.clk)", 
                                                       "tb/tb_uart_csr.sv", 
                                                       109);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("tb/tb_uart_csr.sv", 110, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_csr___024root___dump_triggers__act(Vtb_uart_csr___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_uart_csr___024root___eval_triggers__act(Vtb_uart_csr___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_csr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_csr___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->tb_uart_csr__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_uart_csr__DOT__clk__0))) 
                                     | ((~ (IData)(vlSelf->tb_uart_csr__DOT__rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_uart_csr__DOT__rst_n__0))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->tb_uart_csr__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_uart_csr__DOT__clk__0))));
    vlSelf->__VactTriggered.set(2U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_csr__DOT__clk__0 
        = vlSelf->tb_uart_csr__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_csr__DOT__rst_n__0 
        = vlSelf->tb_uart_csr__DOT__rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_uart_csr___024root___dump_triggers__act(vlSelf);
    }
#endif
}
