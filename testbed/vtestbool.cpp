
// flag for run-time bounds and size checking
 


#include "cooll.hpp"
using namespace COOLL;

#include "testlib.hpp"

#include <iostream>
using namespace std;

#include <vector>




int main()
{
  bool Q;
  int m =0;
  LAvector<double> v1(4,"v1");
  LAvector<double> v2(4,"v2");
  LAvector<double> v3(4,"v3");
  v1 = range<double>(1,4);
  double ans1[] = {1,2,3,4};
  vcompare(v1,ans1);

  LAvector<bool> q1(4,"q1");
  LAvector<bool> q2(4,"q2");

  q1 = (v1==1.0);
  bool ans2[] = {1,0,0,0};
  vcompare(q1,ans2);

  // scalar == and !=

  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 1.0;
  v1[3] = 4.0;
  q1 = (v1==1.0);
  bool ans3[] = {1,0,1,0};
  vcompare(q1,ans3);

  q1=0;
  q1 = (2.0==v1);
  bool ans4[] = {0,1,0,0};
  vcompare(q1,ans4);

  q1=0;
  q1 = (v1!=1.0);
  bool ans5[] = {0,1,0,1};
  vcompare(q1,ans5);

  q1=0;
  q1 = (2.0!=v1);
  bool ans6[] = {1,0,1,1};
  vcompare(q1,ans6);

  // intscalar == and !=


  v1[0] = 1.0;
  v1[1] = 1.0;
  v1[2] = 4.0;
  v1[3] = 2.0;

  q1 = (v1==1);
  bool ans3i[] = {1,1,0,0};
  vcompare(q1,ans3i);

  q1=0;
  q1 = (2==v1);
  bool ans4i[] = {0,0,0,1};
  vcompare(q1,ans4i);

  q1=0;
  q1 = (v1!=1);
  bool ans5i[] = {0,0,1,1};
  vcompare(q1,ans5i);

  q1=0;
  q1 = (2!=v1);
  bool ans6i[] = {1,1,1,0};
  vcompare(q1,ans6i);


  // scalar <= and <

  v1[0] = 2.3;
  v1[1] = -1.0;
  v1[2] = 5.0;
  v1[3] = 3.0;

  q1=0;
  q1 = (v1<=3.0);
  bool ans10[] = {1,1,0,1};
  vcompare(q1,ans10);

  q1=0;
  q1 = (3.0<=v1);
  bool ans11[] = {0,0,1,1};
  vcompare(q1,ans11);

  q1=0;
  q1 = (v1<3.0);
  bool ans12[] = {1,1,0,0};
  vcompare(q1,ans12);

  q1=0;
  q1 = (3.0<v1);
  bool ans13[] = {0,0,1,0};
  vcompare(q1,ans13);


  // intscalar <= and <

  v1[0] = 2.3;
  v1[1] = -1.0;
  v1[2] = 3.0;
  v1[3] = 3.5;


  q1=0;
  q1 = (v1<=3);
  bool ans10i[] = {1,1,1,0};
  vcompare(q1,ans10i);

  q1=0;
  q1 = (3<=v1);
  bool ans11i[] = {0,0,1,1};
  vcompare(q1,ans11i);

  q1=0;
  q1 = (v1<3);
  bool ans12i[] = {1,1,0,0};
  vcompare(q1,ans12i);

  q1=0;
  q1 = (3<v1);
  bool ans13i[] = {0,0,0,1};
  vcompare(q1,ans13i);

  // scalar >= and >

  v1[0] = 3.0;
  v1[1] = -1.0;
  v1[2] = 4.0;
  v1[3] = 2.1;

  q1=0;
  q1 = (v1>=2.1);
  bool ans14[] = {1,0,1,1};
  vcompare(q1,ans14);

  q1=0;
  q1 = (2.1>=v1);
  bool ans15[] = {0,1,0,1};
  vcompare(q1,ans15);


  q1=0;
  q1 = (v1>2.1);
  bool ans16[] = {1,0,1,0};
  vcompare(q1,ans16);

  q1=0;
  q1 = (2.1>v1);
  bool ans17[] = {0,1,0,0};
  vcompare(q1,ans17);


// intscalar >= and >

  v1[0] = 4.0;
  v1[1] = -1.2;
  v1[2] = 2.0;
  v1[3] = 3.0;

  q1=0;
  q1 = (v1>=2);
  bool ans14i[] = {1,0,1,1};
  vcompare(q1,ans14i);

  q1=0;
  q1 = (2>=v1);
  bool ans15i[] = {0,1,1,0};
  vcompare(q1,ans15i);


  q1=0;
  q1 = (v1>2);
  bool ans16i[] = {1,0,0,1};
  vcompare(q1,ans16i);

  q1=0;
  q1 = (2>v1);
  bool ans17i[] = {0,1,0,0};
  vcompare(q1,ans17i);


  // scalar &&, ||

  LAvector<bool> q3(4,"q3");

  q1[0] = 1;
  q1[1] = 0;
  q1[2] = 0;
  q1[3] = 1;

  q3 = q1 && true;
  bool ans20[] = {1,0,0,1};
  vcompare(q3,ans20);
  q3 = q1 && false;
  bool ans21[] = {0,0,0,0};
  vcompare(q3,ans21);
  q3 = q1 || true;
  bool ans22[] = {1,1,1,1};
  vcompare(q3,ans22);
  q3 = q1 || false;
  bool ans23[] = {1,0,0,1};
  vcompare(q3,ans23);

  q1[0] = 0;
  q1[1] = 1;
  q1[2] = 0;
  q1[3] = 1;

  q3 = true && q1;
  bool ans24[] = {0,1,0,1};
  vcompare(q3,ans24);
  q3 =  false && q1;
  bool ans25[] = {0,0,0,0};
  vcompare(q3,ans25);
  q3 = true ||q1;
  bool ans26[] = {1,1,1,1};
  vcompare(q3,ans26);
  q3 = false||q1;
  bool ans27[] = {0,1,0,1};
  vcompare(q3,ans27);

  
  // not -- !

  q1[0] = 1;
  q1[1] = 1;
  q1[2] = 0;
  q1[3] = 0;

  q2[0] = 1;
  q2[1] = 0;
  q2[2] = 1;
  q2[3] = 0;

  q3 = !q1;
  bool ans30[] = {0,0,1,1};
  vcompare(q3,ans30);
  q3 = !q2;
  bool ans31[] = {0,1,0,1};
  vcompare(q3,ans31);


  // vector && vector

  q3 = q1 && q2;
  bool ans32[] = {1,0,0,0};
  vcompare(q3,ans32);
  q3 = q1 && !q2;
  bool ans33[] = {0,1,0,0};
  vcompare(q3,ans33);
  q3 = !q1 && q2;
  bool ans34[] = {0,0,1,0};
  vcompare(q3,ans34);
  q3 = !q1 && !q2;
  bool ans35[] = {0,0,0,1};
  vcompare(q3,ans35);

  // vector || vector

  q3 = q1 || q2;
  bool ans36[] = {1,1,1,0};
  vcompare(q3,ans36);
  q3 = q1 || !q2;
  bool ans37[] = {1,1,0,1};
  vcompare(q3,ans37);
  q3 = !q1 || q2;
  bool ans38[] = {1,0,1,1};
  vcompare(q3,ans38);
  q3 = !q1 || !q2;
  bool ans39[] = {0,1,1,1};
  vcompare(q3,ans39);

  v1[0] = 4.0;
  v1[1] = -1.2;
  v1[2] = 2.0;
  v1[3] = 3.0;

  v2[0] = 4.0;
  v2[1] = -1.0;
  v2[2] = 1.9;
  v2[3] = 3.0;

  // vector == vector
  q1 = (v1==v2);
  bool ans50[] = {1,0,0,1};
  vcompare(q1,ans50);
  q1 = (v1==(v2+10));
  bool ans51[] = {0,0,0,0};
  vcompare(q1,ans51);

  // vector != vector
  q1 = (v1!=v2);
  bool ans52[] = {0,1,1,0};
  vcompare(q1,ans52);
  q1 = (v1!=(v2+10));
  bool ans53[] = {1,1,1,1};
  vcompare(q1,ans53);

  // vector < vector
  q1 = (v1<v2);
  bool ans54[] = {0,1,0,0};
  vcompare(q1,ans54);
  q1 = (v1<(v2+0.2));
  bool ans55[] = {1,1,1,1};
  vcompare(q1,ans55);

  // vector <= vector
  q1 = (v1<=v2);
  bool ans56[] = {1,1,0,1};
  vcompare(q1,ans56);
  q1 = (v1<=(v2-0.1));
  bool ans57[] = {0,1,0,0};
  vcompare(q1,ans57);


 // vector > vector
  q1 = (v1>v2);
  bool ans58[] = {0,0,1,0};
  vcompare(q1,ans58);
  q1 = (v1>(v2-0.1));
  bool ans59[] = {1,0,1,1};
  vcompare(q1,ans59);

  // vector >= vector
  q1 = (v1>=v2);
  bool ans60[] = {1,0,1,1};
  vcompare(q1,ans60);
  q1 = (v1>=(v2+0.05));
  bool ans61[] = {0,0,1,0};
  vcompare(q1,ans61);


  q1[0] = 1;
  q1[1] = 1;
  q1[2] = 0;
  q1[3] = 0;

  q2[0] = 1;
  q2[1] = 0;
  q2[2] = 1;
  q2[3] = 0;

  // alltrue
  Q = alltrue(q1);
  compare(Q,false);
  Q = alltrue(!q1);
  compare(Q,false);
  Q = alltrue(q1||!q1);
  compare(Q,true);

  // anytrue
  Q = anytrue(q1);
  compare(Q,true);
  Q = anytrue(!q1);
  compare(Q,true);
  Q = anytrue(q1&&!q1);
  compare(Q,false);

  // numtrue
  m = numtrue(q1);
  compare(m,2);
  m = numtrue(q1||true);
  compare(m,4);
  m = numtrue(q1&&false);
  compare(m,0);
  m = numtrue(!(q1||q2));
  compare(m,1);

  // find true
  LAvector<unsigned int> p1(0,"p1");
  p1.resize() = findtrue(q1);
  unsigned int ans70[] = {0,1};
  vcompare(p1,ans70);
  p1.resize() = findtrue(q2);
  unsigned int ans71[] = {0,2};
  vcompare(p1,ans71);
  p1.resize() = findtrue(q1||q2);
  unsigned int ans72[] = {0,1,2};
  vcompare(p1,ans72);
  p1.resize() =  findtrue(!q1 && !q2);
  unsigned int ans73[] = {3};
  vcompare(p1,ans73);
  p1.resize() =  findtrue(!q1 || q2);
  unsigned int ans74[] = {0,2,3};
  vcompare(p1,ans74);
  p1.resize() = findtrue(q1&&false);
  unsigned int ans75[] = {};
  vcompare(p1,ans75);
  p1.resize() = findtrue(q1||true);
  unsigned int ans76[] = {0,1,2,3};
  vcompare(p1,ans76);

  cout << "<Boolean vector tests passed>"<<endl;

  return 0;
}
