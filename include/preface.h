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
  

  template <typename T> class NumberType;

  class TensorAbstract;
  template <class D, class DERIVED> class TensorR;  
  template <class D, class DERIVED> class TensorRW;
  
  template <class D, int M = 1+matricks::NumberType<D>::depth()> class Scalar;
  template <class D, int NN = 0, int M = 1+matricks::NumberType<D>::depth()> class Vector;
  template <class D> class Matrix;
  template <class D> class Tensor;


  template <class D, int M = 1+matricks::NumberType<D>::depth()>
    class TERW_Subset;
  template <class D, int M = 1+matricks::NumberType<D>::depth()>
    class TERW_Submask;
  template <class D, int M = 1+matricks::NumberType<D>::depth()>
    class TERW_Resize;
  template <class D, class OP, int M = 1+matricks::NumberType<D>::depth()>
    class TER_RealFromComplex;
  template<class D, class A, class FUNC, int M = 1+matricks::NumberType<D>::depth()>
    class TER_Unary;

  template<class D, class A, class B, class OP, int M = 1+matricks::NumberType<D>::depth()>
    class TER_Binary;

  // Note: lack "+1" for M1,M2 is intended
  template<class A, class B, class D1, class D2, class OP, int M1 = matricks::NumberType<A>::depth(), int M2 = matricks::NumberType<B>::depth()>
    class TER_NewBinary;

  template<class D, class A, class X, int M = 1+matricks::NumberType<D>::depth()>
    class TER_Series;
  template<class D, class A, class B, class X, class OP1, class OP2, int M = 1+matricks::NumberType<D>::depth()>
    class TER_Series2;    

  template<class D, class A, class OP, int M = 1+matricks::NumberType<D>::depth()>
    class TER_TensorOpScalar;

  template<class D, class B, class OP, int M = 1+matricks::NumberType<D>::depth()>
    class TER_ScalarOpTensor;

  template <class DOUT, class A, class D, class OP, int M = 1+matricks::NumberType<D>::depth()>
    class TER_TensorOpScalar_New;

  template <class DOUT, class D, class B, class OP, int M = 1+matricks::NumberType<D>::depth()>
    class TER_ScalarOpTensor_New;
  template<class D, class A, class FUNC, int M = 1+matricks::NumberType<D>::depth()>
    class TER_Bool_Unary;
  template<class D, class A, class B, class OP, int M = 1+matricks::NumberType<D>::depth()>
    class TER_Bool_Binary;
  template<class D, class A, class B, class OP, int M = 1+matricks::NumberType<D>::depth()>
    class TER_Bool_Binary2;
  template<class D, class A, class OP, int M = 1+matricks::NumberType<D>::depth()>
    class TER_Bool_TensorOpScalar;
  template<class D, class B, class OP, int M = 1+matricks::NumberType<D>::depth()>
    class TER_Bool_ScalarOpTensor;
  template<class D, class A, class OP, int M = 1+matricks::NumberType<D>::depth()>
    class TER_Cplx_TensorOpScalar;
  template<class D, class B, class OP, int M = 1+matricks::NumberType<D>::depth()>
    class TER_Cplx_ScalarOpTensor;
  template<class D, class A, class FUNC, int M = 1+matricks::NumberType<D>::depth()>
    class TERW_Transpose;
  template<class D, class A, class FUNC, int M = 1+matricks::NumberType<D>::depth()>
    class TER_Transpose;
  template<class D, class A, class B, int M = 1+matricks::NumberType<D>::depth()>
    class VER_Join;
  template<class D, class A, class B, int M = 1+matricks::NumberType<D>::depth()>
    class VERW_Join;
  template<class D, class A, int M = 1+matricks::NumberType<D>::depth()>
    class VER_Rep;

  


  // *********************************************************************
  // * Class type querying/manipulation
  // ********************************************************************


  // ContainedType - this returns the contained type of a complex number
  //                 this could certainly be specialized for other
  //                 container types
  template <typename T> class ContainedType {
  public:
    typedef void Type;
  };
  template <typename D> class ContainedType<std::complex<D>> {
  public:
    typedef D Type;
  };
  template <typename D> class ContainedType<Imaginary<D>> {
  public:
    typedef D Type;
  };
  template <template<typename> class T, typename D> class ContainedType<T<D> > {
  public:
    typedef D Type;
  };
  template <typename D, typename A> class ContainedType<TensorR<D,A> > {
  public:
    typedef D Type;
  };

  /* FundamentalType - this operates recursively to find the primitive arithmetic type (eg int, float, double)*/
  /*                 this could certainly be specialized for other */
  /*                 container types */
  template <typename T> class FundamentalType {
  public:
    typedef T Type;
    constexpr static int depth() {
      return 0;
    }
  };
  template <template<typename> class T, typename D> class FundamentalType<T<D> > {
  public:
    typedef typename FundamentalType<D>::Type Type;
    constexpr static int depth() {
      return 1+FundamentalType<D>::depth();
    }
  };
  template <typename D, typename A> class FundamentalType<TensorR<D,A> > {
  public:
    typedef typename FundamentalType<D>::Type Type;
    constexpr static int depth() {
      return 1+FundamentalType<D>::depth();
    }
  };

  /* NumberType - this operates recursively to find the base number type (complex<double>, Imaginary<float>, int, double)*/
  /*                 this could certainly be specialized for other */
  /*                 container types */
  template <typename T> class NumberType {
  public:
    typedef T Type;
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
  template <class D> class NumberType<std::complex<D> > {
  public:
    typedef std::complex<D> Type;
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
  template <class D> class NumberType<Imaginary<D> > {
  public:
    typedef Imaginary<D> Type;
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


  template <typename D, template <typename> typename A > class NumberType<A<D>>  {
  public:
    typedef A<D> InputType;
    typedef typename NumberType<D>::Type Type;
    constexpr static int depth() {
      return 1+NumberType<D>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };
  template <typename D, class X1, template <typename,typename> typename A > class NumberType<A<D,X1>>  {
  public:
    typedef A<D,X1> InputType;
    typedef typename NumberType<D>::Type Type;
    constexpr static int depth() {
      return 1+NumberType<D>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
  };
  template <typename D, class X1, class X2, template <typename,typename,typename> typename A > class NumberType<A<D,X1,X2>>  {
  public:
    typedef A<D,X1,X2> InputType;
    typedef typename NumberType<D>::Type Type;
    constexpr static int depth() {
      return 1+NumberType<D>::depth();
    }
    inline static int size(const InputType& x) {
      return x.size();
    }
    inline static int deepsize(const InputType& x) {
      return x.deepsize();
    }
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
  
  
};


#endif
