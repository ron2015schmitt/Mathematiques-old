
[Table of Contents](README.md)


# Access subsets of Vector elements in mātricks
_This document was automatically generated from file_ **`vsubsets.cpp`** (mātricks-v2.29).

You can ccess avector elements using a `Vector` of indices or a C++11 `initializer_list` of indices
## Access vector elements using a `Vector` of indices
### Element access `Vector[Vector]`

* The index Vector _can be smaller than or greater than or equal to_ the length to the data Vector!
* The index Vector _can have repeated indices and indices can be in any order_!


**EXAMPLE 1**: Access via a Vector of indices
```C++
Vector<double> v( linspace<double>(0,1,11) );
operator[0] #1
operator[1] #1
operator[2] #1
operator[3] #1
operator[4] #1
operator[5] #1
operator[6] #1
operator[7] #1
operator[8] #1
operator[9] #1
operator[10] #1
operator[10] #2
operator[9] #2
operator[8] #2
operator[7] #2
operator[6] #2
operator[5] #2
operator[4] #2
operator[3] #2
operator[2] #2
operator[1] #2
operator[0] #2
Vector<index_type> veven( range<index_type>(0,10,2) );
operator[0] #1
operator[0] #1
operator[1] #1
operator[1] #1
operator[2] #1
operator[2] #1
operator[3] #1
operator[3] #1
operator[4] #1
operator[4] #1
operator[5] #1
operator[5] #2
operator[4] #2
operator[3] #2
operator[2] #2
operator[1] #2
operator[0] #2
Vector<index_type> vodd( range<index_type>(1,10,2) );
operator[0] #1
operator[0] #1
operator[1] #1
operator[1] #1
operator[2] #1
operator[2] #1
operator[3] #1
operator[3] #1
operator[4] #1
operator[4] #2
operator[3] #2
operator[2] #2
operator[1] #2
operator[0] #2
Vector<index_type> vconst(15,1 );
```

**The result is**
```C++
  v = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1}; 
  veven = {0, 2, 4, 6, 8, 10}; 
  v[veven] = operator[0] #2
operator[0] #1
operator[1] #2
operator[2] #1
operator[2] #2
operator[4] #1
operator[3] #2
operator[6] #1
operator[4] #2
operator[8] #1
operator[5] #2
operator[10] #1
Vector<double> {0, 0.2, 0.4, 0.6, 0.8, 1}; 
  operator[1] #1
operator[2] #1
v[veven[1]] = 0.2; 
  vodd = {1, 3, 5, 7, 9}; 
  v[vodd] = operator[0] #2
operator[1] #1
operator[1] #2
operator[3] #1
operator[2] #2
operator[5] #1
operator[3] #2
operator[7] #1
operator[4] #2
operator[9] #1
Vector<double> {0.1, 0.3, 0.5, 0.7, 0.9}; 
  operator[1] #1
operator[3] #1
v[vodd[1]] = 0.3; 
  operator[0] #1
operator[1] #1
operator[2] #1
operator[3] #1
operator[4] #1
operator[5] #1
operator[0] #1
operator[1] #1
operator[2] #1
operator[3] #1
operator[4] #1
v[veven,vodd] = operator[0] #2
operator[0] #1
operator[1] #2
operator[2] #1
operator[2] #2
operator[4] #1
operator[3] #2
operator[6] #1
operator[4] #2
operator[8] #1
operator[5] #2
operator[10] #1
operator[6] #2
operator[1] #1
operator[7] #2
operator[3] #1
operator[8] #2
operator[5] #1
operator[9] #2
operator[7] #1
operator[10] #2
operator[9] #1
Vector<double> {0, 0.2, 0.4, 0.6, 0.8, 1, 0.1, 0.3, 0.5, 0.7, 0.9}; 
  operator[1] #1
operator[2] #1
operator[5] #1
v[vodd[veven[1]]] = 0.5; 
  vconst = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  v[vconst] = operator[0] #2
operator[1] #1
operator[1] #2
operator[1] #1
operator[2] #2
operator[1] #1
operator[3] #2
operator[1] #1
operator[4] #2
operator[1] #1
operator[5] #2
operator[1] #1
operator[6] #2
operator[1] #1
operator[7] #2
operator[1] #1
operator[8] #2
operator[1] #1
operator[9] #2
operator[1] #1
operator[10] #2
operator[1] #1
operator[11] #2
operator[1] #1
operator[12] #2
operator[1] #1
operator[13] #2
operator[1] #1
operator[14] #2
operator[1] #1
Vector<double> {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1}; 
```

