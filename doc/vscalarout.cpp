#define MATRICKS_DEBUG


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
  mdtitle("Vector functions that return a scalar (dot product, sum, min, max etc)");
  matricks_preamble();

  header3("dot product");
  text("* The dot product is accomplished via the `|` operator, such that the dot product takes a form similar to P.A.M. Dirac's 'bra-ket' notation.");
  text("* This definition becomes very useful for taking the product of matrices because any number of matrices can be multiplied in a single line of code.");
  
#if CPP11 == 1
  {
    cr();
    cr();
    example(Nex++,"Dot product of two vectors `(v1|v2)`");
    codestart("C++");
    codemultiwcomment("C++11 list initialization", Vector<double> v1({1,2,3,4}));
    codemultiwcomment("C++11 list initialization", Vector<double> v2({1,-1,1,-1}));
    codeend();
    cr();
#endif

   
    resultstart2("");
    resultmulti( (v1|v1) );
    resultmulti( (v2|v2) );
    resultmulti( (v1|v2) );
    resultmulti( (v2|v1) );
    resultmulti( (v1|(2*v2+1)) );
    resultend();
  }



  matricks_toc();
  return 0;
}
