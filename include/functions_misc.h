#ifndef MATHQ__FUNCTIONS_MISC_H
#define MATHQ__FUNCTIONS_MISC_H 1


namespace mathq {

  /****************************************************************************
   * casting
   ****************************************************************************
   */
  
  // ----------------------------------------------------------------
  // FUNCTOR_numbercast
  // ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_numbercast {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return numbercast<DOUT>(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = numbercast<DOUT>(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";
    DOUT d;
    sout = functor_style.apply("numbercast")+display::getBracketedTypeName(d)+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_numbercast")+display::getBracketedTypeName(e); 
  }									
};


  //----------------------------------------------
  // numbercast 
  //----------------------------------------------
  
  template <class D2, class X, class E, class D, int M, int R>			
  auto numbercast(const TensorR<X,E,D,M,R>& x) {		
    typedef typename NumberType<E,D2>::ReplaceTypeE EOUT;		
    return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D2,M,R, FUNCTOR_numbercast<E,EOUT,D,D2>>(x); 
  }
  

    /****************************************************************************
   * Equality related
   ****************************************************************************
   */


// ----------------------------------------------------------------
// FUNCTOR_roundzero
// ----------------------------------------------------------------

  
  template <class E, class D> class FUNCTOR_roundzero {
  public:								
    typedef typename FundamentalType<D>::Type DTOL;
    static D apply(const D d, const DTOL tol) {
      return mathq::roundzero(d,tol);
    }									
    template <class T=E>						
    static typename std::enable_if<!std::is_same<T,D>::value, E& >::type 
    apply(const E& e, const DTOL tol) {
      E *e2 = new E();							
      *e2 = roundzero(e,tol);
      return *e2;								
    }									
    static std::string expression(const std::string& sa, const std::string& sb) {	
      using namespace display;						
      std::string sout = "";						
      sout = sa +" + "+ sb;					
      return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    D d;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_roundzero)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e);
    s += comma + getTypeName(d);
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};

  // -------------------------------------------------------------------
  // roundzero 
  //         
  // -------------------------------------------------------------------
  template <class X, class E, class D, int M, int R> 
  auto roundzero(const TensorR<X,E,D,M,R>& x, const typename FundamentalType<D>::Type& tol = Helper<typename FundamentalType<D>::Type>::tolerance)  {

    typedef typename FundamentalType<D>::Type DTOL;
    return  TER_Binary<TensorR<X,E,D,M,R>,
		       DTOL,
		       E,DTOL,E,D,DTOL,D,M,0,M,R,0,R,
		       FUNCTOR_roundzero<E,D>>(x,tol); 
  } 



  
  // -------------------------------------------------------------------
  // equal - if two tensors are equal. returns a single bool
  //         checks dimensions first
  // -------------------------------------------------------------------
  template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
  bool equal(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2)  {
    if (!dimequiv(x1,x2)) {
      return false;
    }
    return alltrue(x1==x2);
  }


  // ----------------------------------------------------------------
// FUNCTOR_approx: template class for function 'mathq::approx'
//
//    Note: generated from template file 'fun_ternary_functor.hpp'
//          using Python script 'fun_ternary.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_approx { 
public:								
  typedef typename FundamentalType<typename AddType<D1,D2>::Type>::Type DTOL;
  
  static D3 apply(const D1 d1, const D2 d2, const DTOL tol) {
    return mathq::approx(d1, d2, tol);
  }
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2, const DTOL tol) {					
    E3 *e3 = new E3();							
    *e3 = mathq::approx(e1 , e2, tol);
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2, const DTOL tol) {					
    E3 *e3 = new E3();							
    *e3 = mathq::approx(e1 , d2, tol);
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2, const DTOL tol) {					
    E3 *e3 = new E3();							
    *e3 = mathq::approx(d1 , e2, tol);
    return *e3;								
  }									
  
  static std::string expression(const std::string& sa, const std::string& sb, const std::string& sc) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" , "+ sb +" , "+ sc;	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;
    D1 d1;								
    D2 d2;								
    D3 d3;
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_approx)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};

