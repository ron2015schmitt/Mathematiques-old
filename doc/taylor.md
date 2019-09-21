
# Calculating a Taylor series and plotting the results in Mathematica
_This document was automatically generated from file_ **`taylor.cpp`** (mātricks-v2.16-r21).

## Taylor Series for the Bessel Function J<sub>0</sub>(r)
We can easily calculate a [Taylor Series](http://mathworld.wolfram.com/TaylorSeries.html) in matricks. As an example, let's calculate the Taylor series for the [Bessel Function of the first kind](http://mathworld.wolfram.com/BesselFunctionoftheFirstKind.html) of order 0, J<sub>0</sub>(r). 
The first 20 (n=0,1,...19) coefficients for  J<sub>0</sub>(r), are:

                                                                               
** mātricks ERROR:    illegal format string "% 10.8e" passed to Format<double>
                                                                               
                                                                               
** mātricks ERROR:    illegal format string "%s + I*%s" passed to setFormatStringComplex
                                                                               
```C++
J0Coeffs = {
    1, 0, -0.25, 0, 0.015625, 
    0, -0.000434028, 0, 6.78168 10^-06, 0, 
    -6.78168 10^-08, 0, 4.7095 10^-10, 0, -2.40281 10^-12, 
    0, 9.38597 10^-15, 0, -2.8969 10^-17, 0
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
    0, 0.1, 0.2, 0.3, 0.4, 
    0.5, 0.6, 0.7, 0.8, 0.9, 
    1, 1.1, 1.2, 1.3, 1.4, 
    1.5, 1.6, 1.7, 1.8, 1.9, 
    2, 2.1, 2.2, 2.3, 2.4, 
    2.5, 2.6, 2.7, 2.8, 2.9, 
    3, 3.1, 3.2, 3.3, 3.4, 
    3.5, 3.6, 3.7, 3.8, 3.9, 
    4, 4.1, 4.2, 4.3, 4.4, 
    4.5, 4.6, 4.7, 4.8, 4.9, 
    5, 5.1, 5.2, 5.3, 5.4, 
    5.5, 5.6, 5.7, 5.8, 5.9, 
    6, 6.1, 6.2, 6.3, 6.4, 
    6.5, 6.6, 6.7, 6.8, 6.9, 
    7, 7.1, 7.2, 7.3, 7.4, 
    7.5, 7.6, 7.7, 7.8, 7.9, 
    8, 8.1, 8.2, 8.3, 8.4, 
    8.5, 8.6, 8.7, 8.8, 8.9, 
    9, 9.1, 9.2, 9.3, 9.4, 
    9.5, 9.6, 9.7, 9.8, 9.9, 
    10
}; 
y = {
    1, 0.997502, 0.990025, 0.977626, 0.960398, 
    0.93847, 0.912005, 0.881201, 0.846287, 0.807524, 
    0.765198, 0.719622, 0.671133, 0.620086, 0.566855, 
    0.511828, 0.455402, 0.397985, 0.339986, 0.281819, 
    0.223891, 0.166607, 0.110362, 0.0555397, 0.00250764, 
    -0.0483838, -0.096805, -0.142449, -0.185036, -0.224312, 
    -0.260052, -0.292065, -0.320188, -0.344297, -0.364296, 
    -0.380128, -0.39177, -0.399231, -0.402557, -0.401827, 
    -0.397151, -0.388671, -0.376559, -0.361013, -0.342259, 
    -0.320546, -0.296142, -0.269336, -0.240432, -0.209747, 
    -0.177608, -0.14435, -0.110311, -0.0758309, -0.0412482, 
    -0.00689635, 0.0268985, 0.05982, 0.0915646, 0.121843, 
    0.150384, 0.176932, 0.201256, 0.223142, 0.2424, 
    0.258862, 0.272382, 0.282833, 0.29011, 0.294122, 
    0.294796, 0.292064, 0.285863, 0.276129, 0.262785, 
    0.245732, 0.224835, 0.19991, 0.170706, 0.136877, 
    0.0979636, 0.0533548, 0.00225351, -0.0563691, -0.123827, 
    -0.201782, -0.292319, -0.398035, -0.522142, -0.668591, 
    -0.842218, -1.04891, -1.29582, -1.59157, -1.94656, 
    -2.37328, -2.88666, -3.50455, -4.24818, -5.14279, 
    -6.2183
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
    -0.177597, 0.327579, 0.0560405, -0.0561487, -0.00170739, 
    0.00252021, 1.12022 10^-05, -5.3795 10^-05, 2.1333 10^-07, 6.7811 10^-07, 
    -4.88572 10^-09, -5.6642 10^-09, 4.80096 10^-11, 3.37094 10^-11, -2.99711 10^-13, 
    -1.50298 10^-13, 1.33856 10^-15, 5.20979 10^-16, -4.54744 10^-18, -1.44449 10^-18
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
    0, 0.1, 0.2, 0.3, 0.4, 
    0.5, 0.6, 0.7, 0.8, 0.9, 
    1, 1.1, 1.2, 1.3, 1.4, 
    1.5, 1.6, 1.7, 1.8, 1.9, 
    2, 2.1, 2.2, 2.3, 2.4, 
    2.5, 2.6, 2.7, 2.8, 2.9, 
    3, 3.1, 3.2, 3.3, 3.4, 
    3.5, 3.6, 3.7, 3.8, 3.9, 
    4, 4.1, 4.2, 4.3, 4.4, 
    4.5, 4.6, 4.7, 4.8, 4.9, 
    5, 5.1, 5.2, 5.3, 5.4, 
    5.5, 5.6, 5.7, 5.8, 5.9, 
    6, 6.1, 6.2, 6.3, 6.4, 
    6.5, 6.6, 6.7, 6.8, 6.9, 
    7, 7.1, 7.2, 7.3, 7.4, 
    7.5, 7.6, 7.7, 7.8, 7.9, 
    8, 8.1, 8.2, 8.3, 8.4, 
    8.5, 8.6, 8.7, 8.8, 8.9, 
    9, 9.1, 9.2, 9.3, 9.4, 
    9.5, 9.6, 9.7, 9.8, 9.9, 
    10
}; 
y = {
    1.00001, 0.997508, 0.99003, 0.977631, 0.960403, 
    0.938474, 0.912008, 0.881204, 0.84629, 0.807527, 
    0.7652, 0.719624, 0.671135, 0.620088, 0.566857, 
    0.511829, 0.455404, 0.397986, 0.339987, 0.28182, 
    0.223892, 0.166608, 0.110363, 0.0555404, 0.00250823, 
    -0.0483833, -0.0968045, -0.142449, -0.185036, -0.224311, 
    -0.260052, -0.292064, -0.320188, -0.344296, -0.364296, 
    -0.380128, -0.391769, -0.39923, -0.402556, -0.401826, 
    -0.39715, -0.38867, -0.376557, -0.361011, -0.342257, 
    -0.320543, -0.296138, -0.269331, -0.240426, -0.209739, 
    -0.177597, -0.144335, -0.110291, -0.0758034, -0.0412104, 
    -0.00684416, 0.0269706, 0.0599197, 0.0917022, 0.122033, 
    0.150645, 0.177291, 0.201747, 0.223812, 0.24331, 
    0.260094, 0.274043, 0.285064, 0.293095, 0.298102, 
    0.300079, 0.299051, 0.29507, 0.288216, 0.278596, 
    0.266339, 0.251601, 0.234558, 0.215407, 0.194361, 
    0.17165, 0.147516, 0.122214, 0.0960044, 0.0691554, 
    0.0419372, 0.0146207, -0.0125252, -0.0392366, -0.0652563, 
    -0.090337, -0.114243, -0.136753, -0.15766, -0.176777, 
    -0.193935, -0.208985, -0.221803, -0.232284, -0.240351, 
    -0.245947
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
