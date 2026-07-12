// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sync_fifo.h for the primary calling header

#include "Vtb_sync_fifo__pch.h"
#include "Vtb_sync_fifo__Syms.h"
#include "Vtb_sync_fifo___024root.h"

VL_ATTR_COLD void Vtb_sync_fifo___024root___eval_initial__TOP(Vtb_sync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    vlSelf->tb_sync_fifo__DOT__clk = 0U;
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x6669666fU;
    __Vtemp_1[2U] = 0x796e635fU;
    __Vtemp_1[3U] = 0x74625f73U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(4, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sync_fifo___024root___dump_triggers__stl(Vtb_sync_fifo___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_sync_fifo___024root___eval_triggers__stl(Vtb_sync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_sync_fifo___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
