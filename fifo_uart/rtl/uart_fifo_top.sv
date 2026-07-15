module uart_fifo_top #(
    parameter int CLK_FREQ_HZ = 1_000_000,
    parameter int BAUD_RATE   = 100_000,
    parameter int FIFO_DEPTH   = 16
) (
    input  logic       clk,
    input  logic       rst_n,

    input  logic       tx_fifo_wr_en,
    input  logic [7:0] tx_fifo_din,
    output logic       tx_fifo_full,
    output logic       tx_fifo_empty,

    input  logic       rx_fifo_rd_en,
    output logic [7:0] rx_fifo_dout,
    output logic       rx_fifo_full,
    output logic       rx_fifo_empty,

    output logic       tx_busy,
    output logic       framing_error,

    output logic       tx_serial,
    input  logic       rx_serial
);

    logic       tx_start;
    logic [7:0] tx_data;
    logic       tx_done;

    logic [7:0] rx_data;
    logic       rx_valid;
    logic       rx_valid_d;

    logic       tx_fifo_rd_en;
    logic [7:0] tx_fifo_dout;

    logic       rx_fifo_wr_en;

   

    sync_fifo #(
        .DATA_W(8),
        .DEPTH(FIFO_DEPTH)
    ) u_tx_fifo (
        .clk(clk),
        .rst_n(rst_n),
        .wr_en(tx_fifo_wr_en),
        .in_data(tx_fifo_din),
        .rd_en(tx_fifo_rd_en),
        .out_data(tx_fifo_dout),
        .full(tx_fifo_full),
        .empty(tx_fifo_empty)
    );

    sync_fifo #(
        .DATA_W(8),
        .DEPTH(FIFO_DEPTH)
    ) u_rx_fifo (
        .clk(clk),
        .rst_n(rst_n),
        .wr_en(rx_fifo_wr_en),
        .in_data(rx_data),
        .rd_en(rx_fifo_rd_en),
        .out_data(rx_fifo_dout),
        .full(rx_fifo_full),
        .empty(rx_fifo_empty)
    );

    uart_tx #(
        .CLK_FREQ_HZ(CLK_FREQ_HZ),
        .BAUD_RATE(BAUD_RATE)
    ) u_tx (
        .clk(clk),
        .rst_n(rst_n),
        .tx_start(tx_start),
        .tx_data(tx_data),
        .tx(tx_serial),
        .busy(tx_busy),
        .tx_done(tx_done)
    );

    uart_rx #(
        .CLK_FREQ_HZ(CLK_FREQ_HZ),
        .BAUD_RATE(BAUD_RATE)
    ) u_rx (
        .clk(clk),
        .rst_n(rst_n),
        .rx(rx_serial),
        .rx_data(rx_data),
        .rx_valid(rx_valid),
       .framing_error(framing_error)
    );
        


   typedef enum logic [1:0] {TX_IDLE, TX_POP, TX_START, TX_WAIT_BUSY} txm_state_t;
txm_state_t txm_state;

always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        tx_fifo_rd_en <= 1'b0;
        tx_start      <= 1'b0;
        tx_data       <= 8'h00;
        rx_fifo_wr_en <= 1'b0;
        rx_valid_d    <= 1'b0;
        txm_state     <= TX_IDLE;
    end else begin
        tx_fifo_rd_en <= 1'b0;
        tx_start      <= 1'b0;
        rx_fifo_wr_en <= 1'b0;
        rx_valid_d    <= rx_valid;

        case (txm_state)
            TX_IDLE: begin
                if (!tx_busy && !tx_fifo_empty) begin
                    tx_fifo_rd_en <= 1'b1;
                    txm_state     <= TX_POP;
                end
            end

            TX_POP: begin
                txm_state <= TX_START;
            end

            TX_START: begin
                tx_data   <= tx_fifo_dout;
                tx_start  <= 1'b1;
                txm_state <= TX_WAIT_BUSY;
            end

            TX_WAIT_BUSY: begin
                if (tx_busy) begin
                    txm_state <= TX_IDLE;
                end
            end

            default: txm_state <= TX_IDLE;
        endcase

        if (rx_valid && !rx_valid_d && !rx_fifo_full) begin
            rx_fifo_wr_en <= 1'b1;
        end
    end
end
        


                      
    
    
    
          
   

                                     
endmodule
