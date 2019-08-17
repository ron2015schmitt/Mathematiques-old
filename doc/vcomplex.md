
# Complex-valued Vectors in mātricks
_This document was automatically generated from file_ **`vcomplex.cpp`** (mātricks-v2.1-r66).

### Declaring and assigning complex-valued `Vector`'s


**EXAMPLE 1**: Complex  `Vector` 
```C++
using namespace std;
Vector<complex<double> > v(4);
using namespace literals;
using namespace complex_literals;
v = { 1+1i, 1, 1i, 1-1i }; // C++11 list and C++14 literal `i` for unit imaginary 
```

**Some expressions with results**
```C++
  v:  {(1,1),(1,0),(0,1),(1,-1)}; 
```

### Arithmetic with complex-valued `Vector`'s


**EXAMPLE 2**: Complex  `Vector` 
```C++
using namespace std;
Vector<complex<double> > v1(4);
Vector<complex<double> > v2(4);
using namespace literals;
using namespace complex_literals;
v1 = { 1+1i, 1, 1i, 1-1i }; // C++11 list and C++14 literal `i` for unit imaginary 
v2 = { -1i, 0, 1-1i, 1+1i }; // C++11 list and C++14 literal `i` for unit imaginary 
```

**Some expressions with results**
```C++
  v1+v2:  {(1,0),(1,0),(1,0),(2,0)}; 
  v1-v2:  {(1,2),(1,0),(-1,2),(0,-2)}; 
  v1*v2:  {(1,-1),(0,0),(1,1),(2,0)}; 
  v1/v2:  {(-1,1),(inf,-nan),(-0.5,0.5),(0,-1)}; 
```


[Table of Contents](README.md)
