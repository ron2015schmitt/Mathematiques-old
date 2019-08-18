
# Applying User-defined functions in mātricks
_This document was automatically generated from file_ **`vapply.cpp`** (mātricks-v2.1-r85).

### Applying User-defined functions
Since 
```C++
struct X {static double increment (double x) {return ++x;}};
Vector<double> v1({1,2,3,4} );
Vector<double> v2;
v2 = v1.getValArray().apply(X::increment);
```
**The result is**
```C++
  v1:  {1,2,3,4}; 
  v2:  {2,3,4,5}; 
```



[Table of Contents](README.md)
