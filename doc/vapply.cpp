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
  codemulti(struct X {static int increment (int x) {return ++x;}});
  codemulti( Vector<int> v1(4, (const int[]) {1,2,3,4} ) ) ;
  codemulti( Vector<int> v2 );
  codemulti( v2 = v1.getValArray().apply(X::increment) );
  resultstart2(": user-defned function");
  resultmulti( v1  );
  resultmulti( v2  );
  resultend();
  cr();
  }
  

  matricks_toc();


  return 0;
}
