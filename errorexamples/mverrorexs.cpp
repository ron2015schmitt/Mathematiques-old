
#import <iostream>

#define COOLL_CAREFUL




#import "cooll.hpp"

using namespace COOLL;


using namespace std;


int main()
{



 
  Matrix<double> M1(3,2,"M1");
  Matrix<double> M2(3,3,"M2");

  unsigned int i = 0;
  for(register unsigned int r=0; r<M1.Nrows(); r++) 
    for(register unsigned int c=0; c<M1.Ncols(); c++, i++) 
      M1(r,c) = i+1;
  dispcr(M1);

  i = 0;
  for(register unsigned int r=0; r<M2.Nrows(); r++) 
    for(register unsigned int c=0; c<M2.Ncols(); c++, i++) 
      M2(r,c) = 10*(i+1);
  dispcr(M2);

  LAvector<double> v1(3,"v1");
  /*
  M2.submat(0,2,1,2) = M1;
  dispcr(M2);

  dispcr(M1=-M1);

  M2.submat(1,2,0,1) = M1.submat(1,2,0,1);
  dispcr(M2);
  
  for(i=0; i<v1.size(); i++) 
    v1[i] = 100.0 + i;
  dispcr(v1);
  
  M2.submat(0,2,1,1) = v1;
  dispcr(M2);

  M2.submat(0,0,0,2) = v1;
  dispcr(M2);

  M2.row(1) = v1;
  dispcr(M2);

  M2.col(2) = M1.col(0);
  dispcr(M2);

  i = 0;
  for(register unsigned int r=0; r<M2.Nrows(); r++) 
    for(register unsigned int c=0; c<M2.Ncols(); c++, i++) 
      M2(r,c) = 10*(i+1);
  dispcr(M2);

  cout << "M2.row(2) = ~(M1.col(0))"<<endl;
  M2.row(2) = ~(M1.col(0));
  dispcr(M2);

  i = 0;
  for(register unsigned int r=0; r<M2.Nrows(); r++) 
    for(register unsigned int c=0; c<M2.Ncols(); c++, i++) 
      M2(r,c) = 10*(i+1);
  dispcr(M2);

  cout << "M2.col(0) = ~(M2.row(1))"<<endl;
  M2.col(0) = ~(M2.row(1));
  dispcr(M2);

  */

  cout << "v1 = M1"<<endl;
  v1 = M1;

  cout << "v1 = M1.row(1)"<<endl;
  v1 = M1.row(1);

  cout << "v1[seq(0,1)] = M1"<<endl;
  v1[seq(0,1)] = M1;

  cout << "v1[seq(0,1)] = M1.col(1)"<<endl;
  v1[seq(0,1)] = M1.col(1);

  LAvector<double> v3(6,"v3");
  cout << "v3 = M1"<<endl;
  v3 = M1;

  cout<<endl << "BAD EXPRESSION IN VECTOR OUTER PRODUCT"<<endl;
  LAvector<double> v4(3,"v4");
  LAvector<double> v5(3,"v5");
  Matrix<double> M3(3,3,"M3");
  M3 = (v4+v3)^v3;


  cout<<endl << "BAD EXPRESSION IN diag(M3)"<<endl;
  v5 = diag(M3+M1);


  cout<<endl << "BAD MATRIX EXPRESSION IN (MATRIX|VECTOR)"<<endl;
  v5 = (M3+M1)|v4;

  cout<<endl << "BAD MATRIX EXPRESSION IN (VECTOR|MATRIX)"<<endl;
  v5 = (v4|(M3+M1));

  cout<<endl << "BAD VECTOR EXPRESSION IN (MATRIX|VECTOR)"<<endl;
  v5 = M3|(v4+v3);

  cout<<endl << "BAD VECTOR EXPRESSION IN (VECTOR|MATRIX)"<<endl;
  v5 = (v3+v4)|M3;
  
  cout<<endl << "INCOMPATIBLE SIZES IN (MATRIX|VECTOR)"<<endl;
  v5 = M3|v3;

  cout<<endl << "INCOMPATIBLE SIZES IN (VECTOR|MATRIX)"<<endl;
  v5 = v3|M3;
  

  LAvector<complex<double> > vc1(3,"vc1");
  LAvector<complex<double> > vc2(3,"vc2");
  LAvector<complex<double> > vc3(6,"vc3");
  Matrix<complex<double> > MC1(3,3,"MC3");

  cout<<endl << "BAD REAL EXPRESSION IN REAL^COMPLEX VECTOR OUTER PRODUCT"<<endl;
  MC1 = (v3+v4)^vc1;

  cout<<endl << "BAD CMPLX EXPRESSION IN REAL^COMPLEX VECTOR OUTER PRODUCT"<<endl;
  MC1 = v4^(vc1+vc3);


  cout<<endl << "BAD REAL EXPRESSION IN COMPLEX^REAL VECTOR OUTER PRODUCT"<<endl;
  MC1 = vc1^(v3+v4);

  cout<<endl << "BAD CMPLX EXPRESSION IN COMPLEX^REAL VECTOR OUTER PRODUCT"<<endl;
  MC1 = (vc1+vc3)^v4;

  LAvector<complex<double> > vc4(3,"vc4");

  cout<<endl << "BAD MATRIX EXPRESSION IN (REALMATRIX|CMPLXVECTOR)"<<endl;
  vc4 = (M2+M1)|vc1;

  cout<<endl << "BAD MATRIX EXPRESSION IN (CMPLXVECTOR|REALMATRIX)"<<endl;
  vc4 = (vc1|(M2+M1));

  cout<<endl << "BAD MATRIX EXPRESSION IN (CMPLXMATRIX|REALVECTOR)"<<endl;
  vc4 = (MC1+M1)|v4;

  cout<<endl << "BAD MATRIX EXPRESSION IN (REALVECTOR|CMPLXMATRIX)"<<endl;
  vc4 = v4|(MC1+M1);


  cout<<endl << "BAD VECTOR EXPRESSION IN (REALMATRIX|CMPLXVECTOR)"<<endl;
  vc4 = M2|(vc1+vc3);

  cout<<endl << "BAD VECTOR EXPRESSION IN (CMPLXVECTOR|REALMATRIX)"<<endl;
  vc4 = (vc1+vc3)|M2;

  cout<<endl << "BAD VECTOR EXPRESSION IN (CMPLXMATRIX|REALVECTOR)"<<endl;
  vc4 = MC1|(v4+v3);

  cout<<endl << "BAD VECTOR EXPRESSION IN (REALVECTOR|CMPLXMATRIX)"<<endl;
  vc4 = (v3+v4)|MC1;


  cout<<endl << "INCOMPATIBLE SIZES IN (REALMATRIX|CMPLXVECTOR)"<<endl;
  vc4 = M1|vc1;

  cout<<endl << "INCOMPATIBLE SIZES IN (CMPLXVECTOR|REALMATRIX)"<<endl;
  vc4 = vc3|M2;

  cout<<endl << "INCOMPATIBLE SIZES IN (CMPLXMATRIX|REALVECTOR)"<<endl;
  vc4 = MC1|v3;

  cout<<endl << "INCOMPATIBLE SIZES IN (REALVECTOR|CMPLXMATRIX)"<<endl;
  vc4 = v3|MC1;


  cout<<endl << "BAD VECTOR EXPRESSION IN diagmat(vector)"<<endl;
  M1.resize() = diagmat(v3+v4);


  return 0;

}

