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




#ifndef MOPERATORS_H
#define MOPERATORS_H 1


#include <string>
#include <sstream>

namespace COOLL {



  /************************************************************
   *               Templates for Binary Operators
   *
   * D = data type, e.g. double
   * A = either an Matrix or a Mexpr
   * B = either an Matrix or a Mexpr
   ************************************************************
   */

  // matrix + matrix

  template <class D, class A, class B> 
  inline MBinOp<D,MorE<D,A>,MorE<D,B>,ApAdd<D> > 
  operator+(const MorE<D,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<D,MorE<D,A>,MorE<D,B>,ApAdd<D> >(a,b);
  }



  // matrix - matrix

  template <class D, class A, class B> 
  inline MBinOp<D,MorE<D,A>,MorE<D,B>,ApSubtract<D> > 
  operator-(const MorE<D,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<D,MorE<D,A>,MorE<D,B>,ApSubtract<D> >(a,b);
  }


  // matrix * matrix

  template <class D, class A, class B> 
  inline MBinOp<D,MorE<D,A>,MorE<D,B>,ApMultiply<D> > 
  operator*(const MorE<D,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<D,MorE<D,A>,MorE<D,B>,ApMultiply<D> >(a,b);
  }


  // matrix / matrix

  template <class D, class A, class B> 
  inline MBinOp<D,MorE<D,A>,MorE<D,B>,ApDivide<D> > 
  operator/(const MorE<D,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<D,MorE<D,A>,MorE<D,B>,ApDivide<D> >(a,b);
  }



  // dotproduct operator (a|b)

  template <class D, class A, class B> 
  inline Matrix<D>
  operator|( const MorE<D,A>& a, const  MorE<D,B>& b ) {
    const unsigned int NR = a.Nrows();
    const unsigned int NC = b.Ncols();
    const unsigned int M = a.Ncols();
    const unsigned int C1 = NR*M;


#ifdef COOLL_CAREFUL
    std::string name= a.debugtxt() + "|"+  b.debugtxt();
    const unsigned int Mb = b.Nrows();
    if ( (mexpr_is_size_bad(a.size())) || (mexpr_is_size_bad(b.size())) ){ 
      mbad_expr_in_binary(a,b,"","|");
      Matrix<D> y(0,0,name);
      return y;
    } else if (M!=Mb) {
      mbad_dot_product(a,b);
      Matrix<D> y(0,0,name);
      return y;
    }
    Matrix<D> y(NR,NC,name);
#else
    Matrix<D> y(NR,NC);
#endif

    register unsigned int i = 0;
    for(register unsigned int n=0; n < C1; n+=M) 
      for(register unsigned int c=0; c < NC; c++,i++) {
	unsigned int j = n;
	unsigned int k = c;
	const unsigned int C2 = n+M-1;
	// using a local variable for the accumation saves a lot of CPU Time!!
	D result = a(j) * b(k);
	while (j<C2){
	  result += a((j+=1)) * b((k+=NC));
	} 
	y(i) = result;   
      }
    return  y;
  }





  /************************************************************
   *               Templates for matrix/scalar Operators
   *
   * D = data type, e.g. double (matrix and scalar must be of same data type)
   * A = either an Matrix or a Mexpr
   ************************************************************
   */


  // matrix + scalar

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,ApAdd<D> > 
  operator+(const MorE<D,A>& a, const D b)
  {
    return  MatOpScal<D,MorE<D,A>,ApAdd<D> >(a,b);
  }

  // scalar + matrix

  template <class D, class B>
  inline ScalOpMat<D,MorE<D,B>,ApAdd<D> > 
  operator+(const D a, const MorE<D,B>& b )
  {
    return  ScalOpMat<D,MorE<D,B>,ApAdd<D> > (a,b);
  }


  // matrix - scalar

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,ApSubtract<D> > 
  operator-(const MorE<D,A>& a, const D b)
  {
    return  MatOpScal<D,MorE<D,A>,ApSubtract<D> >(a,b);
  }

  // scalar - matrix

