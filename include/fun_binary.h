#ifndef MATHQ__FUN_BINARY_H
#define MATHQ__FUN_BINARY_H 1


namespace mathq {

#define FUN_UNARY_W1(Function,Functor,DIN,DOUT,EIN,EOUT,A)  template <class X, class E, class D, int M, int R> \
    inline auto Function(const A& a, const TensorR<X,EIN,DIN,M,R>& x) {	\
    return  TER_Unary_w1<TensorR<X,EIN,DIN,M,R>,EOUT,DOUT,M,R, Functor<E,D>,A >(a,x); \
}


  #define FUNCTOR_UNARY_W1(Function,ClassName,LIB,DIN,DOUT,EIN,EOUT,A) template <class E, class D> class FUNCTOR_##ClassName { \
  public:								\
    typedef DIN DType;							\
    typedef DOUT DoutType;						\
    typedef EIN EType;							\
    typedef EOUT EoutType;						\
    static DOUT apply(const A& a, const DIN d) {			\
      using LIB::Function;						\
      return Function(a,d);						\
    }									\
    template <class T=EIN>						\
      static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type \
      apply(const A& a, const EOUT& e) {				\
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


  // uint param, double
  FUNCTOR_UNARY_W1(legendre,legendre,std,D,D,E,E,int);
  FUN_UNARY_W1(legendre,FUNCTOR_legendre,D,D,E,E,int);

  FUNCTOR_UNARY_W1(laguerre,laguerre,std,D,D,E,E,int);
  FUN_UNARY_W1(laguerre,FUNCTOR_laguerre,D,D,E,E,int);

  FUNCTOR_UNARY_W1(hermite,hermite,std,D,D,E,E,int);
  FUN_UNARY_W1(hermite,FUNCTOR_hermite,D,D,E,E,int);


  /* FUNCTOR_UNARY(std::sph_bessel,sph_bessel,D,E); */
  /* FUN_UNARY(sph_bessel,FUNCTOR_sph_bessel); */

  /* FUNCTOR_UNARY(std::sph_neumann,sph_neumann,D,E); */
  /* FUN_UNARY(sph_neumann,FUNCTOR_sph_neumann); */

  // (doubleparm,double )
  /* FUNCTOR_UNARY(std::cyl_bessel_i,cyl_bessel_i,D,E); */
  /* FUN_UNARY(cyl_bessel_i,FUNCTOR_cyl_bessel_i); */

  /* FUNCTOR_UNARY(std::cyl_bessel_j,cyl_bessel_j,D,E); */
  /* FUN_UNARY(cyl_bessel_j,FUNCTOR_cyl_bessel_j); */

  /* FUNCTOR_UNARY(std::cyl_bessel_k,cyl_bessel_k,D,E); */
  /* FUN_UNARY(cyl_bessel_k,FUNCTOR_cyl_bessel_k); */

  /* FUNCTOR_UNARY(std::cyl_neumann,cyl_neumann,D,E); */
  /* FUN_UNARY(cyl_neumann,FUNCTOR_cyl_neumann); */




  // binary
  /* FUNCTOR_UNARY(std::beta,beta,D,E); */
  /* FUN_UNARY(beta,FUNCTOR_beta); */

  

  FUNCTOR_UNARY_W1(ellint_1,ellint_1,std,D,D,E,E,D);
  FUN_UNARY_W1(ellint_1,FUNCTOR_ellint_1,D,D,E,E,D);

  FUNCTOR_UNARY_W1(ellint_2,ellint_2,std,D,D,E,E,D);
  FUN_UNARY_W1(ellint_2,FUNCTOR_ellint_2,D,D,E,E,D);

  FUNCTOR_UNARY_W1(ellint_3,ellint_3,std,D,D,E,E,D);
  FUN_UNARY_W1(ellint_3,FUNCTOR_ellint_3,D,D,E,E,D);

  


  
};

#endif 
