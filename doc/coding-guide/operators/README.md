# Mathématiques v3.5.21


<details>

<summary>User Guide</summary>

1. [About](../../about/README.md)<br>
2. [License](../../license/README.md)<br>
3. [Release Notes](../../release-notes/README.md)<br>
4. [Installation](../../installation/README.md)<br>
5. [Makefile / Using Mathématiques](../../using-mathematiques/README.md)<br>
6. [Code Examples](../../examples/README.md)<br>
7. _Coding Guide / Syntax_ <br>
8. [Benchmarks](../../benchmarks/README.md)<br>
9. [Tests](../../test/README.md)<br>
10. [New Feature Plans](../../feature-schedule/README.md)<br>
11. [Developer Guide](../../developer-guide/README.md)<br>


</details>



<details>

<summary>7. Coding Guide / Syntax</summary>

7.1. [Scalar Math: real, imaginary, complex, and quaternions](../scalar/README.md)<br>
7.2. [Vectors](../vector/README.md)<br>
7.3. [Matrices](../matrix/README.md)<br>
7.4. [Tensors](../tensor/README.md)<br>
7.5. [User Guide Notation](../notation/README.md)<br>
7.6. _Operators_ <br>
7.7. [Display of Results](../display/README.md)<br>
7.8. [Linear Algebra](../linear-algebra/README.md)<br>
7.9. [FILE I/O](../file-io/README.md)<br>
7.10. [Debug Modes](../debug/README.md)<br>


</details>



# 7.6. Operators

_This document was generated from the_ C++ _file_ `operators/body.cpp` _using functions and macros in the namespaces_ `mathq::display` _and_ `mathq::md` _in headers_ `"mathq.h"` _and_ `"gitmd.h"`_respectively._ 

## Arithmetic Operators
The operators `+, -, *, /, %` are the addition, subtraction, multiplication, division, and modulus operators respectively.

For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).


| operator | operation | types | 
| :---: | :---: | :---: | 
| `+` | addition | 𝕤, 𝕌 | 
| `-` | subtraction | 𝕤, 𝕌 | 
| `*` | multiplication | 𝕤, 𝕌 | 
| `/` | division | 𝕤, 𝕌 | 
| `%` | modulus | ℤ | 

For container types, the following rules apply for `x op y`:

* For two (zero-depth) containers of the same `rank` and `dimensions`, `x op y` yields the element-wise operation a container of the same `rank` and `dimensions

* All other cases are invalid and will produce unpredictable results or a run-time error. Debug modes will send useful error messages to the stderr.


<br>

### Examples using addition
#### Reals

```C++
1 + 2  =>  int 3
7.5 + 2  =>  double 9.5
7.5 - 0.5  =>  double 7
```

#### Complex, Imaginary and Mixed

```C++
complex<double>(1.5, 0) + complex<double>(0.5, 4)  =>  std::complex<double> (2,4)
Imaginary<double>(1) + Imaginary<double>(33.12)  =>  Imaginary<double> 34.12i
-10 + Imaginary<double>(5.25)  =>  std::complex<double> (-10,5.25)
100 + complex<double>(1.5, 2) + Imaginary<double>(5.25)  =>  std::complex<double> (101.5,7.25)
```

#### Vectors, Matrice, and Tensors

```C++
```

#### Nested Containers

```C++
```

#### Mixed Rank

```C++
```


<br>

## Integer Division
If both numerator and denominator are integers, the division operator gives the integer division result.


<br>

### Examples: integer division
```C++
7 / 2  =>  int 3
```
* The modulus operator `a % b`, gives the remainder after integer divison of `a` by `b`.

```C++
7 % 2  =>  int 1
```
* The function [`std::div`](https://en.cppreference.com/w/cpp/numeric/math/div) can also be used for integer division, It returns both the result and remainder.

```C++
div_t result = div(7, 2);
```
With result:

```C++
result.quot  =>  int 3
result.rem  =>  int 1
```

<br>

## Exponentiation and the `pow` function
C++ does not have an exponentiation operator.  Instead it provides the [`std::pow`](https://en.cppreference.com/w/cpp/numeric/math/div) function
```C++
pow(2, 8)  =>  double 256
pow(25, 1 / 2)  =>  double 1
```

<br>

## Logic Operators
For details refer [Logical Operators](https://en.cppreference.com/w/c/language/operator_logical).


| operator | operation | 
| :---: | :---: | 
| `!` | logical NOT | 
| `\|\|` | logical OR | 
| `&&` | logical AND | 

**CAVEAT**: C++ also has binary bit-wise operators `&` and `|`.  Mistyping the above operators can cause painful bugs. 


Examples:

```C++
true  =>  bool 1
false  =>  bool 0
!true  =>  bool 0
!false  =>  bool 1
true && true  =>  bool 1
true && false  =>  bool 0
true || false  =>  bool 1
```
* In C++ logical operators work for all real and integer types: `0` corresponds to `false` and all non-zero values correspond to `true`

```C++
!true  =>  bool 0
!8  =>  bool 0
!!8.293  =>  bool 1
true && 3  =>  bool 1
true && 0  =>  bool 0
```

<br>

## Relational Operators
For details refer [Comparison Operators](https://en.cppreference.com/w/c/language/operator_comparison).


| operator | operation | 
| :---: | :---: | 
| `==` | equal to | 
| `!=` | not equal to | 
| `<` | less than | 
| `<=` | less than or equal to | 
| `>` | greater than | 
| `>=` | greater than or equal to | 

**CAVEAT**: C++ allows assigment `=` inside `if` statements (eg, `if (a = true) return;`).  Mistyping the equals operator `==` can cause painful bugs. 


Examples:

```C++
(2 == 2)  =>  bool 1
(1 / 2 == 0.5)  =>  bool 0
(1. / 2 == 0.5)  =>  bool 1
(-2 < 34.2)  =>  bool 1
(2 > 0)  =>  bool 1
```

<br>

<hr>
_Linear algebra operators are covered in the Linear Alegbra section._


| ⇦ <br />[User Guide Notation](../notation/README.md)  | [Coding Guide / Syntax](../README.md)<br />Operators<br /><img width=1000/> | ⇨ <br />[Display of Results](../display/README.md)   |
| ------------ | :-------------------------------: | ------------ |

