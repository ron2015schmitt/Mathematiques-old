
# Vector `join` and `rep` functions in mātricks
_This document was automatically generated from file_ **`vconcatrep.cpp`** (mātricks-v2.7-r7).

### Vector `join` function
* The Vector `join` function joins two vectors
* The comma operator `,` performs the same function.
* This is an expression.  It does not create intermeidate objects.
* join can be used on the left hand side as well!


**EXAMPLE 1**: Vector `join` function
```C++
Vector<double> v1( range<double>(0,3) );
Vector<double> v2( range<double>(2,0) );
Vector<double> v3;
v3 = join(v1,v2);
Vector<double> v4;
v4 = (v1,v2);
Vector<double> va(2);
Vector<double> vb(5);
(va,vb) = v4;
```

**The result is**
```C++
  v1:  {0,1,2,3}; 
  v2:  {2,1,0}; 
  v3:  {0,1,2,3,2,1,0}; 
  v4:  {0,1,2,3,2,1,0}; 
  va:  {0,1}; 
  vb:  {2,3,2,1,0}; 
```

### Vector `rep` function
* The Vector `rep(v,m)` function replicates the input vector `m` times.
* `rep` cannot be used on the left hand side of assignment, since it doesn't provide utility to do so.


**EXAMPLE 2**: Vector `rep` function
```C++
Vector<double> v1( range<double>(1,3) );
Vector<double> v2( range<double>(-1,-2) );
Vector<double> v3;
v3 = rep(v1,3);
Vector<double> v4;
v4 = (rep(v1,2), rep(v2,3));
```

**The result is**
```C++
  v1:  {1,2,3}; 
  v2:  {-1,-2}; 
  v3:  {1,2,3,1,2,3,1,2,3}; 
  v4:  {1,2,3,1,2,3,-1,-2,-1,-2,-1,-2}; 
```


_Note that_ `join(expression,expression)` _is not yet implemented_.

_Note that_ `rep(expression, m)` _is not yet implemented_.

[Table of Contents](README.md)
