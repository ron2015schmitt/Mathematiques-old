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
  mdtitle("Debugging");
  mathq_preamble();



  text("The Mathématiques library provides extensive debugging operation, turned on using the flag `MATHQ_DEBUG`");

  text("In this mode extensive error checking is performed to notify the programmer of");

  text(" - out of bounds access for vectors or matrices (e.g. x[10] where x has size less than 9");
  text(" - adding/subtracting/multiplying/dividing vector or matrices of unequal size");
  text(" - invalid dot products of vector and/or matrices ");
  text(" - other assorted errors and warnings");


  header2("SETTING `MATHQ_DEBUG` MODE");

  text("There are two methods to accomplish this.");

  text("1. Use the provided sample makefile and specify `MATHQ_DEBUG=1` on the command line");

  text("```make clean MATHQ_DEBUG=1 myprogram```");

  text("The target `clean` is not needed, but is a recomended practice.");


  text("1. Add a `#define MATHQ_DEBUG 1` statement BEFORE each `mathq.h` include statement");


  codestart("C++");

  text("#define MATHQ_DEBUG 1");
  text("#include \"mathq.h\"");
  codeend();

  header2("DEBUG LEVELS");

  text(" to be written...");

  header2("RECOMMENDATIONS");

  text("* While developing your code, use `MATHQ_DEBUG` mode.  When you are convinced that it is operating without errors or warnings, run normally.");
  
  text("* Compile a `MATHQ_DEBUG` and a quick version of your code, giving the executables different names. This way if a segmentation fault occurs, or you otherwise suspect an error, you can quickly check the problem under careful mode.");
  
  mathq_toc();
  
  return 0;
}
