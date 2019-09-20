
# Calculating a Taylor series and plotting the results in Mathematica
_This document was automatically generated from file_ **`taylor.cpp`** (mātricks-v2.16-r20).

## Taylor Series for the Bessel Function J<sub>0</sub>(r)
We can easily calculate a [Taylor Series](http://mathworld.wolfram.com/TaylorSeries.html) in matricks. As an example, let's calculate the Taylor series for the [Bessel Function of the first kind](http://mathworld.wolfram.com/BesselFunctionoftheFirstKind.html) of order 0, J<sub>0</sub>(r). 
The first 20 (n=0,1,...19) coefficients for  J<sub>0</sub>(r), are:

                                                                               
** mātricks ERROR:    illegal format string "% 10.8e" passed to Format<double>
                                                                               
                                                                               
** mātricks ERROR:    illegal format string "%s + I*%s" passed to setFormatStringComplex
                                                                               
```C++
J0Coeffs = {
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^
}; 
```
These were determined using the following `Mathematica` command

```Mathematica
N[Table[SeriesCoefficient[BesselJ[0,r],{r,0,n}],{n,0,19}]]

```


Set up the output format so that we can copy and paste into Mathematica
```C++
using namespace display;
FormatDataVector::string_opening = "{\n    ";
FormatDataVector::string_delimeter = ", ";
FormatDataVector::max_elements_per_line = 5;
FormatDataVector::string_endofline = "\n    ";
FormatDataVector::string_closing = "\n}";
setFormatString<double>("% 10.8e");
                                                                               
** mātricks ERROR:    illegal format string "% 10.8e" passed to Format<double>
                                                                               
FormatData<double>::tens = true;
```

Define the Vector of coefficients: 

```C++
Vector<double> J0Coeffs = Vector<double>({1.,0.,-0.25,0.,0.015625,0.,-0.000434028,0.,6.78168e-6,0.,-6.78168e-8,0.,4.7095e-10,0.,-2.40281e-12,0.,9.38597e-15,0.,-2.8969e-17,0.});
```

Define the coordinate vector `r` as 101 points over the interval [0,10]: 

```C++
Vector<double> r = linspace<double>(0,10,101);
```

Calculate the Taylor series and store the results in vector `y`: 

```C++
Vector<double> y = taylor(J0Coeffs, r, 19);
```

The results `r` and `y` are:

```Mathematica
r = {
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
y = {
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
Cut and paste the above data for r and y into Mathematica as well as the following commands

```Mathematica
p1=ListPlot[Partition[Riffle[r,y],2],PlotStyle->Red];
p2=Plot[BesselJ[0,r],{r,0,10}];
Show[p1,p2]
```
This yields the following plot comparing the Taylor series [red dots] to the exact function [solid blue].
![Taylor Series for Jo(r)](BesselTaylorSeries.png)
## Maclaurin Series for the Bessel Function J<sub>0</sub>(x)
To acheive better accuracy, we can calculate the [Maclaurin Series](http://mathworld.wolfram.com/MaclaurinSeries.html) at the point `r=5`, which is the center of our interval of interest.
The first 20 (n=0,1,...19) coefficients for the Maclaurin Series (r<sub>0</sub>=5) for the function J<sub>0</sub>(r), are:

                                                                               
** mātricks ERROR:    illegal format string "% 10.8e" passed to Format<double>
                                                                               
                                                                               
** mātricks ERROR:    illegal format string "%s + I*%s" passed to setFormatStringComplex
                                                                               
```C++
J0Coeffs = {
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^, 
    doubl 10^, doubl 10^, doubl 10^, doubl 10^, doubl 10^
}; 
```
These were determined using the following `Mathematica` command

```Mathematica
N[Table[SeriesCoefficient[BesselJ[0,r],{r,5,n}],{n,0,19}]]

```


Set up the output format so that we can copy and paste into Mathematica, this time using the function `set_mathematica_var_format`
```C++
set_mathematica_var_format();
                                                                               
** mātricks ERROR:    illegal format string "% 10.8e" passed to Format<double>
                                                                               
                                                                               
** mātricks ERROR:    illegal format string "%s + I*%s" passed to setFormatStringComplex
                                                                               
```

Define the Vector of coefficients: 

```C++
Vector<double> J0Coeffs = Vector<double>( {-0.177597,0.327579,0.0560405,-0.0561487,-0.00170739,0.00252021,0.0000112022,-0.000053795,2.1333e-7,6.7811e-7,-4.88572e-9,-5.6642e-9,4.80096e-11,3.37094e-11,-2.99711e-13,-1.50298e-13,1.33856e-15,5.20979e-16,-4.54744e-18,-1.44449e-18});
```

Define the coordinate vector `r` as 101 points over the interval [0,10]: 

```C++
Vector<double> r = linspace<double>(0,10,101);
```

Calculate the Maclaurin series and store the results in vector `y`: 

```C++
Vector<double> y = maclaurin(J0Coeffs, r, 19, 5.);
```

The results `r` and `y` are:

```Mathematica
r = {
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
y = {
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
Cut and paste the above data for r and y into Mathematica as well as the following commands

```Mathematica
p1=ListPlot[Partition[Riffle[r,y],2],PlotStyle->Red];
p2=Plot[BesselJ[0,r],{r,0,10}];
Show[p1,p2]
```
This yields the following plot comparing the Maclaurin series [red dots] to the exact function [solid blue].
![Maclaurin Series for Jo(x)](BesselMaclaurinSeries.png)

[Table of Contents](README.md)
