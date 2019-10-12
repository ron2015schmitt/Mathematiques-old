#ifndef MATRICKS__FUNCTORS_H
#define MATRICKS__FUNCTORS_H


//  functor in C++ sense: a class that wraps a function
//
// TODO: add bitwise functors for unsigned types
// TOOD: switch from "apply" to "operator()"?  not sure if that would help. maybe it's good to explcittly show these are functors with ".apply"


namespace matricks {


  extern display::Style functor_namestyle;
  extern display::Style functor_style;
  extern display::Style userfunctor_style;

  
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

  template <class D2, class D1> class Fun_Cast {
  public:
    Fun_Cast() { }

    static inline D2 apply(const D1 a) {
      typedef typename BaseType<D1>::Type DREAL1;
      typedef typename BaseType<D2>::Type DREAL2;
      return numbercast<DREAL2,DREAL1>(a); 
    }
    

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      using namespace display;
      D2 d2;
      std::string sout = functor_style.apply("numbercast")+"<" + getTypeName(d2) + ">(" + sa + ")";
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




  // NEW y = D1 + D2

  template <class D1, class D2> class Fun_Add_New {
  public:
    Fun_Add_New() { }
  
    static inline typename AddType<D1,D2>::Type apply(const D1 a, const D2 b) {
      mout <<"Fun_Add::apply(a,b)"<<std::endl;
      mout <<"       ";
      tdisp(a);
      mout <<"       ";
      tdisp(b); 
      typename AddType<D1,D2>::Type y = a+b;
      mout <<"       ";
      //      tdisp(y);  // this produces the correct value
      return y; 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("+") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D1 d1;
      D1 d2;
      return functor_namestyle.apply(" <")+display::getTypeName(d1)+","+display::getTypeName(d1)+">";
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
    static inline D apply(const D a, const D b) { 
      using std::pow;
      return pow(a,b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = functor_style.apply("pow") +  "(" + sa + ","  + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Pow")+display::getBracketedTypeName(d);
    }
#endif

  };

  
  // y = powint(a,n)  
  // ie. a raised to the n power

  template <class D> class Fun_Monomial {
  public:
    Fun_Monomial() { }
    static inline D apply(const D x, const int n) { 
      using std::pow;
      return pow(x,n); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = functor_style.apply("pow") +  "(" + sa + ","  + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Monomial")+display::getBracketedTypeName(d);
    }
#endif

  };



  
  // sqr(a)

  template <class D> class Fun_Sqr {
  public:
    Fun_Sqr() { }

    static inline D apply(const D a) { 
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

    static inline D apply(const D a) { 
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

    static inline D apply(const D a) { 
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
    
    static inline D apply(const D a) {
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

    static inline D apply(const D a) {
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

    static inline D apply(const D a) {
      using std::log2;
      using matricks::log2;
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

    static inline D apply(const D a) {
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

    static inline D apply(const D a) { 
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

    static inline D apply(const D a) { 
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

    static inline D apply(const D a) { 
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

    static inline D apply(const D a) {
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

    static inline D apply(const D a) {
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
    static inline D apply(const D a, const D b) { 
      using std::atan2;
      return atan2(a,b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = functor_style.apply("atan2") +  "(" + sa + ","  + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Atan2")+display::getBracketedTypeName(d);
    }
#endif

  };


  

  // sinh(a)

  template <class D> class Fun_Sinh {
  public:
    Fun_Sinh() { }

    static inline D apply(const D a) { 
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

    static inline D apply(const D a) { 
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

    static inline D apply(const D a) { 
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

    static inline D apply(const D a) {
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

    static inline D apply(const D a) {
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

    static inline D apply(const D a) { 
      using std::ceil;
      using matricks::ceil; // for complex nums
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

    static inline D apply(const D a) { 
      using std::floor;
      using matricks::floor;  // for complex nums
      return floor(a); 
    }


#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("floor")+"("+ sa + ")";
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

    static inline D apply(const D a) {
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
    typedef typename BaseType<D>::Type DREAL;
    Fun_Roundzero() { }

    static inline D apply(const D a, const DREAL tolerance) { 
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


  
  // approx(a,b,tol)

  template <class D> class Fun_Approx {
  public:
    typedef typename BaseType<D>::Type DREAL;
    Fun_Approx() { }

    static inline bool apply(const D a, const D b, const DREAL tolerance) { 
      return matricks::approx(a, b, tolerance);
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb, const std::string& sc) {
      std::string sout = functor_style.apply("approx") +  "(" + sa + ","  + sb + ","  + sc + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Approx")+display::getBracketedTypeName(d);
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

    static inline D apply(const D a) { 
      return F(a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = userfunctor_style.apply("userfunc") +  "(" + sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_UnaryUser")+display::getBracketedTypeName(d);
    }
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
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = userfunctor_style.apply("userfunc") +  "(" + sa + ","  + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_BinaryUser")+display::getBracketedTypeName(d);
    }
#endif

  };


  // ***********************************************************************
  // *              Logic
  // ***********************************************************************


  // !(a)

  class Fun_Not {
  public:
    Fun_Not() { }

    static inline bool apply(const bool a) { 
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
  
    static inline bool apply(const bool a, const bool b) { 
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
  
    static inline bool apply(const bool a, const bool b) { 
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
  // *              bit-wise logical operators (for unsigned types)
  // ************************************************************************

  // y = a | b

  template <class D> class Fun_BitwiseOr {
  public:
    Fun_BitwiseOr() { }
  
    static inline D apply(const D a, const D b) { 
      return (a | b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("|") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      return functor_namestyle.apply("Fun_BitwiseOr");
    }
#endif

  };

  // y = a & b

  template <class D> class Fun_BitwiseAnd {
  public:
    Fun_BitwiseAnd() { }
  
    static inline D apply(const D a, const D b) { 
      return (a & b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("&") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      return functor_namestyle.apply("Fun_BitwiseAnd");
    }
#endif

  };


  // y = a ^ b

  template <class D> class Fun_BitwiseXor {
  public:
    Fun_BitwiseXor() { }
  
    static inline D apply(const D a, const D b) { 
      return (a ^ b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("^") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      return functor_namestyle.apply("Fun_BitwiseXor");
    }
#endif

  };



  // y = ~b

  template <class D> class Fun_BitwiseNot {
  public:
    Fun_BitwiseNot() { }
  
    static inline D apply(const D a) { 
      return (~a); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa) {
      std::string sout = functor_style.apply("~") + "(" + sa + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      return functor_namestyle.apply("Fun_BitwiseNot");
    }
#endif

  };



  
  // y = a << b

  template <class D> class Fun_BitwiseShiftLeft {
  public:
    Fun_BitwiseShiftLeft() { }
  
    static inline D apply(const D a, const D b) { 
      return (a << b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply("<<") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      return functor_namestyle.apply("Fun_BitwiseShiftLeft");
    }
#endif

  };


  // y = a >> b

  template <class D> class Fun_BitwiseShiftRight {
  public:
    Fun_BitwiseShiftRight() { }
  
    static inline D apply(const D a, const D b) { 
      return (a >> b); 
    }

#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout =  "(" + sa + ")" + functor_style.apply(">>") + "(" + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      return functor_namestyle.apply("Fun_BitwiseShiftRight");
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

    static inline bool apply(const D a, const D b) { 
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
    static inline bool apply(const D a, const D b) { 
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
    static inline bool apply(const D a, const D b) { 
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
    static inline bool apply(const D a, const D b) { 
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
    static inline bool apply(const D a, const D b) { 
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
    static inline bool apply(const D a, const D b) { 
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



  // polar(r,phi)

  template <class D > class Fun_Polar {
  public:
    Fun_Polar() { }

    static inline std::complex<D> apply(const D r, const D phi) { 
      using std::polar;
      return polar(r,phi); 
    }



#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = functor_style.apply("polar") +  "(" + sa + ","  + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Polar")+display::getBracketedTypeName(d);
    }
#endif

  };

 

  // complex(x,y)

  template <class D > class Fun_Complex {
  public:
    Fun_Complex() { }

    static inline std::complex<D> apply(const D x, const D y) { 
      return std::complex<D>(x,y); 
    }



#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = functor_style.apply("complex") +  "(" + sa + ","  + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_Complex")+display::getBracketedTypeName(d);
    }
#endif

  };


  // y = acomplex + breal

  template <class D> class Fun_AddCR {
  public:
    Fun_AddCR() { }
  
    static inline std::complex<D> apply( const std::complex<D> a, const D b) { 
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
      return functor_namestyle.apply("Fun_AddCR")+display::getBracketedTypeName(d);
    }
#endif

  };


  // y = areal + bcomplex

  template <class D> class Fun_AddRC {
  public:
    Fun_AddRC() { }
  
    static inline std::complex<D> apply(const D a, const std::complex<D> b) { 
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
      return functor_namestyle.apply("Fun_AddRC")+display::getBracketedTypeName(d);
    }
#endif

  };


  // y = acomplex - breal

  template <class D> class Fun_SubtractCR {
  public:
    Fun_SubtractCR() { }
  
    static inline std::complex<D> apply( const std::complex<D> a, const D b) { 
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
      return functor_namestyle.apply("Fun_SubtractCR")+display::getBracketedTypeName(d);
    }
#endif

  };


  // y = areal - bcomplex

  template <class D> class Fun_SubtractRC {
  public:
    Fun_SubtractRC() { }
  
    static inline std::complex<D> apply(const D a, const std::complex<D> b) { 
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
      return functor_namestyle.apply("Fun_SubtractRC")+display::getBracketedTypeName(d);
    }
#endif

  };



  // y = acomplex * breal

  template <class D> class Fun_MultiplyCR {
  public:
    Fun_MultiplyCR() { }
  
    static inline std::complex<D> apply( const std::complex<D> a, const D b) { 
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
      return functor_namestyle.apply("Fun_MultiplyCR")+display::getBracketedTypeName(d);
    }
#endif

  };


  // y = areal * bcomplex

  template <class D> class Fun_MultiplyRC {
  public:
    Fun_MultiplyRC() { }
  
    static inline std::complex<D> apply(const D a, const std::complex<D> b) { 
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
      return functor_namestyle.apply("Fun_MultiplyRC")+display::getBracketedTypeName(d);
    }
#endif

  };


  // y = acomplex / breal

  template <class D> class Fun_DivideCR {
  public:
    Fun_DivideCR() { }
  
    static inline std::complex<D> apply( const std::complex<D> a, const D b) { 
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
      return functor_namestyle.apply("Fun_DivideCR")+display::getBracketedTypeName(d);
    }
#endif

  };


  // y = areal / bcomplex

  template <class D> class Fun_DivideRC {
  public:
    Fun_DivideRC() { }
  
    static inline std::complex<D> apply(const D a, const std::complex<D> b) { 
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
      return functor_namestyle.apply("Fun_DivideRC")+display::getBracketedTypeName(d);
    }
#endif

  };


  // y = pow(acomplex,breal),  ie. a raised to the b power

  template <class D> class Fun_PowCR {
  public:
    Fun_PowCR() { }
    static inline std::complex<D> apply(const std::complex<D> a, const D b) { 
      using std::pow;
      return pow(a,b); 
    }
#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = functor_style.apply("pow") +  "(" + sa + ","  + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_PowCR")+display::getBracketedTypeName(d);
    }
#endif

  };


  
  // y = pow(areal,bcomplex),  ie. a raised to the b power

  template <class D> class Fun_PowRC {
  public:
    Fun_PowRC() { }
    static inline std::complex<D> apply( const D a, const std::complex<D> b) { 
      using std::pow;
      return pow(a,b); 
    }
#if MATRICKS_DEBUG>=1
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      std::string sout = functor_style.apply("pow") +  "(" + sa + ","  + sb + ")";
      return sout;
    }
    
    static inline std::string classname() {
      using namespace display;
      D d;
      return functor_namestyle.apply("Fun_PowRC")+display::getBracketedTypeName(d);
    }
#endif

  };



  // abs(a)

  template <class D> class Fun_CAbs {
  public:
    Fun_CAbs() { }

    static inline D apply(const std::complex<D> a) { 
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
      return functor_namestyle.apply("Fun_CAbs")+display::getBracketedTypeName(d);
    }
#endif

  };


  // arg(a)

  template <class D> class Fun_Arg {
  public:
    Fun_Arg() { }

    static inline D apply(const std::complex<D> a) { 
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
      return functor_namestyle.apply("Fun_Arg")+display::getBracketedTypeName(d);
    }
#endif

  };




  // conj(a)

  template <class D > class Fun_Conj {
  public:
    Fun_Conj() { }

    static inline typename Complexify<D>::Type apply(const D a) {
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
      return functor_namestyle.apply("Fun_Conj")+display::getBracketedTypeName(d);
    }
#endif

  };


  // real(a)

  template <class D> class Fun_Real {
  public:
    Fun_Real() { }


    static inline typename Realify<D>::Type apply(const D a) { 
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
      return functor_namestyle.apply("Fun_Real")+display::getBracketedTypeName(d);
    }
#endif

  };


  // imag(a)

  template <class D> class Fun_Imag {
  public:
    Fun_Imag() { }

    static inline typename Realify<D>::Type apply(const D a) { 
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
      return functor_namestyle.apply("Fun_Imag")+display::getBracketedTypeName(d);
    }
#endif

  };


  // TODO: can be get rid of this and use the same round function?
  // round(a)

  template <class D> class Fun_RoundCplx {
  public:
    Fun_RoundCplx() { }

    static inline std::complex<D> apply(const std::complex<D> a) {
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
      return functor_namestyle.apply("Fun_RoundCplx")+display::getBracketedTypeName(d);
    }
#endif

  };




};

#endif

