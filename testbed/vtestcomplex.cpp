
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

  LAvector<cd> v1(4,"v1");
  LAvector<cd> v2(4,"v2");
  LAvector<cd> v3(4,"v3");


  // Initialization tests
  v1[0] = cd(1,-1);
  v1[1] = complex<double>(2,-2);
  v1[2] = complex<double>(3,-3);
  v1[3] = complex<double>(4,-4);

  cd ans1[] = {cd(1,-1),cd(2,-2),cd(3,-3), cd(4,-4)};
  vcompare(v1,ans1);


  v2 = cd(3,2);
  cd ans1a[] = {cd(3,2),cd(3,2),cd(3,2),cd(3,2)};
  vcompare(v2,ans1a);


  LAvector<double> vr1(4,"vr1");
  LAvector<double> vr2(4,"vr2");


  vr1[0] = 11;
  vr1[1] = 22;
  vr1[2] = 33;
  vr1[3] = 44;
  vr2[0] = -100;
  vr2[1] = -200;
  vr2[2] = -300;
  vr2[3] = -400;


  v3 = vcomplex(vr1,vr2);
  cd ans1b[] = {cd(11,-100),cd(22,-200),cd(33,-300),cd(44,-400)};
  vcompare(v3,ans1b);

  vr1[0] = 1;
  vr1[1] = 2;
  vr1[2] = 3;
  vr1[3] = 4;
  vr2[0] = 0;
  vr2[1] = M_PI_4;
  vr2[2] = M_PI_2;
  vr2[3] = M_PI;
  
  v3 = vpolar(vr1,vr2);
  cd ans1c[] = {polar(1.0,0.0),polar(2.0,M_PI_4),polar(3.0,M_PI_2),polar(4.0,M_PI)};
  vcompare(v3,ans1c);
  

  v3 = vcomplex(vr1,5.0);
  cd ans1d[] = {cd(1,5),cd(2,5),cd(3,5),cd(4,5)};
  vcompare(v3,ans1d);

  v3 = vcomplex(vr1,13);
  cd ans1e[] = {cd(1,13),cd(2,13),cd(3,13),cd(4,13)};
  vcompare(v3,ans1e);

  v3 = vcomplex(7.5,vr1);
  cd ans1f[] = {cd(7.5,1),cd(7.5,2),cd(7.5,3),cd(7.5,4)};
  vcompare(v3,ans1f);

  v3 = vcomplex(21,vr1);
  cd ans1g[] = {cd(21,1),cd(21,2),cd(21,3),cd(21,4)};
  vcompare(v3,ans1g);
 
  // Casting Operations

  vector<cd> vstd(4);
  vstd[0] = cd(-1,23);
  vstd[1] = cd(-2,39);
  vstd[2] = cd(-3,65);
  vstd[3] = cd(-4,71);
  v2 = vcast<cd>(vstd);
  cd ans8[] = { cd(-1,23),cd(-2,39),cd(-3,65), cd(-4,71) };
  vcompare(v2,ans8);

  valarray<cd> val(4);
  val[0] = cd(10,100);
  val[1] = cd(20,200);
  val[2] = cd(30,300);
  val[3] = cd(40,400);
  v2 = vcast<cd>(val);
  cd ans9[] =  { cd(10,100),cd(20,200),cd(30,300),cd(40,400) };
  vcompare(v2,ans9);

 


  // addition

  v3 = v1 + v2;
  cd ans11[] = { cd(11,99),cd(22,198),cd(33,297),cd(44,396)};
  vcompare(v3,ans11);
  v3 = v1 + vr1;
  cd ans12[] = { cd(2,-1),cd(4,-2),cd(6,-3),cd(8,-4)};
  vcompare(v3,ans12);
  v3 = vr1 + v2;
  cd ans13[] = { cd(11,100),cd(22,200),cd(33,300),cd(44,400)};
  vcompare(v3,ans13);

  v3 = v1 + cd(1,1);
  cd ans14[] = { cd(2,0),cd(3,-1),cd(4,-2),cd(5,-3)};
  vcompare(v3,ans14);
  v3 = cd(20,40) + v2;
  cd ans15[] = { cd(30,140),cd(40,240),cd(50,340),cd(60,440)};
  vcompare(v3,ans15);

  v3 = v1 + 20;
  cd ans16[] = { cd(21,-1),cd(22,-2),cd(23,-3),cd(24,-4)};
  vcompare(v3,ans16);
  v3 = v1 + 101.5;
  cd ans17[] = { cd(1+101.5,-1),cd(2+101.5,-2),cd(3+101.5,-3),cd(4+101.5,-4)};
  vcompare(v3,ans17);
  v3 = 30 + v1;
  cd ans18[] = { cd(31,-1),cd(32,-2),cd(33,-3),cd(34,-4)};
  vcompare(v3,ans18);
  v3 = 33.0 + v1;
  cd ans19[] = { cd(34,-1),cd(35,-2),cd(36,-3),cd(37,-4)};
  vcompare(v3,ans19);

  v3 = vr1 + cd(1,1);
  cd ans19a[] = { cd(2,1),cd(3,1),cd(4,1),cd(5,1)};
  vcompare(v3,ans19a);
  v3 = cd(20,40) + vr1;
  cd ans19b[] = { cd(21,40),cd(22,40),cd(23,40),cd(24,40)};
  vcompare(v3,ans19b);


  // subtraction

  v3 = v2 - v1;
  cd ans20[] = { cd(9,101),cd(18,202),cd(27,303),cd(36,404)};
  vcompare(v3,ans20);
  v3 = v2 - vr1;
  cd ans21[] = { cd(9,100),cd(18,200),cd(27,300),cd(36,400)};
  vcompare(v3,ans21);
  v3 = vr1 - v1;
  cd ans22[] = { cd(0,1),cd(0,2),cd(0,3),cd(0,4)};
  vcompare(v3,ans22);

  v3 = v2 - cd(3,4);
  cd ans23[] = { cd(7,96),cd(17,196),cd(27,296),cd(37,396)};
  vcompare(v3,ans23);
  v3 = cd(100,400) - v2;
  cd ans24[] = { cd(90,300),cd(80,200),cd(70,100),cd(60,0)};
  vcompare(v3,ans24);

  v3 = v1 - 2;
  cd ans25[] = { cd(-1,-1),cd(0,-2),cd(1,-3),cd(2,-4)};
  vcompare(v3,ans25);
  v3 = v1 - 1.0;
  cd ans26[] = { cd(0,-1),cd(1,-2),cd(2,-3),cd(3,-4)};
  vcompare(v3,ans26);
  v3 = 30 - v1;
  cd ans27[] = { cd(29,1),cd(28,2),cd(27,3),cd(26,4)};
  vcompare(v3,ans27);
  v3 = 44.0 - v1;
  cd ans28[] = { cd(43,1),cd(42,2),cd(41,3),cd(40,4)};
  vcompare(v3,ans28);

  v3 = vr1 - cd(1,1);
  cd ans28a[] = { cd(0,-1),cd(1,-1),cd(2,-1),cd(3,-1)};
  vcompare(v3,ans28a);
  v3 = cd(20,40) - vr1;
  cd ans28b[] = { cd(19,40),cd(18,40),cd(17,40),cd(16,40)};
  vcompare(v3,ans28b);


  // multiplication

  v3 = v1 * v2;
  cd ans29[] = {cd(1,-1)*cd(10,100),cd(2,-2)*cd(20,200),cd(3,-3)*cd(30,300),cd(4,-4)*cd(40,400)};
  vcompare(v3,ans29);
  v3 = vr1 * v2;
  cd ans30[] = {1.0*cd(10,100),2.0*cd(20,200),3.0*cd(30,300),4.0*cd(40,400)};
  vcompare(v3,ans30);
  v3 = v1 * vr1;
  cd ans31[] = {cd(1,-1)*1.0,cd(2,-2)*2.0,cd(3,-3)*3.0,cd(4,-4)*4.0};
  vcompare(v3,ans31);


  v3 = v2 * cd(3,4);
  cd ans32[] = {cd(3,4)*cd(10,100),cd(3,4)*cd(20,200),cd(3,4)*cd(30,300),cd(3,4)*cd(40,400)};
  vcompare(v3,ans32);
  v3 = cd(1.5,2) * v2;
  cd ans33[] = {cd(1.5,2)*cd(10,100),cd(1.5,2)*cd(20,200),cd(1.5,2)*cd(30,300),cd(1.5,2)*cd(40,400)};
  vcompare(v3,ans33);


  v3 = v1 * 2;
  cd ans34[] = {cd(1,-1)*2.0,cd(2,-2)*2.0,cd(3,-3)*2.0,cd(4,-4)*2.0};
  vcompare(v3,ans34);
  v3 = v1 * 1.5;
  cd ans35[] = {cd(1,-1)*1.5,cd(2,-2)*1.5,cd(3,-3)*1.5,cd(4,-4)*1.5};
  vcompare(v3,ans35);
  v3 = 3 * v1;
  cd ans36[] = {cd(1,-1)*3.0,cd(2,-2)*3.0,cd(3,-3)*3.0,cd(4,-4)*3.0};
  vcompare(v3,ans36);
  v3 = 4.4*  v1;
  cd ans37[] = {cd(1,-1)*4.4,cd(2,-2)*4.4,cd(3,-3)*4.4,cd(4,-4)*4.4};
  vcompare(v3,ans37);


  v3 = vr1 * cd(1,2);
  cd ans37a[] = { 1.0*cd(1,2),2.0*cd(1,2),3.0*cd(1,2),4.0*cd(1,2)};
  vcompare(v3,ans37a);
  v3 = cd(20,40) * vr1;
  cd ans37b[] = { 1.0*cd(20,40),2.0*cd(20,40),3.0*cd(20,40),4.0*cd(20,40)};
  vcompare(v3,ans37b);


  // division

  v3 = v1 / v2;
  cd ans40[] = {cd(1,-1)/cd(10,100),cd(2,-2)/cd(20,200),cd(3,-3)/cd(30,300),cd(4,-4)/cd(40,400)};
  vcompare(v3,ans40);
  v3 = vr1 / v2;
  cd ans41[] = {1.0/cd(10,100),2.0/cd(20,200),3.0/cd(30,300),4.0/cd(40,400)};
  vcompare(v3,ans41);
  v3 = v1 / vr1;
  cd ans42[] = {cd(1,-1)/1.0,cd(2,-2)/2.0,cd(3,-3)/3.0,cd(4,-4)/4.0};
  vcompare(v3,ans42);


  v3 = v2 / cd(3,4);
  cd ans43[] = {cd(10,100)/cd(3,4),cd(20,200)/cd(3,4),cd(30,300)/cd(3,4),cd(40,400)/cd(3,4)};
  vcompare(v3,ans43);
  v3 = cd(1.5,2) / v2;
  cd ans44[] = {cd(1.5,2)/cd(10,100),cd(1.5,2)/cd(20,200),cd(1.5,2)/cd(30,300),cd(1.5,2)/cd(40,400)};
  vcompare(v3,ans44);


  v3 = v1 / 2;
  cd ans45[] = {cd(1,-1)/2.0,cd(2,-2)/2.0,cd(3,-3)/2.0,cd(4,-4)/2.0};
  vcompare(v3,ans45);
  v3 = v1 / 1.5;
  cd ans46[] = {cd(1,-1)/1.5,cd(2,-2)/1.5,cd(3,-3)/1.5,cd(4,-4)/1.5};
  vcompare(v3,ans46);
  v3 = 3 / v1;
  cd ans47[] = {3.0/cd(1,-1),3.0/cd(2,-2),3.0/cd(3,-3),3.0/cd(4,-4)};
  vcompare(v3,ans47);
  v3 = 4.4 /  v1;
  cd ans48[] = {4.4/cd(1,-1),4.4/cd(2,-2),4.4/cd(3,-3),4.4/cd(4,-4)};
  vcompare(v3,ans48);

  v3 = vr1 / cd(1,2);
  cd ans48a[] = { 1.0/cd(1,2),2.0/cd(1,2),3.0/cd(1,2),4.0/cd(1,2)};
  vcompare(v3,ans48a);
  v3 = cd(20,40) / vr1;
  cd ans48b[] = { cd(20,40)/1.0,cd(20,40)/2.0,cd(20,40)/3.0,cd(20,40)/4.0};
  vcompare(v3,ans48b);


  // unitary +/-
  v3 = -v1;
  cd ans60[] = {cd(-1,1),cd(-2,2),cd(-3,3), cd(-4,4)};
  vcompare(v3,ans60);
  v3 = +v2;
  cd ans61[] = { cd(10,100),cd(20,200),cd(30,300),cd(40,400) };
  vcompare(v3,ans61); 


  // converting to STL containers
  cd* vc1; 
  v3 = v2+2;
  vc1 = toCarray<cd>(v3);
  cd ans70[] = { cd(10,100)+2.0,cd(20,200)+2.0,cd(30,300)+2.0,cd(40,400)+2.0 };
  vcompare(vc1,ans70);
  delete [] vc1;

  std::vector<complex<float> > vs2(4); 
  v3 = 2*(-v2);
  vs2 = tostdvector<complex<float> >(v3);
  typedef complex<float> cf;
  complex<float> ans71[] = { cf(10,100)*float(-2.0),cf(20,200)*float(-2.0),cf(30,300)*float(-2.0),cf(40,400)*float(-2.0) };
  vcompare(vs2,ans71);

  std::valarray<cd> va1(4); 
  v3 = v1+3.5;
  va1 = tovalarray<cd>(v3);
  cd ans72[] = { cd(1,-1)+3.5,cd(2,-2)+3.5,cd(3,-3)+3.5,cd(4,-4)+3.5 };
  vcompare(va1,ans72);



  // dot product

  cd d = (v1|v2);
  cd ans80 = cd(1,-1)*cd(10,100) + cd(2,-2)*cd(20,200) + cd(3,-3)*cd(30,300) + cd(4,-4)*cd(40,400);
  compare(d,ans80);
   d = (vr1|v2);
  cd ans81 = 1.0*cd(10,100) + 2.0*cd(20,200) + 3.0*cd(30,300) + 4.0*cd(40,400);
  compare(d,ans81);
   d = (v1|vr1);
  cd ans82 = cd(1,-1)*1.0 + cd(2,-2)*2.0 + cd(3,-3)*3.0 + cd(4,-4)*4.0;
  compare(d,ans82);


  // sum
  d = sum(v2);
  cd ans90 = cd(10,100) + cd(20,200) + cd(30,300) + cd(40,400);
  compare(d,ans90);


  // conjugate,abs, arg,real,imag
  v3 = conj(v2+v1);
  cd ans100[] = {cd(11,-99) , cd(22,-198) , cd(33,-297) , cd(44,-396)};
  vcompare(v3,ans100);

  LAvector<double> vr3(4);
  vr3 = real(v2);
  double ans101[] = {10,20,30,40};
  vcompare(vr3,ans101);

  vr3 = imag(2*v2);
  double ans102[] = {200,400,600,800};
  vcompare(vr3,ans102);


  vr3 = abs(v1);
  double ans103[] = {abs(cd(1,-1)),abs(cd(2,-2)),abs(cd(3,-3)), abs(cd(4,-4))}; 
  vcompare(vr3,ans103);

  vr3 = arg(v2+10);
  double ans104[] = { arg(cd(20,100)),arg(cd(30,200)),arg(cd(40,300)),arg(cd(50,400)) };
  vcompare(vr3,ans104);

  
  // norm

  d = norm(v2);
  cd ans110 = sqrt(cd(10,100)*cd(10,-100) + cd(20,200)*cd(20,-200) + cd(30,300)*cd(30,-300) + cd(40,400)*cd(40,-400));
  compare(d,ans110);


  // resize 
  v3.resize(0);
  compare(int(v3.size()),0);

  v3.resize() = v1;
  compare(int(v3.size()),4);
  cd ans120[] = {cd(1,-1),cd(2,-2),cd(3,-3), cd(4,-4)};
  vcompare(v3,ans120);


  // pow
 
  v3 = pow(v2,2.0);
  cd ans130[] = { pow(cd(10,100),2.0),pow(cd(20,200),2.0),pow(cd(30,300),2.0),pow(cd(40,400),2.0) };
  vcompare(v3,ans130); 
  v3 = pow(v2,3);
  cd ans131[] = { pow(cd(10,100),3.0),pow(cd(20,200),3.0),pow(cd(30,300),3.0),pow(cd(40,400),3.0) };
  vcompare(v3,ans131); 

  v3 = pow(2.0,v1);
  cd ans132[] = { pow(2.0,cd(1,-1)),pow(2.0,cd(2,-2)),pow(2.0,cd(3,-3)),pow(2.0,cd(4,-4)) };
  vcompare(v3,ans132); 
  v3 = pow(3,v1);
  cd ans133[] = { pow(3.0,cd(1,-1)),pow(3.0,cd(2,-2)),pow(3.0,cd(3,-3)),pow(3.0,cd(4,-4)) };
  vcompare(v3,ans133); 


  cout << "<Complex vector tests passed>"<<endl;
  return 0;



}
