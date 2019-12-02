#define MATHQ_DEBUG 1


#include "mathq.h"
#include "gitmd.h"

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>



int main()
{
  using namespace mathq;
  using namespace std;
  using namespace display;
  using namespace md;

  int Nex = 1;
  
  mathq_toc();
  cr();cr();
  mdtitle("Vector Debugging (`MEBUG=1`)");
  mathq_preamble();

  mathq_toc();


  return 0;
}
