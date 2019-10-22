# Recursive Tensors (Tensors with Tensor elements)

Implement code necessary so that mathematical operations work for recursive tensors, eg. `Vector<Vector<double>>`.  This allows for the most straightforward way to implement vector and tensor functions of space and time.

1. Methodology is to use `x[index]`, ie `operator[]`, for "deep indexing" that indexes from `0` to `deepsize()-1`, covering all the elements contained.  
1. For shallow indexing, ie first level indexing, use the `operator()` operators:
    1. `Scalar()`
    1. `Vector(i)`
    1. `Matrix(i,j)` etc
1. classes `NewScalar` and `NewVector` have already been created and tested to some extent.  Test this code with unit tests and doc code.  Then release.
1. Repeat methodology for `Matrix` and `Tensor`
1. Repeat methodology for expressions
1. Will need unit testing 
