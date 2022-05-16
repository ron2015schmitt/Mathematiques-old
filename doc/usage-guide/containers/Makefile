#############################################################
# VARIABLES
#############################################################

CHAPTERS = vector matrix tensor

include ../../../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/doc.variables.mk

NONEXEC = branch.json README.md $(LEAF_READMES)
EXEC += 
ALL += 

#---------------------------------------------------------------------
# RECIPES
#---------------------------------------------------------------------
include $(DIR_MATHQ)/make-lib/doc.recipes.mk

%.md: %
	./$* > $@

