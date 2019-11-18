# Tensor dot product

* Use new `<D1,D2>` methodology, following the `operator+` code
* Implement dot product for each tensor class:
   * Scalar • Scalar
   * Vector • Vector
   * Vector • Matrix
   * Matrix • Vector
   * Matrix • Matrix
* For Tensor class sum along the inner dimension of each.
* implement `dot(t1,t2)` functions as well as `operator|`
* implement `dotel(t1,t1)` functions for element-wise dot product, needed for `Vector<Vector<double>>`
* move all code to `functions.h` and get rid of `functions_cplx.h`
