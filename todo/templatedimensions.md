# Tensor Dimensions as Template Parameters

Add template parameters for dimensions of each Tensor class.  
* Each parameter should have the default value of 0
* If parameters are > 0, then the tensor is of fixed size and the `array` class is used for storage
* If paramters are <= 0, then the tensor is of variable size and the class `valarray` is used for storage.  The initial size is abs(parameter).
* The static if construct,`if constexpr(expr)`, as introduced in `C++17` is used to select which code to enable, such as whether to use an `array` or `valarray`

## Scalar class
The `Scalar<D>` class has no size, so no changes are needed.

## Vector class
The `Vector<D>` class has one size parameter.  The new class will be:

```C++
template class Vector<class D, int N = 0>
```

* change size and dimensions methods to use `N` if `N>0`
* use `array` instad of `valarray` if `N>0`
* if `N <= 0`, then `valarray` is used and initial size is `abs(N)`

## Matrix class
The `Matrix<D>` class has two size parameters.  The new class will be:

```C++
template class Vector<class D, int NR = 0, int NC = 0>
```
* if `NR>0 && NC>0` then use fixed size and `array`
* if `NR<=0 && NC<=0` then use variable size and `valarray`
* if only one of the values is greater than zero, then that dimension is fixed, but the other dimensions is variable and thus a `valarray` must be used.


## Tensor class
The `Tensor<D>` class has `0 <= M` size parameters.  The new class will use variadic template parameters.

```C++
template class Vector<class D, int ... Dims>
```
