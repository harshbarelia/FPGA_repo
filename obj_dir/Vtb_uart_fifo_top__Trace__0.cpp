// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_uart_fifo_top__Syms.h"


void Vtb_uart_fifo_top___024root__trace_chg_0_sub_0(Vtb_uart_fifo_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_uart_fifo_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root__trace_chg_0\n"); );
    // Init
    Vtb_uart_fifo_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_fifo_top___024root*>(voidSelf);
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_uart_fifo_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_uart_fifo_top___024root__trace_chg_0_sub_0(Vtb_uart_fifo_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,((((1U & ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr) 
                                      >> 4U)) != (1U 
                                                  & ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr) 
                                                     >> 4U))) 
                              & ((0xfU & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr)) 
                                 == (0xfU & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr))))));
        bufp->chgBit(oldp+1,(vlSelf->tb_uart_fifo_top__DOT__tx_fifo_empty));
        bufp->chgCData(oldp+2,(vlSelf->tb_uart_fifo_top__DOT__rx_fifo_dout),8);
        bufp->chgBit(oldp+3,(vlSelf->tb_uart_fifo_top__DOT__rx_fifo_full));
        bufp->chgBit(oldp+4,(((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__rd_ptr) 
                              == (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__wr_ptr))));
        bufp->chgBit(oldp+5,(vlSelf->tb_uart_fifo_top__DOT__tx_busy));
        bufp->chgBit(oldp+6,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_start));
        bufp->chgCData(oldp+7,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_data),8);
        bufp->chgBit(oldp+8,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_done));
        bufp->chgBit(oldp+9,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_valid_d));
        bufp->chgBit(oldp+10,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_rd_en));
        bufp->chgCData(oldp+11,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_dout),8);
        bufp->chgBit(oldp+12,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_fifo_wr_en));
        bufp->chgCData(oldp+13,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__txm_state),2);
        bufp->chgCData(oldp+14,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[0]),8);
        bufp->chgCData(oldp+15,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[1]),8);
        bufp->chgCData(oldp+16,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[2]),8);
        bufp->chgCData(oldp+17,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[3]),8);
        bufp->chgCData(oldp+18,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[4]),8);
        bufp->chgCData(oldp+19,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[5]),8);
        bufp->chgCData(oldp+20,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[6]),8);
        bufp->chgCData(oldp+21,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[7]),8);
        bufp->chgCData(oldp+22,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[8]),8);
        bufp->chgCData(oldp+23,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[9]),8);
        bufp->chgCData(oldp+24,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[10]),8);
        bufp->chgCData(oldp+25,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[11]),8);
        bufp->chgCData(oldp+26,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[12]),8);
        bufp->chgCData(oldp+27,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[13]),8);
        bufp->chgCData(oldp+28,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[14]),8);
        bufp->chgCData(oldp+29,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[15]),8);
        bufp->chgCData(oldp+30,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__wr_ptr),5);
        bufp->chgCData(oldp+31,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__rd_ptr),5);
        bufp->chgCData(oldp+32,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt),4);
        bufp->chgCData(oldp+33,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__bit_idx),3);
        bufp->chgCData(oldp+34,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[0]),8);
        bufp->chgCData(oldp+35,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[1]),8);
        bufp->chgCData(oldp+36,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[2]),8);
        bufp->chgCData(oldp+37,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[3]),8);
        bufp->chgCData(oldp+38,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[4]),8);
        bufp->chgCData(oldp+39,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[5]),8);
        bufp->chgCData(oldp+40,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[6]),8);
        bufp->chgCData(oldp+41,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[7]),8);
        bufp->chgCData(oldp+42,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[8]),8);
        bufp->chgCData(oldp+43,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[9]),8);
        bufp->chgCData(oldp+44,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[10]),8);
        bufp->chgCData(oldp+45,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[11]),8);
        bufp->chgCData(oldp+46,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[12]),8);
        bufp->chgCData(oldp+47,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[13]),8);
        bufp->chgCData(oldp+48,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[14]),8);
        bufp->chgCData(oldp+49,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[15]),8);
        bufp->chgCData(oldp+50,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr),5);
        bufp->chgCData(oldp+51,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr),5);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+52,(vlSelf->tb_uart_fifo_top__DOT__framing_error));
        bufp->chgBit(oldp+53,(vlSelf->tb_uart_fifo_top__DOT__tx_serial));
        bufp->chgCData(oldp+54,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_data),8);
        bufp->chgBit(oldp+55,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_valid));
        bufp->chgCData(oldp+56,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state),2);
        bufp->chgCData(oldp+57,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt),4);
        bufp->chgCData(oldp+58,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__bit_idx),3);
        bufp->chgCData(oldp+59,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__shreg),8);
        bufp->chgBit(oldp+60,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__rx_s1));
        bufp->chgBit(oldp+61,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__rx_s2));
        bufp->chgCData(oldp+62,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state),2);
        bufp->chgCData(oldp+63,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg),8);
        bufp->chgBit(oldp+64,((1U & ((2U & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state))
                                      ? ((1U & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state)) 
                                         || (1U & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg)))
                                      : (~ (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state))))));
    }
    bufp->chgBit(oldp+65,(vlSelf->tb_uart_fifo_top__DOT__clk));
    bufp->chgBit(oldp+66,(vlSelf->tb_uart_fifo_top__DOT__rst_n));
    bufp->chgBit(oldp+67,(vlSelf->tb_uart_fifo_top__DOT__tx_fifo_wr_en));
    bufp->chgCData(oldp+68,(vlSelf->tb_uart_fifo_top__DOT__tx_fifo_din),8);
    bufp->chgBit(oldp+69,(vlSelf->tb_uart_fifo_top__DOT__rx_fifo_rd_en));
}

void Vtb_uart_fifo_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root__trace_cleanup\n"); );
    // Init
    Vtb_uart_fifo_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_fifo_top___024root*>(voidSelf);
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
