
# Vector functions that return a scalar (dot product, sum, min, max etc) in mātricks
_This document was automatically generated from file_ **`vscalarout.cpp`** (mātricks-v2.1-r64).

### dot product—the `|` operator
* The dot product is accomplished via the `|` operator, such that the dot product takes a form similar to P.A.M. Dirac's 'bra-ket' notation.
* This definition becomes very useful for taking the product of matrices because any number of matrices can be multiplied in a single line of code.


**EXAMPLE 1**: Dot product of two vectors `(v1|v2)`
```C++
Vector<double> v1({1,2,3,4}); // C++11 list initialization
Vector<double> v2({1,-1,1,-1}); // C++11 list initialization
```

**Some expressions with results**
```C++
  (v1|v1):  30; 
  (v2|v2):  4; 
  (v1|v2):  -2; 
  (v2|v1):  -2; 
  (v1|(2*v2+1)):  6; 
```



**EXAMPLE 2**: `sum` the elements of a vector
```C++
Vector<double> v({1,2,3,4}); // C++11 list initialization
```

**Some expressions with results**
```C++
  sum(v):  10; 
  sum(2*exp(v)+1):  173.582; 
```



**EXAMPLE 3**: Compute the _product_ of the elements of a vector
```C++
Vector<double> v({1,2,3,4}); // C++11 list initialization
```

**Some expressions with results**
```C++
  prod(v):  24; 
  prod(2*exp(v)+1):  460753; 
```



**EXAMPLE 4**: Find the _minimum_ of the elements of a vector
```C++
Vector<double> v({1,20,-1,0}); // C++11 list initialization
```

**Some expressions with results**
```C++
  v:  {1,20,-1,0}; 
  min(v):  -1; 
  2*exp(v)+1:  {6.43656,9.7033e+08,1.73576,3}; 
  min(2*exp(v)+1):  1.73576; 
```



**EXAMPLE 5**: Find the _maximum_ of the elements of a vector
```C++
Vector<double> v({1,20,-1,0}); // C++11 list initialization
```

**Some expressions with results**
```C++
  v:  {1,20,-1,0}; 
  max(v):  20; 
  2*exp(v)+1:  {6.43656,9.7033e+08,1.73576,3}; 
  max(2*exp(v)+1):  9.7033e+08; 
```


[Table of Contents](README.md)
