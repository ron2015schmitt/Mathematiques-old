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

  template <class E, class A, class D, int M> 
    inline auto operator+(const TensorR<E,A,D,M>& a)
  {
    return  TER_Unary<E,A,D,M, Fun_Plus<D> >(a);
  }

  // -(Tensor)

  template <class E, class A, class D, int M> 
    inline auto operator-(const TensorR<E,A,D,M>& a)
  {
    return  TER_Unary<E,A,D,M, Fun_Minus<D> >(a);
  }


  

};

#endif 
