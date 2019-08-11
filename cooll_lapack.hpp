// START-OF-NOTICE
// Copyright 2003, Columbia University
// Authors: Ron Schmitt
//
//
// This file is part of the Columbia Object Oriented 
// Linear-algebra Library (COOLL).
//
// You should have received a copy of the License Agreement for the
// COOLL along with the software;  see the file LICENSE.  
// If not, contact
// Department of Applied Physics and Applied Mathematics
// Columbia Univeristy 
// New York, NY 10027
//
// Permission to modify the code and to distribute modified code is
// granted, provided the text of this NOTICE is retained, a notice that
// the code was modified is included with the above COPYRIGHT NOTICE and
// with the COPYRIGHT NOTICE in the LICENSE file, and that the LICENSE
// file is distributed with the modified code.
//
// LICENSOR MAKES NO REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED.
// By way of example, but not limitation, Licensor MAKES NO
// REPRESENTATIONS OR WARRANTIES OF MERCHANTABILITY OR FITNESS FOR ANY
// PARTICULAR PURPOSE OR THAT THE USE OF THE LICENSED SOFTWARE COMPONENTS
// OR DOCUMENTATION WILL NOT INFRINGE ANY PATENTS, COPYRIGHTS, TRADEMARKS
// OR OTHER RIGHTS.
//
// END-OF-NOTICE
//===========================================================================

#ifndef COOLL_H
#include "cooll.hpp"
#endif

#include <complex>


// Interface to LAPACK
// 
// LAPACK uses FORTRAN conventions for storing arrays, which is
// "Column major" order.  Thus standard C 2D arrays must be 
// transposed before sending.
// 
// LAPACK DATATYPES:
//  double precision for real data, and complex data
//  complex types are ordered: {real, complex}
//  which is the same as the STL complex datatype


namespace cooll_lapack {
  using namespace COOLL;

  // shoudl probably do check that FINT is a 32 bit int.
  typedef int FINT;


  extern "C" {

    // DRIVER: std::complex double SVD 
    void zgesvd_(
		 const char*      jobu,
		 const char*      jobvt,
		 const FINT*       m,
		 const FINT*       n,
		 std::complex<double>* a,
		 const FINT*       lda,
		 double*          s,
		 std::complex<double>* u,
		 const FINT*       ldu,
		 std::complex<double>* vt,
		 const FINT*       ldvt,
		 std::complex<double>* work,
		 const FINT*       lwork,
		 double*          rwork,
		 FINT*             info
		 );

  };


  //
  // Given a matrix A, compute the singular value decomposition
  //
  //   A = (U|S|~adj(V))
  //
  // The singular values are positive and sorted by decreasing size.
  //
  //
  // A = MxN complex input matrix
  // U = MxM complex unitary matrix
  // S = MxN diagonal real matrix, represented using min(M,N) real vector
  // V = NxN complex unitary matrix

  inline int svd(
		 Matrix<std::complex<double> >& A, 
		 Matrix<std::complex<double> >& U, LAvector<double>& S, 
		 Matrix<std::complex<double> >& V )  {

    // place checks here


    const unsigned int M = A.Nrows();
    const unsigned int N = A.Ncols();       // Dimensions of matrix.
    const unsigned int minMN = std::min(M,N); 

    Matrix<std::complex<double> > Atemp(N,M,"Atemp");
    // need to pass transpose because lapack uses col major form
    Atemp = ~A;

    if ( (U.Nrows()!=M) || (U.Ncols()!=M) ) {
#ifdef COOLL_CAREFUL
      svd_bad_U(U.objectID(),M);
#endif
      U.resize(M,M);
    }
    if (S.size()!=minMN) {
#ifdef COOLL_CAREFUL
      svd_bad_S(S.objectID(),minMN);
#endif
      S.resize(minMN);
    }
    if ((V.Nrows()!=N) || (V.Ncols()!=N) ) {
#ifdef COOLL_CAREFUL
      svd_bad_V(V.objectID(),N);
#endif
      V.resize(N,N);
    }
    
    const FINT Mfint = static_cast<FINT>(M); 
    const FINT Nfint = static_cast<FINT>(N); 
    const FINT NRwork = 5*static_cast<FINT>(minMN); 
    LAvector<double> Rwork(NRwork,"Rwork");


    LAvector<std::complex<double> > Work(1,"Work");
    const char jobu =  'A';
    const char jobvt = 'A';
    std::complex<double>* aptr = &Atemp(0,0);
    const FINT lda = Mfint;
    double* sptr = &S[0];
    std::complex<double>* uptr = &U(0,0);
    const FINT ldu = Mfint;
    std::complex<double>* vtptr = &V(0,0);
    const FINT ldvt = Nfint;
    std::complex<double>* workptr =&Work[0];
    double* rworkptr = &Rwork[0];
    FINT info = 0;


    // do a "work query" first to determine the optimal work array size
    FINT lwork = -1;

    zgesvd_(&jobu, &jobvt, &Mfint, &Nfint, aptr, &lda, sptr, uptr, &ldu, 
	    vtptr, &ldvt, workptr, &lwork, rworkptr, &info);

    lwork = static_cast<FINT>(Work[0].real());
    Work.resize(lwork);
    workptr =&Work[0];

    /*
      print(jobu);print(jobvt);print(M);printcr(N);
      print(aptr);print(lda); print(sptr); printcr(uptr);
      print(ldu);print(vtptr);print(ldvt);printcr(workptr);
      print(lwork);print(rworkptr);printcr(info);
    */

    zgesvd_(&jobu, &jobvt, &Mfint, &Nfint, aptr, &lda, sptr, uptr, &ldu, 
	    vtptr, &ldvt, workptr, &lwork, rworkptr, &info);

    //LAPACK returns U in col major form, must transpose
    U.transpose();
    //LAPACK returns ~adj(V) in col major form
    V=conj(V);
    
    return static_cast<int>(info);
  }


  


};
