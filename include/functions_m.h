#ifndef MATRICKS__FUNCTIONS_M_H
#define MATRICKS__FUNCTIONS_M_H 1


namespace matricks {



  /************************************************************
   *          Functions that apply to Matrix only
   ************************************************************
   */


  // TODO: check that has exactly two dimensions


  // transpose(A) - conjugate transpose (Hemititan adjoint operator)

  template <class D, class A> 
    TERW_Transpose<D,TensorRW<D,A>,Fun_Plus<D> > 
    transpose(TensorRW<D,A>& a)
    {
      return TERW_Transpose<D,TensorRW<D,A>,Fun_Plus<D> >(a);
    }

};
#endif 
