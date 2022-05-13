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

  OUTPUT("C++ supports [complex numbers](https://mathworld.wolfram.com/ComplexNumber.html) via the template class `std::complex<D>`, where D is some integer or real type. ");
  CR();
  OUTPUT("In this documentation, we denote complex number types using the symbol, ℂ.");

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


  GMD_HEADER2("Declaration and initialization");


  OUTPUT("Complex numbers can be declared and initialized in a variety of ways.");

  CR();
  CR();
  GMD_CODE_START("C++");
  OUTPUT("#include <complex>;");
  OUTPUT("#include <cmath>;");
  OUTPUT("...");
  ECHO_CODE(using namespace std);
  ECHO_CODE(using namespace std::complex_literals);
  ECHO_CODE(complex<double> c1);
  ECHO_CODE(complex<double> c2 = complex<double>(2, -3.5));
  ECHO_CODE(complex<double> c3(1, 2.3));
  ECHO_CODE(complex<double> c4 = 1.4 + 3.5i);
  ECHO_CODE(auto c5 = complex<double>(1.3, -10.5));
  TRDISP(c1);
  TRDISP(c2);
  TRDISP(c3);
  TRDISP(1i);
  TRDISP(c4);
  TRDISP(c5);
  GMD_CODE_END();

  OUTPUT("In the above expression `c4 = 1.4 + 3.5i`, the C++ operator `std::complex_literals::i` is used. ");
  OUTPUT("This operator can only be used after a number and there can NOT be a space between the number and `i`.  ");
  OUTPUT("The operator `i` is a `double`, while `if` and `il` are a `float` and a `long double` respectively.");
  CR();


  return 0;
}
