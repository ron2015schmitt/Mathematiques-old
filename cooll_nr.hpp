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



#include <nr.h>
#include <nrutil.h>

// Interface to Numerical Recipes in C

// should develop a set of routines to convert easily and in-place
// between NRC matrices & vectors and COOLL matrices and vectors.


namespace cooll_nr {


  //
  // Given a matrix A, compute the singular value decomposition
  //
  //   A = U.W.transp(V)
  //
  // where U and V are orthogonal, and W is a diagonal matrix of singular values.
  // The singular values are positive and sorted by decreasing size.
  //
  // The m by n matrix A is the input (m>n)
  //

  inline int svd(
		 Matrix<double>& A, 
		 Matrix<double>& U, LAvector<double>& W, Matrix<double>& V )
  {
    const int M = A.Nrows();
    const int N = A.Ncols();       // Dimensions of matrix.

    /*
      assert(m >= n);
      assert(n == (int)W.size());
      assert(n == (int)V.Nrows() && n == (int)V.Ncols());
    */

    // Allocate NRC-style matrices and vectors.
    double **aandu = numrec::dmatrix(1,M,1,N);
    double **v = numrec::dmatrix(1,N,1,N);
    double *w = numrec::dvector(1,N);

    // Copy the input matrix.
    for (int i = 1; i <= M; ++i) {
      for (int j = 1; j <= N; ++j) {
	aandu[i][j] = A(i-1,j-1);
      }
    }


    numrec::svdcmp(aandu,M,N,w,v);
    numrec::svdsrt(aandu,M,N,w,v);


    // Copy the results
    for (int i = 1; i <= M; ++i) {
      for (int j = 1; j <= N; ++j) {
	U(i-1,j-1) = aandu[i][j];
      }
    }
    for (int i = 1; i <= N; ++i) {
      W[i-1] = w[i];
      for (int j = 1; j <= N; ++j) {
	V(i-1,j-1) = v[i][j];
      }
    }


    return 0;
  }



};
