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
# GENERAL VARS
###########################################################


SUBMAKES = $(wildcard */Makefile)
SUBS = $(wildcard */)
MAKE_SUBDIRS = $(dir $(SUBMAKES))
MAKECLEAN_SUBDIRS = $(addprefix clean_,$(MAKE_SUBDIRS))

# Each Makefile that has an include statement for this file should:
#  - define a variable EXEC that includes of the executable targets
EXEC ?=


###########################################################
#  SPECIAL TARGETS
###########################################################

.PHONY:

# Each Makefile that has an include statement for this file should define a target "norecurse" that makes all targets in that directory but not in subdirectories
default: norecurse

#prevent any default rules from being used
.SUFFIXES:

# don't delete .o files after compilation
.PRECIOUS: %.o 


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
# REAL TARGETS
#############################################################################

FORCE:

# This is used to recursively build - it calls the every subdirectory Makefile
$(MAKE_SUBDIRS): FORCE
	$(MAKE) -C $@

testsubs: FORCE
	@echo $(SUBS)
	@echo $(SUBMAKES)
	@echo $(MAKE_SUBDIRS)
	@echo $(MAKECLEAN_SUBDIRS)

# Target "all" build everything, traversing down the directory tree
# Each Makefile that has an include statement for this file should:
#  - define a target "norecurse" that makes all targets in that directory but not in subdirectories
all: default $(MAKE_SUBDIRS)


# creates a run file that executes all the $(EXEC) files
createrun: 
	@$(DIR_MATHQ)/scripts/createrun.bash $(EXEC)

# creates a .gitignore files for all the $(EXEC) files
.ONESHELL:
gitignore: 
	@\echo -e '# ****  This was created by the command "make gitignore".' > .gitignore
	@\echo -e '# ****  Do NOT manually edit.' >> .gitignore
	@\echo -e "/run" >> .gitignore
	@for name in $(EXEC)
	@do
	@  \printf "/$${name}\n" >> .gitignore
	@done


#############################################################################
# CLEANING
#############################################################################


clean_%: FORCE
	$(MAKE) -C $* cleanall

cleansubs: $(MAKECLEAN_SUBDIRS)


# Each Makefile that has an include statement for this file should:
#  - define a "clean" target with "cleanstd" as a prerequisite
cleanstd: FORCE 
	@command rm -f *.o
	@command rm -f *.a
	@command rm -f *.s
	@command rm -f *.g++_copts
	@command rm -f *.link_md
	@command rm -f core.*

# Target "cleansall" cleans everything, traversing down the directory tree
# Each Makefile that has an include statement for this file should:
#  - NOT define a "cleanall" target
cleanall: FORCE clean cleansubs
	@\rm -f run
	@\rm -f *.temp
	@\rm -f *.tmp
	@\rm -f *~
	@\rm -f ~*
	@\rm -f *.gz
	@\rm -f *.tar
	@\rm -f *.old


