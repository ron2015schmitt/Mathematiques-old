
#include "mathq.h"


int main(int argc, char *argv[])
{
  const double pi = M_PI;
  std::string myname = argv[0];
  
  using namespace mathq;
  using namespace display;

  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  cr();
  cr();
  mout << StyledString::get(HORLINE);
  mout << "running: " <<createStyle(BOLD).apply(myname) << std::endl;

  
  mout<< "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;
  print_mathq_info();
  
  Vector<double> v1( linspace<double>(-1,1,21) );
  Vector<double> v2;
  v2 = 10*sin(pi/2*v1) + 10;

  disp(v1);
  disp(v2);
  disp(v1+v2);

  // dot product
  disp(v1|v2);

  const double N = double(v2.size());
  // mean
  double mu2 = sum(v2)/N;
  disp(mu2);

  // std deviation
  double sigma2 = norm(v2-mu2)/sqrt(N-1);
  disp(sigma2);

  cr();
  mout << "done: " << createStyle(BOLD).apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();

  
  return 0;
}
