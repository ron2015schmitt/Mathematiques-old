
#ifndef VCOMPLEXOPS_H
#define VCOMPLEXOPS_H


#include <complex>


namespace matricks {




  /************************************************************
   *               Templates for Binary Operators
   *
   * D = data type, e.g. double
   * A = either an Vector or a Vexpr
   * B = either an Vector or a Vexpr
   ************************************************************
   */

  // complexvector + realvector
  template <class D, class A, class B> 
  inline VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,ApAddCR<D> > 
  operator+(const VorE<std::complex<D>,A>& a, const VorE<D,B>& b)
  {
    return  VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,ApAddCR<D> >(a,b);
  }
  // realvector + complexvector 
  template <class D, class A, class B> 
  inline VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,ApAddRC<D> > 
  operator+(const VorE<D,A>& a, const VorE<std::complex<D>,B>& b)
  {
    return  VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,ApAddRC<D> >(a,b);
  }


  // complexvector - realvector
  template <class D, class A, class B> 
  inline VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,ApSubtractCR<D> > 
  operator-(const VorE<std::complex<D>,A>& a, const VorE<D,B>& b)
  {
    return  VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,ApSubtractCR<D> >(a,b);
  }
  // realvector - complexvector 
  template <class D, class A, class B> 
  inline VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,ApSubtractRC<D> > 
  operator-(const VorE<D,A>& a, const VorE<std::complex<D>,B>& b)
  {
    return  VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,ApSubtractRC<D> >(a,b);
  }



  // complexvector * realvector
  template <class D, class A, class B> 
  inline VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,ApMultiplyCR<D> > 
  operator*(const VorE<std::complex<D>,A>& a, const VorE<D,B>& b)
  {
    return  VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,ApMultiplyCR<D> >(a,b);
  }
  // realvector * complexvector 
  template <class D, class A, class B> 
  inline VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,ApMultiplyRC<D> > 
  operator*(const VorE<D,A>& a, const VorE<std::complex<D>,B>& b)
  {
    return  VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,ApMultiplyRC<D> >(a,b);
  }



  // complexvector / realvector
  template <class D, class A, class B> 
  inline VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,ApDivideCR<D> > 
  operator/(const VorE<std::complex<D>,A>& a, const VorE<D,B>& b)
  {
    return  VBinOp<std::complex<D>,VorE<std::complex<D>,A>,VorE<D,B>,ApDivideCR<D> >(a,b);
  }
  // realvector / complexvector 
  template <class D, class A, class B> 
  inline VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,ApDivideRC<D> > 
  operator/(const VorE<D,A>& a, const VorE<std::complex<D>,B>& b)
  {
    return  VBinOp<std::complex<D>,VorE<D,A>,VorE<std::complex<D>,B>,ApDivideRC<D> >(a,b);
  }




  // *** functions that return a complex vector from 2 real vectors ***

  // vpolar(r,phi)

  template <class D, class A, class B> 
  inline VBinOp<std::complex<D>,VorE<D,A>,VorE<D,B>,ApPolar<D> > 
  vpolar(const VorE<D,A>& r, const VorE<D,B>& phi)
  {
    return  VBinOp<std::complex<D>,VorE<D,A>,VorE<D,B>,ApPolar<D> >(r,phi);
  }


  // vcomplex(x,y)

  template <class D, class A, class B> 
  inline VBinOp<std::complex<D>,VorE<D,A>,VorE<D,B>,ApComplex<D> > 
  vcomplex(const VorE<D,A>& x, const VorE<D,B>& y)
  {
    return  VBinOp<std::complex<D>,VorE<D,A>,VorE<D,B>,ApComplex<D> >(x,y);
  }




  /************************************************************
   *               Templates for vector/scalar Operators
   *
   * D = data type, e.g. double (vector and scalar must be of same data type)
   * A = either an Vector or a Vexpr
   ************************************************************
   */


  // pow(complexvector,realscalar)

