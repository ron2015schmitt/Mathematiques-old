
// flag for run-time bounds and size checking
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
  header1("Declaring and Assigning Vectors in mātricks");
  matricks_preamble();
  header2("Declaring vectors");
  
  example(Nex++, "Declare vector `v1`.");
  codestart("C++");
  codemulti( const size_type N = 4 );
  codemulti( Vector<double> v1(N) );
  codeend();
  result(v1);


  example(Nex++, "Declare `v2` and initialize to a constant" );
  codestart("C++");
  codemulti( Vector<double> v2(4, -1 ) );
  codeend();
  result(v2);

  example(Nex++, "Declare `v3` and initialize to a **C-style array** of values" );
  codestart("C++");
  codemulti( Vector<double> v3( 4, (const double[]) {10, 20, 30, 40} )  );
  codeend();
  result(v3);

  if (CPP11) {
    example(Nex++, "Declare `v4` and initialize directly (**__C++11__**)" );
    codestart("C++");
    codemulti( Vector<double> v4({10, 20, 30, 40})  );
    codeend();
    result(v4);
  }
  

  example(Nex++, "Declare `v5` and initialize to values of `v3`" );
  codestart("C++");
  codemulti( Vector<double> v5(v3) );
  codeend();
  result(v5);

  example(Nex++, "Declare `v6` and initialize to an expression" );
  codestart("C++");
  codemulti( Vector<double> v6(2*v3+1) );
  codeend();
  result(v6);

  
  return 0;
}
