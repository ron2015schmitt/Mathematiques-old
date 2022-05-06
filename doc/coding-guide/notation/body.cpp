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

  vspace();

  text("The following notation shorthand is used in the User Guide (but certainly not in C++ code!).\n");

  header3("Scalars");
  CR();
  text("| symbol | C++ types |");
  text("| :---: | :---: | ");
  text("| ℤ | any C++ real signed integral type: `bool`, `int`, `long`, etc | ");
  text("| ℕ | any C++ real unsigned integral type: `unsigned int`, `unsigned long`, etc | ");
  text("| ℝ | any C++ real floating-point type: `float`, `double`, `long double`) | ");
  text("| ℂ | any `std::complex<ℝ>` | ");
  text("| 𝕁 | any `Imaginary<ℝ>` | ");
  text("| ℍ | any `Quaternion<ℝ>` | ");
  text("| 𝕂 | any ℝ, ℂ, 𝕁, ℍ | ");
  text("| 𝕤 | any ℤ, 𝕂 | ");

  CR();
  text("Lower case 𝕤 was chosen because 𝕊 is commonly used in mathematics for the spherical groups\n");



  vspace();

  header3("Containers");
  CR();
  text("| symbol | C++ types |");
  text("| :---: | :---: | ");
  text("| 𝕍 | any `Vector<T>` for any scalar or container type or type symbol T | ");
  text("| 𝕄 | any `Matrix<T>` for any scalar or container type or type symbol T | ");
  text("| 𝕥 | any `Tensor<T>` for any scalar or container type or type symbol T | ");
  text("| 𝕌 | any 𝕍, 𝕄, 𝕥 | ");
  CR();
  text("Lower case 𝕥 was chosen because 𝕋 is commonly used in mathematics for the torus groups\n");

  CR();
  vspace();

  return 0;
}
