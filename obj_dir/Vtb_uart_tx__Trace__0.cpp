// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_uart_tx__Syms.h"


void Vtb_uart_tx___024root__trace_chg_0_sub_0(Vtb_uart_tx___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_uart_tx___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_chg_0\n"); );
    // Init
    Vtb_uart_tx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_tx___024root*>(voidSelf);
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_uart_tx___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_uart_tx___024root__trace_chg_0_sub_0(Vtb_uart_tx___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->tb_uart_tx__DOT__tx));
        bufp->chgBit(oldp+1,(vlSelf->tb_uart_tx__DOT__busy));
        bufp->chgBit(oldp+2,(vlSelf->tb_uart_tx__DOT__tx_done));
        bufp->chgCData(oldp+3,(vlSelf->tb_uart_tx__DOT__dut__DOT__state),3);
        bufp->chgSData(oldp+4,(vlSelf->tb_uart_tx__DOT__dut__DOT__baud_cnt),9);
        bufp->chgBit(oldp+5,(vlSelf->tb_uart_tx__DOT__dut__DOT__baud_tick));
        bufp->chgCData(oldp+6,(vlSelf->tb_uart_tx__DOT__dut__DOT__bit_idx),3);
        bufp->chgCData(oldp+7,(vlSelf->tb_uart_tx__DOT__dut__DOT__shreg),8);
    }
    bufp->chgBit(oldp+8,(vlSelf->tb_uart_tx__DOT__clk));
    bufp->chgBit(oldp+9,(vlSelf->tb_uart_tx__DOT__rst_n));
    bufp->chgBit(oldp+10,(vlSelf->tb_uart_tx__DOT__tx_start));
    bufp->chgCData(oldp+11,(vlSelf->tb_uart_tx__DOT__tx_data),8);
}

void Vtb_uart_tx___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_cleanup\n"); );
    // Init
    Vtb_uart_tx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_tx___024root*>(voidSelf);
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
