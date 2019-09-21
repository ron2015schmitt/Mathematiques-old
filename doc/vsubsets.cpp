#define MATRICKS_DEBUG 1


#include "matricks.h"

#include <iostream>
#include <string>
#include <algorithm>

// used to demonstrate how to convert to C++ vectors
#include <vector>

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
  mdtitle("Access subsets of Vector elements");
  matricks_preamble();

  text("You can ccess avector elements using a `Vector` of indices or a C++11 `initializer_list` of indices");

  
  header2("Access vector elements using a `Vector` of indices");

  header3("Element access `Vector[Vector]`");
  cr();
  text("* The index Vector _can be smaller than or greater than or equal to_ the length to the data Vector!");
  text("* The index Vector _can have repeated indices and indices can be in any order_!");
  {
    cr();
    cr();
    example(Nex++,"Access via a Vector of indices");
    codestart("C++");
    codemulti( Vector<double> v( linspace<double>(0,1,11) ) );
    codemulti( Vector<index_type> veven( range<index_type>(0,10,2) ) );
    codemulti( Vector<index_type> vodd( range<index_type>(1,10,2) ) );
    codemulti( Vector<index_type> vconst(15,1 ) );
    codeend();
    cr();
    resultstart();
    resultmulti( v );
    resultmulti( veven );
    resultmulti( v[veven] );
    resultmulti( v[veven[1]] );
    resultmulti( vodd );
    resultmulti( v[vodd] );
    resultmulti( v[vodd[1]]);
    resultmulti( v[veven,vodd] );
    resultmulti( v[vodd[veven[1]]]);
    resultmulti( vconst );
    resultmulti( v[vconst] );
    resultend();
  }



  #if CPP11 == 1
  header2("Access vector elements using an C++11 `initializer_list` of indices");
  header3("Element access `Vector[initializer_list]`");

  cr();
  text("* The list can be smaller than or greater than or equal to the length to the data Vector.");
  text("* The list can have repeated indices and indices can be in any order!");
  {
    cr();
    cr();
    example(Nex++,"Access via a C++11 initializer_list");
    codestart("C++");
    codemulti( Vector<double> v( linspace<double>(0,1,11) ) );
    disp(v);
    codeend();
    cr();
    resultstart();
    resultmulti( v[{0,4}] );
    resultmulti( v[{4,0,1,4}] );
    resultmulti( v[{1,0,2}] );
    resultmulti( v[{4,3,2,1,0}] );
    resultmulti( v[{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}] );
    resultend();
  }
#endif


  matricks_toc();


  return 0;
}
