#ifndef VFUNCTIONS_H
#define VFUNCTIONS_H 1


namespace matricks {



  /************************************************************
   *          Functions thatcreate vectors
   ************************************************************
   */

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

#if MATRICKS_DEBUG>0
    if (N<2) {
      vbadlinspace<D>(start,end,N);
      return *y;
    } 
#endif

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

#if MATRICKS_DEBUG>0
    if (N<2) {
      vbadlinspace<D>(start,end,N);
      return *y;
    } 
#endif
  
    const D step = (end-start)/static_cast<D>(N);
    return linspace(start+step, end, N);
  }


  // linspace_b function [a,b)
  // Returns a vector of N equispaced points,
  // with spacing delta, spanning from a to b-delta

  template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  inline Vector<D>& linspace_b(D start, D end, size_type N) {
    Vector<D> *y = new Vector<D>(N);

#if MATRICKS_DEBUG>0
    if (N<2) {
      vbadlinspace<D>(start,end,N);
      return *y;
    } 
#endif
  
    const D step = (end-start)/static_cast<D>(N);
    return linspace(start, end-step, N);
  }

  // linspace_ab function (a,b)
  // Returns a vector of N equispaced points,
  // with spacing delta, spanning from a+delta to b-delta

  template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  inline Vector<D>& linspace_ab(D start, D end, size_type N) {
    Vector<D> *y = new Vector<D>(N);

#if MATRICKS_DEBUG>0
    if (N<2) {
      vbadlinspace<D>(start,end,N);
      return *y;
    } 
#endif
  
    const D step = (end-start)/static_cast<D>(N+1);
    return linspace(start+step, end-step, N);
  }




  /************************************************************
   *               Binary Functions 
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




  


  // operator, (join)


  template <class D> 
    inline VJoinObj<D,Vector<D>,Vector<D> > 
    operator,(Vector<D>& a, Vector<D>& b)
    {
    
      printf2("  VJoinObj operator,(Vector<D>& a, Vector<D>& b)\n");
      return  VJoinObj<D,Vector<D>,Vector<D> >(a,b);
    }

  //--------------------------------------------
  // Need the const for compiler to find this
  template <class D, class A> 
    inline VJoinObj<D, VWrapper<D,A>, Vector<D> > 
    operator,(const VWrapper<D,A>& a, const Vector<D>& b)
    {
      printf2("  VJoinObj operator,(const VWrapper<D,A>& a, const Vector<D>& b)\n");
      VWrapper<D,A>& a_ = const_cast<VWrapper<D,A>& >(a);
      Vector<D>& b_ = const_cast<Vector<D>& >(b);
      return  VJoinObj<D, VWrapper<D,A>,Vector<D> >(a_,b_);
    }
  //--------------------------------------------

  //--------------------------------------------
  // Need the const for compiler to find this
  template <class D, class B> 
    inline VJoinObj<D, Vector<D>,VWrapper<D,B> > 
    operator,(const Vector<D>& a, const VWrapper<D,B>& b)
    {
      printf2("  VJoinObj operator,(const Vector<D>& a, const VWrapper<D,B>& b)\n");
      Vector<D>& a_ = const_cast<Vector<D>& >(a);
      VWrapper<D,B>& b_ = const_cast<VWrapper<D,B>& >(b);
      return VJoinObj<D, Vector<D>,VWrapper<D,B> >(a_,b_);
    }
  //--------------------------------------------

  //--------------------------------------------
  // Need the const for compiler to find this
  template <class D, class A, class B> 
    inline VJoinObj<D, VWrapper<D,A>,VWrapper<D,B> > 
    operator,(const VWrapper<D,A>& a, const VWrapper<D,B>& b)
    {
      printf2("  VJoinObj operator,(const VWrapper<D,A>& a, const VWrapper<D,B>& b)\n");
      VWrapper<D,A>& a_ = const_cast<VWrapper<D,A>& >(a);
      VWrapper<D,B>& b_ = const_cast<VWrapper<D,B>& >(b);
      return  VJoinObj<D, VWrapper<D,A>,VWrapper<D,B> >(a_,b_);
    }
  //--------------------------------------------


  
  ///---------
  
  template <class D> 
    inline const VJoinExpr<D, Vector<D>,Vector<D> > 
    operator,(const Vector<D>& a, const Vector<D>& b)
    {
      printf2("  VJoinExpr operator,(const Vector<D>& a, const Vector<D>& b)\n");
      return  VJoinExpr<D,Vector<D>,Vector<D> >(a,b);
    }

  template <class D, class B> 
    inline const VJoinExpr<D, Vector<D>,Vexpr<D,B> > 
    operator,(const Vector<D>& a, const Vexpr<D,B>& b)
    {
      printf2("  VJoinExpr operator,(const Vector<D>& a, const Vexpr<D,B>& b)\n");
      return  VJoinExpr<D,Vector<D>,Vexpr<D,B>  >(a,b);
    }

  template <class D, class A> 
    inline const VJoinExpr<D,Vexpr<D,A>,Vector<D> > 
    operator,(const Vexpr<D,A>& a, const Vector<D>& b)
    {
      printf2("  VJoinExpr operator,(const Vexpr<D,A>& a, const Vector<D>& b)\n");
      return  VJoinExpr<D,Vexpr<D,A>,Vector<D> >(a,b);
    }
 
  template <class D, class A, class B> 
    inline const VJoinExpr<D, Vexpr<D,A>,Vexpr<D,B> > 
    operator,(const Vexpr<D,A>& a, const Vexpr<D,B>& b)
    {
      printf2("  VJoinExpr operator,(const Vexpr<D,A>& a, const Vexpr<D,B>& b)\n");
      return  VJoinExpr<D, Vexpr<D,A>,Vexpr<D,B> >(a,b);
    }



  



  // rep(v,m)

  template <class D, class A> 
    inline VRepExpr<D,VorE<D,A> >
    rep(const VorE<D,A>& a, const size_type m) {
    return VRepExpr<D,VorE<D,A> >(a,m);
  }

  
  


  // pow(vector,vector)

  template <class D, class A, class B> 
    inline VBinOp<D,VorE<D,A>,VorE<D,B>,ApPow<D> > 
    pow(const VorE<D,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<D,VorE<D,A>,VorE<D,B>,ApPow<D> >(a,b);
    }


  
  // atan2(vector,vector)

  template <class D, class A, class B> 
    inline VBinOp<D,VorE<D,A>,VorE<D,B>,ApAtan2<D> > 
    atan2(const VorE<D,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<D,VorE<D,A>,VorE<D,B>,ApAtan2<D> >(a,b);
    }



  template <class D, typename TypeHelper<D>::binary_func F, class A, class B> 
    inline VBinOp<D, VorE<D,A>, VorE<D,B>, ApFun2<D,F> > 
    op2(const VorE<D,A>& a, const VorE<D,B>& b)
    {
      return  VBinOp<D, VorE<D,A>, VorE<D,B>, ApFun2<D,F> >(a,b);
    }


  

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


  




  // a==b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApEqual<D> >  
    operator==( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApEqual<D> >(a,b);
  }


  // a!=b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApNotEqual<D> >  
    operator!=( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApNotEqual<D> >(a,b);
  }



  // a<=b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApLessEqual<D> >  
    operator<=( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApLessEqual<D> >(a,b);
  }


  // a>=b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApGreaterEqual<D> >  
    operator>=( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApGreaterEqual<D> >(a,b);
  }


  // a<b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApLess<D> >  
    operator<( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApLess<D> >(a,b);
  }


  // a>b

  template <class D, class A, class B> 
    inline VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApGreat<D> >  
    operator>( const VorE<D,A>& a, const  VorE<D,B>& b ) {
    return VBoolBinOp<D,VorE<D,A>,VorE<D,B>,ApGreat<D> >(a,b);
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




  template <class D, class A> 
    inline VecOpScal<D,VorE<D,A>,ApRoundZeros<D> > 
    roundzero(const VorE<D,A>& a, const D tolerance = MatricksHelper<D>::tolerance)
    {
      return  VecOpScal<D,VorE<D,A>,ApRoundZeros<D> >(a, tolerance);
    }



  // pow(vector,scalar)

  template <class D, class A> 
    inline VecOpScal<D,VorE<D,A>,ApPow<D> > 
    pow(const VorE<D,A>& a, const D b)
    {
      return  VecOpScal<D,VorE<D,A>,ApPow<D> >(a,b);
    }

  // pow(scalar,vector)

  template <class D, class B> 
    inline ScalOpVec<D,VorE<D,B>,ApPow<D> > 
    pow( const D a, const VorE<D,B>& b)
    {
      return  ScalOpVec<D,VorE<D,B>,ApPow<D> >(a,b);
    }



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



  
  // vector && scalar

  template <class A> 
    inline VecOpScal<bool,VorE<bool,A>,ApAnd > 
    operator&&(const VorE<bool,A>& a, const bool b)
    {
      return  VecOpScal<bool,VorE<bool,A>,ApAnd >(a,b);
    }

  // scalar && vector

  template <class B> 
    inline ScalOpVec<bool,VorE<bool,B>,ApAnd > 
    operator&&(const bool a, const VorE<bool,B>& b)
    {
      return  ScalOpVec<bool,VorE<bool,B>,ApAnd >(a,b);
    }

  
  // vector || scalar

  template <class A> 
    inline VecOpScal<bool,VorE<bool,A>,ApOr > 
    operator||(const VorE<bool,A>& a, const bool b)
    {
      return  VecOpScal<bool,VorE<bool,A>,ApOr >(a,b);
    }

  // scalar || vector

  template <class B> 
    inline ScalOpVec<bool,VorE<bool,B>,ApOr > 
    operator||(const bool a, const VorE<bool,B>& b)
    {
      return  ScalOpVec<bool,VorE<bool,B>,ApOr >(a,b);
    }



  // vector == scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApEqual<D> > 
    operator==(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApEqual<D> >(a,b);
    }

  // scalar == vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApEqual<D> > 
    operator==(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApEqual<D> >(a,b);
    }

  // vector != scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApNotEqual<D> > 
    operator!=(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApNotEqual<D> >(a,b);
    }

  // scalar != vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApNotEqual<D> > 
    operator!=(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApNotEqual<D> >(a,b);
    }
  // vector <= scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApLessEqual<D> > 
    operator<=(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApLessEqual<D> >(a,b);
    }

  // scalar <= vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApLessEqual<D> > 
    operator<=(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApLessEqual<D> >(a,b);
    }
  // vector >= scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApGreaterEqual<D> > 
    operator>=(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApGreaterEqual<D> >(a,b);
    }

  // scalar >= vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApGreaterEqual<D> > 
    operator>=(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApGreaterEqual<D> >(a,b);
    }
  // vector < scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApLess<D> > 
    operator<(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApLess<D> >(a,b);
    }

  // scalar < vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApLess<D> > 
    operator<(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApLess<D> >(a,b);
    }
  // vector > scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApGreat<D> > 
    operator>(const VorE<D,A>& a, const D b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApGreat<D> >(a,b);
    }

  // scalar > vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApGreat<D> > 
    operator>(const D a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApGreat<D> >(a,b);
    }



  // the following are defined for convenience

  // vector == int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApEqual<D> > 
    operator==(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApEqual<D> >(a,static_cast<D>(b));
    }

  // int scalar == vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApEqual<D> > 
    operator==(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApEqual<D> >(static_cast<D>(a),b);
    }

  // vector != int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApNotEqual<D> > 
    operator!=(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApNotEqual<D> >(a,static_cast<D>(b));
    }

  // int scalar != vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApNotEqual<D> > 
    operator!=(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApNotEqual<D> >(static_cast<D>(a),b);
    }
  // vector <= int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApLessEqual<D> > 
    operator<=(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApLessEqual<D> >(a,static_cast<D>(b));
    }

  // int scalar <= vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApLessEqual<D> > 
    operator<=(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApLessEqual<D> >(static_cast<D>(a),b);
    }
  // vector >= int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApGreaterEqual<D> > 
    operator>=(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApGreaterEqual<D> >(a,static_cast<D>(b));
    }

  // int scalar >= vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApGreaterEqual<D> > 
    operator>=(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApGreaterEqual<D> >(static_cast<D>(a),b);
    }
  // vector < int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApLess<D> > 
    operator<(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApLess<D> >(a,static_cast<D>(b));
    }

  // int scalar < vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApLess<D> > 
    operator<(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApLess<D> >(static_cast<D>(a),b);
    }
  // vector > int scalar

  template <class D, class A> 
    inline BoolVecOpScal<D,VorE<D,A>,ApGreat<D> > 
    operator>(const VorE<D,A>& a, const int b)
    {
      return  BoolVecOpScal<D,VorE<D,A>,ApGreat<D> >(a,static_cast<D>(b));
    }

  // int scalar > vector

  template <class D, class B> 
    inline BoolScalOpVec<D,VorE<D,B>,ApGreat<D> > 
    operator>(const int a, const VorE<D,B>& b)
    {
      return  BoolScalOpVec<D,VorE<D,B>,ApGreat<D> >(static_cast<D>(a),b);
    }

  // vector && vector

  template <class A, class B> 
    inline VBinOp<bool,VorE<bool,A>,VorE<bool,B>,ApAnd > 
    operator&&(const VorE<bool,A>& a, const VorE<bool,B>& b)
    {
      return  VBinOp<bool,VorE<bool,A>,VorE<bool,B>,ApAnd >(a,b);
    }

  // vector || vector

  template <class A, class B> 
    inline VBinOp<bool,VorE<bool,A>,VorE<bool,B>,ApOr > 
    operator||(const VorE<bool,A>& a, const VorE<bool,B>& b)
    {
      return  VBinOp<bool,VorE<bool,A>,VorE<bool,B>,ApOr >(a,b);
    }


  /****************************************************************
   *              Unary Operators & Unary Functions
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



  // !(vector)

  template <class A> 
    inline VFuncOp<bool,VorE<bool,A>,ApNot > 
    operator!(const VorE<bool,A>& a)
    {
      return  VFuncOp<bool,VorE<bool,A>,ApNot >(a);
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
#if MATRICKS_DEBUG>0
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

    for(index_type i = 0; i<N; i++) 
      y[i] = static_cast<D2>(a(i));
    return y;
  }



  // vcast(C-array)

  template <class D2, class D1> 
    inline Vector<D2>
    vcast(const D1* dptr, const size_type N)
  {
    Vector<D2> y(N,"vcast(C-array)");
    for(index_type i = 0; i<N; i++) 
      y[i] = static_cast<D2>(dptr[i]);
    return  y;
  }

  

  // vcast(std::vector)

  template <class D2, class D1> 
    inline Vector<D2>
    vcast(const std::vector<D1>& v2) {
    const size_type N = v2.size();
    Vector<D2> y(N,"vcast(std::vector)");
    for(index_type i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v2[i]);
    return  y;
  }


  // vcast(std::valarray)

  template <class D2, class D1> 
    inline Vector<D2>
    vcast(const std::valarray<D1>& v2) {
    const size_type N = v2.size();
    Vector<D2> y(N,"vcast(std::valarray)");
    for(index_type i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v2[i]);
    return  y;
  }

  // user-defined functions
  template <class D, typename TypeHelper<D>::unary_func F, class A> 
    inline VFuncOp<D, VorE<D,A>, ApFun1<D,F> > 
    op1(const VorE<D,A>& a)
    {
      return  VFuncOp<D, VorE<D,A>, ApFun1<D,F> >(a);
    }


  // sin(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApSin<D> > 
    sin(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApSin<D> >(a);
    }


  // cos(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApCos<D> > 
    cos(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApCos<D> >(a);
    }



  // tan(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApTan<D> > 
    tan(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApTan<D> >(a);
    }


  // sqrt(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApSqrt<D> > 
    sqrt(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApSqrt<D> >(a);
    }

  // sqr(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApSqr<D> > 
    sqr(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApSqr<D> >(a);
    }

  // cube(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApCube<D> > 
    cube(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApCube<D> >(a);
    }


  // exp(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApExp<D> > 
    exp(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApExp<D> >(a);
    }


  // abs(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApAbs<D> > 
    abs(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApAbs<D> >(a);
    }


  // sgn(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApSign<D> > 
    sgn(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApSign<D> >(a);
    }


  // log(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApLog<D> > 
    log(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApLog<D> >(a);
    }


  // log10(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApLog10<D> > 
    log10(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApLog10<D> >(a);
    }


  // log2(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApLog2<D> > 
    log2(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApLog2<D> >(a);
    }



  // asin(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApAsin<D> > 
    asin(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApAsin<D> >(a);
    }


  // acos(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApAcos<D> > 
    acos(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApAcos<D> >(a);
    }


  // atan(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApAtan<D> > 
    atan(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApAtan<D> >(a);
    }





  // ceil(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApCeil<D> > 
    ceil(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApCeil<D> >(a);
    }


  // floor(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApFloor<D> > 
    floor(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApFloor<D> >(a);
    }


  // round(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApRound<D> > 
    round(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApRound<D> >(a);
    }


  // sinh(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApSinh<D> > 
    sinh(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApSinh<D> >(a);
    }


  // cosh(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApCosh<D> > 
    cosh(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApCosh<D> >(a);
    }


  // tanh(vector)

  template <class D, class A> 
    inline VFuncOp<D,VorE<D,A>,ApTanh<D> > 
    tanh(const VorE<D,A>& a)
    {
      return  VFuncOp<D,VorE<D,A>,ApTanh<D> >(a);
    }


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
    inline VFuncOp<std::complex<D>, VorE<std::complex<D>, A> , ApRoundCplx<D> > 
    round(const VorE<std::complex<D>,A>& a)  {
    return VFuncOp<std::complex<D>, VorE<std::complex<D>, A>, ApRoundCplx<D> >(a);
  }



  /****************************************************************
   * calculus related
   *****************************************************************
   */

  
  // reverse

  template <class D, class A>
    inline Vector<D>& reverse(const VorE<D,A>& f) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->reverse();
    return *g;
  }


  // cumsum() -- cumulative sum

  template <class D, class A>
    inline Vector<D>& cumsum(const VorE<D,A>& f) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->cumsum();
    return *g;
  }
  
  // cumprod()  --  cumulative product
  
  template <class D, class A>
    inline Vector<D>& cumprod(const VorE<D,A>& f) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->cumprod();
    return *g;
  }


  // cumtrapz() -- cumulative trapezoidal summation
  
  template <class D, class A>
    inline Vector<D>& cumtrapz(const VorE<D,A>& f) {
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
    inline Vector<D>& integrate_a2x(const VorE<D,A>& f, const D a, const D b, const int order=1) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->integrate_a2x(a,b,order);
    return *g;
  }


  // cumsumrev() -- cumulative sum -- from last to first

  template <class D, class A>
    inline Vector<D>& cumsum_rev(const VorE<D,A>& f) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->cumsum_rev();
    return *g;
  }

    // cumprodrev()  --  cumulative product  -- from last to first

  template <class D, class A>
    inline Vector<D>& cumprod_rev(const VorE<D,A>& f) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->cumprod_rev();
    return *g;
  }


    // cumtrapz() -- cumulative trapezoidal summation -- from last to first

  template <class D, class A>
    inline Vector<D>& cumtrapz_rev(const VorE<D,A>& f) {
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
    inline Vector<D>& integrate_x2b(const VorE<D,A>& f, const D a, const D b, const int order=1) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->integrate_x2b(a,b,order);
    return *g;
  }



  // diff   (v[n] = v[n] - v[n-1])
  template <class D, class A>
    inline Vector<D>& diff(const VorE<D,A>& f, const bool periodic=false) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->diff(periodic);
    return *g;
  }

  // diff_rev   (v[n] = v[n+1] - v[n])
  template <class D, class A>
    inline Vector<D>& diff_rev(const VorE<D,A>& f, const bool periodic=false) {
    Vector<D> *g = new Vector<D>(f.size());
    *g = f;
    g->diff_rev(periodic);
    return *g;
  }


  // derivative
  // any change in the default parameters must be likewise made in Vector.deriv(...)
  
  template <class D, class A>
    inline Vector<D>& deriv(const VorE<D,A>& f, const D a, const D b, const int n=1, int Dpts=7, const bool periodic=false) {
    Vector<D> *df = new Vector<D>(f.size());
    *df = f;
    df->deriv(a,b,n,Dpts,periodic);
    return *df;
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
    for(index_type i = 0; i<N; i++) 
      dptr[i] = static_cast<D2>(v[i]);
    return  dptr;
  }

  

  // tostdvector(v)

  template <class D2, class D1, class A> 
    inline std::vector<D2>
    tostdvector(const VorE<D1,A>& v) {
    const size_type N = v.size();
    std::vector<D2> y(N);
    for(index_type i = 0; i<N; i++) 
      y[i] = static_cast<D2>(v[i]);
    return y;
  }



  // tovalarray(v)

  template <class D2, class D1, class A> 
    inline std::valarray<D2>
    tovalarray(const VorE<D1,A>& v) {
    const size_type N = v.size();
    std::valarray<D2> y(N);
    for(index_type i = 0; i<N; i++) 
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
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) || vexpr_is_size_bad(b) || ( a.size() != b.size() ) ){ 
      vbad_expr_in_binary(a,b,"","|");
      return 0;
    }
