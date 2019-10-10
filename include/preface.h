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

  //*******************************************************
  //          Typedefs
  //*******************************************************
  
  typedef std::vector<double>::size_type   size_type;
  typedef int index_type;
  typedef long double extended;

  typedef std::complex<float> ComplexFloat;
  typedef std::complex<double> ComplexDouble;
  typedef std::complex<long double> ComplexLongDouble;
  typedef std::complex<char> ComplexChar;
  typedef std::complex<signed char> ComplexSignedChar;
  typedef std::complex<short> ComplexShort;
  typedef std::complex<int> ComplexInt;
  typedef std::complex<long> ComplexLong;
  typedef std::complex<long long> ComplexLongLong;
  typedef std::complex<unsigned char> ComplexUnsignedChar;
  typedef std::complex<unsigned short> ComplexUnsignedShort;
  typedef std::complex<unsigned int> ComplexUnsignedInt;
  typedef std::complex<unsigned long> ComplexUnsignedLong;
  typedef std::complex<unsigned long long> ComplexUnsignedLongLong;


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
    return (approx(real(x),real(y),tolerance) && approx(imag(x),imag(y),tolerance));
  }

  // complex log2
  template <typename D> std::complex<D>
  log2(const std::complex<D>& x) {
    const D A0 = 1/log(D(2));
    return A0*log(x);
  }


  // complex bitwise NOT ~
  inline ComplexUnsignedChar
  operator~(const ComplexUnsignedChar& x) {
    return ComplexUnsignedChar( ~real(x), ~imag(x)  );
  }
  inline ComplexUnsignedShort
  operator~(const ComplexUnsignedShort& x) {
    return ComplexUnsignedShort( ~real(x), ~imag(x)  );
  }
  inline ComplexUnsignedInt
  operator~(const ComplexUnsignedInt& x) {
    return ComplexUnsignedInt( ~real(x), ~imag(x)  );
  }
  inline ComplexUnsignedLong
  operator~(const ComplexUnsignedLong& x) {
    return ComplexUnsignedLong( ~real(x), ~imag(x)  );
  }
  inline ComplexUnsignedLongLong
  operator~(const ComplexUnsignedLongLong& x) {
    return ComplexUnsignedLongLong( ~real(x), ~imag(x)  );
  }
  // complex bitwise OR |
  inline ComplexUnsignedChar
    operator|(const ComplexUnsignedChar& x, const ComplexUnsignedChar& y) {
    return ComplexUnsignedChar( real(x)|real(y), imag(x)|imag(y)  );
  }
  inline ComplexUnsignedShort
  operator|(const ComplexUnsignedShort& x, const ComplexUnsignedShort& y) {
    return ComplexUnsignedShort( real(x)|real(y), imag(x)|imag(y)  );
  }
  inline ComplexUnsignedInt
  operator|(const ComplexUnsignedInt& x, const ComplexUnsignedInt& y) {
    return ComplexUnsignedInt( real(x)|real(y), imag(x)|imag(y)  );
  }
  inline ComplexUnsignedLong
  operator|(const ComplexUnsignedLong& x, const ComplexUnsignedLong& y) {
    return ComplexUnsignedLong( real(x)|real(y), imag(x)|imag(y)  );
  }
  inline ComplexUnsignedLongLong
  operator|(const ComplexUnsignedLongLong& x, const ComplexUnsignedLongLong& y) {
    return ComplexUnsignedLongLong( real(x)|real(y), imag(x)|imag(y)  );
  }
  // complex bitwise OR: complex Scalar | real scalar
  inline ComplexUnsignedChar
    operator|(const ComplexUnsignedChar& x, const unsigned char& y) {
    return ComplexUnsignedChar( real(x)|y, imag(x)|y );
  }
  inline ComplexUnsignedShort
  operator|(const ComplexUnsignedShort& x, const unsigned short& y) {
    return ComplexUnsignedShort( real(x)|y, imag(x)|y );
  }
  inline ComplexUnsignedInt
  operator|(const ComplexUnsignedInt& x, const unsigned int& y) {
    return ComplexUnsignedInt( real(x)|y, imag(x)|y );
  }
  inline ComplexUnsignedLong
  operator|(const ComplexUnsignedLong& x, const unsigned long& y) {
    return ComplexUnsignedLong( real(x)|y, imag(x)|y );
  }
  inline ComplexUnsignedLongLong
  operator|(const ComplexUnsignedLongLong& x, const unsigned long long& y) {
    return ComplexUnsignedLongLong( real(x)|y, imag(x)|y );
  }
  // complex bitwise OR: real scalar | complex Scalar
  inline ComplexUnsignedChar
    operator|(const unsigned char& x, const ComplexUnsignedChar& y) {
    return ComplexUnsignedChar( x|real(y), x|imag(y) );
  }
  inline ComplexUnsignedShort
    operator|(const unsigned short& x, const ComplexUnsignedShort& y) {
    return ComplexUnsignedShort( x|real(y), x|imag(y)  );
  }
  inline ComplexUnsignedInt
    operator|(const unsigned int& x, const ComplexUnsignedInt& y ) {
    return ComplexUnsignedInt( x|real(y), x|imag(y) );
  }
  inline ComplexUnsignedLong
    operator|(const unsigned long& x, const ComplexUnsignedLong& y) {
    return ComplexUnsignedLong( x|real(y), x|imag(y)  );
  }
  inline ComplexUnsignedLongLong
    operator|(const unsigned long long& x, const ComplexUnsignedLongLong& y) {
    return ComplexUnsignedLongLong( x|real(y), x|imag(y)  );
  }
  // complex bitwise XOR ^
  inline ComplexUnsignedChar
    operator^(const ComplexUnsignedChar& x, const ComplexUnsignedChar& y) {
    return ComplexUnsignedChar( real(x)^real(y), imag(x)^imag(y)  );
  }
  inline ComplexUnsignedShort
  operator^(const ComplexUnsignedShort& x, const ComplexUnsignedShort& y) {
    return ComplexUnsignedShort( real(x)^real(y), imag(x)^imag(y)  );
  }
  inline ComplexUnsignedInt
  operator^(const ComplexUnsignedInt& x, const ComplexUnsignedInt& y) {
    return ComplexUnsignedInt( real(x)^real(y), imag(x)^imag(y)  );
  }
  inline ComplexUnsignedLong
  operator^(const ComplexUnsignedLong& x, const ComplexUnsignedLong& y) {
    return ComplexUnsignedLong( real(x)^real(y), imag(x)^imag(y)  );
  }
  inline ComplexUnsignedLongLong
  operator^(const ComplexUnsignedLongLong& x, const ComplexUnsignedLongLong& y) {
    return ComplexUnsignedLongLong( real(x)^real(y), imag(x)^imag(y)  );
  }
  // complex bitwise XOR: complex Scalar ^ real scalar
  inline ComplexUnsignedChar
    operator^(const ComplexUnsignedChar& x, const unsigned char& y) {
    return ComplexUnsignedChar( real(x)^y, imag(x)^y );
  }
  inline ComplexUnsignedShort
  operator^(const ComplexUnsignedShort& x, const unsigned short& y) {
    return ComplexUnsignedShort( real(x)^y, imag(x)^y );
  }
  inline ComplexUnsignedInt
  operator^(const ComplexUnsignedInt& x, const unsigned int& y) {
    return ComplexUnsignedInt( real(x)^y, imag(x)^y );
  }
  inline ComplexUnsignedLong
  operator^(const ComplexUnsignedLong& x, const unsigned long& y) {
    return ComplexUnsignedLong( real(x)^y, imag(x)^y );
  }
  inline ComplexUnsignedLongLong
  operator^(const ComplexUnsignedLongLong& x, const unsigned long long& y) {
    return ComplexUnsignedLongLong( real(x)^y, imag(x)^y );
  }
  // complex bitwise XOR: real scalar ^ complex Scalar
  inline ComplexUnsignedChar
    operator^(const unsigned char& x, const ComplexUnsignedChar& y) {
    return ComplexUnsignedChar( x^real(y), x^imag(y) );
  }
  inline ComplexUnsignedShort
    operator^(const unsigned short& x, const ComplexUnsignedShort& y) {
    return ComplexUnsignedShort( x^real(y), x^imag(y)  );
  }
  inline ComplexUnsignedInt
    operator^(const unsigned int& x, const ComplexUnsignedInt& y ) {
    return ComplexUnsignedInt( x^real(y), x^imag(y) );
  }
  inline ComplexUnsignedLong
    operator^(const unsigned long& x, const ComplexUnsignedLong& y) {
    return ComplexUnsignedLong( x^real(y), x^imag(y)  );
  }
  inline ComplexUnsignedLongLong
    operator^(const unsigned long long& x, const ComplexUnsignedLongLong& y) {
    return ComplexUnsignedLongLong( x^real(y), x^imag(y)  );
  }

  // complex bitwise AND &
  inline ComplexUnsignedChar
    operator&(const ComplexUnsignedChar& x, const ComplexUnsignedChar& y) {
    return ComplexUnsignedChar( real(x)&real(y), imag(x)&imag(y)  );
  }
  inline ComplexUnsignedShort
  operator&(const ComplexUnsignedShort& x, const ComplexUnsignedShort& y) {
    return ComplexUnsignedShort( real(x)&real(y), imag(x)&imag(y)  );
  }
  inline ComplexUnsignedInt
  operator&(const ComplexUnsignedInt& x, const ComplexUnsignedInt& y) {
    return ComplexUnsignedInt( real(x)&real(y), imag(x)&imag(y)  );
  }
  inline ComplexUnsignedLong
  operator&(const ComplexUnsignedLong& x, const ComplexUnsignedLong& y) {
    return ComplexUnsignedLong( real(x)&real(y), imag(x)&imag(y)  );
  }
  inline ComplexUnsignedLongLong
  operator&(const ComplexUnsignedLongLong& x, const ComplexUnsignedLongLong& y) {
    return ComplexUnsignedLongLong( real(x)&real(y), imag(x)&imag(y)  );
  }
  // complex bitwise AND: complex Scalar ^ real scalar
  inline ComplexUnsignedChar
    operator&(const ComplexUnsignedChar& x, const unsigned char& y) {
    return ComplexUnsignedChar( real(x)&y, imag(x)&y );
  }
  inline ComplexUnsignedShort
  operator&(const ComplexUnsignedShort& x, const unsigned short& y) {
    return ComplexUnsignedShort( real(x)&y, imag(x)&y );
  }
  inline ComplexUnsignedInt
  operator&(const ComplexUnsignedInt& x, const unsigned int& y) {
    return ComplexUnsignedInt( real(x)&y, imag(x)&y );
  }
  inline ComplexUnsignedLong
  operator&(const ComplexUnsignedLong& x, const unsigned long& y) {
    return ComplexUnsignedLong( real(x)&y, imag(x)&y );
  }
  inline ComplexUnsignedLongLong
  operator&(const ComplexUnsignedLongLong& x, const unsigned long long& y) {
    return ComplexUnsignedLongLong( real(x)&y, imag(x)&y );
  }
  // complex bitwise AND: real scalar & complex Scalar
  inline ComplexUnsignedChar
    operator&(const unsigned char& x, const ComplexUnsignedChar& y) {
    return ComplexUnsignedChar( x&real(y), x&imag(y) );
  }
  inline ComplexUnsignedShort
    operator&(const unsigned short& x, const ComplexUnsignedShort& y) {
    return ComplexUnsignedShort( x&real(y), x&imag(y)  );
  }
  inline ComplexUnsignedInt
    operator&(const unsigned int& x, const ComplexUnsignedInt& y ) {
    return ComplexUnsignedInt( x&real(y), x&imag(y) );
  }
  inline ComplexUnsignedLong
    operator&(const unsigned long& x, const ComplexUnsignedLong& y) {
    return ComplexUnsignedLong( x&real(y), x&imag(y)  );
  }
  inline ComplexUnsignedLongLong
    operator&(const unsigned long long& x, const ComplexUnsignedLongLong& y) {
    return ComplexUnsignedLongLong( x&real(y), x&imag(y)  );
  }

  // complex bitwise shoft LEFT <<
  inline ComplexUnsignedChar
    operator<<(const ComplexUnsignedChar& x, const unsigned short& y) {
    return ComplexUnsignedChar( real(x)<<y, imag(x)<<y  );
  }
  inline ComplexUnsignedShort
  operator<<(const ComplexUnsignedShort& x, const unsigned short& y) {
    return ComplexUnsignedShort( real(x)<<y, imag(x)<<y  );
  }
  inline ComplexUnsignedInt
  operator<<(const ComplexUnsignedInt& x, const unsigned short& y) {
    return ComplexUnsignedInt( real(x)<<y, imag(x)<<y  );
  }
  inline ComplexUnsignedLong
  operator<<(const ComplexUnsignedLong& x, const unsigned short& y) {
    return ComplexUnsignedLong( real(x)<<y, imag(x)<<y  );
  }
  inline ComplexUnsignedLongLong
  operator<<(const ComplexUnsignedLongLong& x, const unsigned short& y) {
    return ComplexUnsignedLongLong( real(x)<<y, imag(x)<<y  );
  }
  
  // complex bitwise shoft RIGHT >>
  inline ComplexUnsignedChar
    operator>>(const ComplexUnsignedChar& x, const unsigned short& y) {
    return ComplexUnsignedChar( real(x)>>y, imag(x)>>y  );
  }
  inline ComplexUnsignedShort
  operator>>(const ComplexUnsignedShort& x, const unsigned short& y) {
    return ComplexUnsignedShort( real(x)>>y, imag(x)>>y  );
  }
  inline ComplexUnsignedInt
  operator>>(const ComplexUnsignedInt& x, const unsigned short& y) {
    return ComplexUnsignedInt( real(x)>>y, imag(x)>>y  );
  }
  inline ComplexUnsignedLong
  operator>>(const ComplexUnsignedLong& x, const unsigned short& y) {
    return ComplexUnsignedLong( real(x)>>y, imag(x)>>y  );
  }
  inline ComplexUnsignedLongLong
  operator>>(const ComplexUnsignedLongLong& x, const unsigned short& y) {
    return ComplexUnsignedLongLong( real(x)>>y, imag(x)>>y  );
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



  template <typename D> std::complex<D> sgn(const std::complex<D>& z) {
    return std::complex<D>( sgn(real(z)), sgn(imag(z)) );
  }

  template <typename D> std::complex<D> floor(const std::complex<D>& z) {
    using std::floor;
    return std::complex<D>( floor(real(z)), floor(imag(z)) );
  }

  template <typename D> std::complex<D> ceil(const std::complex<D>& z) {
    using std::ceil;
    return std::complex<D>( ceil(real(z)), ceil(imag(z)) );
  }

  
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
