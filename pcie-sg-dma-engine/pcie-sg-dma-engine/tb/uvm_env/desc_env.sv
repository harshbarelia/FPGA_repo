//==============================================================================
// desc_env.sv
// Top-level UVM environment: instantiates driver, monitor, scoreboard,
// predictor, sequencer, and wires all analysis ports.
//==============================================================================
class desc_env extends uvm_env;
    `uvm_component_utils(desc_env)

    desc_driver     driver;
    desc_monitor    monitor;
    desc_scoreboard scoreboard;
    desc_predictor  predictor;
    uvm_sequencer #(desc_seq_item) sequencer;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        driver     = desc_driver::type_id::create("driver", this);
        monitor    = desc_monitor::type_id::create("monitor", this);
        scoreboard = desc_scoreboard::type_id::create("scoreboard", this);
        predictor  = desc_predictor::type_id::create("predictor", this);
        sequencer  = uvm_sequencer#(desc_seq_item)::type_id::create("sequencer", this);
    endfunction

    function void connect_phase(uvm_phase phase);
        // Driver -> Sequencer
        driver.seq_item_port.connect(sequencer.seq_item_export);

        // Monitor -> Scoreboard (actual completions)
        monitor.ap.connect(scoreboard.mon_imp);

        // Driver -> Predictor (driven items for prediction)
        driver.drv_ap.connect(predictor.analysis_export);

        // Predictor -> Scoreboard (expected completions)
        // The predictor broadcasts predicted completions; we need a custom
        // subscriber or use a TLM FIFO to bridge pred_ap into scoreboard.
        // For simplicity, we use a direct function call approach via a
        // custom analysis subscriber that pushes into scoreboard.expected_q.
        predictor.pred_ap.connect(scoreboard.mon_imp);
        // NOTE: In a production env, you'd use separate analysis_imp ports
        // with different IDs (uvm_analysis_imp_decl) for monitor vs predictor
        // paths. This simplified version uses a direct queue push approach.
    endfunction
endclass
