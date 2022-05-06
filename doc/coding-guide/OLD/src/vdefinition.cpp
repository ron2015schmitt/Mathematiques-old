
// flag for run-time bounds and size checking
#define MATHQ_DEBUG 1


#include "mathq.h"

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>





int main()
{
  using namespace mathq;
  using namespace std;
  using namespace display;
  
  int Nex = 1;


  
  mathq_toc();
  CR();CR();
  mdtitle("under the hood—`Vector` definition");
  mathq_preamble();
  OUTPUT("* _This information is mostly irrelavent to usage but is provided for rare cases when you may want to access the underlying data type_.");

  header3("The Vector class is a wrapper");
  OUTPUT("* The `mathq::Vector` wraps a `std::valarray`");
  OUTPUT("* In the example below");
  OUTPUT("  * `valias` is referenced to the valarray inside `vec`.");

  {
    CR();
    EXAMPLE(Nex++, "Getting the `valarray` wrapped by a `Vector`.");
    CR();
    GMD_CODE_START("C++");
    codemulti(using namespace std);
    codemultiNoteC11Array( Vector<double> vec({0,1,2,3}) );
    codemulti( valarray<double>& valias = vec.getValArray() );
    codemulti( vec[1] = -1 );
    codemulti( valias[2] = -2 );
    GMD_CODE_END();
    CR();
    resultstart();
    resultmulti(vec);
    resultmulti(valias);
    resultend();

  }


  header3("Getting the wrapped `valarray`/`array`");
  OUTPUT("* In the example below");
  OUTPUT("  * `vec` is constructed");
  OUTPUT("  * `valias` is referenced to the valarray inside `vec`.");

  {
    CR();
    EXAMPLE(Nex++, "Setting and getting the wrapped `valarray`");
    CR();
    GMD_CODE_START("C++");
    codemulti(using namespace std);
    codemulti( Vector<double> vec(2) );
    codemulti( valarray<double>& valias = vec.getValArray() );
    codemulti( vec[1] = 1 );
    codemulti( valias[2] = 2 );
    GMD_CODE_END();
    CR();
    resultstart();
    resultmulti(vec);
    resultmulti(valias);
    resultend();

  }


  
  mathq_toc();
  
  return 0;
}
