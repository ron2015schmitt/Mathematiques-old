include ../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/core.mk
include $(DIR_MATHQ)/make-lib/infohelp.mk

# do NOT include subdirectories that have a Makefile nor the top subdirectory
CHAPTERS = about benchmarks developer-guide examples feature-schedule installation license release-notes test using-mathematiques
CHAPTER_FILES = $(addsuffix /README.md,$(CHAPTERS))
CHAPTER_NUMS = $(addsuffix /chap-num.md,$(CHAPTERS))
CHAPTER_HEADER_ABOVES = $(addsuffix /header.above.md,$(CHAPTERS))

%/README.md: %/template.md createpage.py toc.json
	python3 createpage.py $*
	@chmod a-w $*.md

toc.json README.md header.md: createtoc.py $(TAG_FILE_MATHQ) toc.txt 
	python3 createtoc.py $(TAG_FILE_MATHQ)
	@chmod a-w toc.json README.md header.md

../README.md: createtop.py $(TAG_FILE_MATHQ) top/template.md
	python3 createtop.py $(TAG_FILE_MATHQ)
	@chmod a-w ../README.md


all: ../README.md toc.json README.md header.md $(CHAPTERS) $(SUBDIRS)

clean: cleanstd 
	@rm -f ../README.md toc.json README.md header.md $(CHAPTER_FILES) $(CHAPTER_NUMS) $(CHAPTER_HEADER_ABOVES)



