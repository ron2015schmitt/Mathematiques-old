# Mathématiques v3.5.1


<details>

<summary>User Guide</summary>

1. [About](../../../about/README.md)<br>
2. [License](../../../license/README.md)<br>
3. [Release Notes](../../../release-notes/README.md)<br>
4. [Installation](../../../installation/README.md)<br>
5. [Makefile / Using Mathématiques](../../../using-mathematiques/README.md)<br>
6. [Code Examples](../../../examples/README.md)<br>
7. _Coding Guide / Syntax_ <br>
8. [Benchmarks](../../../benchmarks/README.md)<br>
9. [Tests](../../../test/README.md)<br>
10. [New Feature Plans](../../../feature-schedule/README.md)<br>
11. [Developer Guide](../../../developer-guide/README.md)<br>


</details>



<details>

<summary>Coding Guide / Syntax</summary>


7.1. _Scalar Math: real, imaginary, complex, and quaternion numbers_ <br>
7.2. [Display of Results](../../display/README.md)<br>
7.3. [Vectors](../../vector/README.md)<br>
7.4. [Matrices](../../matrix/README.md)<br>
7.5. [Linear Algebra](../../linear-algebra/README.md)<br>
7.6. [Tensors](../../tensor/README.md)<br>
7.7. [FILE I/O](../../file-io/README.md)<br>
7.8. [Debug Modes](../../debug/README.md)<br>


</details>



<details>

<summary>Scalar Math: real, imaginary, complex, and quaternion numbers</summary>


7.1.1. _Real number mathematics_ <br>
7.1.2. [Imaginary number mathematics](../imaginary/README.md)<br>
7.1.3. [Complex number mathematics](../complex/README.md)<br>
7.1.4. [Quaternion Mathematics](../quaternion/README.md)<br>


</details>



#### 7.1.1. Real number mathematics



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


| ⇦ <br />  | [Scalar Math: real, imaginary, complex, and quaternion numbers](../README.md)<br />Real number mathematics<br /><img width=1000/> | ⇨ <br />[Imaginary number mathematics](../imaginary/README.md)   |
| ------------ | :-------------------------------: | ------------ |

