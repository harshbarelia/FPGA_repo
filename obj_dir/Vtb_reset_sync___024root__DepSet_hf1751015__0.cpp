// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_reset_sync.h for the primary calling header

#include "Vtb_reset_sync__pch.h"
#include "Vtb_reset_sync__Syms.h"
#include "Vtb_reset_sync___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_reset_sync___024root___eval_initial__TOP__Vtiming__0(Vtb_reset_sync___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_reset_sync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_reset_sync___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x73796e63U;
    __Vtemp_1[2U] = 0x7365745fU;
    __Vtemp_1[3U] = 0x625f7265U;
    __Vtemp_1[4U] = 0x74U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(5, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    co_await vlSelf->__VtrigSched_ha3a9ee0a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_reset_sync.clk)", 
                                                       "tb/tb_reset_sync.sv", 
                                                       18);
    co_await vlSelf->__VtrigSched_ha3a9ee0a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_reset_sync.clk)", 
                                                       "tb/tb_reset_sync.sv", 
                                                       18);
    co_await vlSelf->__VtrigSched_ha3a9ee0a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_reset_sync.clk)", 
                                                       "tb/tb_reset_sync.sv", 
                                                       18);
    vlSelf->tb_reset_sync__DOT__rst_in = 0U;
    co_await vlSelf->__VtrigSched_ha3a9ee0a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_reset_sync.clk)", 
                                                       "tb/tb_reset_sync.sv", 
                                                       20);
    co_await vlSelf->__VtrigSched_ha3a9ee0a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_reset_sync.clk)", 
                                                       "tb/tb_reset_sync.sv", 
                                                       20);
    co_await vlSelf->__VtrigSched_ha3a9ee0a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_reset_sync.clk)", 
                                                       "tb/tb_reset_sync.sv", 
                                                       20);
    co_await vlSelf->__VtrigSched_ha3a9ee0a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_reset_sync.clk)", 
                                                       "tb/tb_reset_sync.sv", 
                                                       20);
    co_await vlSelf->__VtrigSched_ha3a9ee0a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_reset_sync.clk)", 
                                                       "tb/tb_reset_sync.sv", 
                                                       20);
    VL_FINISH_MT("tb/tb_reset_sync.sv", 21, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_reset_sync___024root___dump_triggers__act(Vtb_reset_sync___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_reset_sync___024root___eval_triggers__act(Vtb_reset_sync___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_reset_sync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_reset_sync___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->tb_reset_sync__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_reset_sync__DOT__clk__0))) 
                                     | ((~ (IData)(vlSelf->tb_reset_sync__DOT__rst_in)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_reset_sync__DOT__rst_in__0))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->tb_reset_sync__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_reset_sync__DOT__clk__0))));
    vlSelf->__VactTriggered.set(2U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_reset_sync__DOT__clk__0 
        = vlSelf->tb_reset_sync__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_reset_sync__DOT__rst_in__0 
        = vlSelf->tb_reset_sync__DOT__rst_in;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_reset_sync___024root___dump_triggers__act(vlSelf);
    }
#endif
}
