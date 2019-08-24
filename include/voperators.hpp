#ifndef VOPERATORS_H
#define VOPERATORS_H 1

#include <string>
#include <sstream>


namespace matricks {



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




  


  // join

  template <class D, class A, class B> 
  inline const VJoinExpr<D,VorE<D,A>,VorE<D,B> > 
  join(const VorE<D,A>& a, const VorE<D,B>& b)
  {
    return  VJoinExpr<D,VorE<D,A>,VorE<D,B> >(a,b);
  }


  
  // template <class D, class A, class B> 
  // inline VJoinObj<D,VorE<D,A>,VorE<D,B> > 
  // join(VorE<D,A>& a, VorE<D,B>& b)
  // {
  //   return  VJoinObj<D,VorE<D,A>,VorE<D,B> >(a,b);
  // }



  template <class D> 
  inline VJoinObj<D,Vector<D>,Vector<D> > 
  operator,(Vector<D>& a, Vector<D>& b)
  {
    printf("  VJoinObj operator,(Vector<D>& a, Vector<D>& b)\n");
    return  VJoinObj<D,Vector<D>,Vector<D> >(a,b);
  }

  template <class D> 
  inline const VJoinExpr<D, Vector<D>,Vector<D> > 
  operator,(const Vector<D>& a, const Vector<D>& b)
  {
    printf("  VJoinExpr operator,(const Vector<D>& a, const Vector<D>& b)\n");
    return  VJoinExpr<D,Vector<D>,Vector<D> >(a,b);
  }

  template <class D, class B> 
  inline const VJoinExpr<D, Vector<D>,Vexpr<D,B> > 
  operator,(const Vector<D>& a, const Vexpr<D,B>& b)
  {
    printf("  VJoinExpr operator,(const Vector<D>& a, const Vexpr<D,B>& b)\n");
    return  VJoinExpr<D,Vector<D>,Vexpr<D,B>  >(a,b);
  }

  template <class D, class A> 
  inline VJoinObj<D,Vexpr<D,A>,Vector<D> > 
  operator,(Vexpr<D,A>& a, Vector<D>& b)
  {
    printf("  VJoinObj operator,(Vexpr<D,A>& a, Vector<D>& b)\n");
    return  VJoinObj<D,Vexpr<D,A>,Vector<D> >(a,b);
  }
  
  template <class D, class A, class B> 
  inline const VJoinExpr<D, Vexpr<D,A>,Vexpr<D,B> > 
  operator,(const Vexpr<D,A>& a, const Vexpr<D,B>& b)
  {
    printf("  VJoinExpr operator,(const Vexpr<D,A>& a, const Vexpr<D,B>& b)\n");
    return  VJoinExpr<D, Vexpr<D,A>,Vexpr<D,B> >(a,b);
  }

  // ^^the above works for everything except (vc[{1,0}], vd) =


  

  // template <class D, class B> 
  //  inline VJoinObj<D,Vector<D>,VorW<D,B> > 
  //  operator,(Vector<D>& a, VorW<D,B>& b)
  //  {
  //    return  VJoinObj<D,Vector<D>,VorW<D,B> >(a,b);
  //  }

   // template <class D> 
   // inline VJoinObj<D,Vector<D>,Vector<D> > 
   // operator,(Vector<D>& a, Vector<D>& b)
   // {
   //   return  VJoinObj<D,Vector<D>,Vector<D> >(a,b);
   // }
  
  // template <class D, class A, class B> 
  // inline const VJoinExpr<D,VorE<D,A>,VorE<D,B> > 
  // operator,(const VorE<D,A>& a, const VorE<D,B>& b)
  // {
  //   return  VJoinExpr<D,VorE<D,A>,VorE<D,B> >(a,b);
  // }



    // rep(v,m)

  // TODO:  make input a const.  turn this into a expr
  template <class D> 
  inline Vector<D>&
  rep(Vector<D>& a, size_t m) {
    const size_t Na = a.size();
    const size_t N = m*Na;
    Vector<D> *v = new Vector<D>(N);
    printf("rep for loop\n");
    for(index_type j = 0; j < m; j++) {
      index_type start = j*Na;
      printf("  j=%d, Na=%lu\n",j,Na);
      (*v)[slc(start,start+Na-1)] = a[slc(0,Na-1)];
    }
    return *v;
  }

  
  




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
    
#ifdef MATRICKS_DEBUG
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

