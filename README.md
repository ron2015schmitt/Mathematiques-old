# COOLL
Columbia Object Oriented Linear algebra Library (COOLL)

COOLL is numerical library for performing linear algebra in C++ via simple MATLAB-like syntactic sugar while leveraging C++ templates to provide run-time performance and memory usage on par with C.

Advantages
+ object-oriented matrices and vectors
+ simple MATLAB-like syntactic sugar (eg, syntax to add two matrices is `A+B`, matrix vector multiply is `A|x` )
+ run-time performance and memory usage on par with C
+ does *not* produce intermediate objects (which crush run-time performance and inflate memory usage)
+ pretty formatted output of vectors and matrices
+ `CAREFUL` compile mode produces extensive information to aid in debugging
 + out of bounds access for vectors or matrices (e.g. x[10] where x is a
   vector of length 6.
 + adding/subtracting/multiplying/dividing vector or matrices of unequal
   size
 + invalid dot products of vector and/or matrices 
 + other assorted errors


---------------------------------------------------------------------------

# DEVELOPMENT

Development for this project took place during the years 2003-2008.

The code uses a technique called *expression templating*, the library provides computational efficiency on par with C/Fortran.

*Expression templating* produces complex code in the library itself, but the *user code* is simple, clean, and extremely efficient.

# LICENSE / COPYRIGHT

The code that makes up this library is copyrighted.
Read the LICENSE file.

# INSTALLATION

The first step is to unzip and untar the library:

gunzip cooll-vers.tar.gz
tar xf cooll-vers.tar

You now have a directory with all the COOLL source code

# CONFIGURATION

cd into the COOLL directory and exceute the following command:

```./configure```

This command builds the makefiles and compiles the source code into an
object code library that can be linked to (libcooll.a)



# EXAMPLES  

You will find examples in the subdirectory "examples". Compile the
examples using the make utility:

```make all```

This creates executables that can be run from the command line.  The
file "vexample.cpp is the best way to learn about coding with COOLL.


# SAMPLE MAKEFILE

A sample makefile is included for your convenience:

```examples/SampleMakefile```

AFTER CONFIGURATION, copy this makefile to YOUR source code directory
(or cut and paste into an existing makefile).


# USING THE COOLL LIBRARY

To use the COOLL library you need to include the library file "cooll.hpp"
and link to the libcooll.a library file.  See the following files for
examples

```examples/SampleMakefile```
```examples/vexample.cpp```


# MODES OF OPERATION

The COOLL library supports two mode of operation: CARFEUL and fast.

## fast mode

 This is the default.  All operations are performed without any error checking 
 (e.g. vector or matrix out of bounds access attempts, etc.)

## CAREFUL mode

 This mode can be turned on through two different methods (see the following item).
 In this mode extensive error checking is performed to notify the user of

 - out of bounds access for vectors or matrices (e.g. x[10] where x is a
   vector of length 6.
 - adding/subtracting/multiplying/dividing vector or matrices of unequal
   size
 - invalid dot products of vector and/or matrices 
 - other assorted errors



## SETTING THE MODE

The default mode is "fast mode".  Nothing needs to be done to set fast mode.

Setting to CAERFUL mode is performed via a #define statement. There are
two methods to accomplish this:

### RECOMMENDED METHOD: Use the provided sample makefile and specify CAREFUL=1 on the command line

example:

```make clean CAREFUL=1 myprogram```


The target "clean" is not needed, but is a reccomended practice.

If you want to recompile in fast mode, just use the makefile
without specifying the CAREFUL flag

```make clean myprogram```


### EXPLICIT METHOD: Add a #define statement BEFORE each cooll.hpp include statement

```C++
#define COOLL_CAREFUL 1
#include "cooll.hpp"
```


## RECOMMENDATIONS

While developing your code, use CAREFUL mode.  When you are convinced that it is operating
without errors, switch to fast mode.  

Compile a CAREFUL and a quick version of your code, giving the executables different names.
This way if a segmentation fault occurs, or you otherwise suspect an error, you can quickly
check the problem under careful mode.


##  NOTES

Compile time is also considerably slower in CAREFUL mode.
