# ==============================================================================
# PCIe SG-DMA Engine Directed Verification Makefile (Verilator WSL)
# ==============================================================================

VERILATOR = verilator
VERILATOR_FLAGS = --binary -j 0 --timing --trace \
                  -Wno-fatal -Wno-WIDTHEXPAND -Wno-WIDTHTRUNC \
                  -Wno-UNUSEDSIGNAL -Wno-UNDRIVEN -Wno-UNUSEDPARAM \
                  -Wno-UNOPTFLAT -Wno-CASEINCOMPLETE -Wno-TIMESCALEMOD

OBJ_DIR = obj_dir

TESTS = tb_ring_wraparound \
        tb_malformed_descriptor \
        tb_back_to_back \
        tb_c2h_single \
        tb_h2c_single \
        tb_msix_coalescing

.PHONY: all run clean $(TESTS)

all: $(TESTS)

# Individual testbench targets
tb_ring_wraparound:
	$(VERILATOR) $(VERILATOR_FLAGS) --top-module tb_ring_wraparound -o tb_ring_wraparound \
		rtl/descriptor_engine/desc_ring_mgr.sv tb/directed/tb_ring_wraparound.sv

tb_malformed_descriptor:
	$(VERILATOR) $(VERILATOR_FLAGS) --top-module tb_malformed_descriptor -o tb_malformed_descriptor \
		rtl/descriptor_engine/desc_fetch.sv tb/directed/tb_malformed_descriptor.sv

tb_back_to_back:
	$(VERILATOR) $(VERILATOR_FLAGS) --top-module tb_back_to_back -o tb_back_to_back \
		rtl/descriptor_engine/desc_ring_mgr.sv \
		rtl/descriptor_engine/desc_fetch.sv \
		rtl/descriptor_engine/desc_completion.sv \
		tb/directed/xfer_engine_stub.sv \
		tb/directed/tb_back_to_back.sv

tb_c2h_single:
	$(VERILATOR) $(VERILATOR_FLAGS) --top-module tb_c2h_single -o tb_c2h_single \
		rtl/dma_engines/c2h_engine.sv \
		rtl/tlp/tlp_generator.sv \
		tb/directed/tb_c2h_single.sv

tb_h2c_single:
	$(VERILATOR) $(VERILATOR_FLAGS) --top-module tb_h2c_single -o tb_h2c_single \
		rtl/dma_engines/h2c_engine.sv \
		tb/directed/tb_h2c_single.sv

tb_msix_coalescing:
	$(VERILATOR) $(VERILATOR_FLAGS) --top-module tb_msix_coalescing -o tb_msix_coalescing \
		rtl/interrupt/msix_ctrl.sv \
		rtl/interrupt/msix_table.sv \
		tb/directed/tb_msix_coalescing.sv

# Run all tests and print a clean summary
run: all
	@echo "=================================================="
	@echo "          Running Verification Suite              "
	@echo "=================================================="
	@failed=0; \
	for test in $(TESTS); do \
		echo "Running $$test..."; \
		./$(OBJ_DIR)/$$test > $(OBJ_DIR)/$$test.log 2>&1; \
		if [ $$? -eq 0 ]; then \
			echo "  [PASS] $$test"; \
		else \
			echo "  [FAIL] $$test (see $(OBJ_DIR)/$$test.log)"; \
			failed=`expr $$failed + 1`; \
		fi; \
	done; \
	echo "=================================================="; \
	if [ $$failed -eq 0 ]; then \
		echo "SUCCESS: All tests passed!"; \
	else \
		echo "FAILURE: $$failed test(s) failed."; \
		exit 1; \
	fi

clean:
	rm -rf $(OBJ_DIR) *.vcd
