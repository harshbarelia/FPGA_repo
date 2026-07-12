module uart_tx #(
    parameter int CLK_FREQ_HZ = 1_000_000,
    parameter int BAUD_RATE    = 100_000
) (
    input  logic       clk,
    input  logic       rst_n,
    input  logic       tx_start,
    input  logic [7:0] tx_data,
    output logic       tx,
    output logic       busy,
    output logic       tx_done
);

    localparam int DIVISOR = CLK_FREQ_HZ / BAUD_RATE;
    localparam int CNT_W   = (DIVISOR <= 1) ? 1 : $clog2(DIVISOR);

    typedef logic [CNT_W-1:0] cnt_t;
    localparam cnt_t DIVISOR_M1 = cnt_t'(DIVISOR - 1);

    typedef enum logic [1:0] {IDLE, START, DATA, STOP} state_t;

    state_t state;
    cnt_t   baud_cnt;
    logic [2:0] bit_idx;
    logic [7:0] shreg;
    logic       tx_next;

    always_comb begin
        tx_next = tx;
        case (state)
            IDLE:  tx_next = 1'b1;
            START: tx_next = 1'b0;
            DATA:  tx_next = shreg[0];
            STOP:  tx_next = 1'b1;
            default: tx_next = 1'b1;
        endcase
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state    <= IDLE;
            baud_cnt <= '0;
            bit_idx  <= '0;
            shreg    <= '0;
            tx       <= 1'b1;
            busy     <= 1'b0;
            tx_done  <= 1'b0;
        end else begin
            tx      <= tx_next;
            tx_done <= 1'b0;

            case (state)
                IDLE: begin
                    busy     <= 1'b0;
                    baud_cnt <= '0;
                    bit_idx  <= '0;
                    if (tx_start) begin
                        shreg <= tx_data;
                        busy  <= 1'b1;
                        state <= START;
                    end
                end

                START: begin
                    busy <= 1'b1;
                    if (baud_cnt == DIVISOR_M1) begin
                        baud_cnt <= '0;
                        state    <= DATA;
                        bit_idx  <= 3'd0;
                    end else begin
                        baud_cnt <= baud_cnt + 1'b1;
                    end
                end

                    DATA: begin
                    busy <= 1'b1;
                    if (baud_cnt == DIVISOR_M1) begin
                        baud_cnt <= '0;
                        if (bit_idx == 3'd7) begin
                            state <= STOP;
                        end else begin
                            shreg   <= {1'b0, shreg[7:1]};
                            bit_idx <= bit_idx + 1'b1;
                        end
                    end else begin
                        baud_cnt <= baud_cnt + 1'b1;
                    end
                end

                STOP: begin
                    busy <= 1'b1;
                    if (baud_cnt == DIVISOR_M1) begin
                        baud_cnt <= '0;
                        busy     <= 1'b0;
                        tx_done  <= 1'b1;
                        state    <= IDLE;
                    end else begin
                        baud_cnt <= baud_cnt + 1'b1;
                    end
                end

                default: begin
                    state <= IDLE;
                end
            endcase
        end
    end

endmodule
