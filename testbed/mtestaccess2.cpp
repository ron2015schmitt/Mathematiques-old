
// flag for run-time bounds and size checking
 


#import "matricks.hpp"
using namespace Matricks;

#import "testlib.hpp"

#import <iostream>
using namespace std;


#import <vector>


int main()
{



  Matrix<double> M1(2,2,"M1");
  Matrix<double> M2(3,2,"M2");
  Matrix<double> M3(4,2,"M3");


  LAvector<unsigned int> i0r(2,"i0r");
  LAvector<unsigned int> i0c(2,"i0c");
  LAvector<unsigned int> i1r(2,"i1r");
  LAvector<unsigned int> i1c(2,"i1c");


  // dual set access

  
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  double ans10[] = {1,2,3,4};
  mcompare(M1,ans10);

  M2(0) = 10;
  M2(1) = 20;
  M2(2) = 30;
  M2(3) = 40;
  M2(4) = 50;
  M2(5) = 60;
  double ans11[] = {10,20,30,40,50,60};
  mcompare(M2,ans11);

  M3(0) = 11;
  M3(1) = 22;
  M3(2) = 33;
  M3(3) = 44;
  M3(4) = 55;
  M3(5) = 66;
  M3(6) = 77;
  M3(7) = 88;
  double ans12[] = {11,22,33,44,55,66,77,88};
  mcompare(M3,ans12);

  
  i0r[0] = 3;
  i0r[1] = 1;

  i0c[0] = 1;
  i0c[1] = 0;
  M1 = M3(i0r,i0c);
  double ans13[] = {88,77,44,33};
  mcompare(M1,ans13);

  

  i0r[0] = 0;
  i0r[1] = 2;
  i0c[0] = 0;
  i0c[1] = 1;

  i1r[0] = 1;
  i1r[1] = 2;
  i1c[0] = 0;
  i1c[1] = 1;
  M2(i1r,i1c) = M3(i0r,i0c);
  double ans14[] = {10,20,11,22,55,66};
  mcompare(M2,ans14);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M2(i1r,i1c) = M1;
  double ans15[] = {10,20,1,2,3,4};
  mcompare(M2,ans15);
 

  i0r[0] = 0;
  i0r[1] = 1;
  i0c[0] = 0;
  i0c[1] = 1;
  i1r[0] = 1;
  i1r[1] = 0;
  i1c[0] = 1;
  i1c[1] = 0;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(i0r,i0c) = M1(i1r,i1c);
  double ans16[] = {4,3,2,1};
  mcompare(M1,ans16);

  i0r[0] = 0;
  i0r[1] = 1;
  i0c[0] = 0;
  i0c[1] = 1;
  i1r[0] = 0;
  i1r[1] = 1;
  i1c[0] = 0;
  i1c[1] = 1;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(i0r,i0c) = M1(i1r,i1c);
  double ans17[] = {1,2,3,4};
  mcompare(M1,ans17);


  i0r[0] = 0;
  i0r[1] = 1;
  i0c[0] = 0;
  i0c[1] = 1;
  i1r[0] = 0;
  i1r[1] = 0;
  i1c[0] = 0;
  i1c[1] = 1;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(i0r,i0c) = M1(i1r,i1c);
  double ans18[] = {1,2,1,2};
  mcompare(M1,ans18);

  i0r[0] = 1;
  i0r[1] = 0;
  i0c[0] = 0;
  i0c[1] = 1;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(i0r,i0c) = M1(i0r,i0c);
  double ans19[] = {1,2,3,4};
  mcompare(M1,ans19);


  i0r[0] = 0;
  i0r[1] = 1;
  i0c[0] = 0;
  i0c[1] = 1;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(i0r,i0c) = ~M1(i0r,i0c);
  double ans20[] = {1,3,2,4};
  mcompare(M1,ans20);


  i0r[0] = 1;
  i0r[1] = 0;
  i0c[0] = 0;
  i0c[1] = 1;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(i0r,i0c) = ~M1(i0r,i0c);
  double ans21[] = {4,2,3,1};
  mcompare(M1,ans21);



  // (set,integer) & (inetger,set) access
  

  i0r[0] = 0;
  i0r[1] = 1;
  i1r[0] = 2;
  i1r[1] = 3;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(i0r,0) = M3(i1r,1);
  double ans22[] = {66,2,88,4};
  mcompare(M1,ans22);

  i0c[0] = 0;
  i0c[1] = 1;
  i1c[0] = 1;
  i1c[1] = 0;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(0,i0c) = M3(2,i1c);
  double ans23[] = {66,55,3,4};
  mcompare(M1,ans23);


  i0c[0] = 0;
  i0c[1] = 1;
  i1c[0] = 1;
  i1c[1] = 0;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(0,i0c) = M1(0,i1c);
  double ans24[] = {2,1,3,4};
  mcompare(M1,ans24);

  i1c[0] = 0;
  i1c[1] = 1;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(seq(1,2)) = vcast<double>(M1(0,i1c));
  double ans25[] = {1,1,2,4};
  mcompare(M1,ans25);







  // (ind,ind) access

  
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
 
  M1 = M3(seq(3,1,-2),seq(1,0));
  double ans53[] = {88,77,44,33};
  mcompare(M1,ans53);

  

  M2(seq(1,2),seq(0,1)) = M3(seq(0,2,2),seq(0,1));
  double ans54[] = {10,20,11,22,55,66};
  mcompare(M2,ans54);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M2(seq(1,2),seq(0,1)) = M1;
  double ans55[] = {10,20,1,2,3,4};
  mcompare(M2,ans55);
 

  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(seq(0,1),seq(0,1)) = M1(seq(1,0),seq(1,0));
  double ans56[] = {4,3,2,1};
  mcompare(M1,ans56);

  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(seq(0,1),seq(0,1)) = M1(seq(0,1),seq(0,1));
  double ans57[] = {1,2,3,4};
  mcompare(M1,ans57);



  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(seq(1,0),seq(0,1)) = M1(seq(1,0),seq(0,1));
  double ans59[] = {1,2,3,4};
  mcompare(M1,ans59);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(seq(0,1),seq(0,1)) = ~M1(seq(0,1),seq(0,1));
  double ans60[] = {1,3,2,4};
  mcompare(M1,ans60);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(seq(1,0),seq(0,1)) = ~M1(seq(1,0),seq(0,1));
  double ans61[] = {4,2,3,1};
  mcompare(M1,ans61);




  // (set,ind) access
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

  i0r[0] = 3;
  i0r[1] = 1;
  M1 = M3(i0r,seq(1,0));
  double ans73[] = {88,77,44,33};
  mcompare(M1,ans73);


  

  i0r[0] = 0;
  i0r[1] = 2;
  i1r[0] = 1;
  i1r[1] = 2;
  M2(i1r,seq(0,1)) = M3(i0r,seq(0,1));
  double ans74[] = {10,20,11,22,55,66};
  mcompare(M2,ans74);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M2(i1r,seq(0,1)) = M1;
  double ans75[] = {10,20,1,2,3,4};
  mcompare(M2,ans75);
 

  i0r[0] = 0;
  i0r[1] = 1;
  i1r[0] = 1;
  i1r[1] = 0;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(i0r,seq(0,1)) = M1(i1r,seq(1,0));
  double ans76[] = {4,3,2,1};
  mcompare(M1,ans76);


  i0r[0] = 1;
  i0r[1] = 0;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(i0r,seq(0,1)) = ~M1(i0r,seq(0,1));
  double ans81[] = {4,2,3,1};
  mcompare(M1,ans81);



 // (ind,set) access
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

  i0c[0] = 1;
  i0c[1] = 0;
  M1 = M3(seq(3,1,-2),i0c);
  double ans93[] = {88,77,44,33};
  mcompare(M1,ans93);


  i0c[0] = 0;
  i0c[1] = 1;
  i1c[0] = 0;
  i1c[1] = 1;
  M2(seq(1,2),i1c) = M3(seq(0,2,2),i0c);
  double ans94[] = {10,20,11,22,55,66};
  mcompare(M2,ans94);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M2(seq(1,2),i1c) = M1;
  double ans95[] = {10,20,1,2,3,4};
  mcompare(M2,ans95);
 

  i0c[0] = 0;
  i0c[1] = 1;
  i1c[0] = 1;
  i1c[1] = 0;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(seq(0,1),i0c) = M1(seq(1,0),i1c);
  double ans96[] = {4,3,2,1};
  mcompare(M1,ans96);


  i0c[0] = 0;
  i0c[1] = 1;
  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(seq(1,0),i0c) = ~M1(seq(1,0),i0c);
  double ans101[] = {4,2,3,1};
  mcompare(M1,ans101);



  // (ind,integer) & (inetger,ind) access
  
  M2(0) = 10;
  M2(1) = 20;
  M2(2) = 30;
  M2(3) = 40;
  M2(4) = 50;
  M2(5) = 60;

  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(seq(0,1),0) = M3(seq(2,3),1);
  double ans122[] = {66,2,88,4};
  mcompare(M1,ans122);

  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(0,seq(0,1)) = M3(2,seq(1,0));
  double ans123[] = {66,55,3,4};
  mcompare(M1,ans123);


  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(0,seq(0,1)) = M1(0,seq(1,0));
  double ans124[] = {2,1,3,4};
  mcompare(M1,ans124);

  M1(0) = 1.0;
  M1(1) = 2.0;
  M1(2) = 3.0;
  M1(3) = 4.0;
  M1(seq(1,2)) = vcast<double>(M1(0,seq(0,1)));
  double ans125[] = {1,1,2,4};
  mcompare(M1,ans125);



  cout << "<matrix access tests 2 passed>"<<endl;
  return 0;

}
