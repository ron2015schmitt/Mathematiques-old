

# Mathématiques v3.3.14


## Description 

Mathématiques is numerical library for performing linear algebra, calculus, vector calculus, etc in C++ via simple MATLAB-like syntax while also providing run-time performance and memory usage of hand-coded C or Fortran.

_Mathématiques distinguishes itself from other libraries by an elegance and versatility that are only possible using the features of C++11,14, and 17._


## Features
+ Simple Matlab-like syntax with no run-time cost
+ Performance comparable to C and Fortran

### Math
+ Mixed-type math with auto-promotion
+ Imaginary type
  + Imaginary<double> + <double> auto-promotes to a std::complex<double>
+ Linear algebra
  + inner products
  + outer products
+ Tensors
+ A multitude of special functions that operate on
  + scalars
  + vectors
  + matrices
+ Calculus
  + derivatives
  + integrals

### Output, I/O, and debugging
+ Pretty printing of results
  + styles
  + colors
+ File I/O in various formats including formats for Matlab and Mathematica
+ Debugging modes
  + output includes variable names and formatted vectors / matrices
  + provide bounds checking of arrays and send warnings to the stderr
  + ability to track all large arrays in use

### Documentation
+ Detailed pretty documentation in Markdown.  
+ Markdown documents can be auto-generated from C++ code.

## News 

The first step of refactoring the core code has been completed.

+ v3.3 has been released
  + The build process has been fully refactored, simplified, and streamlined
  + The documentation refactoring has begun

## Coming soon

+ v3.4 Documenation
  + Full refactoring of the online documentation
  + Completed _Coding Guide_, covering all the functionality
  + New in-depth _Developer Guide_

+ v3.5 Indexing
  + Refactor of vector/matrix/tensor indexing, including
    + new index/iterator types such as slices similar to Fortan and Python

+ v3.6 Display and Debugging
  + Refactor of Display and Debugging

+ v3.7+ 
  + More matrix types
  + covariant and contravariant tensors
  + curvilinear coordinate systems


## Documentation

[User Guide](doc/README.md)

