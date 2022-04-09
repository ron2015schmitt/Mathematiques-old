include ../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/core.mk
include $(DIR_MATHQ)/make-lib/infohelp.mk


CHAPTERS = about.md  benchmarks.md  developer-guide.md  examples.md  feature-schedule.md  installation.md  license.md  release-notes.md  test.md  user-guide.md  using-mathematiques.md



toc.json toc.md: toc.txt createtoc.py $(TAG_FILE_MATHQ)
	python3 createtoc.py $(TAG_FILE_MATHQ)

../README.md: createtop.py $(TAG_FILE_MATHQ)
	python3 createtop.py $(TAG_FILE_MATHQ)

%.md: %/template.md createpage.py toc.json
	python3 createpage.py $*

all: ../README.md $(CHAPTERS)
	make -j $(CHAPTERS)

clean:
	rm -f *.md toc.json

