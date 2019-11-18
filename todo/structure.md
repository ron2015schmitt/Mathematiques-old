# Structurural changes


## Recursive Tensors (Tensors with Tensor elements)

Implement code necessary so that mathematical operations work for recursive tensors, eg. `Vector<Vector<double>>`.  This allows for the most straightforward way to implement vector and tensor functions of space and time.


1. Methodology is to use `x[index]`, ie `operator[]`, for "deep indexing" that indexes from `0` to `deepsize()-1`, covering all the elements contained.  
1. For shallow indexing, ie first level indexing, use the `operator()` operators:
    1. `Scalar()` ✓ complete 
    1. `Vector(i)`-- in progress  
       1. change all new valarray statements to data_.resize(N)
       1. enable constructors and methods as required when NN==0
       1. need to convert all `[]` usage, eg in `operator=` and expressions, to `(i)` instead. or (better)  
       1. implement deep access in expressions.
    
    1. `Matrix(i,j)` 
    1. `Tensor(i...)`
    1. add .tdims() method to TensorAbstract
    1. asVector, asMatrix wrapper function expressions

## Miscellaneous
1. convert all binary functions in `functions.h` to the new methodlogy of `operator+`
1. convert all functors in `functors.h` to the new methodlogy of `New_Fun_Add` and delete old versions
1. Benchmark a large vector of 3D vectors. if slow, look into optimization
   1. Use type traits to determine ideal qualifier types for paramters and return values

## Tensor Dimensions as Template Parameters

Add template parameters for dimensions of each Tensor class.  
* Each parameter should have the default value of 0
* If parameters are > 0, then the tensor is of fixed size and the `array` class is used for storage
* If paramters are == 0, then the tensor is of variable size and the class `valarray` is used for storage.  
* The static if construct,`if constexpr(expr)`, as introduced in `C++17` is used to select which code to enable, such as whether to use an `array` or `valarray`

### Scalar class
The `Scalar<D>` class has no size, so no changes are needed.

### Matrix class
The `Matrix<D>` class has two size parameters.  The new class will be:

```C++
template class Vector<class D, int NR = 0, int NC = 0>
```
* if `NR>0 && NC>0` then use fixed size (`array`)
* if `NR=0 && NC=0` then use variable size (`valarray`)
* if only one of the values is greater than zero, then that dimension is fixed, but the other dimensions is variable and thus a `valarray` must be used.


### Tensor class
The `Tensor<D,int R>` class with Rank `R>=0` has size parameters.  Recall that R=0 is a scalar. The new class will use variadic template parameters.

```C++
template class Vector<class D, int R = 0, int ... Dims>
```
Likely don't need `R`, but may be useful for speficying if it can be resized, in which case better to change to `bool RESIZABLE`.

If not resizable, use static if's to enable one and only one element access function, for example if `Rank=3`

```C++
D& operator()(Index i1, Index i2, Index i3) {
  ....
}
```

Due to this, it is probably a good idea to not allow tensor to change rank, except by creating a new Tensor, similar to rehaphing a vector into a matrix.

