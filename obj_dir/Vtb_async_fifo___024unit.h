// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_async_fifo.h for the primary calling header

#ifndef VERILATED_VTB_ASYNC_FIFO___024UNIT_H_
#define VERILATED_VTB_ASYNC_FIFO___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_async_fifo__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_async_fifo___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vtb_async_fifo__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_async_fifo___024unit(Vtb_async_fifo__Syms* symsp, const char* v__name);
    ~Vtb_async_fifo___024unit();
    VL_UNCOPYABLE(Vtb_async_fifo___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
