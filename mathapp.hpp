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





#ifndef MATHAPP_H
#define MATHAPP_H



#include <cmath>
#include <string>



namespace COOLL {


  /****************************************************************************
   *              Binary applicative templates 
   ****************************************************************************/



 





  // y = pow(a,b)  
  // ie. a raised to the b power

  template <class DataT> class ApPow {
  public:
    ApPow() { }
    static inline DataT apply(DataT a, DataT b) { 
      using std::pow;
      return pow(a,b); 
    }


    static std::string debugtxt(const std::string& sa, const std::string& sb) {
      std::string sout = "pow( " + sa + " , " + sb + " )";
      return sout;
    }
  };







  /****************************************************************************
   *              unary applicative templates 
   ****************************************************************************/




  // sin(a)

  template <class DataT> class ApSin {
  public:
    ApSin() { }

    static inline DataT apply(DataT a) { 
      using std::sin;
      return sin(a); 
    }

    static std::string debugtxt(const std::string& sa) {
      std::string sout = "sin(" + sa + ")";
      return sout;
    }

  };


  // cos(a)

  template <class DataT> class ApCos {
  public:
    ApCos() { }

    static inline DataT apply(DataT a) { 
      using std::cos;
      return std::cos(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "cos(" + sa + ")";
      return sout;
    }

  };




  // tan(a)

  template <class DataT> class ApTan {
  public:
    ApTan() { }

    static inline DataT apply(DataT a) { 
      using std::tan;
      return std::tan(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "tan(" + sa + ")";
      return sout;
    }

  };


  // sqrt(a)

  template <class DataT> class ApSqrt {
  public:
    ApSqrt() { }

    static inline DataT apply(DataT a) { 
      using std::sqrt;
      return std::sqrt(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "sqrt(" + sa + ")";
      return sout;
    }

  };


  // sqr(a)

  template <class DataT> class ApSqr {
  public:
    ApSqr() { }

    static inline DataT apply(DataT a) { 
      return (a*a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "sqr(" + sa + ")";
      return sout;
    }

  };


  // cube(a)

  template <class DataT> class ApCube {
  public:
    ApCube() { }

    static inline DataT apply(DataT a) { 
      return (a*a*a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "cube(" + sa + ")";
      return sout;
    }

  };


  // exp(a)
  template <class DataT> class ApExp {
  public:
    ApExp() { }
    
    static inline DataT apply(DataT a) {
      using std::exp;
      return std::exp(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "exp(" + sa + ")";
      return sout;
    }

  };


  // abs(a)

  template <class DataT> class ApAbs {
  public:
    ApAbs() { }

    static inline DataT apply(DataT a) {
      using std::abs;
      return std::abs(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "abs(" + sa + ")";
      return sout;
    }

  };

  // sgn(a)

  template <class DataT> class ApSign {
  public:
    ApSign() { }

    static inline DataT apply(DataT a) {
      return COOLL::sgn(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "sgn(" + sa + ")";
      return sout;
    }

  };

  // log(a)

  template <class DataT> class ApLog {
  public:
    ApLog() { }

    static inline DataT apply(DataT a) {
      using std::log;
      return std::log(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "log(" + sa + ")";
      return sout;
    }

  };

  // log10(a)

  template <class DataT> class ApLog10 {
  public:
    ApLog10() { }

    static inline DataT apply(DataT a) {
      using std::log10;
      return std::log10(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "log10(" + sa + ")";
      return sout;
    }

  };

  // asin(a)

  template <class DataT> class ApAsin {
  public:
    ApAsin() { }

    static inline DataT apply(DataT a) {
      using std::asin;
      return std::asin(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "asin(" + sa + ")";
      return sout;
    }

  };

 // acos(a)

  template <class DataT> class ApAcos {
  public:
    ApAcos() { }

    static inline DataT apply(DataT a) {
      using std::acos;
      return std::acos(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "acos(" + sa + ")";
      return sout;
    }

  };

  // atan(a)

  template <class DataT> class ApAtan {
  public:
    ApAtan() { }

    static inline DataT apply(DataT a) {
      using std::atan;
      return std::atan(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "atan(" + sa + ")";
      return sout;
    }

  };
  // atan2(a)

  template <class DataT> class ApAtan2 {
  public:
    ApAtan2() { }

    static inline DataT apply(DataT a) {
      using std::atan2;
      return std::atan2(a);
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "atan2(" + sa + ")";
      return sout;
    }

  };



  // ceil(a)

  template <class DataT> class ApCeil {
  public:
    ApCeil() { }

    static inline DataT apply(DataT a) { 
      using std::ceil;
      return std::ceil(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "ceil(" + sa + ")";
      return sout;
    }

  };
  // floor(a)

  template <class DataT> class ApFloor {
  public:
    ApFloor() { }

    static inline DataT apply(DataT a) { 
      using std::floor;
      return std::floor(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "floor(" + sa + ")";
      return sout;
    }

  };
  // round(a)

  template <class DataT> class ApRound {
  public:
    ApRound() { }

    static inline DataT apply(DataT a) { 
      return COOLL::round(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "round(" + sa + ")";
      return sout;
    }

  };
  // sinh(a)

  template <class DataT> class ApSinh {
  public:
    ApSinh() { }

    static inline DataT apply(DataT a) { 
      using std::sinh;
      return std::sinh(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "sinh(" + sa + ")";
      return sout;
    }

  };
  // cosh(a)

  template <class DataT> class ApCosh {
  public:
    ApCosh() { }

    static inline DataT apply(DataT a) { 
      using std::cosh;
      return std::cosh(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "cosh(" + sa + ")";
      return sout;
    }

  };
  // tanh(a)

  template <class DataT> class ApTanh {
  public:
    ApTanh() { }

    static inline DataT apply(DataT a) { 
      using std::tanh;
      return std::tanh(a); 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "tanh(" + sa + ")";
      return sout;
    }

  };






};

#endif

