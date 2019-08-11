
// flag for run-time bounds and size checking
 


#import "matricks.hpp"
using namespace Matricks;

#import "testlib.hpp"

#import <iostream>
using namespace std;


#import <vector>


int main()
{

  LAvector<double> v1(3,"v1");
  LAvector<double> v2(3,"v2");

  Matrix<double> M2(3,2,"M2");
  Matrix<double> M2b(2,3,"M2b");

  Matrix<double> M4(3,1,"M4");
  Matrix<double> M4b(1,3,"M4b");



  
  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  double ans10[] = {1,2,3};
  vcompare(v1,ans10);
  v2[0] = 101;
  v2[1] = 102;
  v2[2] = 103;
  double ans10b[] = {101,102,103};
  vcompare(v2,ans10b);

  M2(0) = 10;
  M2(1) = 20;
  M2(2) = 30;
  M2(3) = 40;
  M2(4) = 50;
  M2(5) = 60;
  double ans11[] = {10,20,30,40,50,60};
  mcompare(M2,ans11);

  M2b(0) = 100;
  M2b(1) = 200;
  M2b(2) = 300;
  M2b(3) = 400;
  M2b(4) = 500;
  M2b(5) = 600;
  double ans11b[] = {100,200,300,400,500,600};
  mcompare(M2b,ans11b);


  M4(0) = -1;
  M4(1) = -2;
  M4(2) = -3;
  double ans13[] = {-1,-2,-3};
  mcompare(M4,ans13);

  M4b(0) = -10;
  M4b(1) = -20;
  M4b(2) = -30;
  double ans14[] = {-10,-20,-30};
  mcompare(M4b,ans14);


  // vector = matrix

  v1 = M2b.row(1);
  double ans20[] = {400,500,600};
  vcompare(v1,ans20);

  v1 = M2.col(0);
  double ans21[] = {10,30,50};
  vcompare(v1,ans21);

  v1 = M4;
  double ans22[] = {-1,-2,-3};
  vcompare(v1,ans22);
  v1 = M4.col(0);
  double ans23[] = {-1,-2,-3};
  vcompare(v1,ans23);
  v1 = M4b;
  double ans24[] = {-10,-20,-30};
  vcompare(v1,ans24);
  v1 = M4b.row(0);
  double ans25[] = {-10,-20,-30};
  vcompare(v1,ans25);

  v1 = M4 + ~M4b;
  double ans26[] = {-11,-22,-33};
  vcompare(v1,ans26);
  v1 = M4.col(0)+ 10;
  double ans27[] = {9,8,7};
  vcompare(v1,ans27);



  v1 = M2b.submat(1,1,0,2);
  double ans30[] = {400,500,600};
  vcompare(v1,ans30);

  v1 = M2.submat(0,2,0,0);
  double ans31[] = {10,30,50};
  vcompare(v1,ans31);

  v1 = M4;
  double ans32[] = {-1,-2,-3};
  vcompare(v1,ans32);
  v1 = M4.submat(0,2,0,0);
  double ans33[] = {-1,-2,-3};
  vcompare(v1,ans33);
  v1 = M4b;
  double ans34[] = {-10,-20,-30};
  vcompare(v1,ans34);
  v1 = M4b.submat(0,0,0,2);
  double ans35[] = {-10,-20,-30};
  vcompare(v1,ans35);

  v1 = M4 + ~M4b;
  double ans36[] = {-11,-22,-33};
  vcompare(v1,ans36);
  v1 = M4.submat(0,2,0,0)+ 10;
  double ans37[] = {9,8,7};
  vcompare(v1,ans37);



  // matrix = vector
  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;

  M2b.row(1) = v1;
  double ans40[] = {100,200,300,1,2,3};
  mcompare(M2b,ans40);

  M2.col(0) = v1;
  double ans41[] = {1,20,2,40,3,60};
  mcompare(M2,ans41);

  M4 = v1;
  double ans42[] = {1,2,3};
  mcompare(M4,ans42);

  M4(0) = -1;
  M4(1) = -2;
  M4(2) = -3;
  M4.col(0) = v1;
  double ans43[] = {1,2,3};
  mcompare(M4,ans43);

  M4b = v1;
  double ans44[] = {1,2,3};
  mcompare(M4b,ans44);
  
  M4b(0) = -10;
  M4b(1) = -20;
  M4b(2) = -30;
  M4b.row(0) = v1;
  double ans45[] = {1,2,3};
  mcompare(M4b,ans45);

  M4(0) = -1;
  M4(1) = -2;
  M4(2) = -3;
  M4 = v1 + v2;
  double ans46[] = {102,104,106};
  mcompare(M4,ans46);
  
  M4(0) = -1;
  M4(1) = -2;
  M4(2) = -3;
  M4.col(0) = v1 + 10;
  double ans47[] = {11,12,13};
  mcompare(M4,ans47);


  M2(0) = 10;
  M2(1) = 20;
  M2(2) = 30;
  M2(3) = 40;
  M2(4) = 50;
  M2(5) = 60;
  M2b(0) = 100;
  M2b(1) = 200;
  M2b(2) = 300;
  M2b(3) = 400;
  M2b(4) = 500;
  M2b(5) = 600;
  M4(0) = -1;
  M4(1) = -2;
  M4(2) = -3;
  M4b(0) = -10;
  M4b(1) = -20;
  M4b(2) = -30;
  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;

  M2b.submat(1,1,0,2) = v1;
  double ans60[] = {100,200,300,1,2,3};
  mcompare(M2b,ans60);

  M2.submat(0,2,0,0) = v1;
  double ans61[] = {1,20,2,40,3,60};
  mcompare(M2,ans61);

  M4 = v1;
  double ans62[] = {1,2,3};
  mcompare(M4,ans62);

  M4(0) = -1;
  M4(1) = -2;
  M4(2) = -3;
  M4.submat(0,2,0,0) = v1;
  double ans63[] = {1,2,3};
  mcompare(M4,ans63);

  M4b = v1;
  double ans64[] = {1,2,3};
  mcompare(M4b,ans64);
  
  M4b(0) = -10;
  M4b(1) = -20;
  M4b(2) = -30;
  M4b.submat(0,0,0,2) = v1;
  double ans65[] = {1,2,3};
  mcompare(M4b,ans65);

  M4(0) = -1;
  M4(1) = -2;
  M4(2) = -3;
  M4 = v1 + v2;
  double ans66[] = {102,104,106};
  mcompare(M4,ans66);
  
  M4(0) = -1;
  M4(1) = -2;
  M4(2) = -3;
  M4.submat(0,2,0,0) = v1 + 10;
  double ans67[] = {11,12,13};
  mcompare(M4,ans67);


  cout << "<matrix/vector access tests passed>"<<endl;
  return 0;

}
