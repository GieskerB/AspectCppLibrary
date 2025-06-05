ifeq ($(REGRESSIONTEST),1)
MAKELEVEL := 1
endif

ifeq ($(MAKELEVEL),0)
$(error Sorry, this makefile is not intended to be \
used directly. Please use the makefile in the toplevel \
directory of the AspectC++ source tree instead)
endif

SHELL=/bin/bash
DIFF=diff --strip-trailing-cr

ACTESTS = HelloWorld StackTrace StackTraceExceptionChange StackTraceFallback StackTraceFileChange\
		  ErrorCodeConverter NullptrCheck NullptrCheckComplexPtr

# This test will always fail, since the timing output of the profiler is not stable.
#ACTESTS += Profiler ProfilerThread

ifeq ($(FRONTEND),Clang)
ifneq ($(shell uname -s),Darwin)
endif
endif

# disabled: UnsizedArray
# to be removed: NonInlineIntroInclude
# (uses deprecated introduction syntax massively)

ACMSGTESTS := RepoInvalid RepoVersion Bug570

ACNORUN := $(filter $(ACMSGTESTS), $(ACTESTS))

ACRUN   := $(filter-out $(ACNORUN), $(ACTESTS))

STDOUT_FILE := stdout.txt
STDERR_FILE := stderr.txt
ERROR_FILE :=  error.txt

# ***** The following is only used for the Akut testsystem (REGRESSIONTEST == 1) *****
# ====================================================================================
ifeq ($(REGRESSIONTEST),1)

define do_test_start
    @COUNT=0;PASS=0;FAIL=0;
endef

define do_test_weave
	COUNT=$$(($$COUNT+1)); \
	echo ---START TEST $$COUNT: $1: is expected to PASS; \
	unset LANG; \
	exec 6>&1; \
	exec 7>&2; \
	exec > $(1)/feature.out; \
	exec 2> $(1)/feature.err; \
	$(MAKE) -s EXT="$(EXT)" -C $(1) ; \
	exec 1>&6 6>&-; \
	exec 2>&7 7>&-; \
	cp $(1)/feature.err $(1)/feature.out; \
	rm $(1)/feature.err; \
	exec 6>&1; \
	exec 7>&2; \
	exec > $(STDOUT_FILE); \
	exec 2> $(STDERR_FILE); \
	$(MAKE) -s EXT="$(EXT)" -C $(1) diff-only; \
	RET=$$?; \
	exec 1>&6 6>&-; \
	exec 2>&7 7>&-; \
	if [ $$RET == 0 ];then \
		echo ---END TEST $$COUNT: $1: PASS \(was expected to pass and did pass\); \
		PASS=$$(($$PASS+1)); \
	else \
		cat $(STDOUT_FILE) ;\
		cat $(STDERR_FILE) ;\
		FAIL=$$(($$FAIL+1)); \
		echo ---END TEST $$COUNT: $1: FAIL \(was expected to pass, but failed\); \
	fi;
endef

define do_test_run
	COUNT=$$(($$COUNT+1)); \
	echo ---START TEST $$COUNT: $1: is expected to PASS; \
	exec 6>&1; \
	exec 7>&2; \
	exec > $(STDOUT_FILE); \
	exec 2> $(STDERR_FILE); \
	$(MAKE) -s EXT="$(EXT)" -C $(1) ; \
	RET=$$?; \
	ERR_FLAG=C; \
	if [ $$RET == 0 ];then \
	 	$(MAKE) -s EXT="$(EXT)" -C $(1) diff; \
	 	RET=$$?; \
		ERR_FLAG=D; \
	fi; \
	exec 1>&6 6>&-; \
	exec 2>&7 7>&-; \
	if [ $$RET == 0 ];then \
		echo ---END TEST $$COUNT: $1: PASS \(was expected to pass and did pass\); \
		PASS=$$(($$PASS+1)); \
	else \
		cat $(STDOUT_FILE) ;\
		cat $(STDERR_FILE) ;\
		FAIL=$$(($$FAIL+1)); \
		echo ---END TEST $$COUNT: $1: FAIL \(was expected to pass, but failed\); \
	fi;
endef

define do_test_end
	echo -n "---EXECUTIVE SUMMARY: " ;\
	if [ $$FAIL -eq $$COUNT ]; then\
		echo FAIL \(all tests failed\) ;\
	elif [ $$FAIL -gt 0 ]; then \
		echo PARTLY \($$(( $$PASS * 100 / $$COUNT ))% tests passed as expected\); \
	else \
		echo PASS \(all tests passed\) ;\
	fi ;\
	echo ---START SUMMARY; \
	echo $$COUNT tests in this testcase; \
	echo $$PASS tests passed as expected; \
	echo $$FAIL tests did not pass as expected; \
	echo $$FAIL expected to pass but failed; \
	echo 0 expected to fail but passed; \
	echo ---END SUMMARY
