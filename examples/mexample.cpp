
// flag for run-time bounds and size checking
#define MATRICKS_CAREFUL


#include "matricks.hpp"
using namespace Matricks;

#include <iostream>
using namespace std;





int main()
{
  const int NR = 2;
  const int NC = 2;

  Matrix<double> A1(NR,NC,"A1");

  cout << endl<< "initialize each element of A1" << endl;
  A1(0,0) = 1.0;
  A1(0,1) = 2.0;
  A1(1,0) = 3.0;
  A1(1,1) = 4.0;
  cout << A1<< endl;
  

  cout << endl<< "initialize A2 to a constant" << endl;
  Matrix<double> A2(NR,NC,"A2");
  A2=100.0;
  cout << A2<< endl;

  cout << endl<< "add two matrices" << endl;
  A2=A1+A2;
  cout << A2<< endl;


  Matrix<double> A3(NR,NC,"A3");

  cout << endl<< "subtractionion of matrices" << endl;
  A3 = A2 - A1;
  cout << A3 << endl;

  cout << endl<< "elementwise multiplication of matrices" << endl;
  A3 = A1 * A2;
  cout << A3 << endl;

  cout << endl<< "elementwise division of matrices" << endl;
  A3 =  A2/A1;
  cout << A3 << endl;

  cout << endl<< "matrix + scalar" << endl;
  A3 = A1  + 1;
  cout << A3 << endl;

  cout << endl<< "complicated example#1" << endl;
  A3 = 3*(A1+A2)  +  1000.0;
  cout << A3 << endl;

  cout << endl<< "transpose A3=~A1" << endl;
  A3 = ~A1;
  cout << A3<< endl;


  const int NR2 = 2;
  const int NC2 = 3;
  Matrix<double> A4(NR2,NC2,"A4");
  cout << endl<< "initialize each element of A4" << endl;
  A4(0,0) = 5.0;
  A4(0,1) = 6.0;
  A4(0,2) = 7.0;
  A4(1,0) = 8.0;
  A4(1,1) = 9.0;
  A4(1,2) = 10.0;
  cout << A4<< endl;

  cout << endl<< "dot product A5=(A1|A4)" << endl;
  Matrix<double> A5(NR,NC2,"A5");
  A5 = (A1|A4);
  cout << A5<< endl;

  cout << endl<< "transpose A6=~A5" << endl;
  Matrix<double> A6(NC2,NR,"A6");
  A6 = ~A5;
  cout << A6<< endl;

  cout << endl<< "dot product A6=(A6|A4|A6)" << endl;
  A6=(A6|A4|A6);
  cout << A6 << endl;


  double d;
  cout << endl<< "maximum(A1+A2)" << endl;
  d = max(A1+A2);
  cout <<d << endl;

  cout << endl<< "minimum(2*A1)" << endl;
  d = min(2.0*A1);
  cout <<d << endl;


  cout << endl<< "sum(A1)" << endl;
  d = sum(A1);
  cout <<d << endl;

  cout << endl<< "trace(A5)" << endl;
  d = tr(A5);
  cout <<d << endl;


  Matrix<double> B1(1,4,"B1");
  cout << endl<< "example of a single row matrix" << endl;
  B1(0) = 1;
  B1(1) = 2;
  B1(2) = 3;
  B1(3) = 4;
  cout <<"B1="<<endl<< B1<< endl;

  Matrix<double> B2(4,1,"B2");
  cout << endl<< "example of a single column matrix" << endl;
  B2=3*~B1;
  cout <<"B2="<<endl<< B2<< endl;

  cout << endl<< "dot product of single row and column matrices" << endl;
  Matrix<double> B3(1,1,"B3");
  B3 = (B1|B2);
  cout <<"B3=(B1|B2)="<<B3<<endl;

  
  cout<<endl << "resize to zero to release the memory: A1.resize(0,0)" << endl;
  cout << "this can be used for efficient memory management when working with large matrices" << endl;
  A1.resize(0,0);
  cout <<"A1 = "<<endl<< A1<< endl;

  cout<<endl << "resize and set A1 from an expression" << endl;
  A1.resize() = 2*A2;
  cout <<"A1.resize() = A*A2 = "<<endl<< A1<< endl;

  cout << endl<< "construct a matrix via an expression,  Matrix<double> B4 = ~A1+1;" << endl;
  Matrix<double> B4 = ~A1+1;
  B4.name("B4");
  dispcr(B4);


  LAvector<double> v1(2,"v1");
  v1 = sumbyrow(B4);
  dispcr(v1);
  LAvector<double> v2(3,"v2");
  v2 = sumbycol(A5);
  dispcr(v2);


  v1 = minbyrow(A5);
  dispcr(v1);
  v2 = minbycol(A5);
  dispcr(v2);
  v1 = maxbyrow(A5);
  dispcr(v1);
  v2 = maxbycol(A5);
  dispcr(v2);

  return 0;
}
