#define MATHQ_DEBUG 1


#include "mathq.h"
#include "gitmd.h"

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>



int main()
{
  using namespace mathq;
  using namespace std;
  using namespace display;
  using namespace md;

  int Nex = 1;
  
  mathq_toc();
  cr();cr();
  mdtitle("Complex-valued Vectors");
  mathq_preamble();

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
    // C++14 complex objects are of class "__complex__ double" 
    //    resultmulti( (1.i)*vr + (5.+2.i)*vc);  // C++14
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
    codemulti( vc = complexify(vr, vi) );
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
    example(Nex++,"create a complex vector from a real vector and a scalar");
    codestart("C++");
    codemulti( using namespace std );
    codemulti( Vector<double> v( range<double>(1,4) ));
    codeend();
    cr();

    resultstart2(": create a complex vector from a real vector and a scalar");
    resultmulti( complexify(v, 0.) );
    resultmulti( complexify(v, 1.) );
    resultmulti( complexify(0., v) );
    resultmulti( complexify(1., v) );
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
    codemulti( vc = complexify(vr, vi) );
    codeend();
    cr();

    resultstart2(": compute the complex conjugate of a vector");
    resultmulti( vr  );
    resultmulti( vi  );
    resultmulti( vc  );
    resultmulti( conj(vc)  );
    resultmulti( ~vc  );
    resultend();
    cr();
  }




  
  text("* Functions defined for complex vectors  ");
  
  {
    cr();
    cr();
    example(Nex++,"functions of complex vectors");
    codestart("C++");
    codemulti(const double pi = M_PI);
    codemulti( using namespace std );
    codemulti( Vector<complex<double> > v(3) );
    codemulti( Vector<double> vr( range<double>(1,3) ));
    codemulti( Vector<double> vi( range<double>(-1,1) ));
    codemulti( v = complexify(vr, vi) );
    codeend();
    cr();

    resultstart2(": functions of complex vectors");
    // TODO: need to implement these for complex numbers and then for Tensors
    //  resultmulti( floor(v)  );
    //  resultmulti( ceil(v)  );
    // resultmulti( sgn(v)  );
    resultmulti( v  );
    resultmulti( abs(v)* ( cos(arg(v)) + complexify(0., sin(arg(v))) ) );
    resultmulti( abs(v)  );
    resultmulti( pow(2., v)  );
    resultmulti( pow(v, 2.)  );
    resultmulti( pow(v,v)  );
    resultmulti( exp(v)  );
    resultmulti( round(exp(v))  );
    resultmulti( roundzero(v+1e-16) );
    resultmulti( log(v)  );
    resultmulti( log10(v)  );
    //    resultmulti( log2(v)  );
    resultmulti( sqr(v)  );
    resultmulti( cube(v)  );
    resultmulti( sqrt(v)  );
    resultmulti( sin(v)  );
    resultmulti( cos(v)  );
    resultmulti( tan(v)  );
    resultmulti( sinh(v)  );
    resultmulti( cosh(v)  );
    resultmulti( tanh(v)  );
    resultmulti( asin(v)  );
    resultmulti( acos(v)  );
    resultmulti( atan(v)  );
    resultmulti( atan2(vr, vi)  );
    resultend();
    cr();
    resultstart3("Aritmetic with scalars");
    resultmulti( v + 0.1 );
    resultmulti( 0.1 + v );
    resultmulti( v - 0.1 );
    resultmulti( 0.1 - v );
    resultend();
    cr();

  }




  mathq_toc();

  return 0;
}
