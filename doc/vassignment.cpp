
// flag for run-time bounds and size checking
#define MATRICKS_DEBUG 1


#include "matricks.h"

#include <iostream>
#include <string>

#include <vector>
#include <list>

#if CPP11 == 1
#include <initializer_list>
#endif



int main()
{
  using namespace matricks;
  using namespace std;
  using namespace display;
  using namespace md;

  int Nex = 1;
  
  matricks_toc();
  cr();cr();
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
    cr();
    example(Nex++,"Assign from a C Array.");
    cr();
    text("_In DEBUG mode, this generates a warning since it is a dangerous practice. Use a C++11 list instead._");
    codestart("C++");
    codemulti( Vector<double> v(4) );
    codemulti( v = (const double[]) {1,2,3,4} );
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
  

#if CPP11==1
  {
    example(Nex++,"Assign from another `Vector`.");
    cr();
    text("Note that values are copied from `v2` to `v1`");
    codestart("C++");
    codemultiNoteC11Array( Vector<double> v1(AORLIST({1,2,3,4})) );
    codemultiNoteC11Array( Vector<double> v2(AORLIST({0,0,0,0})) );
    codemulti( v2 = v1 );
    codemulti( v1[0] = 100 );
    codemulti( v2[0] = 200 );
    codeend();
    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultend();
  }
#endif
  
#if CPP11==1
  {
    example(Nex++,"Assign from a `Vector` expression.");
    codestart("C++");
    codemultiNoteC11Array( Vector<double> v1(AORLIST({1,2,3,4})) );
    codemultiNoteC11Array( Vector<double> v2(AORLIST({0,0,0,0})) );
    codemulti( v2 = 2*v1 );
    codeend();
    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultend();
  }
#endif
  
#if CPP11==1
  {
    example(Nex++,"Assign from `std` containers.");
    codestart("C++");
    codemultiNoteC11Array( std::vector<double> vstd(AORLIST({1,2,3,4})) );
    codemulti( Vector<double> v1(4) );
    codemulti( v1 = vstd );
    codemultiNoteC11Array( std::array<double, 3> varray = AORLIST({10,20,30}) );
    codemulti( Vector<double> v2(3) );
    codemulti( v2 = varray );
    codemultiNoteC11Array( std::valarray<double> myvalarray = AORLIST({100,200}) );
    codemulti( Vector<double> v3(2) );
    codemulti( v3 = myvalarray );
    codemultiNoteC11Array( std::list<double> mylist = AORLIST({-1,-2}); );
    codemulti( Vector<double> v4(2) );
    codemulti( v4 = mylist );
    codeend();
    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultmulti(v3);
    resultmulti(v4);
    resultend();
  }
#endif


  matricks_toc();

  return 0;
}
