
# Access subsets of Vector elements in mātricks
_This document was automatically generated from file_ **`vsubsets.cpp`** (mātricks-v2.16-r20).

You can ccess avector elements using a `Vector` of indices or a C++11 `initializer_list` of indices
## Access vector elements using a `Vector` of indices
### Element access `Vector[Vector]`

* The index Vector _can be smaller than or greater than or equal to_ the length to the data Vector!
* The index Vector _can have repeated indices and indices can be in any order_!


**EXAMPLE 1**: Access via a Vector of indices
```C++
Vector<double> v( linspace<double>(0,1,11) );
Vector<index_type> veven( range<index_type>(0,10,2) );
Vector<index_type> vodd( range<index_type>(1,10,2) );
Vector<index_type> vconst(15,1 );
```

**The result is**
```C++
  v = {double, double, double, double, double, double, double, double, double, double, double}; 
  veven = {0, 2, 4, 6, 8, 10}; 
  v[veven] = {double, double, double, double, double, double}; 
  v[veven[1]] = double; 
  vodd = {1, 3, 5, 7, 9}; 
  v[vodd] = {double, double, double, double, double}; 
  v[vodd[1]] = double; 
  v[veven,vodd] = {double, double, double, double, double, double, double, double, double, double, double}; 
  v[vodd[veven[1]]] = double; 
  vconst = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  v[vconst] = {double, double, double, double, double, double, double, double, double, double, double, double, double, double, double}; 
```

## Access vector elements using an C++11 `initializer_list` of indices
### Element access `Vector[initializer_list]`

* The list can be smaller than or greater than or equal to the length to the data Vector.
* The list can have repeated indices and indices can be in any order!


**EXAMPLE 2**: Access via a C++11 initializer_list
```C++
Vector<double> v( linspace<double>(0,1,11) );
v = {double, double, double, double, double, double, double, double, double, double, double}; 
```

**The result is**
```C++
  v[{0,4}] = {double, double}; 
  v[{4,0,1,4}] = {double, double, double, double}; 
  v[{1,0,2}] = {double, double, double}; 
  v[{4,3,2,1,0}] = {double, double, double, double, double}; 
  v[{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}] = {double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double}; 
```


[Table of Contents](README.md)
