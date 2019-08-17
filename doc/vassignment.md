
# Vector assigment in mātricks
_This document was automatically generated from file_ **`vassignment.cpp`** (mātricks-v2.1-r54).

* Vector assignment is performed by copying the elements of the object on the right-hand side to the left-hand side.
* When the right-hand side is an expression, there are _no_ intermediate objects created.
**EXAMPLE 1**: Assign all elements to a single value.
```C++
Vector<double> v(10);
v = 78.9;
```
**The result is**
```C++
  v:  {78.9,78.9,78.9,78.9,78.9,78.9,78.9,78.9,78.9,78.9}; 
```

**EXAMPLE 2**: Assign from a C Array.
_In DEBUG mode, this generates a warning since it is a dangerous practice. Use a C++11 list instead._
```C++
Vector<double> v(4);
v = (const double[]) {1,2,3,4};
**Matricks warning: vector assignment to a C array always carries the risk of out of bounds access. Use C++11 list assignment instead.
                 Vector2= D array[]
          where  Vector2 is Vector<double>[size=4], ID=2
```
**The result is**
```C++
  v:  {0,0,0,0}; 
```

**EXAMPLE 3**: Assign from a C++11 list.
```C++
Vector<double> v(4);
v = {1,2,3,4};
```
**The result is**
```C++
  v:  {1,2,3,4}; 
```

**EXAMPLE 4**: Assign from another `Vector`.
Note that values are copied from `v2` to `v1`
```C++
Vector<double> v1({1,2,3,4});
Vector<double> v2({0,0,0,0});
v2 = v1;
v1[0] = 100;;
v2[0] = 200;;
```
**The result is**
```C++
  v1:  {100,2,3,4}; 
```

**The result is**
```C++
  v2:  {200,2,3,4}; 
```

**EXAMPLE 5**: Assign from a `Vector` expression.
```C++
Vector<double> v1({1,2,3,4});
Vector<double> v2({0,0,0,0});
v2 = 2*v1;
```
**The result is**
```C++
  v1:  {1,2,3,4}; 
```

**The result is**
```C++
  v2:  {2,4,6,8}; 
```


[Table of Contents](README.md)
