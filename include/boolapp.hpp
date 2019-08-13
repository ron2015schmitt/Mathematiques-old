
#ifndef BOOLAPP_H
#define BOOLAPP_H



#include <string>



namespace Matricks {


  /****************************************************************************
   *              Binary applicative templates 
   ****************************************************************************/







  // y = a && b

  class ApAnd {
  public:
    ApAnd() { }
  
    static inline bool apply(bool a, bool b) { 
      return a && b; 
    }

    static std::string debugtxt(const std::string& sa, const std::string& sb) {
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

    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout = "(" + sa + " || " + sb + ")";
      return sout;
    }

  };



  // y = (a == b)

   template <class DataT> class ApEqual {
  public:
    ApEqual() { }
  
    static inline bool apply(DataT a, DataT b) { 
      return (a == b); 
    }

    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout = "(" + sa + " == " + sb + ")";
      return sout;
    }

  };

 



  // y = (a != b)

   template <class DataT> class ApNotEqual {
  public:
    ApNotEqual() { }
  
    static inline bool apply(DataT a, DataT b) { 
      return (a != b); 
    }

    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout = "(" + sa + " != " + sb + ")";
      return sout;
    }

  };

 




  // y = (a <= b)

   template <class DataT> class ApLessEqual {
  public:
    ApLessEqual() { }
  
    static inline bool apply(DataT a, DataT b) { 
      return (a <= b); 
    }

    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout = "(" + sa + " <= " + sb + ")";
      return sout;
    }

  };





  // y = (a >= b)

   template <class DataT> class ApGreaterEqual {
  public:
    ApGreaterEqual() { }
  
    static inline bool apply(DataT a, DataT b) { 
      return (a >= b); 
    }

    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout = "(" + sa + " >= " + sb + ")";
      return sout;
    }

  };

 




  // y = (a < b)

   template <class DataT> class ApLess {
  public:
    ApLess() { }
  
    static inline bool apply(DataT a, DataT b) { 
      return (a < b); 
    }

    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout = "(" + sa + " < " + sb + ")";
      return sout;
    }

  };

 




  // y = (a > b)

   template <class DataT> class ApGreat {
  public:
    ApGreat() { }
  
    static inline bool apply(DataT a, DataT b) { 
      return (a > b); 
    }

    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout = "(" + sa + " > " + sb + ")";
      return sout;
    }

  };

 






  /****************************************************************************
   *              unary applicative templates 
   ****************************************************************************/




  // !(a)

  class ApNot {
  public:
    ApNot() { }

    static inline bool apply(bool a) { 
      return !(a); 
    }

    static std::string debugtxt(const std::string& sa) {
      std::string sout = "!(" + sa + ")";
      return sout;
    }

  };






};

#endif

