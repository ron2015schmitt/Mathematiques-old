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

  header2("`namespace display`: print-related functionality");
  
  header2("The function `disp(x)`");

  text("The function `disp(x)` displays both the variable name (or expression) as well as its value, formatted according to the user.   This is an incredibly useful function.");
  
  example(Nex++,"simple examples of `disp(x)` usage");
  codestart("C++");
  codemulti(  int n = 45 );
  codemulti(  double x = 3.14 );
  codemulti(  double vals[] = {1.1,2.2,3.3} );
  codemulti(  char str[] = "hello" );
  codemulti(  std::string s = "world"  );
  codemulti(  std::complex<double> z(1,-1)  );
  codeend();

  text("display each varible using `disp`:");

  
  codestart("C++");
  text("disp(n)");
  text("disp(x)");
  text("disp(vals)");
  text("disp(str)");
  text("disp(s)");
  text("disp(z)");
  codeend();

  text("An actual screen-shot of the output is shown below:");
  text("![disp example 1](disp_example1.png)");
  
  matricks_toc();


  return 0;
}
