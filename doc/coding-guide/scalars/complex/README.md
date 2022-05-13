<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.43</h1>

<details>

<summary>User Guide</summary>

# [User Guide](../../../README.md)<br>
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

# [7. Coding Guide / Syntax](../../README.md)<br>
7.1. [User Guide Notation](../../notation/README.md)<br>
7.2. _Scalar Types_ <br>
7.3. [Container Types](../../containers/README.md)<br>
7.4. [Operators](../../operators/README.md)<br>
7.5. [Functions](../../functions/README.md)<br>
7.6. [Display of Results](../../display/README.md)<br>
7.7. [Linear Algebra](../../linear-algebra/README.md)<br>
7.8. [FILE I/O](../../file-io/README.md)<br>
7.9. [Debug Modes](../../debug/README.md)<br>


</details>



<details>

<summary>Scalar Types</summary>

# [7.2. Scalar Types](../README.md)<br>
7.2.1. [Reals](../real/README.md)<br>
7.2.2. _Complex numbers_ <br>
7.2.3. [Imaginary numbers](../imaginary/README.md)<br>
7.2.4. [Quaternions](../quaternion/README.md)<br>


</details>



# 7.2.2. Complex numbers



## Introduction
C++ supports [complex numbers](https://mathworld.wolfram.com/ComplexNumber.html) via the template class `std::complex<D>`, where D is some integer or real type. 

In this documentation, we denote complex number types using the symbol, ℂ.

<br>

## Size of complex numbers
The size of a complex number is simply _twice_ the size of the underlying arithmetic type:


```C++
CHAR_BIT = 8 bits

CHAR_BIT*sizeof(int) = 32 bits
CHAR_BIT*sizeof(complex<int>) = 64 bits

CHAR_BIT*sizeof(double) = 64 bits
CHAR_BIT*sizeof(complex<double>) = 128 bits

CHAR_BIT*sizeof(long double) = 128 bits
CHAR_BIT*sizeof(complex<long double>) = 256 bits

```
## Declaration and initialization
Complex numbers can be declared and initialized in a variety of ways.


```C++
#include <complex>;
#include <cmath>;
...
using namespace std;
using namespace std::complex_literals;
complex<double> c1;
complex<double> c2 = complex<double>(2, -3.5);
complex<double> c3(1, 2.3);
complex<double> c4 = 1.4 + 3.5i;
auto c5 = complex<double>(1.3, -10.5);
☀ c1 ➜ std::complex<double> (0,0);
☀ c2 ➜ std::complex<double> (2,-3.5);
☀ c3 ➜ std::complex<double> (1,2.3);
☀ 1i ➜ std::complex<double> (0,1);
☀ c4 ➜ std::complex<double> (1.4,3.5);
☀ c5 ➜ std::complex<double> (1.3,-10.5);
```
In the above expression `c4 = 1.4 + 3.5i`, the C++ operator `std::complex_literals::i` is used. 
This operator can only be used after a number and there can NOT be a space between the number and `i`.  
The operator `i` is a `double`, while `if` and `il` are a `float` and a `long double` respectively.



| ⇦ <br />[Reals](../real/README.md)  | [Scalar Types](../README.md)<br />Complex numbers<br /><img width=1000/> | ⇨ <br />[Imaginary numbers](../imaginary/README.md)   |
| ------------ | :-------------------------------: | ------------ |

