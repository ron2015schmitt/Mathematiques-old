

###############################################################
# ITEMS SPECIFIC TO MATHQ
###############################################################


DIR_MATHQ = __DIR_MATHQ__
INCDIR_MATHQ = $(DIR_MATHQ)/include
LIBDIR_MATHQ = $(DIR_MATHQ)/lib
LIB_MATHQ = -lmathq
INCLUDES += -I $(INCDIR_MATHQ) 
LIBS += -L$(LIBDIR_MATHQ) $(LIB_MATHQ)

#  VERSION_FILE_MATHQ should be a bash file with VERSION_MATHQ=X.X
VERSION_FILE_MATHQ = $(DIR_MATHQ)/files/version.mathq
VERSION_MATHQ = `. $(VERSION_FILE_MATHQ) && echo "$${VERSION_MATHQ}"`
TAG_FILE_MATHQ = $(DIR_MATHQ)/files/tag.mathq
TAG_MATHQ = `cat $(TAG_FILE_MATHQ)`
VERSION_HEADER_FILE_MATHQ = $(DIR_MATHQ)/include/version_mathq.h

LIB_LAPACK = -llapack -lg2c


info_mathq:
	@echo
	@$(call hr)
	@$(call title,"mathq")
	@$(call echovar,DIR_MATHQ)
	@$(call echovar,INCDIR_MATHQ)
	@$(call echovar,LIBDIR_MATHQ)
	@$(call echovar,LIB_MATHQ)
	@$(call echovar,LIB_LAPACK)
	@$(call echovar,VERSION_FILE_MATHQ)
	@$(call echovar,VERSION_MATHQ)
	@$(call echovar,TAG_MATHQ)
	@$(call hr)
	@echo


