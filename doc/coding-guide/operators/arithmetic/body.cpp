#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>

#define MATHQ_DEBUG 1
#include "mathq.h"
#include "macros.h"
#include "gitmd.h"

int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;
  using namespace md;

  markdown_preamble();

  cr();
  cr();


  header2("Arithmetic Operators");
  text("The operators `+, -, *, /` are the addition, subtraction, multiplication, and division operators respectively.\n");
  text("For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).\n");

  cr();
  text("| operator | operation | types | ");
  text("| :---: | :---: | :---: | ");
  text("| `+` | addition | 𝕤, 𝕌 | ");
  text("| `-` | subtraction | 𝕤, 𝕌 | ");
  text("| `*` | multiplication | 𝕤, 𝕌 | ");
  text("| `/` | division | 𝕤, 𝕌 | ");
  cr();

  text("For container types, the following rules apply for `x op y`:\n");
  text("* For two (zero-depth) containers of the same `rank` and `dimensions`, `x op y` yields the element-wise operation a container of the same `rank` and `dimensions\n");
  text("* All other cases are invalid and will produce unpredictable results or a run-time error. Debug modes will send useful error messages to the stderr.\n");


  vspace();
  header2("Exponentiation and the `pow` function");
  text("C++ does not have an exponentiation operator.  Instead it provides the [`std::pow`](https://en.cppreference.com/w/cpp/numeric/math/div) function");
  codestart("C++");
  trdisp(pow(2, 8));
  trdisp(pow(25, 1 / 2));
  codeend();

  vspace();
  header2("Examples using addition");

  header4("Reals");
  cr();
  codestart("C++");
  trdisp(1 + 2);
  trdisp(7.5 + 2);
  trdisp(7.5 - 0.5);
  codeend();
  cr();

  header4("Complex, Imaginary and Mixed");
  cr();
  codestart("C++");
  trdisp(complex<double>(1.5, 0) + complex<double>(0.5, 4));
  codeend();
  cr();

  header4("Imaginary");
  cr();
  codestart("C++");
  trdisp(complex<double>(1.5, 0) + complex<double>(0.5, 4));
  trdisp(Imaginary<double>(1) + Imaginary<double>(33.12));
  trdisp(-10 + Imaginary<double>(5.25));
  trdisp(100 + complex<double>(1.5, 2) + Imaginary<double>(5.25));
  codeend();
  cr();

  header4("Mixed Type");
  cr();
  codestart("C++");
  trdisp(complex<double>(1.5, 0) + complex<double>(0.5, 4));
  trdisp(Imaginary<double>(1) + Imaginary<double>(33.12));
  trdisp(-10 + Imaginary<double>(5.25));
  trdisp(100 + complex<double>(1.5, 2) + Imaginary<double>(5.25));
  codeend();
  cr();

  header4("Containers");
  cr();
  codestart("C++");
  codeend();
  cr();

  header4("Nested Containers");
  cr();
  codestart("C++");
  codeend();
  cr();

  header4("Mixed Rank Math");
  cr();
  codestart("C++");
  codeend();
  cr();

  header4("Mixed Depth Math");
  cr();
  codestart("C++");
  codeend();
  cr();

  return 0;
}
