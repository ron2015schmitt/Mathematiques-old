#ifndef FUNCTIONS_COMPLEX__H
#define FUNCTIONS_COMPLEX__H 1


namespace matricks {

  /****************************************************************************
   *  products: Scalar Scalar
   ****************************************************************************
   */

  // --------------------  dot (inner) product --------------------------------
  
  // (real|complex)

  template <class D> inline
    std::complex<D>  operator|( const Scalar<D>& a, const  Scalar<std::complex<D> >& b ) {
    return a()*b();
  }

  // dot(real, complex)
  
  template <class D> inline
    std::complex<D> dot( const Scalar<D>& a, const  Scalar<std::complex<D> >& b ) {
    return (a|b);
  }


  // (complex|real)

  template <class D> inline
    std::complex<D> operator|( const Scalar<std::complex<D>>& a, const  Scalar<D>& b ) {
    return a()*b();
  }

  // dot(complex, real)

  template <class D> inline
    std::complex<D> dot( const Scalar<std::complex<D>>& a, const  Scalar<D>& b ) {
    return (a|b);
  }


  // --------------------  tensor (outer) product --------------------------------
  

  // (real&complex)

  template <class D> inline
    std::complex<D> operator&( const Scalar<D>& a, const  Scalar<std::complex<D> >& b ) {
    return a()*b();
  }

  // tprod(real, complex)
  
  template <class D> inline
    std::complex<D> tprod( const Scalar<D>& a, const  Scalar<std::complex<D> >& b ) {
    return (a&b);
  }

  // (complex&real)

  template <class D> inline
    std::complex<D> operator&( const Scalar<std::complex<D>>& a, const  Scalar<D>& b ) {
    return 0;
  }

  // tprod(complex, real)

  template <class D> inline
    std::complex<D> tprod( const Scalar<std::complex<D> >& a, const  Scalar<D>& b ) {
    return (a&b);
  }


  // -------------------- antisymmetric (wedge)  product -----------------------
  
  // (real^complex)

  template <class D> inline
    std::complex<D> operator^( const Scalar<D>& a, const  Scalar<std::complex<D> >& b ) {
    return 0;
  }

  // wprod(real, complex)
  
  template <class D> inline
    std::complex<D> wprod( const Scalar<D>& a, const  Scalar<std::complex<D> >& b ) {
    return (a^b);
  }

  // (complex^real)

  template <class D> inline
    std::complex<D> operator^( const Scalar<std::complex<D>>& a, const  Scalar<D>& b ) {
    return 0;
  }

  // wprod(complex, real)

  template <class D> inline
    std::complex<D> wprod( const Scalar<std::complex<D> >& a, const  Scalar<D>& b ) {
    return (a^b);
  }


  
  /****************************************************************************
   *  products: Vector Vector
   ****************************************************************************
   */


  // --------------------  dot (inner) product --------------------------------

  // (areal|bcomplex)

  template <class D> inline
    std::complex<D> operator|( const Vector<D>& a, const  Vector<std::complex<D> >& b ) {

    std::complex<D> result = std::complex<D>(0,0);
    for (register index_type i = a.size(); i--;) {
      result += a[i]*b[i];
    }
    return result;
  }

  // dot(areal,bcomplex)

  template <class D> inline
    std::complex<D> dot( const Vector<D>& a, const  Vector<std::complex<D> >& b ) {
    return (a|b);
  }


  // (acomplex|breal)

  template <class D> inline
    std::complex<D> operator|( const Vector<std::complex<D> >& a, const  Vector<D>& b ) {

    std::complex<D> result = std::complex<D>(0,0);
    for (register index_type i = a.size(); i--;) {
      result += a[i]*b[i];
    }
    return result;
  }

  // dot(acomplex,breal)

  template <class D> inline
    std::complex<D> dot( const Vector<std::complex<D> >& a, const  Vector<D>& b ) {
    return (a|b);
  }

  // --------------------  tensor (outer) product --------------------------------

  // -------------------- antisymmetric (wedge)  product -----------------------

