#define MATRICKS_DEBUG 1


#include "matricks.hpp"
using namespace matricks;

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
  
  int Nex = 1;
  
  cr();
  mdtitle("Access subsets of Vector elements");
  matricks_preamble();

  text("You can ccess avector elements using a `Vector` of indices or a C++11 `initializer_list` of indices");

  
  header2("Element access `Vector[Vector<index_type>]`");


  header3("Access vector elements using a `Vector` or a C++11 `initializer_list` of indices");
  cr();
  text("* The index Vector _can be smaller than or greater than or equal to_ the length to the data Vector!");
  text("* The index Vector _can have repeated indices and indices can be in any order_!");
  {
    cr();
    cr();
    example(Nex++,"Access via a C++11 initializer_list");
    codestart("C++");
    codemulti( Vector<double> v( linspace<double>(0,1,11) ) );
    codemulti( Vector<index_type> veven( range<index_type>(0,10,2) ) );
    codemulti( Vector<index_type> vodd( range<index_type>(1,10,2) ) );
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
    resultmulti( v[((veven,vodd),veven),vodd] );
    resultend();
  }


 header2("Element access `Vector[initializer_list<index_type>]`");


  #if CPP11 == 1
  header3("Access vector elements using a `Vector` or a C++11 `initializer_list` of indices");
  cr();
  text("* The list can be smaller than or greater than or equal to the length to the data Vector.");
  text("* The list can have repeated indices and indices can be in any order.!");
  {
    cr();
    cr();
    example(Nex++,"Access via a C++11 initializer_list");
    codestart("C++");
    codemulti( Vector<double> v( linspace<double>(0,1,11) ) );
    dispcr(v);
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
