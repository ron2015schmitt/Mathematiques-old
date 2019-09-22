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


  // +(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Plus<D> > 
    operator+(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Plus<D> >(a);
    }


  // -(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Minus<D> > 
    operator-(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Minus<D> >(a);
    }

  // vector + vector

  template <class D, class A, class B> 
    inline VBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Add<D> > 
    operator+(const VorE<D,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Add<D> >(a,b);
    }



  // vector - vector

  template <class D, class A, class B> 
    inline VBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Subtract<D> > 
    operator-(const VorE<D,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Subtract<D> >(a,b);
    }


  // vector * vector

  template <class D, class A, class B> 
    inline VBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Multiply<D> > 
    operator*(const VorE<D,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Multiply<D> >(a,b);
    }


  // vector / vector

  template <class D, class A, class B> 
    inline VBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Divide<D> > 
    operator/(const VorE<D,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Divide<D> >(a,b);
    }

  
  // dcast: cast data from D1 to D2

  template <class D2, class D1, class A> 
    inline VFuncOp<D2,VorE<D1,A>,Fun_Cast<D1,D2> > 
    dcast(const VorE<D1,A>& a)
    {
      return  VFuncOp<D2,VorE<D1,A>,Fun_Cast<D1,D2> >(a);
    }

  // ************************************************************************
  // *            Powers and logs
  // ************************************************************************

  // pow(vector,vector)

  template <class D, class A, class B> 
    inline VBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Pow<D> > 
    pow(const VorE<D,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Pow<D> >(a,b);
    }



  // ************************************************************************
  // *            trig, inverse trig, hyperbolic trig
  // ************************************************************************

  // sin(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Sin<D> > 
    sin(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Sin<D> >(a);
    }


  // cos(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Cos<D> > 
    cos(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Cos<D> >(a);
    }



  // tan(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Tan<D> > 
    tan(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Tan<D> >(a);
    }


  // asin(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Asin<D> > 
    asin(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Asin<D> >(a);
    }


  // acos(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Acos<D> > 
    acos(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Acos<D> >(a);
    }


  // atan(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Atan<D> > 
    atan(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Atan<D> >(a);
    }


  // atan2(vector,vector)

  template <class D, class A, class B> 
    inline VBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Atan2<D> > 
    atan2(const VorE<D,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Atan2<D> >(a,b);
    }


  // sinh(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Sinh<D> > 
    sinh(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Sinh<D> >(a);
    }


  // cosh(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Cosh<D> > 
    cosh(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Cosh<D> >(a);
    }


  // tanh(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Tanh<D> > 
    tanh(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Tanh<D> >(a);
    }


  // ************************************************************************
  // *            sign-related and rounding
  // ************************************************************************


  // abs(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Abs<D> > 
    abs(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Abs<D> >(a);
    }


  // sgn(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Sgn<D> > 
    sgn(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Sgn<D> >(a);
    }



  // ceil(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Ceil<D> > 
    ceil(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Ceil<D> >(a);
    }


  // floor(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Floor<D> > 
    floor(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Floor<D> >(a);
    }


  // round(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Round<D> > 
    round(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Round<D> >(a);
    }

  template <class D, class A> 
    inline VecOpScal<D,VorE<D,A>,Fun_Roundzero<D> > 
    roundzero(const VorE<D,A>& a, const D tolerance = MatricksHelper<D>::tolerance)
    {
      return  VecOpScal<D,VorE<D,A>,Fun_Roundzero<D> >(a, tolerance);
    }


  
  

  // complexvector + realvector
  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,Fun_AddCR<D> > 
    operator+(const VorE<std::complex<D>,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,Fun_AddCR<D> >(a,b);
    }
  // realvector + complexvector 
  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,Fun_AddRC<D> > 
    operator+(const VorE<D,A>& a, const VorE<std::complex<D>,B>& b)
    {
      return  VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,Fun_AddRC<D> >(a,b);
    }


  // complexvector - realvector
  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,Fun_SubtractCR<D> > 
    operator-(const VorE<std::complex<D>,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,Fun_SubtractCR<D> >(a,b);
    }
  // realvector - complexvector 
  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,Fun_SubtractRC<D> > 
    operator-(const VorE<D,A>& a, const VorE<std::complex<D>,B>& b)
    {
      return  VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,Fun_SubtractRC<D> >(a,b);
    }



  // complexvector * realvector
  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,Fun_MultiplyCR<D> > 
    operator*(const VorE<std::complex<D>,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,Fun_MultiplyCR<D> >(a,b);
    }
  // realvector * complexvector 
  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,Fun_MultiplyRC<D> > 
    operator*(const VorE<D,A>& a, const VorE<std::complex<D>,B>& b)
    {
      return  VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,Fun_MultiplyRC<D> >(a,b);
    }



  // complexvector / realvector
  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,Fun_DivideCR<D> > 
    operator/(const VorE<std::complex<D>,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,Fun_DivideCR<D> >(a,b);
    }
  // realvector / complexvector 
  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,Fun_DivideRC<D> > 
    operator/(const VorE<D,A>& a, const VorE<std::complex<D>,B>& b)
    {
      return  VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,Fun_DivideRC<D> >(a,b);
    }




  // *** functions that return a complex vector from 2 real vectors ***

  // vpolar(r,phi)

  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<D,A>,VorE<D,B>,Fun_Polar<D> > 
    vpolar(const VorE<D,A>& r, const VorE<D,B>& phi)
    {
      return  VBinOp<std::complex<D>,VorE<D,A>,VorE<D,B>,Fun_Polar<D> >(r,phi);
    }


  // vcomplex(x,y)

  template <class D, class A, class B> 
    inline VBinOp<std::complex<D>,VorE<D,A>,VorE<D,B>,Fun_Complex<D> > 
    vcomplex(const VorE<D,A>& x, const VorE<D,B>& y)
    {
      return  VBinOp<std::complex<D>,VorE<D,A>,VorE<D,B>,Fun_Complex<D> >(x,y);
    }



  // pow(complexvector,realscalar)

  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,Fun_PowCR<D> > 
    pow(const VorE<std::complex<D>,A>& a, const D b)
    {
      return  CVecOpScal<D,VorE<std::complex<D>,A>,Fun_PowCR<D> >(a,b);
    }

  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>, Fun_Roundzero<std::complex<D> > > 
    roundzero(const VorE<std::complex<D>,A>& a, const D tol = MatricksHelper<D>::tolerance)
    {
      return  CVecOpScal<D,VorE<std::complex<D>,A>, Fun_Roundzero<std::complex<D> > >(a,tol);
    }


  // pow(complexvector,intscalar)

  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,Fun_PowCR<D> > 
    pow(const VorE<std::complex<D>,A>& a, const int b)
    {
      return  CVecOpScal<D,VorE<std::complex<D>,A>,Fun_PowCR<D> >(a,static_cast<D>(b));
    }

  // pow(realscalar,complexvector)

  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,Fun_PowRC<D> > 
    pow(const D a, const VorE<std::complex<D>,B>& b)
    {
      return  CScalOpVec<D,VorE<std::complex<D>,B>,Fun_PowRC<D> >(a,b);
    }

  // pow(intscalar,complexvector)

  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,Fun_PowRC<D> > 
    pow(const int a, const VorE<std::complex<D>,B>& b)
    {
      return  CScalOpVec<D,VorE<std::complex<D>,B>,Fun_PowRC<D> >(static_cast<D>(a),b);
    }


 
  
  // vcomplex(vector,realscalar)

  
  template <class D, class A, class B> 
    inline VecOpScal<std::complex<D>, VorE<D,A>, Fun_Complex<D> > 
    vcomplex(const VorE<D,A>& a, const D b)
    {
      return  CVecOpScal<D,VorE<D,A>,Fun_Complex<D > >(a,b);
    }
  // vcomplex(vector,intscalar)

  template <class D, class A> 
    inline CVecOpScal<D,VorE<D,A>,Fun_Complex<D > > 
    vcomplex(const VorE<D,A>& a, const int b)
    {
      return  CVecOpScal<D,VorE<D,A>,Fun_Complex<D > >(a,static_cast<D>(b));
    }

  // vcomplex(realscalar,vector)

  template <class D, class B> 
    inline CScalOpVec<D,VorE<D,B>,Fun_Complex<D > > 
    vcomplex(const D a, const VorE<D,B>& b)
    {
      return  CScalOpVec<D,VorE<D,B>,Fun_Complex<D > >(a,b);
    }
  // vcomplex(intscalar,vector)

  template <class D, class B> 
    inline CScalOpVec<D,VorE<D,B>,Fun_Complex<D > > 
    vcomplex(const int a, const VorE<D,B>& b)
    {
      return  CScalOpVec<D,VorE<D,B>,Fun_Complex<D > >(static_cast<D>(a),b);
    }


  




  // a==b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Equal<D> >  
    operator==( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Equal<D> >(a,b);
  }


  // a!=b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,Fun_NotEqual<D> >  
    operator!=( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,Fun_NotEqual<D> >(a,b);
  }



  // a<=b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,Fun_LessOrEqual<D> >  
    operator<=( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,Fun_LessOrEqual<D> >(a,b);
  }


  // a>=b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,Fun_GreaterOrEqual<D> >  
    operator>=( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,Fun_GreaterOrEqual<D> >(a,b);
  }


  // a<b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Less<D> >  
    operator<( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Less<D> >(a,b);
  }


  // a>b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Greater<D> >  
    operator>( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,Fun_Greater<D> >(a,b);
  }




  /************************************************************
   *               vector/scalar Operators
   *
   * D = data type, e.g. double (vector and scalar must be of same data type)
   * A = either an Vector or a Vexpr
   ************************************************************
   */


  // vector + scalar

  template <class D, class A> 
    inline VecOpScal<D,VorE<D,A>,Fun_Add<D> > 
    operator+(const VorE<D,A>& a, const D b)
    {
      return  VecOpScal<D,VorE<D,A>,Fun_Add<D> >(a,b);
    }

  // scalar + vector

  template <class D, class B>
    inline ScalOpVec<D,VorE<D,B>,Fun_Add<D> > 
    operator+(const D a, const VorE<D,B>& b )
    {
      return  ScalOpVec<D,VorE<D,B>,Fun_Add<D> > (a,b);
    }


  // vector - scalar

  template <class D, class A> 
    inline VecOpScal<D,VorE<D,A>,Fun_Subtract<D> > 
    operator-(const VorE<D,A>& a, const D b)
    {
      return  VecOpScal<D,VorE<D,A>,Fun_Subtract<D> >(a,b);
    }

  // scalar - vector

  template <class D, class B>
    inline ScalOpVec<D,VorE<D,B>,Fun_Subtract<D> > 
    operator-(const D a, const VorE<D,B>& b )
    {
      return  ScalOpVec<D,VorE<D,B>,Fun_Subtract<D> > (a,b);
    }

  // vector * scalar

  template <class D, class A> 
    inline VecOpScal<D,VorE<D,A>,Fun_Multiply<D> > 
    operator*(const VorE<D,A>& a, const D b)
    {
      return  VecOpScal<D,VorE<D,A>,Fun_Multiply<D> >(a,b);
    }

  // scalar * vector

  template <class D, class B>
    inline ScalOpVec<D,VorE<D,B>,Fun_Multiply<D> > 
    operator*(const D a, const VorE<D,B>& b )
    {
      return  ScalOpVec<D,VorE<D,B>,Fun_Multiply<D> > (a,b);
    }

  // vector / scalar

  template <class D, class A> 
    inline VecOpScal<D,VorE<D,A>,Fun_Divide<D> > 
    operator/(const VorE<D,A>& a, const D b)
    {
      return  VecOpScal<D,VorE<D,A>,Fun_Divide<D> >(a,b);
    }

  // scalar / vector

  template <class D, class B>
    inline ScalOpVec<D,VorE<D,B>,Fun_Divide<D> > 
    operator/(const D a, const VorE<D,B>& b )
    {
      return  ScalOpVec<D,VorE<D,B>,Fun_Divide<D> > (a,b);
    }


  // the following are defined for convenience

  // vector + (int scalar)

  template <class D, class A> 
    inline VecOpScal<D,VorE<D,A>,Fun_Add<D> > 
    operator+(const VorE<D,A>& a, const int b)
    {
      return  VecOpScal<D,VorE<D,A>,Fun_Add<D> >(a,b);
    }

  // (int scalar) + vector

  template <class D, class B>
    inline ScalOpVec<D,VorE<D,B>,Fun_Add<D> > 
    operator+(const int a, const VorE<D,B>& b )
    {
      return  ScalOpVec<D,VorE<D,B>,Fun_Add<D> > (a,b);
    }


  // vector - (int scalar)

  template <class D, class A> 
    inline VecOpScal<D,VorE<D,A>,Fun_Subtract<D> > 
    operator-(const VorE<D,A>& a, const int b)
    {
      return  VecOpScal<D,VorE<D,A>,Fun_Subtract<D> >(a,b);
    }

  // (int scalar) - vector

  template <class D, class B>
    inline ScalOpVec<D,VorE<D,B>,Fun_Subtract<D> > 
    operator-(const int a, const VorE<D,B>& b )
    {
      return  ScalOpVec<D,VorE<D,B>,Fun_Subtract<D> > (a,b);
    }

  // vector * (int scalar)

  template <class D, class A> 
    inline VecOpScal<D,VorE<D,A>,Fun_Multiply<D> > 
    operator*(const VorE<D,A>& a, const int b)
    {
      return  VecOpScal<D,VorE<D,A>,Fun_Multiply<D> >(a,b);
    }

  // (int scalar) * vector

  template <class D, class B>
    inline ScalOpVec<D,VorE<D,B>,Fun_Multiply<D> > 
    operator*(const int a, const VorE<D,B>& b )
    {
      return  ScalOpVec<D,VorE<D,B>,Fun_Multiply<D> > (a,b);
    }

  // vector / (int scalar)

  template <class D, class A> 
    inline VecOpScal<D,VorE<D,A>,Fun_Divide<D> > 
    operator/(const VorE<D,A>& a, const int b)
    {
      return  VecOpScal<D,VorE<D,A>,Fun_Divide<D> >(a,b);
    }

  // (int scalar) / vector

  template <class D, class B>
    inline ScalOpVec<D,VorE<D,B>,Fun_Divide<D> > 
    operator/(const int a, const VorE<D,B>& b )
    {
      return  ScalOpVec<D,VorE<D,B>,Fun_Divide<D> > (a,b);
    }







  // pow(vector,scalar)

  template <class D, class A> 
    inline VecOpScal<D,VorE<D,A>,Fun_Pow<D> > 
    pow(const VorE<D,A>& a, const D b)
    {
      return  VecOpScal<D,VorE<D,A>,Fun_Pow<D> >(a,b);
    }

  // pow(scalar,vector)

  template <class D, class B> 
    inline ScalOpVec<D,VorE<D,B>,Fun_Pow<D> > 
    pow( const D a, const VorE<D,B>& b)
    {
      return  ScalOpVec<D,VorE<D,B>,Fun_Pow<D> >(a,b);
    }



  // realvector + complexscalar
  template <class D, class A> 
    inline VecOpScal< std::complex<D>,VorE<D,A>,Fun_AddRC<D> > 
    operator+(const VorE<D,A>& a, const std::complex<D> b)
    {
      return  
	VecOpScal< std::complex<D>,VorE<D,A>,Fun_AddRC<D> >( a,b );
    }

  // complexscalar +  realvector 
  template <class D, class B> 
    inline ScalOpVec< std::complex<D>,VorE<D,B>,Fun_AddCR<D> > 
    operator+(const std::complex<D> a, const VorE<D,B>& b)
    {
      return  
	ScalOpVec< std::complex<D>,VorE<D,B>,Fun_AddCR<D> >( a, b );
    }
  // complexvector + realscalar
  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,Fun_AddCR<D> > 
    operator+(const VorE<std::complex<D>,A>& a, const D b)
    {
      return  
	CVecOpScal<D,VorE<std::complex<D>,A>,Fun_AddCR<D> >(a,b);  
    }
  // complexvector + intscalar
  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,Fun_AddCR<D> > 
    operator+(const VorE<std::complex<D>,A>& a, const int b)
    {
      return  
	CVecOpScal<D,VorE<std::complex<D>,A>,Fun_AddCR<D> >(a,static_cast<D>(b));  
    }
  // realscalar + complexvector
  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,Fun_AddRC<D> > 
    operator+(const D a, const VorE<std::complex<D>,B>& b)
    {
      return  
	CScalOpVec<D,VorE<std::complex<D>,B>,Fun_AddRC<D> >(a,b);  
    }
  // intscalar + complexvector
  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,Fun_AddRC<D> > 
    operator+(const int a, const VorE<std::complex<D>,B>& b)
    {
      return  
	CScalOpVec<D,VorE<std::complex<D>,B>,Fun_AddRC<D > >(static_cast<D>(a),b);  
    }



  // realvector - complexscalar
  template <class D, class A> 
    inline VecOpScal< std::complex<D>,VorE<D,A>,Fun_SubtractRC<D> > 
    operator-(const VorE<D,A>& a, const std::complex<D> b)
    {
      return  
	VecOpScal< std::complex<D>,VorE<D,A>,Fun_SubtractRC<D> >( a,b );
    }

  // complexscalar -  realvector 
  template <class D, class B> 
    inline ScalOpVec< std::complex<D>,VorE<D,B>,Fun_SubtractCR<D> > 
    operator-(const std::complex<D> a, const VorE<D,B>& b)
    {
      return  
	ScalOpVec< std::complex<D>,VorE<D,B>,Fun_SubtractCR<D> >( a, b );
    }
  // complexvector - realscalar
  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,Fun_SubtractCR<D> > 
    operator-(const VorE<std::complex<D>,A>& a, const D b)
    {
      return  
	CVecOpScal<D,VorE<std::complex<D>,A>,Fun_SubtractCR<D> >(a,b);  
    }
  // complexvector - intscalar
  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,Fun_SubtractCR<D> > 
    operator-(const VorE<std::complex<D>,A>& a, const int b)
    {
      return  
	CVecOpScal<D,VorE<std::complex<D>,A>,Fun_SubtractCR<D> >(a,static_cast<D>(b));  
    }
  // realscalar - complexvector
  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,Fun_SubtractRC<D> > 
    operator-(const D a, const VorE<std::complex<D>,B>& b)
    {
      return  
	CScalOpVec<D,VorE<std::complex<D>,B>,Fun_SubtractRC<D> >(a,b);  
    }
  // intscalar - complexvector
  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,Fun_SubtractRC<D> > 
    operator-(const int a, const VorE<std::complex<D>,B>& b)
    {
      return  
	CScalOpVec<D,VorE<std::complex<D>,B>,Fun_SubtractRC<D > >(static_cast<D>(a),b);  
    }


  // realvector * complexscalar
  template <class D, class A> 
    inline VecOpScal< std::complex<D>,VorE<D,A>,Fun_MultiplyRC<D> > 
    operator*(const VorE<D,A>& a, const std::complex<D> b)
    {
      return  
	VecOpScal< std::complex<D>,VorE<D,A>,Fun_MultiplyRC<D> >( a,b );
    }

  // complexscalar *  realvector 
  template <class D, class B> 
    inline ScalOpVec<std::complex<D>,VorE<D,B>,Fun_MultiplyCR<D> > 
    operator*(const std::complex<D> a, const VorE<D,B>& b)
    {
      return  
	ScalOpVec< std::complex<D>,VorE<D,B>,Fun_MultiplyCR<D> >( a, b );
    }
  // complexvector * realscalar
  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,Fun_MultiplyCR<D> > 
    operator*(const VorE<std::complex<D>,A>& a, const D b)
    {
      return  
	CVecOpScal<D,VorE<std::complex<D>,A>,Fun_MultiplyCR<D> >(a,b);  
    }
  // complexvector * intscalar
  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,Fun_MultiplyCR<D> > 
    operator*(const VorE<std::complex<D>,A>& a, const int b)
    {
      return  
	CVecOpScal<D,VorE<std::complex<D>,A>,Fun_MultiplyCR<D> >(a,static_cast<D>(b));  
    }
  // realscalar * complexvector
  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,Fun_MultiplyRC<D> > 
    operator*(const D a, const VorE<std::complex<D>,B>& b)
    {
      return  
	CScalOpVec<D,VorE<std::complex<D>,B>,Fun_MultiplyRC<D> >(a,b);  
    }
  // intscalar * complexvector
  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,Fun_MultiplyRC<D> > 
    operator*(const int a, const VorE<std::complex<D>,B>& b)
    {
      return  
	CScalOpVec<D,VorE<std::complex<D>,B>,Fun_MultiplyRC<D > >(static_cast<D>(a),b);  
    }


  // division

  // realvector / complexscalar
  template <class D, class A> 
    inline VecOpScal< std::complex<D>,VorE<D,A>,Fun_DivideRC<D> > 
    operator/(const VorE<D,A>& a, const std::complex<D> b)
    {
      return  
	VecOpScal< std::complex<D>,VorE<D,A>,Fun_DivideRC<D> >( a,b );
    }

  // complexscalar /  realvector 
  template <class D, class B> 
    inline ScalOpVec< std::complex<D>,VorE<D,B>,Fun_DivideCR<D> > 
    operator/(const std::complex<D> a, const VorE<D,B>& b)
    {
      return  
	ScalOpVec< std::complex<D>,VorE<D,B>,Fun_DivideCR<D> >( a, b );
    }
  // complexvector / realscalar
  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,Fun_DivideCR<D> > 
    operator/(const VorE<std::complex<D>,A>& a, const D b)
    {
      return  
	CVecOpScal<D,VorE<std::complex<D>,A>,Fun_DivideCR<D> >(a,b);  
    }
  // complexvector / intscalar
  template <class D, class A> 
    inline CVecOpScal<D,VorE<std::complex<D>,A>,Fun_DivideCR<D> > 
    operator/(const VorE<std::complex<D>,A>& a, const int b)
    {
      return  
	CVecOpScal<D,VorE<std::complex<D>,A>,Fun_DivideCR<D> >(a,static_cast<D>(b));  
    }
  // realscalar / complexvector
  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,Fun_DivideRC<D> > 
    operator/(const D a, const VorE<std::complex<D>,B>& b)
    {
      return  
	CScalOpVec<D,VorE<std::complex<D>,B>,Fun_DivideRC<D> >(a,b);  
    }
  // intscalar / complexvector
  template <class D, class B> 
    inline CScalOpVec<D,VorE<std::complex<D>,B>,Fun_DivideRC<D> > 
    operator/(const int a, const VorE<std::complex<D>,B>& b)
    {
      return  
	CScalOpVec<D,VorE<std::complex<D>,B>,Fun_DivideRC<D > >(static_cast<D>(a),b);  
    }



  
  // vector && scalar

  template <class A> 
    inline VecOpScal<bool,VorE<bool,A>,Fun_And > 
    operator&&(const VorE<bool,A>& a, const bool b)
    {
      return  VecOpScal<bool,VorE<bool,A>,Fun_And >(a,b);
    }

  // scalar && vector

  template <class B> 
    inline ScalOpVec<bool,VorE<bool,B>,Fun_And > 
    operator&&(const bool a, const VorE<bool,B>& b)
    {
      return  ScalOpVec<bool,VorE<bool,B>,Fun_And >(a,b);
    }

  
  // vector || scalar

  template <class A> 
    inline VecOpScal<bool,VorE<bool,A>,Fun_Or > 
    operator||(const VorE<bool,A>& a, const bool b)
    {
      return  VecOpScal<bool,VorE<bool,A>,Fun_Or >(a,b);
    }

  // scalar || vector

  template <class B> 
    inline ScalOpVec<bool,VorE<bool,B>,Fun_Or > 
    operator||(const bool a, const VorE<bool,B>& b)
    {
      return  ScalOpVec<bool,VorE<bool,B>,Fun_Or >(a,b);
    }



  // vector == scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,Fun_Equal<D> > 
    operator==(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,Fun_Equal<D> >(a,b);
    }

  // scalar == vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,Fun_Equal<D> > 
    operator==(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,Fun_Equal<D> >(a,b);
    }

  // vector != scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,Fun_NotEqual<D> > 
    operator!=(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,Fun_NotEqual<D> >(a,b);
    }

  // scalar != vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,Fun_NotEqual<D> > 
    operator!=(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,Fun_NotEqual<D> >(a,b);
    }
  // vector <= scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,Fun_LessOrEqual<D> > 
    operator<=(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,Fun_LessOrEqual<D> >(a,b);
    }

  // scalar <= vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,Fun_LessOrEqual<D> > 
    operator<=(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,Fun_LessOrEqual<D> >(a,b);
    }
  // vector >= scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,Fun_GreaterOrEqual<D> > 
    operator>=(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,Fun_GreaterOrEqual<D> >(a,b);
    }

  // scalar >= vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,Fun_GreaterOrEqual<D> > 
    operator>=(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,Fun_GreaterOrEqual<D> >(a,b);
    }
  // vector < scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,Fun_Less<D> > 
    operator<(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,Fun_Less<D> >(a,b);
    }

  // scalar < vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,Fun_Less<D> > 
    operator<(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,Fun_Less<D> >(a,b);
    }
  // vector > scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,Fun_Greater<D> > 
    operator>(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,Fun_Greater<D> >(a,b);
    }

  // scalar > vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,Fun_Greater<D> > 
    operator>(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,Fun_Greater<D> >(a,b);
    }



  // the following are defined for convenience

  // vector == int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,Fun_Equal<D> > 
    operator==(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,Fun_Equal<D> >(a,static_cast<D>(b));
    }

  // int scalar == vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,Fun_Equal<D> > 
    operator==(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,Fun_Equal<D> >(static_cast<D>(a),b);
    }

  // vector != int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,Fun_NotEqual<D> > 
    operator!=(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,Fun_NotEqual<D> >(a,static_cast<D>(b));
    }

  // int scalar != vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,Fun_NotEqual<D> > 
    operator!=(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,Fun_NotEqual<D> >(static_cast<D>(a),b);
    }
  // vector <= int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,Fun_LessOrEqual<D> > 
    operator<=(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,Fun_LessOrEqual<D> >(a,static_cast<D>(b));
    }

  // int scalar <= vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,Fun_LessOrEqual<D> > 
    operator<=(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,Fun_LessOrEqual<D> >(static_cast<D>(a),b);
    }
  // vector >= int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,Fun_GreaterOrEqual<D> > 
    operator>=(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,Fun_GreaterOrEqual<D> >(a,static_cast<D>(b));
    }

  // int scalar >= vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,Fun_GreaterOrEqual<D> > 
    operator>=(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,Fun_GreaterOrEqual<D> >(static_cast<D>(a),b);
    }
  // vector < int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,Fun_Less<D> > 
    operator<(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,Fun_Less<D> >(a,static_cast<D>(b));
    }

  // int scalar < vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,Fun_Less<D> > 
    operator<(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,Fun_Less<D> >(static_cast<D>(a),b);
    }
  // vector > int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,Fun_Greater<D> > 
    operator>(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,Fun_Greater<D> >(a,static_cast<D>(b));
    }

  // int scalar > vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,Fun_Greater<D> > 
    operator>(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,Fun_Greater<D> >(static_cast<D>(a),b);
    }

  // vector && vector

  template <class A, class B> 
    inline VBinOp<bool,VorE<bool,A>,VorE<bool,B>,Fun_And > 
    operator&&(const VorE<bool,A>& a, const VorE<bool,B>& b)
    {
      return  VBinOp<bool,VorE<bool,A>,VorE<bool,B>,Fun_And >(a,b);
    }

  // vector || vector

  template <class A, class B> 
    inline VBinOp<bool,VorE<bool,A>,VorE<bool,B>,Fun_Or > 
    operator||(const VorE<bool,A>& a, const VorE<bool,B>& b)
    {
      return  VBinOp<bool,VorE<bool,A>,VorE<bool,B>,Fun_Or >(a,b);
    }





  // !(vector)

  template <class A> 
    inline VFuncOp<bool,VorE<bool,A>,Fun_Not > 
    operator!(const VorE<bool,A>& a)
    {
      return  VFuncOp<bool,VorE<bool,A>,Fun_Not >(a);
    }
  
  


  



  
  template <class D, typename FunctionTypes<D>::binary_func F, class A, class B> 
    inline VBinOp<D, VorE<D,A>, VorE<D,B>, Fun_BinaryUser<D,F> > 
    op2(const VorE<D,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<D, VorE<D,A>, VorE<D,B>, Fun_BinaryUser<D,F> >(a,b);
    }


  // user-defined functions
  template <class D, typename FunctionTypes<D>::unary_func F, class A> 
    inline VFuncOp<D, VorE<D,A>, Fun_UnaryUser<D,F> > 
    op1(const VorE<D,A>& a)
    {
      return  VFuncOp<D, VorE<D,A>, Fun_UnaryUser<D,F> >(a);
    }





  // sqr(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Sqr<D> > 
    sqr(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Sqr<D> >(a);
    }

  // cube(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Cube<D> > 
    cube(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Cube<D> >(a);
    }

  // sqrt(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Sqrt<D> > 
    sqrt(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Sqrt<D> >(a);
    }

  // exp(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Exp<D> > 
    exp(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Exp<D> >(a);
    }



  // log(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Log<D> > 
    log(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Log<D> >(a);
    }


  // log10(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Log10<D> > 
    log10(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Log10<D> >(a);
    }


  // log2(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,Fun_Log2<D> > 
    log2(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,Fun_Log2<D> >(a);
    }








  // conj(complex vector)

  template <class D, class A> 
    inline VFuncOp<std::complex<D>,VorE<std::complex<D>,A>,Fun_Conj<D> > 
    conj(const VorE<std::complex<D>,A>& a)
    {
      return  VFuncOp<std::complex<D>,VorE<std::complex<D>,A>,Fun_Conj<D> >(a);
    }


  template <class D, class A> 
    inline VFuncOp<std::complex<D>,VorE<std::complex<D>,A>,Fun_Conj<D> > 
    operator~(const VorE<std::complex<D>,A>& a)
    {
      return  VFuncOp<std::complex<D>,VorE<std::complex<D>,A>,Fun_Conj<D> >(a);
    }


  
  // *** functions that return a real vector from a complex vector ***

  // abs(complex vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<std::complex<D>,A>,Fun_CAbs<D> > 
    abs(const VorE<std::complex<D>,A>& a)
    {
      return  VFuncOp<D,VorE<std::complex<D>,A>,Fun_CAbs<D> >(a);
    }


  // arg(complex vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<std::complex<D>,A>,Fun_Arg<D> > 
    arg(const VorE<std::complex<D>,A>& a)
    {
      return  VFuncOp<D,VorE<std::complex<D>,A>,Fun_Arg<D> >(a);
    }


  

  // real(complex vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<std::complex<D>,A>,Fun_Real<D> > 
    real(const VorE<std::complex<D>,A>& a)
    {
      return  VFuncOp<D,VorE<std::complex<D>,A>,Fun_Real<D> >(a);
    }

  // imag(complex vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<std::complex<D>,A>,Fun_Imag<D> > 
    imag(const VorE<std::complex<D>,A>& a)
    {
      return  VFuncOp<D,VorE<std::complex<D>,A>,Fun_Imag<D> >(a);
    }


  
  // round(complex vector)

  template <class D, class A> 
    inline VFuncOp<std::complex<D>, VorE<std::complex<D>, A> , Fun_RoundCplx<D> > 
    round(const VorE<std::complex<D>,A>& a)  {
    return VFuncOp<std::complex<D>, VorE<std::complex<D>, A>, Fun_RoundCplx<D> >(a);
  }



  


  /****************************************************************************
   * Binary Functions/Operators that return scalars
   ****************************************************************************
   */






  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */

  // sum(a)

  template <class D, class A> 
    D sum( const VorE<D,A>& a ) {
    
 
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
    D prod( const VorE<D,A>& a ) {
    
 
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
    D norm( const VorE<D,A>& a ) {
    
 
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
    D min( const VorE<D,A>& a ) {
    
 
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
    D max( const VorE<D,A>& a ) {
    
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
    inline D norm( const VorE<std::complex<D>,A>& a ) {
    D result = D();
    
 
    for (register index_type i = a.size(); i--;) {
      D tempR = a[i].real(); 
      D tempI = a[i].imag(); 
      result += tempR*tempR + tempI*tempI;
    }
    return std::sqrt(result);
  }





  /****************************************************************************
   * Unary Functions/Operators that bools or index_type vectors
   ****************************************************************************
   */


  
  // alltrue(a)

  template <class A> 
    inline bool alltrue( const VorE<bool,A>& a ) {
    bool result = true;
    
 
    for (register index_type i = 0; i< a.size(); i++)
      result = result && a[i];
    
    return result;
  }


  // anytrue(a)

  template <class A> 
    inline bool anytrue( const VorE<bool,A>& a ) {
    bool result = false;
    
 
    for (register index_type i = 0; i< a.size(); i++)
      result = result || a[i];
    
    return result;
  }


  // numtrue(a)

  template <class A> 
    inline size_type numtrue( const VorE<bool,A>& a ) {
    size_type result = 0;
    
 
    for (register index_type i = 0; i< a.size(); i++)
      result += static_cast<index_type>(a[i]);
    
    return result;
  }


  


  // findtrue(a)

  template <class A> 
    inline Vector<index_type> findtrue( const VorE<bool,A>& a ) {
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







};

#endif 
