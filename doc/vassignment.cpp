
// flag for run-time bounds and size checking
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
  mdtitle("Vector assigment");
  matricks_preamble();

  text("* Vector assignment is performed by copying the elements of the object on the right-hand side to the left-hand side.");
  text("* When the right-hand side is an expression, there are _no_ intermediate objects created.");
  
  {
    example(Nex++,"Assign all elements to a single value.");
    codestart("C++");
    codemulti( Vector<double> v(10) );
    codemulti( v = 78.9 );
    codeend();
    result(v);
  }


  {
    example(Nex++,"Assign from a C Array.");
    text("_In DEBUG mode, this generates a warning since it is a dangerous practice. Use a C++11 list instead._");
    codestart("C++");
    codemulti( Vector<double> v(4) );
    codemulti( (const double[]) {1,2,3,4} );
    codeend();
    result(v);
  }

#if CPP11==1
  {
    example(Nex++,"Assign from a C++11 list.");
    codestart("C++");
    codemulti( Vector<double> v(4) );
    codemulti( v = {1,2,3,4} );
    codeend();
    result(v);
  }
#endif
  

  matricks_toc();

  return 0;
}
