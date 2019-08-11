
// flag for run-time bounds and size checking
 


#import "matricks.hpp"
using namespace Matricks;

#import "testlib.hpp"

#import <iostream>
using namespace std;


#import <vector>


int main()
{




  LAvector<double> v1(4,"v1");
  LAvector<double> v2(4,"v2");
  LAvector<double> v3(4,"v3");


  // Initialization tests
  "{1,2,3,4}">>v1;
  double ans1[] = {1,2,3,4};
  vcompare(v1,ans1);

  " { 11 , 22 ,\n\n33 , 44 \n}  31 34">>v1;
  double ans2[] = {11,22,33,44};
  vcompare(v1,ans2);

  "{1.1,2.2,3.3,4.4} {5,6,7,8}{9,10,11,12}">>v1>>v2>>v3;
  double ans3[] = {1.1,2.2,3.3,4.4};
  vcompare(v1,ans3);
  double ans4[] = {5,6,7,8};
  vcompare(v2,ans4);
  double ans5[] = {9,10,11,12};
  vcompare(v3,ans5);

  v1.textformat(text_nobraces);
  v2.textformat(text_braces);
  v3.textformat(text_nobraces);
  " -1  -2 -3 -4 {56, 57, 58, 59} \n100 101 102.0 \n1">>v1>>v2>>v3;
  double ans6[] = {-1,-2,-3,-4};
  vcompare(v1,ans6);
  double ans7[] = {56,57,58,59};
  vcompare(v2,ans7);
  double ans8[] = {100,101,102};
  vcompare(v3,ans8);

  v1.textformat(text_nobraces);
  v2.textformat(text_nobraces);
  ostringstream strm;
  strm << v1;
  string s = strm.str();
  s >> v2;
  double ans9[] = {-1,-2,-3,-4};
  vcompare(v2,ans9);

  
  v1.textformat(text_braces);
  v2.textformat(text_braces);
  "{0.1,0.2,0.3,0.4}" >> v1;
  
  strm.str("");// clear contents of string stream
  strm << v1;
  s = strm.str();
  s >> v2;
  double ans10[] = {0.1,0.2,0.3,0.4};
  vcompare(v2,ans10);

  
  v1.textformat(text_nobraces);
  v1.resize(0);
  "5.5 6.6" >> v1;
  double ans11[] = {5.5, 6.6};
  vcompare(v1,ans11);
  
  v1.textformat(text_braces);
  v1.resize(0);
  "{33,34,35}" >> v1;
  double ans12[] = {33,34,35};
  vcompare(v1,ans12);

  cout << "<Vector input tests passed>"<<endl;
  return 0;



}
