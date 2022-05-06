
// flag for run-time bounds and size checking
#define MATHQ_DEBUG 1


#include "mathq.h"

#include <iostream>
#include <string>

#include <vector>
#include <list>




int main()
{
  using namespace mathq;
  using namespace std;
  using namespace display;
  

  int Nex = 1;
  
  mathq_toc();
  CR();CR();
  mdtitle("Vector assigment");
  mathq_preamble();

  OUTPUT("* Vector assignment is performed by copying the elements of the object on the right-hand side to the left-hand side.");
  OUTPUT("* When the right-hand side is an expression, there are _no_ intermediate objects created.");
  
  {
    EXAMPLE(Nex++,"Assign all elements to a single value.");
    GMD_CODE_START("C++");
    codemulti( Vector<double> v(10) );
    codemulti( v = 78.9 );
    GMD_CODE_END();
    RESULT(v);
  }


  {
    CR();
    EXAMPLE(Nex++,"Assign from a C Array.");
    CR();
    OUTPUT("_In DEBUG mode, this generates a warning since it is a dangerous practice. Use a C++11 list instead._");
    GMD_CODE_START("C++");
    codemulti( Vector<double> v(4) );
    codemulti( v = (const double[]) {1,2,3,4} );
    GMD_CODE_END();
    RESULT(v);
  }

  {
    EXAMPLE(Nex++,"Assign from a C++11 list.");
    GMD_CODE_START("C++");
    codemulti( Vector<double> v(4) );
    codemulti( v = {1,2,3,4} );
    GMD_CODE_END();
    RESULT(v);
  }
  

  {
    EXAMPLE(Nex++,"Assign from another `Vector`.");
    CR();
    OUTPUT("Note that values are copied from `v2` to `v1`");
    GMD_CODE_START("C++");
    codemultiNoteC11Array( Vector<double> v1({1,2,3,4}) );
    codemultiNoteC11Array( Vector<double> v2({0,0,0,0}) );
    codemulti( v2 = v1 );
    codemulti( v1[0] = 100 );
    codemulti( v2[0] = 200 );
    GMD_CODE_END();
    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultend();
  }
  
  {
    EXAMPLE(Nex++,"Assign from a `Vector` expression.");
    GMD_CODE_START("C++");
    codemultiNoteC11Array( Vector<double> v1({1,2,3,4}) );
    codemultiNoteC11Array( Vector<double> v2({0,0,0,0}) );
    codemulti( v2 = 2*v1 );
    GMD_CODE_END();
    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultend();
  }
  
  {
    EXAMPLE(Nex++,"Assign from `std` containers.");
    GMD_CODE_START("C++");
    codemultiNoteC11Array( std::vector<double> vstd({1,2,3,4}) );
    codemulti( Vector<double> v1(4) );
    codemulti( v1 = vstd );
    codemultiNoteC11Array( std::array<double, 3> varray = {10,20,30} );
    codemulti( Vector<double> v2(3) );
    codemulti( v2 = varray );
    codemultiNoteC11Array( std::valarray<double> myvalarray = {100,200} );
    codemulti( Vector<double> v3(2) );
    codemulti( v3 = myvalarray );
    codemultiNoteC11Array( std::list<double> mylist = {-1,-2}; );
    codemulti( Vector<double> v4(2) );
    codemulti( v4 = mylist );
    GMD_CODE_END();
    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultmulti(v3);
    resultmulti(v4);
    resultend();
  }


  mathq_toc();

  return 0;
}
