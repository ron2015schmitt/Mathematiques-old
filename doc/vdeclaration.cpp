
// flag for run-time bounds and size checking
#define MATRICKS_CAREFUL


#include "matricks.hpp"
using namespace Matricks;

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if cpp10 == 1
#include <initializer_list>
#endif

char _str[2048];


#define header1(x)  printf("# %s \n", x)
#define header2(x)  printf("## %s \n", x)
#define header3(x)  printf("### %s \n", x)
#define text(x)  printf("%s \n", x)

#define printexp(x)  printf("-> %s = %s\n",  #x, x)

#define codestart(lang) std::cout << std::string("```") << std::string(lang) << std::string("\n")
//#define codestart() printf( "```\n" )
#define codemulti(...)  printf("%s;\n",  #__VA_ARGS__); __VA_ARGS__

#define codeend() printf("```\n")
#define code(x)  codestart();codemulti(x);codeend()

#define resultstart() printf("**The result is**\n```C++\n")
#define resultmulti(...)  printf("  ");dispcr(__VA_ARGS__)
#define resultend() printf("```\n\n")
#define result(x)  resultstart();resultmulti(x);resultend()

int _e = 1;

//#define example(x) sprintf(_str,"**EXAMPLE%2d**: ",_e++); text(std::strcat(_str,x))
#define example(x) sprintf(_str,"**EXAMPLE%2d**: ",_e++); text(std::strcat(_str,x))


#define Vector_(D, var, sz) Matricks::Vector<D> var(sz,#var)

#define RVector2_(D, var, sz) sprintf(_str,"%s :: %s", __FUNCTION__, #var); Matricks::Vector<D> var(sz, "ron")

// __FUNCTION__ __FILE__  __FILE__


int main()
{

  cr();
  header1("Declaring and Assigning Vectors in mātricks");
  printf("This document is automatically generated from file **`%s`**:\n",__FILE__);
  
  header2("Declaring vectors");
  
  example("Declare vector `v1`.");
  codestart("C++");
  codemulti( const size_type N = 4 );
  codemulti( Vector<double> v1(N) );
  codeend();
  result(v1);


  example("Declare `v2` and initialize to a constant" );
  codestart("C++");
  codemulti( Vector<double> v2(4, -1 ) );
  codeend();
  result(v2);

  example("Declare `v3` and initialize to a **C-style array** of values" );
  codestart("C++");
  codemulti( Vector<double> v3( 4, (const double[]) {10, 20, 30, 40} )  );
  codeend();
  result(v3);

  if (cpp11) {
    example("Declare `v4` and initialize directly (**__C++11__**)" );
    codestart("C++");
    codemulti( Vector<double> v4({10, 20, 30, 40})  );
    codeend();
    result(v4);
  }
  

  example("Declare `v5` and initialize to values of `v3`" );
  codestart("C++");
  codemulti( Vector<double> v5(v3) );
  codeend();
  result(v5);

  example("Declare `v6` and initialize to an expression" );
  codestart("C++");
  codemulti( Vector<double> v6(2*v3+1) );
  codeend();
  result(v6);

  
  return 0;
}
