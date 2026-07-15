module reset_sync #(
    parameter int STAGES = 2
) (
    input  logic clk,
    input  logic arst_n,
    output logic srst_n
);

    logic [STAGES-1:0] sync_ff;

    always_ff @(posedge clk or negedge arst_n) begin
        if (!arst_n)
            sync_ff <= '0;
        else
            sync_ff <= {sync_ff[STAGES-2:0], 1'b1};
    end

    assign srst_n = sync_ff[STAGES-1];

endmodule
