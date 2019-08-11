
// flag for run-time bounds and size checking
 


#import "matricks.hpp"
using namespace Matricks;

#import "testlib.hpp"

#import <iostream>
using namespace std;


#import <vector>


int main()
{



  Matrix<double> M1(2,2,"M1");
  Matrix<double> M2(3,2,"M2");
  Matrix<double> M2b(2,3,"M2b");
  Matrix<double> M3(3,3,"M3");

  Matrix<double> M4(3,1,"M4");
  Matrix<double> M4b(1,3,"M4b");



  
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  double ans10[] = {1,2,3,4};
  mcompare(M1,ans10);

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

  M3(0) = 11;
  M3(1) = 22;
  M3(2) = 33;
  M3(3) = 44;
  M3(4) = 55;
  M3(5) = 66;
  M3(6) = 77;
  M3(7) = 88;
  M3(8) = 99;
  double ans12[] = {11,22,33,44,55,66,77,88,99};
  mcompare(M3,ans12);


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


  // .row() & .col() access

  M1.row(0) = M2.row(1);
  double ans20[] = {30,40,3,4};
  mcompare(M1,ans20);

  M1.row(0) = ~M2b.col(2);
  double ans21[] = {300,600,3,4};
  mcompare(M1,ans21);

  M1.row(1) = M1.row(0);
  double ans22[] = {300,600,300,600};
  mcompare(M1,ans22);

  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1.col(1) = ~M1.row(0);
  double ans23[] = {1,1,3,2};
  mcompare(M1,ans23);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1.col(1) = M1.col(0);
  double ans24[] = {1,1,3,3};
  mcompare(M1,ans24);

  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1.col(1) = M2b.col(0);
  double ans25[] = {1,100,3,400};
  mcompare(M1,ans25);

  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1.col(0) = M2b.col(2);
  double ans26[] = {300,2,600,4};
  mcompare(M1,ans26);


  M3.col(1) = ~M2b.row(1);
  double ans27[] = {11,400,33,44,500,66,77,600,99};
  mcompare(M3,ans27);

  M3.col(2) = M2.col(0);
  double ans28[] = {11,400,10,44,500,30,77,600,50};
  mcompare(M3,ans28);

  M3.row(0) = ~M2.col(1);
  double ans29[] = {20,40,60,44,500,30,77,600,50};
  mcompare(M3,ans29);

  M3.row(2) = M2b.row(0);
  double ans30[] = {20,40,60,44,500,30,100,200,300};
  mcompare(M3,ans30);

  M4 = M2.col(1);
  double ans31[] = {20,40,60};
  mcompare(M4,ans31);

  M4b = M2b.row(1);
  double ans32[] = {400,500,600};
  mcompare(M4b,ans32);


  M4(0) = -1;
  M4(1) = -2;
  M4(2) = -3;
  mcompare(M4,ans13);
  M4b(0) = -10;
  M4b(1) = -20;
  M4b(2) = -30;
  mcompare(M4b,ans14);


  M2.col(1) = M4;
  double ans33[] = {10,-1,30,-2,50,-3};
  mcompare(M2,ans33);

  M2b.row(1) = M4b;
  double ans34[] = {100,200,300,-10,-20,-30};
  mcompare(M2b,ans34);

  // .submat
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  mcompare(M1,ans10);

  M2(0) = 10;
  M2(1) = 20;
  M2(2) = 30;
  M2(3) = 40;
  M2(4) = 50;
  M2(5) = 60;
  mcompare(M2,ans11);

  M2b(0) = 100;
  M2b(1) = 200;
  M2b(2) = 300;
  M2b(3) = 400;
  M2b(4) = 500;
  M2b(5) = 600;
  mcompare(M2b,ans11b);

  M3(0) = 11;
  M3(1) = 22;
  M3(2) = 33;
  M3(3) = 44;
  M3(4) = 55;
  M3(5) = 66;
  M3(6) = 77;
  M3(7) = 88;
  M3(8) = 99;
  mcompare(M3,ans12);


  M1= M3.submat(1,2,0,1);
  double ans50[] = {44,55,77,88};
  mcompare(M1,ans50);

  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1.submat(0,1,0,1)= M3.submat(1,2,0,1);
  double ans51[] = {44,55,77,88};
  mcompare(M1,ans51);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M3.submat(0,1,1,2)= M2.submat(1,2,0,1);
  double ans52[] = {11,30,40,44,50,60,77,88,99};

  mcompare(M3,ans52);


  cout << "<matrix access tests 3 passed>"<<endl;
  return 0;

}
