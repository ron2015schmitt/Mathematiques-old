
// flag for run-time bounds and size checking
#define MATRICKS_DEBUG 1


#include "matricks.h"
using namespace matricks;

#include <iostream>
#include <iomanip>
using namespace std;





int main()
{
  
  const int N = 4;

  Vector<double> v1(N,"vec1");
  Vector<double> v2(N,"vec2");
  Vector<double> v3(N,"vec3");

  std::cout << "initialize each element of v1" << std::endl;
  v1[0] = 1.0;
  v1[1] = -2.5;
  v1[2] = 3.3333;
  v1[3] = -4.0;

  std::cout << std::endl;
  std::cout << "default vector printing" << std::endl;
  std::cout << v1 << std::endl;

  std::cout << std::endl;
  std::cout << "vector printing (width=10 spaces)" << std::endl;
  v1.width(10);
  std::cout << v1 << std::endl;

  std::cout << std::endl;
  std::cout << "vector printing (print 2 values per line)" << std::endl;
  v1.perline(2);
  std::cout << v1 << std::endl;

  v1.perline(4);


  std::cout << std::endl;
  std::cout << "vector printing (precision=2 digits)" << std::endl;
  std::cout.setf(ios::showpoint);
  std::cout.precision(2);
  std::cout << v1 << std::endl;


  std::cout << std::endl;
  std::cout << "vector printing (scientific notation)" << std::endl;
  std::cout.setf(ios::scientific);
  std::cout << v1 << std::endl;

  std::cout << std::endl;
  std::cout << "vector printing (left justified)" << std::endl;
  std::cout.setf(ios::left);
  std::cout << v1 << std::endl;


  std::cout << std::endl;
  std::cout << "vector printing (show + sign)" << std::endl;
  std::cout.setf(ios::showpos);
  std::cout << v1 << std::endl;
  std::cout.unsetf(ios::showpos);


  std::cout<<std::endl << "CAN ALSO OUTPUT VECTORS WITHOUT BRACES AND COMMAS"<<std::endl;
  std::cout<< "Here is the contents of v1: ";
  v1.textformat(text_nobraces);
  std::cout <<v1<<std::endl;
  v1.textformat(text_braces);

  cr();
  cr();
  printcr("Several macros are available for printing any variable or expression");
  printcr("The print macros just give the contents of the given variable or expression");
  printcr("The disp do the same as print, but also display the variable name");

  std::cout << std::endl;
  std::cout << "Printing variables using the \"print\", \"printcr\", and \"printcrcr\" macros" << std::endl;
  print(N);
  print(" ");
  printcr(4*N);
  string s = "hello";
  printcr(s);
  printcr(v1);
  printcr(2.0*v1+1.0);
  double d1 = 3.1415;
  printcr(d1);
  cr();
  printcrcr(v1);
  double a1[] = {1.0,2.0};
  printcr(a1);
  

  std::cout << std::endl;
  std::cout << "Printing variables using the \"disp\", \"dispcr\", and \"dispcrcr\" macros" << std::endl;
  disp(N);
  dispcr(4*N);
  dispcr(s);
  dispcr(v1);
  dispcr(2.0*v1+1.0);
  dispcr(d1);
  dispcrcr(v1);
  dispcr(a1);





  return 0;
}
