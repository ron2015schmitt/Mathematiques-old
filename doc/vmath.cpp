#define MATRICKS_CAREFUL


#include "matricks.hpp"
using namespace Matricks;

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif



int main()
{

  int Nex = 1;
  
  cr();
  mdtitle("Vector math");
  matricks_preamble();

  header3("Element-wise arithmetic");
  text("The operators +,-,*,/ perform element wise addition, subtraction, multiplication, and division respectively");

  {
    cr();
    cr();
    example(Nex++,"Element-wise `Vector` math");
    codestart("C++");
    codemulti( Vector<double> v1(4) );
#if CPP11 == 1
    codemultiwcomment("C++11 list", v1 = {10,20,30,40});
#else
    codemulti( v1 = (const double[]) {10,20,30,40} );
#endif
    codemulti( Vector<double> v2(4) );
#if CPP11 == 1
    codemultiwcomment("C++11 list", v2 = {1,2,3,4});
#else
    codemulti( v2 = (const double[]) {1,2,3,4} );
#endif
    codeend();
    cr();

   
    resultstart2();
    resultmulti(v1 + v2);
    resultmulti(v1 - v2);
    resultmulti(v1 * v2);
    resultmulti(v1 / v2);
    resultend();
  }


  header3("Vector-scalar arithmetic");
  text("* The binary operators +,-,*,/ can each be used to pair a scalar and a `Vector`.");
  text("* In this case the scalar is operated on each element of the vector");

  {
    cr();
    cr();
    example(Nex++,"math with scalars and `Vector`s");
    codestart("C++");
    codemulti( Vector<double> v1(4) );
#if CPP11 == 1
    codemultiwcomment("C++11 list", v1 = {10,20,30,40});
#else
    codemulti( v1 = (const double[]) {10,20,30,40} );
#endif
    codeend();
    cr();

    resultstart2();
    resultmulti(v1 + 1);
    resultmulti(1 + v1);
    resultmulti(v1 - 10);
    resultmulti(40 - v1);
    resultmulti(v1 * 2);
    resultmulti(2 * v1);
    resultmulti(v1 / 10);
    resultmulti(120 / v1);
    resultmulti(1 + 120 / v1 - 8/8 + 5*v1*2);
    resultend();
  }


  //  v2 = v1*(sin(2.0*v1)  +  cos(2.0*v1))/2.0;


  // functions supported: sin, cos, tan, sinh, cosh, tanh, exp, log, abs, log10
  // pow(a,b), round, ceil, floor, asin, acos, atan, atan2, sqrt, sgn


  matricks_toc();


  return 0;
}
