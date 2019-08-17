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



int main()
{

  int Nex = 1;
  
  cr();
  mdtitle("Complex-valued Vectors");
  matricks_preamble();

  header3("Declaring and assigning complex-valued `Vector`'s");

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
    example(Nex++,"Complex  `Vector` ");
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


  header3("Arithmetic with complex and real vectors `Vector`'s");

  {
    cr();
    cr();
    example(Nex++,"Complex  `Vector` ");
    codestart("C++");
    codemulti( using namespace std );
    codemulti( Vector<double > vr(4) );
    codemulti( Vector<complex<double> > vc(4) );
#if CPP14 == 1
    codemulti( using namespace literals );
    codemulti( using namespace complex_literals );
    codemultiwcomment("C++11 list ", vr = { 1, 2, 3, 4 } );
    codemultiwcomment("C++11 list and C++14 literal `i` for unit imaginary ", vc = { 1+1i, 1, 1i, -1i } );
#else
#endif
    codeend();
    cr();

   
    resultstart2("");
    resultmulti(vr+vc);
    resultmulti(vr-vc);
    resultmulti(vr*vc);
    resultmulti(vr/vc);
    resultend();
  }


  // std::cout << "real part" << std::endl;
  // v1 = real(v3);
  // std::cout << v1 << std::endl;

  // std::cout << "imag part" << std::endl;
  // v2 = imag(v3);
  // std::cout << v2 << std::endl;

  // std::cout << "maginitude" << std::endl;
  // v1 = abs(v3);
  // std::cout << v1 << std::endl;

  // std::cout << "phase" << std::endl;
  // v2 = arg(v3);
  // std::cout << v2 << std::endl;

  // std::cout << "construct complex vector from magnitude,phase" << std::endl;
  // v3 = vpolar(v1,v2);
  // std::cout << v3 << std::endl;


  // std::cout << "exp(v3)" << std::endl;
  // v3 = exp(v3);
  // std::cout << v3 << std::endl;

  // std::cout << "square each element" << std::endl;
  // v3 = pow(v3,2);
  // std::cout << v3 << std::endl;

  // std::cout << "norm(v3)" << std::endl;
  // double d = norm(v3);
  // std::cout << d << std::endl;


  // "{-1.0,-2.0,-3.0}" >> v1;
  // std::cout << "real(v3)=v1" << std::endl;
  // //real(v3) = v1;
  // std::cout << v1 << std::endl;
  // std::cout << v3 << std::endl;


  matricks_toc();

  return 0;
}
