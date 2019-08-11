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




#ifndef MBOOLOPS_H
#define MBOOLOPS_H





namespace COOLL {





  /************************************************************
   *               Templates for Binary Operators that return bool matrixs
   *
   * D = data type, e.g. double
   * A = either an Matrix or a Mexpr
   * B = either an Matrix or a Mexpr
   ************************************************************
   */


  // a==b

  template <class D, class A, class B> 
  inline MboolBinOp<D,MorE<D,A>,MorE<D,B>,ApEqual<D> >  
  operator==( const MorE<D,A>& a, const  MorE<D,B>& b ) {
    return MboolBinOp<D,MorE<D,A>,MorE<D,B>,ApEqual<D> >(a,b);
  }


  // a!=b

  template <class D, class A, class B> 
  inline MboolBinOp<D,MorE<D,A>,MorE<D,B>,ApNotEqual<D> >  
  operator!=( const MorE<D,A>& a, const  MorE<D,B>& b ) {
    return MboolBinOp<D,MorE<D,A>,MorE<D,B>,ApNotEqual<D> >(a,b);
  }



  // a<=b

  template <class D, class A, class B> 
  inline MboolBinOp<D,MorE<D,A>,MorE<D,B>,ApLessEqual<D> >  
  operator<=( const MorE<D,A>& a, const  MorE<D,B>& b ) {
    return MboolBinOp<D,MorE<D,A>,MorE<D,B>,ApLessEqual<D> >(a,b);
  }


  // a>=b

  template <class D, class A, class B> 
  inline MboolBinOp<D,MorE<D,A>,MorE<D,B>,ApGreaterEqual<D> >  
  operator>=( const MorE<D,A>& a, const  MorE<D,B>& b ) {
    return MboolBinOp<D,MorE<D,A>,MorE<D,B>,ApGreaterEqual<D> >(a,b);
  }


  // a<b

  template <class D, class A, class B> 
  inline MboolBinOp<D,MorE<D,A>,MorE<D,B>,ApLess<D> >  
  operator<( const MorE<D,A>& a, const  MorE<D,B>& b ) {
    return MboolBinOp<D,MorE<D,A>,MorE<D,B>,ApLess<D> >(a,b);
  }


  // a>b

  template <class D, class A, class B> 
  inline MboolBinOp<D,MorE<D,A>,MorE<D,B>,ApGreat<D> >  
  operator>( const MorE<D,A>& a, const  MorE<D,B>& b ) {
    return MboolBinOp<D,MorE<D,A>,MorE<D,B>,ApGreat<D> >(a,b);
  }


 /************************************************************
   *    Templates for matrix/scalar Operators that return Bool matrix
   *
   * D = data type, e.g. double (matrix and scalar must be of same data type)
   * A = either an Matrix or a Mexpr
   ************************************************************
   */



  // matrix == scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,ApEqual<D> > 
  operator==(const MorE<D,A>& a, const D b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,ApEqual<D> >(a,b);
  }

  // scalar == matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,ApEqual<D> > 
  operator==(const D a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,ApEqual<D> >(a,b);
  }

  // matrix != scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,ApNotEqual<D> > 
  operator!=(const MorE<D,A>& a, const D b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,ApNotEqual<D> >(a,b);
  }

  // scalar != matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,ApNotEqual<D> > 
  operator!=(const D a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,ApNotEqual<D> >(a,b);
  }
  // matrix <= scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,ApLessEqual<D> > 
  operator<=(const MorE<D,A>& a, const D b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,ApLessEqual<D> >(a,b);
  }

  // scalar <= matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,ApLessEqual<D> > 
  operator<=(const D a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,ApLessEqual<D> >(a,b);
  }
  // matrix >= scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,ApGreaterEqual<D> > 
  operator>=(const MorE<D,A>& a, const D b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,ApGreaterEqual<D> >(a,b);
  }

  // scalar >= matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,ApGreaterEqual<D> > 
  operator>=(const D a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,ApGreaterEqual<D> >(a,b);
  }
  // matrix < scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,ApLess<D> > 
  operator<(const MorE<D,A>& a, const D b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,ApLess<D> >(a,b);
  }

  // scalar < matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,ApLess<D> > 
  operator<(const D a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,ApLess<D> >(a,b);
  }
  // matrix > scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,ApGreat<D> > 
  operator>(const MorE<D,A>& a, const D b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,ApGreat<D> >(a,b);
  }

  // scalar > matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,ApGreat<D> > 
  operator>(const D a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,ApGreat<D> >(a,b);
  }



  // the following are defined for convenience

  // matrix == int scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,ApEqual<D> > 
  operator==(const MorE<D,A>& a, const int b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,ApEqual<D> >(a,static_cast<D>(b));
  }

