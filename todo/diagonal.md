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

### TO-DO:
 
* write `diag(Matrix)`, which presents the diagonal of a matrix as a vector (via TERW expression)
* write `diag(Vector)`, which presents a vector as the digonal of a matrix (via TERW expression)

* `UpperTriagMatrix`
* `LowerTriagMatrix`
* `SymmetricMatrix`
* `SkewSymmetricMatrix`
* `HermitianMatrix`
* `SkewHermitianMatrix`

* `SparseMatrix` - utilize `std::map`

* `RepMatMatrix`-- repeated Matrix matrix.
* `BlockMatrix` -- set via initializer list notation `G=((A,B),(C,D))`

* `JordanBlockMatrix`

* `BandedMatrix`
   * `JordanFormMatrix`


### Assignment
* only allow assignment to other diagonal matrices, not regular mayrices
* need to write specific `Matrix operator=(DiagMatrix)`
* set regular `Matrix` equal to special matrix "inflates" the matrix

