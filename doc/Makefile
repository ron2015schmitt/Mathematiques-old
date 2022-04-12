include ../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/core.mk
include $(DIR_MATHQ)/make-lib/infohelp.mk

MYDIR := $(shell pwd)
CREATE_TOC := $(DIR_MATHQ)/doc/createtoc.py
CREATE_PAGE := $(DIR_MATHQ)/doc/createpage.py

CHAPTERS = about license release-notes examples installation using-mathematiques coding-guide benchmarks test feature-schedule developer-guide
SUBDIRS_WOSLASH = $(subst /,,$(MAKE_SUBDIRS))
CHAPTERS_NOMAKE = $(filter-out $(SUBDIRS_WOSLASH),$(CHAPTERS))
CHAPTER_FILES = $(addsuffix /README.md,$(CHAPTERS_NOMAKE))
CHAPTER_NUMS = $(addsuffix /chap-num.md,$(CHAPTERS))
CHAPTER_HEADER_ABOVES = $(addsuffix /header.above.md,$(CHAPTERS))



%/README.md: %/template.md $(CREATE_PAGE) toc.json
	@echo "dollar-star="$*
	python3 $(CREATE_PAGE) $*
	@chmod a-w $*/README.md

toc.json README.md header.md: $(CREATE_TOC) $(TAG_FILE_MATHQ) toc.txt 
	python3 $(CREATE_TOC) $(TAG_FILE_MATHQ)
	@chmod a-w toc.json README.md header.md

../README.md: createtop.py $(TAG_FILE_MATHQ) top/template.md
	python3 createtop.py $(TAG_FILE_MATHQ)
	@chmod a-w ../README.md


norecurse: ../README.md toc.json README.md header.md $(CHAPTER_FILES) 
	@echo CHAPTERS=${CHAPTERS}
	@echo CHAPTER_FILES=${CHAPTER_FILES}
	@echo CHAPTER_NUMS=${CHAPTER_NUMS}
	@echo CHAPTER_HEADER_ABOVES=${CHAPTER_HEADER_ABOVES}

clean: cleanstd 
	@rm -f ../README.md toc.json README.md header.md $(CHAPTER_FILES) $(CHAPTER_NUMS) $(CHAPTER_HEADER_ABOVES)


test: FORCE
	@echo $(CHAPTERS)
	@echo $(MAKE_SUBDIRS)
	@echo $(SUBDIRS_WOSLASH)
	@echo $(CHAPTERS_NOMAKE)
