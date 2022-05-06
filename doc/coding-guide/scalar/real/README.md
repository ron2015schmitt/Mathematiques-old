# Mathématiques v3.5.21


<details>

<summary>User Guide</summary>

1. [About](../../../about/README.md)<br>
2. [License](../../../license/README.md)<br>
3. [Release Notes](../../../release-notes/README.md)<br>
4. [Installation](../../../installation/README.md)<br>
5. [Makefile / Using Mathématiques](../../../using-mathematiques/README.md)<br>
6. [Code Examples](../../../examples/README.md)<br>
7. _Coding Guide / Syntax_ <br>
8. [Benchmarks](../../../benchmarks/README.md)<br>
9. [Tests](../../../test/README.md)<br>
10. [New Feature Plans](../../../feature-schedule/README.md)<br>
11. [Developer Guide](../../../developer-guide/README.md)<br>


</details>



<details>

<summary>7. Coding Guide / Syntax</summary>


7.1. _Scalar Math: real, imaginary, complex, and quaternions_ <br>
7.2. [Vectors](../../vector/README.md)<br>
7.3. [Matrices](../../matrix/README.md)<br>
7.4. [Tensors](../../tensor/README.md)<br>
7.5. [User Guide Notation](../../notation/README.md)<br>
7.6. [Operators](../../operators/README.md)<br>
7.7. [Display of Results](../../display/README.md)<br>
7.8. [Linear Algebra](../../linear-algebra/README.md)<br>
7.9. [FILE I/O](../../file-io/README.md)<br>
7.10. [Debug Modes](../../debug/README.md)<br>


</details>



<details>

<summary>7.1. Scalar Math: real, imaginary, complex, and quaternions</summary>


7.1.1. _Real number mathematics_ <br>
7.1.2. [Complex number mathematics](../complex/README.md)<br>
7.1.3. [Imaginary number mathematics](../imaginary/README.md)<br>
7.1.4. [Quaternion Mathematics](../quaternion/README.md)<br>


</details>



# 7.1.1. Real number mathematics

_This document was generated from the_ C++ _file_ `real/body.cpp` _using functions and macros in the namespaces_ `mathq::display` _and_ `mathq::md` _in headers_ `"mathq.h"` _and_ `"gitmd.h"`_respectively._ 

