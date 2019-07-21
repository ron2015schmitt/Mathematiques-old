
#include <iostream>

#define COOLL_CAREFUL

#include "cooll.hpp"

using namespace COOLL;

using namespace std;

int main()
{



  const int R = 3;
  const int C = 2;

 

 
  Matrix<double> M1(R,C,"M1");
  Matrix<double> M2(R,C,"M2");
  Matrix<double> M3(R,C,"M3");


  


 
  
  M1(5) = 1.1;

  double r= M1(5);
  
  M1(2,0) = 2.1;

  r= M1(2,0);

  M1(0,1) = 2.1;

  r= M1(0,1);

  

  return 0;
}
