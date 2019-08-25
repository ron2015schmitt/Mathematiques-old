#define MATRICKS_DEBUG 1


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
  mdtitle("Methods `Vector.sort()`, `Vector.uniq()`, `Vector.quniq()`  ");
  matricks_preamble();

  matricks_toc();


  return 0;
}
