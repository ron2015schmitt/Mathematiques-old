

<details>

<summary>User Guide</summary>

1. [About](about/README.md)<br>
2. [License](license/README.md)<br>
3. [Release Notes](release-notes/README.md)<br>
4. [Example code](examples/README.md)<br>
5. [Installation](installation/README.md)<br>
6. [Using Mathématiques](using-mathematiques/README.md)<br>
7. [Coding Guide / Syntax](coding-guide/README.md)<br>
8. [Benchmarks](benchmarks/README.md)<br>
9. [Tests](test/README.md)<br>
10. [New Feature Schedule](feature-schedule/README.md)<br>
11. [Developer Guide](developer-guide/README.md)<br>


</details>




# 10. New Feature Schedule

## Planned Releases


### v3.4 Documenation Refactoring
1. Full refactoring of the online documentation
2. Complete _Coding Guide_, covering all the functionality
3. New in-depth _Developer Guide_

### v3.5 Indexing Refactoring
1. Refactor of vector/matrix/tensor indexing, including
  + new index/iterator types such as slices similar to Fortran and Python
  + [Index class and new indexing methodology](feature-schedule/index.md)

### v3.6 Display Refactoring
1. [Refactor mout and dout](feature-schedule/refactormout.md)
1. Group macros together, as much as possible. Clearly notate in a specific section in the documentation.
1. [Refactor getTypeName](feature-schedule/gettypename.md)
1. [Refactor FormatData](feature-schedule/formatdata.md)
1. Fix Printing of ```complex<Vector<double>>>``` etc
1. Add data type to output of inner products
  * disp(v1 + v2) = Vector<double> {16, -6}; 
  * disp(M1 + v2) = ^Vector<double>^ {-10, -10};  # missing part between the ^'s
1. [Tensor class FormatData](feature-schedule/tensorformatdata.md)
   1. compact 
   1. by aligned rows and columns with and without braces
   1. Mathematica
   1. Matlab

### v3.7 I/O Refactoring
1. [Save tensor to file](feature-schedule/filesave.md)
1. [Implement >> operators](feature-schedule/inputstreams.md)
1. [Load tensor from file](feature-schedule/fileload.md)

### v3.8 Debug Refactoring
1. put example.cpp::printoptsfile  into  print_mathq_info by grabbing (or passing) the file_name
  * handle when no filename
  * handle when no .g++_copts file
1. [Create Tensor Pool and Tensor info](feature-schedule/poolandinfo.md)
1. [Exceptions and Assertions](feature-schedule/exceptions.md)
1. [Implement all error checking](feature-schedule/errorchecking.md)
1. Implement `VectorOfPtrs` code properly
   * should only be included in debug mode
   * only needed for non-elemental functions
   * only needed when same vector appears on both sides of `=`

### Miscellaneous Small Features
* implement adjoint(Matrix) and ~(Matrix)
* `+=`, `-=`, `*=`, `/=`, operators for all tensors
* `logspace` function similar to `matlab`
* element wise dotproducts
* refactor: `::Type` to `::type`
* Add support for the rest of the [common math functions](https://en.cppreference.com/w/cpp/numeric/math) introduced in `C++11` and `C++20`: `frexp`, `isnan` etc, `ldexp`, `logb`, `ilogb`, `modf`, `div`, `remiander`, `remqou`, `fmod`, `ispow2`, `trunc`, `nearbyint`, `ceil2`, `floor2`, etc.
* `TensorRW` implementation of `real(t)` and `imag(t)`
* `TensorRW` implementation of `A.row(r)` and `A.col(r)`
* `Matrix` constructor and assignment using parameter pack (or list?) of `Vector`, as either cols or rows
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
   * support column major matrices and tensors
* add latex parser for disp?


### Unit testing
1. [Unit Testing](unittesting.md)
2. list requirements to perform testing in about section of top-level README

### Continuous Integration (CI) / Contunous Testing (CT)
1. set up CI / CT on [Github Actions](https://docs.github.com/en/actions) and using Docker 


### Calculus
1. `Interval` virtual class with subclasses `AB(a,b,N)`, `aB(a,b,N)` etc
1. Generalize linspace to generate grids in any number of dimensions. 
  * utilize `RepColMatrix` and `RepRowMatrix`
1. Integrals and derivatives along each dimension of Matrix or Tenspr
   *  best way to re-use code?

### Matrix Math via Lapack/Blas
1. [Special matrices](feature-schedule/diagonal.md)
  * use python script to generate matrix code
1. [Matrix operations](feature-schedule/matrixlapack.md)
1. openblas multi-threading support?
1. Optimize Dot Products for Special Matrices
* use LAPACK / BLAS where efficacious to do so


### Tensor Products
1. [Tensor dot product](feature-schedule/dotproduct.md)
1. [Outer Product and Wedge Product](feature-schedule/outerwedge.md)
1. [Add Benchmarks](feature-schedule/benchmarks.md)


### Vector Calculus
1. [2D and 3D Curvilinear Coordinate Systems](feature-schedule/coordsystems.md)
1. [Functions: R^n -> R^m](feature-schedule/functions.md)



### Tensor Calculus 
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
1. Use compomnent-free notation  for inner products (Misner, Wheeler, Thorne; Frankel)
     
1. generalized coordinate systems
   * basis vectors
   * metric tensor
   * index contraction / dot products
   * raising and lowering operations using the metric tensor
   * currying

### FFT Support via FFTW

### Filters 
1. FIR
1. IIR

### Interpolation and Smoothing

1. Linear using `C++20` functions `midpoint` and `lerp`
1. least squares smoothing and derivatives
1. [Savitsky-Golay](https://en.wikipedia.org/wiki/Savitzky%E2%80%93Golay_filter)
1. splines

### Random Numbers and statistics
* Random vectors for variety of distrubutions
   * utilize [C++11 random distributions functionality](https://en.cppreference.com/w/cpp/numeric/random)
* statistics: multiple linear regression, polynomial least-squares fitting (vandermonde matrix), pricples components analysis



### Possibilities
* investigate use of [swap](https://en.cppreference.com/w/cpp/algorithm/swap)
* investigate use of [multi-threading](https://en.cppreference.com/w/cpp/thread/thread)
* Create a `Number` class to generalize real,s imaginary and complex?
* Graded algebras, such as Clifford Algebras
   * use of Clifford Algebra for Computer Graphics applications
* Support other division algebras data types
   * Quarternions
   * Octonions
* `C++20` features?


 
### Contact

To contact me regarding suggestions, bugs, or volunteer work send an email to `Ron dot Schmitt @ me dot com`


| ⇦ <br />[9. Tests](test/README.md)  | [Table Of Contents](README.md)<br />10. New Feature Schedule<br /><img width=1000/> | ⇨ <br />[11. Developer Guide](developer-guide/README.md)   |
| ----------- | ----------- | ----------- |
