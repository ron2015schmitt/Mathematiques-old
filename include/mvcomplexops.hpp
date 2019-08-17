#ifndef MVCOMPLEXOPS_H
#define MVCOMPLEXOPS_H 1


#include <string>
#include <sstream>


namespace Matricks {




  // outer product: complexvector ^ realvector

  template <class D, class A, class B> 
  inline Matrix<std::complex<D> >
  operator^(const VorE<std::complex<D>,A>& a, const VorE<D,B>& b)
  {
    const size_type NC = a.size();
    const size_type NR = b.size();
#ifdef MATRICKS_DEBUG
    std::string sa = a.debugtxt();
    if (a.vetype() != VE_Vector) 
      sa = "(" + sa + ")";
    std::string sb = b.debugtxt();
    if (b.vetype() != VE_Vector) 
      sb = "(" + sb + ")";
    std::string name= sa + "^"+  sb;
    if (  vexpr_is_size_bad(a) || vexpr_is_size_bad(b)  ) { 
      vbad_expr_in_binary(a,b,"","^");
      Matrix<std::complex<D> > y(0,0,name);
      return y;
    }
    Matrix<std::complex<D> > y(NR,NC,name);
#else
    Matrix<std::complex<D> > y(NR,NC);
#endif

    register size_type i=0;
    for(register size_type r=0; r < NR; r++) 
      for(register size_type c=0; c < NC; c++,i++) 
	y(i) = a[c]*b[r];   

    return  y;
  }


  // outer product: realvector ^ complexvector

  template <class D, class A, class B> 
  inline Matrix<std::complex<D> >
  operator^(const VorE<D,A>& a, const VorE<std::complex<D>,B>& b)
  {
    const size_type NC = a.size();
    const size_type NR = b.size();
#ifdef MATRICKS_DEBUG
    std::string sa = a.debugtxt();
    if (a.vetype() != VE_Vector) 
      sa = "(" + sa + ")";
    std::string sb = b.debugtxt();
    if (b.vetype() != VE_Vector) 
      sb = "(" + sb + ")";
    std::string name= sa + "^"+  sb;
    if (  vexpr_is_size_bad(a) || vexpr_is_size_bad(b)  ) { 
      vbad_expr_in_binary(a,b,"","^");
      Matrix<std::complex<D> > y(0,0,name);
      return y;
    }
    Matrix<std::complex<D> > y(NR,NC,name);
#else
    Matrix<std::complex<D> > y(NR,NC);
#endif

    register size_type i=0;
    for(register size_type r=0; r < NR; r++) 
      for(register size_type c=0; c < NC; c++,i++) 
	y(i) = a[c]*b[r];   

    return  y;
  }









  // dotproduct operator (complex matrix|real vector)

  template <class D, class A, class B> 
  inline Vector<std::complex<D> >
  operator|( const MorE<std::complex<D> ,A>& a, const  VorE<D,B>& b ) {
    const size_type NR = a.Nrows();
    const size_type M = a.Ncols();
    const size_type C1 = NR*M;
    const size_type C2 = M-1;

#ifdef MATRICKS_DEBUG
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
      Vector<std::complex<D> > y(0,name);
      return y;
    } else if (  vexpr_is_size_bad(b)  ) { 
      vbad_expr_in_unary(b,"");
      Vector<std::complex<D> > y(0,name);
      return y;
    } else if (M!=Mb) {
      mvbad_dot_product(a,b);
      Vector<std::complex<D> > y(0,name);
      return y;
    }
    Vector<std::complex<D> > y(NR,name);
#else
    Vector<std::complex<D> > y(NR);
#endif

