#ifndef MATHQ__FUN_BINARY_H
#define MATHQ__FUN_BINARY_H 1


namespace mathq {

  
  // ************************************************************************
  // *              GENERAL BINARY FUNCTOR MACRO
  // ************************************************************************

  
#define FUNCTOR_BINARY_OP(OP,ClassName)				\
  template <class E, class D> class FUNCTOR_##ClassName {		\
  public:								\
  typedef D DType;							\
  typedef D DoutType;							\
  typedef E EType;							\
  typedef E EoutType;							\
  static D apply(const D d1, const D d2) {				\
    return d1 OP d2;						\
  }									\
  template <class T=E>							\
  static  typename std::enable_if<!std::is_same<T,D>::value, E& >::type \
  apply(const E& e1, const E& e2) {					\
    E *e3 = new E();							\
    *e3 = e1 OP e2;						\
    return *e3;								\
  }									\
  static std::string expression(const std::string& sa, const std::string& sb) {	\
    using namespace display;						\
    std::string sout = "";						\
    sout = sa + stringify(OP) + sb; \
    return sout;							\
  }									\
  static std::string classname() {					\
    using namespace display;						\
    E e;								\
    D d;								\
    std::string angle1 =  StyledString::get(BRACKET1).get();		\
    std::string comma =  StyledString::get(COMMA).get();		\
    std::string angle2 =  StyledString::get(BRACKET2).get();		\
    return functor_namestyle.apply(stringify(FUNCTOR_##ClassName))+angle1+display::getTypeName(e)+comma+display::getTypeName(d)+angle2; \
  }									\
  };
  
  // ************************************************************************
  // *             GENERAL BINARY FUNCTION MACRO
  // ************************************************************************

 #define FUNCTION_BINARY(Function,Functor)				\
  template <class X, class E, class D, int M, int R>	\
    auto Function(const TensorR<X,E,D,M,R>& x1, const TensorR<X,E,D,M,R>& x2) { \
    return  TER_Binary<TensorR<X,E,D,M,R>,TensorR<X,E,D,M,R>,E,D,M,R, Functor<E,D> >(x1,x2); \
  }


  // ************************************************************************
  // *             BINARY FUNCTOR / FUNCTION DEFINITIONS
  // ************************************************************************


  // work on addition 
  
  
  //----------------------------------------------
  // Addition (+)
  //----------------------------------------------

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


  FUNCTOR_BINARY_OP(&&,and);
  FUNCTION_BINARY(operator&&,FUNCTOR_and);



  
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
