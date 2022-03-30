# Mathématiques v3.2-r25

Mathématiques is numerical library for performing linear algebra, calculus, vector calculus, etc in C++ via simple MATLAB-like syntax while also providing run-time performance and memory usage of hand-coded C or Fortran.

_Mathématiques distinguishes itself from other libraries by an elegance and versatility that are only possible using the features of C++11,14, and 17._

# Table of Contents

- [Features](#features)
- [About](#about)
- [License](#license)
- [Examples](#examples)
- [Installation](#installation)
  * [Download the source](#download-the-source)
  * [Install Prerequisites](#install-prerequisites)
  * [Docker-Images](#docker-images)
- [Using Mathématiques](#using_mathematiques)
  * [User Makefile](#user-makefile)
  * [EXAMPLE Code File](#example-code-file)
- [User Guide](#user-guide)
- [Benchmarks](#benchmarks)
- [New Feature Schedule](#feature-schedule)
- [Developer Guide](#developer-guide)
  
---------------------------------------------------------------------------

# Features 

+ **V3.2**

**Design**
  + Simple Matlab-like syntax with no run-time cost
  + Performance comparable to C and Fortran
  + Pretty printing with styles and colors
  + Debugging mode
  + File I/O in various formats including formats for Matlab and Mathematica
  + Detailed pretty documentation in Markup.  
  + Markup Documents can be auto-generated from C++ code.
  + "Boiler plate" code is created using Python scripts for supporting functionality such as mixed-type math

**Data Types**
  + Arbitrary rank tensor arrays (Scalar, Vector, Matrix, etc)
  + tensors can have 
    + variable dimensions, using `valarray`:  `Vector<double>`
    + fixed dimensions, using `array`: `Vector<double,3>`
  + fixed array size is ideal for small vectors, eg 2D or 3D vector
  + Each tensor type can have tensor as datatype
    + eg. `Vector<Matrix<double>>` or `Matrix<Vector<double>>`, which can be used to represent a vector-valued function on a 2D or 3D mesh.
  + `Imaginary<D>` number template class that dovetails with the fundamental (real) types `D` and  with `std::complex<D>`

**Operators**
  + arithmetic defined for all types: ints, float, double, Complex, Vector, etc
  + mixed-type math with automatic type promotion: ints and floats, real and complex, vector and scalar, etc
    + eg. can add a vector of type `int` with a vector of type `std::complex<double>` and the output will be a vector of type `std::complex<double>`
    + eg. vector/scalar math, eg add a scalar value to every element of a vector or matrix
  + relational operators and boolean masks for vectors and matrices
  + boolean vector functions ```any```, ```all```, etc

**Mathematical functions**
  + most functions work on all datetypes: floats, Complex, Vector, etc
  + elemental math functions (sin, cos, exp, etc)
  + special functions such as Bessel functions (C++17).

**Linear algreba**
  + element-wise mathematics for Vectors, Matrices, and Tensors
  + dot/inner product
  + outer product and wedge products in progress 

**Calculus**
  + Calculus (derivatives and integrals)
  + Taylor series
  + Fourier Series

**Tensor algreba**
  + convariant / contravairant tensors and operations are in progress...
 
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

**EXAMPLE 1**: Dot product of two real vectors `(v1|v2)`

**variable initialization**
```C++
Vector<double> v1(range<double>(1,4));
Vector<double> v2({1,-1,1,-1}); // C++11 list
```

**Some expressions with results**
```C++
  (v1|v1) = 30; 
  (v1|(2*v2+1)) = 6; 
```

**EXAMPLE 2**: Element-wise `Vector` math

**variable initialization**
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

**EXAMPLE 3**: math with scalars and `Vector`s

**variable initialization**
```C++
Vector<double> v1(4);
v1 = {10,20,30,40}; // C++11 list
```

**Some expressions with results**
```C++
  v1 + 1 = Vector<double> {11, 21, 31, 41}; 
  1 + 120 / v1 - 8/8 + 5*v1*2 = Vector<double> {112, 206, 304, 403}; 
```

**EXAMPLE 4**: functions of a `Vector`

**variable initialization**
```C++
Vector<double> v(7);
v = {-2.5,-2.25,-1,0,1,2.25,2.5}; // C++11 list
```

**Some expressions with results**
```C++
  floor(v) = Vector<double> {-3, -3, -1, 0, 1, 2, 2}; 
  round(v) = Vector<double> {-3, -2, -1, 0, 1, 2, 3}; 
```

# Installation

## Download the source

The first step is to clone the repo

```bash
git clone https://github.com/ron2015schmitt/Mathematiques.git
```

You now have a directory with all the Mathématiques source code

## Install Prerequisites

The following commands are required: `bash`, `python3`, `make`, `g++`, and `gfortran`.

The following library is required: `lapack`.

In Ubuntu, you can install these as follows
```bash
sudo apt update
sudo apt-get install build-essential
sudo apt-get install gfortran
sudo apt-get install liblapacke-dev
sudo apt-get install liblapack-doc
```
The above installation has been verified in [Ubuntu 20.04 LTS](https://releases.ubuntu.com/20.04/)

<a name="docker-images"></a>
### Docker images for the build environment

Docker build files and images are available with all of the prerequisites installed

| O/S  | Build file | Image |
| ----------- | ----------- | ----------- |
| [Ubuntu 20.04 LTS](https://releases.ubuntu.com/20.04/) | [Dockerfile](https://github.com/ron2015schmitt/Mathematiques/tree/master/docker/ubuntu-20.04) | [Image](https://hub.docker.com/repository/docker/electron2015/ubuntu-20.04-mathq-env) |

*The above images do NOT contain the Mathématiques library*

## Run the configuration

cd into the ```Mathematiques``` directory and execute the configure command:

```bash
cd Mathematiques
./configure
```
<a name="using-mathematiques"></a>
# Using Mathématiques

To use the Mathématiques library you need to 

1. Include the library file `include/mathq.h` in your source code
```C++
#include "mathq.h"
```
2. Include the `include/` subdirectory during compilation using the `-I` option

3. Include the `lib/` subdirectory during linking using the `-L` option

4. Include the option `-lmathq` during linking

## EXAMPLE Code File

An example of a C++ source file can be found at [examples/example.cpp](examples/example.cpp).

After configuration, Compile the code and run the code using the Makefile
```bash
make example
./example
```
## User Makefile

After configuration, your user makefile can be found at `example/Makefile`, for your convenience.

*AFTER CONFIGURATION*, copy this makefile to YOUR source code directory (or cut and paste into an existing makefile).

Here is an example of a [typical Makefile](examples/Makefile.example.mk).

# User Guide

Elegant markdown guide for all features, with syntax-highlighted code and examples.

[User's Guide](doc/user-guide/output/README.md)

# Benchmarks

[Benchmarks](benchmark/README.md)

# Feature Schedule

* For information on current and future **development**, refer to the [Mathématiques Feature Schedule](todo/README.md).

# Developer Guide

[Developer Guide](doc/developer/README.md)
