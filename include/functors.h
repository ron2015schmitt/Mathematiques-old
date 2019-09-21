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
  extern display::Style functor_style;

  
  // ************************************************************************
  // *              Arithmetic
  // ************************************************************************



  // unary+ operator

#if MATRICKS_DEBUG>=1
  class Fun_Plus_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Plus : public Fun_Plus_Base {
#else 
  template <class D> class Fun_Plus                       {
#endif
  public:
    Fun_Plus() { }

    static inline D apply(const D a) { 
      return a; 
    }
  };


  
  
  // unary-

#if MATRICKS_DEBUG>=1
  class Fun_Minus_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };

  template <class D> class Fun_Minus : public Fun_Minus_Base {
#else
  template <class D> class Fun_Minus {
#endif
  public:
    Fun_Minus() { }

    static inline D apply(const D a) { 
      return (-a); 
    }

  };


  // cast - from D1 to D2

  template <class D1, class D2> class Fun_Cast {
  public:
    Fun_Cast() { }

    static inline D2 apply(const D1 a) { 
      return static_cast<D2>(a); 
    }
    
#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      using namespace display;
      D2 d2;
      std::string sout = functor_style.apply("static_cast")+"<" + getTypeName(d2) + ">(" + sa + ")";
      return sout;
    }

    static std::string classname() {
      return functor_namestyle.apply("Fun_Cast");
    }
#endif
    
  };



  // y = a + b