## Access vector elements using an C++11 `initializer_list` of indices
### Element access `Vector[initializer_list]`

* The list can be smaller than or greater than or equal to the length to the data Vector.
* The list can have repeated indices and indices can be in any order!


**EXAMPLE 2**: Access via a C++11 initializer_list
```C++
Vector<double> v( linspace<double>(0,1,11) );
operator[0] #1
operator[1] #1
operator[2] #1
operator[3] #1
operator[4] #1
operator[5] #1
operator[6] #1
operator[7] #1
operator[8] #1
operator[9] #1
operator[10] #1
operator[10] #2
operator[9] #2
operator[8] #2
operator[7] #2
operator[6] #2
operator[5] #2
operator[4] #2
operator[3] #2
operator[2] #2
operator[1] #2
operator[0] #2
v = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1}; 
```

**The result is**
```C++
  v[{0,4}] = operator[0] #2
operator[0] #1
operator[1] #2
operator[4] #1
Vector<double> {0, 0.4}; 
  v[{4,0,1,4}] = operator[0] #2
operator[4] #1
operator[1] #2
operator[0] #1
operator[2] #2
operator[1] #1
operator[3] #2
operator[4] #1
Vector<double> {0.4, 0, 0.1, 0.4}; 
  v[{1,0,2}] = operator[0] #2
operator[1] #1
operator[1] #2
operator[0] #1
operator[2] #2
operator[2] #1
Vector<double> {0.1, 0, 0.2}; 
  v[{4,3,2,1,0}] = operator[0] #2
operator[4] #1
operator[1] #2
operator[3] #1
operator[2] #2
operator[2] #1
operator[3] #2
operator[1] #1
operator[4] #2
operator[0] #1
Vector<double> {0.4, 0.3, 0.2, 0.1, 0}; 
  v[{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}] = operator[0] #2
operator[2] #1
operator[1] #2
operator[2] #1
operator[2] #2
operator[2] #1
operator[3] #2
operator[2] #1
operator[4] #2
operator[2] #1
operator[5] #2
operator[2] #1
operator[6] #2
operator[2] #1
operator[7] #2
operator[2] #1
operator[8] #2
operator[2] #1
operator[9] #2
operator[2] #1
operator[10] #2
operator[2] #1
operator[11] #2
operator[2] #1
operator[12] #2
operator[2] #1
operator[13] #2
operator[2] #1
operator[14] #2
operator[2] #1
operator[15] #2
operator[2] #1
operator[16] #2
operator[2] #1
operator[17] #2
operator[2] #1
operator[18] #2
operator[2] #1
operator[19] #2
operator[2] #1
operator[20] #2
operator[2] #1
operator[21] #2
operator[2] #1
operator[22] #2
operator[2] #1
operator[23] #2
operator[2] #1
operator[24] #2
operator[2] #1
operator[25] #2
operator[2] #1
operator[26] #2
operator[2] #1
operator[27] #2
operator[2] #1
operator[28] #2
operator[2] #1
operator[29] #2
operator[2] #1
operator[30] #2
operator[2] #1
operator[31] #2
operator[2] #1
operator[32] #2
operator[2] #1
Vector<double> {0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2}; 
```


[Table of Contents](README.md)
