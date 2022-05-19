#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <stdbool.h>
#include <typeinfo>
#include <optional>

#define MATHQ_DEBUG 1
#include "mathq.h"


int main() {
  using namespace mathq;
  using namespace std;
  using namespace display;


  CR();
  CR();

  using namespace mathq::unit_imaginary;

  using std::sqrt;

  GMD_HEADER2("Introduction");

  OUTPUT("The [imaginary numbers](https://mathworld.wolfram.com/Imaginary.html) are a non-communative [division algebra](https://en.wikipedia.org/wiki/Division_algebra).");


  CR();
  CR();
  OUTPUT("\n<br>\n");
  GMD_HEADER2("Size of imaginary numbers");

  OUTPUT("The size of a imaginary numbers is the same size of the underlying arithmetic type:");

  CR();
  CR();
  GMD_CODE_START("C++");
  SRDISP(" bits", CHAR_BIT);
  CR();
  SRDISP(" bits", CHAR_BIT*sizeof(int));
  SRDISP(" bits", CHAR_BIT*sizeof(Imaginary<int>));
  CR();
  SRDISP(" bits", CHAR_BIT*sizeof(double));
  SRDISP(" bits", CHAR_BIT*sizeof(Imaginary<double>));
  CR();
  SRDISP(" bits", CHAR_BIT*sizeof(long double));
  SRDISP(" bits", CHAR_BIT*sizeof(Imaginary<long double>));
  CR();
  GMD_CODE_END();

  GMD_HEADER2("Declaration and initialization");


  OUTPUT("Declaring quaternion variables in Mathématiques");


  CR();
  CR();
  GMD_CODE_START("C++");
  ECHO_CODE(using namespace mathq);
  ECHO_CODE(using namespace mathq::unit_imaginary);
  CR();
  // ECHO_CODE(auto q1 = Imaginary<double>(1, 2, -1, -3));
  // ECHO_CODE(auto q2 = Imaginary<double>(4, 3, -2, -5));
  // ECHO_CODE(auto q = Imaginary<double>() = 16 + 2*i + 3*j + 13*k);
  // ECHO_CODE(auto p = Imaginary<double>() = 0.53767 + 0.86217*i - 0.43359*j + 2.7694*k);
  GMD_CODE_END();

  MOUT << "In the above expressions we used the constants `i`, `j`, and `k`, which are defined as follows:\n";
  CR();
  GMD_CODE_START("C++");
  TRDISP(mathq::unit_imaginary::i);
  GMD_CODE_END();

  OUTPUT("Unlike the standard C++ `i`, which is an operator, the Mathématiques `i`, `j`, and `k` are constants");

  GMD_HEADER2("Arithmetic");

  OUTPUT("The 4 fundamental arithmetic operators can be used with imaginary numbers.");

  OUTPUT("Mathématiques supports the four arithmetic operators for imaginary numbers:");
  CR();
  GMD_CODE_START("C++");
  // TRDISP(q1+q2);
  // TRDISP(q1-q2);
  // TRDISP(q1*q2);
  // TRDISP(q2/q1);
  GMD_CODE_END();


  GMD_HEADER2("Methods");

  OUTPUT("Assume `q`  is of type `Imaginary<D>` with \n");


  OUTPUT("| syntax | modifies q? | description | ");
  OUTPUT("| :---: | :---: | :---: | ");
  OUTPUT("| `Imaginary<D> invert()` | yes | q := 1/q, returns `q` | ");
  OUTPUT("| `Imaginary<D> negate()` | yes | q := -q, returns `q` | ");
  OUTPUT("| `Imaginary<D> conjugate()` | yes | q := q<sup>*</sup>, returns `q` | ");
  OUTPUT("| `D real()` | no | returns the real part of `q` | ");
  OUTPUT("| `D imag()` | no | returns the i-component part of `q` | ");
  OUTPUT("| `D abs()` | no | returns \\|\\|_q_\\|\\|, the magnitude of `q` | ");
  OUTPUT("| `D normsqr()` | no | returns the magnitude-squared of `q` | ");
  OUTPUT("| `D scalar()` | no | same as real() | ");
  OUTPUT("| `D angle()` | no | returns φ as defined above | ");


  OUTPUT("A few examples are shown below."); 

  CR();
  GMD_CODE_START("C++");
  // TRDISP(q1);
  // TRDISP(q1.real());
  // TRDISP(q1.imag());
  // TRDISP(q1.jmag());
  // TRDISP(q1.kmag());
  // TRDISP(q1.abs());
  // TRDISP(q1.scalar());
  // TRDISP(q1.vector());
  // TRDISP(q1.vabs());
  // TRDISP(q1.unitvector());
  // TRDISP(q1.angle());
  // TRDISP(q1.polar());
  // TRDISP(q1.matrix2by2());
  GMD_CODE_END();



  GMD_HEADER2("Operators & Functions");
  CR();
  OUTPUT("C++ supports many functions and Mathématiques provides several more.  These are listed in detail in the sections on opetators and functions.  C++ supports mixed type arithmetic between all the real types.");
  OUTPUT("Below are a few examples.\n");
  CR();


  CR();
  GMD_CODE_START("C++");
  ECHO_CODE(double pi = 3.14159265358979311599796346854);
  TRDISP(pi);
  TRDISP(2*sin(pi/4) - 1);
  TRDISP(3/pi*asin(0.86602540378));
  TRDISP(exp(2));
  TRDISP(log(10));
  TRDISP(log10(10));
  TRDISP(pow(2,10));
  TRDISP(pow(2,2.5-2));
  GMD_CODE_END();

  GMD_HEADER2("Containers of Imaginary numbers");
  CR();
  OUTPUT("Mathématiques container classes (ie `Vector<D>`, `Matrix<d>`, and `Tensor<D>` can have imaginary numbers as their underlying type.");
  OUTPUT("Below are examples of container math with imaginary numbers.  Mixed math is allowed.\n");
  CR();



  FormatDataVector::string_opening = "{\n";
  FormatDataVector::max_elements_per_line = 1;
  FormatDataVector::string_endofline = "\n";
  GMD_CODE_START("C++");
  // ECHO_CODE(auto v = Vector<Imaginary<double>>({ 16 + 2*i + 3*j + 13*k,
  //                                                5 + 11*i + 10*j + 8*k,
  //                                                9 + 7*i + 6*j + 12*k,
  //                                                4 + 14*i + 15*j + 1*k }));
  GMD_CODE_END();


  GMD_CODE_START("C++");
  // TRDISP(q);
  // CR();
  // TRDISP(v);
  // CR();
  // TRDISP(v + q);
  // CR();
  // TRDISP(exp(v));
  // CR();
  // TRDISP(exp(v) + v);
  // TRDISP(exp(v) + 1);
  // TRDISP(exp(v) + 2.3);
  // TRDISP(exp(v) + complex(1,2));
  // TRDISP(exp(v) + Imaginary<double>(2));
  // TRDISP(exp(v) + Imaginary<double>(1, 2, -1, -3));
  GMD_CODE_END();

  return 0;
}
