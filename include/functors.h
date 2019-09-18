#ifndef MATRICKS__FUNCTORS_H
#define MATRICKS__FUNCTORS_H


//  functor in C++ sense: a class that wraps a function
//
// TODO: use non-template base classes for the debug code and place in cpp file.
//        this speeds up compile time tremendously.
// TODO: add bitwise functors for unsigned types
// TODO: add const to all input vars


namespace matricks {


  extern display::Style functor_namestyle;

  
  // ************************************************************************
  // *              Math 
  // ************************************************************************



  // unary+ operator

#if MATRICKS_DEBUG>=1
  class Fun_Plus_base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class FunPlus : public Fun_Plus_base {
#else 
  template <class D> class FunPlus                       {
#endif
  public:
    FunPlus() { }

    static inline D apply(const D a) { 
      return a; 
    }
  };


  
  
  // unary-

#if MATRICKS_DEBUG>=1
  class Fun_Minus_base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };

  template <class D> class FunMinus : public Fun_Minus_base {
#else
  template <class D> class FunMinus {
#endif
  public:
    FunMinus() { }

    static inline D apply(const D a) { 
      return (-a); 
    }

  };


  // cast - from D1 to D2


  template <class D1, class D2> class FunCast {
  public:
    FunCast() { }

    static inline D2 apply(const D1 a) { 
      return static_cast<D2>(a); 
    }
    
#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      using namespace display;
      D2 d2;
      std::string sout = "static_cast<" + getTypeName<D2>(d2) + ">(" + sa + ")";
      return sout;
    }

    static std::string classname() {
      return functor_namestyle.apply("FunCast");
    }
#endif
    
  };



  // y = a + b

#if MATRICKS_DEBUG>=1
  class Fun_Add_base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };

  template <class D> class FunAdd : public Fun_Add_base {
#else 
  template <class D> class FunAdd {
#endif
  public:
    FunAdd() { }
  
    static inline D apply(const D a, const D b) { 
      return a+b; 
    }

  };



  // y = a - b

#if MATRICKS_DEBUG>=1
  class Fun_Subtract_base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };

  template <class D> class FunSubtract : public Fun_Subtract_base {
#else 
  template <class D> class FunSubtract  {
#endif
  public:
    FunSubtract() { }
  
    static inline D apply(const D a, const D b) { 
      return a-b; 
    }

  };


  // y = a * b

#if MATRICKS_DEBUG>=1
  class Fun_Multiply_base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };

  template <class D> class FunMultiply : public Fun_Multiply_base {
#else 
  template <class D> class FunMultiply  {
#endif
  public:
    FunMultiply() { }

    static inline D apply(const D a, const D b) { 
      return a*b; 
    }

  };




  // y = a / b

#if MATRICKS_DEBUG>=1
  class Fun_Divide_base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };

  template <class D> class FunDivide : public Fun_Divide_base {
#else 
  template <class D> class FunDivide {
#endif
  public:
    FunDivide() { }

    static inline D apply(const D a, const D b) { 
      return a/b; 
    }

  };



  
  
  // y = pow(a,b)  
  // ie. a raised to the b power

#if MATRICKS_DEBUG>=1
  class Fun_Pow_base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };

  template <class D> class ApPow : public Fun_Pow_base {
#else 
  template <class D> class ApPow {
#endif
  public:
    ApPow() { }
    static inline D apply(D a, D b) { 
      using std::pow;
      return pow(a,b); 
    }


    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = "pow( " + sa + " , " + sb + " )";
      return sout;
    }
  };

  
  // y = powint(a,n)  
  // ie. a raised to the n power

