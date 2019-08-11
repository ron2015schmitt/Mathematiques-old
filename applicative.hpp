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


//
//
//  *** Compilation time could be cut drastically when in "CAREFUL" mode
// by placing all the debug functions in nontemplated fucntions.
// see note in verror.cpp for more info



#ifndef APPLICATIVE_H
#define APPLICATIVE_H



#include <string>



namespace COOLL {


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

