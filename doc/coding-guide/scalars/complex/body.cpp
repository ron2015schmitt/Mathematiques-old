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

  header2("Introduction");

  text("\n<br>\n");
  header2("Size of complex numbers");

  text("The size of a complex number is simply _twice_ the size of the underlying arithmetic type:");

  CR();
  CR();
  codestart("C++");
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
  codeend();

  text("The symbol [```CHAR_BIT```](https://en.cppreference.com/w/cpp/header/climits) yields the number of bits per byte, and the C++ function [```sizeof()```](https://en.cppreference.com/w/cpp/language/sizeof) yields the size in _bytes_ of the argument, which can be a type, variable, or expression.");
  CR();
  text("\n<br>\n");
  header2("Operators and functions");

  header3("Arithmetic Operators");
  text("Complex numbers in C++ support the 4 standard arithmetic operators.\n");
  text("For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).\n");

  CR();
  text("| operator | operation | ");
  text("| :---: | :---: | ");
  text("| ```+``` | addition | ");
  text("| ```-``` | subtraction | ");
  text("| ```*``` | multiplication | ");
  text("| ```/``` | division | ");
  CR();

  codestart("C++");
  disp(complex(1.0, 1.0) + complex(2.0, 4.0));
  disp(complex(1.0, 1.0) - complex(2.0, 4.0));
  disp(complex(1.0, 1.0) * complex(2.0, 4.0));
  disp(complex(1.0, 1.0) / complex(2.0, 4.0));
  codeend();


  // Exponentiation and the power function
  text("\n<br>\n");
  header3("Exponentiation and the ```pow``` function");
  text("C++ does not have an exponentiation operator.  Instead it provides the [```std::pow```](https://en.cppreference.com/w/cpp/numeric/complex/div) function");

  codestart("C++");
  disp(pow(complex(1.0, 1.0), complex(2.0, 4.0)));
  codeend();

  text("\n<br>\n");
  header3("Relational Operators");

  text("Complex numbers are not an ordered set.  Therefore, there is no concept of greater than or less than.\n");
  text("For details refer [Comparison Operators](https://en.cppreference.com/w/c/language/operator_comparison).\n");

  CR();
  text("| operator | operation | ");
  text("| :---: | :---: | ");
  text("| `==` | equal to | ");
  text("| `!=` | not equal to | ");
  CR();

  text("Examples:\n");
  codestart("C++");
  CR();
  disp(complex(1.0, 1.0) == complex(1.0, 1.0));
  disp(complex(1.0, 1.0) != complex(1.0, 1.0));
  CR();
  disp(complex(1.0, 1.0) == complex(2.0, 4.0));
  disp(complex(1.0, 1.0) != complex(2.0, 4.0));
  codeend();

  text("\n<br>\n");
  header3("Mathematical functions from the C++ [``std::complex`` header](https://en.cppreference.com/w/cpp/numeric/complex)");

  header4("C++ ``std`` library common functions");

  CR();
  text("The following are [common mathematical functions](https://en.cppreference.com/w/cpp/numeric/math) implemented in the C++ `std` library");
  CR();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `abs` | [absolute value](https://en.cppreference.com/w/cpp/numeric/complex/abs) | ");
  text("| `ceil` | [ceiling function](https://en.cppreference.com/w/cpp/numeric/complex/ceil) | ");
  text("| `floor` | [floor function](https://en.cppreference.com/w/cpp/numeric/complex/floor) | ");
  text("| `trunc` | [truncate function](https://en.cppreference.com/w/cpp/numeric/complex/trunc) | ");
  text("| `round` | [round function](https://en.cppreference.com/w/cpp/numeric/complex/round) | ");
  CR();
  CR();

  text("*Trig Functions*");
  CR();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `sin` | [sine](https://en.cppreference.com/w/cpp/numeric/complex/sin) | ");
  text("| `cos` | [cosine](https://en.cppreference.com/w/cpp/numeric/complex/cos) | ");
  text("| `tan` | [tangent](https://en.cppreference.com/w/cpp/numeric/complex/tan) | ");
  CR();
  CR();

  text("*Inverse Trig Functions*");
  CR();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `asin` | [arc sine](https://en.cppreference.com/w/cpp/numeric/complex/asin) | ");
  text("| `acos` | [arc cosine](https://en.cppreference.com/w/cpp/numeric/complex/acos) | ");
  text("| `atan` | [arc tangent](https://en.cppreference.com/w/cpp/numeric/complex/atan) | ");
  CR();
  CR();

  text("*Hyperbolic Trig Functions*");
  CR();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `sinh` | [Hyperbolic sine](https://en.cppreference.com/w/cpp/numeric/complex/sinh) | ");
  text("| `cosh` | [Hyperbolic cosine](https://en.cppreference.com/w/cpp/numeric/complex/cosh) | ");
  text("| `tanh` | [Hyperbolic tangent](https://en.cppreference.com/w/cpp/numeric/complex/tanh) | ");
  CR();
  CR();

  text("*Inverse Hyperbolic Trig Functions*");
  CR();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `asinh` | [Hyperbolic arc sine](https://en.cppreference.com/w/cpp/numeric/complex/asinh) | ");
  text("| `acosh` | [Hyperbolic arc cosine](https://en.cppreference.com/w/cpp/numeric/complex/acosh) | ");
  text("| `atanh` | [Hyperbolic arc tangent](https://en.cppreference.com/w/cpp/numeric/complex/atanh) | ");

  CR();
  CR();

  text("*Exponentiation*");
  CR();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `pow(x, y)` | [x<sup>y</sup>](https://en.cppreference.com/w/cpp/numeric/complex/pow) | ");
  text("| `sqrt` | [Square Root](https://en.cppreference.com/w/cpp/numeric/complex/sqrt) | ");

  CR();
  CR();

  text("*Exponentials*");
  CR();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `exp` | [e<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/complex/exp) | ");
  CR();
  CR();

  text("*Logarithms*");
  CR();
  text("| function | name | ");
  text("| :---: | :---: | ");
  text("| `log` | [Natural Logarithm, ln(x) = log<sub>e</sub>(x)](https://en.cppreference.com/w/cpp/numeric/complex/log) | ");
  text("| `log10` | [base 10 logarithm, log<sub>10</sub>(x)](https://en.cppreference.com/w/cpp/numeric/complex/log10) | ");
  text("| `log2` | [base 2 logarithm, log<sub>2</sub>(x)](https://en.cppreference.com/w/cpp/numeric/complex/log2) | ");

  CR();
  CR();

  CR();
  text("| function | description | ");
  text("| :---: | :---: | ");
  text("| `sgn(x)` | [signum function](https://en.wikipedia.org/wiki/Sign_function), return type has same type as x | ");
  text("| `zero(x)` | return a zero with the same type as x | ");
  text("| `sqr(x)` | x<sup>2</sup> | ");
  text("| `cube(x)` | x<sup>3</sup> | ");
  CR();
  CR();

  text("\n<br>\n");
  header2("More on types");

  header3("Type information");

  header4("typeid");

  text("The function [`std::typeid`](https://en.cppreference.com/w/cpp/language/typeid) returns an object of type [`std::type_info`](https://en.cppreference.com/w/cpp/types/type_info) (defined in the header `<typeinfo>`). ");
  text("This gives the type for any varable. However, the names are garbled compiler strings that are not pretty. ");
  CR();

  {
    text("Examples:\n");
    codestart("C++");
    codemulti(int n = 3);
    // disp(typeid(n).name());
    text("typeid(n).name() -> \"i\"");
    codemulti(string s = "hello");
    // disp(typeid(s).name());
    text("typeid(s).name() -> \"NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE\"");
    codeend();
  }

  header4("getTypeName");
  text("The function `mathq::display::getTypeName` returns a string that gives the actual human-readable type name. It works for most [fundamental types](https://en.cppreference.com/w/cpp/language/types) and all classes defined in ");
  {
    text("Examples:\n");
    codestart("C++");
    codemulti(int n = 3);
    // disp(getTypeName(n));
    text("getTypeName(n) -> \"int\"");
    codemulti(string s = "hello");
    // disp(getTypeName(s));
    text("getTypeName(s) -> \"std::string\"");
    codeend();
  }
  text("\n<br>\n");
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
    // tdisp(n1 * n2);
    text("n1 * n2 -> int 300");
    CR();
    codemulti(float x1 = 3);
    codemulti(double x2 = 0.1415);
    // tdisp(x1 + x2);
    text("x1 + x2 -> double 3.1415");
    CR();
    codemulti(int8_t y1 = 25);
    codemulti(double y2 = 0.25);
    // tdisp(y1 / y2 + y2);
    text("y1 / y2 + y2 -> double 100.25");
    codeend();
  }

  text("\n<br>\n");
  header3("Type Conversion");
  text("There are various ways to cast one type to another in C++.  ");
  text("Here we demonstrate [explicit conversion](https://en.cppreference.com/w/cpp/language/explicit_cast), which has two forms for the syntax: `(type) expression` or  `type(expression)` ");
  CR();
  CR();

  {
    text("Converting a floating point type to an integer:\n");
    codestart("C++");
    codemulti(int n1 = (int)3.14);
    // tdisp(n1);
    text("n1 -> 3");
    codemulti(int n2 = int(3.14));
    // tdisp(n2);
    text("n2 -> 3");
    codeend();
  }

  {
    text("Forcing floating point division by converting the numerator to a `float`\n");
    codestart("C++");
    codemulti(double x = (21 + 1) / 7);
    // tdisp(x);
    text("x -> 3");
    codemulti(double y = float(21 + 1) / 7);
    // tdisp(y);
    text("y -> 3.14286");
    codeend();
  }

  return 0;
}
