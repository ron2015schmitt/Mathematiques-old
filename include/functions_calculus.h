#ifndef MATRICKS__FUNCTIONS_CALCULUS_H
#define MATRICKS__FUNCTIONS_CALCULUS_H 1


namespace matricks {



  /****************************************************************
   * calculus related
   *****************************************************************
   */

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
    mdisp(a,b,n,Dpts,periodic,f.size());
    Vector<D> *df = new Vector<D>(f.size());
    tdisp(*df);
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
    inline auto maclaurin(const TensorR<D,A>& a, const TensorR<D,X>& x, const int N, const D x0)
  {
    return  TER_Series<D, TensorR<D,A>, TensorR<D,X> >(a,x,N,x0);
  }
  
  // taylor(vector coefs, vector vals, max N)

  template <class D, class A, class X> 
    inline auto taylor(const TensorR<D,A>& a, const TensorR<D,X>& x, const int N)
  {
    return  TER_Series<D, TensorR<D,A>, TensorR<D,X> >(a,x,N);
  }

  // ifourier(vector cos coefs, vector sin coefs, vector vals, max N, k1=2pi/wavelength or 2pi/period)
  // sin coefs must include a coef for n=0 even though its irrelevant

  template <class D, class A, class B, class X> 
    inline auto ifourier(const TensorR<D,A>& Acos, const TensorR<D,B>& Bsin, const TensorR<D,X>& x, const int N, const D k1)
  {
    return  TER_Series2<D, TensorR<D,A>, TensorR<D,B>, TensorR<D,X>, Fun_Cos<D>, Fun_Sin<D> >(Acos,Bsin,x,N,k1);
  }




  

};

#endif 
