#ifndef MATHQ__FUNCTIONS_H
#define MATHQ__FUNCTIONS_H 1


namespace mathq {





  /************************************************************
   *          Functions that apply to all tensors
   ************************************************************
   */


  // ************************************************************************
  // *              Arithmetic
  // ************************************************************************


  // +(Tensor)

  template <class X, class E, class D, int M, int R> 
    inline auto operator+(const TensorR<X,E,D,M,R>& x)
  {
    return  TER_Unary<TensorR<X,E,D,M,R>,E,D,M,R, Fun_Plus<D> >(x);
  }

  // -(Tensor)

  template <class X, class E, class D, int M, int R> 
    inline auto operator-(const TensorR<X,E,D,M,R>& x)
  {
    return  TER_Unary<TensorR<X,E,D,M,R>,E,D,M,R, Fun_Minus<E,D> >(x);
  }


  

};

#endif 
