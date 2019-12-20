#ifndef MATHQ__FUN_BINARY_H
#define MATHQ__FUN_BINARY_H 1


namespace mathq {

  
  // ************************************************************************
  // *              GENERAL BINARY FUNCTOR MACRO
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
  // *             GENERAL BINARY FUNCTION MACRO
  // ************************************************************************

  // #define FUNCTION_BINARY(Function,Functor)




  // ************************************************************************
  // *             BINARY FUNCTOR / FUNCTION DEFINITIONS
  // ************************************************************************


  // work on addition 

  FUNCTOR_BINARY_OP(+,add);
  
  //----------------------------------------------
  // Addition (+)
  //----------------------------------------------
  template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
  auto operator+(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // since M and R are equal, E1 and E2 has same form
    return  TER_Binary<TensorR<A,E1,D1,M,R>,TensorR<B,E2,D2,M,R>,E1,E2,E3,D1,D2,D3,M,M,M,R, FUNCTOR_add<E1,E2,E3,D1,D2,D3> >(x1,x2); 
  }


  // // Tensor<D1> + Tensor<D2>

  // template <class D1, class D2, class A, class B> 
  //   inline auto operator+(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
  // {
  //   return  TER_Binary<TensorR<D1,A>,TensorR<D2,B>,D1,D2,Fun_Add<D1,D2>>(a,b);
  // }


  // // Tensor<D1> + D2

  // template <class D1, class D2, class A, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D2>::value> > 
  //   inline auto operator+(const TensorR<D1,A>& a, const D2& b)
  //   {
  //     return  TER_Binary<TensorR<D1,A>,D2,D1,D2,Fun_Add<D1,D2>>(a,b);
  //   }

  
  // // D1 + Tensor<D2>

  // template <class D1, class D2, class B, typename = std::enable_if_t<!std::is_base_of<TensorAbstract,D1>::value> > 
  //   inline auto operator+(const D1& a, const TensorR<D2,B>& b)
  //   {
  //     return  TER_Binary<D1,TensorR<D2,B>,D1,D2,Fun_Add<D1,D2>>(a,b);
  //   }

    
  // // Tensor<T> + T
    
  // template <class T, class A, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
  //   inline auto operator+(const TensorR<T,A>& a, const T& b)
  //   {
  //     return  TER_Binary<TensorR<T,A>,T,T,T,Fun_Add<T,T>>(a,b);
  //   }
    

  // // T + Tensor<T>

  // template <class T, class B, typename = std::enable_if_t<std::is_base_of<TensorAbstract,T>::value>> 
  //   inline auto operator+(const T& a, const TensorR<T,B>& b)
  //   {
  //     return  TER_Binary<T,TensorR<T,B>,T,T,Fun_Add<T,T>>(a,b);
  //   }


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
