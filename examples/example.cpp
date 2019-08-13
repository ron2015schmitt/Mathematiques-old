#include <iostream>
#include <string>

#include "matricks.hpp"


int main()
{

  using namespace Matricks;
  Vector<double> v1(2, 3.14);

  std::cout << std::endl << v1 << std::endl;
  
  return 0;
}
