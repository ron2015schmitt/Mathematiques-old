
# Vector math in mātricks
This document was automatically generated from file **`vmath.cpp`** (mātricks-v2.1-r32).

### Element-wise arithmetic
The operators +,-,*,/ perform element wise addition, subtraction, multiplication, and division respectively


**EXAMPLE 1**: Element-wise `Vector` math
```C++
Vector<double> v1(4);
v1 = {10,20,30,40};
Vector<double> v2(4);
v2 = {1,2,3,4};
```

**The result is**
```C++
  v1 + v2:  {11,22,33,44}; 
  v1 - v2:  {9,18,27,36}; 
  v1 * v2:  {10,40,90,160}; 
  v1 / v2:  {10,10,10,10}; 
```

