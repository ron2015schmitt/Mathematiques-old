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

  vspace();

  OUTPUT("The following notation shorthand is used in the User Guide (but certainly not in C++ code!).\n");

  header3("Scalars");
  CR();
  OUTPUT("| symbol | C++ types |");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| ℤ | any C++ real signed integral type: `bool`, `int`, `long`, etc | ");
  OUTPUT("| ℕ | any C++ real unsigned integral type: `unsigned int`, `unsigned long`, etc | ");
  OUTPUT("| ℝ | any C++ real floating-point type: `float`, `double`, `long double`) | ");
  OUTPUT("| ℂ | any `std::complex<ℝ>` | ");
  OUTPUT("| 𝕁 | any `Imaginary<ℝ>` | ");
  OUTPUT("| ℍ | any `Quaternion<ℝ>` | ");
  OUTPUT("| 𝕂 | any ℝ, ℂ, 𝕁, ℍ | ");
  OUTPUT("| 𝕤 | any ℤ, 𝕂 | ");

  CR();
  OUTPUT("Lower case 𝕤 was chosen because 𝕊 is commonly used in mathematics for the spherical groups\n");



  vspace();

  header3("Containers");
  CR();
  OUTPUT("| symbol | C++ types |");
  OUTPUT("| :---: | :---: | ");
  OUTPUT("| 𝕍 | any `Vector<T>` for any scalar or container type or type symbol T | ");
  OUTPUT("| 𝕄 | any `Matrix<T>` for any scalar or container type or type symbol T | ");
  OUTPUT("| 𝕥 | any `Tensor<T>` for any scalar or container type or type symbol T | ");
  OUTPUT("| 𝕌 | any 𝕍, 𝕄, 𝕥 | ");
  CR();
  OUTPUT("Lower case 𝕥 was chosen because 𝕋 is commonly used in mathematics for the torus groups\n");

  CR();
  vspace();

  return 0;
}
