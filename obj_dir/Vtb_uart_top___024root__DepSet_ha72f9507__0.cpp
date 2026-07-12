// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_uart_top.h for the primary calling header

#include "Vtb_uart_top__pch.h"
#include "Vtb_uart_top__Syms.h"
#include "Vtb_uart_top___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_uart_top___024root___eval_initial__TOP__Vtiming__0(Vtb_uart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_top___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x5f746f70U;
    __Vtemp_1[2U] = 0x75617274U;
    __Vtemp_1[3U] = 0x74625fU;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(4, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelf->tb_uart_top__DOT__rst_n = 0U;
    vlSelf->tb_uart_top__DOT__tx_start = 0U;
    vlSelf->tb_uart_top__DOT__tx_data = 0U;
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       51);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       51);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       51);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       51);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       51);
    vlSelf->tb_uart_top__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       54);
    vlSelf->tb_uart_top__DOT__tx_data = 0xa5U;
    vlSelf->tb_uart_top__DOT__tx_start = 1U;
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       57);
    vlSelf->tb_uart_top__DOT__tx_start = 0U;
    while ((1U & (~ (IData)(vlSelf->tb_uart_top__DOT__rx_valid)))) {
        co_await vlSelf->__VtrigSched_h68bc4cef__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] tb_uart_top.rx_valid)", 
                                                           "tb/tb_uart_top.sv", 
                                                           60);
    }
    if (VL_UNLIKELY((0xa5U != (IData)(vlSelf->tb_uart_top__DOT__rx_data)))) {
        VL_WRITEF("[%0t] %%Error: tb_uart_top.sv:62: Assertion failed in %Ntb_uart_top: Loopback failed: expected 0xA5, got 0x%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  8,(IData)(vlSelf->tb_uart_top__DOT__rx_data));
        VL_STOP_MT("tb/tb_uart_top.sv", 62, "");
    }
    if (VL_UNLIKELY(vlSelf->tb_uart_top__DOT__framing_error)) {
        VL_WRITEF("[%0t] %%Error: tb_uart_top.sv:65: Assertion failed in %Ntb_uart_top: Unexpected framing_error on valid frame\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("tb/tb_uart_top.sv", 65, "");
    }
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       68);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       70);
    vlSelf->tb_uart_top__DOT__tx_data = 0x3cU;
    vlSelf->tb_uart_top__DOT__tx_start = 1U;
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       73);
    vlSelf->tb_uart_top__DOT__tx_start = 0U;
    while ((1U & (~ (IData)(vlSelf->tb_uart_top__DOT__rx_valid)))) {
        co_await vlSelf->__VtrigSched_h68bc4cef__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] tb_uart_top.rx_valid)", 
                                                           "tb/tb_uart_top.sv", 
                                                           76);
    }
    if (VL_UNLIKELY((0x3cU != (IData)(vlSelf->tb_uart_top__DOT__rx_data)))) {
        VL_WRITEF("[%0t] %%Error: tb_uart_top.sv:78: Assertion failed in %Ntb_uart_top: Loopback failed: expected 0x3C, got 0x%0x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  8,(IData)(vlSelf->tb_uart_top__DOT__rx_data));
        VL_STOP_MT("tb/tb_uart_top.sv", 78, "");
    }
    if (VL_UNLIKELY(vlSelf->tb_uart_top__DOT__framing_error)) {
        VL_WRITEF("[%0t] %%Error: tb_uart_top.sv:81: Assertion failed in %Ntb_uart_top: Unexpected framing_error on valid frame\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("tb/tb_uart_top.sv", 81, "");
    }
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_he1c9665e__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_top.clk)", 
                                                       "tb/tb_uart_top.sv", 
                                                       84);
    VL_FINISH_MT("tb/tb_uart_top.sv", 85, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_top___024root___dump_triggers__act(Vtb_uart_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_uart_top___024root___eval_triggers__act(Vtb_uart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_top___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->tb_uart_top__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_uart_top__DOT__clk__0))) 
                                     | ((~ (IData)(vlSelf->tb_uart_top__DOT__rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_uart_top__DOT__rst_n__0))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->tb_uart_top__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_uart_top__DOT__clk__0))));
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSelf->tb_uart_top__DOT__rx_valid) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_uart_top__DOT__rx_valid__0)));
    vlSelf->__VactTriggered.set(3U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_top__DOT__clk__0 
        = vlSelf->tb_uart_top__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_top__DOT__rst_n__0 
        = vlSelf->tb_uart_top__DOT__rst_n;
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_top__DOT__rx_valid__0 
        = vlSelf->tb_uart_top__DOT__rx_valid;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(2U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_uart_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
