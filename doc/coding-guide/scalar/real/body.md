

## Integers
### Signed Integers
C++ supports several different signed integer types.  The size of each depends on the CPU and compiler.  However, for a 64-bit CPU running Linux, they are consistently the same:


```C++
  sizeof(char) = 1; 
  sizeof(short) = 2; 
  sizeof(int) = 4; 
  sizeof(long) = 8; 
  sizeof(long long) = 8; 
```
The C++ function [```sizeof()```](https://en.cppreference.com/w/cpp/language/sizeof) yields the size in _bytes_ of the argument, which can be a type, variable, or expression.

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
### Indexing Types
sizeof(off_t) = 8
sizeof(size_t) = 8
## Floating Point Numbers
sizeof(float) = 4
sizeof(double) = 8
sizeof(double double) = 16
## Auto-promotion
