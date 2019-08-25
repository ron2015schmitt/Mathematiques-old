
# Vector join operator and `rep` functions in mātricks
_This document was automatically generated from file_ **`vconcatrep.cpp`** (mātricks-v2.10).

### Vector join operator `,` 
* The Vector operator `,` joins two vectors
* This is an expression.  It does not create intermediate objects.
* join can be used on the left hand side as well!


**EXAMPLE 1**: Vector join operator `,`
```C++
Vector<double> v1( range<double>(0,2) );
Vector<double> v2( range<double>(3,4) );
```

**The result is**
```C++
  v1:  {0,1,2}; 
  v2:  {3,4}; 
  (v1,v2):  {0,1,2,3,4}; 
  (v1,v2,v1):  {0,1,2,3,4,0,1,2}; 
  (v1,v2,v1,v2):  {0,1,2,3,4,0,1,2,3,4}; 
  (10*v1,v2):  {0,10,20,3,4}; 
  (v1,10*v2):  {0,1,2,30,40}; 
  (10*v1,10*v2):  {0,10,20,30,40}; 
```


The following are examples usign the join operator on the left hand side

```C++
Vector<double> va(2);
Vector<double> vb(3);
(va,vb) = range<double>(1,5);
```

**The result is**
```C++
  va:  {1,2}; 
  vb:  {3,4,5}; 
```

```C++
Vector<double> ua(2);
Vector<double> ub(3);
(ua[{1,0}],ub) = range<double>(1,5);
```

**The result is**
```C++
  ua:  {2,1}; 
  ub:  {3,4,5}; 
```

```C++
Vector<double> wa(2);
Vector<double> wb(3);
(wa,wb[{2,1,0}]) = range<double>(1,5);
```

**The result is**
```C++
  wa:  {1,2}; 
  wb:  {5,4,3}; 
```

```C++
Vector<double> za(2);
Vector<double> zb(3);
(za[{1,0}],zb[{2,1,0}]) = range<double>(1,5);
```

**The result is**
```C++
  za:  {2,1}; 
  zb:  {5,4,3}; 
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




[Table of Contents](README.md)