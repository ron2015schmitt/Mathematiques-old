
// flag for run-time bounds and size checking
#define MATRICKS_CAREFUL


#include "matricks.hpp"
using namespace Matricks;

#include <iostream>
using namespace std;





int main()
{
  const int N = 4;

  Vector<double> v1(N);
  Vector<double> v2(N);

  std::cout << "initialize v1" << std::endl;
  v1 = range<double>(1,4) * 3.14159265/4.0;
  std::cout << v1 << std::endl;

  std::cout << "sin" << std::endl;
  v2 = sin(v1);
  std::cout << v2 << std::endl;

  std::cout << "log" << std::endl;
  v2 = log(v1);
  std::cout << v2 << std::endl;

  std::cout << "sign, sgn(v2)" << std::endl;
  v2[0] = -2.5;
  v2[1] = 100;
  v2[2] = 0;
  v2[3] = 23;
  std::cout << v2 << std::endl;
  v2 = sgn(v2);
  std::cout << v2 << std::endl;

  std::cout << "v1^3.0" << std::endl;
  v2 = pow(v1,3.0);
  std::cout << v2 << std::endl;

  std::cout << "round(v2)" << std::endl;
  v2 = round(v2);
  std::cout << v2 << std::endl;

  std::cout << "complicated example#2" << std::endl;
  v2 = v1*(sin(2.0*v1)  +  cos(2.0*v1))/2.0;
  std::cout << v2 << std::endl;


  // functions supported: sin, cos, tan, sinh, cosh, tanh, exp, log, abs, log10
  // pow(a,b), round, ceil, floor, asin, acos, atan, atan2, sqrt


  return 0;
}
