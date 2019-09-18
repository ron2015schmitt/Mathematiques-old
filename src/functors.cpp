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



  // ************************************************************************
  // *              Math 
  // ************************************************************************




  // unary+ operator
  
  std::string Fun_Plus_base::expression(const std::string& sa) {
    std::string sout = "+(" + sa + ")";
    return sout;
  }

  std::string Fun_Plus_base::classname() {
    return functor_namestyle.apply("Fun_Plus");
  }


 
  // unary- operator

  std::string Fun_Minus_base::expression(const std::string& sa) {
    std::string sout = "-(" + sa + ")";
    return sout;
  }

  std::string Fun_Minus_base::classname() {
    return functor_namestyle.apply("Fun_Minus");
  }


  // y = a + b

  std::string Fun_Add_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + " + " + "(" + sb + ")";
    return sout;
  }

  std::string Fun_Add_base::classname() {
    return functor_namestyle.apply("Fun_Add");
  }


  // y = a - b

  std::string Fun_Subtract_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + " - " + "(" + sb + ")";
    return sout;
  }

  std::string Fun_Subtract_base::classname() {
    return functor_namestyle.apply("Fun_Subtract");
  }


  // y = a * b

  std::string Fun_Multiply_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + "*" + "(" + sb + ")";
    return sout;
  }

  std::string Fun_Multiply_base::classname() {
    return functor_namestyle.apply("Fun_Multiply");
  }


  
  // y = a / b

  std::string Fun_Divide_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + "/" + "(" + sb + ")";
    return sout;
  }

  std::string Fun_Divide_base::classname() {
    return functor_namestyle.apply("Fun_Divide");
  }


  
};

