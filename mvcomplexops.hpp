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




#ifndef MVCOMPLEXOPS_H
#define MVCOMPLEXOPS_H 1


#include <string>
#include <sstream>


namespace COOLL {




  // outer product: complexvector ^ realvector

  template <class D, class A, class B> 
  inline Matrix<std::complex<D> >
  operator^(const VorE<std::complex<D>,A>& a, const VorE<D,B>& b)
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
      Matrix<std::complex<D> > y(0,0,name);
      return y;
    }
    Matrix<std::complex<D> > y(NR,NC,name);
#else
    Matrix<std::complex<D> > y(NR,NC);
#endif

    register unsigned int i=0;
    for(register unsigned int r=0; r < NR; r++) 
      for(register unsigned int c=0; c < NC; c++,i++) 
	y(i) = a[c]*b[r];   

    return  y;
  }


  // outer product: realvector ^ complexvector

  template <class D, class A, class B> 
  inline Matrix<std::complex<D> >
  operator^(const VorE<D,A>& a, const VorE<std::complex<D>,B>& b)
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
      Matrix<std::complex<D> > y(0,0,name);
      return y;
    }
    Matrix<std::complex<D> > y(NR,NC,name);
#else
    Matrix<std::complex<D> > y(NR,NC);
#endif

    register unsigned int i=0;
    for(register unsigned int r=0; r < NR; r++) 
      for(register unsigned int c=0; c < NC; c++,i++) 
	y(i) = a[c]*b[r];   

    return  y;
  }









  // dotproduct operator (complex matrix|real vector)

  template <class D, class A, class B> 
  inline LAvector<std::complex<D> >
  operator|( const MorE<std::complex<D> ,A>& a, const  VorE<D,B>& b ) {
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
      LAvector<std::complex<D> > y(0,name);
      return y;
    } else if (  vexpr_is_size_bad(b)  ) { 
      vbad_expr_in_unary(b,"");
      LAvector<std::complex<D> > y(0,name);
      return y;
    } else if (M!=Mb) {
      mvbad_dot_product(a,b);
      LAvector<std::complex<D> > y(0,name);
      return y;
    }
    LAvector<std::complex<D> > y(NR,name);
#else
    LAvector<std::complex<D> > y(NR);
#endif

    register unsigned int i = 0;
    for(register unsigned int n=0; n < C1; n+=M, i++) {
      unsigned int j = n;
      unsigned int k = 0;
       // using a local variable for the accumation saves a lot of CPU Time!!
      std::complex<D>  result = a(j) * b[k];
      do {
	result += a((j+=1)) * b[(k+=1)];
      } while (k<C2);
      y[i] = result;   
    }
    return  y;
  }



  // dotproduct operator (realvector|complexmatrix)

  template <class D, class A, class B> 
  inline LAvector<std::complex<D> >
  operator|( const VorE<D,A>& a, const  MorE<std::complex<D> ,B>& b ) {
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
      LAvector<std::complex<D> > y(0,name);
      return y;
    } else if (  vexpr_is_size_bad(a)  ) { 
      vbad_expr_in_unary(a,"");
      LAvector<std::complex<D> > y(0,name);
      return y;
    } else if (M!=Ma) {
      vmbad_dot_product(a,b);
      LAvector<std::complex<D> > y(0,name);
      return y;
    }
    LAvector<std::complex<D> > y(NC,name);
#else
    LAvector<std::complex<D> > y(NC);
#endif

    register unsigned int i = 0;
    for(register unsigned int c=0; c < NC; c++,i++) {
      unsigned int j = 0;
      unsigned int k = c;
      const unsigned int C2 = M-1;
      // using a local variable for the accumation saves a lot of CPU Time!!
      std::complex<D>  result = a[j] * b(k);
      do {
	result += a[(j+=1)] * b((k+=NC));
      } while (j<C2);
      y[i] = result;   
    }
    return  y;
  }







  // dotproduct operator (realmatrix|complexvector)

  template <class D, class A, class B> 
  inline LAvector<std::complex<D> >
  operator|( const MorE<D,A>& a, const  VorE<std::complex<D> ,B>& b ) {
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
      LAvector<std::complex<D> > y(0,name);
      return y;
    } else if (  vexpr_is_size_bad(b)  ) { 
      vbad_expr_in_unary(b,"");
      LAvector<std::complex<D> > y(0,name);
      return y;
    } else if (M!=Mb) {
      mvbad_dot_product(a,b);
      LAvector<std::complex<D> > y(0,name);
      return y;
    }
    LAvector<std::complex<D> > y(NR,name);
#else
    LAvector<std::complex<D> > y(NR);
#endif

    register unsigned int i = 0;
    for(register unsigned int n=0; n < C1; n+=M, i++) {
      unsigned int j = n;
      unsigned int k = 0;
       // using a local variable for the accumation saves a lot of CPU Time!!
      std::complex<D>  result = a(j) * b[k];
      do {
	result += a((j+=1)) * b[(k+=1)];
      } while (k<C2);
      y[i] = result;   
    }
    return  y;
  }



  // dotproduct operator (complexvector|realmatrix)

  template <class D, class A, class B> 
  inline LAvector<std::complex<D> >
  operator|( const VorE<std::complex<D> ,A>& a, const  MorE<D,B>& b ) {
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
      LAvector<std::complex<D> > y(0,name);
      return y;
    } else if (  vexpr_is_size_bad(a)  ) { 
      vbad_expr_in_unary(a,"");
      LAvector<std::complex<D> > y(0,name);
      return y;
    } else if (M!=Ma) {
      vmbad_dot_product(a,b);
      LAvector<std::complex<D> > y(0,name);
      return y;
    }
    LAvector<std::complex<D> > y(NC,name);
#else
    LAvector<std::complex<D> > y(NC);
#endif

    register unsigned int i = 0;
    for(register unsigned int c=0; c < NC; c++,i++) {
      unsigned int j = 0;
      unsigned int k = c;
      const unsigned int C2 = M-1;
      // using a local variable for the accumation saves a lot of CPU Time!!
      std::complex<D>  result = a[j] * b(k);
      do {
	result += a[(j+=1)] * b((k+=NC));
      } while (j<C2);
      y[i] = result;   
    }
    return  y;
  }






};

#endif 
