// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_baud_gen.h for the primary calling header

#ifndef VERILATED_VTB_BAUD_GEN___024ROOT_H_
#define VERILATED_VTB_BAUD_GEN___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_baud_gen__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_baud_gen___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_baud_gen__DOT__clk;
    CData/*0:0*/ tb_baud_gen__DOT__rst_n;
    CData/*0:0*/ tb_baud_gen__DOT__baud_tick;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_baud_gen__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_baud_gen__DOT__rst_n__0;
    CData/*0:0*/ __VactContinue;
    SData/*8:0*/ tb_baud_gen__DOT__dut__DOT__count;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_haacabe3f__0;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_baud_gen__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_baud_gen___024root(Vtb_baud_gen__Syms* symsp, const char* v__name);
    ~Vtb_baud_gen___024root();
    VL_UNCOPYABLE(Vtb_baud_gen___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