#if MATRICKS_DEBUG>=1
  class Fun_Monomial_base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };
  template <class D> class ApMonomial : public Fun_Monomial_base {
#else 
  template <class D> class ApMonomial {
#endif
  public:
    ApMonomial() { }
    static inline D apply(D x, int n) { 
      using std::pow;
      return pow(x,n); 
    }


    static std::string expression(const std::string& sx, const std::string& sn) {
      std::string sout = sx + "^" + sn ;
      return sout;
    }
  };


  // y = atan2(a,b)  

#if MATRICKS_DEBUG>=1
  class Fun_Atan2_base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };
  template <class D> class ApAtan2 : public Fun_Atan2_base {
#else 
  template <class D> class ApAtan2 {
#endif
  public:
    ApAtan2() { }
    static inline D apply(D a, D b) { 
      using std::atan2;
      return atan2(a,b); 
    }


    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = "atan2( " + sa + " , " + sb + " )";
      return sout;
    }
  };

  ///////////////////////

  // sin(a)

  template <class D> class ApSin {
  public:
    ApSin() { }

    static inline D apply(D a) { 
      using std::sin;
      return sin(a); 
    }

    static std::string expression(const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
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

    static std::string expression( const std::string& sa) {
      std::string sout = "tanh(" + sa + ")";
      return sout;
    }

  };
  // roundzero(a,tol)

  template <class D> class ApRoundZeros {
  public:
    typedef typename GetDataType<D>::Type DREAL;
    ApRoundZeros() { }

    static inline D apply(D a, const DREAL tolerance) { 
      return roundzero(a, tolerance);
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = "roundzero( " + sa + " , " + sb + " )";
      return sout;
    }

  };


  // ************************************************************************
  // *              User Defined
  // ************************************************************************


  template<class D>
    struct TypeHelper {
      typedef D(*unary_func)(D);
      typedef D(*binary_func)(D, D);
    };


  // y = op1<D,userfunc>(a)

  template <class D, typename TypeHelper<D>::unary_func F> class ApFun1 {
  public:
    ApFun1() { }

    static inline D apply(D a) { 
      return F(a); 
    }

    static std::string expression(const std::string& sa) {
      std::string sout =std::string("op1<")+  typeid(D).name()+","+typeid(F).name() +">(" + sa + ")";
      return sout;
    }

  };


  
  // y = op2<D,userfunc>(a,b)
  template <class D, typename TypeHelper<D>::binary_func F> class ApFun2 {
  public:
    ApFun2() { }
    static inline D apply(const D a, const D b) { 
      return F(a,b); 
    }
    

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =std::string("op2<")+ stringify(D)+","+ stringify(F) +">(" + sa + " , " + sb + ")";
      return sout;
    }
  };


  // ***********************************************************************
  // *              Logic
  // ***********************************************************************


  // !(a)

  class ApNot {
  public:
    ApNot() { }

    static inline bool apply(bool a) { 
      return !(a); 
    }

    static std::string expression(const std::string& sa) {
      std::string sout = "!(" + sa + ")";
      return sout;
    }

  };

  
  // y = a && b

  class ApAnd {
  public:
    ApAnd() { }
  
    static inline bool apply(bool a, bool b) { 
      return a && b; 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = "(" + sa + " && " + sb;
      return sout;
    }

  };


  // y = a || b

  class ApOr {
  public:
    ApOr() { }
  
    static inline bool apply(bool a, bool b) { 
      return (a || b); 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = "(" + sa + " || " + sb + ")";
      return sout;
    }

  };




  // ************************************************************************
  // *              Relational ops (return a bool from two Ds)
  // ************************************************************************

  // y = (a == b)

  template <class D> class ApEqual {
  public:
    ApEqual() { }
  
    static inline bool apply(D a, D b) { 
      return (a == b); 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = "(" + sa + " == " + sb + ")";
      return sout;
    }

  };

 



  // y = (a != b)

  template <class D> class ApNotEqual {
  public:
    ApNotEqual() { }
  
    static inline bool apply(D a, D b) { 
      return (a != b); 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = "(" + sa + " != " + sb + ")";
      return sout;
    }

  };

 




  // y = (a <= b)

  template <class D> class ApLessEqual {
  public:
    ApLessEqual() { }
  
    static inline bool apply(D a, D b) { 
      return (a <= b); 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = "(" + sa + " <= " + sb + ")";
      return sout;
    }

  };





  // y = (a >= b)

  template <class D> class ApGreaterEqual {
  public:
    ApGreaterEqual() { }
  
    static inline bool apply(D a, D b) { 
      return (a >= b); 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = "(" + sa + " >= " + sb + ")";
      return sout;
    }

  };


  // y = (a < b)

  template <class D> class ApLess {
  public:
    ApLess() { }
  
    static inline bool apply(D a, D b) { 
      return (a < b); 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = "(" + sa + " < " + sb + ")";
      return sout;
    }

  };


  // y = (a > b)

  template <class D> class ApGreat {
  public:
    ApGreat() { }
  
    static inline bool apply(D a, D b) { 
      return (a > b); 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = "(" + sa + " > " + sb + ")";
      return sout;
    }

  };



  // ************************************************************************
  // *              complex numbers
  // ************************************************************************



  // polar(r,phi)

  template <class D > class ApPolar {
  public:
    ApPolar() { }

    static inline std::complex<D> apply(D r, D phi) { 
      using std::polar;
      return polar(r,phi); 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = "polar(" + sa + " , " + sb +  ")";
      return sout;
    }

  };

 

  // complex(x,y)

  template <class D > class ApComplex {
  public:
    ApComplex() { }

    static inline std::complex<D> apply(D x, D y) { 
      return std::complex<D>(x,y); 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = "complex(" + sa + " , " + sb +  ")";
      return sout;
    }

  };


  // y = acomplex + breal

  template <class D> class FunAddCR {
  public:
    FunAddCR() { }
  
    static inline std::complex<D> apply( std::complex<D> a, D b) { 
      return a+b; 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " + " + sb;
      return sout;
    }

  };


  // y = areal + bcomplex

  template <class D> class FunAddRC {
  public:
    FunAddRC() { }
  
    static inline std::complex<D> apply(D a, std::complex<D> b) { 
      return a+b; 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " + " + sb;
      return sout;
    }

  };


  // y = acomplex - breal

  template <class D> class FunSubtractCR {
  public:
    FunSubtractCR() { }
  
    static inline std::complex<D> apply( std::complex<D> a, D b) { 
      return a-b; 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " - " + sb;
      return sout;
    }

  };


  // y = areal - bcomplex

  template <class D> class FunSubtractRC {
  public:
    FunSubtractRC() { }
  
    static inline std::complex<D> apply(D a, std::complex<D> b) { 
      return a-b; 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " - " + sb;
      return sout;
    }

  };



  // y = acomplex * breal

  template <class D> class FunMultiplyCR {
  public:
    FunMultiplyCR() { }
  
    static inline std::complex<D> apply( std::complex<D> a, D b) { 
      return a*b; 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " * " + sb;
      return sout;
    }

  };


  // y = areal * bcomplex

  template <class D> class FunMultiplyRC {
  public:
    FunMultiplyRC() { }
  
    static inline std::complex<D> apply(D a, std::complex<D> b) { 
      return a*b; 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " * " + sb;
      return sout;
    }

  };


  // y = acomplex / breal

  template <class D> class FunDivideCR {
  public:
    FunDivideCR() { }
  
    static inline std::complex<D> apply( std::complex<D> a, D b) { 
      return a/b; 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " / " + sb;
      return sout;
    }

  };


  // y = areal / bcomplex

  template <class D> class FunDivideRC {
  public:
    FunDivideRC() { }
  
    static inline std::complex<D> apply(D a, std::complex<D> b) { 
      return a/b; 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " / " + sb;
      return sout;
    }

  };


  // y = pow(acomplex,breal),  ie. a raised to the b power

  template <class D> class ApPowCR {
  public:
    ApPowCR() { }
    static inline std::complex<D> apply(std::complex<D> a, D b) { 
      using std::pow;
      return pow(a,b); 
    }
    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = "pow( " + sa + " , " + sb + " )";
      return sout;
    }
  };


  
  // y = pow(areal,bcomplex),  ie. a raised to the b power

  template <class D> class ApPowRC {
  public:
    ApPowRC() { }
    static inline std::complex<D> apply( D a, std::complex<D> b) { 
      using std::pow;
      return pow(a,b); 
    }
    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = "pow( " + sa + " , " + sb + " )";
      return sout;
    }
  };



  // abs(a)

  template <class D> class ApCAbs {
  public:
    ApCAbs() { }

    static inline D apply(std::complex<D> a) { 
      using std::abs;
      return abs(a); 
    }

    static std::string expression(const std::string& sa) {
      std::string sout = "abs(" + sa + ")";
      return sout;
    }

  };


  // arg(a)

  template <class D> class ApArg {
  public:
    ApArg() { }

    static inline D apply(std::complex<D> a) { 
      using std::arg;
      return arg(a); 
    }

    static std::string expression(const std::string& sa) {
      std::string sout = "arg(" + sa + ")";
      return sout;
    }

  };




  // conj(a)

  template <class D > class ApConj {
  public:
    ApConj() { }

    static inline std::complex<D> apply(std::complex<D> a) { 
      using std::conj;
      return conj(a); 
    }

    static std::string expression(const std::string& sa) {
      std::string sout = "conj(" + sa + ")";
      return sout;
    }

  };


  // real(a)

  template <class D> class ApReal {
  public:
    ApReal() { }


    static inline const D apply(const std::complex<D> a) { 
      using std::real;
      return real(a); 
    }

    static std::string expression(const std::string& sa) {
      std::string sout = "real(" + sa + ")";
      return sout;
    }

  };


  // imag(a)

  template <class D> class ApImag {
  public:
    ApImag() { }

    static inline D apply(std::complex<D> a) { 
      using std::imag;
      return imag(a); 
    }

    static std::string expression(const std::string& sa) {
      std::string sout = "imag(" + sa + ")";
      return sout;
    }

  };

  // round(a)

  template <class D> class ApRoundCplx {
  public:
    ApRoundCplx() { }

    static inline std::complex<D> apply(std::complex<D> a) {
      return matricks::round(a); 
    }

    static std::string expression( const std::string& sa) {
      std::string sout = "round(" + sa + ")";
      return sout;
    }

  };




};

#endif