#endif
 
    for (register index_type i = a.size(); i--;)
      result += a[i]*b[i];
    
    return result;
  }


  // dotproduct operator (areal|bcomplex)

  template <class D, class A, class B> 
    inline std::complex<D>  operator|( const VorE<D,A>& a, const  VorE<std::complex<D>,B>& b ) {
    std::complex<D> result = std::complex<D>();
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) || vexpr_is_size_bad(b) || ( a.size() != b.size() ) ){ 
      vbad_expr_in_binary(a,b,"","|");
      return 0;
    }
#endif
 
    for (register index_type i = a.size(); i--;)
      result += a[i]*b[i];
    
    return result;
  }


  // dotproduct operator (acomplex|breal)

  template <class D, class A, class B> 
    inline std::complex<D>  operator|( const VorE<std::complex<D>,A>& a, const  VorE<D,B>& b ) {
    std::complex<D> result = std::complex<D>();
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) || vexpr_is_size_bad(b) || ( a.size() != b.size() ) ){ 
      vbad_expr_in_binary(a,b,"","|");
      return 0;
    }
#endif
 
    for (register index_type i = a.size(); i--;)
      result += a[i]*b[i];
    
    return result;
  }





  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */

  // sum(a)

  template <class D, class A> 
    D sum( const VorE<D,A>& a ) {
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"sum");
      return 0;
    }
