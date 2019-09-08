
# Calculus in mātricks
_This document was automatically generated from file_ **`calculus.cpp`** (mātricks-v2.14-r15).

## Integration
### Definite integrals
Integrating over an interval [a,b] yields a single number--the area under the curve.

![Definite Integral](DefiniteIntegral.PNG)


**EXAMPLE 1**: Definite integrals
```C++
const size_type N = 100000;
const double a = 0 + 1/double(N);
const double b = 1 - 1/double(N);
Vector<double> x(linspace<double>(a,b,N-1));
Vector<double> f;
f=-log(log(1/x));
```

Integrating f(x), as given above, yields the [Euler–Mascheroni](http://mathworld.wolfram.com/Euler-MascheroniConstant.html) constant whose exact value is `0.577215664901532...`.  The function _f_(_x_) is singular at both x=0 and x=1.  Thus we omitted these points. As the results show, this simple approach to the integral isn't particularly accurate. 

 ![Euler–Mascheron Integral](EulerMascheroniConstant.PNG)

**Results**
```C++
  N = 100000; 
  a = 1e-05; 
  b = 0.99999; 
  integrate_a2b(f,a,b,0) = 0.577156; 
  integrate_a2b(f,a,b,1) = 0.577117; 
  integrate_a2b(f,a,b,2) = 0.577116; 
```

### Semi-Definite Integrals
A semi-definite integral is created by replacing one of the end points with _x_.

* For the integral

![Semi-Definite Integral a2x](SemiDefinite_a2x.PNG)

use the method `.integrate_a2x(a, b, order)`.


* For the integral

![Semi-Definite Integral x2b](SemiDefinite_x2b.PNG)

use the method `.integrate_x2b(a, b, order)`.


Where [`a`,`b`] defines the interval being used and `order` specifies the integration method order: 

* 0 for rectangular integration

* 1 for trapezoidal integration.



A semi-definite integral yields a function as its output.
Integration requires a cumulative sum.  Thus the caculation can not be accomplished via element-wise operations.  For this reasons these functions are performed in place, mimizing both memory usage and computation time.
All of the remaining functions discussed in this section modify the vector _in place_.


**EXAMPLE 2**:  The error function integral
The [error function](http://mathworld.wolfram.com/Erf.html) is the following semi-definite integral of a Gaussian function (with zero mean and variance of 1/2).

![ErrorFunction](ErrorFunction.PNG)
```C++
const size_type N = 101;
const double a = 0;
const double b = 4;
const double pi = 3.14159265358979323846;
Vector<double> x( linspace<double>(a,b,N) );
Vector<double> gauss;
gauss = 2/sqrt(pi)*exp(-sqr(x));
Vector<double> erf = gauss;
erf.integrate_a2x(a,b,1);
set_mathematica_var_format();
```

The results _x_ and _erf_(_x_) are:

```Mathematica
x = {
     0.00000000 10^+00,  4.00000000 10^-02,  8.00000000 10^-02,  1.20000000 10^-01,  1.60000000 10^-01, 
     2.00000000 10^-01,  2.40000000 10^-01,  2.80000000 10^-01,  3.20000000 10^-01,  3.60000000 10^-01, 
     4.00000000 10^-01,  4.40000000 10^-01,  4.80000000 10^-01,  5.20000000 10^-01,  5.60000000 10^-01, 
     6.00000000 10^-01,  6.40000000 10^-01,  6.80000000 10^-01,  7.20000000 10^-01,  7.60000000 10^-01, 
     8.00000000 10^-01,  8.40000000 10^-01,  8.80000000 10^-01,  9.20000000 10^-01,  9.60000000 10^-01, 
     1.00000000 10^+00,  1.04000000 10^+00,  1.08000000 10^+00,  1.12000000 10^+00,  1.16000000 10^+00, 
     1.20000000 10^+00,  1.24000000 10^+00,  1.28000000 10^+00,  1.32000000 10^+00,  1.36000000 10^+00, 
     1.40000000 10^+00,  1.44000000 10^+00,  1.48000000 10^+00,  1.52000000 10^+00,  1.56000000 10^+00, 
     1.60000000 10^+00,  1.64000000 10^+00,  1.68000000 10^+00,  1.72000000 10^+00,  1.76000000 10^+00, 
     1.80000000 10^+00,  1.84000000 10^+00,  1.88000000 10^+00,  1.92000000 10^+00,  1.96000000 10^+00, 
     2.00000000 10^+00,  2.04000000 10^+00,  2.08000000 10^+00,  2.12000000 10^+00,  2.16000000 10^+00, 
     2.20000000 10^+00,  2.24000000 10^+00,  2.28000000 10^+00,  2.32000000 10^+00,  2.36000000 10^+00, 
     2.40000000 10^+00,  2.44000000 10^+00,  2.48000000 10^+00,  2.52000000 10^+00,  2.56000000 10^+00, 
     2.60000000 10^+00,  2.64000000 10^+00,  2.68000000 10^+00,  2.72000000 10^+00,  2.76000000 10^+00, 
     2.80000000 10^+00,  2.84000000 10^+00,  2.88000000 10^+00,  2.92000000 10^+00,  2.96000000 10^+00, 
     3.00000000 10^+00,  3.04000000 10^+00,  3.08000000 10^+00,  3.12000000 10^+00,  3.16000000 10^+00, 
     3.20000000 10^+00,  3.24000000 10^+00,  3.28000000 10^+00,  3.32000000 10^+00,  3.36000000 10^+00, 
     3.40000000 10^+00,  3.44000000 10^+00,  3.48000000 10^+00,  3.52000000 10^+00,  3.56000000 10^+00, 
     3.60000000 10^+00,  3.64000000 10^+00,  3.68000000 10^+00,  3.72000000 10^+00,  3.76000000 10^+00, 
     3.80000000 10^+00,  3.84000000 10^+00,  3.88000000 10^+00,  3.92000000 10^+00,  3.96000000 10^+00, 
     4.00000000 10^+00
}; 
erf = {
     0.00000000 10^+00,  4.50990874 10^-02,  9.00542035 10^-02,  1.34722754 10^-01,  1.78964878 10^-01, 
     2.22644760 10^-01,  2.65631874 10^-01,  3.07802157 10^-01,  3.49039065 10^-01,  3.89234530 10^-01, 
     4.28289776 10^-01,  4.66116007 10^-01,  5.02634945 10^-01,  5.37779218 10^-01,  5.71492603 10^-01, 
     6.03730117 10^-01,  6.34457960 10^-01,  6.63653329 10^-01,  6.91304101 10^-01,  7.17408392 10^-01, 
     7.41974023 10^-01,  7.65017886 10^-01,  7.86565245 10^-01,  8.06648966 10^-01,  8.25308708 10^-01, 
     8.42590092 10^-01,  8.58543840 10^-01,  8.73224930 10^-01,  8.86691757 10^-01,  8.99005316 10^-01, 
     9.10228427 10^-01,  9.20425003 10^-01,  9.29659362 10^-01,  9.37995609 10^-01,  9.45497068 10^-01, 
     9.52225784 10^-01,  9.58242093 10^-01,  9.63604249 10^-01,  9.68368120 10^-01,  9.72586950 10^-01, 
     9.76311170 10^-01,  9.79588273 10^-01,  9.82462732 10^-01,  9.84975970 10^-01,  9.87166365 10^-01, 
     9.89069294 10^-01,  9.90717206 10^-01,  9.92139722 10^-01,  9.93363749 10^-01,  9.94413623 10^-01, 
     9.95311246 10^-01,  9.96076247 10^-01,  9.96726140 10^-01,  9.97276483 10^-01,  9.97741036 10^-01, 
     9.98131921 10^-01,  9.98459771 10^-01,  9.98733872 10^-01,  9.98962305 10^-01,  9.99152071 10^-01, 
     9.99309212 10^-01,  9.99438921 10^-01,  9.99545645 10^-01,  9.99633178 10^-01,  9.99704740 10^-01, 
     9.99763059 10^-01,  9.99810434 10^-01,  9.99848796 10^-01,  9.99879761 10^-01,  9.99904674 10^-01, 
     9.99924655 10^-01,  9.99940629 10^-01,  9.99953359 10^-01,  9.99963471 10^-01,  9.99971478 10^-01, 
     9.99977798 10^-01,  9.99982771 10^-01,  9.99986670 10^-01,  9.99989719 10^-01,  9.99992095 10^-01, 
     9.99993940 10^-01,  9.99995369 10^-01,  9.99996472 10^-01,  9.99997320 10^-01,  9.99997971 10^-01, 
     9.99998468 10^-01,  9.99998847 10^-01,  9.99999135 10^-01,  9.99999353 10^-01,  9.99999518 10^-01, 
     9.99999642 10^-01,  9.99999734 10^-01,  9.99999804 10^-01,  9.99999856 10^-01,  9.99999894 10^-01, 
     9.99999922 10^-01,  9.99999943 10^-01,  9.99999959 10^-01,  9.99999970 10^-01,  9.99999978 10^-01, 
     9.99999984 10^-01
}; 
```
Cut and paste the above data for `x` and `erf` into Mathematica as well as the following commands

```Mathematica
p1=ListPlot[Partition[Riffle[x,erf],2],PlotStyle->Red];
p2=Plot[Erf[0,x],{x,0,4}];
Show[p1,p2]
```
This yields the following plot comparing the results above [red dots] to the exact function [solid blue].
![ErrorFunctionPlot](ErrorFunctionPlot.png)
## Differentiation
 Differentiation requires points around it. For this reasons these functions are performed in place, mimizing both memory usage and computation time.


**EXAMPLE 3**: Derivatives
```C++
Vector<double> v1(5);
```

**Some expressions with results**
```C++
```

## Various related functions
All of these functions modify the vector _in place_.


**EXAMPLE 4**: Various functions: `cumsum`, `cumprod`, `cumtrapz`, `diff`, etc
```C++
set_default_format();
Vector<double> v1(5);
```

**Some expressions with results**
```C++
  v1 = {1,4,9,16,25} = {1,4,9,16,25}; 
  v1.cumsum() = {1,5,14,30,55}; 
  v1 = {1,4,9,16,25} = {1,4,9,16,25}; 
  v1.cumtrapz() = {0,2.5,9,21.5,42}; 
  v1 = {1,2,3,4,5} = {1,2,3,4,5}; 
  v1.cumprod() = {1,2,6,24,120}; 
  v1 = {1,4,9,16,25} = {1,4,9,16,25}; 
  v1.diff() = {3,3,5,7,9}; 
  v1 = {1,4,9,16,25} = {1,4,9,16,25}; 
  v1.diff(true) = {-24,3,5,7,9}; 
  v1 = {25,16,9,4,1} = {25,16,9,4,1}; 
  v1.cumsum_rev() = {55,30,14,5,1}; 
  v1 = {25,16,9,4,1} = {25,16,9,4,1}; 
  v1.cumtrapz_rev() = {42,21.5,9,2.5,0}; 
  v1 = {5,4,3,2,1} = {5,4,3,2,1}; 
  v1.cumprod_rev() = {120,24,6,2,1}; 
  v1 = {1,4,9,16,25} = {1,4,9,16,25}; 
  v1.diff_rev() = {3,5,7,9,9}; 
  v1 = {1,4,9,16,25} = {1,4,9,16,25}; 
  v1.diff_rev(true) = {3,5,7,9,-24}; 
```

The suffix `_rev` denote that the function starts at the highest element instead of the lowest element. Passing `true` to diff signifies that the function is periodic over the interval [a,b]. 

[Table of Contents](README.md)
