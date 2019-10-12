#ifndef MATRICKS__MATH_IMAG_H
#define MATRICKS__MATH_IMAG_H


namespace matricks {



  // ***************************************************************************
  // *                   Imaginary Number
  // ***************************************************************************
  template <typename D> class Imaginary {
  private:
    D d_;
  public:    
    Imaginary() {
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

        // stream << operator

    friend std::ostream& operator<<(std::ostream &stream, const Imaginary<D>& w) {
      using namespace display;
      dispval_strm(stream, w.value());
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
    return x;
  }

  // Imaginary<D> + Imaginary<D>
  
  template <typename D> inline
    Imaginary<D>
    operator+(const Imaginary<D>& x1, const Imaginary<D>& x2) {
    return Imaginary<D>(x1.value()+x2.value());
  }

  // Imaginary<D1> - Imaginary<D2>
  
  template <typename D> inline
    Imaginary<D>
    operator-(const Imaginary<D>& x1, const Imaginary<D>& x2) {
    return Imaginary<D>(x1.value()-x2.value());
  }

  // Imaginary<D1> * Imaginary<D2>
  
  template <typename D> inline
    D
    operator*(const Imaginary<D>& x1, const Imaginary<D>& x2) {
    return x1.value()*x2.value();
  }

  // Imaginary<D> / Imaginary<D>
  
  template <typename D> inline
    D
    operator/(const Imaginary<D>& x1, const Imaginary<D>& x2) {
    return x1.value()*x2.value();
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
    Imaginary<typename DivType<D1,D2>::Type>
    operator/(const Imaginary<D1>& x1, const Imaginary<D2>& x2) {
    typedef typename DivType<D1,D2>::Type D3;
    return D3(x1.value()/x2.value());
  }


  // ***************************************************************************
  // * Imaginary arithmetic:  Imaginary<D1> OP R2
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



  // TODO:  unary functions like sin, cos, tab, round, etc
  

  
 
  
};


#endif
