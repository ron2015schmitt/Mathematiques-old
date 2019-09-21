
[Table of Contents](README.md)


# Calculating a function via Fourier series and plotting the results in Matlab
_This document was automatically generated from file_ **`fourier.cpp`** (mātricks-v2.16-r23).

## Fourier Series for the Clausen Functions
As our example, we'll use the [Clausen functions](http://mathworld.wolfram.com/ClausenFunction.html). The Clausen function of order _n_ has Fourier series: 
![Clausen Functions](ClausenDefinition.png)
### Clausen function of order _n=1_


Set up the output format so that we can copy and paste into Matlab
```C++
using namespace display;
FormatDataVector::string_opening = "[ ...\n    ";
FormatDataVector::string_delimeter = ", ";
FormatDataVector::max_elements_per_line = 5;
FormatDataVector::string_endofline = " ...\n    ";
FormatDataVector::string_closing = " ...\n]";
setFormatString<double>("% 10.8e");
                                                                               
** mātricks ERROR:    illegal format string "% 10.8e" passed to Format<double>
                                                                               
FormatData<double>::tens = false;
```

Define the coefficient vectors: 

```C++
const size_type N = 20;
Vector<double> k = range<double>(0,N-1);
Vector<double> An = 1/k;
An[0] = 0.;
Vector<double> Bn = Vector<double>(N,0.);
```

Define the coordinate vector `t` as 51 points over the interval [0,+2pi]: 

```C++
const double pi = 3.14159265358979323846;
Vector<double> t = linspace<double>(0,2*pi,51);
```

Calculate the Fourier series and store the results in vector `CL1`: 

```C++
const double T = 2*pi;
const double omega = 2*pi/T;
Vector<double> CL1 = ifourier(An,Bn, t, An.size(), omega );
```

The results `t` and `CL1` are:

```Matlab
t = [ ...
    0, 0.125664, 0.251327, 0.376991, 0.502655,  ...
    0.628319, 0.753982, 0.879646, 1.00531, 1.13097,  ...
    1.25664, 1.3823, 1.50796, 1.63363, 1.75929,  ...
    1.88496, 2.01062, 2.13628, 2.26195, 2.38761,  ...
    2.51327, 2.63894, 2.7646, 2.89027, 3.01593,  ...
    3.14159, 3.26726, 3.39292, 3.51858, 3.64425,  ...
    3.76991, 3.89557, 4.02124, 4.1469, 4.27257,  ...
    4.39823, 4.52389, 4.64956, 4.77522, 4.90088,  ...
    5.02655, 5.15221, 5.27788, 5.40354, 5.5292,  ...
    5.65487, 5.78053, 5.90619, 6.03186, 6.15752,  ...
    6.28319 ...
]; 
CL1 = [ ...
    3.54774, 2.3765, 1.18838, 1.08954, 0.670212,  ...
    0.449883, 0.366845, 0.101723, 0.0716511, -0.0702907,  ...
    -0.188548, -0.203656, -0.347537, -0.362834, -0.423506,  ...
    -0.507164, -0.493691, -0.582134, -0.589925, -0.605337,  ...
    -0.668655, -0.636695, -0.687731, -0.690152, -0.671363,  ...
    -0.718771, -0.671363, -0.690152, -0.687731, -0.636695,  ...
    -0.668655, -0.605337, -0.589925, -0.582134, -0.493691,  ...
    -0.507164, -0.423506, -0.362834, -0.347537, -0.203656,  ...
    -0.188548, -0.0702907, 0.0716511, 0.101723, 0.366845,  ...
    0.449883, 0.670212, 1.08954, 1.18838, 2.3765,  ...
    3.54774 ...
]; 
```
Cut and paste the above data for `t` and `CL1` into Matlab as well as the following commands

```Matlab
N=10000;
dt=2*pi/N;
tt=linspace(dt,2*pi-dt,10000);
y1=-log(2*abs(sin(tt/2)));
plot(t,CL1,'r.',tt,y1)
```
The above matlab code calculates the first Clausen function using the equation


