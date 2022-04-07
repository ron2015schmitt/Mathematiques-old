include $(DIR_MATHQ)/make-lib/infohelp.mk

#############################################################################
# Project specific
#############################################################################

EXEC += example

all: $(EXEC)

clean: cleanstd
	@\rm -f $(EXEC)


