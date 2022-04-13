

<details>

<summary>User Guide</summary>

1. [About](about/README.md)<br>
2. [License](license/README.md)<br>
3. [Release Notes](release-notes/README.md)<br>
4. [Example code](examples/README.md)<br>
5. [Installation](installation/README.md)<br>
6. [Using Mathématiques](using-mathematiques/README.md)<br>
7. [Coding Guide / Syntax](coding-guide/README.md)<br>
8. [Benchmarks](benchmarks/README.md)<br>
9. [Tests](test/README.md)<br>
10. [New Feature Schedule](feature-schedule/README.md)<br>
11. [Developer Guide](developer-guide/README.md)<br>


</details>




# 4. Example code

## Examples

### EXAMPLE 1: Element-wise `Vector` math

**Actual C++ code**
```C++
Vector<double> v1(4);
v1 = {10,20,30,40}; 
Vector<double> v2(4);
v2 = {1,2,3,4}; 

disp(v1 + v2);
disp(v1 - v2);
disp(v1 * v2);
disp(v1 / v2);
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

disp(mu);
disp(sigma);
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
disp(v);
disp(A);
disp(A | v);
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

disp(u);
disp(v);
disp(A);
disp(u|A|v);
disp(u|(2*A-1)|(10 * sin(pi / 2 * v) + 5));
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

| ⇦ <br />[3. Release Notes](release-notes/README.md)  | [Table Of Contents](README.md)<br />4. Example code<br /><img width=1000/> | ⇨ <br />[5. Installation](installation/README.md)   |
| ----------- | ----------- | ----------- |