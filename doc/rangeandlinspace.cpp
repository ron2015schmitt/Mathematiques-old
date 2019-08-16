
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
  mdtitle("The `**range**` and `**linspace**` functions");
  matricks_preamble();
  

  header2("Using the `**range**` Function");
  text("* For integers `start`, `end`, the `range<D>(start,end)` function returns a Vector<D> containing the numbers {`start`,`start`+1, `start`+2,... , `end`}");
  codestart("C++");
  dispcr(range<int>(1,8));
  dispcr(range<double>(-3,3));
  codeend();

  text("* Counting down is also supported");
  codestart("C++");
  dispcr(range<int>(10,0));
  codeend();

  
  text("* The range<D>(Nstart,Nend,Nstride) function returns a Vector<D> containging the whole numbers from start counting by stride");
  


  {
    cr();
    cr();
    example(Nex++,"Assign `Vector`s of various types  using the **`range`** function");
    codestart("C++");
    code( Vector<unsigned int> v1 (4) );
    code( v1 = range<unsigned int>(0,3) );
    dispcr(v1);
    code( Vector<int> v2 (4) );
    code( v2 = range<int>(0,3) );
    dispcr(v2);
    code( Vector<double> v3 (4) );
    code( v3 = range<double>(0,3) );
    dispcr(v3);
    codeend();
    cr();
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
