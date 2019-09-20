
# Calculus in mātricks
_This document was automatically generated from file_ **`calculus.cpp`** (mātricks-v2.16-r20).

## Integration
### Definite integrals
Integrating over an interval (a,b) yields a single number--the area under the curve.

![Definite Integral](DefiniteIntegral.png)


**EXAMPLE 1**: Definite integrals
```C++
const size_type N = 100000;
const double a = 0;
const double b = 1;
Vector<double> x(linspace_ab<double>(a,b,N));
Vector<double> f;
f=-log(log(1/x));
```

Integrating f(x), as given above, yields the [Euler–Mascheroni](http://mathworld.wolfram.com/Euler-MascheroniConstant.html) constant whose exact value is `0.577215664901532...`.  The function _f_(_x_) is singular at both x=0 and x=1.  Thus we omitted these points. As the results show, many points are needed to achieve even a few digits of accuracy, due to the singularities. 

 ![Euler–Mascheron Integral](EulerMascheroniConstant.png)

**Results**
```C++
  N = 100000; 
  a = double; 
  b = double; 
  integrate_a2b(f,a,b,0) = double; 
  integrate_a2b(f,a,b,1) = double; 
  integrate_a2b: Number of points must be odd N=100000
integrate_a2b(f,a,b,2) = double; 
```

### Semi-Definite Integrals
A semi-definite integral is created by replacing one of the end points with _x_.

* For the integral

![Semi-Definite Integral a2x](SemiDefinite_a2x.png)

use the method `f.integrate_a2x(a, b)` or the function `integrate_a2x(f, a, b)`.


* For the integral

![Semi-Definite Integral x2b](SemiDefinite_x2b.png)

use the method `f.integrate_x2b(a, b)` or the function `integrate_x2b(f, a, b)`.


Where [`a`,`b`] defines the interval being used



A semi-definite integral yields a function as its output.
Integration requires a cumulative sum.  Thus the caculation can not be accomplished via element-wise operations.  For this reasons these functions can be performed: 
  * on a Vector in place using `f.integrate_a2x(a, b)`, mimizing both memory usage and computation time.
  * on a Vector or expression using the function `integrate_a2x(f, a, b)`,  in which case a `new Vector` is created inside the function and returned. 
All of the remaining functions discussed in this page can be called in either manner.


**EXAMPLE 2**:  The error function integral
The [error function](http://mathworld.wolfram.com/Erf.html) is the following semi-definite integral of a Gaussian function (with zero mean and variance of 1/2).

![ErrorFunction](ErrorFunction.png)
```C++
const size_type N = 101;
const double a = 0;
const double b = 4;
const double pi = 3.14159265358979323846;
Vector<double> x( linspace<double>(a,b,N) );
Vector<double> gauss;
gauss = 2/sqrt(pi)*exp(-sqr(x));
Vector<double> erf = gauss;
erf.integrate_a2x(a,b);
set_mathematica_var_format();
                                                                               
** mātricks ERROR:    illegal format string "% 10.8e" passed to Format<double>
                                                                               
                                                                               
** mātricks ERROR:    illegal format string "%s + I*%s" passed to setFormatStringComplex
                                                                               
```

The results _x_ and _erf_(_x_) are:

```Mathematica
x = {
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^
}; 
erf = {
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^
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
### Semi-Definite Integrals: optional parameters
The optional `order` parameter specifies the integration method order: 

* 0 for rectangular integration

* 1 for trapezoidal integration (DEFAULT).

Usage: 

* `f.integrate_x2b(a, b, order)`
* `integrate_x2b(f, a, b, order)`
## Differentiation
* Differentiation requires points around it.   The derivative can be performed :
  * on a Vector in place using `f.deriv(a, b)`, mimizing both memory usage and computation time.
  * on a Vector or expression using the function `deriv(f, a, b)`,  in which case a `new Vector` is created inside the function and returned. 


**EXAMPLE 3**: Derivative of the function _f_(_x_) = 5 _x_


The derivative of the function _f_(_x_) = is the constant 5
```C++
set_default_format();
                                                                               
** mātricks ERROR:    illegal format string "(%s, %s)" passed to setFormatStringComplex
                                                                               
const double pi = 3.14159265358979323846;
const size_type N = 11;
const double a = 0;
const double b = 1;
Vector<double> x( linspace<double>(a,b,N) );
```

**Results**
```C++
  x = {double,double,double,double,double,double,double,double,double,double,double}; 
  deriv(5*x,a,b) = {double,double,double,double,double,double,double,double,double,double,double}; 
```

### Differentiation: optional parameters
* The differentiation method/function has 3 optional parameters:
  * `f.deriv(a, b, n, Dpts, periodic)` or `deriv(f, a, b, n, Dpts, periodic)`
* The optional parameters are:
  * `n` [DEFAULT=`1`] is the number of derivatives to compute: 
  * `Dpts` [DEFAULT=`7`] is the number of points to use in the calculation: 2,3,5, or 7.  More points yield better accuracy. 
  * `periodic` [DEFAULT=`false`]. When set to `true` the derivative at the end points will be of higher accuracy for periodic function.
### Differentiation: taking multiple derivatives in one call


**EXAMPLE 4**: The fourth derivative of sin _x_


Here we take the 4th derivative of sin _x_ using `Dpts`=2,3,5, and 7 points. The result for all should be sin _x_:


![4th derivative of sin(x)](fourthDerivativeOfSin.png)


We also set `periodic=true` since sin _x_ is periodic over [0,2pi)
```C++
set_mathematica_var_format();
                                                                               
** mātricks ERROR:    illegal format string "% 10.8e" passed to Format<double>
                                                                               
                                                                               
** mātricks ERROR:    illegal format string "%s + I*%s" passed to setFormatStringComplex
                                                                               
const double pi = 3.14159265358979323846;
const size_type N = 25;
const double a = 0;
const double b = 2*pi;
Vector<double> x( linspace_b<double>(a,b,N) );
Vector<double> f = sin(x);
Vector<double> f2 = deriv(f,a,b,4,2,true );
Vector<double> f3 = deriv(f,a,b,4,3,true );
Vector<double> f5 = deriv(f,a,b,4,5,true );
Vector<double> f7 = deriv(f,a,b,4,7,true );
```

```Mathematica
x = {
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^
}; 
f2 = {
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^
}; 
f3 = {
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^
}; 
f5 = {
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^
}; 
f7 = {
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^
}; 
```
Cut and paste the above data for `x`, `f2`, `f3`,...  into Mathematica as well as the following commands

```Mathematica
p2 = ListPlot[Partition[Riffle[x, f2], 2], PlotStyle -> {Red, PointSize[0.01], Opacity[0.9]},PlotLegends -> {"Dpts=2"}];
p3 = ListPlot[Partition[Riffle[x, f3], 2], PlotStyle -> {Orange, PointSize[0.01], Opacity[0.75]}, PlotLegends -> {"Dpts=3"}];
p5 = ListPlot[Partition[Riffle[x, f5], 2], PlotStyle -> {Green, PointSize[0.01], Opacity[0.5]}, PlotLegends -> {"Dpts=5"}];
p7 = ListPlot[Partition[Riffle[x, f7], 2],PlotStyle -> {Black, PointSize[0.005], Opacity[0.9]}, PlotLegends -> {"Dpts=7"}];
p = Plot[Sin[x], {x, 0, 2*Pi}, PlotLegends -> {"sin(x)"}];
Show[p, p2, p3, p5, p7]
```
This yields the following plot comparing the results above [dots] to the exact function [solid blue].
![The Fourth Derivative of Sin(x)](FourthDerivativeSinPlot.png)
From these results we observe:
* the 2 point derivative has a bias that shifts the data to the right by 1/2 a grid point for each derivative taken.
* the 3 point derivative is approximately correct: rms error = 2.9%
* the 5 point derivative is very accurate:         rms error = 0.04%
* the 7 point derivative is even more accurate:    rms error = 5ppm


The root mean square (rms) errors were calculated in Mathematica using the following commands.
```Mathematica
RootMeanSquare[f2 - Sin[x]]*100
RootMeanSquare[f3 - Sin[x]]*100
RootMeanSquare[f5 - Sin[x]]*100
RootMeanSquare[f7 - Sin[x]]*10^6
```
## Various functions related to integration and differentiation
All of these functions can be called _either_ as a method, eg `v.cumsum()` or a function `cumsum(v)`.


**EXAMPLE 5**: Various functions: `cumsum`, `cumprod`, `cumtrapz`, `diff`, etc
```C++
set_default_format();
                                                                               
** mātricks ERROR:    illegal format string "(%s, %s)" passed to setFormatStringComplex
                                                                               
Vector<double> v1(5);
```

**Some expressions with results**
```C++
  v1 = {1,4,9,16,25} = {double,double,double,double,double}; 
  v1.cumsum() = {double,double,double,double,double}; 
  v1 = {1,4,9,16,25} = {double,double,double,double,double}; 
  v1.cumtrapz() = {double,double,double,double,double}; 
  v1 = {1,2,3,4,5} = {double,double,double,double,double}; 
  v1.cumprod() = {double,double,double,double,double}; 
  v1 = {1,4,9,16,25} = {double,double,double,double,double}; 
  v1.diff() = {double,double,double,double,double}; 
  v1 = {1,4,9,16,25} = {double,double,double,double,double}; 
  v1.diff(true) = {double,double,double,double,double}; 
  v1 = {25,16,9,4,1} = {double,double,double,double,double}; 
  v1.cumsum_rev() = {double,double,double,double,double}; 
  v1 = {25,16,9,4,1} = {double,double,double,double,double}; 
  v1.cumtrapz_rev() = {double,double,double,double,double}; 
  v1 = {5,4,3,2,1} = {double,double,double,double,double}; 
  v1.cumprod_rev() = {double,double,double,double,double}; 
  v1 = {1,4,9,16,25} = {double,double,double,double,double}; 
  v1.diff_rev() = {double,double,double,double,double}; 
  v1 = {1,4,9,16,25} = {double,double,double,double,double}; 
  v1.diff_rev(true) = {double,double,double,double,double}; 
```

The suffix `_rev` denote that the function starts at the highest element instead of the lowest element. Passing `true` to diff signifies that the function is periodic over the interval [a,b]. 

[Table of Contents](README.md)
