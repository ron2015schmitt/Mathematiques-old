# Special matrices

_Back to [Table of Contents](README.md)_

* Special matrices do *not* inherit from Matrix since dimensions() will distinguish
* Special matrices do *not* allow nesting, other than as noted for block style matrices.


### Already Implemented:
* `ZeroMatrix`
* `IdentityMatrix`
* `ConstDiagMatrix`

### TO-DO:
* `ExchangeMatrix` (The J matrix)
* `DiagMatrix` and `DDiagMatrix`
   * Diag has `min(NR,NC)` elements 
   * `A[i]` access ranges across diagonal, from `0` to `min(NR,NC)`
   * `A(i,j)` access simply returns 0 if not on diagonal. error if try to write to `A(i,j)` with `i!=j`
   * `DDiagDecompMatrix`: functions only act on diagonal (for use in decompositions) (note this documentation).
   * write `diag(vector)` and `diag(matrix)` functions as well as `vector(diag)`
* `RepColMatrix` -- need for Grids/meshes to save memory
* `RepRowMatrix` -- need for Grids/meshes to save memory
* `RepMatMatrix`
* `BlockMatrix` -- set via initializer list notation 
```c++
G={{A,B},{C,D}}
``` 
* `JordanBlockMatrix`
* `BandedMatrix`
   * `ToeplitzMatrix`
   * `JordanFormMatrix`
* `UpperTriagMatrix`
* `LowerTriagMatrix`
* `SymmetricMatrix`
* `SkewSymmetricMatrix`
* `HermitianMatrix`
* `SkewHermitianMatrix`
* `SparseMatrix` - utilize `std::map`

### Assignment
* only allow assignment to other diagonal matrices, not regular mayrices
* need to write specific `Matrix operator=(DiagMatrix)`
* set regular `Matrix` equal to special matrix "inflates" the matrix

