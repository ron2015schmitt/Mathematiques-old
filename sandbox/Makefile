#############################################################
# VARIABLES
#############################################################
include ../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/variables.mk

NONEXEC = 
EXEC += printing testing testing2 tfoverloading depth indexing imaginary enableexperiment selfmethod parmpack recurseadd testunary testunary2 testunary3 test4deep insideout typeinfo testbinary testrelops testternary testjoin classes specialmats
ALL += run gitignore

# overide the default compiler options
OPTIMIZE = -O1

#---------------------------------------------------------------------
# RECIPES
#---------------------------------------------------------------------

include $(DIR_MATHQ)/make-lib/recipes.mk
include $(DIR_MATHQ)/make-lib/infohelp.mk

clean: cleanstd

