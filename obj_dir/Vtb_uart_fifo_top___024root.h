// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_uart_fifo_top.h for the primary calling header

#ifndef VERILATED_VTB_UART_FIFO_TOP___024ROOT_H_
#define VERILATED_VTB_UART_FIFO_TOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_uart_fifo_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_uart_fifo_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_uart_fifo_top__DOT__clk;
    CData/*0:0*/ tb_uart_fifo_top__DOT__rst_n;
    CData/*0:0*/ tb_uart_fifo_top__DOT__tx_fifo_wr_en;
    CData/*7:0*/ tb_uart_fifo_top__DOT__tx_fifo_din;
    CData/*0:0*/ tb_uart_fifo_top__DOT__tx_fifo_full;
    CData/*0:0*/ tb_uart_fifo_top__DOT__tx_fifo_empty;
    CData/*0:0*/ tb_uart_fifo_top__DOT__rx_fifo_rd_en;
    CData/*7:0*/ tb_uart_fifo_top__DOT__rx_fifo_dout;
    CData/*0:0*/ tb_uart_fifo_top__DOT__rx_fifo_full;
    CData/*0:0*/ tb_uart_fifo_top__DOT__rx_fifo_empty;
    CData/*0:0*/ tb_uart_fifo_top__DOT__tx_busy;
    CData/*0:0*/ tb_uart_fifo_top__DOT__framing_error;
    CData/*0:0*/ tb_uart_fifo_top__DOT__tx_serial;
    CData/*0:0*/ tb_uart_fifo_top__DOT__dut__DOT__tx_start;
    CData/*7:0*/ tb_uart_fifo_top__DOT__dut__DOT__tx_data;
    CData/*0:0*/ tb_uart_fifo_top__DOT__dut__DOT__tx_done;
    CData/*7:0*/ tb_uart_fifo_top__DOT__dut__DOT__rx_data;
    CData/*0:0*/ tb_uart_fifo_top__DOT__dut__DOT__rx_valid;
    CData/*0:0*/ tb_uart_fifo_top__DOT__dut__DOT__rx_valid_d;
    CData/*0:0*/ tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_rd_en;
    CData/*7:0*/ tb_uart_fifo_top__DOT__dut__DOT__tx_fifo_dout;
    CData/*0:0*/ tb_uart_fifo_top__DOT__dut__DOT__rx_fifo_wr_en;
    CData/*1:0*/ tb_uart_fifo_top__DOT__dut__DOT__txm_state;
    CData/*4:0*/ tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr;
    CData/*4:0*/ tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr;
    CData/*4:0*/ tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__wr_ptr;
    CData/*4:0*/ tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__rd_ptr;
    CData/*1:0*/ tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state;
    CData/*3:0*/ tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__baud_cnt;
    CData/*2:0*/ tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__bit_idx;
    CData/*7:0*/ tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg;
    CData/*1:0*/ tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state;
    CData/*3:0*/ tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt;
    CData/*2:0*/ tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__bit_idx;
    CData/*7:0*/ tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__shreg;
    CData/*0:0*/ tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__rx_s1;
    CData/*0:0*/ tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__rx_s2;
    CData/*1:0*/ __Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__state;
    CData/*7:0*/ __Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_tx__DOT__shreg;
    CData/*3:0*/ __Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__cnt;
    CData/*1:0*/ __Vdly__tb_uart_fifo_top__DOT__dut__DOT__u_rx__DOT__state;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_uart_fifo_top__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_uart_fifo_top__DOT__rst_n__0;
    CData/*0:0*/ __Vtrigprevexpr_h601fd02a__0;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 16> tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__mem;
    VlUnpacked<CData/*7:0*/, 16> tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__mem;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hbf5f2e57__0;
    VlTriggerScheduler __VtrigSched_hc8280648__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_uart_fifo_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_uart_fifo_top___024root(Vtb_uart_fifo_top__Syms* symsp, const char* v__name);
    ~Vtb_uart_fifo_top___024root();
    VL_UNCOPYABLE(Vtb_uart_fifo_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
