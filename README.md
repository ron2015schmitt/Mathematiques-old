# Mathématiques v3.2-r25

Mathématiques is numerical library for performing linear algebra, calculus, vector calculus, etc in C++ via simple MATLAB-like syntax while also providing run-time performance and memory usage of hand-coded C or Fortran.

_Mathématiques distinguishes itself from other libraries by an elegance and versatility that are only possible using the features of C++11,14, and 17._

# Table of Contents

- [Features](#features)
- [About](#about)
- [License](#license)
- [Examples](#examples)
- [Installation](#installation)
- [Configuration](#configuration)
- [Using Mathématiques](#using_mathematiques)
  * [EXAMPLE Makefile](#example-makefile)
  * [EXAMPLE Code File](#example-code-file)
- [User Guide](#user-guide)
- [Benchmarks](#benchmarks)
- [New Feature Schedule](#feature-schedule)
  
---------------------------------------------------------------------------

# Features 

+ **V3.0** the first official release

**Design**
  + Simple Matlab-like syntax with no run-time cost
  + Performance comparable to C and Fortran
  + Pretty printing and debugging mode
  + File I/O in various formats including formats for Matlab and Mathematica
  + Detailed pretty documentation in Markup.  
  + Markup Documents can be auto-generated from C++ code
  + "boiler plate" code is created using Python scripts for supporting functionality such as mixed-type math

**Data Types**
  + Arbitrary rank tenor arrays (Scalar, Vector, Matrix, etc)
  + Each tensor type can have tensor as datatype
    + eg. `Vector<Matrix<double>>` or `Matrix<Vector<double>>`, which can be used to represent a vector-valued function on a 2D or 3D mesh.
  + can have fixed (uses `array`) or variable dimensions (uses `valarray`)
  + fixed array size is ideal for small vectors, eg 2D or 3D vector
  + `Imaginary<D>` number template class that dovetails with the fundamental (real) types `D` and  with `std::complex<D>`

**Operators**
  + arithmetic defined for all types: ints, float, double, Complex, Vector, etc
  + mixed-type math with automatic type promotion: ints and floats, real and complex, vector and scalar, etc
    + eg. can add a vector of type `int` with a vector of type `std::complex<double>` and the output will be a vector of type `std::complex<double>`
    + eg. vector/scalar math, eg add a scalar value to every element of a vector or matrix
  + relational operators and boolean masks for vectors and matrices
  + boolean vector functions ```any```, ```all```, etc

**Mathematical functions**
  + Most functions work on all datetypes: floats, Complex, Vector, etc
  + Elemental math functions (sin, cos, exp, etc)
  + Special functions such as Bessel functions (C++17).

**Calculus**
  + Calculus (derivatives and integrals)
  + Taylor series
  + Fourier Series

**Tests**
  + 237 unit tests (so far), with a very clear and elegant output.
  + Python unit test generation in progress
  + CI/CT using Docker images in progress
  
# About

Development for this project originally took place during the years 2003-2008 

The code resurrected in 2019, improved, and put on github.

The code uses a form of C++ [template metaprogramming](https://en.wikipedia.org/wiki/Template_metaprogramming) called [expression templating](https://en.wikipedia.org/wiki/Expression_templates), the library provides computational efficiency on par with C/Fortran.

*Expression templating* produces complex code in the library itself, but the *user code* is simple, clean, and extremely efficient.

The GNU gcc (g++) compiler is used by default.

# License 

The code that makes up this library is copyrighted under the *MIT license*.

[Read the LICENSE file for details](LICENSE).

# Examples

### dot product—the `|` operator
* The dot product is accomplished via the `|` operator, such that the dot product takes a form similar to P.A.M. Dirac's 'bra-ket' notation.
* This definition becomes very useful for taking the product of matrices because any number of matrices can be multiplied in a single line of code.


**EXAMPLE 1**: Dot product of two real vectors `(v1|v2)`
```C++
Vector<double> v1(range<double>(1,4));
Vector<double> v2({1,-1,1,-1}); // C++11 list
```

**Some expressions with results**
```C++
  (v1|v1) = 30; 
  (v2|v2) = 4; 
  (v1|v2) = -2; 
  (v2|v1) = -2; 
  (v1|(2*v2+1)) = 6; 
```

**EXAMPLE 2**: Element-wise `Vector` math
```C++
Vector<double> v1(4);
v1 = {10,20,30,40}; // C++11 list
Vector<double> v2(4);
v2 = {1,2,3,4}; // C++11 list
```

**Some expressions with results**
```C++
  v1 + v2 = Vector<double> {11, 22, 33, 44}; 
  v1 - v2 = Vector<double> {9, 18, 27, 36}; 
  v1 * v2 = Vector<double> {10, 40, 90, 160}; 
  v1 / v2 = Vector<double> {10, 10, 10, 10}; 
```

### Vector-scalar arithmetic
* The binary operators +,-,*,/ can each be used to pair a scalar and a `Vector`.
* In this case the scalar is operated on each element of the vector


**EXAMPLE 3**: math with scalars and `Vector`s
```C++
Vector<double> v1(4);
v1 = {10,20,30,40}; // C++11 list
```

**Some expressions with results**
```C++
  v1 + 1 = Vector<double> {11, 21, 31, 41}; 
  1 + v1 = Vector<double> {11, 21, 31, 41}; 
  v1 - 10 = Vector<double> {0, 10, 20, 30}; 
  40 - v1 = Vector<double> {30, 20, 10, 0}; 
  v1 * 2 = Vector<double> {20, 40, 60, 80}; 
  2 * v1 = Vector<double> {20, 40, 60, 80}; 
  v1 / 10 = Vector<double> {1, 2, 3, 4}; 
  120 / v1 = Vector<double> {12, 6, 4, 3}; 
  1 + 120 / v1 - 8/8 + 5*v1*2 = Vector<double> {112, 206, 304, 403}; 
```

### Vector math functions
* A large number of functions is supported.  
* A function of a `Vector` operates on each element.  


**EXAMPLE 4**: functions of a `Vector`—rounding and sign-related 
```C++
Vector<double> v(7);
v = {-2.5,-2.25,-1,0,1,2.25,2.5}; // C++11 list
```

**Some expressions with results**: rounding and sign-related
```C++
  floor(v) = Vector<double> {-3, -3, -1, 0, 1, 2, 2}; 
  ceil(v) = Vector<double> {-2, -2, -1, 0, 1, 3, 3}; 
  round(v) = Vector<double> {-3, -2, -1, 0, 1, 2, 3}; 
  sgn(v) = Vector<double> {-1, -1, -1, 0, 1, 1, 1}; 
  abs(v) = Vector<double> {2.5, 2.25, 1, 0, 1, 2.25, 2.5}; 
```

# Installation

The first step is to clone the repo

```git clone https://github.com/ron2015schmitt/Mathematiques.git```

You now have a directory with all the Mathématiques source code



# Configuration

cd into the ```Mathematiques``` directory and execute the configure command:

```
cd Mathematiques
./configure
```
<a name="using_mathematiques"></a>
# Using Mathématiques

To use the Mathématiques library you need to 

1. Include the library file `include/mathq.h` in your source code
```C++
#include "mathq.h"
```
2. Include the `include/` subdirectory during compilation using the `-I` option

3. Include the `lib/` subdirectory during linking using the `-L` option

4. Include the option `-lmathq` during linking

## EXAMPLE Makefile

An example makefile, [examples/Makefile](examples/Makefile),  is included for your convenience.

*AFTER CONFIGURATION*, copy this makefile to YOUR source code directory (or cut and paste into an existing makefile).

## EXAMPLE Code File

An example of a C++ source file can be found at [examples/example.cpp](examples/example.cpp).

Compile the code and run the code using the Makefile
```bash
make example
./example
```
*or* by using `g++` directly
```bash
g++ -I ~/mathq/include example.cpp -o example -L ~/mathq/lib -lmathq
./example
```

# User Guide

Elegant markdown guide with colored code for all features.

[User's Guide](doc/README.md)

# Benchmarks

[Benchmarks](benchmark/README.md)



# Feature Schedule

* For information on current and future **development**, refer to the [Mathématiques Feature Schedule](todo/README.md).
