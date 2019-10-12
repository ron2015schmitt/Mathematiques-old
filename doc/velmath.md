
[Table of Contents](README.md)


# Element-wise Vector math in mātricks
_This document was automatically generated from file_ **`velmath.cpp`** (mātricks-v2.24).

### Element-wise arithmetic
The operators +,-,*,/ perform element-wise addition, subtraction, multiplication, and division respectively


**EXAMPLE 1**: Element-wise `Vector` math
```C++
Vector<double> v1(4);
v1 = {10,20,30,40}; // C++11 list
Vector<double> v2(4);
v2 = {1,2,3,4}; // C++11 list
```

v1 = {10, 20, 30, 40}; 
{10, 20, 30, 40}+{1, 2, 3, 4}...
Vector<double> a = {10, 20, 30, 40}; 
Vector<double> b = {1, 2, 3, 4}; 
*vptrs = {0x7ffe07be2d80, 0x7ffe07be2da0}; 
Vector<double> *a_ = {10, 20, 30, 40}; 
Vector<double> *b_ = {1, 2, 3, 4}; 
unsigned long this->size() = 4; 
v1+v2 = i = 3; (*a_)[i] = 40; (*b_)[i] = 4; 
i = 2; (*a_)[i] = 30; (*b_)[i] = 3; 
i = 1; (*a_)[i] = 20; (*b_)[i] = 2; 
i = 0; (*a_)[i] = 10; (*b_)[i] = 1; 
Vector<double> {11, 22, 33, 44}; 
v1 = {10, 20, 30, 40}; 
**Some expressions with results**
```C++
  {10, 20, 30, 40}+{1, 2, 3, 4}...
Vector<double> a = {10, 20, 30, 40}; 
Vector<double> b = {1, 2, 3, 4}; 
*vptrs = {0x7ffe07be2d80, 0x7ffe07be2da0}; 
Vector<double> *a_ = {10, 20, 30, 40}; 
Vector<double> *b_ = {1, 2, 3, 4}; 
unsigned long this->size() = 4; 
v1 + v2 = i = 3; (*a_)[i] = 40; (*b_)[i] = 4; 
i = 2; (*a_)[i] = 30; (*b_)[i] = 3; 
i = 1; (*a_)[i] = 20; (*b_)[i] = 2; 
i = 0; (*a_)[i] = 10; (*b_)[i] = 1; 
Vector<double> {11, 22, 33, 44}; 
  Vector<double> a = {10, 20, 30, 40}; 
Vector<double> b = {1, 2, 3, 4}; 
*vptrs = {0x7ffe07be2d80, 0x7ffe07be2da0}; 
Vector<double> *a_ = {10, 20, 30, 40}; 
Vector<double> *b_ = {1, 2, 3, 4}; 
unsigned long this->size() = 4; 
v1 - v2 = i = 3; (*a_)[i] = 40; (*b_)[i] = 4; 
i = 2; (*a_)[i] = 30; (*b_)[i] = 3; 
i = 1; (*a_)[i] = 20; (*b_)[i] = 2; 
i = 0; (*a_)[i] = 10; (*b_)[i] = 1; 
Vector<double> {9, 18, 27, 36}; 
  Vector<double> a = {10, 20, 30, 40}; 
Vector<double> b = {1, 2, 3, 4}; 
*vptrs = {0x7ffe07be2d80, 0x7ffe07be2da0}; 
Vector<double> *a_ = {10, 20, 30, 40}; 
Vector<double> *b_ = {1, 2, 3, 4}; 
unsigned long this->size() = 4; 
v1 * v2 = i = 3; (*a_)[i] = 40; (*b_)[i] = 4; 
i = 2; (*a_)[i] = 30; (*b_)[i] = 3; 
i = 1; (*a_)[i] = 20; (*b_)[i] = 2; 
i = 0; (*a_)[i] = 10; (*b_)[i] = 1; 
Vector<double> {10, 40, 90, 160}; 
  Vector<double> a = {10, 20, 30, 40}; 
Vector<double> b = {1, 2, 3, 4}; 
*vptrs = {0x7ffe07be2d80, 0x7ffe07be2da0}; 
Vector<double> *a_ = {10, 20, 30, 40}; 
Vector<double> *b_ = {1, 2, 3, 4}; 
unsigned long this->size() = 4; 
v1 / v2 = i = 3; (*a_)[i] = 40; (*b_)[i] = 4; 
i = 2; (*a_)[i] = 30; (*b_)[i] = 3; 
i = 1; (*a_)[i] = 20; (*b_)[i] = 2; 
i = 0; (*a_)[i] = 10; (*b_)[i] = 1; 
Vector<double> {10, 10, 10, 10}; 
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
  v1 + 1 = Vector<double> {11, 21, 31, 41}; 
  1 + v1 = Vector<double> {11, 21, 31, 41}; 
  v1 - 10 = Vector<double> {0, 10, 20, 30}; 
  40 - v1 = Vector<double> {30, 20, 10, 0}; 
  v1 * 2 = Vector<double> {20, 40, 60, 80}; 
  2 * v1 = Vector<double> {20, 40, 60, 80}; 
  v1 / 10 = Vector<double> {1, 2, 3, 4}; 
  120 / v1 = Vector<double> {12, 6, 4, 3}; 
  Vector<double> {12, 6, 4, 3}+Vector<double> {100, 200, 300, 400}...
TER_TensorOpScalar a = Vector<double> {12, 6, 4, 3}; 
TER_TensorOpScalar b = Vector<double> {100, 200, 300, 400}; 
*vptrs = {0x7ffe07be2d00, 0x7ffe07be2d00}; 
TER_TensorOpScalar *a_ = Vector<double> {12, 6, 4, 3}; 
TER_TensorOpScalar *b_ = Vector<double> {100, 200, 300, 400}; 
unsigned long this->size() = 4; 
1 + 120 / v1 - 8/8 + 5*v1*2 = i = 3; (*a_)[i] = 3; (*b_)[i] = 400; 
i = 2; (*a_)[i] = 4; (*b_)[i] = 300; 
i = 1; (*a_)[i] = 6; (*b_)[i] = 200; 
i = 0; (*a_)[i] = 12; (*b_)[i] = 100; 
Vector<double> {112, 206, 304, 403}; 
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
  floor(v) = Vector<double> {-3, -3, -1, 0, 1, 2, 2}; 
  ceil(v) = Vector<double> {-2, -2, -1, 0, 1, 3, 3}; 
  round(v) = Vector<double> {-3, -2, -1, 0, 1, 2, 3}; 
  sgn(v) = Vector<double> {-1, -1, -1, 0, 1, 1, 1}; 
  abs(v) = Vector<double> {2.5, 2.25, 1, 0, 1, 2.25, 2.5}; 
```




