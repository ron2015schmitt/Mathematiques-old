<br>



C++ supports a wide variety of [integer and floating point types](https://en.cppreference.com/w/cpp/language/types).
## Integers
### Signed Integers
C++ supports several different signed integer types.  The size of each depends on the CPU and compiler.  However, for a 64-bit CPU running Linux, they have the same number of bits:


```C++
CHAR_BIT = 8 bits
CHAR_BIT*sizeof(char) = 8 bits
CHAR_BIT*sizeof(short) = 16 bits
CHAR_BIT*sizeof(int) = 32 bits
CHAR_BIT*sizeof(long) = 64 bits
CHAR_BIT*sizeof(long long) = 64 bits
```
The symbol [```CHAR_BIT```](https://en.cppreference.com/w/cpp/header/climits) yields the number of bits per byte, and the C++ function [```sizeof()```](https://en.cppreference.com/w/cpp/language/sizeof) yields the size in _bytes_ of the argument, which can be a type, variable, or expression.

The maximum and minimum for each type are given below.
| Type | Min | Max |
| :--- | :---: | :---: |
| ```char``` | -128 | 127 |
| ```short``` | -32768 | 32767 |
| ```int``` | -2147483648 | 2147483647 |
| ```long``` | -9223372036854775808 | 9223372036854775807 |
| ```long long``` | -9223372036854775808 | 9223372036854775807 |

Here the C++ [```std::numeric_limits```](https://en.cppreference.com/w/cpp/types/numeric_limits) functions were used to compute the max and min.
## Unsigned Integers
C++ supports unsigned versions of each integer type.
The maximum and minimum for each type are given below.
| Type | Min | Max |
| :--- | :---: | :---: |
| ```unsigned char``` | 0 | 255 |
| ```unsigned short``` | 0 | 65535 |
| ```unsigned int``` | 0 | 4294967295 |
| ```unsigned long``` | 0 | 18446744073709551615 |
| ```unsigned long long``` | 0 | 18446744073709551615 |
### Indexing Types
The type [```size_t```](https://en.cppreference.com/w/c/types/size_t) is the _unsigned_ integer type that is the best type to use for array indexing and loop counting because it size_t can store the maximum size of a theoretically possible object of any type (including array)
It's size depends on implementation.  The 64-bit Linux size is shown below:

CHAR_SIZE*sizeof(size_t) = 8 bits

### Fixed width integer types
C++11 introduced new types, called [fixed interger types](https://en.cppreference.com/w/cpp/types/integer), that allow you to directly specify the number of bits:
| type | signed / unsigned | bits |
| :--- | :---: | :---: |
| int8_t | signed | 8 bits |
| int16_t | signed | 8 bits |
| int32_t | signed | 16 bits |
| int64_t | signed | 32 bits |
| uint8_t | unsigned | 8 bits |
| uint16_t | unsigned | 8 bits |
| uint32_t | unsigned | 16 bits |
| uint64_t | unsigned | 32 bits |
### Logic
The boolean type, [```bool```](https://en.cppreference.com/w/c/types/boolean), was introduced in C99.  A ```bool``` can take only two values, 0 or 1.
Two associated constants are defined: ```true``` and ```false```.


```C++
CHAR_BIT*sizeof(bool) = 8 bits
true = 1
false = 0
```
## Floating Point Numbers
On modern systems, C++ generally supports three types of floating point number:


```C++
CHAR_BIT*sizeof(float) = 8 bits
CHAR_BIT*sizeof(double) = 16 bits
CHAR_BIT*sizeof(long double) = 32 bits
```
The three types are compared below.
| type | name | bits | standard |  ```digits10``` |  ```max_digits10``` | ```epsilon()``` | ```min()``` | ```lowest()``` | ```max()``` | 
| :--- | :---: | :---: | :---:  | :---:  | :---:  | :---:  | :---:  | :---: | :---: |
| float | Single Precision | 32 bits | [IEEE 754-2008 binary32](https://en.wikipedia.org/wiki/Single-precision_floating-point_format) | 6 |  9 |  1.1920929e-07 |  1.17549435e-38 |  -3.40282347e+38 |  3.40282347e+38 | 
| double | Double Precision | 64 bits | [IEEE 754-2008 binary64](https://en.wikipedia.org/wiki/Double-precision_floating-point_format) | 15 |  17 |  2.2204460492503131e-16 |  2.2250738585072014e-308 |  -1.7976931348623157e+308 |  1.7976931348623157e+308 | 
| long double | Quad Precision | 128 bits | [IEEE 754-2008 binary128](https://en.wikipedia.org/wiki/Quadruple-precision_floating-point_format) | 18 |  21 |  1.08420217248550443401e-19 |  3.36210314311209350626e-4932 |  -1.18973149535723176502e+4932 |  1.18973149535723176502e+4932 | 


The functions ```epsilon()```, ```min()```, ```lowest()```, and  ```max()```, as well as the static values ```digits10``` and ```max_digits10``` are found in [```limits```](https://en.cppreference.com/w/cpp/types/numeric_limits)
The static value ```max_digits10``` was used as the precision for printing the above values.
## Operators
## Functions
## Mixed-typed math and auto-promotion


