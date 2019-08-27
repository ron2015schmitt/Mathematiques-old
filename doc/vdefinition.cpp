
// flag for run-time bounds and size checking
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
    codemultiNoteC11Array( Vector<double> vec( CARRAY({0,1,2,3}) ) );
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


  header3("Setting and getting the wrapped `valarray`");
  text("* In the example below");
  text("  * valarray `vaptr` points to a new valarray");
  text("  * `vec` is constructed with zero size");
  text("  * `vec` is set to wrap `vaptr`" );
  text("  * `valias` is referenced to the valarray inside `vec`.");

  {
    cr();
    example(Nex++, "Setting and getting the wrapped `valarray`");
    cr();
    codestart("C++");
    codemulti(using namespace std);
    codemulti( valarray<double>* vaptr = new valarray<double>(4) );
    codemulti( Vector<double> vec(0) );
    codemulti( vec.setValArray(vaptr) );
    codemulti( valarray<double>& valias = vec.getValArray() );
    codemulti( (*vaptr)[0] = 99 );
    codemulti( vec[1] = 1 );
    codemulti( valias[2] = 2 );
    codeend();
    cr();
    resultstart();
    resultmulti(*vaptr);
    resultmulti(vec);
    resultmulti(valias);
    resultend();

  }

  text("  * The above code is correct in that it does not delete the object pointed to by `vaptr`.  After calling method `setValArray`, the `Vector` takes ownership and will delete the valarray in its destrcutor.");

  
  matricks_toc();
  
  return 0;
}
