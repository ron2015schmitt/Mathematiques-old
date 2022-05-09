<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.34</h1>

<details>

<summary>User Guide</summary>

# [User Guide](../README.md)<br>
1. [About](../about/README.md)<br>
2. [License](../license/README.md)<br>
3. _Release Notes_ <br>
4. [Installation](../installation/README.md)<br>
5. [Makefile / Using Mathématiques](../using-mathematiques/README.md)<br>
6. [Code Examples](../examples/README.md)<br>
7. [Coding Guide / Syntax](../coding-guide/README.md)<br>
8. [Benchmarks](../benchmarks/README.md)<br>
9. [Tests](../test/README.md)<br>
10. [New Feature Plans](../feature-schedule/README.md)<br>
11. [Developer Guide](../developer-guide/README.md)<br>


</details>



# 3. Release Notes


## **v3.4** Documentation Refactoring
  + Full refactoring of the online documentation
  + expanable table of contents header
  + navigation footer

## **v3.3** Build Process Refactoring
  + The build process has been fully refactored, simplified, and streamlined
  + The documentation refactoring has begun
  
## **v3.2** First Official Release

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


| ⇦ <br />[License](../license/README.md)  | [User Guide](../README.md)<br />Release Notes<br /><img width=1000/> | ⇨ <br />[Installation](../installation/README.md)   |
| ------------ | :-------------------------------: | ------------ |

