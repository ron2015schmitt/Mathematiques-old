include ../make-lib/dirmathq.mk
-include $(DIR_MATHQ)/make-lib/variables.mk
-include $(DIR_MATHQ)/make-lib/colors.mk
-include $(DIR_MATHQ)/make-lib/core.mk
-include $(DIR_MATHQ)/make-lib/infohelp.mk


libmathq.a: display.o debug.o slices.o 
	@echo "generating libmathq.a `cat $(TAG_FILE_MATHQ)`"
	@\ar rUuv libmathq.a $?

lib: libmathq.a
	@\mkdir -p $(DIR_MATHQ)/lib
	@\cp libmathq.a $(DIR_MATHQ)/lib/


all: lib 

clean: cleanstd
	@\rm -f $(DIR_MATHQ)/lib/libmathq.a