endef

regression_test:
	$(call do_test_start) \
	$(foreach T, $(ACRUN), $(call do_test_run, $(T))) \
	$(foreach T, $(ACNORUN), $(call do_test_weave, $(T))) \
	$(call do_test_end)

endif

# ================================================================================
# ***** The above is only used for the Akut testsystem (REGRESSIONTEST == 1) *****


all: $(addsuffix .make, $(ACRUN)) $(addsuffix .weave, $(ACNORUN))
	@if [ -f $(ERROR_FILE) ];then \
		echo -e "\n\n"; \
		echo "+---------+"; \
		echo "|ERRORS:  |"; \
		echo "+---------+"; \
		cat $(ERROR_FILE); \
		rm -f $(STDOUT_FILE) $(STDERR_FILE) $(ERROR_FILE); \
		exit 1; \
	 else \
		echo -e "\n\n"; \
	 	echo "All tests OK"; \
	 	rm -f $(STDOUT_FILE) $(STDERR_FILE); \
	 fi;\

ref:  $(addsuffix .ref, $(ACTESTS))

refclean:
	rm */feature.ref

run: $(addsuffix .run, $(ACRUN))

clean: $(addsuffix .clean, $(ACTESTS))


%.weave: %
	@unset LANG; \
	exec 6>&1; \
	exec 7>&2; \
	exec > $</feature.out; \
	exec 2> $</feature.err; \
	$(MAKE) -s EXT="$(EXT)" -C $< ; \
	exec 1>&6 6>&-; \
	exec 2>&7 7>&-; \
	cp $</feature.err $</feature.out; \
	rm $</feature.err; \
	exec 6>&1; \
	exec 7>&2; \
	exec > $(STDOUT_FILE); \
	exec 2> $(STDERR_FILE); \
	$(MAKE) -s EXT="$(EXT)" -C $< diff-only; \
	RET=$$?; \
	exec 1>&6 6>&-; \
	exec 2>&7 7>&-; \
	if [ $$RET == 0 ];then \
		echo -n "."; \
	else \
		ERR_FLAG=D; \
	 	echo -n "[$$ERR_FLAG:$<]"; \
		echo -ne "\n-----------------------------------------------------------------------------\n" >> $(ERROR_FILE); \
		echo  -n "TEST: $<" >> $(ERROR_FILE); \
		echo -ne "\n-----------------------------------------------------------------------------\n" >> $(ERROR_FILE); \
		echo -e "STDOUT:\n--------" >> $(ERROR_FILE); \
		cat $(STDOUT_FILE) >> $(ERROR_FILE); \
		echo   >> $(ERROR_FILE); \
		echo -e "STDERR:\n--------" >> $(ERROR_FILE); \
		cat $(STDERR_FILE) >> $(ERROR_FILE); \
		echo   >> $(ERROR_FILE); \
	fi;


%.make: %
	@exec 6>&1; \
	exec 7>&2; \
	exec > $(STDOUT_FILE); \
	exec 2> $(STDERR_FILE); \
	$(MAKE) -s EXT="$(EXT)" -C $< ; \
	RET=$$?; \
	ERR_FLAG=C; \
	if [ $$RET == 0 ];then \
	 	$(MAKE) -s EXT="$(EXT)" -C $< diff; \
	 	RET=$$?; \
		ERR_FLAG=D; \
	fi; \
	exec 1>&6 6>&-; \
	exec 2>&7 7>&-; \
	if [ $$RET == 0 ];then \
		echo -n "."; \
	else \
	 	echo -n "[$$ERR_FLAG:$<]"; \
		echo -ne "\n-----------------------------------------------------------------------------\n" >> $(ERROR_FILE); \
		echo  -n "TEST: $<" >> $(ERROR_FILE); \
		echo -ne "\n-----------------------------------------------------------------------------\n" >> $(ERROR_FILE); \
		echo -e "STDOUT:\n--------" >> $(ERROR_FILE); \
		cat $(STDOUT_FILE) >> $(ERROR_FILE); \
		echo   >> $(ERROR_FILE); \
		echo -e "STDERR:\n--------" >> $(ERROR_FILE); \
		cat $(STDERR_FILE) >> $(ERROR_FILE); \
		echo   >> $(ERROR_FILE); \
	fi;




%.ref: %
	$(MAKE) -s EXT="$(EXT)" -C $< ref;

%.run:	%
	@echo Making and running test '$<'
	cd $< && $(MAKE) run

%.clean: %
	cd $< && $(MAKE) clean

.PHONY: all clean run ref
