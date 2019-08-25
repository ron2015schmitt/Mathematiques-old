
# Vector relational operators (`==`,`<`,`>`, etc), logical operators and masks in mātricks
_This document was automatically generated from file_ **`vrelational.cpp`** (mātricks-v2.9).

## Relational operators
### Relational operators between two Vectors

Vector relations operate element-wise, similar to arithmetic operators. Given two Vectors of the same size, a vector relational expression (eg `(v1>v2)` returns a vector of booleans of the same size


**EXAMPLE 1**: relational operators between two vectors`
```C++
Vector<double> v1( range<double>(1,3) );
Vector<double> v2( range<double>(3,1) );
```

**Some expressions with results**
```C++
  v1:  {1,2,3}; 
  v2:  {3,2,1}; 
  v1 > v2:  {0,0,1}; 
  v1 >= v2:  {0,1,1}; 
  v1 < v2:  {1,0,0}; 
  v1 <= v2:  {1,1,0}; 
  v1 == v2:  {0,1,0}; 
  v1 != v2:  {1,0,1}; 
```

### Relational operators between a Vector and scalar


**EXAMPLE 2**: relational operators between a vector and a scalar`
```C++
Vector<double> v( range<double>(1,3) );
```

**Some expressions with results**
```C++
  v:  {1,2,3}; 
  v > 2:  {0,0,1}; 
  v >= 2:  {0,1,1}; 
  v < 2:  {1,0,0}; 
  v <= 2:  {1,1,0}; 
  v == 2:  {0,1,0}; 
  v != 2:  {1,0,1}; 
```

## Logical operators
### The element-wise logical operatora `&&`,`||`,`!`


**EXAMPLE 3**: The element-wise logical operators
```C++
Vector<double> v( range<double>(1,5) );
```

**Some expressions with results**
```C++
  v:  {1,2,3,4,5}; 
  (v > 2):  {0,0,1,1,1}; 
  !(v > 2):  {1,1,0,0,0}; 
  (v >= 2) && (v <= 4 ):  {0,1,1,1,0}; 
  (v <= 2) || (v >= 4 ):  {1,1,0,1,1}; 
```

### The functions `alltrue` and `numtrue`


**EXAMPLE 4**: The functions `alltrue` and `numtrue`
```C++
Vector<double> v( range<double>(1,3) );
```

**Some expressions with results**
```C++
  v:  {1,2,3}; 
  (v > 2):  {0,0,1}; 
  alltrue(v > 2):  0; 
  numtrue(v > 2):  1; 
  numtrue(!(v > 2)):  2; 
  alltrue(v == v):  1; 
```

## Vector mask access
* A subset of a vector can be extracted using a boolean-valued vector of the same size.
* For example `v[v>0]` will return a vector containing only the positive values of v.
* Vector mask access can be used on the left hand side of assigment, allowing you to set values via masks.


**EXAMPLE 5**: Using vector masks
```C++
Vector<double> v( range<double>(-10,10) );
```

**Some expressions with results**
```C++
  v:  {-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10}; 
  v > 6:  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1}; 
  v[(v > 6)]:  {7,8,9,10}; 
```


Now set all elements that are larger than 6 to 6 (clipping)
```C++
v[(v > 6)] = 6.;
```
**The result is**
```C++
  v:  {-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,6,6,6,6}; 
```


Now set all negative elements to zero
```C++
v[(v < 0)] = 0.;
```
**The result is**
```C++
  v:  {0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,6,6,6,6}; 
```


_Note that_ `expression[mask]` _access is not yet implemented_

[Table of Contents](README.md)
