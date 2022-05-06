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

  text("C++ supports a wide variety of real number [integer and floating point types](https://en.cppreference.com/w/cpp/language/types), operators, and functions.");
  cr();
  text("Mathématiques supplements C++ functionality with several more functions.");

  cr();
  text("Mathématiques extends many of these operators and functions to complex numbers, imaginary numbers, and quaterions, as well as extending to vectors, matrices, and tensors in a element-wise fashion.");

  cr();
  cr();
  header2("Integers");
  cr();
  cr();

  header3("Signed Integers");

  text("C++ supports several different signed integer types.  The size of each depends on the CPU and compiler.  For a 64-bit CPU running Linux, they have the following number of bits:");

  cr();
  cr();
  codestart("C++");
  printf("CHAR_BIT = %d bits\n", CHAR_BIT);
  printf("CHAR_BIT*sizeof(char) = %ld bits\n", CHAR_BIT * sizeof(char));
  printf("CHAR_BIT*sizeof(short) = %ld bits\n", CHAR_BIT * sizeof(short));
  printf("CHAR_BIT*sizeof(int) = %ld bits\n", CHAR_BIT * sizeof(int));
  printf("CHAR_BIT*sizeof(long) = %ld bits\n", CHAR_BIT * sizeof(long));
  printf("CHAR_BIT*sizeof(long long) = %ld bits\n", CHAR_BIT * sizeof(long long));
  codeend();

  text("The symbol [```CHAR_BIT```](https://en.cppreference.com/w/cpp/header/climits) yields the number of bits per byte, and the C++ function [```sizeof()```](https://en.cppreference.com/w/cpp/language/sizeof) yields the size in _bytes_ of the argument, which can be a type, variable, or expression.");
  cr();
  text("The maximum and minimum for each type are given below.");

  text("| Type | Min | Max |");
  text("| :--- | :---: | :---: |");
  printf("| ```char``` | %d | %d |\n", std::numeric_limits<char>::min(), std::numeric_limits<char>::max());
  printf("| ```short``` | %d | %d |\n", std::numeric_limits<short>::min(), std::numeric_limits<short>::max());
  printf("| ```int``` | %d | %d |\n", std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
  printf("| ```long``` | %ld | %ld |\n", std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
  printf("| ```long long``` | %lld | %lld |\n", std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());

  cr();
  text("Here the C++ [```std::numeric_limits```](https://en.cppreference.com/w/cpp/types/numeric_limits) functions were used to compute the max and min.");

  vspace();
  header3("Unsigned Integers");

  text("C++ supports unsigned versions of each integer type.");

  text("The maximum and minimum for each type are given below.");

  text("| Type | Min | Max |");
  text("| :--- | :---: | :---: |");
  printf("| ```bool``` | %u | %u |\n", std::numeric_limits<bool>::min(), std::numeric_limits<bool>::max());
  printf("| ```unsigned char``` | %u | %u |\n", std::numeric_limits<unsigned char>::min(), std::numeric_limits<unsigned char>::max());
  printf("| ```unsigned short``` | %u | %u |\n", std::numeric_limits<unsigned short>::min(), std::numeric_limits<unsigned short>::max());
  printf("| ```unsigned int``` | %u | %u |\n", std::numeric_limits<unsigned int>::min(), std::numeric_limits<unsigned int>::max());
  printf("| ```unsigned long``` | %lu | %lu |\n", std::numeric_limits<unsigned long>::min(), std::numeric_limits<unsigned long>::max());
  printf("| ```unsigned long long``` | %llu | %llu |\n", std::numeric_limits<unsigned long long>::min(), std::numeric_limits<unsigned long long>::max());
  printf("| ```size_t``` | %lu | %lu |\n", std::numeric_limits<size_t>::min(), std::numeric_limits<size_t>::max());


  vspace();
  header3("Boolean");

  text("The boolean type, [```bool```](https://en.cppreference.com/w/c/types/boolean), was introduced in C99.  A ```bool``` can take only two values, 0 or 1.");
  text("Two associated constants are defined: ```true``` and ```false```.\n");

  cr();
  codestart("C++");
  printf("CHAR_BIT*sizeof(bool) = %ld bits\n", CHAR_BIT * sizeof(bool));
  cr();
  trdisp(false);
  trdisp(true);
  codeend();

  vspace();
  header3("Indexing Types");

  text("The type [```size_t```](https://en.cppreference.com/w/c/types/size_t) is the _unsigned_ integer type that is the best type to use for array indexing and loop counting because it size_t can store the maximum size of a theoretically possible object of any type (including array)");
  text("It's size depends on implementation.  The 64-bit Linux size is shown below:");

  cr();
  cr();
  codestart("C++");
  printf("CHAR_SIZE*sizeof(size_t) = %ld bits\n", sizeof(size_t));
  codeend();
  cr();

  vspace();
  header3("Fixed width integer types");

  text("C++11 introduced new types, called [fixed interger types](https://en.cppreference.com/w/cpp/types/integer), that allow you to directly specify the number of bits:");

  cr();
  text("| type | bits |");
  text("| :--- | :---: |");
  text("| int8_t | 8 bits |");
  text("| int16_t | 8 bits |");
  text("| int32_t | 16 bits |");
  text("| int64_t | 32 bits |");
  cr();

  cr();
  text("| type | bits |");
  text("| :--- | :---: |");
  text("| uint8_t | 8 bits |");
  text("| uint16_t | 8 bits |");
  text("| uint32_t | 16 bits |");
  text("| uint64_t | 32 bits |");
  cr();


  vspace();
  header2("Floating Point Numbers");

  text("On modern systems, C++ generally supports three types of floating point number:");

  cr();
  cr();
  codestart("C++");
  printf("CHAR_BIT*sizeof(float) = %ld bits\n", CHAR_BIT * sizeof(char));
  printf("CHAR_BIT*sizeof(double) = %ld bits\n", CHAR_BIT * sizeof(short));
  printf("CHAR_BIT*sizeof(long double) = %ld bits\n", CHAR_BIT * sizeof(int));
  codeend();

  text("The three types are compared below.");

  text("| type | name | bits | standard |  ```digits10``` |  ```max_digits10``` | ```epsilon()``` | ```min()``` | ```lowest()``` | ```max()``` | ");
  text("| :--- | :---: | :---: | :---:  | :---:  | :---:  | :---:  | :---:  | :---: | :---: |");
  printf("| float | Single Precision | 32 bits | [IEEE 754-2008 binary32](https://en.wikipedia.org/wiki/Single-precision_floating-point_format) |");
  printf(" %d | ", numeric_limits<float>::digits10);
  printf(" %d | ", numeric_limits<float>::max_digits10);
  printf(" %0.*g | ", numeric_limits<float>::max_digits10, numeric_limits<float>::epsilon());
  printf(" %0.*g | ", numeric_limits<float>::max_digits10, numeric_limits<float>::min());
  printf(" %0.*g | ", numeric_limits<float>::max_digits10, numeric_limits<float>::lowest());
  printf(" %0.*g | ", numeric_limits<float>::max_digits10, numeric_limits<float>::max());
  cr();
  printf("| double | Double Precision | 64 bits | [IEEE 754-2008 binary64](https://en.wikipedia.org/wiki/Double-precision_floating-point_format) |");
  printf(" %d | ", numeric_limits<double>::digits10);
  printf(" %d | ", numeric_limits<double>::max_digits10);
  printf(" %0.*g | ", numeric_limits<double>::max_digits10, numeric_limits<double>::epsilon());
  printf(" %0.*g | ", numeric_limits<double>::max_digits10, numeric_limits<double>::min());
  printf(" %0.*g | ", numeric_limits<double>::max_digits10, numeric_limits<double>::lowest());
  printf(" %0.*g | ", numeric_limits<double>::max_digits10, numeric_limits<double>::max());
  cr();
  printf("| long double | Quad Precision | 128 bits | [IEEE 754-2008 binary128](https://en.wikipedia.org/wiki/Quadruple-precision_floating-point_format) |");
  printf(" %d | ", numeric_limits<long double>::digits10);
  printf(" %d | ", numeric_limits<long double>::max_digits10);
  printf(" %0.*Lg | ", numeric_limits<long double>::max_digits10, numeric_limits<long double>::epsilon());
  printf(" %0.*Lg | ", numeric_limits<long double>::max_digits10, numeric_limits<long double>::min());
  printf(" %0.*Lg | ", numeric_limits<long double>::max_digits10, numeric_limits<long double>::lowest());
  printf(" %0.*Lg | ", numeric_limits<long double>::max_digits10, numeric_limits<long double>::max());
  cr();

  cr();
  cr();

  text("The functions ```epsilon()```, ```min()```, ```lowest()```, and  ```max()```, as well as the static values ```digits10``` and ```max_digits10``` are found in [```limits```](https://en.cppreference.com/w/cpp/types/numeric_limits)");

  text("The static value ```max_digits10``` was used as the precision for printing the above values.\n");

  vspace();
  header2("Operators and functions");

  header3("Arithmetic Operators");
  text("The operators ```+, -, *, /, %``` are the addition, subtraction, multiplication, division, and modulus operators respectively.\n");
  text("For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).\n");

  cr();
  text("| operator | operation | ");
  text("| :---: | :---: | ");
  text("| ```+``` | addition | ");
  text("| ```-``` | subtraction | ");
  text("| ```*``` | multiplication | ");
  text("| ```/``` | division | ");
  text("| ```%``` | modulus | ");
  cr();

  text("* If both numerator and denominator are integers, the division operator gives the integer division result.\n");
  codestart("C++");
  trdisp(7 / 2);
  codeend();
  text("* The modulus operator ```a % b```, gives the remainder after integer divison of ```a``` by ```b```.\n");
  codestart("C++");
  trdisp(7 % 2);
  codeend();
  text("* The function [```std::div```](https://en.cppreference.com/w/cpp/numeric/math/div) can also be used for integer division, It returns both the result and remainder.\n");

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