  // int scalar == matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,ApEqual<D> > 
  operator==(const int a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,ApEqual<D> >(static_cast<D>(a),b);
  }

  // matrix != int scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,ApNotEqual<D> > 
  operator!=(const MorE<D,A>& a, const int b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,ApNotEqual<D> >(a,static_cast<D>(b));
  }

  // int scalar != matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,ApNotEqual<D> > 
  operator!=(const int a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,ApNotEqual<D> >(static_cast<D>(a),b);
  }
  // matrix <= int scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,ApLessEqual<D> > 
  operator<=(const MorE<D,A>& a, const int b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,ApLessEqual<D> >(a,static_cast<D>(b));
  }

  // int scalar <= matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,ApLessEqual<D> > 
  operator<=(const int a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,ApLessEqual<D> >(static_cast<D>(a),b);
  }
  // matrix >= int scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,ApGreaterEqual<D> > 
  operator>=(const MorE<D,A>& a, const int b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,ApGreaterEqual<D> >(a,static_cast<D>(b));
  }

  // int scalar >= matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,ApGreaterEqual<D> > 
  operator>=(const int a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,ApGreaterEqual<D> >(static_cast<D>(a),b);
  }
  // matrix < int scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,ApLess<D> > 
  operator<(const MorE<D,A>& a, const int b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,ApLess<D> >(a,static_cast<D>(b));
  }

  // int scalar < matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,ApLess<D> > 
  operator<(const int a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,ApLess<D> >(static_cast<D>(a),b);
  }
  // matrix > int scalar

  template <class D, class A> 
  inline BoolMatOpScal<D,MorE<D,A>,ApGreat<D> > 
  operator>(const MorE<D,A>& a, const int b)
  {
    return  BoolMatOpScal<D,MorE<D,A>,ApGreat<D> >(a,static_cast<D>(b));
  }

  // int scalar > matrix

  template <class D, class B> 
  inline BoolScalOpMat<D,MorE<D,B>,ApGreat<D> > 
  operator>(const int a, const MorE<D,B>& b)
  {
    return  BoolScalOpMat<D,MorE<D,B>,ApGreat<D> >(static_cast<D>(a),b);
  }




  /************************************************************
   *               Templates for Binary Operators
   *
   * A = either an Matrix or a Mexpr
   * B = either an Matrix or a Mexpr
   ************************************************************
   */

  // matrix && matrix

  template <class A, class B> 
  inline MBinOp<bool,MorE<bool,A>,MorE<bool,B>,ApAnd > 
  operator&&(const MorE<bool,A>& a, const MorE<bool,B>& b)
  {
    return  MBinOp<bool,MorE<bool,A>,MorE<bool,B>,ApAnd >(a,b);
  }

  // matrix || matrix

  template <class A, class B> 
  inline MBinOp<bool,MorE<bool,A>,MorE<bool,B>,ApOr > 
  operator||(const MorE<bool,A>& a, const MorE<bool,B>& b)
  {
    return  MBinOp<bool,MorE<bool,A>,MorE<bool,B>,ApOr >(a,b);
  }










  /************************************************************
   *               Templates for matrix/scalar Operators
   *
   * A = either an Matrix or a Mexpr
   ************************************************************
   */


  // matrix && scalar

  template <class A> 
  inline MatOpScal<bool,MorE<bool,A>,ApAnd > 
  operator&&(const MorE<bool,A>& a, const bool b)
  {
    return  MatOpScal<bool,MorE<bool,A>,ApAnd >(a,b);
  }

  // scalar && matrix

  template <class B> 
  inline ScalOpMat<bool,MorE<bool,B>,ApAnd > 
  operator&&(const bool a, const MorE<bool,B>& b)
  {
    return  ScalOpMat<bool,MorE<bool,B>,ApAnd >(a,b);
  }

  
  // matrix || scalar

  template <class A> 
  inline MatOpScal<bool,MorE<bool,A>,ApOr > 
  operator||(const MorE<bool,A>& a, const bool b)
  {
    return  MatOpScal<bool,MorE<bool,A>,ApOr >(a,b);
  }

  // scalar || matrix

  template <class B> 
  inline ScalOpMat<bool,MorE<bool,B>,ApOr > 
  operator||(const bool a, const MorE<bool,B>& b)
  {
    return  ScalOpMat<bool,MorE<bool,B>,ApOr >(a,b);
  }



  /****************************************************************
   *               Templates for Unary Operators & Unary Functions
   *
   * A = either an Matrix or a Mexpr
   *****************************************************************
   */


  
  // !(matrix)

