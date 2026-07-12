// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_reset_sync.h for the primary calling header

#ifndef VERILATED_VTB_RESET_SYNC___024ROOT_H_
#define VERILATED_VTB_RESET_SYNC___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_reset_sync__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_reset_sync___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_reset_sync__DOT__clk;
    CData/*0:0*/ tb_reset_sync__DOT__rst_in;
    CData/*1:0*/ tb_reset_sync__DOT__dut__DOT__sync_ff;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_reset_sync__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_reset_sync__DOT__rst_in__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_ha3a9ee0a__0;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_reset_sync__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_reset_sync___024root(Vtb_reset_sync__Syms* symsp, const char* v__name);
    ~Vtb_reset_sync___024root();
    VL_UNCOPYABLE(Vtb_reset_sync___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
