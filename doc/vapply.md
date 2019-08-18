
# Applying User-defined functions in mātricks
_This document was automatically generated from file_ **`vapply.cpp`** (mātricks-v2.1-r84).

### Applying User-defined functions
Since 
```C++
struct X {static int increment (int x) {return ++x;}};
Vector<int> v1(4, (const int[]) {1,2,3,4} );
**Matricks warning: vector assignment to a C array always carries the risk of out of bounds access. Use C++11 list assignment instead.
                 Vector1 = D[]
          where  Vector1 is Vector<int>[size=4], ID=1
Vector<int> v2;
v2 = v1.getValArray().apply(X::increment);
**Some expressions with results**: user-defned function
```C++
  v1:  {1,2,3,4}; 
  v2:  {2,3,4,5}; 
```



[Table of Contents](README.md)
