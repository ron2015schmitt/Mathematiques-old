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




#ifndef VBOOLOPS_H
#define VBOOLOPS_H





namespace COOLL {





  /************************************************************
   *               Templates for Binary Operators that return bool vectors
   *
   * D = data type, e.g. double
   * A = either an LAvector or a Vexpr
   * B = either an LAvector or a Vexpr
   ************************************************************
   */


  // a==b

  template <class D, class A, class B> 
  inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApEqual<D> >  
  operator==( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApEqual<D> >(a,b);
  }


  // a!=b

  template <class D, class A, class B> 
  inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApNotEqual<D> >  
  operator!=( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApNotEqual<D> >(a,b);
  }



  // a<=b

  template <class D, class A, class B> 
  inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApLessEqual<D> >  
  operator<=( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApLessEqual<D> >(a,b);
  }


  // a>=b

  template <class D, class A, class B> 
  inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApGreaterEqual<D> >  
  operator>=( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApGreaterEqual<D> >(a,b);
  }


  // a<b

  template <class D, class A, class B> 
  inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApLess<D> >  
  operator<( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApLess<D> >(a,b);
  }


  // a>b

  template <class D, class A, class B> 
  inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApGreat<D> >  
  operator>( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApGreat<D> >(a,b);
  }


 /************************************************************
   *               Templates for vector/scalar Operators that return Bool vector
   *
   * D = data type, e.g. double (vector and scalar must be of same data type)
   * A = either an LAvector or a Vexpr
   ************************************************************
   */



  // vector == scalar

  template <class D, class A> 
  inline BoolVecOpScal<D,VorE<D,A>,ApEqual<D> > 
  operator==(const VorE<D,A>& a, const D b)
  {
    return  BoolVecOpScal<D,VorE<D,A>,ApEqual<D> >(a,b);
  }

  // scalar == vector

  template <class D, class B> 
  inline BoolScalOpVec<D,VorE<D,B>,ApEqual<D> > 
  operator==(const D a, const VorE<D,B>& b)
  {
    return  BoolScalOpVec<D,VorE<D,B>,ApEqual<D> >(a,b);
  }

  // vector != scalar

  template <class D, class A> 
  inline BoolVecOpScal<D,VorE<D,A>,ApNotEqual<D> > 
  operator!=(const VorE<D,A>& a, const D b)
  {
    return  BoolVecOpScal<D,VorE<D,A>,ApNotEqual<D> >(a,b);
  }

  // scalar != vector

  template <class D, class B> 
  inline BoolScalOpVec<D,VorE<D,B>,ApNotEqual<D> > 
  operator!=(const D a, const VorE<D,B>& b)
  {
    return  BoolScalOpVec<D,VorE<D,B>,ApNotEqual<D> >(a,b);
  }
  // vector <= scalar

  template <class D, class A> 
  inline BoolVecOpScal<D,VorE<D,A>,ApLessEqual<D> > 
  operator<=(const VorE<D,A>& a, const D b)
  {
    return  BoolVecOpScal<D,VorE<D,A>,ApLessEqual<D> >(a,b);
  }

  // scalar <= vector

  template <class D, class B> 
  inline BoolScalOpVec<D,VorE<D,B>,ApLessEqual<D> > 
  operator<=(const D a, const VorE<D,B>& b)
  {
    return  BoolScalOpVec<D,VorE<D,B>,ApLessEqual<D> >(a,b);
  }
  // vector >= scalar

  template <class D, class A> 
  inline BoolVecOpScal<D,VorE<D,A>,ApGreaterEqual<D> > 
  operator>=(const VorE<D,A>& a, const D b)
  {
    return  BoolVecOpScal<D,VorE<D,A>,ApGreaterEqual<D> >(a,b);
  }

  // scalar >= vector

  template <class D, class B> 
  inline BoolScalOpVec<D,VorE<D,B>,ApGreaterEqual<D> > 
  operator>=(const D a, const VorE<D,B>& b)
  {
    return  BoolScalOpVec<D,VorE<D,B>,ApGreaterEqual<D> >(a,b);
  }
  // vector < scalar

  template <class D, class A> 
  inline BoolVecOpScal<D,VorE<D,A>,ApLess<D> > 
  operator<(const VorE<D,A>& a, const D b)
  {
    return  BoolVecOpScal<D,VorE<D,A>,ApLess<D> >(a,b);
  }

  // scalar < vector

  template <class D, class B> 
  inline BoolScalOpVec<D,VorE<D,B>,ApLess<D> > 
  operator<(const D a, const VorE<D,B>& b)
  {
    return  BoolScalOpVec<D,VorE<D,B>,ApLess<D> >(a,b);
  }
  // vector > scalar

