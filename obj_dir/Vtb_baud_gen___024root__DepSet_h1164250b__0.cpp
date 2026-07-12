// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_baud_gen.h for the primary calling header

#include "Vtb_baud_gen__pch.h"
#include "Vtb_baud_gen__Syms.h"
#include "Vtb_baud_gen___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_baud_gen___024root___eval_initial__TOP__Vtiming__1(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Init
    IData/*31:0*/ tb_baud_gen__DOT____Vrepeat1;
    tb_baud_gen__DOT____Vrepeat1 = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x5f67656eU;
    __Vtemp_1[2U] = 0x62617564U;
    __Vtemp_1[3U] = 0x74625fU;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(4, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelf->tb_baud_gen__DOT__rst_n = 0U;
    co_await vlSelf->__VtrigSched_haacabe3f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_baud_gen.clk)", 
                                                       "tb/tb_baud_gen.sv", 
                                                       29);
    co_await vlSelf->__VtrigSched_haacabe3f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_baud_gen.clk)", 
                                                       "tb/tb_baud_gen.sv", 
                                                       29);
    co_await vlSelf->__VtrigSched_haacabe3f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_baud_gen.clk)", 
                                                       "tb/tb_baud_gen.sv", 
                                                       29);
    vlSelf->tb_baud_gen__DOT__rst_n = 1U;
    tb_baud_gen__DOT____Vrepeat1 = 0x258U;
    while (VL_LTS_III(32, 0U, tb_baud_gen__DOT____Vrepeat1)) {
        co_await vlSelf->__VtrigSched_haacabe3f__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_baud_gen.clk)", 
                                                           "tb/tb_baud_gen.sv", 
                                                           32);
        tb_baud_gen__DOT____Vrepeat1 = (tb_baud_gen__DOT____Vrepeat1 
                                        - (IData)(1U));
    }
    VL_FINISH_MT("tb/tb_baud_gen.sv", 33, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_baud_gen___024root___dump_triggers__act(Vtb_baud_gen___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_baud_gen___024root___eval_triggers__act(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->tb_baud_gen__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_baud_gen__DOT__clk__0))) 
                                     | ((~ (IData)(vlSelf->tb_baud_gen__DOT__rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_baud_gen__DOT__rst_n__0))));
    vlSelf->__VactTriggered.set(1U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSelf->tb_baud_gen__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_baud_gen__DOT__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__tb_baud_gen__DOT__clk__0 
        = vlSelf->tb_baud_gen__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_baud_gen__DOT__rst_n__0 
        = vlSelf->tb_baud_gen__DOT__rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_baud_gen___024root___dump_triggers__act(vlSelf);
    }
#endif
}
