
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
  mdtitle("Vector definition");
  matricks_preamble();

  header3("A `Matricks::Vector` wraps a `std::valarray`");
  text("* This bears repeating: a `Matricks::Vector` wraps a `std::valarray`");

  {
    example(Nex++, "Declare vector `v1` (initialize to zeroes).");
    codestart("C++");
    codemulti( const size_type N = 4 );
    codemulti( Vector<double> v1(N) );
    codeend();
    result(v1);
  }
  
  matricks_toc();
  
  return 0;
}