#if MATRICKS_DEBUG>=1
  class Fun_Add_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };

  template <class D> class Fun_Add : public Fun_Add_Base {
#else 
  template <class D> class Fun_Add {
#endif
  public:
    Fun_Add() { }
  
    static inline D apply(const D a, const D b) { 
      return a+b; 
    }

  };



  // y = a - b

#if MATRICKS_DEBUG>=1
  class Fun_Subtract_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };

  template <class D> class Fun_Subtract : public Fun_Subtract_Base {
#else 
  template <class D> class Fun_Subtract  {
#endif
  public:
    Fun_Subtract() { }
  
    static inline D apply(const D a, const D b) { 
      return a-b; 
    }

  };


  // y = a * b

#if MATRICKS_DEBUG>=1
  class Fun_Multiply_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };

  template <class D> class Fun_Multiply : public Fun_Multiply_Base {
#else 
  template <class D> class Fun_Multiply  {
#endif
  public:
    Fun_Multiply() { }

    static inline D apply(const D a, const D b) { 
      return a*b; 
    }

  };




  // y = a / b

#if MATRICKS_DEBUG>=1
  class Fun_Divide_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };

  template <class D> class Fun_Divide : public Fun_Divide_Base {
#else 
  template <class D> class Fun_Divide {
#endif
  public:
    Fun_Divide() { }

    static inline D apply(const D a, const D b) { 
      return a/b; 
    }

  };



  // ************************************************************************
  // *            Powers and logs
  // ************************************************************************

  
  
  // y = pow(a,b)  
  // ie. a raised to the b power

#if MATRICKS_DEBUG>=1
  class Fun_Pow_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };

  template <class D> class Fun_Pow : public Fun_Pow_Base {
#else 
  template <class D> class Fun_Pow {
#endif
  public:
    Fun_Pow() { }
    static inline D apply(D a, D b) { 
      using std::pow;
      return pow(a,b); 
    }
  };

  
  // y = powint(a,n)  
  // ie. a raised to the n power

#if MATRICKS_DEBUG>=1
  class Fun_Monomial_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };
  template <class D> class Fun_Monomial : public Fun_Monomial_Base {
#else 
  template <class D> class Fun_Monomial {
#endif
  public:
    Fun_Monomial() { }
    static inline D apply(D x, int n) { 
      using std::pow;
      return pow(x,n); 
    }
  };



  
  // sqr(a)

#if MATRICKS_DEBUG>=1
  class Fun_Sqr_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Sqr : public Fun_Sqr_Base {
#else 
  template <class D> class Fun_Sqr {
#endif
  public:
    Fun_Sqr() { }

    static inline D apply(D a) { 
      return (a*a); 
    }

  };


  // cube(a)

#if MATRICKS_DEBUG>=1
  class Fun_Cube_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Cube : public Fun_Cube_Base {
#else 
  template <class D> class Fun_Cube {
#endif
  public:
    Fun_Cube() { }

    static inline D apply(D a) { 
      return (a*a*a); 
    }
  };


  // sqrt(a)

#if MATRICKS_DEBUG>=1
  class Fun_Sqrt_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Sqrt : public Fun_Sqrt_Base {
#else 
  template <class D> class Fun_Sqrt {
#endif
  public:
    Fun_Sqrt() { }

    static inline D apply(D a) { 
      using std::sqrt;
      return sqrt(a); 
    }

  };


  // exp(a)
#if MATRICKS_DEBUG>=1
  class Fun_Exp_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Exp : public Fun_Exp_Base {
#else 
    template <class D> class Fun_Exp {
#endif
  public:
    Fun_Exp() { }
    
    static inline D apply(D a) {
      using std::exp;
      return exp(a);
    }

  };

 
  // log(a)

#if MATRICKS_DEBUG>=1
  class Fun_Log_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Log : public Fun_Log_Base {
#else 
  template <class D> class Fun_Log {
#endif
  public:
    Fun_Log() { }

    static inline D apply(D a) {
      using std::log;
      return log(a);
    }

  };


  
  // log2(a)

#if MATRICKS_DEBUG>=1
  class Fun_Log2_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Log2 : public Fun_Log2_Base {
#else 
  template <class D> class Fun_Log2 {
#endif
  public:
    Fun_Log2() { }

    static inline D apply(D a) {
      using std::log;
      return log2(a);
    }
  };


  
  // log10(a)
 
#if MATRICKS_DEBUG>=1
  class Fun_Log10_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Log10 : public Fun_Log10_Base {
#else 
  template <class D> class Fun_Log10 {
#endif
  public:
    Fun_Log10() { }

    static inline D apply(D a) {
      using std::log10;
      return log10(a);
    }
  };



    
  // ************************************************************************
  // *            trig, inverse trig, hyperbolic trig
  // ************************************************************************


  // sin(a)

#if MATRICKS_DEBUG>=1
  class Fun_Sin_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Sin : public Fun_Sin_Base {
#else 
    template <class D> class Fun_Sin {
#endif
  public:
    Fun_Sin() { }

    static inline D apply(D a) { 
      using std::sin;
      return sin(a); 
    }

  };


  // cos(a)

#if MATRICKS_DEBUG>=1
  class Fun_Cos_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Cos : public Fun_Cos_Base {
#else 
    template <class D> class Fun_Cos {
#endif
  public:
    Fun_Cos() { }

    static inline D apply(D a) { 
      using std::cos;
      return cos(a); 
    }

  };




  // tan(a)

#if MATRICKS_DEBUG>=1
  class Fun_Tan_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Tan : public Fun_Tan_Base {
#else 
    template <class D> class Fun_Tan {
#endif
  public:
    Fun_Tan() { }

    static inline D apply(D a) { 
      using std::tan;
      return tan(a); 
    }
  };


  // asin(a)

#if MATRICKS_DEBUG>=1
  class Fun_Asin_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Asin : public Fun_Asin_Base {
#else 
  template <class D> class Fun_Asin                       {
#endif
  public:
    Fun_Asin() { }

    static inline D apply(D a) {
      using std::asin;
      return asin(a);
    }
  };


  
  // acos(a)

#if MATRICKS_DEBUG>=1
  class Fun_Acos_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Acos : public Fun_Acos_Base {
#else 
  template <class D> class Fun_Acos                       {
#endif
  public:
    Fun_Acos() { }

    static inline D apply(D a) {
      using std::acos;
      return acos(a);
    }
  };


  
  // atan(a)

#if MATRICKS_DEBUG>=1
  class Fun_Atan_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Atan : public Fun_Atan_Base {
#else 
  template <class D> class Fun_Atan {
#endif
  public:
    Fun_Atan() { }

    static inline D apply(D a) {
      using std::atan;
      return atan(a);
    }
  };




    // y = atan2(a,b)  

#if MATRICKS_DEBUG>=1
  class Fun_Atan2_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };
  template <class D> class Fun_Atan2 : public Fun_Atan2_Base {
#else 
  template <class D> class Fun_Atan2 {
#endif
  public:
    Fun_Atan2() { }
    static inline D apply(D a, D b) { 
      using std::atan2;
      return atan2(a,b); 
    }
  };


  

  // sinh(a)

#if MATRICKS_DEBUG>=1
  class Fun_Sinh_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Sinh : public Fun_Sinh_Base {
#else 
  template <class D> class Fun_Sinh {
#endif
  public:
    Fun_Sinh() { }

    static inline D apply(D a) { 
      using std::sinh;
      return sinh(a); 
    }

  };



  // cosh(a)

#if MATRICKS_DEBUG>=1
  class Fun_Cosh_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Cosh : public Fun_Cosh_Base {
#else 
  template <class D> class Fun_Cosh {
#endif
  public:
    Fun_Cosh() { }

    static inline D apply(D a) { 
      using std::cosh;
      return cosh(a); 
    }
  };


  
  // tanh(a)

#if MATRICKS_DEBUG>=1
  class Fun_Tanh_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Tanh : public Fun_Tanh_Base {
#else 
  template <class D> class Fun_Tanh {
#endif
  public:
    Fun_Tanh() { }

    static inline D apply(D a) { 
      using std::tanh;
      return tanh(a); 
    }
  };



  // ************************************************************************
  // *            sign-related and rounding
  // ************************************************************************


    // abs(a)

#if MATRICKS_DEBUG>=1
  class Fun_Abs_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Abs : public Fun_Abs_Base {
#else 
  template <class D> class Fun_Abs {
#endif
  public:
    Fun_Abs() { }

    static inline D apply(D a) {
      using std::abs;
      return abs(a);
    }
  };


  
  // sgn(a)

#if MATRICKS_DEBUG>=1
  class Fun_Sgn_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Sgn : public Fun_Sgn_Base {
#else 
  template <class D> class Fun_Sgn {
#endif
  public:
    Fun_Sgn() { }

    static inline D apply(D a) {
      return matricks::sgn(a);
    }
  };


  
 
  
  // ceil(a)

#if MATRICKS_DEBUG>=1
  class Fun_Ceil_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Ceil : public Fun_Ceil_Base {
#else 
  template <class D> class Fun_Ceil {
#endif
  public:
    Fun_Ceil() { }

    static inline D apply(D a) { 
      using std::ceil;
      return ceil(a); 
    }

  };


  
  // floor(a)

#if MATRICKS_DEBUG>=1
  class Fun_Floor_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Floor : public Fun_Floor_Base {
#else 
  template <class D> class Fun_Floor {
#endif
  public:
    Fun_Floor() { }

    static inline D apply(D a) { 
      using std::floor;
      return floor(a); 
    }

  };


  
  // round(a)

#if MATRICKS_DEBUG>=1
  class Fun_Round_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D> class Fun_Round : public Fun_Round_Base {
#else 
  template <class D> class Fun_Round {
#endif
  public:
    Fun_Round() { }

    static inline D apply(D a) {
      using std::round;
      return round(a); 
    }
  };

  
  // roundzero(a,tol)

#if MATRICKS_DEBUG>=1
  class Fun_Roundzero_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };
  
  template <class D> class Fun_Roundzero : public Fun_Roundzero_Base {
#else 
  template <class D> class Fun_Roundzero {
#endif
  public:
    typedef typename GetDataType<D>::Type DREAL;
    Fun_Roundzero() { }

    static inline D apply(D a, const DREAL tolerance) { 
      return matricks::roundzero(a, tolerance);
    }
  };


  // ************************************************************************
  // *              User Defined
  // ************************************************************************



  // y = op1<D,userfunc>(a)

#if MATRICKS_DEBUG>=1
  class Fun_UnaryUser_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  template <class D, typename matricks::FunctionTypes<D>::unary_func F> class Fun_UnaryUser : public Fun_UnaryUser_Base {
#else 
  template <class D, typename matricks::FunctionTypes<D>::unary_func F> class Fun_UnaryUser {
#endif
  public:
    Fun_UnaryUser() { }

    static inline D apply(D a) { 
      return F(a); 
    }


    
  };


  
  // y = op2<D,userfunc>(a,b)

#if MATRICKS_DEBUG>=1
  class Fun_BinaryUser_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };
  
  template <class D, typename FunctionTypes<D>::binary_func F> class Fun_BinaryUser : public Fun_BinaryUser_Base {
#else 
  template <class D, typename FunctionTypes<D>::binary_func F> class Fun_BinaryUser {
#endif
  public:
    Fun_BinaryUser() { }
    static inline D apply(const D a, const D b) { 
      return F(a,b); 
    }
  };


  // ***********************************************************************
  // *              Logic
  // ***********************************************************************


  // !(a)

#if MATRICKS_DEBUG>=1
  class Fun_Not_Base {
  public:
    static std::string expression(const std::string& sa);
    static std::string classname();
  };
  
  class Fun_Not : public Fun_Not_Base {
#else 
  class Fun_Not {
#endif
  public:
    Fun_Not() { }

    static inline bool apply(bool a) { 
      return !(a); 
    }
  };

  
  // y = a && b

#if MATRICKS_DEBUG>=1
  class Fun_And_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };
  
  class Fun_And :public Fun_And_Base {
#else 
  class Fun_And {
#endif
  public:
    Fun_And() { }
  
    static inline bool apply(bool a, bool b) { 
      return a && b; 
    }
  };


  // y = a || b

#if MATRICKS_DEBUG>=1
  class Fun_Or_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };
  
  class Fun_Or : public Fun_Or_Base {
#else 
  class Fun_Or {
#endif
  public:
    Fun_Or() { }
  
    static inline bool apply(bool a, bool b) { 
      return (a || b); 
    }
  };




  // ************************************************************************
  // *              Relational ops (return a bool from two Ds)
  // ************************************************************************

  // y = (a == b)

#if MATRICKS_DEBUG>=1
  class Fun_Equal_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };
  
  template <class D> class Fun_Equal : public Fun_Equal_Base {
#else 
  template <class D> class Fun_Equal {
#endif
  public:
    Fun_Equal() { }

    static inline bool apply(D a, D b) { 
      return (a == b); 
    }
  };

 



  // y = (a != b)

  
#if MATRICKS_DEBUG>=1
  class Fun_NotEqual_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };
  
  template <class D> class Fun_NotEqual : public Fun_NotEqual_Base {
#else 
  template <class D> class Fun_NotEqual {
#endif
  public:
    Fun_NotEqual() { }
    static inline bool apply(D a, D b) { 
      return (a != b); 
    }
  };

 




  // y = (a <= b)

  
#if MATRICKS_DEBUG>=1
  class Fun_LessOrEqual_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };
  
  template <class D> class Fun_LessOrEqual : public Fun_LessOrEqual_Base {
#else 
  template <class D> class Fun_LessOrEqual {
#endif
  public:
    Fun_LessOrEqual() { }
    static inline bool apply(D a, D b) { 
      return (a <= b); 
    }
  };





  // y = (a >= b)

#if MATRICKS_DEBUG>=1
  class Fun_GreaterOrEqual_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };
  
  template <class D> class Fun_GreaterOrEqual : public Fun_GreaterOrEqual_Base {
#else 
  template <class D> class Fun_GreaterOrEqual {
#endif
  public:
    Fun_GreaterOrEqual() { }
    static inline bool apply(D a, D b) { 
      return (a >= b); 
    }
  };


  // y = (a < b)

#if MATRICKS_DEBUG>=1
  class Fun_Less_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };
  
  template <class D> class Fun_Less : public Fun_Less_Base {
#else 
  template <class D> class Fun_Less {
#endif
  public:
    Fun_Less() { }
    static inline bool apply(D a, D b) { 
      return (a < b); 
    }
  };


  // y = (a > b)

#if MATRICKS_DEBUG>=1
  class Fun_Greater_Base {
  public:
    static std::string expression(const std::string& sa, const std::string& sb);
    static std::string classname();
  };
  
  template <class D> class Fun_Greater : public Fun_Greater_Base {
#else 
  template <class D> class Fun_Greater {
#endif
  public:
    Fun_Greater() { }
    static inline bool apply(D a, D b) { 
      return (a > b); 
    }
  };



  // ************************************************************************
  // *              complex numbers
  // ************************************************************************

  ///////////////////////
  // refactored to HERE
  ////////////////////////


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

  template <class D> class Fun_AddCR {
  public:
    Fun_AddCR() { }
  
    static inline std::complex<D> apply( std::complex<D> a, D b) { 
      return a+b; 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " + " + sb;
      return sout;
    }

  };


  // y = areal + bcomplex

  template <class D> class Fun_AddRC {
  public:
    Fun_AddRC() { }
  
    static inline std::complex<D> apply(D a, std::complex<D> b) { 
      return a+b; 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " + " + sb;
      return sout;
    }

  };


  // y = acomplex - breal

  template <class D> class Fun_SubtractCR {
  public:
    Fun_SubtractCR() { }
  
    static inline std::complex<D> apply( std::complex<D> a, D b) { 
      return a-b; 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " - " + sb;
      return sout;
    }

  };


  // y = areal - bcomplex

  template <class D> class Fun_SubtractRC {
  public:
    Fun_SubtractRC() { }
  
    static inline std::complex<D> apply(D a, std::complex<D> b) { 
      return a-b; 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " - " + sb;
      return sout;
    }

  };



  // y = acomplex * breal

  template <class D> class Fun_MultiplyCR {
  public:
    Fun_MultiplyCR() { }
  
    static inline std::complex<D> apply( std::complex<D> a, D b) { 
      return a*b; 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " * " + sb;
      return sout;
    }

  };


  // y = areal * bcomplex

  template <class D> class Fun_MultiplyRC {
  public:
    Fun_MultiplyRC() { }
  
    static inline std::complex<D> apply(D a, std::complex<D> b) { 
      return a*b; 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " * " + sb;
      return sout;
    }

  };


  // y = acomplex / breal

  template <class D> class Fun_DivideCR {
  public:
    Fun_DivideCR() { }
  
    static inline std::complex<D> apply( std::complex<D> a, D b) { 
      return a/b; 
    }

    static std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " / " + sb;
      return sout;
    }

  };


  // y = areal / bcomplex

  template <class D> class Fun_DivideRC {
  public:
    Fun_DivideRC() { }
  
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

  template <class D> class Fun_RoundCplx {
  public:
    Fun_RoundCplx() { }

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

