
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
  mdtitle("The `linspace` functions");
  matricks_preamble();

  header2("The `linspace` function: numerical interval [a,b]");
  text("* The function `linspace<D>(a,b,N)` returns a `Vector<D>` containing an equispaced sequence of `N` points, from `a` to `b`, spaced by `(b-a)/(N-1)`");
  text("* Note that `b` can be less than `a`, in which case the returned sequence is decreasing");
  codestart("C++");
  disp(linspace<double>(100,400,4));
  disp(linspace<unsigned int>(1,2,2));
  disp(linspace<double>(0,1,11));
  disp(linspace<double>(1,0,11));
  codeend();


  header2("The `linspace_a` function: numerical interval (a,b]");
  text("* The function `linspace_a<D>(a,b,N)` returns a `Vector<D>` containing an equispaced sequence of `N` points, from `a+delta` to `b`, where `delta=(b-a)/(N)` is the spacing between consecutive points.");
  text("* Note that `b` can be less than `a`, in which case the returned sequence is decreasing");
  codestart("C++");
  disp(linspace_a<double>(0,1,10));
  disp(linspace_a<double>(1,0,10));
  codeend();


  header2("The `linspace_b` function: numerical interval [a,b)");
  text("* The function `linspace_b<D>(a,b,N)` returns a `Vector<D>` containing an equispaced sequence of `N` points, from `a` to `b-delta`, where `delta=(b-a)/(N)` is the spacing between consecutive points.");
  text("* Note that `b` can be less than `a`, in which case the returned sequence is decreasing");
  codestart("C++");
  disp(linspace_b<double>(0,1,10));
  disp(linspace_b<double>(1,0,10));
  codeend();

  text("* This function is very useful for dealing the domain of trig functions, since typicallywe want to use the **interval [0,2*pi)**, ie we dont want to include the point 2*pi");


  header2("The `linspace_ab` function: numerical interval (a,b)");
  text("* The function `linspace_ab<D>(a,b,N)` returns a `Vector<D>` containing an equispaced sequence of `N` points, from `a+delta` to `b-delta`, where `delta=(b-a)/(N+1)` is the spacing between consecutive points.");
  text("* Note that `b` can be less than `a`, in which case the returned sequence is decreasing");
  codestart("C++");
  disp(linspace_ab<double>(0,1,9));
  disp(linspace_ab<double>(1,0,9));
  codeend();

  
  matricks_toc();

  return 0;
}
