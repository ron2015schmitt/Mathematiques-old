
// flag for run-time bounds and size checking
 


#include "cooll.hpp"
using namespace COOLL;

#include "testlib.hpp"

#include <iostream>
using namespace std;


#include <vector>


int main()
{

  Matrix<double> M1(2,2,"M1");
  Matrix<double> M2(3,2,"M2");
  Matrix<double> M3(4,2,"M3");


  // range objects

  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  double ans1[] = {1,2,3,4};
  mcompare(M1,ans1);

  M2(0) = 10;
  M2(1) = 20;
  M2(2) = 30;
  M2(3) = 40;
  M2(4) = 50;
  M2(5) = 60;
  double ans2[] = {10,20,30,40,50,60};
  mcompare(M2,ans2);

  M3(0) = 11;
  M3(1) = 22;
  M3(2) = 33;
  M3(3) = 44;
  M3(4) = 55;
  M3(5) = 66;
  M3(6) = 77;
  M3(7) = 88;
  double ans3[] = {11,22,33,44,55,66,77,88};
  mcompare(M3,ans3);

  
  M1 = mcast<double>(M3(seq(2,5)),2,2);
  double ans10[] = {33,44,55,66};
  mcompare(M1,ans10);

  M1 =mcast<double>(M3(seq(3,0)),2,2);
  double ans11[] = {44,33,22,11};
  mcompare(M1,ans11);


  M1 = mcast<double>(M3(seq(0,6,2)),2,2);
  double ans12[] = {11,33,55,77};
  mcompare(M1,ans12);


  Matrix<double> MX(2,1,"MX");

  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(seq(2,3)) = MX;
  double ans13a[] = {1,2,0,0};
  mcompare(M1,ans13a);


      
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(seq(2,3)) = M2(seq(3,1,-2));
  double ans13[] = {1,2,40,20};
  mcompare(M1,ans13);
  
   
  M1(seq(0,3)) = M1(seq(3,0));
  double ans14[] = {20,40,2,1};
  mcompare(M1,ans14);

  
  M1 = mcast<double>(M1(seq(3,0)),2,2);
  double ans15[] = {1,2,40,20};
  mcompare(M1,ans15);

  

  M1(seq(0,3,2)) = -1;
  double ans16[] = {-1,2,-1,20};
  mcompare(M1,ans16);

  
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M2(seq(5,2)) = M1(seq(0,3));
  double ans18[] = {10,20,4,3,2,1};
  mcompare(M2,ans18);
  
  M2(seq(2,5)) =  mcast<double>(M1,4,1);
  double ans19[] = {10,20,1,2,3,4};
  mcompare(M2,ans19);

  
  M1(seq(3,0)) = vcast<double>(M1);
  double ans20[] = {4,3,2,1};
  mcompare(M1,ans20);

  
  M1(seq(3,0,-1)) = M1(seq(0,3,1));
  double ans21[] = {1,2,3,4};
  mcompare(M1,ans21);


  M1(seq(3,0,-1)) = M1(seq(0,3,1)) + 100;
  double ans22[] = {104,103,102,101};
  mcompare(M1,ans22);



  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M2(0) = 10;
  M2(1) = 20;
  M2(2) = 30;
  M2(3) = 40;
  M2(4) = 50;
  M2(5) = 60;
  M1(seq(3,0,-1)) = M1(seq(0,3,1)) + M2(seq(2,5));
  double ans23[] = {64,53,42,31};
  mcompare(M1,ans23);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1 = mcast<double>(2*M1(seq(3,0)),2,2);
  double ans24[] = {8,6,4,2};
  mcompare(M1,ans24);

  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(seq(3,0)) = mcast<double>( 3*M1 +1, 4,1);
  double ans25[] = {13,10,7,4};
  mcompare(M1,ans25);

 
  
  //////////////////////////////////////////////////////////

  // set objects

  LAvector<unsigned int> i0(2,"i0");
  LAvector<unsigned int> i0b(2,"ib");
  LAvector<unsigned int> i1(4,"i1");
  LAvector<unsigned int> i1b(4,"i1b");
  LAvector<unsigned int> i1c(4,"i1c");
  LAvector<unsigned int> i2(6,"i2");
  LAvector<unsigned int> i3(8,"i3");

  
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  double ans50[] = {1,2,3,4};
  mcompare(M1,ans50);

  M2(0) = 10;
  M2(1) = 20;
  M2(2) = 30;
  M2(3) = 40;
  M2(4) = 50;
  M2(5) = 60;
  double ans51[] = {10,20,30,40,50,60};
  mcompare(M2,ans51);

  M3(0) = 11;
  M3(1) = 22;
  M3(2) = 33;
  M3(3) = 44;
  M3(4) = 55;
  M3(5) = 66;
  M3(6) = 77;
  M3(7) = 88;
  double ans52[] = {11,22,33,44,55,66,77,88};
  mcompare(M3,ans52);

  
  i1[0] = 5;
  i1[1] = 0;
  i1[2] = 1;
  i1[3] = 3;
  M1 = mcast<double>(M3(i1),2,2);
  double ans60[] = {66,11,22,44};
  mcompare(M1,ans60);

  
  i1[0] = 3;
  i1[1] = 2;
  i1[2] = 1;
  i1[3] = 0;
  M1 = mcast<double>(M3(i1),2,2);
  double ans61[] = {44,33,22,11};
  mcompare(M1,ans61);


 

 

  i0[0] = 5;
  i0[1] = 0;
  M1(seq(1,2)) = M2(i0);
  double ans62[] = {44,60,10,11};
  mcompare(M1,ans62);



  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  i0[0] = 1;
  i0[1] = 2;
  i0b[0] = 3;
  i0b[1] = 1;
  M1(i0) = M2(i0b);
  double ans63[] = {1,40,20,4};
  mcompare(M1,ans63);


  i1[0] = 0;
  i1[1] = 1;
  i1[2] = 2;
  i1[3] = 3;
  i1b[0] = 3;
  i1b[1] = 2;
  i1b[2] = 1;
  i1b[3] = 0;
  M1(i1) =  M1(i1b);
  double ans64[] = {4,20,40,1};
  mcompare(M1,ans64);


  M1 =  mcast<double>(M1(i1b),2,2);
  double ans65[] = {1,40,20,4};
  mcompare(M1,ans65);

  i0[0] = 0;
  i0[1] = 2;
  M1(i0) = -1;
  double ans66[] = {-1,40,-1,4};
  mcompare(M1,ans66);



  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  i1[0] = 5;
  i1[1] = 4;
  i1[2] = 3;
  i1[3] = 2;
  M2(i1) = vcast<double>(M1);
  double ans68[] = {10,20,4,3,2,1};
  mcompare(M2,ans68);

  i1 = i1[seq(3,0)];
  M2(i1) = mcast<double>(M1,4,1);
  double ans69[] = {10,20,1,2,3,4};
  mcompare(M2,ans69);

  i1[0] = 1;
  i1[1] = 1;
  i1[2] = 1;
  i1[3] = 1;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(i1) = vcast<double>(M1);
  double ans70[] = {1,4,3,4};
  mcompare(M1,ans70);


  i1[0] = 1;
  i1[1] = 1;
  i1[2] = 1;
  i1[3] = 1;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1 =  mcast<double>(M1(i1),2,2);
  double ans70b[] = {2,2,2,2};
  mcompare(M1,ans70b);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  i1[0] = 1;
  i1[1] = 3;
  i1[2] = 0;
  i1[3] = 2;
  i1b[0] = 2;
  i1b[1] = 0;
  i1b[2] = 1;
  i1b[3] = 3;
  M1(i1) = M1(i1b);
  double ans71[] = {2,3,4,1};
  mcompare(M1,ans71);

 
  M1(i1b) = M1(i1) + 100;
  double ans72[] = {101,102,103,104};
  mcompare(M1,ans72);


  M1(0) = 0;
  M1(1) = 1.0;
  M1(2) = 2.0;
  M1(3) = 3.0;
  M2(0) = 10;
  M2(1) = 11;
  M2(2) = 12;
  M2(3) = 100;
  M2(4) = 14;
  M2(5) = 15;
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
  M1(i1) = M1(i1b) + M2(i1c);
  double ans73[] = {13,15,11,100};
  mcompare(M1,ans73);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  i1[0] = 3;
  i1[1] = 3;
  i1[2] = 0;
  i1[3] = 1;
  M1 = mcast<double>(2*M1(i1),2,2);
  double ans74[] = {8,8,2,4};
  mcompare(M1,ans74);


  
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  i1[0] = 3;
  i1[1] = 2;
  i1[2] = 0;
  i1[3] = 2;
  M1(i1) = vcast<double>(3*M1 +1);
  double ans75[] = {10,2,13,4};
  mcompare(M1,ans75);




  i1[0] = 5;
  i1[1] = 0;
  i1[2] = 1;
  i1[3] = 3;
  M3(0) = 110;
  M3(1) = -22;
  M3(2) = 33;
  M3(3) = -44;
  M3(4) = 1;
  M3(5) = 24;
  M3(6) = 101;
  M3(7) = 6;
  
  M1(seq(0,3)) = M3(findtrue(M3>20));
  double ans80[] = {110,33,24,101};
  mcompare(M1,ans80);
  

  i1[0] = 5;
  i1[1] = 0;
  i1[2] = 1;
  i1[3] = 3;
  M3(0) = 110;
  M3(1) = -22;
  M3(2) = 33;
  M3(3) = -44;
  M3(4) = 1;
  M3(5) = 24;
  M3(6) = 101;
  M3(7) = 6;
  M1 = 99;

  
  M1(findtrue(range<unsigned int>(0,3)<2)) = M3(seq(1,2));
  double ans81[] = {-22,33,99,99};
  mcompare(M1,ans81);
  

  
  M3.resize() = M3(findtrue(M3<0));
  double ans82[] = {-22,-44};
  mcompare(M3,ans82);
  

  M3.resize(4,2);

  //////////////////////////////////////////////////////////

  // mask objects

  Matrix<bool> B1(2,2,"B1");
  Matrix<bool> B1b(2,2,"B1b");
  Matrix<bool> B2(3,2,"B2");
  Matrix<bool> B3(4,2,"B3");

  
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  double ans100[] = {1,2,3,4};
  mcompare(M1,ans100);

  M2(0) = 10;
  M2(1) = 20;
  M2(2) = 30;
  M2(3) = 40;
  M2(4) = 50;
  M2(5) = 60;
  double ans101[] = {10,20,30,40,50,60};
  mcompare(M2,ans101);

  M3(0) = 11;
  M3(1) = 22;
  M3(2) = 33;
  M3(3) = 44;
  M3(4) = 55;
  M3(5) = 66;
  M3(6) = 77;
  M3(7) = 88;
  double ans102[] = {11,22,33,44,55,66,77,88};
  mcompare(M3,ans102);

  
  B3(0) = 1;
  B3(1) = 0;
  B3(2) = 1;
  B3(3) = 0;
  B3(4) = 0;
  B3(5) = 1;
  B3(6) = 1;
  B3(7) = 0;
  M1 = mcast<double>(M3(B3),2,2);
  double ans110[] = {11,33,66,77};
  mcompare(M1,ans110);


  B2(0) = 1;
  B2(1) = 1;
  B2(2) = 1;
  B2(3) = 0;
  B2(4) = 0;
  B2(5) = 1;
  M1 = mcast<double>(M2(B2),2,2);
  double ans111[] = {10,20,30,60};
  mcompare(M1,ans111);



  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  B1(0) = 0;
  B1(1) = 1;
  B1(2) = 1;
  B1(3) = 0;
  B2(0) = 0;
  B2(1) = 0;
  B2(2) = 0;
  B2(3) = 1;
  B2(4) = 0;
  B2(5) = 1;

  M1(B1) = M2(B2);
  double ans112[] = {1,40,60,4};
  mcompare(M1,ans112);



  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  B1(0) = 0;
  B1(1) = 0;
  B1(2) = 0;
  B1(3) = 0;
  B2(0) = 0;
  B2(1) = 0;
  B2(2) = 0;
  B2(3) = 0;
  B2(4) = 0;
  B2(5) = 0;
  M1(B1) = M2(B2);
  double ans113[] = {1,2,3,4};
  mcompare(M1,ans113);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  B1(0) = 1;
  B1(1) = 1;
  B1(2) = 1;
  B1(3) = 1;
  B2(0) = 0;
  B2(1) = 0;
  B2(2) = 1;
  B2(3) = 1;
  B2(4) = 1;
  B2(5) = 1;
  M1(B1) = M2(B2);
  double ans114[] = {30,40,50,60};
  mcompare(M1,ans114);



  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  B1(0) = 1;
  B1(1) = 1;
  B1(2) = 1;
  B1(3) = 1;
  M1 = mcast<double>(M1(B1),2,2);
  double ans115[] = {1,2,3,4};
  mcompare(M1,ans115);

  B1(0) = 1;
  B1(1) = 0;
  B1(2) = 1;
  B1(3) = 0;
  M1(B1) = -1;
  double ans116[] = {-1,2,-1,4};
  mcompare(M1,ans116);



  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  B2(0) = 0;
  B2(1) = 0;
  B2(2) = 1;
  B2(3) = 1;
  B2(4) = 1;
  B2(5) = 1;
  M2(B2) = vcast<double>(M1);
  double ans117[] = {10,20,1,2,3,4};
  mcompare(M2,ans117);

  B2(0) = 1;
  B2(1) = 0;
  B2(2) = 1;
  B2(3) = 1;
  B2(4) = 0;
  B2(5) = 1;
  M2(B2) =  vcast<double>(M1);
  double ans119[] = {1,20,2,3,3,4};
  mcompare(M2,ans119);


  
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  B1(0) = 1;
  B1(1) = 1;
  B1(2) = 1;
  B1(3) = 1;
  M1(B1) =  vcast<double>(M1);
  double ans120[] = {1,2,3,4};
  mcompare(M1,ans120);


  M1 = mcast<double>(M1(B1),2,2);
  double ans120b[] = {1,2,3,4};
  mcompare(M1,ans120b);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  B1(0) = 0;
  B1(1) = 1;
  B1(2) = 1;
  B1(3) = 0;
  B1b(0) = 1;
  B1b(1) = 1;
  B1b(2) = 0;
  B1b(3) = 0;
  M1(B1) = M1(B1b);
  double ans121[] = {1,1,2,4};
  mcompare(M1,ans121);

 
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(B1) = M1(B1b) + 100;
  double ans122[] = {1,101,102,4};
  mcompare(M1,ans122);
  

  M1(0) = 1;
  M1(1) = 2;
  M1(2) = 3;
  M1(3) = 4;
  M2(0) = 10;
  M2(1) = 11;
  M2(2) = 12;
  M2(3) = 13;
  M2(4) = 97;
  M2(5) = 15;
  B1(0) = 0;
  B1(1) = 1;
  B1(2) = 1;
  B1(3) = 0;
  B1b(0) = 1;
  B1b(1) = 1;
  B1b(2) = 0;
  B1b(3) = 0;
  B2(0) = 0;
  B2(1) = 1;
  B2(2) = 0;
  B2(3) = 0;
  B2(4) = 1;
  B2(5) = 0;
  M1(B1) = M1(B1b) + M2(B2);
  double ans123[] = {1,12,99,4};
  mcompare(M1,ans123);




  B1(0) = 1;
  B1(1) = 1;
  B1(2) = 1;
  B1(3) = 1;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1 = mcast<double>(2*M1(B1),2,2);
  double ans124[] = {2,4,6,8};
  mcompare(M1,ans124);


  
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  B1(0) = 1;
  B1(1) = 1;
  B1(2) = 1;
  B1(3) = 1;
  M1(B1) = vcast<double>(3*M1 +1);
  double ans125[] = {4,7,10,13};
  mcompare(M1,ans125);




  M3(0) = 110;
  M3(1) = -22;
  M3(2) = 33;
  M3(3) = -44;
  M3(4) = 1;
  M3(5) = 24;
  M3(6) = 101;
  M3(7) = 6;
  M1 = mcast<double>(M3(M3>20),2,2);
  double ans130[] = {110,33,24,101};
  mcompare(M1,ans130);

  M3(0) = 110;
  M3(1) = -22;
  M3(2) = 33;
  M3(3) = -44;
  M3(4) = 1;
  M3(5) = 24;
  M3(6) = 101;
  M3(7) = 6;
  M1 = 99;
  M1(findtrue(range<unsigned int>(0,3)<2))= M3(seq(1,2));
  M1(seq(0,1)) = M3(seq(1,2));
  double ans131[] = {-22,33,99,99};
  mcompare(M1,ans131);

  M3.resize() = M3(M3<0);
  double ans132[] = {-22,-44};
  mcompare(M3,ans132);

  M3.resize(4,2);


  // range & set 

  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  double ans200[] = {1,2,3,4};
  mcompare(M1,ans200);

  M2(0) = 10;
  M2(1) = 20;
  M2(2) = 30;
  M2(3) = 40;
  M2(4) = 50;
  M2(5) = 60;
  double ans201[] = {10,20,30,40,50,60};
  mcompare(M2,ans201);

  M3(0) = 11;
  M3(1) = 22;
  M3(2) = 33;
  M3(3) = 44;
  M3(4) = 55;
  M3(5) = 66;
  M3(6) = 77;
  M3(7) = 88;
  double ans202[] = {11,22,33,44,55,66,77,88};
  mcompare(M3,ans202);

  
  i1[0] = 5;
  i1[1] = 0;
  i1[2] = 1;
  i1[3] = 3;
  M1(seq(3,0)) = M3(i1);
  double ans203[] = {44,22,11,66};
  mcompare(M1,ans203);


  i0[0] = 2;
  i0[1] = 6;
  M1(seq(1,2)) = M3(i0)/11 + 100;
  double ans204[] = {44,33.0/11.0+100.0,77.0/11.0+100.0,66};
  mcompare(M1,ans204);


  i1[0] = 1;
  i1[1] = 2;
  i1[2] = 0;
  i1[3] = 3;
  M1(i1) = M3(seq(1,7,2));
  double ans205[] = {66,22,44,88};
  mcompare(M1,ans205);

  i1[0] = 1;
  i1[1] = 2;
  i1[2] = 0;
  i1[3] = 3;
  M1(i1) = M3(seq(0,3)) + M2(seq(2,5));
  double ans206[] = {83,41,62,104};
  mcompare(M1,ans206);

  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  i1[0] = 1;
  i1[1] = 2;
  i1[2] = 0;
  i1[3] = 3;
  M1(i1) = M1(seq(3,0));
  double ans207[] = {2,4,3,1};
  mcompare(M1,ans207);


  // range & mask

  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;

  B3(0) = 1;
  B3(1) = 0;
  B3(2) = 1;
  B3(3) = 0;
  B3(4) = 0;
  B3(5) = 1;
  B3(6) = 1;
  B3(7) = 0;
  M1(seq(3,0)) = M3(B3);
  double ans250[] = {77,66,33,11};
  mcompare(M1,ans250);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  B1(0) = 1;
  B1(1) = 0;
  B1(2) = 1;
  B1(3) = 0;
  M1(B1) = M3(seq(2,5,3));
  double ans251[] = {33,2,66,4};
  mcompare(M1,ans251);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  B1(0) = 1;
  B1(1) = 1;
  B1(2) = 1;
  B1(3) = 1;
  M1 = mcast<double>(M1(B1) + M3(seq(0,6,2)),2,2);
  double ans252[] = {12,35,58,81};
  mcompare(M1,ans252);




  // mask &set

  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;

  i1[0] = 1;
  i1[1] = 3;
  i1[2] = 2;
  i1[3] = 0;
  B3(0) = 0;
  B3(1) = 1;
  B3(2) = 1;
  B3(3) = 0;
  B3(4) = 1;
  B3(5) = 1;
  B3(6) = 0;
  B3(7) = 0;
  M1(i1) = M3(B3);
  double ans300[] = {66,22,55,33};
  mcompare(M1,ans300);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  i0[0] = 7;
  i0[1] = 3;
  B1(0) = 1;
  B1(1) = 0;
  B1(2) = 0;
  B1(3) = 1;
  M1(B1) = M3(i0);
  double ans301[] = {88,2,3,44};
  mcompare(M1,ans301);


  

  cout << "<matrix access tests passed>"<<endl;
  return 0;

}
