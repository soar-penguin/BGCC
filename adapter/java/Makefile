ifndef JAVA_HOME
$(error Variable JAVA_HOME not set)
endif

all:
	@which $(ANT) &>/dev/null || (echo $(ANT) not exist; exit 1;)
	@cd bgcc && $(ANT) && cd ..
	@$(MAKE) -C bgcc4j

clean:
	@cd bgcc && $(ANT) clean && cd ..
	@$(MAKE) clean -C bgcc4j