  template <class D, class B>
  inline ScalOpMat<D,MorE<D,B>,ApSubtract<D> > 
  operator-(const D a, const MorE<D,B>& b )
  {
    return  ScalOpMat<D,MorE<D,B>,ApSubtract<D> > (a,b);
  }

  // matrix * scalar

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,ApMultiply<D> > 
  operator*(const MorE<D,A>& a, const D b)
  {
    return  MatOpScal<D,MorE<D,A>,ApMultiply<D> >(a,b);
  }

  // scalar * matrix

  template <class D, class B>
  inline ScalOpMat<D,MorE<D,B>,ApMultiply<D> > 
  operator*(const D a, const MorE<D,B>& b )
  {
    return  ScalOpMat<D,MorE<D,B>,ApMultiply<D> > (a,b);
  }

  // matrix / scalar

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,ApDivide<D> > 
  operator/(const MorE<D,A>& a, const D b)
  {
    return  MatOpScal<D,MorE<D,A>,ApDivide<D> >(a,b);
  }

  // scalar / matrix

  template <class D, class B>
  inline ScalOpMat<D,MorE<D,B>,ApDivide<D> > 
  operator/(const D a, const MorE<D,B>& b )
  {
    return  ScalOpMat<D,MorE<D,B>,ApDivide<D> > (a,b);
  }






  // the following are defined for convenience

  // matrix + (int scalar)

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,ApAdd<D> > 
  operator+(const MorE<D,A>& a, const int b)
  {
    return  MatOpScal<D,MorE<D,A>,ApAdd<D> >(a,b);
  }

  // (int scalar) + matrix

  template <class D, class B>
  inline ScalOpMat<D,MorE<D,B>,ApAdd<D> > 
  operator+(const int a, const MorE<D,B>& b )
  {
    return  ScalOpMat<D,MorE<D,B>,ApAdd<D> > (a,b);
  }


  // matrix - (int scalar)

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,ApSubtract<D> > 
  operator-(const MorE<D,A>& a, const int b)
  {
    return  MatOpScal<D,MorE<D,A>,ApSubtract<D> >(a,b);
  }

  // (int scalar) - matrix

  template <class D, class B>
  inline ScalOpMat<D,MorE<D,B>,ApSubtract<D> > 
  operator-(const int a, const MorE<D,B>& b )
  {
    return  ScalOpMat<D,MorE<D,B>,ApSubtract<D> > (a,b);
  }

  // matrix * (int scalar)

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,ApMultiply<D> > 
  operator*(const MorE<D,A>& a, const int b)
  {
    return  MatOpScal<D,MorE<D,A>,ApMultiply<D> >(a,b);
  }

  // (int scalar) * matrix

  template <class D, class B>
  inline ScalOpMat<D,MorE<D,B>,ApMultiply<D> > 
  operator*(const int a, const MorE<D,B>& b )
  {
    return  ScalOpMat<D,MorE<D,B>,ApMultiply<D> > (a,b);
  }

  // matrix / (int scalar)

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,ApDivide<D> > 
  operator/(const MorE<D,A>& a, const int b)
  {
    return  MatOpScal<D,MorE<D,A>,ApDivide<D> >(a,b);
  }

  // (int scalar) / matrix

  template <class D, class B>
  inline ScalOpMat<D,MorE<D,B>,ApDivide<D> > 
  operator/(const int a, const MorE<D,B>& b )
  {
    return  ScalOpMat<D,MorE<D,B>,ApDivide<D> > (a,b);
  }




  /****************************************************************
   *               Templates for Unary Operators & Unary Functions
   *
   * D = data type, e.g. double 
   * A = either an Matrix or a Mexpr
   *****************************************************************
   */

  // +(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApPlus<D> > 
  operator+(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApPlus<D> >(a);
  }


  // -(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApMinus<D> > 
  operator-(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApMinus<D> >(a);
  }


  // mcast(matrix)

