// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_sync_fifo__Syms.h"


VL_ATTR_COLD void Vtb_sync_fifo___024root__trace_init_sub__TOP__0(Vtb_sync_fifo___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("tb_sync_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+27,0,"DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+28,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+29,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+22,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+26,0,"in_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1,0,"out_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+2,0,"full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+27,0,"DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+28,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+29,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+22,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+26,0,"in_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+25,0,"rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"out_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+2,0,"full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("mem", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+4+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+20,0,"wr_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+21,0,"rd_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("u_assert_sync_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+29,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+22,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"full",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"empty",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+20,0,"wr_ptr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+21,0,"rd_ptr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_sync_fifo___024root__trace_init_top(Vtb_sync_fifo___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root__trace_init_top\n"); );
    // Body
    Vtb_sync_fifo___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_sync_fifo___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_sync_fifo___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_sync_fifo___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_sync_fifo___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_sync_fifo___024root__trace_register(Vtb_sync_fifo___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtb_sync_fifo___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb_sync_fifo___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb_sync_fifo___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb_sync_fifo___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_sync_fifo___024root__trace_const_0_sub_0(Vtb_sync_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_sync_fifo___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root__trace_const_0\n"); );
    // Init
    Vtb_sync_fifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_sync_fifo___024root*>(voidSelf);
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_sync_fifo___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_sync_fifo___024root__trace_const_0_sub_0(Vtb_sync_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+27,(8U),32);
    bufp->fullIData(oldp+28,(0x10U),32);
    bufp->fullIData(oldp+29,(4U),32);
}

VL_ATTR_COLD void Vtb_sync_fifo___024root__trace_full_0_sub_0(Vtb_sync_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_sync_fifo___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root__trace_full_0\n"); );
    // Init
    Vtb_sync_fifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_sync_fifo___024root*>(voidSelf);
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_sync_fifo___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_sync_fifo___024root__trace_full_0_sub_0(Vtb_sync_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sync_fifo___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->tb_sync_fifo__DOT__out_data),8);
    bufp->fullBit(oldp+2,((((1U & ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr) 
                                   >> 4U)) != (1U & 
                                               ((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                                                >> 4U))) 
                           & ((0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr)) 
                              == (0xfU & (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr))))));
    bufp->fullBit(oldp+3,(((IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr) 
                           == (IData)(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr))));
    bufp->fullCData(oldp+4,(vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[0]),8);
    bufp->fullCData(oldp+5,(vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[1]),8);
    bufp->fullCData(oldp+6,(vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[2]),8);
    bufp->fullCData(oldp+7,(vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[3]),8);
    bufp->fullCData(oldp+8,(vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[4]),8);
    bufp->fullCData(oldp+9,(vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[5]),8);
    bufp->fullCData(oldp+10,(vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[6]),8);
    bufp->fullCData(oldp+11,(vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[7]),8);
    bufp->fullCData(oldp+12,(vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[8]),8);
    bufp->fullCData(oldp+13,(vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[9]),8);
    bufp->fullCData(oldp+14,(vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[10]),8);
    bufp->fullCData(oldp+15,(vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[11]),8);
    bufp->fullCData(oldp+16,(vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[12]),8);
    bufp->fullCData(oldp+17,(vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[13]),8);
    bufp->fullCData(oldp+18,(vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[14]),8);
    bufp->fullCData(oldp+19,(vlSelf->tb_sync_fifo__DOT__dut__DOT__mem[15]),8);
    bufp->fullCData(oldp+20,(vlSelf->tb_sync_fifo__DOT__dut__DOT__wr_ptr),5);
    bufp->fullCData(oldp+21,(vlSelf->tb_sync_fifo__DOT__dut__DOT__rd_ptr),5);
    bufp->fullBit(oldp+22,(vlSelf->tb_sync_fifo__DOT__clk));
    bufp->fullBit(oldp+23,(vlSelf->tb_sync_fifo__DOT__rst_n));
    bufp->fullBit(oldp+24,(vlSelf->tb_sync_fifo__DOT__wr_en));
    bufp->fullBit(oldp+25,(vlSelf->tb_sync_fifo__DOT__rd_en));
    bufp->fullCData(oldp+26,(vlSelf->tb_sync_fifo__DOT__in_data),8);
}
