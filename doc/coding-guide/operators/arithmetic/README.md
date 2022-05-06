<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.26</h1>

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
7.1. [Scalar Types](../../scalars/README.md)<br>
7.2. [Container Types](../../containers/README.md)<br>
7.3. [User Guide Notation](../../notation/README.md)<br>
7.4. _Operators_ <br>
7.5. [Functions](../../functions/README.md)<br>
7.6. [Display of Results](../../display/README.md)<br>
7.7. [Linear Algebra](../../linear-algebra/README.md)<br>
7.8. [FILE I/O](../../file-io/README.md)<br>
7.9. [Debug Modes](../../debug/README.md)<br>


</details>



<details>

<summary>Operators</summary>

# [7.4. Operators](../README.md)<br>

7.4.1. _Arithmetic_ <br>
7.4.2. [Integer Division](../integer-division/README.md)<br>
7.4.3. [Logic](../logic/README.md)<br>
7.4.4. [Relational](../relational/README.md)<br>


</details>



# 7.4.1. Arithmetic

_This document was generated from the_ C++ _file_ `arithmetic/body.cpp` _using functions and macros in the namespaces_ `mathq::display` _and_ `mathq::md` _in headers_ `"mathq.h"` _and_ `"gitmd.h"`_respectively._ 

## Arithmetic Operators
The operators `+, -, *, /` are the addition, subtraction, multiplication, and division operators respectively.

For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).


| operator | operation | types | 
| :---: | :---: | :---: | 
| `+` | addition | 𝕤, 𝕌 | 
| `-` | subtraction | 𝕤, 𝕌 | 
| `*` | multiplication | 𝕤, 𝕌 | 
| `/` | division | 𝕤, 𝕌 | 

For container types, the following rules apply for `x op y`:

* For two (zero-depth) containers of the same `rank` and `dimensions`, `x op y` yields the element-wise operation a container of the same `rank` and `dimensions

* All other cases are invalid and will produce unpredictable results or a run-time error. Debug modes will send useful error messages to the stderr.


<br>

## Exponentiation and the `pow` function
C++ does not have an exponentiation operator.  Instead it provides the [`std::pow`](https://en.cppreference.com/w/cpp/numeric/math/div) function
```C++
pow(2, 8) ➜  double 256
pow(25, 1 / 2) ➜  double 1
```

<br>

## Examples using addition
#### Reals

```C++
1 + 2 ➜  int 3
7.5 + 2 ➜  double 9.5
7.5 - 0.5 ➜  double 7
```

#### Complex, Imaginary and Mixed

```C++
complex<double>(1.5, 0) + complex<double>(0.5, 4) ➜  std::complex<double> (2,4)
```

#### Imaginary

```C++
complex<double>(1.5, 0) + complex<double>(0.5, 4) ➜  std::complex<double> (2,4)
Imaginary<double>(1) + Imaginary<double>(33.12) ➜  Imaginary<double> 34.12i
-10 + Imaginary<double>(5.25) ➜  std::complex<double> (-10,5.25)
100 + complex<double>(1.5, 2) + Imaginary<double>(5.25) ➜  std::complex<double> (101.5,7.25)
```

#### Mixed Type

```C++
complex<double>(1.5, 0) + complex<double>(0.5, 4) ➜  std::complex<double> (2,4)
Imaginary<double>(1) + Imaginary<double>(33.12) ➜  Imaginary<double> 34.12i
-10 + Imaginary<double>(5.25) ➜  std::complex<double> (-10,5.25)
100 + complex<double>(1.5, 2) + Imaginary<double>(5.25) ➜  std::complex<double> (101.5,7.25)
```

#### Containers

```C++
```

#### Nested Containers

```C++
```

#### Mixed Rank Math

```C++
```

#### Mixed Depth Math

```C++
```



| ⇦ <br />  | [Operators](../README.md)<br />Arithmetic<br /><img width=1000/> | ⇨ <br />[Integer Division](../integer-division/README.md)   |
| ------------ | :-------------------------------: | ------------ |