// ----------------------------------------------------------------
// approx
// template functions for 'approx'
//
// ----------------------------------------------------------------


// TODO: runtime check that deep dimensions of E1 and E2 and E3 are the same

  

// (11) Tensor<E1(D1)> , Tensor<E2(D2)> 

  template <class A, class B, class E1, class E2, class D1, class D2, int M, int R>
  auto approx(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2, const typename FundamentalType<typename AddType<D1,D2>::Type>::Type& tol = Helper<typename FundamentalType<typename AddType<D1,D2>::Type>::Type>::tolerance) {

    typedef typename FundamentalType<typename AddType<D1,D2>::Type>::Type DTOL;
    typedef bool D3;
    typedef typename NumberType<E1,D3>::ReplaceTypeE E3;
    return  TER_Ternary<TensorR<A,E1,D1,M,R>,
			TensorR<B,E2,D2,M,R>,
			DTOL,
			E1,E2,DTOL,E3, D1,D2,DTOL,D3, M,M,0,M, R,R,0,R,
			FUNCTOR_approx<E1,E2,E3, D1,D2,D3> >(x1,x2,tol); 
}

// (10) Tensor<E1(D1)> , D2 

  template <class A, class E1, class D1, class D2, int M, int R>
  auto approx(const TensorR<A,E1,D1,M,R>& x1, const D2& x2, const typename FundamentalType<typename AddType<D1,D2>::Type>::Type& tol = Helper<typename FundamentalType<typename AddType<D1,D2>::Type>::Type>::tolerance) {

    typedef typename FundamentalType<typename AddType<D1,D2>::Type>::Type DTOL;
    typedef bool D3;
    typedef typename NumberType<E1,D3>::ReplaceTypeE E3;  
    return  TER_Ternary<TensorR<A,E1,D1,M,R>,
			D2,
			DTOL,
			E1,D2,DTOL,E3, D1,D2,DTOL,D3, M,0,0,M, R,0,0,R,
			FUNCTOR_approx<E1,D2,E3, D1,D2,D3> >(x1,x2,tol); 
}



