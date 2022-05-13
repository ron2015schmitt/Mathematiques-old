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
7.2.2. [Complex numbers](../complex/README.md)<br>
7.2.3. [Imaginary numbers](../imaginary/README.md)<br>
7.2.4. _Quaternions_ <br>


</details>



# 7.2.4. Quaternions



## Introduction
The [quaternions](https://mathworld.wolfram.com/Quaternion.html) are a non-communative [division algebra](https://en.wikipedia.org/wiki/Division_algebra).
The quaternions are the third algebra in the sequence of [Cayley–Dickson algebras](https://en.wikipedia.org/wiki/Cayley%E2%80%93Dickson_construction), with the first two algebras being the reals and the complex numbers. 
They were [invented by Hamilton in 1843](https://en.wikipedia.org/wiki/Quaternion), as a generalization of complex numbers.  

A quaternion can be written in terms of a real number, imaginary number, and two other numbers:

q = a + b **i** + c **j** + d **k**

Multiplication of the basis elements is defined as follows.  Note that multiplication is not commutative 

| × | 1 | **i** | **j** | **k** | 
| :---: | :---: | :---: | :---: | :---: |
| 1 |1 | i | j | k | 
| **i** |i | -1 | k | -j | 
| **j** |j | -k | -1 | i | 
| **k** |k | j | -i | -1 | 

The above table is referred to as the [Cayley Table](https://en.wikipedia.org/wiki/Cayley_table) for Quaternions.  Each entry is the product of the row label times the col label.



<br>

## Size of quaternionss
The size of a quaternions is simply _four times_ the size of the underlying arithmetic type:


```C++
☀ CHAR_BIT ➜ 8 bits;

☀ CHAR_BIT * sizeof(int) ➜ 32 bits;
☀ CHAR_BIT * sizeof(Quaternion<int>) ➜ 128 bits;

☀ CHAR_BIT * sizeof(double) ➜ 64 bits;
☀ CHAR_BIT * sizeof(Quaternion<double>) ➜ 256 bits;

☀ CHAR_BIT * sizeof(long double) ➜ 128 bits;
☀ CHAR_BIT * sizeof(Quaternion<long double>) ➜ 512 bits;

```
## Declartion
Declaring quaternion variables in Mathématiques


```C++
auto q1 = Quaternion<double>(1, 2, -1, -3);
auto q2 = Quaternion<double>(4, 3, -2, -5);
auto q = Quaternion<double>() = 16 + 2 * i + 3 * j + 13 * k;
auto p = Quaternion<double>() = 0.53767 + 0.86217 * i - 0.43359 * j + 2.7694 * k;
auto x1 = Quaternion<double>() = 16 + 2 * i + 3 * j + 13 * k;
auto x2 = Quaternion<double>() = 5 + 11 * i + 10 * j + 8 * k;
auto x3 = Quaternion<double>() = 9 + 7 * i + 6 * j + 12 * k;
auto x4 = Quaternion<double>() = 4 + 14 * i + 15 * j + 1 * k;
```
## Arithmetic
```C++
auto v = Vector<Quaternion<double>>({16 + 2 * i + 3 * j + 13 * k, 5 + 11 * i + 10 * j + 8 * k, 9 + 7 * i + 6 * j + 12 * k, 4 + 14 * i + 15 * j + 1 * k});
auto v2 = Vector<Quaternion<double>>({0.53767 + 0.86217 * i - 0.43359 * j + 2.7694 * k, 1.8339 + 0.31877 * i + 0.34262 * j - 1.3499 * k, -2.2588 - 1.3077 * i + 3.5784 * j + 3.0349 * k});
```
## Methods
Assume `q`  is of type `Quaternion<D>` with 

> _q_ = _a_ + _b_ **i** + _c_ **j** + _d_ **k** 

The scalar+vector form of q is 

>  _q_ = _a_ + **v**. 

The polar form of q is: 

> _q_ = ||_q_|| ( cos _φ_ + **n̂** sin _φ_ ). 

where  

> _φ_ ≐  cos<sup-1></sup>( _a_/||_q_|| ). 

and  

> **n̂** ≐ **v**/||**v**||

| syntax | modifies q? | description | 
| :---: | :---: | :---: | 
| `Quaternion<D> invert()` | yes | q := 1/q, returns `q` | 
| `Quaternion<D> negate()` | yes | q := -q, returns `q` | 
| `Quaternion<D> conjugate()` | yes | q := q<sup>*</sup>, returns `q` | 
| `D real()` | no | returns the real part of `q` | 
| `D imag()` | no | returns the i-component part of `q` | 
| `D jmag()` | no | returns the j-component part of `q` | 
| `D kmag()` | no | returns the k-component of `q` | 
| `D abs()` | no | returns \|\|_q_\|\|, the magnitude of `q` | 
| `D normsqr()` | no | returns the magnitude-squared of `q` | 
| `D scalar()` | no | same as real() | 
| `Quaternion<D> normalized()` | no | returns _q_/\|\|_q_\|\| | 
| `Vector<D,3> vector()` | no | returns **v**, the vector part of `q` | 
| `Vector<D,3> unitvector()` | no | returns **n̂**, the vector part of `q` normalized to 1 | 
| `D vabs()` | no | returns, _v_=\|\|**v**\|\| the magnitude of `q.vector()` | 
| `D vnormsqr()` | no | returns \|\|**v**\|\|<sup>2</sup> | 
| `D angle()` | no | returns φ as defined above | 
| `std::tuple<D, D, Vector<D, 3>> polar()` | no | returns { \|\|_q_\|\|, φ, **n̂** } as a tuple | 
| `Matrix<std::complex<D>, 2, 2> matrix2by2()` | no | returns **Q**, the 2x2 matrix form<sup>1</sup> of _q_ | 

1. **Q** = [  _a_ + **i** _b_,  _c_ + **i** _d_; 
             -_c_ + **i** _d_,  _a_ - **i** _b_  ]

## Functions
```C++
☀ v ➜ Vector<Quaternion<double>> {
16 + 2i + 3j + 13k, 
5 + 11i + 10j + 8k, 
9 + 7i + 6j + 12k, 
4 + 14i + 15j + k};
☀ exp(v) ➜ TER_Unary Vector<Quaternion<double>> {
5.35246e+06 + 1.05157e+06i + 1.57736e+06j + 6.83522e+06k, 
-57.3593 + -89.1893i + -81.0812j + -64.865k, 
-6799.09 + 2039.12i + 1747.82j + 3495.64k, 
-6.65998 + 36.9313i + 39.5692j + 2.63795k};
☀ v2 ➜ Vector<Quaternion<double>> {
0.53767 + 0.86217i + -0.43359j + 2.7694k, 
1.8339 + 0.31877i + 0.34262j + -1.3499k, 
-2.2588 + -1.3077i + 3.5784j + 3.0349k};
☀ log(v2) ➜ TER_Unary Vector<Quaternion<double>> {
1.09246 + 0.408481i + -0.205427j + 1.31209k, 
0.843609 + 0.147668i + 0.158716j + -0.62533k, 
1.68067 + -0.53829i + 1.47298j + 1.24926k};
☀ log(exp(v)) ➜ TER_Unary Vector<Quaternion<double>> {
16 + 0.137037i + 0.205556j + 0.890742k, 
5 + -1.28206i + -1.16551j + -0.932411k, 
9 + 1.18714i + 1.01755j + 2.03509k, 
4 + 1.15385i + 1.23627j + 0.082418k};
☀ exp(log(v)) ➜ TER_Unary Vector<Quaternion<double>> {
16 + 2i + 3j + 13k, 
5 + 11i + 10j + 8k, 
9 + 7i + 6j + 12k, 
4 + 14i + 15j + k};
☀ log(exp(v2)) ➜ TER_Unary Vector<Quaternion<double>> {
0.53767 + 0.86217i + -0.43359j + 2.7694k, 
1.8339 + 0.31877i + 0.34262j + -1.3499k, 
-2.2588 + 0.37916i + -1.03754j + -0.879951k};
☀ exp(log(v2)) ➜ TER_Unary Vector<Quaternion<double>> {
0.53767 + 0.86217i + -0.43359j + 2.7694k, 
1.8339 + 0.31877i + 0.34262j + -1.3499k, 
-2.2588 + -1.3077i + 3.5784j + 3.0349k};
☀ log(Quaternion<double>(2, 0, 0, 0)) ➜ Quaternion<double> 0.693147 + -nani + -nanj + -nank;
☀ log(Quaternion<double>(-2, 0, 0, 0)) ➜ Quaternion<double> 0.693147 + -nani + -nanj + -nank;

```
Mathématiques supports the four arithmetic operators for quaternions:

```C++
☀ q1 + q2 ➜ Quaternion<double> 5 + 5i + -3j + -8k;
☀ q1 - q2 ➜ Quaternion<double> -3 + -i + j + 2k;
☀ q1 * q2 ➜ Quaternion<double> -19 + 10i + -5j + -18k;
☀ q2 / q1 ➜ Quaternion<double> 1.8 + -0.4i + 0.2j + 0.4k;
```
Mathématiques supports several methods
```C++
☀ q ➜ Quaternion<double> 16 + 2i + 3j + 13k;
☀ exp(q) ➜ Quaternion<double> 5.35246e+06 + 1.05157e+06i + 1.57736e+06j + 6.83522e+06k;
☀ exp(log(q)) ➜ Quaternion<double> 16 + 2i + 3j + 13k;
☀ p ➜ Quaternion<double> 0.53767 + 0.86217i + -0.43359j + 2.7694k;
☀ log(p) ➜ Quaternion<double> 1.09246 + 0.408481i + -0.205427j + 1.31209k;
☀ log(exp(p)) ➜ Quaternion<double> 0.53767 + 0.86217i + -0.43359j + 2.7694k;
☀ q1 ➜ Quaternion<double> 1 + 2i + -j + -3k;
☀ real(q1) ➜ 1; ☀ imag(q1) ➜ 2; ☀ jmag(q1) ➜ -1; ☀ kmag(q1) ➜ -3; 
☀ q1.scalar() ➜ double 1;
☀ q1.vector() ➜ Vector<double,NE=3> {
2, 
-1, 
-3};
☀ +q1 ➜ Quaternion<double> 1 + 2i + -j + -3k;
☀ -q1 ➜ Quaternion<double> -1 + -2i + j + 3k;
☀ abs(q1) ➜ double 3.87298;
☀ q1 ➜ Quaternion<double> 1 + 2i + -j + -3k;
☀ exp(q1) ➜ Quaternion<double> -2.2434 + -0.820493i + 0.410247j + 1.23074k;
☀ log(q1) ➜ Quaternion<double> 1.35403 + 0.700031i + -0.350016j + -1.05005k;
☀ log(exp(q1)) ➜ Quaternion<double> 1 + -1.3585i + 0.679252j + 2.03776k;
auto w = Quaternion<double>(-2.2434, -0.820493, 0.410247, 1.23074);
☀ w ➜ Quaternion<double> -2.2434 + -0.820493i + 0.410247j + 1.23074k;
☀ log(w) ➜ Quaternion<double> 1 + -1.3585i + 0.679253j + 2.03776k;
☀ exp(log(q1)) ➜ Quaternion<double> 1 + 2i + -j + -3k;
☀ q1 ➜ Quaternion<double> 1 + 2i + -j + -3k;
☀ q1 * q1 ➜ Quaternion<double> -13 + 4i + -2j + -6k;
☀ pow(q1, 2) ➜ Quaternion<double> -13 + 4i + -2j + -6k;
☀ pow(q1, 0.5) ➜ Quaternion<double> 1.56093 + 0.640645i + -0.320323j + -0.960968k;
☀ pow(pow(q1, 0.5), 2) ➜ Quaternion<double> 1 + 2i + -1j + -3k;
☀ q1.angle() ➜ double 1.30964;
☀ q1.abs() ➜ double 3.87298;
☀ q1.vabs() ➜ double 3.74166;
☀ q1.unitvector() ➜ Vector<double,NE=3> {
0.534522, 
-0.267261, 
-0.801784};
☀ q1.abs() ➜ double 3.87298;
☀ normsqr(q1) ➜ double 15;
☀ q1.invert() ➜ Quaternion<double> 0.0666667 + -0.133333i + 0.0666667j + 0.2k;
☀ q1 ➜ Quaternion<double> 0.0666667 + -0.133333i + 0.0666667j + 0.2k;
☀ q1.invert() ➜ Quaternion<double> 1 + 2i + -1j + -3k;
☀ q1 ➜ Quaternion<double> 1 + 2i + -1j + -3k;
☀ inv(q1) ➜ Quaternion<double> 0.0666667 + -0.133333i + 0.0666667j + 0.2k;
☀ conj(q1) ➜ Quaternion<double> 1 + -2i + 1j + 3k;
☀ ~q1 ➜ Quaternion<double> 1 + -2i + 1j + 3k;
☀ q1.matrix2by2() ➜ Matrix<std::complex<double>,NR=2,NC=2> { {(1,2), (-1,-3)}, {(1,-3), (1,-2)} };

☀ q2 * inv(q1) ➜ Quaternion<double> 1.8 + -0.4i + 0.2j + 0.4k;
☀ abs(q1 * q2) ➜ double 28.4605;
☀ q2 ➜ Quaternion<double> 4 + 3i + -2j + -5k;
☀ abs(q2) ➜ double 7.34847;
```
```C++
```


| ⇦ <br />[Imaginary numbers](../imaginary/README.md)  | [Scalar Types](../README.md)<br />Quaternions<br /><img width=1000/> | ⇨ <br />   |
| ------------ | :-------------------------------: | ------------ |

