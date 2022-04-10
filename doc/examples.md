

<details>

  <summary>Table of Contents</summary>

1. [About](about.md)
2. [License](license.md)
3. [Release Notes](release-notes.md)
4. [Example code](examples.md)
5. [Installation](installation.md)
6. [Using Mathématiques](using-mathematiques.md)
7. [Coding Guide / Syntax](coding-guide.md)
8. [Benchmarks](benchmarks.md)
9. [Tests](test.md)
10. [New Feature Schedule](feature-schedule.md)
11. [Developer Guide](developer-guide.md)


</details>




# 4-Example code


**EXAMPLE 1**: Dot product of two real vectors `(v1|v2)`

**variable initialization**
```C++
Vector<double> v1(range<double>(1,4));
Vector<double> v2({1,-1,1,-1}); // C++11 list
```

**Some expressions with results**
```C++
  (v1|v1) = 30; 
  (v1|(2*v2+1)) = 6; 
```

**EXAMPLE 2**: Element-wise `Vector` math

**variable initialization**
```C++
Vector<double> v1(4);
v1 = {10,20,30,40}; // C++11 list
Vector<double> v2(4);
v2 = {1,2,3,4}; // C++11 list
```

**Some expressions with results**
```C++
  v1 + v2 = Vector<double> {11, 22, 33, 44}; 
  v1 - v2 = Vector<double> {9, 18, 27, 36}; 
  v1 * v2 = Vector<double> {10, 40, 90, 160}; 
  v1 / v2 = Vector<double> {10, 10, 10, 10}; 
```

**EXAMPLE 3**: math with scalars and `Vector`s

**variable initialization**
```C++
Vector<double> v1(4);
v1 = {10,20,30,40}; // C++11 list
```

**Some expressions with results**
```C++
  v1 + 1 = Vector<double> {11, 21, 31, 41}; 
  1 + 120 / v1 - 8/8 + 5*v1*2 = Vector<double> {112, 206, 304, 403}; 
```

**EXAMPLE 4**: functions of a `Vector`

**variable initialization**
```C++
Vector<double> v(7);
v = {-2.5,-2.25,-1,0,1,2.25,2.5}; // C++11 list
```

**Some expressions with results**
```C++
  floor(v) = Vector<double> {-3, -3, -1, 0, 1, 2, 2}; 
  round(v) = Vector<double> {-3, -2, -1, 0, 1, 2, 3}; 
```

| ⇦ <br />[3-Release Notes](release-notes.md)  | [Table Of Contents](README.md)<br />4-Example code<br /><img width=1000/> | ⇨ <br />[5-Installation](installation.md)   |
| ----------- | ----------- | ----------- |
