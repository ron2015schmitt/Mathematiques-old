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
  mdtitle("Vector relational operators (`==`,`<`,`>`, etc), logical operators and masks");
  matricks_preamble();

  header2("Relational operators");

  header3("Relational operators between two Vectors");
  cr();
  text("Vector relations operate element-wise, similar to arithmetic operators. Given two Vectors of the same size, a vector relational expression (eg `(v1>v2)` returns a vector of booleans of the same size"); 

  {
    cr();
    cr();
    example(Nex++,"relational operators between two vectors`");
    codestart("C++");
    codemulti( Vector<double> v1( range<double>(1,3) ) );
    codemulti( Vector<double> v2( range<double>(3,1) ) );
    codeend();
    cr();
    
   
    resultstart2("");
    resultmulti( v1 );
    resultmulti( v2 );
    resultmulti( v1 >  v2 );
    resultmulti( v1 >= v2 );
    resultmulti( v1 <  v2 );
    resultmulti( v1 <= v2 );
    resultmulti( v1 == v2 );
    resultmulti( v1 != v2 );
    resultend();
  }

  header3("Relational operators between a Vector and scalar");
  {
    cr();
    cr();
    example(Nex++,"relational operators between a vector and a scalar`");
    codestart("C++");
    codemulti( Vector<double> v( range<double>(1,3) ) );
    codeend();
    cr();
    
   
    resultstart2("");
    resultmulti( v );
    resultmulti( v >  2 );
    resultmulti( v >= 2 );
    resultmulti( v <  2 );
    resultmulti( v <= 2 );
    resultmulti( v == 2 );
    resultmulti( v != 2 );
    resultend();
  }

  header2("Logical operators");

  header3("The element-wise logical operatora `&&`,`||`,`!`");
  {
    cr();
    cr();
    example(Nex++,"The element-wise logical operators");
    codestart("C++");
    codemulti( Vector<double> v( range<double>(1,5) ) );
    codeend();
    cr();
    
   
    resultstart2("");
    resultmulti( v );
    resultmulti(  (v > 2) );
    resultmulti( !(v > 2) );
    resultmulti( (v >= 2) && (v <= 4 ));
    resultmulti( (v <= 2) || (v >= 4 ));
    resultend();
  }

  header3("The functions `alltrue` and `numtrue`");
  {
    cr();
    cr();
    example(Nex++,"The functions `alltrue` and `numtrue`");
    codestart("C++");
    codemulti( Vector<double> v( range<double>(1,3) ) );
    codeend();
    cr();
    
   
    resultstart2("");
    resultmulti( v );
    resultmulti(  (v > 2) );
    resultmulti( alltrue(v > 2) );
    resultmulti( numtrue(v > 2) );
    resultmulti( numtrue(!(v > 2)) );
    resultmulti( alltrue(v == v) );
    resultend();
  }

  header2("Vector mask access");
  text("* A subset of a vector can be extracted using a boolean-valued vector of the same size.");
  text("* For example `v[v>0]` will return a vector containing only the positive values of v.");
  text("* Vector mask access can be used on the left hand side of assigment, allowing you to set values via masks.");
  {
    cr();
    cr();
    example(Nex++,"Using vector masks");
    codestart("C++");
    codemulti( Vector<double> v( range<double>(-10,10) ) );
    codeend();
    cr();
    
   
    resultstart2("");
    resultmulti( v );
    resultmulti( v > 6 );
    resultmulti( v[(v > 6)] );
    resultend();
    cr();

    text("Now set all elements that are larger than 6 to 6 (clipping)");
    codestart("C++");
    codemulti( v[(v > 6)] = 6. );
    codeend();
    resultstart();
    resultmulti( v );    
    resultend();
    cr();

    text("Now set all negative elements to zero");
    codestart("C++");
    codemulti( v[(v < 0)] = 0. );
    codeend();
    resultstart();
    resultmulti( v );    
    resultend();
    cr();

    
  }


  text("_Note that_ `expression[mask]` _access is not yet implemented_");

  matricks_toc();
    
  
  return 0;
}
