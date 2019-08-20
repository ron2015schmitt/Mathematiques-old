
# Vector assigment in mātricks
_This document was automatically generated from file_ **`vassignment.cpp`** (mātricks-v2.7-r10).

* Vector assignment is performed by copying the elements of the object on the right-hand side to the left-hand side.
* When the right-hand side is an expression, there are _no_ intermediate objects created.
**EXAMPLE 1**: Assign all elements to a single value.
```C++
Vector<double> v(10);
v = 78.9;
```
**The result is**
```C++
  v:  ; 
```


**EXAMPLE 2**: Assign from a C Array.

_In DEBUG mode, this generates a warning since it is a dangerous practice. Use a C++11 list instead._
```C++
Vector<double> v(4);
v = (const double[]) {1,2,3,4};
**matricks warning: vector assignment to a C array always carries the risk of out of bounds access. Use C++11 list assignment instead.
                 Vector2 = D[]
          where  Vector2 is Vector<double>[size=4], ID=2
```
**The result is**
```C++
  v:  ; 
```

**EXAMPLE 3**: Assign from a C++11 list.
```C++
Vector<double> v(4);
v = {1,2,3,4};
```
**The result is**
```C++
  v:  ; 
```

**EXAMPLE 4**: Assign from another `Vector`.

Note that values are copied from `v2` to `v1`
```C++
Vector<double> v1({1,2,3,4}); // C++11 list
Vector<double> v2({0,0,0,0}); // C++11 list
v2 = v1;
v1[0] = 100;
v2[0] = 200;
```
**The result is**
```C++
  v1:  ; 
  v2:  ; 
```

**EXAMPLE 5**: Assign from a `Vector` expression.
```C++
Vector<double> v1({1,2,3,4}); // C++11 list
Vector<double> v2({0,0,0,0}); // C++11 list
v2 = 2*v1;
```
**The result is**
```C++
  v1:  ; 
  v2:  ; 
```

**EXAMPLE 6**: Assign from `std` containers.
```C++
std::vector<double> vstd({1,2,3,4}); // C++11 list
Vector<double> v1(4);
v1 = vstd;
std::array<double, 3> varray = {10,20,30}; // C++11 list
Vector<double> v2(3);
v2 = varray;
std::valarray<double> myvalarray = {100,200}; // C++11 list
Vector<double> v3(2);
v3 = myvalarray;
std::list<double> mylist = {-1,-2};; // C++11 list
Vector<double> v4(2);
v4 = mylist;
```
**The result is**
```C++
  v1:  ; 
  v2:  ; 
  v3:  ; 
  v4:  ; 
```


[Table of Contents](README.md)
