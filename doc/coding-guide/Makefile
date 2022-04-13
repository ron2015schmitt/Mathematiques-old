include ../../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/style.mk
<<<<<<< HEAD
include $(DIR_MATHQ)/make-lib/core.mk
include $(DIR_MATHQ)/make-lib/infohelp.mk


MYDIR := $(shell pwd)
CREATE_TOC := $(DIR_MATHQ)/doc/createtoc.py
CREATE_PAGE := $(DIR_MATHQ)/doc/createpage.py

=======
include $(DIR_MATHQ)/make-lib/infohelp.mk
include $(DIR_MATHQ)/make-lib/doc.mk
>>>>>>> 414823b388b18e49f5701298f15363ca011043b9


# do NOT include subdirectories that have a Makefile nor the top subdirectory
CHAPTERS = scalar display vector matrix linear-algebra tensor file-io debug
<<<<<<< HEAD
CHAPTER_FILES = $(addsuffix /README.md,$(CHAPTERS)) 
CHAPTER_NUMS = $(addsuffix /chap-num.md,$(CHAPTERS)) 
CHAPTER_HEADER_ABOVES = $(addsuffix /header.above.md,$(CHAPTERS))
=======
>>>>>>> 414823b388b18e49f5701298f15363ca011043b9

%/README.md: %/template.md $(CREATE_PAGE) toc.json
	python3 $(CREATE_PAGE) $*
	@chmod a-w $*/README.md

toc.json README.md header.md: $(CREATE_TOC) $(TAG_FILE_MATHQ) toc.txt
	python3 $(CREATE_TOC) $(TAG_FILE_MATHQ)
	@chmod a-w toc.json README.md header.md


<<<<<<< HEAD
norecurse: toc.json README.md header.md $(CHAPTER_FILES) $(MAKE_SUBDIRS)

clean: cleanstd 
	@rm -f ../README.md toc.json README.md header.md $(CHAPTER_FILES) $(CHAPTER_NUMS) $(CHAPTER_HEADER_ABOVES)
=======
some: $(TAG_FILE_MATHQ) toc.json README.md header.md $(CHAPTER_READMES) $(MAKE_SUBDIRS)

clean: cleanstd 
	@rm -f ../README.md toc.json README.md header.md $(CHAPTER_READMES) $(CHAPTER_NUMS) $(CHAPTER_HEADER_ABOVES)
>>>>>>> 414823b388b18e49f5701298f15363ca011043b9