  template <class D, class A> 
  inline BoolVecOpScal<D,VorE<D,A>,ApGreat<D> > 
  operator>(const VorE<D,A>& a, const D b)
  {
    return  BoolVecOpScal<D,VorE<D,A>,ApGreat<D> >(a,b);
  }

  // scalar > vector

  template <class D, class B> 
  inline BoolScalOpVec<D,VorE<D,B>,ApGreat<D> > 
  operator>(const D a, const VorE<D,B>& b)
  {
    return  BoolScalOpVec<D,VorE<D,B>,ApGreat<D> >(a,b);
  }



  // the following are defined for convenience

  // vector == int scalar

  template <class D, class A> 
  inline BoolVecOpScal<D,VorE<D,A>,ApEqual<D> > 
  operator==(const VorE<D,A>& a, const int b)
  {
    return  BoolVecOpScal<D,VorE<D,A>,ApEqual<D> >(a,static_cast<D>(b));
  }

  // int scalar == vector

  template <class D, class B> 
  inline BoolScalOpVec<D,VorE<D,B>,ApEqual<D> > 
  operator==(const int a, const VorE<D,B>& b)
  {
    return  BoolScalOpVec<D,VorE<D,B>,ApEqual<D> >(static_cast<D>(a),b);
  }

  // vector != int scalar

  template <class D, class A> 
  inline BoolVecOpScal<D,VorE<D,A>,ApNotEqual<D> > 
  operator!=(const VorE<D,A>& a, const int b)
  {
    return  BoolVecOpScal<D,VorE<D,A>,ApNotEqual<D> >(a,static_cast<D>(b));
  }

  // int scalar != vector

  template <class D, class B> 
  inline BoolScalOpVec<D,VorE<D,B>,ApNotEqual<D> > 
  operator!=(const int a, const VorE<D,B>& b)
  {
    return  BoolScalOpVec<D,VorE<D,B>,ApNotEqual<D> >(static_cast<D>(a),b);
  }
  // vector <= int scalar

  template <class D, class A> 
  inline BoolVecOpScal<D,VorE<D,A>,ApLessEqual<D> > 
  operator<=(const VorE<D,A>& a, const int b)
  {
    return  BoolVecOpScal<D,VorE<D,A>,ApLessEqual<D> >(a,static_cast<D>(b));
  }

  // int scalar <= vector

  template <class D, class B> 
  inline BoolScalOpVec<D,VorE<D,B>,ApLessEqual<D> > 
  operator<=(const int a, const VorE<D,B>& b)
  {
    return  BoolScalOpVec<D,VorE<D,B>,ApLessEqual<D> >(static_cast<D>(a),b);
  }
  // vector >= int scalar

  template <class D, class A> 
  inline BoolVecOpScal<D,VorE<D,A>,ApGreaterEqual<D> > 
  operator>=(const VorE<D,A>& a, const int b)
  {
    return  BoolVecOpScal<D,VorE<D,A>,ApGreaterEqual<D> >(a,static_cast<D>(b));
  }

  // int scalar >= vector

  template <class D, class B> 
  inline BoolScalOpVec<D,VorE<D,B>,ApGreaterEqual<D> > 
  operator>=(const int a, const VorE<D,B>& b)
  {
    return  BoolScalOpVec<D,VorE<D,B>,ApGreaterEqual<D> >(static_cast<D>(a),b);
  }
  // vector < int scalar

  template <class D, class A> 
  inline BoolVecOpScal<D,VorE<D,A>,ApLess<D> > 
  operator<(const VorE<D,A>& a, const int b)
  {
    return  BoolVecOpScal<D,VorE<D,A>,ApLess<D> >(a,static_cast<D>(b));
  }

  // int scalar < vector

  template <class D, class B> 
  inline BoolScalOpVec<D,VorE<D,B>,ApLess<D> > 
  operator<(const int a, const VorE<D,B>& b)
  {
    return  BoolScalOpVec<D,VorE<D,B>,ApLess<D> >(static_cast<D>(a),b);
  }
  // vector > int scalar

  template <class D, class A> 
  inline BoolVecOpScal<D,VorE<D,A>,ApGreat<D> > 
  operator>(const VorE<D,A>& a, const int b)
  {
    return  BoolVecOpScal<D,VorE<D,A>,ApGreat<D> >(a,static_cast<D>(b));
  }

  // int scalar > vector

  template <class D, class B> 
  inline BoolScalOpVec<D,VorE<D,B>,ApGreat<D> > 
  operator>(const int a, const VorE<D,B>& b)
  {
    return  BoolScalOpVec<D,VorE<D,B>,ApGreat<D> >(static_cast<D>(a),b);
  }




