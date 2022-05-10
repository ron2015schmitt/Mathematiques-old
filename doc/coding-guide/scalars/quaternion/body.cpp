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

  using namespace mathq::unit_quaternion;
  using namespace mathq::unit_imaginary;

  GMD_HEADER2("Introduction");

  OUTPUT("\
| × | 1 | **i** | **j** | **k** | \n\
| :---: | :---: | :---: | :---: | :---: |");

  // first row
  OUTPUT_NOCR("| 1 |");
  OUTPUT_NOCR(1 * 1);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(1 * i);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(1 * j);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(1 * k);
  OUTPUT_NOCR(" | ");
  CR();

  // 2nd row
  OUTPUT_NOCR("| **i** |");
  OUTPUT_NOCR(i * 1);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(i * i);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(i * j);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(i * k);
  OUTPUT_NOCR(" | ");
  CR();

  // third row
  OUTPUT_NOCR("| **j** |");
  OUTPUT_NOCR(j * 1);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(j * i);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(j * j);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(j * k);
  OUTPUT_NOCR(" | ");
  CR();

  // 4th row
  OUTPUT_NOCR("| **k** |");
  OUTPUT_NOCR(k * 1);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(k * i);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(k * j);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(k * k);
  OUTPUT_NOCR(" | ");
  CR();

  CR();
  OUTPUT("The above table is referred to as the [Cayley Table](https://en.wikipedia.org/wiki/Cayley_table) for Quaternions.  Each entry is the product of the row label times the col label.");

  CR();
  CR();
  OUTPUT("\n<br>\n");
  GMD_HEADER2("Size of quaternionss");

  OUTPUT("The size of a quaternions is simply _four times_ the size of the underlying arithmetic type:");

  CR();
  CR();
  GMD_CODE_START("C++");
  SRDISP(" bits",CHAR_BIT);
  CR();
  SRDISP(" bits",CHAR_BIT * sizeof(int));
  SRDISP(" bits",CHAR_BIT * sizeof(Quaternion<int>));
  CR();
  SRDISP(" bits",CHAR_BIT * sizeof(double));
  SRDISP(" bits",CHAR_BIT * sizeof(Quaternion<double>));
  CR();
  SRDISP(" bits",CHAR_BIT * sizeof(long double));
  SRDISP(" bits",CHAR_BIT * sizeof(Quaternion<long double>));
  CR();
  GMD_CODE_END();

  CR();
  CR();
  GMD_CODE_START("C++");
  using namespace mathq;
  ECHO_CODE(auto q1 = Quaternion<double>(1, 2, -1, -3));
  ECHO_CODE(auto q2 = Quaternion<double>(4, 3, -2, -5));
  CR();
  TRDISP(q1);
  MDISP(real(q1), imag(q1), jmag(q1), kmag(q1));
  TRDISP(q1.scalar());
  TRDISP(q1.vector());
  TRDISP(q2);
  TRDISP(q1 * q2);
  TRDISP(abs(q1 * q2));
  GMD_CODE_END();

  return 0;
}
