
// flag for run-time bounds and size checking
 


#include "cooll.hpp"
using namespace COOLL;

#include "testlib.hpp"

#include <iostream>
using namespace std;


#include <vector>


int main()
{

  string s = "";


  // default constr.
  LAvector<double> v1;
  "{1,2,3,4,5}">>v1;
  double ans1[] = {1,2,3,4,5};
  vcompare(v1,ans1);
  v1.name("vec1");
  s="vec1";
  compare(v1.name(),s);

  // default constr. with name
  LAvector<double> v2("vec2");
  "{1,2,3}">>v2;
  double ans2[] = {1,2,3};
  vcompare(v2,ans2);
  s="vec2";
  compare(v2.name(),s);

  //  constr. with size
  LAvector<double> v3(4);
  "{10,20,30,40}">>v3;
  double ans3[] = {10,20,30,40};
  vcompare(v3,ans3);
  v3.name("vec3");
  s="vec3";
  compare(v3.name(),s);

  //  constr. with size and name
  LAvector<double> v4(2,"vec4");
  "{-1,-2}">>v4;
  double ans4[] = {-1,-2};
  vcompare(v4,ans4);
  s="vec4";
  compare(v4.name(),s);

  //  init constr. 
  LAvector<double> v5(3,3.14);
  double ans5[] = {3.14,3.14,3.14};
  vcompare(v5,ans5);
  v5.name("vec5");
  s="vec5";
  compare(v5.name(),s);


  //  init constr. with name
  LAvector<double> v6(4,1.11,"vec6");
  double ans6[] = {1.11,1.11,1.11,1.11};
  vcompare(v6,ans6);
  s="vec6";
  compare(v6.name(),s);

  //COPY CONTRUCTOR
  v5[0]=1.0;
  LAvector<double> v7 = v5;
  double ans7[] = {1.0,3.14,3.14};
  vcompare(v7,ans7);
  v7.name("vec7");
  s="vec7";
  compare(v7.name(),s);


  //COPY CONTRUCTOR w/name
  v5[0]=20.0;
  LAvector<double> v8(v5,"vec8");
  double ans8[] = {20.0,3.14,3.14};
  vcompare(v8,ans8);
  s="vec8";
  compare(v8.name(),s);


  //Expression CONTRUCTOR
  v5[0]=1.0;
  LAvector<double> v9 = 2*v5;
  double ans9[] = {2.0*1.0,2.0*3.14,2.0*3.14};
  vcompare(v9,ans9);
  v9.name("vec9");
  s="vec9";
  compare(v9.name(),s);


  //Expression CONTRUCTOR w/name
  v5[0]=1.5;
  LAvector<double> v10((v5+1.0),"vec10");
  double ans10[] = {1.5+1.0,3.14+1.0,3.14+1.0};
  vcompare(v10,ans10);
  s="vec10";
  compare(v10.name(),s);


  //  New constr. with size and name  and desstructor
  LAvector<double> *v11 = new LAvector<double>(2,"vec11");
  "{7,8}">>(*v11);
  double ans11[] = {7,8};
  vcompare(*v11,ans11);
  s="vec11";
  compare(v11->name(),s);
  delete v11;

  cout << "<Vector constructor tests passed>"<<endl;
  return 0;



}
