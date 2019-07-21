
// flag for run-time bounds and size checking
 


#include "cooll.hpp"
using namespace COOLL;

#include "testlib.hpp"

#include <iostream>
using namespace std;


#include <vector>


int main()
{




  p3vector<double> v1;
  p3vector<double> v2;
  p3vector<double> v3;


  "{1,2,3}">>v1;
  double ans1[] = {1,2,3};
  vcompare(v1,ans1);

  " { 11 , 22 ,\n\n33 }  31 34">>v1;
  double ans2[] = {11,22,33};
  vcompare(v1,ans2);

  "{1.1,2.2,3.3} {5,6,7}{9,10,11}">>v1>>v2>>v3;
  double ans3[] = {1.1,2.2,3.3};
  vcompare(v1,ans3);
  double ans4[] = {5,6,7};
  vcompare(v2,ans4);
  double ans5[] = {9,10,11};
  vcompare(v3,ans5);

  p3vectorformat::textformat(text_nobraces);
  " -1  -2 -3 56 57 58  \n100 101 102.0 \n1">>v1>>v2>>v3;
  double ans6[] = {-1,-2,-3};
  vcompare(v1,ans6);
  double ans7[] = {56,57,58};
  vcompare(v2,ans7);
  double ans8[] = {100,101,102};
  vcompare(v3,ans8);

  p3vectorformat::textformat(text_nobraces);
  ostringstream strm;
  strm << v1;
  string s = strm.str();
  s >> v2;
  double ans9[] = {-1,-2,-3};
  vcompare(v2,ans9);

  
  p3vectorformat::textformat(text_braces);
  "{0.1,0.2,0.3}" >> v1;
  
  strm.str("");// clear contents of string stream
  strm << v1;
  s = strm.str();
  s >> v2;
  double ans10[] = {0.1,0.2,0.3};
  vcompare(v2,ans10);

  
  cout << "<Physical 3-vector input tests passed>"<<endl;
  return 0;



}