  template <class D2, class D1, class A> 
  inline MFuncOp<D2,MorE<D1,A>,ApCast<D1,D2> > 
  mcast(const MorE<D1,A>& a)
  {
    return  MFuncOp<D2,MorE<D1,A>,ApCast<D1,D2> >(a);
  }


  // mcast(matrix,nr,nc)

  template <class D2, class D1, class A> 
  inline MFuncReshape<D2,MorE<D1,A>,ApCast<D1,D2> > 
  mcast(const MorE<D1,A>& a, const unsigned int nr, const unsigned int nc)
  {
    return  MFuncReshape<D2,MorE<D1,A>,ApCast<D1,D2> >(a,nr,nc);
  }



  // mcast(vector)

  template <class D2, class D1, class A> 
  inline MFuncVec<D2,VorE<D1,A>,ApCast<D1,D2> > 
  mcast(const VorE<D1,A>& a, const unsigned int NR, const unsigned int NC)
  {
    return  MFuncVec<D2,VorE<D1,A>,ApCast<D1,D2> >(a,NR,NC);
  }


  // mcast(C-Array)

  template <class D2, class D1> 
  inline Matrix<D2> 
  mcast(const D1* dptr, const unsigned int NR, const unsigned int NC)
  {
#ifdef COOLL_CAREFUL
    Matrix<D2> m(NR,NC,"mcast(C-array)");
#else
    Matrix<D2> m(NR,NC);
#endif
    for(unsigned int i = 0; i<NR*NC; i++) 
      m(i) = static_cast<D2>(dptr[i]);
    return  m;
  }



  // mcast(FortranArray)

  template <class D2, class D1> 
  inline Matrix<D2> 
  mcastF(const D1* dptr, const unsigned int NR, const unsigned int NC)
  {
#ifdef COOLL_CAREFUL
    Matrix<D2> y(NR,NC,"mcast(Fortran-array)");
#else
    Matrix<D2> y(NR,NC);
#endif
    const unsigned int C1 = NR*NC-NR;
    register unsigned int i = 0;
    for(register unsigned int c = 0; c < NR; c++, i++) {
      register unsigned int k = c;
      y(i) = static_cast<D2>(dptr[k]);
      while (k<C1) {
	y((i+=1)) = static_cast<D2>(dptr[k+=NR]);
      } 
    }
    return y;
  }




  
  // transpose ~(matrix)

  template <class D, class A> 
  inline Matrix<D>
  operator~(const MorE<D,A>& a)
  {
    // 0.75 secs
    const unsigned int NR = a.Nrows();
    const unsigned int NC = a.Ncols();
    const unsigned int NN = a.size();
    const unsigned int C1 = NN-NC;
    

#ifdef COOLL_CAREFUL
    std::string name=a.debugtxt();
    if (a.metype()==ME_Matrix)
      name = "~" + name;
    else
      name = "~("+name+")";

    if ( mexpr_is_size_bad(a.size()) ){ 
      mbad_expr_in_unary(a,"~");
      Matrix<D> y(0,0,name);
      return y;
    }
    Matrix<D> y(NC,NR,name);
#else
    Matrix<D> y(NC,NR);
#endif


    register unsigned int i = 0;
    for(register unsigned int c = 0; c < NC; c++, i++) {
      register unsigned int k = c;
      y(i) = a(k);
      while (k<C1) {
	y((i+=1)) = a((k+=NC));
      } 
    }
    return  y;
  }





  /****************************************************************
   * functions that convert matrices into other objects
   *****************************************************************
   */


  // toCarray(matrix)

  template <class D2, class D1, class A> 
  inline D2*
  toCarray(const MorE<D1,A>& m) {

#ifdef COOLL_CAREFUL
    if ( mexpr_is_size_bad(m.size()) ){ 
      mbad_expr_in_unary(m,"toCarray");
      return 0;
    }
#endif

    const unsigned int N = m.size();
    D2* dptr = new D2[N];
    for(unsigned int i = 0; i<N; i++) 
      dptr[i] = static_cast<D2>(m(i));
    return  dptr;
  }


  // toFarray(matrix)

