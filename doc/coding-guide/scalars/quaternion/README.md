<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.38</h1>

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

7.1. _Scalar Types_ <br>
7.2. [Container Types](../../containers/README.md)<br>
7.3. [User Guide Notation](../../notation/README.md)<br>
7.4. [Operators](../../operators/README.md)<br>
7.5. [Functions](../../functions/README.md)<br>
7.6. [Display of Results](../../display/README.md)<br>
7.7. [Linear Algebra](../../linear-algebra/README.md)<br>
7.8. [FILE I/O](../../file-io/README.md)<br>
7.9. [Debug Modes](../../debug/README.md)<br>


</details>



<details>

<summary>Scalar Types</summary>

# [7.1. Scalar Types](../README.md)<br>
7.1.1. [Reals](../real/README.md)<br>
7.1.2. [Complex numbers](../complex/README.md)<br>
7.1.3. [Imaginary numbers](../imaginary/README.md)<br>
7.1.4. _Quaternions_ <br>


</details>



# 7.1.4. Quaternions



## Introduction
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


```C++
auto q1 = Quaternion<double>(1, 2, -1, -3);
auto q2 = Quaternion<double>(4, 3, -2, -5);

☀ q1 ➜ Quaternion<double> 1 + 2i + -j + -3k;
☀ real(q1) ➜ 1; ☀ imag(q1) ➜ 2; ☀ jmag(q1) ➜ -1; ☀ kmag(q1) ➜ -3; 
☀ q1.scalar() ➜ double 1;
☀ q1.vector() ➜ Vector<double,NE=3> {2, -1, -3};
☀ q2 ➜ Quaternion<double> 4 + 3i + -2j + -5k;
☀ q1 * q2 ➜ Quaternion<double> -19 + 10i + -5j + -18k;
☀ abs(q1 * q2) ➜ double 28.4605;
```


| ⇦ <br />[Imaginary numbers](../imaginary/README.md)  | [Scalar Types](../README.md)<br />Quaternions<br /><img width=1000/> | ⇨ <br />   |
| ------------ | :-------------------------------: | ------------ |

