
# Complex-valued Vectors in mātricks
_This document was automatically generated from file_ **`vcomplex.cpp`** (mātricks-v2.13-r29).

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
  ~z2:  (1,-1); 
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
  v:  {1 + i*1, 1 + i*0, 0 + i*1, 1 + i*-1}; 
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
  v1+v2:  {1 + i*0, 1 + i*0, 1 + i*0, 1 + i*0}; 
  v1-v2:  {-1 + i*-2, -1 + i*0, 1 + i*-2, 1 + i*2}; 
  v1*v2:  {1 + i*-1, 0 + i*0, 1 + i*1, 1 + i*-1}; 
  v1/v2:  {-0.5 + i*-0.5, 0 + i*0, -1 + i*-1, -1 + i*1}; 
```

### Mixed arithmetic with complex and real vectors and scalars `Vector`'s


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
  vr+vc:  {2 + i*1, 3 + i*0, 3 + i*1, 4 + i*-1}; 
  vr-vc:  {0 + i*-1, 1 + i*-0, 3 + i*-1, 4 + i*1}; 
  vr*vc:  {1 + i*1, 2 + i*0, 0 + i*3, 0 + i*-4}; 
  vr/vc:  {0.5 + i*-0.5, 2 + i*0, 0 + i*-3, -0 + i*4}; 
  2.*vr + vc/2. + 1:  {3.5 + i*0.5, 5.5 + i*0, 7 + i*0.5, 9 + i*-0.5}; 
  complex<double>(0,1)*vr + complex<double>(5,2)*vc:  {3 + i*8, 5 + i*4, -2 + i*8, 2 + i*-1}; 
```

### real and imag parts of `Vector`'s


**EXAMPLE 6**: get the real and imaginary part of a complex vector
```C++
using namespace std;
Vector<complex<double> > v(4);
v = {1+1.i, 1., 1.i, 2-5.i}; // C++11 list and C++14 imag
```

**Some expressions with results**: real and imaginary parts
```C++
  v:  {1 + i*1, 1 + i*0, 0 + i*1, 2 + i*-5}; 
  real(v):  {1, 1, 0, 2}; 
  imag(v):  {1, 0, 1, -5}; 
```


### creating complex Vectors from real vectors and scalars


**EXAMPLE 7**: create a complex vector from two real vectors
```C++
using namespace std;
Vector<complex<double> > vc(4);
Vector<double> vr( range<double>(1,4) );
Vector<double> vi( range<double>(-1,-4) );
vc = vcomplex(vr, vi);
```

**Some expressions with results**: create a complex vector from two real vectors
```C++
  vr:  {1, 2, 3, 4}; 
  vi:  {-1, -2, -3, -4}; 
  vc:  {1 + i*-1, 2 + i*-2, 3 + i*-3, 4 + i*-4}; 
  real(vc):  {1, 2, 3, 4}; 
  imag(vc):  {-1, -2, -3, -4}; 
```




**EXAMPLE 8**: create a complex vector from a real vector and a scalar
```C++
using namespace std;
Vector<double> v( range<double>(1,4) );
```

**Some expressions with results**: create a complex vector from a real vector and a scalar
```C++
  vcomplex(v, 0.):  {1 + i*0, 2 + i*0, 3 + i*0, 4 + i*0}; 
  vcomplex(v, 1.):  {1 + i*1, 2 + i*1, 3 + i*1, 4 + i*1}; 
  vcomplex(0., v):  {0 + i*1, 0 + i*2, 0 + i*3, 0 + i*4}; 
  vcomplex(1., v):  {1 + i*1, 1 + i*2, 1 + i*3, 1 + i*4}; 
```


### Complex Conjugation
Complex cojugation can be performed via the function `conj` or via the operator `~`


**EXAMPLE 9**: compute the complex conjugate of a vector
```C++
using namespace std;
Vector<complex<double> > vc(3);
Vector<double> vr( range<double>(1,3) );
Vector<double> vi( range<double>(-1,1) );
vc = vcomplex(vr, vi);
```

**Some expressions with results**: compute the complex conjugate of a vector
```C++
  vr:  {1, 2, 3}; 
  vi:  {-1, 0, 1}; 
  vc:  {1 + i*-1, 2 + i*0, 3 + i*1}; 
  conj(vc):  {1 + i*1, 2 + i*-0, 3 + i*-1}; 
  ~vc:  {1 + i*1, 2 + i*-0, 3 + i*-1}; 
```


* Functions defined for complex vectors  


**EXAMPLE10**: functions of complex vectors
```C++
const double pi = 3.14159265358979323846;
using namespace std;
Vector<complex<double> > v(3);
Vector<double> vr( range<double>(1,3) );
Vector<double> vi( range<double>(-1,1) );
v = vcomplex(vr, vi);
```

**Some expressions with results**: functions of complex vectors
```C++
  v:  {1 + i*-1, 2 + i*0, 3 + i*1}; 
  abs(v)* ( cos(arg(v)) + vcomplex(0., sin(arg(v))) ):  {1 + i*-1, 2 + i*0, 3 + i*1}; 
  exp(v):  {1.46869 + i*-2.28736, 7.38906 + i*0, 10.8523 + i*16.9014}; 
  round(exp(v)):  {1 + i*-2, 7 + i*0, 11 + i*17}; 
  v + 0.1:  {1.1 + i*-1, 2.1 + i*0, 3.1 + i*1}; 
  0.1 + v:  {1.1 + i*-1, 2.1 + i*0, 3.1 + i*1}; 
  v - 0.1:  {0.9 + i*-1, 1.9 + i*0, 2.9 + i*1}; 
  0.1 - v:  {-0.9 + i*1, -1.9 + i*-0, -2.9 + i*-1}; 
  roundzero(v+1e-16):  {1 + i*-1, 2 + i*0, 3 + i*1}; 
```



[Table of Contents](README.md)