#endif
 
    const size_type N = a.size();
    if (N==0)
      return 0;

    D result = a[0];

    for (register index_type i = 1; i < N ; i++ )
      result += a[i];
    
    return result;
  }


  // integrate_a2b(a)
  // order  name
  //     0  rectangular
  //     1  trapazoidal
  //     2  simpson
  //     3  simpson 3/8
  //     4  Boole
  
  template <class D, class A> 
    D integrate_a2b( const VorE<D,A>& v, const D a, const D b, const int order=1 ) {
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(v) ) {
      vbad_expr_in_unary(v,"integrate_a2b");
      return 0;
    }
    if (b<a)  {
      std::cerr << "integrate_a2b: bad limit end points a="<<a<<", b="<<b<<std::endl;
      return 0;
    }
    
#endif
 
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

  
  // prod(a)

  template <class D, class A> 
    D prod( const VorE<D,A>& a ) {
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"prod");
      return 0;
    }
#endif
 
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
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"norm");
      return 0;
    }
#endif
 
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
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"min");
      return 0;
    }
#endif
 
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
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"max");
      return 0;
    }
#endif
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
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"norm");
      return 0;
    }
#endif
 
    for (register index_type i = a.size(); i--;) {
      D tempR = a[i].real(); 
      D tempI = a[i].imag(); 
      result += tempR*tempR + tempI*tempI;
    }
    return std::sqrt(result);
  }



  /************************************************************
   *               Templates for Binary+scalar Operators 
   *
   * D = data type, e.g. double
   * A = either an Vector or a Vexpr
   * B = either an Vector or a Vexpr
   * N = int
   ************************************************************
   */



  // maclaurin(vector coefs, vector vals, max N)

  template <class D, class A, class X> 
    inline VSeriesOp<D, VorE<D,A>, VorE<D,X> > 
    maclaurin(const VorE<D,A>& a, const VorE<D,X>& x, const int N, const D x0)
    {
      return  VSeriesOp<D, VorE<D,A>, VorE<D,X> >(a,x,N,x0);
    }
  
  // taylor(vector coefs, vector vals, max N)

  template <class D, class A, class X> 
    inline VSeriesOp<D, VorE<D,A>, VorE<D,X> > 
    taylor(const VorE<D,A>& a, const VorE<D,X>& x, const int N)
    {
      return  VSeriesOp<D, VorE<D,A>, VorE<D,X> >(a,x,N);
    }

  // ifourier(vector cos coefs, vector sin coefs, vector vals, max N, k1=2pi/wavelength or 2pi/period)
  // sin coefs must include a coef for n=0 even though its irrelevant

  template <class D, class A, class B, class X> 
    inline  VSeriesOp2<D, VorE<D,A>, VorE<D,B>, VorE<D,X>, ApCos<D>, ApSin<D> >
    ifourier(const VorE<D,A>& Acos, const VorE<D,B>& Bsin, const VorE<D,X>& x, const int N, const D k1)
    {
      return  VSeriesOp2<D, VorE<D,A>, VorE<D,B>, VorE<D,X>, ApCos<D>, ApSin<D> >(Acos,Bsin,x,N,k1);
    }












  /****************************************************************************
   * Unary Functions/Operators that bools or index_type vectors
   ****************************************************************************
   */


  
  // alltrue(a)

  template <class A> 
    inline bool alltrue( const VorE<bool,A>& a ) {
    bool result = true;
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"alltrue");
      return false;
    }
