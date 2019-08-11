
// flag for run-time bounds and size checking
#define MATRICKS_CAREFUL


#include "matricks.hpp"
using namespace Matricks;

#include <iostream>
#include <iomanip>
using namespace std;





int main()
{
  
  const int N = 4;

  LAvector<double> v1(N,"vec1");
  LAvector<double> v2(N,"vec2");
  LAvector<double> v3(N,"vec3");

  cout << "initialize each element of v1" << endl;
  v1[0] = 1.0;
  v1[1] = -2.5;
  v1[2] = 3.3333;
  v1[3] = -4.0;

  cout << endl;
  cout << "default vector printing" << endl;
  cout << v1 << endl;

  cout << endl;
  cout << "vector printing (width=10 spaces)" << endl;
  v1.width(10);
  cout << v1 << endl;

  cout << endl;
  cout << "vector printing (print 2 values per line)" << endl;
  v1.perline(2);
  cout << v1 << endl;

  v1.perline(4);


  cout << endl;
  cout << "vector printing (precision=2 digits)" << endl;
  cout.setf(ios::showpoint);
  cout.precision(2);
  cout << v1 << endl;


  cout << endl;
  cout << "vector printing (scientific notation)" << endl;
  cout.setf(ios::scientific);
  cout << v1 << endl;

  cout << endl;
  cout << "vector printing (left justified)" << endl;
  cout.setf(ios::left);
  cout << v1 << endl;


  cout << endl;
  cout << "vector printing (show + sign)" << endl;
  cout.setf(ios::showpos);
  cout << v1 << endl;
  cout.unsetf(ios::showpos);


  cout<<endl << "CAN ALSO OUTPUT VECTORS WITHOUT BRACES AND COMMAS"<<endl;
  cout<< "Here is the contents of v1: ";
  v1.textformat(text_nobraces);
  cout <<v1<<endl;
  v1.textformat(text_braces);

  cr();
  cr();
  printcr("Several macros are available for printing any variable or expression");
  printcr("The print macros just give the contents of the given variable or expression");
  printcr("The disp do the same as print, but also display the variable name");

  cout << endl;
  cout << "Printing variables using the \"print\", \"printcr\", and \"printcrcr\" macros" << endl;
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
  

  cout << endl;
  cout << "Printing variables using the \"disp\", \"dispcr\", and \"dispcrcr\" macros" << endl;
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
