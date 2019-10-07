#ifndef FUNCTIONS_H
#define FUNCTIONS_H 1


namespace matricks {



  /************************************************************
   *          Functions that apply to all tensors
   ************************************************************
   */


  // ************************************************************************
  // *              Arithmetic
  // ************************************************************************


  // +(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Plus<D> > 
    operator+(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Plus<D> >(a);
    }


  // -(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Minus<D> > 
    operator-(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Minus<D> >(a);
    }

  // Tensor + Tensor

  template <class D, class A, class B> 
    inline TER_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Add<D> > 
    operator+(const TensorR<D,A>& a, const TensorR<D,B>& b)
    {
      return  TER_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Add<D> >(a,b);
    }



  // Tensor - Tensor

  template <class D, class A, class B> 
    inline TER_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Subtract<D> > 
    operator-(const TensorR<D,A>& a, const TensorR<D,B>& b)
    {
      return  TER_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Subtract<D> >(a,b);
    }


  // Tensor * Tensor

  template <class D, class A, class B> 
    inline TER_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Multiply<D> > 
    operator*(const TensorR<D,A>& a, const TensorR<D,B>& b)
    {
      return  TER_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Multiply<D> >(a,b);
    }


  // Tensor / Tensor

  template <class D, class A, class B> 
    inline TER_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Divide<D> > 
    operator/(const TensorR<D,A>& a, const TensorR<D,B>& b)
    {
      return  TER_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Divide<D> >(a,b);
    }

  
  // datacast: cast data from D1 to D2

  template <class D2, class D1, class A> 
    inline TER_Unary<D2,TensorR<D1,A>,Fun_Cast<D1,D2> > 
    datacast(const TensorR<D1,A>& a)
    {
      return  TER_Unary<D2,TensorR<D1,A>,Fun_Cast<D1,D2> >(a);
    }


  /****************************************************************************
   *  dot products
   ****************************************************************************
   */


  // dot product operator (a|b)

