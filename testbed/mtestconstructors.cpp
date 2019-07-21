
// flag for run-time bounds and size checking
 


#include "cooll.hpp"
using namespace COOLL;

#include "testlib.hpp"

#include <iostream>
using namespace std;



int main()
{

  string s = "";


  // default constr.
  Matrix<double> A1;
  "{{1,2},{3,4}}">>A1;
  double ans1[] = {1,2,3,4};
  mcompare(A1,ans1);
  A1.name("Mat1");
  s="Mat1";
  compare(A1.name(),s);

  // default constr. with name
  Matrix<double> A2("Mat2");
  "{{1,2,3},{11,12,13}}">>A2;
  double ans2[] = {1,2,3,11,12,13};
  mcompare(A2,ans2);
  s="Mat2";
  compare(A2.name(),s);

  //  constr. with size
  Matrix<double> A3(3,2);
  "{{10,20},{30,40},{50,60}}">>A3;
  double ans3[] = {10,20,30,40,50,60};
  mcompare(A3,ans3);
  A3.name("Mat3");
  s="Mat3";
  compare(A3.name(),s);

  //  constr. with size and name
  Matrix<double> A4(1,2,"Mat4");
  "{{-1,-2}}">>A4;
  double ans4[] = {-1,-2};
  mcompare(A4,ans4);
  s="Mat4";
  compare(A4.name(),s);



  //COPY CONTRUCTOR
  Matrix<double> A7 = A1;
  double ans7[] = {1,2,3,4};
  mcompare(A7,ans7);
  A7.name("Mat7");
  s="Mat7";
  compare(A7.name(),s);


  //COPY CONTRUCTOR w/name
  Matrix<double> A8(A4,"Mat8");
  double ans8[] = {-1,-2};
  mcompare(A8,ans8);
  s="Mat8";
  compare(A8.name(),s);


  //Expression CONTRUCTOR
  Matrix<double> A9 = 2*A1;
  double ans9[] = {2.0*1.0,2.0*2.0,2.0*3.0,2.0*4.0};
  mcompare(A9,ans9);
  A9.name("Mat9");
  s="Mat9";
  compare(A9.name(),s);


  //Expression CONTRUCTOR w/name
  Matrix<double> A10((A1+1.5),"Mat10");
  double ans10[] = {1.0+1.5, 2.0+1.5, 3.0+1.5, 4.0+1.5};
  mcompare(A10,ans10);
  s="Mat10";
  compare(A10.name(),s);


  //  New constr. with size and name  and desstructor
  Matrix<double> *A11 = new Matrix<double>(2,2,"Mat11");
  "{{7,8},{9,10}}">>(*A11);
  double ans11[] = {7,8,9,10};
  mcompare(*A11,ans11);
  s="Mat11";
  compare(A11->name(),s);
  delete A11;

  cout << "<Matrix constructor tests passed>"<<endl;
  return 0;



}
