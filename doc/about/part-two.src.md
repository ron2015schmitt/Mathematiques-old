

## History

Development for this project originally took place in very rough form during the years 2003-2008 using the C99/C++.

The code was resurrected in 2019: refactored, extended, improved, simplified, and updated with C++11, C++14, C++17 features.

In early 2020, the project was officially launched as _Mathématiques_ and uploaded to a github!


## Techniques

The code uses a form of C++ [template metaprogramming](https://en.wikipedia.org/wiki/Template_metaprogramming) called [expression templating](https://en.wikipedia.org/wiki/Expression_templates), the library provides computational efficiency on par with C/Fortran.

*Expression templating* produces complex code in the library itself, but the *user code* is simple, clean, and extremely efficient.

## Platform

The initial platform chosen is
* language
  1. C++17 or higher, necessary to create the syntax
* compiler
  1. The GNU g++ compiler that supports C++17 XX or higher
* OS
  1. Linux: Ubuntu 20.05
* packages
  1. LAPACK: for the more advanced linear algebra functions: matrix inverse, and decompositions

Other configurations are of course possible with modification.




