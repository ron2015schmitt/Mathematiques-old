#define MATRICKS_DEBUG 1


#include "matricks.h"

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
  
  cr();
  mdtitle("Formatted, styled (color, bold etc) printing");
  matricks_preamble();
  Header2("The function `disp(x)`");

  text("The function `disp(x)` displays both the variable name (or expression) as well as its value, formatted according to the user.   This is an incredibly useful function.");

    example(Nex++,"simple examples of `disp(x)` usage");
    codestart("C++");
 
    codeend();

  
  
  matricks_toc();


  return 0;
}
