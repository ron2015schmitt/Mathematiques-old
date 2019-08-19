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
  mdtitle("Vector functions that return a scalar (dot product, sum, min, max etc)");
  matricks_preamble();

  header3("dot product—the `|` operator");
  text("* The dot product is accomplished via the `|` operator, such that the dot product takes a form similar to P.A.M. Dirac's 'bra-ket' notation.");
  text("* This definition becomes very useful for taking the product of matrices because any number of matrices can be multiplied in a single line of code.");
  
  {
    cr();
    cr();
    example(Nex++,"Dot product of two real vectors `(v1|v2)`");
    codestart("C++");
    codemulti(Vector<double> v1(range<double>(1,4)));
    codemultiNoteC11Array(Vector<double> v2(CARRAY({1,-1,1,-1})));
    codeend();
    cr();

   
    resultstart2("");
    resultmulti( (v1|v1) );
    resultmulti( (v2|v2) );
    resultmulti( (v1|v2) );
    resultmulti( (v2|v1) );
    resultmulti( (v1|(2*v2+1)) );
    resultend();
  }


    {
    cr();
    cr();
    example(Nex++,"Dot product of two complex vectors `(~v1|v2)=(conj(v1)|v2)`");
    cr();
    text("The complex dot product is defined such that the first vector conjugated.  In this manner, the dot product of a complex vector with itself produces a real number.");
    codestart("C++");
    codemulti(using namespace std);
    codemulti(const double tol = 2e-16);
    codemulti(Vector<complex<double> > v1);
    codemulti(v1 = vcomplex(range<double>(1,2), 0.));
    codemulti(v1.roundzero(tol));
    codemulti(Vector<complex<double> > v2);
    codemulti(v2 = vcomplex(range<double>(-1,-2), range<double>(2,3)));
    codemulti(v2.roundzero(tol));
    codeend();
    cr();

   
    resultstart2("");
    resultmulti( v1 );
    resultmulti( v2 );
    resultmulti( (~v1|v1) );
    resultmulti( (~v2|v2) );
    resultmulti( (~v1|v2) );
    resultmulti( (~v2|v1) );
    resultmulti( (~v1|(2*v2+1)) );
    resultend();
  }


  {
    cr();
    cr();
    example(Nex++,"`sum` the elements of a vector");
    codestart("C++");
#if CPP11 == 1
    codemultiwcomment("C++11 list initialization", Vector<double> v({1,2,3,4}));
#else
    codemulti( Vector<double> v( 4, (const double[]) {1, 2, 3, 4} )  );
#endif
    codeend();
    cr();

   
    resultstart2("");
    resultmulti( sum(v) );
    resultmulti( sum(2*exp(v)+1) );
    resultend();
  }


    {
    cr();
    cr();
    example(Nex++,"`sum` the elements of a vector");
    codestart("C++");
#if CPP11 == 1
    codemultiwcomment("C++11 list initialization", Vector<double> v({1,2,3,4}));
#else
    codemulti( Vector<double> v( 4, (const double[]) {1, 2, 3, 4} )  );
#endif
    codeend();
    cr();

   
    resultstart2("");
    resultmulti( sum(v) );
    resultmulti( sum(2*exp(v)+1) );
    resultend();
  }


  {
    cr();
    cr();
    example(Nex++,"`integrate` a vector over the interval [a,b]");
    codestart("C++");
    codemulti( Vector<double> v );
    codemulti( v = exp(linspace<double>(-1,1,13)));
    codeend();
    cr();
   
    resultstart2(" precise value to 16 digits is 2.35040238729 (via Mathematica)");
    resultmulti( integrate(v,-1.,1.) );
    resultmulti( integrate(v,-1.,1.,2) );
    resultmulti( integrate(v,-1.,1.,3) );
    resultmulti( integrate(v,-1.,1.,4) );
    resultend();
  }

  
  {
    cr();
    cr();
    example(Nex++,"Compute the _product_ of the elements of a vector");
    codestart("C++");
#if CPP11 == 1
    codemultiwcomment("C++11 list initialization", Vector<double> v({1,2,3,4}));
#else
    codemulti( Vector<double> v( 4, (const double[]) {1, 2, 3, 4} )  );
#endif
    codeend();
    cr();

   
    resultstart2("");
    resultmulti( prod(v) );
    resultmulti( prod(2*exp(v)+1) );
    resultend();
  }



    {
    cr();
    cr();
    example(Nex++,"Find the _minimum_ of the elements of a vector");
    codestart("C++");
#if CPP11 == 1
    codemultiwcomment("C++11 list initialization", Vector<double> v({1,20,-1,0}));
#else
    codemulti( Vector<double> v( 4, (const double[]) {1,20,-1,0} )  );
#endif
    codeend();
    cr();

   
    resultstart2("");
    resultmulti( v );
    resultmulti( min(v) );
    resultmulti( 2*exp(v)+1 );
    resultmulti( min(2*exp(v)+1) );
    resultend();
  }


      {
    cr();
    cr();
    example(Nex++,"Find the _maximum_ of the elements of a vector");
    codestart("C++");
#if CPP11 == 1
    codemultiwcomment("C++11 list initialization", Vector<double> v({1,20,-1,0}));
#else
    codemulti( Vector<double> v( 4, (const double[]) {1,20,-1,0} )  );
#endif
    codeend();
    cr();

   
    resultstart2("");
    resultmulti( v );
    resultmulti( max(v) );
    resultmulti( 2*exp(v)+1 );
    resultmulti( max(2*exp(v)+1) );
    resultend();
  }

  
  matricks_toc();
  return 0;
}
