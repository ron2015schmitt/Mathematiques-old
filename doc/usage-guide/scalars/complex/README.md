<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.57-c++17</h1>

<details>

<summary>User Manual</summary>

# [User Manual](../../../README.md)<br>
1. [About](../../../about/README.md)<br>
2. [License](../../../license/README.md)<br>
3. [Status, Planned Work & Release Notes](../../../status-release/README.md)<br>
4. [Description and Example Usage](../../../description-examples/README.md)<br>
5. [Installation](../../../installation/README.md)<br>
6. [Your First Mathématiques Project](../../../first-project/README.md)<br>
7. _Usage Guide: Syntax, Data Types, Functions, etc_ <br>
8. [Benchmarks](../../../benchmarks/README.md)<br>
9. [Tests](../../../test/README.md)<br>
10. [Developer Guide: Modifying and Extending Mathématiques](../../../developer-guide/README.md)<br>


</details>



<details>

<summary>Usage Guide: Syntax, Data Types, Functions, etc</summary>

# [7. Usage Guide: Syntax, Data Types, Functions, etc](../../README.md)<br>
7.1. [Usage Guide Notation](../../notation/README.md)<br>
7.2. _Scalar Types (Real, Imaginary, Complex & Quaternion)_ <br>
7.3. [Container Types (Vector, Matrix & Tensor)](../../containers/README.md)<br>
7.4. [Operators](../../operators/README.md)<br>
7.5. [Functions](../../functions/README.md)<br>
7.6. [Display of Results](../../display/README.md)<br>
7.7. [Linear Algebra](../../linear-algebra/README.md)<br>
7.8. [FILE I/O](../../file-io/README.md)<br>
7.9. [Debug Modes](../../debug/README.md)<br>


</details>



<details>

<summary>Scalar Types (Real, Imaginary, Complex & Quaternion)</summary>

# [7.2. Scalar Types (Real, Imaginary, Complex & Quaternion)](../README.md)<br>
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
☀ c4 ➜ std::complex<double> (1.4,3.5);
☀ c5 ➜ std::complex<double> (1.3,-10.5);
```
In the above expression `c4 = 1.4 + 3.5i`, the C++ operator `std::complex_literals::i` is used. 
This operator can only be used after a number and there can NOT be a space between the number and `i`.  
The operator `i` is a `double`, while `if` and `il` are a `float` and a `long double` respectively.

## Arithmetic
The 4 fundamental arithmetic operators can be used with complex numbers.
```C++

☀ 1.4 + 3.5i + 2.6 + 1.5i ➜ std::complex<double> (4,5);
☀ complex<double>(1.3, -10.5) - complex<double>(1.3, -10.5) ➜ std::complex<double> (0,0);
☀ 2 + 4.5i * 2 + 3i ➜ std::complex<double> (2,12);
☀ 2 + 4.5i / 2 + 3i ➜ std::complex<double> (2,5.25);

```
## Math with mixed types
Mathématiques extends the C++ functionality so that mixed math (ints, floating pt, complex<int>, complex<floating pt>) is possible.
```C++

☀ 1 + 10i ➜ std::complex<double> (1,10);
☀ complex<double>(1.3, -10.5) - complex<int>(1, 3) ➜ std::complex<double> (0.3,-13.5);
☀ complex<double>(1.3, -10.5) - complex<float>(1.2, 5) ➜ std::complex<double> (0.1,-15.5);
☀ 5 + complex<double>(1.3, -10.5) ➜ std::complex<double> (6.3,-10.5);
☀ int(100) + complex<double>(1.3, -10.5) ➜ std::complex<double> (101.3,-10.5);
☀ float(100) + complex<double>(1.3, -10.5) ➜ std::complex<double> (101.3,-10.5);

```
**Without Mathématiques, all of the above expressions will fail to compile!**

Let `OP` be `+`, `-`, `*`, or `/`.

1. `complex<D1> OP complex<D2>` will fail to compile without Mathématiques unless D1==D2

1. `complex<D1> OP D2` will fail to compile without Mathématiques unless D1==D2


The philosophy behind Mathématiques is that the user would rather be concerned with math and algorithms than overly-rigid syntax.


## Functions

Many functions also work on complex numbers.  These are listed in detail in the section on functions.
Below are a few examples.


```C++

☀ sin(1.4 + 3.5i) ➜ std::complex<double> (16.3317,2.8117);
☀ exp((3.1415/2)*1i) ➜ std::complex<double> (4.63268e-05,1);
☀ pow(1.5 + 3i, 0.5) ➜ std::complex<double> (1.5579,0.962835);

```


| ⇦ <br />[Reals](../real/README.md)  | [Scalar Types (Real, Imaginary, Complex & Quaternion)](../README.md)<br />Complex numbers<br /><img width=1000/> | ⇨ <br />[Imaginary numbers](../imaginary/README.md)   |
| ------------ | :-------------------------------: | ------------ |
