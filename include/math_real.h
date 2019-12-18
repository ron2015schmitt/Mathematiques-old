#ifndef MATHQ__MATH_REAL_H
#define MATHQ__MATH_REAL_H


namespace mathq {


  // ***************************************************************************
  // *                   REAL MATH LIBRARY
  // ***************************************************************************


  
    // maximum subcript size for vectors and matrices (since we allow negative indexing)
  const size_type maxsize = std::numeric_limits<index_type>::max();
  const size_type badsize = std::numeric_limits<size_type>::max();


 /****************************************************************************
   * tolerances
   **************************************************************************** 
   */

  template <typename D> struct MatricksHelper {
  public:
    static D tolerance = D(0);
  };
  template <> struct MatricksHelper<long double> {
  public:
    constexpr static long double tolerance = 1.5e-30;
  };
  template <> struct MatricksHelper<double> {
  public:
    constexpr static double tolerance = 1.5e-16;
  };
  template <> struct MatricksHelper<float> {
  public:
    constexpr static float tolerance = 3.5e-7;
  };


 
  
  // TODO: C++17 has its own gcd gcf
  
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
  
  template <typename D, typename = std::enable_if_t<std::is_floating_point<D>::value>>
    D roundzero(const D& x, const D tolerance) {
    return (std::abs(x) < std::abs(tolerance) ? 0. : x);
  }


  // zero
  
  template <typename D, typename = std::enable_if_t<std::is_floating_point<D>::value>>
    D zero(const D& x) {
    return 0;
  }

  // imag
  
  template <typename D, typename = std::enable_if_t<std::is_floating_point<D>::value>>
    D imag(const D& x) {
    return 0;
  }

  
  // approx
  
  template <typename D, typename = std::enable_if_t<std::is_floating_point<D>::value>> bool approx(const D& x, const D& y, const D tolerance) {
    using std::abs;
    D tol = tolerance;
    D d = (abs(x)+abs(y))/2.;
    if (d > 1.) {
      tol *= d;
    }
    return (roundzero(abs(x-y), tol) == 0.);
  }

  // numbercast
  
  template <typename D2, typename D1,
    typename = std::enable_if_t<std::is_arithmetic<D1>::value>,
    typename = std::enable_if_t<std::is_arithmetic<D2>::value> >
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


  
 
  
};


#endif
