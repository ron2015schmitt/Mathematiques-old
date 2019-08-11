
#import "matricks.hpp"
using namespace Matricks;

#import <iostream>
#import <iomanip>
using namespace std;

#import "testlib.hpp"






int main()
{
  double d=0.0;

  p3vector<double> v1(1,2,3);
  p3vector<double> v2;
  p3vector<double> v3;

  double ans1[] = {1,2,3};
  vcompare(v1,ans1);
  v1=v1;
  vcompare(v1,ans1);
  
  v1[0]=-1;
  v2=v1;
  double ans2[] = {-1,2,3};  
  vcompare(v2,ans2);


  v2[0]=101;
  v2[1]=102;
  v2[2]=103;
  double ans3[] = {101,102,103};  
  vcompare(v2,ans3);

  v2.x()=11;
  v2.y()=22;
  v2.z()=33;
  double ans4[] = {11,22,33};  
  vcompare(v2,ans4);


  v2.x(3.1);
  v2.y(3.2);
  v2.z(3.3);
  double ans5[] = {3.1,3.2,3.3};  
  vcompare(v2,ans5);



  d=v2.x();
  compare(d,3.1);
  d=v2.y();
  compare(d,3.2);
  d=v2.z();
  compare(d,3.3);


  d=v1[0];
  compare(d,-1.0);
  d=v1[1];
  compare(d,2.0);
  d=v1[2];
  compare(d,3.0);


  // Vector Arithmatic

  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;
  v2[0] = 100;
  v2[1] = 200;
  v2[2] = 300;

  v3 = v1 + v2;
  double ans11[] = {101,202,303};
  vcompare(v3,ans11);

  v3 = v1 + v3;
  double ans11a[] = {102,204,306};
  vcompare(v3,ans11a);

  v3 = v2 - v1;
  double ans12[] = {99,198,297};
  vcompare(v3,ans12);

  v3 = v1 * v2;
  double ans13[] = {100,400,900};
  vcompare(v3,ans13);

  v3 =  v2/v1;
  double ans14[] = {100,100,100};
  vcompare(v3,ans14);


  v3 =  v2/v1;
  double ans15[] = {100,100,100};
  vcompare(v3,ans15);

  v3 = 3*(v1+v2) + 1000;
  double ans16[] = {1303,1606,1909};
  vcompare(v3,ans16);

  v3 = -200 + 100*v1;
  double ans17[] = {-100,0,100};
  vcompare(v3,ans17);


  // vector scalar arithmatic

  v3 = 10+v2;
  double ans18[] = {110,210,310};
  vcompare(v3,ans18);
  v3 = v2+7;
  double ans19[] = {107,207,307};
  vcompare(v3,ans19);
  v3 = 13.0+v2;
  double ans20[] = {113,213,313};
  vcompare(v3,ans20);
  v3 = v2+7.5;
  double ans21[] = {107.5,207.5,307.5};
  vcompare(v3,ans21);

  v3 = 1000-v2;
  double ans22[] = {900,800,700};
  vcompare(v3,ans22);
  v3 = v2-11;
  double ans23[] = {89,189,289};
  vcompare(v3,ans23);
  v3 = 10.0-v2;
  double ans24[] = {-90,-190,-290};
  vcompare(v3,ans24);
  v3 = v2-2.1;
  double ans25[] = {100-2.1,200-2.1,300-2.1};
  vcompare(v3,ans25);

  v3 = 6*v2;
  double ans26[] = {600,1200,1800};
  vcompare(v3,ans26);
  v3 = v2*-3;
  double ans27[] = {-300,-600,-900};
  vcompare(v3,ans27);
  v3 = 11.0*v2;
  double ans28[] = {1100,2200,3300};
  vcompare(v3,ans28);
  v3 = v2*2.0;
  double ans29[] = {200,400,600};
  vcompare(v3,ans29);

  v3 = 100/v2;
  double ans30[] = {1,1.0/2.0,1.0/3.0};
  vcompare(v3,ans30);
  v3 = v2/100;
  double ans31[] = {1,2,3};
  vcompare(v3,ans31);
  v3 = 1200.0/v2;
  double ans32[] = {12,6,4};
  vcompare(v3,ans32);
  v3 = v2/2.0;
  double ans33[] = {50,100,150};
  vcompare(v3,ans33);


  // unitary +/-
  v3 = +v1;
  double ans34[] = {1,2,3};
  vcompare(v3,ans34);
  v3 = -v2;
  double ans35[] = {-100,-200,-300};
  vcompare(v3,ans35); 


  // dot product

  d = dot(v1,v2);
  compare(d,1400.0);

  d = dot(v1,v2) + 1.0;
  double a1 = (100+400+900) +1.0;
  compare(d,a1);

  // min and max
  
  v3[0]=19;
  v3[1]=-5;
  v3[2]=103;
  d = max(v3);
  compare(d,103.0);

  d = min(v3);
  compare(d,-5.0);

  // sum & norm

  d = sum(v3);
  compare(d,117.0);

  d = norm(v1);
  double a2 = sqrt(1.0*1.0 + 2.0*2.0 + 3.0*3.0);
  compare(d,a2);

  d = normsqr(v1);
  a2 = 1.0*1.0 + 2.0*2.0 + 3.0*3.0;
  compare(d,a2);

  //cross product
  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;
  v2[0] = 4;
  v2[1] = 5;
  v2[2] = 6;
 
  v3=cross(v1,v2);
  double ans40[] = {2.0*6.0-5.0*3.0, -1.0*6.0+4.0*3.0, 1.0*5.0-4.0*2.0};
  vcompare(v3,ans40); 


  cout << "<Basic physical 3-vector tests passed>"<<endl;

  return 0;
}