  template <class D, class A> 
  inline CVecOpScal<D,VorE<std::complex<D>,A>,ApPowCR<D> > 
  pow(const VorE<std::complex<D>,A>& a, const D b)
  {
    return  CVecOpScal<D,VorE<std::complex<D>,A>,ApPowCR<D> >(a,b);
  }

  template <class D, class A> 
  inline CVecOpScal<D,VorE<std::complex<D>,A>, ApRoundZeros<std::complex<D> > > 
  roundzero(const VorE<std::complex<D>,A>& a, const D tol = MatricksHelper<D>::tolerance)
  {
    return  CVecOpScal<D,VorE<std::complex<D>,A>, ApRoundZeros<std::complex<D> > >(a,tol);
  }


  // pow(complexvector,intscalar)

  template <class D, class A> 
  inline CVecOpScal<D,VorE<std::complex<D>,A>,ApPowCR<D> > 
  pow(const VorE<std::complex<D>,A>& a, const int b)
  {
    return  CVecOpScal<D,VorE<std::complex<D>,A>,ApPowCR<D> >(a,static_cast<D>(b));
  }

  // pow(realscalar,complexvector)

  template <class D, class B> 
  inline CScalOpVec<D,VorE<std::complex<D>,B>,ApPowRC<D> > 
  pow(const D a, const VorE<std::complex<D>,B>& b)
  {
    return  CScalOpVec<D,VorE<std::complex<D>,B>,ApPowRC<D> >(a,b);
  }

  // pow(intscalar,complexvector)

  template <class D, class B> 
  inline CScalOpVec<D,VorE<std::complex<D>,B>,ApPowRC<D> > 
  pow(const int a, const VorE<std::complex<D>,B>& b)
  {
    return  CScalOpVec<D,VorE<std::complex<D>,B>,ApPowRC<D> >(static_cast<D>(a),b);
  }


 
  
  // vcomplex(vector,realscalar)

  
  template <class D, class A, class B> 
  inline VecOpScal<std::complex<D>, VorE<D,A>, ApComplex<D> > 
  vcomplex(const VorE<D,A>& a, const D b)
  {
    return  CVecOpScal<D,VorE<D,A>,ApComplex<D > >(a,b);
  }
  // vcomplex(vector,intscalar)

  template <class D, class A> 
  inline CVecOpScal<D,VorE<D,A>,ApComplex<D > > 
  vcomplex(const VorE<D,A>& a, const int b)
  {
    return  CVecOpScal<D,VorE<D,A>,ApComplex<D > >(a,static_cast<D>(b));
  }

  // vcomplex(realscalar,vector)

  template <class D, class B> 
  inline CScalOpVec<D,VorE<D,B>,ApComplex<D > > 
  vcomplex(const D a, const VorE<D,B>& b)
  {
    return  CScalOpVec<D,VorE<D,B>,ApComplex<D > >(a,b);
  }
  // vcomplex(intscalar,vector)

  template <class D, class B> 
  inline CScalOpVec<D,VorE<D,B>,ApComplex<D > > 
  vcomplex(const int a, const VorE<D,B>& b)
  {
    return  CScalOpVec<D,VorE<D,B>,ApComplex<D > >(static_cast<D>(a),b);
  }



  



  /************************************************************
   *               Templates for vector/scalar Operators
   *
   * D = data type, e.g. double (vector and scalar must be of same data type)
   * A = either an Vector or a Vexpr
   ************************************************************
   */

  

  // realvector + complexscalar
  template <class D, class A> 
  inline VecOpScal< std::complex<D>,VorE<D,A>,ApAddRC<D> > 
  operator+(const VorE<D,A>& a, const std::complex<D> b)
  {
    return  
      VecOpScal< std::complex<D>,VorE<D,A>,ApAddRC<D> >( a,b );
  }

