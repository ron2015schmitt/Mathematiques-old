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


  // complex conjugate
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
  // * Complex math operators of mixed base types (D1,D2)
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
    printf("D1=%s D2=%s D3=%s \n",typeid(D1).name(),typeid(D2).name(),typeid(D3).name());
    D3 topR = real(x1)*real(x2)+imag(x1)*imag(x2);
    D3 topI = -real(x1)*imag(x2)+imag(x1)*real(x2);
    D3 bot = real(x2)*real(x2)+imag(x2)*imag(x2);
    return T3(topR/bot,topI/bot);
  }




  // *********************************************************************
  // * Complex bitwise math
  // *********************************************************************

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

 
  
};


#endif
