#define MATRICKS_DEBUG


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
  mdtitle("Vector file i/o");
  matricks_preamble();


// // the load and save functions use the standard C++ file streams
  // // and are provided as a convenience

  // Vector<double> v1(5,"vec1");
  // Vector<double> v2("vec2");

  // dispcr(v2);

  // "{1,2,3,4,5}" >> v1;
  // dispcr(v1);

  // // save a vector to a file in default "braces" format
  // save(v1,"v1.temp");

  // // load a vector from a file in "braces" format
  // // ** NOTE THAT THE DESTINATION VECTOR IS CLEARED AND RESIZED TO MATCH
  // // ** THE DATA IN The FILE
  // load(v2,"v1.temp");

  // dispcr(v2);


  // "{1.1,1.2,1.3,1.4,1.5}" >> v1;
  // dispcr(v1);


  // // save a vector to a file in default "no braces" format
  // v1.textformat(text_nobraces);
  // save(v1,"v1b.temp");

  // // load a vector from a file in "no braces" format
  // v2.clear();
  // dispcr(v2);
  // v2.textformat(text_nobraces);
  // load(v2,"v1b.temp");

  // dispcr(v2);


  matricks_toc();

  return 0;
}
