#ifndef MATHQ__MATH_IMAG_H
#define MATHQ__MATH_IMAG_H


namespace mathq {



  // ***************************************************************************
  // *                   Imaginary Number
  // ***************************************************************************
  template <typename D> class Imaginary {
  private:
    D d_;
  public:    
  Imaginary() : d_(1){
    }
  Imaginary(const D d) : d_(d) {
    }

    D value() const{
      return d_;
    }

    Imaginary<D>& negate() {
      d_ = -d_;
      return *this;
    }

    D operator=(const D& y) {
      return d_ = y.value();
    }

    inline static std::string classname()  {
      D d;
      return "Imaginary"+display::getBracketedTypeName(d);
    }




    // arithmetic operators
    Imaginary<D>& operator+=(const Imaginary<D>& y) {
      *this = *this + y;
      return *this;
    }

    Imaginary<D>& operator-=(const Imaginary<D>& y) {
      *this = *this - y;
      return *this;
    }


    Imaginary<D>& operator*=(const D& y) {
      *this = *this * y;
      return *this;
    }

    Imaginary<D>& operator/=(const D& y) {
      *this = *this / y;
      return *this;
    }



    
    // stream << operator

    friend std::ostream& operator<<(std::ostream &stream, const Imaginary<D>& w) {
      using namespace display;
      const D val = w.value();
      if (val != 1) {
	dispval_strm(stream, val);
      }
      // TODO: create style for the i
      stream << "i";
      return stream;
    }


    //template <class D>	
    friend inline std::istream& operator>>(const std::string s,  Imaginary<D>& w) {	
      std::istringstream st(s);
      return (st >> w);
    }


    // stream >> operator

    // TODO: implement this
    friend std::istream& operator>>(std::istream& stream,  Imaginary<D>& w) {	
      return stream;
    }


  }; 
  

  // ***************************************************************************
  // * i: the unit imaginary
  // ***************************************************************************


  namespace unit_imaginary {
    const Imaginary<float> iF(1);
    const Imaginary<double> i(1);
    const Imaginary<long double> iL(1);
  };



  // ***************************************************************************
  // numbercast
  // ***************************************************************************
  
  template <typename D2, typename D1>
    Imaginary<D2> numbercast(const Imaginary<D1>& x) {
    using namespace std;
    return Imaginary<D2>( numbercast<D2,D1>(x.value()) );
  }

  // ***************************************************************************
  // complexify
  // ***************************************************************************

  
  template <typename D> inline
    std::complex<D>
    complexify(const Imaginary<D>& x) {
    return std::complex<D>(0,x.value());
  }

  
  // ***************************************************************************
  // * Imaginary arithmetic: Imaginary<D>
  // ***************************************************************************

  // +Imaginary<D>
  
  template <typename D> inline
    Imaginary<D>
    operator+(const Imaginary<D>& x) {
    return x;
  }

  // -Imaginary<D>
  
  template <typename D> inline
    Imaginary<D>
    operator-(const Imaginary<D>& x) {
    Imaginary<D> y = x;
    return y.negate();
  }


  // ***************************************************************************
  // * Imaginary arithmetic: Imaginary<D1> OP Imaginary<D2>
  // ***************************************************************************


  // Imaginary<D1> + Imaginary<D2>
  
  template <typename D1, typename D2> inline
    Imaginary<typename AddType<D1,D2>::Type>
    operator+(const Imaginary<D1>& x1, const Imaginary<D2>& x2) {
    typedef typename AddType<D1,D2>::Type D3;
    return Imaginary<D3>(x1.value()+x2.value());
  }

  // Imaginary<D1> - Imaginary<D2>
  
  template <typename D1, typename D2> inline
    Imaginary<typename SubType<D1,D2>::Type>
    operator-(const Imaginary<D1>& x1, const Imaginary<D2>& x2) {
    typedef typename SubType<D1,D2>::Type D3;
    return Imaginary<D3>(x1.value()-x2.value());
  }

