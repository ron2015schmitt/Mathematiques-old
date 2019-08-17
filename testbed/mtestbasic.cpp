
// flag for run-time bounds and size checking
 


#import "matricks.hpp"
using namespace Matricks;

#import "testlib.hpp"

#import <iostream>
using namespace std;


#import <vector>


int main()
{
  double d;

  Matrix<double> M1(2,2,"M1");
  Matrix<double> M2(2,2,"M2");
  Matrix<double> M3(2,2,"M3");


  // Initialization tests
  M1(0,0) = 51;
  M1(0,1) = 52;
  M1(1,0) = 53;
  M1(1,1) = 54;
  double ans0[] = {51,52,53,54};
  mcompare(M1,ans0);
  M1=M1;
  mcompare(M1,ans0);

  M1(0) = 1;
  M1(1) = 2;
  M1(2) = 3;
  M1(3) = 4;
  double ans1[] = {1,2,3,4};
  mcompare(M1,ans1);
  
  M2 = 1;
  double ans1a[] = {1,1,1,1};
  mcompare(M2,ans1a);
  M2(0) = 100;
  M2(1) = 200;
  M2(2) = 300;
  M2(3) = 400;
  double ans1b[] = {100,200,300,400};
  mcompare(M2,ans1b);
  
  M3=M2;
  mcompare(M3,ans1b);



  // Matrix Arithmatic


  M3 = M1 + M2;
  double ans11[] = {101,202,303,404};
  mcompare(M3,ans11);

  M3 = M1 + M3;
  double ans11a[] = {102,204,306,408};
  mcompare(M3,ans11a);

  M3 = M2 - M1;
  double ans12[] = {99,198,297,396};
  mcompare(M3,ans12);

  M3 = M1 * M2;
  double ans13[] = {100,400,900,1600};
  mcompare(M3,ans13);

  M3 =  M2/M1;
  double ans14[] = {100,100,100,100};
  mcompare(M3,ans14);


  M3 =  M2/M1;
  double ans15[] = {100,100,100,100};
  mcompare(M3,ans15);

  M3 = 3*(M1+M2) + 1000;
  double ans16[] = {1303,1606,1909,2212};
  mcompare(M3,ans16);

  M3 = -200 + 100*M1;
  double ans17[] = {-100,0,100,200};
  mcompare(M3,ans17);


  // matrix scalar arithmatic

  M3 = 10+M2;
  double ans18[] = {110,210,310,410};
  mcompare(M3,ans18);
  M3 = M2+7;
  double ans19[] = {107,207,307,407};
  mcompare(M3,ans19);
  M3 = 13.0+M2;
  double ans20[] = {113,213,313,413};
  mcompare(M3,ans20);
  M3 = M2+7.5;
  double ans21[] = {107.5,207.5,307.5,407.5};
  mcompare(M3,ans21);

  M3 = 1000-M2;
  double ans22[] = {900,800,700,600};
  mcompare(M3,ans22);
  M3 = M2-11;
  double ans23[] = {89,189,289,389};
  mcompare(M3,ans23);
  M3 = 10.0-M2;
  double ans24[] = {-90,-190,-290,-390};
  mcompare(M3,ans24);
  M3 = M2-2.1;
  double ans25[] = {100-2.1,200-2.1,300-2.1,400-2.1};
  mcompare(M3,ans25);

  M3 = 6*M2;
  double ans26[] = {600,1200,1800,2400};
  mcompare(M3,ans26);
  M3 = M2*-3;
  double ans27[] = {-300,-600,-900,-1200};
  mcompare(M3,ans27);
  M3 = 11.0*M2;
  double ans28[] = {1100,2200,3300,4400};
  mcompare(M3,ans28);
  M3 = M2*2.0;
  double ans29[] = {200,400,600,800};
  mcompare(M3,ans29);

  M3 = 100/M2;
  double ans30[] = {1,1.0/2.0,1.0/3.0,1.0/4.0};
  mcompare(M3,ans30);
  M3 = M2/100;
  double ans31[] = {1,2,3,4};
  mcompare(M3,ans31);
  M3 = 1200.0/M2;
  double ans32[] = {12,6,4,3};
  mcompare(M3,ans32);
  M3 = M2/2.0;
  double ans33[] = {50,100,150,200};
  mcompare(M3,ans33);


  // unitary +/-
  M3 = +M1;
  double ans34[] = {1,2,3,4};
  mcompare(M3,ans34);
  M3 = -M2;
  double ans35[] = {-100,-200,-300,-400};
  mcompare(M3,ans35); 

  // min and max
  double ans39[] = {19,-5.0,103,100};
  M3 = mcast<double>(ans39,2,2);
  d = max(M3);
  compare(d,103.0);

  d = min(M3);
  compare(d,-5.0);

  // sum 

  d = sum(M3);
  compare(d,217.0);


  // resize 
  M3.resize(0,0);
  compare(int(M3.size()),0);

  M3.resize() = M1;
  compare(int(M3.size()),4);
  double ans40[] = {1,2,3,4};
  mcompare(M3,ans40);

  M3.resize() = M2-M1;
  compare(int(M3.size()),4);
  double ans41[] = {99,198,297,396};
  mcompare(M3,ans41);

  M3.resize();
  compare(int(M3.size()),4);
  mcompare(M3,ans41);

  M3.clear();
  compare(int(M3.size()),0);
  M3=M1;
  double ans41a[] = {1,2,3,4};
  mcompare(M3,ans41a);

  M3.clear();
  compare(int(M3.size()),0);
  M3=2*M1-2;
  double ans41b[] = {0,2,4,6};
  mcompare(M3,ans41b);





  Matrix<double> M5(2,1,"M5");
  "{{21,32},{43,54}}" >> M3;
#ifdef MATRICKS_DEBUG
  printcrcr("[A warning below indicates proper functionality.]");
#endif
  M5=M3;
  double ans50[] = {21.0, 32.0, 43.0, 54.0};
  mcompare(M5,ans50);

  M5.resize(3,4);
  unsigned int ans50a = 3;
  compare(M5.Nrows(),ans50a);
  unsigned int ans50b = 4;
  compare(M5.Ncols(),ans50b);
#ifdef MATRICKS_DEBUG
  printcrcr("[A warning below indicates proper functionality.]");
#endif
  M5=2.0*M3;
  double ans51[] = {21.0*2.0, 32.0*2.0, 43.0*2.0, 54.0*2.0};
  mcompare(M5,ans51);
  unsigned int ans50c = 2;
  compare(M5.Nrows(),ans50c);
  unsigned int ans50d = 2;
  compare(M5.Ncols(),ans50d);
   


  cout << "<Basic matrix tests 1 passed>"<<endl;
  return 0;


}
