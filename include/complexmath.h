#ifndef MATRICKS__COMPLEXMATH_H
#define MATRICKS__COMPLEXMATH_H


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


  // is_complex - text is an object is complex type
  template<class T> struct is_complex : std::false_type {};
  template<class T> struct is_complex<std::complex<T>> : std::true_type {};

  
  // numbercast
  
  template <typename D2, typename D1>
    std::complex<D2> numbercast(const std::complex<D1>& x) {
    using std::real;
    using std::imag;
    return std::complex<D2>( numbercast<D2,D1>(real(x)), numbercast<D2,D1>(imag(x)) );
  }


  // C++ does not have "instanceof" type guarding so even if it
  // can't get to the code it will produce a compile error
  template <typename D> D matricksconj(const D& x) {
    return x;
  }
  template <typename D> std::complex<D> matricksconj(const std::complex<D>& z) {
    return std::conj(z);
  }


  // complex conjugate OPERTOR ~

  // TODO: rewrite using type traits and only floating types
  template <typename D> std::complex<D>
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
  // * Complex math: complex<D1> OP complex<D2>
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
  // * Complex math: complex<D1> OP D2
  // *                        D1 OP complex<D2>
  // ***************************************************************************

  // complex<D1> + D2
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_fundamental<D2>::value> >inline
    std::complex<typename AddType<D1,D2>::Type>
    operator+(const std::complex<D1>& x1, const D2& x2) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)+x2;
    D3 yI = imag(x1);
    return T3(yR,yI);
  }

  // D1 + complex<D2>
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_fundamental<D1>::value> >inline
    std::complex<typename AddType<D1,D2>::Type>
    operator+(const D1& x1, const std::complex<D2>& x2) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = x1+real(x2);
    D3 yI = imag(x2);
    return T3(yR,yI);
  }


  // complex<D1> - D2
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_fundamental<D2>::value> >inline
    std::complex<typename SubType<D1,D2>::Type>
    operator-(const std::complex<D1>& x1, const D2& x2) {
    typedef typename SubType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)-x2;
    D3 yI = imag(x1);
    return T3(yR,yI);
  }

  // D1 - complex<D2>
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_fundamental<D1>::value> >inline
    std::complex<typename SubType<D1,D2>::Type>
    operator-(const D1& x1, const std::complex<D2>& x2) {
    typedef typename SubType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = x1-real(x2);
    D3 yI = -imag(x2);
    return T3(yR,yI);
  }


  // complex<D1> * D2
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_fundamental<D2>::value> >inline
    std::complex<typename MultType<D1,D2>::Type>
    operator*(const std::complex<D1>& x1, const D2& x2) {
    typedef typename MultType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)*x2;
    D3 yI = imag(x1)*x2;
    return T3(yR,yI);
  }

  // D1 * complex<D2>
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_fundamental<D1>::value> >inline
    std::complex<typename MultType<D1,D2>::Type>
    operator*(const D1& x1, const std::complex<D2>& x2) {
    typedef typename MultType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = x1*real(x2);
    D3 yI = x1*imag(x2);
    return T3(yR,yI);
  }


  // complex<D1> / D2
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_fundamental<D2>::value> >inline
    std::complex<typename DivType<D1,D2>::Type>
    operator/(const std::complex<D1>& x1, const D2& x2) {
    typedef typename DivType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 yR = real(x1)/x2;
    D3 yI = imag(x1)/x2;
    return T3(yR,yI);
  }

  // D1 / complex<D2>
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_fundamental<D1>::value> >inline
    std::complex<typename DivType<D1,D2>::Type>
    operator/(const D1& x1, const std::complex<D2>& x2) {
    typedef typename DivType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 topR = x1*real(x2);
    D3 topI = -x1*imag(x2);
    D3 bot = real(x2)*real(x2)+imag(x2)*imag(x2);
    return T3(topR/bot,topI/bot);
  }
  


  // *********************************************************************
  // * Complex bitwise math
  // *********************************************************************

  // TODO: rewrite using type traits. integral types only
  
  // complex bitwise NOT ~
  inline ComplexUnsignedChar
  operator~(const ComplexUnsignedChar& x) {
    return ComplexUnsignedChar( ~real(x), ~imag(x)  );
  }
  // complex bitwise OR |
  inline ComplexUnsignedChar
    operator|(const ComplexUnsignedChar& x, const ComplexUnsignedChar& y) {
    return ComplexUnsignedChar( real(x)|real(y), imag(x)|imag(y)  );
  }
  // complex bitwise OR: complex Scalar | real scalar
  inline ComplexUnsignedChar
    operator|(const ComplexUnsignedChar& x, const unsigned char& y) {
    return ComplexUnsignedChar( real(x)|y, imag(x)|y );
  }
  // complex bitwise OR: real scalar | complex Scalar
  inline ComplexUnsignedChar
    operator|(const unsigned char& x, const ComplexUnsignedChar& y) {
    return ComplexUnsignedChar( x|real(y), x|imag(y) );
  }
  // complex bitwise XOR ^
  inline ComplexUnsignedChar
    operator^(const ComplexUnsignedChar& x, const ComplexUnsignedChar& y) {
    return ComplexUnsignedChar( real(x)^real(y), imag(x)^imag(y)  );
  }
  // complex bitwise XOR: complex Scalar ^ real scalar
  inline ComplexUnsignedChar
    operator^(const ComplexUnsignedChar& x, const unsigned char& y) {
    return ComplexUnsignedChar( real(x)^y, imag(x)^y );
  }
  // complex bitwise XOR: real scalar ^ complex Scalar
  inline ComplexUnsignedChar
    operator^(const unsigned char& x, const ComplexUnsignedChar& y) {
    return ComplexUnsignedChar( x^real(y), x^imag(y) );
  }

  // complex bitwise AND &
  inline ComplexUnsignedChar
    operator&(const ComplexUnsignedChar& x, const ComplexUnsignedChar& y) {
    return ComplexUnsignedChar( real(x)&real(y), imag(x)&imag(y)  );
  }
  // complex bitwise AND: complex Scalar ^ real scalar
  inline ComplexUnsignedChar
    operator&(const ComplexUnsignedChar& x, const unsigned char& y) {
    return ComplexUnsignedChar( real(x)&y, imag(x)&y );
  }
  // complex bitwise AND: real scalar & complex Scalar
  inline ComplexUnsignedChar
    operator&(const unsigned char& x, const ComplexUnsignedChar& y) {
    return ComplexUnsignedChar( x&real(y), x&imag(y) );
  }

  // complex bitwise shoft LEFT <<
  inline ComplexUnsignedChar
    operator<<(const ComplexUnsignedChar& x, const unsigned short& y) {
    return ComplexUnsignedChar( real(x)<<y, imag(x)<<y  );
  }
  
  // complex bitwise shoft RIGHT >>
  inline ComplexUnsignedChar
    operator>>(const ComplexUnsignedChar& x, const unsigned short& y) {
    return ComplexUnsignedChar( real(x)>>y, imag(x)>>y  );
  }

 
  
};


#endif