  template <class D, class A, class B> 
    inline D operator|( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {
    D result = D();
    
 
    for (register index_type i = a.size(); i--;)
      result += a[i]*b[i];
    
    return result;
  }


  // dot product operator (areal|bcomplex)

  template <class D, class A, class B> 
    inline std::complex<D>  operator|( const TensorR<D,A>& a, const  TensorR<std::complex<D>,B>& b ) {
    std::complex<D> result = std::complex<D>();
    
 
    for (register index_type i = a.size(); i--;)
      result += a[i]*b[i];
    
    return result;
  }


  // dot product operator (acomplex|breal)

  template <class D, class A, class B> 
    inline std::complex<D>  operator|( const TensorR<std::complex<D>,A>& a, const  TensorR<D,B>& b ) {
    std::complex<D> result = std::complex<D>();
    
 
    for (register index_type i = a.size(); i--;)
      result += a[i]*b[i];
    
    return result;
  }


    // dot(a,b)

  template <class D, class A, class B> 
    inline D dot( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {
    D result = D();
    
 
    for (register index_type i = a.size(); i--;)
      result += a[i]*b[i];
    
    return result;
  }


  // dot(areal,bcomplex)

  template <class D, class A, class B> 
    inline std::complex<D>  dot( const TensorR<D,A>& a, const  TensorR<std::complex<D>,B>& b ) {
    std::complex<D> result = std::complex<D>();
    
 
    for (register index_type i = a.size(); i--;)
      result += a[i]*b[i];
    
    return result;
  }


  // dot(acomplex,breal)

  template <class D, class A, class B> 
    inline std::complex<D>  dot( const TensorR<std::complex<D>,A>& a, const  TensorR<D,B>& b ) {
    std::complex<D> result = std::complex<D>();
    
 
    for (register index_type i = a.size(); i--;)
      result += a[i]*b[i];
    
    return result;
  }

  
  // ************************************************************************
  // *            Powers and logs
  // ************************************************************************

  // pow(Tensor,Tensor)

  template <class D, class A, class B> 
    inline TER_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Pow<D> > 
    pow(const TensorR<D,A>& a, const TensorR<D,B>& b)
    {
      return  TER_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Pow<D> >(a,b);
    }


  // sqr(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Sqr<D> > 
    sqr(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Sqr<D> >(a);
    }

  // cube(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Cube<D> > 
    cube(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Cube<D> >(a);
    }

  // sqrt(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Sqrt<D> > 
    sqrt(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Sqrt<D> >(a);
    }

  // exp(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Exp<D> > 
    exp(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Exp<D> >(a);
    }



  // log(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Log<D> > 
    log(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Log<D> >(a);
    }


  // log10(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Log10<D> > 
    log10(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Log10<D> >(a);
    }


  // log2(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Log2<D> > 
    log2(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Log2<D> >(a);
    }






  // ************************************************************************
  // *            trig, inverse trig, hyperbolic trig
  // ************************************************************************

  // sin(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Sin<D> > 
    sin(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Sin<D> >(a);
    }


  // cos(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Cos<D> > 
    cos(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Cos<D> >(a);
    }



  // tan(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Tan<D> > 
    tan(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Tan<D> >(a);
    }


  // asin(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Asin<D> > 
    asin(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Asin<D> >(a);
    }


  // acos(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Acos<D> > 
    acos(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Acos<D> >(a);
    }


  // atan(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Atan<D> > 
    atan(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Atan<D> >(a);
    }


  // atan2(Tensor,Tensor)

  template <class D, class A, class B> 
    inline TER_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Atan2<D> > 
    atan2(const TensorR<D,A>& a, const TensorR<D,B>& b)
    {
      return  TER_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Atan2<D> >(a,b);
    }


  // sinh(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Sinh<D> > 
    sinh(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Sinh<D> >(a);
    }


  // cosh(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Cosh<D> > 
    cosh(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Cosh<D> >(a);
    }


  // tanh(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Tanh<D> > 
    tanh(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Tanh<D> >(a);
    }


  // ************************************************************************
  // *            sign-related and rounding
  // ************************************************************************


  // abs(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Abs<D> > 
    abs(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Abs<D> >(a);
    }


  // sgn(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Sgn<D> > 
    sgn(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Sgn<D> >(a);
    }



  // ceil(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Ceil<D> > 
    ceil(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Ceil<D> >(a);
    }


  // floor(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Floor<D> > 
    floor(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Floor<D> >(a);
    }


  // round(Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<D,A>,Fun_Round<D> > 
    round(const TensorR<D,A>& a)
    {
      return  TER_Unary<D,TensorR<D,A>,Fun_Round<D> >(a);
    }



  // roundzero(Tensor)

  template <class D, class A> 
    inline TER_TensorOpScalar<D,TensorR<D,A>,Fun_Roundzero<D> > 
    roundzero(const TensorR<D,A>& a, const D tolerance = MatricksHelper<D>::tolerance)
    {
      return  TER_TensorOpScalar<D,TensorR<D,A>,Fun_Roundzero<D> >(a, tolerance);
    }


  

  // ************************************************************************
  // *              User Defined
  // ************************************************************************


  // user-defined functions
  template <class D, typename FunctionTypes<D>::unary_func F, class A> 
    inline TER_Unary<D, TensorR<D,A>, Fun_UnaryUser<D,F> > 
    op1(const TensorR<D,A>& a)
    {
      return  TER_Unary<D, TensorR<D,A>, Fun_UnaryUser<D,F> >(a);
    }


  
  template <class D, typename FunctionTypes<D>::binary_func F, class A, class B> 
    inline TER_Binary<D, TensorR<D,A>, TensorR<D,B>, Fun_BinaryUser<D,F> > 
    op2(const TensorR<D,A>& a, const TensorR<D,B>& b)
    {
      return  TER_Binary<D, TensorR<D,A>, TensorR<D,B>, Fun_BinaryUser<D,F> >(a,b);
    }




  


  // ***********************************************************************
  // *              Logic
  // ***********************************************************************


  

  // !(Tensor)

  template <class A> 
    inline TER_Unary<bool,TensorR<bool,A>,Fun_Not > 
    operator!(const TensorR<bool,A>& a)
    {
      return  TER_Unary<bool,TensorR<bool,A>,Fun_Not >(a);
    }
  

  // Tensor && Tensor

  template <class A, class B> 
    inline TER_Binary<bool,TensorR<bool,A>,TensorR<bool,B>,Fun_And > 
    operator&&(const TensorR<bool,A>& a, const TensorR<bool,B>& b)
    {
      return  TER_Binary<bool,TensorR<bool,A>,TensorR<bool,B>,Fun_And >(a,b);
    }

  // Tensor || Tensor

  template <class A, class B> 
    inline TER_Binary<bool,TensorR<bool,A>,TensorR<bool,B>,Fun_Or > 
    operator||(const TensorR<bool,A>& a, const TensorR<bool,B>& b)
    {
      return  TER_Binary<bool,TensorR<bool,A>,TensorR<bool,B>,Fun_Or >(a,b);
    }


  // ************************************************************************
  // *            Bit wise operators for unisgned types
  // ************************************************************************


  // bitwise not (aka 1's complement): ~
  // NOTE: "~" is also used for Hermitian adjoint
  template <class A> 
    inline TER_Unary<unsigned char, TensorR<unsigned char,A> ,Fun_BitwiseNot<unsigned char> >
    operator~( const TensorR<unsigned char,A>& a ) {
    return
      TER_Unary<unsigned char, TensorR<unsigned char,A> ,Fun_BitwiseNot<unsigned char> >(a);
  }
  template <class A> 
    inline TER_Unary<unsigned short, TensorR<unsigned short,A> ,Fun_BitwiseNot<unsigned short> >
    operator~( const TensorR<unsigned short,A>& a ) {
    return
      TER_Unary<unsigned short, TensorR<unsigned short,A> ,Fun_BitwiseNot<unsigned short> >(a);
  }
  template <class A> 
    inline TER_Unary<unsigned int, TensorR<unsigned int,A> ,Fun_BitwiseNot<unsigned int> >
    operator~( const TensorR<unsigned int,A>& a ) {
    return
      TER_Unary<unsigned int, TensorR<unsigned int,A> ,Fun_BitwiseNot<unsigned int> >(a);
  }
  template <class A> 
    inline TER_Unary<unsigned long, TensorR<unsigned long,A> ,Fun_BitwiseNot<unsigned long> >
    operator~( const TensorR<unsigned long,A>& a ) {
    return
      TER_Unary<unsigned long, TensorR<unsigned long,A> ,Fun_BitwiseNot<unsigned long> >(a);
  }
  template <class A> 
    inline TER_Unary<unsigned long long, TensorR<unsigned long long,A> ,Fun_BitwiseNot<unsigned long long> >
    operator~( const TensorR<unsigned long long,A>& a ) {
    return
      TER_Unary<unsigned long long, TensorR<unsigned long long,A> ,Fun_BitwiseNot<unsigned long long> >(a);
  }

  
  // Bitwise Or: |
  // NOTE: that "|" is also used for dot product short hand 

  template <class A, class B> 
    inline TER_Binary<unsigned char,TensorR<unsigned char,A>,TensorR<unsigned char,B>,Fun_BitwiseOr<unsigned char> >
    operator|( const TensorR<unsigned char,A>& a, const  TensorR<unsigned char,B>& b ) {
    return TER_Binary<unsigned char,TensorR<unsigned char,A>,TensorR<unsigned char,B>,Fun_BitwiseOr<unsigned char> >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<unsigned short,TensorR<unsigned short,A>,TensorR<unsigned short,B>,Fun_BitwiseOr<unsigned short> >
    operator|( const TensorR<unsigned short,A>& a, const  TensorR<unsigned short,B>& b ) {
    return TER_Binary<unsigned short,TensorR<unsigned short,A>,TensorR<unsigned short,B>,Fun_BitwiseOr<unsigned short> >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<unsigned int,TensorR<unsigned int,A>,TensorR<unsigned int,B>,Fun_BitwiseOr<unsigned int> >
    operator|( const TensorR<unsigned int,A>& a, const  TensorR<unsigned int,B>& b ) {
    return TER_Binary<unsigned int,TensorR<unsigned int,A>,TensorR<unsigned int,B>,Fun_BitwiseOr<unsigned int> >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<unsigned long,TensorR<unsigned long,A>,TensorR<unsigned long,B>,Fun_BitwiseOr<unsigned long> >
    operator|( const TensorR<unsigned long,A>& a, const  TensorR<unsigned long,B>& b ) {
    return TER_Binary<unsigned long,TensorR<unsigned long,A>,TensorR<unsigned long,B>,Fun_BitwiseOr<unsigned long> >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<unsigned long long,TensorR<unsigned long long,A>,TensorR<unsigned long long,B>,Fun_BitwiseOr<unsigned long long> >
    operator|( const TensorR<unsigned long long,A>& a, const  TensorR<unsigned long long,B>& b ) {
    return TER_Binary<unsigned long long,TensorR<unsigned long long,A>,TensorR<unsigned long long,B>,Fun_BitwiseOr<unsigned long long> >(a,b);
  }

  // Bitwise And: &

  template <class A, class B> 
    inline TER_Binary<unsigned char,TensorR<unsigned char,A>,TensorR<unsigned char,B>,Fun_BitwiseAnd<unsigned char> >
    operator&( const TensorR<unsigned char,A>& a, const  TensorR<unsigned char,B>& b ) {
    return TER_Binary<unsigned char,TensorR<unsigned char,A>,TensorR<unsigned char,B>,Fun_BitwiseAnd<unsigned char> >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<unsigned short,TensorR<unsigned short,A>,TensorR<unsigned short,B>,Fun_BitwiseAnd<unsigned short> >
    operator&( const TensorR<unsigned short,A>& a, const  TensorR<unsigned short,B>& b ) {
    return TER_Binary<unsigned short,TensorR<unsigned short,A>,TensorR<unsigned short,B>,Fun_BitwiseAnd<unsigned short> >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<unsigned int,TensorR<unsigned int,A>,TensorR<unsigned int,B>,Fun_BitwiseAnd<unsigned int> >
    operator&( const TensorR<unsigned int,A>& a, const  TensorR<unsigned int,B>& b ) {
    return TER_Binary<unsigned int,TensorR<unsigned int,A>,TensorR<unsigned int,B>,Fun_BitwiseAnd<unsigned int> >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<unsigned long,TensorR<unsigned long,A>,TensorR<unsigned long,B>,Fun_BitwiseAnd<unsigned long> >
    operator&( const TensorR<unsigned long,A>& a, const  TensorR<unsigned long,B>& b ) {
    return TER_Binary<unsigned long,TensorR<unsigned long,A>,TensorR<unsigned long,B>,Fun_BitwiseAnd<unsigned long> >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<unsigned long long,TensorR<unsigned long long,A>,TensorR<unsigned long long,B>,Fun_BitwiseAnd<unsigned long long> >
    operator&( const TensorR<unsigned long long,A>& a, const  TensorR<unsigned long long,B>& b ) {
    return TER_Binary<unsigned long long,TensorR<unsigned long long,A>,TensorR<unsigned long long,B>,Fun_BitwiseAnd<unsigned long long> >(a,b);
  }


  // Bitwise Xor: ^
  // NOTE: that "^" is also used for exterior product short hand 

  template <class A, class B> 
    inline TER_Binary<unsigned char,TensorR<unsigned char,A>,TensorR<unsigned char,B>,Fun_BitwiseXor<unsigned char> >
    operator^( const TensorR<unsigned char,A>& a, const  TensorR<unsigned char,B>& b ) {
    return TER_Binary<unsigned char,TensorR<unsigned char,A>,TensorR<unsigned char,B>,Fun_BitwiseXor<unsigned char> >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<unsigned short,TensorR<unsigned short,A>,TensorR<unsigned short,B>,Fun_BitwiseXor<unsigned short> >
    operator^( const TensorR<unsigned short,A>& a, const  TensorR<unsigned short,B>& b ) {
    return TER_Binary<unsigned short,TensorR<unsigned short,A>,TensorR<unsigned short,B>,Fun_BitwiseXor<unsigned short> >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<unsigned int,TensorR<unsigned int,A>,TensorR<unsigned int,B>,Fun_BitwiseXor<unsigned int> >
    operator^( const TensorR<unsigned int,A>& a, const  TensorR<unsigned int,B>& b ) {
    return TER_Binary<unsigned int,TensorR<unsigned int,A>,TensorR<unsigned int,B>,Fun_BitwiseXor<unsigned int> >(a,b);
  }
  template <class A, class B> inline
    TER_Binary<unsigned long,TensorR<unsigned long,A>,TensorR<unsigned long,B>,Fun_BitwiseXor<unsigned long> >
    operator^( const TensorR<unsigned long,A>& a, const  TensorR<unsigned long,B>& b ) {
    return
      TER_Binary<unsigned long,TensorR<unsigned long,A>,TensorR<unsigned long,B>,Fun_BitwiseXor<unsigned long> >(a,b);
  }
  template <class A, class B> inline
    TER_Binary<unsigned long long,TensorR<unsigned long long,A>,TensorR<unsigned long long,B>,Fun_BitwiseXor<unsigned long long> >
    operator^( const TensorR<unsigned long long,A>& a, const  TensorR<unsigned long long,B>& b ) {
    return
      TER_Binary<unsigned long long,TensorR<unsigned long long,A>,TensorR<unsigned long long,B>,Fun_BitwiseXor<unsigned long long> >(a,b);
  }


  // Bitwise ShiftLeft: <<

  template <class A, class B> 
    inline TER_Binary<unsigned char,TensorR<unsigned char,A>,TensorR<unsigned char,B>,Fun_BitwiseShiftLeft<unsigned char> >
    operator<<( const TensorR<unsigned char,A>& a, const  TensorR<unsigned char,B>& b ) {
    return TER_Binary<unsigned char,TensorR<unsigned char,A>,TensorR<unsigned char,B>,Fun_BitwiseShiftLeft<unsigned char> >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<unsigned short,TensorR<unsigned short,A>,TensorR<unsigned short,B>,Fun_BitwiseShiftLeft<unsigned short> >
    operator<<( const TensorR<unsigned short,A>& a, const  TensorR<unsigned short,B>& b ) {
    return TER_Binary<unsigned short,TensorR<unsigned short,A>,TensorR<unsigned short,B>,Fun_BitwiseShiftLeft<unsigned short> >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<unsigned int,TensorR<unsigned int,A>,TensorR<unsigned int,B>,Fun_BitwiseShiftLeft<unsigned int> >
    operator<<( const TensorR<unsigned int,A>& a, const  TensorR<unsigned int,B>& b ) {
    return TER_Binary<unsigned int,TensorR<unsigned int,A>,TensorR<unsigned int,B>,Fun_BitwiseShiftLeft<unsigned int> >(a,b);
  }
  template <class A, class B> inline
    TER_Binary<unsigned long,TensorR<unsigned long,A>,TensorR<unsigned long,B>,Fun_BitwiseShiftLeft<unsigned long> >
    operator<<( const TensorR<unsigned long,A>& a, const  TensorR<unsigned long,B>& b ) {
    return
      TER_Binary<unsigned long,TensorR<unsigned long,A>,TensorR<unsigned long,B>,Fun_BitwiseShiftLeft<unsigned long> >(a,b);
  }
  template <class A, class B> inline
    TER_Binary<unsigned long long,TensorR<unsigned long long,A>,TensorR<unsigned long long,B>,Fun_BitwiseShiftLeft<unsigned long long> >
    operator<<( const TensorR<unsigned long long,A>& a, const  TensorR<unsigned long long,B>& b ) {
    return
      TER_Binary<unsigned long long,TensorR<unsigned long long,A>,TensorR<unsigned long long,B>,Fun_BitwiseShiftLeft<unsigned long long> >(a,b);
  }
  

  // Bitwise ShiftRight: >>

  template <class A, class B> 
    inline TER_Binary<unsigned char,TensorR<unsigned char,A>,TensorR<unsigned char,B>,Fun_BitwiseShiftRight<unsigned char> >
    operator>>( const TensorR<unsigned char,A>& a, const  TensorR<unsigned char,B>& b ) {
    return TER_Binary<unsigned char,TensorR<unsigned char,A>,TensorR<unsigned char,B>,Fun_BitwiseShiftRight<unsigned char> >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<unsigned short,TensorR<unsigned short,A>,TensorR<unsigned short,B>,Fun_BitwiseShiftRight<unsigned short> >
    operator>>( const TensorR<unsigned short,A>& a, const  TensorR<unsigned short,B>& b ) {
    return TER_Binary<unsigned short,TensorR<unsigned short,A>,TensorR<unsigned short,B>,Fun_BitwiseShiftRight<unsigned short> >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<unsigned int,TensorR<unsigned int,A>,TensorR<unsigned int,B>,Fun_BitwiseShiftRight<unsigned int> >
    operator>>( const TensorR<unsigned int,A>& a, const  TensorR<unsigned int,B>& b ) {
    return TER_Binary<unsigned int,TensorR<unsigned int,A>,TensorR<unsigned int,B>,Fun_BitwiseShiftRight<unsigned int> >(a,b);
  }
  template <class A, class B> inline
    TER_Binary<unsigned long,TensorR<unsigned long,A>,TensorR<unsigned long,B>,Fun_BitwiseShiftRight<unsigned long> >
    operator>>( const TensorR<unsigned long,A>& a, const  TensorR<unsigned long,B>& b ) {
    return
      TER_Binary<unsigned long,TensorR<unsigned long,A>,TensorR<unsigned long,B>,Fun_BitwiseShiftRight<unsigned long> >(a,b);
  }
  template <class A, class B> inline
    TER_Binary<unsigned long long,TensorR<unsigned long long,A>,TensorR<unsigned long long,B>,Fun_BitwiseShiftRight<unsigned long long> >
    operator>>( const TensorR<unsigned long long,A>& a, const  TensorR<unsigned long long,B>& b ) {
    return
      TER_Binary<unsigned long long,TensorR<unsigned long long,A>,TensorR<unsigned long long,B>,Fun_BitwiseShiftRight<unsigned long long> >(a,b);
  }

  
  // ************************************************************************
  // *              Relational ops (return a bool Tensor from two D Tensors)
  // ************************************************************************



  // a==b

  template <class D, class A, class B> 
    inline TER_Bool_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Equal<D> >  
    operator==( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {
    return TER_Bool_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Equal<D> >(a,b);
  }

  // approxel(a,b,tol)

  template <class D, class A, class B> 
    inline TER_Bool_Binary2<D,TensorR<D,A>,TensorR<D,B>,Fun_Approx<D> >  
    approxel( const TensorR<D,A>& a, const  TensorR<D,B>& b, const D tol = MatricksHelper<D>::tolerance) {
    return TER_Bool_Binary2<D,TensorR<D,A>,TensorR<D,B>,Fun_Approx<D> >(a,b,tol);
  }

  
  // -------------------------------------------------------------------
  // equal - if two tensors are equal. returns a single bool
  //         checks dimensions first
  // -------------------------------------------------------------------
  template <class D, class A, class B>
    inline bool equal(const TensorR<D,A>& tensor1, const TensorR<D,B>& tensor2) {
    if (!dimequiv(tensor1,tensor2)) {
      return false;
    }
    for (int ii = 0; ii < tensor1.size(); ii++) {
      if (tensor1[ii] != tensor2[ii]) {
	return false;
      }
    }
    return true;
  }


  // -------------------------------------------------------------------
  // approx - if two tensors are approximately equal, returns a single bool
  //          checks dimensions first
  // -------------------------------------------------------------------
  template <class D, class A, class B>
    inline bool approx(const TensorR<D,A>& tensor1, const TensorR<D,B>& tensor2, const D tolerance) {
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


  // a!=b

  template <class D, class A, class B> 
    inline TER_Bool_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_NotEqual<D> >  
    operator!=( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {
    return TER_Bool_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_NotEqual<D> >(a,b);
  }



  // a<=b

  template <class D, class A, class B> 
    inline TER_Bool_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_LessOrEqual<D> >  
    operator<=( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {
    return TER_Bool_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_LessOrEqual<D> >(a,b);
  }


  // a>=b

  template <class D, class A, class B> 
    inline TER_Bool_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_GreaterOrEqual<D> >  
    operator>=( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {
    return TER_Bool_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_GreaterOrEqual<D> >(a,b);
  }


  // a<b

  template <class D, class A, class B> 
    inline TER_Bool_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Less<D> >  
    operator<( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {
    return TER_Bool_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Less<D> >(a,b);
  }


  // a>b

  template <class D, class A, class B> 
    inline TER_Bool_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Greater<D> >  
    operator>( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {
    return TER_Bool_Binary<D,TensorR<D,A>,TensorR<D,B>,Fun_Greater<D> >(a,b);
  }



  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */

  // sum(a)

  template <class D, class A> 
    D sum( const TensorR<D,A>& a ) {
    
 
    const size_type N = a.size();
    if (N==0)
      return 0;

    D result = a[0];

    for (register index_type i = 1; i < N ; i++ )
      result += a[i];
    
    return result;
  }



  
  // prod(a)

  template <class D, class A> 
    D prod( const TensorR<D,A>& a ) {
    
 
    const size_type N = a.size();
    if (N==0)
      return 0;

    D result = a[0];

    for (register index_type i = 1; i < N ; i++ )
      result *= a[i];
    
    return result;
  }





  // norm(a)

  template <class D, class A> 
    D norm( const TensorR<D,A>& a ) {
    
 
    const size_type N = a.size();
    if (N==0)
      return 0;

    D result = a[0]*a[0];

    for (register index_type i = 1; i < N ; i++ )
      result += a[i]*a[i];
    
    return std::sqrt(result);
  }




  // min(a)

  template <class D, class A> 
    D min( const TensorR<D,A>& a ) {
    
 
    const size_type N = a.size();
    if (N==0)
      return 0;

    D result = a[0];

    for (register index_type i = 1; i < N ; i++ )
      result = std::min(result,a[i]);
    
    return result;
  }




  // max(a)

  template <class D, class A> 
    D max( const TensorR<D,A>& a ) {
    
    const size_type N = a.size();
    if (N==0)
      return 0;

    D result = a[0];

    for (register index_type i = 1; i < N ; i++ )
      result = std::max(result,a[i]);
    
    return result;
  }



  // norm(a)

  template <class D, class A> 
    inline D norm( const TensorR<std::complex<D>,A>& a ) {
    D result = D();
    
 
    for (register index_type i = a.size(); i--;) {
      D tempR = a[i].real(); 
      D tempI = a[i].imag(); 
      result += tempR*tempR + tempI*tempI;
    }
    return std::sqrt(result);
  }




  
  /****************************************************************************
   * Unary Functions/Operators that bools or index_type Tensors
   ****************************************************************************
   */


  
  // alltrue(a)

  template <class A> 
    inline bool alltrue( const TensorR<bool,A>& a ) {
    bool result = true;
    
 
    for (register index_type i = 0; i< a.size(); i++)
      result = result && a[i];
    
    return result;
  }


  // anytrue(a)

  template <class A> 
    inline bool anytrue( const TensorR<bool,A>& a ) {
    bool result = false;
    
 
    for (register index_type i = 0; i< a.size(); i++)
      result = result || a[i];
    
    return result;
  }


  // numtrue(a)

  template <class A> 
    inline size_type numtrue( const TensorR<bool,A>& a ) {
    size_type result = 0;
    
 
    for (register index_type i = 0; i< a.size(); i++)
      result += static_cast<index_type>(a[i]);
    
    return result;
  }


  


  // findtrue(a)

  template <class A> 
    inline Vector<index_type> findtrue( const TensorR<bool,A>& a ) {
    int N = 0;
    

    for (register index_type i = 0; i< a.size(); i++)
      N += int(a[i]);
 
    Vector<index_type> y(N);

    index_type j =0;
    for (register index_type i = 0; i< a.size(); i++)
      if (a[i])
	y[j++] = i;
    
    return y;
  }



  /************************************************************
   *               Tensor/scalar mix
   ************************************************************
   */

  //---------- Tensor scalar mix: arithmetic -----------------

  // Tensor + scalar

  template <class D, class A> 
    inline TER_TensorOpScalar<D,TensorR<D,A>,Fun_Add<D> > 
    operator+(const TensorR<D,A>& a, const D b)
    {
      return  TER_TensorOpScalar<D,TensorR<D,A>,Fun_Add<D> >(a,b);
    }

  // scalar + Tensor

  template <class D, class B>
    inline TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Add<D> > 
    operator+(const D a, const TensorR<D,B>& b )
    {
      return  TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Add<D> > (a,b);
    }


  // Tensor - scalar

  template <class D, class A> 
    inline TER_TensorOpScalar<D,TensorR<D,A>,Fun_Subtract<D> > 
    operator-(const TensorR<D,A>& a, const D b)
    {
      return  TER_TensorOpScalar<D,TensorR<D,A>,Fun_Subtract<D> >(a,b);
    }

  // scalar - Tensor

  template <class D, class B>
    inline TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Subtract<D> > 
    operator-(const D a, const TensorR<D,B>& b )
    {
      return  TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Subtract<D> > (a,b);
    }

  // Tensor * scalar

  template <class D, class A> 
    inline TER_TensorOpScalar<D,TensorR<D,A>,Fun_Multiply<D> > 
    operator*(const TensorR<D,A>& a, const D b)
    {
      return  TER_TensorOpScalar<D,TensorR<D,A>,Fun_Multiply<D> >(a,b);
    }

  // scalar * Tensor

  template <class D, class B>
    inline TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Multiply<D> > 
    operator*(const D a, const TensorR<D,B>& b )
    {
      return  TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Multiply<D> > (a,b);
    }

  // Tensor / scalar

  template <class D, class A> 
    inline TER_TensorOpScalar<D,TensorR<D,A>,Fun_Divide<D> > 
    operator/(const TensorR<D,A>& a, const D b)
    {
      return  TER_TensorOpScalar<D,TensorR<D,A>,Fun_Divide<D> >(a,b);
    }

  // scalar / Tensor

  template <class D, class B>
    inline TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Divide<D> > 
    operator/(const D a, const TensorR<D,B>& b )
    {
      return  TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Divide<D> > (a,b);
    }



  // Tensor + (int scalar)

  template <class D, class A> 
    inline TER_TensorOpScalar<D,TensorR<D,A>,Fun_Add<D> > 
    operator+(const TensorR<D,A>& a, const int b)
    {
      return  TER_TensorOpScalar<D,TensorR<D,A>,Fun_Add<D> >(a,b);
    }

  // (int scalar) + Tensor

  template <class D, class B>
    inline TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Add<D> > 
    operator+(const int a, const TensorR<D,B>& b )
    {
      return  TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Add<D> > (a,b);
    }


  // Tensor - (int scalar)

  template <class D, class A> 
    inline TER_TensorOpScalar<D,TensorR<D,A>,Fun_Subtract<D> > 
    operator-(const TensorR<D,A>& a, const int b)
    {
      return  TER_TensorOpScalar<D,TensorR<D,A>,Fun_Subtract<D> >(a,b);
    }

  // (int scalar) - Tensor

  template <class D, class B>
    inline TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Subtract<D> > 
    operator-(const int a, const TensorR<D,B>& b )
    {
      return  TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Subtract<D> > (a,b);
    }

  // Tensor * (int scalar)

  template <class D, class A> 
    inline TER_TensorOpScalar<D,TensorR<D,A>,Fun_Multiply<D> > 
    operator*(const TensorR<D,A>& a, const int b)
    {
      return  TER_TensorOpScalar<D,TensorR<D,A>,Fun_Multiply<D> >(a,b);
    }

  // (int scalar) * Tensor

  template <class D, class B>
    inline TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Multiply<D> > 
    operator*(const int a, const TensorR<D,B>& b )
    {
      return  TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Multiply<D> > (a,b);
    }

  // Tensor / (int scalar)

  template <class D, class A> 
    inline TER_TensorOpScalar<D,TensorR<D,A>,Fun_Divide<D> > 
    operator/(const TensorR<D,A>& a, const int b)
    {
      return  TER_TensorOpScalar<D,TensorR<D,A>,Fun_Divide<D> >(a,b);
    }

  // (int scalar) / Tensor

  template <class D, class B>
    inline TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Divide<D> > 
    operator/(const int a, const TensorR<D,B>& b )
    {
      return  TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Divide<D> > (a,b);
    }



  //---------- Tensor scalar mix: powers and exponents -----------------


  // pow(Tensor,scalar)

  template <class D, class A> 
    inline TER_TensorOpScalar<D,TensorR<D,A>,Fun_Pow<D> > 
    pow(const TensorR<D,A>& a, const D b)
    {
      return  TER_TensorOpScalar<D,TensorR<D,A>,Fun_Pow<D> >(a,b);
    }

  // pow(scalar,Tensor)

  template <class D, class B> 
    inline TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Pow<D> > 
    pow( const D a, const TensorR<D,B>& b)
    {
      return  TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Pow<D> >(a,b);
    }



  //---------- Tensor-scalar mix: logic -----------------

  
  // Tensor && scalar

  template <class A> 
    inline TER_TensorOpScalar<bool,TensorR<bool,A>,Fun_And > 
    operator&&(const TensorR<bool,A>& a, const bool b)
    {
      return  TER_TensorOpScalar<bool,TensorR<bool,A>,Fun_And >(a,b);
    }

  // scalar && Tensor

  template <class B> 
    inline TER_ScalarOpTensor<bool,TensorR<bool,B>,Fun_And > 
    operator&&(const bool a, const TensorR<bool,B>& b)
    {
      return  TER_ScalarOpTensor<bool,TensorR<bool,B>,Fun_And >(a,b);
    }

  
  // Tensor || scalar

  template <class A> 
    inline TER_TensorOpScalar<bool,TensorR<bool,A>,Fun_Or > 
    operator||(const TensorR<bool,A>& a, const bool b)
    {
      return  TER_TensorOpScalar<bool,TensorR<bool,A>,Fun_Or >(a,b);
    }

  // scalar || Tensor

  template <class B> 
    inline TER_ScalarOpTensor<bool,TensorR<bool,B>,Fun_Or > 
    operator||(const bool a, const TensorR<bool,B>& b)
    {
      return  TER_ScalarOpTensor<bool,TensorR<bool,B>,Fun_Or >(a,b);
    }

  //---------- Tensor scalar mix: relational -----------------


  // Tensor == scalar

  template <class D, class A> 
    inline TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_Equal<D> > 
    operator==(const TensorR<D,A>& a, const D b)
    {
      return  TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_Equal<D> >(a,b);
    }

  // scalar == Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Equal<D> > 
    operator==(const D a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Equal<D> >(a,b);
    }

  // Tensor == int scalar

  template <class D, class A> 
    inline TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_Equal<D> > 
    operator==(const TensorR<D,A>& a, const int b)
    {
      return  TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_Equal<D> >(a,static_cast<D>(b));
    }

  // int scalar == Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Equal<D> > 
    operator==(const int a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Equal<D> >(static_cast<D>(a),b);
    }

  // Tensor != scalar

  template <class D, class A> 
    inline TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_NotEqual<D> > 
    operator!=(const TensorR<D,A>& a, const D b)
    {
      return  TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_NotEqual<D> >(a,b);
    }

  // scalar != Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_NotEqual<D> > 
    operator!=(const D a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_NotEqual<D> >(a,b);
    }

  // Tensor != int scalar

  template <class D, class A> 
    inline TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_NotEqual<D> > 
    operator!=(const TensorR<D,A>& a, const int b)
    {
      return  TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_NotEqual<D> >(a,static_cast<D>(b));
    }

  // int scalar != Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_NotEqual<D> > 
    operator!=(const int a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_NotEqual<D> >(static_cast<D>(a),b);
    }

  // Tensor <= scalar

  template <class D, class A> 
    inline TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_LessOrEqual<D> > 
    operator<=(const TensorR<D,A>& a, const D b)
    {
      return  TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_LessOrEqual<D> >(a,b);
    }

  // scalar <= Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_LessOrEqual<D> > 
    operator<=(const D a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_LessOrEqual<D> >(a,b);
    }

  // Tensor <= int scalar

  template <class D, class A> 
    inline TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_LessOrEqual<D> > 
    operator<=(const TensorR<D,A>& a, const int b)
    {
      return  TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_LessOrEqual<D> >(a,static_cast<D>(b));
    }

  // int scalar <= Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_LessOrEqual<D> > 
    operator<=(const int a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_LessOrEqual<D> >(static_cast<D>(a),b);
    }

  // Tensor >= scalar

  template <class D, class A> 
    inline TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_GreaterOrEqual<D> > 
    operator>=(const TensorR<D,A>& a, const D b)
    {
      return  TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_GreaterOrEqual<D> >(a,b);
    }

  // scalar >= Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_GreaterOrEqual<D> > 
    operator>=(const D a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_GreaterOrEqual<D> >(a,b);
    }

  // Tensor >= int scalar

  template <class D, class A> 
    inline TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_GreaterOrEqual<D> > 
    operator>=(const TensorR<D,A>& a, const int b)
    {
      return  TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_GreaterOrEqual<D> >(a,static_cast<D>(b));
    }

  // int scalar >= Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_GreaterOrEqual<D> > 
    operator>=(const int a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_GreaterOrEqual<D> >(static_cast<D>(a),b);
    }

  // Tensor < scalar

  template <class D, class A> 
    inline TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_Less<D> > 
    operator<(const TensorR<D,A>& a, const D b)
    {
      return  TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_Less<D> >(a,b);
    }

  // scalar < Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Less<D> > 
    operator<(const D a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Less<D> >(a,b);
    }
  // Tensor < int scalar

  template <class D, class A> 
    inline TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_Less<D> > 
    operator<(const TensorR<D,A>& a, const int b)
    {
      return  TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_Less<D> >(a,static_cast<D>(b));
    }

  // int scalar < Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Less<D> > 
    operator<(const int a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Less<D> >(static_cast<D>(a),b);
    }

  // Tensor > scalar

  template <class D, class A> 
    inline TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_Greater<D> > 
    operator>(const TensorR<D,A>& a, const D b)
    {
      return  TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_Greater<D> >(a,b);
    }

  // scalar > Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Greater<D> > 
    operator>(const D a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Greater<D> >(a,b);
    }



  // Tensor > int scalar

  template <class D, class A> 
    inline TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_Greater<D> > 
    operator>(const TensorR<D,A>& a, const int b)
    {
      return  TER_Bool_TensorOpScalar<D,TensorR<D,A>,Fun_Greater<D> >(a,static_cast<D>(b));
    }

  // int scalar > Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Greater<D> > 
    operator>(const int a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Greater<D> >(static_cast<D>(a),b);
    }





  
  // ************************************************************************
  // *              Complex numbers
  // ************************************************************************

  // abs(complex Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<std::complex<D>,A>,Fun_CAbs<D> > 
    abs(const TensorR<std::complex<D>,A>& a)
    {
      return  TER_Unary<D,TensorR<std::complex<D>,A>,Fun_CAbs<D> >(a);
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
  

  // real(complex Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<std::complex<D>,A>,Fun_Real<D> > 
    real(const TensorR<std::complex<D>,A>& a)
    {
      return  TER_Unary<D,TensorR<std::complex<D>,A>,Fun_Real<D> >(a);
    }

  // imag(complex Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<std::complex<D>,A>,Fun_Imag<D> > 
    imag(const TensorR<std::complex<D>,A>& a)
    {
      return  TER_Unary<D,TensorR<std::complex<D>,A>,Fun_Imag<D> >(a);
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



  
  // round(complex Tensor)

  template <class D, class A> 
    inline TER_Unary<std::complex<D>, TensorR<std::complex<D>, A> , Fun_RoundCplx<D> > 
    round(const TensorR<std::complex<D>,A>& a)  {
    return TER_Unary<std::complex<D>, TensorR<std::complex<D>, A>, Fun_RoundCplx<D> >(a);
  }

  
  template <class D, class A> 
    inline TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>, Fun_Roundzero<std::complex<D> > > 
    roundzero(const TensorR<std::complex<D>,A>& a, const D tol = MatricksHelper<D>::tolerance)
    {
      return  TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>, Fun_Roundzero<std::complex<D> > >(a,tol);
    }

  // --------------------- complex/real Tensor/scalar pow(a,b) ---------------------------------


  // pow(complexTensor,realscalar)

  template <class D, class A> 
    inline TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_PowCR<D> > 
    pow(const TensorR<std::complex<D>,A>& a, const D b)
    {
      return  TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_PowCR<D> >(a,b);
    }



  // pow(complexTensor,intscalar)

  template <class D, class A> 
    inline TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_PowCR<D> > 
    pow(const TensorR<std::complex<D>,A>& a, const int b)
    {
      return  TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_PowCR<D> >(a,static_cast<D>(b));
    }

  // pow(realscalar,complexTensor)

  template <class D, class B> 
    inline TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_PowRC<D> > 
    pow(const D a, const TensorR<std::complex<D>,B>& b)
    {
      return  TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_PowRC<D> >(a,b);
    }

  // pow(intscalar,complexTensor)

  template <class D, class B> 
    inline TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_PowRC<D> > 
    pow(const int a, const TensorR<std::complex<D>,B>& b)
    {
      return  TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_PowRC<D> >(static_cast<D>(a),b);
    }

  
  // ************************************************************************
  // *              Transpose Conjugate and Adjoint
  // ************************************************************************


  // transpose(A) - conjugate transpose (Hemititan adjoint operator)

  template <class D, class A> 
    TERW_Transpose<D,TensorRW<D,A>,Fun_Plus<D> > 
    transpose(TensorRW<D,A>& a)
    {
      return TERW_Transpose<D,TensorRW<D,A>,Fun_Plus<D> >(a);
    }

  // conj(complex Tensor)

  template <class D, class A> 
    inline TER_Unary<std::complex<D>,TensorR<std::complex<D>,A>,Fun_Conj<D> > 
    conj(const TensorR<std::complex<D>,A>& a)
    {
      return  TER_Unary<std::complex<D>,TensorR<std::complex<D>,A>,Fun_Conj<D> >(a);
    }

  // adjoint(A) - conjugate transpose 

  template <class D, class A> 
    inline TER_Transpose<std::complex<D>,TensorR<std::complex<D>,A>,Fun_Conj<D> > 
    adjoint(const TensorR<std::complex<D>,A>& a)
    {
      return  TER_Transpose<std::complex<D>,TensorR<std::complex<D>,A>,Fun_Conj<D> >(a);
    }

  
  // ~A conjugate transpose operator

  template <class D, class A> 
    inline TER_Transpose<std::complex<D>,TensorR<std::complex<D>,A>,Fun_Conj<D> > 
    operator~(const TensorR<std::complex<D>,A>& a)
    {
      return  TER_Transpose<std::complex<D>,TensorR<std::complex<D>,A>,Fun_Conj<D> >(a);
    }







  //************************************************************************
  //                 COMPLEX / REAL - Tensor / Scalar mixed artimetic
  //************************************************************************
  
  

  // complexTensor + realTensor
  template <class D, class A, class B> 
    inline TER_Binary<std::complex<D>,TensorR<std::complex<D>,A>,TensorR<D,B>,Fun_AddCR<D> > 
    operator+(const TensorR<std::complex<D>,A>& a, const TensorR<D,B>& b)
    {
      return  TER_Binary<std::complex<D>,TensorR<std::complex<D>,A>,TensorR<D,B>,Fun_AddCR<D> >(a,b);
    }
  // realTensor + complexTensor 
  template <class D, class A, class B> 
    inline TER_Binary<std::complex<D>,TensorR<D,A>,TensorR<std::complex<D>,B>,Fun_AddRC<D> > 
    operator+(const TensorR<D,A>& a, const TensorR<std::complex<D>,B>& b)
    {
      return  TER_Binary<std::complex<D>,TensorR<D,A>,TensorR<std::complex<D>,B>,Fun_AddRC<D> >(a,b);
    }
  // realTensor + complexscalar
  template <class D, class A> 
    inline TER_TensorOpScalar< std::complex<D>,TensorR<D,A>,Fun_AddRC<D> > 
    operator+(const TensorR<D,A>& a, const std::complex<D> b)
    {
      return  
	TER_TensorOpScalar< std::complex<D>,TensorR<D,A>,Fun_AddRC<D> >( a,b );
    }

  // complexscalar +  realTensor 
  template <class D, class B> 
    inline TER_ScalarOpTensor< std::complex<D>,TensorR<D,B>,Fun_AddCR<D> > 
    operator+(const std::complex<D> a, const TensorR<D,B>& b)
    {
      return  
	TER_ScalarOpTensor< std::complex<D>,TensorR<D,B>,Fun_AddCR<D> >( a, b );
    }
  // complexTensor + realscalar
  template <class D, class A> 
    inline TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_AddCR<D> > 
    operator+(const TensorR<std::complex<D>,A>& a, const D b)
    {
      return  
	TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_AddCR<D> >(a,b);  
    }
  // complexTensor + intscalar
  template <class D, class A> 
    inline TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_AddCR<D> > 
    operator+(const TensorR<std::complex<D>,A>& a, const int b)
    {
      return  
	TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_AddCR<D> >(a,static_cast<D>(b));  
    }
  // realscalar + complexTensor
  template <class D, class B> 
    inline TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_AddRC<D> > 
    operator+(const D a, const TensorR<std::complex<D>,B>& b)
    {
      return  
	TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_AddRC<D> >(a,b);  
    }
  // intscalar + complexTensor
  template <class D, class B> 
    inline TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_AddRC<D> > 
    operator+(const int a, const TensorR<std::complex<D>,B>& b)
    {
      return  
	TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_AddRC<D > >(static_cast<D>(a),b);  
    }


  // complexTensor - realTensor
  template <class D, class A, class B> 
    inline TER_Binary<std::complex<D>,TensorR<std::complex<D>,A>,TensorR<D,B>,Fun_SubtractCR<D> > 
    operator-(const TensorR<std::complex<D>,A>& a, const TensorR<D,B>& b)
    {
      return  TER_Binary<std::complex<D>,TensorR<std::complex<D>,A>,TensorR<D,B>,Fun_SubtractCR<D> >(a,b);
    }
  // realTensor - complexTensor 
  template <class D, class A, class B> 
    inline TER_Binary<std::complex<D>,TensorR<D,A>,TensorR<std::complex<D>,B>,Fun_SubtractRC<D> > 
    operator-(const TensorR<D,A>& a, const TensorR<std::complex<D>,B>& b)
    {
      return  TER_Binary<std::complex<D>,TensorR<D,A>,TensorR<std::complex<D>,B>,Fun_SubtractRC<D> >(a,b);
    }

  // realTensor - complexscalar
  template <class D, class A> 
    inline TER_TensorOpScalar< std::complex<D>,TensorR<D,A>,Fun_SubtractRC<D> > 
    operator-(const TensorR<D,A>& a, const std::complex<D> b)
    {
      return  
	TER_TensorOpScalar< std::complex<D>,TensorR<D,A>,Fun_SubtractRC<D> >( a,b );
    }

  // complexscalar -  realTensor 
  template <class D, class B> 
    inline TER_ScalarOpTensor< std::complex<D>,TensorR<D,B>,Fun_SubtractCR<D> > 
    operator-(const std::complex<D> a, const TensorR<D,B>& b)
    {
      return  
	TER_ScalarOpTensor< std::complex<D>,TensorR<D,B>,Fun_SubtractCR<D> >( a, b );
    }
  // complexTensor - realscalar
  template <class D, class A> 
    inline TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_SubtractCR<D> > 
    operator-(const TensorR<std::complex<D>,A>& a, const D b)
    {
      return  
	TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_SubtractCR<D> >(a,b);  
    }
  // complexTensor - intscalar
  template <class D, class A> 
    inline TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_SubtractCR<D> > 
    operator-(const TensorR<std::complex<D>,A>& a, const int b)
    {
      return  
	TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_SubtractCR<D> >(a,static_cast<D>(b));  
    }
  // realscalar - complexTensor
  template <class D, class B> 
    inline TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_SubtractRC<D> > 
    operator-(const D a, const TensorR<std::complex<D>,B>& b)
    {
      return  
	TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_SubtractRC<D> >(a,b);  
    }
  // intscalar - complexTensor
  template <class D, class B> 
    inline TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_SubtractRC<D> > 
    operator-(const int a, const TensorR<std::complex<D>,B>& b)
    {
      return  
	TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_SubtractRC<D > >(static_cast<D>(a),b);  
    }



  // complexTensor * realTensor
  template <class D, class A, class B> 
    inline TER_Binary<std::complex<D>,TensorR<std::complex<D>,A>,TensorR<D,B>,Fun_MultiplyCR<D> > 
    operator*(const TensorR<std::complex<D>,A>& a, const TensorR<D,B>& b)
    {
      return  TER_Binary<std::complex<D>,TensorR<std::complex<D>,A>,TensorR<D,B>,Fun_MultiplyCR<D> >(a,b);
    }
  // realTensor * complexTensor 
  template <class D, class A, class B> 
    inline TER_Binary<std::complex<D>,TensorR<D,A>,TensorR<std::complex<D>,B>,Fun_MultiplyRC<D> > 
    operator*(const TensorR<D,A>& a, const TensorR<std::complex<D>,B>& b)
    {
      return  TER_Binary<std::complex<D>,TensorR<D,A>,TensorR<std::complex<D>,B>,Fun_MultiplyRC<D> >(a,b);
    }

  // realTensor * complexscalar
  template <class D, class A> 
    inline TER_TensorOpScalar< std::complex<D>,TensorR<D,A>,Fun_MultiplyRC<D> > 
    operator*(const TensorR<D,A>& a, const std::complex<D> b)
    {
      return  
	TER_TensorOpScalar< std::complex<D>,TensorR<D,A>,Fun_MultiplyRC<D> >( a,b );
    }

  // complexscalar *  realTensor 
  template <class D, class B> 
    inline TER_ScalarOpTensor<std::complex<D>,TensorR<D,B>,Fun_MultiplyCR<D> > 
    operator*(const std::complex<D> a, const TensorR<D,B>& b)
    {
      return  
	TER_ScalarOpTensor< std::complex<D>,TensorR<D,B>,Fun_MultiplyCR<D> >( a, b );
    }
  // complexTensor * realscalar
  template <class D, class A> 
    inline TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_MultiplyCR<D> > 
    operator*(const TensorR<std::complex<D>,A>& a, const D b)
    {
      return  
	TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_MultiplyCR<D> >(a,b);  
    }
  // complexTensor * intscalar
  template <class D, class A> 
    inline TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_MultiplyCR<D> > 
    operator*(const TensorR<std::complex<D>,A>& a, const int b)
    {
      return  
	TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_MultiplyCR<D> >(a,static_cast<D>(b));  
    }
  // realscalar * complexTensor
  template <class D, class B> 
    inline TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_MultiplyRC<D> > 
    operator*(const D a, const TensorR<std::complex<D>,B>& b)
    {
      return  
	TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_MultiplyRC<D> >(a,b);  
    }
  // intscalar * complexTensor
  template <class D, class B> 
    inline TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_MultiplyRC<D> > 
    operator*(const int a, const TensorR<std::complex<D>,B>& b)
    {
      return  
	TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_MultiplyRC<D > >(static_cast<D>(a),b);  
    }


  // complexTensor / realTensor
  template <class D, class A, class B> 
    inline TER_Binary<std::complex<D>,TensorR<std::complex<D>,A>,TensorR<D,B>,Fun_DivideCR<D> > 
    operator/(const TensorR<std::complex<D>,A>& a, const TensorR<D,B>& b)
    {
      return  TER_Binary<std::complex<D>,TensorR<std::complex<D>,A>,TensorR<D,B>,Fun_DivideCR<D> >(a,b);
    }
  // realTensor / complexTensor 
  template <class D, class A, class B> 
    inline TER_Binary<std::complex<D>,TensorR<D,A>,TensorR<std::complex<D>,B>,Fun_DivideRC<D> > 
    operator/(const TensorR<D,A>& a, const TensorR<std::complex<D>,B>& b)
    {
      return  TER_Binary<std::complex<D>,TensorR<D,A>,TensorR<std::complex<D>,B>,Fun_DivideRC<D> >(a,b);
    }


  // realTensor / complexscalar
  template <class D, class A> 
    inline TER_TensorOpScalar< std::complex<D>,TensorR<D,A>,Fun_DivideRC<D> > 
    operator/(const TensorR<D,A>& a, const std::complex<D> b)
    {
      return  
	TER_TensorOpScalar< std::complex<D>,TensorR<D,A>,Fun_DivideRC<D> >( a,b );
    }

  // complexscalar /  realTensor 
  template <class D, class B> 
    inline TER_ScalarOpTensor< std::complex<D>,TensorR<D,B>,Fun_DivideCR<D> > 
    operator/(const std::complex<D> a, const TensorR<D,B>& b)
    {
      return  
	TER_ScalarOpTensor< std::complex<D>,TensorR<D,B>,Fun_DivideCR<D> >( a, b );
    }
  // complexTensor / realscalar
  template <class D, class A> 
    inline TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_DivideCR<D> > 
    operator/(const TensorR<std::complex<D>,A>& a, const D b)
    {
      return  
	TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_DivideCR<D> >(a,b);  
    }
  // complexTensor / intscalar
  template <class D, class A> 
    inline TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_DivideCR<D> > 
    operator/(const TensorR<std::complex<D>,A>& a, const int b)
    {
      return  
	TER_Cplx_TensorOpScalar<D,TensorR<std::complex<D>,A>,Fun_DivideCR<D> >(a,static_cast<D>(b));  
    }
  // realscalar / complexTensor
  template <class D, class B> 
    inline TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_DivideRC<D> > 
    operator/(const D a, const TensorR<std::complex<D>,B>& b)
    {
      return  
	TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_DivideRC<D> >(a,b);  
    }
  // intscalar / complexTensor
  template <class D, class B> 
    inline TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_DivideRC<D> > 
    operator/(const int a, const TensorR<std::complex<D>,B>& b)
    {
      return  
	TER_Cplx_ScalarOpTensor<D,TensorR<std::complex<D>,B>,Fun_DivideRC<D > >(static_cast<D>(a),b);  
    }






  

};

#endif 
