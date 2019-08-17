
# Vector declaration in mātricks
_This document was automatically generated from file_ **`vdeclaration.cpp`** (mātricks-v2.1-r60).

**EXAMPLE 1**: Declare vector `v1`.
```C++
const size_type N = 4;
Vector<double> v1(N);
```
**The result is**
```C++
  v1:  {0,0,0,0}; 
```

**EXAMPLE 2**: Declare `v2` and initialize to a constant
```C++
Vector<double> v2(4, -1 );
```
**The result is**
```C++
  v2:  {-1,-1,-1,-1}; 
```

**EXAMPLE 3**: Declare `v3` and initialize to a **C-style array** of values
```C++
Vector<double> v3( 4, (const double[]) {10, 20, 30, 40} );
**Matricks warning: vector assignment to a C array always carries the risk of out of bounds access. Use C++11 list assignment instead.
                 Vector3 = D[]
          where  Vector3 is Vector<double>[size=4], ID=3
```
**The result is**
```C++
  v3:  {10,20,30,40}; 
```

**EXAMPLE 4**: Declare `v4` and initialize directly (**__C++11__**)
```C++
Vector<double> v4({10, 20, 30, 40});
```
**The result is**
```C++
  v4:  {10,20,30,40}; 
```

**EXAMPLE 5**: Declare `v5` and initialize to values of `v3`
```C++
Vector<double> v5(v3);
```
**The result is**
```C++
  v5:  {10,20,30,40}; 
```

**EXAMPLE 6**: Declare `v6` and initialize to an expression
```C++
Vector<double> v6(2*v3+1);
```
**The result is**
```C++
  v6:  {21,41,61,81}; 
```


[Table of Contents](README.md)
