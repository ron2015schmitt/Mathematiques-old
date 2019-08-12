


#ifndef VBOOLOPS_H
#define VBOOLOPS_H

namespace Matricks {





  /************************************************************
   *               Templates for Binary Operators that return bool vectors
   *
   * D = data type, e.g. double
   * A = either an Vector or a Vexpr
   * B = either an Vector or a Vexpr
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
   * A = either an Vector or a Vexpr
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
   * A = either an Vector or a Vexpr
   * B = either an Vector or a Vexpr
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
   * A = either an Vector or a Vexpr
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
   * A = either an Vector or a Vexpr
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
    
#ifdef Matricks_CAREFUL
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"alltrue");
      return false;
    }
#endif
 
    for (register size_type i = 0; i< a.size(); i++)
      result = result && a[i];
    
    return result;
  }


   // anytrue(a)

  template <class A> 
  inline bool anytrue( const VorE<bool,A>& a ) {
    bool result = false;
    
#ifdef Matricks_CAREFUL
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"anytrue");
      return false;
    }
#endif
 
    for (register size_type i = 0; i< a.size(); i++)
      result = result || a[i];
    
    return result;
  }


  // numtrue(a)

  template <class A> 
  inline size_type numtrue( const VorE<bool,A>& a ) {
    size_type result = 0;
    
#ifdef Matricks_CAREFUL
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"numtrue");
      return 0;
    }
#endif
 
    for (register size_type i = 0; i< a.size(); i++)
      result += static_cast<size_type>(a[i]);
    
    return result;
  }


  


  // findtrue(a)

  template <class A> 
  inline Vector<size_type> findtrue( const VorE<bool,A>& a ) {
    int N = 0;
    
#ifdef Matricks_CAREFUL
    std::string s = "findtrue(" + a.debugtxt() + ")";
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"findtrue");
      Vector<size_type> y(0,s);
      return y;
    }
#endif

    for (register size_type i = 0; i< a.size(); i++)
      N += int(a[i]);
 
#ifdef Matricks_CAREFUL
    Vector<size_type> y(N,s);
#else
    Vector<size_type> y(N);
#endif

    size_type j =0;
    for (register size_type i = 0; i< a.size(); i++)
      if (a[i])
	y[j++] = i;
    
    return y;
  }





};

#endif 
