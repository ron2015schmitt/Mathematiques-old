

#ifndef MVOPERATORS_H
#define MVOPERATORS_H

#include <string>
#include <sstream>


namespace matricks {




  // outer product: vector ^ vector

  template <class D, class A, class B> 
  inline Matrix<D>
  operator^(const VorE<D,A>& a, const VorE<D,B>& b)
  {
    const size_type NC = a.size();
    const size_type NR = b.size();
#if MATRICKS_DEBUG>0
    std::string sa = a.debugtxt();
    if (a.vetype() != VE_Vector) 
      sa = "(" + sa + ")";
    std::string sb = b.debugtxt();
    if (b.vetype() != VE_Vector) 
      sb = "(" + sb + ")";
    std::string name= sa + "^"+  sb;
    if (  vexpr_is_size_bad(a) || vexpr_is_size_bad(b)  ) { 
      vbad_expr_in_binary(a,b,"","^");
      Matrix<D> y(0,0,name);
      return y;
    }
    Matrix<D> y(NR,NC,name);
#else
    Matrix<D> y(NR,NC);
#endif

    register index_type i=0;
    for(register index_type r=0; r < NR; r++) 
      for(register index_type c=0; c < NC; c++,i++) 
	y(i) = a[c]*b[r];   

    return  y;
  }



  // vector = diagonal(Matrix)

  template <class D, class A> 
  inline Vector<D>
  diag(const MorE<D,A>& a)
  {
    size_type Nmin;
    if (a.Nrows() < a.Ncols())
      Nmin=a.Nrows();
    else
      Nmin=a.Ncols();
    const size_type N=Nmin;
#if MATRICKS_DEBUG>0
    std::string name= "diag("+a.debugtxt() +")";
    if ( mexpr_is_size_bad(a.size()) ){ 
      mbad_expr_in_unary(a,"diag");
      Vector<D> v(0,name);
      return v;
    }
    Vector<D> v(N,name);
#else
    Vector<D> v(N);
#endif

    for (register index_type i = 0; i < N ; i++ )
      v[i] = a(i,i);
    return v;
  }





  // diagmat(vector)

  template <class D, class A> 
  inline Matrix<D>
  diagmat(const VorE<D,A>& a)
  {
    const size_type N = a.size();
#if MATRICKS_DEBUG>0
    std::string name;
    name = "diagmat(" + a.debugtxt() + ")";
    if (  vexpr_is_size_bad(a) ) { 
      vbad_expr_in_unary(a,"diagmat");
      Matrix<D> y(0,0,name);
      return y;
    }
    Matrix<D> y(N,N,name);
#else
    Matrix<D> y(N,N);
#endif

    for(register index_type i=0; i < N; i++) 
      y(i,i) = a[i];   

    return  y;
  }

   


  // dotproduct operator (matrix|vector)

  template <class D, class A, class B> 
  inline Vector<D>
  operator|( const MorE<D,A>& a, const  VorE<D,B>& b ) {
    const size_type NR = a.Nrows();
    const size_type M = a.Ncols();
    const index_type C1 = NR*M;
    const index_type C2 = M-1;

#if MATRICKS_DEBUG>0
    std::string sa = a.debugtxt();
    if (a.metype() != ME_Matrix) 
      sa = "(" + sa + ")";
    std::string sb = b.debugtxt();
    if (b.vetype() != VE_Vector) 
      sb = "(" + sb + ")";
    std::string name= sa + "|"+  sb;
    const size_type Mb = b.size();

    if (mexpr_is_size_bad(a.size()) ) { 
      mbad_expr_in_unary(a,""); 
      Vector<D> y(0,name);
      return y;
    } else if (  vexpr_is_size_bad(b)  ) { 
      vbad_expr_in_unary(b,"");
      Vector<D> y(0,name);
      return y;
    } else if (M!=Mb) {
      mvbad_dot_product(a,b);
      Vector<D> y(0,name);
      return y;
    }
    Vector<D> y(NR,name);
#else
    Vector<D> y(NR);
#endif

    register index_type i = 0;
    for(register index_type n=0; n < C1; n+=M, i++) {
      index_type j = n;
      index_type k = 0;
       // using a local variable for the accumation saves a lot of CPU Time!!
      D result = a(j) * b[k];
      do {
	result += a((j+=1)) * b[(k+=1)];
      } while (k<C2);
      y[i] = result;   
    }
    return  y;
  }



  // dotproduct operator (vector|matrix)

  template <class D, class A, class B> 
  inline Vector<D>
  operator|( const VorE<D,A>& a, const  MorE<D,B>& b ) {
    const size_type NC = b.Ncols();
    const size_type M = b.Nrows();

#if MATRICKS_DEBUG>0
    std::string sa = a.debugtxt();
    std::string sb = b.debugtxt();
    if (a.vetype() != VE_Vector) 
      sa = "(" + sa + ")";
    if (b.metype() != ME_Matrix) 
      sb = "(" + sb + ")";
    std::string name= sa + "|"+  sb;
    const size_type Ma = a.size();
    if (mexpr_is_size_bad(b.size()) ) { 
      mbad_expr_in_unary(b,""); 
      Vector<D> y(0,name);
      return y;
    } else if (  vexpr_is_size_bad(a)  ) { 
      vbad_expr_in_unary(a,"");
      Vector<D> y(0,name);
      return y;
    } else if (M!=Ma) {
      vmbad_dot_product(a,b);
      Vector<D> y(0,name);
      return y;
    }
    Vector<D> y(NC,name);
#else
    Vector<D> y(NC);
#endif

    register index_type i = 0;
    for(register index_type c=0; c < NC; c++,i++) {
      index_type j = 0;
      index_type k = c;
      const index_type C2 = M-1;
      // using a local variable for the accumation saves a lot of CPU Time!!
      D result = a[j] * b(k);
      do {
	result += a[(j+=1)] * b((k+=NC));
      } while (j<C2);
      y[i] = result;   
    }
    return  y;
  }




};

#endif 
