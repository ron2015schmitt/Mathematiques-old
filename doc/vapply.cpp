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
  mdtitle("Applying User-defined functions");
  matricks_preamble();

  header3("Applying User-defined functions");
  text("Since ");

  {
  codestart("C++");
  codemulti(struct X {static double increment (double x) {return ++x;}});
  codemulti( Vector<double> v1(CARRAY({1,2,3,4}) ) ) ;
  codemulti( Vector<double> v2 );
  codemulti( v2 = v1.getValArray().apply(X::increment) );
  codeend();
  resultstart();
  resultmulti( v1  );
  resultmulti( v2  );
  resultend();
  cr();
  }
  

  matricks_toc();


  return 0;
}
