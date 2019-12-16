


include ../Makefile


libmathq.a: display.o debug.o slices.o 
	@echo "configuring MATHQ library `cat $(TAG_FILE_MATHQ)`"
	ar rUuv libmathq.a $?

$(EXEC): libmathq.a
