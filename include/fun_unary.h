#ifndef MATHQ__FUN_UNARY_H
#define MATHQ__FUN_UNARY_H 1


  // TODO: convert macros to Python script


namespace mathq {



  // ************************************************************************
  // *              GENERAL UNARY FUNCTOR MACRO
  // ************************************************************************

  
#define FUNCTOR_UNARY(Function,ClassName)			\
  template <class E, class D> class FUNCTOR_##ClassName {		\
  public:								\
    typedef D DType;							\
    typedef D DoutType;						\
    typedef E EType;							\
    typedef E EoutType;						\
    static D apply(const D d) {					\
      return Function(d);						\
    }									\
    template <class T=E>						\
      static  typename std::enable_if<!std::is_same<T,D>::value, E& >::type \
      apply(const E& e) {						\
      E *e2 = new E();						\
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
  
  // ************************************************************************
  // *             GENERAL UNARY FUNCTION MACRO
  // ************************************************************************

#define FUNCTION_UNARY(Function,Functor)		\
  template <class X, class E, class D, int M, int R>			\
  inline auto Function(const TensorR<X,E,D,M,R>& x) {		\
    return  TER_Unary<TensorR<X,E,D,M,R>,E,D,M,R, Functor<E,D> >(x); \
    }



  // ************************************************************************
  // *             UNARY FUNCTOR / FUNCTION DEFINITIONS
  // ************************************************************************

  FUNCTOR_UNARY(!,not);
  FUNCTION_UNARY(operator!,FUNCTOR_not);

  FUNCTOR_UNARY(+,plus);
  FUNCTION_UNARY(operator+,FUNCTOR_plus);

  FUNCTOR_UNARY(-,minus);
  FUNCTION_UNARY(operator-,FUNCTOR_minus);

  FUNCTOR_UNARY(std::sin,sin);
  FUNCTION_UNARY(sin,FUNCTOR_sin);

  FUNCTOR_UNARY(std::cos,cos);
  FUNCTION_UNARY(cos,FUNCTOR_cos);

  FUNCTOR_UNARY(std::tan,tan);
  FUNCTION_UNARY(tan,FUNCTOR_tan);

  
  FUNCTOR_UNARY(std::asin,asin);
  FUNCTION_UNARY(asin,FUNCTOR_asin);

  FUNCTOR_UNARY(std::acos,acos);
  FUNCTION_UNARY(acos,FUNCTOR_acos);

  FUNCTOR_UNARY(std::atan,atan);
  FUNCTION_UNARY(atan,FUNCTOR_atan);

  
  FUNCTOR_UNARY(std::sinh,sinh);
  FUNCTION_UNARY(sinh,FUNCTOR_sinh);

  FUNCTOR_UNARY(std::cosh,cosh);
  FUNCTION_UNARY(cosh,FUNCTOR_cosh);

  FUNCTOR_UNARY(std::tanh,tanh);
  FUNCTION_UNARY(tanh,FUNCTOR_tanh);


  FUNCTOR_UNARY(std::asinh,asinh);
  FUNCTION_UNARY(asinh,FUNCTOR_asinh);

  FUNCTOR_UNARY(std::acosh,acosh);
  FUNCTION_UNARY(acosh,FUNCTOR_acosh);

  FUNCTOR_UNARY(std::atanh,atanh);
  FUNCTION_UNARY(atanh,FUNCTOR_atanh);

  FUNCTOR_UNARY(std::sqrt,sqrt);
  FUNCTION_UNARY(sqrt,FUNCTOR_sqrt);

 
  FUNCTOR_UNARY(std::cbrt,cbrt);
  FUNCTION_UNARY(cbrt,FUNCTOR_cbrt);
  
  FUNCTOR_UNARY(mathq::sqr,sqr);
  FUNCTION_UNARY(sqr,FUNCTOR_sqr);


  FUNCTOR_UNARY(mathq::cube,cube);
  FUNCTION_UNARY(cube,FUNCTOR_cube);


  FUNCTOR_UNARY(std::exp,exp);
  FUNCTION_UNARY(exp,FUNCTOR_exp);

  FUNCTOR_UNARY(std::exp2,exp2);
  FUNCTION_UNARY(exp2,FUNCTOR_exp2);


  FUNCTOR_UNARY(std::expm1,expm1);
  FUNCTION_UNARY(expm1,FUNCTOR_expm1);


  FUNCTOR_UNARY(std::log,log);
  FUNCTION_UNARY(log,FUNCTOR_log);


  FUNCTOR_UNARY(std::log10,log10);
  FUNCTION_UNARY(log10,FUNCTOR_log10);


  FUNCTOR_UNARY(std::log2,log2);
  FUNCTION_UNARY(log2,FUNCTOR_log2);


  FUNCTOR_UNARY(std::log1p,log1p);
  FUNCTION_UNARY(log1p,FUNCTOR_log1p);

  FUNCTOR_UNARY(std::logb,logb);
  FUNCTION_UNARY(logb,FUNCTOR_logb);


  FUNCTOR_UNARY(std::abs,abs);
  FUNCTION_UNARY(abs,FUNCTOR_abs);

  
  FUNCTOR_UNARY(mathq::sgn,sgn);
  FUNCTION_UNARY(sgn,FUNCTOR_sgn);

  
  FUNCTOR_UNARY(std::ceil,ceil);
  FUNCTION_UNARY(ceil,FUNCTOR_ceil);

  
  FUNCTOR_UNARY(std::floor,floor);
  FUNCTION_UNARY(floor,FUNCTOR_floor);

  
  FUNCTOR_UNARY(std::round,round);
  FUNCTION_UNARY(round,FUNCTOR_round);


  FUNCTOR_UNARY(std::trunc,trunc);
  FUNCTION_UNARY(trunc,FUNCTOR_trunc);


  FUNCTOR_UNARY(std::erf,erf);
  FUNCTION_UNARY(erf,FUNCTOR_erf);

 
  FUNCTOR_UNARY(std::erfc,erfc);
  FUNCTION_UNARY(erfc,FUNCTOR_erfc);

  
  FUNCTOR_UNARY(std::tgamma,tgamma);
  FUNCTION_UNARY(tgamma,FUNCTOR_tgamma);

  
  FUNCTOR_UNARY(std::lgamma,lgamma);
  FUNCTION_UNARY(lgamma,FUNCTOR_lgamma);


  FUNCTOR_UNARY(std::expint,expint);
  FUNCTION_UNARY(expint,FUNCTOR_expint);


  FUNCTOR_UNARY(std::riemann_zeta,riemann_zeta);
  FUNCTION_UNARY(riemann_zeta,FUNCTOR_riemann_zeta);


  FUNCTOR_UNARY(std::comp_ellint_1,comp_ellint_1);
  FUNCTION_UNARY(comp_ellint_1,FUNCTOR_comp_ellint_1);


  FUNCTOR_UNARY(std::comp_ellint_2,comp_ellint_2);
  FUNCTION_UNARY(comp_ellint_2,FUNCTOR_comp_ellint_2);



  

  // ************************************************************************
  // *              UNARY TYPE 2 FUNCTOR MACRO--DIFFERENT OUTPUT FROM INPUT
  // ************************************************************************

  
#define FUNCTOR_UNARY_TYPE2(Function,ClassName,DOUT)				\
  template <class E, class D> class FUNCTOR_##ClassName {		\
  public:								\
    typedef D DType;							\
    typedef DOUT DoutType;						\
    typedef E EType;							\
    typedef typename NumberType<E,DOUT>::ReplaceTypeE EoutType;	      \
    static DOUT apply(const D d) {					\
      return Function(d);						\
    }									\
    template <class T=E>						\
      static  typename std::enable_if<!std::is_same<T,D>::value, EoutType& >::type \
      apply(const E& e) {						\
      E *e2 = new E();						\
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
  
  // ************************************************************************
  // *              UNARY TYPE 2 FUNCTOR MACRO--DIFFERENT OUTPUT FROM INPUT
  // ************************************************************************

#define FUNCTION_UNARY_TYPE2(Function,Functor,DOUT)				\
  template <class X, class E, class D, int M, int R>			\
  inline auto Function(const TensorR<X,E,D,M,R>& x) {		\
    typedef typename NumberType<E,DOUT>::ReplaceTypeE EOUT;		\
    return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,DOUT,M,R, Functor<E,D>>(x); \
    }
  
  // ************************************************************************
  // *             UNARY TYPE 2 FUNCTOR / FUNCTION DEFINITIONS
  // ************************************************************************
  
  FUNCTOR_UNARY_TYPE2(std::ilogb,ilogb,int);
  FUNCTION_UNARY_TYPE2(ilogb,FUNCTOR_ilogb,int);

  


  // ************************************************************************
  // *             UNARY COMPLEX-ONLY FUNCTIONS
  // ************************************************************************


  //***************************************************************
  // conj(x)
  //***************************************************************


  // function: conj(x) x=real

  template <class X, class E, class D, int M, int R> 
    EnableMethodIf<std::is_arithmetic<D>::value,const TensorR<X,E,D,M,R>&>  
    conj(const TensorR<X,E,D,M,R>& x) {
    return x;
  }


  // function: conj(x) x=imag
  
  template <class X, class E, class D, int M, int R> 
  inline const auto conj(const TensorR<X,E,Imaginary<D>,M,R>& x) {
    typedef Imaginary<D> DIN;
    typedef Imaginary<D> DOUT;
    typedef E EIN;
    typedef E EOUT;
    return  -x; 
  }
  


  // FUNCTOR: conj(x) x=complex

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



  // function: conj(x) x=complex

  template <class X, class E, class D, int M, int R> 
    inline auto conj(const TensorR<X,E,std::complex<D>,M,R>& x) {
    typedef std::complex<D> DIN;
    typedef std::complex<D> DOUT;
    typedef E EIN;
    typedef E EOUT;
    return  TER_Unary<TensorR<X,EIN,DIN,M,R>,EIN,DIN,M,R,FUNCTOR_conj<E,D>>(x); 
  }





  //***************************************************************
  // real(x)
  //***************************************************************

  // function: real(x) x=real
  
  template <class X, class E, class D, int M, int R> EnableMethodIf<std::is_arithmetic<D>::value,const TensorR<X,E,D,M,R>&>  
    real(const TensorR<X,E,D,M,R>& x) {
    return x;
  }

  // FUNCTOR: real(x) x=Imaginary 

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

    
  // function: real(x) x=Imaginary 
 
  template <class X, class E, class D, int M, int R> 
    inline auto
    real(const TensorR<X,E,Imaginary<D>,M,R>& x) {
    typedef Imaginary<D> DIN;
    typedef D DOUT;
    typedef E EIN;
    typedef typename NumberType<E,D>::ReplaceTypeE EOUT;
    return  TER_Unary<TensorR<X,E,Imaginary<D>,M,R>,EOUT,DOUT,M,R,FUNCTOR_real_from_imag<E,DIN>>(x); 
  }


  
  // FUNCTOR: real(x) x=complex

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


  // function: real(x) x=complex

  template <class X, class E, class D, int M, int R> 
    inline auto
    real(const TensorR<X,E,std::complex<D>,M,R>& x) {
    typedef std::complex<D> DIN;
    typedef D DOUT;
    typedef E EIN;
    typedef typename NumberType<E,D>::ReplaceTypeE EOUT;
    return  TER_Unary<TensorR<X,E,DIN,M,R>,EOUT,DOUT,M,R,FUNCTOR_real_from_complex<E,DIN>>(x); 
  }

 




  //***************************************************************
  // imag(x)
  //***************************************************************

  // FUNCTOR imag(x) x=real

  template <class E, class D> class FUNCTOR_imag_from_real { 
  public:
    static const D apply(const D d) { 
      return 0;
    }
    template <class T=E> 
      static  const typename std::enable_if<!std::is_same<T,D>::value, E& >::type  
      apply(const E& e) { 
      E *e2 = new E(); 
      *e2 = imag(e); 
      return *e2; 
    }
  };

  // function: imag(x) x=real

  template <class X, class E, class D, int M, int R> EnableMethodIf<std::is_arithmetic<D>::value,TER_Unary<TensorR<X,E,D,M,R>,E,D,M,R,FUNCTOR_imag_from_real<E,D>>>  
    imag(const TensorR<X,E,D,M,R>& x) {
    return  TER_Unary<TensorR<X,E,D,M,R>,E,D,M,R,FUNCTOR_imag_from_real<E,D>>(x); 
  }

  // FUNCTOR imag(x) x=Imaginary 

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
    template <class T=E> 
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


  // FUNCTOR: imag(x) x=complex
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

 



    
  //  complex abs and arg norm, others?  

  




};

#endif 
