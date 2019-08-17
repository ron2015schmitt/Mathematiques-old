
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
  mdtitle("The `linspace` function");
  matricks_preamble();

  text("* The function `linspace<D>(start,end,N)` returns a `Vector<D>` containing an equispaced sequence of `N` points, from `start` to `end`, spaced by `(start-end)/(N-1)`");
  text("* Note that `end` can be less than `start`, in which case the returned sequence is decreasing");
  codestart("C++");
  dispcr(linspace<double>(100,400,4));
  dispcr(linspace<unsigned int>(1,2,2));
  dispcr(linspace<double>(0,1,11));
  dispcr(linspace<double>(1,0,11));
  codeend();

  matricks_toc();

  return 0;
}
