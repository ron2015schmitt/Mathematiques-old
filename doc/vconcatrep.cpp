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
 
  using namespace std;
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
    codemulti( Vector<double> v1( range<double>(0,2) ) );
    codemulti( Vector<double> v2( range<double>(3,4) ) );
    codeend();
    cr();

    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultmulti( (v1,v2) );
    resultmulti( (v1,v2,v1) );
    resultmulti( (v1,v2,v1,v2) );
    resultmulti( (10*v1,v2)  );
    resultmulti( (v1,10*v2)  );
    resultmulti( (10*v1,10*v2)  );
    resultend();


    codestart("C++");
    codemulti( Vector<double> va(2) );
    codemulti( Vector<double> vb(3) );
    codemulti( (va,vb) = range<double>(1,5) );
    codeend();
    cr();
    resultstart();
    resultmulti(va);
    resultmulti(vb);
    resultend();

    codestart("C++");
    codemulti( Vector<double> ua(2) );
    codemulti( Vector<double> ub(3) );
    codemulti( (ua[{1,0}],ub) = range<double>(1,5) );
    codeend();
    cr();
    resultstart();
    resultmulti(ua);
    resultmulti(ub);
    resultend();

    codestart("C++");
    codemulti( Vector<double> wa(2) );
    codemulti( Vector<double> wb(3) );
    codemulti( (wa,wb[{2,1,0}]) = range<double>(1,5) );
    codeend();
    cr();
    resultstart();
    resultmulti(wa);
    resultmulti(wb);
    resultend();

    codestart("C++");
    codemulti( Vector<double> za(2) );
    codemulti( Vector<double> zb(3) );
    codemulti( (za[{1,0}],zb[{2,1,0}]) = range<double>(1,5) );
    codeend();
    cr();
    resultstart();
    resultmulti(za);
    resultmulti(zb);
    resultend();

    
    
    codestart("C++");
    codemulti( Vector<double> v3 );
    codemulti( v3 = (v1,v2,v1,v2) );
    codemulti( Vector<double> v4a );
    codemulti( v4a = (v1,v2) );
    codemulti( Vector<double> v4b );
    codemulti( v4b = (v1,10*v2) );
    codemulti( Vector<double> v4c );
    codemulti( v4c = (10*v1,v2) );
    codemulti( Vector<double> v4d );
    codemulti( v4d = (10*v1,10*v2) );
    codemulti( Vector<double> v5( range<double>(0,6) )  );
    codemulti( Vector<double> vc(2) );
    codemulti( Vector<double> vd(5) );
    //    codemulti( (vc[{1,0}],vd) = v5 );
    codemulti( Vector<double> ve(2) );
    codemulti( Vector<double> vf(5) );
    //    codemulti( (ve,vf[{4,3,2,1,0}]) = v5 );
    codeend();
    cr();

   
    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultmulti(v3);
    resultmulti(v4a);
    resultmulti(v4b);
    resultmulti(v4c);
    resultmulti(v4d);
    resultmulti(v5);
    resultmulti(va);
    resultmulti(vb);
    resultmulti(vc);
    resultmulti(vd);
    resultmulti(ve);
    resultmulti(vf);
    resultmulti( (v1,v1,v1) );
    resultmulti( (v1,v2,4*v1) );
    resultmulti( (5*v1,v2) );
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
  cr();
  text("_Note that_ `rep(expression, m)` _is not yet implemented_.");

  matricks_toc();


  return 0;
}
