#ifndef VOPERATORS_H
#define VOPERATORS_H 1

#include <string>
#include <sstream>


namespace Matricks {



  /************************************************************
   *               Templates for Binary Operators
   *
   * D = data type, e.g. double
   * A = either an Vector or a Vexpr
   * B = either an Vector or a Vexpr
   ************************************************************
   */

  // vector + vector

  template <class D, class A, class B> 
  inline VBinOp<D,VorE<D,A>,VorE<D,B>,ApAdd<D> > 
  operator+(const VorE<D,A>& a, const VorE<D,B>& b)
  {
    return  VBinOp<D,VorE<D,A>,VorE<D,B>,ApAdd<D> >(a,b);
  }



  // vector - vector

  template <class D, class A, class B> 
  inline VBinOp<D,VorE<D,A>,VorE<D,B>,ApSubtract<D> > 
  operator-(const VorE<D,A>& a, const VorE<D,B>& b)
  {
    return  VBinOp<D,VorE<D,A>,VorE<D,B>,ApSubtract<D> >(a,b);
  }


  // vector * vector

  template <class D, class A, class B> 
  inline VBinOp<D,VorE<D,A>,VorE<D,B>,ApMultiply<D> > 
  operator*(const VorE<D,A>& a, const VorE<D,B>& b)
  {
    return  VBinOp<D,VorE<D,A>,VorE<D,B>,ApMultiply<D> >(a,b);
  }


  // vector / vector

  template <class D, class A, class B> 
  inline VBinOp<D,VorE<D,A>,VorE<D,B>,ApDivide<D> > 
  operator/(const VorE<D,A>& a, const VorE<D,B>& b)
  {
    return  VBinOp<D,VorE<D,A>,VorE<D,B>,ApDivide<D> >(a,b);
  }




  /*

  // vector , vector

  template <class D, class A, class B> 
  inline VConcatOp<D,VorE<D,A>,VorE<D,B> > 
  operator,(const VorE<D,A>& a, const VorE<D,B>& b)
  {
    return  VConcatOp<D,VorE<D,A>,VorE<D,B> >(a,b);
  }

  // vectorexp , scalar

  template <class D, class A> 
  inline VConcatOp<D,VorE<D,A>,VScalObj<D> > 
  operator,(const VorE<D,A>& a, const D b)
  {
    return  VConcatOp<D,VorE<D,A>,VScalObj<D> >(a,VScalObj<D>(b));
  }

  */




  /************************************************************
   *               Templates for vector/scalar Operators
   *
   * D = data type, e.g. double (vector and scalar must be of same data type)
   * A = either an Vector or a Vexpr
   ************************************************************
   */


  // vector + scalar

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApAdd<D> > 
  operator+(const VorE<D,A>& a, const D b)
  {
    return  VecOpScal<D,VorE<D,A>,ApAdd<D> >(a,b);
  }

  // scalar + vector

  template <class D, class B>
  inline ScalOpVec<D,VorE<D,B>,ApAdd<D> > 
  operator+(const D a, const VorE<D,B>& b )
  {
    return  ScalOpVec<D,VorE<D,B>,ApAdd<D> > (a,b);
  }


  // vector - scalar

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApSubtract<D> > 
  operator-(const VorE<D,A>& a, const D b)
  {
    return  VecOpScal<D,VorE<D,A>,ApSubtract<D> >(a,b);
  }

  // scalar - vector

  template <class D, class B>
  inline ScalOpVec<D,VorE<D,B>,ApSubtract<D> > 
  operator-(const D a, const VorE<D,B>& b )
  {
    return  ScalOpVec<D,VorE<D,B>,ApSubtract<D> > (a,b);
  }

  // vector * scalar

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApMultiply<D> > 
  operator*(const VorE<D,A>& a, const D b)
  {
    return  VecOpScal<D,VorE<D,A>,ApMultiply<D> >(a,b);
  }

  // scalar * vector

  template <class D, class B>
  inline ScalOpVec<D,VorE<D,B>,ApMultiply<D> > 
  operator*(const D a, const VorE<D,B>& b )
  {
    return  ScalOpVec<D,VorE<D,B>,ApMultiply<D> > (a,b);
  }

  // vector / scalar

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApDivide<D> > 
  operator/(const VorE<D,A>& a, const D b)
  {
    return  VecOpScal<D,VorE<D,A>,ApDivide<D> >(a,b);
  }

  // scalar / vector

  template <class D, class B>
  inline ScalOpVec<D,VorE<D,B>,ApDivide<D> > 
  operator/(const D a, const VorE<D,B>& b )
  {
    return  ScalOpVec<D,VorE<D,B>,ApDivide<D> > (a,b);
  }


