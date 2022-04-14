#---------------------------------------------------------------------
# RECIPES
#---------------------------------------------------------------------

include $(DIR_MATHQ)/make-lib/recipes.mk
include $(DIR_MATHQ)/make-lib/info.mk
include $(DIR_MATHQ)/make-lib/help.mk

branch.json README.md: $(CREATE_DOC_BRANCH) $(TAG_FILE_MATHQ)
	python3 $(CREATE_DOC_BRANCH) $(TAG_FILE_MATHQ)  --chapters $(CHAPTERS)  --nodes $(CHAPTER_BRANCHES)
#	@chmod a-w branch.json README.md 

.SECONDEXPANSION:  # use this so that we can use $$==% as prerequisites 
%/README.md: $(CREATE_DOC_LEAF) branch.json $$*/title.md $$*/body.md $$*/node.json
	python3 $(CREATE_DOC_LEAF) $*

# 	@chmod a-w $*/README.md

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
