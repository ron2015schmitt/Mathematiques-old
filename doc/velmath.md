
# Element-wise Vector math in mātricks
_This document was automatically generated from file_ **`velmath.cpp`** (mātricks-v2.16-r20).

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
  v1 + v2 = {double, double, double, double}; 
  v1 - v2 = {double, double, double, double}; 
  v1 * v2 = {double, double, double, double}; 
  v1 / v2 = {double, double, double, double}; 
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
  v1 + 1 = {double, double, double, double}; 
  1 + v1 = {double, double, double, double}; 
  v1 - 10 = {double, double, double, double}; 
  40 - v1 = {double, double, double, double}; 
  v1 * 2 = {double, double, double, double}; 
  2 * v1 = {double, double, double, double}; 
  v1 / 10 = {double, double, double, double}; 
  120 / v1 = {double, double, double, double}; 
  1 + 120 / v1 - 8/8 + 5*v1*2 = {double, double, double, double}; 
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
  floor(v) = {double, double, double, double, double, double, double}; 
  ceil(v) = {double, double, double, double, double, double, double}; 
  round(v) = {double, double, double, double, double, double, double}; 
  sgn(v) = {double, double, double, double, double, double, double}; 
  abs(v) = {double, double, double, double, double, double, double}; 
```




**EXAMPLE 4**: functions of a `Vector`—powers, roots, and exponentiation
```C++
Vector<double> v(5);
v = {-1,0,1,2,4}; // C++11 list
```

**Some expressions with results**: powers, roots, and exponentiation
```C++
  pow(2., v) = {double, double, double, double, double}; 
  pow(v, 2.) = {double, double, double, double, double}; 
  pow(v,v) = {double, double, double, double, double}; 
  exp(v) = {double, double, double, double, double}; 
  log(v) = {double, double, double, double, double}; 
  log10(v) = {double, double, double, double, double}; 
  log2(v) = {double, double, double, double, double}; 
  sqr(v) = {double, double, double, double, double}; 
  cube(v) = {double, double, double, double, double}; 
  sqrt(v) = {double, double, double, double, double}; 
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
  sin(v) = {double, double, double, double, double}; 
  cos(v) = {double, double, double, double, double}; 
  tan(v) = {double, double, double, double, double}; 
```


The results are cleaner, when we round to a tolerance

**Some expressions with results**: trig with rounded zeros
```C++
  roundzero(sin(v),tol) = {double, double, double, double, double}; 
  roundzero(cos(v),tol) = {double, double, double, double, double}; 
  roundzero(tan(v),tol) = {double, double, double, double, double}; 
```



**EXAMPLE 6**: functions of a `Vector`—rounding and sign-related 
```C++
Vector<double> v(3);
v = {-1,0,1}; // C++11 list
```

**Some expressions with results**: hyperbolic trig
```C++
  sinh(v) = {double, double, double}; 
  cosh(v) = {double, double, double}; 
  tanh(v) = {double, double, double}; 
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
  asin(v)/pi = {double, double, double}; 
  acos(v)/pi = {double, double, double}; 
  atan(v)/pi = {double, double, double}; 
  atan2(v1, v2)/pi = {double, double, double, double, double, double, double, double, double}; 
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
  2*log10(abs(v1/v2)*100) + 3 + pow(-v2,2.) = {double, double, double, double}; 
```


[Table of Contents](README.md)
