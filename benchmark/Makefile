include ../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/colors.mk
include $(DIR_MATHQ)/make-lib/core.mk
include $(DIR_MATHQ)/make-lib/infohelp.mk

EXEC += benchmark

# overide the default compiler options
OPTIMIZE = -O3 -finline-limit=750


all: $(EXEC)

clean: cleanstd
	@\rm -f $(EXEC)


