// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_uart_fifo_top.h for the primary calling header

#include "Vtb_uart_fifo_top__pch.h"
#include "Vtb_uart_fifo_top__Syms.h"
#include "Vtb_uart_fifo_top___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_uart_fifo_top___024root___eval_initial__TOP__Vtiming__0(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    CData/*7:0*/ __Vtask_tb_uart_fifo_top__DOT__push_tx__0__data;
    __Vtask_tb_uart_fifo_top__DOT__push_tx__0__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_fifo_top__DOT__push_tx__1__data;
    __Vtask_tb_uart_fifo_top__DOT__push_tx__1__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_fifo_top__DOT__push_tx__2__data;
    __Vtask_tb_uart_fifo_top__DOT__push_tx__2__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_fifo_top__DOT__check_rx__3__exp;
    __Vtask_tb_uart_fifo_top__DOT__check_rx__3__exp = 0;
    CData/*7:0*/ __Vtask_tb_uart_fifo_top__DOT__check_rx__3__got;
    __Vtask_tb_uart_fifo_top__DOT__check_rx__3__got = 0;
    CData/*7:0*/ __Vtask_tb_uart_fifo_top__DOT__pop_rx__4__data;
    __Vtask_tb_uart_fifo_top__DOT__pop_rx__4__data = 0;
    IData/*31:0*/ __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__5__timeout_cycles;
    __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__5__timeout_cycles = 0;
    CData/*7:0*/ __Vtask_tb_uart_fifo_top__DOT__check_rx__6__exp;
    __Vtask_tb_uart_fifo_top__DOT__check_rx__6__exp = 0;
    CData/*7:0*/ __Vtask_tb_uart_fifo_top__DOT__check_rx__6__got;
    __Vtask_tb_uart_fifo_top__DOT__check_rx__6__got = 0;
    CData/*7:0*/ __Vtask_tb_uart_fifo_top__DOT__pop_rx__7__data;
    __Vtask_tb_uart_fifo_top__DOT__pop_rx__7__data = 0;
    IData/*31:0*/ __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__8__timeout_cycles;
    __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__8__timeout_cycles = 0;
    CData/*7:0*/ __Vtask_tb_uart_fifo_top__DOT__check_rx__9__exp;
    __Vtask_tb_uart_fifo_top__DOT__check_rx__9__exp = 0;
    CData/*7:0*/ __Vtask_tb_uart_fifo_top__DOT__check_rx__9__got;
    __Vtask_tb_uart_fifo_top__DOT__check_rx__9__got = 0;
    CData/*7:0*/ __Vtask_tb_uart_fifo_top__DOT__pop_rx__10__data;
    __Vtask_tb_uart_fifo_top__DOT__pop_rx__10__data = 0;
    IData/*31:0*/ __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__11__timeout_cycles;
    __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__11__timeout_cycles = 0;
    VlWide<5>/*159:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x5f746f70U;
    __Vtemp_1[2U] = 0x6669666fU;
    __Vtemp_1[3U] = 0x6172745fU;
    __Vtemp_1[4U] = 0x74625f75U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(5, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelf->tb_uart_fifo_top__DOT__rst_n = 0U;
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_wr_en = 0U;
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_din = 0U;
    vlSelf->tb_uart_fifo_top__DOT__rx_fifo_rd_en = 0U;
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       117);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       117);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       117);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       117);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       117);
    vlSelf->tb_uart_fifo_top__DOT__rst_n = 1U;
    VL_WRITEF("[%0t] Reset released\n",64,VL_TIME_UNITED_Q(1),
              -12);
    __Vtask_tb_uart_fifo_top__DOT__push_tx__0__data = 0xa5U;
    while ((((1U & ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr) 
                    >> 4U)) != (1U & ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr) 
                                      >> 4U))) & ((0xfU 
                                                   & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr)) 
                                                  == 
                                                  (0xfU 
                                                   & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr))))) {
        co_await vlSelf->__VtrigSched_hc8280648__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] (~ ((tb_uart_fifo_top.dut.u_tx_fifo.wr_ptr[4] != tb_uart_fifo_top.dut.u_tx_fifo.rd_ptr[4]) & (tb_uart_fifo_top.dut.u_tx_fifo.wr_ptr[3:0] == tb_uart_fifo_top.dut.u_tx_fifo.rd_ptr[3:0]))))", 
                                                           "tb/tb_uart_fifo_top.sv", 
                                                           55);
    }
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       56);
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_din = __Vtask_tb_uart_fifo_top__DOT__push_tx__0__data;
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_wr_en = 1U;
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       59);
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_wr_en = 0U;
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_din = 0U;
    VL_WRITEF("[%0t] PUSH TX = 0x%02x\n",64,VL_TIME_UNITED_Q(1),
              -12,8,(IData)(__Vtask_tb_uart_fifo_top__DOT__push_tx__0__data));
    __Vtask_tb_uart_fifo_top__DOT__push_tx__1__data = 0x3cU;
    while ((((1U & ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr) 
                    >> 4U)) != (1U & ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr) 
                                      >> 4U))) & ((0xfU 
                                                   & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr)) 
                                                  == 
                                                  (0xfU 
                                                   & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr))))) {
        co_await vlSelf->__VtrigSched_hc8280648__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] (~ ((tb_uart_fifo_top.dut.u_tx_fifo.wr_ptr[4] != tb_uart_fifo_top.dut.u_tx_fifo.rd_ptr[4]) & (tb_uart_fifo_top.dut.u_tx_fifo.wr_ptr[3:0] == tb_uart_fifo_top.dut.u_tx_fifo.rd_ptr[3:0]))))", 
                                                           "tb/tb_uart_fifo_top.sv", 
                                                           55);
    }
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       56);
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_din = __Vtask_tb_uart_fifo_top__DOT__push_tx__1__data;
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_wr_en = 1U;
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       59);
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_wr_en = 0U;
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_din = 0U;
    VL_WRITEF("[%0t] PUSH TX = 0x%02x\n",64,VL_TIME_UNITED_Q(1),
              -12,8,(IData)(__Vtask_tb_uart_fifo_top__DOT__push_tx__1__data));
    __Vtask_tb_uart_fifo_top__DOT__push_tx__2__data = 0xf0U;
    while ((((1U & ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr) 
                    >> 4U)) != (1U & ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr) 
                                      >> 4U))) & ((0xfU 
                                                   & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr)) 
                                                  == 
                                                  (0xfU 
                                                   & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr))))) {
        co_await vlSelf->__VtrigSched_hc8280648__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] (~ ((tb_uart_fifo_top.dut.u_tx_fifo.wr_ptr[4] != tb_uart_fifo_top.dut.u_tx_fifo.rd_ptr[4]) & (tb_uart_fifo_top.dut.u_tx_fifo.wr_ptr[3:0] == tb_uart_fifo_top.dut.u_tx_fifo.rd_ptr[3:0]))))", 
                                                           "tb/tb_uart_fifo_top.sv", 
                                                           55);
    }
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       56);
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_din = __Vtask_tb_uart_fifo_top__DOT__push_tx__2__data;
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_wr_en = 1U;
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       59);
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_wr_en = 0U;
    vlSelf->tb_uart_fifo_top__DOT__tx_fifo_din = 0U;
    VL_WRITEF("[%0t] PUSH TX = 0x%02x\n[%0t] Skipping TX monitor; using RX checks instead\n",
              64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_uart_fifo_top__DOT__push_tx__2__data),
              64,VL_TIME_UNITED_Q(1),-12);
    __Vtask_tb_uart_fifo_top__DOT__check_rx__3__exp = 0xa5U;
    __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__5__timeout_cycles = 0U;
    while (((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__rd_ptr) 
            == (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__wr_ptr))) {
        co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_uart_fifo_top.clk)", 
                                                           "tb/tb_uart_fifo_top.sv", 
                                                           71);
        __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__5__timeout_cycles 
            = ((IData)(1U) + __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__5__timeout_cycles);
        if (VL_UNLIKELY(VL_LTS_III(32, 0x4e20U, __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__5__timeout_cycles))) {
            VL_WRITEF("[%0t] %%Fatal: tb_uart_fifo_top.sv:74: Assertion failed in %Ntb_uart_fifo_top.wait_for_rx_data: [%0t] Timeout waiting for RX FIFO data\n",
                      64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                      64,VL_TIME_UNITED_Q(1),-12);
            VL_STOP_MT("tb/tb_uart_fifo_top.sv", 74, "");
        }
    }
    vlSelf->tb_uart_fifo_top__DOT__rx_fifo_rd_en = 1U;
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       84);
    __Vtask_tb_uart_fifo_top__DOT__pop_rx__4__data 
        = vlSelf->tb_uart_fifo_top__DOT__rx_fifo_dout;
    vlSelf->tb_uart_fifo_top__DOT__rx_fifo_rd_en = 0U;
    VL_WRITEF("[%0t] POP RX  = 0x%02x\n",64,VL_TIME_UNITED_Q(1),
              -12,8,(IData)(__Vtask_tb_uart_fifo_top__DOT__pop_rx__4__data));
    __Vtask_tb_uart_fifo_top__DOT__check_rx__3__got 
        = __Vtask_tb_uart_fifo_top__DOT__pop_rx__4__data;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_uart_fifo_top__DOT__check_rx__3__got) 
                     != (IData)(__Vtask_tb_uart_fifo_top__DOT__check_rx__3__exp)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_uart_fifo_top.sv:96: Assertion failed in %Ntb_uart_fifo_top.check_rx: [%0t] RX CHECK FAIL expected=0x%02x got=0x%02x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_uart_fifo_top__DOT__check_rx__3__exp),
                  8,__Vtask_tb_uart_fifo_top__DOT__check_rx__3__got);
        VL_STOP_MT("tb/tb_uart_fifo_top.sv", 96, "");
    }
    VL_WRITEF("[%0t] RX CHECK PASS expected=0x%02x got=0x%02x\n[%0t] RX after first byte\n",
              64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_uart_fifo_top__DOT__check_rx__3__exp),
              8,__Vtask_tb_uart_fifo_top__DOT__check_rx__3__got,
              64,VL_TIME_UNITED_Q(1),-12);
    __Vtask_tb_uart_fifo_top__DOT__check_rx__6__exp = 0x3cU;
    __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__8__timeout_cycles = 0U;
    while (((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__rd_ptr) 
            == (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__wr_ptr))) {
        co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_uart_fifo_top.clk)", 
                                                           "tb/tb_uart_fifo_top.sv", 
                                                           71);
        __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__8__timeout_cycles 
            = ((IData)(1U) + __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__8__timeout_cycles);
        if (VL_UNLIKELY(VL_LTS_III(32, 0x4e20U, __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__8__timeout_cycles))) {
            VL_WRITEF("[%0t] %%Fatal: tb_uart_fifo_top.sv:74: Assertion failed in %Ntb_uart_fifo_top.wait_for_rx_data: [%0t] Timeout waiting for RX FIFO data\n",
                      64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                      64,VL_TIME_UNITED_Q(1),-12);
            VL_STOP_MT("tb/tb_uart_fifo_top.sv", 74, "");
        }
    }
    vlSelf->tb_uart_fifo_top__DOT__rx_fifo_rd_en = 1U;
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       84);
    __Vtask_tb_uart_fifo_top__DOT__pop_rx__7__data 
        = vlSelf->tb_uart_fifo_top__DOT__rx_fifo_dout;
    vlSelf->tb_uart_fifo_top__DOT__rx_fifo_rd_en = 0U;
    VL_WRITEF("[%0t] POP RX  = 0x%02x\n",64,VL_TIME_UNITED_Q(1),
              -12,8,(IData)(__Vtask_tb_uart_fifo_top__DOT__pop_rx__7__data));
    __Vtask_tb_uart_fifo_top__DOT__check_rx__6__got 
        = __Vtask_tb_uart_fifo_top__DOT__pop_rx__7__data;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_uart_fifo_top__DOT__check_rx__6__got) 
                     != (IData)(__Vtask_tb_uart_fifo_top__DOT__check_rx__6__exp)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_uart_fifo_top.sv:96: Assertion failed in %Ntb_uart_fifo_top.check_rx: [%0t] RX CHECK FAIL expected=0x%02x got=0x%02x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_uart_fifo_top__DOT__check_rx__6__exp),
                  8,__Vtask_tb_uart_fifo_top__DOT__check_rx__6__got);
        VL_STOP_MT("tb/tb_uart_fifo_top.sv", 96, "");
    }
    VL_WRITEF("[%0t] RX CHECK PASS expected=0x%02x got=0x%02x\n[%0t] RX after second byte\n",
              64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_uart_fifo_top__DOT__check_rx__6__exp),
              8,__Vtask_tb_uart_fifo_top__DOT__check_rx__6__got,
              64,VL_TIME_UNITED_Q(1),-12);
    __Vtask_tb_uart_fifo_top__DOT__check_rx__9__exp = 0xf0U;
    __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__11__timeout_cycles = 0U;
    while (((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__rd_ptr) 
            == (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_rx_fifo__DOT__wr_ptr))) {
        co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_uart_fifo_top.clk)", 
                                                           "tb/tb_uart_fifo_top.sv", 
                                                           71);
        __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__11__timeout_cycles 
            = ((IData)(1U) + __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__11__timeout_cycles);
        if (VL_UNLIKELY(VL_LTS_III(32, 0x4e20U, __Vtask_tb_uart_fifo_top__DOT__wait_for_rx_data__11__timeout_cycles))) {
            VL_WRITEF("[%0t] %%Fatal: tb_uart_fifo_top.sv:74: Assertion failed in %Ntb_uart_fifo_top.wait_for_rx_data: [%0t] Timeout waiting for RX FIFO data\n",
                      64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                      64,VL_TIME_UNITED_Q(1),-12);
            VL_STOP_MT("tb/tb_uart_fifo_top.sv", 74, "");
        }
    }
    vlSelf->tb_uart_fifo_top__DOT__rx_fifo_rd_en = 1U;
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       84);
    __Vtask_tb_uart_fifo_top__DOT__pop_rx__10__data 
        = vlSelf->tb_uart_fifo_top__DOT__rx_fifo_dout;
    vlSelf->tb_uart_fifo_top__DOT__rx_fifo_rd_en = 0U;
    VL_WRITEF("[%0t] POP RX  = 0x%02x\n",64,VL_TIME_UNITED_Q(1),
              -12,8,(IData)(__Vtask_tb_uart_fifo_top__DOT__pop_rx__10__data));
    __Vtask_tb_uart_fifo_top__DOT__check_rx__9__got 
        = __Vtask_tb_uart_fifo_top__DOT__pop_rx__10__data;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_uart_fifo_top__DOT__check_rx__9__got) 
                     != (IData)(__Vtask_tb_uart_fifo_top__DOT__check_rx__9__exp)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_uart_fifo_top.sv:96: Assertion failed in %Ntb_uart_fifo_top.check_rx: [%0t] RX CHECK FAIL expected=0x%02x got=0x%02x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_uart_fifo_top__DOT__check_rx__9__exp),
                  8,__Vtask_tb_uart_fifo_top__DOT__check_rx__9__got);
        VL_STOP_MT("tb/tb_uart_fifo_top.sv", 96, "");
    }
    VL_WRITEF("[%0t] RX CHECK PASS expected=0x%02x got=0x%02x\n[%0t] RX after third byte\n",
              64,VL_TIME_UNITED_Q(1),-12,8,(IData)(__Vtask_tb_uart_fifo_top__DOT__check_rx__9__exp),
              8,__Vtask_tb_uart_fifo_top__DOT__check_rx__9__got,
              64,VL_TIME_UNITED_Q(1),-12);
    if (VL_UNLIKELY(vlSelf->tb_uart_fifo_top__DOT__framing_error)) {
        VL_WRITEF("[%0t] %%Fatal: tb_uart_fifo_top.sv:137: Assertion failed in %Ntb_uart_fifo_top: [%0t] Unexpected framing_error asserted\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("tb/tb_uart_fifo_top.sv", 137, "");
    }
    VL_WRITEF("[%0t] UART FIFO loopback PASSED\n",64,
              VL_TIME_UNITED_Q(1),-12);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    co_await vlSelf->__VtrigSched_hbf5f2e57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_uart_fifo_top.clk)", 
                                                       "tb/tb_uart_fifo_top.sv", 
                                                       141);
    VL_FINISH_MT("tb/tb_uart_fifo_top.sv", 142, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_fifo_top___024root___dump_triggers__act(Vtb_uart_fifo_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_uart_fifo_top___024root___eval_triggers__act(Vtb_uart_fifo_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_uart_fifo_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_fifo_top___024root___eval_triggers__act\n"); );
    // Body
    CData/*0:0*/ __Vtrigcurrexpr_h601fd02a__0;
    __Vtrigcurrexpr_h601fd02a__0 = 0;
    __Vtrigcurrexpr_h601fd02a__0 = (1U & (~ (((1U & 
                                               ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr) 
                                                >> 4U)) 
                                              != (1U 
                                                  & ((IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr) 
                                                     >> 4U))) 
                                             & ((0xfU 
                                                 & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__wr_ptr)) 
                                                == 
                                                (0xfU 
                                                 & (IData)(vlSelf->tb_uart_fifo_top__DOT__dut__DOT__u_tx_fifo__DOT__rd_ptr))))));
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->tb_uart_fifo_top__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_uart_fifo_top__DOT__clk__0))));
    vlSelf->__VactTriggered.set(1U, (((IData)(vlSelf->tb_uart_fifo_top__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_uart_fifo_top__DOT__clk__0))) 
                                     | ((~ (IData)(vlSelf->tb_uart_fifo_top__DOT__rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_uart_fifo_top__DOT__rst_n__0))));
    vlSelf->__VactTriggered.set(2U, ((IData)(__Vtrigcurrexpr_h601fd02a__0) 
                                     != (IData)(vlSelf->__Vtrigprevexpr_h601fd02a__0)));
    vlSelf->__VactTriggered.set(3U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_fifo_top__DOT__clk__0 
        = vlSelf->tb_uart_fifo_top__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_fifo_top__DOT__rst_n__0 
        = vlSelf->tb_uart_fifo_top__DOT__rst_n;
    vlSelf->__Vtrigprevexpr_h601fd02a__0 = __Vtrigcurrexpr_h601fd02a__0;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(2U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_uart_fifo_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
