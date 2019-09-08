
# Calculus in mātricks
_This document was automatically generated from file_ **`calculus.cpp`** (mātricks-v2.14-r5).

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
     0.00000000 10^+00,  3.59258581 10^-05,  1.70120539 10^-04,  4.55494426 10^-04,  9.67968927 10^-04, 
     1.81480149 10^-03,  3.14537111 10^-03,  5.16497344 10^-03,  8.15224148 10^-03,  1.24808658 10^-02, 
     1.86463292 10^-02,  2.72983858 10^-02,  3.92799976 10^-02,  5.56733731 10^-02,  7.78536341 10^-02, 
     1.07550444 10^-01,  1.46917669 10^-01,  1.98610781 10^-01,  2.65871294 10^-01,  3.52616976 10^-01, 
     4.63535995 10^-01,  6.04182490 10^-01,  7.81070350 10^-01,  1.00176128 10^+00,  1.27494259 10^+00, 
     1.61048942 10^+00,  2.01950597 10^+00,  2.51433960 10^+00,  3.10856201 10^+00,  3.81691199 10^+00, 
     4.65519441 10^+00,  5.64013186 10^+00,  6.78916596 10^+00,  8.12020757 10^+00,  9.65133701 10^+00, 
     1.14004577 10^+01,  1.33849091 10^+01,  1.56210469 10^+01,  1.81238025 10^+01,  2.09062323 10^+01, 
     2.39790742 10^+01,  2.73503254 10^+01,  3.10248582 10^+01,  3.50040908 10^+01,  3.92857284 10^+01, 
     4.38635874 10^+01,  4.87275151 10^+01,  5.38634114 10^+01,  5.92533581 10^+01,  6.48758552 10^+01, 
     7.07061588 10^+01,  7.67167147 10^+01,  8.28776723 10^+01,  8.91574651 10^+01,  9.55234375 10^+01, 
     1.01942498 10^+02,  1.08381778 10^+02,  1.14809271 10^+02,  1.21194437 10^+02,  1.27508749 10^+02, 
     1.33726170 10^+02,  1.39823536 10^+02,  1.45780859 10^+02,  1.51581521 10^+02,  1.57212373 10^+02, 
     1.62663734 10^+02,  1.67929311 10^+02,  1.73006024 10^+02,  1.77893774 10^+02,  1.82595156 10^+02, 
     1.87115124 10^+02,  1.91460638 10^+02,  1.95640292 10^+02,  1.99663954 10^+02,  2.03542405 10^+02, 
     2.07287008 10^+02,  2.10909405 10^+02,  2.14421247 10^+02,  2.17833966 10^+02,  2.21158585 10^+02, 
     2.24405564 10^+02,  2.27584693 10^+02,  2.30705009 10^+02,  2.33774759 10^+02,  2.36801376 10^+02, 
     2.39791487 10^+02,  2.42750943 10^+02,  2.45684849 10^+02,  2.48597626 10^+02,  2.51493057 10^+02, 
     2.54374355 10^+02,  2.57244223 10^+02,  2.60104914 10^+02,  2.62958290 10^+02,  2.65805880 10^+02, 
     2.68648922 10^+02,  2.71488419 10^+02,  2.74325169 10^+02,  2.77159807 10^+02,  2.79992832 10^+02, 
     2.82824635 10^+02
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
