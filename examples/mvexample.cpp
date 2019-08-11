
// flag for run-time bounds and size checking
#define MATRICKS_CAREFUL


#include "matricks.hpp"
using namespace Matricks;

#include <iostream>
using namespace std;





int main()
{
  const int N1 = 4;
  const int N2 = 3;
  
  LAvector<double> x1(N1,"x1");
  cout << "initialize each element of x1" << endl;
  x1[0] = 1.0;
  x1[1] = 2.0;
  x1[2] = 3.0;
  x1[3] = 4.0;
  cout << x1<< endl;

  LAvector<double> x2(N2,"x2");
  cout << "initialize each element of x2" << endl;
  x2[0] = 5.0;
  x2[1] = 6.0;
  x2[2] = 7.0;
  cout << x2 << endl;


  Matrix<double> A1(N2,N1,"A1");
  cout << "initialize each element of A1" << endl;
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
  cout << A1<< endl;

  Matrix<double> A2(N2,N1,"A2");

  cout << "outer product A2=x1^x2" << endl;
  A2 = (x1^x2);
  cout << A2<< endl;
  

  cout << "complicated example A2=(x1^x2) + 3*A1" << endl;
  A2 = (x1^x2) + 3.0*A1;
  cout << A2<< endl;


  cout << "x1=row 1 of A2" << endl;
  x1 = A2.row(1);
  cout << x1<< endl;

  cout << "x2=column 2 of A2" << endl;
  x2 = A2.col(1);
  cout << x2<< endl;
  

  cout << "x2=diagonal of A2+A1" << endl;
  x2 = diag(A1+A2);
  cout << x2<< endl;

  LAvector<double> x3(N1,"x3");
  cout << "initialize each element of x3" << endl;
  x3[0] = 1;
  x3[1] = 2;
  x3[2] = 3;
  x3[3] = 4;
  cout << x3 << endl;

  cout << "matrix/vector dot product x2=(A1|x3)" << endl;
  x2 = (A1|x3);
  cout << x2<< endl;

  cout << "initialize each element of x2" << endl;
  x2[0] = 1;
  x2[1] = 2;
  x2[2] = 3;
  cout << x2 << endl;

  cout << "matrix/vector dot product x3=(~A1|x2)" << endl;
  x3 = (~A1|x2);
  cout << x3<< endl;

  cout << "vector/matrix dot product x3=(x2|A1)" << endl;
  x3 = (x2|A1);
  cout << x3<< endl;

  cout << x2<< endl;
  cout << "initialize each element of x1" << endl;
  x1[0] = 1;
  x1[1] = 3;
  x1[2] = 5;
  x1[3] = 2;
  cout << x1<< endl;
  LAvector<double> x4(N2,"x4");
  x4 =(A1|x1);
  cout<<"x4 = (A1|x1)=" << x4<< endl;

  cout << "vector/matrix/vector dot product (x2|A1|x1)" << endl;
  double d = (x2|A1|x1);
  cout << d << endl;


  cout << "x1 = row 2 of A1" << endl;
  x1 = A1.row(2);
  cout << x1 << endl;


  cout << "x1 = sqrt(row 2 of A1)" << endl;
  x1 = sqrt_el(A1.row(2));
  cout << x1 << endl;


  cout << "x2 = (col 0 of A1) " << endl;
  x2 = A1.col(0);
  cout << x2 << endl;

  cout << "x2 = A1[2,1:3]" << endl;
  x2 = A1.submat(2,2,1,3);
  cout << x2 << endl;

  cout << "x1[0:2] = (col 0 of A1) " << endl;
  //  x1[ind(0,2)] = A1.col(0);
  cout << x1 << endl;


  return 0;
}