// (01) D1, Tensor<E2(D2)> 

  template <class B, class E2, class D1, class D2, int M, int R>
  auto approx(D1& x1, const TensorR<B,E2,D2,M,R>& x2, const typename FundamentalType<typename AddType<D1,D2>::Type>::Type& tol = Helper<typename FundamentalType<typename AddType<D1,D2>::Type>::Type>::tolerance) {

    typedef typename FundamentalType<typename AddType<D1,D2>::Type>::Type DTOL;
    typedef bool D3;
    typedef typename NumberType<E2,D3>::ReplaceTypeE E3;  
    return  TER_Ternary<D1,
			TensorR<B,E2,D2,M,R>,
			DTOL,
			D1,E2,DTOL,E3, D1,D2,DTOL,D3, 0,M,0,M, 0,R,0,R,
			FUNCTOR_approx<D1,E2,E3, D1,D2,D3> >(x1,x2,tol); 
}



  // -------------------------------------------------------------------
  // equal_approx - if two tensors are approximately equal, returns a single bool
  //          checks dimensions first
  // -------------------------------------------------------------------
  template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
  bool equal_approx(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2, const  typename FundamentalType<typename AddType<D1,D2>::Type>::Type tol = Helper< typename FundamentalType<typename AddType<D1,D2>::Type>::Type>::tolerance)  {
    
    if (!dimequiv(x1,x2)) {
      return false;
    }
    return alltrue(approx(x1,x2,tol));
  }



  /****************************************************************************
   * Unary Functions/Operators that bools or index_type Tensors
   ****************************************************************************
   */


  
  // alltrue(a)

  template <class X, class E, class D, int M, int R,  typename = EnableIf<std::is_same<D,bool>::value> > 
    bool alltrue( const TensorR<X,E,D,M,R>& x ) {

    for (index_type i = 0; i< x.deepsize(); i++) {
      if (!x.dat(i)) {
	return false;
      }
    }
    
    return true;
  }


  // anytrue(a)

  template <class X, class E, class D, int M, int R,  typename = EnableIf<std::is_same<D,bool>::value> > 
    bool anytrue( const TensorR<X,E,D,M,R>& x ) {

    for (index_type i = 0; i< x.deepsize(); i++) {
      if (x.dat(i)) {
	return true;
      }
    }
    
    return false;
  }


  // numtrue(a)

  template <class X, class E, class D, int M, int R,  typename = EnableIf<std::is_same<D,bool>::value> > 
    index_type numtrue( const TensorR<X,E,D,M,R>& x ) {

    index_type result = 0;
 
    for (index_type i = 0; i< x.deepsize(); i++) {
      result += static_cast<index_type>(x.dat(i));
    }
    
    return result;
  }


  


  // findtrue(a) - deep indexing

  // NOTE: declaration in preface.h

  template <class X, class E, class D, int M, int R> 
  EnableMethodIf<std::is_same<D,bool>::value,Vector<index_type>&>
  findtrue( const TensorR<X,E,D,M,R>& x ) {
    index_type N = numtrue(x);
    Vector<index_type> *y = new Vector<index_type>(N);

    index_type j =0;
    for (index_type i = 0; i< x.deepsize(); i++)
      if (x.dat(i))
	(*y)[j++] = i;
    
    return *y;
  }


  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */

  // sum(a)

  template <class X, class E, class D, int M, int R > 
    E sum( const TensorR<X,E,D,M,R>& v ) {
    
 
    const size_type N = v.size();
    if (N==0)
      return 0;

    E result = v[0];

    for (index_type i = 1; i < N ; i++ ) {
      result += v[i];
    }
    
    return result;
  }



  
  // prod(a)

  template <class X, class E, class D, int M, int R > 
    E prod( const TensorR<X,E,D,M,R>& v ) {
    
 
    const size_type N = v.size();
    if (N==0)
      return 0;

    E result = v[0];

    for (index_type i = 1; i < N ; i++ ) {
      result *= v[i];
    }
    
    return result;
  }









  // min(a)

  template <class X, class E, class D, int M, int R>
    D min( const TensorR<X,E,D,M,R>& v ) {
    
    const size_type N = v.deepsize();
    if (N==0) {
      return 0;
    }
    
    D result = v.dat(0);

    for (index_type i = 1; i < N ; i++ ) {
      result = std::min(result,v.dat(i));
    }
    
    return result;
  }




  // max(a)

  template <class X, class E, class D, int M, int R>
    D max( const TensorR<X,E,D,M,R>& v ) {
    
    const size_type N = v.deepsize();
    if (N==0) {
      return 0;
    }
    
    D result = v.dat(0);

    for (index_type i = 1; i < N ; i++ ) {
      result = std::max(result,v.dat(i));
    }
    
    return result;
  }

  // sumofsqrs(a)

  template <class X, class E, class D, int M, int R>
    D sumofsqrs( const TensorR<X,E,D,M,R>& v ) {
    D result = D();
    for (index_type i = 0; i < v.size(); i++)  {
      result += normsqr(v[i]);
    }
    return result;
  }

  // norm(a)  - L2 norm

  template <class X, class E, class D, int M, int R>
    D norm( const TensorR<X,E,D,M,R>& v ) {
    return std::sqrt( sumofsqrs(v) );
  }



  // *********************************************************
  // *          Functions that create vectors
  // *********************************************************

  // The Range generating function (with step given)

  template <class D>
    Vector<D>& range(D start, D end, D step) {
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
    Vector<D>& range(D start, D end) {
    if (end >= start)
      return range<D>(start,end,static_cast<D>(1));
    else 
      return range<D>(start,end,static_cast<D>(-1));
  }





  // linspace function [a,b]

  template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
    Vector<D>& linspace(D start, D end, size_type N) {
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
    Vector<D>& linspace_a(D start, D end, size_type N) {
    Vector<D> *y = new Vector<D>(N);

  
    const D step = (end-start)/static_cast<D>(N);
    return linspace(start+step, end, N);
  }


  // linspace_b function [a,b)
  // Returns a vector of N equispaced points,
  // with spacing delta, spanning from a to b-delta

  template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
    Vector<D>& linspace_b(D start, D end, size_type N) {
    Vector<D> *y = new Vector<D>(N);

  
    const D step = (end-start)/static_cast<D>(N);
    return linspace(start, end-step, N);
  }

  // linspace_ab function (a,b)
  // Returns a vector of N equispaced points,
  // with spacing delta, spanning from a+delta to b-delta

  template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
    Vector<D>& linspace_ab(D start, D end, size_type N) {
    Vector<D> *y = new Vector<D>(N);

  
    const D step = (end-start)/static_cast<D>(N+1);
    return linspace(start+step, end-step, N);
  }



  // *********************************************************
  // *          Functions that return a vector from a vector
  // *********************************************************
  
  
  // reverse
  
  template <class X, class E, class D, int M, int R> 
  EnableMethodIf<R==1,Vector<E>&> reverse(const TensorR<X,E,D,M,R>& f) {
    Vector<E> *g = new Vector<E>(f.size());
    *g = f;
    g->reverse();
    return *g;
  }


  // cumsum() -- cumulative sum

  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1,Vector<E>&> cumsum(const TensorR<X,E,D,M,R>& f) {
    Vector<E> *g = new Vector<E>(f.size());
    *g = f;
    g->cumsum();
    return *g;
  }
  
  // cumprod()  --  cumulative product
  
  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1,Vector<E>&> cumprod(const TensorR<X,E,D,M,R>& f) {
    Vector<E> *g = new Vector<E>(f.size());
    *g = f;
    g->cumprod();
    return *g;
  }


  // cumtrapz() -- cumulative trapezoidal summation
  
  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1,Vector<E>&> cumtrapz(const TensorR<X,E,D,M,R>& f) {
    Vector<E> *g = new Vector<E>(f.size());
    *g = f;
    g->cumtrapz();
    return *g;
  }

  // integrate_a2x(order)
  // order  name
  //     0  rectangular
  //     1  trapazoidal
  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1,Vector<E>&> integrate_a2x(const TensorR<X,E,D,M,R>& f, const D a, const D b, const int order=1) {
    Vector<E> *g = new Vector<E>(f.size());
    *g = f;
    g->integrate_a2x(a,b,order);
    return *g;
  }


  // cumsumrev() -- cumulative sum -- from last to first

  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1,Vector<E>&> cumsum_rev(const TensorR<X,E,D,M,R>& f) {
    Vector<E> *g = new Vector<E>(f.size());
    *g = f;
    g->cumsum_rev();
    return *g;
  }

  // cumprodrev()  --  cumulative product  -- from last to first

  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1,Vector<E>&> cumprod_rev(const TensorR<X,E,D,M,R>& f) {
    Vector<E> *g = new Vector<E>(f.size());
    *g = f;
    g->cumprod_rev();
    return *g;
  }


  // cumtrapz() -- cumulative trapezoidal summation -- from last to first

  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1,Vector<E>&> cumtrapz_rev(const TensorR<X,E,D,M,R>& f) {
    Vector<E> *g = new Vector<E>(f.size());
    *g = f;
    g->cumtrapz_rev();
    return *g;
  }



  // integrate_x2b
  // order  name
  //     0  rectangular
  //     1  trapazoidal
  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1,Vector<E>&> integrate_x2b(const TensorR<X,E,D,M,R>& f, const D a, const D b, const int order=1) {
    Vector<E> *g = new Vector<E>(f.size());
    *g = f;
    g->integrate_x2b(a,b,order);
    return *g;
  }



  // diff   (v[n] = v[n] - v[n-1])
  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1,Vector<E>&>  diff(const TensorR<X,E,D,M,R>& f, const bool periodic=false) {
    Vector<E> *g = new Vector<E>(f.size());
    *g = f;
    g->diff(periodic);
    return *g;
  }

  // diff_rev   (v[n] = v[n+1] - v[n])
  template <class X, class E, class D, int M, int R>
    EnableMethodIf<R==1,Vector<E>&>  diff_rev(const TensorR<X,E,D,M,R>& f, const bool periodic=false) {
    Vector<E> *g = new Vector<E>(f.size());
    *g = f;
    g->diff_rev(periodic);
    return *g;
  }


  // derivative
  // any change in the default parameters must be likewise made in Vector.deriv(...)
  
  template <class X, class E, class D, int M, int R>
  EnableMethodIf<R==1,Vector<E>&>  deriv(const TensorR<X,E,D,M,R>& f, const D a, const D b, const int n=1, int Dpts=7, const bool periodic=false) {
    //    mdisp(a,b,n,Dpts,periodic,f.size());
    Vector<E> *df = new Vector<E>(f.size());
    //    tdisp(*df);
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
  
  template <class X, class E, class D, int M, int R>
  EnableMethodIf<(M==1)&&(R==1),D> integrate_a2b( const TensorR<X,E,D,M,R>& v, const D a, const D b, const int order=1 ) {
    
 
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
      for (index_type j = 0; j < N ; j++ ) {
	result += v[j];
      }
      result = result * (b-a)/D(N);
      break;
    case 1:
      result += (v[0]+v[N-1])/2;
      for (index_type j = 1; j < N-1 ; j++ ) {
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
	for (index_type j = 1; j < N-1 ; j++ ) {
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
	for (index_type j = 1; j < N-1 ; j++ ) {
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
	for (index_type j = 1; j < N-1 ; j++ ) {
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
#if MATHQ_DEBUG>0
      std::cerr << "integrate_a2b: bad order parameter order="<<order<<std::endl;   
#endif
      break;
    }

    return result;
  }



  // *********************************************************
  // *          Series
  // *********************************************************


  // maclaurin(vector coefs, vector vals, max N, x0)

  template <class A, class X, class E, class D, int M1, int M2, int R1, int R2, typename = EnableIf<(M1==1)&&(R1==1)>> 
    auto maclaurin(const TensorR<A,D,D,M1,R1>& a, const TensorR<X,E,D,M2,R2>& x, const int N, const D x0)
  {
    return TER_Series<TensorR<A,D,D,M1,R1>,TensorR<X,E,D,M2,R2>,E,D,M2,R2>(a,x,N,x0);
  }
  
  // // taylor(vector coefs, vector vals, max N)

  template <class A, class X, class E, class D, int M1, int M2, int R1, int R2, typename = EnableIf<(M1==1)&&(R1==1)>> 
    auto taylor(const TensorR<A,D,D,M1,R1>& a, const TensorR<X,E,D,M2,R2>& x, const int N)
  {
    return TER_Series<TensorR<A,D,D,M1,R1>,TensorR<X,E,D,M2,R2>,E,D,M2,R2>(a,x,N);
  }

  // // ifourier(vector cos coefs, vector sin coefs, vector vals, max N, k1=2pi/wavelength or 2pi/period)
  // // sin coefs must include a coef for n=0 even though its irrelevant

  template <class A, class B, class X, class D, int M, int R , typename = EnableIf<(M==1)&&(R==1)> > 
    auto ifourier(const TensorR<A,D,D,M,R>& Acos, const TensorR<B,D,D,M,R>& Bsin, const TensorR<X,D,D,M,R>& x, const int N, const D k1)
  {
    return  TER_Series2<TensorR<A,D,D,M,R>, TensorR<B,D,D,M,R>, TensorR<X,D,D,M,R>, D, FUNCTOR_cos<D,D,D,D>, FUNCTOR_sin<D,D,D,D> >(Acos,Bsin,x,N,k1);
  }




  

};

#endif 
