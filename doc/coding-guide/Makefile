include ../../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/core.mk
include $(DIR_MATHQ)/make-lib/infohelp.mk


MYDIR := $(shell pwd)
CREATE_TOC := $(DIR_MATHQ)/doc/createtoc.py
CREATE_PAGE := $(DIR_MATHQ)/doc/createpage.py



# do NOT include subdirectories that have a Makefile nor the top subdirectory
CHAPTERS = scalar display vector matrix linear-algebra tensor file-io debug
CHAPTER_FILES = $(addsuffix /README.md,$(CHAPTERS)) 
CHAPTER_NUMS = $(addsuffix /chap-num.md,$(CHAPTERS)) 
CHAPTER_HEADER_ABOVES = $(addsuffix /header.above.md,$(CHAPTERS))

%/README.md: %/template.md $(CREATE_PAGE) toc.json
	python3 $(CREATE_PAGE) $*
	@chmod a-w $*/README.md

toc.json README.md header.md: $(CREATE_TOC) $(TAG_FILE_MATHQ) toc.txt
	python3 $(CREATE_TOC) $(TAG_FILE_MATHQ)
	@chmod a-w toc.json README.md header.md


all: toc.json README.md header.md $(CHAPTER_FILES) $(SUBDIRS)

clean: cleanstd 
	@rm -f ../README.md toc.json README.md header.md $(CHAPTER_FILES) $(CHAPTER_NUMS) $(CHAPTER_HEADER_ABOVES)

