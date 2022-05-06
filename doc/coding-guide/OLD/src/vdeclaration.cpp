
// flag for run-time bounds and size checking
#define MATHQ_DEBUG 1


#include "mathq.h"

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>





int main()
{
  using namespace mathq;
  using namespace std;
  using namespace display;
  
  
  int Nex = 1;
  
  mathq_toc();
  CR();CR();
  mdtitle("Vector declaration");
  mathq_preamble();

 
  {
    EXAMPLE(Nex++, "Declare vector `v` (initialize to zeros).");
    codestart("C++");
    codemulti( const size_type N = 4 );
    codemulti( Vector<double> v(N) );
    codeend();
    RESULT(v);
  }

  {
    EXAMPLE(Nex++, "Declare `v` and initialize to a constant" );
    codestart("C++");
    codemulti( Vector<double> v(4, -1 ) );
    codeend();
    RESULT(v);
  }

  {
    EXAMPLE(Nex++, "Declare `v` and initialize to a **C-style array** of values" );
    CR();
    text("In debug mode, this produces a warning, as shown below");
    codestart("C++");
    codemulti( Vector<double> v( 4, (const double[]) {10, 20, 30, 40} )  );
    codeend();
    RESULT(v);
  }

  {
    EXAMPLE(Nex++, "Declare `v` and initialize directly from a list (**__C++11__**)" );
    codestart("C++");
    codemulti( Vector<double> v({10, 20, 30, 40})  );
    codeend();
    RESULT(v);
  }

  {
    EXAMPLE(Nex++, "Declare `v2` and initialize to values of `v1`" );
    text("* Note that this is a _copy_ constructor.");
    text("* In fact _all_ of the `Vector` constructors are _copy_ constructors.");
    codestart("C++");
    codemultiNoteC11Array( Vector<double> v1( {10,11,12,13} ) );
    codemulti( Vector<double> v2(v1) );
    codemulti( v1[0] = -1 );
    codemulti( v2[0] = -2 );
    codeend();
    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultend();
  }

  {
    EXAMPLE(Nex++, "Declare `v2` and initialize to an expression" );
    text("* The expression is computed without creating any intermediate objects.");  
    codestart("C++");
    codemultiNoteC11Array( Vector<double> v1({10,11,12,13} ) );
    codemulti( Vector<double> v2(10*v1+1) );
    codeend();
    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultend();
  }


  mathq_toc();
  
  return 0;
}