![Closed form for CL1(t)](ClausenFormula_n1.png)


We exclude the end points, 0 and pi, because the function is infinite at these points.
This yields the following plot comparing the Fourier series [red dots] to the exact function [solid blue].
![Fourier Series for CL1</sub>(t)](ClausenFourierSeries_n1.png)
### Clausen function of order _n=2_


Set up the output format so that we can copy and paste into Matlab, this time using the function `set_matlab_var_format()`
```C++
set_matlab_var_format();
                                                                               
** mātricks ERROR:    illegal format string "% 10.8e" passed to Format<double>
                                                                               
                                                                               
** mātricks ERROR:    illegal format string "%s + i*%s" passed to setFormatStringComplex
                                                                               
```

Define the coefficient vectors: 

```C++
const size_type N = 20;
Vector<double> k = range<double>(0,N-1);
Vector<double> An = Vector<double>(N,0.);
Vector<double> Bn = 1./sqr(k);
Bn[0] = 0.;
```

Define the coordinate vector `t` as 51 points over the interval [0,+2pi]: 

```C++
const double pi = 3.14159265358979323846;
Vector<double> t = linspace<double>(0,2*pi,51);
```

Calculate the Fourier series and store the results in vector `CL2`: 

```C++
const double T = 2*pi;
const double omega = 2*pi/T;
Vector<double> CL2 = ifourier(An,Bn, t, An.size(), omega );
```

The results `t` and `CL2` are:

```Matlab
t = [ ...
    0, 0.125664, 0.251327, 0.376991, 0.502655,  ...
    0.628319, 0.753982, 0.879646, 1.00531, 1.13097,  ...
    1.25664, 1.3823, 1.50796, 1.63363, 1.75929,  ...
    1.88496, 2.01062, 2.13628, 2.26195, 2.38761,  ...
    2.51327, 2.63894, 2.7646, 2.89027, 3.01593,  ...
    3.14159, 3.26726, 3.39292, 3.51858, 3.64425,  ...
    3.76991, 3.89557, 4.02124, 4.1469, 4.27257,  ...
    4.39823, 4.52389, 4.64956, 4.77522, 4.90088,  ...
    5.02655, 5.15221, 5.27788, 5.40354, 5.5292,  ...
    5.65487, 5.78053, 5.90619, 6.03186, 6.15752,  ...
    6.28319 ...
]; 
CL2 = [ ...
    0, 0.391567, 0.600043, 0.741013, 0.855181,  ...
    0.920044, 0.974362, 1.00264, 1.01204, 1.01443,  ...
    0.995652, 0.972211, 0.93764, 0.891563, 0.843917,  ...
    0.783913, 0.721453, 0.654424, 0.579352, 0.505676,  ...
    0.424673, 0.342573, 0.260247, 0.172247, 0.0878556,  ...
    -2.15361e-16, -0.0878556, -0.172247, -0.260247, -0.342573,  ...
    -0.424673, -0.505676, -0.579352, -0.654424, -0.721453,  ...
    -0.783913, -0.843917, -0.891563, -0.93764, -0.972211,  ...
    -0.995652, -1.01443, -1.01204, -1.00264, -0.974362,  ...
    -0.920044, -0.855181, -0.741013, -0.600043, -0.391567,  ...
    -9.123e-16 ...
]; 
```
Cut and paste the above data for t and CL2 into Matlab as well as the following commands.

```Matlab
N=10000;
dt=2*pi/N;
tt=linspace(dt,2*pi-dt,10000);
y2=cumtrapz(-log(2*abs(sin(tt/2))))*dt;
plot(t,CL2,'r.',tt,y2)
```
The above matlab code calculates the second Clausen function using the following integral


![Closed form for CL2(t)](ClausenFormula_n2.png)


We exclude the end points, 0 and pi, because the integrand is infinite at these points.
This yields the following plot comparing the Fourier series [red dots] to the exact function [solid blue].
![Fourier Series for CL2(t)](ClausenFourierSeries_n2.png)

[Table of Contents](README.md)
