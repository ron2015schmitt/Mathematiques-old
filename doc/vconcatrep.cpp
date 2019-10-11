#define MATRICKS_DEBUG 1

 
#include "matricks.h"
#include "gitmd.h"

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>


int main()
{
  using namespace matricks;
  using namespace std;
  using namespace display;
  using namespace md;
 
  int Nex = 1;


  matricks_toc();
  cr();cr();
  mdtitle("Vector join operator `(v1,v2)` and `rep` function");
  matricks_preamble();

  
  header3("Vector join operator `,` ");
  text("* The Vector operator `,` joins two vectors");
  text("* This is an expression.  It does not create intermediate objects.");
  text("* join can be used on the left hand side as well!");
 
  {
    cr();
    cr();
    example(Nex++,"Vector join operator `,`");
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

    cr();
    text("The following are examples usign the join operator on the left hand side");
    cr();
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
  }    
    

  header3("Vector `rep` function");
  text("* The Vector `rep(v,m)` function replicates the input vector `m` times.");
  text("* `rep` cannot be used on the left hand side of assignment, since it doesn't provide utility to do so.");
  text("* The Vector `rep(v,m)` function can be combined with the join operator.");

  
  {
    cr();
    cr();
    example(Nex++,"Vector `rep` function");
    codestart("C++");
    codemulti( Vector<double> v1( range<double>(1,3) ) );
    codemulti( Vector<double> v2( range<double>(4,5) ) );
    codemulti( Vector<double> v3 );
    codemulti( v3 = rep(v1,3) );
    codemulti( Vector<double> v4 );
    codemulti( v4 = (rep(v1,2), rep(v2,3)) );
    codemulti( Vector<double> v5 );
    codemulti( v5 = rep((v1,v2),2) );
    codeend();
    cr();

   
    resultstart();
    resultmulti(v1);
    resultmulti(v2);
    resultmulti(v3);
    resultmulti(v4);
    resultmulti(v5);
    resultend();
  }

  cr();
  cr();
  
  matricks_toc();


  return 0;
}
