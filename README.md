# Mathématiques v3.2-r25

Mathématiques is numerical library for performing linear algebra, calculus, vector calculus, etc in C++ via simple MATLAB-like syntax while also providing run-time performance and memory usage of hand-coded C or Fortran.

_Mathématiques distinguishes itself from other libraries by an elegance and versatility that are only possible using the features of C++11,14, and 17._

# Table of Contents

- [FEATURES](#features)
- [DEVELOPMENT](#development)
- [LICENSE](#license)
- [INSTALLATION](#installation)
- [CONFIGURATION](#configuration)
- [USING THE Mathématiques LIBRARY](#using-the-math-matiques-library)
  * [EXAMPLE MAKEFILE](#example-makefile)
  * [EXAMPLE CODE FILE](#example-code-file)
- [BENCHMARKS](#benchmarks)
- [User Guide](#user-guide)
- [Feature Schedule](#feature-schedule)
  
---------------------------------------------------------------------------

# FEATURES 

+ **V3.0** the first official release
  + Arbitrary rank tenor arrays (Scalar, Vector, Matrix, etc)
  + Each tensor type can have tensor as datatype, eg `Vector<Vector<double>>`, which can be used to represent a vector-valued function on a mesh.
  + can have fixed (uses `array`) or variable dimensions (uses `valarray`)
  + fixed array size is ideal for small vectors, eg 2D or 3D vector
  + Elemental math functions (sin, cos, exp, etc)
  + Special functions such as Bessek functions (C++17).
  + "boiler plate" code is created using Python scripts
  + Calculus (derivatives and integrals)
  + Taylor series
  + Fourier Series
  + Simple Matlab-like syntax with no run-time cost
  + Pretty printing
  + 237 unit tests (so far), with a very clear and elegant output.
  + Python unit test generation in progress
  + `Imaginary<D>` number template class that dovetails with the fundamental (rwal) types `D` and  with `std::complex<D>`
  + relational operators and boolean masks
  + mixed-type math with automatic type promotion, eg can add a vector of type `int` with a vector of type `std::complex<double>` and the output will be a vector of type `std::complex<double>`
  + vector/scalar math, eg add a scalar value to every element of a vector or matrix


# DEVELOPMENT

Development for this project originally took place during the years 2003-2008 

The code resurrected in 2019, improved, and put on github.

The code uses a form of C++ [template metaprogramming](https://en.wikipedia.org/wiki/Template_metaprogramming) called [expression templating](https://en.wikipedia.org/wiki/Expression_templates), the library provides computational efficiency on par with C/Fortran.

*Expression templating* produces complex code in the library itself, but the *user code* is simple, clean, and extremely efficient.

# LICENSE 

The code that makes up this library is copyrighted under the *MIT license*.

[Read the LICENSE file for details](LICENSE).

# INSTALLATION

The first step is to clone the repo

```git clone https://github.com/ron2015schmitt/mathq.git```

You now have a directory with all the Mathématiques source code

# CONFIGURATION

cd into the mathq directory and execute the configure command:

```
cd mathq
./configure
```

# USING THE Mathématiques LIBRARY

To use the Mathématiques library you need to 

1. Include the library file `include/mathq.h` in your source code
```C++
#include "mathq.h"
```
2. Include the `include/` subdirectory during compilation using the `-I` option

3. Include the `lib/` subdirectory during linking using the `-L` option

4. Include the option `-lmathq` during linking

## EXAMPLE MAKEFILE

An example makefile, [examples/Makefile](examples/Makefile),  is included for your convenience.

*AFTER CONFIGURATION*, copy this makefile to YOUR source code directory (or cut and paste into an existing makefile).

## EXAMPLE CODE FILE

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

# BENCHMARKS

[Benchmarks](benchmark/README.md)

# User's Guide

[User's Guide](doc/README.md)

# Feature Schedule

* For information on current and future **development**, refer to the [Mathématiques Feature Schedule](todo/README.md).