**EXAMPLE 4**: functions of a `Vector`—powers, roots, and exponentiation
```C++
Vector<double> v(5);
v = {-1,0,1,2,4}; // C++11 list
```

**Some expressions with results**: powers, roots, and exponentiation
```C++
  pow(2., v) = Vector<double> {0.5, 1, 2, 4, 16}; 
  pow(v, 2.) = Vector<double> {1, 0, 1, 4, 16}; 
  Vector<double> a = {-1, 0, 1, 2, 4}; 
Vector<double> b = {-1, 0, 1, 2, 4}; 
*vptrs = {0x7ffe07be2da0, 0x7ffe07be2da0}; 
Vector<double> *a_ = {-1, 0, 1, 2, 4}; 
Vector<double> *b_ = {-1, 0, 1, 2, 4}; 
unsigned long this->size() = 5; 
pow(v,v) = i = 4; (*a_)[i] = 4; (*b_)[i] = 4; 
i = 3; (*a_)[i] = 2; (*b_)[i] = 2; 
i = 2; (*a_)[i] = 1; (*b_)[i] = 1; 
i = 1; (*a_)[i] = 0; (*b_)[i] = 0; 
i = 0; (*a_)[i] = -1; (*b_)[i] = -1; 
Vector<double> {-1, 1, 1, 4, 256}; 
  exp(v) = Vector<double> {0.367879, 1, 2.71828, 7.38906, 54.5982}; 
  log(v) = Vector<double> {nan, -inf, 0, 0.693147, 1.38629}; 
  log10(v) = Vector<double> {nan, -inf, 0, 0.30103, 0.60206}; 
  log2(v) = Vector<double> {nan, -inf, 0, 1, 2}; 
  sqr(v) = Vector<double> {1, 0, 1, 4, 16}; 
  cube(v) = Vector<double> {-1, 0, 1, 8, 64}; 
  sqrt(v) = Vector<double> {-nan, 0, 1, 1.41421, 2}; 
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
  sin(v) = Vector<double> {-1.22465e-16, -1, 0, 1, 1.22465e-16}; 
  cos(v) = Vector<double> {-1, 6.12323e-17, 1, 6.12323e-17, -1}; 
  tan(v) = Vector<double> {1.22465e-16, -1.63312e+16, 0, 1.63312e+16, -1.22465e-16}; 
```


The results are cleaner, when we round to a tolerance

**Some expressions with results**: trig with rounded zeros
```C++
  roundzero(sin(v),tol) = Vector<double> {0, -1, 0, 1, 0}; 
  roundzero(cos(v),tol) = Vector<double> {-1, 0, 1, 0, -1}; 
  roundzero(tan(v),tol) = Vector<double> {0, -1.63312e+16, 0, 1.63312e+16, 0}; 
```



**EXAMPLE 6**: functions of a `Vector`—rounding and sign-related 
```C++
Vector<double> v(3);
v = {-1,0,1}; // C++11 list
```

