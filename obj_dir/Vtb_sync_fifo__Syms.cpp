// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_sync_fifo__pch.h"
#include "Vtb_sync_fifo.h"
#include "Vtb_sync_fifo___024root.h"
#include "Vtb_sync_fifo___024unit.h"

// FUNCTIONS
Vtb_sync_fifo__Syms::~Vtb_sync_fifo__Syms()
{
#ifdef VM_TRACE
    if (__Vm_dumping) _traceDumpClose();
#endif  // VM_TRACE
}

void Vtb_sync_fifo__Syms::_traceDump() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumperp->dump(VL_TIME_Q());
}

void Vtb_sync_fifo__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void Vtb_sync_fifo__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}

Vtb_sync_fifo__Syms::Vtb_sync_fifo__Syms(VerilatedContext* contextp, const char* namep, Vtb_sync_fifo* modelp)
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
    __Vscope_tb_sync_fifo.configure(this, name(), "tb_sync_fifo", "tb_sync_fifo", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_sync_fifo__check_flags.configure(this, name(), "tb_sync_fifo.check_flags", "check_flags", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_sync_fifo__pop.configure(this, name(), "tb_sync_fifo.pop", "pop", -12, VerilatedScope::SCOPE_OTHER);
}
