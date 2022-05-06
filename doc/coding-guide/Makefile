#############################################################
# VARIABLES
#############################################################

CHAPTERS = scalar vector matrix tensor notation operators display linear-algebra  file-io debug

include ../../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/doc.variables.mk

NONEXEC = branch.json README.md $(LEAF_READMES)
EXEC += ./notation/body ./operators/body
ALL += 

#---------------------------------------------------------------------
# RECIPES
#---------------------------------------------------------------------
include $(DIR_MATHQ)/make-lib/doc.recipes.mk

%.md: %
	./$* > $@



