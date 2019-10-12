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
    inline TER_Unary<D2,TensorR<D1,A>,Fun_Cast<D2,D1> > 
    datacast(const TensorR<D1,A>& a)
    {
      return  TER_Unary<D2,TensorR<D1,A>,Fun_Cast<D2,D1> >(a);
    }



  /****************************************************************************
   *  products: Scalar Scalar
   ****************************************************************************
   */

  // --------------------  dot (inner) product --------------------------------
  
  // (a|b)

  // TODO: rewrite for only floating point base types
  template <class D> inline
    D operator|( const Scalar<D>& a, const  Scalar<D>& b ) {
    return a()*b();
  }


  // dot(a,b)

  template <class D> inline
    D dot( const Scalar<D>& a, const  Scalar<D>& b ) {
    return (a|b);
  }


  // --------------------  tensor (outer) product --------------------------------
  
  // (a&b)
  // TODO: rewrite for only floating point base types

  template <class D> inline
    D operator&( const Scalar<D>& a, const  Scalar<D>& b ) {
    return a()*b();
  }


  // tprod(a,b)

  template <class D> inline
    D tprod( const Scalar<D>& a, const  Scalar<D>& b ) {
    return (a&b);
  }


  // -------------------- antisymmetric (wedge)  product -----------------------
  
  // (a^b)
  // TODO: rewrite for only floating point base types

  template <class D> inline
    D operator^( const Scalar<D>& a, const  Scalar<D>& b ) {
    return 0;
  }


  // wprod(a,b)

  template <class D> inline
    D wprod( const Scalar<D>& a, const  Scalar<D>& b ) {
    return (a^b);
  }

  
  /****************************************************************************
   *  products: Vector Vector
   ****************************************************************************
   */


  // --------------------  dot (inner) product --------------------------------

  // (a|b)
  // TODO: rewrite for only floating point base types

  template <class D> inline
    D operator|( const Vector<D>& a, const  Vector<D>& b ) {

    D result = D(0);
    for (register index_type i = a.size(); i--;) {
      result += a[i]*b[i];
    }
    return result;
  }

  // dot(a,b)

  template <class D> inline
    D dot( const Vector<D>& a, const  Vector<D>& b ) {
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


  // (a|b)

  template <class D, class A, class B> inline
    D operator|( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {

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

  // dot(a,b)

  template <class D, class A, class B> inline
    D dot( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {
    return (a|b);
  }

  // --------------------  tensor (outer) product --------------------------------

    // (a&b)

  template <class D, class A, class B> inline
    D operator&( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {

    // (Scalar&Scalar)
    if ((a.ndims() == 0) && (b.ndims() == 0)) {
      return a[0]*b[0];
    }

  }

  // tprod(a,b)

  template <class D, class A, class B> inline
    D tprod( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {
    return (a&b);
  }

  // -------------------- antisymmetric (wedge)  product -----------------------

  // (a^b)

  template <class D, class A, class B> inline
    D operator^( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {

    // (Scalar^Scalar)
    if ((a.ndims() == 0) && (b.ndims() == 0)) {
      return a[0]*b[0];
    }

  }

  // wprod(a,b)

  template <class D, class A, class B> inline
    D wprod( const TensorR<D,A>& a, const  TensorR<D,B>& b ) {
    return (a^b);
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
  // *            Bit wise operators for unsigned types
  // ************************************************************************


  // TODO: rewrite for only integral types as base type
  
  // bitwise not (aka 1's complement): ~
  // NOTE: "~" is also used for Hermitian adjoint
  
  // Bitwise Or: |
  // NOTE: that "|" is also used for dot product short hand 


  // Bitwise And: &


  // Bitwise Xor: ^
  // NOTE: that "^" is also used for exterior product short hand 



  // Bitwise ShiftLeft: <<

  

  // Bitwise ShiftRight: >>




  
  
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

  // Tensor<int> + (int scalar) -- needed to avoid operator ambiguity

  template <class A> 
    inline TER_TensorOpScalar<int,TensorR<int,A>,Fun_Add<int> > 
    operator+(const TensorR<int,A>& a, const int b)
    {
      return  TER_TensorOpScalar<int,TensorR<int,A>,Fun_Add<int> >(a,b);
    }

  // (int scalar) + Tensor

  template <class D, class B>
    inline TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Add<D> > 
    operator+(const int a, const TensorR<D,B>& b )
    {
      return  TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Add<D> > (a,b);
    }

  // (int scalar) + Tensor<int>

  template <class B>
    inline TER_ScalarOpTensor<int,TensorR<int,B>,Fun_Add<int> > 
    operator+(const int a, const TensorR<int,B>& b )
    {
      return  TER_ScalarOpTensor<int,TensorR<int,B>,Fun_Add<int> > (a,b);
    }


  // Tensor - (int scalar)

  template <class D, class A> 
    inline TER_TensorOpScalar<D,TensorR<D,A>,Fun_Subtract<D> > 
    operator-(const TensorR<D,A>& a, const int b)
    {
      return  TER_TensorOpScalar<D,TensorR<D,A>,Fun_Subtract<D> >(a,b);
    }

  // Tensor<int> - (int scalar)

  template <class A> 
    inline TER_TensorOpScalar<int,TensorR<int,A>,Fun_Subtract<int> > 
    operator-(const TensorR<int,A>& a, const int b)
    {
      return  TER_TensorOpScalar<int,TensorR<int,A>,Fun_Subtract<int> >(a,b);
    }

  // (int scalar) - Tensor

  template <class D, class B>
    inline TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Subtract<D> > 
    operator-(const int a, const TensorR<D,B>& b )
    {
      return  TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Subtract<D> > (a,b);
    }

  // (int scalar) - Tensor<int>

  template <class B>
    inline TER_ScalarOpTensor<int,TensorR<int,B>,Fun_Subtract<int> > 
    operator-(const int a, const TensorR<int,B>& b )
    {
      return  TER_ScalarOpTensor<int,TensorR<int,B>,Fun_Subtract<int> > (a,b);
    }

  // Tensor * (int scalar)

  template <class D, class A> 
    inline TER_TensorOpScalar<D,TensorR<D,A>,Fun_Multiply<D> > 
    operator*(const TensorR<D,A>& a, const int b)
    {
      return  TER_TensorOpScalar<D,TensorR<D,A>,Fun_Multiply<D> >(a,b);
    }

  // Tensor<int> * (int scalar)

  template <class A> 
    inline TER_TensorOpScalar<int,TensorR<int,A>,Fun_Multiply<int> > 
    operator*(const TensorR<int,A>& a, const int b)
    {
      return  TER_TensorOpScalar<int,TensorR<int,A>,Fun_Multiply<int> >(a,b);
    }


  // (int scalar) * Tensor

  template <class D, class B>
    inline TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Multiply<D> > 
    operator*(const int a, const TensorR<D,B>& b )
    {
      return  TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Multiply<D> > (a,b);
    }

  // (int scalar) * Tensor<int>

  template <class B>
    inline TER_ScalarOpTensor<int,TensorR<int,B>,Fun_Multiply<int> > 
    operator*(const int a, const TensorR<int,B>& b )
    {
      return  TER_ScalarOpTensor<int,TensorR<int,B>,Fun_Multiply<int> > (a,b);
    }

  // Tensor / (int scalar)

  template <class D, class A> 
    inline TER_TensorOpScalar<D,TensorR<D,A>,Fun_Divide<D> > 
    operator/(const TensorR<D,A>& a, const int b)
    {
      return  TER_TensorOpScalar<D,TensorR<D,A>,Fun_Divide<D> >(a,b);
    }

  // Tensor<int> / (int scalar)

  template <class A> 
    inline TER_TensorOpScalar<int,TensorR<int,A>,Fun_Divide<int> > 
    operator/(const TensorR<int,A>& a, const int b)
    {
      return  TER_TensorOpScalar<int,TensorR<int,A>,Fun_Divide<int> >(a,b);
    }

  // (int scalar) / Tensor

  template <class D, class B>
    inline TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Divide<D> > 
    operator/(const int a, const TensorR<D,B>& b )
    {
      return  TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Divide<D> > (a,b);
    }

  // (int scalar) / Tensor<int>

  template <class B>
    inline TER_ScalarOpTensor<int,TensorR<int,B>,Fun_Divide<int> > 
    operator/(const int a, const TensorR<int,B>& b )
    {
      return  TER_ScalarOpTensor<int,TensorR<int,B>,Fun_Divide<int> > (a,b);
    }


  //---------- Tensor scalar mix: powers and exponents -----------------


  // pow(Tensor,scalar)

  template <class D, class A> 
    inline TER_TensorOpScalar<D,TensorR<D,A>,Fun_Pow<D> > 
    pow(const TensorR<D,A>& a, const D b)
    {
      return  TER_TensorOpScalar<D,TensorR<D,A>,Fun_Pow<D> >(a,b);
    }

  // pow(Tensor,int)

  template <class D, class A> 
    inline TER_TensorOpScalar<D,TensorR<D,A>,Fun_Monomial<D> > 
    pow(const TensorR<D,A>& a, const int b)
    {
      return  TER_TensorOpScalar<D,TensorR<D,A>,Fun_Monomial<D> >(a,b);
    }

  // pow(Tensor<int>,int)

  template <class A> 
    inline TER_TensorOpScalar<int,TensorR<int,A>,Fun_Monomial<int> > 
    pow(const TensorR<int,A>& a, const int b)
    {
      return  TER_TensorOpScalar<int,TensorR<int,A>,Fun_Monomial<int> >(a,b);
    }

  // pow(scalar,Tensor)

  template <class D, class B> 
    inline TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Pow<D> > 
    pow( const D a, const TensorR<D,B>& b)
    {
      return  TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Pow<D> >(a,b);
    }
  // pow(int,Tensor)

  template <class D, class B> 
    inline TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Monomial<D> > 
    pow( const int a, const TensorR<D,B>& b)
    {
      return  TER_ScalarOpTensor<D,TensorR<D,B>,Fun_Monomial<D> >(a,b);
    }
  // pow(int,Tensor<int>)

  template <class B> 
    inline TER_ScalarOpTensor<int,TensorR<int,B>,Fun_Pow<int> > 
    pow( const int a, const TensorR<int,B>& b)
    {
      return  TER_ScalarOpTensor<int,TensorR<int,B>,Fun_Pow<int> >(a,b);
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

  // Tensor<int> == int scalar

  template <class A> 
    inline TER_Bool_TensorOpScalar<int,TensorR<int,A>,Fun_Equal<int> > 
    operator==(const TensorR<int,A>& a, const int b)
    {
      return  TER_Bool_TensorOpScalar<int,TensorR<int,A>,Fun_Equal<int> >(a,static_cast<int>(b));
    }


  // int scalar == Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Equal<D> > 
    operator==(const int a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Equal<D> >(static_cast<D>(a),b);
    }
  // int scalar == Tensor<int>

  template <class B> 
    inline TER_Bool_ScalarOpTensor<int,TensorR<int,B>,Fun_Equal<int> > 
    operator==(const int a, const TensorR<int,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<int,TensorR<int,B>,Fun_Equal<int> >(static_cast<int>(a),b);
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

  // Tensor<int> != int scalar

  template <class A> 
    inline TER_Bool_TensorOpScalar<int,TensorR<int,A>,Fun_NotEqual<int> > 
    operator!=(const TensorR<int,A>& a, const int b)
    {
      return  TER_Bool_TensorOpScalar<int,TensorR<int,A>,Fun_NotEqual<int> >(a,static_cast<int>(b));
    }

  // int scalar != Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_NotEqual<D> > 
    operator!=(const int a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_NotEqual<D> >(static_cast<D>(a),b);
    }

  // int scalar != Tensor<int>

  template <class B> 
    inline TER_Bool_ScalarOpTensor<int,TensorR<int,B>,Fun_NotEqual<int> > 
    operator!=(const int a, const TensorR<int,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<int,TensorR<int,B>,Fun_NotEqual<int> >(static_cast<int>(a),b);
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

  // Tensor<int> <= int scalar

  template <class A> 
    inline TER_Bool_TensorOpScalar<int,TensorR<int,A>,Fun_LessOrEqual<int> > 
    operator<=(const TensorR<int,A>& a, const int b)
    {
      return  TER_Bool_TensorOpScalar<int,TensorR<int,A>,Fun_LessOrEqual<int> >(a,static_cast<int>(b));
    }

  // int scalar <= Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_LessOrEqual<D> > 
    operator<=(const int a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_LessOrEqual<D> >(static_cast<D>(a),b);
    }
  // int scalar <= Tensor<int>

  template <class B> 
    inline TER_Bool_ScalarOpTensor<int,TensorR<int,B>,Fun_LessOrEqual<int> > 
    operator<=(const int a, const TensorR<int,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<int,TensorR<int,B>,Fun_LessOrEqual<int> >(static_cast<int>(a),b);
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
  // Tensor >= int scalar

  template <class A> 
    inline TER_Bool_TensorOpScalar<int,TensorR<int,A>,Fun_GreaterOrEqual<int> > 
    operator>=(const TensorR<int,A>& a, const int b)
    {
      return  TER_Bool_TensorOpScalar<int,TensorR<int,A>,Fun_GreaterOrEqual<int> >(a,static_cast<int>(b));
    }

  // int scalar >= Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_GreaterOrEqual<D> > 
    operator>=(const int a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_GreaterOrEqual<D> >(static_cast<D>(a),b);
    }
  // int scalar >= Tensor

  template <class B> 
    inline TER_Bool_ScalarOpTensor<int,TensorR<int,B>,Fun_GreaterOrEqual<int> > 
    operator>=(const int a, const TensorR<int,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<int,TensorR<int,B>,Fun_GreaterOrEqual<int> >(static_cast<int>(a),b);
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
  // Tensor<int> < int scalar

  template <class A> 
    inline TER_Bool_TensorOpScalar<int,TensorR<int,A>,Fun_Less<int> > 
    operator<(const TensorR<int,A>& a, const int b)
    {
      return  TER_Bool_TensorOpScalar<int,TensorR<int,A>,Fun_Less<int> >(a,static_cast<int>(b));
    }

  // int scalar < Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Less<D> > 
    operator<(const int a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Less<D> >(static_cast<D>(a),b);
    }
  // int scalar < Tensor<int>

  template <class B> 
    inline TER_Bool_ScalarOpTensor<int,TensorR<int,B>,Fun_Less<int> > 
    operator<(const int a, const TensorR<int,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<int,TensorR<int,B>,Fun_Less<int> >(static_cast<int>(a),b);
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
  // Tensor<int> > int scalar

  template <class A> 
    inline TER_Bool_TensorOpScalar<int,TensorR<int,A>,Fun_Greater<int> > 
    operator>(const TensorR<int,A>& a, const int b)
    {
      return  TER_Bool_TensorOpScalar<int,TensorR<int,A>,Fun_Greater<int> >(a,static_cast<int>(b));
    }

  // int scalar > Tensor

  template <class D, class B> 
    inline TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Greater<D> > 
    operator>(const int a, const TensorR<D,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<D,TensorR<D,B>,Fun_Greater<D> >(static_cast<D>(a),b);
    }
  // int scalar > Tensor<int>

  template <class B> 
    inline TER_Bool_ScalarOpTensor<int,TensorR<int,B>,Fun_Greater<int> > 
    operator>(const int a, const TensorR<int,B>& b)
    {
      return  TER_Bool_ScalarOpTensor<int,TensorR<int,B>,Fun_Greater<int> >(static_cast<int>(a),b);
    }





  

  
  // ************************************************************************
  // *              Transpoe, Conjugate, Adjoint, and ~
  // ************************************************************************


  // real(Tensor)

  template <class D, class A> 
    inline TER_Unary<typename Realify<D>::Type, TensorR<D,A>, Fun_Real<D> > 
    real(const TensorR<D,A>& a)
    {
      return TER_Unary<typename Realify<D>::Type, TensorR<D,A>, Fun_Real<D> >(a);
    }

  // imag(Tensor)

  template <class D, class A> 
    inline TER_Unary<typename Realify<D>::Type, TensorR<D,A>, Fun_Imag<D> > 
    imag(const TensorR<D,A>& a)
    {
      return TER_Unary<typename Realify<D>::Type, TensorR<D,A>, Fun_Imag<D> >(a);
    }


  // conj(Tensor)

  template <class D, class A> 
    inline TER_Unary<typename Complexify<D>::Type, TensorR<D,A>, Fun_Conj<D> > 
    conj(const TensorR<D,A>& a)
    {
      return TER_Unary<typename Complexify<D>::Type, TensorR<D,A>, Fun_Conj<D> >(a);
    }


  
  // transpose(A) 

  template <class D, class A> 
    TERW_Transpose<D,TensorRW<D,A>,Fun_Plus<D> > 
    transpose(TensorRW<D,A>& a)
    {
      return TERW_Transpose<D,TensorRW<D,A>,Fun_Plus<D> >(a);
    }

  // adjoint(A) - conjugate transpose 

  template <class D, class A> 
    inline TER_Transpose<D,TensorR<D,A>,Fun_Conj<D> > 
    adjoint(const TensorR<D,A>& a)
    {
      return  TER_Transpose<D,TensorR<D,A>,Fun_Conj<D> >(a);
    }

  
  // ~A conjugate transpose operator

  template <class D, class A> 
    inline TER_Transpose<D,TensorR<D,A>,Fun_Conj<D> > 
    operator~(const TensorR<D,A>& a)
    {
      return  TER_Transpose<D,TensorR<D,A>,Fun_Conj<D> >(a);
    }













  // *********************************************************
  // *          Functions that create vectors
  // *********************************************************

  // The Range generating function (with step given)

  template <class D>
  inline Vector<D>& range(D start, D end, D step) {
    // determine size
    size_type N = 0;
    if (step > 0) {
      for (D x =start; x<=end; x +=step)
	N +=1;
    } else {
      for (D x =start; x>=end; x +=step) 
	N +=1;
    }
    Vector<D> *y = new Vector<D>(N);
    
    (*y)[0] = start;
    for (size_type i =1; i<N; i++)
      (*y)[i] = (*y)[i-1] + step;
    
    return *y;
  }


  // The Range generating function (step by +/-1)

  template <class D>
  inline Vector<D>& range(D start, D end) {
    if (end >= start)
      return range<D>(start,end,static_cast<D>(1));
    else 
      return range<D>(start,end,static_cast<D>(-1));
  }





  // linspace function [a,b]

  template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  inline Vector<D>& linspace(D start, D end, size_type N) {
    Vector<D> *y = new Vector<D>(N);


    const D step = (end-start)/static_cast<D>(N-1);

    (*y)[0] = start;
    for(size_type i = 1; i<(N-1); i++) 
      (*y)[i] = start + static_cast<D>(i)*step;
    (*y)[N-1] = end;
    return *y;


  }



  // linspace_a function (a,b]
  // Returns a vector of N equispaced points,
  // with spacing delta, spanning from a+delta to b

  template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  inline Vector<D>& linspace_a(D start, D end, size_type N) {
    Vector<D> *y = new Vector<D>(N);

  
    const D step = (end-start)/static_cast<D>(N);
    return linspace(start+step, end, N);
  }


  // linspace_b function [a,b)
  // Returns a vector of N equispaced points,
  // with spacing delta, spanning from a to b-delta

  template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  inline Vector<D>& linspace_b(D start, D end, size_type N) {
    Vector<D> *y = new Vector<D>(N);

  
    const D step = (end-start)/static_cast<D>(N);
    return linspace(start, end-step, N);
  }

  // linspace_ab function (a,b)
  // Returns a vector of N equispaced points,
  // with spacing delta, spanning from a+delta to b-delta

  template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  inline Vector<D>& linspace_ab(D start, D end, size_type N) {
    Vector<D> *y = new Vector<D>(N);

  
    const D step = (end-start)/static_cast<D>(N+1);
    return linspace(start+step, end-step, N);
  }






  // operator, (join)


  template <class D> 
    inline VERW_Join<D,Vector<D>,Vector<D> > 
    operator,(Vector<D>& a, Vector<D>& b)
    {
    
      printf2("  VERW_Join operator,(Vector<D>& a, Vector<D>& b)\n");
      return  VERW_Join<D,Vector<D>,Vector<D> >(a,b);
    }

  //--------------------------------------------
  // Need the const for compiler to find this
  // then we cast away the const
  template <class D, class A> 
    inline VERW_Join<D, TensorRW<D,A>, Vector<D> > 
    operator,(const TensorRW<D,A>& a, const Vector<D>& b)
    {
      printf2("  VERW_Join operator,(const TensorRW<D,A>& a, const Vector<D>& b)\n");
      TensorRW<D,A>& a_ = const_cast<TensorRW<D,A>& >(a);
      Vector<D>& b_ = const_cast<Vector<D>& >(b);
      return  VERW_Join<D, TensorRW<D,A>,Vector<D> >(a_,b_);
    }
  //--------------------------------------------

  //--------------------------------------------
  // Need the const for compiler to find this
  // then we cast away the const
  template <class D, class B> 
    inline VERW_Join<D, Vector<D>,TensorRW<D,B> > 
    operator,(const Vector<D>& a, const TensorRW<D,B>& b)
    {
      printf2("  VERW_Join operator,(const Vector<D>& a, const TensorRW<D,B>& b)\n");
      Vector<D>& a_ = const_cast<Vector<D>& >(a);
      TensorRW<D,B>& b_ = const_cast<TensorRW<D,B>& >(b);
      return VERW_Join<D, Vector<D>,TensorRW<D,B> >(a_,b_);
    }
  //--------------------------------------------

  //--------------------------------------------
  // Need the const for compiler to find this
  template <class D, class A, class B> 
    inline VERW_Join<D, TensorRW<D,A>,TensorRW<D,B> > 
    operator,(const TensorRW<D,A>& a, const TensorRW<D,B>& b)
    {
      printf2("  VERW_Join operator,(const TensorRW<D,A>& a, const TensorRW<D,B>& b)\n");
      TensorRW<D,A>& a_ = const_cast<TensorRW<D,A>& >(a);
      TensorRW<D,B>& b_ = const_cast<TensorRW<D,B>& >(b);
      return  VERW_Join<D, TensorRW<D,A>,TensorRW<D,B> >(a_,b_);
    }
  //--------------------------------------------


  
  ///---------
  
  template <class D> 
    inline const VER_Join<D, Vector<D>,Vector<D> > 
    operator,(const Vector<D>& a, const Vector<D>& b)
    {
      printf2("  VER_Join operator,(const Vector<D>& a, const Vector<D>& b)\n");
      return  VER_Join<D,Vector<D>,Vector<D> >(a,b);
    }

  template <class D, class B> 
    inline const VER_Join<D, Vector<D>,TensorR<D,B> > 
    operator,(const Vector<D>& a, const TensorR<D,B>& b)
    {
      printf2("  VER_Join operator,(const Vector<D>& a, const TensorR<D,B>& b)\n");
      return  VER_Join<D,Vector<D>,TensorR<D,B>  >(a,b);
    }

  template <class D, class A> 
    inline const VER_Join<D,TensorR<D,A>,Vector<D> > 
    operator,(const TensorR<D,A>& a, const Vector<D>& b)
    {
      printf2("  VER_Join operator,(const TensorR<D,A>& a, const Vector<D>& b)\n");
      return  VER_Join<D,TensorR<D,A>,Vector<D> >(a,b);
    }
 
  template <class D, class A, class B> 
    inline const VER_Join<D, TensorR<D,A>,TensorR<D,B> > 
    operator,(const TensorR<D,A>& a, const TensorR<D,B>& b)
    {
      printf2("  VER_Join operator,(const TensorR<D,A>& a, const TensorR<D,B>& b)\n");
      return  VER_Join<D, TensorR<D,A>,TensorR<D,B> >(a,b);
    }






  // rep(v,m)

  template <class D, class A> 
    inline VER_Rep<D,TensorR<D,A> >
    rep(const TensorR<D,A>& a, const size_type m) {
    return VER_Rep<D,TensorR<D,A> >(a,m);
  }

  
 

  


  /****************************************************************
   * functions that convert vectors into other objects
   *****************************************************************
   */


  // toCarray(v)

  template <class D2, class D1, class A> 
    inline D2* toCarray(const TensorR<D1,A>& v) {
    const size_type N = v.size();
    D2* dptr = new D2[N];
    for(index_type i = 0; i<N; i++) 
      dptr[i] = static_cast<D2>(v[i]);
    return  dptr;
  }

  

  // tostdvector(v)

  template <class D2, class D1, class A> 
    inline std::vector<D2>
    tostdvector(const TensorR<D1,A>& v) {
    const size_type N = v.size();
    std::vector<D2> y(N);
    for(index_type i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v[i]);
    return y;
  }



  // tovalarray(v)

  template <class D2, class D1, class A> 
    inline std::valarray<D2>
    tovalarray(const TensorR<D1,A>& v) {
    const size_type N = v.size();
    std::valarray<D2> y(N);
    for(index_type i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v[i]);
    return y;
  }


  /****************************************************************
   * calculus related
   *****************************************************************
   */

  
  // reverse

  template <class D, class A>
    inline Vector<D>& reverse(const TensorR<D,A>& f) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->reverse();
    return *g;
  }


  // cumsum() -- cumulative sum

  template <class D, class A>
    inline Vector<D>& cumsum(const TensorR<D,A>& f) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->cumsum();
    return *g;
  }
  
  // cumprod()  --  cumulative product
  
  template <class D, class A>
    inline Vector<D>& cumprod(const TensorR<D,A>& f) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->cumprod();
    return *g;
  }


  // cumtrapz() -- cumulative trapezoidal summation
  
  template <class D, class A>
    inline Vector<D>& cumtrapz(const TensorR<D,A>& f) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->cumtrapz();
    return *g;
  }

  // integrate_a2x(order)
  // order  name
  //     0  rectangular
  //     1  trapazoidal
  template <class D, class A>
    inline Vector<D>& integrate_a2x(const TensorR<D,A>& f, const D a, const D b, const int order=1) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->integrate_a2x(a,b,order);
    return *g;
  }


  // cumsumrev() -- cumulative sum -- from last to first

  template <class D, class A>
    inline Vector<D>& cumsum_rev(const TensorR<D,A>& f) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->cumsum_rev();
    return *g;
  }

    // cumprodrev()  --  cumulative product  -- from last to first

  template <class D, class A>
    inline Vector<D>& cumprod_rev(const TensorR<D,A>& f) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->cumprod_rev();
    return *g;
  }


    // cumtrapz() -- cumulative trapezoidal summation -- from last to first

  template <class D, class A>
    inline Vector<D>& cumtrapz_rev(const TensorR<D,A>& f) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->cumtrapz_rev();
    return *g;
  }



  // integrate_x2b
  // order  name
  //     0  rectangular
  //     1  trapazoidal
  template <class D, class A>
    inline Vector<D>& integrate_x2b(const TensorR<D,A>& f, const D a, const D b, const int order=1) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->integrate_x2b(a,b,order);
    return *g;
  }



  // diff   (v[n] = v[n] - v[n-1])
  template <class D, class A>
    inline Vector<D>& diff(const TensorR<D,A>& f, const bool periodic=false) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->diff(periodic);
    return *g;
  }

  // diff_rev   (v[n] = v[n+1] - v[n])
  template <class D, class A>
    inline Vector<D>& diff_rev(const TensorR<D,A>& f, const bool periodic=false) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->diff_rev(periodic);
    return *g;
  }


  // derivative
  // any change in the default parameters must be likewise made in Vector.deriv(...)
  
  template <class D, class A>
    inline Vector<D>& deriv(const TensorR<D,A>& f, const D a, const D b, const int n=1, int Dpts=7, const bool periodic=false) {
    Vector<D> *df = new Vector<D>(f.size());
    *df = f;
    df->deriv(a,b,n,Dpts,periodic);
    return *df;
  }
  
  // integrate_a2b(a)
  // order  name
  //     0  rectangular
  //     1  trapazoidal
  //     2  simpson
  //     3  simpson 3/8
  //     4  Boole
  
  template <class D, class A> 
    D integrate_a2b( const TensorR<D,A>& v, const D a, const D b, const int order=1 ) {
    
 
    const size_type N = v.size();
    if (N==0) {
      return 0;
    }
    if (a==b) {
      return 0;
    }

    D result = 0;

    switch (order) {
    case 0:
      for (register index_type j = 0; j < N ; j++ ) {
	result += v[j];
      }
      result = result * (b-a)/D(N);
      break;
    case 1:
      result += (v[0]+v[N-1])/2;
      for (register index_type j = 1; j < N-1 ; j++ ) {
	result += v[j];
      }
      result = result * (b-a)/D(N-1);
      break;
    case 2:
      if (N%2==0)  {
	mout << "integrate_a2b: Number of points must be odd N="<<N<<std::endl;
      }
      {
	D sodd = 0;
	D seven = 0;
	result += v[0]+v[N-1];
	for (register index_type j = 1; j < N-1 ; j++ ) {
	  if (j%2==1) {
	    sodd += v[j];
	  } else {
	    seven += v[j];
	  }
	}
	result += 4*sodd + 2*seven;
	result = result * (b-a)/(3*D(N-1));
      }
      break;
    case 3:
      if (N%3!=1)  {
	mout << "integrate_a2b: N-1 must be divisible by 3, N="<<N<<std::endl;
      }
      {
	D s1 = 0;
	D s2 = 0;
	D s3 = 0;
	
	result += v[0]+v[N-1];
	for (register index_type j = 1; j < N-1 ; j++ ) {
	  if (j%3==1) {
	    s1 += v[j];
	  } else if (j%3==2) {
	    s2 += v[j];
	  } else {
	    s3 += v[j];
	  }
	}
	result += 3*s1 + 3*s2 + 2*s3;
	result = result * 3*(b-a)/(8*D(N-1));
      }
      break;
    case 4:
      if (N%4!=1)  {
	mout << "integrate_a2b: N-1 must be divisible by 4, N="<<N<<std::endl;
      }
      {
	D s1 = 0;
	D s2 = 0;
	D s3 = 0;
	D s4 = 0;
	
	result += 7*(v[0]+v[N-1]);
	for (register index_type j = 1; j < N-1 ; j++ ) {
	  if (j%4==1) {
	    s1 += v[j];
	  } else if (j%4==2) {
	    s2 += v[j];
	  } else if (j%4==3) {
	    s3 += v[j];
	  } else {
	    s4 += v[j];
	  }
	}
	result += 32*s1 + 12*s2 + 32*s3 + 14*s4;
	result = result * 2*(b-a)/(45*D(N-1));
      }
      break;
    default:
#if MATRICKS_DEBUG>0
      std::cerr << "integrate_a2b: bad order parameter order="<<order<<std::endl;   
#endif
      break;
    }

    return result;
  }



  // *********************************************************
  // *          Series
  // *********************************************************


  // maclaurin(vector coefs, vector vals, max N)

  template <class D, class A, class X> 
    inline TER_Series<D, TensorR<D,A>, TensorR<D,X> > 
    maclaurin(const TensorR<D,A>& a, const TensorR<D,X>& x, const int N, const D x0)
    {
      return  TER_Series<D, TensorR<D,A>, TensorR<D,X> >(a,x,N,x0);
    }
  
  // taylor(vector coefs, vector vals, max N)

  template <class D, class A, class X> 
    inline TER_Series<D, TensorR<D,A>, TensorR<D,X> > 
    taylor(const TensorR<D,A>& a, const TensorR<D,X>& x, const int N)
    {
      return  TER_Series<D, TensorR<D,A>, TensorR<D,X> >(a,x,N);
    }

  // ifourier(vector cos coefs, vector sin coefs, vector vals, max N, k1=2pi/wavelength or 2pi/period)
  // sin coefs must include a coef for n=0 even though its irrelevant

  template <class D, class A, class B, class X> 
    inline  TER_Series2<D, TensorR<D,A>, TensorR<D,B>, TensorR<D,X>, Fun_Cos<D>, Fun_Sin<D> >
    ifourier(const TensorR<D,A>& Acos, const TensorR<D,B>& Bsin, const TensorR<D,X>& x, const int N, const D k1)
    {
      return  TER_Series2<D, TensorR<D,A>, TensorR<D,B>, TensorR<D,X>, Fun_Cos<D>, Fun_Sin<D> >(Acos,Bsin,x,N,k1);
    }

















  

};

#endif 
