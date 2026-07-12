// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_async_fifo__Syms.h"


VL_ATTR_COLD void Vtb_async_fifo___024root__trace_init_sub__TOP__0(Vtb_async_fifo___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("tb_async_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+39,0,"DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+40,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+41,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+33,0,"wr_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"rd_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"wr_rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"rd_rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"in_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+9,0,"out_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+15,0,"full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+39,0,"DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+40,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+41,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+33,0,"wr_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"wr_rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"in_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+15,0,"full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"rd_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"rd_rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+9,0,"out_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+10,0,"empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("mem", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+16+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+6,0,"wr_ptr_bin",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+35,0,"wr_ptr_bin_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+11,0,"rd_ptr_bin",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+36,0,"rd_ptr_bin_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+32,0,"wr_ptr_gray",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+37,0,"wr_ptr_gray_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+12,0,"rd_ptr_gray",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+38,0,"rd_ptr_gray_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+13,0,"wr_ptr_gray_sync1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+14,0,"wr_ptr_gray_sync2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+7,0,"rd_ptr_gray_sync1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+8,0,"rd_ptr_gray_sync2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("u_assert_async_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+41,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+33,0,"wr_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"wr_rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"full",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"wr_ptr_bin",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+37,0,"wr_ptr_gray_next",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+8,0,"rd_ptr_gray_sync2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+34,0,"rd_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"rd_rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"empty",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"rd_ptr_bin",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+12,0,"rd_ptr_gray",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+14,0,"wr_ptr_gray_sync2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_async_fifo___024root__trace_init_top(Vtb_async_fifo___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root__trace_init_top\n"); );
    // Body
    Vtb_async_fifo___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_async_fifo___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_async_fifo___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_async_fifo___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_async_fifo___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_async_fifo___024root__trace_register(Vtb_async_fifo___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtb_async_fifo___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb_async_fifo___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb_async_fifo___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb_async_fifo___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_async_fifo___024root__trace_const_0_sub_0(Vtb_async_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_async_fifo___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root__trace_const_0\n"); );
    // Init
    Vtb_async_fifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_async_fifo___024root*>(voidSelf);
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_async_fifo___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_async_fifo___024root__trace_const_0_sub_0(Vtb_async_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+39,(8U),32);
    bufp->fullIData(oldp+40,(0x10U),32);
    bufp->fullIData(oldp+41,(4U),32);
}

VL_ATTR_COLD void Vtb_async_fifo___024root__trace_full_0_sub_0(Vtb_async_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_async_fifo___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root__trace_full_0\n"); );
    // Init
    Vtb_async_fifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_async_fifo___024root*>(voidSelf);
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_async_fifo___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_async_fifo___024root__trace_full_0_sub_0(Vtb_async_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_async_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_async_fifo___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->tb_async_fifo__DOT__wr_rst_n));
    bufp->fullBit(oldp+2,(vlSelf->tb_async_fifo__DOT__rd_rst_n));
    bufp->fullBit(oldp+3,(vlSelf->tb_async_fifo__DOT__wr_en));
    bufp->fullBit(oldp+4,(vlSelf->tb_async_fifo__DOT__rd_en));
    bufp->fullCData(oldp+5,(vlSelf->tb_async_fifo__DOT__in_data),8);
    bufp->fullCData(oldp+6,(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_bin),5);
    bufp->fullCData(oldp+7,(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync1),5);
    bufp->fullCData(oldp+8,(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync2),5);
    bufp->fullCData(oldp+9,(vlSelf->tb_async_fifo__DOT__out_data),8);
    bufp->fullBit(oldp+10,(vlSelf->tb_async_fifo__DOT__empty));
    bufp->fullCData(oldp+11,(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_bin),5);
    bufp->fullCData(oldp+12,(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray),5);
    bufp->fullCData(oldp+13,(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_sync1),5);
    bufp->fullCData(oldp+14,(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_sync2),5);
    bufp->fullBit(oldp+15,(vlSelf->tb_async_fifo__DOT__full));
    bufp->fullCData(oldp+16,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[0]),8);
    bufp->fullCData(oldp+17,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[1]),8);
    bufp->fullCData(oldp+18,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[2]),8);
    bufp->fullCData(oldp+19,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[3]),8);
    bufp->fullCData(oldp+20,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[4]),8);
    bufp->fullCData(oldp+21,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[5]),8);
    bufp->fullCData(oldp+22,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[6]),8);
    bufp->fullCData(oldp+23,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[7]),8);
    bufp->fullCData(oldp+24,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[8]),8);
    bufp->fullCData(oldp+25,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[9]),8);
    bufp->fullCData(oldp+26,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[10]),8);
    bufp->fullCData(oldp+27,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[11]),8);
    bufp->fullCData(oldp+28,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[12]),8);
    bufp->fullCData(oldp+29,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[13]),8);
    bufp->fullCData(oldp+30,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[14]),8);
    bufp->fullCData(oldp+31,(vlSelf->tb_async_fifo__DOT__dut__DOT__mem[15]),8);
    bufp->fullCData(oldp+32,(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray),5);
    bufp->fullBit(oldp+33,(vlSelf->tb_async_fifo__DOT__wr_clk));
    bufp->fullBit(oldp+34,(vlSelf->tb_async_fifo__DOT__rd_clk));
    bufp->fullCData(oldp+35,(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_bin_next),5);
    bufp->fullCData(oldp+36,(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_bin_next),5);
    bufp->fullCData(oldp+37,(vlSelf->tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_next),5);
    bufp->fullCData(oldp+38,(vlSelf->tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_next),5);
}