  // complexscalar +  realvector 
  template <class D, class B> 
  inline ScalOpVec< std::complex<D>,VorE<D,B>,ApAddCR<D> > 
  operator+(const std::complex<D> a, const VorE<D,B>& b)
  {
    return  
      ScalOpVec< std::complex<D>,VorE<D,B>,ApAddCR<D> >( a, b );
  }
  // complexvector + realscalar
  template <class D, class A> 
  inline CVecOpScal<D,VorE<std::complex<D>,A>,ApAddCR<D> > 
  operator+(const VorE<std::complex<D>,A>& a, const D b)
  {
    return  
      CVecOpScal<D,VorE<std::complex<D>,A>,ApAddCR<D> >(a,b);  
  }
  // complexvector + intscalar
  template <class D, class A> 
  inline CVecOpScal<D,VorE<std::complex<D>,A>,ApAddCR<D> > 
  operator+(const VorE<std::complex<D>,A>& a, const int b)
  {
    return  
      CVecOpScal<D,VorE<std::complex<D>,A>,ApAddCR<D> >(a,static_cast<D>(b));  
  }
  // realscalar + complexvector
  template <class D, class B> 
  inline CScalOpVec<D,VorE<std::complex<D>,B>,ApAddRC<D> > 
  operator+(const D a, const VorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpVec<D,VorE<std::complex<D>,B>,ApAddRC<D> >(a,b);  
  }
  // intscalar + complexvector
  template <class D, class B> 
  inline CScalOpVec<D,VorE<std::complex<D>,B>,ApAddRC<D> > 
  operator+(const int a, const VorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpVec<D,VorE<std::complex<D>,B>,ApAddRC<D > >(static_cast<D>(a),b);  
  }



  // realvector - complexscalar
  template <class D, class A> 
  inline VecOpScal< std::complex<D>,VorE<D,A>,ApSubtractRC<D> > 
  operator-(const VorE<D,A>& a, const std::complex<D> b)
  {
    return  
      VecOpScal< std::complex<D>,VorE<D,A>,ApSubtractRC<D> >( a,b );
  }

  // complexscalar -  realvector 
  template <class D, class B> 
  inline ScalOpVec< std::complex<D>,VorE<D,B>,ApSubtractCR<D> > 
  operator-(const std::complex<D> a, const VorE<D,B>& b)
  {
    return  
      ScalOpVec< std::complex<D>,VorE<D,B>,ApSubtractCR<D> >( a, b );
  }
  // complexvector - realscalar
  template <class D, class A> 
  inline CVecOpScal<D,VorE<std::complex<D>,A>,ApSubtractCR<D> > 
  operator-(const VorE<std::complex<D>,A>& a, const D b)
  {
    return  
      CVecOpScal<D,VorE<std::complex<D>,A>,ApSubtractCR<D> >(a,b);  
  }
  // complexvector - intscalar
  template <class D, class A> 
  inline CVecOpScal<D,VorE<std::complex<D>,A>,ApSubtractCR<D> > 
  operator-(const VorE<std::complex<D>,A>& a, const int b)
  {
    return  
      CVecOpScal<D,VorE<std::complex<D>,A>,ApSubtractCR<D> >(a,static_cast<D>(b));  
  }
  // realscalar - complexvector
  template <class D, class B> 
  inline CScalOpVec<D,VorE<std::complex<D>,B>,ApSubtractRC<D> > 
  operator-(const D a, const VorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpVec<D,VorE<std::complex<D>,B>,ApSubtractRC<D> >(a,b);  
  }
  // intscalar - complexvector
  template <class D, class B> 
  inline CScalOpVec<D,VorE<std::complex<D>,B>,ApSubtractRC<D> > 
  operator-(const int a, const VorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpVec<D,VorE<std::complex<D>,B>,ApSubtractRC<D > >(static_cast<D>(a),b);  
  }


  // realvector * complexscalar
  template <class D, class A> 
  inline VecOpScal< std::complex<D>,VorE<D,A>,ApMultiplyRC<D> > 
  operator*(const VorE<D,A>& a, const std::complex<D> b)
  {
    return  
      VecOpScal< std::complex<D>,VorE<D,A>,ApMultiplyRC<D> >( a,b );
  }

