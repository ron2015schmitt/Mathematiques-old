###########################################################
# GENERAL VARS
###########################################################

SHELL := /bin/bash

# dynamic variables

PWD = $(shell pwd)
WHOAMI = $(abspath $(lastword $(MAKEFILE_LIST)))
WHEREAMI = $(dir $(WHOAMI))

# dynamic variables
SUBMAKES = $(wildcard */Makefile)
SUBS = $(wildcard */)
MAKE_SUBDIRS = $(dir $(SUBMAKES))
MAKECLEAN_SUBDIRS = $(addprefix clean_,$(MAKE_SUBDIRS))


# Each Makefile that has an include statement for this file should:
#  - define a variable EXEC that includes of the executable targets
NONEXEC ?=
EXEC ?=
ALL ?=

# Each Makefile that has an include statement for this file should:
#  - define a variable ALL that includes any targets that are 
#    NOT part of "nonrecurse" nor "$(SUBMAKES)" but that should be
#    built for the "all" target defined in this file




###############################################################
# ITEMS SPECIFIC TO MATHQ FILES and DIRS
###############################################################

# static variables
MAKEDIR_MATHQ := $(DIR_MATHQ)/make-lib
TAG_FILE_MATHQ := $(DIR_MATHQ)/versioning/tag.mathq.out.txt

# dynamic variables
TAG_MATHQ = `cat $(TAG_FILE_MATHQ)`


# These vairables are used only for building Matehmatiques
# ie are not needed by the end user code
#
#  COMPATIBLE_VERSION_MATHQ_FILE should be a bash file with: export COMPATIBLE_VERSION_MATHQ=X.X

#scripts
CREATE_TOC := $(DIR_MATHQ)/scripts/createtoc.py
CREATE_TOP := $(DIR_MATHQ)/scripts/createtop.py
CREATE_PAGE := $(DIR_MATHQ)/scripts/createpage.py
CREATE_RUN := $(DIR_MATHQ)/scripts/createrun.bash

# static variables
TAG_ANNOTATION_FILE := $(DIR_MATHQ)/versioning/tag.annotation.mathq.out.txt
VERSION_HEADER_FILE_MATHQ := $(DIR_MATHQ)/include/version_mathq.h
COMPATIBLE_VERSION_MATHQ_FILE := $(DIR_MATHQ)/versioning/compatible.version.master.record.mathq

# dynamic variables
COMPATIBLE_VERSION_MATHQ = `. $(COMPATIBLE_VERSION_MATHQ_FILE) && echo "$${COMPATIBLE_VERSION_MATHQ}"`


####################################################################
# VARIABLES SPECIFIC TO includes and libs for compilers and linkers
####################################################################

INCDIR_MATHQ := $(DIR_MATHQ)/include
INCLUDES := -I $(INCDIR_MATHQ) 

LIB_LAPACK := -llapack -lg2c

LIBDIR_MATHQ := $(DIR_MATHQ)/lib
LIBNAME_MATHQ += mathq
LIBFILE_MATHQ := $(LIBDIR_MATHQ)/lib$(LIBNAME_MATHQ).a
LIB_MATHQ := -l$(LIBNAME_MATHQ)

LIBS := -L$(LIBDIR_MATHQ) $(LIB_MATHQ)



####################################################################
# Compiler and Linker flags 
####################################################################

####################################################################
# g++ COMPILER
#
# make help-g++
#      This will give a nice shortened summary of options.
#
# For full details of options and up to date list see:
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
#
#     "If you use multiple -O options, with or without level
#      numbers, the last such option is the one that is effective."
#
####################################################################

# COPT provided at the command line will append to options
override COPT ?=  -Wfatal-errors

# OPTIMIZE provided at the command line will supercede the following
#          That is the values below will be written over.
OPTIMIZE ?= -O2

CFLAGS = $(OPTIMIZE) $(COPT) $(INCLUDES)
CPPC = g++ -pipe --std=c++17 

ifdef MATHQ_DEBUG
CFLAGS += -D "MATHQ_DEBUG=$(MATHQ_DEBUG)"
endif


####################################################################
# gfortran COMPILER
####################################################################
FC = gfortran
override FOPT ?=
FFLAGS = $(FOPT)
LNK_FFLAGS = -lgfortran +fgcse-after-reload

####################################################################
# g++ linker
# LOPT provided at the command line will append to options
####################################################################
override LOPT ?=
LFLAGS = $(OPTIMIZE) $(LOPT)
