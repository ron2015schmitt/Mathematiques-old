
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
  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  double ans1[] = {1,2,3,4};
  vcompare(v1,ans1);
  v1=v1;
  vcompare(v1,ans1);
  
  v2 = 1;
  double ans1a[] = {1,1,1,1};
  vcompare(v2,ans1a);

  v2 = range<double>(5,8);
  double ans2[] = {5,6,7,8};
  vcompare(v2,ans2);

  v2 = range<double>(4,1);
  double ans3[] = {4,3,2,1};
  vcompare(v2,ans3);

  v2 = range<double>(400,100,-100);
  double ans4[] = {400,300,200,100};
  vcompare(v2,ans4);

  v3=v2;
  vcompare(v3,ans4);



  v2 = linspace<double>(100,400,4);
  double ans5[] = {100,200,300,400};
  vcompare(v2,ans5);

  v2 = linspace<double>(6,3,4);
  double ans6[] = {6,5,4,3};
  vcompare(v2,ans6);



  // Casting Operations

  double ans7[4] = {1.234, 101.3, 0, -23.4};
  v2 = vcast<double>(ans7,4);
  vcompare(v2,ans7);

  vector<double> vstd(4);
  vstd[0] = -1;
  vstd[1] = -2;
  vstd[2] = -3;
  vstd[3] = -4;
  v2 = vcast<double>(vstd);
  double ans8[] = {-1,-2,-3,-4};
  vcompare(v2,ans8);

  valarray<double> val(4);
  val[0] = -11;
  val[1] = -12;
  val[2] = -13;
  val[3] = -14;
  v2 = vcast<double>(val);
  double ans9[] = {-11,-12,-13,-14};
  vcompare(v2,ans9);

  v2 = range<double>(100,400,100);
  double ans10[] = {100,200,300,400};
  vcompare(v2,ans10);

  LAvector<int> vi1(4);
  vi1[0]= 23;
  vi1[1]= 20;
  vi1[2]= 34;
  vi1[3]= 100;
  v3 = vcast<double>(vi1);
  double ans10a[] = {23,20,34,100};
  vcompare(v3,ans10a);
  vi1 = vcast<int>(v3+1);
  int ans10b[] = {24,21,35,101};
  vcompare(vi1,ans10b);

  LAvector<extended> ve1(4);
  ve1 = vcast<extended>(v3*2);
  extended ans10c[] = {46,40,68,200};
  vcompare(ve1,ans10c);

  Matrix<double> M2(2,2);
  M2(0) = 100;
  M2(1) = -200;
  M2(2) = 300;
  M2(3) = -100;
  v3=vcast<double>(M2);
  double ans10f[] = {100,-200,300,-100};
  vcompare(v3,ans10f);

  // Vector Arithmatic


  v3 = v1 + v2;
  double ans11[] = {101,202,303,404};
  vcompare(v3,ans11);

  v3 = v1 + v3;
  double ans11a[] = {102,204,306,408};
  vcompare(v3,ans11a);

  v3 = v2 - v1;
  double ans12[] = {99,198,297,396};
  vcompare(v3,ans12);

  v3 = v1 * v2;
  double ans13[] = {100,400,900,1600};
  vcompare(v3,ans13);

  v3 =  v2/v1;
  double ans14[] = {100,100,100,100};
  vcompare(v3,ans14);


  v3 =  v2/v1;
  double ans15[] = {100,100,100,100};
  vcompare(v3,ans15);

  v3 = 3*(v1+v2) + 1000;
  double ans16[] = {1303,1606,1909,2212};
  vcompare(v3,ans16);

  v3 = -200 + 100*v1;
  double ans17[] = {-100,0,100,200};
  vcompare(v3,ans17);


  // vector scalar arithmatic

  v3 = 10+v2;
  double ans18[] = {110,210,310,410};
  vcompare(v3,ans18);
  v3 = v2+7;
  double ans19[] = {107,207,307,407};
  vcompare(v3,ans19);
  v3 = 13.0+v2;
  double ans20[] = {113,213,313,413};
  vcompare(v3,ans20);
  v3 = v2+7.5;
  double ans21[] = {107.5,207.5,307.5,407.5};
  vcompare(v3,ans21);

  v3 = 1000-v2;
  double ans22[] = {900,800,700,600};
  vcompare(v3,ans22);
  v3 = v2-11;
  double ans23[] = {89,189,289,389};
  vcompare(v3,ans23);
  v3 = 10.0-v2;
  double ans24[] = {-90,-190,-290,-390};
  vcompare(v3,ans24);
  v3 = v2-2.1;
  double ans25[] = {100-2.1,200-2.1,300-2.1,400-2.1};
  vcompare(v3,ans25);

  v3 = 6*v2;
  double ans26[] = {600,1200,1800,2400};
  vcompare(v3,ans26);
  v3 = v2*-3;
  double ans27[] = {-300,-600,-900,-1200};
  vcompare(v3,ans27);
  v3 = 11.0*v2;
  double ans28[] = {1100,2200,3300,4400};
  vcompare(v3,ans28);
  v3 = v2*2.0;
  double ans29[] = {200,400,600,800};
  vcompare(v3,ans29);

  v3 = 100/v2;
  double ans30[] = {1,1.0/2.0,1.0/3.0,1.0/4.0};
  vcompare(v3,ans30);
  v3 = v2/100;
  double ans31[] = {1,2,3,4};
  vcompare(v3,ans31);
  v3 = 1200.0/v2;
  double ans32[] = {12,6,4,3};
  vcompare(v3,ans32);
  v3 = v2/2.0;
  double ans33[] = {50,100,150,200};
  vcompare(v3,ans33);


  // unitary +/-
  v3 = +v1;
  double ans34[] = {1,2,3,4};
  vcompare(v3,ans34);
  v3 = -v2;
  double ans35[] = {-100,-200,-300,-400};
  vcompare(v3,ans35); 

  // converting to STL containers
  int* vc1; 
  v3 = 1+v2/2;
  vc1 = toCarray<int>(v3);
  double ans36[] = {51,101,151,201};
  vcompare(vc1,ans36);
  delete [] vc1;

  std::vector<float> vs2(4); 
  v3 = 2*(-v2);
  vs2 = tostdvector<float>(v3);
  double ans37[] = {-200,-400,-600,-800};
  vcompare(vs2,ans37);

  std::valarray<double> va1(4); 
  v3 = v1+3.5;
  va1 = tovalarray<double>(v3);
  double ans38[] = {1+3.5,2+3.5,3+3.5,4+3.5};
  vcompare(va1,ans38);


  // dot product

  double d = (v1|v2);
  compare(d,3000.0);

  d = (v1|v1+3*v2) + 1.0;
  double a1 = 1+4+9+16+3*(100+400+900+1600) +1.0;
  compare(d,a1);

  // min and max
  
  double ans39[] = {19,-5.0,103,100};
  v3 = vcast<double>(ans39,4);
  d = max(v3);
  compare(d,103.0);

  d = min(v3);
  compare(d,-5.0);

  // sum & norm

  d = sum(v3);
  compare(d,217.0);

  d = norm(v1);
  double a2 = sqrt(1.0*1.0 + 2.0*2.0 + 3.0*3.0 +4.0*4.0);
  compare(d,a2);


  // resize 
  v3.resize(0);
  compare(int(v3.size()),0);

  v3.resize() = v1;
  compare(int(v3.size()),4);
  double ans40[] = {1,2,3,4};
  vcompare(v3,ans40);

  v3.resize() = v2-v1;
  compare(int(v3.size()),4);
  double ans41[] = {99,198,297,396};
  vcompare(v3,ans41);

  v3.resize();
  compare(int(v3.size()),4);
  vcompare(v3,ans41);

  v3.clear();
  compare(int(v3.size()),0);
  v3=v1;
  double ans41a[] = {1,2,3,4};
  vcompare(v3,ans41a);

  v3.clear();
  compare(int(v3.size()),0);
  v3=2*v1-2;
  double ans41b[] = {0,2,4,6};
  vcompare(v3,ans41b);

  // sort
  double ans42a[] = {101,1002,-3,-4};
  v3 = vcast<double>(ans42a,4);
  vcompare(v3,ans42a);
  sort(v3);
  double ans42b[] = {-4,-3,101,1002};
  vcompare(v3,ans42b);

  double ans43a[] = {21.1,-7,34.4,0};
  v3 = vcast<double>(ans43a,4);
  vcompare(v3,ans43a);
  LAvector<unsigned int> vi3 = sortwind(v3);
  double ans43b[] = {-7,0,21.1,34.4};
  vcompare(v3,ans43b);
  unsigned int ans43c[] = {1,3,0,2};
  vcompare(vi3,ans43c);



 
  LAvector<double> v5(2,"v5");
  "{21,32,43,54}" >> v3;
#ifdef MATRICKS_DEBUG
  printcrcr("[A warning below indicates proper functionality.]");
#endif
  v5=v3;
  double ans50[] = {21.0, 32.0, 43.0, 54.0};
  vcompare(v5,ans50);

  v5.resize(7);
  unsigned int ans50a = 7;
  compare(v5.size(),ans50a);
#ifdef MATRICKS_DEBUG
  printcrcr("[A warning below indicates proper functionality.]");
#endif
  v5=2.0*v3;
  double ans51[] = {21.0*2.0, 32.0*2.0, 43.0*2.0, 54.0*2.0};
  vcompare(v5,ans51);
  

  cout << "<Basic vector tests passed>"<<endl;
  return 0;



}
