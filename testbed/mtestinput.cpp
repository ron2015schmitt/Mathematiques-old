
// flag for run-time bounds and size checking
 


#import "matricks.hpp"
using namespace Matricks;

#import "testlib.hpp"

#import <iostream>
using namespace std;


#import <vector>


int main()
{


  unsigned int n =0;

  Matrix<double> A1(2,2,"A1");
  Matrix<double> A2(2,3,"A2");
  Matrix<double> A3(1,2,"A3");
  Matrix<double> A4(2,3,"A4");


  // Initialization tests
  "{{1,2},{3,4}}">>A1;
  double ans1[] = {1,2,3,4};
  mcompare(A1,ans1);

  A1.textformat(text_nobraces);
  "5 6 \n7 8\n">>A1;
  double ans1b[] = {5,6,7,8};
  mcompare(A1,ans1b);

  A1.textformat(text_nobraces);
  "-1 -2 -3 -4">>A1;
  double ans1c[] = {-1,-2,-3,-4};
  mcompare(A1,ans1c);


  A1.textformat(text_braces);
  " { \n{ 11\n,22}, {33 , 44\n}}  \n\n4231 2">>A1;
  double ans2[] = {11,22,33,44};
  mcompare(A1,ans2);


  "{{1.1,2.2},{3.3,4.4}} {{5,6,7},{8,9,10}}{{11,12}}">>A1>>A2>>A3;
  double ans3[] = {1.1,2.2,3.3,4.4};
  mcompare(A1,ans3);
  double ans4[] = {5,6,7,8,9,10};
  mcompare(A2,ans4);
  double ans5[] = {11,12};
  mcompare(A3,ans5);

  A1.textformat(text_nobraces);
  A2.textformat(text_braces);
  A3.textformat(text_nobraces);
  "21 22 23 24 {{31,32,33},{34,35,36}}41 42\n">>A1>>A2>>A3;
  double ans6[] = {21,22,23,24};
  mcompare(A1,ans6);
  double ans7[] = {31,32,33,34,35,36};
  mcompare(A2,ans7);
  double ans8[] = {41,42};
  mcompare(A3,ans8);


  A2.textformat(text_nobraces);
  A4.textformat(text_nobraces);
  ostringstream strm;
  strm << A2;
  string s = strm.str();
  s >> A4;
  double ans9[] =  {31,32,33,34,35,36};
  mcompare(A4,ans9);

  A2.textformat(text_braces);
  A4.textformat(text_braces);
  "{{101, 102, 103},{ 104, 105, 106}}">>A2;
  strm.str("");// clear contents of string stream
  strm << A2;
  s = strm.str();
  s >> A4;
  double ans10[] =  {101,102,103,104,105,106};
  mcompare(A4,ans10);

  A1.textformat(text_nobraces);
  A1.resize(0,0);
  "5.5 6.6 \n7.7 8.8\n9.9 10.10" >> A1;
  n=3;
  compare(A1.Nrows(),n);
  n=2;
  compare(A1.Ncols(),n);
  double ans11[] = {5.5,6.6,7.7,8.8,9.9,10.10};
  mcompare(A1,ans11);

  A1.textformat(text_nobraces);
  A1.resize(0,0);
  "1.5 1.6 \n1.7 1.8\n1.9 1.10\n" >> A1;
  n=3;
  compare(A1.Nrows(),n);
  n=2;
  compare(A1.Ncols(),n);
  double ans11b[] = {1.5,1.6,1.7,1.8,1.9,1.10};
  mcompare(A1,ans11b);
  
  A1.textformat(text_braces);
  A1.resize(0,0);
  "{{33,34,35}} {1}" >> A1;
  n=1;
  compare(A1.Nrows(),n);
  n=3;
  compare(A1.Ncols(),n);
  double ans12[] = {33,34,35};
  mcompare(A1,ans12);


  A1.textformat(text_braces);
  A1.resize(0,0);
  "{{13,27,29,31},{1,2,3,4}} " >> A1;
  n=2;
  compare(A1.Nrows(),n);
  n=4;
  compare(A1.Ncols(),n);
  double ans13[] = {13,27,29,31,1,2,3,4};
  mcompare(A1,ans13);

  
  cout << "<Matrix input tests passed>"<<endl;
  return 0;



}
