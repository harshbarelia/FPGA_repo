// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_async_fifo__pch.h"
#include "Vtb_async_fifo.h"
#include "Vtb_async_fifo___024root.h"
#include "Vtb_async_fifo___024unit.h"

// FUNCTIONS
Vtb_async_fifo__Syms::~Vtb_async_fifo__Syms()
{
}

Vtb_async_fifo__Syms::Vtb_async_fifo__Syms(VerilatedContext* contextp, const char* namep, Vtb_async_fifo* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_tb_async_fifo.configure(this, name(), "tb_async_fifo", "tb_async_fifo", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_async_fifo__read_data.configure(this, name(), "tb_async_fifo.read_data", "read_data", -12, VerilatedScope::SCOPE_OTHER);
}
