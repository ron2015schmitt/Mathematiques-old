include ../make-lib/dirmathq.mk
include $(DIR_MATHQ)/make-lib/style.mk
include $(DIR_MATHQ)/make-lib/core.mk
include $(DIR_MATHQ)/make-lib/infohelp.mk

EXEC += printing testing testing2 tfoverloading depth indexing imaginary enableexperiment selfmethod parmpack recurseadd testunary testunary2 testunary3 test4deep insideout typeinfo testbinary testrelops testternary testjoin classes specialmats

# overide the default compiler options
OPTIMIZE = -O1


all: $(EXEC)

clean: cleanstd
	@\rm -f $(EXEC)


