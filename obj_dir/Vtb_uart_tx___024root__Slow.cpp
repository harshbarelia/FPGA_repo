// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_uart_tx.h for the primary calling header

#include "Vtb_uart_tx__pch.h"
#include "Vtb_uart_tx__Syms.h"
#include "Vtb_uart_tx___024root.h"

void Vtb_uart_tx___024root___ctor_var_reset(Vtb_uart_tx___024root* vlSelf);

Vtb_uart_tx___024root::Vtb_uart_tx___024root(Vtb_uart_tx__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_uart_tx___024root___ctor_var_reset(this);
}

void Vtb_uart_tx___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtb_uart_tx___024root::~Vtb_uart_tx___024root() {
}
