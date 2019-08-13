
// flag for run-time bounds and size checking
#define MATRICKS_CAREFUL


#include "matricks.hpp"
using namespace Matricks;

#include <iostream>
using namespace std;

  

int main()
{
  const int N = 3;

  // real vectors
  Vector<double> v1(N);
  Vector<double> v2(N);


  std::cout << "initialize v1 (real vector) using range<" << std::endl;
  v1 = range<double>(1,3);
  std::cout << v1 << std::endl;

  std::cout << "initialize v2 (real vector) using range<" << std::endl;
  v2 = range<double>(100,300,100);
  std::cout << v2 << std::endl;

  // complex vectors

  Vector<complex<double> > v3(N);


  std::cout << "initialize each element of v3 (complex vector)" << std::endl;
  v3[0] = complex<double>(1,2);
  v3[1] = complex<double>(3,4);
  v3[2] = complex<double>(5,6);
  std::cout << v3 << std::endl;

  std::cout << "initialize v3 = (v1,0)" << std::endl;
  v3 = vcomplex(v1,0);
  std::cout << v3 << std::endl;

  std::cout << "initialize v3 = (0,v1)" << std::endl;
  v3 = vcomplex(0,v1);
  std::cout << v3 << std::endl;

  std::cout << "initialize v3 = (v1,v2)" << std::endl;
  v3 = vcomplex(v1,v2);
  std::cout << v3 << std::endl;

  std::cout <<std::endl << "add real and complex vectors" << std::endl;
  v3 = v3+v1;
  std::cout <<"v3=v3+v1="<< v3 << std::endl;

  std::cout <<std::endl << "subtraction with real and complex vectors" << std::endl;
  v3 = v3-v1;
  std::cout <<"v3=v3-v1="<< v3 << std::endl;

  std::cout <<std::endl << "multipy real and complex vectors" << std::endl;
  v3 = v3*v1;
  std::cout <<"v3=v3*v1="<< v3 << std::endl;

  std::cout <<std::endl << "division with real and complex vectors" << std::endl;
  v3 = v3/v1;
  std::cout <<"v3=v3/v1="<< v3 << std::endl;

  std::cout<<std::endl << "dot product (v3|v3)" << std::endl;
  complex<double> dc = (v3|v3);
  std::cout <<dc << std::endl;


  std::cout << "conjugate dot product  conj(v3)|v3" << std::endl;
  dc = conj(v3)|v3;
  std::cout <<dc << std::endl;

  std::cout << "dot product (v1|v3)" << std::endl;
  dc = (v1|v3);
  std::cout <<dc << std::endl;

  std::cout << "real part" << std::endl;
  v1 = real(v3);
  std::cout << v1 << std::endl;

  std::cout << "imag part" << std::endl;
  v2 = imag(v3);
  std::cout << v2 << std::endl;

  std::cout << "maginitude" << std::endl;
  v1 = abs(v3);
  std::cout << v1 << std::endl;

  std::cout << "phase" << std::endl;
  v2 = arg(v3);
  std::cout << v2 << std::endl;

  std::cout << "construct complex vector from magnitude,phase" << std::endl;
  v3 = vpolar(v1,v2);
  std::cout << v3 << std::endl;


  std::cout << "exp(v3)" << std::endl;
  v3 = exp(v3);
  std::cout << v3 << std::endl;

  std::cout << "square each element" << std::endl;
  v3 = pow(v3,2);
  std::cout << v3 << std::endl;

  std::cout << "norm(v3)" << std::endl;
  double d = norm(v3);
  std::cout << d << std::endl;


  "{-1.0,-2.0,-3.0}" >> v1;
  std::cout << "real(v3)=v1" << std::endl;
  //real(v3) = v1;
  std::cout << v1 << std::endl;
  std::cout << v3 << std::endl;



  return 0;
}
