
// flag for run-time bounds and size checking
#define MATRICKS_CAREFUL


#include "matricks.hpp"
using namespace Matricks;

#include <iostream>
using namespace std;





int main()
{
  const int N = 4;

  LAvector<double> v1(N);
  LAvector<double> v2(N);

  cout << "initialize v1" << endl;
  v1 = range<double>(1,4) * 3.14159265/4.0;
  cout << v1 << endl;

  cout << "sin" << endl;
  v2 = sin(v1);
  cout << v2 << endl;

  cout << "log" << endl;
  v2 = log(v1);
  cout << v2 << endl;

  cout << "sign, sgn(v2)" << endl;
  v2[0] = -2.5;
  v2[1] = 100;
  v2[2] = 0;
  v2[3] = 23;
  cout << v2 << endl;
  v2 = sgn(v2);
  cout << v2 << endl;

  cout << "v1^3.0" << endl;
  v2 = pow(v1,3.0);
  cout << v2 << endl;

  cout << "round(v2)" << endl;
  v2 = round(v2);
  cout << v2 << endl;

  cout << "complicated example#2" << endl;
  v2 = v1*(sin(2.0*v1)  +  cos(2.0*v1))/2.0;
  cout << v2 << endl;


  // functions supported: sin, cos, tan, sinh, cosh, tanh, exp, log, abs, log10
  // pow(a,b), round, ceil, floor, asin, acos, atan, atan2, sqrt


  return 0;
}
