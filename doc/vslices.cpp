#define MATRICKS_DEBUG


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
  dispcr(maxsize);
  
  int Nex = 1;
  
  cr();
  mdtitle("python-like access: negative indices, slices, lists");
  matricks_preamble();

  header2("Element access");

  header3("Positive and negative indices");
  text("Similar to python, mātricks allows negative indices");
  cr();
  text("v[-1] = v[N-1] = end element");
  text("v[-2] = v[N-2] = penultimate element");
  text("v[-N] = v[0]   = first element");
  {
    cr();
    cr();
    example(Nex++,"Positive and negative indices");
    codestart("C++");
    codemulti( Vector<double> v( range<double>(0,10) ) );
    codemulti( const int N = v.size() );
    codeend();
    cr();
    
   
    resultstart2("");
    resultmulti( v );
    resultmulti( N );
    resultmulti( v[0] );
    resultmulti( v[1] );
    resultmulti( v[N-1] );
    resultmulti( v[-1] );
    resultmulti( v[-2] );
    resultmulti( v[-N] );
    resultend();
  }


  {
    cr();
    cr();
    example(Nex++,"Reverse a vector in place.");
    codestart("C++");
    codemulti( Vector<double> v( range<double>(0,10) ) );
    codeend();
    cr();
    resultstart();
    resultmulti( v );
    resultend();
    codestart("C++");
    codemulti( for (int i = 0; i < v.size()/2; i++) std::swap(v[i],v[-i-1]) );
    codeend();
    cr();
    resultstart();
    resultmulti( v );
    resultend();
  }


  
  header2("Slices");
  header3("The [start,end] slice");

  {
    cr();
    cr();
    example(Nex++,"slice `v[start,end]`");
    codestart("C++");
    codemulti( Vector<double> v( range<double>(0,10) ) );
    codeend();
    cr();
    
   
    resultstart2("");
    resultmulti( v[seq(2,6)]);
    resultend();
  }



  matricks_toc();


  return 0;
}