**Some expressions with results**: hyperbolic trig
```C++
  sinh(v) = Vector<double> {-1.1752, 0, 1.1752}; 
  cosh(v) = Vector<double> {1.54308, 1, 1.54308}; 
  tanh(v) = Vector<double> {-0.761594, 0, 0.761594}; 
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
  asin(v)/pi = Vector<double> {-0.5, 0, 0.5}; 
  acos(v)/pi = Vector<double> {1, 0.5, 0}; 
  atan(v)/pi = Vector<double> {-0.25, 0, 0.25}; 
  Vector<double> a = {-1, -1, -1, 0, 0, 0, 1, 1, 1}; 
Vector<double> b = {-1, 0, 1, -1, 0, 1, -1, 0, 1}; 
*vptrs = {0x7ffe07be2d60, 0x7ffe07be2d80}; 
Vector<double> *a_ = {-1, -1, -1, 0, 0, 0, 1, 1, 1}; 
Vector<double> *b_ = {-1, 0, 1, -1, 0, 1, -1, 0, 1}; 
unsigned long this->size() = 9; 
atan2(v1, v2)/pi = i = 8; (*a_)[i] = 1; (*b_)[i] = 1; 
i = 7; (*a_)[i] = 1; (*b_)[i] = 0; 
i = 6; (*a_)[i] = 1; (*b_)[i] = -1; 
i = 5; (*a_)[i] = 0; (*b_)[i] = 1; 
i = 4; (*a_)[i] = 0; (*b_)[i] = 0; 
i = 3; (*a_)[i] = 0; (*b_)[i] = -1; 
i = 2; (*a_)[i] = -1; (*b_)[i] = 1; 
i = 1; (*a_)[i] = -1; (*b_)[i] = 0; 
i = 0; (*a_)[i] = -1; (*b_)[i] = -1; 
Vector<double> {-0.75, -0.5, -0.25, 1, 0, 0, 0.75, 0.5, 0.25}; 
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
  Vector<double> a = {10, 20, 30, 40}; 
Vector<double> b = {-1, -2, -3, -4}; 
*vptrs = {0x7ffe07be2ca0, 0x7ffe07be2cb0}; 
Vector<double> *a_ = {10, 20, 30, 40}; 
Vector<double> *b_ = {-1, -2, -3, -4}; 
unsigned long this->size() = 4; 
i = 3; (*a_)[i] = 40; (*b_)[i] = -4; 
i = 2; (*a_)[i] = 30; (*b_)[i] = -3; 
i = 1; (*a_)[i] = 20; (*b_)[i] = -2; 
i = 0; (*a_)[i] = 10; (*b_)[i] = -1; 
Vector<double> {9, 9, 9, 9}+Vector<double> {1, 4, 9, 16}...
TER_TensorOpScalar_New a = i = 3; (*a_)[i] = 40; (*b_)[i] = -4; 
i = 2; (*a_)[i] = 30; (*b_)[i] = -3; 
i = 1; (*a_)[i] = 20; (*b_)[i] = -2; 
i = 0; (*a_)[i] = 10; (*b_)[i] = -1; 
Vector<double> {9, 9, 9, 9}; 
TER_TensorOpScalar b = Vector<double> {1, 4, 9, 16}; 
*vptrs = {0x7ffe07be2ca0, 0x7ffe07be2cb0, 0x7ffe07be2cb0}; 
TER_TensorOpScalar_New *a_ = i = 3; (*a_)[i] = 40; (*b_)[i] = -4; 
i = 2; (*a_)[i] = 30; (*b_)[i] = -3; 
i = 1; (*a_)[i] = 20; (*b_)[i] = -2; 
i = 0; (*a_)[i] = 10; (*b_)[i] = -1; 
Vector<double> {9, 9, 9, 9}; 
TER_TensorOpScalar *b_ = Vector<double> {1, 4, 9, 16}; 
unsigned long this->size() = 4; 
2*log10(abs(v1/v2)*100) + 3 + pow(-v2,2.) = i = 3; i = 3; (*a_)[i] = 40; (*b_)[i] = -4; 
(*a_)[i] = 9; (*b_)[i] = 16; 
i = 3; (*a_)[i] = 40; (*b_)[i] = -4; 
i = 2; i = 2; (*a_)[i] = 30; (*b_)[i] = -3; 
(*a_)[i] = 9; (*b_)[i] = 9; 
i = 2; (*a_)[i] = 30; (*b_)[i] = -3; 
i = 1; i = 1; (*a_)[i] = 20; (*b_)[i] = -2; 
(*a_)[i] = 9; (*b_)[i] = 4; 
i = 1; (*a_)[i] = 20; (*b_)[i] = -2; 
i = 0; i = 0; (*a_)[i] = 10; (*b_)[i] = -1; 
(*a_)[i] = 9; (*b_)[i] = 1; 
i = 0; (*a_)[i] = 10; (*b_)[i] = -1; 
Vector<double> {10, 13, 18, 25}; 
```


[Table of Contents](README.md)
