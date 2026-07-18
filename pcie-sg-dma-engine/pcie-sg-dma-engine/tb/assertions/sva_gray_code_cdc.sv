//==============================================================================
// sva_gray_code_cdc.sv
// Bound into async_fifo.sv. Verifies the single-bit-toggle Gray code
// invariant -- catches encoding bugs before they become metastability bugs.
//==============================================================================
module sva_gray_code_cdc #(
    parameter int ADDR_WIDTH = 4
)(
    input logic wr_clk, wr_rst_n, wr_en,
    input logic [ADDR_WIDTH:0] wr_ptr_gray,
    input logic rd_clk, rd_rst_n, rd_en,
    input logic [ADDR_WIDTH:0] rd_ptr_gray
);

    property p_gray_single_bit_toggle_wr;
        @(posedge wr_clk) disable iff (!wr_rst_n)
        wr_en |=> ($countones(wr_ptr_gray ^ $past(wr_ptr_gray)) <= 1);
    endproperty
    a_gray_single_bit_toggle_wr: assert property (p_gray_single_bit_toggle_wr)
        else $error("Write Gray pointer changed more than 1 bit -- CDC hazard");

    property p_gray_single_bit_toggle_rd;
        @(posedge rd_clk) disable iff (!rd_rst_n)
        rd_en |=> ($countones(rd_ptr_gray ^ $past(rd_ptr_gray)) <= 1);
    endproperty
    a_gray_single_bit_toggle_rd: assert property (p_gray_single_bit_toggle_rd)
        else $error("Read Gray pointer changed more than 1 bit -- CDC hazard");

endmodule
