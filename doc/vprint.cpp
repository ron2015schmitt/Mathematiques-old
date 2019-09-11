#define MATRICKS_DEBUG 1


#include "matricks.h"

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif


// ************************************************************
// The output screenshots are generated by examples/printing.cpp
// ************************************************************


int main()
{
  using namespace matricks;
  using namespace std;
  using namespace display;
  using namespace md;

  int Nex = 1;
  
  cr();
  mdtitle("Formatted and styled printing");
  matricks_preamble();

  header2("`namespace display`: print-related functionality");
  
  header3("The function `disp(x)`");
  cr();cr();

  text("The function `disp(x)` displays both the variable name (or expression) as well as its value, formatted according to the user.   This is an incredibly useful function.");
  cr();cr();
  
  example(Nex++,"simple examples of `disp(x)` usage");
  cr();cr();
  codestart("C++");
  codemulti(  int n = 45 );
  codemulti(  double x = 3.14 );
  codemulti(  double vals[] = {1.1,2.2,3.3} );
  codemulti(  bool done = true );
  codemulti( Vector<double> v = range<double>(1,10) );
  codemulti(  char str[] = "hello" );
  codemulti(  std::string s = "world"  );
  codemulti(  std::complex<double> z(1,-1)  );
  codeend();

  text("display each varible using `disp`:");
  cr();cr();

  codestart("C++");
  text("disp(n);");
  text("disp(x);");
  text("disp(vals);");
  text("disp(done);");
  text("disp(v);");
  text("disp(str);");
  text("disp(s);");
  text("disp(z);");
  codeend();

  cr();cr();
  text("An actual screen-shot of the output is shown below:");
  cr();cr();
  text("![disp example 1](disp_example1.png)");
  

  header3("The function `tdisp(x)`");
  cr();cr();

  text("The function `tdisp(x)` displays the variable type, in addition to the variable name and value");
  cr();cr();
  
  example(Nex++,"simple examples of `tdisp(x)` usage");

  text("display each varible using `tdisp`:");
  cr();cr();

  codestart("C++");
  text("tdisp(n);");
  text("tdisp(x);");
  text("tdisp(vals);");
  text("tdisp(done);");
  text("tdisp(v);");
  text("tdisp(str);");
  text("tdisp(s);");
  text("tdisp(z);");
  codeend();

  cr();cr();
  text("An actual screen-shot of the output is shown below:");
  cr();cr();
  text("![disp example 2](disp_example2.png)");


  matricks_toc();

  return 0;
}
