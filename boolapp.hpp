// START-OF-NOTICE
// Copyright 2003, Columbia University
// Authors: Ron Schmitt
//
//
// This file is part of the Columbia Object Oriented 
// Linear-algebra Library (COOLL).
//
// You should have received a copy of the License Agreement for the
// COOLL along with the software;  see the file LICENSE.  
// If not, contact
// Department of Applied Physics and Applied Mathematics
// Columbia Univeristy 
// New York, NY 10027
//
// Permission to modify the code and to distribute modified code is
// granted, provided the text of this NOTICE is retained, a notice that
// the code was modified is included with the above COPYRIGHT NOTICE and
// with the COPYRIGHT NOTICE in the LICENSE file, and that the LICENSE
// file is distributed with the modified code.
//
// LICENSOR MAKES NO REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED.
// By way of example, but not limitation, Licensor MAKES NO
// REPRESENTATIONS OR WARRANTIES OF MERCHANTABILITY OR FITNESS FOR ANY
// PARTICULAR PURPOSE OR THAT THE USE OF THE LICENSED SOFTWARE COMPONENTS
// OR DOCUMENTATION WILL NOT INFRINGE ANY PATENTS, COPYRIGHTS, TRADEMARKS
// OR OTHER RIGHTS.
//
// END-OF-NOTICE
//===========================================================================





#ifndef BOOLAPP_H
#define BOOLAPP_H



#include <string>



namespace COOLL {


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

