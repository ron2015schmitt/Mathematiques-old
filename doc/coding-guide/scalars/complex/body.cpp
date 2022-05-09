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

  return 0;
}
