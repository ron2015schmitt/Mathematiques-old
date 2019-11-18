
// flag for run-time bounds and size checking
#define MATRICKS_DEBUG 1


#include "matricks.h"
#include "gitmd.h"

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>





int main()
{
  using namespace matricks;
  using namespace std;
  using namespace display;
  using namespace md;
  int Nex = 1;


  
  matricks_toc();
  cr();cr();
  mdtitle("under the hood—`Vector` definition");
  matricks_preamble();
  text("* _This information is mostly irrelavent to usage but is provided for rare cases when you may want to access the underlying data type_.");

  header3("The Vector class is a wrapper");
  text("* The `matricks::Vector` wraps a `std::valarray`");
  text("* In the example below");
  text("  * `valias` is referenced to the valarray inside `vec`.");

  {
    cr();
    example(Nex++, "Getting the `valarray` wrapped by a `Vector`.");
    cr();
    codestart("C++");
    codemulti(using namespace std);
    codemultiNoteC11Array( Vector<double> vec({0,1,2,3}) );
    codemulti( valarray<double>& valias = vec.getValArray() );
    codemulti( vec[1] = -1 );
    codemulti( valias[2] = -2 );
    codeend();
    cr();
    resultstart();
    resultmulti(vec);
    resultmulti(valias);
    resultend();

  }


  header3("Getting the wrapped `valarray`/`array`");
  text("* In the example below");
  text("  * `vec` is constructed");
  text("  * `valias` is referenced to the valarray inside `vec`.");

  {
    cr();
    example(Nex++, "Setting and getting the wrapped `valarray`");
    cr();
    codestart("C++");
    codemulti(using namespace std);
    codemulti( Vector<double> vec(2) );
    codemulti( valarray<double>& valias = vec.getValArray() );
    codemulti( vec[1] = 1 );
    codemulti( valias[2] = 2 );
    codeend();
    cr();
    resultstart();
    resultmulti(vec);
    resultmulti(valias);
    resultend();

  }


  
  matricks_toc();
  
  return 0;
}
