<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.52-c++17</h1>

<details>

<summary>User Guide</summary>

# [User Guide](../../../README.md)<br>
1. [About](../../../about/README.md)<br>
2. [License](../../../license/README.md)<br>
3. [Status, Release Notes & Planned Work](../../../status-release/README.md)<br>
4. [Description and Example Usage](../../../description-examples/README.md)<br>
5. [Installation](../../../installation/README.md)<br>
6. [Your First Mathématiques Project](../../../first-project/README.md)<br>
7. _Usage Guide: Syntax, Data types, Functions, etc_ <br>
8. [Benchmarks](../../../benchmarks/README.md)<br>
9. [Tests](../../../test/README.md)<br>
10. [Developer Guide: Modifying and Extending Mathématiques](../../../developer-guide/README.md)<br>


</details>



<details>

<summary>Usage Guide: Syntax, Data types, Functions, etc</summary>

# [7. Usage Guide: Syntax, Data types, Functions, etc](../../README.md)<br>
7.1. [User Guide Notation](../../notation/README.md)<br>
7.2. [Scalar Types](../../scalars/README.md)<br>
7.3. [Container Types](../../containers/README.md)<br>
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
7.4.1. [Arithmetic](../arithmetic/README.md)<br>
7.4.2. _Integer Division_ <br>
7.4.3. [Logic](../logic/README.md)<br>
7.4.4. [Relational](../relational/README.md)<br>


</details>



# 7.4.2. Integer Division

_This document was generated from the C++ file_ `integer-division/body.cpp` _using macros and functions (in namespace `mathq::display`) from the header_ `"mathq.h"`. 

C++ also provides support for integer division witjh remainder.

If both numerator and denominator are integers, the division operator gives the integer division result.

For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).


| operator | operation | types | 
| :---: | :---: | :---: | 
| `/` | integer division | 𝕤, 𝕌 | 
| `%` | modulus | ℤ | 


<br>

### Examples: integer division
```C++
☀ 7 / 2 ➜ int 3;
```
* The modulus operator `a % b`, gives the remainder after integer divison of `a` by `b`.

```C++
☀ 7 % 2 ➜ int 1;
```
* The function [`std::div`](https://en.cppreference.com/w/cpp/numeric/math/div) can also be used for integer division, It returns both the result and remainder.

```C++
div_t result = div(7, 2);
```
With result:

```C++
☀ result.quot ➜ int 3;
☀ result.rem ➜ int 1;
```


| ⇦ <br />[Arithmetic](../arithmetic/README.md)  | [Operators](../README.md)<br />Integer Division<br /><img width=1000/> | ⇨ <br />[Logic](../logic/README.md)   |
| ------------ | :-------------------------------: | ------------ |

