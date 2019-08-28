
// flag for run-time bounds and size checking
#define MATRICKS_DEBUG 1


#include "matricks.h"
using namespace matricks;

#include <iostream>
using namespace std;





int main()
{
  const int N1 = 4;
  const int N2 = 3;
  
  Vector<double> x1(N1,"x1");
  std::cout << "initialize each element of x1" << std::endl;
  x1[0] = 1.0;
  x1[1] = 2.0;
  x1[2] = 3.0;
  x1[3] = 4.0;
  std::cout << x1<< std::endl;

  Vector<double> x2(N2,"x2");
  std::cout << "initialize each element of x2" << std::endl;
  x2[0] = 5.0;
  x2[1] = 6.0;
  x2[2] = 7.0;
  std::cout << x2 << std::endl;


  Matrix<double> A1(N2,N1,"A1");
  std::cout << "initialize each element of A1" << std::endl;
  A1(0,0) = 10.0;
  A1(0,1) = 20.0;
  A1(0,2) = 30.0;
  A1(0,3) = 40.0;
  A1(1,0) = 50.0;
  A1(1,1) = 60.0;
  A1(1,2) = 70.0;
  A1(1,3) = 80.0;
  A1(2,0) = 90.0;
  A1(2,1) = 100.0;
  A1(2,2) = 110.0;
  A1(2,3) = 120.0;
  std::cout << A1<< std::endl;

  Matrix<double> A2(N2,N1,"A2");

  std::cout << "outer product A2=x1^x2" << std::endl;
  A2 = (x1^x2);
  std::cout << A2<< std::endl;
  

  std::cout << "complicated example A2=(x1^x2) + 3*A1" << std::endl;
  A2 = (x1^x2) + 3.0*A1;
  std::cout << A2<< std::endl;


  std::cout << "x1=row 1 of A2" << std::endl;
  x1 = A2.row(1);
  std::cout << x1<< std::endl;

  std::cout << "x2=column 2 of A2" << std::endl;
  x2 = A2.col(1);
  std::cout << x2<< std::endl;
  

  std::cout << "x2=diagonal of A2+A1" << std::endl;
  x2 = diag(A1+A2);
  std::cout << x2<< std::endl;

  Vector<double> x3(N1,"x3");
  std::cout << "initialize each element of x3" << std::endl;
  x3[0] = 1;
  x3[1] = 2;
  x3[2] = 3;
  x3[3] = 4;
  std::cout << x3 << std::endl;

  std::cout << "matrix/vector dot product x2=(A1|x3)" << std::endl;
  x2 = (A1|x3);
  std::cout << x2<< std::endl;

  std::cout << "initialize each element of x2" << std::endl;
  x2[0] = 1;
  x2[1] = 2;
  x2[2] = 3;
  std::cout << x2 << std::endl;

  std::cout << "matrix/vector dot product x3=(~A1|x2)" << std::endl;
  x3 = (~A1|x2);
  std::cout << x3<< std::endl;

  std::cout << "vector/matrix dot product x3=(x2|A1)" << std::endl;
  x3 = (x2|A1);
  std::cout << x3<< std::endl;

  std::cout << x2<< std::endl;
  std::cout << "initialize each element of x1" << std::endl;
  x1[0] = 1;
  x1[1] = 3;
  x1[2] = 5;
  x1[3] = 2;
  std::cout << x1<< std::endl;
  Vector<double> x4(N2,"x4");
  x4 =(A1|x1);
  std::cout<<"x4 = (A1|x1)=" << x4<< std::endl;

  std::cout << "vector/matrix/vector dot product (x2|A1|x1)" << std::endl;
  double d = (x2|A1|x1);
  std::cout << d << std::endl;


  std::cout << "x1 = row 2 of A1" << std::endl;
  x1 = A1.row(2);
  std::cout << x1 << std::endl;


  std::cout << "x1 = sqrt(row 2 of A1)" << std::endl;
  x1 = sqrt_el(A1.row(2));
  std::cout << x1 << std::endl;


  std::cout << "x2 = (col 0 of A1) " << std::endl;
  x2 = A1.col(0);
  std::cout << x2 << std::endl;

  std::cout << "x2 = A1[2,1:3]" << std::endl;
  x2 = A1.submat(2,2,1,3);
  std::cout << x2 << std::endl;

  std::cout << "x1[0:2] = (col 0 of A1) " << std::endl;
  //  x1[ind(0,2)] = A1.col(0);
  std::cout << x1 << std::endl;


  return 0;
}
