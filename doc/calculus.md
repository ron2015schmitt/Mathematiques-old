
# Calculus in mātricks
_This document was automatically generated from file_ **`calculus.cpp`** (mātricks-v2.14-r6).

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

![Semi-Definite Integral a2x](SemiDefinite_a2x.PNG)

![Semi-Definite Integral x2b](SemiDefinite_x2b.PNG)

A semi-definite integral yields a function as its output.
Integration requires a cumulative sum.  Thus the caculation can not be accomplished via element-wise operations.  For this reasons these functions are performed in place, mimizing both memory usage and computation time.
All of the remaining functions discussed in this section modify the vector _in place_.


**EXAMPLE 2**:  The error function integral
The [error function](http://mathworld.wolfram.com/Erf.html) is the following semi-definite integral of the Gaussian function.

![ErrorFunction](ErrorFunction.PNG)
```C++
const size_type N = 101;
const double a = -4;
const double b = 4;
const double pi = 3.14159265358979323846;
Vector<double> x( linspace<double>(a,b,N) );
Vector<double> erf;
erf = 2/sqrt(pi)*exp(-sqr(x)/2);
erf.integrate_a2x(a,b,1);
set_mathematica_var_format();
```

The results _x_ and _f_(_x_) are:

```Mathematica
x = {
    -4.00000000 10^+00, -3.92000000 10^+00, -3.84000000 10^+00, -3.76000000 10^+00, -3.68000000 10^+00, 
    -3.60000000 10^+00, -3.52000000 10^+00, -3.44000000 10^+00, -3.36000000 10^+00, -3.28000000 10^+00, 
    -3.20000000 10^+00, -3.12000000 10^+00, -3.04000000 10^+00, -2.96000000 10^+00, -2.88000000 10^+00, 
    -2.80000000 10^+00, -2.72000000 10^+00, -2.64000000 10^+00, -2.56000000 10^+00, -2.48000000 10^+00, 
    -2.40000000 10^+00, -2.32000000 10^+00, -2.24000000 10^+00, -2.16000000 10^+00, -2.08000000 10^+00, 
    -2.00000000 10^+00, -1.92000000 10^+00, -1.84000000 10^+00, -1.76000000 10^+00, -1.68000000 10^+00, 
    -1.60000000 10^+00, -1.52000000 10^+00, -1.44000000 10^+00, -1.36000000 10^+00, -1.28000000 10^+00, 
    -1.20000000 10^+00, -1.12000000 10^+00, -1.04000000 10^+00, -9.60000000 10^-01, -8.80000000 10^-01, 
    -8.00000000 10^-01, -7.20000000 10^-01, -6.40000000 10^-01, -5.60000000 10^-01, -4.80000000 10^-01, 
    -4.00000000 10^-01, -3.20000000 10^-01, -2.40000000 10^-01, -1.60000000 10^-01, -8.00000000 10^-02, 
     0.00000000 10^+00,  8.00000000 10^-02,  1.60000000 10^-01,  2.40000000 10^-01,  3.20000000 10^-01, 
     4.00000000 10^-01,  4.80000000 10^-01,  5.60000000 10^-01,  6.40000000 10^-01,  7.20000000 10^-01, 
     8.00000000 10^-01,  8.80000000 10^-01,  9.60000000 10^-01,  1.04000000 10^+00,  1.12000000 10^+00, 
     1.20000000 10^+00,  1.28000000 10^+00,  1.36000000 10^+00,  1.44000000 10^+00,  1.52000000 10^+00, 
     1.60000000 10^+00,  1.68000000 10^+00,  1.76000000 10^+00,  1.84000000 10^+00,  1.92000000 10^+00, 
     2.00000000 10^+00,  2.08000000 10^+00,  2.16000000 10^+00,  2.24000000 10^+00,  2.32000000 10^+00, 
     2.40000000 10^+00,  2.48000000 10^+00,  2.56000000 10^+00,  2.64000000 10^+00,  2.72000000 10^+00, 
     2.80000000 10^+00,  2.88000000 10^+00,  2.96000000 10^+00,  3.04000000 10^+00,  3.12000000 10^+00, 
     3.20000000 10^+00,  3.28000000 10^+00,  3.36000000 10^+00,  3.44000000 10^+00,  3.52000000 10^+00, 
     3.60000000 10^+00,  3.68000000 10^+00,  3.76000000 10^+00,  3.84000000 10^+00,  3.92000000 10^+00, 
     4.00000000 10^+00
}; 
erf = {
     0.00000000 10^+00,  3.59258581 10^-05,  8.50602694 10^-05,  1.51831475 10^-04,  2.41992232 10^-04, 
     3.62960297 10^-04,  5.24228519 10^-04,  7.37853348 10^-04,  1.01903018 10^-03,  1.38676287 10^-03, 
     1.86463292 10^-03,  2.48167143 10^-03,  3.27333313 10^-03,  4.28256716 10^-03,  5.56097387 10^-03, 
     7.17002962 10^-03,  9.18235431 10^-03,  1.16829871 10^-02,  1.47706274 10^-02,  1.85587882 10^-02, 
     2.31767997 10^-02,  2.87705947 10^-02,  3.55031977 10^-02,  4.35548384 10^-02,  5.31226078 10^-02, 
     6.44195768 10^-02,  7.76733067 10^-02,  9.31236887 10^-02,  1.11020072 10^-01,  1.31617655 10^-01, 
     1.55173147 10^-01,  1.81939738 10^-01,  2.12161436 10^-01,  2.46066896 10^-01,  2.83862853 10^-01, 
     3.25727363 10^-01,  3.71803029 10^-01,  4.22190458 10^-01,  4.76942171 10^-01,  5.36057238 10^-01, 
     5.99476856 10^-01,  6.67081108 10^-01,  7.38687099 10^-01,  8.14048623 10^-01,  8.92857463 10^-01, 
     9.74746387 10^-01,  1.05929381 10^+00,  1.14603003 10^+00,  1.23444496 10^+00,  1.32399704 10^+00, 
     1.41412318 10^+00,  1.50424931 10^+00,  1.59380139 10^+00,  1.68221632 10^+00,  1.76895255 10^+00, 
     1.85349997 10^+00,  1.93538889 10^+00,  2.01419773 10^+00,  2.08955925 10^+00,  2.16116524 10^+00, 
     2.22876950 10^+00,  2.29218911 10^+00,  2.35130418 10^+00,  2.40605589 10^+00,  2.45644332 10^+00, 
     2.50251899 10^+00,  2.54438350 10^+00,  2.58217946 10^+00,  2.61608492 10^+00,  2.64630661 10^+00, 
     2.67307321 10^+00,  2.69662870 10^+00,  2.71722628 10^+00,  2.73512266 10^+00,  2.75057305 10^+00, 
     2.76382678 10^+00,  2.77512374 10^+00,  2.78469151 10^+00,  2.79274315 10^+00,  2.79947576 10^+00, 
     2.80506955 10^+00,  2.80968756 10^+00,  2.81347572 10^+00,  2.81656337 10^+00,  2.81906400 10^+00, 
     2.82107632 10^+00,  2.82268538 10^+00,  2.82396379 10^+00,  2.82497302 10^+00,  2.82576468 10^+00, 
     2.82638172 10^+00,  2.82685959 10^+00,  2.82722732 10^+00,  2.82750850 10^+00,  2.82772212 10^+00, 
     2.82788339 10^+00,  2.82800436 10^+00,  2.82809452 10^+00,  2.82816129 10^+00,  2.82821043 10^+00, 
     2.82824635 10^+00
}; 
```
Cut and paste the above data for `x` and `erf` into Mathematica as well as the following commands

```Mathematica
p1=ListPlot[Partition[Riffle[x,erf],2],PlotStyle->Red];
p2=Plot[Erf[0,x],{x,-4,4}];
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
