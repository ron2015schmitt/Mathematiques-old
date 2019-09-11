#include "matricks.h"

#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif



int main()
{
  using namespace matricks;
  using namespace display;

  int n = 45;
  double x = 3.14;
  double vals[] = {1.1,2.2,3.3};
  char str[] = "hello";
  std::string s = "world";
  std::complex<double> z(1,-1);

  disp(n);
  disp(x);
  disp(vals);
  disp(str);
  disp(s);
  disp(z);

  return 0;
}