  /****************************************************************************
   *  product: Matrix Matrix
   ****************************************************************************
   */

  // --------------------  dot (inner) product --------------------------------
  // --------------------  tensor (outer) product --------------------------------

  // -------------------- antisymmetric (wedge)  product -----------------------

  
  /****************************************************************************
   *  product: Matrix Vector
   ****************************************************************************
   */
  // --------------------  dot (inner) product --------------------------------
  // --------------------  tensor (outer) product --------------------------------

  // -------------------- antisymmetric (wedge)  product -----------------------


  /****************************************************************************
   *  product: TensorR TensorR
   ****************************************************************************
   */
  // --------------------  dot (inner) product --------------------------------


  // (real a|complex b)

  template <class D, class A, class B> inline
    D operator|( const TensorR<D,A>& a, const  TensorR<std::complex<D>,B>& b ) {

    // (Scalar|Scalar)
    if ((a.ndims() == 0) && (b.ndims() == 0)) {
      return a[0]*b[0];
    }

    // (Vector|Vector)
    if ((a.ndims() == 1) && (b.ndims() == 1)) {
      D result = D(0);
      for (register index_type i = a.size(); i--;) {
	result += a[i]*b[i];
      }
      return result;
    }
  }

  // dot(real a,complex b)

  template <class D, class A, class B> inline
    D dot( const TensorR<D,A>& a, const  TensorR<std::complex<D>,B>& b ) {
    return (a|b);
  }


  // (complex a|real b)

  template <class D, class A, class B> inline
    D operator|( const TensorR<std::complex<D>,A>& a, const  TensorR<D,B>& b ) {

    // (Scalar|Scalar)
    if ((a.ndims() == 0) && (b.ndims() == 0)) {
      return a[0]*b[0];
    }

    // (Vector|Vector)
    if ((a.ndims() == 1) && (b.ndims() == 1)) {
      D result = D(0);
      for (register index_type i = a.size(); i--;) {
	result += a[i]*b[i];
      }
      return result;
    }
  }

  // dot(complex a,real b)

  template <class D, class A, class B> inline
    D dot( const TensorR<std::complex<D>,A>& a, const  TensorR<D,B>& b ) {
    return (a|b);
  }

  
  // --------------------  tensor (outer) product --------------------------------

  // (real & complex)

  template <class D, class A, class B> inline
    D operator&( const TensorR<D,A>& a, const  TensorR<std::complex<D>,B>& b ) {

    // (Scalar & Scalar)
    if ((a.ndims() == 0) && (b.ndims() == 0)) {
      return a[0]*b[0];
    }

  }

  // tprod(real,complex)

  template <class D, class A, class B> inline
    D tprod( const TensorR<D,A>& a, const  TensorR<std::complex<D>,B>& b ) {
    return (a&b);
  }


  // (complex & real)

  template <class D, class A, class B> inline
    D operator&( const TensorR<std::complex<D>,A>& a, const  TensorR<D,B>& b ) {

    // (Scalar & Scalar)
    if ((a.ndims() == 0) && (b.ndims() == 0)) {
      return a[0]*b[0];
    }

  }

  // tprod(complex, real)

  template <class D, class A, class B> inline
    D tprod( const TensorR<std::complex<D>,A>& a, const  TensorR<D,B>& b ) {
    return (a&b);
  }

  // -------------------- antisymmetric (wedge)  product -----------------------
  //  a ^ b = a & b - b & a
  // --------------------------------------------------------------------------
  
  // (real ^ complex)

  template <class D, class A, class B> inline
    D operator^( const TensorR<D,A>& a, const  TensorR<std::complex<D>,B>& b ) {

    // (Scalar ^ Scalar)
    if ((a.ndims() == 0) && (b.ndims() == 0)) {
      return 0;
    }

  }

  // wprod(real,complex)

  template <class D, class A, class B> inline
    D wprod( const TensorR<D,A>& a, const  TensorR<std::complex<D>,B>& b ) {
    return (a^b);
  }


  // (complex ^ real)

