
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
  LAvector<double> v1(N);
  LAvector<double> v2(N);


  cout << "initialize v1 using range<" << endl;
  v1 = range<double>(1,3);
  cout << v1 << endl;

  cout << "initialize v2 using range<" << endl;
  v2 = range<double>(100,300,100);
  cout << v2 << endl;

  // complex vectors

  LAvector<complex<double> > v3(N);


  cout << "initialize each element of v3" << endl;
  v3[0] = complex<double>(1.0,2.0);
  v3[1] = complex<double>(3.0,4.0);
  v3[2] = complex<double>(5.0,6.0);
  cout << v3 << endl;





  cout << "initialize v3 = (v1,0)" << endl;
  v3 = vcomplex(v1,0);
  cout << v3 << endl;

  cout << "initialize v3 = (0,v1)" << endl;
  v3 = vcomplex(0.0,v1);
  cout << v3 << endl;



  Matrix<double> M1(2,2);
  M1(0,0) = 1.0;
  M1(0,1) = 2.0;
  M1(1,0) = 3.0;
  M1(1,1) = 4.0;
  Matrix<double> M2(2,2);
  Matrix<complex<double> > M3(2,2);
  cout << "initialize M3 = (M1,0)" << endl;
  M3 = mcomplex(M1,0.0);
  cout << M3 << endl;

  cout << "initialize M3 = (0,M1)" << endl;
  M3 = mcomplex(0.0,M1);
  cout << M3 << endl;



  cout << "initialize v3 = (v1,v2)" << endl;
  v3 = vcomplex(v1,v2);
  cout << v3 << endl;

  cout << "dot product" << endl;
  complex<double> dc = v3|v3;
  cout <<dc << endl;


  cout << "conjgate dot product" << endl;
  dc = conj(v3)|v3;
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
  v3 = pow(v3,2.0);
  cout << v3 << endl;

  cout << "norm(v3)" << endl;
  double d = norm(v3);
  cout << d << endl;


  return 0;
}
