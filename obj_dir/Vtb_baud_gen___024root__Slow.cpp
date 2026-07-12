// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_baud_gen.h for the primary calling header

#include "Vtb_baud_gen__pch.h"
#include "Vtb_baud_gen__Syms.h"
#include "Vtb_baud_gen___024root.h"

void Vtb_baud_gen___024root___ctor_var_reset(Vtb_baud_gen___024root* vlSelf);

Vtb_baud_gen___024root::Vtb_baud_gen___024root(Vtb_baud_gen__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_baud_gen___024root___ctor_var_reset(this);
}

void Vtb_baud_gen___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtb_baud_gen___024root::~Vtb_baud_gen___024root() {
}
