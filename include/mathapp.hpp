#ifndef MATHAPP_H
#define MATHAPP_H



//#include <cmath>
#include <ctgmath>
#include <string>



namespace matricks {


  template<class D>
  struct TypeHelper {
    typedef D(*unary_func)(D);
    typedef D(*binary_func)(D, D);
  };


  /****************************************************************************
   *              Binary applicative templates 
   ****************************************************************************/


  // y = op2<D,userfunc>(a,b)
  template <class D, typename TypeHelper<D>::binary_func F> class ApFun2 {
  public:
    ApFun2() { }
    static inline D apply(D a, D b) { 
      return F(a,b); 
    }


    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout =std::string("op2<")+ stringify(D)+","+ stringify(F) +">(" + sa + " , " + sb + ")";
       return sout;
    }
  };


  // y = pow(a,b)  
  // ie. a raised to the b power

  template <class D> class ApPow {
  public:
    ApPow() { }
    static inline D apply(D a, D b) { 
      using std::pow;
      return pow(a,b); 
    }


    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout = "pow( " + sa + " , " + sb + " )";
      return sout;
    }
  };



    // y = atan2(a,b)  

  template <class D> class ApAtan2 {
  public:
    ApAtan2() { }
    static inline D apply(D a, D b) { 
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



  
    // y = op1<D,userfunc>(a)

  template <class D, typename TypeHelper<D>::unary_func F> class ApFun1 {
  public:
    ApFun1() { }

    static inline D apply(D a) { 
      return F(a); 
    }

    static std::string debugtxt(const std::string& sa) {
      std::string sout =std::string("op1<")+  typeid(D).name()+","+typeid(F).name() +">(" + sa + ")";
      return sout;
    }

  };



  // sin(a)

  template <class D> class ApSin {
  public:
    ApSin() { }

    static inline D apply(D a) { 
      using std::sin;
      return sin(a); 
    }

    static std::string debugtxt(const std::string& sa) {
      std::string sout = "sin(" + sa + ")";
      return sout;
    }

  };


  // cos(a)

  template <class D> class ApCos {
  public:
    ApCos() { }

    static inline D apply(D a) { 
      using std::cos;
      return std::cos(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "cos(" + sa + ")";
      return sout;
    }

  };




  // tan(a)

  template <class D> class ApTan {
  public:
    ApTan() { }

    static inline D apply(D a) { 
      using std::tan;
      return std::tan(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "tan(" + sa + ")";
      return sout;
    }

  };


  // sqrt(a)

  template <class D> class ApSqrt {
  public:
    ApSqrt() { }

    static inline D apply(D a) { 
      using std::sqrt;
      return std::sqrt(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "sqrt(" + sa + ")";
      return sout;
    }

  };


  // sqr(a)

  template <class D> class ApSqr {
  public:
    ApSqr() { }

    static inline D apply(D a) { 
      return (a*a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "sqr(" + sa + ")";
      return sout;
    }

  };


  // cube(a)

  template <class D> class ApCube {
  public:
    ApCube() { }

    static inline D apply(D a) { 
      return (a*a*a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "cube(" + sa + ")";
      return sout;
    }

  };


  // exp(a)
  template <class D> class ApExp {
  public:
    ApExp() { }
    
    static inline D apply(D a) {
      using std::exp;
      return std::exp(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "exp(" + sa + ")";
      return sout;
    }

  };


  // abs(a)

  template <class D> class ApAbs {
  public:
    ApAbs() { }

    static inline D apply(D a) {
      using std::abs;
      return std::abs(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "abs(" + sa + ")";
      return sout;
    }

  };

  // sgn(a)

  template <class D> class ApSign {
  public:
    ApSign() { }

    static inline D apply(D a) {
      return matricks::sgn(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "sgn(" + sa + ")";
      return sout;
    }

  };

  // log(a)

  template <class D> class ApLog {
  public:
    ApLog() { }

    static inline D apply(D a) {
      using std::log;
      return std::log(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "log(" + sa + ")";
      return sout;
    }

  };

  // log2(a)

  template <class D> class ApLog2 {
  public:
    ApLog2() { }

    static inline D apply(D a) {
      using std::log;
      return std::log2(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "log2(" + sa + ")";
      return sout;
    }

  };


  // log10(a)

  template <class D> class ApLog10 {
  public:
    ApLog10() { }

    static inline D apply(D a) {
      using std::log10;
      return std::log10(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "log10(" + sa + ")";
      return sout;
    }

  };

  // asin(a)

  template <class D> class ApAsin {
  public:
    ApAsin() { }

    static inline D apply(D a) {
      using std::asin;
      return std::asin(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "asin(" + sa + ")";
      return sout;
    }

  };

 // acos(a)

  template <class D> class ApAcos {
  public:
    ApAcos() { }

    static inline D apply(D a) {
      using std::acos;
      return std::acos(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "acos(" + sa + ")";
      return sout;
    }

  };

  // atan(a)

  template <class D> class ApAtan {
  public:
    ApAtan() { }

    static inline D apply(D a) {
      using std::atan;
      return std::atan(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "atan(" + sa + ")";
      return sout;
    }

  };


  // ceil(a)

  template <class D> class ApCeil {
  public:
    ApCeil() { }

    static inline D apply(D a) { 
      using std::ceil;
      return std::ceil(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "ceil(" + sa + ")";
      return sout;
    }

  };
  // floor(a)

  template <class D> class ApFloor {
  public:
    ApFloor() { }

    static inline D apply(D a) { 
      using std::floor;
      return std::floor(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "floor(" + sa + ")";
      return sout;
    }

  };
  // round(a)

  template <class D> class ApRound {
  public:
    ApRound() { }

    static inline D apply(D a) {
      return std::round(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "round(" + sa + ")";
      return sout;
    }

  };
  // sinh(a)

  template <class D> class ApSinh {
  public:
    ApSinh() { }

    static inline D apply(D a) { 
      using std::sinh;
      return std::sinh(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "sinh(" + sa + ")";
      return sout;
    }

  };
  // cosh(a)

  template <class D> class ApCosh {
  public:
    ApCosh() { }

    static inline D apply(D a) { 
      using std::cosh;
      return std::cosh(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "cosh(" + sa + ")";
      return sout;
    }

  };
  // tanh(a)

  template <class D> class ApTanh {
  public:
    ApTanh() { }

    static inline D apply(D a) { 
      using std::tanh;
      return std::tanh(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "tanh(" + sa + ")";
      return sout;
    }

  };




    
   // roundzero(a,tol)

  template <class D> class ApRoundZeros {
  public:
    typedef typename RealVersionOfType<D>::Type DREAL;
    ApRoundZeros() { }

    static inline D apply(D a, const DREAL tolerance) { 
      return roundzero(a, tolerance);
    }

    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout = "roundzero( " + sa + " , " + sb + " )";
      return sout;
    }

  };




};

#endif

