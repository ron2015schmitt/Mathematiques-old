#ifndef MMATHOPS_H
#define MMATHOPS_H


namespace matricks {



  //  ELEMENT-WISE MATHEMATHICAL OPERATIONS
  //  i.e. the operation such as sin is performed independently
  //  on each individual matrix element


 /************************************************************
   *               Templates for Binary Operators
   *
   * D = data type, e.g. double
   * A = either an Matrix or a Mexpr
   * B = either an Matrix or a Mexpr
   ************************************************************
   */

  // pow_el(matrix,matrix)

  template <class D, class A, class B> 
  inline MBinOp<D,MorE<D,A>,MorE<D,B>,ApPow<D> > 
  pow_el(const MorE<D,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<D,MorE<D,A>,MorE<D,B>,ApPow<D> >(a,b);
  }


  /************************************************************
   *               Templates for matrix/scalar Operators
   *
   * D = data type, e.g. double _el(matrix and scalar must be of same data type)
   * A = either an Matrix or a Mexpr
   ************************************************************
   */






  // pow_el(matrix,scalar)

  template <class D, class A> 
  inline MatOpScal<D,MorE<D,A>,ApPow<D> > 
  pow_el(const MorE<D,A>& a, const D b)
  {
    return  MatOpScal<D,MorE<D,A>,ApPow<D> >(a,b);
  }

  // pow_el(scalar,matrix)

  template <class D, class B> 
  inline ScalOpMat<D,MorE<D,B>,ApPow<D> > 
  pow_el( const D a, const MorE<D,B>& b)
  {
    return  ScalOpMat<D,MorE<D,B>,ApPow<D> >(a,b);
  }





  /****************************************************************
   *               Templates for Unary Operators & Unary Functions
   *
   * D = data type, e.g. double 
   * A = either an Matrix or a Mexpr
   *****************************************************************
   */



  // sin_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApSin<D> > 
  sin_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApSin<D> >(a);
  }


  // cos_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApCos<D> > 
  cos_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApCos<D> >(a);
  }



  // tan_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApTan<D> > 
  tan_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApTan<D> >(a);
  }
  // sqrt_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApSqrt<D> > 
  sqrt_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApSqrt<D> >(a);
  }
  // sqr_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApSqr<D> > 
  sqr_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApSqr<D> >(a);
  }
  // cube_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApCube<D> > 
  cube_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApCube<D> >(a);
  }
  // exp_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApExp<D> > 
  exp_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApExp<D> >(a);
  }
  // abs(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApAbs<D> > 
  abs(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApAbs<D> >(a);
  }
  // sgn(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApSign<D> > 
  sgn(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApSign<D> >(a);
  }
  // log_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApLog<D> > 
  log_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApLog<D> >(a);
  }
  // log10_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApLog10<D> > 
  log10_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApLog10<D> >(a);
  }
  // asin_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApAsin<D> > 
  asin_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApAsin<D> >(a);
  }

  // acos_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApAcos<D> > 
  acos_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApAcos<D> >(a);
  }
  // atan_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApAtan<D> > 
  atan_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApAtan<D> >(a);
  }
  // atan2_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApAtan2<D> > 
  atan2_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApAtan2<D> >(a);
  }
  // ceil_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApCeil<D> > 
  ceil_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApCeil<D> >(a);
  }
  // floor_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApFloor<D> > 
  floor_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApFloor<D> >(a);
  }
  // round_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApRound<D> > 
  round_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApRound<D> >(a);
  }
  // sinh_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApSinh<D> > 
  sinh_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApSinh<D> >(a);
  }
  // cosh_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApCosh<D> > 
  cosh_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApCosh<D> >(a);
  }
  // tanh_el(matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<D,A>,ApTanh<D> > 
  tanh_el(const MorE<D,A>& a)
  {
    return  MFuncOp<D,MorE<D,A>,ApTanh<D> >(a);
  }

  

};


#endif 
