# Mathématiques v2.33-r49

Mathématiques is numerical library for performing linear algebra, calculus, vector calculus, etc in C++ via simple MATLAB-like syntax while also providing run-time performance and memory usage of hand-coded C or Fortran.

_Mathématiques distinguishes itself from other libraries by an elegance and versatility that are only possible using the features of C++11,14, and 17._

+ V3.0, the first official release)  is almost ready.
  + Arbitrary rank tenor arrays (Scalar, Vector, Matrix, etc)
  + Each tensor type can have tensor as datatype, eg `Vector<Vector<double>>`, which can be used to represent a vector-valued function on a mesh.
  + can have fixed (uses `array`) or variable dimensions (uses `valarray`)
  + fixed array size is ideal for small vectors, eg 2D or 3D vector
  + no boiler-plates. all are processed by the same functions (sin, cos, exp, etc)
  + calculus (derivatives and integrals)
  + Taylor series
  + Fourier Series
  + Tensor calculus (covaraint and contravariant tensors of any rank)
  + no loss of elegance and simplicity in use
  + no real-time cost
  + 237 unit tests (so far), with a very clear and elegant output.
  + unit tests: metacode in progress to generate full code coverage using expected results generated via meta code in C++ with calls to matlab. (matlab not required for usage of the library)
  + Online [User's Guide](doc/README.md) in progress
  + refer to [TO-DO List](todo/README.md) to monitor development progress




Advantages
+ object-oriented matrices and vectors
+ run-time performance and memory usage on par with optimized C or and Fortran
+ simple MATLAB-like syntactic sugar 
  + slices of vectors and matrices
  + add two matrices is `A+B`
  + matrix-vector multiply is `A|x` (`|` is symbol used for inner product)
  + extremely efficient matrix-matrix multiply `A|B`
  + element-wise multiply is `A*B`
  + complicated expressions supported `(A + B - 33.14*C)|(2*x + y)` *without* run-time overhead and no intermediate objects
  + complex number support
  + functions of matrices/vectors supported: `sin(x)`, `exp(A)` etc
  + SVD and Eiegenvalue decomposition supported via LAPACK
  + matrix inverse: `inv(A)`
+ does *not* produce intermediate objects (which crush run-time performance and inflate memory usage)
+ expressions are computed in a single for loop
+ hand-optimized matrix multiply
+ pretty formatted output of vectors and matrices
+ simple file i/o of vectors and matrices
+ Online [User's Guide](doc/README.md) in git markdown
  + clear documentation of every feature
  + documentation is generated from C++ code using the library itself
+ `MATHQ_DEBUG` debugging compile mode produces extensive information to aid in debugging
  + out of bounds access for vectors or matrices (e.g. x[10] where x is a
   vector of length 6.
  + adding/subtracting/multiplying/dividing vector or matrices of unequal
   size
  + invalid dot products of vector and/or matrices 
  + other assorted errors

+ I ran benchmarks vs. a handcoded for loop. The results are impressive (-O3 optimization):
![benchmarks](files/benchmark.png)

where the second code comparision is hand-coded loop 
```C++
std::valarray<double> x(N);
for(int i=0; i<N; i++)
  x[i] = double(i)/double(N-1);
std::valarray<double> f(N);
start_timer();
for(int i=0; i<N; i++)
     f[i] = cos(2*pi + pi*sin(2*pi*x[i] + pi/6));
stop_timer();
```

vs mathq syntax 
```C++
Vector<double> x(N);
x = linspace<double>(0,1,N);
Vector<double> f(N);
start();
f = cos(2*pi + pi*sin(2*pi*x + pi/6));
stop();
```

---------------------------------------------------------------------------

# DEVELOPMENT

Development for this project originally took place during the years 2003-2008 

The code resurrected in 2019, imporved, and put on github.

The code uses a form of C++ [template metaprogramming](https://en.wikipedia.org/wiki/Template_metaprogramming) called [expression templating](https://en.wikipedia.org/wiki/Expression_templates), the library provides computational efficiency on par with C/Fortran.

*Expression templating* produces complex code in the library itself, but the *user code* is simple, clean, and extremely efficient.

# LICENSE 

The code that makes up this library is copyrighted under the *MIT license*.

[Read the LICENSE file for details](LICENSE).

# INSTALLATION

The first step is to clone the repo

```git clone https://github.com/ron2015schmitt/mathq.git```

You now have a directory with all the Mathématiques source code

# CONFIGURATION

cd into the mathq directory and execute the configure command:

```
cd mathq
./configure
```

# USING THE Mathématiques LIBRARY

To use the Mathématiques library you need to 

1. Include the library file `include/mathq.h` in your source code
```C++
#include "mathq.h"
```
2. Include the `include/` subdirectory during compilation using the `-I` option

3. Include the `lib/` subdirectory during linking using the `-L` option

4. Include the option `-lmathq` during linking

## EXAMPLE CODE FILE

An example of a C++ source file (```examples/example.cpp```) is shown below

```C++

#include "mathq.h"


int main(int argc, char *argv[])
{
  const double pi = M_PI;
  std::string myname = argv[0];
  
  using namespace mathq;
  using namespace display;

  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  cr();
  cr();
  mout << StyledString::get(HORLINE);
  mout << "running: " <<createStyle(BOLD).apply(myname) << std::endl;

  
  mout<< "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;
  print_mathq_info();
  
  Vector<double> v1( linspace<double>(-1,1,21) );
  Vector<double> v2;
  v2 = 10*sin(pi/2*v1) + 10;

  disp(v1);
  disp(v2);
  disp(v1+v2);

  // dot product
  disp(v1|v2);

  const double N = double(v2.size());
  // mean
  double mu2 = sum(v2)/N;
  disp(mu2);

  // std deviation
  double sigma2 = norm(v2-mu2)/sqrt(N-1);
  disp(sigma2);

  cr();
  mout << "done: " << createStyle(BOLD).apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();

  
  return 0;
}
```

Compile the code and run the code using
```bash
g++ -I ~/mathq/include example.cpp -o example -L ~/mathq/lib -lmathq
./example
```

## EXAMPLE MAKEFILE

A example makefile, ```examples/Makefile```,  is included for your convenience 

*AFTER CONFIGURATION*, copy this makefile to YOUR source code directory (or cut and paste into an existing makefile).


# EXTENSIVE DEBUGGING SUPPORT

The Mathématiques library provides extensive debugging operation, turned on using the flag `MATHQ_DEBUG`.   The word `MATHQ_DEBUG` was chosen over `DEBUG` to avoid clashing with other code (libraries).

In this mode extensive error checking is performed to notify the user of

 - out of bounds access for vectors or matrices (e.g. x[10] where x is a
   vector of length 6.
 - adding/subtracting/multiplying/dividing vector or matrices of unequal
   size
 - invalid dot products of vector and/or matrices 
 - other assorted errors and warnings



## SETTING `MATHQ_DEBUG` MODE

There are two methods to accomplish this.

### RECOMMENDED METHOD: Use the provided sample makefile and specify `MATHQ_DEBUG=1` on the command line

example:

```make clean MATHQ_DEBUG=1 myprogram```


The target `clean` is not needed, but is a reccomended practice.

If you want to recompile in fast mode, just use the makefile
without specifying the `MATHQ_DEBUG` flag

```make clean myprogram```


### EXPLICIT METHOD: Add a `#define MATHQ_DEBUG 1` statement BEFORE each `mathq.h` include statement

```C++
#define MATHQ_DEBUG 1
#include "mathq.h"
```


## RECOMMENDATIONS

While developing your code, use `MATHQ_DEBUG` mode.  When you are convinced that it is operating
without errors or warnings, run normally.  

Compile a `MATHQ_DEBUG` and a quick version of your code, giving the executables different names.
This way if a segmentation fault occurs, or you otherwise suspect an error, you can quickly
check the problem under careful mode.


##  NOTES

Compile time is also considerably slower in MATHQ_DEBUG mode.

# DOCUMENTATION

[User's Guide](doc/README.md)

