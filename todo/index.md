# Index class and new indexing methodology

_Back to [Table of Contents](README.md)_

Refer to file `sandbox/indexing.cpp` for prototyping.

* replace `size_type` everywhere with `index_type`
* `IndexUnion` has member for each type / pointer to each type
* `Index` class has constructors for
   * `index_type`
   * `sindex_type`  (signed index)
   * `start, stop`  (unsigned and signed)
   * `start, stop, step` (unsigned and signed)
   * `initializer_list`
   * `Vector<index_type>` (subset)
   * `Vector<bool>`  (mask)
* implement `<<` and informative display of `Index` class
* harmonize negative index definition with that of Python
* Index access for each tensor class
   * `Vector(Index ind)`
   * `Vector(Index ind)`
   * `Matrix(Index ind1, Index ind2)`
   * `Tensor(Index... ind1)`
* Define both direct index (for speed) access for each tensor class
   * `Vector[index_type i]` and `Vector[Index ind]`
   * `Vector.dat(index_type i)` and `Vector.dat(Index ind)`
* define `even`, `odd` slices in their own namespace

