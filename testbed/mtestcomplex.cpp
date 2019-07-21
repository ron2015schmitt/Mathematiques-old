
// flag for run-time bounds and size checking
 


#include "cooll.hpp"
using namespace COOLL;

#include "testlib.hpp"

#include <iostream>
using namespace std;


#include <vector>
#include <complex>
#include <cmath>


int main()
{
  typedef complex<double> cd;

  Matrix<cd> M1(2,2,"M1");
  Matrix<cd> M2(2,2,"M2");
  Matrix<cd> M3(2,2,"M3");



  // Initialization tests
  M1(0,0) =  cd(1,-1);
  M1(0,1) =  complex<double>(2,-2);
  M1(1,0) =  complex<double>(3,-3);
  M1(1,1) = complex<double>(4,-4);

  cd ans1[] = {cd(1,-1),cd(2,-2),cd(3,-3), cd(4,-4)};
  mcompare(M1,ans1);


  M2 = cd(3,2);
  cd ans1a[] = {cd(3,2),cd(3,2),cd(3,2),cd(3,2)};
  mcompare(M2,ans1a);


  M2(0) = cd(10,100);
  M2(1) = cd(20,200);
  M2(2) = cd(30,300);
  M2(3) = cd(40,400);
  cd ans9[] =  { cd(10,100),cd(20,200),cd(30,300),cd(40,400) };
  mcompare(M2,ans9);


  Matrix<double> MR1(2,2,"MR1");
  Matrix<double> MR2(2,2,"MR2");


  MR1(0) = 11;
  MR1(1) = 22;
  MR1(2) = 33;
  MR1(3) = 44;
  MR2(0) = -100;
  MR2(1) = -200;
  MR2(2) = -300;
  MR2(3) = -400;


  M3 = mcomplex(MR1,MR2);
  cd ans1b[] = {cd(11,-100),cd(22,-200),cd(33,-300),cd(44,-400)};
  mcompare(M3,ans1b);

  MR1(0) = 1;
  MR1(1) = 2;
  MR1(2) = 3;
  MR1(3) = 4;
  MR2(0) = 0;
  MR2(1) = M_PI_4;
  MR2(2) = M_PI_2;
  MR2(3) = M_PI;
  
  M3 = mpolar(MR1,MR2);
  cd ans1c[] = {polar(1.0,0.0),polar(2.0,M_PI_4),polar(3.0,M_PI_2),polar(4.0,M_PI)};
  mcompare(M3,ans1c);
  

  M3 = mcomplex(MR1,5.0);
  cd ans1d[] = {cd(1,5),cd(2,5),cd(3,5),cd(4,5)};
  mcompare(M3,ans1d);

  M3 = mcomplex(MR1,13);
  cd ans1e[] = {cd(1,13),cd(2,13),cd(3,13),cd(4,13)};
  mcompare(M3,ans1e);

  M3 = mcomplex(7.5,MR1);
  cd ans1f[] = {cd(7.5,1),cd(7.5,2),cd(7.5,3),cd(7.5,4)};
  mcompare(M3,ans1f);

  M3 = mcomplex(21,MR1);
  cd ans1g[] = {cd(21,1),cd(21,2),cd(21,3),cd(21,4)};
  mcompare(M3,ans1g);
 


  // addition

  M3 = M1 + M2;
  cd ans11[] = { cd(11,99),cd(22,198),cd(33,297),cd(44,396)};
  mcompare(M3,ans11);
  M3 = M1 + MR1;
  cd ans12[] = { cd(2,-1),cd(4,-2),cd(6,-3),cd(8,-4)};
  mcompare(M3,ans12);
  M3 = MR1 + M2;
  cd ans13[] = { cd(11,100),cd(22,200),cd(33,300),cd(44,400)};
  mcompare(M3,ans13);

  M3 = M1 + cd(1,1);
  cd ans14[] = { cd(2,0),cd(3,-1),cd(4,-2),cd(5,-3)};
  mcompare(M3,ans14);
  M3 = cd(20,40) + M2;
  cd ans15[] = { cd(30,140),cd(40,240),cd(50,340),cd(60,440)};
  mcompare(M3,ans15);

  M3 = M1 + 20;
  cd ans16[] = { cd(21,-1),cd(22,-2),cd(23,-3),cd(24,-4)};
  mcompare(M3,ans16);
  M3 = M1 + 101.5;
  cd ans17[] = { cd(1+101.5,-1),cd(2+101.5,-2),cd(3+101.5,-3),cd(4+101.5,-4)};
  mcompare(M3,ans17);
  M3 = 30 + M1;
  cd ans18[] = { cd(31,-1),cd(32,-2),cd(33,-3),cd(34,-4)};
  mcompare(M3,ans18);
  M3 = 33.0 + M1;
  cd ans19[] = { cd(34,-1),cd(35,-2),cd(36,-3),cd(37,-4)};
  mcompare(M3,ans19);

  M3 = MR1 + cd(1,1);
  cd ans19a[] = { cd(2,1),cd(3,1),cd(4,1),cd(5,1)};
  mcompare(M3,ans19a);
  M3 = cd(20,40) + MR1;
  cd ans19b[] = { cd(21,40),cd(22,40),cd(23,40),cd(24,40)};
  mcompare(M3,ans19b);


  // subtraction

  M3 = M2 - M1;
  cd ans20[] = { cd(9,101),cd(18,202),cd(27,303),cd(36,404)};
  mcompare(M3,ans20);
  M3 = M2 - MR1;
  cd ans21[] = { cd(9,100),cd(18,200),cd(27,300),cd(36,400)};
  mcompare(M3,ans21);
  M3 = MR1 - M1;
  cd ans22[] = { cd(0,1),cd(0,2),cd(0,3),cd(0,4)};
  mcompare(M3,ans22);

  M3 = M2 - cd(3,4);
  cd ans23[] = { cd(7,96),cd(17,196),cd(27,296),cd(37,396)};
  mcompare(M3,ans23);
  M3 = cd(100,400) - M2;
  cd ans24[] = { cd(90,300),cd(80,200),cd(70,100),cd(60,0)};
  mcompare(M3,ans24);

  M3 = M1 - 2;
  cd ans25[] = { cd(-1,-1),cd(0,-2),cd(1,-3),cd(2,-4)};
  mcompare(M3,ans25);
  M3 = M1 - 1.0;
  cd ans26[] = { cd(0,-1),cd(1,-2),cd(2,-3),cd(3,-4)};
  mcompare(M3,ans26);
  M3 = 30 - M1;
  cd ans27[] = { cd(29,1),cd(28,2),cd(27,3),cd(26,4)};
  mcompare(M3,ans27);
  M3 = 44.0 - M1;
  cd ans28[] = { cd(43,1),cd(42,2),cd(41,3),cd(40,4)};
  mcompare(M3,ans28);

  M3 = MR1 - cd(1,1);
  cd ans28a[] = { cd(0,-1),cd(1,-1),cd(2,-1),cd(3,-1)};
  mcompare(M3,ans28a);
  M3 = cd(20,40) - MR1;
  cd ans28b[] = { cd(19,40),cd(18,40),cd(17,40),cd(16,40)};
  mcompare(M3,ans28b);


  // multiplication

  M3 = M1 * M2;
  cd ans29[] = {cd(1,-1)*cd(10,100),cd(2,-2)*cd(20,200),cd(3,-3)*cd(30,300),cd(4,-4)*cd(40,400)};
  mcompare(M3,ans29);
  M3 = MR1 * M2;
  cd ans30[] = {1.0*cd(10,100),2.0*cd(20,200),3.0*cd(30,300),4.0*cd(40,400)};
  mcompare(M3,ans30);
  M3 = M1 * MR1;
  cd ans31[] = {cd(1,-1)*1.0,cd(2,-2)*2.0,cd(3,-3)*3.0,cd(4,-4)*4.0};
  mcompare(M3,ans31);


  M3 = M2 * cd(3,4);
  cd ans32[] = {cd(3,4)*cd(10,100),cd(3,4)*cd(20,200),cd(3,4)*cd(30,300),cd(3,4)*cd(40,400)};
  mcompare(M3,ans32);
  M3 = cd(1.5,2) * M2;
  cd ans33[] = {cd(1.5,2)*cd(10,100),cd(1.5,2)*cd(20,200),cd(1.5,2)*cd(30,300),cd(1.5,2)*cd(40,400)};
  mcompare(M3,ans33);


  M3 = M1 * 2;
  cd ans34[] = {cd(1,-1)*2.0,cd(2,-2)*2.0,cd(3,-3)*2.0,cd(4,-4)*2.0};
  mcompare(M3,ans34);
  M3 = M1 * 1.5;
  cd ans35[] = {cd(1,-1)*1.5,cd(2,-2)*1.5,cd(3,-3)*1.5,cd(4,-4)*1.5};
  mcompare(M3,ans35);
  M3 = 3 * M1;
  cd ans36[] = {cd(1,-1)*3.0,cd(2,-2)*3.0,cd(3,-3)*3.0,cd(4,-4)*3.0};
  mcompare(M3,ans36);
  M3 = 4.4*  M1;
  cd ans37[] = {cd(1,-1)*4.4,cd(2,-2)*4.4,cd(3,-3)*4.4,cd(4,-4)*4.4};
  mcompare(M3,ans37);


  M3 = MR1 * cd(1,2);
  cd ans37a[] = { 1.0*cd(1,2),2.0*cd(1,2),3.0*cd(1,2),4.0*cd(1,2)};
  mcompare(M3,ans37a);
  M3 = cd(20,40) * MR1;
  cd ans37b[] = { 1.0*cd(20,40),2.0*cd(20,40),3.0*cd(20,40),4.0*cd(20,40)};
  mcompare(M3,ans37b);


  // division

  M3 = M1 / M2;
  cd ans40[] = {cd(1,-1)/cd(10,100),cd(2,-2)/cd(20,200),cd(3,-3)/cd(30,300),cd(4,-4)/cd(40,400)};
  mcompare(M3,ans40);
  M3 = MR1 / M2;
  cd ans41[] = {1.0/cd(10,100),2.0/cd(20,200),3.0/cd(30,300),4.0/cd(40,400)};
  mcompare(M3,ans41);
  M3 = M1 / MR1;
  cd ans42[] = {cd(1,-1)/1.0,cd(2,-2)/2.0,cd(3,-3)/3.0,cd(4,-4)/4.0};
  mcompare(M3,ans42);


  M3 = M2 / cd(3,4);
  cd ans43[] = {cd(10,100)/cd(3,4),cd(20,200)/cd(3,4),cd(30,300)/cd(3,4),cd(40,400)/cd(3,4)};
  mcompare(M3,ans43);
  M3 = cd(1.5,2) / M2;
  cd ans44[] = {cd(1.5,2)/cd(10,100),cd(1.5,2)/cd(20,200),cd(1.5,2)/cd(30,300),cd(1.5,2)/cd(40,400)};
  mcompare(M3,ans44);


  M3 = M1 / 2;
  cd ans45[] = {cd(1,-1)/2.0,cd(2,-2)/2.0,cd(3,-3)/2.0,cd(4,-4)/2.0};
  mcompare(M3,ans45);
  M3 = M1 / 1.5;
  cd ans46[] = {cd(1,-1)/1.5,cd(2,-2)/1.5,cd(3,-3)/1.5,cd(4,-4)/1.5};
  mcompare(M3,ans46);
  M3 = 3 / M1;
  cd ans47[] = {3.0/cd(1,-1),3.0/cd(2,-2),3.0/cd(3,-3),3.0/cd(4,-4)};
  mcompare(M3,ans47);
  M3 = 4.4 /  M1;
  cd ans48[] = {4.4/cd(1,-1),4.4/cd(2,-2),4.4/cd(3,-3),4.4/cd(4,-4)};
  mcompare(M3,ans48);

  M3 = MR1 / cd(1,2);
  cd ans48a[] = { 1.0/cd(1,2),2.0/cd(1,2),3.0/cd(1,2),4.0/cd(1,2)};
  mcompare(M3,ans48a);
  M3 = cd(20,40) / MR1;
  cd ans48b[] = { cd(20,40)/1.0,cd(20,40)/2.0,cd(20,40)/3.0,cd(20,40)/4.0};
  mcompare(M3,ans48b);


  // unitary +/-
  M3 = -M1;
  cd ans60[] = {cd(-1,1),cd(-2,2),cd(-3,3), cd(-4,4)};
  mcompare(M3,ans60);
  M3 = +M2;
  cd ans61[] = { cd(10,100),cd(20,200),cd(30,300),cd(40,400) };
  mcompare(M3,ans61); 


  // conjugate,abs, arg,real,imag
  M3 = conj(M2+M1);
  cd ans100[] = {cd(11,-99) , cd(22,-198) , cd(33,-297) , cd(44,-396)};
  mcompare(M3,ans100);

  Matrix<double> MR3(2,2,"MR3");
  MR3 = real(M2);
  double ans101[] = {10,20,30,40};
  mcompare(MR3,ans101);

  MR3 = imag(2*M2);
  double ans102[] = {200,400,600,800};
  mcompare(MR3,ans102);


  MR3 = abs(M1);
  double ans103[] = {abs(cd(1,-1)),abs(cd(2,-2)),abs(cd(3,-3)), abs(cd(4,-4))};
  mcompare(MR3,ans103);

  MR3 = arg(M2+10);
  double ans104[] = { arg(cd(20,100)),arg(cd(30,200)),arg(cd(40,300)),arg(cd(50,400)) };
  mcompare(MR3,ans104);


  // pow_el

  M3 = pow_el(M2,2.0);
  cd ans130[] = { pow(cd(10,100),2.0),pow(cd(20,200),2.0),pow(cd(30,300),2.0),pow(cd(40,400),2.0) };
  mcompare(M3,ans130);
  M3 = pow_el(M2,3);
  cd ans131[] = { pow(cd(10,100),3.0),pow(cd(20,200),3.0),pow(cd(30,300),3.0),pow(cd(40,400),3.0) };
  mcompare(M3,ans131);

  M3 = pow_el(2.0,M1);
  cd ans132[] = { pow(2.0,cd(1,-1)),pow(2.0,cd(2,-2)),pow(2.0,cd(3,-3)),pow(2.0,cd(4,-4))
};
  mcompare(M3,ans132);
  M3 = pow_el(3,M1);
  cd ans133[] = { pow(3.0,cd(1,-1)),pow(3.0,cd(2,-2)),pow(3.0,cd(3,-3)),pow(3.0,cd(4,-4))
};
  mcompare(M3,ans133);



  cout << "<Complex matrix tests 1 passed>"<<endl;
  return 0;

}
