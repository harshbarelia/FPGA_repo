// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_async_fifo__Syms.h"


void Vtb_async_fifo___024root__trace_chg_0_sub_0(Vtb_async_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_async_fifo___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root__trace_chg_0\n"); );
    // Init
    Vtb_async_fifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_async_fifo___024root*>(voidSelf);
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_async_fifo___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_async_fifo___024root__trace_chg_0_sub_0(Vtb_async_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,(vlSelf->tb_async_fifo__DOT__wr_rst_n));
        bufp->chgBit(oldp+1,(vlSelf->tb_async_fifo__DOT__rd_rst_n));
        bufp->chgBit(oldp+2,(vlSelf->tb_async_fifo__DOT__wr_en));
        bufp->chgBit(oldp+3,(vlSelf->tb_async_fifo__DOT__rd_en));
        bufp->chgCData(oldp+4,(vlSelf->tb_async_fifo__DOT__in_data),8);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgCData(oldp+5,(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_bin),5);
        bufp->chgCData(oldp+6,(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync1),5);
        bufp->chgCData(oldp+7,(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync2),5);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgCData(oldp+8,(vlSelf->tb_async_fifo__DOT__out_data),8);
        bufp->chgBit(oldp+9,(vlSelf->tb_async_fifo__DOT__empty));
        bufp->chgCData(oldp+10,(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_bin),5);
        bufp->chgCData(oldp+11,(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray),5);
        bufp->chgCData(oldp+12,(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_sync1),5);
        bufp->chgCData(oldp+13,(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_sync2),5);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[5U])) {
        bufp->chgBit(oldp+14,(vlSelf->tb_async_fifo__DOT__full));
        bufp->chgCData(oldp+15,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[0]),8);
        bufp->chgCData(oldp+16,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[1]),8);
        bufp->chgCData(oldp+17,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[2]),8);
        bufp->chgCData(oldp+18,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[3]),8);
        bufp->chgCData(oldp+19,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[4]),8);
        bufp->chgCData(oldp+20,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[5]),8);
        bufp->chgCData(oldp+21,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[6]),8);
        bufp->chgCData(oldp+22,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[7]),8);
        bufp->chgCData(oldp+23,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[8]),8);
        bufp->chgCData(oldp+24,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[9]),8);
        bufp->chgCData(oldp+25,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[10]),8);
        bufp->chgCData(oldp+26,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[11]),8);
        bufp->chgCData(oldp+27,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[12]),8);
        bufp->chgCData(oldp+28,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[13]),8);
        bufp->chgCData(oldp+29,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[14]),8);
        bufp->chgCData(oldp+30,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[15]),8);
        bufp->chgCData(oldp+31,(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray),5);
    }
    bufp->chgBit(oldp+32,(vlSelf->tb_async_fifo__DOT__wr_clk));
    bufp->chgBit(oldp+33,(vlSelf->tb_async_fifo__DOT__rd_clk));
    bufp->chgCData(oldp+34,(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_bin_next),5);
    bufp->chgCData(oldp+35,(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_bin_next),5);
    bufp->chgCData(oldp+36,(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_next),5);
    bufp->chgCData(oldp+37,(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_next),5);
}

void Vtb_async_fifo___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root__trace_cleanup\n"); );
    // Init
    Vtb_async_fifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_async_fifo___024root*>(voidSelf);
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
