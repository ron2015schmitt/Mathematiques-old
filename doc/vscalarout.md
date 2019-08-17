
# Vector functions that return a scalar (dot product, sum, min, max etc) in mātricks
_This document was automatically generated from file_ **`vscalarout.cpp`** (mātricks-v2.1-r63).

### dot product
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


[Table of Contents](README.md)
