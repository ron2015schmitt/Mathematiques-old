
// flag for run-time bounds and size checking
#define MATRICKS_CAREFUL


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
  mdtitle("The `range` and `linspace` functions");
  matricks_preamble();
  

  header2("The `range` Function");

  header3("Increasing Sequences");

  text("* The function `range<D>(start,end)` returns a Vector<D> containing the numbers `{start,start+1, start+2,..., end}`");
  codestart("C++");
  dispcr(range<int>(1,10));
  dispcr(range<double>(-3,3));
  codeend();

  header3("Decreasing Sequences");
  text("* Counting down is also supported");
  codestart("C++");
  dispcr(range<int>(10,0));
  codeend();


  header3("Non-integer Sequences");

  text("* The start and end need not be integers ");
  codestart("C++");
  dispcr(range<double>(1.5,5.5));
  dispcr(range<double>(5.5,1.5));
  codeend();

  header3("Arbitrary stride");

  
  text("* The function `range<D>(Nstart,Nend,Nstride)` returns a Vector<D> containing the numbers `{start,start+stride, start+2*stride,..., end}`");


  header3("The end point isn't always included");

  text("* The end point is only included when ");
  text("```C++");
  text("end == start + n * stride");
  text("```");
  text("where `n` is an integer");

  text("Below are two examples where the end point is not included");
  codestart("C++");
  dispcr(range<int>(0,5,2));
  dispcr(range<double>(1,3.5));
  codeend();


  header3("Initializing `Vector`'s using `range`");

  {
    cr();
    cr();
    example(Nex++,"Initialize `Vector`'s of various data types  using the *`range`* function");
    codestart("C++");
    codemulti( Vector<unsigned int> v1 ( range<unsigned int>(0,3) ) );
    codemulti( Vector<int> v2 ( range<int>(0,3) ) );
    codemulti( Vector<double> v3 ( range<double>(0,3)) );
    codeend();
    cr();

    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultmulti(v3);
    resultend();
  }

  // {
  // cr();
  // cr();
  // example("Assign `Vector<int>` using the **`range`** function, counting down");
  // code( v1 = range<int>(4,1) );
  // cr();
  // result(v1);
  // }
  
  // cr();
  // cr();
  // example("Assign `v1` using the **`range`** function");
  // code( v1 = range<double>(400,100,-100) );
  // cr();
  // result(v1);

  // header3("Using the **`linspace`** function");
  // cr();
  // cr();
  // example("Assign `v1` using the **`linspace`** function");
  // code( v1 = linspace<double>(100,400,4) );
  // cr(); 
  // result(v1);

  // cr();
  // cr();
  // example("Assign `v1` using the **`linspace`** function");
  // code( v1 = linspace<double>(6,3,4) );
  // cr();
  // result(v1);




  matricks_toc();

  return 0;
}
