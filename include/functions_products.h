#ifndef MATHQ__FUNCTIONS_PRODUCTS_H
#define MATHQ__FUNCTIONS_PRODUCTS_H 1


namespace mathq {

  /****************************************************************************
   *  products: Scalar Scalar
   ****************************************************************************
   */

  // --------------------  dot (inner) product --------------------------------
  
  // dot(a,b)

  template <class E1, class E2> 
    auto dot( const Scalar<E1>& a, const  Scalar<E2>& b ) {
    return a()*b();
  }

  // (a|b)

  // TODO: rewrite for only floating point base types
  template <class E1, class E2> 
    auto operator|( const Scalar<E1>& a, const  Scalar<E2>& b ) {
    return dot(a,b);
  }




  // --------------------  tensor (outer) product --------------------------------
  
  // prodt(a,b)

  template <class E1, class E2> 
    auto prodt( const Scalar<E1>& a, const  Scalar<E2>& b ) {
    return a()*b();
  }

  // (a&b)
  // TODO: rewrite for only floating point base types

  template <class E1, class E2> 
  auto operator&( const Scalar<E1>& a, const  Scalar<E2>& b ) {
    return prodt(a,b);
  }




  // -------------------- antisymmetric (wedge)  product -----------------------
  
  // prodw(a,b)

  template <class E1, class E2> 
  auto prodw( const Scalar<E1>& a, const  Scalar<E2>& b ) {
    return 0;
  }

  // (a^b)
  // TODO: rewrite for only floating point base types

  template <class E1, class E2> 
  auto operator^( const Scalar<E1>& a, const  Scalar<E2>& b ) {
    return prodw(a,b);
  }



  
  /****************************************************************************
   *  products: Vector Vector
   ****************************************************************************
   */


  // --------------------  dot (inner) product --------------------------------

  // (a|b)
  // TODO: rewrite for only floating point base types

  template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
  EnableMethodIf<R==1, typename MultType<D1,D2>::Type&> dot(const TensorR<A,E1,D1,M,R>& a, const TensorR<B,E2,D2,M,R>& b) {

      typedef typename MultType<D1,D2>::Type D3;
      typedef typename NumberType<E1,D3>::ReplaceTypeD E3;   // see TODO note above

      E3* result = new E3;
      *result = 0;
      for (index_type i = 0; i < a.deepsize(); i++) {
	*result += a[i]*b[i];
      }
      return *result;
  }

  // (a|b)

  template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
  EnableMethodIf<R==1, typename MultType<D1,D2>::Type&> operator|(const TensorR<A,E1,D1,M,R>& a, const TensorR<B,E2,D2,M,R>& b) {
    return dot(a,b);
  }

  // --------------------  tensor (outer) product --------------------------------

  // -------------------- antisymmetric (wedge)  product -----------------------


  // -------------------- cross  product -----------------------

  
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


//   // (a|b)

// template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
// auto operator|(const TensorR<A,E1,D1,M,R>& a, const TensorR<B,E2,D2,M,R>& b) {
//   typedef typename MultType<D1,D2>::Type D3;
//   typedef typename NumberType<E1,D3>::ReplaceTypeD E3;   // see TODO note above
  
//     // (Scalar|Scalar)
//     if ((a.ndims() == 0) && (b.ndims() == 0)) {
//       return a[0]*b[0];
//     }

//     // (Vector|Vector)
//     if ((a.ndims() == 1) && (b.ndims() == 1)) {
//       D result = D(0);
//       for (index_type i = a.deepsize(); i--;) {
// 	result += a[i]*b[i];
//       }
//       return result;
//     }
//   }

//   // dot(a,b)

// template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
// auto dot(const TensorR<A,E1,D1,M,R>& a, const TensorR<B,E2,D2,M,R>& b) {
//     return (a|b);
//   }

//   // --------------------  tensor (outer) product --------------------------------

//   // (a&b)

// template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
// auto operator&(const TensorR<A,E1,D1,M,R>& a, const TensorR<B,E2,D2,M,R>& b) {
//   typedef typename MultType<D1,D2>::Type D3;
//   typedef typename NumberType<E1,D3>::ReplaceTypeD E3;   // see TODO note above

//     // (Scalar&Scalar)
//     if ((a.ndims() == 0) && (b.ndims() == 0)) {
//       return a[0]*b[0];
//     }

//   }

//   // prodt(a,b)

// template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
// auto prodt(const TensorR<A,E1,D1,M,R>& a, const TensorR<B,E2,D2,M,R>& b) {
//     return (a&b);
//   }

//   // -------------------- antisymmetric (wedge)  product -----------------------

//   // (a^b)

// template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
// auto operator^(const TensorR<A,E1,D1,M,R>& a, const TensorR<B,E2,D2,M,R>& b) {
//   typedef typename MultType<D1,D2>::Type D3;
//   typedef typename NumberType<E1,D3>::ReplaceTypeD E3;   // see TODO note above

//     // (Scalar^Scalar)
//     if ((a.ndims() == 0) && (b.ndims() == 0)) {
//       return a[0]*b[0];
//     }

//   }

//   // prodw(a,b)

// template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
// auto prodw(const TensorR<A,E1,D1,M,R>& a, const TensorR<B,E2,D2,M,R>& b) {
//     return (a^b);
//   }

  

};

#endif 
