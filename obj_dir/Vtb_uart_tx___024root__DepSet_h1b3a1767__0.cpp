// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_uart_tx.h for the primary calling header

#include "Vtb_uart_tx__pch.h"
#include "Vtb_uart_tx__Syms.h"
#include "Vtb_uart_tx___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_uart_tx___024root___eval_initial__TOP__Vtiming__0(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    IData/*31:0*/ tb_uart_tx__DOT____Vrepeat1;
    tb_uart_tx__DOT____Vrepeat1 = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x745f7478U;
    __Vtemp_1[2U] = 0x5f756172U;
    __Vtemp_1[3U] = 0x7462U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(4, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelf->tb_uart_tx__DOT__rst_n = 0U;
    vlSelf->tb_uart_tx__DOT__tx_start = 0U;
    vlSelf->tb_uart_tx__DOT__tx_data = 0xa5U;
    co_await vlSelf->__VtrigSched_h3fba570b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_tx.clk)", 
                                                       "tb/tb_uart_tx.sv", 
                                                       38);
    co_await vlSelf->__VtrigSched_h3fba570b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_tx.clk)", 
                                                       "tb/tb_uart_tx.sv", 
                                                       38);
    co_await vlSelf->__VtrigSched_h3fba570b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_tx.clk)", 
                                                       "tb/tb_uart_tx.sv", 
                                                       38);
    vlSelf->tb_uart_tx__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_h3fba570b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_tx.clk)", 
                                                       "tb/tb_uart_tx.sv", 
                                                       41);
    vlSelf->tb_uart_tx__DOT__tx_start = 1U;
    co_await vlSelf->__VtrigSched_h3fba570b__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_tx.clk)", 
                                                       "tb/tb_uart_tx.sv", 
                                                       43);
    vlSelf->tb_uart_tx__DOT__tx_start = 0U;
    tb_uart_tx__DOT____Vrepeat1 = 0x146cU;
    while (VL_LTS_III(32, 0U, tb_uart_tx__DOT____Vrepeat1)) {
        co_await vlSelf->__VtrigSched_h3fba570b__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_uart_tx.clk)", 
                                                           "tb/tb_uart_tx.sv", 
                                                           46);
        tb_uart_tx__DOT____Vrepeat1 = (tb_uart_tx__DOT____Vrepeat1 
                                       - (IData)(1U));
    }
    VL_FINISH_MT("tb/tb_uart_tx.sv", 47, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_tx___024root___dump_triggers__act(Vtb_uart_tx___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_uart_tx___024root___eval_triggers__act(Vtb_uart_tx___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->tb_uart_tx__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_uart_tx__DOT__clk__0))) 
                                     | ((~ (IData)(vlSelf->tb_uart_tx__DOT__rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_uart_tx__DOT__rst_n__0))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->tb_uart_tx__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_uart_tx__DOT__clk__0))));
    vlSelf->__VactTriggered.set(2U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_tx__DOT__clk__0 
        = vlSelf->tb_uart_tx__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_tx__DOT__rst_n__0 
        = vlSelf->tb_uart_tx__DOT__rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_uart_tx___024root___dump_triggers__act(vlSelf);
    }
#endif
}
