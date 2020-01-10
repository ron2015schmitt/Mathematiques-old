# Special matrices

_Back to [Table of Contents](README.md)_

* Special matrices do *not* inherit from Matrix since dimensions() will distinguish
* Special matrices do *not* allow nesting, other than as noted for block style matrices.


### Already Implemented:
* `MatrixZero`
* `MatrixIdentity`
* `MatrixExchange` (The J matrix)
* `MatrixConstDiag`
* `MatrixDiagonal`
* `MatrixRevDiag`  
* `MatrixRepCol` -- repeated Column matrix. need for Grids/meshes to save memory
* `MatrixRepRow` -- repeated Row matrix. need for Grids/meshes to save memory
* `MatrixVandermonde`
* `MatrixToeplitz`
* `UpperTriagMatrix`
* `LowerTriagMatrix`
* `SymmetricMatrix`
* `SkewSymmetricMatrix`
* `HermitianMatrix`
* `SkewHermitianMatrix`

### TO-DO:
 
* write `diag(Matrix)`, which presents the diagonal of a matrix as a vector (via TERW expression)
* write `diag(Vector)`, which presents a vector as the digonal of a matrix (via TERW expression)
* implement `constructor(constTensor<X,D,D,1,2>& x)` and `operator=(constTensor<X,D,D,1,2>& x)`
   * need `(r,c)` method for TensorR
   * `Matrix` should use `(r,c)` instead of `.dat()` and `[k]`
* implement direct data access for each matrix
  * implement `dataIndex(r,c)` method for use with `data_`  (refer to `MatrixSymmetric`)
* perhaps implement iterator for each type of matrix (as a subclass) at some point

## Other Matrices
* `SparseMatrix` - utilize `std::map`
* `RepMatMatrix`-- repeated Matrix matrix.
* `BlockMatrix` -- set via initializer list notation `G=((A,B),(C,D))`
* `JordanBlockMatrix`
* `BandedMatrix`
   * `JordanFormMatrix`



