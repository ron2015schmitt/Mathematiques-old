
// flag for run-time bounds and size checking
#define MATRICKS_DEBUG 1


#include "matricks.h"
#include "gitmd.h"

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif



int main()
{
  using namespace matricks;
  using namespace std;
  using namespace display;
  using namespace md;

  int Nex = 1;
  
  matricks_toc();
  cr();cr();
  mdtitle("The `range` function");
  matricks_preamble();

  header3("Increasing Sequences");

  text("* The function `range<D>(start,end)` returns a Vector<D> containing the numbers `{start, start+1, start+2, ..., (end)}`");
  cr();
  example(Nex++, "Increasing sequences using `range`");
  codestart("C++");
  disp(range<int>(1,10));
  disp(range<double>(-3,3));
  codeend();

  header3("Decreasing Sequences");
  text("* Counting down is also supported");
  cr();
  example(Nex++, "Decreasing sequence using `range`");
  codestart("C++");
  disp(range<int>(10,0));
  codeend();


  header3("Non-integer Sequences");

  text("* The start and end need not be integers ");
  cr();
  example(Nex++, "Floating point sequences using `range`");
  codestart("C++");
  disp(range<double>(1.5,5.5));
  disp(range<double>(5.5,1.5));
  codeend();

  header3("Arbitrary stride");

  
  text("* The function `range<D>(Nstart,Nend,Nstride)` returns a Vector<D> containing the numbers `{start, start+stride, start+2*stride, ..., (end)}`");

  cr();
  example(Nex++, "Seqeunces of different strides using `range`");
  codestart("C++");
  disp(range<int>(2,10,2));
  disp(range<double>(0,10,0.5));
  codeend();

  header3("The end point isn't always included");

  text("* The end point is only included when ");
  text("```C++");
  text("end == start + n * stride");
  text("```");
  text("where `n` is an integer.\n");

  cr();
  example(Nex++, "End point is not included in certain cases");
  codestart("C++");
  disp(range<int>(0,5,2));
  disp(range<double>(1,3.5));
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


  header3("Assigning `Vector`'s using `range`");

  {
    cr();
    cr();
    example(Nex++,"Assigning a `Vector`'s to a *`range`*");
    codestart("C++");
    codemulti( const size_t N = 10);
    codemulti( Vector<double> v (N));
    codemulti( v = range<double>(0,N-1));
    codeend();
    cr();

    resultstart();
    resultmulti(v);
    resultend();
  }




  matricks_toc();

  return 0;
}
