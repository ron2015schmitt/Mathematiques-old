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
  text("The operators `+, -, *, /, %` are the addition, subtraction, multiplication, division, and modulus operators respectively.\n");
  text("For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).\n");

  cr();
  text("| operator | operation | types | ");
  text("| :---: | :---: | :---: | ");
  text("| `+` | addition | 𝕤, 𝕌 | ");
  text("| `-` | subtraction | 𝕤, 𝕌 | ");
  text("| `*` | multiplication | 𝕤, 𝕌 | ");
  text("| `/` | division | 𝕤, 𝕌 | ");
  text("| `%` | modulus | ℤ | ");
  cr();

  text("For container types, the following rules apply for `x op y`:\n");
  text("* For two (zero-depth) containers of the same `rank` and `dimensions`, `x op y` yields the element-wise operation a container of the same `rank` and `dimensions\n");
  text("* All other cases are invalid and will produce unpredictable results or a run-time error. Debug modes will send useful error messages to the stderr.\n");

  vspace();
  header3("Examples using addition");

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
  trdisp(Imaginary<double>(1) + Imaginary<double>(33.12));
  trdisp(-10 + Imaginary<double>(5.25));
  trdisp(100 + complex<double>(1.5, 2) + Imaginary<double>(5.25));
  codeend();
  cr();

  header4("Vectors, Matrice, and Tensors");
  cr();
  codestart("C++");
  codeend();
  cr();

  header4("Nested Containers");
  cr();
  codestart("C++");
  codeend();
  cr();

  header4("Mixed Rank");
  cr();
  codestart("C++");
  codeend();
  cr();


  vspace();
  header2("Integer Division");
  text("If both numerator and denominator are integers, the division operator gives the integer division result.\n");

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

  vspace();
  header2("Exponentiation and the `pow` function");
  text("C++ does not have an exponentiation operator.  Instead it provides the [`std::pow`](https://en.cppreference.com/w/cpp/numeric/math/div) function");
  codestart("C++");
  trdisp(pow(2, 8));
  trdisp(pow(25, 1 / 2));
  codeend();

  vspace();
  header2("Logic Operators");
  text("For details refer [Logical Operators](https://en.cppreference.com/w/c/language/operator_logical).\n");

  cr();
  text("| operator | operation | ");
  text("| :---: | :---: | ");
  text("| `!` | logical NOT | ");
  text("| `\\|\\|` | logical OR | ");
  text("| `&&` | logical AND | ");
  cr();

  text("**CAVEAT**: C++ also has binary bit-wise operators `&` and `|`.  Mistyping the above operators can cause painful bugs. \n");

  cr();
  text("Examples:\n");
  codestart("C++");
  trdisp(true);
  trdisp(false);
  trdisp(!true);
  trdisp(!false);
  trdisp(true && true);
  trdisp(true && false);
  trdisp(true || false);
  codeend();

  text("* In C++ logical operators work for all real and integer types: `0` corresponds to `false` and all non-zero values correspond to `true`\n");
  codestart("C++");
  trdisp(!true);
  trdisp(!8);
  trdisp(!!8.293);
  trdisp(true && 3);
  trdisp(true && 0);
  codeend();

  vspace();
  header2("Relational Operators");

  text("For details refer [Comparison Operators](https://en.cppreference.com/w/c/language/operator_comparison).\n");

  cr();
  text("| operator | operation | ");
  text("| :---: | :---: | ");
  text("| `==` | equal to | ");
  text("| `!=` | not equal to | ");
  text("| `<` | less than | ");
  text("| `<=` | less than or equal to | ");
  text("| `>` | greater than | ");
  text("| `>=` | greater than or equal to | ");
  // text("| `<=>` | three-way comparison | ");
  cr();

  text("**CAVEAT**: C++ allows assigment `=` inside `if` statements (eg, `if (a = true) return;`).  Mistyping the equals operator `==` can cause painful bugs. \n");

  cr();
  text("Examples:\n");
  codestart("C++");
  trdisp((2 == 2));
  trdisp((1 / 2 == 0.5));
  trdisp((1. / 2 == 0.5));
  trdisp((-2 < 34.2));
  trdisp((2 > 0));
  codeend();

  vspace();
  text("<hr>");
  text("_Linear algebra operators are covered in the Linear Alegbra section._");
  return 0;
}
