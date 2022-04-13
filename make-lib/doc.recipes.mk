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
