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

  OUTPUT("C++ supports a wide variety of real numbers [integer and floating point types](https://en.cppreference.com/w/cpp/language/types).");
  CR();
  GMD_HEADER2("Integers");
  CR();

  GMD_HEADER3("Signed Integers");

  OUTPUT("C++ supports several different signed integer types.  **The size of each depends on the CPU and compiler**.  For a 64-bit CPU running Linux, they have the following number of bits:");

  OUTPUT("The symbol [`CHAR_BIT`](https://en.cppreference.com/w/cpp/header/climits) yields the number of bits per byte, and the C++ function [`sizeof()`](https://en.cppreference.com/w/cpp/language/sizeof) yields the size in _bytes_ of the argument, which can be a type, variable, or expression.");
  CR();
  OUTPUT("The maximum and minimum for each type are given below.");

  OUTPUT("| Type | Size<sup>1,2</sup> | Min<sup>1,3</sup> | Max<sup>1,4</sup> |");
  OUTPUT("| :--- | :---: | :---: | :---: | ");
  // note: need to cast numeric_limits<char>::min() as an int so that it gets printed as a number and not an ASCII charcter
  OUTPUT("| `char` | " << CHAR_BIT*sizeof(char) << " bits | " << int(numeric_limits<char>::min()) << " | " << int(numeric_limits<char>::max()) << " | ");
  OUTPUT("| `short` | " << CHAR_BIT*sizeof(short) << " bits | " << numeric_limits<short>::min() << " | " << numeric_limits<short>::max() << " | ");
  OUTPUT("| `int` | " << CHAR_BIT*sizeof(int) << " bits | " << numeric_limits<int>::min() << " | " << numeric_limits<int>::max() << " | ");
  OUTPUT("| `long` | " << CHAR_BIT*sizeof(long) << " bits | " << numeric_limits<long>::min() << " | " << numeric_limits<long>::max() << " | ");
  OUTPUT("| `long long` | " << CHAR_BIT*sizeof(long long) << " bits | " << numeric_limits<long long>::min() << " | " << numeric_limits<long long>::max() << " | ");

  OUTPUT("1. Sizes and limits given for a 64-bit CPU running Linux");
  OUTPUT("2. The C++ constant [`CHAR_BIT`](https://en.cppreference.com/w/cpp/types/numeric_limits) and C++ function[`std::sizeof`](https://en.cppreference.com/w/cpp/types/numeric_limits) were used to compute size in bits, eg. `CHAR_BIT*sizeof(int)`.");
  OUTPUT("3. The C++ [`std::numeric_limits`](https://en.cppreference.com/w/cpp/types/numeric_limits) functions were used to compute the max and min.");
  OUTPUT("4. The C++ [`std::numeric_limits`](https://en.cppreference.com/w/cpp/types/numeric_limits) functions were used to compute the max and min.");
  CR();

  GMD_VSPACE();
  GMD_HEADER3("Unsigned Integers");

  OUTPUT("C++ also supports several different unsigned integer types.  **The size of each depends on the CPU and compiler**.  For a 64-bit CPU running Linux, they have the following number of bits:");

  OUTPUT("| Type | Size<sup>1,2</sup> | Min<sup>1,3</sup> | Max<sup>1,4</sup> |");
  OUTPUT("| :--- | :---: | :---: | :---: | ");
  OUTPUT("| `bool` | " << CHAR_BIT*sizeof(bool) << " bits | " << numeric_limits<bool>::min() << " | " << numeric_limits<bool>::max() << " | ");
  OUTPUT("| `unsigned char` | " << CHAR_BIT*sizeof(unsigned char) << " bits | " << int(numeric_limits<unsigned char>::min()) << " | " << int(numeric_limits<unsigned char>::max()) << " | ");
  OUTPUT("| `unsigned short` | " << CHAR_BIT*sizeof(unsigned short) << " bits | " << numeric_limits<unsigned short>::min() << " | " << numeric_limits<unsigned short>::max() << " | ");
  OUTPUT("| `unsigned int` | " << CHAR_BIT*sizeof(unsigned int) << " bits | " << numeric_limits<unsigned int>::min() << " | " << numeric_limits<unsigned int>::max() << " | ");
  OUTPUT("| `unsigned long` | " << CHAR_BIT*sizeof(unsigned long) << " bits | " << numeric_limits<unsigned long>::min() << " | " << numeric_limits<unsigned long>::max() << " | ");
  OUTPUT("| `unsigned long long` | " << CHAR_BIT*sizeof(unsigned long long) << " bits | " << numeric_limits<unsigned long long>::min() << " | " << numeric_limits<unsigned long long>::max() << " | ");
  OUTPUT("| `size_t` | " << CHAR_BIT*sizeof(size_t) << " bits | " << numeric_limits<size_t>::min() << " | " << numeric_limits<size_t>::max() << " | ");

  OUTPUT("1. Sizes and limits given for a 64-bit CPU running Linux");
  OUTPUT("2. The C++ constant [`CHAR_BIT`](https://en.cppreference.com/w/cpp/types/numeric_limits) and C++ function[`std::sizeof`](https://en.cppreference.com/w/cpp/types/numeric_limits) were used to compute size in bits, eg. `CHAR_BIT*sizeof(int)`.");
  OUTPUT("3. The C++ [`std::numeric_limits`](https://en.cppreference.com/w/cpp/types/numeric_limits) functions were used to compute the max and min.");
  OUTPUT("4. The C++ [`std::numeric_limits`](https://en.cppreference.com/w/cpp/types/numeric_limits) functions were used to compute the max and min.");

  GMD_VSPACE();
  GMD_HEADER3("Boolean");

  OUTPUT("The boolean type, [`bool`](https://en.cppreference.com/w/c/types/boolean), was introduced in C99.  A `bool` can take only two values, 0 or 1.");
  OUTPUT("Two associated constants are defined: `true` and `false`.\n");

  CR();
  GMD_CODE_START("C++");
  SRDISP(" bits", CHAR_BIT*sizeof(bool));
  CR();
  TRDISP(false);
  TRDISP(true);
  GMD_CODE_END();

  GMD_VSPACE();
  GMD_HEADER3("Indexing Types");

  OUTPUT("The type [`size_t`](https://en.cppreference.com/w/c/types/size_t) is the _unsigned_ integer type that is the best type to use for array indexing and loop counting because it size_t can store the maximum size of a theoretically possible object of any type (including array), no smaller and no larger.");
  OUTPUT("It's size depends on implementation.  The 64-bit Linux size is shown below:");

  CR();
  CR();
  GMD_CODE_START("C++");
  SRDISP(" bits", CHAR_BIT*sizeof(size_t));
  GMD_CODE_END();
  CR();

  GMD_VSPACE();
  GMD_HEADER3("Fixed width integer types");

  OUTPUT("C++11 introduced new types, called [fixed interger types](https://en.cppreference.com/w/cpp/types/integer), that allow you to directly specify the number of bits:");

  CR();
  OUTPUT("| Type | Size<sup>1</sup> | Min<sup>2</sup> | Max<sup>3</sup> |");
  OUTPUT("| :--- | :---: | :---: | :---: | ");
  OUTPUT("| `int8_t` | " << CHAR_BIT*sizeof(int8_t) << " bits | " << int(numeric_limits<int8_t>::min()) << " | " << int(numeric_limits<int8_t>::max()) << " | ");
  OUTPUT("| `int16_t` | " << CHAR_BIT*sizeof(int16_t) << " bits | " << numeric_limits<int16_t>::min() << " | " << numeric_limits<int16_t>::max() << " | ");
  OUTPUT("| `int32_t` | " << CHAR_BIT*sizeof(int32_t) << " bits | " << numeric_limits<int32_t>::min() << " | " << numeric_limits<int32_t>::max() << " | ");
  OUTPUT("| `int64_t` | " << CHAR_BIT*sizeof(int64_t) << " bits | " << numeric_limits<int64_t>::min() << " | " << numeric_limits<int64_t>::max() << " | ");
  CR();


  GMD_VSPACE();
  CR();
  OUTPUT("| Type | Size<sup>1</sup> | Min<sup>2</sup> | Max<sup>3</sup> |");
  OUTPUT("| :--- | :---: | :---: | :---: | ");
  OUTPUT("| `uint8_t` | " << CHAR_BIT*sizeof(uint8_t) << " bits | " << int(numeric_limits<uint8_t>::min()) << " | " << int(numeric_limits<uint8_t>::max()) << " | ");
  OUTPUT("| `uint16_t` | " << CHAR_BIT*sizeof(uint16_t) << " bits | " << numeric_limits<uint16_t>::min() << " | " << numeric_limits<uint16_t>::max() << " | ");
  OUTPUT("| `uint32_t` | " << CHAR_BIT*sizeof(uint32_t) << " bits | " << numeric_limits<uint32_t>::min() << " | " << numeric_limits<uint32_t>::max() << " | ");
  OUTPUT("| `uint64_t` | " << CHAR_BIT*sizeof(uint64_t) << " bits | " << numeric_limits<uint64_t>::min() << " | " << numeric_limits<uint64_t>::max() << " | ");
  CR();
  OUTPUT("1. The C++ constant [`CHAR_BIT`](https://en.cppreference.com/w/cpp/types/numeric_limits) and C++ function[`std::sizeof`](https://en.cppreference.com/w/cpp/types/numeric_limits) were used to compute size in bits, eg. `CHAR_BIT*sizeof(uint)`.");
  OUTPUT("2. The C++ [`std::numeric_limits`](https://en.cppreference.com/w/cpp/types/numeric_limits) functions were used to compute the max and min.");
  OUTPUT("3. The C++ [`std::numeric_limits`](https://en.cppreference.com/w/cpp/types/numeric_limits) functions were used to compute the max and min.");


  GMD_VSPACE();
  GMD_HEADER2("Floating Point Numbers");

  OUTPUT("C++ generally supports three types of floating point number.  These types aare the same for all CPUs and operating systems.");


  OUTPUT("The three types are compared below.");

  OUTPUT("| type | name | bits | standard |  `digits10` |  `max_digits10` | `epsilon()` | `min()` | `lowest()` | `max()` | ");
  OUTPUT("| :--- | :---: | :---: | :---:  | :---:  | :---:  | :---:  | :---:  | :---: | :---: |");
  OUTPUT_NOCR("| float | Single Precision | ");
  OUTPUT_NOCR(CHAR_BIT*sizeof(float));
  OUTPUT_NOCR(" | [IEEE 754-2008 binary32](https://en.wikipedia.org/wiki/Single-precision_floating-point_format) |");
  OUTPUT_NOCR(numeric_limits<float>::digits10);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(numeric_limits<float>::max_digits10);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(numeric_limits<float>::epsilon());
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(numeric_limits<float>::min());
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(numeric_limits<float>::lowest());
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(numeric_limits<float>::max());
  OUTPUT_NOCR(" | ");
  CR();

  OUTPUT_NOCR("| double | Double Precision | ");
  OUTPUT_NOCR(CHAR_BIT*sizeof(double));
  OUTPUT_NOCR(" | [IEEE 754-2008 binary32](https://en.wikipedia.org/wiki/Single-precision_floating-point_format) |");
  OUTPUT_NOCR(numeric_limits<double>::digits10);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(numeric_limits<double>::max_digits10);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(numeric_limits<double>::epsilon());
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(numeric_limits<double>::min());
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(numeric_limits<double>::lowest());
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(numeric_limits<double>::max());
  OUTPUT_NOCR(" | ");
  CR();


  OUTPUT_NOCR("| long double | Quad Precision | ");
  OUTPUT_NOCR(CHAR_BIT*sizeof(long double));
  OUTPUT_NOCR(" | [IEEE 754-2008 binary32](https://en.wikipedia.org/wiki/Single-precision_floating-point_format) |");
  OUTPUT_NOCR(numeric_limits<long double>::digits10);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(numeric_limits<long double>::max_digits10);
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(numeric_limits<long double>::epsilon());
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(numeric_limits<long double>::min());
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(numeric_limits<long double>::lowest());
  OUTPUT_NOCR(" | ");
  OUTPUT_NOCR(numeric_limits<long double>::max());
  OUTPUT_NOCR(" | ");
  CR();
  CR();

  OUTPUT("The functions `epsilon()`, `min()`, `lowest()`, and  `max()`, as well as the static values `digits10` and `max_digits10` are found in [`limits`](https://en.cppreference.com/w/cpp/types/numeric_limits)");

  OUTPUT("The static value `max_digits10` was used as the precision for printing the above values.\n");


  return 0;
}
