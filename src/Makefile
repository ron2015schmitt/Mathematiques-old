


include ../Makefile


libmatricks.a: display.o matrickscommon.o verror.o merror.o p3vector.o
	@echo "configuring MATRICKS library `cat $(TAG_FILE_MATRICKS)`"
	ar rUuv libmatricks.a $?

$(EXEC): libmatricks.a
