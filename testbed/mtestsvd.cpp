
 


#include "cooll.hpp"
using namespace COOLL;

#include "cooll_lapack.hpp"

#include "testlib.hpp"

#include <iostream>
using namespace std;


#include <vector>


#include <cmath>



int main()
{

  typedef complex<double> cd;

  
  int rc;

  Matrix<complex<double> > A1(3,3,"A1");
  Matrix<complex<double> > U1(3,3,"U1");
  LAvector<double> S1(3,"S1");
  Matrix<complex<double> > V1(3,3,"V1");


  // SVD test #1 
  A1(0,0) = 1.0;
  A1(0,1) = 2.0;
  A1(0,2) = 3.0;
  A1(1,0) = 4.0;
  A1(1,1) = 5.0;
  A1(1,2) = 6.0;
  A1(2,0) = 7.0;
  A1(2,1) = 8.0;
  A1(2,2) = 9.0;
  complex<double>  ans1[] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
  mcompare(A1,ans1);

  rc = cooll_lapack::svd(A1,U1,S1,V1);
  compare(rc,0);

  complex<double>  ans1a[] = {cd(-0.214837238368397,0.0), cd( 0.887230688346371,0.0), cd( 0.408248290463862,0.0),
			      cd(-0.520587389464737,0.0), cd( 0.249643952988297,0.0), cd(-0.816496580927726,0.0),
			      cd(-0.826337540561078,0.0), cd(-0.387942782369774,0.0), cd(0.408248290463863,0.0)};
  msoftcompare(U1,ans1a,8);

  double  ans1b[] = {16.8481033526142,1.06836951455471,0.0};
  vsoftcompare(S1,ans1b,8);

                         
                        
                        

  complex<double>  ans1c[] = {cd(-0.479671177877772,0.0), cd(-0.77669099032156,0.0), cd(-0.408248290463863,0.0),
			      cd(-0.572367793972062,0.0), cd(-0.0756864701045585,0.0), cd(0.816496580927726,0.0),
			      cd(-0.665064410066353,0.0), cd( 0.625318050112443,0.0), cd(-0.408248290463863,0.0)};
  msoftcompare(V1,ans1c,8);


  // SVD test #2

  A1(0,0) = 3.5355;
  A1(0,1) = 1.0;
  A1(0,2) = -1.0;
  A1(1,0) = 0.0;
  A1(1,1) = 2.1213;
  A1(1,2) = 2.1213;
  A1(2,0) = 3.5355;
  A1(2,1) = -1.0;
  A1(2,2) = 1.0;
  complex<double> ans2[] = {3.5355,1.0,-1.0,0.0,2.1213,2.1213,3.5355,-1.0,1.0};
  mcompare(A1,ans2);

  rc = cooll_lapack::svd(A1,U1,S1,V1);
  compare(rc,0);

  complex<double>  ans2a[] = {cd(-0.707106781186547,0.0), cd(0.0,0.0), cd(-0.707106781186547,0.0),
			      cd(0.0,0.0),               cd(1.0,0.0),  cd(0.0,0.0),
			      cd(-0.707106781186547,0.0), cd(0.0,0.0), cd(0.707106781186548,0.0)};
  msoftcompare(U1,ans2a,8);

  double  ans2b[] = { 4.99995204977008, 2.99997122986205, 2.0};
  vsoftcompare(S1,ans2b,8);

  complex<double>  ans2c[] = {cd(-1.0,0.0), cd(0.0,0.0), cd(0.0,0.0),
			      cd(0.0,0.0), cd(0.70710678118654,0.0), cd(-0.70710678118654,0.0),
			      cd(0.0,0.0), cd(0.70710678118654,0.0), cd(+0.70710678118654,0.0)};
  msoftcompare(V1,ans2c,8);


  // SVD test #3
  Matrix<complex<double> > A2(3,2,"A2");
  Matrix<complex<double> > U2(3,3,"U2");
  LAvector<double> S2(2,"S2");
  Matrix<complex<double> > V2(2,2,"V2");
  A2(0,0) = 1.0;
  A2(0,1) = 2.0;
  A2(1,0) = 3.0;
  A2(1,1) = 4.0;
  A2(2,0) = 5.0;
  A2(2,1) = 6.0;
  complex<double>  ans3[] = {1.0,2.0,3.0,4.0,5.0,6.0};
  mcompare(A2,ans3);

  rc = cooll_lapack::svd(A2,U2,S2,V2);
  compare(rc,0);


  complex<double>  ans3a[] = {cd(-0.229847696400071,0.0), cd(0.883461017698525,0.0), cd(0.408248290463863,0.0),
			      cd(-0.524744818760294,0.0), cd(0.240782492132546,0.0), cd(-0.816496580927726,0.0),
			      cd(-0.819641941120516,0.0), cd(-0.401896033433432,0.0), cd(0.408248290463863,0.0)};
  msoftcompare(U2,ans3a,8);

  double  ans3b[] = {9.52551809156511,0.514300580658644};
  vsoftcompare(S2,ans3b,8);


  complex<double>  ans3c[] = {cd(-0.61962948382934,0.0), cd(-0.784894453267052,0.0),
			      cd(-0.784894453267052,0.0), cd(+0.61962948382934,0.0)};
  msoftcompare(V2,ans3c,8);


  // SVD test #4
  Matrix<complex<double> > A3(2,3,"A3");
  Matrix<complex<double> > U3(2,2,"U3");
  LAvector<double> S3(2,"S3");
  Matrix<complex<double> > V3(3,3,"V3");
  A3(0,0) = 1.0;
  A3(0,1) = 2.0;
  A3(0,2) = 3.0;
  A3(1,0) = 4.0;
  A3(1,1) = 5.0;
  A3(1,2) = 6.0;
  complex<double>  ans4[] = {1.0,2.0,3.0,4.0,5.0,6.0};
  mcompare(A3,ans4);

  rc = cooll_lapack::svd(A3,U3,S3,V3);
  compare(rc,0);

             
                 

  complex<double>  ans4a[] = {cd(-0.386317703118612,0.0), cd(-0.922365780077058,0.0),
			      cd(-0.922365780077058,0.0), cd(0.386317703118612,0.0)};
  msoftcompare(U3,ans4a,8);

  double  ans4b[] = { 9.50803200069572,0.772869635673484};
  vsoftcompare(S3,ans4b,8);

  complex<double>  ans4c[] = {cd(-0.428667133548626,0.0), cd(0.805963908589297,0.0), cd(0.408248290463864,0.0),
			      cd(-0.566306918848035,0.0), cd(0.112382414096594,0.0), cd(-0.816496580927726,0.0),
			      cd(-0.703946704147444,0.0), cd(-0.58119908039611,0.0), cd(0.408248290463864,0.0)};
  msoftcompare(V3,ans4c,8);

  cout << "<LAPACK SVD tests passed>"<<endl;
  return 0;

 

}
