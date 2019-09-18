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



  // ************************************************************************
  // *              Math 
  // ************************************************************************




  // unary+ operator
  
  std::string FunPlus_base::expression(const std::string& sa) {
    std::string sout = "+(" + sa + ")";
    return sout;
  }

  std::string FunPlus_base::classname() {
    return functor_namestyle.apply("FunPlus");
  }


 
  // unary- operator

  std::string FunMinus_base::expression(const std::string& sa) {
    std::string sout = "-(" + sa + ")";
    return sout;
  }

  std::string FunMinus_base::classname() {
    return functor_namestyle.apply("FunMinus");
  }


  // y = a + b

  std::string FunAdd_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + " + " + "(" + sb + ")";
    return sout;
  }

  std::string FunAdd_base::classname() {
    return functor_namestyle.apply("FunAdd");
  }


  // y = a - b

  std::string FunSubtract_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + " - " + "(" + sb + ")";
    return sout;
  }

  std::string FunSubtract_base::classname() {
    return functor_namestyle.apply("FunSubtract");
  }


  // y = a * b

  std::string FunMultiply_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + "*" + "(" + sb + ")";
    return sout;
  }

  std::string FunMultiply_base::classname() {
    return functor_namestyle.apply("FunMultiply");
  }


  
  // y = a / b

  std::string FunDivide_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + "/" + "(" + sb + ")";
    return sout;
  }

  std::string FunDivide_base::classname() {
    return functor_namestyle.apply("FunDivide");
  }


  
};

