
// flag for run-time bounds and size checking
 


#include "cooll.hpp"
using namespace COOLL;

#include "testlib.hpp"

#include <iostream>
using namespace std;


#include <vector>


int main()
{

  LAvector<double> v1(4,"v1");
  LAvector<double> v2(6,"v2");
  LAvector<double> v3(8,"v3");


  // range objects

  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  double ans1[] = {1,2,3,4};
  vcompare(v1,ans1);

  v2[0] = 10;
  v2[1] = 20;
  v2[2] = 30;
  v2[3] = 40;
  v2[4] = 50;
  v2[5] = 60;
  double ans2[] = {10,20,30,40,50,60};
  vcompare(v2,ans2);

  v3[0] = 11;
  v3[1] = 22;
  v3[2] = 33;
  v3[3] = 44;
  v3[4] = 55;
  v3[5] = 66;
  v3[6] = 77;
  v3[7] = 88;
  double ans3[] = {11,22,33,44,55,66,77,88};
  vcompare(v3,ans3);

  
  v1 = v3[seq(2,5)];
  double ans10[] = {33,44,55,66};
  vcompare(v1,ans10);

  v1 = v3[seq(3,0)];
  double ans11[] = {44,33,22,11};
  vcompare(v1,ans11);


  v1 = v3[seq(0,6,2)];
  double ans12[] = {11,33,55,77};
  vcompare(v1,ans12);

  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  v1[seq(2,3)] = v2[seq(3,1,-2)];
  double ans13[] = {1,2,40,20};
  vcompare(v1,ans13);


  v1[seq(0,3)] = v1[seq(3,0)];
  double ans14[] = {20,40,2,1};
  vcompare(v1,ans14);


  v1 = v1[seq(3,0)];
  double ans15[] = {1,2,40,20};
  vcompare(v1,ans15);

  v1[seq(0,3,2)] = -1;
  double ans16[] = {-1,2,-1,20};
  vcompare(v1,ans16);


  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  v2[seq(5,2)] = v1;
  double ans18[] = {10,20,4,3,2,1};
  vcompare(v2,ans18);

  v2[seq(2,5)] = v1;
  double ans19[] = {10,20,1,2,3,4};
  vcompare(v2,ans19);

  v1[seq(3,0)] = v1;
  double ans20[] = {4,3,2,1};
  vcompare(v1,ans20);

  v1[seq(3,0,-1)] = v1[seq(0,3,1)];
  double ans21[] = {1,2,3,4};
  vcompare(v1,ans21);


  v1[seq(3,0,-1)] = v1[seq(0,3,1)] + 100;
  double ans22[] = {104,103,102,101};
  vcompare(v1,ans22);

  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  v2[0] = 10;
  v2[1] = 20;
  v2[2] = 30;
  v2[3] = 40;
  v2[4] = 50;
  v2[5] = 60;
  v1[seq(3,0,-1)] = v1[seq(0,3,1)] + v2[seq(2,5)];
  double ans23[] = {64,53,42,31};
  vcompare(v1,ans23);


  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  v1 = 2*v1[seq(3,0)];
  double ans24[] = {8,6,4,2};
  vcompare(v1,ans24);

  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  v1[seq(3,0)] = 3*v1 +1;
  double ans25[] = {13,10,7,4};
  vcompare(v1,ans25);


  //////////////////////////////////////////////////////////

  // set objects

  LAvector<unsigned int> i0(2,"i0");
  LAvector<unsigned int> i0b(2,"ib");
  LAvector<unsigned int> i1(4,"i1");
  LAvector<unsigned int> i1b(4,"i1b");
  LAvector<unsigned int> i1c(4,"i1c");
  LAvector<unsigned int> i2(6,"i2");
  LAvector<unsigned int> i3(8,"i3");


  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  double ans50[] = {1,2,3,4};
  vcompare(v1,ans50);

  v2[0] = 10;
  v2[1] = 20;
  v2[2] = 30;
  v2[3] = 40;
  v2[4] = 50;
  v2[5] = 60;
  double ans51[] = {10,20,30,40,50,60};
  vcompare(v2,ans51);

  v3[0] = 11;
  v3[1] = 22;
  v3[2] = 33;
  v3[3] = 44;
  v3[4] = 55;
  v3[5] = 66;
  v3[6] = 77;
  v3[7] = 88;
  double ans52[] = {11,22,33,44,55,66,77,88};
  vcompare(v3,ans52);

  
  i1[0] = 5;
  i1[1] = 0;
  i1[2] = 1;
  i1[3] = 3;
  v1 = v3[i1];
  double ans60[] = {66,11,22,44};
  vcompare(v1,ans60);

  
  i1[0] = 3;
  i1[1] = 2;
  i1[2] = 1;
  i1[3] = 0;
  v1 = v3[i1];
  double ans61[] = {44,33,22,11};
  vcompare(v1,ans61);


  i0[0] = 5;
  i0[1] = 0;
  v1[seq(1,2)] = v2[i0];
  double ans62[] = {44,60,10,11};
  vcompare(v1,ans62);



  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  i0[0] = 1;
  i0[1] = 2;
  i0b[0] = 3;
  i0b[1] = 1;
  v1[i0] = v2[i0b];
  double ans63[] = {1,40,20,4};
  vcompare(v1,ans63);


  i1[0] = 0;
  i1[1] = 1;
  i1[2] = 2;
  i1[3] = 3;
  i1b[0] = 3;
  i1b[1] = 2;
  i1b[2] = 1;
  i1b[3] = 0;
  v1[i1] = v1[i1b];
  double ans64[] = {4,20,40,1};
  vcompare(v1,ans64);


  v1 = v1[i1b];
  double ans65[] = {1,40,20,4};
  vcompare(v1,ans65);

  i0[0] = 0;
  i0[1] = 2;
  v1[i0] = -1;
  double ans66[] = {-1,40,-1,4};
  vcompare(v1,ans66);



  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  i1[0] = 5;
  i1[1] = 4;
  i1[2] = 3;
  i1[3] = 2;
  v2[i1] = v1;
  double ans68[] = {10,20,4,3,2,1};
  vcompare(v2,ans68);

  i1 = i1[seq(3,0)];
  v2[i1] = v1;
  double ans69[] = {10,20,1,2,3,4};
  vcompare(v2,ans69);

  i1[0] = 1;
  i1[1] = 1;
  i1[2] = 1;
  i1[3] = 1;
  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  v1[i1] = v1;
  double ans70[] = {1,4,3,4};
  vcompare(v1,ans70);


  i1[0] = 1;
  i1[1] = 1;
  i1[2] = 1;
  i1[3] = 1;
  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  v1 = v1[i1];
  double ans70b[] = {2,2,2,2};
  vcompare(v1,ans70b);


  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  i1[0] = 1;
  i1[1] = 3;
  i1[2] = 0;
  i1[3] = 2;
  i1b[0] = 2;
  i1b[1] = 0;
  i1b[2] = 1;
  i1b[3] = 3;
  v1[i1] = v1[i1b];
  double ans71[] = {2,3,4,1};
  vcompare(v1,ans71);

 
  v1[i1b] = v1[i1] + 100;
  double ans72[] = {101,102,103,104};
  vcompare(v1,ans72);


  v1[0] = 0;
  v1[1] = 1.0;
  v1[2] = 2.0;
  v1[3] = 3.0;
  v2[0] = 10;
  v2[1] = 11;
  v2[2] = 12;
  v2[3] = 100;
  v2[4] = 14;
  v2[5] = 15;
  i1[0] = 3;
  i1[1] = 2;
  i1[2] = 0;
  i1[3] = 1;
  i1b[0] = 0;
  i1b[1] = 1;
  i1b[2] = 2;
  i1b[3] = 3;
  i1c[0] = 3;
  i1c[1] = 0;
  i1c[2] = 1;
  i1c[3] = 2;
  v1[i1] = v1[i1b] + v2[i1c];
  double ans73[] = {13,15,11,100};
  vcompare(v1,ans73);


  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  i1[0] = 3;
  i1[1] = 3;
  i1[2] = 0;
  i1[3] = 1;
  v1 = 2*v1[i1];
  double ans74[] = {8,8,2,4};
  vcompare(v1,ans74);


  
  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  i1[0] = 3;
  i1[1] = 2;
  i1[2] = 0;
  i1[3] = 2;
  v1[i1] = 3*v1 +1;
  double ans75[] = {10,2,13,4};
  vcompare(v1,ans75);




  i1[0] = 5;
  i1[1] = 0;
  i1[2] = 1;
  i1[3] = 3;
  v3[0] = 110;
  v3[1] = -22;
  v3[2] = 33;
  v3[3] = -44;
  v3[4] = 1;
  v3[5] = 24;
  v3[6] = 101;
  v3[7] = 6;
  v1 = v3[findtrue(v3>20)];
  double ans80[] = {110,33,24,101};
  vcompare(v1,ans80);

  i1[0] = 5;
  i1[1] = 0;
  i1[2] = 1;
  i1[3] = 3;
  v3[0] = 110;
  v3[1] = -22;
  v3[2] = 33;
  v3[3] = -44;
  v3[4] = 1;
  v3[5] = 24;
  v3[6] = 101;
  v3[7] = 6;
  v1 = 99;
  v1[findtrue(range<unsigned int>(0,3)<2)] = v3[seq(1,2)];
  double ans81[] = {-22,33,99,99};
  vcompare(v1,ans81);

  v3.resize() = v3[findtrue(v3<0)];
  double ans82[] = {-22,-44};
  vcompare(v3,ans82);

  v3.resize(8);

  //////////////////////////////////////////////////////////

  // mask objects

  LAvector<bool> b1(4,"b1");
  LAvector<bool> b1b(4,"b1b");
  LAvector<bool> b2(6,"b2");
  LAvector<bool> b3(8,"b3");


  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  double ans100[] = {1,2,3,4};
  vcompare(v1,ans100);

  v2[0] = 10;
  v2[1] = 20;
  v2[2] = 30;
  v2[3] = 40;
  v2[4] = 50;
  v2[5] = 60;
  double ans101[] = {10,20,30,40,50,60};
  vcompare(v2,ans101);

  v3[0] = 11;
  v3[1] = 22;
  v3[2] = 33;
  v3[3] = 44;
  v3[4] = 55;
  v3[5] = 66;
  v3[6] = 77;
  v3[7] = 88;
  double ans102[] = {11,22,33,44,55,66,77,88};
  vcompare(v3,ans102);

  
  b3[0] = 1;
  b3[1] = 0;
  b3[2] = 1;
  b3[3] = 0;
  b3[4] = 0;
  b3[5] = 1;
  b3[6] = 1;
  b3[7] = 0;
  v1 = v3[b3];
  double ans110[] = {11,33,66,77};
  vcompare(v1,ans110);


  b2[0] = 1;
  b2[1] = 1;
  b2[2] = 1;
  b2[3] = 0;
  b2[4] = 0;
  b2[5] = 1;
  v1 = v2[b2];
  double ans111[] = {10,20,30,60};
  vcompare(v1,ans111);



  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  b1[0] = 0;
  b1[1] = 1;
  b1[2] = 1;
  b1[3] = 0;
  b2[0] = 0;
  b2[1] = 0;
  b2[2] = 0;
  b2[3] = 1;
  b2[4] = 0;
  b2[5] = 1;

  v1[b1] = v2[b2];
  double ans112[] = {1,40,60,4};
  vcompare(v1,ans112);



  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  b1[0] = 0;
  b1[1] = 0;
  b1[2] = 0;
  b1[3] = 0;
  b2[0] = 0;
  b2[1] = 0;
  b2[2] = 0;
  b2[3] = 0;
  b2[4] = 0;
  b2[5] = 0;
  v1[b1] = v2[b2];
  double ans113[] = {1,2,3,4};
  vcompare(v1,ans113);


  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  b1[0] = 1;
  b1[1] = 1;
  b1[2] = 1;
  b1[3] = 1;
  b2[0] = 0;
  b2[1] = 0;
  b2[2] = 1;
  b2[3] = 1;
  b2[4] = 1;
  b2[5] = 1;
  v1[b1] = v2[b2];
  double ans114[] = {30,40,50,60};
  vcompare(v1,ans114);



  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  b1[0] = 1;
  b1[1] = 1;
  b1[2] = 1;
  b1[3] = 1;
  v1 = v1[b1];
  double ans115[] = {1,2,3,4};
  vcompare(v1,ans115);

  b1[0] = 1;
  b1[1] = 0;
  b1[2] = 1;
  b1[3] = 0;
  v1[b1] = -1;
  double ans116[] = {-1,2,-1,4};
  vcompare(v1,ans116);



  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  b2[0] = 0;
  b2[1] = 0;
  b2[2] = 1;
  b2[3] = 1;
  b2[4] = 1;
  b2[5] = 1;
  v2[b2] = v1;
  double ans117[] = {10,20,1,2,3,4};
  vcompare(v2,ans117);

  b2[0] = 1;
  b2[1] = 0;
  b2[2] = 1;
  b2[3] = 1;
  b2[4] = 0;
  b2[5] = 1;
  v2[b2] = v1;
  double ans119[] = {1,20,2,3,3,4};
  vcompare(v2,ans119);


  
  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  b1[0] = 1;
  b1[1] = 1;
  b1[2] = 1;
  b1[3] = 1;
  v1[b1] = v1;
  double ans120[] = {1,2,3,4};
  vcompare(v1,ans120);


  v1 = v1[b1];
  double ans120b[] = {1,2,3,4};
  vcompare(v1,ans120b);


  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  b1[0] = 0;
  b1[1] = 1;
  b1[2] = 1;
  b1[3] = 0;
  b1b[0] = 1;
  b1b[1] = 1;
  b1b[2] = 0;
  b1b[3] = 0;
  v1[b1] = v1[b1b];
  double ans121[] = {1,1,2,4};
  vcompare(v1,ans121);

 
  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  v1[b1] = v1[b1b] + 100;
  double ans122[] = {1,101,102,4};
  vcompare(v1,ans122);
  

  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;
  v1[3] = 4;
  v2[0] = 10;
  v2[1] = 11;
  v2[2] = 12;
  v2[3] = 13;
  v2[4] = 97;
  v2[5] = 15;
  b1[0] = 0;
  b1[1] = 1;
  b1[2] = 1;
  b1[3] = 0;
  b1b[0] = 1;
  b1b[1] = 1;
  b1b[2] = 0;
  b1b[3] = 0;
  b2[0] = 0;
  b2[1] = 1;
  b2[2] = 0;
  b2[3] = 0;
  b2[4] = 1;
  b2[5] = 0;
  v1[b1] = v1[b1b] + v2[b2];
  double ans123[] = {1,12,99,4};
  vcompare(v1,ans123);




  b1[0] = 1;
  b1[1] = 1;
  b1[2] = 1;
  b1[3] = 1;
  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  v1 = 2*v1[b1];
  double ans124[] = {2,4,6,8};
  vcompare(v1,ans124);


  
  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  b1[0] = 1;
  b1[1] = 1;
  b1[2] = 1;
  b1[3] = 1;
  v1[b1] = 3*v1 +1;
  double ans125[] = {4,7,10,13};
  vcompare(v1,ans125);




  v3[0] = 110;
  v3[1] = -22;
  v3[2] = 33;
  v3[3] = -44;
  v3[4] = 1;
  v3[5] = 24;
  v3[6] = 101;
  v3[7] = 6;
  v1 = v3[v3>20];
  double ans130[] = {110,33,24,101};
  vcompare(v1,ans130);

  v3[0] = 110;
  v3[1] = -22;
  v3[2] = 33;
  v3[3] = -44;
  v3[4] = 1;
  v3[5] = 24;
  v3[6] = 101;
  v3[7] = 6;
  v1 = 99;
  v1[range<unsigned int>(0,3)<2] = v3[seq(1,2)];
  double ans131[] = {-22,33,99,99};
  vcompare(v1,ans131);

  v3.resize() = v3[v3<0];
  double ans132[] = {-22,-44};
  vcompare(v3,ans132);

  v3.resize(8);


  // range & set 

  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  double ans200[] = {1,2,3,4};
  vcompare(v1,ans200);

  v2[0] = 10;
  v2[1] = 20;
  v2[2] = 30;
  v2[3] = 40;
  v2[4] = 50;
  v2[5] = 60;
  double ans201[] = {10,20,30,40,50,60};
  vcompare(v2,ans201);

  v3[0] = 11;
  v3[1] = 22;
  v3[2] = 33;
  v3[3] = 44;
  v3[4] = 55;
  v3[5] = 66;
  v3[6] = 77;
  v3[7] = 88;
  double ans202[] = {11,22,33,44,55,66,77,88};
  vcompare(v3,ans202);

  
  i1[0] = 5;
  i1[1] = 0;
  i1[2] = 1;
  i1[3] = 3;
  v1[seq(3,0)] = v3[i1];
  double ans203[] = {44,22,11,66};
  vcompare(v1,ans203);


  i0[0] = 2;
  i0[1] = 6;
  v1[seq(1,2)] = v3[i0]/11 + 100;
  double ans204[] = {44,33.0/11.0+100.0,77.0/11.0+100.0};
  vcompare(v1,ans204);


  i1[0] = 1;
  i1[1] = 2;
  i1[2] = 0;
  i1[3] = 3;
  v1[i1] = v3[seq(1,7,2)];
  double ans205[] = {66,22,44,88};
  vcompare(v1,ans205);

  i1[0] = 1;
  i1[1] = 2;
  i1[2] = 0;
  i1[3] = 3;
  v1[i1] = v3[seq(0,3)] + v2[seq(2,5)];
  double ans206[] = {83,41,62,104};
  vcompare(v1,ans206);

  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  i1[0] = 1;
  i1[1] = 2;
  i1[2] = 0;
  i1[3] = 3;
  v1[i1] = v1[seq(3,0)];
  double ans207[] = {2,4,3,1};
  vcompare(v1,ans207);


  // range & mask

  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;

  b3[0] = 1;
  b3[1] = 0;
  b3[2] = 1;
  b3[3] = 0;
  b3[4] = 0;
  b3[5] = 1;
  b3[6] = 1;
  b3[7] = 0;
  v1[seq(3,0)] = v3[b3];
  double ans250[] = {77,66,33,11};
  vcompare(v1,ans250);


  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  b1[0] = 1;
  b1[1] = 0;
  b1[2] = 1;
  b1[3] = 0;
  v1[b1] = v3[seq(2,5,3)];
  double ans251[] = {33,2,66,4};
  vcompare(v1,ans251);


  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  b1[0] = 1;
  b1[1] = 1;
  b1[2] = 1;
  b1[3] = 1;
  v1 = v1[b1] + v3[seq(0,6,2)];
  double ans252[] = {12,35,58,81};
  vcompare(v1,ans252);




  // mask &set

  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;

  i1[0] = 1;
  i1[1] = 3;
  i1[2] = 2;
  i1[3] = 0;
  b3[0] = 0;
  b3[1] = 1;
  b3[2] = 1;
  b3[3] = 0;
  b3[4] = 1;
  b3[5] = 1;
  b3[6] = 0;
  b3[7] = 0;
  v1[i1] = v3[b3];
  double ans300[] = {66,22,55,33};
  vcompare(v1,ans300);


  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  i0[0] = 7;
  i0[1] = 3;
  b1[0] = 1;
  b1[1] = 0;
  b1[2] = 0;
  b1[3] = 1;
  v1[b1] = v3[i0];
  double ans301[] = {88,2,3,44};
  vcompare(v1,ans301);




  cout << "<vector access tests passed>"<<endl;
  return 0;

}
