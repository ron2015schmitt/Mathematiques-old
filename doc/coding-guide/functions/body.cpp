#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>

#define MATHQ_DEBUG 1
#include "mathq.h"

int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;
  

  markdown_preamble();

  CR();
  CR();

  text("C++ supports a wide variety of mathematical functions.");
  CR();
  text("Mathématiques supplements C++ functionality with several more functions.");

  CR();
  text("Mathématiques extends many of these functions to complex numbers, imaginary numbers, and quaterions, as well as extending to vectors, matrices, and tensors in a element-wise fashion.");


  CR();
  text("The following are basic mathematical functions for manipulating numbers.");
  CR();
  text("| function | namespace | header | name | ");
  text("| :---: | :---: | :---: | :---: | ");
  text("| `abs(x)` | `std` | `<cmath>` | [absolute value](https://en.cppreference.com/w/cpp/numeric/math/abs) | ");
  text("| `abs(u)` | `mathq` | `\"mathq.h\"` | **mathq** abs  | ");
  text("| `ceil(x)` | `std` | `<cmath>` | [ceiling function](https://en.cppreference.com/w/cpp/numeric/math/ceil) | ");
  text("| `ceil(u)` | `mathq` | `\"mathq.h\"` | **mathq** ceiling | ");
  text("| `floor(x)` | `std` | `<cmath>` | [floor function](https://en.cppreference.com/w/cpp/numeric/math/floor) | ");
  text("| `floor(u)` | `mathq` | `\"mathq.h\"` | **mathq** floor | ");
  text("| `one(u)` | `mathq` | `\"mathq.h\"` | return a one with the same type as x | ");
  text("| `trunc(x)` | `std` | `<cmath>` | [truncate function](https://en.cppreference.com/w/cpp/numeric/math/trunc) | ");
  text("| `trunc(u)` | `mathq` | `\"mathq.h\"` | **mathq** truncate | ");
  text("| `round(x)` | `std` | `<cmath>` | [round function](https://en.cppreference.com/w/cpp/numeric/math/round) | ");
  text("| `round(u)` | `mathq` | `\"mathq.h\"` | **mathq** round function | ");
  text("| `roundzero(u, tolerance = Helper<X>::tolerance)` | `mathq` | `\"mathq.h\"` | round numbers with magnitude less than `tolerance` to 0. The default values are shown below. | ");
  text("| `sgn(u)` | `mathq` | `\"mathq.h\"` | [signum function](https://en.wikipedia.org/wiki/Sign_function), return type has same type as x | ");
  text("| `zero(u)` | `mathq` | `\"mathq.h\"` | return a zero with the same type as x | ");
  CR();
  CR();

  text("Notes:");
  text("The default `zero_tolerance` values are global variables and can be changed by the user code.");
  text("The default values were chosen so that the typical numerical error encountered with trig functions will produce exactly zero when appropriate.");
  CR();
  codestart("C++");
  disp(Helper<float>::tolerance);
  disp(Helper<double>::tolerance);
  disp(Helper<long double>::tolerance);
  codeend();
  CR();

  CR();
  vspace();

  CR();
  text("The following functions / operators are provided for using real number types with imaginary and complex types.");
  CR();
  text("| function | namespace | header | name | ");
  text("| :---: | :---: | :---: | :---: | ");
  text("| `real(x)` | `mathq` | `\"mathq.h\"` | returns x | ");
  text("| `imag(x)` | `mathq` | `\"mathq.h\"` | returns `zero(x)` | ");
  text("| `conj(x)` | `mathq` | `\"mathq.h\"` | returns x | ");
  text("| `~x` | `mathq` | `\"mathq.h\"` | returns x | ");
  CR();
  CR();

  text("*Trig Functions*");
  CR();
  text("| function | namespace | header | name | ");
  text("| :---: | :---: | :---: | :---: | ");
  text("| `sin(x)` | [sine](https://en.cppreference.com/w/cpp/numeric/math/sin) | ");
  text("| `cos(x)` | [cosine](https://en.cppreference.com/w/cpp/numeric/math/cos) | ");
  text("| `tan(x)` | [tangent](https://en.cppreference.com/w/cpp/numeric/math/tan) | ");
  CR();
  CR();

  text("*Inverse Trig Functions*");
  CR();
  text("| function | namespace | header | name | ");
  text("| :---: | :---: | :---: | :---: | ");
  text("| `asin(x)` | [arc sine](https://en.cppreference.com/w/cpp/numeric/math/asin) | ");
  text("| `acos(x)` | [arc cosine](https://en.cppreference.com/w/cpp/numeric/math/acos) | ");
  text("| `atan(x)` | [arc tangent: all results are mapped into -𝜋/2 <= 𝜃 <= +𝜋/2](https://en.cppreference.com/w/cpp/numeric/math/atan) | ");
  text("| `atan2(b, a)` | [arc tangent of b/a with full quadrant angles, 0 <= 𝜃 < +2𝜋](https://en.cppreference.com/w/cpp/numeric/math/atan2) | ");
  CR();
  CR();

  text("*Hyperbolic Trig Functions*");
  CR();
  text("| function | namespace | header | name | ");
  text("| :---: | :---: | :---: | :---: | ");
  text("| `sinh(x)` | [Hyperbolic sine](https://en.cppreference.com/w/cpp/numeric/math/sinh) | ");
  text("| `cosh(x)` | [Hyperbolic cosine](https://en.cppreference.com/w/cpp/numeric/math/cosh) | ");
  text("| `tanh(x)` | [Hyperbolic tangent](https://en.cppreference.com/w/cpp/numeric/math/tanh) | ");
  CR();
  CR();

  text("*Inverse Hyperbolic Trig Functions*");
  CR();
  text("| function | namespace | header | name | ");
  text("| :---: | :---: | :---: | :---: | ");
  text("| `asinh(x)` | [Hyperbolic arc sine](https://en.cppreference.com/w/cpp/numeric/math/asinh) | ");
  text("| `acosh(x)` | [Hyperbolic arc cosine](https://en.cppreference.com/w/cpp/numeric/math/acosh) | ");
  text("| `atanh(x)` | [Hyperbolic arc tangent](https://en.cppreference.com/w/cpp/numeric/math/atanh) | ");

  CR();
  CR();

  text("*Exponentiation*");
  CR();
  text("| function | namespace | header | name | ");
  text("| :---: | :---: | :---: | :---: | ");
  text("| `pow(x, y)` | [x<sup>y</sup>](https://en.cppreference.com/w/cpp/numeric/math/pow) | ");
  text("| `sqrt(x)` | [Square Root](https://en.cppreference.com/w/cpp/numeric/math/sqrt) | ");
  text("| `cqrt(x)` | [Cube Root](https://en.cppreference.com/w/cpp/numeric/math/cqrt) | ");

  CR();
  CR();

  text("*Exponentials*");
  CR();
  text("| function | namespace | header | name | ");
  text("| :---: | :---: | :---: | :---: | ");
  text("| `exp(x)` | [e<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/math/exp) | ");
  text("| `exp2(x)` | [2<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/math/exp2) | ");
  text("| `expm1(x)` | [e<sup>x</sup> - 1](https://en.cppreference.com/w/cpp/numeric/math/expm1) | ");
  CR();
  CR();

  text("*Logarithms*");
  CR();
  text("| function | namespace | header | name | ");
  text("| :---: | :---: | :---: | :---: | ");
  text("| `log(x)` | [Natural Logarithm, ln(x) = log<sub>e</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log) | ");
  text("| `log10(x)` | [base 10 logarithm, log<sub>10</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log10) | ");
  text("| `log2(x)` | [base 2 logarithm, log<sub>2</sub>(x)](https://en.cppreference.com/w/cpp/numeric/math/log2) | ");
  text("| `log1p(x)` | [ln(x + 1)](https://en.cppreference.com/w/cpp/numeric/math/log1p) | ");
  text("| `logb(x)` | [extracts exponent of the number and returns a floating point type](https://en.cppreference.com/w/cpp/numeric/math/logb) | ");
  text("| `ilogb(x)` | [extracts exponent of the number and returns an integral type](https://en.cppreference.com/w/cpp/numeric/math/ilogb) | ");

  CR();
  CR();

  text("*Other Functions*");
  CR();
  text("| function | namespace | header | name | ");
  text("| :---: | :---: | :---: | :---: | ");
  text("| `erf(x)` | [error function, erf(x)](https://en.cppreference.com/w/cpp/numeric/math/erf) | ");
  text("| `erfc(x)` | [complimentary error function, erfc(x)](https://en.cppreference.com/w/cpp/numeric/math/erfc) | ");
  text("| `tgamma(x)` | [Gamma Function, Γ(x)](https://en.cppreference.com/w/cpp/numeric/math/tgamma) | ");
  text("| `lgamma(x)` | [Natural Logarithm of the Gamma Function, ln(Γ(x))](https://en.cppreference.com/w/cpp/numeric/math/lgamma) | ");
  CR();
  CR();

  header4("C++ ``std`` library special functions");

  text("The following [special mathematical functions](https://en.cppreference.com/w/cpp/numeric/special_functions) implemented in the C++ `std` library");
  CR();

  text("*Bessel Functions*");
  CR();
  text("| <div style='width:180px'>function</div> | namespace | header | name | ");
  text("| :---: | :---: | :---: | :---: | ");
  text("| `cyl_bessel_j(𝜈, x)` | _J_<sub>𝜈</sub>(_x_) | [Bessel function of the 1st kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_j) | ");
  text("| `cyl_neumann(𝜈, x)` | _Y_<sub>𝜈</sub>(_x_) | [Bessel (aka Neumann or Weber) function of the 2nd kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_neumann) | ");
  text("| `cyl_bessel_i(𝜈, x)` | _I_<sub>𝜈</sub>(_x_) | [Modified Bessel function of the 1st kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_i) | ");
  text("| `cyl_bessel_k(𝜈, x)` | _K_<sub>𝜈</sub>(_x_) | [Modified Bessel function of the 2nd kind of degree 𝜈](https://en.cppreference.com/w/cpp/numeric/special_functions/cyl_bessel_k) | ");

  CR();
  CR();
  text("*Spherical Bessel Functions*");
  CR();
  text("| <div style='width:180px'>function</div> | namespace | header | name | ");
  text("| :---: | :---: | :---: | :---: | ");
  text("| `sph_bessel(n, x)` | _j_<sub>n</sub>(_x_) | [Spherical Bessel function of the 1st kind of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_bessel) | ");
  text("| `sph_neumann(n, x)` | _y_<sub>n</sub>(_x_) | [Spherical Bessel (aka Neumann or Weber) function of the 2nd kind of degree n, aka Spherical Neumann function](https://en.cppreference.com/w/cpp/numeric/special_functions/sph_neumann) | ");
  CR();
  CR();

  text("*Orthogonal Polynomials*");
  CR();
  text("| <div style='width:180px'>function</div> | namespace | header | name | ");
  text("| :---: | :---: | :---: | :---: | ");
  text("| `hermite(n, x)` | _H_<sub>n</sub>(_x_) | [Hermite polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/hermite) | ");
  text("| `laguerre(n, x)` | _L_<sub>n</sub>(_x_) | [Laguerre polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/laguerre) | ");
  text("| `legendre(n, x)` | _P_<sub>n</sub>(_x_) | [Legendre polynomial of degree n](https://en.cppreference.com/w/cpp/numeric/special_functions/legendre) | ");
  text("| `assoc_laguerre(n, m, x)` | _L_<sub>n,m</sub>(_x_) | [Associated Laguerre polynomial of degree n, order m](https://en.cppreference.com/w/cpp/numeric/special_functions/assoc_laguerre) | ");
  text("| `assoc_legendre(n, m, x)` | _P_<sub>n,m</sub>(_x_) | [Associated Legendre polynomial of degree n, order m](https://en.cppreference.com/w/cpp/numeric/special_functions/assoc_legendre) | ");
  CR();
  CR();

  text("*Other Special Functions*");
  CR();
  text("| <div style='width:180px'>function</div> | namespace | header | name | ");
  text("| :---: | :---: | :---: | :---: | ");
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
  CR();
  CR();
  text("† This is equal to a [Spherical Harmonic](https://en.wikipedia.org/wiki/Spherical_harmonics) with _φ_=0, as the notation implies.");

  header3("Mathematical functions from the Mathématiques library, namespace `mathq`");

  text("The following are mathematical functions implemented in the Mathématiques library, namespace `mathq`");
  CR();
  text("| <div style='width:180px'>function</div> | namespace | header | name | ");
  text("| :---: | :---: | :---: | :---: | ");
  text("| `sqr(x)` | x<sup>2</sup> | ");
  text("| `cube(x)` | x<sup>3</sup> | ");
  CR();
  CR();

  vspace();
  header2("More on types");

  header3("Type information");

  header4("typeid(x)");

  text("The function [`std::typeid`](https://en.cppreference.com/w/cpp/language/typeid) returns an object of type [`std::type_info`](https://en.cppreference.com/w/cpp/types/type_info) (defined in the header `<typeinfo>`). ");
  text("This gives the type for any varable. However, the names are garbled compiler strings that are not pretty. ");
  CR();

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
  CR();
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
    CR();
    codemulti(float x1 = 3);
    codemulti(double x2 = 0.1415);
    trdisp(x1 + x2);
    // text("x1 + x2 -> double 3.1415");
    CR();
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
  CR();
  CR();

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