C++ supports a wide variety of real number [integer and floating point types](https://en.cppreference.com/w/cpp/language/types), operators, and functions.

Mathématiques supplements C++ functionality with several more functions.

Mathématiques extends many of these operators and functions to complex numbers, imaginary numbers, and quaterions, as well as extending to vectors, matrices, and tensors in a element-wise fashion.


## Integers


### Signed Integers
C++ supports several different signed integer types.  The size of each depends on the CPU and compiler.  For a 64-bit CPU running Linux, they have the following number of bits:


```C++
CHAR_BIT = 8 bits
CHAR_BIT*sizeof(char) = 8 bits
CHAR_BIT*sizeof(short) = 16 bits
CHAR_BIT*sizeof(int) = 32 bits
CHAR_BIT*sizeof(long) = 64 bits
CHAR_BIT*sizeof(long long) = 64 bits
```
The symbol [```CHAR_BIT```](https://en.cppreference.com/w/cpp/header/climits) yields the number of bits per byte, and the C++ function [```sizeof()```](https://en.cppreference.com/w/cpp/language/sizeof) yields the size in _bytes_ of the argument, which can be a type, variable, or expression.

The maximum and minimum for each type are given below.
| Type | Min | Max |
| :--- | :---: | :---: |
| ```char``` | -128 | 127 |
| ```short``` | -32768 | 32767 |
| ```int``` | -2147483648 | 2147483647 |
| ```long``` | -9223372036854775808 | 9223372036854775807 |
| ```long long``` | -9223372036854775808 | 9223372036854775807 |

Here the C++ [```std::numeric_limits```](https://en.cppreference.com/w/cpp/types/numeric_limits) functions were used to compute the max and min.

<br>

### Unsigned Integers
C++ supports unsigned versions of each integer type.
The maximum and minimum for each type are given below.
| Type | Min | Max |
| :--- | :---: | :---: |
| ```unsigned char``` | 0 | 255 |
| ```unsigned short``` | 0 | 65535 |
| ```unsigned int``` | 0 | 4294967295 |
| ```unsigned long``` | 0 | 18446744073709551615 |
| ```unsigned long long``` | 0 | 18446744073709551615 |

<br>

### Indexing Types
The type [```size_t```](https://en.cppreference.com/w/c/types/size_t) is the _unsigned_ integer type that is the best type to use for array indexing and loop counting because it size_t can store the maximum size of a theoretically possible object of any type (including array)
It's size depends on implementation.  The 64-bit Linux size is shown below:


```C++
CHAR_SIZE*sizeof(size_t) = 8 bits
```


<br>

### Fixed width integer types
C++11 introduced new types, called [fixed interger types](https://en.cppreference.com/w/cpp/types/integer), that allow you to directly specify the number of bits:
| type | signed / unsigned | bits |
| :--- | :---: | :---: |
| int8_t | signed | 8 bits |
| int16_t | signed | 8 bits |
| int32_t | signed | 16 bits |
| int64_t | signed | 32 bits |
| uint8_t | unsigned | 8 bits |
| uint16_t | unsigned | 8 bits |
| uint32_t | unsigned | 16 bits |
| uint64_t | unsigned | 32 bits |


<br>

### Logic
The boolean type, [```bool```](https://en.cppreference.com/w/c/types/boolean), was introduced in C99.  A ```bool``` can take only two values, 0 or 1.
Two associated constants are defined: ```true``` and ```false```.


```C++
CHAR_BIT*sizeof(bool) = 8 bits

false  =>  bool 0
true  =>  bool 1
```

<br>

### Bitwise Math
Bit-wise math is supported by C++, but not inherently supported by Mathématiques because the bitwise operators are overloaded for vector/matrix operations.  Of course, modification of the source could easily support bit-wise vector/matrix operations.

<br>

## Floating Point Numbers
On modern systems, C++ generally supports three types of floating point number:


```C++
CHAR_BIT*sizeof(float) = 8 bits
CHAR_BIT*sizeof(double) = 16 bits
CHAR_BIT*sizeof(long double) = 32 bits
```
The three types are compared below.
| type | name | bits | standard |  ```digits10``` |  ```max_digits10``` | ```epsilon()``` | ```min()``` | ```lowest()``` | ```max()``` | 
| :--- | :---: | :---: | :---:  | :---:  | :---:  | :---:  | :---:  | :---: | :---: |
| float | Single Precision | 32 bits | [IEEE 754-2008 binary32](https://en.wikipedia.org/wiki/Single-precision_floating-point_format) | 6 |  9 |  1.1920929e-07 |  1.17549435e-38 |  -3.40282347e+38 |  3.40282347e+38 | 
| double | Double Precision | 64 bits | [IEEE 754-2008 binary64](https://en.wikipedia.org/wiki/Double-precision_floating-point_format) | 15 |  17 |  2.2204460492503131e-16 |  2.2250738585072014e-308 |  -1.7976931348623157e+308 |  1.7976931348623157e+308 | 
| long double | Quad Precision | 128 bits | [IEEE 754-2008 binary128](https://en.wikipedia.org/wiki/Quadruple-precision_floating-point_format) | 18 |  21 |  1.08420217248550443401e-19 |  3.36210314311209350626e-4932 |  -1.18973149535723176502e+4932 |  1.18973149535723176502e+4932 | 


The functions ```epsilon()```, ```min()```, ```lowest()```, and  ```max()```, as well as the static values ```digits10``` and ```max_digits10``` are found in [```limits```](https://en.cppreference.com/w/cpp/types/numeric_limits)
The static value ```max_digits10``` was used as the precision for printing the above values.


<br>

## Operators and functions
### Arithmetic Operators
The operators ```+, -, *, /, %``` are the addition, subtraction, multiplication, division, and modulus operators respectively.

For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).


| operator | operation | 
| :---: | :---: | 
| ```+``` | addition | 
| ```-``` | subtraction | 
| ```*``` | multiplication | 
| ```/``` | division | 
| ```%``` | modulus | 

* If both numerator and denominator are integers, the division operator gives the integer division result.

```C++
7 / 2  =>  int 3
```
* The modulus operator ```a % b```, gives the remainder after integer divison of ```a``` by ```b```.

```C++
7 % 2  =>  int 1
```
* The function [```std::div```](https://en.cppreference.com/w/cpp/numeric/math/div) can also be used for integer division, It returns both the result and remainder.

```C++
div_t result = div(7, 2);
```
With result:

```C++
result.quot  =>  int 3
result.rem  =>  int 1
```

<br>

### Exponentiation and the ```pow``` function
C++ does not have an exponentiation operator.  Instead it provides the [```std::pow```](https://en.cppreference.com/w/cpp/numeric/math/div) function
```C++
pow(2, 8)  =>  double 256
pow(25, 1 / 2)  =>  double 1
```

<br>

### Logic Operators
For details refer [Logical Operators](https://en.cppreference.com/w/c/language/operator_logical).


| operator | operation | 
| :---: | :---: | 
| ```!``` | logical NOT | 
| `\|\|` | logical OR | 
| ```&&``` | logical AND | 

**CAVEAT**: C++ also has binary bit-wise operators `&` and `|`.  Mistyping the above operators can cause painful bugs. 


Examples:

```C++
true  =>  bool 1
false  =>  bool 0
!true  =>  bool 0
!false  =>  bool 1
true && true  =>  bool 1
true && false  =>  bool 0
true || false  =>  bool 1
```
* In C++ logical operators work for all real and integer types: `0` corresponds to `false` and all non-zero values correspond to `true`

```C++
!true  =>  bool 0
!8  =>  bool 0
!!8.293  =>  bool 1
true && 3  =>  bool 1
true && 0  =>  bool 0
```

<br>

### Relational Operators
For details refer [Comparison Operators](https://en.cppreference.com/w/c/language/operator_comparison).


| operator | operation | 
| :---: | :---: | 
| `==` | equal to | 
| `!=` | not equal to | 
| `<` | less than | 
| `<=` | less than or equal to | 
| `>` | greater than | 
| `>=` | greater than or equal to | 

**CAVEAT**: C++ allows assigment `=` inside `if` statements (eg, `if (a = true) return;`).  Mistyping the equals operator `==` can cause painful bugs. 


Examples:

```C++
(2 == 2)  =>  bool 1
(1 / 2 == 0.5)  =>  bool 0
(1. / 2 == 0.5)  =>  bool 1
(-2 < 34.2)  =>  bool 1
(2 > 0)  =>  bool 1
```

<br>

### Mathematical functions from the C++ ``std`` library
The following notation is used in the User Guide.


| symbol | C++ types |
| :---: | :---: | 
| ℤ | any C++ real integral type: `bool`, `int`, `long`, etc | 
| ℝ | any C++ real floating-point type: `float`, `double`, `long double`) | 
| ℂ | any `std::complex<ℝ>` | 
| 𝕁 | any `Imaginary<ℝ>` | 
| ℍ | any `Quaternion<ℝ>` | 
| 𝕂 | any ℝ, ℂ, 𝕁, ℍ | 
| 𝕊 | any ℤ, 𝕂 | 


<br>

#### Mathematical Functions

The following are basic mathematical functions for manipulating numbers.

| function | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `abs(x)` | `std` | `<cmath>` | [absolute value](https://en.cppreference.com/w/cpp/numeric/math/abs) | 
| `abs(u)` | `mathq` | `"mathq.h"` | **mathq** abs  | 
| `ceil(x)` | `std` | `<cmath>` | [ceiling function](https://en.cppreference.com/w/cpp/numeric/math/ceil) | 
| `ceil(u)` | `mathq` | `"mathq.h"` | **mathq** ceiling | 
| `floor(x)` | `std` | `<cmath>` | [floor function](https://en.cppreference.com/w/cpp/numeric/math/floor) | 
| `floor(u)` | `mathq` | `"mathq.h"` | **mathq** floor | 
| `one(u)` | `mathq` | `"mathq.h"` | return a one with the same type as x | 
| `trunc(x)` | `std` | `<cmath>` | [truncate function](https://en.cppreference.com/w/cpp/numeric/math/trunc) | 
| `trunc(u)` | `mathq` | `"mathq.h"` | **mathq** truncate | 
| `round(x)` | `std` | `<cmath>` | [round function](https://en.cppreference.com/w/cpp/numeric/math/round) | 
| `round(u)` | `mathq` | `"mathq.h"` | **mathq** round function | 
| `roundzero(u, tolerance = Helper<X>::tolerance)` | `mathq` | `"mathq.h"` | round numbers with magnitude less than `tolerance` to 0. The default values are shown below. | 
| `sgn(u)` | `mathq` | `"mathq.h"` | [signum function](https://en.wikipedia.org/wiki/Sign_function), return type has same type as x | 
| `zero(u)` | `mathq` | `"mathq.h"` | return a zero with the same type as x | 


Notes:
The default `zero_tolerance` values are global variables and can be changed by the user code.
The default values were chosen so that the typical numerical error encountered with trig functions will produce exactly zero when appropriate.

```C++
Helper<float>::tolerance  =>  3.5e-07
Helper<double>::tolerance  =>  1.5e-16
Helper<long double>::tolerance  =>  1.5e-30
```



<br>


The following functions / operators are provided for using real number types with imaginary and complex types.

| function | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `real(x)` | `mathq` | `"mathq.h"` | returns x | 
| `imag(x)` | `mathq` | `"mathq.h"` | returns `zero(x)` | 
| `conj(x)` | `mathq` | `"mathq.h"` | returns x | 
| `~x` | `mathq` | `"mathq.h"` | returns x | 


*Trig Functions*

| function | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `sin(x)` | [sine](https://en.cppreference.com/w/cpp/numeric/math/sin) | 
| `cos(x)` | [cosine](https://en.cppreference.com/w/cpp/numeric/math/cos) | 
| `tan(x)` | [tangent](https://en.cppreference.com/w/cpp/numeric/math/tan) | 


*Inverse Trig Functions*

| function | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `asin(x)` | [arc sine](https://en.cppreference.com/w/cpp/numeric/math/asin) | 
| `acos(x)` | [arc cosine](https://en.cppreference.com/w/cpp/numeric/math/acos) | 
| `atan(x)` | [arc tangent: all results are mapped into -𝜋/2 <= 𝜃 <= +𝜋/2](https://en.cppreference.com/w/cpp/numeric/math/atan) | 
| `atan2(b, a)` | [arc tangent of b/a with full quadrant angles, 0 <= 𝜃 < +2𝜋](https://en.cppreference.com/w/cpp/numeric/math/atan2) | 


*Hyperbolic Trig Functions*

| function | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `sinh(x)` | [Hyperbolic sine](https://en.cppreference.com/w/cpp/numeric/math/sinh) | 
| `cosh(x)` | [Hyperbolic cosine](https://en.cppreference.com/w/cpp/numeric/math/cosh) | 
| `tanh(x)` | [Hyperbolic tangent](https://en.cppreference.com/w/cpp/numeric/math/tanh) | 


*Inverse Hyperbolic Trig Functions*

| function | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `asinh(x)` | [Hyperbolic arc sine](https://en.cppreference.com/w/cpp/numeric/math/asinh) | 
| `acosh(x)` | [Hyperbolic arc cosine](https://en.cppreference.com/w/cpp/numeric/math/acosh) | 
| `atanh(x)` | [Hyperbolic arc tangent](https://en.cppreference.com/w/cpp/numeric/math/atanh) | 


*Exponentiation*

| function | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `pow(x, y)` | [x<sup>y</sup>](https://en.cppreference.com/w/cpp/numeric/math/pow) | 
| `sqrt(x)` | [Square Root](https://en.cppreference.com/w/cpp/numeric/math/sqrt) | 
| `cqrt(x)` | [Cube Root](https://en.cppreference.com/w/cpp/numeric/math/cqrt) | 


*Exponentials*

| function | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `exp(x)` | [e<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/math/exp) | 
| `exp2(x)` | [2<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/math/exp2) | 
| `expm1(x)` | [e<sup>x</sup> - 1](https://en.cppreference.com/w/cpp/numeric/math/expm1) | 


*Logarithms*

| function | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `log(x)` | [Natural Logarithm, ln(x) = log<sub>e</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log) | 
| `log10(x)` | [base 10 logarithm, log<sub>10</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log10) | 
| `log2(x)` | [base 2 logarithm, log<sub>2</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log2) | 
| `log1p(x)` | [ln(x + 1)](https://en.cppreference.com/w/cpp/numeric/math/log1p) | 
| `logb(x)` | [extracts exponent of the number and returns a floating point type](https://en.cppreference.com/w/cpp/numeric/math/logb) | 
| `ilogb(x)` | [extracts exponent of the number and returns an integral type](https://en.cppreference.com/w/cpp/numeric/math/ilogb) | 


*Other Functions*

| function | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `erf(x)` | [error function, erf(x)](https://en.cppreference.com/w/cpp/numeric/math/erf) | 
| `erfc(x)` | [complimentary error function, erfc(x)](https://en.cppreference.com/w/cpp/numeric/math/erfc) | 
| `tgamma(x)` | [Gamma Function, Γ(x)](https://en.cppreference.com/w/cpp/numeric/math/tgamma) | 
| `lgamma(x)` | [Natural Logarithm of the Gamma Function, ln(Γ(x))](https://en.cppreference.com/w/cpp/numeric/math/lgamma) | 


#### C++ ``std`` library special functions
The following [special mathematical functions](https://en.cppreference.com/w/cpp/numeric/special_functions) implemented in the C++ `std` library

*Bessel Functions*

| <div style='width:180px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `cyl_bessel_j(𝜈, x)` | _J_<sub>𝜈</sub>(_x_) | [Bessel function of the 1st kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_j) | 
| `cyl_neumann(𝜈, x)` | _Y_<sub>𝜈</sub>(_x_) | [Bessel (aka Neumann or Weber) function of the 2nd kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_neumann) | 
| `cyl_bessel_i(𝜈, x)` | _I_<sub>𝜈</sub>(_x_) | [Modified Bessel function of the 1st kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_i) | 
| `cyl_bessel_k(𝜈, x)` | _K_<sub>𝜈</sub>(_x_) | [Modified Bessel function of the 2nd kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_k) | 


*Spherical Bessel Functions*

| <div style='width:180px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `sph_bessel(n, x)` | _j_<sub>n</sub>(_x_) | [Spherical Bessel function of the 1st kind of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_bessel) | 
| `sph_neumann(n, x)` | _y_<sub>n</sub>(_x_) | [Spherical Bessel (aka Neumann or Weber) function of the 2nd kind of degree n, aka Spherical Neumann function](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_neumann) | 


*Orthogonal Polynomials*

| <div style='width:180px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `hermite(n, x)` | _H_<sub>n</sub>(_x_) | [Hermite polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/hermite) | 
| `laguerre(n, x)` | _L_<sub>n</sub>(_x_) | [Laguerre polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/laguerre) | 
| `legendre(n, x)` | _P_<sub>n</sub>(_x_) | [Legendre polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/legendre) | 
| `assoc_laguerre(n, m, x)` | _L_<sub>n,m</sub>(_x_) | [Associated Laguerre polynomial of degree n, order m](https://en.cppreference.com/w/cpp/numeric/special_functions/assoc_laguerre) | 
| `assoc_legendre(n, m, x)` | _P_<sub>n,m</sub>(_x_) | [Associated Legendre polynomial of degree n, order m](https://en.cppreference.com/w/cpp/numeric/special_functions/assoc_legendre) | 


*Other Special Functions*

| <div style='width:180px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `beta(x, y)` |  B(_x_,_y_) | [Euler beta function (Euler Integral of the 1st kind)](https://en.cppreference.com/w/cpp/numeric/special_functions/beta) | 
| `comp_ellint_1(k)` |  _K_(_k_) |  [Complete elliptic integral of the 1st kind](https://en.cppreference.com/w/cpp/numeric/special_functions/comp_ellint_1) | 
| `comp_ellint_2(k)` |  _E_(_k_) |  [Complete elliptic integral of the 2nd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/comp_ellint_2) | 
| `comp_ellint_3(n, k)` |  _Π_(_n_,_k_) |  [Complete elliptic integral of the 3rd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/comp_ellint_3) | 
| `ellint_1(k, φ)` |  _F_(_φ_, _k_) |  [(Incomplete) elliptic integral of the 1st kind](https://en.cppreference.com/w/cpp/numeric/special_functions/ellint_1) | 
| `ellint_2(k, φ)` |  _E_(_φ_, _k_) |  [(Incomplete) elliptic integral of the 2nd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/ellint_2) | 
| `ellint_3(k, n, φ)` |  _Π_(_n_; _φ_, _k_) |  [(Incomplete) elliptic integral of the 3rd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/ellint_3) | 
| `expint(x)` |  Ei(_x_) |  [Exponential Integral](https://en.cppreference.com/w/cpp/numeric/special_functions/expint) | 
| `riemann_zeta(x)` |  ζ(_x_) | [Riemann Zeta Function](https://en.cppreference.com/w/cpp/numeric/special_functions/riemann_zeta) | 
| `sph_legendre(l, m, θ)` | _Y_<sub>_l_</sub><sup>_m_</sup></sub>(_θ_, _φ_=0) | [Spherical Associated Legendre function<sup>†</sup> of degree _l_, order _m_](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_legendre) | 


† This is equal to a [Spherical Harmonic](https://en.wikipedia.org/wiki/Spherical_harmonics) with _φ_=0, as the notation implies.
### Mathematical functions from the Mathématiques library, namespace `mathq`
The following are mathematical functions implemented in the Mathématiques library, namespace `mathq`

| <div style='width:180px'>function</div> | namespace | header | name | 
| :---: | :---: | :---: | :---: | 
| `sqr(x)` | x<sup>2</sup> | 
| `cube(x)` | x<sup>3</sup> | 



<br>

## More on types
### Type information
#### typeid(x)
The function [`std::typeid`](https://en.cppreference.com/w/cpp/language/typeid) returns an object of type [`std::type_info`](https://en.cppreference.com/w/cpp/types/type_info) (defined in the header `<typeinfo>`). 
This gives the type for any varable. However, the names are garbled compiler strings that are not pretty. 

Examples:

```C++
int n = 3;
typeid(n).name()  =>  i
string s = "hello";
typeid(s).name()  =>  NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
```

<br>

#### getTypeName(x)
The function `mathq::display::getTypeName` returns a string that gives the actual human-readable type name. It works for most [fundamental types](https://en.cppreference.com/w/cpp/language/types) and all classes defined in 
Examples:

```C++
int n = 3;
getTypeName(n)  =>  int
string s = "hello";
getTypeName(s)  =>  std::string
```

<br>

### Mixed-typed math and auto-promotion

C++ automatically converts number types depending on context.
This is referred to as [implicit conversion](https://en.cppreference.com/w/c/language/conversion).
For example, when adding an integer and a floating point number, the integer is first converted to a floating point type before the addition takes place.
As another example, when adding two integers (or floating point types) of different sizes, the smaller size is first converted to the larger size. This porces is referred to as _promotion_.
Examples:

```C++
short n1 = 3;
int n2 = 100;
n1 * n2  =>  int 300

float x1 = 3;
double x2 = 0.1415;
x1 + x2  =>  double 3.1415

int8_t y1 = 25;
double y2 = 0.25;
y1 / y2 + y2  =>  double 100.25
```

<br>

### Type Conversion
There are various ways to cast one type to another in C++.  
Here we demonstrate [explicit conversion](https://en.cppreference.com/w/cpp/language/explicit_cast), which has two forms for the syntax: `(type) expression` or  `type(expression)` 


Converting a floating point type to an integer:

```C++
int n1 = (int)3.14;
n1  =>  int 3
int n2 = int(3.14);
n2  =>  int 3
```
Forcing floating point division by converting the numerator to a `float`

```C++
double x = (21 + 1) / 7;
x  =>  double 3
double y = float(21 + 1) / 7;
y  =>  double 3.14286
```


| ⇦ <br />  | [Scalar Math: real, imaginary, complex, and quaternions](../README.md)<br />Real number mathematics<br /><img width=1000/> | ⇨ <br />[Complex number mathematics](../complex/README.md)   |
| ------------ | :-------------------------------: | ------------ |

