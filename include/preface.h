#ifndef MATRICKS__PREFACE_H
#define MATRICKS__PREFACE_H


#define CPP11 (__cplusplus >= 201100L)
#define CPP14 (__cplusplus >= 201400L)
#define CPP17 (__cplusplus >= 201700L)

#define _stringify(...) #__VA_ARGS__
#define stringify(...) _stringify(__VA_ARGS__)



#define DO_EXPAND(VAL)  99##VAL
#define EXPAND(VAL)     DO_EXPAND(VAL)


#ifdef MEBUG
 #if (EXPAND(MEBUG) == 99)
  // defined but no value: set to 1
  #define MATRICKS_DEBUG 1
 #else
  #define MATRICKS_DEBUG EXPAND(MEBUG)
 #endif
#endif


#ifndef MATRICKS_DEBUG
// not defined: set to 0
   #define MATRICKS_DEBUG 0
#elif (EXPAND(MATRICKS_DEBUG) == 99)
  // defined but no value: set to 1
  #undef MATRICKS_DEBUG
  #define MATRICKS_DEBUG 1
#elif (MATRICKS_DEBUG>3)
  // no modes defined above 3
  #undef MATRICKS_DEBUG
  #define MATRICKS_DEBUG 3
#endif


// this is created by the makefile and placed in '[exec]_opt.cpp' for
// any executable the is compiled
// it contains the $(OPTIMIZE) flag with all the compile optimization options
extern char COMPILE_OPTIMIZE[];


namespace display {
  
  template <typename T> inline std::string getBracketedTypeName(const T& var);
  template <typename T> inline void dispval_strm(std::ostream &stream, const T& d);
};

namespace matricks {

  //*******************************************************
  //          Typedefs
  //*******************************************************
  
  typedef std::vector<double>::size_type   size_type;
  typedef int index_type;
  typedef long double extended;

  template <typename D> class Imaginary;
  
  template <typename T, typename NUM=double> class NumberType;


  // E = element type (int, double, complex<double>, bool, Scalar<double>, Vector<double>, Matrix<double>, etc)
  // D = number type (int, double, complex<double>, bool, etc)
  
  class TensorAbstract;
  template <class E, class DERIVED, typename D, int M>
    class TensorR;  
  template <class E, class DERIVED, typename D, int M>
    class TensorRW;


  
  template <class E,              typename D = typename NumberType<E>::Type, int M = 1+NumberType<E>::depth()> class
    Scalar;
  template <class E, int NE = 0,  typename D = typename NumberType<E>::Type, int M = 1+NumberType<E>::depth()> class
    Vector;
  template <class E, int NR = 0, int NC = 0,    typename D = typename NumberType<E>::Type, int M = 1+NumberType<E>::depth()> class
    Matrix;
  template <class E, int NDims = 0,   typename D = typename NumberType<E>::Type, int M = 1+NumberType<E>::depth()> class
    Tensor;



  template<class D, class A, class FUNC, int M = 1+NumberType<D>::depth()> class
    TER_Unary;

  // Note: the lack "+1" for M1,M2 is intended
  template<class A, class B, class D1, class D2, class OP, int M1 = NumberType<A>::depth(), int M2 = NumberType<B>::depth()> class
    TER_Binary;

  template<class A, class B, class C, class D1, class D2, class D3, class OP, int M1 = NumberType<A>::depth(), int M2 = NumberType<B>::depth(), int M3 = NumberType<C>::depth()> class
    TER_Ternary;
  

  template <class D, int M = 1+NumberType<D>::depth()>
    class TERW_Subset;
  template <class D, int M = 1+NumberType<D>::depth()>
    class TERW_Submask;
  template <class D, int M = 1+NumberType<D>::depth()>
    class TERW_Resize;
  template <class D, class OP, int M = 1+NumberType<D>::depth()>
    class TER_RealFromComplex;


  template<class D, class A, class X, int M = 1+NumberType<D>::depth()>
    class TER_Series;
  template<class D, class A, class B, class X, class OP1, class OP2, int M = 1+NumberType<D>::depth()>
    class TER_Series2;    


  template<class D, class A, class FUNC, int M = 1+NumberType<D>::depth()>
    class TERW_Transpose;
  template<class D, class A, class FUNC, int M = 1+NumberType<D>::depth()>
    class TER_Transpose;
  template<class D, class A, class B, int M = 1+NumberType<D>::depth()>
    class VER_Join;
  template<class D, class A, class B, int M = 1+NumberType<D>::depth()>
    class VERW_Join;
  template<class D, class A, int M = 1+NumberType<D>::depth()>
    class VER_Rep;

  



