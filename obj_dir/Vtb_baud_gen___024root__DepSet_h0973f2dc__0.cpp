// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_baud_gen.h for the primary calling header

#include "Vtb_baud_gen__pch.h"
#include "Vtb_baud_gen___024root.h"

VlCoroutine Vtb_baud_gen___024root___eval_initial__TOP__Vtiming__0(Vtb_baud_gen___024root* vlSelf);
VlCoroutine Vtb_baud_gen___024root___eval_initial__TOP__Vtiming__1(Vtb_baud_gen___024root* vlSelf);

void Vtb_baud_gen___024root___eval_initial(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___eval_initial\n"); );
    // Body
    Vtb_baud_gen___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_baud_gen___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_baud_gen__DOT__clk__0 
        = vlSelf->tb_baud_gen__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_baud_gen__DOT__rst_n__0 
        = vlSelf->tb_baud_gen__DOT__rst_n;
}

VL_INLINE_OPT VlCoroutine Vtb_baud_gen___024root___eval_initial__TOP__Vtiming__0(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->tb_baud_gen__DOT__clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                           "tb/tb_baud_gen.sv", 
                                           21);
        vlSelf->tb_baud_gen__DOT__clk = (1U & (~ (IData)(vlSelf->tb_baud_gen__DOT__clk)));
    }
}

void Vtb_baud_gen___024root___eval_act(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtb_baud_gen___024root___nba_sequent__TOP__0(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*8:0*/ __Vdly__tb_baud_gen__DOT__dut__DOT__count;
    __Vdly__tb_baud_gen__DOT__dut__DOT__count = 0;
    // Body
    __Vdly__tb_baud_gen__DOT__dut__DOT__count = vlSelf->tb_baud_gen__DOT__dut__DOT__count;
    if (vlSelf->tb_baud_gen__DOT__rst_n) {
        if ((0x1b1U == (IData)(vlSelf->tb_baud_gen__DOT__dut__DOT__count))) {
            vlSelf->tb_baud_gen__DOT__baud_tick = 1U;
            __Vdly__tb_baud_gen__DOT__dut__DOT__count = 0U;
        } else {
            __Vdly__tb_baud_gen__DOT__dut__DOT__count 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->tb_baud_gen__DOT__dut__DOT__count)));
            vlSelf->tb_baud_gen__DOT__baud_tick = 0U;
        }
    } else {
        __Vdly__tb_baud_gen__DOT__dut__DOT__count = 0U;
        vlSelf->tb_baud_gen__DOT__baud_tick = 0U;
    }
    vlSelf->tb_baud_gen__DOT__dut__DOT__count = __Vdly__tb_baud_gen__DOT__dut__DOT__count;
}

void Vtb_baud_gen___024root___eval_nba(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_baud_gen___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vtb_baud_gen___024root___timing_resume(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___timing_resume\n"); );
    // Body
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_haacabe3f__0.resume("@(posedge tb_baud_gen.clk)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_baud_gen___024root___timing_commit(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___timing_commit\n"); );
    // Body
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_haacabe3f__0.commit("@(posedge tb_baud_gen.clk)");
    }
}

void Vtb_baud_gen___024root___eval_triggers__act(Vtb_baud_gen___024root* vlSelf);

bool Vtb_baud_gen___024root___eval_phase__act(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_baud_gen___024root___eval_triggers__act(vlSelf);
    Vtb_baud_gen___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_baud_gen___024root___timing_resume(vlSelf);
        Vtb_baud_gen___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_baud_gen___024root___eval_phase__nba(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_baud_gen___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_baud_gen___024root___dump_triggers__nba(Vtb_baud_gen___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_baud_gen___024root___dump_triggers__act(Vtb_baud_gen___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_baud_gen___024root___eval(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_baud_gen___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_baud_gen.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_baud_gen___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_baud_gen.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_baud_gen___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_baud_gen___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_baud_gen___024root___eval_debug_assertions(Vtb_baud_gen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_baud_gen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_baud_gen___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
