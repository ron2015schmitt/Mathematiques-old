#############################################################
# VARIABLES
#############################################################

MAKEFILE := $(abspath $(lastword $(MAKEFILE_LIST)))

include ../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/variables.mk

MAKEFILE_REL := $(subst $(DIR_MATHQ)/,,$(MAKEFILE))

CREATE_TOC := $(DIR_MATHQ)/scripts/createtoc.py
CREATE_PAGE := $(DIR_MATHQ)/scripts/createpage.py

SUBDIRS_WOSLASH = $(subst /,,$(MAKE_SUBDIRS))
CHAPTERS_NOMAKE = $(filter-out $(SUBDIRS_WOSLASH),$(CHAPTERS))
CHAPTER_READMES = $(addsuffix /README.md,$(CHAPTERS_NOMAKE))
CHAPTER_NUMS = $(addsuffix /chap-num.md,$(CHAPTERS))
CHAPTER_DATA_FILES = $(addsuffix /data.json,$(CHAPTERS))

#---------------------------------------------------------------------
# RECIPES
#---------------------------------------------------------------------

include $(DIR_MATHQ)/make-lib/recipes.mk
include $(DIR_MATHQ)/make-lib/info.mk
include $(DIR_MATHQ)/make-lib/help.mk

%/README.md: %/template.md $(CREATE_PAGE) toc.json
	python3 $(CREATE_PAGE) $*
	@chmod a-w $*/README.md

toc.json README.md header.md: $(CREATE_TOC) $(TAG_FILE_MATHQ) toc.txt 
	python3 $(CREATE_TOC) $(TAG_FILE_MATHQ)
	@chmod a-w toc.json README.md header.md

clean: cleanstd

cleanall:: cleansubs

test: FORCE
	@echo CHAPTERS=$(CHAPTERS)
	@echo SUBDIRS_WOSLASH=$(SUBDIRS_WOSLASH)
	@echo CHAPTERS_NOMAKE=$(CHAPTERS_NOMAKE)
	@echo CHAPTER_READMES=$(CHAPTER_READMES)
	@echo CHAPTER_NUMS=$(CHAPTER_NUMS)
	@echo CHAPTER_DATA_FILES=$(CHAPTER_DATA_FILES)
