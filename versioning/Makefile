#############################################################
# VARIABLES
#############################################################

MAKEFILE := $(abspath $(lastword $(MAKEFILE_LIST)))

include ../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/variables.mk

MAKEFILE_REL := $(subst $(DIR_MATHQ)/,,$(MAKEFILE))


NONEXEC = newrev
EXEC += 
ALL += 

# overide the default compiler options
OPTIMIZE = -O3 -finline-limit=750


#---------------------------------------------------------------------
# RECIPES
#---------------------------------------------------------------------

include $(DIR_MATHQ)/make-lib/recipes.mk
include $(DIR_MATHQ)/make-lib/info.mk
include $(DIR_MATHQ)/make-lib/help.mk

newrev: FORCE
	\python3 $(DIR_MATHQ)/scripts/createrev.py $(COMPATIBLE_VERSION_MATHQ_FILE) $(TAG_FILE_MATHQ) $(TAG_ANNOTATION_FILE)
	@chmod a-w $(TAG_FILE_MATHQ) 
	@chmod a-w $(TAG_ANNOTATION_FILE)

$(TAG_FILE_MATHQ) $(TAG_ANNOTATION_FILE): $(COMPATIBLE_VERSION_MATHQ_FILE)
	newrev

clean: cleanstd
	\rm -f $(TAG_FILE_MATHQ) 
	git restore $(TAG_FILE_MATHQ) 
	\rm -f $(TAG_ANNOTATION_FILE)
	git restore $(TAG_ANNOTATION_FILE) 

