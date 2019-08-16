
# Vector math in mātricks
This document was automatically generated from file **`vmath.cpp`** (mātricks-v2.1-r36).

### Element-wise arithmetic
The operators +,-,*,/ perform element wise addition, subtraction, multiplication, and division respectively


**EXAMPLE 1**: Element-wise `Vector` math
```C++
Vector<double> v1(4);
v1 = {10,20,30,40}; // C++11 list
Vector<double> v2(4);
v2 = {1,2,3,4}; // C++11 list
```

**Some expressions with results**
```C++
  v1 + v2:  {11,22,33,44}; 
  v1 - v2:  {9,18,27,36}; 
  v1 * v2:  {10,40,90,160}; 
  v1 / v2:  {10,10,10,10}; 
```

### Vector-scalar arithmetic
* The binary operators +,-,*,/ can each be used to pair a scalar and a `Vector`.
* In this case the scalar is operated on each element of the vector


**EXAMPLE 2**: math with scalars and `Vector`s
```C++
Vector<double> v1(4);
v1 = {10,20,30,40}; // C++11 list
```

**Some expressions with results**
```C++
  v1 + 1:  {11,21,31,41}; 
  1 + v1:  {11,21,31,41}; 
  v1 - 10:  {0,10,20,30}; 
  40 - v1:  {30,20,10,0}; 
  v1 * 2:  {20,40,60,80}; 
  2 * v1:  {20,40,60,80}; 
  v1 / 10:  {1,2,3,4}; 
  120 / v1:  {12,6,4,3}; 
  1 + 120 / v1 - 8/8 + 5*v1*2:  {112,206,304,403}; 
```

### Vector math functions
* A large number of functions is supported.  
* A function of a `Vector` operates on each element.  


**EXAMPLE 3**: functions of a `Vector`
```C++
Vector<double> v(3);
v = {-2.5,-2.25,-1,0,1,2.25,2.5}; // C++11 list
```

**Some expressions with results**: rounding and sign-related
```C++
  floor(v):  {-3,-3,-1,0,1,2,2}; 
  ceil(v):  {-2,-2,-1,0,1,3,3}; 
  round(v):  {-3,-2,-1,0,1,2,3}; 
  sgn(v):  {-1,-1,-1,0,1,1,1}; 
  abs(v):  {2.5,2.25,1,0,1,2.25,2.5}; 
**Some expressions with results**: powers, roots, and exponentiation
```C++
  exp(v):  {0.082085,0.105399,0.367879,1,2.71828,9.48774,12.1825}; 
  log(v):  {nan,nan,nan,-inf,0,0.81093,0.916291}; 
  log10(v):  {nan,nan,nan,-inf,0,0.352183,0.39794}; 
  sqr(v):  {6.25,5.0625,1,0,1,5.0625,6.25}; 
  cube(v):  {-15.625,-11.3906,-1,0,1,11.3906,15.625}; 
  sqrt(v):  {-nan,-nan,-nan,0,1,1.5,1.58114}; 
**Some expressions with results**: trig
```C++
  sin(v):  {-0.598472,-0.778073,-0.841471,0,0.841471,0.778073,0.598472}; 
  cos(v):  {-0.801144,-0.628174,0.540302,1,0.540302,-0.628174,-0.801144}; 
  tan(v):  {0.747022,1.23863,-1.55741,0,1.55741,-1.23863,-0.747022}; 
**Some expressions with results**: hyperbolic trig
```C++
  sinh(v):  {-6.0502,-4.69117,-1.1752,0,1.1752,4.69117,6.0502}; 
  cosh(v):  {6.13229,4.79657,1.54308,1,1.54308,4.79657,6.13229}; 
  tanh(v):  {-0.986614,-0.978026,-0.761594,0,0.761594,0.978026,0.986614}; 
**Some expressions with results**: inverse (ie 'arc') trig
```C++
  asin(v):  {nan,nan,-1.5708,0,1.5708,nan,nan}; 
  acos(v):  {nan,nan,3.14159,1.5708,0,nan,nan}; 
  atan(v):  {-1.19029,-1.15257,-0.785398,0,0.785398,1.15257,1.19029}; 
```

### Arbitrary combinations of the above functionality are supported

[Table of Contents](README.md)