  // the following are defined for convenience

  // vector + (int scalar)

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApAdd<D> > 
  operator+(const VorE<D,A>& a, const int b)
  {
    return  VecOpScal<D,VorE<D,A>,ApAdd<D> >(a,b);
  }

  // (int scalar) + vector

  template <class D, class B>
  inline ScalOpVec<D,VorE<D,B>,ApAdd<D> > 
  operator+(const int a, const VorE<D,B>& b )
  {
    return  ScalOpVec<D,VorE<D,B>,ApAdd<D> > (a,b);
  }


  // vector - (int scalar)

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApSubtract<D> > 
  operator-(const VorE<D,A>& a, const int b)
  {
    return  VecOpScal<D,VorE<D,A>,ApSubtract<D> >(a,b);
  }

  // (int scalar) - vector

  template <class D, class B>
  inline ScalOpVec<D,VorE<D,B>,ApSubtract<D> > 
  operator-(const int a, const VorE<D,B>& b )
  {
    return  ScalOpVec<D,VorE<D,B>,ApSubtract<D> > (a,b);
  }

  // vector * (int scalar)

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApMultiply<D> > 
  operator*(const VorE<D,A>& a, const int b)
  {
    return  VecOpScal<D,VorE<D,A>,ApMultiply<D> >(a,b);
  }

  // (int scalar) * vector

  template <class D, class B>
  inline ScalOpVec<D,VorE<D,B>,ApMultiply<D> > 
  operator*(const int a, const VorE<D,B>& b )
  {
    return  ScalOpVec<D,VorE<D,B>,ApMultiply<D> > (a,b);
  }

  // vector / (int scalar)

  template <class D, class A> 
  inline VecOpScal<D,VorE<D,A>,ApDivide<D> > 
  operator/(const VorE<D,A>& a, const int b)
  {
    return  VecOpScal<D,VorE<D,A>,ApDivide<D> >(a,b);
  }

  // (int scalar) / vector

  template <class D, class B>
  inline ScalOpVec<D,VorE<D,B>,ApDivide<D> > 
  operator/(const int a, const VorE<D,B>& b )
  {
    return  ScalOpVec<D,VorE<D,B>,ApDivide<D> > (a,b);
  }





  /****************************************************************
   *               Templates for Unary Operators & Unary Functions
   *
   * D = data type, e.g. double 
   * A = either an Vector or a Vexpr
   *****************************************************************
   */

  // +(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApPlus<D> > 
  operator+(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApPlus<D> >(a);
  }


  // -(vector)

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,ApMinus<D> > 
  operator-(const VorE<D,A>& a)
  {
    return  VFuncOp<D,VorE<D,A>,ApMinus<D> >(a);
  }


  // vcast(vector)

  template <class D2, class D1, class A> 
  inline VFuncOp<D2,VorE<D1,A>,ApCast<D1,D2> > 
  vcast(const VorE<D1,A>& a)
  {
    return  VFuncOp<D2,VorE<D1,A>,ApCast<D1,D2> >(a);
  }


  // vcast(matrix)

  template <class D2, class D1, class A> 
  inline Vector<D2> 
  vcast(const MorE<D1,A>& a)
  {
    const size_type N = a.size();
#ifdef MATRICKS_DEBUG
    std::string name=a.debugtxt();
    name = "vcast("+name+")";
    if ( mexpr_is_size_bad(a.size()) ){ 
      mbad_expr_in_unary(a,"vcast");
      Vector<D2> y(0,name);
      return y;
    }
    Vector<D2> y(N,name);
#else
    Vector<D2> y(N);
#endif

    for(size_type i = 0; i<N; i++) 
      y[i] = static_cast<D2>(a(i));
    return y;
  }



  // vcast(C-array)

  template <class D2, class D1> 
  inline Vector<D2>
  vcast(const D1* dptr, const size_type N)
  {
    Vector<D2> y(N,"vcast(C-array)");
    for(size_type i = 0; i<N; i++) 
      y[i] = static_cast<D2>(dptr[i]);
    return  y;
  }

  

  // vcast(std::vector)

  template <class D2, class D1> 
  inline Vector<D2>
  vcast(const std::vector<D1>& v2) {
    const size_type N = v2.size();
    Vector<D2> y(N,"vcast(std::vector)");
    for(size_type i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v2[i]);
    return  y;
  }


  // vcast(std::valarray)

  template <class D2, class D1> 
  inline Vector<D2>
  vcast(const std::valarray<D1>& v2) {
    const size_type N = v2.size();
    Vector<D2> y(N,"vcast(std::valarray)");
    for(size_type i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v2[i]);
    return  y;
  }



