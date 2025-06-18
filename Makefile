# TARGET  ?= linux-release
# BINDIR := bin/$(TARGET)
# PROG := $(BINDIR)/ac++$(EXT)
# export AC := $(shell pwd)/$(PROG)
# export AG := $(shell pwd)/$(BINDIR)/ag++$(EXT)

export AC := ac++
export AG := ag++

MAKE ?= make

ACFLAGS := -k -v 9

test: testall

test%:
	$(MAKE) -C tests -s  $*

.PHONY: test
