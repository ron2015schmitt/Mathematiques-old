<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.39</h1>

<details>

<summary>User Guide</summary>

# [User Guide](../README.md)<br>

1. _About_ <br>
2. [License](../license/README.md)<br>
3. [Release Notes](../release-notes/README.md)<br>
4. [Installation](../installation/README.md)<br>
5. [Makefile / Using Mathématiques](../using-mathematiques/README.md)<br>
6. [Code Examples](../examples/README.md)<br>
7. [Coding Guide / Syntax](../coding-guide/README.md)<br>
8. [Benchmarks](../benchmarks/README.md)<br>
9. [Tests](../test/README.md)<br>
10. [New Feature Plans](../feature-schedule/README.md)<br>
11. [Developer Guide](../developer-guide/README.md)<br>


</details>



# 1. About


## Goal

The goal of the Mathématiques project is to provide a _library_ for _numerical computation_, _computation sciences_, _engineering simulations_, and _computer graphics_ that is
* user friendly
* feature rich
* flexible

has 
* simple compact syntax

with
* easy-to-use output functions that produce clearly formatted results in color, including type information
* debug modes for bounds and dimension checking
* production mode that runs as fast as possible, without any checking

producing executables that are
* fast
* memory efficient

## Language

C++ was chosen for its efficiency and because it has the features, such as templating, needed to create a syntax.

## Platform

The initial platform chosen is
* language
  1. C++17 or higher
* compiler
  1. The GNU g++ compiler that supports C++17 XX or higher
* OS
  1. Linux: Ubuntu 20.05
* packages
  1. LAPACK: for the more advanced linear algebra functions: matrix inverse, and decompositions

Other configurations are of course possible with modification.


## Influences

* Matlab
* Python
* Fortran95
* Mathematica

## History

Development for this project originally took place in very rough form during the years 2003-2008 using the C99/C++.

The code was resurrected in 2019: refactored, extended, improved, simplified, and updated with C++11, C++14, C++17 features.

In early 2020, the project was officially launched as _Mathématiques_ and uploaded to a github!

Currently, in 2022, Mathématiques is undergoing changes to make it sponsor-ready.  This process includes full documentation in markdown and refactoring of some of the code.

## Techniques

The code uses a form of C++ [template metaprogramming](https://en.wikipedia.org/wiki/Template_metaprogramming) called [expression templating](https://en.wikipedia.org/wiki/Expression_templates), the library provides computational efficiency on par with C/Fortran.

*Expression templating* produces complex code in the library itself, but the *user code* is simple, clean, and extremely efficient.

TODO: add Fortran C note.





| ⇦ <br />  | [User Guide](../README.md)<br />About<br /><img width=1000/> | ⇨ <br />[License](../license/README.md)   |
| ------------ | :-------------------------------: | ------------ |

