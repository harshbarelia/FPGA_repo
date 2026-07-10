module baud_gen #(
    parameter int CLK_FREQ_HZ = 50_000_000,
    parameter int BAUD_RATE   = 115_200
) (
    input  logic clk,
    input  logic rst_n,
    output logic baud_tick
);

    localparam int DIVISOR = CLK_FREQ_HZ / BAUD_RATE;
    localparam int CNT_W   = (DIVISOR <= 1) ? 1 : $clog2(DIVISOR);
    localparam logic [CNT_W-1:0] DIVISOR_M1 = CNT_W'(DIVISOR - 1);    

    logic [CNT_W-1:0] count;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            count     <= '0;
            baud_tick <= 1'b0;
        end else begin
            if (count == DIVISOR_M1) begin
                baud_tick <= 1'b1;
                count     <= '0;
            end else begin
                count     <= count + 1'b1;
                baud_tick <= 1'b0;
            end
        end
    end

endmodule
