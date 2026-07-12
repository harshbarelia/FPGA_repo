// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_uart_rx.h for the primary calling header

#include "Vtb_uart_rx__pch.h"
#include "Vtb_uart_rx__Syms.h"
#include "Vtb_uart_rx___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_uart_rx___024root___eval_initial__TOP__Vtiming__0(Vtb_uart_rx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_rx___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    CData/*7:0*/ __Vtask_tb_uart_rx__DOT__send_byte__0__b;
    __Vtask_tb_uart_rx__DOT__send_byte__0__b = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x745f7278U;
    __Vtemp_1[2U] = 0x5f756172U;
    __Vtemp_1[3U] = 0x7462U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(4, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelf->tb_uart_rx__DOT__rst_n = 0U;
    vlSelf->tb_uart_rx__DOT__rx = 1U;
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       54);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       54);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       54);
    vlSelf->tb_uart_rx__DOT__rst_n = 1U;
    __Vtask_tb_uart_rx__DOT__send_byte__0__b = 0xa5U;
    vlSelf->tb_uart_rx__DOT__rx = 1U;
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       32);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       32);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       32);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       32);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       32);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       32);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       32);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       32);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       32);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       32);
    vlSelf->tb_uart_rx__DOT__rx = 0U;
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       35);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       35);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       35);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       35);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       35);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       35);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       35);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       35);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       35);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       35);
    vlSelf->tb_uart_rx__DOT__rx = (1U & (IData)(__Vtask_tb_uart_rx__DOT__send_byte__0__b));
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    vlSelf->tb_uart_rx__DOT__send_byte__Vstatic__i = 1U;
    vlSelf->tb_uart_rx__DOT__rx = (1U & ((IData)(__Vtask_tb_uart_rx__DOT__send_byte__0__b) 
                                         >> 1U));
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    vlSelf->tb_uart_rx__DOT__send_byte__Vstatic__i = 2U;
    vlSelf->tb_uart_rx__DOT__rx = (1U & ((IData)(__Vtask_tb_uart_rx__DOT__send_byte__0__b) 
                                         >> 2U));
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    vlSelf->tb_uart_rx__DOT__send_byte__Vstatic__i = 3U;
    vlSelf->tb_uart_rx__DOT__rx = (1U & ((IData)(__Vtask_tb_uart_rx__DOT__send_byte__0__b) 
                                         >> 3U));
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    vlSelf->tb_uart_rx__DOT__send_byte__Vstatic__i = 4U;
    vlSelf->tb_uart_rx__DOT__rx = (1U & ((IData)(__Vtask_tb_uart_rx__DOT__send_byte__0__b) 
                                         >> 4U));
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    vlSelf->tb_uart_rx__DOT__send_byte__Vstatic__i = 5U;
    vlSelf->tb_uart_rx__DOT__rx = (1U & ((IData)(__Vtask_tb_uart_rx__DOT__send_byte__0__b) 
                                         >> 5U));
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    vlSelf->tb_uart_rx__DOT__send_byte__Vstatic__i = 6U;
    vlSelf->tb_uart_rx__DOT__rx = (1U & ((IData)(__Vtask_tb_uart_rx__DOT__send_byte__0__b) 
                                         >> 6U));
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    vlSelf->tb_uart_rx__DOT__send_byte__Vstatic__i = 7U;
    vlSelf->tb_uart_rx__DOT__rx = (1U & ((IData)(__Vtask_tb_uart_rx__DOT__send_byte__0__b) 
                                         >> 7U));
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       39);
    vlSelf->tb_uart_rx__DOT__send_byte__Vstatic__i = 8U;
    vlSelf->tb_uart_rx__DOT__rx = 1U;
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       43);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    co_await vlSelf->__VtrigSched_hafcd772c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_rx.clk)", 
                                                       "tb/tb_uart_rx.sv", 
                                                       59);
    VL_FINISH_MT("tb/tb_uart_rx.sv", 60, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_rx___024root___dump_triggers__act(Vtb_uart_rx___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_uart_rx___024root___eval_triggers__act(Vtb_uart_rx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_rx___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->tb_uart_rx__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_uart_rx__DOT__clk__0))) 
                                     | ((~ (IData)(vlSelf->tb_uart_rx__DOT__rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_uart_rx__DOT__rst_n__0))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->tb_uart_rx__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_uart_rx__DOT__clk__0))));
    vlSelf->__VactTriggered.set(2U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_rx__DOT__clk__0 
        = vlSelf->tb_uart_rx__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_rx__DOT__rst_n__0 
        = vlSelf->tb_uart_rx__DOT__rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_uart_rx___024root___dump_triggers__act(vlSelf);
    }
#endif
}