  template <class A> 
  inline MFuncOp<bool,MorE<bool,A>,ApNot > 
  operator!(const MorE<bool,A>& a)
  {
    return  MFuncOp<bool,MorE<bool,A>,ApNot >(a);
  }
  




  










  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */


  
  // alltrue(a)

  template <class A> 
  inline bool alltrue( const MorE<bool,A>& a ) {
    bool result = true;
    
#ifdef COOLL_CAREFUL
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"alltrue");
      return false;
    }
#endif
 
    for (register unsigned int i = 0; i< a.size(); i++)
      result = result && a(i);
    
    return result;
  }


  // alltruebyrow(a)

  template <class A> 
  inline LAvector<bool> alltruebyrow( const MorE<bool,A>& a ) {
    
    const unsigned int NR = a.Nrows();
    const unsigned int NC = a.Ncols();
#ifdef COOLL_CAREFUL
    std::string s = "alltruebyrow(" + a.debugtxt() + ")";
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"alltruebyrow");
      LAvector<bool> y(0,s);
      return y;
    }
    LAvector<bool> y(NR,s);
#else
    LAvector<bool> y(NR);
#endif

    unsigned int i = 0;
    for(unsigned int r = 0; r<NR; r++) {
      bool temp=true;
      for(unsigned int c = 0; c<NC; c++,i++) {
	temp = temp && a(i);
      }
      y[r] = temp;
    }
    return y;
  }

  // alltruebycol(a)
  template <class A> 
  inline LAvector<bool> alltruebycol( const MorE<bool,A>& a ) {
    
    const unsigned int NR = a.Nrows();
    const unsigned int NC = a.Ncols();
#ifdef COOLL_CAREFUL
    std::string s = "alltruebycol(" + a.debugtxt() + ")";
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"alltruebycol");
      LAvector<bool> y(0,s);
      return y;
    }
    LAvector<bool> y(NC,s);
#else
    LAvector<bool> y(NC);
#endif

    for(unsigned int c = 0; c<NC; c++) {
      unsigned int LIMIT = NR*NC-NC+c+1;
      bool temp=true;
      for(unsigned int i = c; i<LIMIT; i+=NC) {
	temp = temp && a(i);
      }
      y[c] = temp;
    }
    return y;
  }









   // anytrue(a)

  template <class A> 
  inline bool anytrue( const MorE<bool,A>& a ) {
    bool result = false;
    
#ifdef COOLL_CAREFUL
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"anytrue");
      return false;
    }
#endif
 
    for (register unsigned int i = 0; i< a.size(); i++)
      result = result || a(i);
    
    return result;
  }



  // anytruebyrow(a)

  template <class A> 
  inline LAvector<bool> anytruebyrow( const MorE<bool,A>& a ) {
    
    const unsigned int NR = a.Nrows();
    const unsigned int NC = a.Ncols();
#ifdef COOLL_CAREFUL
    std::string s = "anytruebyrow(" + a.debugtxt() + ")";
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"anytruebyrow");
      LAvector<bool> y(0,s);
      return y;
    }
    LAvector<bool> y(NR,s);
#else
    LAvector<bool> y(NR);
#endif

    unsigned int i = 0;
    for(unsigned int r = 0; r<NR; r++) {
      bool temp=false;
      for(unsigned int c = 0; c<NC; c++,i++) {
	temp = temp || a(i);
      }
      y[r] = temp;
    }
    return y;
  }

  // anytruebycol(a)
  template <class A> 
  inline LAvector<bool> anytruebycol( const MorE<bool,A>& a ) {
    
    const unsigned int NR = a.Nrows();
    const unsigned int NC = a.Ncols();
#ifdef COOLL_CAREFUL
    std::string s = "anytruebycol(" + a.debugtxt() + ")";
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"anytruebycol");
      LAvector<bool> y(0,s);
      return y;
    }
    LAvector<bool> y(NC,s);
#else
    LAvector<bool> y(NC);
#endif

    for(unsigned int c = 0; c<NC; c++) {
      unsigned int LIMIT = NR*NC-NC+c+1;
      bool temp=false;
      for(unsigned int i = c; i<LIMIT; i+=NC) {
	temp = temp || a(i);
      }
      y[c] = temp;
    }
    return y;
  }


  // numtrue(a)

  template <class A> 
  inline unsigned int numtrue( const MorE<bool,A>& a ) {
    unsigned int result = 0;
    
#ifdef COOLL_CAREFUL
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"numtrue");
      return 0;
    }
