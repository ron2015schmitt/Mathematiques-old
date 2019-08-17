
# Vector assigment in mātricks
This document was automatically generated from file **`vassignment.cpp`** (mātricks-v2.1-r50).

* Vector assignment is performed by copying the elements of the object on the right-hand side to the left-hand side.
* When the right-hand side is an expression, there are _no_ intermediate objects created.
**EXAMPLE 1**: Assign all elements to a single value.
```C++
Vector<double> v1(10);
v1 = 78.9;
```
**The result is**
```C++
  v1:  {78.9,78.9,78.9,78.9,78.9,78.9,78.9,78.9,78.9,78.9}; 
```

**EXAMPLE 2**: Assign from a C Array.
```C++
Vector<double> v1(4);
v1 = {1,2,3,4};
Vector<double> v2(4);
v1 = {1,2,3,4};
```
**The result is**
```C++
  v1:  {1,2,3,4}; 
```

**EXAMPLE 3**: Assign from a C++11 list.
```C++
Vector<double> v1(4);
v1 = {1,2,3,4};
```
**The result is**
```C++
  v1:  {1,2,3,4}; 
```


[Table of Contents](README.md)
