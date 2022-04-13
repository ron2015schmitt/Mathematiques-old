
SUBDIRS_WOSLASH = $(subst /,,$(MAKE_SUBDIRS))
CHAPTERS_NOMAKE = $(filter-out $(SUBDIRS_WOSLASH),$(CHAPTERS))
CHAPTER_READMES = $(addsuffix /README.md,$(CHAPTERS_NOMAKE))
CHAPTER_NUMS = $(addsuffix /chap-num.md,$(CHAPTERS))
CHAPTER_HEADER_ABOVES = $(addsuffix /header.above.md,$(CHAPTERS))
