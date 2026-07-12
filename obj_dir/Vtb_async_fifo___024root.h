// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_async_fifo.h for the primary calling header

#ifndef VERILATED_VTB_ASYNC_FIFO___024ROOT_H_
#define VERILATED_VTB_ASYNC_FIFO___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_async_fifo__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_async_fifo___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_async_fifo__DOT__wr_clk;
    CData/*0:0*/ tb_async_fifo__DOT__rd_clk;
    CData/*0:0*/ tb_async_fifo__DOT__wr_rst_n;
    CData/*0:0*/ tb_async_fifo__DOT__rd_rst_n;
    CData/*0:0*/ tb_async_fifo__DOT__wr_en;
    CData/*0:0*/ tb_async_fifo__DOT__rd_en;
    CData/*7:0*/ tb_async_fifo__DOT__in_data;
    CData/*7:0*/ tb_async_fifo__DOT__out_data;
    CData/*0:0*/ tb_async_fifo__DOT__full;
    CData/*0:0*/ tb_async_fifo__DOT__empty;
    CData/*4:0*/ tb_async_fifo__DOT__dut__DOT__wr_ptr_bin;
    CData/*4:0*/ tb_async_fifo__DOT__dut__DOT__wr_ptr_bin_next;
    CData/*4:0*/ tb_async_fifo__DOT__dut__DOT__rd_ptr_bin;
    CData/*4:0*/ tb_async_fifo__DOT__dut__DOT__rd_ptr_bin_next;
    CData/*4:0*/ tb_async_fifo__DOT__dut__DOT__wr_ptr_gray;
    CData/*4:0*/ tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_next;
    CData/*4:0*/ tb_async_fifo__DOT__dut__DOT__rd_ptr_gray;
    CData/*4:0*/ tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_next;
    CData/*4:0*/ tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_sync1;
    CData/*4:0*/ tb_async_fifo__DOT__dut__DOT__wr_ptr_gray_sync2;
    CData/*4:0*/ tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync1;
    CData/*4:0*/ tb_async_fifo__DOT__dut__DOT__rd_ptr_gray_sync2;
    CData/*3:0*/ __Vdlyvdim0__tb_async_fifo__DOT__dut__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__tb_async_fifo__DOT__dut__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__tb_async_fifo__DOT__dut__DOT__mem__v0;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_async_fifo__DOT__wr_clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_async_fifo__DOT__wr_rst_n__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_async_fifo__DOT__rd_clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_async_fifo__DOT__rd_rst_n__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 16> tb_async_fifo__DOT__dut__DOT__mem;
    VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    VlQueue<CData/*7:0*/> tb_async_fifo__DOT__model_q;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h687c3cce__0;
    VlTriggerScheduler __VtrigSched_hfb329b30__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<5> __VactTriggered;
    VlTriggerVec<5> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_async_fifo__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_async_fifo___024root(Vtb_async_fifo__Syms* symsp, const char* v__name);
    ~Vtb_async_fifo___024root();
    VL_UNCOPYABLE(Vtb_async_fifo___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
