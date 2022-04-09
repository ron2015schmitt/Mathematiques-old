include ../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/core.mk
include $(DIR_MATHQ)/make-lib/infohelp.mk


CHAPTERS = about.md  benchmarks.md  developer-guide.md  examples.md  feature-schedule.md  installation.md  license.md  release-notes.md  test.md  coding-guide.md  using-mathematiques.md

%.md: %/template.md createpage.py toc.json
	python3 createpage.py $*

toc.json README.md header.d: createtoc.py $(TAG_FILE_MATHQ) toc.txt 
	python3 createtoc.py $(TAG_FILE_MATHQ)

../README.md: createtop.py $(TAG_FILE_MATHQ) top/template.md
	python3 createtop.py $(TAG_FILE_MATHQ)

all: ../README.md toc.json README.md header.d $(CHAPTERS)

clean:
	rm -f *.md toc.json

