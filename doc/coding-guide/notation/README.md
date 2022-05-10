<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.38</h1>

<details>

<summary>User Guide</summary>

# [User Guide](../../README.md)<br>
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

<summary>Coding Guide / Syntax</summary>

# [7. Coding Guide / Syntax](../README.md)<br>
7.1. [Scalar Types](../scalars/README.md)<br>
7.2. [Container Types](../containers/README.md)<br>
7.3. _User Guide Notation_ <br>
7.4. [Operators](../operators/README.md)<br>
7.5. [Functions](../functions/README.md)<br>
7.6. [Display of Results](../display/README.md)<br>
7.7. [Linear Algebra](../linear-algebra/README.md)<br>
7.8. [FILE I/O](../file-io/README.md)<br>
7.9. [Debug Modes](../debug/README.md)<br>


</details>



# 7.3. User Guide Notation

_This document was generated from the C++ file_ `notation/body.cpp` _using macros and functions (in namespace `mathq::display`) from the header_ `"mathq.h"`. 
<br>

The following notation shorthand is used in the User Guide (but certainly not in C++ code!).

### Scalars

| symbol | C++ types |
| :---: | :---: | 
| ℤ | any C++ real signed integral type: `bool`, `int`, `long`, etc | 
| ℕ | any C++ real unsigned integral type: `unsigned int`, `unsigned long`, etc | 
| ℝ | any C++ real floating-point type: `float`, `double`, `long double`) | 
| ℂ | any `std::complex<ℝ>` | 
| 𝕁 | any `Imaginary<ℝ>` | 
| ℍ | any `Quaternion<ℝ>` | 
| 𝕂 | any ℝ, ℂ, 𝕁, ℍ | 
| 𝕤 | any ℤ, 𝕂 | 

Lower case 𝕤 was chosen because 𝕊 is commonly used in mathematics for the spherical groups


<br>

### Containers

| symbol | C++ types |
| :---: | :---: | 
| 𝕍 | any `Vector<T>` for any scalar or container type or type symbol T | 
| 𝕄 | any `Matrix<T>` for any scalar or container type or type symbol T | 
| 𝕥 | any `Tensor<T>` for any scalar or container type or type symbol T | 
| 𝕌 | any 𝕍, 𝕄, 𝕥 | 

Lower case 𝕥 was chosen because 𝕋 is commonly used in mathematics for the torus groups



<br>



| ⇦ <br />[Container Types](../containers/README.md)  | [Coding Guide / Syntax](../README.md)<br />User Guide Notation<br /><img width=1000/> | ⇨ <br />[Operators](../operators/README.md)   |
| ------------ | :-------------------------------: | ------------ |

