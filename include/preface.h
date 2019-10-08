#ifndef MATRICKS__PREFACE
#define MATRICKS__PREFACE


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


  typedef std::vector<double>::size_type   size_type;
  typedef int index_type;

  typedef long double extended;

  // maximum subcript size for vectors and matrices (since we allow negative indexing)
  const size_type maxsize = std::numeric_limits<index_type>::max();
  const size_type badsize = std::numeric_limits<size_type>::max();


  template <class D> class Vector;
  template <class D, class A> class TensorR;  
  template <class D, class A> class TensorRW;
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
    return (roundzero(abs(x-y), tolerance) == 0);
  }

  // numbercast
  
  template <typename D2, typename D1>
    D2 numbercast(const D1 x) {
    return static_cast<D2>( x );
  }

  // numbercast
  
  template <typename D2, typename D1>
    std::complex<D2> numbercast(const std::complex<D1>& x) {
    using std::real;
    using std::imag;
    return std::complex<D2>( numbercast<D2,D1>(real(x)), numbercast<D2,D1>(imag(x)) );
  }
  
  
  // complex conjugate
  template <typename D> std::complex<D>
  operator~(const std::complex<D>& x) {
    return std::complex<D>(x.real(), -x.imag());
  }


  // complex rounding

  template <typename D> std::complex<D> round(const std::complex<D>& x) {
    return std::complex<D>(std::round(x.real()), std::round(x.imag()));
  }

  // complex - roundzero
  template <typename D> std::complex<D> roundzero(const std::complex<D>& x, const D tolerance) {
    return std::complex<D>(roundzero(x.real(),tolerance), roundzero(x.imag(),tolerance));
  }

    // approx - complex
  
  template <typename D> bool approx(const std::complex<D>& x, const std::complex<D>& y, const D tolerance) {
    using std::abs;
    return (roundzero(abs(x-y), tolerance) == 0);
  }


  // C++ does not have "instanceof" type guarding so even if it
  // can't get to the code it will produce a compile error
  // could also address this by casting where needed
  template <typename D> D matricksconj(const D& x) {
    return x;
  }
  template <typename D> std::complex<D> matricksconj(const std::complex<D>& z) {
    return std::conj(z);
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



  /************************************************************************
   * Class type querying/manipulation
   ************************************************************************      */
  template <typename T> class GetDataType {
  public:
    typedef T Type;
  };
  template <typename D> class GetDataType<std::complex<D> > {
  public:
    typedef typename GetDataType<D>::Type Type;
  };

  template<class T> struct is_complex : std::false_type {};
  template<class T> struct is_complex<std::complex<T>> : std::true_type {};
  
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
