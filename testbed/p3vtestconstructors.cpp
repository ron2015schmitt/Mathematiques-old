
// flag for run-time bounds and size checking
 


#import "matricks.hpp"
using namespace Matricks;

#import "testlib.hpp"

#import <iostream>
using namespace std;


#import <vector>


int main()
{

  string s = "";


  // default constr.
  p3vector<double> v1;
  "{1,2,3}">>v1;
  double ans1[] = {1,2,3};
  vcompare(v1,ans1);

  // default constr. with name
  p3vector<double> v2("vec2");
  "{1,2,3}">>v2;
  double ans2[] = {1,2,3};
  vcompare(v2,ans2);


  //  init constr. 
  p3vector<double> v5(1.1,1.2,1.3);
  double ans5[] = {1.1,1.2,1.3};
  vcompare(v5,ans5);



  //COPY CONTRUCTOR
  v5[0]=1.0;
  p3vector<double> v7 = v5;
  double ans7[] = {1.0,1.2,1.3};
  vcompare(v7,ans7);


  //COPY CONTRUCTOR w/name
  v5[0]=20.0;
  p3vector<double> v8(v5,"vec8");
  double ans8[] = {20.0,1.2,1.3};
  vcompare(v8,ans8);


  //Expression CONTRUCTOR
  v5[0]=1.0;
  p3vector<double> v9 = 2*v5;
  double ans9[] = {2.0*1.0,2.0*1.2,2.0*1.3};
  vcompare(v9,ans9);


  //Expression CONTRUCTOR w/name
  v5[0]=1.5;
  p3vector<double> v10((v5+1.0),"vec10");
  double ans10[] = {1.5+1.0,1.2+1.0,1.3+1.0};
  vcompare(v10,ans10);


  //  New constr. and desctructor
  p3vector<double> *v11 = new p3vector<double>();
  "{7,8,9}">>(*v11);
  double ans11[] = {7,8,9};
  vcompare(*v11,ans11);
  delete v11;

  cout << "<Physical 3-vector constructor tests passed>"<<endl;
  return 0;



}
