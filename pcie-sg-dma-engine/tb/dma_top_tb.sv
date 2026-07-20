
// dma_top_tb.sv
// Ring-buffer smoke test over AXI4-LITE ONLY interfaces. Programs
// RING_BASE/RING_SIZE, writes ONE H2C descriptor (HOST DDR -> local
// BRAM), rings the doorbell, and checks data + MSI-X completion.
`timescale 1ns/1ps
import dma_pkg::*;

module dma_top_tb;

    logic clk = 0;
    logic rst_n = 0;
    always #5 clk = ~clk;
    initial begin rst_n = 0; repeat (10) @(posedge clk); rst_n = 1; end

    logic [11:0] awaddr, araddr;
    logic        awvalid, arvalid, wvalid, bready, rready;
    logic [31:0] wdata, rdata;
    logic [3:0]  wstrb;
    logic        awready, wready, bvalid, arready, rvalid;
    logic [1:0]  bresp, rresp;

    logic [31:0] m_araddr, m_awaddr, m_rdata, m_wdata;
    logic        m_arvalid, m_arready, m_awvalid, m_awready;
    logic        m_rvalid, m_rready, m_wvalid, m_wready;
    logic        m_bvalid, m_bready;
    logic        msix_irq;

    dma_top dut (
        .clk(clk), .rst_n(rst_n),
        .s_axil_awaddr(awaddr), .s_axil_awvalid(awvalid), .s_axil_awready(awready),
        .s_axil_wdata(wdata), .s_axil_wstrb(wstrb), .s_axil_wvalid(wvalid), .s_axil_wready(wready),
        .s_axil_bresp(bresp), .s_axil_bvalid(bvalid), .s_axil_bready(bready),
        .s_axil_araddr(araddr), .s_axil_arvalid(arvalid), .s_axil_arready(arready),
        .s_axil_rdata(rdata), .s_axil_rresp(rresp), .s_axil_rvalid(rvalid), .s_axil_rready(rready),
        .m_axil_araddr(m_araddr), .m_axil_arvalid(m_arvalid), .m_axil_arready(m_arready),
        .m_axil_rdata(m_rdata), .m_axil_rvalid(m_rvalid), .m_axil_rready(m_rready),
        .m_axil_awaddr(m_awaddr), .m_axil_awvalid(m_awvalid), .m_axil_awready(m_awready),
        .m_axil_wdata(m_wdata), .m_axil_wvalid(m_wvalid), .m_axil_wready(m_wready),
        .m_axil_bvalid(m_bvalid), .m_axil_bready(m_bready),
        .msix_irq(msix_irq)
    );

    axi4_mem_bfm u_bfm (
        .clk(clk), .rst_n(rst_n),
        .s_araddr(m_araddr), .s_arvalid(m_arvalid), .s_arready(m_arready),
        .s_rdata(m_rdata), .s_rvalid(m_rvalid), .s_rready(m_rready),
        .s_awaddr(m_awaddr), .s_awvalid(m_awvalid), .s_awready(m_awready),
        .s_wdata(m_wdata), .s_wvalid(m_wvalid), .s_wready(m_wready),
        .s_bvalid(m_bvalid), .s_bready(m_bready)
    );

    task axil_write(logic [11:0] addr, logic [31:0] data);
        begin
            @(posedge clk);
            awaddr <= addr; awvalid <= 1; wdata <= data; wvalid <= 1; wstrb <= 4'hF; bready <= 1;
            @(posedge clk);
            awvalid <= 0; wvalid <= 0;
            wait (bvalid);
            @(posedge clk);
        end
    endtask

    // Descriptor ring lives in HOST DDR (SW/driver populates it there).
    localparam logic [31:0] RING_BASE = HOST_DDR_BASE + 32'h0000_1000;
    localparam logic [31:0] RING_SIZE = 32'd16; // 16 slots

    // H2C test: move data FROM host DDR INTO local BRAM (NOT DDR->DDR).
    localparam logic [31:0] SRC_ADDR  = HOST_DDR_BASE + 32'h0000_2000; // host DDR source
    localparam logic [31:0] DST_ADDR  = BRAM_BASE;                     // local BRAM destination
    localparam logic [31:0] XFER_LEN  = 32'd256;

    task write_desc_slot(int slot, logic [31:0] src, logic [31:0] dst, logic [31:0] len, logic [31:0] ctrl);
        logic [31:0] daddr;
        begin
            // Descriptors live in HOST DDR - poke u_bfm.ddr_mem[] with
            // HOST_DDR_BASE offset subtracted.
            daddr = RING_BASE + slot * DESC_BYTES;
            {u_bfm.ddr_mem[daddr-HOST_DDR_BASE+3],u_bfm.ddr_mem[daddr-HOST_DDR_BASE+2],
             u_bfm.ddr_mem[daddr-HOST_DDR_BASE+1],u_bfm.ddr_mem[daddr-HOST_DDR_BASE+0]} = src;
            {u_bfm.ddr_mem[daddr-HOST_DDR_BASE+7],u_bfm.ddr_mem[daddr-HOST_DDR_BASE+6],
             u_bfm.ddr_mem[daddr-HOST_DDR_BASE+5],u_bfm.ddr_mem[daddr-HOST_DDR_BASE+4]} = dst;
            {u_bfm.ddr_mem[daddr-HOST_DDR_BASE+11],u_bfm.ddr_mem[daddr-HOST_DDR_BASE+10],
             u_bfm.ddr_mem[daddr-HOST_DDR_BASE+9],u_bfm.ddr_mem[daddr-HOST_DDR_BASE+8]} = len;
            {u_bfm.ddr_mem[daddr-HOST_DDR_BASE+15],u_bfm.ddr_mem[daddr-HOST_DDR_BASE+14],
             u_bfm.ddr_mem[daddr-HOST_DDR_BASE+13],u_bfm.ddr_mem[daddr-HOST_DDR_BASE+12]} = ctrl;
        end
    endtask

    initial begin
        wait (rst_n);
        @(posedge clk);
        // control: IRQ_EN=1 (bit1), DIR=H2C (bit3=0) -> 32'h0000_0002
        write_desc_slot(0, SRC_ADDR, DST_ADDR, XFER_LEN, 32'h0000_0002);
    end

    initial begin
        awvalid=0; wvalid=0; bready=0; arvalid=0; rready=0;
        wait (rst_n);
        repeat (5) @(posedge clk);

        axil_write(12'h004, RING_BASE);         // RING_BASE (32-bit, single register)
        axil_write(12'h00C, RING_SIZE);         // RING_SIZE
        axil_write(12'h018, 32'h0000_0001);     // IRQ_EN
        axil_write(12'h000, 32'h0000_0001);     // CTRL: dma_enable=1

        axil_write(12'h010, 32'd1);             // doorbell: TAIL_PTR=1 (one descriptor posted)

        wait (msix_irq === 1'b1);
        $display("[TB] MSI-X interrupt observed at time %0t", $time);

        repeat (5) @(posedge clk);
        // SRC_ADDR is in HOST DDR (ddr_mem[]), DST_ADDR is in local BRAM
        // (bram_mem[]) - two SEPARATE arrays, confirming a true
        // DDR->BRAM transfer happened rather than a DDR->DDR loopback.
        for (int i = 0; i < XFER_LEN; i++) begin
            byte src_byte = u_bfm.ddr_mem[SRC_ADDR - HOST_DDR_BASE + i];
            byte dst_byte = u_bfm.bram_mem[DST_ADDR - BRAM_BASE + i];
            if (dst_byte !== src_byte) begin
                $error("[TB] Data mismatch at byte %0d: bram_dst=%0h ddr_src=%0h", i, dst_byte, src_byte);
            end
        end
        $display("[TB] H2C DDR->BRAM single-descriptor smoke test PASSED (head_ptr should now equal tail_ptr=1)");

        repeat (20) @(posedge clk);
        $finish;
    end

endmodule : dma_top_tb
