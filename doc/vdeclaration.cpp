
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
  mdtitle("Vector declaration");
  matricks_preamble();

 
  {
    example(Nex++, "Declare vector `v` (initialize to zeros).");
    codestart("C++");
    codemulti( const size_type N = 4 );
    codemulti( Vector<double> v(N) );
    codeend();
    result(v);
  }

  {
    example(Nex++, "Declare `v` and initialize to a constant" );
    codestart("C++");
    codemulti( Vector<double> v(4, -1 ) );
    codeend();
    result(v);
  }

  {
    example(Nex++, "Declare `v` and initialize to a **C-style array** of values" );
    codestart("C++");
    codemulti( Vector<double> v( 4, (const double[]) {10, 20, 30, 40} )  );
    codeend();
    result(v);
  }

#if CPP11 
  {
    example(Nex++, "Declare `v` and initialize directly from a list (**__C++11__**)" );
    codestart("C++");
    codemulti( Vector<double> v({10, 20, 30, 40})  );
    codeend();
    result(v);
  }
#endif

  {
    example(Nex++, "Declare `v2` and initialize to values of `v1`" );
    text("* Note that this is a _copy_ constructor.");
    text("* In fact all of the `Vector` constructors are _copy_ constructors.");
    codestart("C++");
    codemulti( Vector<double> v1( CARRAY({10,11,12,13}) ) );
    codemulti( Vector<double> v2(v1) );
    codemulti( v1[0] = -1 );
    codemulti( v2[0] = -2 );
    codeend();
    result(v1);
    result(v2);
  }

  {
    example(Nex++, "Declare `v2` and initialize to an expression" );
    text("* The expression is computed without creating any intermediate objects.");  
    codestart("C++");
    codemulti( Vector<double> v1( CARRAY({10,11,12,13}) ) );
    codemulti( Vector<double> v2(10*v1+1) );
    codeend();
    result(v1);
    result(v2);
  }


  matricks_toc();
  
  return 0;
}
