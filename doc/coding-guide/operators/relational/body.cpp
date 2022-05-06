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
  

  markdown_preamble();

  CR();
  CR();


  vspace();
  header2("Relational Operators");

  text("For details refer [Comparison Operators](https://en.cppreference.com/w/c/language/operator_comparison).\n");

  CR();
  text("| operator | operation | ");
  text("| :---: | :---: | ");
  text("| `==` | equal to | ");
  text("| `!=` | not equal to | ");
  text("| `<` | less than | ");
  text("| `<=` | less than or equal to | ");
  text("| `>` | greater than | ");
  text("| `>=` | greater than or equal to | ");
  // text("| `<=>` | three-way comparison | ");
  CR();

  text("**CAVEAT**: C++ allows assigment `=` inside `if` statements (eg, `if (a = true) return;`).  Mistyping the equals operator `==` can cause painful bugs. \n");

  CR();
  text("Examples:\n");
  codestart("C++");
  trdisp((2 == 2));
  trdisp((1 / 2 == 0.5));
  trdisp((1. / 2 == 0.5));
  trdisp((-2 < 34.2));
  trdisp((2 > 0));
  codeend();


  return 0;
}
