// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_uart_csr__Syms.h"


void Vtb_uart_csr___024root__trace_chg_0_sub_0(Vtb_uart_csr___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_uart_csr___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_csr___024root__trace_chg_0\n"); );
    // Init
    Vtb_uart_csr___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_csr___024root*>(voidSelf);
    Vtb_uart_csr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_uart_csr___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_uart_csr___024root__trace_chg_0_sub_0(Vtb_uart_csr___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_csr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_csr___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,(vlSelf->tb_uart_csr__DOT__rst_n));
        bufp->chgBit(oldp+1,(vlSelf->tb_uart_csr__DOT__wr_en));
        bufp->chgCData(oldp+2,(vlSelf->tb_uart_csr__DOT__wstrb),4);
        bufp->chgCData(oldp+3,(vlSelf->tb_uart_csr__DOT__addr),4);
        bufp->chgIData(oldp+4,(vlSelf->tb_uart_csr__DOT__wdata),32);
        bufp->chgBit(oldp+5,(vlSelf->tb_uart_csr__DOT__rd_en));
        bufp->chgIData(oldp+6,(vlSelf->tb_uart_csr__DOT__status_val),32);
        bufp->chgIData(oldp+7,(vlSelf->tb_uart_csr__DOT__rxdata_val),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+8,(vlSelf->tb_uart_csr__DOT__tx_serial));
        bufp->chgBit(oldp+9,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_csr__DOT__tx_start_pulse));
        bufp->chgCData(oldp+10,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_csr__DOT__tx_data_reg),8);
        bufp->chgBit(oldp+11,(vlSelf->tb_uart_csr__DOT__dut__DOT__tx_busy));
        bufp->chgBit(oldp+12,(vlSelf->tb_uart_csr__DOT__dut__DOT__tx_done));
        bufp->chgCData(oldp+13,(vlSelf->tb_uart_csr__DOT__dut__DOT__rx_data),8);
        bufp->chgBit(oldp+14,(vlSelf->tb_uart_csr__DOT__dut__DOT__rx_valid));
        bufp->chgBit(oldp+15,(vlSelf->tb_uart_csr__DOT__dut__DOT__framing_error));
        bufp->chgBit(oldp+16,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_csr__DOT__rx_enable_reg));
        bufp->chgBit(oldp+17,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_csr__DOT__rx_valid_sticky));
        bufp->chgBit(oldp+18,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_csr__DOT__framing_error_sticky));
        bufp->chgCData(oldp+19,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_csr__DOT__rx_data_reg),8);
        bufp->chgCData(oldp+20,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_rx__DOT__state),2);
        bufp->chgCData(oldp+21,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_rx__DOT__cnt),4);
        bufp->chgCData(oldp+22,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_rx__DOT__bit_idx),3);
        bufp->chgCData(oldp+23,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_rx__DOT__shreg),8);
        bufp->chgBit(oldp+24,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_rx__DOT__rx_s1));
        bufp->chgBit(oldp+25,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_rx__DOT__rx_s2));
        bufp->chgCData(oldp+26,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_tx__DOT__state),3);
        bufp->chgCData(oldp+27,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_tx__DOT__baud_cnt),4);
        bufp->chgBit(oldp+28,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_tx__DOT__baud_tick));
        bufp->chgCData(oldp+29,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_tx__DOT__bit_idx),3);
        bufp->chgCData(oldp+30,(vlSelf->tb_uart_csr__DOT__dut__DOT__u_tx__DOT__shreg),8);
    }
    bufp->chgBit(oldp+31,(vlSelf->tb_uart_csr__DOT__clk));
    bufp->chgIData(oldp+32,(vlSelf->tb_uart_csr__DOT__rdata),32);
}

void Vtb_uart_csr___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_csr___024root__trace_cleanup\n"); );
    // Init
    Vtb_uart_csr___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_csr___024root*>(voidSelf);
    Vtb_uart_csr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
