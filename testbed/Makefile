
EXEC =   vtestbasic vtestcomplex mtestbasic mtestbasic2 mtestcomplex mtestcomplex2 mvtestbasic mvtestcomplex vtestbool mtestbool vtestaccess mtestaccess mtestaccess2 mtestaccess3 mvtestaccess vtestinput mtestinput mtestconstructors vtestconstructors p3vtestbasic p3vtestcomplex p3vtestinput p3vtestconstructors debugtools multivec


LAPACKEXEC= mtestsvd


include ../Makefile

mtestsvd: mtestsvd.o
	$(CXX) $(LDFLAGS) $@.o -o $@ $(LIBS) $(LIB_LAPACK)

lapacktests: $(LAPACKEXEC)

