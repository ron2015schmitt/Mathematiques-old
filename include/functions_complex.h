#ifndef FUNCTIONS_COMPLEX__H
#define FUNCTIONS_COMPLEX__H 1


namespace matricks {

  


  // norm(a)

  template <class D, class A> 
    inline D norm( const TensorR<std::complex<D>,A>& a ) {
    D result = D();
    
 
    for (index_type i = a.size(); i--;) {
      D tempR = a[i].real(); 
      D tempI = a[i].imag(); 
      result += tempR*tempR + tempI*tempI;
    }
    return std::sqrt(result);
  }

  // arg(complex Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<std::complex<D>,A>,Fun_Arg<D> > 
    arg(const TensorR<std::complex<D>,A>& a)
    {
      return  TER_Unary<D,TensorR<std::complex<D>,A>,Fun_Arg<D> >(a);
    }



  // polar(r,phi)

  template <class D1, class D2, class A, class B> 
    inline auto polar(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  {
    return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_Polar<D1,D2>>(a,b);
  }

  // polar(Tensor<D1> , D2)
  
  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D2>::value> > 
    inline auto polar(const TensorR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<TensorR<D1,A>,D2,D1,D2,Fun_Polar<D1,D2>>(a,b);
    }
  
  
  // polar(D1 , Tensor<D2>)
  
  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D1>::value> > 
    inline auto polar(const D1& a, const TensorR<D2,B>& b)
    {
      return  TER_Binary<D1,TensorR<D2,B>,D1,D2,Fun_Polar<D1,D2>>(a,b);
    }
  
  
  // polar(Tensor<T> , T)
  
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto polar(const TensorR<T,A>& a, const T& b)
    {
      return  TER_Binary<TensorR<T,A>,T,T,T,Fun_Polar<T,T>>(a,b);
    }
  
  
  // polar(T , Tensor<T>)
  
  template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto polar(const T& a, const TensorR<T,B>& b)
    {
      return  TER_Binary<T,TensorR<T,B>,T,T,Fun_Polar<T,T>>(a,b);
    }




  // ------------------- vcomplex -------------------------------
  
  // complexify(x,y)

  template <class D1, class D2, class A, class B> 
    inline auto complexify(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  {
    return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_Complex<D1,D2>>(a,b);
  }

 
  // complexify(Tensor<D1> , D2)
  
  template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D2>::value> > 
    inline auto complexify(const TensorR<D1,A>& a, const D2& b)
    {
      return  TER_Binary<TensorR<D1,A>,D2,D1,D2,Fun_Complex<D1,D2>>(a,b);
    }
  
  
  // complexify(D1 , Tensor<D2>)
  
  template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D1>::value> > 
    inline auto complexify(const D1& a, const TensorR<D2,B>& b)
    {
      return  TER_Binary<D1,TensorR<D2,B>,D1,D2,Fun_Complex<D1,D2>>(a,b);
    }
  
  
  // complexify(Tensor<T> , T)
  
  template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto complexify(const TensorR<T,A>& a, const T& b)
    {
      return  TER_Binary<TensorR<T,A>,T,T,T,Fun_Complex<T,T>>(a,b);
    }
  
  
  // complexify(T , Tensor<T>)
  
  template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
    inline auto complexify(const T& a, const TensorR<T,B>& b)
    {
      return  TER_Binary<T,TensorR<T,B>,T,T,Fun_Complex<T,T>>(a,b);
    }

};

#endif 
