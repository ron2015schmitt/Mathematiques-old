
[Table of Contents](README.md)


# Vector functions that return a scalar (dot product, sum, min, max etc) in mātricks
_This document was automatically generated from file_ **`vscalarout.cpp`** (mātricks-v2.29).

### dot product—the `|` operator
* The dot product is accomplished via the `|` operator, such that the dot product takes a form similar to P.A.M. Dirac's 'bra-ket' notation.
* This definition becomes very useful for taking the product of matrices because any number of matrices can be multiplied in a single line of code.


**EXAMPLE 1**: Dot product of two real vectors `(v1|v2)`
```C++
Vector<double> v1(range<double>(1,4));
operator[0] #1
operator[0] #1
operator[1] #1
operator[1] #1
operator[2] #1
operator[2] #1
operator[3] #1
operator[3] #2
operator[2] #2
operator[1] #2
operator[0] #2
Vector<double> v2({1,-1,1,-1}); // C++11 list
```

**Some expressions with results**
```C++
  operator[3] #2
operator[3] #2
operator[2] #2
operator[2] #2
operator[1] #2
operator[1] #2
operator[0] #2
operator[0] #2
(v1|v1) = 30; 
  operator[3] #2
operator[3] #2
operator[2] #2
operator[2] #2
operator[1] #2
operator[1] #2
operator[0] #2
operator[0] #2
(v2|v2) = 4; 
  operator[3] #2
operator[3] #2
operator[2] #2
operator[2] #2
operator[1] #2
operator[1] #2
operator[0] #2
operator[0] #2
(v1|v2) = -2; 
  operator[3] #2
operator[3] #2
operator[2] #2
operator[2] #2
operator[1] #2
operator[1] #2
operator[0] #2
operator[0] #2
(v2|v1) = -2; 
  operator[3] #2
operator[3] #2
operator[2] #2
operator[2] #2
operator[1] #2
operator[1] #2
operator[0] #2
operator[0] #2
(v1|(2*v2+1)) = 6; 
```



**EXAMPLE 2**: Dot product of two complex vectors `(~v1|v2)=(conj(v1)|v2)`

The complex dot product is defined such that the first vector conjugated.  In this manner, the dot product of a complex vector with itself produces a real number.
```C++
using namespace std;
const double tol = 2e-16;
Vector<complex<double> > v1;
v1 = vcomplex(range<double>(1,2), 0.);
operator[0] #1
operator[0] #1
operator[1] #1
operator[0] #2
operator[1] #2
v1.roundzero(tol);
Vector<complex<double> > v2;
v2 = vcomplex(range<double>(-1,-2), range<double>(2,3));
operator[0] #1
operator[0] #1
operator[1] #1
operator[0] #1
operator[0] #1
operator[1] #1
operator[0] #2
operator[0] #2
operator[1] #2
operator[1] #2
v2.roundzero(tol);
```

**Some expressions with results**
```C++
  v1 = {(1,0), (2,0)}; 
  v2 = {(-1,2), (-2,3)}; 
  operator[1] #2
operator[1] #2
operator[0] #2
operator[0] #2
(~v1|v1) = (5,0); 
  operator[1] #2
operator[1] #2
operator[0] #2
operator[0] #2
(~v2|v2) = (18,0); 
  operator[1] #2
operator[1] #2
operator[0] #2
operator[0] #2
(~v1|v2) = (-5,8); 
  operator[1] #2
operator[1] #2
operator[0] #2
operator[0] #2
(~v2|v1) = (-5,-8); 
  operator[1] #2
operator[1] #2
operator[0] #2
operator[0] #2
(~v1|(2*v2+1)) = (-7,16); 
```



**EXAMPLE 3**: `sum` the elements of a vector
```C++
Vector<double> v({1,2,3,4}); // C++11 list initialization
```

**Some expressions with results**
```C++
  operator[0] #2
operator[1] #2
operator[2] #2
operator[3] #2
sum(v) = 10; 
  operator[0] #2
operator[1] #2
operator[2] #2
operator[3] #2
sum(2*exp(v)+1) = 173.582; 
```



**EXAMPLE 4**: `sum` the elements of a vector
```C++
Vector<double> v({1,2,3,4}); // C++11 list initialization
```

