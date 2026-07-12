// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_sync_fifo.h for the primary calling header

#ifndef VERILATED_VTB_SYNC_FIFO___024ROOT_H_
#define VERILATED_VTB_SYNC_FIFO___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_sync_fifo__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_sync_fifo___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_sync_fifo__DOT__clk;
    CData/*0:0*/ tb_sync_fifo__DOT__rst_n;
    CData/*0:0*/ tb_sync_fifo__DOT__wr_en;
    CData/*0:0*/ tb_sync_fifo__DOT__rd_en;
    CData/*7:0*/ tb_sync_fifo__DOT__in_data;
    CData/*7:0*/ tb_sync_fifo__DOT__out_data;
    CData/*0:0*/ tb_sync_fifo__DOT__full;
    CData/*0:0*/ tb_sync_fifo__DOT__empty;
    CData/*4:0*/ tb_sync_fifo__DOT__dut__DOT__wr_ptr;
    CData/*4:0*/ tb_sync_fifo__DOT__dut__DOT__rd_ptr;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_sync_fifo__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_sync_fifo__DOT__rst_n__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 16> tb_sync_fifo__DOT__dut__DOT__mem;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlQueue<CData/*7:0*/> tb_sync_fifo__DOT__model_q;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h77df6ff2__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_sync_fifo__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_sync_fifo___024root(Vtb_sync_fifo__Syms* symsp, const char* v__name);
    ~Vtb_sync_fifo___024root();
    VL_UNCOPYABLE(Vtb_sync_fifo___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
