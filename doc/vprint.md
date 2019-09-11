
# Formatted and styled printing in mātricks
_This document was automatically generated from file_ **`vprint.cpp`** (mātricks-v2.15-r9).

## `namespace display`: print-related functionality
### The function `disp(x)`


The function `disp(x)` displays both the variable name (or expression) as well as its value, formatted according to the user.   This is an incredibly useful function.


**EXAMPLE 1**: simple examples of `disp(x)` usage


```C++
int n = 45;
double x = 3.14;
double vals[] = {1.1,2.2,3.3};
bool done = true;
Vector<double> v = range<double>(1,10);
char str[] = "hello";
std::string s = "world";
std::complex<double> z(1,-1);
```
display each varible using `disp`:


```C++
disp(n);
disp(x);
disp(vals);
disp(done);
disp(v);
disp(str);
disp(s);
disp(z);
```


An actual screen-shot of the output is shown below:


![disp example 1](disp_example1.png)
### The function `tdisp(x)`


The function `tdisp(x)` displays the variable type, in addition to the variable name and value


**EXAMPLE 2**: simple examples of `tdisp(x)` usage
display each varible using `tdisp`:


```C++
tdisp(n);
tdisp(x);
tdisp(vals);
tdisp(done);
tdisp(v);
tdisp(str);
tdisp(s);
tdisp(z);
```


An actual screen-shot of the output is shown below:


![disp example 2](disp_example2.png)

[Table of Contents](README.md)
