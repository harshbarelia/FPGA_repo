// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_reset_sync.h for the primary calling header

#include "Vtb_reset_sync__pch.h"
#include "Vtb_reset_sync__Syms.h"
#include "Vtb_reset_sync___024root.h"

void Vtb_reset_sync___024root___ctor_var_reset(Vtb_reset_sync___024root* vlSelf);

Vtb_reset_sync___024root::Vtb_reset_sync___024root(Vtb_reset_sync__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_reset_sync___024root___ctor_var_reset(this);
}

void Vtb_reset_sync___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtb_reset_sync___024root::~Vtb_reset_sync___024root() {
}
