#define MATRICKS_DEBUG


#include "matricks.hpp"
using namespace Matricks;

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif

  int increment (int x) {return ++x;}


int main()
{

  int Nex = 1;
  
  cr();
  mdtitle("In-place Vector math");
  matricks_preamble();

  header3("In-place Vector math");
  text("Since ");

  
  Vector<int> v1({1,2,3,4});
  Vector<int> v2;
  v2 = v1.getValArray().apply(increment);
  dispcr(v1);
  dispcr(v2);
  
//   {
//     cr();
//     cr();
//     example(Nex++,"functions of a `Vector`—rounding and sign-related ");
//     codestart("C++");
//     codemulti( Vector<double> v(7) );
//     codemultiNoteC11Array(v = CARRAY({-2.5,-2.25,-1,0,1,2.25,2.5}));
//     codeend();
//     cr();

//     resultstart2(": in-place rounding and sign-related");
//     resultmulti( floor(v)  );
//     resultmulti( ceil(v)  );
//     resultmulti( round(v)  );
//     resultmulti( sgn(v)  );
//     resultmulti( abs(v)  );
//     resultend();
//     cr();
//   }
    
//   {
//     cr();
//     cr();
//     example(Nex++,"functions of a `Vector`—powers, roots, and exponentiation");
//     codestart("C++");
//     codemulti( Vector<double> v(5) );
//     codemultiNoteC11Array(v = CARRAY({-1,0,1,2,4}));
//     codeend();
//     cr();
//     resultstart2(": powers, roots, and exponentiation");
//     resultmulti( pow(2., v)  );
//     resultmulti( pow(v, 2.)  );
//     resultmulti( pow(v,v)  );
//     resultmulti( exp(v)  );
//     resultmulti( log(v)  );
//     resultmulti( log10(v)  );
//     resultmulti( log2(v)  );
//     resultmulti( sqr(v)  );
//     resultmulti( cube(v)  );
//     resultmulti( sqrt(v)  );
//     resultend();
//     cr();
//   }


//   {
//     cr();
//     cr();

//     example(Nex++,"functions of a `Vector`—trig");
//     codestart("C++");
//     codemulti( Vector<double> v(5) );
// #if CPP11 == 1
//     codemultiwcomment("C++11 constexpr",constexpr double pi = std::acos(-1) );
// #else
//     codemulti( double pi = std::acos(-1) );
// #endif
//     codemultiNoteC11Array(v = CARRAY({-pi, -pi/2, 0, pi/2, pi}));
//     codemulti( const double tol = 2e-16 );
//     codeend();
//     cr();

//     resultstart2(": trig");
//     resultmulti( sin(v)  );
//     resultmulti( cos(v)  );
//     resultmulti( tan(v)  );
//     resultend();
//     cr();
//     text("The results are cleaner, when we round to a tolerance");
//     cr();
//     resultstart2(": trig with rounded zeros");
//     resultmulti( roundzeros(sin(v),tol)  );
//     resultmulti( roundzeros(cos(v),tol)  );
//     resultmulti( roundzeros(tan(v),tol)  );
//     resultend();
    
//   }

  
//   {
//     cr();
//     cr();
//     example(Nex++,"functions of a `Vector`—rounding and sign-related ");
//     codestart("C++");
//     codemulti( Vector<double> v(3) );
//     codemultiNoteC11Array(v = CARRAY({-1,0,1}));
//     codeend();
//     cr();

//     resultstart2(": hyperbolic trig");
//     resultmulti( sinh(v)  );
//     resultmulti( cosh(v)  );
//     resultmulti( tanh(v)  );
//     resultend();
//     cr();
//   }


//   {
//     cr();
//     cr();
//     example(Nex++,"functions of a `Vector`—inverse trig");
//     codestart("C++");
//     codemulti( Vector<double> v(3) );
//     codemulti( Vector<double> v1(9) );
//     codemulti( Vector<double> v2(9) );
//     codemultiNoteC11Array(v = CARRAY({-1,0,1}));
//     codemultiNoteC11Array(v1 = CARRAY({-1,-1,-1, 0, 0, 0, 1, 1, 1}));
//     codemultiNoteC11Array(v2 = CARRAY({-1, 0, 1,-1, 0, 1,-1, 0, 1}));
//     codeend();
//     cr();

//     resultstart2(": inverse trig");
//     resultmulti( asin(v)  );
//     resultmulti( acos(v)  );
//     resultmulti( atan(v)  );
//     resultmulti( atan2(v1, v2)  );
//     resultend();
//   }



//   header3("Arbitrary combinations of the above functionality are supported");
//   text("* Because mātricks uses expression templating:");
//   text("  * no intermediate objects are created");
//   text("  * the expression is calculated in a single for loop");


//     {
//     cr();
//     cr();
//     example(Nex++,"A huge expression");
//     codestart("C++");
//     codemulti( Vector<double> v1(4) );
//     codemultiNoteC11Array(v1 = CARRAY({10,20,30,40}));
//     codemulti( Vector<double> v2(4) );
//     codemultiNoteC11Array(v2 = CARRAY({-1,-2,-3,-4}));
//     codeend();
//     cr();

   
//     resultstart2("");
//     resultmulti(2*log10(abs(v1/v2)*100) + 3 + pow(-v2,2.) );
//     resultend();
//   }

  matricks_toc();


  return 0;
}
