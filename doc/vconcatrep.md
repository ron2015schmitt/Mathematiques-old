
# Vector join operator `(v1,v2)` and `rep` function in mātricks
_This document was automatically generated from file_ **`vconcatrep.cpp`** (mātricks-v2.16-r20).

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
  v1 = {double, double, double}; 
  v2 = {double, double}; 
  (v1,v2) = {double, double, double, double, double}; 
  (v1,v2,v1) = {double, double, double, double, double, double, double, double}; 
  (v1,v2,v1,v2) = {double, double, double, double, double, double, double, double, double, double}; 
  (10*v1,v2) = {double, double, double, double, double}; 
  (v1,10*v2) = {double, double, double, double, double}; 
  (10*v1,10*v2) = {double, double, double, double, double}; 
```


The following are examples usign the join operator on the left hand side

```C++
Vector<double> va(2);
Vector<double> vb(3);
(va,vb) = range<double>(1,5);
```

**The result is**
```C++
  va = {double, double}; 
  vb = {double, double, double}; 
```

```C++
Vector<double> ua(2);
Vector<double> ub(3);
(ua[{1,0}],ub) = range<double>(1,5);
```

**The result is**
```C++
  ua = {double, double}; 
  ub = {double, double, double}; 
```

```C++
Vector<double> wa(2);
Vector<double> wb(3);
(wa,wb[{2,1,0}]) = range<double>(1,5);
```

**The result is**
```C++
  wa = {double, double}; 
  wb = {double, double, double}; 
```

```C++
Vector<double> za(2);
Vector<double> zb(3);
(za[{1,0}],zb[{2,1,0}]) = range<double>(1,5);
```

**The result is**
```C++
  za = {double, double}; 
  zb = {double, double, double}; 
```

### Vector `rep` function
* The Vector `rep(v,m)` function replicates the input vector `m` times.
* `rep` cannot be used on the left hand side of assignment, since it doesn't provide utility to do so.
* The Vector `rep(v,m)` function can be combined with the join operator.


**EXAMPLE 2**: Vector `rep` function
```C++
Vector<double> v1( range<double>(1,3) );
Vector<double> v2( range<double>(4,5) );
Vector<double> v3;
v3 = rep(v1,3);
Vector<double> v4;
v4 = (rep(v1,2), rep(v2,3));
Vector<double> v5;
v5 = rep((v1,v2),2);
```

**The result is**
```C++
  v1 = {double, double, double}; 
  v2 = {double, double}; 
  v3 = {double, double, double, double, double, double, double, double, double}; 
  v4 = {double, double, double, double, double, double, double, double, double, double, double, double}; 
  v5 = {double, double, double, double, double, double, double, double, double, double}; 
```




[Table of Contents](README.md)
