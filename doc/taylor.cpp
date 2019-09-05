#define MATRICKS_DEBUG 2


#include "matricks.h"
#include "TypeTraits.h"
#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif





int main()
{
 
  using namespace matricks;
  using namespace std;
  using namespace display;
  using namespace md;


  Vector<double> Bessel0Coeffs =  Vector<double>({1.,0.,-0.25,0.,0.015625,0.,-0.000434028,0.,6.78168e-6,0.,-6.78168e-8,0.,4.7095e-10,0.,-2.40281e-12,0.,9.38597e-15,0.,-2.8969e-17,0.,7.24226e-20,0.,-1.49633e-22,0.,2.5978e-25,0.});

  Vector<double> r = linspace<double>(0,10,101);

  Vector<double> y = taylor(Bessel0Coeffs, r, 25);

  disp(y);


  return 0;
}
