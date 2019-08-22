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
  mdtitle("Vector `join` and `rep` functions");
  matricks_preamble();

  
  header3("Vector `join` function");
  text("* The Vector `join` function joins two vectors");
  text("* The comma operator `,` performs the same function.");
  text("* This is an expression.  It does not create intermeidate objects.");
  text("* join can be used on the left hand side as well!");
 
  {
    cr();
    cr();
    example(Nex++,"Vector `join` function");
    codestart("C++");
    codemulti( Vector<double> v1( range<double>(0,3) ) );
    codemulti( Vector<double> v2( range<double>(2,0) ) );
    codemulti( Vector<double> v3 );
    codemulti( v3 = join(v1,v2) );
    codemulti( Vector<double> v4 );
    codemulti( v4 = (v1,10*v2) );
    codemulti( Vector<double> va(2) );
    codemulti( Vector<double> vb(5) );
    //codemulti( (va,vb) = v4 );
    codeend();
    cr();

   
    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultmulti(v3);
    resultmulti(v4);
    resultmulti(va);
    resultmulti(vb);
    resultmulti( join(v1,v1) );
    resultmulti( join(join(v1,v1),v1) );
    resultmulti( (v1,v1) );
    resultmulti( (v1,v1,v1) );
    resultmulti( (v1,v2,4*v1) );
    resultend();
  }

  header3("Vector `rep` function");
  text("* The Vector `rep(v,m)` function replicates the input vector `m` times.");
  text("* `rep` cannot be used on the left hand side of assignment, since it doesn't provide utility to do so.");

  
  {
    cr();
    cr();
    example(Nex++,"Vector `rep` function");
    codestart("C++");
    codemulti( Vector<double> v1( range<double>(1,3) ) );
    codemulti( Vector<double> v2( range<double>(-1,-2) ) );
    codemulti( Vector<double> v3 );
    codemulti( v3 = rep(v1,3) );
    codemulti( Vector<double> v4 );
    codemulti( v4 = (rep(v1,2), rep(v2,3)) );
    codeend();
    cr();

   
    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultmulti(v3);
    resultmulti(v4);
    resultend();
  }

  cr();
  text("_Note that_ `join(expression,expression)` _is not yet implemented_.");
  cr();
  text("_Note that_ `rep(expression, m)` _is not yet implemented_.");

  matricks_toc();


  return 0;
}
