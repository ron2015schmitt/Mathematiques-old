#ifndef MATHQ__UNARY_H
#define MATHQ__UNARY_H 1


namespace mathq {





  /************************************************************
   *          Functions that apply to all tensors
   ************************************************************
   */

  // TODO: convert macros to Python script


  // ************************************************************************
  // *             UNARY FUNCTION MACRO
  // ************************************************************************

#define FUN_UNARY_OLD(Function,Functor)  template <class X, class E, class D, int M, int R> \
    inline auto Function(const TensorR<X,E,D,M,R>& x)			\
  {									\
    return  TER_Unary<TensorR<X,E,D,M,R>,E,D,M,R, Functor<E,D> >(x);	\
  }

#define FUN_UNARY_BOOL(Function,Functor)  template <class X, class E, int M, int R> \
    inline auto Function(const TensorR<X,E,bool,M,R>& x)		\
  {									\
    return  TER_Unary<TensorR<X,E,bool,M,R>,E,bool,M,R, Functor<E,bool> >(x); \
  }
  

  // ************************************************************************
  // *              UNARY FUNCTOR MACRO
  // ************************************************************************

#define FUNCTOR_UNARY(Function,ClassName,DOUT,EOUT) template <class E, class D> class FUNCTOR_##ClassName { \
  public:								\
    typedef D DType;							\
    typedef DOUT DoutType;						\
    typedef E EType;							\
    typedef EOUT EoutType;						\
    static DoutType apply(const DType d) {				\
      return Function(d);						\
    }									\
    template <class T=E>						\
      static  typename std::enable_if<!std::is_same<T,D>::value, EoutType >::type \
      apply(const EType& e) {						\
      EType *e2 = new EType();						\
      *e2 = Function(e);						\
      return *e2;							\
    }									\
    static std::string expression(const std::string& sa) {		\
      using namespace display;						\
      std::string sout = "";						\
      sout = functor_style.apply(stringify(Function))+"("+ sa + ")";	\
      return sout;							\
    }									\
    static std::string classname() {					\
      using namespace display;						\
      E e;								\
      return functor_namestyle.apply(stringify(FUNTOR_##ClassName))+display::getBracketedTypeName(e); \
    }									\
  }



#define FUN_UNARY_NEW(Function,Functor,DIN,DOUT,EIN,EOUT)  template <class X, class E, class D, int M, int R> \
    inline auto Function(const TensorR<X,EIN,DIN,M,R>& x) {		\
  return  TER_Unary<TensorR<X,EIN,DIN,M,R>,EOUT,DOUT,M,R, Functor<E,D> >(x); \
}

#define FUN_UNARY_W1(Function,Functor,DIN,DOUT,EIN,EOUT,A)  template <class X, class E, class D, int M, int R> \
    inline auto Function(const A& a, const TensorR<X,EIN,DIN,M,R>& x) {	\
    return  TER_Unary_w1<TensorR<X,EIN,DIN,M,R>,EOUT,DOUT,M,R, Functor<E,D>,A >(a,x); \
}
  
  
#define FUNCTOR_UNARY_NEW(Function,ClassName,LIB,DIN,DOUT,EIN,EOUT) template <class E, class D> class FUNCTOR_##ClassName { \
  public:								\
    typedef DIN DType;							\
    typedef DOUT DoutType;						\
    typedef EIN EType;							\
    typedef EOUT EoutType;						\
    static DOUT apply(const DIN d) {					\
      using LIB::Function;						\
      return Function(d);						\
    }									\
    template <class T=EIN>						\
      static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type \
      apply(const EOUT& e) {						\
      using LIB::Function;						\
      EOUT *e2 = new EOUT();						\
      *e2 = Function(e);						\
      return *e2;							\
    }									\
    static std::string expression(const std::string& sa) {		\
      using namespace display;						\
      std::string sout = "";						\
      sout = functor_style.apply(stringify(Function))+"("+ sa + ")";	\
      return sout;							\
    }									\
    static std::string classname() {					\
      using namespace display;						\
      EIN e;								\
      return functor_namestyle.apply(stringify(FUNTOR_##ClassName))+display::getBracketedTypeName(e); \
    }									\
  }


#define FUNCTOR_UNARY_W1(Function,ClassName,LIB,DIN,DOUT,EIN,EOUT,A) template <class E, class D> class FUNCTOR_##ClassName { \
  public:								\
    typedef DIN DType;							\
    typedef DOUT DoutType;						\
    typedef EIN EType;							\
    typedef EOUT EoutType;						\
    static DOUT apply(const A& a, const DIN d) {				\
      using LIB::Function;						\
      return Function(a,d);						\
    }									\
    template <class T=EIN>						\
      static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type \
      apply(const A& a, const EOUT& e) {					\
      using LIB::Function;						\
      EOUT *e2 = new EOUT();						\
      *e2 = Function(a,e);						\
      return *e2;							\
    }									\
    static std::string expression(const std::string& sa) {		\
      using namespace display;						\
      std::string sout = "";						\
      sout = functor_style.apply(stringify(Function))+"("+ sa + ")";	\
      return sout;							\
    }									\
    static std::string classname() {					\
      using namespace display;						\
      EIN e;								\
      return functor_namestyle.apply(stringify(FUNTOR_##ClassName))+display::getBracketedTypeName(e); \
    }									\
  }

  
  // ************************************************************************
  // *             UNARY FUNCTIONS
  // ************************************************************************

  
  FUNCTOR_UNARY(+,plus,D,E);
  FUN_UNARY_OLD(operator+,FUNCTOR_plus);
  
  FUNCTOR_UNARY(-,minus,D,E);
  FUN_UNARY_OLD(operator-,FUNCTOR_minus);


  FUNCTOR_UNARY(std::sin,sin,D,E);
  FUN_UNARY_OLD(sin,FUNCTOR_sin);

  FUNCTOR_UNARY(std::cos,cos,D,E);
  FUN_UNARY_OLD(cos,FUNCTOR_cos);

  FUNCTOR_UNARY(std::tan,tan,D,E);
  FUN_UNARY_OLD(tan,FUNCTOR_tan);

  FUNCTOR_UNARY(std::asin,asin,D,E);
  FUN_UNARY_OLD(asin,FUNCTOR_asin);

  FUNCTOR_UNARY(std::acos,acos,D,E);
  FUN_UNARY_OLD(acos,FUNCTOR_acos);

  FUNCTOR_UNARY(std::atan,atan,D,E);
  FUN_UNARY_OLD(atan,FUNCTOR_atan);

  
  FUNCTOR_UNARY(std::sinh,sinh,D,E);
  FUN_UNARY_OLD(sinh,FUNCTOR_sinh);

  FUNCTOR_UNARY(std::cosh,cosh,D,E);
  FUN_UNARY_OLD(cosh,FUNCTOR_cosh);

  FUNCTOR_UNARY(std::tanh,tanh,D,E);
  FUN_UNARY_OLD(tanh,FUNCTOR_tanh);

  FUNCTOR_UNARY(std::asinh,asinh,D,E);
  FUN_UNARY_OLD(asinh,FUNCTOR_asinh);

  FUNCTOR_UNARY(std::acosh,acosh,D,E);
  FUN_UNARY_OLD(acosh,FUNCTOR_acosh);

  FUNCTOR_UNARY(std::atanh,atanh,D,E);
  FUN_UNARY_OLD(atanh,FUNCTOR_atanh);


  FUNCTOR_UNARY(std::sqrt,sqrt,D,E);
  FUN_UNARY_OLD(sqrt,FUNCTOR_sqrt);
  
  FUNCTOR_UNARY(std::cbrt,cbrt,D,E);
  FUN_UNARY_OLD(cbrt,FUNCTOR_cbrt);

  
  FUNCTOR_UNARY(mathq::sqr,sqr,D,E);
  FUN_UNARY_OLD(sqr,FUNCTOR_sqr);

  FUNCTOR_UNARY(mathq::cube,cube,D,E);
  FUN_UNARY_OLD(cube,FUNCTOR_cube);

  FUNCTOR_UNARY(std::exp,exp,D,E);
  FUN_UNARY_OLD(exp,FUNCTOR_exp);

  FUNCTOR_UNARY(std::exp2,exp2,D,E);
  FUN_UNARY_OLD(exp2,FUNCTOR_exp2);

  FUNCTOR_UNARY(std::expm1,expm1,D,E);
  FUN_UNARY_OLD(expml,FUNCTOR_expm1);

  FUNCTOR_UNARY(std::log,log,D,E);
  FUN_UNARY_OLD(log,FUNCTOR_log);

  FUNCTOR_UNARY(std::log10,log10,D,E);
  FUN_UNARY_OLD(log10,FUNCTOR_log10);

  FUNCTOR_UNARY(std::log2,log2,D,E);
  FUN_UNARY_OLD(log2,FUNCTOR_log2);

  FUNCTOR_UNARY(std::log1p,log1p,D,E);
  FUN_UNARY_OLD(log1p,FUNCTOR_log1p);


  FUNCTOR_UNARY(std::abs,abs,D,E);
  FUN_UNARY_OLD(abs,FUNCTOR_abs);
  
  FUNCTOR_UNARY(mathq::sgn,sgn,D,E);
  FUN_UNARY_OLD(sgn,FUNCTOR_sgn);

  
  FUNCTOR_UNARY(std::ceil,ceil,D,E);
  FUN_UNARY_OLD(ceil,FUNCTOR_ceil);
  
  FUNCTOR_UNARY(std::floor,floor,D,E);
  FUN_UNARY_OLD(floor,FUNCTOR_floor);
  
  FUNCTOR_UNARY(std::round,round,D,E);
  FUN_UNARY_OLD(round,FUNCTOR_round);

  FUNCTOR_UNARY(std::trunc,trunc,D,E);
  FUN_UNARY_OLD(trunc,FUNCTOR_trunc);

  FUNCTOR_UNARY(std::erf,erf,D,E);
  FUN_UNARY_OLD(erf,FUNCTOR_erf);
 
  FUNCTOR_UNARY(std::erfc,erfc,D,E);
  FUN_UNARY_OLD(erfc,FUNCTOR_erfc);
  
  FUNCTOR_UNARY(std::tgamma,tgamma,D,E);
  FUN_UNARY_OLD(tgamma,FUNCTOR_tgamma);
  
  FUNCTOR_UNARY(std::lgamma,lgamma,D,E);
  FUN_UNARY_OLD(lgamma,FUNCTOR_lgamma);

  FUNCTOR_UNARY(std::expint,expint,D,E);
  FUN_UNARY_OLD(expint,FUNCTOR_expint);

  FUNCTOR_UNARY(std::riemann_zeta,riemann_zeta,D,E);
  FUN_UNARY_OLD(riemann_zeta,FUNCTOR_riemann_zeta);

  FUNCTOR_UNARY(std::comp_ellint_1,comp_ellint_1,D,E);
  FUN_UNARY_OLD(comp_ellint_1,FUNCTOR_comp_ellint_1);

  FUNCTOR_UNARY(std::comp_ellint_2,comp_ellint_2,D,E);
  FUN_UNARY_OLD(comp_ellint_2,FUNCTOR_comp_ellint_2);


  

  // ************************************************************************
  // *             UNARY BOOLEAN FUNCTIONS
  // ************************************************************************


  FUNCTOR_UNARY(!,not,bool,E);
  FUN_UNARY_OLD(operator!,FUNCTOR_not);


  // ************************************************************************
  // *             UNARY COMPLEX FUNCTIONS
  // ************************************************************************

  //FUNCTOR_UNARY_NEW(Function,ClassName,LIB,DIN,DOUT,EIN,EOUT) template <class E, class D> class FUNCTOR_##ClassName { \

  //  FUNCTOR_UNARY_NEW(conj,conj,std,std::complex<D>,std::complex<D>,E,E);
  //  FUN_UNARY_NEW(conj,FUNCTOR_conj,std::complex<D>,std::complex<D>);

//***************************************************************
// conj(x)
//***************************************************************

  
  template <class E, class D> class FUNCTOR_conj { 
  public:
    typedef std::complex<D> DIN;
    typedef std::complex<D> DOUT;
    typedef E EIN;
    typedef E EOUT;
    static DOUT apply(const DIN d) { 
      namespace LIB = std;
      using LIB::conj;
      return conj(d);
    }
    template <class T=EIN> 
      static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type  
      apply(const EOUT& e) { 
      namespace LIB = std;
      using LIB::conj;    
      EOUT *e2 = new EOUT(); 
      *e2 = Function(e); 
      return *e2; 
    }
    static std::string expression(const std::string& sa) {
      using namespace display;
      std::string sout = "";
      sout = functor_style.apply(stringify(Function))+"("+ sa + ")";	
      return sout;
    }
    static std::string classname() {
      using namespace display;
      EIN e;
      return functor_namestyle.apply(stringify(FUNTOR_conj))+display::getBracketedTypeName(e);
    }
  };



  template <class X, class E, class D, int M, int R> 
    EnableMethodIf<std::is_arithmetic<D>::value,const TensorR<X,E,D,M,R>&>  
    conj(const TensorR<X,E,D,M,R>& x) {
  return x;
}


  template <class X, class E, class D, int M, int R> 
    inline auto conj(const TensorR<X,E,std::complex<D>,M,R>& x) {
  typedef std::complex<D> DIN;
  typedef std::complex<D> DOUT;
  typedef E EIN;
  typedef E EOUT;
  return  TER_Unary<TensorR<X,EIN,DIN,M,R>,EIN,DIN,M,R,FUNCTOR_conj<E,D>>(x); 
}




  template <class X, class E, class D, int M, int R> 
    inline const auto conj(const TensorR<X,E,Imaginary<D>,M,R>& x) {
  typedef Imaginary<D> DIN;
  typedef Imaginary<D> DOUT;
  typedef E EIN;
  typedef E EOUT;
  return  -x; 
}


//***************************************************************
// real(x)
//***************************************************************

  // real(x) x=real
  template <class X, class E, class D, int M, int R> EnableMethodIf<std::is_arithmetic<D>::value,const TensorR<X,E,D,M,R>&>  
    real(const TensorR<X,E,D,M,R>& x) {
  return x;
}


  // real(x) x=complex FUNCTOR
  template <class E, class D> class FUNCTOR_real_from_complex { 
 public:
typedef typename Realify<D>::Type DOUT;
  typedef E EIN;
  typedef typename NumberType<E,DOUT>::ReplaceTypeE EOUT;
  static const DOUT apply(const D d) { 
  namespace LIB = std;
  using LIB::real;
  return real(d);
}
  template <class T=EIN> 
    static  const typename std::enable_if<!std::is_same<T,D>::value, EOUT& >::type  
    apply(const EIN& e) { 
  namespace LIB = std;
  using LIB::real;    
  EOUT *e2 = new EOUT(); 
  *e2 = Function(e); 
  return *e2; 
}
};

  // real(x) x=complex function

  template <class X, class E, class D, int M, int R> 
    inline auto
    real(const TensorR<X,E,std::complex<D>,M,R>& x) {
  typedef std::complex<D> DIN;
  typedef D DOUT;
  typedef E EIN;
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;
  return  TER_Unary<TensorR<X,E,DIN,M,R>,EOUT,DOUT,M,R,FUNCTOR_real_from_complex<E,DIN>>(x); 
}

 


  // real(x) x=Imaginary FUNCTOR

  template <class E, class D> class FUNCTOR_real_from_imag { 
 public:
typedef typename Realify<D>::Type DOUT;
typedef E EIN;
  typedef typename NumberType<E,DOUT>::ReplaceTypeE EOUT;
  static const DOUT apply(const D d) { 
  namespace LIB = mathq;
  using LIB::real;
  return real(d);
}
  template <class T=EIN> 
    static  const typename std::enable_if<!std::is_same<T,D>::value, EOUT& >::type  
    apply(const EIN& e) { 
  namespace LIB = mathq;
  using LIB::real;    
  EOUT *e2 = new EOUT(); 
  *e2 = Function(e); 
  return *e2; 
}
};

    
  // real(x) x=Imaginary function
 
  template <class X, class E, class D, int M, int R> 
    inline auto
    real(const TensorR<X,E,Imaginary<D>,M,R>& x) {
  typedef Imaginary<D> DIN;
  typedef D DOUT;
  typedef E EIN;
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;
  return  TER_Unary<TensorR<X,E,Imaginary<D>,M,R>,EOUT,DOUT,M,R,FUNCTOR_real_from_imag<E,DIN>>(x); 
}



//***************************************************************
// imag(x)
//***************************************************************

  // imag(x) x=real
  template <class E, class D> class FUNCTOR_imag_from_real { 
 public:
typedef typename Realify<D>::Type DOUT;
  typedef E EIN;
  typedef typename NumberType<E,DOUT>::ReplaceTypeE EOUT;
  static const DOUT apply(const D d) { 
  return 0;
}
  template <class T=EIN> 
    static  const typename std::enable_if<!std::is_same<T,D>::value, EOUT& >::type  
    apply(const EIN& e) { 
  EOUT *e2 = new EOUT(); 
  *e2 = imag(e); 
  return *e2; 
}
};
  template <class X, class E, class D, int M, int R> EnableMethodIf<std::is_arithmetic<D>::value,TER_Unary<TensorR<X,E,D,M,R>,E,D,M,R,FUNCTOR_imag_from_real<E,D>>>  
    imag(const TensorR<X,E,D,M,R>& x) {
  return  TER_Unary<TensorR<X,E,D,M,R>,E,D,M,R,FUNCTOR_imag_from_real<E,D>>(x); 
}



  // imag(x) x=complex FUNCTOR
  template <class E, class D> class FUNCTOR_imag_from_complex { 
 public:
typedef typename Realify<D>::Type DOUT;
  typedef E EIN;
  typedef typename NumberType<E,DOUT>::ReplaceTypeE EOUT;
  static const DOUT apply(const D d) { 
  namespace LIB = std;
  using LIB::imag;
  return imag(d);
}
  template <class T=EIN> 
    static  const typename std::enable_if<!std::is_same<T,D>::value, EOUT& >::type  
    apply(const EIN& e) { 
  namespace LIB = std;
  using LIB::imag;    
  EOUT *e2 = new EOUT(); 
  *e2 = imag(e); 
  return *e2; 
}
};

  // imag(x) x=complex function

  template <class X, class E, class D, int M, int R> 
    inline auto
    imag(const TensorR<X,E,std::complex<D>,M,R>& x) {
  typedef std::complex<D> DIN;
  typedef D DOUT;
  typedef E EIN;
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;
  return  TER_Unary<TensorR<X,E,DIN,M,R>,EOUT,DOUT,M,R,FUNCTOR_imag_from_complex<E,DIN>>(x); 
}

 


  // imag(x) x=Imaginary FUNCTOR

  template <class E, class D> class FUNCTOR_imag_from_imag { 
 public:
typedef typename Realify<D>::Type DOUT;
typedef E EIN;
  typedef typename NumberType<E,DOUT>::ReplaceTypeE EOUT;
  static const DOUT apply(const D d) { 
  namespace LIB = mathq;
  using LIB::imag;
  return imag(d);
}
  template <class T=EIN> 
    static  const typename std::enable_if<!std::is_same<T,D>::value, EOUT& >::type  
    apply(const EIN& e) { 
  namespace LIB = mathq;
  using LIB::imag;    
  EOUT *e2 = new EOUT(); 
  *e2 = Function(e); 
  return *e2; 
}
};

    
  // imag(x) x=Imaginary function
 
  template <class X, class E, class D, int M, int R> 
    inline auto
    imag(const TensorR<X,E,Imaginary<D>,M,R>& x) {
  typedef Imaginary<D> DIN;
  typedef D DOUT;
  typedef E EIN;
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;
  return  TER_Unary<TensorR<X,E,Imaginary<D>,M,R>,EOUT,DOUT,M,R,FUNCTOR_imag_from_imag<E,DIN>>(x); 
}

    
  //  ~, complex abs and arg

  

  
  FUNCTOR_UNARY_W1(legendre,legendre,std,D,D,E,E,int);
  FUN_UNARY_W1(legendre,FUNCTOR_legendre,D,D,E,E,int);

  FUNCTOR_UNARY_W1(laguerre,laguerre,std,D,D,E,E,int);
  FUN_UNARY_W1(laguerre,FUNCTOR_laguerre,D,D,E,E,int);

  FUNCTOR_UNARY_W1(hermite,hermite,std,D,D,E,E,int);
  FUN_UNARY_W1(hermite,FUNCTOR_hermite,D,D,E,E,int);

  FUNCTOR_UNARY_W1(ellint_1,ellint_1,std,D,D,E,E,D);
  FUN_UNARY_W1(ellint_1,FUNCTOR_ellint_1,D,D,E,E,D);

  FUNCTOR_UNARY_W1(ellint_2,ellint_2,std,D,D,E,E,D);
  FUN_UNARY_W1(ellint_2,FUNCTOR_ellint_2,D,D,E,E,D);

  FUNCTOR_UNARY_W1(comp_ellint_3,comp_ellint_3,std,D,D,E,E,D);
  FUN_UNARY_W1(comp_ellint_3,FUNCTOR_comp_ellint_3,D,D,E,E,D);

  
  /* FUNCTOR_UNARY(std::sph_legendre,sph_legendre,D,E); */
  /* FUN_UNARY(sph_legendre,FUNCTOR_sph_legendre); */

  /* FUNCTOR_UNARY(std::assoc_legendre,assoc_legendre,D,E); */
  /* FUN_UNARY(assoc_legendre,FUNCTOR_assoc_legendre); */


  /* FUNCTOR_UNARY(std::assoc_laguerre,assoc_laguerre,D,E); */
  /* FUN_UNARY(assoc_laguerre,FUNCTOR_assoc_laguerre); */

  
    

  /* FUNCTOR_UNARY(std::ellint_3,ellint_3,D,E); */
  /* FUN_UNARY(ellint_3,FUNCTOR_ellint_3); */


  
  /* FUNCTOR_UNARY(std::sph_bessel,sph_bessel,D,E); */
  /* FUN_UNARY(sph_bessel,FUNCTOR_sph_bessel); */

  /* FUNCTOR_UNARY(std::cyl_bessel_i,cyl_bessel_i,D,E); */
  /* FUN_UNARY(cyl_bessel_i,FUNCTOR_cyl_bessel_i); */

  /* FUNCTOR_UNARY(std::cyl_bessel_j,cyl_bessel_j,D,E); */
  /* FUN_UNARY(cyl_bessel_j,FUNCTOR_cyl_bessel_j); */

  /* FUNCTOR_UNARY(std::cyl_bessel_k,cyl_bessel_k,D,E); */
  /* FUN_UNARY(cyl_bessel_k,FUNCTOR_cyl_bessel_k); */



  /* FUNCTOR_UNARY(std::sph_neumann,sph_neumann,D,E); */
  /* FUN_UNARY(sph_neumann,FUNCTOR_sph_neumann); */

  /* FUNCTOR_UNARY(std::cyl_neumann,cyl_neumann,D,E); */
  /* FUN_UNARY(cyl_neumann,FUNCTOR_cyl_neumann); */

  // binary
  /* FUNCTOR_UNARY(std::beta,beta,D,E); */
  /* FUN_UNARY(beta,FUNCTOR_beta); */

};

#endif 