  // complexscalar *  realvector 
  template <class D, class B> 
  inline ScalOpVec<std::complex<D>,VorE<D,B>,ApMultiplyCR<D> > 
  operator*(const std::complex<D> a, const VorE<D,B>& b)
  {
    return  
      ScalOpVec< std::complex<D>,VorE<D,B>,ApMultiplyCR<D> >( a, b );
  }
  // complexvector * realscalar
  template <class D, class A> 
  inline CVecOpScal<D,VorE<std::complex<D>,A>,ApMultiplyCR<D> > 
  operator*(const VorE<std::complex<D>,A>& a, const D b)
  {
    return  
      CVecOpScal<D,VorE<std::complex<D>,A>,ApMultiplyCR<D> >(a,b);  
  }
  // complexvector * intscalar
  template <class D, class A> 
  inline CVecOpScal<D,VorE<std::complex<D>,A>,ApMultiplyCR<D> > 
  operator*(const VorE<std::complex<D>,A>& a, const int b)
  {
    return  
      CVecOpScal<D,VorE<std::complex<D>,A>,ApMultiplyCR<D> >(a,static_cast<D>(b));  
  }
  // realscalar * complexvector
  template <class D, class B> 
  inline CScalOpVec<D,VorE<std::complex<D>,B>,ApMultiplyRC<D> > 
  operator*(const D a, const VorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpVec<D,VorE<std::complex<D>,B>,ApMultiplyRC<D> >(a,b);  
  }
  // intscalar * complexvector
  template <class D, class B> 
  inline CScalOpVec<D,VorE<std::complex<D>,B>,ApMultiplyRC<D> > 
  operator*(const int a, const VorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpVec<D,VorE<std::complex<D>,B>,ApMultiplyRC<D > >(static_cast<D>(a),b);  
  }


  // division

  // realvector / complexscalar
  template <class D, class A> 
  inline VecOpScal< std::complex<D>,VorE<D,A>,ApDivideRC<D> > 
  operator/(const VorE<D,A>& a, const std::complex<D> b)
  {
    return  
      VecOpScal< std::complex<D>,VorE<D,A>,ApDivideRC<D> >( a,b );
  }

  // complexscalar /  realvector 
  template <class D, class B> 
  inline ScalOpVec< std::complex<D>,VorE<D,B>,ApDivideCR<D> > 
  operator/(const std::complex<D> a, const VorE<D,B>& b)
  {
    return  
      ScalOpVec< std::complex<D>,VorE<D,B>,ApDivideCR<D> >( a, b );
  }
  // complexvector / realscalar
  template <class D, class A> 
  inline CVecOpScal<D,VorE<std::complex<D>,A>,ApDivideCR<D> > 
  operator/(const VorE<std::complex<D>,A>& a, const D b)
  {
    return  
      CVecOpScal<D,VorE<std::complex<D>,A>,ApDivideCR<D> >(a,b);  
  }
  // complexvector / intscalar
  template <class D, class A> 
  inline CVecOpScal<D,VorE<std::complex<D>,A>,ApDivideCR<D> > 
  operator/(const VorE<std::complex<D>,A>& a, const int b)
  {
    return  
      CVecOpScal<D,VorE<std::complex<D>,A>,ApDivideCR<D> >(a,static_cast<D>(b));  
  }
  // realscalar / complexvector
  template <class D, class B> 
  inline CScalOpVec<D,VorE<std::complex<D>,B>,ApDivideRC<D> > 
  operator/(const D a, const VorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpVec<D,VorE<std::complex<D>,B>,ApDivideRC<D> >(a,b);  
  }
  // intscalar / complexvector
  template <class D, class B> 
  inline CScalOpVec<D,VorE<std::complex<D>,B>,ApDivideRC<D> > 
  operator/(const int a, const VorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpVec<D,VorE<std::complex<D>,B>,ApDivideRC<D > >(static_cast<D>(a),b);  
  }









  /****************************************************************
   *               Templates for Unary Operators & Unary Functions
   *
   * D = data type, e.g. double 
   * A = either an Vector or a Vexpr
   *****************************************************************
   */

