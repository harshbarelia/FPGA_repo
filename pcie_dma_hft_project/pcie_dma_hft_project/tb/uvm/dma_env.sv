class dma_env extends uvm_env;
    `uvm_component_utils(dma_env)
    dma_sequencer  seqr;
    dma_driver     drv;
    dma_monitor    mon;
    dma_scoreboard scb;
    dma_coverage   cov;

    function new(string name = "dma_env", uvm_component parent = null);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        seqr = dma_sequencer::type_id::create("seqr", this);
        drv  = dma_driver::type_id::create("drv", this);
        mon  = dma_monitor::type_id::create("mon", this);
        scb  = dma_scoreboard::type_id::create("scb", this);
        cov  = dma_coverage::type_id::create("cov", this);
    endfunction

    function void connect_phase(uvm_phase phase);
        drv.seq_item_port.connect(seqr.seq_item_export);
        mon.ap.connect(scb.item_imp);
        mon.ap.connect(cov.analysis_export);
    endfunction
endclass
