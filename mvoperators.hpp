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




#ifndef MVOPERATORS_H
#define MVOPERATORS_H 1


#include <string>
#include <sstream>


namespace COOLL {




  // outer product: vector ^ vector

  template <class D, class A, class B> 
  inline Matrix<D>
  operator^(const VorE<D,A>& a, const VorE<D,B>& b)
  {
    const unsigned int NC = a.size();
    const unsigned int NR = b.size();
#ifdef COOLL_CAREFUL
    std::string sa = a.debugtxt();
    if (a.vetype() != VE_LAvector) 
      sa = "(" + sa + ")";
    std::string sb = b.debugtxt();
    if (b.vetype() != VE_LAvector) 
      sb = "(" + sb + ")";
    std::string name= sa + "^"+  sb;
    if (  vexpr_is_size_bad(a) || vexpr_is_size_bad(b)  ) { 
      vbad_expr_in_binary(a,b,"","^");
      Matrix<D> y(0,0,name);
      return y;
    }
    Matrix<D> y(NR,NC,name);
#else
    Matrix<D> y(NR,NC);
#endif

    register unsigned int i=0;
    for(register unsigned int r=0; r < NR; r++) 
      for(register unsigned int c=0; c < NC; c++,i++) 
	y(i) = a[c]*b[r];   

    return  y;
  }



  // vector = diagonal(Matrix)

  template <class D, class A> 
  inline LAvector<D>
  diag(const MorE<D,A>& a)
  {
    unsigned int Nmin;
    if (a.Nrows() < a.Ncols())
      Nmin=a.Nrows();
    else
      Nmin=a.Ncols();
    const unsigned int N=Nmin;
#ifdef COOLL_CAREFUL
    std::string name= "diag("+a.debugtxt() +")";
    if ( mexpr_is_size_bad(a.size()) ){ 
      mbad_expr_in_unary(a,"diag");
      LAvector<D> v(0,name);
      return v;
    }
    LAvector<D> v(N,name);
#else
    LAvector<D> v(N);
#endif

    for (register unsigned int i = 0; i < N ; i++ )
      v[i] = a(i,i);
    return v;
  }





  // diagmat(vector)

  template <class D, class A> 
  inline Matrix<D>
  diagmat(const VorE<D,A>& a)
  {
    const unsigned int N = a.size();
#ifdef COOLL_CAREFUL
    std::string name;
    name = "diagmat(" + a.debugtxt() + ")";
    if (  vexpr_is_size_bad(a) ) { 
      vbad_expr_in_unary(a,"diagmat");
      Matrix<D> y(0,0,name);
      return y;
    }
    Matrix<D> y(N,N,name);
#else
    Matrix<D> y(N,N);
#endif

    for(register unsigned int i=0; i < N; i++) 
      y(i,i) = a[i];   

    return  y;
  }

   


  // dotproduct operator (matrix|vector)

  template <class D, class A, class B> 
  inline LAvector<D>
  operator|( const MorE<D,A>& a, const  VorE<D,B>& b ) {
    const unsigned int NR = a.Nrows();
    const unsigned int M = a.Ncols();
    const unsigned int C1 = NR*M;
    const unsigned int C2 = M-1;

#ifdef COOLL_CAREFUL
    std::string sa = a.debugtxt();
    if (a.metype() != ME_Matrix) 
      sa = "(" + sa + ")";
    std::string sb = b.debugtxt();
    if (b.vetype() != VE_LAvector) 
      sb = "(" + sb + ")";
    std::string name= sa + "|"+  sb;
    const unsigned int Mb = b.size();

    if (mexpr_is_size_bad(a.size()) ) { 
      mbad_expr_in_unary(a,""); 
      LAvector<D> y(0,name);
      return y;
    } else if (  vexpr_is_size_bad(b)  ) { 
      vbad_expr_in_unary(b,"");
      LAvector<D> y(0,name);
      return y;
    } else if (M!=Mb) {
      mvbad_dot_product(a,b);
      LAvector<D> y(0,name);
      return y;
    }
    LAvector<D> y(NR,name);
#else
    LAvector<D> y(NR);
#endif

    register unsigned int i = 0;
    for(register unsigned int n=0; n < C1; n+=M, i++) {
      unsigned int j = n;
      unsigned int k = 0;
       // using a local variable for the accumation saves a lot of CPU Time!!
      D result = a(j) * b[k];
      do {
	result += a((j+=1)) * b[(k+=1)];
      } while (k<C2);
      y[i] = result;   
    }
    return  y;
  }



  // dotproduct operator (vector|matrix)

  template <class D, class A, class B> 
  inline LAvector<D>
  operator|( const VorE<D,A>& a, const  MorE<D,B>& b ) {
    const unsigned int NC = b.Ncols();
    const unsigned int M = b.Nrows();

#ifdef COOLL_CAREFUL
    std::string sa = a.debugtxt();
    std::string sb = b.debugtxt();
    if (a.vetype() != VE_LAvector) 
      sa = "(" + sa + ")";
    if (b.metype() != ME_Matrix) 
      sb = "(" + sb + ")";
    std::string name= sa + "|"+  sb;
    const unsigned int Ma = a.size();
    if (mexpr_is_size_bad(b.size()) ) { 
      mbad_expr_in_unary(b,""); 
      LAvector<D> y(0,name);
      return y;
    } else if (  vexpr_is_size_bad(a)  ) { 
      vbad_expr_in_unary(a,"");
      LAvector<D> y(0,name);
      return y;
    } else if (M!=Ma) {
      vmbad_dot_product(a,b);
      LAvector<D> y(0,name);
      return y;
    }
    LAvector<D> y(NC,name);
#else
    LAvector<D> y(NC);
#endif

    register unsigned int i = 0;
    for(register unsigned int c=0; c < NC; c++,i++) {
      unsigned int j = 0;
      unsigned int k = c;
      const unsigned int C2 = M-1;
      // using a local variable for the accumation saves a lot of CPU Time!!
      D result = a[j] * b(k);
      do {
	result += a[(j+=1)] * b((k+=NC));
      } while (j<C2);
      y[i] = result;   
    }
    return  y;
  }




};

#endif 
