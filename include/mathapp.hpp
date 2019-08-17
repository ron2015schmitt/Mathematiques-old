#ifndef MATHAPP_H
#define MATHAPP_H



//#include <cmath>
#include <tgmath.h>
#include <string>



namespace Matricks {


  /****************************************************************************
   *              Binary applicative templates 
   ****************************************************************************/


  // y = pow(a,b)  
  // ie. a raised to the b power

  template <class DataT> class ApPow {
  public:
    ApPow() { }
    static inline DataT apply(DataT a, DataT b) { 
      using std::pow;
      return pow(a,b); 
    }


    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout = "pow( " + sa + " , " + sb + " )";
      return sout;
    }
  };



    // y = atan2(a,b)  

  template <class DataT> class ApAtan2 {
  public:
    ApAtan2() { }
    static inline DataT apply(DataT a, DataT b) { 
      using std::atan2;
      return atan2(a,b); 
    }


    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout = "atan2( " + sa + " , " + sb + " )";
      return sout;
    }
  };







  /****************************************************************************
   *              unary applicative templates 
   ****************************************************************************/




  // sin(a)

  template <class DataT> class ApSin {
  public:
    ApSin() { }

    static inline DataT apply(DataT a) { 
      using std::sin;
      return sin(a); 
    }

    static std::string debugtxt(const std::string& sa) {
      std::string sout = "sin(" + sa + ")";
      return sout;
    }

  };


  // cos(a)

  template <class DataT> class ApCos {
  public:
    ApCos() { }

    static inline DataT apply(DataT a) { 
      using std::cos;
      return std::cos(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "cos(" + sa + ")";
      return sout;
    }

  };




  // tan(a)

  template <class DataT> class ApTan {
  public:
    ApTan() { }

    static inline DataT apply(DataT a) { 
      using std::tan;
      return std::tan(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "tan(" + sa + ")";
      return sout;
    }

  };


  // sqrt(a)

  template <class DataT> class ApSqrt {
  public:
    ApSqrt() { }

    static inline DataT apply(DataT a) { 
      using std::sqrt;
      return std::sqrt(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "sqrt(" + sa + ")";
      return sout;
    }

  };


  // sqr(a)

  template <class DataT> class ApSqr {
  public:
    ApSqr() { }

    static inline DataT apply(DataT a) { 
      return (a*a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "sqr(" + sa + ")";
      return sout;
    }

  };


  // cube(a)

  template <class DataT> class ApCube {
  public:
    ApCube() { }

    static inline DataT apply(DataT a) { 
      return (a*a*a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "cube(" + sa + ")";
      return sout;
    }

  };


  // exp(a)
  template <class DataT> class ApExp {
  public:
    ApExp() { }
    
    static inline DataT apply(DataT a) {
      using std::exp;
      return std::exp(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "exp(" + sa + ")";
      return sout;
    }

  };


  // abs(a)

  template <class DataT> class ApAbs {
  public:
    ApAbs() { }

    static inline DataT apply(DataT a) {
      using std::abs;
      return std::abs(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "abs(" + sa + ")";
      return sout;
    }

  };

  // sgn(a)

  template <class DataT> class ApSign {
  public:
    ApSign() { }

    static inline DataT apply(DataT a) {
      return Matricks::sgn(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "sgn(" + sa + ")";
      return sout;
    }

  };

  // log(a)

  template <class DataT> class ApLog {
  public:
    ApLog() { }

    static inline DataT apply(DataT a) {
      using std::log;
      return std::log(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "log(" + sa + ")";
      return sout;
    }

  };

  // log2(a)

  template <class DataT> class ApLog2 {
  public:
    ApLog2() { }

    static inline DataT apply(DataT a) {
      using std::log;
      return std::log2(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "log2(" + sa + ")";
      return sout;
    }

  };


  // log10(a)

  template <class DataT> class ApLog10 {
  public:
    ApLog10() { }

    static inline DataT apply(DataT a) {
      using std::log10;
      return std::log10(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "log10(" + sa + ")";
      return sout;
    }

  };

  // asin(a)

  template <class DataT> class ApAsin {
  public:
    ApAsin() { }

    static inline DataT apply(DataT a) {
      using std::asin;
      return std::asin(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "asin(" + sa + ")";
      return sout;
    }

  };

 // acos(a)

  template <class DataT> class ApAcos {
  public:
    ApAcos() { }

    static inline DataT apply(DataT a) {
      using std::acos;
      return std::acos(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "acos(" + sa + ")";
      return sout;
    }

  };

  // atan(a)

  template <class DataT> class ApAtan {
  public:
    ApAtan() { }

    static inline DataT apply(DataT a) {
      using std::atan;
      return std::atan(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "atan(" + sa + ")";
      return sout;
    }

  };


  // ceil(a)

  template <class DataT> class ApCeil {
  public:
    ApCeil() { }

    static inline DataT apply(DataT a) { 
      using std::ceil;
      return std::ceil(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "ceil(" + sa + ")";
      return sout;
    }

  };
  // floor(a)

  template <class DataT> class ApFloor {
  public:
    ApFloor() { }

    static inline DataT apply(DataT a) { 
      using std::floor;
      return std::floor(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "floor(" + sa + ")";
      return sout;
    }

  };
  // round(a)

  template <class DataT> class ApRound {
  public:
    ApRound() { }

    static inline DataT apply(DataT a) { 
      return std::round(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "round(" + sa + ")";
      return sout;
    }

  };
  // sinh(a)

  template <class DataT> class ApSinh {
  public:
    ApSinh() { }

    static inline DataT apply(DataT a) { 
      using std::sinh;
      return std::sinh(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "sinh(" + sa + ")";
      return sout;
    }

  };
  // cosh(a)

  template <class DataT> class ApCosh {
  public:
    ApCosh() { }

    static inline DataT apply(DataT a) { 
      using std::cosh;
      return std::cosh(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "cosh(" + sa + ")";
      return sout;
    }

  };
  // tanh(a)

  template <class DataT> class ApTanh {
  public:
    ApTanh() { }

    static inline DataT apply(DataT a) { 
      using std::tanh;
      return std::tanh(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "tanh(" + sa + ")";
      return sout;
    }

  };






};

#endif

