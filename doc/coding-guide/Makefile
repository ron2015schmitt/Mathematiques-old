include ../../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/infohelp.mk
include $(DIR_MATHQ)/make-lib/doc.mk


# do NOT include subdirectories that have a Makefile nor the top subdirectory
CHAPTERS = scalar display vector matrix linear-algebra tensor file-io debug

%/README.md: %/template.md $(CREATE_PAGE) toc.json
	python3 $(CREATE_PAGE) $*
	@chmod a-w $*/README.md

toc.json README.md header.md: $(CREATE_TOC) $(TAG_FILE_MATHQ) toc.txt
	python3 $(CREATE_TOC) $(TAG_FILE_MATHQ)
	@chmod a-w toc.json README.md header.md


some: $(TAG_FILE_MATHQ) toc.json README.md header.md $(CHAPTER_READMES) $(MAKE_SUBDIRS)

clean: cleanstd 
	@rm -f ../README.md toc.json README.md header.md $(CHAPTER_READMES) $(CHAPTER_NUMS) $(CHAPTER_HEADER_ABOVES)

