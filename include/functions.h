#ifndef MATHQ__FUNCTIONS_H
#define MATHQ__FUNCTIONS_H 1


namespace mathq {





  /************************************************************
   *          Functions that apply to all tensors
   ************************************************************
   */

  // TODO: convert macros to Python script


  // ************************************************************************
  // *             UNARY MACRO
  // ************************************************************************

#define FUN_UNARY(Function,Functor)  template <class X, class E, class D, int M, int R> \
    inline auto Function(const TensorR<X,E,D,M,R>& x)\
  {\
    return  TER_Unary<TensorR<X,E,D,M,R>,E,D,M,R, Functor<E,D> >(x);	\
  }

  // ************************************************************************
  // *             UNARY FUNCTIONS
  // ************************************************************************

  
    FUN_UNARY(operator+,FUNCTOR_plus);
    FUN_UNARY(operator-,FUNCTOR_minus);

  

};

#endif 
