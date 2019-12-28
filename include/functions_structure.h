#ifndef MATRICKS__FUNCTIONS_STRUCTURE_H
#define MATRICKS__FUNCTIONS_STRUCTURE_H 1


namespace mathq {


    
  // ************************************************************************
  // *              Transpose, Conjugate, Adjoint, and ~
  // ************************************************************************



  
  // transpose(A) 

  template <class X, class E, class D, int M, int R> 
  auto transpose(const TensorR<X,E,D,M,R>& x)
  {
    return TER_Transpose<TensorR<X,E,D,M,R>,E,D,M,R,FUNCTOR_pos<E,E,D,D>>(x);
  }

  // adjoint(A) - conjugate transpose - complex

  template <class X, class E, class D, int M, int R> 
  auto adjoint(const TensorR<X,E,std::complex<D>,M,R>& x)
  {
    return TER_Transpose<TensorR<X,E,std::complex<D>,M,R>,E,std::complex<D>,M,R,FUNCTOR_conj_complex<E,E,std::complex<D>,std::complex<D>>>(x);
  }

  

  // adjoint(A) - conjugate transpose - Imaginary

  template <class X, class E, class D, int M, int R> 
  auto adjoint(const TensorR<X,E,Imaginary<D>,M,R>& x)
  {
    return TER_Transpose<TensorR<X,E,Imaginary<D>,M,R>,E,Imaginary<D>,M,R,FUNCTOR_conj_imag<E,E,Imaginary<D>,Imaginary<D>>>(x);
  }



  
  // ~A conjugate transpose operator

  template <class X, class E, class D, int M, int R> 
  auto operator~(const TensorR<X,E,D,M,R>& x)
  {
    return adjoint(x);
  }










  // // operator, (join)


  // template <class D> 
  //    auto operator,(Vector<D>& a, Vector<D>& b)
  //   {
    
  //     printf2("  VERW_Join operator,(Vector<D>& a, Vector<D>& b)\n");
  //     return  VERW_Join<D,Vector<D>,Vector<D> >(a,b);
  //   }

  // // //--------------------------------------------
  // // // Need the const for compiler to find this
  // // // then we cast away the const
  // template <class D, class A> 
  //    auto operator,(const TensorRW<D,A>& a, const Vector<D>& b)
  //   {
  //     printf2("  VERW_Join operator,(const TensorRW<D,A>& a, const Vector<D>& b)\n");
  //     TensorRW<D,A>& a_ = const_cast<TensorRW<D,A>& >(a);
  //     Vector<D>& b_ = const_cast<Vector<D>& >(b);
  //     return  VERW_Join<D, TensorRW<D,A>,Vector<D> >(a_,b_);
  //   }
  // // //--------------------------------------------

  // // //--------------------------------------------
  // // // Need the const for compiler to find this
  // // // then we cast away the const
  // template <class D, class B> 
  //    auto operator,(const Vector<D>& a, const TensorRW<D,B>& b)
  //   {
  //     printf2("  VERW_Join operator,(const Vector<D>& a, const TensorRW<D,B>& b)\n");
  //     Vector<D>& a_ = const_cast<Vector<D>& >(a);
  //     TensorRW<D,B>& b_ = const_cast<TensorRW<D,B>& >(b);
  //     return VERW_Join<D, Vector<D>,TensorRW<D,B> >(a_,b_);
  //   }
  // // //--------------------------------------------

  // // //--------------------------------------------
  // // // Need the const for compiler to find this
  // template <class D, class A, class B> 
  //    auto operator,(const TensorRW<D,A>& a, const TensorRW<D,B>& b)
  //   {
  //     printf2("  VERW_Join operator,(const TensorRW<D,A>& a, const TensorRW<D,B>& b)\n");
  //     TensorRW<D,A>& a_ = const_cast<TensorRW<D,A>& >(a);
  //     TensorRW<D,B>& b_ = const_cast<TensorRW<D,B>& >(b);
  //     return  VERW_Join<D, TensorRW<D,A>,TensorRW<D,B> >(a_,b_);
  //   }
  // // //--------------------------------------------


  
  // // ///---------
  
  // template <class D> 
  //    const auto operator,(const Vector<D>& a, const Vector<D>& b)
  //   {
  //     printf2("  VER_Join operator,(const Vector<D>& a, const Vector<D>& b)\n");
  //     return  VER_Join<D,Vector<D>,Vector<D> >(a,b);
  //   }

  // template <class D, class B> 
  //    const auto operator,(const Vector<D>& a, const TensorR<D,B>& b)
  //   {
  //     printf2("  VER_Join operator,(const Vector<D>& a, const TensorR<D,B>& b)\n");
  //     return  VER_Join<D,Vector<D>,TensorR<D,B>  >(a,b);
  //   }

  // template <class D, class A> 
  //    const auto operator,(const TensorR<D,A>& a, const Vector<D>& b)
  //   {
  //     printf2("  VER_Join operator,(const TensorR<D,A>& a, const Vector<D>& b)\n");
  //     return  VER_Join<D,TensorR<D,A>,Vector<D> >(a,b);
  //   }
 
  // template <class D, class A, class B> 
  //    const auto operator,(const TensorR<D,A>& a, const TensorR<D,B>& b)
  //   {
  //     printf2("  VER_Join operator,(const TensorR<D,A>& a, const TensorR<D,B>& b)\n");
  //     return  VER_Join<D, TensorR<D,A>,TensorR<D,B> >(a,b);
  //   }






  // rep(v,m)

  template <class A, class D> 
   auto rep(const TensorR<A,D,D,1,1>& a, const size_type m) {
    return TER_Rep<TensorR<A,D,D,1,1>,D>(a,m);
  }

  




  

};

#endif 
