
// flag for run-time bounds and size checking
#define MATRICKS_DEBUG 1


#include "matricks.h"
using namespace matricks;

#include <iostream>
using namespace std;





int main()
{
  const int NR = 2;
  const int NC = 2;

  Matrix<double> A1(NR,NC,"A1");

  std::cout << std::endl<< "initialize each element of A1" << std::endl;
  A1(0,0) = 1.0;
  A1(0,1) = 2.0;
  A1(1,0) = 3.0;
  A1(1,1) = 4.0;
  std::cout << A1<< std::endl;
  

  std::cout << std::endl<< "initialize A2 to a constant" << std::endl;
  Matrix<double> A2(NR,NC,"A2");
  A2=100.0;
  std::cout << A2<< std::endl;

  std::cout << std::endl<< "add two matrices" << std::endl;
  A2=A1+A2;
  std::cout << A2<< std::endl;


  Matrix<double> A3(NR,NC,"A3");

  std::cout << std::endl<< "subtractionion of matrices" << std::endl;
  A3 = A2 - A1;
  std::cout << A3 << std::endl;

  std::cout << std::endl<< "elementwise multiplication of matrices" << std::endl;
  A3 = A1 * A2;
  std::cout << A3 << std::endl;

  std::cout << std::endl<< "elementwise division of matrices" << std::endl;
  A3 =  A2/A1;
  std::cout << A3 << std::endl;

  std::cout << std::endl<< "matrix + scalar" << std::endl;
  A3 = A1  + 1;
  std::cout << A3 << std::endl;

  std::cout << std::endl<< "complicated example#1" << std::endl;
  A3 = 3*(A1+A2)  +  1000.0;
  std::cout << A3 << std::endl;

  std::cout << std::endl<< "transpose A3=~A1" << std::endl;
  A3 = ~A1;
  std::cout << A3<< std::endl;


  const int NR2 = 2;
  const int NC2 = 3;
  Matrix<double> A4(NR2,NC2,"A4");
  std::cout << std::endl<< "initialize each element of A4" << std::endl;
  A4(0,0) = 5.0;
  A4(0,1) = 6.0;
  A4(0,2) = 7.0;
  A4(1,0) = 8.0;
  A4(1,1) = 9.0;
  A4(1,2) = 10.0;
  std::cout << A4<< std::endl;

  std::cout << std::endl<< "dot product A5=(A1|A4)" << std::endl;
  Matrix<double> A5(NR,NC2,"A5");
  A5 = (A1|A4);
  std::cout << A5<< std::endl;

  std::cout << std::endl<< "transpose A6=~A5" << std::endl;
  Matrix<double> A6(NC2,NR,"A6");
  A6 = ~A5;
  std::cout << A6<< std::endl;

  std::cout << std::endl<< "dot product A6=(A6|A4|A6)" << std::endl;
  A6=(A6|A4|A6);
  std::cout << A6 << std::endl;


  double d;
  std::cout << std::endl<< "maximum(A1+A2)" << std::endl;
  d = max(A1+A2);
  std::cout <<d << std::endl;

  std::cout << std::endl<< "minimum(2*A1)" << std::endl;
  d = min(2.0*A1);
  std::cout <<d << std::endl;


  std::cout << std::endl<< "sum(A1)" << std::endl;
  d = sum(A1);
  std::cout <<d << std::endl;

  std::cout << std::endl<< "trace(A5)" << std::endl;
  d = tr(A5);
  std::cout <<d << std::endl;


  Matrix<double> B1(1,4,"B1");
  std::cout << std::endl<< "example of a single row matrix" << std::endl;
  B1(0) = 1;
  B1(1) = 2;
  B1(2) = 3;
  B1(3) = 4;
  std::cout <<"B1="<<std::endl<< B1<< std::endl;

  Matrix<double> B2(4,1,"B2");
  std::cout << std::endl<< "example of a single column matrix" << std::endl;
  B2=3*~B1;
  std::cout <<"B2="<<std::endl<< B2<< std::endl;

  std::cout << std::endl<< "dot product of single row and column matrices" << std::endl;
  Matrix<double> B3(1,1,"B3");
  B3 = (B1|B2);
  std::cout <<"B3=(B1|B2)="<<B3<<std::endl;

  
  std::cout<<std::endl << "resize to zero to release the memory: A1.resize(0,0)" << std::endl;
  std::cout << "this can be used for efficient memory management when working with large matrices" << std::endl;
  A1.resize(0,0);
  std::cout <<"A1 = "<<std::endl<< A1<< std::endl;

  std::cout<<std::endl << "resize and set A1 from an expression" << std::endl;
  A1.resize() = 2*A2;
  std::cout <<"A1.resize() = A*A2 = "<<std::endl<< A1<< std::endl;

  std::cout << std::endl<< "construct a matrix via an expression,  Matrix<double> B4 = ~A1+1;" << std::endl;
  Matrix<double> B4 = ~A1+1;
  B4.name("B4");
  disp(B4);


  Vector<double> v1(2,"v1");
  v1 = sumbyrow(B4);
  disp(v1);
  Vector<double> v2(3,"v2");
  v2 = sumbycol(A5);
  disp(v2);


  v1 = minbyrow(A5);
  disp(v1);
  v2 = minbycol(A5);
  disp(v2);
  v1 = maxbyrow(A5);
  disp(v1);
  v2 = maxbycol(A5);
  disp(v2);

  return 0;
}
