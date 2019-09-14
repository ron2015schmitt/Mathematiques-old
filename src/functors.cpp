#include "matricks.h"
//  functor in C++ sense: a class that wraps a function
//
// Use non-template base classes for the debug code and place in cpp file.
//        this speeds up compile time tremendously.

namespace matricks {


  // ************************************************************************
  // *              Math 
  // ************************************************************************



  // unary+ operator
  
  std::string FunPlus_base::expression(const std::string& sa) {
    std::string sout = "+(" + sa + ")";
    return sout;
  }



 
  // unary- operator

  std::string FunMinus_base::expression(const std::string& sa) {
    std::string sout = "-(" + sa + ")";
    return sout;
  }



  // y = a + b

  std::string FunAdd_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + " + " + "(" + sb + ")";
    return sout;
  }



  // y = a - b

  std::string FunSubtract_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + " - " + "(" + sb + ")";
    return sout;
  }

  // y = a * b

  std::string FunMultiply_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + "*" + "(" + sb + ")";
    return sout;
  }


  // y = a / b

  std::string FunDivide_base::expression(const std::string& sa, const std::string& sb) {
    std::string sout = "(" + sa + ")" + "/" + "(" + sb + ")";
    return sout;
  }



  
};

