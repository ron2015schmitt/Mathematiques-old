
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

  Matrix<double> A1(4,3,"A1");
  Matrix<double> A2(4,3,"A2");
  Matrix<double> A3(4,3,"A3");
  Matrix<double> B1(3,4,"B1");
  Matrix<double> B2(3,4,"B2");
  Matrix<double> B3(3,4,"B3");

  Matrix<double> C33(3,3,"C33");
  Matrix<double> C44(4,4,"C44");


  // Initialization tests
  A1(0,0) = 1;
  A1(0,1) = 2;
  A1(0,2) = 3;
  A1(1,0) = 4;
  A1(1,1) = 5;
  A1(1,2) = 6;
  A1(2,0) = 7;
  A1(2,1) = 8;
  A1(2,2) = 9;
  A1(3,0) = 10;
  A1(3,1) = 11;
  A1(3,2) = 12;
  double ans0[] = {1,2,3,4,5,6,7,8,9,10,11,12};
  mcompare(A1,ans0);

  A2(0) = 11;
  A2(1) = -3;
  A2(2) = 3;
  A2(3) = 0;
  A2(4) = 41;
  A2(5) = -100;
  A2(6) = 36;
  A2(7) = 2;
  A2(8) = 34;
  A2(9) = 7;
  A2(10) = 30;
  A2(11) = -4;
  double ans1[] = {11,-3,3,0,41,-100,36,2,34,7,30,-4};
  mcompare(A2,ans1);
  A3 = 5.5;
  double ans1a[] = {5.5,5.5,5.5,5.5,5.5,5.5,5.5,5.5,5.5,5.5,5.5,5.5};
  mcompare(A3,ans1a);



  // min and max
  d = min(A2);
  compare(d,-100.0);
  d = max(A2);
  compare(d,41.0);
 
  LAvector<double> v3(3);
  LAvector<double> v4(4);
  v4 = minbyrow(A2);
  double ans10[] = {-3,-100,2,-4};
  vcompare(v4,ans10);
  v4 = maxbyrow(A2);
  double ans11[] = {11,41,36,30};
  vcompare(v4,ans11);
  v3 = minbycol(A2);
  double ans12[] = {0,-3,-100};
  vcompare(v3,ans12);
  v3 = maxbycol(A2);
  double ans13[] = {36,41,34};
  vcompare(v3,ans13);
 
  // sum 

  d = sum(A2);
  double ans20 = 11 + -3 + 3 + 0 + 41 + -100 + 36 + 2 + 34 + 7 + 30 + -4;
  compare(d,ans20);
  v4 = sumbyrow(A2);
  double ans21[] = {11+-3+3,0+41-100,36+2+34,7+30-4};
  vcompare(v4,ans21);
  v3 = sumbycol(A2);
  double ans22[] = {11+0+36+7,-3+41+2+30,3-100+34-4};
  vcompare(v3,ans22);

  //transpose

  B1 = ~A2 + ~A1;
  double ans30[] = {12,4,43,17,-1,46,10,41,6,-94,43,8  };
  mcompare(B1,ans30);


  B1 = ~(A1+A2)+1;
  double ans31[] = {13,5,44,18,0,47,11,42,7,-93,44,9  };
  mcompare(B1,ans31);


  //trace 

  d = tr(A1);
  compare(d,15.0);
  d = tr(B1);
  compare(d,104.0);

  // dot product

  B1(2,2)=49;


  C33 = (B1|A1);
  double ans40[] = {521,601,681,685,785,885,68,40,12 };
  mcompare(C33,ans40);

  C33 = 0;
  C33 = ~(~A1|~B1);
  double ans41[] = {521,601,681,685,785,885,68,40,12 };
  mcompare(C33,ans41);

  C33 = ~C33;
  double ans32[] = {521,685,68,601,785,40,681,885,12  };
  mcompare(C33,ans32);


  C44 = (A2|B1);
  double ans42[] = {164,-365,598,99,-700,11227,-4449,822,706,-2888,3272,1038,63,1817,442,1350};
  mcompare(C44,ans42);


  C33(0,0) = -5;
  C33(0,1) = 601;
  C33(0,2) = 681;
  C33(1,0) = 685;
  C33(1,1) = 785;
  C33(1,2) = 885;
  C33(2,0) = -68;
  C33(2,1) = 4;
  C33(2,2) = 12;
  double ans43[] = {365402,471504,536652,474120,1031450,1171830,2264,-37680,-42624};
  C33=(C33|C33);
  mcompare(C33,ans43);


  // reshape

  C33.reshape(9,1);
  C33(1,0) = 2;
  C33(3,0) = 4;
  double ans50[] = {365402,2,536652,4,1031450,1171830,2264,-37680,-42624};
  mcompare(C33,ans50);
  C33.reshape(1,9);
  C33(0,7) = 8;
  C33(0,0) = 0;
  double ans51[] = {0,2,536652,4,1031450,1171830,2264,8,-42624};
  mcompare(C33,ans51);

  A1.reshape(6,2);
  A1(3,1)= -88;
  double ans53[] = {1,2,3,4,5,6,7,-88,9,10,11,12};
  mcompare(A1,ans53);


  // casting

  A1(2,1)= -66;
  Matrix<int> MI1 = mcast<int>(A1);
  int ans60[] = {1,2,3,4,5,-66,7,-88,9,10,11,12};
  mcompare(MI1,ans60);


  
  A3=0;
  LAvector<double> v1(12);
  v1[0] = 11;
  v1[1] = -3;
  v1[2] = 3;
  v1[3] = 0;
  v1[4] = 41;
  v1[5] = 99;
  v1[6] = 36;
  v1[7] = 2;
  v1[8] = 34;
  v1[9] = 7;
  v1[10] = 30;
  v1[11] = -4;
  double ans61[] = {11,-3,3,0,41,99,36,2,34,7,30,-4};
  A3=mcast<double>(v1,4,3);
  mcompare(A3,ans61);


  double ans62[] = {11,22,33,44,55,66,77,88,99,1010,1111,1212};
  B3=mcast<double>(ans62,3,4);
  mcompare(B3,ans62);

  B3=0;
  double ans63[3][4] = 
    { {1,2,3,4},
      {11,22,33,44},
      {111,222,333,444}};
  B3=mcast<double>(&ans63[0][0],3,4);
  double ans63b[] = {1,2,3,4,11,22,33,44,111,222,333,444};
  mcompare(B3, ans63b );


  
  B3=0;
  double ans64[] = {1,2,3,40,11,22,33,44,111,2221,333,444};
  B3=mcastF<double>(&ans64[0],3,4);
  A3=~B3;
  double ans64b[] = {1,2,3,40,11,22,33,44,111,2221,333,444};
  mcompare(A3, ans64b );


  // converting matrices to other objects

  double* ptr1;
  ptr1 = toCarray<double>(A1);
  double ans70[] = {1,2,3,4,5,-66,7,-88,9,10,11,12};
  vcompare(ptr1,ans70);

  ptr1 = toFarray<double>(A1);
  double ans71[] = {1,3,5,7,9,11,2,4,-66,-88,10,12};
  vcompare(ptr1,ans71);


  // inplace transpose
  C33.reshape(3,3);
  C33(0,0) = -5;
  C33(0,1) = 601;
  C33(0,2) = 681;
  C33(1,0) = 685;
  C33(1,1) = 785;
  C33(1,2) = 885;
  C33(2,0) = -68;
  C33(2,1) = 4;
  C33(2,2) = 12;

  double ans80[] = {-5,601,681,685,785,885,-68,4,12};
  mcompare(C33,ans80);

  C33.transpose();
  compare(int(C33.size()),9);
  compare(int(C33.Nrows()),3);
  compare(int(C33.Ncols()),3);
  double ans81[] = {-5,685,-68,601,785,4,681,885,12};
  mcompare(C33,ans81);

  C33.transpose();
  compare(int(C33.size()),9);
  compare(int(C33.Nrows()),3);
  compare(int(C33.Ncols()),3);
  mcompare(C33,ans80);


  A1.reshape(4,3);
  A1(0,0) = 1;
  A1(0,1) = 2;
  A1(0,2) = 3;
  A1(1,0) = 4;
  A1(1,1) = 5;
  A1(1,2) = 6;
  A1(2,0) = 7;
  A1(2,1) = 8;
  A1(2,2) = 9;
  A1(3,0) = 10;
  A1(3,1) = 11;
  A1(3,2) = 12;
  double ans83[] = {1,2,3,4,5,6,7,8,9,10,11,12};
  mcompare(A1,ans83);

  A1.transpose();
  compare(int(A1.size()),12);
  compare(int(A1.Nrows()),3);
  compare(int(A1.Ncols()),4);
  double ans84[] = {1,4,7,10,2,5,8,11,3,6,9,12};
  mcompare(A1,ans84);

  A1.transpose();
  compare(int(A1.size()),12);
  compare(int(A1.Nrows()),4);
  compare(int(A1.Ncols()),3);
  mcompare(A1,ans83);


  cout << "<Basic matrix tests 2 passed>"<<endl;
  return 0;


}
