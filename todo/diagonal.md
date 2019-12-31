# Special matrices

_Back to [Table of Contents](README.md)_

Already Implemented:
* `ZeroMatrix`
* `IdentityMatrix`
* `ConstDiagMatrix`

TO-DO:
* `DiagMatrix`
* `RepColMatrix` -- need for Grids/meshes to save memory
* `RepRowMatrix` -- need for Grids/meshes to save memory
* `RepMatMatrix`
* `BlockMatrix`
* `JordanBlockMatrix`
* `JordanFormMatrix`
* `UpperTriagMatrix`
* `LowerTriagMatrix`
* `SymmetricMatrix`
* `AntiSymmetricMatrix`
* `SparseMatrix`


Notes:
* Do *not* inherit from Matrix since dimensions() will distinguish
* has `min(NR,NC)` elements 
* `A[i]` access ranges across diagonal, from `0` to `min(NR,NC)`
* `A(i,j)` access simply returns 0 if not on diagonal. error if try to write to `A(i,j)` with `i!=j`
* functions only act on diagonal (note this in doc)
* write `inflate` function to convert to `Nr x Nc` matrix
* write `diag(vector)` and `diag(matrix)` functions as well as vector(diag)
* only allow assignment to other diagonal matrices, not regular mayrices
* need to write specific `Matrix operator=(DiagMatrix)`

