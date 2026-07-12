// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_uart_rx__Syms.h"


void Vtb_uart_rx___024root__trace_chg_0_sub_0(Vtb_uart_rx___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_uart_rx___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_rx___024root__trace_chg_0\n"); );
    // Init
    Vtb_uart_rx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_rx___024root*>(voidSelf);
    Vtb_uart_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_uart_rx___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_uart_rx___024root__trace_chg_0_sub_0(Vtb_uart_rx___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_rx___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->tb_uart_rx__DOT__rx_data),8);
        bufp->chgBit(oldp+1,(vlSelf->tb_uart_rx__DOT__rx_valid));
        bufp->chgBit(oldp+2,(vlSelf->tb_uart_rx__DOT__framing_error));
        bufp->chgCData(oldp+3,(vlSelf->tb_uart_rx__DOT__dut__DOT__state),2);
        bufp->chgCData(oldp+4,(vlSelf->tb_uart_rx__DOT__dut__DOT__cnt),4);
        bufp->chgCData(oldp+5,(vlSelf->tb_uart_rx__DOT__dut__DOT__bit_idx),3);
        bufp->chgCData(oldp+6,(vlSelf->tb_uart_rx__DOT__dut__DOT__shreg),8);
        bufp->chgBit(oldp+7,(vlSelf->tb_uart_rx__DOT__dut__DOT__rx_s1));
        bufp->chgBit(oldp+8,(vlSelf->tb_uart_rx__DOT__dut__DOT__rx_s2));
    }
    bufp->chgBit(oldp+9,(vlSelf->tb_uart_rx__DOT__clk));
    bufp->chgBit(oldp+10,(vlSelf->tb_uart_rx__DOT__rst_n));
    bufp->chgBit(oldp+11,(vlSelf->tb_uart_rx__DOT__rx));
    bufp->chgIData(oldp+12,(vlSelf->tb_uart_rx__DOT__send_byte__Vstatic__i),32);
}

void Vtb_uart_rx___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_rx___024root__trace_cleanup\n"); );
    // Init
    Vtb_uart_rx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_rx___024root*>(voidSelf);
    Vtb_uart_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