  // Imaginary<D1> * Imaginary<D2>
  
  template <typename D1, typename D2> inline
    typename MultType<D1,D2>::Type
    operator*(const Imaginary<D1>& x1, const Imaginary<D2>& x2) {
    typedef typename MultType<D1,D2>::Type D3;
    return -D3(x1.value()*x2.value());
  }


  // Imaginary<D1> / Imaginary<D2>
  
  template <typename D1, typename D2> inline
    typename DivType<D1,D2>::Type
    operator/(const Imaginary<D1>& x1, const Imaginary<D2>& x2) {
    typedef typename DivType<D1,D2>::Type D3;
    return D3(x1.value()/x2.value());
  }




  

  // ***************************************************************************
  // * Imaginary-Real arithmetic:  Imaginary<D1> OP R2
  // *                                  R1  OP Imaginary<D2>
  // ***************************************************************************

  // Imaginary<D1> + R2
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value> >inline
    std::complex<typename AddType<D1,D2>::Type>
    operator+(const Imaginary<D1>& xi, const D2& xr) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    return T3(xr,xi.value());
  }

  // D1 + Imaginary<D2>
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value> >inline
    std::complex<typename AddType<D1,D2>::Type>
    operator+(const D1& xr, const Imaginary<D2>& xi) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    return T3(xr,xi.value());
  }


  // Imaginary<D1> - D2
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value> >inline
    std::complex<typename AddType<D1,D2>::Type>
    operator-(const Imaginary<D1>& xi, const D2& xr) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    return T3(-xr,xi.value());
  }

  // D1 - Imaginary<D2>
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value> >inline
    std::complex<typename AddType<D1,D2>::Type>
    operator-(const D1& xr, const Imaginary<D2>& xi) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    return T3(xr,-xi.value());
  }


  // Imaginary<D1> * D2
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value> >inline
    Imaginary<typename MultType<D1,D2>::Type>
    operator*(const Imaginary<D1>& x1, const D2& x2) {
    typedef typename MultType<D1,D2>::Type D3;
    typedef Imaginary<D3> T3;
    return T3(x1.value()*x2);
  }

  // D1 * Imaginary<D2>
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value> >inline
    Imaginary<typename MultType<D1,D2>::Type>
    operator*(const D1& x1, const Imaginary<D2>& x2) {
    typedef typename MultType<D1,D2>::Type D3;
    typedef Imaginary<D3> T3;
    return T3(x1*x2.value());
  }


  // Imaginary<D1> / D2
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value> >inline
    Imaginary<typename DivType<D1,D2>::Type>
    operator/(const Imaginary<D1>& x1, const D2& x2) {
    typedef typename DivType<D1,D2>::Type D3;
    typedef Imaginary<D3> T3;
    return T3(x1.value()/x2);
  }

  // D1 / Imaginary<D2>
  
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value> >inline
    Imaginary<typename DivType<D1,D2>::Type>
    operator/(const D1& x1, const Imaginary<D2>& x2) {
    typedef typename DivType<D1,D2>::Type D3;
    typedef Imaginary<D3> T3;
    return T3(-x1/x2.value());
  }


  // ***************************************************************************
  // * Imaginary arithmetic:  Imaginary<D1> OP complex<D2>
  // *                          complex<D1> OP Imaginary<D2>
  // ***************************************************************************

  // Imaginary<D1> + complex<D2>
  
  template <typename D1, typename D2> inline
    std::complex<typename AddType<D1,D2>::Type>
    operator+(const Imaginary<D1>& xi, const std::complex<D2>& z) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    return T3(real(z),xi.value()+imag(z));
  }

  // complex<D1> + Imaginary<D2>
  template <typename D1, typename D2> inline
    std::complex<typename AddType<D1,D2>::Type>
    operator+(const std::complex<D2>& z, const Imaginary<D1>& xi) {
    typedef typename AddType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    return T3(real(z),imag(z)+xi.value());
  }
  

  // Imaginary<D1> - complex<D2>
  
  template <typename D1, typename D2> inline
    std::complex<typename SubType<D1,D2>::Type>
    operator-(const Imaginary<D1>& xi, const std::complex<D2>& z) {
    typedef typename SubType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    return T3(-real(z),xi.value()-imag(z));
  }

  // complex<D1> - Imaginary<D2>
  
  template <typename D1, typename D2> inline
    std::complex<typename SubType<D1,D2>::Type>
    operator-(const std::complex<D2>& z, const Imaginary<D1>& xi) {
    typedef typename SubType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    return T3(real(z),imag(z)-xi.value());
  }


  // Imaginary<D1> * complex<D2>
  
  template <typename D1, typename D2> inline
    std::complex<typename MultType<D1,D2>::Type>
    operator*(const Imaginary<D1>& xi, const std::complex<D2>& z) {
    typedef typename MultType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    return T3(-xi.value()*imag(z),xi.value()*real(z));
  }

  
  // complex<D2> * Imaginary<D1>
  
  template <typename D1, typename D2> inline
    std::complex<typename MultType<D1,D2>::Type>
    operator*(const std::complex<D2>& z, const Imaginary<D1>& xi) {
    typedef typename MultType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    return T3(-imag(z)*xi.value(),real(z)*xi.value());
  }


  // Imaginary<D1> / complex<D2>
  
  template <typename D1, typename D2> inline
    std::complex<typename DivType<D1,D2>::Type>
    operator/(const Imaginary<D1>& xi, const std::complex<D2>& z) {
    typedef typename DivType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    return T3(-xi.value()*imag(z),xi.value()*real(z));
  }
  
  // complex<D2> / Imaginary<D1>
  
  template <typename D1, typename D2> inline
    std::complex<typename DivType<D1,D2>::Type>
    operator/(const std::complex<D2>& z, const Imaginary<D1>& xi) {
    typedef typename DivType<D1,D2>::Type D3;
    typedef typename std::complex<D3> T3;
    D3 topR = xi.value()*imag(z);
    D3 topI = xi.value()*real(z);
    D3 bot = real(z)*real(z)+imag(z)*imag(z);
    return T3(topR/bot,topI/bot);
  }
  


  //*******************************************************
  //          Typedefs
  //*******************************************************
  

  typedef Imaginary<float> ImFloat;
  typedef Imaginary<double> ImDouble;
  typedef Imaginary<long double> ImLongDouble;
  typedef Imaginary<char> ImChar;
  typedef Imaginary<signed char> ImSignedChar;
  typedef Imaginary<short> ImShort;
  typedef Imaginary<int> ImInt;
  typedef Imaginary<long> ImLong;
  typedef Imaginary<long long> ImLongLong;
  typedef Imaginary<unsigned char> ImUnsignedChar;
  typedef Imaginary<unsigned short> ImUnsignedShort;
  typedef Imaginary<unsigned int> ImUnsignedInt;
  typedef Imaginary<unsigned long> ImUnsignedLong;
  typedef Imaginary<unsigned long long> ImUnsignedLongLong;



  //*******************************************************
  //          unary funcs
  //*******************************************************
  
  // real(z)
  
  template <typename D> inline
    D real(const Imaginary<D>& z) {
    return 0;
  }

  // imag(z)
  
  template <typename D> inline
    D imag(const Imaginary<D>& z) {
    return z.value();
  }
  
  // arg(z)  -  this is pi/2, but let the std library calculate
  //            since we don't know data type
  
  template <typename D> inline
    D arg(const Imaginary<D>& z) {
    using std::arg;
    std::complex<D> dummy(0,1);
    return arg(dummy);
  }


  // abs(z)
  
  template <typename D> inline
    D abs(const Imaginary<D>& z) {
    using std::abs;
    return abs(z.value());
  }

  // norm(z) - the C++ std defines norm as magnitude squared,
  //           going against mathematics convention
  
  template <typename D> inline
    D norm(const Imaginary<D>& z) {
    using std::abs;
    D x = abs(z);
    return x*x;
  }


  // conj(z)  - we go against C++  convention
  //            Note: C++ std lib returns complex number for conj(real)
  
  template <typename D> inline
    Imaginary<D>
    conj(const Imaginary<D>& z) {
    return -z;
  }



  // complex conjugate OPERTOR ~

  template <typename D, typename = std::enable_if_t<std::is_floating_point<D>::value> > Imaginary<D>
  operator~(const Imaginary<D>& z) {
    return conj(z);
  }



  // polar(z)  

  template <typename D> inline
    std::complex<D>
    polar(const Imaginary<D>& z) {
    return std::complex(abs(z), arg(z));
  }

  // exp(z)  

  template <typename D> inline
    std::complex<D>
    exp(const Imaginary<D>& z) {
    const D& val = z.value(); 
    return std::complex(cos(val), sin(val));
  }

  // log(z)  

  template <typename D> inline
    std::complex<D>
    log(const Imaginary<D>& z) {
    using std::log;
    using std::arg;
    const D& val = z.value();
    return std::complex(log(val), arg(z) );
  }


  // log10
  template <typename D>
    std::complex<D>
    log10(const Imaginary<D>& z) {
    using std::log;
    const D A0 = 1/log(D(10));
    return A0*log(z);
  }


  // log2
  template <typename D>
    std::complex<D>
    log2(const Imaginary<D>& z) {
    using std::log;
    const D A0 = 1/log(D(2));
    return A0*log(z);
  }


  // pow(I1,I2)
  template <typename D1, typename D2> inline
    std::complex<typename MultType<D1,D2>::Type>
    pow(const Imaginary<D1>& x1, const Imaginary<D2>& x2) {
    using std::pow;
    typedef typename MultType<D1,D2>::Type D3;
    return pow(
	       complexify(numbercast<D3>(x1)),
	       complexify(numbercast<D3>(x2)) );
  }


  // pow(I1,R2)
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D2>::value> >inline
    std::complex<typename MultType<D1,D2>::Type>
    pow(const Imaginary<D1>& x1, const D2& x2) {
    using std::pow;
    typedef typename MultType<D1,D2>::Type D3;
    return pow(
	       complexify(numbercast<D3>(x1)),
	       numbercast<D3>(x2) );
  }

  // pow(R1,I2)
  template <typename D1, typename D2, typename = std::enable_if_t<std::is_arithmetic<D1>::value> >inline
    std::complex<typename MultType<D1,D2>::Type>
    pow(const D1& x1, const Imaginary<D2>& x2) {
    using std::pow;
    typedef typename MultType<D1,D2>::Type D3;
    return pow(
	       numbercast<D3>(x1),
	       complexify(numbercast<D3>(x2)) );
  }

  
  // pow(I1,C2)
  template <typename D1, typename D2> inline
    std::complex<typename MultType<D1,D2>::Type>
    pow(const Imaginary<D1>& x1, const std::complex<D2>& x2) {
    using std::pow;
    typedef typename MultType<D1,D2>::Type D3;
    return pow(
	       complexify(numbercast<D3>(x1)),
	       numbercast<D3>(x2) );
  }

  // pow(C1,I2)
  template <typename D1, typename D2> inline
    std::complex<typename MultType<D1,D2>::Type>
    pow(const std::complex<D1>& x1, const Imaginary<D2>& x2) {
    using std::pow;
    typedef typename MultType<D1,D2>::Type D3;
    return pow(
	       numbercast<D3>(x1),
	       complexify(numbercast<D3>(x2)) );
  }

  
  // sqrt
  template <typename D>
    std::complex<D>
    sqrt(const Imaginary<D>& z) {
    using std::sqrt;
    const D A0 = sqrt(z.value()/2);
    return A0*std::complex<D>(1,1);
  }


  // sqr
  template <typename D>
    D sqr(const Imaginary<D>& z) {
    return -z.value()*z.value();
  }

  // cube
  template <typename D>
    Imaginary<D> cube(const Imaginary<D>& z) {
    return Imaginary<D>(-z.value()*z.value()*z.value());
  }

  


  // sin
  template <typename D>
    Imaginary<D>
    sin(const Imaginary<D>& z) {
    using std::sin;
    return Imaginary<D>( sin(z.value()) );
  }

  // cos
  template <typename D>
    D
    cos(const Imaginary<D>& z) {
    using std::cos;
    return cos(z.value());
  }

  // tan
  template <typename D>
    Imaginary<D>
    tan(const Imaginary<D>& z) {
    using std::tan;
    return Imaginary<D>( tan(z.value()) );
  }

  // asin
  template <typename D>
    Imaginary<D>
    asin(const Imaginary<D>& z) {
    using std::asin;
    return Imaginary<D>( asin(z.value()) );
  }

  // acos
  template <typename D>
    std::complex<D>
    acos(const Imaginary<D>& z) {
    using std::acos;
    return acos(complexify(z));
  }

  // atan
  template <typename D>
    std::complex<D>
    atan(const Imaginary<D>& z) {
    using std::atan;
    return atan(complexify(z));
  }

  // atan2
  template <typename D>
    std::complex<D>
    atan2(const Imaginary<D>& z) {
    using std::atan2;
    return atan2(z.value(),0);
  }


  
  // sinh
  template <typename D>
    Imaginary<D>
    sinh(const Imaginary<D>& z) {
    using std::sinh;
    return Imaginary<D>( sinh(z.value()) );
  }

  // cosh
  template <typename D>
    D
    cosh(const Imaginary<D>& z) {
    using std::cosh;
    return cosh(z.value());
  }

  // tanh
  template <typename D>
    Imaginary<D>
    tanh(const Imaginary<D>& z) {
    using std::tanh;
    return Imaginary<D>( tanh(z.value()) );
  }


  // asinh
  template <typename D>
    std::complex<D>
    asinh(const Imaginary<D>& z) {
    using std::asinh;
    return asinh(complexify(z));
  }

  // acosh
  template <typename D>
    std::complex<D>
    acosh(const Imaginary<D>& z) {
    using std::acosh;
    return acosh(complexify(z));
  }

  // atanh
  template <typename D>
    std::complex<D>
    atanh(const Imaginary<D>& z) {
    using std::atanh;
    return atanh(complexify(z));
  }


  

  // imaginary rounding

  template <typename D> Imaginary<D> round(const Imaginary<D>& x) {
    using std::round;
    return Imaginary<D>(round(x.value()) );
  }

  // Imaginary - sgn
  template <typename D> Imaginary<D> sgn(const Imaginary<D>& z) {
    return Imaginary<D>( sgn(z.value()) );
  }

  // Imaginary - floor
  template <typename D> Imaginary<D> floor(const Imaginary<D>& z) {
    using std::floor;
    return Imaginary<D>( floor(z.value()) );
  }

  // Imaginary - ceil
  template <typename D> Imaginary<D> ceil(const Imaginary<D>& z) {
    using std::ceil;
    return Imaginary<D>( ceil(z.value()) );
  }



  // Imaginary - roundzero
  template <typename D> Imaginary<D> roundzero(const Imaginary<D>& x, const D tolerance) {
    return Imaginary<D>(roundzero(x.value(),tolerance));
  }

    // approx - Imaginary
  
  template <typename D> bool approx(const Imaginary<D>& x, const Imaginary<D>& y, const D tolerance) {
    return approx(x.value(),y.value(),tolerance);
  }



  
};


#endif
