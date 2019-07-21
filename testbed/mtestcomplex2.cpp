
// flag for run-time bounds and size checking
 


#include "cooll.hpp"
using namespace COOLL;

#include "testlib.hpp"

#include <iostream>
using namespace std;


#include <vector>


int main()
{

  typedef complex<double> cd;

  typedef complex<float> cf;

  cd result;

  Matrix<cd> A1(4,3,"A1");
  Matrix<cd> A2(4,3,"A2");
  Matrix<cd> A3(4,3,"A3");
  Matrix<cd> B1(3,4,"B1");
  Matrix<cd> B2(3,4,"B2");
  Matrix<cd> B3(3,4,"B3");

  Matrix<cd> C33(3,3,"C33");
  Matrix<cd> C44(4,4,"C44");


  // Initialization tests
  A1(0,0) = cd(1,-3);
  A1(0,1) = cd(2,4);
  A1(0,2) = cd(3,7);
  A1(1,0) = cd(4,-2);
  A1(1,1) = cd(5,-1);
  A1(1,2) = cd(6,0);
  A1(2,0) = cd(7,-4);
  A1(2,1) = cd(8,-8);
  A1(2,2) = cd(9,-10);
  A1(3,0) = cd(10,-1);
  A1(3,1) = cd(11,-12);
  A1(3,2) = cd(12,-13);
  cd ans0[] = { cd(1,-3),  cd(2,4),    cd(3,7),
		cd(4,-2),  cd(5,-1),   cd(6,0),
		cd(7,-4),  cd(8,-8),   cd(9,-10),
		cd(10,-1), cd(11,-12), cd(12,-13), };
  mcompare(A1,ans0);

  A2(0) =  cd(3,-1);
  A2(1) =  cd(-8,-4);
  A2(2) =  cd(4,-5);
  A2(3) =  cd(-6,13);
  A2(4) =  cd(1,5);
  A2(5) =  cd(7,0);
  A2(6) =  cd(-1,8);
  A2(7) =  cd(-8,9);
  A2(8) =  cd(0,-3);
  A2(9) =  cd(2,4);
  A2(10) = cd(4,-1);
  A2(11) = cd(2,9);
  cd ans1[] = { cd(3,-1),   cd(-8,-4), cd(4,-5),
		cd(-6,13),  cd(1,5),   cd(7,0),
		cd(-1,8),   cd(-8,9),  cd(0,-3),
		cd(2,4),    cd(4,-1),  cd(2,9) };
  mcompare(A2,ans1);

  A3 = 5.5;
  cd ans1a[] = {5.5,5.5,5.5,5.5,5.5,5.5,5.5,5.5,5.5,5.5,5.5,5.5};
  mcompare(A3,ans1a);
  A3 = cd(5.5,4.4);
  cd ans1b[] = {cd(5.5,4.4),cd(5.5,4.4),cd(5.5,4.4),cd(5.5,4.4),
		    cd(5.5,4.4),cd(5.5,4.4),cd(5.5,4.4),cd(5.5,4.4),
		    cd(5.5,4.4),cd(5.5,4.4),cd(5.5,4.4),cd(5.5,4.4)
  };
  mcompare(A3,ans1b);


 
  // sum 
  LAvector<cd> v3(3);
  LAvector<cd> v4(4);


  result = sum(A2);
  cd ans20 =  cd(3,-1) +   cd(-8,-4) + cd(4,-5) + cd(-6,13) 
    + cd(1,5) +  cd(7,0) + cd(-1,8) +   cd(-8,9) 
    + cd(0,-3) + cd(2,4) +    cd(4,-1) +  cd(2,9);
  compare(result,ans20);
  v4 = sumbyrow(A2);
  cd ans21[] = {cd(3-8+4,-1-4-5),cd(-6+1+7,13+5+0),cd(-1-8+0,8+9-3),cd(2+4+2,4-1+9)};
  vcompare(v4,ans21);
  v3 = sumbycol(A2);
  cd ans22[] = {cd(3-6-1+2,-1+13+8+4), cd(-8+1-8+4,-4+5+9-1), cd(4+7+0+2,-5+0-3+9)};
  vcompare(v3,ans22);




  
  //transpose

  B1 = ~A2;
  cd ans30[] = { cd(3,-1),   cd(-6,13), cd(-1,8), cd(2,4),  
		 cd(-8,-4),   cd(1,5), cd(-8,9), cd(4,-1),
		cd(4,-5),    cd(7,0),  cd(0,-3), cd(2,9) };
  mcompare(B1,ans30);

  //adjoint
  B1 = cd(100,100);
  B1 = ~conj(A2);
  cd ans31[] = { cd(3,1),   cd(-6,-13), cd(-1,-8), cd(2,-4),  
		 cd(-8,4),   cd(1,-5), cd(-8,-9), cd(4,1),
		cd(4,5),    cd(7,-0),  cd(0,3), cd(2,-9) };
  mcompare(B1,ans31);
  B2 = cd(1,-2);
  B2 = adj(A2);
  cd ans32[] = { cd(3,1),   cd(-6,-13), cd(-1,-8), cd(2,-4),  
		 cd(-8,4),   cd(1,-5), cd(-8,-9), cd(4,1),
		cd(4,5),    cd(7,-0),  cd(0,3), cd(2,-9) };
  mcompare(B2,ans32);

  // conjugate
  A3 = conj(A1);
  cd ans33[] = { cd(1,3),  cd(2,-4),    cd(3,-7),
		cd(4,2),  cd(5,1),   cd(6,-0),
		cd(7,4),  cd(8,8),   cd(9,10),
		cd(10,1), cd(11,12), cd(12,13), };
  mcompare(A3,ans33);

  //trace 

  result = tr(A1);
  compare(result,cd(1+5+9,-3-1-10));

  // reshape

  A3.reshape(2,6);
  A3(1,0) = cd(1,0);
  A3(1,5) = cd(3,-2);
  cd ans40[] = { cd(1,3),  cd(2,-4),    cd(3,-7), cd(4,2),  cd(5,1),   cd(6,-0),
		cd(1,0),  cd(8,8),   cd(9,10), cd(10,1), cd(11,12), cd(3,-2) };
  mcompare(A3,ans40);

  A3.reshape(4,3);
  A3(3,2) = cd(-9,9);
  cd ans41[] = { cd(1,3),  cd(2,-4),    cd(3,-7), cd(4,2),  cd(5,1),   cd(6,-0),
		cd(1,0),  cd(8,8),   cd(9,10), cd(10,1), cd(11,12), cd(-9,9) };
  mcompare(A3,ans41);



  // dot product



  B1(0,0) = cd(6,7);
  B1(0,1) = cd(2,5);
  B1(0,2) = cd(5,2);
  B1(0,3) = cd(12,-18);
  B1(1,0) = cd(-12,9);
  B1(1,1) = cd(7,-6);
  B1(1,2) = cd(2,1);
  B1(1,3) = cd(9,-7);
  B1(2,0) = cd(4,5);
  B1(2,1) = cd(1,6);
  B1(2,2) = cd(1,0);
  B1(2,3) = cd(-3,8);
  cd ans50[] = { cd(6,7),  cd(2,5),    cd(5,2), cd(12,-18),  
		 cd(-12,9),   cd(7,-6), cd(2,1),  cd(9,-7),  
		 cd(4,5), cd(1,6), cd(1,0), cd(-3,8), };
  mcompare(B1,ans50);

  
  C33 = (B1|A1);
  cd ans51[] = {cd(190,-193), cd(-29,-305), cd(-44,-311),
		cd(132,-73), cd(8,-260), cd(-12,-305),
		cd(20,94), cd(70,171), cd(60,204) };
  mcompare(C33,ans51);
  
  //real dot complex
  Matrix<double> MR4x2(4,2,"MR4x2");
  MR4x2(0,0) = 21;
  MR4x2(0,1) = 3;
  MR4x2(1,0) = -7;
  MR4x2(1,1) =  -3;
  MR4x2(2,0) = 2;
  MR4x2(2,1) = 1;
  MR4x2(3,0) = 0;
  MR4x2(3,1) = -1;
  double ans52[] = { 21,3,
		 -7,-3,
		 2,1,
		 0,-1};
  mcompare(MR4x2,ans52);

  
  Matrix<cd> C3x2(3,2,"C3x2");
  C3x2 = (B1|MR4x2);
  cd ans52b[] = { cd(122,116), cd(5,26),
		  cd(-297,233), cd(-64,53),
		  cd(79,63), cd(13,-11) };
  mcompare(C3x2,ans52b);


  // complex dot real
  Matrix<double> MR2x3(2,3,"MR2x3");
  MR2x3(0,0) = -3;
  MR2x3(0,1) = 0;
  MR2x3(0,2) = -16;
  MR2x3(1,0) = 12;
  MR2x3(1,1) =  1;
  MR2x3(1,2) =  5;
  double ans53[] = {-3,0,-16,12,1,5};
  mcompare(MR2x3,ans53);

  Matrix<cd> C2x4(2,4,"C2x4");
  C2x4 = (MR2x3|~A1);
  cd ans53b[] = { cd(-51,-103), cd(-108,6), cd(-165,172), cd(-222,211),
		  cd(29,3), cd(83,-25), cd(137,-106), cd(191,-89) };
  mcompare(C2x4,ans53b);


  

  // casting

  A1(2,1)= cd(-66,66);
  Matrix<complex<float> > MF1 = mcast<complex<float> >(A1);
  complex<float> ans60[] =  { cf(1,-3),  cf(2,4),    cf(3,7),
		cf(4,-2),  cf(5,-1),   cf(6,0),
		cf(7,-4),  cf(-66,66),   cf(9,-10),
		cf(10,-1), cf(11,-12), cf(12,-13), };
  mcompare(MF1,ans60);

  
  

  B3=0;
  cd ans62[] =  { cd(1,3),  cd(2,4),    cd(33,2),
		cd(4,23),  cd(5,-1),   cd(60,0),
		cd(-7,1),  cd(0,3),   cd(19,19),
		cd(1,-1), cd(14,-2), cd(-10,13), };
  B3=mcast<cd>(ans62,3,4);
  mcompare(B3,ans62);

  A3=0;
  cd ans63[4][3] =  {{ cd(1,-3),  cd(2,4),    cd(3,7)},
		     { cd(4,-2),  cd(5,-1),   cd(6,0)},
		     {cd(7,-4),  cd(0,0),   cd(9,-10)},
		     {cd(10,-1), cd(1,-2), cd(12,-13)} };
  A3=mcast<cd>(&ans63[0][0],4,3);
  cd ans63b[] =  { cd(1,-3),  cd(2,4),    cd(3,7),
		cd(4,-2),  cd(5,-1),   cd(6,0),
		cd(7,-4),  cd(0,0),   cd(9,-10),
		cd(10,-1), cd(1,-2), cd(12,-13), };
  mcompare(A3, ans63b );


  
  B3=0;
  cd ans64[] =  { cd(1,-3),  cd(2,4),    cd(3,7),
		cd(4,-2),  cd(5,-1),   cd(6,0),
		cd(7,-4),  cd(0,0),   cd(9,-10),
		cd(10,-1), cd(1,-2), cd(12,-13), };
  B3=mcastF<cd>(ans64,3,4);
  A3=~B3;
  mcompare(A3, ans64 );



  // converting matrices to other objects

  A1(2,1)=cd(8,-8);
  cd* ptr1;
  ptr1 = toCarray<cd>(A1);
  cd ans70[] = { cd(1,-3),  cd(2,4),    cd(3,7),
		cd(4,-2),  cd(5,-1),   cd(6,0),
		cd(7,-4),  cd(8,-8),   cd(9,-10),
		cd(10,-1), cd(11,-12), cd(12,-13), };
  vcompare(ptr1,ans70);

  ptr1 = toFarray<cd>(A1);

  cd ans71[] = { cd(1,-3),  cd(4,-2),    cd(7,-4), cd(10,-1),  
		 cd(2,4),   cd(5,-1), cd(8,-8),  cd(11,-12),  
		 cd(3,7), cd(6,0), cd(9,-10), cd(12,-13), };

  vcompare(ptr1,ans71);


  cout << "<Complex matrix tests 2 passed>"<<endl;
  return 0;


}
