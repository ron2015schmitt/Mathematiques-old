# Planned Releases for 2020

_Updated January 2, 2020_

## Items for V3.3
1. [Update Documentation](doc.md)

## Items for V4.0 - Unit testing
1. [Unit Testing](unittesting.md)

## Items for V5.0 - Refactor indexing
1. [Index class and new indexing methodology](index.md)

## Items for V6.0 - Tensor Products
1. [Tensor dot product](dotproduct.md)
1. [Outer Product and Wedge Product](outerwedge.md)
1. [Add Benchmarks](benchmarks.md)

## Items for V7.0 -- Special Matrices
1. [Special matrices](diagonal.md)

## Items for V8.0 -- Calculus
1. `Interval` virtual class with subclasses `AB(a,b,N)`, `aB(a,b,N)` etc
1. Generalize linspace to generate grids in any number of dimensions. 
  * utilize `RepColMatrix` and `RepRowMatrix`
1. Integrals and derivatives along each dimension of Matrix or Tenspr

## Items for V9.0 -- Matrix Math via Lapack/Blas
1. [Matrix operations](matrixlapack.md)
1. openblas multi-threading support

## Items for V10.0 -- Optimize Dot Products for Special Matrices

## Items for V11.0 -- Vector Calculus
1. [2D and 3D Curvilinear Coordinate Systems](coordsystems.md)
1. [Functions: R^n -> R^m](functions.md)

## Items for V12.0 -- Refactor Display
1. [Refactor mout and dout](refactormout.md)
1. Group macros together, as much as possible. Clearly notate in a specific section in the documentation.
1. [Refactor getTypeName](gettypename.md)
1. [Refactor FormatData](formatdata.md)
1. Fix Printing of ```complex<Vector<double>>>``` etc
1. [Tensor class FormatData](tensorformatdata.md)
   1. compact 
   1. by aligned rows and columns with and without braces
   1. Mathematica
   1. Matlab

## Items for V13.0 -- File I/O
1. [Save tensor to file](filesave.md)
1. [Implement >> operators](inputstreams.md)
1. [Load tensor from file](fileload.md)

## Items for V14.0 -- Debug Functionality
1. [Create Tensor Pool and Tensor info](poolandinfo.md)
1. [Exceptions and Assertions](exceptions.md)
1. [Implement all error checking](errorchecking.md)
1. Implement `VectorOfPtrs` code properly
   * should only be included in debug mode
   * only needed for non-elemental functions
   * only needed when same vector appears on both sides of `=`

## Items for V15.0 -- Tensor Calculus 
1. contravariant and covariant vectors
   * define Rank0: 
      * Vector<NE=1>
   * define Rank1<N,bool>: 
      * Matrix<N,1> for bool=true (contravariant/high indices)
      * Matrix<1,N> for bool=false (covariant/low indices)
   * define Rank2<N,bool,bool>: 
      * Tensor<R=4> with dimenions (N,1,N,1) for <true,true> 
      * Tensor<R=4> with dimenions (N,1,1,N) for <true,false> 
      * Tensor<R=4> with dimenions (1,N,N,1) for <false,true> 
      * Tensor<R=4> with dimenions (1,N,1,N) for <false,false>       
1. generalized coordinate systems
   * basis vectors
   * metric tensor
   * index contraction / dot products
   * raising and lowering operations using the metric tensor

## Items for V16.0 -- FFT Support via FFTW

## Filters 
1. FIR
1. IIR

## Interpolation

1. Linear using `C++20` functions `midpoint` and `lerp`
1. least squares smoothing and derivatives
1. [Savitsky-Golay](https://en.wikipedia.org/wiki/Savitzky%E2%80%93Golay_filter)
1. splines


## Miscellaneous Small Features
* Random vectors for variety of distrubutions
   * utilize [C++11 random distributions functionality](https://en.cppreference.com/w/cpp/numeric/random)
* `+=`, `-=`, `*=`, `/=`, operators for all tensors
* refactor: `::Type` to `::type`
* Add support for the rest of the [common math functions](https://en.cppreference.com/w/cpp/numeric/math) introduced in `C++11` and `C++20`: `frexp`, `isnan` etc, `ldexp`, `logb`, `ilogb`, `modf`, `div`, `remiander`, `remqou`, `fmod`, `ispow2`, `trunc`, `nearbyint`, `ceil2`, `floor2`, etc.
* `TensorRW` implementation of `real(t)` and `imag(t)`
* `TensorRW` implementation of `A.row(r)` and `A.col(r)`
* Refactor `NumberType` etc to use constexpr fields instead of static methods
* Modify Taylor Series to operate at top level (not deep level.)  Test with Scalar<Matrix> and Vector <Matrix> 
   * dat(i) must call [i].
   * perhaps have a boolean in all TensorR subclasses that denotes which is faster: [i] or dat(i)
* `Vector` size modifications. Refer to [C++ Containers library](https://en.cppreference.com/w/cpp/container)
   * implement `join` functions for Vector and a scalar
   * Implement `insert(i)`, `remove(i)`,`pop_front`,`push_front`, `pop_back`,`push_back`, methods to `Vector` class
   * `NE == -1` -> use `std::vector` for storage
   * `NE == -2` -> use `std::list` for storage
   * `NE == -3` -> use `std::forward_list` for storage
   * `NE == -4` -> use `std::stack` for storage
   * `NE == -5` -> use `std::froward_stack` for storage
* `Matrix` size modifications. 
   * Implement `insertRow/Col(i)`, `removeRow/Col(i)`,`pop_top/bot`,`push_top/bot`, `pop_left/right`,`push_left/right`, methods to `Matrix` class

## Possibilities
* investigate use of [swap](https://en.cppreference.com/w/cpp/algorithm/swap)
* investigate use of [multi-threading](https://en.cppreference.com/w/cpp/thread/thread)
* Create a `Number` class to generalize real,s imaginary and complex?
* Graded algebras, such as Clifford Algebras
   * use of Clifford Algebra for Computer Graphics applications
* `C++20` features?
* statistics: multiple linear regression and PGA

## Other
1. [Developer guide](developerguide.md)
1. link on Wikipedia C++ numerical packages
1. [Release Checklist](checklist.md)
1. Remove `old/` directory and its files

## Contact

To contact me regarding suggestions, bugs, or volunteer work send an email to `Ron dot Schmitt @ me dot com`

---------------
---------------

_Links_

* [Mathématiques Overview](../README.md)
* [User Guide](../doc/README.md)

