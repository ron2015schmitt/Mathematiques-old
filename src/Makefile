


include ../Makefile


libmatricks.a: display.o debug.o p3vector.o
	@echo "configuring MATRICKS library `cat $(TAG_FILE_MATRICKS)`"
	ar rUuv libmatricks.a $?

$(EXEC): libmatricks.a
