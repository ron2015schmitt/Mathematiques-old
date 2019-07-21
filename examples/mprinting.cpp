
// flag for run-time bounds and size checking
#define COOLL_CAREFUL


#include "cooll.hpp"
using namespace COOLL;

#include <iostream>
#include <iomanip>
using namespace std;





int main()
{
  
  Matrix<double> A1(2,3,"A1");

  cout << "initialize each element of A1" << endl;
  A1(0,0) = 1.1;
  A1(0,1) = 1.2;
  A1(0,2) = 1.3;
  A1(1,0) = 2.1;
  A1(1,1) = 2.2;
  A1(1,2) = 2.3;

  cout << endl;
  cout << "default matrix printing (braces, width=0)" << endl;
  dispcrcr(A1);

  cout << endl;
  cout << "matrix printing: no braces, width=0" << endl;
  A1.textformat(text_nobraces);
  dispcrcr(A1);


  cout << endl;
  cout << "matrix printing: braces, width=10 spaces" << endl;
  A1.textformat(text_braces);
  A1.width(10);
  dispcrcr(A1);

  cout << endl;
  cout << "matrix printing: no braces, width=5 spaces, precision=3 digits" << endl;
  A1.textformat(text_nobraces);
  A1.width(5);
  cout.setf(ios::showpoint);
  cout.precision(3);
  dispcrcr(A1);


  return 0;
}
