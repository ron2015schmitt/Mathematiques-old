#define MATRICKS_DEBUG 1


#include "matricks.h"
#include "gitmd.h"

#include <iostream>
#include <string>

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
  mdtitle("Vector Debugging (`MEBUG=1`)");
  matricks_preamble();

  matricks_toc();


  return 0;
}
