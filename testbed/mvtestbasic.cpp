
// flag for run-time bounds and size checking
 


#import "matricks.hpp"
using namespace Matricks;

#import "testlib.hpp"

#import <iostream>
using namespace std;


#import <vector>


int main()
{
  double d;

  Matrix<double> A1(4,3,"A1");


  A1(0) = 11;
  A1(1) = -3;
  A1(2) = 3;
  A1(3) = 0;
  A1(4) = 41;
  A1(5) = -100;
  A1(6) = 36;
  A1(7) = 2;
  A1(8) = 34;
  A1(9) = 7;
  A1(10) = 30;
  A1(11) = -4;
  double ans1[] = {11,-3,3,
		   0,41,-100,
		   36,2,34,
		   7,30,-4};
  mcompare(A1,ans1);

  LAvector<double> v1(3);
  v1[0] = 13;
  v1[1] = -10;
  v1[2] = 4;
  double ans2[] = {13,-10,4};
  vcompare(v1,ans2);

  LAvector<double> v3(4,"v3");

  v3 = (A1|v1);
  double ans3[] = {13*11 + -10*-3  + 4*3,
		   13*0  + -10*41  + 4*-100,
		   13*36 + -10*2   + 4*34,
		   13*7  + -10*30  + 4*-4,
  };
  vcompare(v3,ans3);

  v3[0] = 8;
  v3[1] = -5;
  v3[2] = 2;
  v3[3] = 3;
  double ans4[] = {8,-5,2,3  };
  vcompare(v3,ans4);
  Matrix<double> A2(4,3);
  A2 = (v1^v3);
  double ans5[] = {8*13,   8*-10, 8*4,
		   -5*13, -5*-10, -5*4,
		   2*13,   2*-10, 2*4,
		   3*13,   3*-10, 3*4 };
  mcompare(A2,ans5);



  LAvector<double> v2(4,"v2");
  v2[0] = 1;
  v2[1] = 3;
  v2[2] = 5;
  v2[3] = 8;
  double ans6[] = {1,3,5,8};
  vcompare(v2,ans6);

  LAvector<double> v4(3,"v4");
  v4 = (v2|A1);
  double ans7[] = {11*1 + 0*3 + 36*5 + 7*8,
		   -3*1 + 41*3 + 2*5 + 30*8,
		    3*1 + -100*3 + 34*5 + -4*8 };
  vcompare(v4,ans7);


  d = (v2|A1|v1);
  double ans8 =  13 *(11*1 + 0*3 + 36*5 + 7*8) 
    + -10*(-3*1 + 41*3 + 2*5 + 30*8) 
    +   4*(3*1 + -100*3 + 34*5 + -4*8);
  compare(d,ans8);

  LAvector<double> v5(3,"v5");
  v5=diag(A1);
  double ans10[] = {11,41,34};
  vcompare(v5,ans10);

  Matrix<double> A3(3,3,"A3");
  A3=diagmat(v5);
  double ans11[] = {11,0,0,0,41,0,0,0,34};
  mcompare(A3,ans11);
  
  
  cout << "<Basic matrix-vector tests passed>"<<endl;
  return 0;


}
