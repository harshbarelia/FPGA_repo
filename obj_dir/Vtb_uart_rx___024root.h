// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_uart_rx.h for the primary calling header

#ifndef VERILATED_VTB_UART_RX___024ROOT_H_
#define VERILATED_VTB_UART_RX___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_uart_rx__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_uart_rx___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_uart_rx__DOT__clk;
    CData/*0:0*/ tb_uart_rx__DOT__rst_n;
    CData/*0:0*/ tb_uart_rx__DOT__rx;
    CData/*7:0*/ tb_uart_rx__DOT__rx_data;
    CData/*0:0*/ tb_uart_rx__DOT__rx_valid;
    CData/*0:0*/ tb_uart_rx__DOT__framing_error;
    CData/*1:0*/ tb_uart_rx__DOT__dut__DOT__state;
    CData/*3:0*/ tb_uart_rx__DOT__dut__DOT__cnt;
    CData/*2:0*/ tb_uart_rx__DOT__dut__DOT__bit_idx;
    CData/*7:0*/ tb_uart_rx__DOT__dut__DOT__shreg;
    CData/*0:0*/ tb_uart_rx__DOT__dut__DOT__rx_s1;
    CData/*0:0*/ tb_uart_rx__DOT__dut__DOT__rx_s2;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_uart_rx__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_uart_rx__DOT__rst_n__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ tb_uart_rx__DOT__send_byte__Vstatic__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hafcd772c__0;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_uart_rx__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_uart_rx___024root(Vtb_uart_rx__Syms* symsp, const char* v__name);
    ~Vtb_uart_rx___024root();
    VL_UNCOPYABLE(Vtb_uart_rx___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
