# Mathématiques v3.5.23


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

<summary>7. Coding Guide / Syntax</summary>

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

<summary>7.4. Operators</summary>

7.4.1. [Arithmetic](../arithmetic/README.md)<br>
7.4.2. [Integer Division](../integer-division/README.md)<br>
7.4.3. _Logic_ <br>
7.4.4. [Relational](../relational/README.md)<br>


</details>



# 7.4.3. Logic

_This document was generated from the_ C++ _file_ `logic/body.cpp` _using functions and macros in the namespaces_ `mathq::display` _and_ `mathq::md` _in headers_ `"mathq.h"` _and_ `"gitmd.h"`_respectively._ 


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
true  ➜  bool 1
false  ➜  bool 0
!true  ➜  bool 0
!false  ➜  bool 1
true && true  ➜  bool 1
true && false  ➜  bool 0
true || false  ➜  bool 1
```
* In C++ logical operators work for all real and integer types: `0` corresponds to `false` and all non-zero values correspond to `true`

```C++
!true  ➜  bool 0
!8  ➜  bool 0
!!8.293  ➜  bool 1
true && 3  ➜  bool 1
true && 0  ➜  bool 0
```

<br>



| ⇦ <br />[Integer Division](../integer-division/README.md)  | [Operators](../README.md)<br />Logic<br /><img width=1000/> | ⇨ <br />[Relational](../relational/README.md)   |
| ------------ | :-------------------------------: | ------------ |

