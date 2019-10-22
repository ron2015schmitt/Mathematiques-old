# Diagonal matrices

* Probably best to *not* inherit from Matrix since dimensions() will distinguish
* has `min(NR,NC)` elements 
* `A[i]` access ranges across diagonal, from `0` to `min(NR,NC)`
* `A(i,j)` access simply returns 0 if not on diagonal. error if try to write to `A(i,j)` with `i!=j`
* functions only act on diagonal (note this in doc)
* write `inflate` function to convert to `Nr x Nc` matrix
* vector conversion
* write `diag(vector)` and `diag(matrix)` functions

