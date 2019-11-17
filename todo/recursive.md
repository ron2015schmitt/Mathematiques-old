# Recursive Tensors (Tensors with Tensor elements)

Implement code necessary so that mathematical operations work for recursive tensors, eg. `Vector<Vector<double>>`.  This allows for the most straightforward way to implement vector and tensor functions of space and time.

1. Methodology is to use `x[index]`, ie `operator[]`, for "deep indexing" that indexes from `0` to `deepsize()-1`, covering all the elements contained.  
1. For shallow indexing, ie first level indexing, use the `operator()` operators:
    1. `Scalar()`  (done)
    1. `Vector(i)`  (start from experimental class `NewVector`)
    1. `Matrix(i,j)` 
    1. `Tensor`
1. Repeat methodology for expressions
