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
  

  CR();
  CR();

  GMD_HEADER2("Introduction");

  OUTPUT("\n<br>\n");
  GMD_HEADER2("Size of complex numbers");

  OUTPUT("The size of a complex number is simply _twice_ the size of the underlying arithmetic type:");

  CR();
  CR();
  GMD_CODE_START("C++");
  printf("CHAR_BIT = %d bits\n", CHAR_BIT);
  CR();
  printf("CHAR_BIT*sizeof(int) = %ld bits\n", CHAR_BIT * sizeof(int));
  printf("CHAR_BIT*sizeof(complex<int>) = %ld bits\n", CHAR_BIT * sizeof(complex<int>));
  CR();
  printf("CHAR_BIT*sizeof(double) = %ld bits\n", CHAR_BIT * sizeof(double));
  printf("CHAR_BIT*sizeof(complex<double>) = %ld bits\n", CHAR_BIT * sizeof(complex<double>));
  CR();
  printf("CHAR_BIT*sizeof(long double) = %ld bits\n", CHAR_BIT * sizeof(long double));
  printf("CHAR_BIT*sizeof(complex<long double>) = %ld bits\n", CHAR_BIT * sizeof(complex<long double>));
  CR();
  GMD_CODE_END();

  OUTPUT("The symbol [```CHAR_BIT```](https://en.cppreference.com/w/cpp/header/climits) yields the number of bits per byte, and the C++ function [```sizeof()```](https://en.cppreference.com/w/cpp/language/sizeof) yields the size in _bytes_ of the argument, which can be a type, variable, or expression.");
  CR();
  OUTPUT("\n<br>\n");
  GMD_HEADER2("Operators and functions");

  GMD_HEADER3("Arithmetic Operators");
  OUTPUT("Complex numbers in C++ support the 4 standard arithmetic operators.\n");
  OUTPUT("For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).\n");

  CR();
  OUTPUT("| operator | operation | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| ```+``` | addition | ");
  OUTPUT("| ```-``` | subtraction | ");
  OUTPUT("| ```*``` | multiplication | ");
  OUTPUT("| ```/``` | division | ");
  CR();

  GMD_CODE_START("C++");
  DISP(complex(1.0, 1.0) + complex(2.0, 4.0));
  DISP(complex(1.0, 1.0) - complex(2.0, 4.0));
  DISP(complex(1.0, 1.0) * complex(2.0, 4.0));
  DISP(complex(1.0, 1.0) / complex(2.0, 4.0));
  GMD_CODE_END();


  // Exponentiation and the power function
  OUTPUT("\n<br>\n");
  GMD_HEADER3("Exponentiation and the ```pow``` function");
  OUTPUT("C++ does not have an exponentiation operator.  Instead it provides the [```std::pow```](https://en.cppreference.com/w/cpp/numeric/complex/div) function");

  GMD_CODE_START("C++");
  DISP(pow(complex(1.0, 1.0), complex(2.0, 4.0)));
  GMD_CODE_END();

  OUTPUT("\n<br>\n");
  GMD_HEADER3("Relational Operators");

  OUTPUT("Complex numbers are not an ordered set.  Therefore, there is no concept of greater than or less than.\n");
  OUTPUT("For details refer [Comparison Operators](https://en.cppreference.com/w/c/language/operator_comparison).\n");

  CR();
  OUTPUT("| operator | operation | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `==` | equal to | ");
  OUTPUT("| `!=` | not equal to | ");
  CR();

  OUTPUT("Examples:\n");
  GMD_CODE_START("C++");
  CR();
  DISP(complex(1.0, 1.0) == complex(1.0, 1.0));
  DISP(complex(1.0, 1.0) != complex(1.0, 1.0));
  CR();
  DISP(complex(1.0, 1.0) == complex(2.0, 4.0));
  DISP(complex(1.0, 1.0) != complex(2.0, 4.0));
  GMD_CODE_END();

  OUTPUT("\n<br>\n");
  GMD_HEADER3("Mathematical functions from the C++ [``std::complex`` header](https://en.cppreference.com/w/cpp/numeric/complex)");

  GMD_HEADER4("C++ ``std`` library common functions");

  CR();
  OUTPUT("The following are [common mathematical functions](https://en.cppreference.com/w/cpp/numeric/math) implemented in the C++ `std` library");
  CR();
  OUTPUT("| function | name | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `abs` | [absolute value](https://en.cppreference.com/w/cpp/numeric/complex/abs) | ");
  OUTPUT("| `ceil` | [ceiling function](https://en.cppreference.com/w/cpp/numeric/complex/ceil) | ");
  OUTPUT("| `floor` | [floor function](https://en.cppreference.com/w/cpp/numeric/complex/floor) | ");
  OUTPUT("| `trunc` | [truncate function](https://en.cppreference.com/w/cpp/numeric/complex/trunc) | ");
  OUTPUT("| `round` | [round function](https://en.cppreference.com/w/cpp/numeric/complex/round) | ");
  CR();
  CR();

  OUTPUT("*Trig Functions*");
  CR();
  OUTPUT("| function | name | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `sin` | [sine](https://en.cppreference.com/w/cpp/numeric/complex/sin) | ");
  OUTPUT("| `cos` | [cosine](https://en.cppreference.com/w/cpp/numeric/complex/cos) | ");
  OUTPUT("| `tan` | [tangent](https://en.cppreference.com/w/cpp/numeric/complex/tan) | ");
  CR();
  CR();

  OUTPUT("*Inverse Trig Functions*");
  CR();
  OUTPUT("| function | name | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `asin` | [arc sine](https://en.cppreference.com/w/cpp/numeric/complex/asin) | ");
  OUTPUT("| `acos` | [arc cosine](https://en.cppreference.com/w/cpp/numeric/complex/acos) | ");
  OUTPUT("| `atan` | [arc tangent](https://en.cppreference.com/w/cpp/numeric/complex/atan) | ");
  CR();
  CR();

  OUTPUT("*Hyperbolic Trig Functions*");
  CR();
  OUTPUT("| function | name | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `sinh` | [Hyperbolic sine](https://en.cppreference.com/w/cpp/numeric/complex/sinh) | ");
  OUTPUT("| `cosh` | [Hyperbolic cosine](https://en.cppreference.com/w/cpp/numeric/complex/cosh) | ");
  OUTPUT("| `tanh` | [Hyperbolic tangent](https://en.cppreference.com/w/cpp/numeric/complex/tanh) | ");
  CR();
  CR();

  OUTPUT("*Inverse Hyperbolic Trig Functions*");
  CR();
  OUTPUT("| function | name | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `asinh` | [Hyperbolic arc sine](https://en.cppreference.com/w/cpp/numeric/complex/asinh) | ");
  OUTPUT("| `acosh` | [Hyperbolic arc cosine](https://en.cppreference.com/w/cpp/numeric/complex/acosh) | ");
  OUTPUT("| `atanh` | [Hyperbolic arc tangent](https://en.cppreference.com/w/cpp/numeric/complex/atanh) | ");

  CR();
  CR();

  OUTPUT("*Exponentiation*");
  CR();
  OUTPUT("| function | name | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `pow(x, y)` | [x<sup>y</sup>](https://en.cppreference.com/w/cpp/numeric/complex/pow) | ");
  OUTPUT("| `sqrt` | [Square Root](https://en.cppreference.com/w/cpp/numeric/complex/sqrt) | ");

  CR();
  CR();

  OUTPUT("*Exponentials*");
  CR();
  OUTPUT("| function | name | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `exp` | [e<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/complex/exp) | ");
  CR();
  CR();

  OUTPUT("*Logarithms*");
  CR();
  OUTPUT("| function | name | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `log` | [Natural Logarithm, ln(x) = log<sub>e</sub>(x)](https://en.cppreference.com/w/cpp/numeric/complex/log) | ");
  OUTPUT("| `log10` | [base 10 logarithm, log<sub>10</sub>(x)](https://en.cppreference.com/w/cpp/numeric/complex/log10) | ");
  OUTPUT("| `log2` | [base 2 logarithm, log<sub>2</sub>(x)](https://en.cppreference.com/w/cpp/numeric/complex/log2) | ");

  CR();
  CR();

  CR();
  OUTPUT("| function | description | ");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| `sgn(x)` | [signum function](https://en.wikipedia.org/wiki/Sign_function), return type has same type as x | ");
  OUTPUT("| `zero(x)` | return a zero with the same type as x | ");
  OUTPUT("| `sqr(x)` | x<sup>2</sup> | ");
  OUTPUT("| `cube(x)` | x<sup>3</sup> | ");
  CR();
  CR();

  OUTPUT("\n<br>\n");
  GMD_HEADER2("More on types");

  GMD_HEADER3("Type information");

  GMD_HEADER4("typeid");

  OUTPUT("The function [`std::typeid`](https://en.cppreference.com/w/cpp/language/typeid) returns an object of type [`std::type_info`](https://en.cppreference.com/w/cpp/types/type_info) (defined in the header `<typeinfo>`). ");
  OUTPUT("This gives the type for any varable. However, the names are garbled compiler strings that are not pretty. ");
  CR();

  {
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ECHO_CODE(int n = 3);
    // DISP(typeid(n).name());
    OUTPUT("typeid(n).name() -> \"i\"");
    ECHO_CODE(string s = "hello");
    // DISP(typeid(s).name());
    OUTPUT("typeid(s).name() -> \"NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE\"");
    GMD_CODE_END();
  }

  GMD_HEADER4("getTypeName");
  OUTPUT("The function `mathq::display::getTypeName` returns a string that gives the actual human-readable type name. It works for most [fundamental types](https://en.cppreference.com/w/cpp/language/types) and all classes defined in ");
  {
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ECHO_CODE(int n = 3);
    // DISP(getTypeName(n));
    OUTPUT("getTypeName(n) -> \"int\"");
    ECHO_CODE(string s = "hello");
    // DISP(getTypeName(s));
    OUTPUT("getTypeName(s) -> \"std::string\"");
    GMD_CODE_END();
  }
  OUTPUT("\n<br>\n");
  GMD_HEADER3("Mixed-typed math and auto-promotion");
  CR();
  OUTPUT("C++ automatically converts number types depending on context.");
  OUTPUT("This is referred to as [implicit conversion](https://en.cppreference.com/w/c/language/conversion).");
  OUTPUT("For example, when adding an integer and a floating point number, the integer is first converted to a floating point type before the addition takes place.");
  OUTPUT("As another example, when adding two integers (or floating point types) of different sizes, the smaller size is first converted to the larger size. This porces is referred to as _promotion_.");

  {
    OUTPUT("Examples:\n");
    GMD_CODE_START("C++");
    ECHO_CODE(short n1 = 3);
    ECHO_CODE(int n2 = 100);
    // TLDISP(n1 * n2);
    OUTPUT("n1 * n2 -> int 300");
    CR();
    ECHO_CODE(float x1 = 3);
    ECHO_CODE(double x2 = 0.1415);
    // TLDISP(x1 + x2);
    OUTPUT("x1 + x2 -> double 3.1415");
    CR();
    ECHO_CODE(int8_t y1 = 25);
    ECHO_CODE(double y2 = 0.25);
    // TLDISP(y1 / y2 + y2);
    OUTPUT("y1 / y2 + y2 -> double 100.25");
    GMD_CODE_END();
  }

  OUTPUT("\n<br>\n");
  GMD_HEADER3("Type Conversion");
  OUTPUT("There are various ways to cast one type to another in C++.  ");
  OUTPUT("Here we demonstrate [explicit conversion](https://en.cppreference.com/w/cpp/language/explicit_cast), which has two forms for the syntax: `(type) expression` or  `type(expression)` ");
  CR();
  CR();

  {
    OUTPUT("Converting a floating point type to an integer:\n");
    GMD_CODE_START("C++");
    ECHO_CODE(int n1 = (int)3.14);
    // TLDISP(n1);
    OUTPUT("n1 -> 3");
    ECHO_CODE(int n2 = int(3.14));
    // TLDISP(n2);
    OUTPUT("n2 -> 3");
    GMD_CODE_END();
  }

  {
    OUTPUT("Forcing floating point division by converting the numerator to a `float`\n");
    GMD_CODE_START("C++");
    ECHO_CODE(double x = (21 + 1) / 7);
    // TLDISP(x);
    OUTPUT("x -> 3");
    ECHO_CODE(double y = float(21 + 1) / 7);
    // TLDISP(y);
    OUTPUT("y -> 3.14286");
    GMD_CODE_END();
  }

  return 0;
}