    for (register index_type i = 1; i < N ; i++ )
      result += a[i];
    
    return result;
  }


  // integrate(a)
  // order  name
  //     1  trapazoidal
  //     2  simpson
  //     3  simpson 3/8
  //     4  Boole
  
  template <class D, class A> 
  D integrate( const VorE<D,A>& v, const D a, const D b, const int order=1 ) {
    
#ifdef MATRICKS_DEBUG
    if (  vexpr_is_size_bad(v) ) {
      vbad_expr_in_unary(v,"integrate");
      return 0;
    }
    if (b<a)  {
      std::cerr << "integrate: bad limit end points a="<<a<<", b="<<b<<std::endl;
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
    case 1:

      result += (v[0]+v[N-1])/2;
      for (register index_type j = 1; j < N-1 ; j++ ) {
	result += v[j];
      }
      result = result * (b-a)/D(N-1);
      break;
    case 2:
      if (N%2==0)  {
	std::cout << "integrate: Number of points must be odd N="<<N<<std::endl;
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
	std::cout << "integrate: N-1 must be divisible by 3, N="<<N<<std::endl;
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
	std::cout << "integrate: N-1 must be divisible by 4, N="<<N<<std::endl;
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
#ifdef MATRICKS_DEBUG
      std::cerr << "integrate: bad order parameter order="<<order<<std::endl;   
#endif
      break;
    }

    return result;
  }

  
  // prod(a)

  template <class D, class A> 
  D prod( const VorE<D,A>& a ) {
    
#ifdef MATRICKS_DEBUG
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

    for (register index_type i = 1; i < N ; i++ )
      result += a[i]*a[i];
    
    return std::sqrt(result);
  }




  // min(a)

  template <class D, class A> 
  D min( const VorE<D,A>& a ) {
    
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

    for (register index_type i = 1; i < N ; i++ )
      result = std::min(result,a[i]);
    
    return result;
  }




  // max(a)

  template <class D, class A> 
  D max( const VorE<D,A>& a ) {
    
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

    for (register index_type i = 1; i < N ; i++ )
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
    
    for (register index_type i = 0; i < N ; i++ )
      data[i] = a[i];

    sort(data.begin(),data.end());
    
    for (register index_type i = 0; i < N ; i++ )
      a[i] = data[i];

  }



  // sort and return the sorted indices: sortwind(a)

  template <class DAT> class idpair {
  public:
    index_type ind;
    DAT dat;
    
    bool operator<(const idpair<DAT>& x2) const {
      return (this->dat < x2.dat);
    }
  };

  template <class D> Vector<index_type> sortwind(Vector<D>& a ) {

    const size_type N = a.size();
#ifdef MATRICKS_DEBUG
    std::string name = "sortindices(" + a.debugtxt() +")";
    if (  vexpr_is_size_bad(a) ) {
      vbad_expr_in_unary(a,"sortwind");
      Vector<index_type> ivec(0,name);
      return ivec;
    }
    Vector<index_type> ivec(N,name);
#else
    Vector<index_type> ivec(N);
#endif

    if (N==0)
      return ivec;
    
    std::vector<idpair<D> > data(N);
    

    for (register index_type i = 0; i < N ; i++ ) {
      data[i].ind = i;
      data[i].dat = a[i];
    }
    
    
    sort(data.begin(),data.end());
    
    
    for (register index_type i = 0; i < N ; i++ ) {
      ivec[i] = data[i].ind;
      a[i] = data[i].dat;
    }
    
    return ivec;
    
  }


  // reverse(a)

  template <class D>
  Vector<D>& reverse(Vector<D>& a ) {

    const size_type N = a.size();
    if (N==0)
      return a;
   
    for (register index_type i = 0; i < N/2 ; i++ ) {
      D temp = a[i];
      a[i] = a[N-i-1];
      a[N-i-1] = temp;
    }

    return a;

  }



};

#endif //VOPERATORS_H
