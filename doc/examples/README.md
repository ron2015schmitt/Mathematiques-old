<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.31</h1>

<details>

<summary>User Guide</summary>

# [User Guide](../README.md)<br>
1. [About](../about/README.md)<br>
2. [License](../license/README.md)<br>
3. [Release Notes](../release-notes/README.md)<br>
4. [Installation](../installation/README.md)<br>
5. [Makefile / Using Mathématiques](../using-mathematiques/README.md)<br>
6. _Code Examples_ <br>
7. [Coding Guide / Syntax](../coding-guide/README.md)<br>
8. [Benchmarks](../benchmarks/README.md)<br>
9. [Tests](../test/README.md)<br>
10. [New Feature Plans](../feature-schedule/README.md)<br>
11. [Developer Guide](../developer-guide/README.md)<br>


</details>



# 6. Code Examples

## Examples

### EXAMPLE 1: Element-wise `Vector` math

**Actual C++ code**
```C++
Vector<double> v1(4);
v1 = {10,20,30,40}; 
Vector<double> v2(4);
v2 = {1,2,3,4}; 

DISP(v1 + v2);
DISP(v1 - v2);
DISP(v1 * v2);
DISP(v1 / v2);
```

**Text Output**
```C++
  v1 + v2 = Vector<double> {11, 22, 33, 44}; 
  v1 - v2 = Vector<double> {9, 18, 27, 36}; 
  v1 * v2 = Vector<double> {10, 40, 90, 160}; 
  v1 / v2 = Vector<double> {10, 10, 10, 10}; 
```

### EXAMPLE 2: Complicated Element-wise `Vector` math

**Actual C++ code**
```C++
Vector<double> u( linspace<double>(-1,1,21) );
Vector<double> v;
v = 10*sin(pi/2*u) + 10;

const double N = double(v.size());
double mu = sum(v)/N;
double sigma = norm(v-mu)/sqrt(N-1);

DISP(mu);
DISP(sigma);
```

**Text Output**
```C++
mu = 10; 
sigma = 7.4162; 
```

### EXAMPLE 3: Linear Algebra

Inner product is designated by the `|` operator, eg ```M | v```.  You can optionally enclose in parentheses so that it looks similar to Dirac's bra-ket notation: ```(M | v)```.

Note that in bra-ket notation, vectors are neither row nor column vector.  Their behavior is determined by context.   If you would like to create row/column vectors the syntax is: ```Matrix<double> A(N,1)``` for column vectors and ```Matrix<double> A(1,N)``` for row vectors


**Actual C++ code**
```C++
Vector<double> v({2, -1});
Matrix<double> A({{1, 2}, {3, 4}, {5, 6}});
DISP(v);
DISP(A);
DISP(A | v);
```

**Text Output**
```C++
v = {2, -1}; 
A = [
    1, 2
    3, 4
    5, 6
]; 
A|v = {0, 2, 4}; 
```

### EXAMPLE 4: Complicated Linear Algebra

This example is the bilinear form for a matrix ```A``` and two vectors ```u``` and ```v```.  From context, ```u``` behaves as a row vector and ```v``` behaves as acolumn vector.

**Actual C++ code**
```C++
Vector<double> v({2, -1});
Vector<double> u({1, -2, 4});
Matrix<double> A({{1, 2}, {3, 4}, {5, 6}});

DISP(u);
DISP(v);
DISP(A);
DISP(u|A|v);
DISP(u|(2*A-1)|(10 * sin(pi / 2 * v) + 5));
```

**Text Output**
```C++
u = {1, -2, 4}; 
v = {2, -1}; 
A = [
    1, 2
    3, 4
    5, 6
]; 
u|A|v = 12; 
u|(2*A-1)|(10 * sin(pi / 2 * v) + 5) = -30; 
```


| ⇦ <br />[Makefile / Using Mathématiques](../using-mathematiques/README.md)  | [User Guide](../README.md)<br />Code Examples<br /><img width=1000/> | ⇨ <br />[Coding Guide / Syntax](../coding-guide/README.md)   |
| ------------ | :-------------------------------: | ------------ |

