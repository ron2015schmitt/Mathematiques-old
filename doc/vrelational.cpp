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
  mdtitle("Vector relational operators (`==`,`<`,`>`, etc), masks, logical operators (`!`,`&&`,etc) and logical functions (`alltrue`,`anytrue`,`numtrue`,`findtrue`)");
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

  header2("Logical functions");

  header3("The functions `alltrue`, `anytrue`, `numtrue`, and `findtrue`");
  {
    cr();
    text("* The function `alltrue(v)` returns a `bool`: true if every element of `v` is true, otherwise it returns false");
    cr();
    text("* The function `anytrue(v)` returns a `bool`: true if any element of `v` is true, otherwise it returns false");
    cr();
    text("* The function `numtrue(v)` returns a `size_type` equal to the number of elements of `v` that are true. ");
    cr();
    text("* The function `findtrue(v)` returns a `Vector<index_type>` which contains the indices of the true elements of `v`. ");
    cr();
    cr();
    example(Nex++,"The functions `alltrue`, `anytrue`, `numtrue`, and `findtrue`");
    codestart("C++");
    codemulti( Vector<double> v( range<double>(1,3) ) );
    codeend();
    cr();
    
   
    resultstart2("");
    resultmulti( v );
    resultmulti(  (v > 2) );
    resultmulti( alltrue(v > 2) );
    resultmulti( alltrue(v > 0) );
    resultmulti( anytrue(v > 2) );
    resultmulti( numtrue(v > 2) );
    resultmulti( numtrue(!(v > 2)) );
    resultmulti( numtrue(v > 0) );
    resultmulti( findtrue(v > 2) );
    resultmulti( findtrue(v > 0) );
    resultend();
  }

  matricks_toc();
    
  
  return 0;
}
