#ifndef MATRICKS__MATH_CPLX_H
#define MATRICKS__MATH_CPLX_H


namespace matricks {



  

  
  // ***************************************************************************
  // *                   COMPLEX MATH LIBRARY
  // ***************************************************************************

  //*******************************************************
  //          Typedefs
  //*******************************************************
  

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


 

  //*******************************************************
  //          Type-related functions and classes
  //*******************************************************

  

  // is_complex - text is an object is complex type (false)
  template<class T> struct is_complex : std::false_type {};

  // std::complex class (true)
  template<class D> struct is_complex<std::complex<D>> : std::true_type {};
  
  // T<std::complex> (true)  container holding complex
  template<template<typename> class T, class D> struct is_complex<T<std::complex<D> > > : std::true_type {};


  template <typename D> class Complexify {
  public:
    typedef std::complex<D> Type;
  };
  template <typename D> class Complexify<std::complex<D> > {
  public:
    typedef std::complex<D> Type;
  };
  template <template<typename> class T, typename D> class Complexify<T<D> > {
  public:
    typedef T<typename Complexify<D>::Type> Type;
  };
  template <typename D, typename A> class Complexify<TensorR<D,A> > {
  public:
    typedef TensorR<typename Complexify<D>::Type,A> Type;
  };


  template <typename D> class Realify {
  public:
    typedef D Type;
  };
  template <typename D> class Realify<std::complex<D> > {
  public:
    typedef D Type;
  };
  template <template<typename> class T, typename D> class Realify<T<D> > {
  public:
    typedef T<typename Realify<D>::Type> Type;
  };
  template <typename D, typename A> class Realify<TensorR<D,A> > {
  public:
    typedef TensorR<typename Realify<D>::Type,A> Type;
  };


  
  // numbercast
  
  template <typename D2, typename D1>
    std::complex<D2> numbercast(const std::complex<D1>& x) {
    using namespace std;
    return std::complex<D2>( numbercast<D2,D1>(real(x)), numbercast<D2,D1>(imag(x)) );
  }


  //*******************************************************
  //          unary math functions
  //*******************************************************



  // complex conjugate OPERTOR ~

  // TODO: rewrite using type traits and only floating types
  template <typename D, typename = std::enable_if_t<std::is_floating_point<D>::value> > std::complex<D>
  operator~(const std::complex<D>& x) {
    return std::complex<D>(x.real(), -x.imag());
  }


  // complex rounding

  template <typename D> std::complex<D> round(const std::complex<D>& x) {
    return std::complex<D>(std::round(x.real()), std::round(x.imag()));
  }

  // complex - sgn
  template <typename D> std::complex<D> sgn(const std::complex<D>& z) {
    return std::complex<D>( sgn(real(z)), sgn(imag(z)) );
  }

  // complex - floor
  template <typename D> std::complex<D> floor(const std::complex<D>& z) {
    using std::floor;
    return std::complex<D>( floor(real(z)), floor(imag(z)) );
  }

  // complex - ceil
  template <typename D> std::complex<D> ceil(const std::complex<D>& z) {
    using std::ceil;
    return std::complex<D>( ceil(real(z)), ceil(imag(z)) );
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


  // ***************************************************************************
  // * Complex arithmetic: complex<D1> OP complex<D2>
  // ***************************************************************************


  // complex<D1> + complex<D2>
  
  template <typename D1, typename D2> inline
    std::complex<typename AddType<D1,D2>::Type>
    operator+(const std::complex<D1>& x1, const std::complex<D2>& x2) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)+real(x2);
    D3 yI = imag(x1)+imag(x2);
    T3 y(yR,yI);
    return y;
  }

  // complex<D1> - complex<D2>
  
  template <typename D1, typename D2> inline
    std::complex<typename SubType<D1,D2>::Type>
    operator-(const std::complex<D1>& x1, const std::complex<D2>& x2) {
    typedef typename SubType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)-real(x2);
    D3 yI = imag(x1)-imag(x2);
    T3 y(yR,yI);
    return y;
  }

  // complex<D1> * complex<D2>
  
  template <typename D1, typename D2> inline
    std::complex<typename MultType<D1,D2>::Type>
    operator*(const std::complex<D1>& x1, const std::complex<D2>& x2) {
    typedef typename MultType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)*real(x2)-imag(x1)*imag(x2);
    D3 yI = real(x1)*imag(x2)+imag(x1)*real(x2);
    T3 y(yR,yI);
    return y;
  }


  // complex<D1> / complex<D2>
  
  template <typename D1, typename D2> inline
    std::complex<typename DivType<D1,D2>::Type>
    operator/(const std::complex<D1>& x1, const std::complex<D2>& x2) {
    typedef typename DivType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 topR = real(x1)*real(x2)+imag(x1)*imag(x2);
    D3 topI = -real(x1)*imag(x2)+imag(x1)*real(x2);
    D3 bot = real(x2)*real(x2)+imag(x2)*imag(x2);
    return T3(topR/bot,topI/bot);
  }


  // ***************************************************************************
  // * Complex arithmetic:  complex<D1> OP D2
  // *                              D1  OP complex<D2>
  // ***************************************************************************

  // complex<D1> + D2
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value> >inline
    std::complex<typename AddType<D1,D2>::Type>
    operator+(const std::complex<D1>& x1, const D2& x2) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)+x2;
    D3 yI = imag(x1);
    return T3(yR,yI);
  }

  // D1 + complex<D2>
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value> >inline
    std::complex<typename AddType<D1,D2>::Type>
    operator+(const D1& x1, const std::complex<D2>& x2) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = x1+real(x2);
    D3 yI = imag(x2);
    return T3(yR,yI);
  }


  // complex<D1> - D2
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value> >inline
    std::complex<typename SubType<D1,D2>::Type>
    operator-(const std::complex<D1>& x1, const D2& x2) {
    typedef typename SubType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)-x2;
    D3 yI = imag(x1);
    return T3(yR,yI);
  }

  // D1 - complex<D2>
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value> >inline
    std::complex<typename SubType<D1,D2>::Type>
    operator-(const D1& x1, const std::complex<D2>& x2) {
    typedef typename SubType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = x1-real(x2);
    D3 yI = -imag(x2);
    return T3(yR,yI);
  }


  // complex<D1> * D2
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value> >inline
    std::complex<typename MultType<D1,D2>::Type>
    operator*(const std::complex<D1>& x1, const D2& x2) {
    typedef typename MultType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)*x2;
    D3 yI = imag(x1)*x2;
    return T3(yR,yI);
  }

  // D1 * complex<D2>
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value> >inline
    std::complex<typename MultType<D1,D2>::Type>
    operator*(const D1& x1, const std::complex<D2>& x2) {
    typedef typename MultType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = x1*real(x2);
    D3 yI = x1*imag(x2);
    return T3(yR,yI);
  }


  // complex<D1> / D2
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value> >inline
    std::complex<typename DivType<D1,D2>::Type>
    operator/(const std::complex<D1>& x1, const D2& x2) {
    typedef typename DivType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)/x2;
    D3 yI = imag(x1)/x2;
    return T3(yR,yI);
  }

  // D1 / complex<D2>
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value> >inline
    std::complex<typename DivType<D1,D2>::Type>
    operator/(const D1& x1, const std::complex<D2>& x2) {
    typedef typename DivType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 topR = x1*real(x2);
    D3 topI = -x1*imag(x2);
    D3 bot = real(x2)*real(x2)+imag(x2)*imag(x2);
    return T3(topR/bot,topI/bot);
  }
  



 
  
};


#endif