#endif
 
    for (register unsigned int i = 0; i< a.size(); i++)
      result += static_cast<unsigned int>(a(i));
    
    return result;
  }



  // numtruebyrow(a)

  template <class A> 
  inline LAvector< unsigned int> numtruebyrow( const MorE<bool,A>& a ) {
    
    const unsigned int NR = a.Nrows();
    const unsigned int NC = a.Ncols();
#ifdef COOLL_CAREFUL
    std::string s = "numtruebyrow(" + a.debugtxt() + ")";
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"numtruebyrow");
      LAvector< unsigned int> y(0,s);
      return y;
    }
    LAvector< unsigned int> y(NR,s);
#else
    LAvector< unsigned int> y(NR);
#endif

    unsigned int i = 0;
    for(unsigned int r = 0; r<NR; r++) {
       unsigned int temp=0;
      for(unsigned int c = 0; c<NC; c++,i++) {
	temp  += static_cast<unsigned int>(a(i));
      }
      y[r] = temp;
    }
    return y;
  }

  // numtruebycol(a)
  template <class A> 
  inline LAvector< unsigned int> numtruebycol( const MorE<bool,A>& a ) {
    
    const unsigned int NR = a.Nrows();
    const unsigned int NC = a.Ncols();
#ifdef COOLL_CAREFUL
    std::string s = "numtruebycol(" + a.debugtxt() + ")";
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"numtruebycol");
      LAvector< unsigned int> y(0,s);
      return y;
    }
    LAvector< unsigned int> y(NC,s);
#else
    LAvector< unsigned int> y(NC);
#endif

    for(unsigned int c = 0; c<NC; c++) {
      unsigned int LIMIT = NR*NC-NC+c+1;
      unsigned int temp=0;
      for(unsigned int i = c; i<LIMIT; i+=NC) {
	temp  += static_cast<unsigned int>(a(i));
      }
      y[c] = temp;
    }
    return y;
  }



  
  

  // findtrue(a)

  template <class A> 
  inline Matrix<unsigned int> findtrue( const MorE<bool,A>& a ) {
    unsigned int N = 0;
    
#ifdef COOLL_CAREFUL
    std::string s = "findtrue(" + a.debugtxt() + ")";
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"findtrue");
      Matrix<unsigned int> y(0,2,s);
      return y;
    }
#endif
 
    for (register unsigned int i = 0; i< a.size(); i++)
      N += static_cast<unsigned int>(a(i));
 
#ifdef COOLL_CAREFUL
    Matrix<unsigned int> y(N,2,s);
#else
    Matrix<unsigned int> y(N,2);
#endif

   unsigned int i = 0;
   unsigned int j = 0;
    for(unsigned int r = 0; r<a.Nrows(); r++) {
       for(unsigned int c = 0; c<a.Ncols(); c++,i++) {
	 if (a(i)) {
	   y(j,0) = r;
	   y(j,1) = c;
	   j++;
	 }
       }
    }
    return y;
  }





  // findtruesi(a) -- return in single index format

  template <class A> 
  inline LAvector<unsigned int> findtruesi( const MorE<bool,A>& a ) {
    unsigned int N = 0;
    
#ifdef COOLL_CAREFUL
    std::string s = "findtruesi(" + a.debugtxt() + ")";
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"findtruesi");
      LAvector<unsigned int> y(0,s);
      return y;
    }
#endif
 
    for (register unsigned int i = 0; i< a.size(); i++)
      N += static_cast<unsigned int>(a(i));
 
#ifdef COOLL_CAREFUL
    LAvector<unsigned int> y(N,s);
#else
    LAvector<unsigned int> y(N);
#endif

    unsigned int j = 0;
    for (register unsigned int i = 0; i< a.size(); i++) {
      if (a(i)) {
	y[j] = i;
	j++;
      }
    }
    
    return y;
  }

  

  // findtruebyrow(a)

  template <class A> 
  inline LAvector<unsigned int> findtruebyrow( const MorE<bool,A>& a ) {
    unsigned int N = 0;
    
#ifdef COOLL_CAREFUL
    std::string s = "findtruebyrow(" + a.debugtxt() + ")";
    if (  mexpr_is_size_bad(a.size()) ) {
      mbad_expr_in_unary(a,"findtruebyrow");
      LAvector<unsigned int> y(0,2,s);
      return y;
    }
#endif
 
    for (register unsigned int i = 0; i< a.size(); i++)
      N += static_cast<unsigned int>(a(i));
 
#ifdef COOLL_CAREFUL
    LAvector<unsigned int> y(N,2,s);
#else
    LAvector<unsigned int> y(N,2);
#endif

   unsigned int i = 0;
   unsigned int j = 0;
    for(unsigned int r = 0; r<a.Nrows(); r++) {
       for(unsigned int c = 0; c<a.Ncols(); c++,i++) {
	 if (a(i)) {
	   y[r] = 1;
	 }
       }
    }
    return y;
  }

  



};

#endif 
