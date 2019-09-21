#define MATRICKS_DEBUG 1
#include "matricks.h"
//  functor in C++ sense: a class that wraps a function
//
// Use non-template base classes for the debug code and place in cpp file.
//        this speeds up compile time tremendously.
//
// For same reason we'll let the expressions print out the <D> portion
// of the classname since they have to do such work anyway


// Move this to util.h
#include <type_traits>
template <class, template <class> class>
struct is_instance : public std::false_type {};

template <class T, template <class> class U>
struct is_instance<U<T>, U> : public std::true_type {};


namespace matricks {


  display::Style functor_namestyle = createStyle(display::ORANGE2);
  display::Style functor_style = createStyle(display::BOLD);



  // ************************************************************************
  // *              Arithmetic
  // ************************************************************************

  // unary+ operator
  
  std::string Fun_Plus_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("+")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Plus_Base::classname() {
    return functor_namestyle.apply("Fun_Plus");
  }


 
  // unary- operator

  std::string Fun_Minus_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("-")+"(" + sa + ")";
    return sout;
  }

  std::string Fun_Minus_Base::classname() {
    return functor_namestyle.apply("Fun_Minus");
  }


  // y = a + b

  std::string Fun_Add_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + functor_style.apply("+") + "(" + sb + ")";
    return sout;
  }

  std::string Fun_Add_Base::classname() {
    return functor_namestyle.apply("Fun_Add");
  }


  // y = a - b

  std::string Fun_Subtract_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + functor_style.apply("-") + "(" + sb + ")";
    return sout;
  }

  std::string Fun_Subtract_Base::classname() {
    return functor_namestyle.apply("Fun_Subtract");
  }


  // y = a * b

  std::string Fun_Multiply_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + functor_style.apply("*") + "(" + sb + ")";
    return sout;
  }

  std::string Fun_Multiply_Base::classname() {
    return functor_namestyle.apply("Fun_Multiply");
  }


  
  // y = a / b

  std::string Fun_Divide_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + functor_style.apply("/") + "(" + sb + ")";
    return sout;
  }

  std::string Fun_Divide_Base::classname() {
    return functor_namestyle.apply("Fun_Divide");
  }


  // ************************************************************************
  // *            Powers and logs
  // ************************************************************************

  
  // y = pow(a,b)  
  // ie. a raised to the b power

  std::string Fun_Pow_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + functor_style.apply("^") +"("+ sb + ")";
    return sout;
  }

  std::string Fun_Pow_Base::classname() {
    return functor_namestyle.apply("Fun_Pow");
  }

  
  // y = powint(a,n)  
  // ie. a raised to the n power

  std::string Fun_Monomial_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + functor_style.apply("^") +"("+ sb + ")";
    return sout;
  }

  std::string Fun_Monomial_Base::classname() {
    return functor_namestyle.apply("Fun_Monomial");
  }



  // sqr(a)

  std::string Fun_Sqr_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("sqr")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Sqr_Base::classname() {
    return functor_namestyle.apply("Fun_Sqr");
  }



  // cube(a)

  std::string Fun_Cube_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("cube")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Cube_Base::classname() {
    return functor_namestyle.apply("Fun_Cube");
  }


 
  // sqrt(a)

  std::string Fun_Sqrt_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("sqrt")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Sqrt_Base::classname() {
    return functor_namestyle.apply("Fun_Sqrt");
  }

 
  // exp(a)
  std::string Fun_Exp_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("exp")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Exp_Base::classname() {
    return functor_namestyle.apply("Fun_Exp");
  }


  // log(a)

  std::string Fun_Log_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("log")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Log_Base::classname() {
    return functor_namestyle.apply("Fun_Log");
  }


  
  // log2(a)

  std::string Fun_Log2_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("log2")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Log2_Base::classname() {
    return functor_namestyle.apply("Fun_Log2");
  }


  
  // log10(a)
 
  std::string Fun_Log10_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("log10")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Log10_Base::classname() {
    return functor_namestyle.apply("Fun_Log10");
  }


  // ************************************************************************
  // *            trig, inverse trig, hyperbolic trig
  // ************************************************************************

  // sin(a)

  std::string Fun_Sin_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("sin")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Sin_Base::classname() {
    return functor_namestyle.apply("Fun_Sin");
  }


  // cos(a)

  std::string Fun_Cos_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("cos")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Cos_Base::classname() {
    return functor_namestyle.apply("Fun_Cos");
  }



  // tan(a)

  std::string Fun_Tan_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("tan")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Tan_Base::classname() {
    return functor_namestyle.apply("Fun_Tan");
  }

  // asin(a)

  std::string Fun_Asin_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("asin")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Asin_Base::classname() {
    return functor_namestyle.apply("Fun_Asin");
  }


  
  // acos(a)

  std::string Fun_Acos_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("acos")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Acos_Base::classname() {
    return functor_namestyle.apply("Fun_Acos");
  }


  
  // atan(a)

  std::string Fun_Atan_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("atan")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Atan_Base::classname() {
    return functor_namestyle.apply("Fun_Atan");
  }

  // y = atan2(a,b)  

  std::string Fun_Atan2_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = functor_style.apply("atan2") + "("+sa+", " + sb + ")";
    return sout;
  }

  std::string Fun_Atan2_Base::classname() {
    return functor_namestyle.apply("Fun_Atan2");
  }

  // sinh(a)

  std::string Fun_Sinh_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("sinh")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Sinh_Base::classname() {
    return functor_namestyle.apply("Fun_Sinh");
  }


  // cosh(a)

  std::string Fun_Cosh_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("cosh")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Cosh_Base::classname() {
    return functor_namestyle.apply("Fun_Cosh");
  }

  
  // tanh(a)

  std::string Fun_Tanh_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("tanh")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Tanh_Base::classname() {
    return functor_namestyle.apply("Fun_Tanh");
  }


  // ************************************************************************
  // *            sign-related and rounding
  // ************************************************************************

 
    // abs(a)

  std::string Fun_Abs_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("abs")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Abs_Base::classname() {
    return functor_namestyle.apply("Fun_Abs");
  }

  
  // sgn(a)

  std::string Fun_Sgn_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("sgn")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Sgn_Base::classname() {
    return functor_namestyle.apply("Fun_Sgn");
  }


  
  // ceil(a)

  std::string Fun_Ceil_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("ceil")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Ceil_Base::classname() {
    return functor_namestyle.apply("Fun_Ceil");
  }


  
  // floor(a)

  std::string Fun_Floor_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("floor")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Floor_Base::classname() {
    return functor_namestyle.apply("Fun_Floor");
  }


  
  // round(a)

  std::string Fun_Round_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("round")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Round_Base::classname() {
    return functor_namestyle.apply("Fun_Round");
  }


  // roundzero(a,tol)

  std::string Fun_Roundzero_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = functor_style.apply("roundzero")+"("+ sa+", "+sb + ")";
    return sout;
  }

  std::string Fun_Roundzero_Base::classname() {
    return functor_namestyle.apply("Fun_Roundzero");
  }


  // y = op1<D,userfunc>(a)

  std::string Fun_UnaryUser_Base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("userfunction") + "(" + sa + ")";
    return sout;
  }

  std::string Fun_UnaryUser_Base::classname() {
    return functor_namestyle.apply("Fun_UnaryUser");
  }



  // y = op2<D,userfunc>(a,b)

  
  std::string Fun_BinaryUser_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = functor_style.apply("userfunction")+"("+ sa+", "+sb + ")";
    return sout;
  }

  std::string Fun_BinaryUser_Base::classname() {
    return functor_namestyle.apply("Fun_BinaryUser");
  }


  // !(a)

  std::string Fun_Not_Base::expression(const std::string& sa) {
    std::string sout =  functor_style.apply("!")+"(" + sa + ")";
    return sout;
  }

  std::string Fun_Not_Base::classname() {
    return functor_namestyle.apply("Fun_Not");
  }


  // y = a && b
  
  std::string Fun_And_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "("+ sa+")"+functor_style.apply("&&")+"("+sb + ")";
    return sout;
  }

  std::string Fun_And_Base::classname() {
    return functor_namestyle.apply("Fun_And");
  }



  // y = a || b

  std::string Fun_Or_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "("+ sa+")"+functor_style.apply("||")+"("+sb + ")";
    return sout;
  }

  std::string Fun_Or_Base::classname() {
    return functor_namestyle.apply("Fun_Or");
  }


  // y = (a == b)

  std::string Fun_Equal_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "("+ sa+")"+functor_style.apply("==")+"("+sb + ")";
    return sout;
  }

  std::string Fun_Equal_Base::classname() {
    return functor_namestyle.apply("Fun_Equal");
  }


  // y = (a != b)

  std::string Fun_NotEqual_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "("+ sa+")"+functor_style.apply("!=")+"("+sb + ")";
    return sout;
  }

  std::string Fun_NotEqual_Base::classname() {
    return functor_namestyle.apply("Fun_NotEqual");
  }


  // y = (a <= b)
  
  std::string Fun_LessOrEqual_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "("+ sa+")"+functor_style.apply("<=")+"("+sb + ")";
    return sout;
  }

  std::string Fun_LessOrEqual_Base::classname() {
    return functor_namestyle.apply("Fun_LessOrEqual");
  }

  
  // y = (a >= b)

  std::string Fun_GreaterOrEqual_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "("+ sa+")"+functor_style.apply(">=")+"("+sb + ")";
    return sout;
  }

  std::string Fun_GreaterOrEqual_Base::classname() {
    return functor_namestyle.apply("Fun_GreaterOrEqual");
  }

  
  // y = (a < b)
  
  std::string Fun_Less_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "("+ sa+")"+functor_style.apply("<")+"("+sb + ")";
    return sout;
  }

  std::string Fun_Less_Base::classname() {
    return functor_namestyle.apply("Fun_Less");
  }

  
  // y = (a > b)

  std::string Fun_Greater_Base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "("+ sa+")"+functor_style.apply(">")+"("+sb + ")";
    return sout;
  }

  std::string Fun_Greater_Base::classname() {
    return functor_namestyle.apply("Fun_Greater");
  }

 


  
  
};

