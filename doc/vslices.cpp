#define MATRICKS_DEBUG


#include "matricks.hpp"
using namespace matricks;

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
  mdtitle("Vector slices");
  matricks_preamble();

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
    resultmulti( v[2,6]);
    resultmulti( v[seq(2,6)]);
    resultend();
  }



  matricks_toc();


  return 0;
}
