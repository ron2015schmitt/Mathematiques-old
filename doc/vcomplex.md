
# Complex-valued Vectors in mātricks
_This document was automatically generated from file_ **`vcomplex.cpp`** (mātricks-v2.1-r84).

### Representing the unit imaginary _i_
* In C++, there is no definition for pure imaginary numbers.
* This is in contrast to Fortran.
* The unit imaginary is thus `complex<D>(0,1`


**EXAMPLE 1**: The unit imaginary _i_ in C++14

* In C++14, the unit imaginary is defined by the product operator `operator""i`
```C++
using namespace std;
using namespace literals;
using namespace complex_literals;
complex<double> z1 = 1i;
complex<double> z2 = 1+1i;
complex<double> z3 = -5i;
complex<double> z4 = 5;
```
**Some expressions with results**
```C++
  z1:  (0,1); 
  z2:  (1,1); 
  z3:  (0,-5); 
  z4:  (5,0); 
```



**EXAMPLE 2**: The unit imaginary _i_ (works in any version)

In earlier versions of C++, the unit imaginary can be defined by
```C++
using namespace std;
const complex<double> i = complex<double>(0,1);
complex<double> z1 = 1.*i;
complex<double> z2 = 1. + 1.*i;
complex<double> z3 = -5.*i;
complex<double> z4 = 5;
```

**Some expressions with results**
```C++
  z1:  (0,1); 
  z2:  (1,1); 
  z3:  (-0,-5); 
  z4:  (5,0); 
```

### Declaring a complex-valued `Vector`


**EXAMPLE 3**: Complex  `Vector` 
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


**EXAMPLE 4**: Complex `Vector` arithmetic
```C++
using namespace std;
Vector<complex<double> > v1(4);
Vector<complex<double> > v2(4);
using namespace literals;
using namespace complex_literals;
v1 = { -1i, 0, 1-1i, 1+1i }; // C++11 list and C++14 literal `i` for unit imaginary 
v2 = { 1+1i, 1, 1i, -1i }; // C++11 list and C++14 literal `i` for unit imaginary 
```

**Some expressions with results**
```C++
  v1+v2:  {(1,0),(1,0),(1,0),(1,0)}; 
  v1-v2:  {(-1,-2),(-1,0),(1,-2),(1,2)}; 
  v1*v2:  {(1,-1),(0,0),(1,1),(1,-1)}; 
  v1/v2:  {(-0.5,-0.5),(0,0),(-1,-1),(-1,1)}; 
```

### Arithmetic with complex and real vectors and scalars `Vector`'s


**EXAMPLE 5**: Mixed real and complex arithmetic 
```C++
using namespace std;
Vector<double > vr(4);
Vector<complex<double> > vc(4);
using namespace literals;
using namespace complex_literals;
vr = { 1, 2, 3, 4 }; // C++11 list 
vc = { 1+1i, 1, 1i, -1i }; // C++11 list and C++14 literal `i` for unit imaginary 
```

**Some expressions with results**
```C++
  vr+vc:  {(2,1),(3,0),(3,1),(4,-1)}; 
  vr-vc:  {(0,-1),(1,-0),(3,-1),(4,1)}; 
  vr*vc:  {(1,1),(2,0),(0,3),(0,-4)}; 
  vr/vc:  {(0.5,-0.5),(2,0),(0,-3),(-0,4)}; 
  2.*vr + vc/2. + 1:  {(inf,inf),(inf,0),(7,inf),(9,-inf)}; 
  complex<double>(0,1)*vr + complex<double>(5,2)*vc:  {(3,8),(5,4),(-2,8),(2,-1)}; 
```



**EXAMPLE 6**: real and imaginary parts
```C++
using namespace std;
Vector<complex<double> > v(4);
v = {1+1.i, 1., 1.i, 2-5.i}; // C++11 list and C++14 imag
```

**Some expressions with results**: real and imaginary parts
```C++
  v:  {(1,1),(1,0),(0,1),(2,-5)}; 
  real(v):  {1,1,0,2}; 
  imag(v):  {1,0,1,-5}; 
```



[Table of Contents](README.md)
