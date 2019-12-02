#ifndef MATRICKS__FUNCTIONS_H
#define MATRICKS__FUNCTIONS_H 1


namespace matricks {





  /************************************************************
   *          Functions that apply to all tensors
   ************************************************************
   */


  // ************************************************************************
  // *              Arithmetic
  // ************************************************************************


  // +(Tensor)

  template <class E, class A, class D, int M, int R> 
    inline auto operator+(const TensorR<E,A,D,M,R>& x)
  {
    return  TER_Unary<E,A,D,M,R, Fun_Plus<D> >(x);
  }

  // -(Tensor)

  template <class E, class A, class D, int M, int R> 
    inline auto operator-(const TensorR<E,A,D,M,R>& x)
  {
    return  TER_Unary<E,A,D,M,R, Fun_Minus<D> >(x);
  }


  

};

#endif 
