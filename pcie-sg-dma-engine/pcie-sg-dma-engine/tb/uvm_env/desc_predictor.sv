//==============================================================================
// desc_predictor.sv
// UVM reference model: subscribes to driver sequence items, applies the
// same validation logic as desc_fetch.sv's DECODE stage, and pushes
// predicted completion transactions into the scoreboard's expected queue.
//==============================================================================
class desc_predictor extends uvm_subscriber #(desc_seq_item);
    `uvm_component_utils(desc_predictor)

    uvm_analysis_port #(desc_completion_txn) pred_ap;

    localparam int MAX_XFER_LEN = 32'h0400_0000;

    function new(string name, uvm_component parent);
        super.new(name, parent);
        pred_ap = new("pred_ap", this);
    endfunction

    // Mirrors desc_fetch.sv DECODE validation logic exactly.
    // If you change the RTL validation rules, you MUST update this function
    // to match — otherwise the scoreboard will false-pass or false-fail.
    function bit predict_error(desc_seq_item item);
        bit err = 0;
        // Zero length
        if (item.length == 32'd0) err = 1;
        // Oversized
        if (item.length > MAX_XFER_LEN) err = 1;
        // Misaligned src address (must be DW-aligned, bits [1:0] == 0)
        if (item.src_addr[1:0] != 2'b00) err = 1;
        // Misaligned dst address
        if (item.dst_addr[1:0] != 2'b00) err = 1;
        return err;
    endfunction

    // Called automatically when the driver broadcasts a driven item
    function void write(desc_seq_item t);
        desc_completion_txn pred_txn;
        pred_txn = desc_completion_txn::type_id::create("pred_txn");
        pred_txn.error_flag  = predict_error(t);
        pred_txn.status_word = {30'd0, pred_txn.error_flag, 1'b1}; // bit0=complete, bit1=error
        pred_ap.write(pred_txn);
        `uvm_info("PRED", $sformatf("Predicted: error=%0b for len=%0d src=%0h dst=%0h",
                  pred_txn.error_flag, t.length, t.src_addr, t.dst_addr), UVM_MEDIUM)
    endfunction

endclass