  /************************************************************
   *               Templates for Binary Operators
   *
   * A = either an LAvector or a Vexpr
   * B = either an LAvector or a Vexpr
   ************************************************************
   */

  // vector && vector

  template <class A, class B> 
  inline VBinOp<bool,VorE<bool,A>,VorE<bool,B>,ApAnd > 
  operator&&(const VorE<bool,A>& a, const VorE<bool,B>& b)
  {
    return  VBinOp<bool,VorE<bool,A>,VorE<bool,B>,ApAnd >(a,b);
  }

  // vector || vector

  template <class A, class B> 
  inline VBinOp<bool,VorE<bool,A>,VorE<bool,B>,ApOr > 
  operator||(const VorE<bool,A>& a, const VorE<bool,B>& b)
  {
    return  VBinOp<bool,VorE<bool,A>,VorE<bool,B>,ApOr >(a,b);
  }










  /************************************************************
   *               Templates for vector/scalar Operators
   *
   * A = either an LAvector or a Vexpr
   ************************************************************
   */


  // vector && scalar

  template <class A> 
  inline VecOpScal<bool,VorE<bool,A>,ApAnd > 
  operator&&(const VorE<bool,A>& a, const bool b)
  {
    return  VecOpScal<bool,VorE<bool,A>,ApAnd >(a,b);
  }

  // scalar && vector

  template <class B> 
  inline ScalOpVec<bool,VorE<bool,B>,ApAnd > 
  operator&&(const bool a, const VorE<bool,B>& b)
  {
    return  ScalOpVec<bool,VorE<bool,B>,ApAnd >(a,b);
  }

  
  // vector || scalar

  template <class A> 
  inline VecOpScal<bool,VorE<bool,A>,ApOr > 
  operator||(const VorE<bool,A>& a, const bool b)
  {
    return  VecOpScal<bool,VorE<bool,A>,ApOr >(a,b);
  }

  // scalar || vector

  template <class B> 
  inline ScalOpVec<bool,VorE<bool,B>,ApOr > 
  operator||(const bool a, const VorE<bool,B>& b)
  {
    return  ScalOpVec<bool,VorE<bool,B>,ApOr >(a,b);
  }



  /****************************************************************
   *               Templates for Unary Operators & Unary Functions
   *
   * A = either an LAvector or a Vexpr
   *****************************************************************
   */


  
  // !(vector)

  template <class A> 
  inline VFuncOp<bool,VorE<bool,A>,ApNot > 
  operator!(const VorE<bool,A>& a)
  {
    return  VFuncOp<bool,VorE<bool,A>,ApNot >(a);
  }
  




  










  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */


  
  // alltrue(a)

  template <class A> 
  inline bool alltrue( const VorE<bool,A>& a ) {
    bool result = true;
    
#ifdef COOLL_CAREFUL
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"alltrue");
      return false;
    }
#endif
 
    for (register unsigned int i = 0; i< a.size(); i++)
      result = result && a[i];
    
    return result;
  }


   // anytrue(a)

  template <class A> 
  inline bool anytrue( const VorE<bool,A>& a ) {
    bool result = false;
    
#ifdef COOLL_CAREFUL
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"anytrue");
      return false;
    }
#endif
 
    for (register unsigned int i = 0; i< a.size(); i++)
      result = result || a[i];
    
    return result;
  }


  // numtrue(a)

  template <class A> 
  inline unsigned int numtrue( const VorE<bool,A>& a ) {
    unsigned int result = 0;
    
#ifdef COOLL_CAREFUL
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"numtrue");
      return 0;
    }
#endif
 
    for (register unsigned int i = 0; i< a.size(); i++)
      result += static_cast<unsigned int>(a[i]);
    
    return result;
  }


  


  // findtrue(a)

  template <class A> 
  inline LAvector<unsigned int> findtrue( const VorE<bool,A>& a ) {
    int N = 0;
    
#ifdef COOLL_CAREFUL
    std::string s = "findtrue(" + a.debugtxt() + ")";
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"findtrue");
      LAvector<unsigned int> y(0,s);
      return y;
    }
#endif

    for (register unsigned int i = 0; i< a.size(); i++)
      N += int(a[i]);
 
#ifdef COOLL_CAREFUL
    LAvector<unsigned int> y(N,s);
#else
    LAvector<unsigned int> y(N);
#endif

    unsigned int j =0;
    for (register unsigned int i = 0; i< a.size(); i++)
      if (a[i])
	y[j++] = i;
    
    return y;
  }





};

#endif 
