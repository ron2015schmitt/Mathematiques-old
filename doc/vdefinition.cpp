
// flag for run-time bounds and size checking
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
  mdtitle("Vector definition");
  matricks_preamble();

  header3("A `Matricks::Vector` wraps a `std::valarray`");
  text("* This bears repeating: a `Matricks::Vector` wraps a `std::valarray`");
  text("* In the example below");
  text("  * `valias` is referenced to the valarray inside `vec`.");

  {
    cr();
    example(Nex++, "Getting the `valarray` wrapped by a `Vector`.");
    codestart("C++");
    codemulti(using namespace std);
    codemultiNoteC11Array( Vector<double> vec( CARRAY({0,1,2,3}) ) );
    codemulti( valarray<double>& valias = vec.getValArray() );
    codemulti( vec[1] = -1 );
    codemulti( valias[2] = -2 );
    codeend();
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