**Some expressions with results**
```C++
  operator[0] #2
operator[1] #2
operator[2] #2
operator[3] #2
sum(v) = 10; 
  operator[0] #2
operator[1] #2
operator[2] #2
operator[3] #2
sum(2*exp(v)+1) = 173.582; 
```



**EXAMPLE 5**: `integrate_a2b` a vector over the interval [a,b]
```C++
Vector<double> v;
v = exp(linspace<double>(-1,1,13));
operator[0] #1
operator[1] #1
operator[2] #1
operator[3] #1
operator[4] #1
operator[5] #1
operator[6] #1
operator[7] #1
operator[8] #1
operator[9] #1
operator[10] #1
operator[11] #1
operator[12] #1
operator[0] #2
operator[1] #2
operator[2] #2
operator[3] #2
operator[4] #2
operator[5] #2
operator[6] #2
operator[7] #2
operator[8] #2
operator[9] #2
operator[10] #2
operator[11] #2
operator[12] #2
```

**Some expressions with results** precise value to 16 digits is 2.35040238729 (via Mathematica)
```C++
  operator[0] #2
operator[12] #2
operator[1] #2
operator[2] #2
operator[3] #2
operator[4] #2
operator[5] #2
operator[6] #2
operator[7] #2
operator[8] #2
operator[9] #2
operator[10] #2
operator[11] #2
integrate_a2b(v,-1.,1.) = 2.35584; 
  operator[0] #2
operator[12] #2
operator[1] #2
operator[2] #2
operator[3] #2
operator[4] #2
operator[5] #2
operator[6] #2
operator[7] #2
operator[8] #2
operator[9] #2
operator[10] #2
operator[11] #2
integrate_a2b(v,-1.,1.,2) = 2.35041; 
  operator[0] #2
operator[12] #2
operator[1] #2
operator[2] #2
operator[3] #2
operator[4] #2
operator[5] #2
operator[6] #2
operator[7] #2
operator[8] #2
operator[9] #2
operator[10] #2
operator[11] #2
integrate_a2b(v,-1.,1.,3) = 2.35042; 
  operator[0] #2
operator[12] #2
operator[1] #2
operator[2] #2
operator[3] #2
operator[4] #2
operator[5] #2
operator[6] #2
operator[7] #2
operator[8] #2
operator[9] #2
operator[10] #2
operator[11] #2
integrate_a2b(v,-1.,1.,4) = 2.3504; 
```



**EXAMPLE 6**: Compute the _product_ of the elements of a vector
```C++
Vector<double> v({1,2,3,4}); // C++11 list initialization
```

**Some expressions with results**
```C++
  operator[0] #2
operator[1] #2
operator[2] #2
operator[3] #2
prod(v) = 24; 
  operator[0] #2
operator[1] #2
operator[2] #2
operator[3] #2
prod(2*exp(v)+1) = 460753; 
```



**EXAMPLE 7**: Find the _minimum_ of the elements of a vector
```C++
Vector<double> v({1,20,-1,0}); // C++11 list initialization
```

**Some expressions with results**
```C++
  v = {1, 20, -1, 0}; 
  operator[0] #2
operator[1] #2
operator[2] #2
operator[3] #2
min(v) = -1; 
  2*exp(v)+1 = operator[0] #2
operator[1] #2
operator[2] #2
operator[3] #2
Vector<double> {6.43656, 9.7033e+08, 1.73576, 3}; 
  operator[0] #2
operator[1] #2
operator[2] #2
operator[3] #2
min(2*exp(v)+1) = 1.73576; 
```



**EXAMPLE 8**: Find the _maximum_ of the elements of a vector
```C++
Vector<double> v({1,20,-1,0}); // C++11 list initialization
```

**Some expressions with results**
```C++
  v = {1, 20, -1, 0}; 
  operator[0] #2
operator[1] #2
operator[2] #2
operator[3] #2
max(v) = 20; 
  2*exp(v)+1 = operator[0] #2
operator[1] #2
operator[2] #2
operator[3] #2
Vector<double> {6.43656, 9.7033e+08, 1.73576, 3}; 
  operator[0] #2
operator[1] #2
operator[2] #2
operator[3] #2
max(2*exp(v)+1) = 9.7033e+08; 
```


[Table of Contents](README.md)
