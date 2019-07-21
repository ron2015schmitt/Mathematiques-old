
// flag for run-time bounds and size checking
#define COOLL_CAREFUL


#include "cooll.hpp"
using namespace COOLL;

#include <iostream>
using namespace std;

  

int main()
{
  const int N = 3;

  // real vectors
  LAvector<double> v1(N);
  LAvector<double> v2(N);


  cout << "initialize v1 (real vector) using range<" << endl;
  v1 = range<double>(1,3);
  cout << v1 << endl;

  cout << "initialize v2 (real vector) using range<" << endl;
  v2 = range<double>(100,300,100);
  cout << v2 << endl;

  // complex vectors

  LAvector<complex<double> > v3(N);


  cout << "initialize each element of v3 (complex vector)" << endl;
  v3[0] = complex<double>(1,2);
  v3[1] = complex<double>(3,4);
  v3[2] = complex<double>(5,6);
  cout << v3 << endl;

  cout << "initialize v3 = (v1,0)" << endl;
  v3 = vcomplex(v1,0);
  cout << v3 << endl;

  cout << "initialize v3 = (0,v1)" << endl;
  v3 = vcomplex(0,v1);
  cout << v3 << endl;

  cout << "initialize v3 = (v1,v2)" << endl;
  v3 = vcomplex(v1,v2);
  cout << v3 << endl;

  cout <<endl << "add real and complex vectors" << endl;
  v3 = v3+v1;
  cout <<"v3=v3+v1="<< v3 << endl;

  cout <<endl << "subtraction with real and complex vectors" << endl;
  v3 = v3-v1;
  cout <<"v3=v3-v1="<< v3 << endl;

  cout <<endl << "multipy real and complex vectors" << endl;
  v3 = v3*v1;
  cout <<"v3=v3*v1="<< v3 << endl;

  cout <<endl << "division with real and complex vectors" << endl;
  v3 = v3/v1;
  cout <<"v3=v3/v1="<< v3 << endl;

  cout<<endl << "dot product (v3|v3)" << endl;
  complex<double> dc = (v3|v3);
  cout <<dc << endl;


  cout << "conjugate dot product  conj(v3)|v3" << endl;
  dc = conj(v3)|v3;
  cout <<dc << endl;

  cout << "dot product (v1|v3)" << endl;
  dc = (v1|v3);
  cout <<dc << endl;

  cout << "real part" << endl;
  v1 = real(v3);
  cout << v1 << endl;

  cout << "imag part" << endl;
  v2 = imag(v3);
  cout << v2 << endl;

  cout << "maginitude" << endl;
  v1 = abs(v3);
  cout << v1 << endl;

  cout << "phase" << endl;
  v2 = arg(v3);
  cout << v2 << endl;

  cout << "construct complex vector from magnitude,phase" << endl;
  v3 = vpolar(v1,v2);
  cout << v3 << endl;


  cout << "exp(v3)" << endl;
  v3 = exp(v3);
  cout << v3 << endl;

  cout << "square each element" << endl;
  v3 = pow(v3,2);
  cout << v3 << endl;

  cout << "norm(v3)" << endl;
  double d = norm(v3);
  cout << d << endl;


  "{-1.0,-2.0,-3.0}" >> v1;
  cout << "real(v3)=v1" << endl;
  //real(v3) = v1;
  cout << v1 << endl;
  cout << v3 << endl;



  return 0;
}
