
// axi4_mem_bfm.sv
// AXI4-LITE slave Behavioral Functional Model representing TWO
// DISTINCT physical memories on the same shared AXI4-Lite bus:
//   - HOST DDR region  [HOST_DDR_BASE, HOST_DDR_BASE+HOST_DDR_SIZE)
//   - Local BRAM region [BRAM_BASE, BRAM_BASE+BRAM_SIZE)
// AXI4-Lite has NO burst (no ARLEN/AWLEN) and NO transaction ID -
// every transaction is exactly one BEAT_BYTES-wide beat, one
// outstanding read and one outstanding write at a time. Address
// decode picks the correct backing array based on the incoming
// address, so H2C (DDR->BRAM) and C2H (BRAM->DDR) actually move
// data between two separate memories instead of within one unified
// array. BRAM is modeled with lower latency than DDR to reflect
// on-chip vs off-chip (over-PCIe) access characteristics.
import dma_pkg::*;

module axi4_mem_bfm #(
    parameter int DDR_RD_LATENCY  = 6,  // host DDR round-trip over PCIe: higher latency
    parameter int DDR_WR_LATENCY  = 4,
    parameter int BRAM_RD_LATENCY = 1,  // on-chip BRAM: much lower latency
    parameter int BRAM_WR_LATENCY = 1
)(
    input  logic clk,
    input  logic rst_n,
    input  logic [31:0]  s_araddr,
    input  logic          s_arvalid,
    output logic          s_arready,
    output logic [31:0]  s_rdata,
    output logic          s_rvalid,
    input  logic          s_rready,
    input  logic [31:0]  s_awaddr,
    input  logic          s_awvalid,
    output logic          s_awready,
    input  logic [31:0]  s_wdata,
    input  logic          s_wvalid,
    output logic          s_wready,
    output logic          s_bvalid,
    input  logic          s_bready
);

    // Two SEPARATE backing arrays so H2C/C2H genuinely move data
    // between two distinct memories instead of within one array.
    byte ddr_mem  [0:HOST_DDR_SIZE-1];
    byte bram_mem [0:BRAM_SIZE-1];

    initial begin
        for (int i = 0; i < HOST_DDR_SIZE; i++) ddr_mem[i]  = i[7:0];
        for (int i = 0; i < BRAM_SIZE; i++)     bram_mem[i] = 8'h00; // BRAM starts empty/zeroed
    end

    function automatic logic [31:0] get_word(logic [31:0] addr);
        logic [31:0] w;
        begin
            if (addr_in_bram(addr)) begin
                w[7:0]   = bram_mem[addr-BRAM_BASE+0];
                w[15:8]  = bram_mem[addr-BRAM_BASE+1];
                w[23:16] = bram_mem[addr-BRAM_BASE+2];
                w[31:24] = bram_mem[addr-BRAM_BASE+3];
            end else begin
                w[7:0]   = ddr_mem[addr-HOST_DDR_BASE+0];
                w[15:8]  = ddr_mem[addr-HOST_DDR_BASE+1];
                w[23:16] = ddr_mem[addr-HOST_DDR_BASE+2];
                w[31:24] = ddr_mem[addr-HOST_DDR_BASE+3];
            end
            get_word = w;
        end
    endfunction

    task automatic set_word(logic [31:0] addr, logic [31:0] data);
        begin
            if (addr_in_bram(addr)) begin
                bram_mem[addr-BRAM_BASE+0] = data[7:0];
                bram_mem[addr-BRAM_BASE+1] = data[15:8];
                bram_mem[addr-BRAM_BASE+2] = data[23:16];
                bram_mem[addr-BRAM_BASE+3] = data[31:24];
            end else begin
                ddr_mem[addr-HOST_DDR_BASE+0] = data[7:0];
                ddr_mem[addr-HOST_DDR_BASE+1] = data[15:8];
                ddr_mem[addr-HOST_DDR_BASE+2] = data[23:16];
                ddr_mem[addr-HOST_DDR_BASE+3] = data[31:24];
            end
        end
    endtask

    typedef enum logic [1:0] {R_IDLE, R_LAT, R_DATA} rstate_t;
    rstate_t rstate;
    logic [31:0] rd_addr_l;
    int rd_lat_cnt;

    assign s_arready = (rstate == R_IDLE);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rstate <= R_IDLE; s_rvalid <= 1'b0;
        end else begin
            case (rstate)
                R_IDLE: begin
                    s_rvalid <= 1'b0;
                    if (s_arvalid && s_arready) begin
                        rd_addr_l  <= s_araddr;
                        rd_lat_cnt <= addr_in_bram(s_araddr) ? BRAM_RD_LATENCY : DDR_RD_LATENCY;
                        rstate     <= R_LAT;
                    end
                end
                R_LAT: begin
                    if (rd_lat_cnt == 0) rstate <= R_DATA;
                    else rd_lat_cnt <= rd_lat_cnt - 1;
                end
                R_DATA: begin
                    s_rvalid <= 1'b1;
                    s_rdata  <= get_word(rd_addr_l);
                    if (s_rvalid && s_rready) begin
                        s_rvalid <= 1'b0;
                        rstate   <= R_IDLE;
                    end
                end
                default: rstate <= R_IDLE;
            endcase
        end
    end

    typedef enum logic [1:0] {W_IDLE, W_LAT, W_RESP} wstate_t;
    wstate_t wstate;
    int wr_lat_cnt;

    assign s_awready = (wstate == W_IDLE);
    assign s_wready  = (wstate == W_IDLE);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wstate <= W_IDLE; s_bvalid <= 1'b0;
        end else begin
            case (wstate)
                W_IDLE: begin
                    if (s_awvalid && s_awready && s_wvalid && s_wready) begin
                        set_word(s_awaddr, s_wdata);
                        wr_lat_cnt <= addr_in_bram(s_awaddr) ? BRAM_WR_LATENCY : DDR_WR_LATENCY;
                        wstate     <= W_LAT;
                    end
                end
                W_LAT: begin
                    if (wr_lat_cnt == 0) wstate <= W_RESP;
                    else wr_lat_cnt <= wr_lat_cnt - 1;
                end
                W_RESP: begin
                    s_bvalid <= 1'b1;
                    if (s_bvalid && s_bready) begin
                        s_bvalid <= 1'b0;
                        wstate   <= W_IDLE;
                    end
                end
                default: wstate <= W_IDLE;
            endcase
        end
    end

endmodule : axi4_mem_bfm
