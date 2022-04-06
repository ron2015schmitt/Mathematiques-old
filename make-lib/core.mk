SHELL := /bin/bash
PWD = $(shell pwd)


###############################################################
# ITEMS SPECIFIC TO MATHQ FILES and DIRS
###############################################################

MAKEDIR_MATHQ := $(DIR_MATHQ)/make-lib
INCDIR_MATHQ := $(DIR_MATHQ)/include
LIBDIR_MATHQ := $(DIR_MATHQ)/lib
LIB_LAPACK = -llapack -lg2c
LIB_MATHQ := -lmathq
INCLUDES += -I $(INCDIR_MATHQ) 
LIBS += -L$(LIBDIR_MATHQ) $(LIB_MATHQ)



###########################################################
#  SPECIAL TARGETS
###########################################################

.PHONY: default
default: all

#prevent any default rules from being used
.SUFFIXES:

# don't delete .o files after compilation
.PRECIOUS: %.o %_opts.cpp

EXEC ?=

#############################################################################
# g++ COMPILER
#
# For full details of options and up to date list see:
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
#
#     "If you use multiple -O options, with or without level
#      numbers, the last such option is the one that is effective."
#
#############################################################################

# COPT provided at the command line will append to options
override COPT ?=  -Wfatal-errors

# OPTIMIZE provided at the command line will supercede the following
#          That is the values below will be written over.
OPTIMIZE ?= -O2

CFLAGS = $(OPTIMIZE) $(COPT) $(INCLUDES)
CPPC = g++ -pipe --std=c++17 

EXTRAS := 
ifdef MATHQ_DEBUG
EXTRAS := -D"MATHQ_DEBUG"
endif

%.o: %.cpp 
ifdef MATHQ_COPTS
	@\echo "#define MATHQ_COPTS 1" > $*.cpp__opts
	@\echo "char COMPILER_OPT_STR[] = "\"$(OPTIMIZE)\";" >> $*.cpp__opts
	@\cat $*.cpp >> $*.cpp__opts
	$(CPPC) $(CFLAGS) $(EXTRAS) -D"MATHQ_COPTS" -c $*.cpp__opts -o $@
else
	$(CPPC) $(CFLAGS) $(EXTRAS) -c $*.cpp -o $@
endif


#############################################################################
# gfortran COMPILER
#############################################################################
FC = gfortran
override FOPT ?=
FFLAGS = $(FOPT)
LNK_FFLAGS = -lgfortran +fgcse-after-reload

%.o: %.f 
	$(FC) $(FFLAGS) -c $*.f -o $*.o


#############################################################################
# g++ linker
# LOPT provided at the command line will append to options
#############################################################################
LNK = g++
override LOPT ?=
LFLAGS = $(OPTIMIZE) $(LOPT)

%: %.o 
	$(CPPC) $(LFLAGS) $*.o -o $@ $(LIBS) 


#############################################################################
# Clean up 
#############################################################################

FORCE:

cleanstd: FORCE 
	@command rm -f *.o
	@command rm -f *.a
	@command rm -f *.s
	@command rm -f *.cpp__opts
	@command rm -f *.temp
	@command rm -f *.tmp
	@command rm -f *.link_md
	@command rm -f *~
	@command rm -f core.*


#############################################################################
# User Code
#############################################################################

