#ifndef VMATHOPS_H
#define VMATHOPS_H

#include <cmath>
#include <string>

namespace Matricks {


 /************************************************************
   *               Templates for Binary Operators
   *
   * D = data type, e.g. double
   * A = either an Vector or a Vexpr
   * B = either an Vector or a Vexpr
   ************************************************************
   */

  // pow(vector,vector)

  template <class D, class A, class B> 
  inline VBinOp<D,VorE<D,A>,VorE<D,B>,ApPow<D> > 
  pow(const VorE<D,A>& a, const VorE<D,B>& b)
  {
    return  VBinOp<D,VorE<D,A>,VorE<D,B>,ApPow<D> >(a,b);
  }






  /************************************************************
   *               Templates for vector/scalar Operators
   *
   * D = data type, e.g. double (vector and scalar must be of same data type)
   * A = either an Vector or a Vexpr
   ************************************************************
   */






  // pow(vector,scalar)

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApPow<D> > 
  pow(const VorE<D,A>& a, const D b)
  {
    return  VecOpScal<D,VorE<D,A>,ApPow<D> >(a,b);
  }

  // pow(scalar,vector)

  template <class D, class B> 
  inline ScalOpVec<D,VorE<D,B>,ApPow<D> > 
  pow( const D a, const VorE<D,B>& b)
  {
    return  ScalOpVec<D,VorE<D,B>,ApPow<D> >(a,b);
  }





  /****************************************************************
   *               Templates for Unary Operators & Unary Functions
   *
   * D = data type, e.g. double 
   * A = either an Vector or a Vexpr
   *****************************************************************
   */



  // sin(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApSin<D> > 
  sin(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApSin<D> >(a);
  }


  // cos(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApCos<D> > 
  cos(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApCos<D> >(a);
  }



  // tan(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApTan<D> > 
  tan(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApTan<D> >(a);
  }
  // sqrt(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApSqrt<D> > 
  sqrt(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApSqrt<D> >(a);
  }
  // sqr(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApSqr<D> > 
  sqr(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApSqr<D> >(a);
  }
  // exp(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApExp<D> > 
  exp(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApExp<D> >(a);
  }
  // abs(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApAbs<D> > 
  abs(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApAbs<D> >(a);
  }
  // sgn(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApSign<D> > 
  sgn(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApSign<D> >(a);
  }
  // log(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApLog<D> > 
  log(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApLog<D> >(a);
  }
  // log10(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApLog10<D> > 
  log10(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApLog10<D> >(a);
  }
  // asin(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApAsin<D> > 
  asin(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApAsin<D> >(a);
  }

  // acos(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApAcos<D> > 
  acos(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApAcos<D> >(a);
  }
  // atan(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApAtan<D> > 
  atan(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApAtan<D> >(a);
  }
  // atan2(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApAtan2<D> > 
  atan2(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApAtan2<D> >(a);
  }
  // ceil(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApCeil<D> > 
  ceil(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApCeil<D> >(a);
  }
  // floor(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApFloor<D> > 
  floor(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApFloor<D> >(a);
  }
  // round(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApRound<D> > 
  round(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApRound<D> >(a);
  }
  // sinh(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApSinh<D> > 
  sinh(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApSinh<D> >(a);
  }
  // cosh(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApCosh<D> > 
  cosh(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApCosh<D> >(a);
  }
  // tanh(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApTanh<D> > 
  tanh(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApTanh<D> >(a);
  }

  

};


#endif 