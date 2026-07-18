//==============================================================================
// desc_if.sv
// SystemVerilog interface bundling all signals needed by the UVM driver,
// monitor, and scoreboard to interact with the descriptor engine DUT.
//==============================================================================

interface desc_if #(
    parameter int RING_DEPTH = 128,
    parameter int PTR_WIDTH  = $clog2(RING_DEPTH) + 1
)(
    input logic clk,
    input logic rst_n
);

    // Ring manager interface
    logic [PTR_WIDTH-1:0] sw_insert_ptr_wr;
    logic                 sw_insert_ptr_wr_en;
    logic [PTR_WIDTH-1:0] insert_ptr;
    logic [PTR_WIDTH-1:0] extract_ptr;
    logic                 ring_empty;
    logic                 ring_full;
    logic                 extract_valid;

    // Descriptor ring base address
    logic [63:0]          ring_base;

    // Current insert index (tracked by driver)
    logic [PTR_WIDTH-1:0] cur_insert_idx;

    // Descriptor read interface (simulated host memory)
    logic                 desc_rd_req;
    logic [63:0]          desc_rd_addr;
    logic                 desc_rd_valid;
    logic [255:0]         desc_rd_data;

    // Decode output observability
    logic [63:0]          desc_src_addr;
    logic [63:0]          desc_dst_addr;
    logic [31:0]          desc_len;
    logic                 desc_dir;
    logic                 desc_irq_en;
    logic                 decode_error;

    // Dispatch interface
    logic                 dispatch_valid;
    logic                 dispatch_ack;
    logic                 xfer_done;
    logic                 xfer_error;

    // Writeback interface
    logic                 writeback_req;
    logic                 writeback_done;
    logic                 wb_wr_req;
    logic [63:0]          wb_wr_addr;
    logic [31:0]          wb_wr_data;

    // FSM debug
    logic [3:0]           state_dbg;

    // Simulated host memory (simple associative array model)
    logic [255:0] host_mem [logic [63:0]];

    // Write a descriptor into simulated host memory
    function void write_host_mem(input logic [63:0] addr, input logic [255:0] data);
        host_mem[addr] = data;
    endfunction

    // Read a descriptor from simulated host memory
    function logic [255:0] read_host_mem(input logic [63:0] addr);
        if (host_mem.exists(addr))
            return host_mem[addr];
        else
            return '0;
    endfunction

    // Modport for active driver
    modport drv (
        input  clk, rst_n,
        output sw_insert_ptr_wr, sw_insert_ptr_wr_en,
        input  insert_ptr, extract_ptr,
        input  ring_empty, ring_full, extract_valid,
        output ring_base, cur_insert_idx
    );

    // Modport for passive monitor
    modport mon (
        input clk, rst_n,
        input insert_ptr, extract_ptr,
        input dispatch_valid, dispatch_ack,
        input xfer_done, xfer_error,
        input writeback_req, writeback_done,
        input wb_wr_req, wb_wr_addr, wb_wr_data,
        input decode_error,
        input state_dbg
    );

endinterface
