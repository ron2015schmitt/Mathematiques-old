#############################################################
# VARIABLES
#############################################################

CHAPTERS = real complex imaginary quaternion

include ../../../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/doc.variables.mk

NONEXEC = branch.json README.md $(LEAF_READMES)
EXEC += ./real/body
ALL += 

#---------------------------------------------------------------------
# RECIPES
#---------------------------------------------------------------------
include $(DIR_MATHQ)/make-lib/doc.recipes.mk

%.md: %
	./$* > $@

cleanall:: FORCE
	@echo "$(WHOAMI)"

