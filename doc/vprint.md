
# Formatted and styled printing in mātricks
_This document was automatically generated from file_ **`vprint.cpp`** (mātricks-v2.15-r7).

## `namespace display`: print-related functionality
### The function `disp(x)`


The function `disp(x)` displays both the variable name (or expression) as well as its value, formatted according to the user.   This is an incredibly useful function.


**EXAMPLE 1**: simple examples of `disp(x)` usage


```C++
int n = 45;
double x = 3.14;
double vals[] = {1.1,2.2,3.3};
char str[] = "hello";
std::string s = "world";
std::complex<double> z(1,-1);
```
display each varible using `disp`:


```C++
disp(n)
disp(x)
disp(vals)
disp(str)
disp(s)
disp(z)
```


An actual screen-shot of the output is shown below:


![disp example 1](disp_example1.png)

[Table of Contents](README.md)
