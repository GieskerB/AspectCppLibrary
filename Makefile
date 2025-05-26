# ******************************
# *       S E T T I N G S      *
# ******************************

# AspectC++ supports alternative frontends: Puma or Clang
# It can be configured the 'make FRONTEND=...'. Default is Clang.
export FRONTEND ?= Clang

# PUMA root
PUMA    ?= ../Puma

# ACModel root
ACMODEL ?= ACModel

# LLVM config command
LLVMCONF ?= llvm-config

# libxml2 config command
XML2CONF ?= xml2-config

# default target
TARGET  ?= linux-release

# include the PUMA configuration variables
# => set _TARGET, RELEASE, CFLAGS, CXXFLAGS, CPPFLAGS, etc.
include $(PUMA)/vars.mk
CPPFLAGS += -g
CXXFLAGS += -g


PLATFORM := $(shell echo $(_TARGET) | cut -d _ -f1)
ARCH := $(shell echo $(_TARGET) | cut -d _ -f2-)

# check whether we compile for Windows: TARGET-Variable starts with 'win'
ifneq ($(filter win%,$(TARGET)),)
	WIN := yes
	EXT := .exe
endif

# libxml2 settings
LIBXML2_INC := $(shell $(XML2CONF) --cflags)
LIBXML2_INC := $(patsubst -I/%, -isystem /%, $(LIBXML2_INC))
LIBXML2_LIB := $(shell $(XML2CONF) --libs)

# Check Clang version and define all necessary symbols (LLVM_*)
ifneq ($(MAKECMDGOALS),clean)
  ifeq ($(FRONTEND),Clang)
    include config/clang.mk
  endif
endif

# linker settings
export SHARED # if defined, sub-makes should see this setting, too

ifneq ($(PLATFORM),macos)
ifeq ($(SHARED),)
  LDFLAGS += -static
endif
ifeq ($(FRONTEND),Puma)
	LDFLAGS += -Wl,-Bstatic -L$(PUMA)/lib/$(TARGET) -lPuma
ifneq ($(SHARED),)
	LDFLAGS += -Wl,-Bdynamic
endif
else # FRONTEND is Clang
	LDFLAGS += -L$(PUMA)/lib/$(TARGET) -lMiniPuma
ifneq ($(SHARED),)
	LDFLAGS += #-Wl,-Bdynamic
endif
endif
else
ifeq ($(FRONTEND),Puma)
	LDFLAGS += -L$(PUMA)/lib/$(TARGET) -lPuma
else # FRONTEND is Clang
	LDFLAGS += -L$(PUMA)/lib/$(TARGET) -lMiniPuma
endif
endif

LDFLAGS += $(LIBXML2_LIB)
ifneq ($(FRONTEND),Puma)
  LDFLAGS += -lclangRewriteFrontend -lclangRewrite -lclangFrontend -lclangSerialization -lclangDriver -lclangParse -lclangSema -lclangAnalysis -lclangEdit -lclangAST -lclangLex -lclangBasic -lLLVMAsmParser -lLLVMMCParser -lLLVMBitReader -lLLVMTransformUtils -lLLVMCore -lLLVMMC -lLLVMOption -lLLVMSupport
  ifeq ($(filter-out 18.1.3 18.1.8 19.1.6, $(shell $(LLVMCONF) --version)),)
    LDFLAGS += -lclangAPINotes -lclangSupport -lclangASTMatchers -lclangBasic # extra libs for clang-18/19
  endif
ifneq ($(PLATFORM),macos)
  # On the ARMEL platform we also need -latomic. This is a workaround for a gcc bug.
  LDFLAGS += -Wl,--as-needed -latomic -Wl,--no-as-needed
  # ... until here
#  LDFLAGS += `$(LLVMCONF) --libs`
  LDFLAGS += $(patsubst %,-Xlinker --wrap=%,$(LLVM_SYMBOLS))
else
# Mac OS X is special, we patch the clang libraries below.
  LDFLAGS := libclangSema.o $(filter-out -lclangSema, $(LDFLAGS))
endif
LDFLAGS += `$(LLVMCONF) --ldflags`
# - Additional libraries ("--libs") needed
# - Starting with 4.0 "--system-libs" returns nothing if the debian clang package is used. "--link-static" forces
#   "--system-libs" to return the system libs in all cases
LDFLAGS += $(shell $(LLVMCONF) --libs --system-libs --link-static)

# On Windows (MinGW) fix the linker flags; llvm-config is not perfect
# 1. replace libzstd.dll.a with a normal -l
# 2. add -lversion
ifeq ($(WIN),yes)
  LDFLAGS := $(patsubst %/libzstd.dll.a, -lzstd, $(LDFLAGS)) -lversion
endif

# workaround for strange MacOS config from clang
ifeq ($(PLATFORM),macos)
LDFLAGS := $(filter-out -llibxml2.tbd, $(LDFLAGS))
endif
endif

# compiler settings
ifeq ($(WIN),yes)
  RES := windres
  RCFILES := win-ac++.rc
  ifeq ($(SHARED),)
     CPPFLAGS += -DLIBXML_STATIC # the MinGW libxml2 requires this; otherwise linker problems
  endif
endif

CPPFLAGS += -I$(PUMA)/extern -I$(PUMA)/include $(LIBXML2_INC)
ifeq ($(FRONTEND),Puma)
  CPPFLAGS += -DFRONTEND_PUMA -g
else
  FILTEROUT :=
ifeq ($(RELEASE),debug)
  # filter-out "-DNDEBUG" added by LLVMCONF, if LLVM is in built in release-mode
  FILTEROUT := -DNDEBUG
