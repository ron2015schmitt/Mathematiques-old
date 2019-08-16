
# Vector math in mātricks
This document was automatically generated from file **`vmath.cpp`** (mātricks-v2.1-r32).

### Element-wise arithmetic
The operators +,-,*,/ perform element wise addition, subtraction, multiplication, and division respectively


**EXAMPLE 1**: Element-wise `Vector` math (using C++11 assignment)
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

### Vector-scalar arithmetic
* The binary operators +,-,*,/ can each be used with a scalar and a `Vector`.
* In this case the scalar is operated on each element of the vector


**EXAMPLE 2**: math with scalars and `Vector`s  (using C++11 assignment)
```C++
Vector<double> v1(4);
v1 = {10,20,30,40};
```

**The result is**
```C++
  v1 + 1:  {11,21,31,41}; 
  1 + v1:  {11,21,31,41}; 
  v1 - 10:  {0,10,20,30}; 
  40 - v1:  {30,20,10,0}; 
  v1 * 2:  {20,40,60,80}; 
  2 * v1:  {20,40,60,80}; 
  v1 / 10:  {1,2,3,4}; 
  40 / v1:  {4,2,1.33333,1}; 
  1+ 40 / v1 - 8/8 + 5*v1*2:  {104,202,301.333,401}; 
```


[Table of Contents](README.md)
