include ../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/infohelp.mk
include $(DIR_MATHQ)/make-lib/doc.mk

CHAPTERS = about license release-notes examples installation using-mathematiques coding-guide benchmarks test feature-schedule developer-guide


%/README.md: %/template.md $(CREATE_PAGE) toc.json
	@echo "dollar-star="$*
	python3 $(CREATE_PAGE) $*
	@chmod a-w $*/README.md

toc.json README.md header.md: $(CREATE_TOC) $(TAG_FILE_MATHQ) toc.txt 
	python3 $(CREATE_TOC) $(TAG_FILE_MATHQ)
	@chmod a-w toc.json README.md header.md

some: $(TAG_FILE_MATHQ) ../README.md toc.json README.md header.md $(CHAPTER_READMES) 
	@echo CHAPTERS=${CHAPTERS}
	@echo CHAPTER_READMES=${CHAPTER_READMES}
	@echo CHAPTER_NUMS=${CHAPTER_NUMS}
	@echo CHAPTER_HEADER_ABOVES=${CHAPTER_HEADER_ABOVES}

clean: cleanstd 
	@rm -f toc.json README.md header.md $(CHAPTER_READMES) $(CHAPTER_NUMS) $(CHAPTER_HEADER_ABOVES)


test: FORCE
	@echo $(CHAPTERS)
	@echo $(MAKE_SUBDIRS)
	@echo $(SUBDIRS_WOSLASH)
	@echo $(CHAPTERS_NOMAKE)
