function Any::Any(const MyType& var): MyType = double, var = 3.4
function Any::Any(const MyType& var): MyType = int, var = 1
function Any::Any(const MyType& var): MyType = Vector<double> , var = {0,0,0,0,0}
function Any::Any(const MyType& var): MyType = Vector<Vector<double> > , var = {}

# Vector `join` and `rep` functions in mātricks
_This document was automatically generated from file_ **`vconcatrep.cpp`** (mātricks-v2.8-r2).

### Vector `join` function
* The Vector `join` function joins two vectors
* The comma operator `,` performs the same function.
* This is an expression.  It does not create intermeidate objects.
* join can be used on the left hand side as well!


**EXAMPLE 1**: Vector `join` function
```C++
Vector<double> v1( range<double>(0,2) );
Vector<double> v2( range<double>(3,4) );
```

**The result is**
```C++
  v1:  {0,1,2}; 
  v2:  {3,4}; 
    VJoinObj operator,(Vector<D>& a, Vector<D>& b)
(v1,v2):  {0,1,2,3,4}; 
    VJoinObj operator,(Vector<D>& a, Vector<D>& b)
  VJoinExpr operator,(const Vexpr<D,A>& a, const Vector<D>& b)
(v1,v2,v1):  {0,1,2,3,4,0,1,2}; 
    VJoinObj operator,(Vector<D>& a, Vector<D>& b)
  VJoinExpr operator,(const Vexpr<D,A>& a, const Vector<D>& b)
  VJoinExpr operator,(const Vexpr<D,A>& a, const Vector<D>& b)
(v1,v2,v1,v2):  {0,1,2,3,4,0,1,2,3,4}; 
    VJoinExpr operator,(const Vexpr<D,A>& a, const Vector<D>& b)
(10*v1,v2):  {0,10,20,3,4}; 
    VJoinExpr operator,(const Vector<D>& a, const Vexpr<D,B>& b)
(v1,10*v2):  {0,1,2,30,40}; 
  (10*v1,10*v2):  {30,40}; 
```

```C++
Vector<double> v3;
v3 = (v1,v2,v1,v2);
  VJoinObj operator,(Vector<D>& a, Vector<D>& b)
  VJoinExpr operator,(const Vexpr<D,A>& a, const Vector<D>& b)
  VJoinExpr operator,(const Vexpr<D,A>& a, const Vector<D>& b)
Vector<double> v4a;
v4a = (v1,v2);
  VJoinObj operator,(Vector<D>& a, Vector<D>& b)
Vector<double> v4b;
v4b = (v1,10*v2);
  VJoinExpr operator,(const Vector<D>& a, const Vexpr<D,B>& b)
Vector<double> v4c;
v4c = (10*v1,v2);
  VJoinExpr operator,(const Vexpr<D,A>& a, const Vector<D>& b)
Vector<double> v4d;
v4d = (10*v1,10*v2);
Vector<double> v5( range<double>(0,6) );
Vector<double> va(2);
Vector<double> vb(5);
(va,vb) = v5;
  VJoinObj operator,(Vector<D>& a, Vector<D>& b)
VJoinObj<D,A,B>& operator=(const VorE<D,C>& rhs)
Vector<double> vc(2);
Vector<double> vd(5);
vc[{1,0}] = va;
  VSubsetObj(Vector<D>& a, const std::initializer_list<index_type>& list)
Vector<double> ve(2);
Vector<double> vf(5);
```

**The result is**
```C++
  v1:  {0,1,2}; 
  v2:  {3,4}; 
  v3:  {0,1,2,3,4,0,1,2,3,4}; 
  v4a:  {0,1,2,3,4}; 
  v4b:  {0,1,2,30,40}; 
  v4c:  {0,10,20,3,4}; 
  v4d:  {30,40}; 
  v5:  {0,1,2,3,4,5,6}; 
  va:  {0,1}; 
  vb:  {2,3,4,5,6}; 
  vc:  {1,0}; 
  vd:  {0,0,0,0,0}; 
  ve:  {0,0}; 
  vf:  {0,0,0,0,0}; 
    VJoinObj operator,(Vector<D>& a, Vector<D>& b)
  VJoinExpr operator,(const Vexpr<D,A>& a, const Vector<D>& b)
(v1,v1,v1):  {0,1,2,0,1,2,0,1,2}; 
    VJoinObj operator,(Vector<D>& a, Vector<D>& b)
(v1,v2,4*v1):  {0,4,8}; 
    VJoinExpr operator,(const Vexpr<D,A>& a, const Vector<D>& b)
(5*v1,v2):  {0,5,10,3,4}; 
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
rep for loop
  j=0, Na=3
  j=1, Na=3
  j=2, Na=3
Vector<double> v4;
v4 = (rep(v1,2), rep(v2,3));
rep for loop
  j=0, Na=2
  j=1, Na=2
  j=2, Na=2
rep for loop
  j=0, Na=3
  j=1, Na=3
  VJoinObj operator,(Vector<D>& a, Vector<D>& b)
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