    register size_type i = 0;
    for(register size_type n=0; n < C1; n+=M, i++) {
      size_type j = n;
      size_type k = 0;
       // using a local variable for the accumation saves a lot of CPU Time!!
      std::complex<D>  result = a(j) * b[k];
      do {
	result += a((j+=1)) * b[(k+=1)];
      } while (k<C2);
      y[i] = result;   
    }
    return  y;
  }



  // dotproduct operator (realvector|complexmatrix)

  template <class D, class A, class B> 
  inline Vector<std::complex<D> >
  operator|( const VorE<D,A>& a, const  MorE<std::complex<D> ,B>& b ) {
    const size_type NC = b.Ncols();
    const size_type M = b.Nrows();

#ifdef MATRICKS_DEBUG
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
      Vector<std::complex<D> > y(0,name);
      return y;
    } else if (  vexpr_is_size_bad(a)  ) { 
      vbad_expr_in_unary(a,"");
      Vector<std::complex<D> > y(0,name);
      return y;
    } else if (M!=Ma) {
      vmbad_dot_product(a,b);
      Vector<std::complex<D> > y(0,name);
      return y;
    }
    Vector<std::complex<D> > y(NC,name);
#else
    Vector<std::complex<D> > y(NC);
#endif

    register size_type i = 0;
    for(register size_type c=0; c < NC; c++,i++) {
      size_type j = 0;
      size_type k = c;
      const size_type C2 = M-1;
      // using a local variable for the accumation saves a lot of CPU Time!!
      std::complex<D>  result = a[j] * b(k);
      do {
	result += a[(j+=1)] * b((k+=NC));
      } while (j<C2);
      y[i] = result;   
    }
    return  y;
  }







  // dotproduct operator (realmatrix|complexvector)

  template <class D, class A, class B> 
  inline Vector<std::complex<D> >
  operator|( const MorE<D,A>& a, const  VorE<std::complex<D> ,B>& b ) {
    const size_type NR = a.Nrows();
    const size_type M = a.Ncols();
    const size_type C1 = NR*M;
    const size_type C2 = M-1;

#ifdef MATRICKS_DEBUG
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
      Vector<std::complex<D> > y(0,name);
      return y;
    } else if (  vexpr_is_size_bad(b)  ) { 
      vbad_expr_in_unary(b,"");
      Vector<std::complex<D> > y(0,name);
      return y;
    } else if (M!=Mb) {
      mvbad_dot_product(a,b);
      Vector<std::complex<D> > y(0,name);
      return y;
    }
    Vector<std::complex<D> > y(NR,name);
#else
    Vector<std::complex<D> > y(NR);
#endif

    register size_type i = 0;
    for(register size_type n=0; n < C1; n+=M, i++) {
      size_type j = n;
      size_type k = 0;
       // using a local variable for the accumation saves a lot of CPU Time!!
      std::complex<D>  result = a(j) * b[k];
      do {
	result += a((j+=1)) * b[(k+=1)];
      } while (k<C2);
      y[i] = result;   
    }
    return  y;
  }



  // dotproduct operator (complexvector|realmatrix)

  template <class D, class A, class B> 
  inline Vector<std::complex<D> >
  operator|( const VorE<std::complex<D> ,A>& a, const  MorE<D,B>& b ) {
    const size_type NC = b.Ncols();
    const size_type M = b.Nrows();

#ifdef MATRICKS_DEBUG
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
      Vector<std::complex<D> > y(0,name);
      return y;
    } else if (  vexpr_is_size_bad(a)  ) { 
      vbad_expr_in_unary(a,"");
      Vector<std::complex<D> > y(0,name);
      return y;
    } else if (M!=Ma) {
      vmbad_dot_product(a,b);
      Vector<std::complex<D> > y(0,name);
      return y;
    }
    Vector<std::complex<D> > y(NC,name);
#else
    Vector<std::complex<D> > y(NC);
#endif

    register size_type i = 0;
    for(register size_type c=0; c < NC; c++,i++) {
      size_type j = 0;
      size_type k = c;
      const size_type C2 = M-1;
      // using a local variable for the accumation saves a lot of CPU Time!!
      std::complex<D>  result = a[j] * b(k);
      do {
	result += a[(j+=1)] * b((k+=NC));
      } while (j<C2);
      y[i] = result;   
    }
    return  y;
  }






};

#endif 
