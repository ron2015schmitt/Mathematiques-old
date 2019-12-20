#ifndef MATHQ__FUN_BINARY_H
#define MATHQ__FUN_BINARY_H 1


namespace mathq {

  // DUSCUSSION:
  // It makes the most sense to put all the logic regarding types
  //  1. in once place 
  //  2. at the code entry point (the functions)
  //
  // For this reason, the type logic is placed in the functions
  // and then passed to the Functor and the Expression template.
  

  
  // ************************************************************************
  // *         FUNCTOR MACRO FOR GENERAL BINARY operators
  // ************************************************************************

  
#define FUNCTOR_BINARY_OP(OP,ClassName)					\
  template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_##ClassName { \
  public:								\
  static D3 apply(const D1 d1, const D2 d2) {				\
    return d1 OP d2;							\
  }									\
  template <class T=E1>							\
  static E3&  apply(const E1& e1, const E2& e2) {			\
    E3 *e3 = new E3();							\
    *e3 = e1 OP e2;							\
    return *e3;								\
  }									\
  static std::string expression(const std::string& sa, const std::string& sb) {	\
    using namespace display;						\
    std::string sout = "";						\
    sout = sa + stringify(OP) + sb;					\
    return sout;							\
  }									\
  static std::string classname() {					\
    using namespace display;						\
    E1 e1;								\
    E2 e2;								\
    E3 e3;								\
    D1 d1;								\
    D2 d2;								\
    D3 d3;								\
    std::string comma =  StyledString::get(COMMA).get();		\
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_##ClassName)); \
    s += StyledString::get(BRACKET1).get();				\
    s += getTypeName(e1);						\
    s += comma + getTypeName(e2);					\
    s += comma + getTypeName(e3);					\
    s += comma + getTypeName(d1);					\
    s += comma + getTypeName(d2);					\
    s += comma + getTypeName(d3);					\
    s += StyledString::get(BRACKET2).get();				\
    return s;								\
  }									\
  };

  // ************************************************************************
  // *         FUNCTOR MACRO FOR GENERAL BINARY functions
  // ************************************************************************
  
  // ************************************************************************
  // *             BINARY FUNCTOR / FUNCTION DEFINITIONS
  // ************************************************************************


  // work on addition 

  FUNCTOR_BINARY_OP(+,add);
  
  //----------------------------------------------
  // Addition (+)
  //----------------------------------------------

  // Tensor<E1(D1)> + Tensor<E2(D2)>

  // TODO: realtime check that deep dimensions of E1 and E2 are the same

  template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
  auto operator+(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
    return  TER_Binary<TensorR<A,E1,D1,M,R>,
		       TensorR<B,E2,D2,M,R>,
		       E1,E2,E3,D1,D2,D3,M,M,M,R,R,R,
		       FUNCTOR_add<E1,E2,E3,D1,D2,D3> >(x1,x2); 
  }


  

  // Tensor<E(D1)> + D2

  template <class A, class D2, class E, class D1, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>> 
  auto operator+(const TensorR<A,E,D1,M,R>& x1, const D2& x2) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
    return  TER_Binary<TensorR<A,E,D1,M,R>,
		       D2,
		       E,Null,E3,D1,D2,D3,M,0,M,R,R,R,
		       FUNCTOR_add<E,Null,E3,D1,D2,D3> >(x1,x2); 
  }


  
  // D1 + Tensor<E(D2)>

  template <class D1, class B, class E, class D2, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>> 
  auto operator+(const D1& x1, const TensorR<B,E,D2,M,R>& x2) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
    return  TER_Binary<D1,
		       TensorR<B,E,D2,M,R>,
		       Null,E,E3,D1,D2,D3,0,M,M,R,R,R,
		       FUNCTOR_add<Null,E,E3,D1,D2,D3> >(x1,x2); 
  }


  // Tensor<E(D1)> + E(D2)

  // E(D1) + Tensor<E(D2)>

  // TODO: run-time check
  //       (deep dimensions of E1 == deepdimensions of x2)
  //       or
  //       (deep dimensions of x1 == deepdimensions of E2)
  
  
  template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2, typename = std::enable_if_t<(M1==M2+1)&&(std::is_base_of<TensorAbstract,E1>::value)&&(E1::Rvalue==R2)> >
  auto operator+(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef E1 E;
    constexpr int R = R1;
    typedef typename NumberType<E,D3>::ReplaceTypeE E3;   // see TODO note above
    return  TER_Binary<TensorR<A,E1,D1,M1,R>,
  		       TensorR<B,E2,D2,M2,R2>,
  		       E1,E2,E3,D1,D2,D3,M1,M2,M1,R,R2,R,
  		       FUNCTOR_add<E,E,E3,D1,D2,D3> >(x1,x2); 
  }


  // Tensor<D1,R,M> + Tensor<D2,R,1>

  // Tensor<D1,R,1> + Tensor<D2,R,M>

  // TODO: run-timecheck dimesions of x1  equal dimensions of x2

  template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R, typename = std::enable_if_t<(M1>=2)&&(M2==1)&&(std::is_base_of<TensorAbstract,E1>::value)> >
  auto operator+(const TensorR<A,E1,D1,M1,R>& x1, const TensorR<B,E2,D2,M2,R>& x2) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
    return  TER_Binary<TensorR<A,E1,D1,M1,R>,
  		       TensorR<B,E2,D2,M2,R>,
  		       E1,E2,E3,D1,D2,D3,M1,M2,M1,R,R,R,
  		       FUNCTOR_add<E1,E2,E3,D1,D2,D3> >(x1,x2); 
  }






  
  
  //----------------------------------------------
  // logical AND (&&)
  //----------------------------------------------


  // FUNCTOR_BINARY_OP(&&,and);
  // FUNCTION_BINARY(operator&&,FUNCTOR_and);



  
  // // Tensor<D1> && Tensor<D2>

  // template <class D1, class D2, class A, class B> 
  //   inline auto operator&&(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  // {
  //   return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_And<D1,D2>>(a,b);
  // }


  // // Tensor<D1> && bool

  // template <class D1, class A> 
  //   inline auto operator&&(const TensorR<D1,A>& a, const bool& b)
  //   {
  //     return  TER_Binary<TensorR<D1,A>,bool,D1,bool,Fun_And<D1,bool>>(a,b);
  //   }

  
  // // bool && Tensor<D2>

  // template <class D2, class B>
  //   inline auto operator&&(const bool& a, const TensorR<D2,B>& b)
  //   {
  //     return  TER_Binary<bool,TensorR<D2,B>,bool,D2,Fun_And<bool,D2>>(a,b);
  //   }

    
  // // Tensor<T> && T
    
  // template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
  //   inline auto operator&&(const TensorR<T,A>& a, const T& b)
  //   {
  //     return  TER_Binary<TensorR<T,A>,T,T,T,Fun_And<T,T>>(a,b);
  //   }
    

  // // T && Tensor<T>

  // template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
  //   inline auto operator&&(const T& a, const TensorR<T,B>& b)
  //   {
  //     return  TER_Binary<T,TensorR<T,B>,T,T,Fun_And<T,T>>(a,b);
  //   }



  
};

#endif 