  // *********************************************************************
  // * Class type querying/manipulation
  // ********************************************************************


  // ContainedType - this returns the contained type of a complex number
  //                 this could certainly be specialized for other
  //                 container types
  template <typename T> class
    ContainedType {
  public:
    typedef void Type;
  };
  template <typename D> class
    ContainedType<std::complex<D>> {
  public:
    typedef D Type;
  };
  template <typename D> class
    ContainedType<Imaginary<D>> {
  public:
    typedef D Type;
  };
  template <template<typename> class T, typename D> class
    ContainedType<T<D> > {
  public:
    typedef D Type;
  };
  template <typename E, typename A,typename D, int M> class
    ContainedType<TensorR<E,A,D,M> > {
  public:
    typedef E Type;
  };



  // FundamentalType - this operates recursively to find the primitive arithmetic type
  //                   eg int, float, double, ...
  template <typename T> class
    FundamentalType {
  public:
    typedef T Type;
    constexpr static int depth() {
      return 0;
    }
  };

  template <class E, template<typename> class T> class
    FundamentalType<T<E>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1+FundamentalType<E>::depth();
    }
  };
  template <class E> class
    FundamentalType<std::complex<E>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1+FundamentalType<E>::depth();
    }
  };
  template <class E> class
    FundamentalType<Imaginary<E>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1+FundamentalType<E>::depth();
    }
  };


  
  //  Scalar<E>
  template <class E> class
    FundamentalType<Scalar<E>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1+FundamentalType<E>::depth();
    }
  };
  
  //  Vector<E>
  template <class E> class
    FundamentalType<Vector<E>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1+FundamentalType<E>::depth();
    }
  };

  //  Matrix<E>

  template <class E> class
    FundamentalType<Matrix<E>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1+FundamentalType<E>::depth();
    }
  };


  //  Tensor<E>
  template <class E> class
    FundamentalType<Tensor<E>> {
  public:
    typedef typename FundamentalType<E>::Type Type;
    constexpr static int depth() {
      return 1+FundamentalType<E>::depth();
    }
  };


  //  TensorR<E,A,D,M>

  template <class E, class A, class D, int M> class
    FundamentalType<TensorR<E,A,D,M>> {
  public:
    typedef E Type;
    constexpr static int depth() {
      return M;
    }
  };


  
  
  // NumberType - this operates recursively to find the base number type
  //              eg. complex<double>, Imaginary<float>, int, double, etc
  template <typename T, typename NewD> class
    NumberType {
  public:
    typedef T Type;
    typedef NewD ReplaceType;
    constexpr static int depth() {
      return 0;
    }
    inline static int size(const T x) {
      return 1;
    }
    inline static int deepsize(const T& x) {
      return 1;
    }
  };
  template <class D, typename NewD> class
    NumberType<std::complex<D>,NewD > {
  public:
    typedef std::complex<D> Type;
    typedef NewD ReplaceType;
    constexpr static int depth() {
      return 0;
    }
    inline static int size(const std::complex<D> x) {
      return 1;
    }
    inline static int deepsize(const std::complex<D> x) {
      return 1;
    }
  };
  template <class D, typename NewD> class NumberType<Imaginary<D>,NewD > {
  public:
    typedef Imaginary<D> Type;
    typedef NewD ReplaceType;
    constexpr static int depth() {
      return 0;
    }
    inline static int size(const Imaginary<D> x) {
      return 1;
    }
    inline static int deepsize(const Imaginary<D> x) {
      return 1;
    }
  };


  
  //  Scalar<E>
  
  template <class E, typename NewD> class
    NumberType<Scalar<E>,NewD > {
  public:
    typedef Scalar<E> InputType;
    typedef typename NumberType<E>::Type Type;
    typedef Scalar<typename NumberType<E,NewD>::ReplaceType> ReplaceType;
    constexpr static int depth() {
      return 1+NumberType<E,NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };


  //  Vector<E>

  template <class E, typename NewD> class
    NumberType<Vector<E>,NewD > {
  public:
    typedef Vector<E> InputType;
    typedef typename NumberType<E>::Type Type;
    typedef Vector<typename NumberType<E,NewD>::ReplaceType> ReplaceType;
    constexpr static int depth() {
      return 1+NumberType<E,NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };


  //  Matrix<E>

  template <class E, typename NewD> class
    NumberType<Matrix<E>,NewD > {
  public:
    typedef Matrix<E> InputType;
    typedef typename NumberType<E>::Type Type;
    typedef Matrix<typename NumberType<E,NewD>::ReplaceType> ReplaceType;
    constexpr static int depth() {
      return 1+NumberType<E,NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };


  //  Tensor<E>

  template <class E, typename NewD> class
    NumberType<Tensor<E>,NewD > {
  public:
    typedef Tensor<E> InputType;
    typedef typename NumberType<E>::Type Type;
    typedef Tensor<typename NumberType<E,NewD>::ReplaceType> ReplaceType;
    constexpr static int depth() {
      return 1+NumberType<E,NewD>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };


  //  TensorR<E,A,D,M>

  template <class E, class A, class D, int M, typename NewD> class
    NumberType<TensorR<E,A,D,M>,NewD> {
  public:
    typedef TensorR<E,A,D,M> InputType;
    typedef A DerivedType;
    typedef D OldD;
    typedef D OldE;
    typedef typename NumberType<E,NewD>::ReplaceType NewE;
    typedef TensorR<NewE, A, NewD,M> Type;
    constexpr static int depth() {
      return M;
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };




  
  // DeeperType - this operates recursively to find the primitive arithmetic type
  template <typename T1, typename T2> class
    DeeperType {
  public:
    typedef typename std::conditional< NumberType<T1>::depth() >= NumberType<T2>::depth(), T1, T2>::type Type;
  };



  
  // ***************************************************************************
  // At(x,n) -  for primitives, return x
  //            for container of any type, return x[n]
  // ***************************************************************************

  template <class D>
  inline D&& At(D&& x, index_type n) {
    return x;
  }
  template <class D>
  inline const D&& At(const D&& x, index_type n) {
    return x;
  }
  template <template<class> class T, class D>
  inline D&& At(T<D>&& x, index_type n) {
    return x[n];
  }
  template <template<class> class T, class D>
  inline const D&& At(const T<D>&& x, index_type n) {
    return x[n];
  }

  
  
  // ***************************************************************************
  // * {Add,Sub,Mult,Div}Type: Class that determines return type of an aritmetic
  // *                 operation between two types
  // ***************************************************************************

  template <typename T1, typename T2> class AddType {
  public:
    T1 x1;
    T2 x2;
    typedef decltype(x1+x2) Type;
    static inline std::string name() {
      return typeid(Type).name();
    }
  };
  template <typename T1, typename T2> class SubType {
  public:
    T1 x1;
    T2 x2;
    typedef decltype(x1-x2) Type;
  };
  template <typename T1, typename T2> class MultType {
  public:
    T1 x1;
    T2 x2;
    typedef decltype(x1*x2) Type;
  };
  template <typename T1, typename T2> class DivType {
  public:
    T1 x1;
    T2 x2;
    typedef decltype(x1/x2) Type;
  };


    // ************************************************************************
  // * ReturnType: Class that determines return type of two Tensors of different depths
  // ***************************************************************************


  template <typename A, typename B, typename NewD> class ResultType {
  public:

    typedef typename DeeperType<A,B>::Type DeeperType;
    typedef typename NumberType<DeeperType,NewD>::ReplaceType TensorType;
    constexpr static bool isprim = (NumberType<A>::depth() == 0)&&(NumberType<B>::depth() == 0);
    typedef typename std::conditional<isprim, NewD, TensorType >::type Type;
  };


  
  
  //***********************************************************************
  //     is_instance<FilledTemplateClassA or object, TemplateCLassB>
  //
  //   is_instance<Fun_Multiply<double>, Fun_Divide>{}       -> false
  //   is_instance<Fun_Multiply<double>, Fun_Multiply>{}     -> true
  //   is_instance<obj, Vector>{}     -
  //***********************************************************************


  template <class, template <class> class>
    struct is_instance : public std::false_type {};
  template <class T, template <class> class U>
    struct is_instance<U<T>, U> : public std::true_type {};

  //***********************************************************************
  //  EnableConstructorIf - used for enabling constructors 
  //***********************************************************************

  template<bool B>
    using EnableConstructorIf = typename std::enable_if<B, int>::type;

  //***********************************************************************
  //  EnableIf - used for enabling constructors 
  //***********************************************************************
  template<bool B, class T>
    using EnableMethodIf = typename std::enable_if<B,T>::type;

  //************************************************************************
  //* Basic Function types for computation
  //************************************************************************   
  template <typename D> class FunctionTypes {
  public:
    typedef D (* zeroarg_func)();
    typedef D (* unary_func)(D);
    typedef D (* binary_func)(D, D);
    typedef D (* tertiary_func)(D, D, D);
    typedef D (* quaternary_func)(D, D, D);
  };
  


  ////////////////////////////////////////////////////////////
  // In functions.h
  ////////////////////////////////////////////////////////////

  template <class E, class A, int M> inline Vector<index_type>& findtrue( const TensorR<E,A,bool,M>& a );

};


#endif