  template <class D, class A, class B> inline
    D operator^( const TensorR<std::complex<D>,A>& a, const  TensorR<D,B>& b ) {

    // (Scalar ^ Scalar)
    if ((a.ndims() == 0) && (b.ndims() == 0)) {
      return 0;
    }

  }

  // wprod(complex, real)

  template <class D, class A, class B> inline
    D wprod( const TensorR<std::complex<D>,A>& a, const  TensorR<D,B>& b ) {
    return (a^b);
  }





  // ************************************************************************
  // *            Bit wise operators for COMPLEX unsigned types
  // ************************************************************************


  // bitwise not (aka 1's complement): ~
  // NOTE: "~" is also used for Hermitian adjoint
  template <class A> 
    inline TER_Unary<ComplexUnsignedChar, TensorR<ComplexUnsignedChar,A> ,Fun_BitwiseNot<ComplexUnsignedChar > >
    operator~( const TensorR<ComplexUnsignedChar,A>& a ) {
    return
      TER_Unary<ComplexUnsignedChar, TensorR<ComplexUnsignedChar,A> ,Fun_BitwiseNot<ComplexUnsignedChar > >(a);
  }
  template <class A> 
    inline TER_Unary<ComplexUnsignedShort, TensorR<ComplexUnsignedShort,A> ,Fun_BitwiseNot<ComplexUnsignedShort > >
    operator~( const TensorR<ComplexUnsignedShort,A>& a ) {
    return
      TER_Unary<ComplexUnsignedShort, TensorR<ComplexUnsignedShort,A> ,Fun_BitwiseNot<ComplexUnsignedShort > >(a);
  }
  template <class A> 
    inline TER_Unary<ComplexUnsignedInt, TensorR<ComplexUnsignedInt,A> ,Fun_BitwiseNot<ComplexUnsignedInt > >
    operator~( const TensorR<ComplexUnsignedInt,A>& a ) {
    return
      TER_Unary<ComplexUnsignedInt, TensorR<ComplexUnsignedInt,A> ,Fun_BitwiseNot<ComplexUnsignedInt > >(a);
  }
  template <class A> 
    inline TER_Unary<ComplexUnsignedLong, TensorR<ComplexUnsignedLong,A> ,Fun_BitwiseNot<ComplexUnsignedLong > >
    operator~( const TensorR<ComplexUnsignedLong,A>& a ) {
    return
      TER_Unary<ComplexUnsignedLong, TensorR<ComplexUnsignedLong,A> ,Fun_BitwiseNot<ComplexUnsignedLong > >(a);
  }
  template <class A> 
    inline TER_Unary<ComplexUnsignedLongLong, TensorR<ComplexUnsignedLongLong,A> ,Fun_BitwiseNot<ComplexUnsignedLongLong > >
    operator~( const TensorR<ComplexUnsignedLongLong,A>& a ) {
    return
      TER_Unary<ComplexUnsignedLongLong, TensorR<ComplexUnsignedLongLong,A> ,Fun_BitwiseNot<ComplexUnsignedLongLong > >(a);
  }

  
  // Bitwise Or: |
  // NOTE: that "|" is also used for dot product short hand 

