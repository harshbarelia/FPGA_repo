// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_uart_fifo_top__Syms.h"


VL_ATTR_COLD void Vtb_uart_fifo_top___024root__trace_init_sub__TOP__0(Vtb_uart_fifo_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("tb_uart_fifo_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+71,0,"CLK_FREQ_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+72,0,"BAUD_RATE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+73,0,"CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+74,0,"BIT_CYCLES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"tx_fifo_wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+69,0,"tx_fifo_din",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+1,0,"tx_fifo_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"tx_fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"rx_fifo_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"rx_fifo_dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+4,0,"rx_fifo_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"rx_fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"tx_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"framing_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"tx_serial",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"rx_serial",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+71,0,"CLK_FREQ_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+72,0,"BAUD_RATE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+75,0,"FIFO_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"tx_fifo_wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+69,0,"tx_fifo_din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+1,0,"tx_fifo_full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"tx_fifo_empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"rx_fifo_rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"rx_fifo_dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+4,0,"rx_fifo_full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"rx_fifo_empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"tx_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"framing_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"tx_serial",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"rx_serial",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"tx_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"tx_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+9,0,"tx_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+55,0,"rx_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+56,0,"rx_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"rx_valid_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"tx_fifo_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"tx_fifo_dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+13,0,"rx_fifo_wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+14,0,"txm_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("u_rx", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+71,0,"CLK_FREQ_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+72,0,"BAUD_RATE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+55,0,"rx_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+56,0,"rx_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"framing_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+74,0,"DIVISOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+76,0,"CNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+77,0,"DIVISOR_M1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+78,0,"MID_COUNT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+57,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+58,0,"cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+59,0,"bit_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+60,0,"shreg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+61,0,"rx_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"rx_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_rx_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+79,0,"DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+75,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+76,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+55,0,"in_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+70,0,"rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"out_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+4,0,"full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("mem", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+15+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+31,0,"wr_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+32,0,"rd_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_tx", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+71,0,"CLK_FREQ_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+72,0,"BAUD_RATE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"tx_start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"tx_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+54,0,"tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"tx_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+74,0,"DIVISOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+76,0,"CNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+80,0,"DIVISOR_M1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+63,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+33,0,"baud_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+34,0,"bit_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+64,0,"shreg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+65,0,"tx_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_tx_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+79,0,"DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+75,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+76,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+69,0,"in_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+11,0,"rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"out_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+1,0,"full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("mem", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+35+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+51,0,"wr_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+52,0,"rd_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_uart_fifo_top___024root__trace_init_top(Vtb_uart_fifo_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root__trace_init_top\n"); );
    // Body
    Vtb_uart_fifo_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_uart_fifo_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_uart_fifo_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_uart_fifo_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_uart_fifo_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_uart_fifo_top___024root__trace_register(Vtb_uart_fifo_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtb_uart_fifo_top___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb_uart_fifo_top___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb_uart_fifo_top___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb_uart_fifo_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_uart_fifo_top___024root__trace_const_0_sub_0(Vtb_uart_fifo_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_uart_fifo_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root__trace_const_0\n"); );
    // Init
    Vtb_uart_fifo_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_fifo_top___024root*>(voidSelf);
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_uart_fifo_top___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_uart_fifo_top___024root__trace_const_0_sub_0(Vtb_uart_fifo_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+71,(0xf4240U),32);
    bufp->fullIData(oldp+72,(0x186a0U),32);
    bufp->fullIData(oldp+73,(2U),32);
    bufp->fullIData(oldp+74,(0xaU),32);
    bufp->fullIData(oldp+75,(0x10U),32);
    bufp->fullIData(oldp+76,(4U),32);
    bufp->fullCData(oldp+77,(9U),4);
    bufp->fullCData(oldp+78,(5U),4);
    bufp->fullIData(oldp+79,(8U),32);
    bufp->fullCData(oldp+80,(9U),4);
}

VL_ATTR_COLD void Vtb_uart_fifo_top___024root__trace_full_0_sub_0(Vtb_uart_fifo_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_uart_fifo_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root__trace_full_0\n"); );
    // Init
    Vtb_uart_fifo_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_fifo_top___024root*>(voidSelf);
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_uart_fifo_top___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_uart_fifo_top___024root__trace_full_0_sub_0(Vtb_uart_fifo_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,((((1U & ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr) 
                                   >> 4U)) != (1U & 
                                               ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr) 
                                                >> 4U))) 
                           & ((0xfU & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr)) 
                              == (0xfU & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr))))));
    bufp->fullBit(oldp+2,(vlSelf->tb_uart_fifo_top__DOT__tx_fifo_empty));
    bufp->fullCData(oldp+3,(vlSelf->tb_uart_fifo_top__DOT__rx_fifo_dout),8);
    bufp->fullBit(oldp+4,(vlSelf->tb_uart_fifo_top__DOT__rx_fifo_full));
    bufp->fullBit(oldp+5,(((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__rd_ptr) 
                           == (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__wr_ptr))));
    bufp->fullBit(oldp+6,(vlSelf->tb_uart_fifo_top__DOT__tx_busy));
    bufp->fullBit(oldp+7,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_start));
    bufp->fullCData(oldp+8,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_data),8);
    bufp->fullBit(oldp+9,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_done));
    bufp->fullBit(oldp+10,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_valid_d));
    bufp->fullBit(oldp+11,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_rd_en));
    bufp->fullCData(oldp+12,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_dout),8);
    bufp->fullBit(oldp+13,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_fifo_wr_en));
    bufp->fullCData(oldp+14,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__txm_state),2);
    bufp->fullCData(oldp+15,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[0]),8);
    bufp->fullCData(oldp+16,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[1]),8);
    bufp->fullCData(oldp+17,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[2]),8);
    bufp->fullCData(oldp+18,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[3]),8);
    bufp->fullCData(oldp+19,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[4]),8);
    bufp->fullCData(oldp+20,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[5]),8);
    bufp->fullCData(oldp+21,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[6]),8);
    bufp->fullCData(oldp+22,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[7]),8);
    bufp->fullCData(oldp+23,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[8]),8);
    bufp->fullCData(oldp+24,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[9]),8);
    bufp->fullCData(oldp+25,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[10]),8);
    bufp->fullCData(oldp+26,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[11]),8);
    bufp->fullCData(oldp+27,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[12]),8);
    bufp->fullCData(oldp+28,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[13]),8);
    bufp->fullCData(oldp+29,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[14]),8);
    bufp->fullCData(oldp+30,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem[15]),8);
    bufp->fullCData(oldp+31,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__wr_ptr),5);
    bufp->fullCData(oldp+32,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__rd_ptr),5);
    bufp->fullCData(oldp+33,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt),4);
    bufp->fullCData(oldp+34,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__bit_idx),3);
    bufp->fullCData(oldp+35,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[0]),8);
    bufp->fullCData(oldp+36,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[1]),8);
    bufp->fullCData(oldp+37,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[2]),8);
    bufp->fullCData(oldp+38,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[3]),8);
    bufp->fullCData(oldp+39,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[4]),8);
    bufp->fullCData(oldp+40,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[5]),8);
    bufp->fullCData(oldp+41,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[6]),8);
    bufp->fullCData(oldp+42,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[7]),8);
    bufp->fullCData(oldp+43,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[8]),8);
    bufp->fullCData(oldp+44,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[9]),8);
    bufp->fullCData(oldp+45,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[10]),8);
    bufp->fullCData(oldp+46,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[11]),8);
    bufp->fullCData(oldp+47,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[12]),8);
    bufp->fullCData(oldp+48,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[13]),8);
    bufp->fullCData(oldp+49,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[14]),8);
    bufp->fullCData(oldp+50,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem[15]),8);
    bufp->fullCData(oldp+51,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr),5);
    bufp->fullCData(oldp+52,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr),5);
    bufp->fullBit(oldp+53,(vlSelf->tb_uart_fifo_top__DOT__framing_error));
    bufp->fullBit(oldp+54,(vlSelf->tb_uart_fifo_top__DOT__tx_serial));
    bufp->fullCData(oldp+55,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_data),8);
    bufp->fullBit(oldp+56,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__rx_valid));
    bufp->fullCData(oldp+57,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state),2);
    bufp->fullCData(oldp+58,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt),4);
    bufp->fullCData(oldp+59,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__bit_idx),3);
    bufp->fullCData(oldp+60,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__shreg),8);
    bufp->fullBit(oldp+61,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__rx_s1));
    bufp->fullBit(oldp+62,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__rx_s2));
    bufp->fullCData(oldp+63,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state),2);
    bufp->fullCData(oldp+64,(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg),8);
    bufp->fullBit(oldp+65,((1U & ((2U & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state))
                                   ? ((1U & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state)) 
                                      || (1U & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg)))
                                   : (~ (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state))))));
    bufp->fullBit(oldp+66,(vlSelf->tb_uart_fifo_top__DOT__clk));
    bufp->fullBit(oldp+67,(vlSelf->tb_uart_fifo_top__DOT__rst_n));
    bufp->fullBit(oldp+68,(vlSelf->tb_uart_fifo_top__DOT__tx_fifo_wr_en));
    bufp->fullCData(oldp+69,(vlSelf->tb_uart_fifo_top__DOT__tx_fifo_din),8);
    bufp->fullBit(oldp+70,(vlSelf->tb_uart_fifo_top__DOT__rx_fifo_rd_en));
}