  /****************************************************************
   * functions that convert vectors into other objects
   *****************************************************************
   */


  // toCarray(v)

  template <class D2, class D1, class A> 
  inline D2*
  toCarray(const VorE<D1,A>& v) {
    const size_type N = v.size();
    D2* dptr = new D2[N];
    for(size_type i = 0; i<N; i++) 
      dptr[i] = static_cast<D2>(v[i]);
    return  dptr;
  }

  

  // tostdvector(v)

  template <class D2, class D1, class A> 
  inline std::vector<D2>
  tostdvector(const VorE<D1,A>& v) {
    const size_type N = v.size();
    std::vector<D2> y(N);
    for(size_type i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v[i]);
    return y;
  }



  // tovalarray(v)

  template <class D2, class D1, class A> 
  inline std::valarray<D2>
  tovalarray(const VorE<D1,A>& v) {
    const size_type N = v.size();
    std::valarray<D2> y(N);
    for(size_type i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v[i]);
    return y;
  }


  /****************************************************************************
   * Binary Functions/Operators that return scalars
   ****************************************************************************
   */


  // dotproduct operator (a|b)

  template <class D, class A, class B> 
  inline D operator|( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    D result = D();
    
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

  // sum(a)

  template <class D, class A> 
  inline D sum( const VorE<D,A>& a ) {
    
#ifdef MATRICKS_DEBUG
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"sum");
      return 0;
    }
#endif
 
    const size_type N = a.size();
    if (N==0)
      return 0;

    D result = a[0];

    for (register size_type i = 1; i < N ; i++ )
      result += a[i];
    
    return result;
  }







  // norm(a)

  template <class D, class A> 
  inline D norm( const VorE<D,A>& a ) {
    
#ifdef MATRICKS_DEBUG
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"norm");
      return 0;
    }
#endif
 
    const size_type N = a.size();
    if (N==0)
      return 0;

    D result = a[0]*a[0];

    for (register size_type i = 1; i < N ; i++ )
      result += a[i]*a[i];
    
    return std::sqrt(result);
  }




  // min(a)

  template <class D, class A> 
  inline D min( const VorE<D,A>& a ) {
    
#ifdef MATRICKS_DEBUG
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"min");
      return 0;
    }
#endif
 
    const size_type N = a.size();
    if (N==0)
      return 0;

    D result = a[0];

    for (register size_type i = 1; i < N ; i++ )
      result = std::min(result,a[i]);
    
    return result;
  }




  // max(a)

  template <class D, class A> 
  inline D max( const VorE<D,A>& a ) {
    
#ifdef MATRICKS_DEBUG
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"max");
      return 0;
    }
#endif
    const size_type N = a.size();
    if (N==0)
      return 0;

    D result = a[0];

    for (register size_type i = 1; i < N ; i++ )
      result = std::max(result,a[i]);
    
    return result;
  }







  /****************************************************************************
   * Unary Functions/Operators that perform "in place", modifying the argument
   ****************************************************************************
   */

  // sort(a)

  template <class D> void sort(Vector<D>& a ) {

    const size_type N = a.size();
    if (N==0)
      return;

    // have to copy data into a vector, since valarray doesn't 
    // support sorting
    std::vector<D> data(N);
    
    for (register size_type i = 0; i < N ; i++ )
      data[i] = a[i];

    sort(data.begin(),data.end());
    
    for (register size_type i = 0; i < N ; i++ )
      a[i] = data[i];

  }



  // sort and return the sorted indices: sortwind(a)

  template <class DAT> class idpair {
  public:
    size_type ind;
    DAT dat;
    
    bool operator<(const idpair<DAT>& x2) const {
      return (this->dat < x2.dat);
    }
  };

  template <class D> Vector<uint> sortwind(Vector<D>& a ) {

    const size_type N = a.size();
#ifdef MATRICKS_DEBUG
    std::string name = "sortindices(" + a.debugtxt() +")";
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"sortwind");
      Vector<uint> ivec(0,name);
      return ivec;
    }
    Vector<uint> ivec(N,name);
#else
    Vector<uint> ivec(N);
#endif

    if (N==0)
      return ivec;
    
    std::vector<idpair<D> > data(N);
    

    for (register size_type i = 0; i < N ; i++ ) {
      data[i].ind = i;
      data[i].dat = a[i];
    }
    
    
    sort(data.begin(),data.end());
    
    
    for (register size_type i = 0; i < N ; i++ ) {
      ivec[i] = data[i].ind;
      a[i] = data[i].dat;
    }
    
    return ivec;
    
  }



};

#endif //VOPERATORS_H
