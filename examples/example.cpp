#include <tgmath.h>

#include "matricks.h"


int main()
{
  const double pi = M_PI;
  
  using namespace matricks;
  using namespace display;
  print_matricks_info();
  
  Vector<double> v1( linspace<double>(-1,1,21) );
  Vector<double> v2;
  v2 = 10*sin(pi/2*v1) + 10;

  dispcr(v1);
  dispcr(v2);
  dispcr(v1+v2);

  // dot product
  dispcr(v1|v2);

  const double N = double(v2.size());
  // mean
  double mu2 = sum(v2)/N;
  dispcr(mu2);

  // std deviation
  double sigma2 = norm(v2-mu2)/sqrt(N-1);
  dispcr(sigma2);
  
  return 0;
}
