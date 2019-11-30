#ifndef FUNCTIONS_COMPLEX__H
#define FUNCTIONS_COMPLEX__H 1


namespace matricks {

  
  // ************************************************************************
  // *              Complex numbers
  // ************************************************************************

  // approxel(a,b,tol)

  template <class D, class A, class B> 
    inline TER_Bool_Binary2<
    std::complex<D>,
    TensorR<std::complex<D>,A>,
    TensorR<std::complex<D>,B>,
    Fun_Approx<std::complex<D>
    > >  
    approxel( const TensorR<std::complex<D>,A>& a,
	      const TensorR<std::complex<D>,B>& b,
	      const D tol = MatricksHelper<D>::tolerance) {
    return TER_Bool_Binary2<
      std::complex<D>,
      TensorR<std::complex<D>,A>,
      TensorR<std::complex<D>,B>,
      Fun_Approx<std::complex<D>
      > >(a,b,tol);
  }

  // -------------------------------------------------------------------
  // approx - if two tensors are approximately equal, returns a single bool
  //          checks dimensions first
  // -------------------------------------------------------------------
  template <class D, class A, class B>
    inline bool approx(const TensorR<std::complex<D>,A>& tensor1, const TensorR<std::complex<D>,B>& tensor2, const D tolerance) {
    if (!dimequiv(tensor1,tensor2)) {
      return false;
    }
    for (int ii = 0; ii < tensor1.size(); ii++) {
      if (!approx(tensor1[ii], tensor2[ii], tolerance)) {
	return false;
      }
    }
    return true;
  }


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



  // vpolar(r,phi)

  template <class D, class A, class B> 
    inline TER_Binary<std::complex<D>,TensorR<D,A>,TensorR<D,B>,Fun_Polar<D> > 
    vpolar(const TensorR<D,A>& r, const TensorR<D,B>& phi)
    {
      return  TER_Binary<std::complex<D>,TensorR<D,A>,TensorR<D,B>,Fun_Polar<D> >(r,phi);
    }
  



  // ------------------- vcomplex -------------------------------
  
  // vcomplex(x,y)

  template <class D, class A, class B> 
    inline TER_Binary<std::complex<D>,TensorR<D,A>,TensorR<D,B>,Fun_Complex<D> > 
    vcomplex(const TensorR<D,A>& x, const TensorR<D,B>& y)
    {
      return  TER_Binary<std::complex<D>,TensorR<D,A>,TensorR<D,B>,Fun_Complex<D> >(x,y);
    }


  
  // vcomplex(Tensor,realscalar)
  
  template <class D, class A, class B> 
    inline TER_TensorOpScalar<std::complex<D>, TensorR<D,A>, Fun_Complex<D> > 
    vcomplex(const TensorR<D,A>& a, const D b)
    {
      return  TER_Cplx_TensorOpScalar<D,TensorR<D,A>,Fun_Complex<D > >(a,b);
    }

  
  // vcomplex(Tensor,intscalar)

  template <class D, class A> 
    inline TER_Cplx_TensorOpScalar<D,TensorR<D,A>,Fun_Complex<D > > 
    vcomplex(const TensorR<D,A>& a, const int b)
    {
      return  TER_Cplx_TensorOpScalar<D,TensorR<D,A>,Fun_Complex<D > >(a,static_cast<D>(b));
    }

  
  // vcomplex(Tensor<int>,intscalar)

  template <class A> 
    inline TER_Cplx_TensorOpScalar<int,TensorR<int,A>,Fun_Complex<int> > 
    vcomplex(const TensorR<int,A>& a, const int b)
    {
      return  TER_Cplx_TensorOpScalar<int,TensorR<int,A>,Fun_Complex<int> >(a,static_cast<int>(b));
    }


  // vcomplex(realscalar,Tensor)

  template <class D, class B> 
    inline TER_Cplx_ScalarOpTensor<D,TensorR<D,B>,Fun_Complex<D > > 
    vcomplex(const D a, const TensorR<D,B>& b)
    {
      return  TER_Cplx_ScalarOpTensor<D,TensorR<D,B>,Fun_Complex<D > >(a,b);
    }

  // vcomplex(intscalar,Tensor)

  template <class D, class B> 
    inline TER_Cplx_ScalarOpTensor<D,TensorR<D,B>,Fun_Complex<D > > 
    vcomplex(const int a, const TensorR<D,B>& b)
    {
      return  TER_Cplx_ScalarOpTensor<D,TensorR<D,B>,Fun_Complex<D > >(static_cast<D>(a),b);
    }


  // vcomplex(intscalar,Tensor<int>)

  template <class B> 
    inline TER_Cplx_ScalarOpTensor<int,TensorR<int,B>,Fun_Complex<int> > 
    vcomplex(const int a, const TensorR<int,B>& b)
    {
      return  TER_Cplx_ScalarOpTensor<int,TensorR<int,B>,Fun_Complex<int> >(static_cast<int>(a),b);
    }



  
  // round(complex Tensor)

  template <class D, class A> 
    inline TER_Unary<std::complex<D>, TensorR<std::complex<D>, A> , Fun_RoundCplx<D> > 
    round(const TensorR<std::complex<D>,A>& a)  {
    return TER_Unary<std::complex<D>, TensorR<std::complex<D>, A>, Fun_RoundCplx<D> >(a);
  }


  // roundzero(complex Tensor)
  
  template <class D, class A> 
    inline TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>, Fun_Roundzero<std::complex<D> > > 
    roundzero(const TensorR<std::complex<D>,A>& a, const D tol = MatricksHelper<D>::tolerance)
    {
      return  TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>, Fun_Roundzero<std::complex<D> > >(a,tol);
    }









  

};

#endif 