endif
  LLVM_CPPFLAGS := $(shell $(LLVMCONF) --cppflags)
  ifeq ($(WIN),yes)
    # llvm-config on Windows generates path name with '\' that mingw g++ can't handle properly
    LLVM_CPPFLAGS := $(subst \,/,$(LLVM_CPPFLAGS))
  endif
  LLVM_CPPFLAGS := $(patsubst -I/%, -isystem /%, $(LLVM_CPPFLAGS))
  CPPFLAGS += $(filter-out $(FILTEROUT),$(LLVM_CPPFLAGS)) -g
  CPPFLAGS += -DFRONTEND_CLANG
  CXXFLAGS += -fno-rtti -Wno-strict-aliasing -Wno-nonnull# hide annoying warnings in Clang headers
  # Clang >= 11 uses C++14 features; "c++14" does not work -> WIN32 not defined on Windows!
  # clang >= 18 requires C++17
  CXXFLAGS += -std=gnu++11 -g
endif

# profiling
ifneq ($(GPROF),)
	LDFLAGS := $(LDFLAGS) -lc_p -lm_p
	CXXFLAGS += -pg
endif

ifneq ($(PROFILING),)
	CPPFLAGS += -DPROFILING
endif

# use libacmodel
LDFLAGS  += -L$(ACMODEL)/lib/$(TARGET) -lacmodel
ACMODELLIB := $(ACMODEL)/lib/$(TARGET)/libacmodel.a

# ******************************
# *       S O U R C E S        *
# ******************************

BINDIR := bin/$(TARGET)

#programm to compile
PROG := $(BINDIR)/ac++$(EXT)

# sources; front-end specific files for the wrong frontend are filtered out
CCSOURCES := $(wildcard *.cc)
ifeq ($(FRONTEND),Puma)
CCSOURCES := $(filter-out Clang%.cc, $(CCSOURCES))
else
CLANG_PATCHED_SOURCES := $(filter Clang-$(LLVM_VERSION)-%.cc, $(CCSOURCES))
CCSOURCES := $(filter-out Puma%.cc, $(CCSOURCES))
CCSOURCES := $(filter-out Clang-%.cc, $(CCSOURCES)) $(CLANG_PATCHED_SOURCES)
endif

OBJECTDIR := ObjFiles/$(TARGET)
OBJECTS := $(addprefix $(OBJECTDIR)/,$(CCSOURCES:.cc=.o) $(RCFILES:.rc=.o))

DEPDIR := DepFiles/$(TARGET)
DEPS := $(addprefix $(DEPDIR)/,$(CCSOURCES:.cc=.d))
# dependency file generation flags for g++; note that "=" is used instead of ":="
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d
DEPFLAGS_SHOW := -MT <file.o> -MMD -MP -MF <file.d>

CONFIGDIR := config

DIRS := $(OBJECTDIR) $(DEPDIR) $(BINDIR)

# ******************************
# *  E X A M P L E  / T E S T  *
# ******************************

# tool selection
export AC := $(shell pwd)/$(PROG)
export AG := $(shell pwd)/$(BINDIR)/ag++$(EXT) -g

MAKE ?= make --debug

# ac++ settings for tests
ACFLAGS := -k -v 9 -g


# ******************************
# *      T A R G E T S         *
# ******************************

define _show_target
	@echo "---"
	@echo "Making AspectC++ for TARGET=$(TARGET)"
	@echo "  Compiler = $(CXX) $(DEPFLAGS_SHOW) $(CPPFLAGS) $(CXXFLAGS)"
	@echo "  Linker   = $(CXX) $(CXXFLAGS) <objects> $(LDFLAGS)"
	@echo "---"
endef

all:
	@$(MAKE) -C ACModel
	@$(call _show_target)
	@$(MAKE) $(PROG)

#.NOTPARALLEL: all

strip: $(PROG)
	@$(STRIP) $<

showtarget:
	@$(call _show_target)

clean:  testclean
	@$(MAKE) -C ACModel clean
	@echo Making it clean.
	@rm -rf  core core.* *~ $(PROG) $(OBJECTDIR) $(DEPDIR) $(ERROR_FILE)

cleanall:	testclean doxygen-clean clean

test: $(PROG) testall

doxygen:
	@echo "Making AspectC++ documentation with doxygen"
	@doxygen doc/doxygen.conf && echo "=> see doc/doxygen/html/index.html"

doxygen-clean:
	@rm -rf doc/doxygen

.PHONY: all strip showtarget \
		test clean cleanall \
        doxygen doxygen-clean

# ******************************
# *       R U L E S            *
# ******************************

$(DIRS) :
	@mkdir -p $@

$(PROG): $(OBJECTS) $(ACMODELLIB)
	@echo "Linking $@."
	@mkdir -p $(BINDIR)
	@$(CXX) -o $@ $(CXXFLAGS) $^ $(LDFLAGS)

$(OBJECTDIR)/%.o : %.cc
	@echo Making object file $@.
	@mkdir -p $(OBJECTDIR) $(DEPDIR)
	@$(CXX) $(DEPFLAGS) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

# -Wold-style-cast to find classic C casts "a = (A*)b;"

test%:
	$(MAKE) -C tests -s  $*

%.example_make: %
	cd examples/$< ; \
	$(AC) $(ACFLAGS) -I. -p . -d ../$<-out \
	-r ../$<.acp ; \
	cp Makefile ../$<-out/Makefile; \
	cd ../$<-out; g++ -o $< *.cc -lpthread

%.example_run:	%.example_make
	@echo ""
	@echo ---- Running $* ----
	@cd examples/$*-out; `find . -type f -perm -700`

include $(wildcard $(DEPS))
