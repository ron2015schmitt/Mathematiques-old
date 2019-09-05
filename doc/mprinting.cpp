
// flag for run-time bounds and size checking
#define MATRICKS_DEBUG 1


#include "matricks.h"
using namespace matricks;

#include <iostream>
#include <iomanip>
using namespace std;





int main()
{
  
  Matrix<double> A1(2,3,"A1");

  std::cout << "initialize each element of A1" << std::endl;
  A1(0,0) = 1.1;
  A1(0,1) = 1.2;
  A1(0,2) = 1.3;
  A1(1,0) = 2.1;
  A1(1,1) = 2.2;
  A1(1,2) = 2.3;

  std::cout << std::endl;
  std::cout << "default matrix printing (braces, width=0)" << std::endl;
  dispcr(A1);

  std::cout << std::endl;
  std::cout << "matrix printing: no braces, width=0" << std::endl;
  A1.textformat(text_nobraces);
  dispcr(A1);


  std::cout << std::endl;
  std::cout << "matrix printing: braces, width=10 spaces" << std::endl;
  A1.textformat(text_braces);
  A1.width(10);
  dispcr(A1);

  std::cout << std::endl;
  std::cout << "matrix printing: no braces, width=5 spaces, precision=3 digits" << std::endl;
  A1.textformat(text_nobraces);
  A1.width(5);
  std::cout.setf(ios::showpoint);
  std::cout.precision(3);
  dispcr(A1);


  return 0;
}
