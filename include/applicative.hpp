


#ifndef APPLICATIVE_H
#define APPLICATIVE_H


//
//
//  *** Compilation time could be cut drastically when in "DEBUG" mode
// by placing all the debug functions in nontemplated fucntions.
// see note in verror.cpp for more info





#include <string>



namespace Matricks {


  /****************************************************************************
   *              Binary applicative templates 
   ****************************************************************************/



  // y = a + b

  template <class DataT> class ApAdd {
  public:
    ApAdd() { }
  
    static inline DataT apply(DataT a, DataT b) { 
      return a+b; 
    }

    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " + " + sb;
      return sout;
    }

  };



  // y = a - b

  template <class DataT> class ApSubtract {
  public:
    ApSubtract() { }
  
    static inline DataT apply(DataT a, DataT b) { 
      return a-b; 
    }

    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " - " + sb;
      return sout;
    }
  };




  // y = a * b

  template <class DataT> class ApMultiply {
  public:
    ApMultiply() { }

    static inline DataT apply(DataT a, DataT b) { 
      return a*b; 
    }

    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " * " + sb;
      return sout;
    }
  };




  // y = a / b

  template <class DataT> class ApDivide {
  public:
    ApDivide() { }

    static inline DataT apply(DataT a, DataT b) { 
      return a/b; 
    }

    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout = sa + " / " + sb;
      return sout;
    }
  };









  /****************************************************************************
   *              unary applicative templates 
   ****************************************************************************/


  // unary+

  template <class DataT> class ApPlus {

  public:
    ApPlus() { }

    static inline DataT apply(DataT a) { 
      return a; 
    }

    static std::string debugtxt(const std::string& sa) {
      std::string sout = "+(" + sa + ")";
      return sout;
    }

  };

  // unary-

  template <class DataT> class ApMinus {
  public:
    ApMinus() { }

    static inline DataT apply(DataT a) { 
      return (-a); 
    }

    static std::string debugtxt(const std::string& sa) {
      std::string sout = "-(" + sa + ")";
      return sout;
    }

  };


  // cast

  template <class D1, class D2> class ApCast {
  public:
    ApCast() { }

    static inline D2 apply(D1 a) { 
      return static_cast<D2 >(a); 
    }

    static std::string debugtxt(const std::string& sa) {
      std::ostringstream stream;
      stream << typeid(D2).name();
      std::string tname = stream.str();
      std::string sout = "cast<" + tname + ">(" + sa + ")";
      return sout;
    }

  };






};

#endif

