
#import <iostream>

#define MATRICKS_DEBUG

#import "cooll.hpp"

using namespace COOLL;

using namespace std;

int main()
{



  const int R = 3;
  const int C = 2;

 
  Matrix<double> r(R,C,"r");
  r=100;
  cout << r.name() <<"="<<r << endl;
  Matrix<double> rr(R,C,"r");
  rr=200;
  cout << rr.name() <<"="<<rr << endl;
  Matrix<double> rrr(R,C,"r");
  rrr=300;
  cout << rrr.name() <<"="<<rrr << endl;
  rrr.name("rrr");
  cout << rrr.name() <<"="<<rrr << endl;


 
  Matrix<double> M1(R,C,"M1");
  Matrix<double> M2(R,C,"M2");
  Matrix<double> M3(R,C,"M3");


  M3(0,0)=1;
  M3(0,1)=2;
  M3(1,0)=3;
  M3(1,1)=4;
  M3(2,0)=5;
  M3(2,1)=6;
 
  
  cout << endl << "OUT OF BOUNDS INDEX i=6" << endl;
  M1(6) = 1.1;

  cout << endl << "OUT OF BOUNDS INDEX, i=7" << endl;
  double x= M1(7);
  
  cout << endl << "OUT OF BOUNDS INDEX r=3" << endl;
  M1(3,0) = 2.1;

  cout << endl << "OUT OF BOUNDS INDEX r=3" << endl;
  x= M1(3,0);

  cout << endl << "OUT OF BOUNDS INDEX c=2" << endl;
  M1(0,2) = 2.1;


  cout << endl << "OUT OF BOUNDS INDEX c=2" << endl;
  x= M1(0,2);

 cout << endl << "ASSIGNMENT TO MATRIX OF DIFFERENT SIZE" << endl;
  Matrix<double> M5(R,C+1,"M5");
  M5= M2;
  

  cout << endl << "EXPRESSION FORMED BETWEEN MATRICES OF DIFFERENT SIZE" << endl;  M5= M5+M2;
  
  cout << endl << "TRANSPOSE OF BAD EXPRESSION" << endl;
  Matrix<double> M4(C,R,"M4");
  M4=~(M3+M5);

  cout << endl << "ADJOINT OF BAD EXPRESSION" << endl;
  Matrix<complex<double> > M6(C,R,"M6");
  M6=adj(M6+M5);



  Matrix<double> B1(1,4,"B1");
  cout << endl<< "EXAMPLE OF A SINGLE ROW MATRIX" << endl;
  B1(0) = 1;
  B1(1) = 2;
  B1(2) = 3;
  B1(3) = 4;
  cout <<"B1="<<endl<< B1<< endl;

  Matrix<double> B2(3,1,"B2");
  cout << endl<< "EXAMPLE OF A SINGLE COLUMN MATRIX" << endl;
  B2(0) = 10;
  B2(1) = 20;
  B2(2) = 30;
  cout <<"B2="<<endl<< B2<< endl;

  cout << endl<< "BAD DOT PRODUCT OF SINGLE ROW AND COLUMN MATRICES" << endl;
  Matrix<double> B3(1,1,"B3");
  B3 = (B1|B2);
  cout <<"B3=(B1|B2)="<<B3<<endl;



  cout << endl << "DOT PRODUCT OF BAD EXPRESSION" << endl;
  B3=(~B2|B2+M1);
  cout << endl << "DOT PRODUCT OF BAD EXPRESSION" << endl;
  B3=(B2+M1|~B2);

  cout << endl << "RESIZE OF BAD EXPRESSION" << endl;
  B3.resize()=B2+M1;




  cout << endl << "ILLEGAL RESHAPE" << endl;
  M1.reshape(4,3);

  cout << endl << "MATRIX TOO BIG" << endl;
  Matrix<double> M10(maxsize-1,2,"M10");


  Matrix<bool> MB1(2,2,"MB1");
  Matrix<bool> MB2(4,1,"MB2");
  Matrix<bool> MB3(2,1,"MB3");
  bool Q = false;
  cout << endl << "BAD EXPRESSION IN alltrue()" << endl;
  Q = alltrue(MB1+MB2);
  
  cout << endl << "BAD EXPRESSION IN anytrue()" << endl;
  Q = anytrue(MB1+MB3);
  
  int m = 0;
  cout << endl << "BAD EXPRESSION IN numtrue()" << endl;
  m = numtrue(MB1+MB3);

  Vector<bool> vb1(2,"vb1");
  cout << endl << "BAD EXPRESSION IN alltruebyrow()" << endl;
  vb1 = alltruebyrow(MB1+MB2);
  cout << endl << "BAD EXPRESSION IN alltruebycol()" << endl;
  vb1 = alltruebycol(MB1+MB2);
  cout << endl << "BAD EXPRESSION IN anytruebyrow()" << endl;
  vb1 = anytruebyrow(MB1+MB2);
  cout << endl << "BAD EXPRESSION IN anytruebycol()" << endl;
  vb1 = anytruebycol(MB1+MB2);

  Vector<unsigned int> vm1(2,"vm1");
  cout << endl << "BAD EXPRESSION IN numtruebyrow()" << endl;
  vm1 = numtruebyrow(MB1+MB2);
  cout << endl << "BAD EXPRESSION IN numtruebycol()" << endl;
  vm1 = numtruebycol(MB1+MB2);
  

  Matrix<unsigned int> F1(0,0,"F1");
  cout << endl << "BAD EXPRESSION IN findtrue(matrix)" << endl;
  F1 = findtrue(MB1+MB2);


  Matrix<double> A1(2,2,"A1");
  Matrix<double> A2(3,2,"A2");
  Matrix<double> A3(4,2,"A3");
  Vector<double> u1(2,"u1");


  cout << endl << "ILLEGAL USE OF .resize()" << endl;
  A1=A1.resize();


  Vector<double> vtemp0(4,"vtemp0");
  Matrix<unsigned int> Aind1(4,3,"Aind1");
  cout << endl << "BADLY SIZED MATRIX IN PAIRED SET ACCESS" << endl;
  vtemp0 =  A1(Aind1);
  
  cout << endl << "ASSIGNMENT OF DIFFERENT SIZE SEQUENCES" << endl;
  A1(seq(2,3,2)) = A2(seq(3,1,-2));

  Matrix<bool> Mbool1(4,1,"Mbool1");
  cout<< endl << "MATRIX MASK SIZE DOES NOT MATCH MATRIX SIZE" << endl;
  A1 = A1(Mbool1);


  Vector<bool> ubool1(3,"ubool1");
  cout<< endl << "VECTOR MASK SIZE DOES NOT MATCH MATRIX SIZE" << endl;
  A1 = A1(ubool1);
 

  cout << endl << "OUT BOUNDS SEQUENCE ACCESS" << endl;
  u1 = A1(seq(3,4));

  cout << endl << "OUT OF BOUNDS .row() ACCESS" << endl;
  u1 = A1.row(2);

  cout << endl << "OUT OF BOUNDS .col() ACCESS" << endl;
  u1 = A1.col(2);

  Vector<unsigned int> vset1(5,"vset1");
  vset1 = range<unsigned int>(0,4);
  Vector<double> vtemp1(5,"vtemp1");
  cout << endl << "OUT OF BOUNDS SET ACCESS" << endl;
  vtemp1 =  A1(vset1);



  cout << endl << "OUT OF BOUNDS PAIRED SET ACCESS" << endl;
  Matrix<unsigned int> Aind2(6,2,"Aind2");
  Vector<double> vtemp2(6,"vtemp2");
  Aind2 = findtrue(A2==0);
  vtemp2 =  A1(Aind2);


  cout << endl << "OUT BOUNDS (sequence,inetger) ACCESS" << endl;
  A2.resize() = A1(seq(0,1),2);
  cout << endl << "OUT BOUNDS (sequence,inetger) ACCESS" << endl;
  A2.resize() = A1(seq(1,2),0);


  cout << endl << "OUT BOUNDS (integer,sequence) ACCESS" << endl;
  A2.resize() = A1(2,seq(0,1));
  cout << endl << "OUT BOUNDS (integer,sequence) ACCESS" << endl;
  A2.resize() = A1(0,seq(1,2));


  cout << endl << "OUT BOUNDS (sequence,sequence) ACCESS" << endl;
  A2.resize() = A1(seq(0,1),seq(0,2));


  Vector<unsigned int> vset1b(2,"vset1b");
  vset1b = range<unsigned int>(1,2);
  Vector<unsigned int> vset2(2,"vset2");
  vset2 = range<unsigned int>(0,1);
  cout << endl << "OUT BOUNDS (sequence,set) ACCESS" << endl;
  A2.resize() = A1(seq(0,1),vset1b);
  cout << endl << "OUT BOUNDS (sequence,set) ACCESS" << endl;
  A2.resize() = A1(seq(0,2),vset2);
  cout << endl << "OUT BOUNDS (set,sequence) ACCESS" << endl;
  A2.resize() = A1(vset1b,seq(0,1));
  cout << endl << "OUT BOUNDS (set,sequence) ACCESS" << endl;
  A2.resize() = A1(vset2,seq(0,2));

  cout << endl << "OUT BOUNDS (set,set) ACCESS" << endl;
  A2.resize() = A1(vset1b,vset2);
  cout << endl << "OUT BOUNDS (integer,set) ACCESS" << endl;
  A2.resize() = A1(2,vset2);
  cout << endl << "OUT BOUNDS (integer,set) ACCESS" << endl;
  A2.resize() = A1(0,vset1b);
  cout << endl << "OUT BOUNDS (set,integer) ACCESS" << endl;
  A2.resize() = A1(vset2,2);
  cout << endl << "OUT BOUNDS (set,integer) ACCESS" << endl;
  A2.resize() = A1(vset1b,0);

  cout << endl << "INCOMPATIBLY-SIZED WRAPPERS IN EXPRESSION" << endl;
  A2.resize() = 2*A1(0,vset2) + A1(vset2,1);


  cout << endl << "INCOMPATIBLY-SIZED WRAPPERS IN EXPRESSION" << endl;
  A2.resize() = 2*A1(A1==0) + A1(vset2,1);


  cout << endl << "SIZE MISMATCH IN ASSIGNMENT TO WRAPPER" << endl;
  A1 = 2*A1(A1==0) ;

  cout << endl << "SIZE MISMATCH IN ASSIGNMENT TO WRAPPER" << endl;
  A1 = A1(A1==0) ;


  cout << endl << "SIZE MISMATCH IN ASSIGNMENT TO WRAPPER" << endl;
  A1 = 2*A1(seq(0,1),seq(0,0)) ;

  cout << endl << "SIZE MISMATCH IN ASSIGNMENT TO WRAPPER" << endl;
  A1 = A1(seq(0,1),seq(0,0)) ;



  Matrix<double> Mzero(0,0,"Mzero");
  cout<< endl << "assigment to matrix of different size (WARNING)" << endl;

  M1(0,0)=1;
  M1(0,1)=2;
  M1(1,0)=3;
  M1(1,1)=4;
  M1(2,0)=5;
  M1(2,1)=6;
   Mzero = M1;
  dispcr(Mzero);

  Matrix<double> Mzero2;
  cout<< endl << "assigment to vector expression of different size (WARNING)" << endl;
  M2(0,0)=10;
  M2(0,1)=20;
  M2(1,0)=30;
  M2(1,1)=40;
  M2(2,0)=50;
  M2(2,1)=60;
  Mzero2 = M1+M2;
  dispcr(Mzero2);


  return 0;
}
