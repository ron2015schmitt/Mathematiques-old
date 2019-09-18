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
  
  std::string Fun_Plus_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("+")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Plus_base::classname() {
    return functor_namestyle.apply("Fun_Plus");
  }


 
  // unary- operator

  std::string Fun_Minus_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("-")+"(" + sa + ")";
    return sout;
  }

  std::string Fun_Minus_base::classname() {
    return functor_namestyle.apply("Fun_Minus");
  }


  // y = a + b

  std::string Fun_Add_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + functor_style.apply("+") + "(" + sb + ")";
    return sout;
  }

  std::string Fun_Add_base::classname() {
    return functor_namestyle.apply("Fun_Add");
  }


  // y = a - b

  std::string Fun_Subtract_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + functor_style.apply("-") + "(" + sb + ")";
    return sout;
  }

  std::string Fun_Subtract_base::classname() {
    return functor_namestyle.apply("Fun_Subtract");
  }


  // y = a * b

  std::string Fun_Multiply_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + functor_style.apply("*") + "(" + sb + ")";
    return sout;
  }

  std::string Fun_Multiply_base::classname() {
    return functor_namestyle.apply("Fun_Multiply");
  }


  
  // y = a / b

  std::string Fun_Divide_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + functor_style.apply("/") + "(" + sb + ")";
    return sout;
  }

  std::string Fun_Divide_base::classname() {
    return functor_namestyle.apply("Fun_Divide");
  }


  // ************************************************************************
  // *            Powers and logs
  // ************************************************************************

  
  // y = pow(a,b)  
  // ie. a raised to the b power

  std::string Fun_Pow_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + functor_style.apply("^") +"("+ sb + ")";
    return sout;
  }

  std::string Fun_Pow_base::classname() {
    return functor_namestyle.apply("Fun_Pow");
  }

  
  // y = powint(a,n)  
  // ie. a raised to the n power

  std::string Fun_Monomial_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + functor_style.apply("^") +"("+ sb + ")";
    return sout;
  }

  std::string Fun_Monomial_base::classname() {
    return functor_namestyle.apply("Fun_Monomial");
  }



  // sqr(a)

  std::string Fun_Sqr_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("sqr")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Sqr_base::classname() {
    return functor_namestyle.apply("Fun_Sqr");
  }



  // cube(a)

  std::string Fun_Cube_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("cube")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Cube_base::classname() {
    return functor_namestyle.apply("Fun_Cube");
  }


 
  // sqrt(a)

  std::string Fun_Sqrt_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("sqrt")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Sqrt_base::classname() {
    return functor_namestyle.apply("Fun_Sqrt");
  }

 
  // exp(a)
  std::string Fun_Exp_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("exp")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Exp_base::classname() {
    return functor_namestyle.apply("Fun_Exp");
  }


  // log(a)

  std::string Fun_Log_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("log")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Log_base::classname() {
    return functor_namestyle.apply("Fun_Log");
  }


  
  // log2(a)

  std::string Fun_Log2_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("log2")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Log2_base::classname() {
    return functor_namestyle.apply("Fun_Log2");
  }


  
  // log10(a)
 
  std::string Fun_Log10_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("log10")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Log10_base::classname() {
    return functor_namestyle.apply("Fun_Log10");
  }


  // ************************************************************************
  // *            trig, inverse trig, hyperbolic trig
  // ************************************************************************

  // sin(a)

  std::string Fun_Sin_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("sin")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Sin_base::classname() {
    return functor_namestyle.apply("Fun_Sin");
  }


  // cos(a)

  std::string Fun_Cos_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("cos")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Cos_base::classname() {
    return functor_namestyle.apply("Fun_Cos");
  }



  // tan(a)

  std::string Fun_Tan_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("tan")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Tan_base::classname() {
    return functor_namestyle.apply("Fun_Tan");
  }

  // asin(a)

  std::string Fun_Asin_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("asin")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Asin_base::classname() {
    return functor_namestyle.apply("Fun_Asin");
  }


  
  // acos(a)

  std::string Fun_Acos_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("acos")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Acos_base::classname() {
    return functor_namestyle.apply("Fun_Acos");
  }


  
  // atan(a)

  std::string Fun_Atan_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("atan")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Atan_base::classname() {
    return functor_namestyle.apply("Fun_Atan");
  }

  // y = atan2(a,b)  

  std::string Fun_Atan2_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = functor_style.apply("atan2") + "("+sa+", " + sb + ")";
    return sout;
  }

  std::string Fun_Atan2_base::classname() {
    return functor_namestyle.apply("Fun_Atan2");
  }

  // sinh(a)

  std::string Fun_Sinh_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("sinh")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Sinh_base::classname() {
    return functor_namestyle.apply("Fun_Sinh");
  }


  // cosh(a)

  std::string Fun_Cosh_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("cosh")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Cosh_base::classname() {
    return functor_namestyle.apply("Fun_Cosh");
  }

  
  // tanh(a)

  std::string Fun_Tanh_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("tanh")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Tanh_base::classname() {
    return functor_namestyle.apply("Fun_Tanh");
  }


  // ************************************************************************
  // *            sign-related and rounding
  // ************************************************************************

 
    // abs(a)

  std::string Fun_Abs_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("abs")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Abs_base::classname() {
    return functor_namestyle.apply("Fun_Abs");
  }

  
  // sgn(a)

  std::string Fun_Sgn_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("sgn")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Sgn_base::classname() {
    return functor_namestyle.apply("Fun_Sgn");
  }


  
  // ceil(a)

  std::string Fun_Ceil_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("ceil")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Ceil_base::classname() {
    return functor_namestyle.apply("Fun_Ceil");
  }


  
  // floor(a)

  std::string Fun_Floor_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("floor")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Floor_base::classname() {
    return functor_namestyle.apply("Fun_Floor");
  }


  
  // round(a)

  std::string Fun_Round_base::expression(const std::string& sa) {
    std::string sout = functor_style.apply("round")+"("+ sa + ")";
    return sout;
  }

  std::string Fun_Round_base::classname() {
    return functor_namestyle.apply("Fun_Round");
  }


  // roundzero(a,tol)

  std::string Fun_Roundzero_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = functor_style.apply("roundzero")+"("+ sa+", "+sb + ")";
    return sout;
  }

  std::string Fun_Roundzero_base::classname() {
    return functor_namestyle.apply("Fun_Roundzero");
  }




  


  
  
};

