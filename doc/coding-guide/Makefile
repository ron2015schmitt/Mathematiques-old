include ../../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/core.mk
include $(DIR_MATHQ)/make-lib/infohelp.mk


MYDIR := $(shell pwd)
CREATE_TOC := $(DIR_MATHQ)/doc/createtoc.py
CREATE_PAGE := $(DIR_MATHQ)/doc/$(CREATE_PAGE)

CHAPTERS = 

%/README.md: %/template.md $(CREATE_PAGE) toc.json
	python3 $(CREATE_PAGE) $*
	@chmod a-w $*.md

toc.json README.md header.md: $(CREATE_TOC) $(TAG_FILE_MATHQ) toc.txt
	python3 $(CREATE_TOC) $(TAG_FILE_MATHQ)
	@chmod a-w toc.json README.md header.md



all: toc.json README.md header.md $(CHAPTERS) $(SUBDIRS)

clean:
	@rm -f toc.json README.md 