  template <class D2, class D1, class A> 
  inline D2*
  toFarray(const MorE<D1,A>& m) {

#ifdef COOLL_CAREFUL
    if ( mexpr_is_size_bad(m.size()) ){ 
      mbad_expr_in_unary(m,"toFarray");
      return 0;
    }
#endif

    const unsigned int NR = m.Nrows();
    //    const unsigned int NC = m.Ncols();
    const unsigned int N = m.size();
    D2* dptr = new D2[N];
    const unsigned int C1 = N-NR;
    register unsigned int i = 0;
    for(register unsigned int c = 0; c < NR; c++, i++) {
      register unsigned int k = c;
      dptr[k] = static_cast<D2>(m(i));
      while (k<C1) {
	dptr[k+=NR] = static_cast<D2>(m(i+=1));
      } 
    }
    return  dptr;
  }



  template <class A> 
  LAvector<unsigned int> sub2ind(const MorE<unsigned int,A>& subs, const unsigned int NC) {
    const unsigned int N = subs.Nrows();
#ifdef COOLL_CAREFUL
    std::string s = "sub2ind(" + subs.debugtxt() + ")";
    LAvector<unsigned int> ii(N,s);
    if ( subs.Ncols() !=2 ) {
      //error
      return ii;
    }
#else
    LAvector<unsigned int> ii(N);
#endif 

    for (unsigned int i = 0;  i <N; i++)
      ii[i] = NC*subs(i,0) + subs(i,1);

    return ii;
  }


  /****************************************************************************
   * Binary Functions/Operators that return scalars
   ****************************************************************************
   */












  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */

  // sum(a)

  template <class D, class A> 
  inline D sum( const MorE<D,A>& a ) {
    
#ifdef COOLL_CAREFUL
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"sum");
      return 0;
    }
#endif
 
    D result = a(0);

    for (register unsigned int i = 1; i < a.size() ; i++ )
      result += a(i);
    
    return result;
  }



  // sumbyrow(a)
  template <class D, class A> 
  inline LAvector<D> sumbyrow( const MorE<D,A>& a ) {
    
    const unsigned int NR = a.Nrows();
    const unsigned int NC = a.Ncols();
#ifdef COOLL_CAREFUL
    std::string s = "sumbyrow(" + a.debugtxt() + ")";
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"sumbyrow");
      LAvector<D> y(0,s);
      return y;
    }
    LAvector<D> y(NR,s);
#else
    LAvector<D> y(NR);
#endif

    unsigned int i = 0;
    for(unsigned int r = 0; r<NR; r++) {
      D temp=D();
      for(unsigned int c = 0; c<NC; c++,i++) {
	temp += a(i);
      }
      y[r] = temp;
    }
    
    return y;
  }


  // sumbycol(a)
  template <class D, class A> 
  inline LAvector<D> sumbycol( const MorE<D,A>& a ) {
    
    const unsigned int NR = a.Nrows();
    const unsigned int NC = a.Ncols();
#ifdef COOLL_CAREFUL
    std::string s = "sumbycol(" + a.debugtxt() + ")";
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"sumbycol");
      LAvector<D> y(0,s);
      return y;
    }
    LAvector<D> y(NC,s);
#else
    LAvector<D> y(NC);
#endif

    for(unsigned int c = 0; c<NC; c++) {
      unsigned int LIMIT = NR*NC-NC+c+1;
      D temp=D();
      for(unsigned int i = c; i<LIMIT; i+=NC) {
	temp += a(i);
      }
      y[c] = temp;
    }
    return y;
  }





  // min(a)

  template <class D, class A> 
  inline D min( const MorE<D,A>& a ) {
#ifdef COOLL_CAREFUL
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"min");
      return 0;
    }
#endif
    D result = a(0);
    for (register unsigned int i = 1; i < a.size() ; i++ )
      result = std::min(result,a(i));
    return result;
  }



  // minbyrow(a)

  template <class D, class A> 
  inline LAvector<D> minbyrow( const MorE<D,A>& a ) {
    
    const unsigned int NR = a.Nrows();
    const unsigned int NC = a.Ncols();
#ifdef COOLL_CAREFUL
    std::string s = "minbyrow(" + a.debugtxt() + ")";
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"minbyrow");
      LAvector<D> y(0,s);
      return y;
    }
    LAvector<D> y(NR,s);
