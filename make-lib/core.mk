SHELL := /bin/bash
PWD = $(shell pwd)


###############################################################
# ITEMS SPECIFIC TO MATHQ FILES and DIRS
###############################################################

# static variables
MAKEDIR_MATHQ := $(DIR_MATHQ)/make-lib
TAG_FILE_MATHQ := $(DIR_MATHQ)/versioning/tag.mathq.out.txt

# dynamic variables
TAG_MATHQ = `cat $(TAG_FILE_MATHQ)`


###############################################################
# ITEMS SPECIFIC TO includes and libs
###############################################################

INCDIR_MATHQ := $(DIR_MATHQ)/include
LIBDIR_MATHQ := $(DIR_MATHQ)/lib
LIB_LAPACK := -llapack -lg2c
LIB_MATHQ := -lmathq

INCLUDES := -I $(INCDIR_MATHQ) 
LIBS := -L$(LIBDIR_MATHQ) $(LIB_MATHQ)



###########################################################
#  SPECIAL TARGETS
###########################################################

.PHONY: default
default: all

#prevent any default rules from being used
.SUFFIXES:

# don't delete .o files after compilation
.PRECIOUS: %.o 

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
EXTRAS := -D "MATHQ_DEBUG=$(MATHQ_DEBUG)"
endif

%.o: %.cpp 
	@\echo -e "g++ compile options used:  $(OPTIMIZE)" > $*.g++_copts
	$(CPPC) $(CFLAGS) $(EXTRAS) -c $*.cpp -o $@


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
	@command rm -f *.g++_copts
	@command rm -f *.link_md
	@command rm -f core.*


cleanall: FORCE clean
	\rm -f run
	@\rm -f *.temp
	@\rm -f *.tmp
	\rm -f *~
	\rm -f ~*
	\rm -f *.gz
	\rm -f *.tar
	\rm -f *.old


createrun: 
	@$(DIR_MATHQ)/scripts/createrun.bash $(EXEC)

.ONESHELL:
gitignore: 
	@\echo -e '# ****  This was created by the command "make gitignore".' > .gitignore
	@\echo -e '# ****  Do NOT manually edit.' >> .gitignore
	@\echo -e "/run" >> .gitignore
	@for name in $(EXEC)
	@do
	@  \printf "/$${name}\n" >> .gitignore
	@done

