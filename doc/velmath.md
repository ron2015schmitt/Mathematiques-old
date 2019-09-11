
# Element-wise Vector math in mātricks
_This document was automatically generated from file_ **`velmath.cpp`** (mātricks-v2.15-r10).

### Element-wise arithmetic
The operators +,-,*,/ perform element-wise addition, subtraction, multiplication, and division respectively


**EXAMPLE 1**: Element-wise `Vector` math
```C++
Vector<double> v1(4);
v1 = {10,20,30,40}; // C++11 list
Vector<double> v2(4);
v2 = {1,2,3,4}; // C++11 list
```

**Some expressions with results**
```C++
  v1 + v2 = {11, 22, 33, 44}; 
  v1 - v2 = {9, 18, 27, 36}; 
  v1 * v2 = {10, 40, 90, 160}; 
  v1 / v2 = {10, 10, 10, 10}; 
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
  v1 + 1 = {11, 21, 31, 41}; 
  1 + v1 = {11, 21, 31, 41}; 
  v1 - 10 = {0, 10, 20, 30}; 
  40 - v1 = {30, 20, 10, 0}; 
  v1 * 2 = {20, 40, 60, 80}; 
  2 * v1 = {20, 40, 60, 80}; 
  v1 / 10 = {1, 2, 3, 4}; 
  120 / v1 = {12, 6, 4, 3}; 
  1 + 120 / v1 - 8/8 + 5*v1*2 = {112, 206, 304, 403}; 
```

### Vector math functions
* A large number of functions is supported.  
* A function of a `Vector` operates on each element.  


**EXAMPLE 3**: functions of a `Vector`—rounding and sign-related 
```C++
Vector<double> v(7);
v = {-2.5,-2.25,-1,0,1,2.25,2.5}; // C++11 list
```

**Some expressions with results**: rounding and sign-related
```C++
  floor(v) = {-3, -3, -1, 0, 1, 2, 2}; 
  ceil(v) = {-2, -2, -1, 0, 1, 3, 3}; 
  round(v) = {-3, -2, -1, 0, 1, 2, 3}; 
  sgn(v) = {-1, -1, -1, 0, 1, 1, 1}; 
  abs(v) = {2.5, 2.25, 1, 0, 1, 2.25, 2.5}; 
```




**EXAMPLE 4**: functions of a `Vector`—powers, roots, and exponentiation
```C++
Vector<double> v(5);
v = {-1,0,1,2,4}; // C++11 list
```

**Some expressions with results**: powers, roots, and exponentiation
```C++
  pow(2., v) = {0.5, 1, 2, 4, 16}; 
  pow(v, 2.) = {1, 0, 1, 4, 16}; 
  pow(v,v) = {-1, 1, 1, 4, 256}; 
  exp(v) = {0.367879, 1, 2.71828, 7.38906, 54.5982}; 
  log(v) = {nan, -inf, 0, 0.693147, 1.38629}; 
  log10(v) = {nan, -inf, 0, 0.30103, 0.60206}; 
  log2(v) = {nan, -inf, 0, 1, 2}; 
  sqr(v) = {1, 0, 1, 4, 16}; 
  cube(v) = {-1, 0, 1, 8, 64}; 
  sqrt(v) = {-nan, 0, 1, 1.41421, 2}; 
```




**EXAMPLE 5**: functions of a `Vector`—trig
```C++
Vector<double> v(5);
constexpr double pi = std::acos(-1); // C++11 constexpr
v = {-pi, -pi/2, 0, pi/2, pi}; // C++11 list
const double tol = 2e-16;
```

**Some expressions with results**: trig
```C++
  sin(v) = {-1.22465e-16, -1, 0, 1, 1.22465e-16}; 
  cos(v) = {-1, 6.12323e-17, 1, 6.12323e-17, -1}; 
  tan(v) = {1.22465e-16, -1.63312e+16, 0, 1.63312e+16, -1.22465e-16}; 
```


The results are cleaner, when we round to a tolerance

**Some expressions with results**: trig with rounded zeros
```C++
  roundzero(sin(v),tol) = {0, -1, 0, 1, 0}; 
  roundzero(cos(v),tol) = {-1, 0, 1, 0, -1}; 
  roundzero(tan(v),tol) = {0, -1.63312e+16, 0, 1.63312e+16, 0}; 
```



**EXAMPLE 6**: functions of a `Vector`—rounding and sign-related 
```C++
Vector<double> v(3);
v = {-1,0,1}; // C++11 list
```

**Some expressions with results**: hyperbolic trig
```C++
  sinh(v) = {-1.1752, 0, 1.1752}; 
  cosh(v) = {1.54308, 1, 1.54308}; 
  tanh(v) = {-0.761594, 0, 0.761594}; 
```




**EXAMPLE 7**: functions of a `Vector`—inverse trig
```C++
double pi = std::acos(-1);
Vector<double> v(3);
Vector<double> v1(9);
Vector<double> v2(9);
v = {-1,0,1}; // C++11 list
v1 = {-1,-1,-1, 0, 0, 0, 1, 1, 1}; // C++11 list
v2 = {-1, 0, 1,-1, 0, 1,-1, 0, 1}; // C++11 list
```

**Some expressions with results**: inverse trig
```C++
  asin(v)/pi = {-0.5, 0, 0.5}; 
  acos(v)/pi = {1, 0.5, 0}; 
  atan(v)/pi = {-0.25, 0, 0.25}; 
  atan2(v1, v2)/pi = {-0.75, -0.5, -0.25, 1, 0, 0, 0.75, 0.5, 0.25}; 
```

### Arbitrary combinations of the above functionality are supported
* Because mātricks uses expression templating:
  * no intermediate objects are created
  * the expression is calculated in a single for loop


**EXAMPLE 8**: A huge expression
```C++
Vector<double> v1(4);
v1 = {10,20,30,40}; // C++11 list
Vector<double> v2(4);
v2 = {-1,-2,-3,-4}; // C++11 list
```

**Some expressions with results**
```C++
  2*log10(abs(v1/v2)*100) + 3 + pow(-v2,2.) = {10, 13, 18, 25}; 
```


[Table of Contents](README.md)
