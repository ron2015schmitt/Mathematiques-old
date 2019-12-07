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

#define FUN_UNARY(Function,Functor)  template <class X, class E, class D, int M, int R> \
    inline auto Function(const TensorR<X,E,D,M,R>& x)			\
  {									\
    return  TER_Unary<TensorR<X,E,D,M,R>,E,D,M,R, Functor<E,D> >(x);	\
  }


  // ************************************************************************
  // *              UNARY FUNCTOR MACRO
  // ************************************************************************

#define FUNCTOR_UNARY(Function,ClassName,DOUT,EOUT) template <class E, class D> class FUNCTOR_##ClassName {\
  public:\
    typedef D DType;\
    typedef DOUT DoutType;\
    typedef E EType;\
    typedef EOUT EoutType;\
    static DoutType apply(const DType d) { \
      return Function(d);\
    }\
    template <class T=E> \
    static  typename std::enable_if<!std::is_same<T,D>::value, EoutType >::type  \
    apply(const EType& e) { \
      EType *e2 = new EType(); \
      *e2 = Function(e); \
      return *e2; \
    }\
      static std::string expression(const std::string& sa) {\
	using namespace display;\
	std::string sout = "";\
	sout = functor_style.apply(stringify(Function))+"("+ sa + ")";	\
					     return sout;\
					     }\
	static std::string classname() {\
	using namespace display;\
	E e;\
	return functor_namestyle.apply(stringify(FUNTOR_##ClassName))+display::getBracketedTypeName(e);\
      }\
    }

  
  // ************************************************************************
  // *             UNARY FUNCTIONS
  // ************************************************************************

  
  FUNCTOR_UNARY(+,plus,D,E);
  FUN_UNARY(operator+,FUNCTOR_plus);
  
  FUNCTOR_UNARY(-,minus,D,E);
  FUN_UNARY(operator-,FUNCTOR_minus);


  FUNCTOR_UNARY(std::sin,sin,D,E);
  FUN_UNARY(sin,FUNCTOR_sin);

  FUNCTOR_UNARY(std::cos,cos,D,E);
  FUN_UNARY(cos,FUNCTOR_cos);

  FUNCTOR_UNARY(std::tan,tan,D,E);
  FUN_UNARY(tan,FUNCTOR_tan);

  FUNCTOR_UNARY(std::asin,asin,D,E);
  FUN_UNARY(asin,FUNCTOR_asin);

  FUNCTOR_UNARY(std::acos,acos,D,E);
  FUN_UNARY(acos,FUNCTOR_acos);

  FUNCTOR_UNARY(std::atan,atan,D,E);
  FUN_UNARY(atan,FUNCTOR_atan);

  
  FUNCTOR_UNARY(std::sinh,sinh,D,E);
  FUN_UNARY(sinh,FUNCTOR_sinh);

  FUNCTOR_UNARY(std::cosh,cosh,D,E);
  FUN_UNARY(cosh,FUNCTOR_cosh);

  FUNCTOR_UNARY(std::tanh,tanh,D,E);
  FUN_UNARY(tanh,FUNCTOR_tanh);

  FUNCTOR_UNARY(std::asinh,asinh,D,E);
  FUN_UNARY(asinh,FUNCTOR_asinh);

  FUNCTOR_UNARY(std::acosh,acosh,D,E);
  FUN_UNARY(acosh,FUNCTOR_acosh);

  FUNCTOR_UNARY(std::atanh,atanh,D,E);
  FUN_UNARY(atanh,FUNCTOR_atanh);


  FUNCTOR_UNARY(std::sqrt,sqrt,D,E);
  FUN_UNARY(sqrt,FUNCTOR_sqrt);
  
  FUNCTOR_UNARY(std::cbrt,cbrt,D,E);
  FUN_UNARY(cbrt,FUNCTOR_cbrt);

  
  FUNCTOR_UNARY(mathq::sqr,sqr,D,E);
  FUN_UNARY(sqr,FUNCTOR_sqr);

  FUNCTOR_UNARY(mathq::cube,cube,D,E);
  FUN_UNARY(cube,FUNCTOR_cube);

  FUNCTOR_UNARY(std::exp,exp,D,E);
  FUN_UNARY(exp,FUNCTOR_exp);

  FUNCTOR_UNARY(std::exp2,exp2,D,E);
  FUN_UNARY(exp2,FUNCTOR_exp2);

  FUNCTOR_UNARY(std::expm1,expm1,D,E);
  FUN_UNARY(expml,FUNCTOR_expm1);

  FUNCTOR_UNARY(std::log,log,D,E);
  FUN_UNARY(log,FUNCTOR_log);

  FUNCTOR_UNARY(std::log10,log10,D,E);
  FUN_UNARY(log10,FUNCTOR_log10);

  FUNCTOR_UNARY(std::log2,log2,D,E);
  FUN_UNARY(log2,FUNCTOR_log2);

  FUNCTOR_UNARY(std::log1p,log1p,D,E);
  FUN_UNARY(log1p,FUNCTOR_log1p);


  FUNCTOR_UNARY(std::abs,abs,D,E);
  FUN_UNARY(abs,FUNCTOR_abs);
  
  FUNCTOR_UNARY(mathq::sgn,sgn,D,E);
  FUN_UNARY(sgn,FUNCTOR_sgn);

  
  FUNCTOR_UNARY(std::ceil,ceil,D,E);
  FUN_UNARY(ceil,FUNCTOR_ceil);
  
  FUNCTOR_UNARY(std::floor,floor,D,E);
  FUN_UNARY(floor,FUNCTOR_floor);
  
  FUNCTOR_UNARY(std::round,round,D,E);
  FUN_UNARY(round,FUNCTOR_round);

  FUNCTOR_UNARY(std::trunc,trunc,D,E);
  FUN_UNARY(trunc,FUNCTOR_trunc);

  FUNCTOR_UNARY(std::erf,erf,D,E);
  FUN_UNARY(erf,FUNCTOR_erf);
 
  FUNCTOR_UNARY(std::erfc,erfc,D,E);
  FUN_UNARY(erfc,FUNCTOR_erfc);
  
  FUNCTOR_UNARY(std::tgamma,tgamma,D,E);
  FUN_UNARY(tgamma,FUNCTOR_tgamma);
  
  FUNCTOR_UNARY(std::lgamma,lgamma,D,E);
  FUN_UNARY(lgamma,FUNCTOR_lgamma);

  FUNCTOR_UNARY(std::expint,expint,D,E);
  FUN_UNARY(expint,FUNCTOR_expint);

  FUNCTOR_UNARY(std::riemann_zeta,riemann_zeta,D,E);
  FUN_UNARY(riemann_zeta,FUNCTOR_riemann_zeta);






  
  /* FUNCTOR_UNARY(std::beta,beta,D,E); */
  /* FUN_UNARY(beta,FUNCTOR_beta); */

  /* FUNCTOR_UNARY(std::legendre,legendre,D,E); */
  /* FUN_UNARY(legendre,FUNCTOR_legendre); */

  /* FUNCTOR_UNARY(std::sph_legendre,sph_legendre,D,E); */
  /* FUN_UNARY(sph_legendre,FUNCTOR_sph_legendre); */

  /* FUNCTOR_UNARY(std::assoc_legendre,assoc_legendre,D,E); */
  /* FUN_UNARY(assoc_legendre,FUNCTOR_assoc_legendre); */

  /* FUNCTOR_UNARY(std::laguerre,laguerre,D,E); */
  /* FUN_UNARY(laguerre,FUNCTOR_laguerre); */

  /* FUNCTOR_UNARY(std::assoc_laguerre,assoc_laguerre,D,E); */
  /* FUN_UNARY(assoc_laguerre,FUNCTOR_assoc_laguerre); */

  
    
  /* FUNCTOR_UNARY(std::ellint_1,ellint_1,D,E); */
  /* FUN_UNARY(ellint_1,FUNCTOR_ellint_1); */

  /* FUNCTOR_UNARY(std::ellint_2,ellint_2,D,E); */
  /* FUN_UNARY(ellint_2,FUNCTOR_ellint_2); */

  /* FUNCTOR_UNARY(std::ellint_3,ellint_3,D,E); */
  /* FUN_UNARY(ellint_3,FUNCTOR_ellint_3); */

  /* FUNCTOR_UNARY(std::comp_ellint_1,comp_ellint_1,D,E); */
  /* FUN_UNARY(comp_ellint_1,FUNCTOR_comp_ellint_1); */

  /* FUNCTOR_UNARY(std::comp_ellint_2,comp_ellint_2,D,E); */
  /* FUN_UNARY(comp_ellint_2,FUNCTOR_comp_ellint_2); */

  /* FUNCTOR_UNARY(std::comp_ellint_3,comp_ellint_3,D,E); */
  /* FUN_UNARY(comp_ellint_3,FUNCTOR_comp_ellint_3); */

  
  /* FUNCTOR_UNARY(std::sph_bessel,sph_bessel,D,E); */
  /* FUN_UNARY(sph_bessel,FUNCTOR_sph_bessel); */

  /* FUNCTOR_UNARY(std::cyl_bessel_i,cyl_bessel_i,D,E); */
  /* FUN_UNARY(cyl_bessel_i,FUNCTOR_cyl_bessel_i); */

  /* FUNCTOR_UNARY(std::cyl_bessel_j,cyl_bessel_j,D,E); */
  /* FUN_UNARY(cyl_bessel_j,FUNCTOR_cyl_bessel_j); */

  /* FUNCTOR_UNARY(std::cyl_bessel_k,cyl_bessel_k,D,E); */
  /* FUN_UNARY(cyl_bessel_k,FUNCTOR_cyl_bessel_k); */

  /* FUNCTOR_UNARY(std::hermite,hermite,D,E); */
  /* FUN_UNARY(hermite,FUNCTOR_hermite); */


  /* FUNCTOR_UNARY(std::sph_neumann,sph_neumann,D,E); */
  /* FUN_UNARY(sph_neumann,FUNCTOR_sph_neumann); */

  /* FUNCTOR_UNARY(std::cyl_neumann,cyl_neumann,D,E); */
  /* FUN_UNARY(cyl_neumann,FUNCTOR_cyl_neumann); */
 

};

#endif 
