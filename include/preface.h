#ifndef MATRICKS__PREFACE_H
#define MATRICKS__PREFACE_H


#define CPP11 (__cplusplus >= 201100L)
#define CPP14 (__cplusplus >= 201400L)
#define CPP17 (__cplusplus >= 201700L)

#define _stringify(...) #__VA_ARGS__
#define stringify(...) _stringify(__VA_ARGS__)


#if CPP11 == 1
#define AORLIST(...) __VA_ARGS__
#else
#define AORLIST(...)  (const double[]) __VA_ARGS__
#endif


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


namespace matricks {

  //*******************************************************
  //          Typedefs
  //*******************************************************
  
  typedef std::vector<double>::size_type   size_type;
  typedef int index_type;
  typedef long double extended;


  // maximum subcript size for vectors and matrices (since we allow negative indexing)
  const size_type maxsize = std::numeric_limits<index_type>::max();
  const size_type badsize = std::numeric_limits<size_type>::max();


  template <class D, class A> class TensorR;  
  template <class D, class DERIVED> class TensorRW;
  template <class D> class Scalar;
  template <class D> class Vector;
  template <class D> class Matrix;
  template <class D> class Tensor;

  template <class D, class A> class VER_Rep;
  template <class D> class VSliceObj;
  template <class D> class VSliceExpr;
  template <class D> class TERW_Subset;
  template <class D> class TERW_Submask;
  template <class D, class A, class B> class VERW_Join;
  template <class D, class A, class B> class VER_Join;
  template <class D> class TERW_Resize;
  template <class D, class A, class X> class TER_Series;



    /****************************************************************************
   * math
   **************************************************************************** 
   */

  // GCD
  inline int gcd(int a, int b) {
    int r;
    do {
      r = a % b;
      a = b;
      b = r;
    } while (r != 0);
    
    return a;
  }


  // roundzero
  
  template <typename D> D roundzero(const D& x, const D tolerance) {
    return (std::abs(x) < std::abs(tolerance) ? 0 : x);
  }

  // approx
  
  template <typename D> bool approx(const D& x, const D& y, const D tolerance) {
    using std::abs;
    D tol = tolerance;
    D d = (abs(x)+abs(y))/2;
    if (d > 1) {
      tol *= d;
    }
    return (roundzero(abs(x-y), tol) == 0);
  }

  // numbercast
  
  template <typename D2, typename D1>
    D2 numbercast(const D1 x) {
    return static_cast<D2>( x );
  }

  

  //***********************************************************************
  //       sgn(x) function
  //***********************************************************************
  
#define SGN_MACRO(D)  inline D sgn(const D x) {if (x>0) return static_cast<D>(1); else if (x<0) return static_cast<D>(-1); else return static_cast<D>(0);}
#define SGN_MACRO_US(D)  inline D sgn(const D x) {if (x>0) return static_cast<D>(1);else return static_cast<D>(0);}

  SGN_MACRO(float);
  SGN_MACRO(double);
  SGN_MACRO(long double);
  SGN_MACRO(char);
  SGN_MACRO_US(unsigned char);
  SGN_MACRO(short);
  SGN_MACRO_US(unsigned short);
  SGN_MACRO(int);
  SGN_MACRO_US(unsigned int);
  SGN_MACRO(long);
  SGN_MACRO_US(unsigned long);
#if LONGLONG_EXISTS
  SGN_MACRO(long long);
  SGN_MACRO_US(unsigned long long);
#endif


  
  /****************************************************************************
   * tolerances
   **************************************************************************** 
   */

  template <typename D> struct MatricksHelper {
  public:
    static D tolerance = D(0);
  };
  template <> struct MatricksHelper<double> {
  public:
    constexpr static double tolerance = 1.5e-16;
  };
  template <> struct MatricksHelper<float> {
  public:
    constexpr static float tolerance = 3.5e-7;
  };



  // *********************************************************************
  // * Class type querying/manipulation
  // ********************************************************************

  // ContainedType - this returns the contained type of a complex number
  //                 this could certainly be specialized for other
  //                 container types
  template <typename T> class ContainedType {
  public:
  typedef T Type;
  };
  template <typename D> class ContainedType<std::complex<D> > {
  public:
    typedef D Type;
  };
  template <typename D> class ContainedType<Vector<D> > {
  public:
    typedef D Type;
  };
  template <typename D, typename A> class ContainedType<TensorR<D,A> > {
  public:
    typedef D Type;
  };

  /* BaseType - this operates recursively to find the base arithmetic type */
  /*                 this could certainly be specialized for other */
  /*                 container types */
  template <typename T> class BaseType {
  public:
    typedef T Type;
  };
  template <typename D> class BaseType<std::complex<D> > {
  public:
    typedef typename BaseType<D>::Type Type;
  };
  template <typename D> class BaseType<Vector<D> > {
  public:
    typedef typename BaseType<D>::Type Type;
  };
  template <typename D, typename A> class BaseType<TensorR<D,A> > {
  public:
    typedef typename BaseType<D>::Type Type;
  };


  template<class T> struct is_float : std::false_type {};
  template<> struct is_float<float> : std::true_type {};

  
  // ***************************************************************************
  // * ArithmeticType: Class that determines return type of an aritmetic
  // *                 operation between two types
  // ***************************************************************************

  template <typename T1, typename T2> class AddType {
  public:
    T1 x1;
    T2 x2;
    typedef typeof(x1+x2) Type;
    static inline std::string name() {
      return typeid(Type).name();
    }
  };
  template <typename T1, typename T2> class SubType {
  public:
    T1 x1;
    T2 x2;
    typedef typeof(x1-x2) Type;
  };
  template <typename T1, typename T2> class MultType {
  public:
    T1 x1;
    T2 x2;
    typedef typeof(x1*x2) Type;
  };
  template <typename T1, typename T2> class DivType {
  public:
    T1 x1;
    T2 x2;
    typedef typeof(x1/x2) Type;
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
