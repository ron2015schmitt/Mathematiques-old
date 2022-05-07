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
  

  GMD_PREAMBLE();

  CR();
  CR();


  GMD_HEADER2("Arithmetic Operators");
  OUTPUT("The operators `+, -, *, /` are the addition, subtraction, multiplication, and division operators respectively.\n");
  OUTPUT("For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).\n");

  CR();
  OUTPUT("| operator | operation | types | ");
  OUTPUT("| :---: | :---: | :---: | ");
  OUTPUT("| `+` | addition | 𝕤, 𝕌 | ");
  OUTPUT("| `-` | subtraction | 𝕤, 𝕌 | ");
  OUTPUT("| `*` | multiplication | 𝕤, 𝕌 | ");
  OUTPUT("| `/` | division | 𝕤, 𝕌 | ");
  CR();

  OUTPUT("For container types, the following rules apply for `x op y`:\n");
  OUTPUT("* For two (zero-depth) containers of the same `rank` and `dimensions`, `x op y` yields the element-wise operation a container of the same `rank` and `dimensions\n");
  OUTPUT("* All other cases are invalid and will produce unpredictable results or a run-time error. Debug modes will send useful error messages to the stderr.\n");


  GMD_VSPACE();
  GMD_HEADER2("Exponentiation and the `pow` function");
  OUTPUT("C++ does not have an exponentiation operator.  Instead it provides the [`std::pow`](https://en.cppreference.com/w/cpp/numeric/math/div) function");
  GMD_CODE_START("C++");
  TRDISP(pow(2, 8));
  TRDISP(pow(25, 1 / 2));
  GMD_CODE_END();

  GMD_VSPACE();
  GMD_HEADER2("Examples using addition");

  GMD_HEADER4("Reals");
  CR();
  GMD_CODE_START("C++");
  TRDISP(1 + 2);
  TRDISP(7.5 + 2);
  TRDISP(7.5 - 0.5);
  GMD_CODE_END();
  CR();

  GMD_HEADER4("Complex, Imaginary and Mixed");
  CR();
  GMD_CODE_START("C++");
  TRDISP(complex<double>(1.5, 0) + complex<double>(0.5, 4));
  GMD_CODE_END();
  CR();

  GMD_HEADER4("Imaginary");
  CR();
  GMD_CODE_START("C++");
  TRDISP(complex<double>(1.5, 0) + complex<double>(0.5, 4));
  TRDISP(Imaginary<double>(1) + Imaginary<double>(33.12));
  TRDISP(-10 + Imaginary<double>(5.25));
  TRDISP(100 + complex<double>(1.5, 2) + Imaginary<double>(5.25));
  GMD_CODE_END();
  CR();

  GMD_HEADER4("Mixed Type");
  CR();
  GMD_CODE_START("C++");
  TRDISP(complex<double>(1.5, 0) + complex<double>(0.5, 4));
  TRDISP(Imaginary<double>(1) + Imaginary<double>(33.12));
  TRDISP(-10 + Imaginary<double>(5.25));
  TRDISP(100 + complex<double>(1.5, 2) + Imaginary<double>(5.25));
  GMD_CODE_END();
  CR();

  GMD_HEADER4("Containers");
  CR();
  GMD_CODE_START("C++");
  GMD_CODE_END();
  CR();

  GMD_HEADER4("Nested Containers");
  CR();
  GMD_CODE_START("C++");
  GMD_CODE_END();
  CR();

  GMD_HEADER4("Mixed Rank Math");
  CR();
  GMD_CODE_START("C++");
  GMD_CODE_END();
  CR();

  GMD_HEADER4("Mixed Depth Math");
  CR();
  GMD_CODE_START("C++");
  GMD_CODE_END();
  CR();

  return 0;
}
