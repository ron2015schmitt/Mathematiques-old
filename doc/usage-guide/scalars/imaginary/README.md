<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.56-c++17</h1>

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
7.2. _Scalar Types: Real, Imaginary, Complex & Quaternion_ <br>
7.3. [Container Types: Vector, Matrix & Tensor](../../containers/README.md)<br>
7.4. [Operators](../../operators/README.md)<br>
7.5. [Functions](../../functions/README.md)<br>
7.6. [Display of Results](../../display/README.md)<br>
7.7. [Linear Algebra](../../linear-algebra/README.md)<br>
7.8. [FILE I/O](../../file-io/README.md)<br>
7.9. [Debug Modes](../../debug/README.md)<br>


</details>



<details>

<summary>Scalar Types: Real, Imaginary, Complex & Quaternion</summary>

# [7.2. Scalar Types: Real, Imaginary, Complex & Quaternion](../README.md)<br>
7.2.1. [Reals](../real/README.md)<br>
7.2.2. [Complex numbers](../complex/README.md)<br>
7.2.3. _Imaginary numbers_ <br>
7.2.4. [Quaternions](../quaternion/README.md)<br>


</details>



# 7.2.3. Imaginary numbers



## Introduction
The [imaginary numbers](https://mathworld.wolfram.com/Imaginary.html) are a non-communative [division algebra](https://en.wikipedia.org/wiki/Division_algebra).



<br>

## Size of imaginary numbers
The size of a imaginary numbers is the same size of the underlying arithmetic type:


```C++
☀ CHAR_BIT ➜ 8 bits;

☀ CHAR_BIT*sizeof(int) ➜ 32 bits;
☀ CHAR_BIT*sizeof(Imaginary<int>) ➜ 32 bits;

☀ CHAR_BIT*sizeof(double) ➜ 64 bits;
☀ CHAR_BIT*sizeof(Imaginary<double>) ➜ 64 bits;

☀ CHAR_BIT*sizeof(long double) ➜ 128 bits;
☀ CHAR_BIT*sizeof(Imaginary<long double>) ➜ 128 bits;

```
## Declaration and initialization
Declaring quaternion variables in Mathématiques


```C++
using namespace mathq;
using namespace mathq::unit_imaginary;

```
In the above expressions we used the constants `i`, `j`, and `k`, which are defined as follows:

```C++
☀ mathq::unit_imaginary::i ➜ Imaginary<double> i;
```
Unlike the standard C++ `i`, which is an operator, the Mathématiques `i`, `j`, and `k` are constants
## Arithmetic
The 4 fundamental arithmetic operators can be used with imaginary numbers.
Mathématiques supports the four arithmetic operators for imaginary numbers:

```C++
```
## Methods
Assume `q`  is of type `Imaginary<D>` with 

| syntax | modifies q? | description | 
| :---: | :---: | :---: | 
| `Imaginary<D> invert()` | yes | q := 1/q, returns `q` | 
| `Imaginary<D> negate()` | yes | q := -q, returns `q` | 
| `Imaginary<D> conjugate()` | yes | q := q<sup>*</sup>, returns `q` | 
| `D real()` | no | returns the real part of `q` | 
| `D imag()` | no | returns the i-component part of `q` | 
| `D abs()` | no | returns \|\|_q_\|\|, the magnitude of `q` | 
| `D normsqr()` | no | returns the magnitude-squared of `q` | 
| `D scalar()` | no | same as real() | 
| `D angle()` | no | returns φ as defined above | 
A few examples are shown below.

```C++
```
## Operators & Functions

C++ supports many functions and Mathématiques provides several more.  These are listed in detail in the sections on opetators and functions.  C++ supports mixed type arithmetic between all the real types.
Below are a few examples.



```C++
double pi = 3.14159265358979311599796346854;
☀ pi ➜ double 3.14159;
☀ 2*sin(pi/4) - 1 ➜ double 0.414214;
☀ 3/pi*asin(0.86602540378) ➜ double 1;
☀ exp(2) ➜ double 7.38906;
☀ log(10) ➜ double 2.30259;
☀ log10(10) ➜ double 1;
☀ pow(2,10) ➜ double 1024;
☀ pow(2,2.5-2) ➜ double 1.41421;
```
## Containers of Imaginary numbers

Mathématiques container classes (ie `Vector<D>`, `Matrix<d>`, and `Tensor<D>` can have imaginary numbers as their underlying type.
Below are examples of container math with imaginary numbers.  Mixed math is allowed.


```C++
```
```C++
```


| ⇦ <br />[Complex numbers](../complex/README.md)  | [Scalar Types: Real, Imaginary, Complex & Quaternion](../README.md)<br />Imaginary numbers<br /><img width=1000/> | ⇨ <br />[Quaternions](../quaternion/README.md)   |
| ------------ | :-------------------------------: | ------------ |