#endif
 
    for (register index_type i = 0; i< a.size(); i++)
      result = result && a[i];
    
    return result;
  }


  // anytrue(a)

  template <class A> 
    inline bool anytrue( const VorE<bool,A>& a ) {
    bool result = false;
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"anytrue");
      return false;
    }
#endif
 
    for (register index_type i = 0; i< a.size(); i++)
      result = result || a[i];
    
    return result;
  }


  // numtrue(a)

  template <class A> 
    inline size_type numtrue( const VorE<bool,A>& a ) {
    size_type result = 0;
    
#if MATRICKS_DEBUG>0
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"numtrue");
      return 0;
    }
#endif
 
    for (register index_type i = 0; i< a.size(); i++)
      result += static_cast<index_type>(a[i]);
    
    return result;
  }


  


  // findtrue(a)

  template <class A> 
    inline Vector<index_type> findtrue( const VorE<bool,A>& a ) {
    int N = 0;
    
#if MATRICKS_DEBUG>0
    std::string s = "findtrue(" + a.debugtxt() + ")";
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"findtrue");
      //      Vector<index_type> y(0,s);
      Vector<index_type> y(0);
      return y;
    }
#endif

    for (register index_type i = 0; i< a.size(); i++)
      N += int(a[i]);
 
#if MATRICKS_DEBUG>0
    //   Vector<index_type> y(N,s);
    Vector<index_type> y(N);
#else
    Vector<index_type> y(N);
#endif

    index_type j =0;
    for (register index_type i = 0; i< a.size(); i++)
      if (a[i])
	y[j++] = i;
    
    return y;
  }







};

#endif 
