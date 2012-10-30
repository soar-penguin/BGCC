.PHONY: bgcc testsuite bidl2sl adapter bgcc_clean testsuite_clean

ifdef JAVA_HOME_1_6_33
export JAVA_HOME=$(JAVA_HOME_1_6_33)
endif

ifdef ANT_HOME_1_8
export ANT=$(ANT_HOME_1_8)/bin/ant
else
export ANT=ant
endif

all: bgcc bidl2sl adapter

export OUTPUT_PATH=./output

bgcc:
	@echo
	@echo
	@echo "make bgcc..."
	@$(MAKE) -C bgcc
	@echo "make bgcc ok."
	@echo
	@echo
	
bidl2sl:
	@echo
	@echo
	@echo "make bidl2sl..."
	@$(MAKE) -C bidl2sl
	@mkdir -p output
	cp bidl2sl/bidl2sl output/bidl2sl
	@echo "make bidl2sl ok."
	@echo
	@echo

adapter: bgcc
	@echo
	@echo
	@echo "make adapter..."
	@$(MAKE) -C adapter/java
	cp adapter/java/output/libbgcc4j.so $(OUTPUT_PATH)/lib
	@echo
	@echo

clean: bgcc_clean bidl2sl_clean adapter_clean
	@rm -rf output

bgcc_clean:
	@$(MAKE) clean -C bgcc

bidl2sl_clean:
	@$(MAKE) clean -C bidl2sl

adapter_clean:
	@$(MAKE) clean -C adapter/java