#else
    LAvector<D> y(NR);
#endif
    unsigned int i = 0;
    for(unsigned int r = 0; r<NR; r++) {
      D temp = a(i); 
      i++;
      for(unsigned int c = 1; c<NC; c++,i++) {
	temp =  std::min(temp,a(i));
      }
      y[r] = temp;
    }
    return y;
  }



  // minbycol(a)

  template <class D, class A> 
  inline LAvector<D> minbycol( const MorE<D,A>& a ) {
    
    const unsigned int NR = a.Nrows();
    const unsigned int NC = a.Ncols();
#ifdef COOLL_CAREFUL
    std::string s = "minbycol(" + a.debugtxt() + ")";
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"minbycol");
      LAvector<D> y(0,s);
      return y;
    }
    LAvector<D> y(NC,s);
#else
    LAvector<D> y(NC);
#endif

    for(unsigned int c = 0; c<NC; c++) {
      unsigned int LIMIT = NR*NC-NC+c+1;
      unsigned int i = c;
      D temp=a(i);
      for(i+=NC; i<LIMIT; i+=NC) {
	temp = std::min(temp,a(i));
      }
      y[c] = temp;
    }
    return y;
  }



  // max(a)

  template <class D, class A> 
  inline D max( const MorE<D,A>& a ) {
    
#ifdef COOLL_CAREFUL
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"max");
      return 0;
    }
#endif
 
    D result = a(0);

    for (register unsigned int i = 1; i < a.size() ; i++ )
      result = std::max(result,a(i));
    
    return result;
  }






  // maxbyrow(a)

  template <class D, class A> 
  inline LAvector<D> maxbyrow( const MorE<D,A>& a ) {
    
    const unsigned int NR = a.Nrows();
    const unsigned int NC = a.Ncols();
#ifdef COOLL_CAREFUL
    std::string s = "maxbyrow(" + a.debugtxt() + ")";
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"maxbyrow");
      LAvector<D> y(0,s);
      return y;
    }
    LAvector<D> y(NR,s);
#else
    LAvector<D> y(NR);
#endif
    unsigned int i = 0;
    for(unsigned int r = 0; r<NR; r++) {
      D temp = a(i); 
      i++;
      for(unsigned int c = 1; c<NC; c++,i++) {
	temp =  std::max(temp,a(i));
      }
      y[r] = temp;
    }
    return y;
  }



  // maxbycol(a)

  template <class D, class A> 
  inline LAvector<D> maxbycol( const MorE<D,A>& a ) {
    
    const unsigned int NR = a.Nrows();
    const unsigned int NC = a.Ncols();
#ifdef COOLL_CAREFUL
    std::string s = "maxbycol(" + a.debugtxt() + ")";
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"maxbycol");
      LAvector<D> y(0,s);
      return y;
    }
    LAvector<D> y(NC,s);
#else
    LAvector<D> y(NC);
#endif

    for(unsigned int c = 0; c<NC; c++) {
      unsigned int LIMIT = NR*NC-NC+c+1;
      unsigned int i = c;
      D temp=a(i);
      for(i+=NC; i<LIMIT; i+=NC) {
	temp = std::max(temp,a(i));
      }
      y[c] = temp;
    }
    return y;
  }






  // tr(a)  trace

  template <class D, class A> 
  inline D tr( const MorE<D,A>& a ) {
    
#ifdef COOLL_CAREFUL
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"tr");
      return 0;
    }
#endif
 
    D result = a(0);
    unsigned int Nmin;
    if (a.Nrows() < a.Ncols())
      Nmin=a.Nrows();
    else
      Nmin=a.Ncols();
    
    const unsigned int N=Nmin;

    for (register unsigned int i = 1; i < N ; i++ )
      result += a(i,i);
    
    return result;
  }


};





#endif 
