#define MATHQ_DEBUG 1

#include "mathq.h"
#include "gitmd.h"

#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>

int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;
  using namespace md;

  markdown_preamble();

  cr();
  cr();

  text("C++ supports a wide variety of real number [integer and floating point types](https://en.cppreference.com/w/cpp/language/types), operators, and functions.");
  cr();
  text("Mathématiques supplements C++ functionality with several more functions.");

  cr();
  text("Mathématiques extends all of these operators and functions to vectors, matrices, and tensors, in a element-wise fashion.");

  cr();
  cr();
  header2("Integers");
  cr();
  cr();

  header3("Signed Integers");

  text("C++ supports several different signed integer types.  The size of each depends on the CPU and compiler.  For a 64-bit CPU running Linux, they have the following number of bits:");

  cr();
  cr();
  codestart("C++");
  printf("CHAR_BIT = %d bits\n", CHAR_BIT);
  printf("CHAR_BIT*sizeof(char) = %ld bits\n", CHAR_BIT * sizeof(char));
  printf("CHAR_BIT*sizeof(short) = %ld bits\n", CHAR_BIT * sizeof(short));
  printf("CHAR_BIT*sizeof(int) = %ld bits\n", CHAR_BIT * sizeof(int));
  printf("CHAR_BIT*sizeof(long) = %ld bits\n", CHAR_BIT * sizeof(long));
  printf("CHAR_BIT*sizeof(long long) = %ld bits\n", CHAR_BIT * sizeof(long long));
  codeend();

  text("The symbol [```CHAR_BIT```](https://en.cppreference.com/w/cpp/header/climits) yields the number of bits per byte, and the C++ function [```sizeof()```](https://en.cppreference.com/w/cpp/language/sizeof) yields the size in _bytes_ of the argument, which can be a type, variable, or expression.");
  cr();
  text("The maximum and minimum for each type are given below.");

  text("| Type | Min | Max |");
  text("| :--- | :---: | :---: |");
  printf("| ```char``` | %d | %d |\n", std::numeric_limits<char>::min(), std::numeric_limits<char>::max());
  printf("| ```short``` | %d | %d |\n", std::numeric_limits<short>::min(), std::numeric_limits<short>::max());
  printf("| ```int``` | %d | %d |\n", std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
  printf("| ```long``` | %ld | %ld |\n", std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
  printf("| ```long long``` | %lld | %lld |\n", std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());

  cr();
  text("Here the C++ [```std::numeric_limits```](https://en.cppreference.com/w/cpp/types/numeric_limits) functions were used to compute the max and min.");

  vspace();
  header3("Unsigned Integers");

  text("C++ supports unsigned versions of each integer type.");

  text("The maximum and minimum for each type are given below.");

  text("| Type | Min | Max |");
  text("| :--- | :---: | :---: |");
  printf("| ```unsigned char``` | %u | %u |\n", std::numeric_limits<unsigned char>::min(), std::numeric_limits<unsigned char>::max());
  printf("| ```unsigned short``` | %u | %u |\n", std::numeric_limits<unsigned short>::min(), std::numeric_limits<unsigned short>::max());
  printf("| ```unsigned int``` | %u | %u |\n", std::numeric_limits<unsigned int>::min(), std::numeric_limits<unsigned int>::max());
  printf("| ```unsigned long``` | %lu | %lu |\n", std::numeric_limits<unsigned long>::min(), std::numeric_limits<unsigned long>::max());
  printf("| ```unsigned long long``` | %llu | %llu |\n", std::numeric_limits<unsigned long long>::min(), std::numeric_limits<unsigned long long>::max());

  vspace();
  header3("Indexing Types");

  text("The type [```size_t```](https://en.cppreference.com/w/c/types/size_t) is the _unsigned_ integer type that is the best type to use for array indexing and loop counting because it size_t can store the maximum size of a theoretically possible object of any type (including array)");
  text("It's size depends on implementation.  The 64-bit Linux size is shown below:");

  cr();
  cr();
  codestart("C++");
  printf("CHAR_SIZE*sizeof(size_t) = %ld bits\n", sizeof(size_t));
  codeend();
  cr();

  vspace();
  header3("Fixed width integer types");

  text("C++11 introduced new types, called [fixed interger types](https://en.cppreference.com/w/cpp/types/integer), that allow you to directly specify the number of bits:");

  text("| type | signed / unsigned | bits |");
  text("| :--- | :---: | :---: |");
  text("| int8_t | signed | 8 bits |");
  text("| int16_t | signed | 8 bits |");
  text("| int32_t | signed | 16 bits |");
  text("| int64_t | signed | 32 bits |");
  text("| uint8_t | unsigned | 8 bits |");
  text("| uint16_t | unsigned | 8 bits |");
  text("| uint32_t | unsigned | 16 bits |");
  text("| uint64_t | unsigned | 32 bits |");
  cr();

  vspace();
  header3("Logic");

  text("The boolean type, [```bool```](https://en.cppreference.com/w/c/types/boolean), was introduced in C99.  A ```bool``` can take only two values, 0 or 1.");
  text("Two associated constants are defined: ```true``` and ```false```.\n");

  cr();
  codestart("C++");
  printf("CHAR_BIT*sizeof(bool) = %ld bits\n", CHAR_BIT * sizeof(bool));
  cr();
  trdisp(false);
  trdisp(true);
  codeend();

  vspace();
  header3("Bitwise Math");

  text("Bit-wise math is supported by C++, but not inherently supported by Mathématiques because the bitwise operators are overloaded for vector/matrix operations.  Of course, modification of the source could easily support bit-wise vector/matrix operations.");

  vspace();
  header2("Floating Point Numbers");

  text("On modern systems, C++ generally supports three types of floating point number:");

  cr();
  cr();
  codestart("C++");
  printf("CHAR_BIT*sizeof(float) = %ld bits\n", CHAR_BIT * sizeof(char));
  printf("CHAR_BIT*sizeof(double) = %ld bits\n", CHAR_BIT * sizeof(short));
  printf("CHAR_BIT*sizeof(long double) = %ld bits\n", CHAR_BIT * sizeof(int));
  codeend();

  text("The three types are compared below.");

  text("| type | name | bits | standard |  ```digits10``` |  ```max_digits10``` | ```epsilon()``` | ```min()``` | ```lowest()``` | ```max()``` | ");
  text("| :--- | :---: | :---: | :---:  | :---:  | :---:  | :---:  | :---:  | :---: | :---: |");
  printf("| float | Single Precision | 32 bits | [IEEE 754-2008 binary32](https://en.wikipedia.org/wiki/Single-precision_floating-point_format) |");
  printf(" %d | ", numeric_limits<float>::digits10);
  printf(" %d | ", numeric_limits<float>::max_digits10);
  printf(" %0.*g | ", numeric_limits<float>::max_digits10, numeric_limits<float>::epsilon());
  printf(" %0.*g | ", numeric_limits<float>::max_digits10, numeric_limits<float>::min());
  printf(" %0.*g | ", numeric_limits<float>::max_digits10, numeric_limits<float>::lowest());
  printf(" %0.*g | ", numeric_limits<float>::max_digits10, numeric_limits<float>::max());
  cr();
  printf("| double | Double Precision | 64 bits | [IEEE 754-2008 binary64](https://en.wikipedia.org/wiki/Double-precision_floating-point_format) |");
  printf(" %d | ", numeric_limits<double>::digits10);
  printf(" %d | ", numeric_limits<double>::max_digits10);
  printf(" %0.*g | ", numeric_limits<double>::max_digits10, numeric_limits<double>::epsilon());
  printf(" %0.*g | ", numeric_limits<double>::max_digits10, numeric_limits<double>::min());
  printf(" %0.*g | ", numeric_limits<double>::max_digits10, numeric_limits<double>::lowest());
  printf(" %0.*g | ", numeric_limits<double>::max_digits10, numeric_limits<double>::max());
  cr();
  printf("| long double | Quad Precision | 128 bits | [IEEE 754-2008 binary128](https://en.wikipedia.org/wiki/Quadruple-precision_floating-point_format) |");
  printf(" %d | ", numeric_limits<long double>::digits10);
  printf(" %d | ", numeric_limits<long double>::max_digits10);
  printf(" %0.*Lg | ", numeric_limits<long double>::max_digits10, numeric_limits<long double>::epsilon());
  printf(" %0.*Lg | ", numeric_limits<long double>::max_digits10, numeric_limits<long double>::min());
  printf(" %0.*Lg | ", numeric_limits<long double>::max_digits10, numeric_limits<long double>::lowest());
  printf(" %0.*Lg | ", numeric_limits<long double>::max_digits10, numeric_limits<long double>::max());
  cr();

  cr();
  cr();

  text("The functions ```epsilon()```, ```min()```, ```lowest()```, and  ```max()```, as well as the static values ```digits10``` and ```max_digits10``` are found in [```limits```](https://en.cppreference.com/w/cpp/types/numeric_limits)");

  text("The static value ```max_digits10``` was used as the precision for printing the above values.\n");

  vspace();
  header2("Operators and functions");

  header3("Arithmetic Operators");
  text("The operators ```+, -, *, /, %``` are the addition, subtraction, multiplication, division, and modulus operators respectively.\n");
  text("For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).\n");

  cr();
  text("| operator | operation | ");
  text("| :---: | :---: | ");
  text("| ```+``` | addition | ");
  text("| ```-``` | subtraction | ");
  text("| ```*``` | multiplication | ");
  text("| ```/``` | division | ");
  text("| ```%``` | modulus | ");
  cr();

  text("* If both numerator and denominator are integers, the division operator gives the integer division result.\n");
  codestart("C++");
  trdisp(7 / 2);
  codeend();
  text("* The modulus operator ```a % b```, gives the remainder after integer divison of ```a``` by ```b```.\n");
  codestart("C++");
  trdisp(7 % 2);
  codeend();
  text("* The function [```std::div```](https://en.cppreference.com/w/cpp/numeric/math/div) can also be used for integer division, It returns both the result and remainder.\n");

  codestart("C++");
  codemulti(div_t result = div(7, 2));
  codeend();
  text("With result:\n");
  codestart("C++");
  trdisp(result.quot);
  trdisp(result.rem);
  codeend();

  // Exponentiation and the power function
  vspace();
  header3("Exponentiation and the ```pow``` function");
  text("C++ does not have an exponentiation operator.  Instead it provides the [```std::pow```](https://en.cppreference.com/w/cpp/numeric/math/div) function");
  codestart("C++");
  trdisp(pow(2, 8));
  trdisp(pow(25, 1 / 2));
  codeend();

  vspace();
  header3("Logic Operators");
  text("For details refer [Logical Operators](https://en.cppreference.com/w/c/language/operator_logical).\n");

  cr();
  text("| operator | operation | ");
  text("| :---: | :---: | ");
  text("| ```!``` | logical NOT | ");
  text("| `\\|\\|` | logical OR | ");
  text("| ```&&``` | logical AND | ");
  cr();

  text("Examples:\n");
  codestart("C++");
  trdisp(true);
  trdisp(false);
  trdisp(!true);
  trdisp(!false);
  trdisp(true && true);
  trdisp(true && false);
  trdisp(true || false);
  codeend();

  text("* In C++ logical operators work for all real and integer types: `0` corresponds to `false` and all non-zero values correspond to `true`\n");
  codestart("C++");
  trdisp(!true);
  trdisp(!8);
  trdisp(!!8.293);
  trdisp(true && 3);
  trdisp(true && 0);
  codeend();

  vspace();
  header3("Relational Operators");

  text("For details refer [Comparison Operators](https://en.cppreference.com/w/c/language/operator_comparison).\n");

  cr();
  text("| operator | operation | ");
  text("| :---: | :---: | ");
  text("| `==` | equal to | ");
  text("| `!=` | not equal to | ");
  text("| `<` | less than | ");
  text("| `<=` | less than or equal to | ");
  text("| `>` | greater than | ");
  text("| `>=` | greater than or equal to | ");
  // text("| `<=>` | three-way comparison | ");
  cr();

  text("Examples:\n");
  codestart("C++");
  trdisp((2 == 2));
  trdisp((1 / 2 == 0.5));
  trdisp((1. / 2 == 0.5));
  trdisp((-2 < 34.2));
  trdisp((2 > 0));
  codeend();

  vspace();
  header3("Mathematical functions from the C++ ``std`` library");

  header4("C++ ``std`` library common functions");

  cr();
  text("The following are [common mathematical functions](https://en.cppreference.com/w/cpp/numeric/math) implemented in the C++ `std` library");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `abs(x)` | [absolute value](https://en.cppreference.com/w/cpp/numeric/math/abs) | ");
  text("| `ceil(x)` | [ceiling function](https://en.cppreference.com/w/cpp/numeric/math/ceil) | ");
  text("| `floor(x)` | [floor function](https://en.cppreference.com/w/cpp/numeric/math/floor) | ");
  text("| `trunc(x)` | [truncate function](https://en.cppreference.com/w/cpp/numeric/math/trunc) | ");
  text("| `round(x)` | [round function](https://en.cppreference.com/w/cpp/numeric/math/round) | ");
  cr();
  cr();

  text("*Trig Functions*");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `sin(x)` | [sine](https://en.cppreference.com/w/cpp/numeric/math/sin) | ");
  text("| `cos(x)` | [cosine](https://en.cppreference.com/w/cpp/numeric/math/cos) | ");
  text("| `tan(x)` | [tangent](https://en.cppreference.com/w/cpp/numeric/math/tan) | ");
  cr();
  cr();

  text("*Inverse Trig Functions*");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `asin(x)` | [arc sine](https://en.cppreference.com/w/cpp/numeric/math/asin) | ");
  text("| `acos(x)` | [arc cosine](https://en.cppreference.com/w/cpp/numeric/math/acos) | ");
  text("| `atan(x)` | [arc tangent: all results are mapped into -𝜋/2 <= 𝜃 <= +𝜋/2](https://en.cppreference.com/w/cpp/numeric/math/atan) | ");
  text("| `atan2(b, a)` | [arc tangent of b/a with full quadrant angles, 0 <= 𝜃 < +2𝜋](https://en.cppreference.com/w/cpp/numeric/math/atan2) | ");
  cr();
  cr();

  text("*Hyperbolic Trig Functions*");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `sinh(x)` | [Hyperbolic sine](https://en.cppreference.com/w/cpp/numeric/math/sinh) | ");
  text("| `cosh(x)` | [Hyperbolic cosine](https://en.cppreference.com/w/cpp/numeric/math/cosh) | ");
  text("| `tanh(x)` | [Hyperbolic tangent](https://en.cppreference.com/w/cpp/numeric/math/tanh) | ");
  cr();
  cr();

  text("*Inverse Hyperbolic Trig Functions*");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `asinh(x)` | [Hyperbolic arc sine](https://en.cppreference.com/w/cpp/numeric/math/asinh) | ");
  text("| `acosh(x)` | [Hyperbolic arc cosine](https://en.cppreference.com/w/cpp/numeric/math/acosh) | ");
  text("| `atanh(x)` | [Hyperbolic arc tangent](https://en.cppreference.com/w/cpp/numeric/math/atanh) | ");

  cr();
  cr();

  text("*Exponentiation*");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `pow(x, y)` | [x<sup>y</sup>](https://en.cppreference.com/w/cpp/numeric/math/pow) | ");
  text("| `sqrt(x)` | [Square Root](https://en.cppreference.com/w/cpp/numeric/math/sqrt) | ");
  text("| `cqrt(x)` | [Cube Root](https://en.cppreference.com/w/cpp/numeric/math/cqrt) | ");

  cr();
  cr();

  text("*Exponentials*");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `exp(x)` | [e<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/math/exp) | ");
  text("| `exp2(x)` | [2<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/math/exp2) | ");
  text("| `expm1(x)` | [e<sup>x</sup> - 1](https://en.cppreference.com/w/cpp/numeric/math/expm1) | ");
  cr();
  cr();

  text("*Logarithms*");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `log(x)` | [Natural Logarithm, ln(x) = log<sub>e</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log) | ");
  text("| `log10(x)` | [base 10 logarithm, log<sub>10</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log10) | ");
  text("| `log2(x)` | [base 2 logarithm, log<sub>2</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log2) | ");
  text("| `log1p(x)` | [ln(x + 1)](https://en.cppreference.com/w/cpp/numeric/math/log1p) | ");
  text("| `logb(x)` | [extracts exponent of the number and returns a floating point type](https://en.cppreference.com/w/cpp/numeric/math/logb) | ");
  text("| `ilogb(x)` | [extracts exponent of the number and returns an integral type](https://en.cppreference.com/w/cpp/numeric/math/ilogb) | ");

  cr();
  cr();

  text("*Other Functions*");
  cr();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `erf(x)` | [error function, erf(x)](https://en.cppreference.com/w/cpp/numeric/math/erf) | ");
  text("| `erfc(x)` | [complimentary error function, erfc(x)](https://en.cppreference.com/w/cpp/numeric/math/erfc) | ");
  text("| `tgamma(x)` | [Gamma Function, Γ(x)](https://en.cppreference.com/w/cpp/numeric/math/tgamma) | ");
  text("| `lgamma(x)` | [Natural Logarithm of the Gamma Function, ln(Γ(x))](https://en.cppreference.com/w/cpp/numeric/math/lgamma) | ");
  cr();
  cr();

  header4("C++ ``std`` library special functions");

  text("The following [special mathematical functions](https://en.cppreference.com/w/cpp/numeric/special_functions) implemented in the C++ `std` library");
  cr();

  text("*Bessel Functions*");
  cr();
  text("| <div style='width:180px'>function</div> | symbol | name | ");
  text("| :---: | :---: |  :---: |");
  text("| `cyl_bessel_j(𝜈, x)` | _J_<sub>𝜈</sub>(_x_) | [Bessel function of the 1st kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_j) | ");
  text("| `cyl_neumann(𝜈, x)` | _Y_<sub>𝜈</sub>(_x_) | [Bessel (aka Neumann or Weber) function of the 2nd kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_neumann) | ");
  text("| `cyl_bessel_i(𝜈, x)` | _I_<sub>𝜈</sub>(_x_) | [Modified Bessel function of the 1st kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_i) | ");
  text("| `cyl_bessel_k(𝜈, x)` | _K_<sub>𝜈</sub>(_x_) | [Modified Bessel function of the 2nd kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_k) | ");

  cr();
  cr();
  text("*Spherical Bessel Functions*");
  cr();
  text("| <div style='width:180px'>function</div> | symbol | name | ");
  text("| :---: | :---: |  :---: |");
  text("| `sph_bessel(n, x)` | _j_<sub>n</sub>(_x_) | [Spherical Bessel function of the 1st kind of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_bessel) | ");
  text("| `sph_neumann(n, x)` | _y_<sub>n</sub>(_x_) | [Spherical Bessel (aka Neumann or Weber) function of the 2nd kind of degree n, aka Spherical Neumann function](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_neumann) | ");
  cr();
  cr();

  text("*Orthogonal Polynomials*");
  cr();
  text("| <div style='width:180px'>function</div>  | symbol | name | ");
  text("| :---: | :---: |  :---: |");
  text("| `hermite(n, x)` | _H_<sub>n</sub>(_x_) | [Hermite polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/hermite) | ");
  text("| `laguerre(n, x)` | _L_<sub>n</sub>(_x_) | [Laguerre polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/laguerre) | ");
  text("| `legendre(n, x)` | _P_<sub>n</sub>(_x_) | [Legendre polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/legendre) | ");
  text("| `assoc_laguerre(n, m, x)` | _L_<sub>n,m</sub>(_x_) | [Associated Laguerre polynomial of degree n, order m](https://en.cppreference.com/w/cpp/numeric/special_functions/assoc_laguerre) | ");
  text("| `assoc_legendre(n, m, x)` | _P_<sub>n,m</sub>(_x_) | [Associated Legendre polynomial of degree n, order m](https://en.cppreference.com/w/cpp/numeric/special_functions/assoc_legendre) | ");
  cr();
  cr();

  text("*Other Special Functions*");
  cr();
  text("| <div style='width:180px'>function</div> | symbol | name | ");
  text("| :---: | :---: |  :---: |");
  text("| `beta(x, y)` |  B(_x_,_y_) | [Euler beta function (Euler Integral of the 1st kind)](https://en.cppreference.com/w/cpp/numeric/special_functions/beta) | ");
  text("| `comp_ellint_1(k)` |  _K_(_k_) |  [Complete elliptic integral of the 1st kind](https://en.cppreference.com/w/cpp/numeric/special_functions/comp_ellint_1) | ");
  text("| `comp_ellint_2(k)` |  _E_(_k_) |  [Complete elliptic integral of the 2nd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/comp_ellint_2) | ");
  text("| `comp_ellint_3(n, k)` |  _Π_(_n_,_k_) |  [Complete elliptic integral of the 3rd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/comp_ellint_3) | ");
  text("| `ellint_1(k, φ)` |  _F_(_φ_, _k_) |  [(Incomplete) elliptic integral of the 1st kind](https://en.cppreference.com/w/cpp/numeric/special_functions/ellint_1) | ");
  text("| `ellint_2(k, φ)` |  _E_(_φ_, _k_) |  [(Incomplete) elliptic integral of the 2nd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/ellint_2) | ");
  text("| `ellint_3(k, n, φ)` |  _Π_(_n_; _φ_, _k_) |  [(Incomplete) elliptic integral of the 3rd kind](https://en.cppreference.com/w/cpp/numeric/special_functions/ellint_3) | ");
  text("| `expint(x)` |  Ei(_x_) |  [Exponential Integral](https://en.cppreference.com/w/cpp/numeric/special_functions/expint) | ");
  text("| `riemann_zeta(x)` |  ζ(_x_) | [Riemann Zeta Function](https://en.cppreference.com/w/cpp/numeric/special_functions/riemann_zeta) | ");
  text("| `sph_legendre(l, m, θ)` | _Y_<sub>_l_</sub><sup>_m_</sup></sub>(_θ_, _φ_=0) | [Spherical Associated Legendre function<sup>†</sup> of degree _l_, order _m_](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_legendre) | ");
  cr();
  cr();
  text("† This is equal to a [Spherical Harmonic](https://en.wikipedia.org/wiki/Spherical_harmonics) with _φ_=0, as the notation implies.");

  header3("Mathematical functions from the Mathématiques library, namespace `mathq`");

  text("The following are mathematical functions implemented in the Mathématiques library, namespace `mathq`");
  cr();
  text("| function | description | ");
  text("| :---: | :---: | ");
  text("| `sgn(x)` | [signum function](https://en.wikipedia.org/wiki/Sign_function), return type has same type as x | ");
  text("| `zero(x)` | return a zero with the same type as x | ");
  text("| `sqr(x)` | x<sup>2</sup> | ");
  text("| `cube(x)` | x<sup>3</sup> | ");
  cr();
  cr();

  vspace();
  header2("More on types");

  header3("Type information");

  header4("typeid(x)");

  text("The function [`std::typeid`](https://en.cppreference.com/w/cpp/language/typeid) returns an object of type [`std::type_info`](https://en.cppreference.com/w/cpp/types/type_info) (defined in the header `<typeinfo>`). ");
  text("This gives the type for any varable. However, the names are garbled compiler strings that are not pretty. ");
  cr();

  {
    text("Examples:\n");
    codestart("C++");
    codemulti(int n = 3);
    disp(typeid(n).name());
    // text("typeid(n).name() -> \"i\"");
    codemulti(string s = "hello");
    disp(typeid(s).name());
    // text("typeid(s).name() -> \"NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE\"");
    codeend();
  }

  vspace();
  header4("getTypeName(x)");
  text("The function `mathq::display::getTypeName` returns a string that gives the actual human-readable type name. It works for most [fundamental types](https://en.cppreference.com/w/cpp/language/types) and all classes defined in ");
  {
    text("Examples:\n");
    codestart("C++");
    codemulti(int n = 3);
    disp(getTypeName(n));
    // text("getTypeName(n) -> \"int\"");
    codemulti(string s = "hello");
    disp(getTypeName(s));
    // text("getTypeName(s) -> \"std::string\"");
    codeend();
  }
  vspace();
  header3("Mixed-typed math and auto-promotion");
  cr();
  text("C++ automatically converts number types depending on context.");
  text("This is referred to as [implicit conversion](https://en.cppreference.com/w/c/language/conversion).");
  text("For example, when adding an integer and a floating point number, the integer is first converted to a floating point type before the addition takes place.");
  text("As another example, when adding two integers (or floating point types) of different sizes, the smaller size is first converted to the larger size. This porces is referred to as _promotion_.");

  {
    text("Examples:\n");
    codestart("C++");
    codemulti(short n1 = 3);
    codemulti(int n2 = 100);
    trdisp(n1 * n2);
    // text("n1 * n2 -> int 300");
    cr();
    codemulti(float x1 = 3);
    codemulti(double x2 = 0.1415);
    trdisp(x1 + x2);
    // text("x1 + x2 -> double 3.1415");
    cr();
    codemulti(int8_t y1 = 25);
    codemulti(double y2 = 0.25);
    trdisp(y1 / y2 + y2);
    // text("y1 / y2 + y2 -> double 100.25");
    codeend();
  }

  vspace();
  header3("Type Conversion");
  text("There are various ways to cast one type to another in C++.  ");
  text("Here we demonstrate [explicit conversion](https://en.cppreference.com/w/cpp/language/explicit_cast), which has two forms for the syntax: `(type) expression` or  `type(expression)` ");
  cr();
  cr();

  {
    text("Converting a floating point type to an integer:\n");
    codestart("C++");
    codemulti(int n1 = (int)3.14);
    trdisp(n1);
    // text("n1 -> 3");
    codemulti(int n2 = int(3.14));
    trdisp(n2);
    // text("n2 -> 3");
    codeend();
  }

  {
    text("Forcing floating point division by converting the numerator to a `float`\n");
    codestart("C++");
    codemulti(double x = (21 + 1) / 7);
    trdisp(x);
    // text("x -> 3");
    codemulti(double y = float(21 + 1) / 7);
    trdisp(y);
    // text("y -> 3.14286");
    codeend();
  }

  return 0;
}
