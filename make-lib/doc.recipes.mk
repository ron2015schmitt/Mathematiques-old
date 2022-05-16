#---------------------------------------------------------------------
# RECIPES
#---------------------------------------------------------------------

include $(DIR_MATHQ)/make-lib/recipes.mk
include $(DIR_MATHQ)/make-lib/info.mk
include $(DIR_MATHQ)/make-lib/help.mk

# get rid of branch.json and see if everythng still works

# add subdir nodefiles as target
branch.json README.md: $(CREATE_DOC_BRANCH) $(TAG_FILE_MATHQ) body.temp.md title.src.md
	python3 $(CREATE_DOC_BRANCH) $(TAG_FILE_MATHQ)  --chapters $(CHAPTERS)  --nodes $(CHAPTER_BRANCHES)
#	@chmod a-w branch.json README.md 

.SECONDEXPANSION:  # use this so that we can use $$==% as prerequisites 
%/README.md: $(CREATE_DOC_LEAF) branch.json $$*/title.src.md $$*/body.temp.md $$*/node.json
	python3 $(CREATE_DOC_LEAF) $*

# 	@chmod a-w $*/README.md

# create from c++ executable
%.temp.md: %
	./$* > $@

# create from src.md file
%.temp.md: %.src.md
	cp $*.src.md $@

# create from bash script
%.temp.md: %.bash
	./$*.bash > $@

clean: cleanstd
	\rm -f branch.json README.md $(LEAF_READMES) $(CHAPTER_NODE_FILES) 

cleanall:: cleansubs

info-chapters: FORCE
	@echo
	@echo -e ${BLUE}${BOLD}CHAPTERS${DEFCLR}${NORMAL}=$(CHAPTERS)
	@echo
	@echo -e ${BLUE}${BOLD}CHAPTER_BRANCHES${DEFCLR}${NORMAL}=$(CHAPTER_BRANCHES)
	@echo
	@echo -e ${BLUE}${BOLD}CHAPTER_LEAVES${DEFCLR}${NORMAL}=$(CHAPTER_LEAVES)
	@echo
	@echo -e ${BLUE}${BOLD}LEAF_READMES${DEFCLR}${NORMAL}=$(LEAF_READMES)
	@echo
