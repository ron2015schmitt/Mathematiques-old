#############################################################
# VARIABLES
#############################################################

MAKEFILE := $(abspath $(lastword $(MAKEFILE_LIST)))

include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/variables.mk

MAKEFILE_REL := $(subst $(DIR_MATHQ)/,,$(MAKEFILE))

# Scripts
CREATE_DOC_BRANCH := $(DIR_MATHQ)/scripts/createdocbranch.py
CREATE_DOC_LEAF := $(DIR_MATHQ)/scripts/createdocleaf.py

# CHAPTERS must be defined in the "incuder" file
CHAPTER_NODE_FILES = $(addsuffix /node.json,$(CHAPTERS))
CHAPTER_BRANCHES = $(subst /,,$(MAKE_SUBDIRS))
CHAPTER_LEAVES = $(filter-out $(CHAPTER_BRANCHES),$(CHAPTERS))

LEAF_READMES = $(addsuffix /README.md,$(CHAPTER_LEAVES))


info::
	@echo
	@$(call hr)
	@$(call title,"doc related")
	@$(call echovar,MAKEFILE)
	@$(call echovar,MAKEFILE_REL)
	@$(call echovar,CREATE_DOC_BRANCH)
	@$(call echovar,CREATE_DOC_LEAF)
	@$(call echovar,CHAPTER_NODE_FILES)
	@$(call echovar,CHAPTER_BRANCHES)
	@$(call echovar,CHAPTER_LEAVES)
	@$(call echovar,LEAF_READMES)