  template <class A, class B> 
    inline TER_Binary<ComplexUnsignedChar,TensorR<ComplexUnsignedChar,A>,TensorR<ComplexUnsignedChar,B>,Fun_BitwiseOr<ComplexUnsignedChar > >
    operator|( const TensorR<ComplexUnsignedChar,A>& a, const  TensorR<ComplexUnsignedChar,B>& b ) {
    return TER_Binary<ComplexUnsignedChar,TensorR<ComplexUnsignedChar,A>,TensorR<ComplexUnsignedChar,B>,Fun_BitwiseOr<ComplexUnsignedChar > >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<ComplexUnsignedShort,TensorR<ComplexUnsignedShort,A>,TensorR<ComplexUnsignedShort,B>,Fun_BitwiseOr<ComplexUnsignedShort > >
    operator|( const TensorR<ComplexUnsignedShort,A>& a, const  TensorR<ComplexUnsignedShort,B>& b ) {
    return TER_Binary<ComplexUnsignedShort,TensorR<ComplexUnsignedShort,A>,TensorR<ComplexUnsignedShort,B>,Fun_BitwiseOr<ComplexUnsignedShort > >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<ComplexUnsignedInt,TensorR<ComplexUnsignedInt,A>,TensorR<ComplexUnsignedInt,B>,Fun_BitwiseOr<ComplexUnsignedInt > >
    operator|( const TensorR<ComplexUnsignedInt,A>& a, const  TensorR<ComplexUnsignedInt,B>& b ) {
    return TER_Binary<ComplexUnsignedInt,TensorR<ComplexUnsignedInt,A>,TensorR<ComplexUnsignedInt,B>,Fun_BitwiseOr<ComplexUnsignedInt > >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<ComplexUnsignedLong,TensorR<ComplexUnsignedLong,A>,TensorR<ComplexUnsignedLong,B>,Fun_BitwiseOr<ComplexUnsignedLong > >
    operator|( const TensorR<ComplexUnsignedLong,A>& a, const  TensorR<ComplexUnsignedLong,B>& b ) {
    return TER_Binary<ComplexUnsignedLong,TensorR<ComplexUnsignedLong,A>,TensorR<ComplexUnsignedLong,B>,Fun_BitwiseOr<ComplexUnsignedLong > >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<ComplexUnsignedLongLong,TensorR<ComplexUnsignedLongLong,A>,TensorR<ComplexUnsignedLongLong,B>,Fun_BitwiseOr<ComplexUnsignedLongLong > >
    operator|( const TensorR<ComplexUnsignedLongLong,A>& a, const  TensorR<ComplexUnsignedLongLong,B>& b ) {
    return TER_Binary<ComplexUnsignedLongLong,TensorR<ComplexUnsignedLongLong,A>,TensorR<ComplexUnsignedLongLong,B>,Fun_BitwiseOr<ComplexUnsignedLongLong > >(a,b);
  }

  // Bitwise And: &

  template <class A, class B> 
    inline TER_Binary<ComplexUnsignedChar,TensorR<ComplexUnsignedChar,A>,TensorR<ComplexUnsignedChar,B>,Fun_BitwiseAnd<ComplexUnsignedChar > >
    operator&( const TensorR<ComplexUnsignedChar,A>& a, const  TensorR<ComplexUnsignedChar,B>& b ) {
    return TER_Binary<ComplexUnsignedChar,TensorR<ComplexUnsignedChar,A>,TensorR<ComplexUnsignedChar,B>,Fun_BitwiseAnd<ComplexUnsignedChar > >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<ComplexUnsignedShort,TensorR<ComplexUnsignedShort,A>,TensorR<ComplexUnsignedShort,B>,Fun_BitwiseAnd<ComplexUnsignedShort > >
    operator&( const TensorR<ComplexUnsignedShort,A>& a, const  TensorR<ComplexUnsignedShort,B>& b ) {
    return TER_Binary<ComplexUnsignedShort,TensorR<ComplexUnsignedShort,A>,TensorR<ComplexUnsignedShort,B>,Fun_BitwiseAnd<ComplexUnsignedShort > >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<ComplexUnsignedInt,TensorR<ComplexUnsignedInt,A>,TensorR<ComplexUnsignedInt,B>,Fun_BitwiseAnd<ComplexUnsignedInt > >
    operator&( const TensorR<ComplexUnsignedInt,A>& a, const  TensorR<ComplexUnsignedInt,B>& b ) {
    return TER_Binary<ComplexUnsignedInt,TensorR<ComplexUnsignedInt,A>,TensorR<ComplexUnsignedInt,B>,Fun_BitwiseAnd<ComplexUnsignedInt > >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<ComplexUnsignedLong,TensorR<ComplexUnsignedLong,A>,TensorR<ComplexUnsignedLong,B>,Fun_BitwiseAnd<ComplexUnsignedLong > >
    operator&( const TensorR<ComplexUnsignedLong,A>& a, const  TensorR<ComplexUnsignedLong,B>& b ) {
    return TER_Binary<ComplexUnsignedLong,TensorR<ComplexUnsignedLong,A>,TensorR<ComplexUnsignedLong,B>,Fun_BitwiseAnd<ComplexUnsignedLong > >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<ComplexUnsignedLongLong,TensorR<ComplexUnsignedLongLong,A>,TensorR<ComplexUnsignedLongLong,B>,Fun_BitwiseAnd<ComplexUnsignedLongLong > >
    operator&( const TensorR<ComplexUnsignedLongLong,A>& a, const  TensorR<ComplexUnsignedLongLong,B>& b ) {
    return TER_Binary<ComplexUnsignedLongLong,TensorR<ComplexUnsignedLongLong,A>,TensorR<ComplexUnsignedLongLong,B>,Fun_BitwiseAnd<ComplexUnsignedLongLong > >(a,b);
  }


  // Bitwise Xor: ^
  // NOTE: that "^" is also used for exterior product short hand 

  template <class A, class B> 
    inline TER_Binary<ComplexUnsignedChar,TensorR<ComplexUnsignedChar,A>,TensorR<ComplexUnsignedChar,B>,Fun_BitwiseXor<ComplexUnsignedChar > >
    operator^( const TensorR<ComplexUnsignedChar,A>& a, const  TensorR<ComplexUnsignedChar,B>& b ) {
    return TER_Binary<ComplexUnsignedChar,TensorR<ComplexUnsignedChar,A>,TensorR<ComplexUnsignedChar,B>,Fun_BitwiseXor<ComplexUnsignedChar > >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<ComplexUnsignedShort,TensorR<ComplexUnsignedShort,A>,TensorR<ComplexUnsignedShort,B>,Fun_BitwiseXor<ComplexUnsignedShort > >
    operator^( const TensorR<ComplexUnsignedShort,A>& a, const  TensorR<ComplexUnsignedShort,B>& b ) {
    return TER_Binary<ComplexUnsignedShort,TensorR<ComplexUnsignedShort,A>,TensorR<ComplexUnsignedShort,B>,Fun_BitwiseXor<ComplexUnsignedShort > >(a,b);
  }
  template <class A, class B> 
    inline TER_Binary<ComplexUnsignedInt,TensorR<ComplexUnsignedInt,A>,TensorR<ComplexUnsignedInt,B>,Fun_BitwiseXor<ComplexUnsignedInt > >
    operator^( const TensorR<ComplexUnsignedInt,A>& a, const  TensorR<ComplexUnsignedInt,B>& b ) {
    return TER_Binary<ComplexUnsignedInt,TensorR<ComplexUnsignedInt,A>,TensorR<ComplexUnsignedInt,B>,Fun_BitwiseXor<ComplexUnsignedInt > >(a,b);
  }
  template <class A, class B> inline
    TER_Binary<ComplexUnsignedLong,TensorR<ComplexUnsignedLong,A>,TensorR<ComplexUnsignedLong,B>,Fun_BitwiseXor<ComplexUnsignedLong > >
    operator^( const TensorR<ComplexUnsignedLong,A>& a, const  TensorR<ComplexUnsignedLong,B>& b ) {
    return
      TER_Binary<ComplexUnsignedLong,TensorR<ComplexUnsignedLong,A>,TensorR<ComplexUnsignedLong,B>,Fun_BitwiseXor<ComplexUnsignedLong > >(a,b);
  }
  template <class A, class B> inline
    TER_Binary<ComplexUnsignedLongLong,TensorR<ComplexUnsignedLongLong,A>,TensorR<ComplexUnsignedLongLong,B>,Fun_BitwiseXor<ComplexUnsignedLongLong > >
    operator^( const TensorR<ComplexUnsignedLongLong,A>& a, const  TensorR<ComplexUnsignedLongLong,B>& b ) {
    return
      TER_Binary<ComplexUnsignedLongLong,TensorR<ComplexUnsignedLongLong,A>,TensorR<ComplexUnsignedLongLong,B>,Fun_BitwiseXor<ComplexUnsignedLongLong > >(a,b);
  }


  // Bitwise ShiftLeft: <<

  /* template <class A, class B>  */
  /*   inline TER_TensorOpScalar<ComplexUnsignedChar,TensorR<ComplexUnsignedChar,A>,TensorR<ComplexUnsignedChar,B>,Fun_BitwiseShiftLeft<ComplexUnsignedChar > > */
  /*   operator<<( const TensorR<ComplexUnsignedChar,A>& a, const unsigned short b ) { */
  /*   return TER_TensorOpScalar<ComplexUnsignedChar,TensorR<ComplexUnsignedChar,A>,TensorR<ComplexUnsignedChar,B>,Fun_BitwiseShiftLeft<ComplexUnsignedChar > >(a,b); */
  /* } */
  /* template <class A, class B>  */
  /*   inline TER_TensorOpScalar<ComplexUnsignedShort,TensorR<ComplexUnsignedShort,A>,TensorR<ComplexUnsignedShort,B>,Fun_BitwiseShiftLeft<ComplexUnsignedShort > > */
  /*   operator<<( const TensorR<ComplexUnsignedShort,A>& a, const unsigned short b ) { */
  /*   return TER_TensorOpScalar<ComplexUnsignedShort,TensorR<ComplexUnsignedShort,A>,TensorR<ComplexUnsignedShort,B>,Fun_BitwiseShiftLeft<ComplexUnsignedShort > >(a,b); */
  /* } */
  /* template <class A, class B>  */
  /*   inline TER_TensorOpScalar<ComplexUnsignedInt,TensorR<ComplexUnsignedInt,A>,TensorR<ComplexUnsignedInt,B>,Fun_BitwiseShiftLeft<ComplexUnsignedInt > > */
  /*   operator<<( const TensorR<ComplexUnsignedInt,A>& a, const unsigned short b ) { */
  /*   return TER_TensorOpScalar<ComplexUnsignedInt,TensorR<ComplexUnsignedInt,A>,TensorR<ComplexUnsignedInt,B>,Fun_BitwiseShiftLeft<ComplexUnsignedInt > >(a,b); */
  /* } */
  /* template <class A, class B> inline */
  /*   TER_TensorOpScalar<ComplexUnsignedLong,TensorR<ComplexUnsignedLong,A>,TensorR<ComplexUnsignedLong,B>,Fun_BitwiseShiftLeft<ComplexUnsignedLong > > */
  /*   operator<<( const TensorR<ComplexUnsignedLong,A>& a, const unsigned short b ) { */
  /*   return */
  /*     TER_TensorOpScalar<ComplexUnsignedLong,TensorR<ComplexUnsignedLong,A>,TensorR<ComplexUnsignedLong,B>,Fun_BitwiseShiftLeft<ComplexUnsignedLong > >(a,b); */
  /* } */
  /* template <class A, class B> inline */
  /*   TER_TensorOpScalar<ComplexUnsignedLongLong,TensorR<ComplexUnsignedLongLong,A>,TensorR<ComplexUnsignedLongLong,B>,Fun_BitwiseShiftLeft<ComplexUnsignedLongLong > > */
  /*   operator<<( const TensorR<ComplexUnsignedLongLong,A>& a, const unsigned short b ) { */
  /*   return */
  /*     TER_TensorOpScalar<ComplexUnsignedLongLong,TensorR<ComplexUnsignedLongLong,A>,TensorR<ComplexUnsignedLongLong,B>,Fun_BitwiseShiftLeft<ComplexUnsignedLongLong > >(a,b); */
  /* } */
  

  /* // Bitwise ShiftRight: >> */

  /* template <class A, class B>  */
  /*   inline TER_TensorOpScalar<ComplexUnsignedChar,TensorR<ComplexUnsignedChar,A>,TensorR<ComplexUnsignedChar,B>,Fun_BitwiseShiftRight<ComplexUnsignedChar > > */
  /*   operator>>( const TensorR<ComplexUnsignedChar,A>& a, const unsigned short b ) { */
  /*   return TER_TensorOpScalar<ComplexUnsignedChar,TensorR<ComplexUnsignedChar,A>,TensorR<ComplexUnsignedChar,B>,Fun_BitwiseShiftRight<ComplexUnsignedChar > >(a,b); */
  /* } */
  /* template <class A, class B>  */
  /*   inline TER_TensorOpScalar<ComplexUnsignedShort,TensorR<ComplexUnsignedShort,A>,TensorR<ComplexUnsignedShort,B>,Fun_BitwiseShiftRight<ComplexUnsignedShort > > */
  /*   operator>>( const TensorR<ComplexUnsignedShort,A>& a, const unsigned short b ) { */
  /*   return TER_TensorOpScalar<ComplexUnsignedShort,TensorR<ComplexUnsignedShort,A>,TensorR<ComplexUnsignedShort,B>,Fun_BitwiseShiftRight<ComplexUnsignedShort > >(a,b); */
  /* } */
  /* template <class A, class B>  */
  /*   inline TER_TensorOpScalar<ComplexUnsignedInt,TensorR<ComplexUnsignedInt,A>,TensorR<ComplexUnsignedInt,B>,Fun_BitwiseShiftRight<ComplexUnsignedInt > > */
  /*   operator>>( const TensorR<ComplexUnsignedInt,A>& a, const unsigned short b ) { */
  /*   return TER_TensorOpScalar<ComplexUnsignedInt,TensorR<ComplexUnsignedInt,A>,TensorR<ComplexUnsignedInt,B>,Fun_BitwiseShiftRight<ComplexUnsignedInt > >(a,b); */
  /* } */
  /* template <class A, class B> inline */
  /*   TER_TensorOpScalar<ComplexUnsignedLong,TensorR<ComplexUnsignedLong,A>,TensorR<ComplexUnsignedLong,B>,Fun_BitwiseShiftRight<ComplexUnsignedLong > > */
  /*   operator>>( const TensorR<ComplexUnsignedLong,A>& a, const unsigned short b ) { */
  /*   return */
  /*     TER_TensorOpScalar<ComplexUnsignedLong,TensorR<ComplexUnsignedLong,A>,TensorR<ComplexUnsignedLong,B>,Fun_BitwiseShiftRight<ComplexUnsignedLong > >(a,b); */
  /* } */
  /* template <class A, class B> inline */
  /*   TER_TensorOpScalar<ComplexUnsignedLongLong,TensorR<ComplexUnsignedLongLong,A>,TensorR<ComplexUnsignedLongLong,B>,Fun_BitwiseShiftRight<ComplexUnsignedLongLong > > */
  /*   operator>>( const TensorR<ComplexUnsignedLongLong,A>& a, const unsigned short b ) { */
  /*   return */
  /*     TER_TensorOpScalar<ComplexUnsignedLongLong,TensorR<ComplexUnsignedLongLong,A>,TensorR<ComplexUnsignedLongLong,B>,Fun_BitwiseShiftRight<ComplexUnsignedLongLong > >(a,b); */
  /* } */

  



  
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

  // abs(complex Tensor)

  template <class D, class A> 
    inline TER_Unary<D,TensorR<std::complex<D>,A>,Fun_CAbs<D> > 
    abs(const TensorR<std::complex<D>,A>& a)
    {
      return  TER_Unary<D,TensorR<std::complex<D>,A>,Fun_CAbs<D> >(a);
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

  // pow(complexTensor<int>,intscalar)

  template <class A> 
    inline TER_Cplx_TensorOpScalar<int,TensorR<ComplexInt,A>,Fun_PowCR<int> > 
    pow(const TensorR<ComplexInt,A>& a, const int b)
    {
      return  TER_Cplx_TensorOpScalar<int,TensorR<ComplexInt,A>,Fun_PowCR<int> >(a,static_cast<int>(b));
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

  // pow(intscalar,complexTensor<int>)

  template <class B> 
    inline TER_Cplx_ScalarOpTensor<int,TensorR<ComplexInt,B>,Fun_PowRC<int> > 
    pow(const int a, const TensorR<ComplexInt,B>& b)
    {
      return  TER_Cplx_ScalarOpTensor<int,TensorR<ComplexInt,B>,Fun_PowRC<int> >(static_cast<int>(a),b);
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


  // complexTensor<int> + intscalar
  template <class A> 
    inline TER_Cplx_TensorOpScalar<int,TensorR<ComplexInt,A>,Fun_AddCR<int> > 
    operator+(const TensorR<ComplexInt,A>& a, const int b)
    {
      return  
	TER_Cplx_TensorOpScalar<int,TensorR<ComplexInt,A>,Fun_AddCR<int> >(a,static_cast<int>(b));  
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

  // intscalar + complexTensor<int>
  template <class B> 
    inline TER_Cplx_ScalarOpTensor<int,TensorR<ComplexInt,B>,Fun_AddRC<int> > 
    operator+(const int a, const TensorR<ComplexInt,B>& b)
    {
      return  
	TER_Cplx_ScalarOpTensor<int,TensorR<ComplexInt,B>,Fun_AddRC<int> >(static_cast<int>(a),b);  
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

  // complexTensor<int> - intscalar
  template <class A> 
    inline TER_Cplx_TensorOpScalar<int,TensorR<ComplexInt,A>,Fun_SubtractCR<int> > 
    operator-(const TensorR<ComplexInt,A>& a, const int b)
    {
      return  
	TER_Cplx_TensorOpScalar<int,TensorR<ComplexInt,A>,Fun_SubtractCR<int> >(a,static_cast<int>(b));  
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
  // intscalar - complexTensor<int>
  template <class B> 
    inline TER_Cplx_ScalarOpTensor<int,TensorR<ComplexInt,B>,Fun_SubtractRC<int> > 
    operator-(const int a, const TensorR<ComplexInt,B>& b)
    {
      return  
	TER_Cplx_ScalarOpTensor<int,TensorR<ComplexInt,B>,Fun_SubtractRC<int> >(static_cast<int>(a),b);  
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
  // complexTensor<int> * intscalar
  template <class A> 
    inline TER_Cplx_TensorOpScalar<int,TensorR<ComplexInt,A>,Fun_MultiplyCR<int> > 
    operator*(const TensorR<ComplexInt,A>& a, const int b)
    {
      return  
	TER_Cplx_TensorOpScalar<int,TensorR<ComplexInt,A>,Fun_MultiplyCR<int> >(a,static_cast<int>(b));  
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

  // intscalar * complexTensor<int>
  template <class B> 
    inline TER_Cplx_ScalarOpTensor<int,TensorR<ComplexInt,B>,Fun_MultiplyRC<int> > 
    operator*(const int a, const TensorR<ComplexInt,B>& b)
    {
      return  
	TER_Cplx_ScalarOpTensor<int,TensorR<ComplexInt,B>,Fun_MultiplyRC<int> >(static_cast<int>(a),b);  
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

  // complexTensor<int> / intscalar
  template <class A> 
    inline TER_Cplx_TensorOpScalar<int,TensorR<ComplexInt,A>,Fun_DivideCR<int> > 
    operator/(const TensorR<ComplexInt,A>& a, const int b)
    {
      return  
	TER_Cplx_TensorOpScalar<int,TensorR<ComplexInt,A>,Fun_DivideCR<int> >(a,static_cast<int>(b));  
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
  // intscalar / complexTensor<int>
  template <class B> 
    inline TER_Cplx_ScalarOpTensor<int,TensorR<ComplexInt,B>,Fun_DivideRC<int> > 
    operator/(const int a, const TensorR<ComplexInt,B>& b)
    {
      return  
	TER_Cplx_ScalarOpTensor<int,TensorR<ComplexInt,B>,Fun_DivideRC<int> >(static_cast<int>(a),b);  
    }






  

};

#endif 
