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
  mdtitle("Complex-valued Vectors");
  matricks_preamble();

  header3("Representing the unit imaginary _i_");

  text("* In C++, there is no definition for pure imaginary numbers.");
  text("* This is in contrast to Fortran.");
  text("* The unit imaginary is thus `complex<D>(0,1`");

  {
    cr();
    cr();
    example(Nex++,"The unit imaginary _i_ in C++14");
    cr();
    text("* In C++14, the unit imaginary is defined by the product operator `operator\"\"i`");
#if CPP14 == 1
    codestart("C++");
    codemulti( using namespace std );
    codemulti( using namespace literals );
    codemulti( using namespace complex_literals );
    codemulti(complex<double> z1 = 1i );
    codemulti(complex<double> z2 = 1+1i );
    codemulti(complex<double> z3 = -5i );
    codemulti(complex<double> z4 = 5 );
    codeend();
    resultstart2("");
    resultmulti(z1);
    resultmulti(z2);
    resultmulti(~z2);
    resultmulti(z3);
    resultmulti(z4);
    resultend();
  }
#endif
    
  {
    cr();
    cr();
    example(Nex++,"The unit imaginary _i_ (works in any version)");
    cr(); 
    text("In earlier versions of C++, the unit imaginary can be defined by");
    codestart("C++");
    codemulti( using namespace std );
    codemulti( const complex<double> i = complex<double>(0,1) );
    codemulti(complex<double> z1 = 1.*i );
    codemulti(complex<double> z2 = 1. + 1.*i );
    codemulti(complex<double> z3 = -5.*i );
    codemulti(complex<double> z4 = 5 );
    codeend();
    cr();
    resultstart2("");
    resultmulti(z1);
    resultmulti(z2);
    resultmulti(z3);
    resultmulti(z4);
    resultend();

  }



  header3("Declaring a complex-valued `Vector`");

  {
    cr();
    cr();
    example(Nex++,"Complex  `Vector` ");
    codestart("C++");
    codemulti( using namespace std );
    codemulti( Vector<complex<double> > v(4) );
#if CPP14 == 1
    codemulti( using namespace literals );
    codemulti( using namespace complex_literals );
    codemultiwcomment("C++11 list and C++14 literal `i` for unit imaginary ", v = { 1+1i, 1, 1i, 1-1i } );
#else
#endif
    codeend();
    cr();

   
    resultstart2("");
    resultmulti(v);
    resultend();
  }



  header3("Arithmetic with complex-valued `Vector`'s");

  {
    cr();
    cr();
    example(Nex++,"Complex `Vector` arithmetic");
    codestart("C++");
    codemulti( using namespace std );
    codemulti( Vector<complex<double> > v1(4) );
    codemulti( Vector<complex<double> > v2(4) );
#if CPP14 == 1
    codemulti( using namespace literals );
    codemulti( using namespace complex_literals );
    codemultiwcomment("C++11 list and C++14 literal `i` for unit imaginary ", v1 = { -1i, 0, 1-1i, 1+1i } );
    codemultiwcomment("C++11 list and C++14 literal `i` for unit imaginary ", v2 = { 1+1i, 1, 1i, -1i } );
#else
#endif
    codeend();
    cr();

   
    resultstart2("");
    resultmulti(v1+v2);
    resultmulti(v1-v2);
    resultmulti(v1*v2);
    resultmulti(v1/v2);
    resultend();
  }


  header3("Mixed arithmetic with complex and real vectors and scalars `Vector`'s");

  {
    cr();
    cr();
    example(Nex++,"Mixed real and complex arithmetic ");
    codestart("C++");
    codemulti( using namespace std );
    codemulti( Vector<double > vr(4) );
    codemulti( Vector<complex<double> > vc(4) );
#if CPP14 == 1
    codemulti( using namespace literals );
    codemulti( using namespace complex_literals );
    codemultiwcomment("C++11 list ", vr = { 1, 2, 3, 4 } );
    codemultiwcomment("C++11 list and C++14 literal `i` for unit imaginary ", vc = { 1+1i, 1, 1i, -1i } );
#endif
    codeend();
    cr();

   
    resultstart2("");
    resultmulti(vr+vc);
    resultmulti(vr-vc);
    resultmulti(vr*vc);
    resultmulti(vr/vc);
    resultmulti(2.*vr + vc/2. + 1);
    //    resultmulti( (1.i)*vr + (5.+2.i)*vc);
    resultmulti( complex<double>(0,1)*vr + complex<double>(5,2)*vc);
    resultend();
  }


  header3("real and imag parts of `Vector`'s");


  {
    cr();
    cr();
    example(Nex++,"get the real and imaginary part of a complex vector");
    codestart("C++");
    codemulti( using namespace std );
    codemulti( Vector<complex<double> > v(4) );
#if CPP14 == 1
    codemultiwcomment("C++11 list and C++14 imag", v = {1+1.i, 1., 1.i, 2-5.i});
#else
    codemulti( v = (const complex<double>[]) {complex<double>(1,1), complex<double>(1,0), complex<double>(0,1), complex<double>(2,-5)} );
#endif
    codeend();
    cr();

    resultstart2(": real and imaginary parts");
    resultmulti( v  );
    resultmulti( real(v)  );
    resultmulti( imag(v)  );
    resultend();
    cr();
  }


  header3("creating complex Vectors from real vectors and scalars");

  {
    cr();
    cr();
    example(Nex++,"create a complex vector from two real vectors");
    codestart("C++");
    codemulti( using namespace std );
    codemulti( Vector<complex<double> > vc(4) );
    codemulti( Vector<double> vr( range<double>(1,4) ));
    codemulti( Vector<double> vi( range<double>(-1,-4) ));
    codemulti( vc = vcomplex(vr, vi) );
    codeend();
    cr();

    resultstart2(": create a complex vector from two real vectors");
    resultmulti( vr  );
    resultmulti( vi  );
    resultmulti( vc  );
    resultmulti( real(vc)  );
    resultmulti( imag(vc)  );
    resultend();
    cr();
  }

  {
    cr();
    cr();
    example(Nex++,"create a complex vector from a real vector");
    codestart("C++");
    codemulti( using namespace std );
    codemulti( Vector<double> v( range<double>(1,4) ));
    codeend();
    cr();

    resultstart2(": create a complex vector from a real vector");
    resultmulti( vcomplex(v,0.) );
    resultmulti( vcomplex(0.,v)  );
    resultmulti( vcomplex(v,v) );
    resultmulti( vcomplex(v,1.) );
    resultend();
    cr();
  }


  header3("Complex Conjugation");

  text("Complex cojugation can be performed via the function `conj` or via the operator `~`");
  {
    cr();
    cr();
    example(Nex++,"compute the complex conjugate of a vector");
    codestart("C++");
    codemulti( using namespace std );
    codemulti( Vector<complex<double> > vc(3) );
    codemulti( Vector<double> vr( range<double>(1,3) ));
    codemulti( Vector<double> vi( range<double>(-1,1) ));
    codemulti( vc = vcomplex(vr, vi) );
    codeend();
    cr();

    resultstart2(": create a complex vector from two real vectors");
    resultmulti( vr  );
    resultmulti( vi  );
    resultmulti( vc  );
    resultmulti( conj(vc)  );
    resultmulti( ~vc  );
    resultend();
    cr();
  }



  
  //   text("* A function of a `Vector` operates on each element.  ");
  
  //   {
  //     cr();
  //     cr();
  //     example(Nex++,"functions of a `Vector`—rounding and sign-related ");
  //     codestart("C++");
  //     codemulti( Vector<double> v(7) );
  // #if CPP11 == 1
  //     codemultiwcomment("C++11 list", v = {-2.5,-2.25,-1,0,1,2.25,2.5});
  // #else
  //     codemulti( v = (const double[]) {-2.5,-2.25,-1,0,1,2.25,2.5} );
  // #endif
  //     codeend();
  //     cr();

  //     resultstart2(": rounding and sign-related");
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
  // #if CPP11 == 1
  //     codemultiwcomment("C++11 list", v = {-1,0,1,2,4});
  // #else
  //     codemulti( v = (const double[]) {-1,0,1,2,4} );
  // #endif
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
  //     codemultiwcomment("C++11 list", v = {-pi, -pi/2, 0, pi/2, pi});
  // #else
  //     codemulti( double pi = std::acos(-1) );
  //     codemulti( v = (const double[]) {-pi, -pi, 0, pi, pi} );
  // #endif
  //     codeend();
  //     cr();

  //     resultstart2(": trig");
  //     resultmulti( sin(v)  );
  //     resultmulti( cos(v)  );
  //     resultmulti( tan(v)  );
  //     resultend();
  //     cr();
  //   }

  
  //   {
  //     cr();
  //     cr();
  //     example(Nex++,"functions of a `Vector`—rounding and sign-related ");
  //     codestart("C++");
  //     codemulti( Vector<double> v(3) );
  // #if CPP11 == 1
  //     codemultiwcomment("C++11 list", v = {-1,0,1});
  // #else
  //     codemulti( v = (const double[]) {-1,0,1} );
  // #endif
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
  // #if CPP11 == 1
  //     codemultiwcomment("C++11 list", v = {-1,0,1});
  //     codemultiwcomment("C++11 list", v1 = {-1,-1,-1, 0, 0, 0, 1, 1, 1});
  //     codemultiwcomment("C++11 list", v2 = {-1, 0, 1,-1, 0, 1,-1, 0, 1});
  // #else
  //     codemulti( v = (const double[]) {-1,0,1} );
  //     codemulti( v1 = (const double[]) {-1,-1,-1, 0, 0, 0, 1, 1, 1});
  //     codemulti( v2 = (const double[]) {-1, 0, 1,-1, 0, 1,-1, 0, 1});
  // #endif
  //     codeend();
  //     cr();

  //     resultstart2(": inverse trig");
  //     resultmulti( asin(v)  );
  //     resultmulti( acos(v)  );
  //     resultmulti( atan(v)  );
  //     resultmulti( atan2(v1, v2)  );
  //     resultend();
  //   }


  matricks_toc();

  return 0;
}