  // *** functions that return a complex vector from a complex vector ***

  // conj(complex vector)

  template <class D, class A> 
  inline VFuncOp<std::complex<D>,VorE<std::complex<D>,A>,ApConj<D> > 
  conj(const VorE<std::complex<D>,A>& a)
  {
    return  VFuncOp<std::complex<D>,VorE<std::complex<D>,A>,ApConj<D> >(a);
  }


  template <class D, class A> 
  inline VFuncOp<std::complex<D>,VorE<std::complex<D>,A>,ApConj<D> > 
  operator~(const VorE<std::complex<D>,A>& a)
  {
    return  VFuncOp<std::complex<D>,VorE<std::complex<D>,A>,ApConj<D> >(a);
  }


  
  // *** functions that return a real vector from a complex vector ***

  // abs(complex vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<std::complex<D>,A>,ApCAbs<D> > 
  abs(const VorE<std::complex<D>,A>& a)
  {
    return  VFuncOp<D,VorE<std::complex<D>,A>,ApCAbs<D> >(a);
  }


  // arg(complex vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<std::complex<D>,A>,ApArg<D> > 
  arg(const VorE<std::complex<D>,A>& a)
  {
    return  VFuncOp<D,VorE<std::complex<D>,A>,ApArg<D> >(a);
  }


  

  // real(complex vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<std::complex<D>,A>,ApReal<D> > 
  real(const VorE<std::complex<D>,A>& a)
  {
    return  VFuncOp<D,VorE<std::complex<D>,A>,ApReal<D> >(a);
  }

  // imag(complex vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<std::complex<D>,A>,ApImag<D> > 
  imag(const VorE<std::complex<D>,A>& a)
  {
    return  VFuncOp<D,VorE<std::complex<D>,A>,ApImag<D> >(a);
  }


  
  // round(complex vector)

  template <class D, class A> 
  inline VFuncOp<std::complex<D>, VorE<std::complex<D>, A>, ApRoundCplx<D> > 
  round(const VorE<std::complex<D>,A>& a)  {
    return VFuncOp<std::complex<D>, VorE<std::complex<D>, A>, ApRoundCplx<D> >(a);
  }


  /****************************************************************************
   * Binary Functions/Operators that return scalars
   ****************************************************************************
   */


  // dotproduct operator (areal|bcomplex)

  template <class D, class A, class B> 
  inline std::complex<D>  operator|( const VorE<D,A>& a, const  VorE<std::complex<D>,B>& b ) {
    std::complex<D> result = std::complex<D>();
    
#ifdef MATRICKS_DEBUG
    if (  vexpr_is_size_bad(a) || vexpr_is_size_bad(b) || ( a.size() != b.size() ) ){ 
      vbad_expr_in_binary(a,b,"","|");
      return 0;
    }
#endif
 
    for (register size_type i = a.size(); i--;)
      result += a[i]*b[i];
    
    return result;
  }


  // dotproduct operator (acomplex|breal)

  template <class D, class A, class B> 
  inline std::complex<D>  operator|( const VorE<std::complex<D>,A>& a, const  VorE<D,B>& b ) {
    std::complex<D> result = std::complex<D>();
    
#ifdef MATRICKS_DEBUG
    if (  vexpr_is_size_bad(a) || vexpr_is_size_bad(b) || ( a.size() != b.size() ) ){ 
      vbad_expr_in_binary(a,b,"","|");
      return 0;
    }
#endif
 
    for (register size_type i = a.size(); i--;)
      result += a[i]*b[i];
    
    return result;
  }




  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */




  // norm(a)

  template <class D, class A> 
  inline D norm( const VorE<std::complex<D>,A>& a ) {
    D result = D();
    
#ifdef MATRICKS_DEBUG
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"norm");
      return 0;
    }
#endif
 
    for (register size_type i = a.size(); i--;) {
      D tempR = a[i].real(); 
      D tempI = a[i].imag(); 
      result += tempR*tempR + tempI*tempI;
    }
    return std::sqrt(result);
  }






};

#endif 
