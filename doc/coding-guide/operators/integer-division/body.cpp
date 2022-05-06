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
  text("C++ also provides support for integer division witjh remainder.\n");
  text("If both numerator and denominator are integers, the division operator gives the integer division result.\n");
  text("For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).\n");

  cr();
  text("| operator | operation | types | ");
  text("| :---: | :---: | :---: | ");
  text("| `/` | integer division | 𝕤, 𝕌 | ");
  text("| `%` | modulus | ℤ | ");
  cr();

  vspace();
  header3("Examples: integer division");
  codestart("C++");
  trdisp(7 / 2);
  codeend();
  text("* The modulus operator `a % b`, gives the remainder after integer divison of `a` by `b`.\n");
  codestart("C++");
  trdisp(7 % 2);
  codeend();
  text("* The function [`std::div`](https://en.cppreference.com/w/cpp/numeric/math/div) can also be used for integer division, It returns both the result and remainder.\n");

  codestart("C++");
  codemulti(div_t result = div(7, 2));
  codeend();
  text("With result:\n");
  codestart("C++");
  trdisp(result.quot);
  trdisp(result.rem);
  codeend();

  return 0;
}
