module uart_csr (
    input  logic        clk,
    input  logic        rst_n,

    input  logic         wr_en,
    input  logic [3:0]   wstrb,
    input  logic [3:0]   addr,
    input  logic [31:0]  wdata,
    input  logic         rd_en,
    output logic [31:0]  rdata,

    output logic         tx_start,
    output logic [7:0]   tx_data,
    input  logic         tx_busy,
    input  logic         tx_done,

    input  logic [7:0]   rx_data_in,
    input  logic         rx_valid_in,
    input  logic         framing_error_in
);

    logic [7:0] tx_data_reg;
    logic       rx_enable_reg;
    logic       rx_valid_sticky;
    logic       framing_error_sticky;
    logic [7:0] rx_data_reg;
    logic       tx_start_pulse;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            tx_data_reg          <= 8'h00;
            rx_enable_reg        <= 1'b0;
            tx_start_pulse       <= 1'b0;
            rx_data_reg          <= 8'h00;
            rx_valid_sticky      <= 1'b0;
            framing_error_sticky <= 1'b0;
        end else begin
            tx_start_pulse <= 1'b0;

            if (rx_valid_in) begin
                rx_valid_sticky <= 1'b1;
                rx_data_reg     <= rx_data_in;
            end
            if (framing_error_in) begin
                framing_error_sticky <= 1'b1;
            end

            if (wr_en) begin
                case (addr)
                    4'h0: begin
                        if (wstrb[0]) begin
                            if (wdata[0]) tx_start_pulse <= 1'b1;
                            rx_enable_reg <= wdata[1];
                        end
                    end
                    4'h4: begin
                        if (wstrb[0]) begin
                            if (wdata[1]) rx_valid_sticky      <= 1'b0;
                            if (wdata[2]) framing_error_sticky <= 1'b0;
                        end
                    end
                    4'h8: begin
                        if (wstrb[0]) tx_data_reg <= wdata[7:0];
                    end
                    default: ;
                endcase
            end
        end
    end

    assign tx_start = tx_start_pulse;
    assign tx_data  = tx_data_reg;

    always_comb begin
        rdata = 32'h0000_0000;
        if (rd_en) begin
            case (addr)
                4'h0: rdata = {30'b0, rx_enable_reg, 1'b0};
                4'h4: rdata = {29'b0, framing_error_sticky, rx_valid_sticky, tx_busy};
                4'h8: rdata = {24'b0, tx_data_reg};
                4'hC: rdata = {24'b0, rx_data_reg};
                default: rdata = 32'h0000_0000;
            endcase
        end
    end

endmodule
