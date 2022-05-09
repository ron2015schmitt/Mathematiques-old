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
  OUTPUT_NOCR(1*1);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(1*i);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(1*j);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(1*k);
  OUTPUT_NOCR(" | ");
  CR();

  // 2nd row
  OUTPUT_NOCR("| **i** |");
  OUTPUT_NOCR(i*1);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(i*i);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(i*j);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(i*k);
  OUTPUT_NOCR(" | ");
  CR();

  // third row
  OUTPUT_NOCR("| **j** |");
  OUTPUT_NOCR(j*1);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(j*i);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(j*j);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(j*k);
  OUTPUT_NOCR(" | ");
  CR();

  // 4th row
  OUTPUT_NOCR("| **k** |");
  OUTPUT_NOCR(k*1);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(k*i);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(k*j);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(k*k);
  OUTPUT_NOCR(" | ");
  CR();

  CR();
  OUTPUT("The above table is referred to as the [Cayley Table](https://en.wikipedia.org/wiki/Cayley_table) for Quaternions.  Each entry is the product of the row label times the col label.");

  CR();
  CR();
  OUTPUT("\n<br>\n");
  GMD_HEADER2("Size of quaternionss");

  OUTPUT("The size of a quaternions is simply _twice_ the size of the underlying arithmetic type:");

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

  return 0;
}
