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

  template <class D> class Fun_Plus {
  public:
    Fun_Plus() {}

    static inline D apply(const D a) { 
      return a;
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("+")+"("+ sa + ")";
      return sout;
    }

    static inline std::string classname() {
      D d;
      return functor_namestyle.apply("Fun_Plus")+display::getBracketedTypeName(d);
    }
#endif
        
  };
    

  
  
  // unary-

  template <class D> class Fun_Minus {
  public:
    Fun_Minus() { }

    static inline D apply(const D a) { 
      return (-a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("-")+"("+ sa + ")";
      return sout;
    }

    static inline std::string classname() {
      D d;
      return functor_namestyle.apply("Fun_Minus")+display::getBracketedTypeName(d);
    }
#endif

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
      using namespace display;
      D1 d1;
      D2 d2;
      std::string s = functor_namestyle.apply("Fun_Cast");
      s += StyledString::get(ANGLE1).get() + getTypeName(d1);
      s += StyledString::get(COMMA).get() + getTypeName(d2);
      s += StyledString::get(ANGLE2).get();
      return s;
    }
#endif
    
  };



  // y = a + b

  template <class D> class Fun_Add {
  public:
    Fun_Add() { }
  
    static inline D apply(const D a, const D b) { 
      return a+b; 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("+") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Add")+display::getBracketedTypeName(d);
    }
#endif

  };


  
  // y = a - b

  template <class D> class Fun_Subtract  {
  public:
    Fun_Subtract() { }
  
    static inline D apply(const D a, const D b) { 
      return a-b; 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("-") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Subtract")+display::getBracketedTypeName(d);
    }
#endif

  };


  // y = a * b

  template <class D> class Fun_Multiply  {
  public:
    Fun_Multiply() { }

    static inline D apply(const D a, const D b) { 
      return a*b; 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("*") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Multiply")+display::getBracketedTypeName(d);
    }
#endif

  };




  // y = a / b

  template <class D> class Fun_Divide {
  public:
    Fun_Divide() { }

    static inline D apply(const D a, const D b) { 
      return a/b; 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("/") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Divide")+display::getBracketedTypeName(d);
    }
#endif

  };



  // ************************************************************************
  // *            Powers and logs
  // ************************************************************************

  
  
  // y = pow(a,b)  
  // ie. a raised to the b power

  template <class D> class Fun_Pow {
  public:
    Fun_Pow() { }
    static inline D apply(D a, D b) { 
      using std::pow;
      return pow(a,b); 
    }

#if MATRICKS_DEBUG>=1
#endif

  };

  
  // y = powint(a,n)  
  // ie. a raised to the n power

  template <class D> class Fun_Monomial {
  public:
    Fun_Monomial() { }
    static inline D apply(D x, int n) { 
      using std::pow;
      return pow(x,n); 
    }

#if MATRICKS_DEBUG>=1
#endif

  };



  
  // sqr(a)

  template <class D> class Fun_Sqr {
  public:
    Fun_Sqr() { }

    static inline D apply(D a) { 
      return (a*a); 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("sqr")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Sqr")+display::getBracketedTypeName(d);
    }
#endif

  };


  // cube(a)

  template <class D> class Fun_Cube {
  public:
    Fun_Cube() { }

    static inline D apply(D a) { 
      return (a*a*a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("cube")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Cube")+display::getBracketedTypeName(d);
    }
#endif

  };


  // sqrt(a)

  template <class D> class Fun_Sqrt {
  public:
    Fun_Sqrt() { }

    static inline D apply(D a) { 
      using std::sqrt;
      return sqrt(a); 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("sqrt")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Sqrt")+display::getBracketedTypeName(d);
    }
#endif

  };


  // exp(a)
  template <class D> class Fun_Exp {
  public:
    Fun_Exp() { }
    
    static inline D apply(D a) {
      using std::exp;
      return exp(a);
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("exp")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Exp")+display::getBracketedTypeName(d);
    }
#endif

  };

 
  // log(a)

  template <class D> class Fun_Log {
  public:
    Fun_Log() { }

    static inline D apply(D a) {
      using std::log;
      return log(a);
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("log")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Log")+display::getBracketedTypeName(d);
     }
#endif

  };


  
  // log2(a)

  template <class D> class Fun_Log2 {
  public:
    Fun_Log2() { }

    static inline D apply(D a) {
      using std::log;
      return log2(a);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("log2")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Log2")+display::getBracketedTypeName(d);
     }
#endif

  };


  
  // log10(a)
 
  template <class D> class Fun_Log10 {
  public:
    Fun_Log10() {
    }

    static inline D apply(D a) {
      using std::log10;
      return log10(a);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("log10")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Log10")+display::getBracketedTypeName(d);
     }
#endif

  };



    
  // ************************************************************************
  // *            trig, inverse trig, hyperbolic trig
  // ************************************************************************


  // sin(a)

  template <class D> class Fun_Sin {
  public:
    Fun_Sin() { }

    static inline D apply(D a) { 
      using std::sin;
      return sin(a); 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("sin")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Sin")+display::getBracketedTypeName(d);
     }
#endif

  };


  // cos(a)

  template <class D> class Fun_Cos {
  public:
    Fun_Cos() { }

    static inline D apply(D a) { 
      using std::cos;
      return cos(a); 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("cos")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Cos")+display::getBracketedTypeName(d);
     }
#endif

  };




  // tan(a)

  template <class D> class Fun_Tan {
  public:
    Fun_Tan() { }

    static inline D apply(D a) { 
      using std::tan;
      return tan(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("tan")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Tan")+display::getBracketedTypeName(d);
     }
#endif

  };


  // asin(a)

  template <class D> class Fun_Asin                       {
  public:
    Fun_Asin() { }

    static inline D apply(D a) {
      using std::asin;
      return asin(a);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("asin")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Asin")+display::getBracketedTypeName(d);
     }
#endif

  };


  
  // acos(a)

  template <class D> class Fun_Acos                       {
  public:
    Fun_Acos() { }

    static inline D apply(D a) {
      using std::acos;
      return acos(a);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("acos")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Acos")+display::getBracketedTypeName(d);
    }
#endif

  };


  
  // atan(a)

  template <class D> class Fun_Atan {
  public:
    Fun_Atan() { }

    static inline D apply(D a) {
      using std::atan;
      return atan(a);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("atan")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Atan")+display::getBracketedTypeName(d);
    }
#endif

  };




  // y = atan2(a,b)  

  template <class D> class Fun_Atan2 {
  public:
    Fun_Atan2() { }
    static inline D apply(D a, D b) { 
      using std::atan2;
      return atan2(a,b); 
    }

#if MATRICKS_DEBUG>=1
#endif

  };


  

  // sinh(a)

  template <class D> class Fun_Sinh {
  public:
    Fun_Sinh() { }

    static inline D apply(D a) { 
      using std::sinh;
      return sinh(a); 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("sinh")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Sinh")+display::getBracketedTypeName(d);
    }
#endif

  };



  // cosh(a)

  template <class D> class Fun_Cosh {
  public:
    Fun_Cosh() { }

    static inline D apply(D a) { 
      using std::cosh;
      return cosh(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("cosh")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Cosh")+display::getBracketedTypeName(d);
    }
#endif

  };


  
  // tanh(a)

  template <class D> class Fun_Tanh {
  public:
    Fun_Tanh() { }

    static inline D apply(D a) { 
      using std::tanh;
      return tanh(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("tanh")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Tanh")+display::getBracketedTypeName(d);

    }
#endif

  };



  // ************************************************************************
  // *            sign-related and rounding
  // ************************************************************************


  // abs(a)

  template <class D> class Fun_Abs {
  public:
    Fun_Abs() { }

    static inline D apply(D a) {
      using std::abs;
      return abs(a);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("abs")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Abs")+display::getBracketedTypeName(d);
    }
#endif

  };


  
  // sgn(a)

  template <class D> class Fun_Sgn {
  public:
    Fun_Sgn() { }

    static inline D apply(D a) {
      return matricks::sgn(a);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("sgn")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Sgn")+display::getBracketedTypeName(d);
    }
#endif

  };


  
 
  
  // ceil(a)

  template <class D> class Fun_Ceil {
  public:
    Fun_Ceil() { }

    static inline D apply(D a) { 
      using std::ceil;
      return ceil(a); 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("ceil")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Ceil")+display::getBracketedTypeName(d);
    }
#endif

  };


  
  // floor(a)

  template <class D> class Fun_Floor {
  public:
    Fun_Floor() { }

    static inline D apply(D a) { 
      using std::floor;
      return floor(a); 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("+")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Floor")+display::getBracketedTypeName(d);
    }
#endif

  };


  
  // round(a)

  template <class D> class Fun_Round {
  public:
    Fun_Round() { }

    static inline D apply(D a) {
      using std::round;
      return round(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("round")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Round")+display::getBracketedTypeName(d);
    }
#endif

  };

  
  // roundzero(a,tol)

  template <class D> class Fun_Roundzero {
  public:
    typedef typename GetDataType<D>::Type DREAL;
    Fun_Roundzero() { }

    static inline D apply(D a, const DREAL tolerance) { 
      return matricks::roundzero(a, tolerance);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = functor_style.apply("roundzero") +  "(" + sa + ","  + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Roundzero")+display::getBracketedTypeName(d);
    }
#endif

  };


  // ************************************************************************
  // *              User Defined
  // ************************************************************************



  // y = op1<D,userfunc>(a)

  template <class D, typename matricks::FunctionTypes<D>::unary_func F> class Fun_UnaryUser {
  public:
    Fun_UnaryUser() { }

    static inline D apply(D a) { 
      return F(a); 
    }



#if MATRICKS_DEBUG>=1
#endif

    
  };


  
  // y = op2<D,userfunc>(a,b)

  template <class D, typename FunctionTypes<D>::binary_func F> class Fun_BinaryUser {
  public:
    Fun_BinaryUser() { }
    static inline D apply(const D a, const D b) { 
      return F(a,b); 
    }

#if MATRICKS_DEBUG>=1
#endif

  };


  // ***********************************************************************
  // *              Logic
  // ***********************************************************************


  // !(a)

  class Fun_Not {
  public:
    Fun_Not() { }

    static inline bool apply(bool a) { 
      return !(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("!")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      return functor_namestyle.apply("Fun_Not");
    }
#endif

  };

  
  // y = a && b

  class Fun_And {
  public:
    Fun_And() { }
  
    static inline bool apply(bool a, bool b) { 
      return a && b; 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("&&") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      return functor_namestyle.apply("Fun_And");
    }
#endif

  };


  // y = a || b

  class Fun_Or {
  public:
    Fun_Or() { }
  
    static inline bool apply(bool a, bool b) { 
      return (a || b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("||") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      return functor_namestyle.apply("Fun_Or");
    }
#endif

  };




  // ************************************************************************
  // *              Relational ops (return a bool from two Ds)
  // ************************************************************************

  // y = (a == b)

  template <class D> class Fun_Equal {
  public:
    Fun_Equal() { }

    static inline bool apply(D a, D b) { 
      return (a == b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("==") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Equal")+display::getBracketedTypeName(d);
    }
#endif

  };

 



  // y = (a != b)

  template <class D> class Fun_NotEqual {
  public:
    Fun_NotEqual() { }
    static inline bool apply(D a, D b) { 
      return (a != b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("!=") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_NotEqual")+display::getBracketedTypeName(d);
    }
#endif

  };

 




  // y = (a <= b)

  
  template <class D> class Fun_LessOrEqual {
  public:
    Fun_LessOrEqual() { }
    static inline bool apply(D a, D b) { 
      return (a <= b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("<=") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_LessOrEqual")+display::getBracketedTypeName(d);
    }
#endif

  };





  // y = (a >= b)

  template <class D> class Fun_GreaterOrEqual {
  public:
    Fun_GreaterOrEqual() { }
    static inline bool apply(D a, D b) { 
      return (a >= b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply(">=") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_GreaterOrEqual")+display::getBracketedTypeName(d);
    }
#endif

  };


  // y = (a < b)

  template <class D> class Fun_Less {
  public:
    Fun_Less() { }
    static inline bool apply(D a, D b) { 
      return (a < b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("<") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Less")+display::getBracketedTypeName(d);
    }
#endif

  };


  // y = (a > b)

  template <class D> class Fun_Greater {
  public:
    Fun_Greater() { }
    static inline bool apply(D a, D b) { 
      return (a > b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply(">") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Greater")+display::getBracketedTypeName(d);
    }
#endif

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



#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("+") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Plus")+display::getBracketedTypeName(d);
    }
#endif

  };

 

  // complex(x,y)

  template <class D > class ApComplex {
  public:
    ApComplex() { }

    static inline std::complex<D> apply(D x, D y) { 
      return std::complex<D>(x,y); 
    }



#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("+") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Plus")+display::getBracketedTypeName(d);
    }
#endif

  };


  // y = acomplex + breal

  template <class D> class Fun_AddCR {
  public:
    Fun_AddCR() { }
  
    static inline std::complex<D> apply( std::complex<D> a, D b) { 
      return a+b; 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("+") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Plus")+display::getBracketedTypeName(d);
    }
#endif

  };


  // y = areal + bcomplex

  template <class D> class Fun_AddRC {
  public:
    Fun_AddRC() { }
  
    static inline std::complex<D> apply(D a, std::complex<D> b) { 
      return a+b; 
    }



#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("+") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Plus")+display::getBracketedTypeName(d);
    }
#endif

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


#if MATRICKS_DEBUG>=1
#endif

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


#if MATRICKS_DEBUG>=1
#endif

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


#if MATRICKS_DEBUG>=1
#endif

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


#if MATRICKS_DEBUG>=1
#endif

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


#if MATRICKS_DEBUG>=1
#endif

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


#if MATRICKS_DEBUG>=1
#endif

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

#if MATRICKS_DEBUG>=1
#endif

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


#if MATRICKS_DEBUG>=1
#endif

  };



  // abs(a)

  template <class D> class ApCAbs {
  public:
    ApCAbs() { }

    static inline D apply(std::complex<D> a) { 
      using std::abs;
      return abs(a); 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("abs")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Plus")+display::getBracketedTypeName(d);
    }
#endif

  };


  // arg(a)

  template <class D> class ApArg {
  public:
    ApArg() { }

    static inline D apply(std::complex<D> a) { 
      using std::arg;
      return arg(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("arg")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Plus")+display::getBracketedTypeName(d);
    }
#endif

  };




  // conj(a)

  template <class D > class ApConj {
  public:
    ApConj() { }

    static inline std::complex<D> apply(std::complex<D> a) { 
      using std::conj;
      return conj(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("conj")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      D d;
      return functor_namestyle.apply("Fun_Plus")+display::getBracketedTypeName(d);
    }
#endif

  };


  // real(a)

  template <class D> class ApReal {
  public:
    ApReal() { }


    static inline const D apply(const std::complex<D> a) { 
      using std::real;
      return real(a); 
    }



#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("real")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Plus")+display::getBracketedTypeName(d);
    }
#endif

  };


  // imag(a)

  template <class D> class ApImag {
  public:
    ApImag() { }

    static inline D apply(std::complex<D> a) { 
      using std::imag;
      return imag(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("imag")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      D d;
      return functor_namestyle.apply("Fun_Plus")+display::getBracketedTypeName(d);
    }
#endif

  };

  // round(a)

  template <class D> class Fun_RoundCplx {
  public:
    Fun_RoundCplx() { }

    static inline std::complex<D> apply(std::complex<D> a) {
      return matricks::round(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("round")+"("+ sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Plus")+display::getBracketedTypeName(d);
    }
#endif

  };




};

#endif

