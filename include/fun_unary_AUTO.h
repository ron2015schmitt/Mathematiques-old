#ifndef MATHQ__FUN_UNARY_AUTO_H
#define MATHQ__FUN_UNARY_AUTO_H 1

// THIS FILE WAS *AUTO-GENERATED* BY PYTHON SCRIPT 'fun_unary.py'

namespace mathq { 



//********************************************************************
//--------------------------------------------------------------------
//                        Functors
//--------------------------------------------------------------------
//********************************************************************


  
// ----------------------------------------------------------------
// FUNCTOR_pos: template class for function '+'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_pos {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return +(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = +(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("+")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_pos")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_neg: template class for function '-'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_neg {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return -(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = -(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("-")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_neg")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_not: template class for function '!'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_not {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return !(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = !(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("!")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_not")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_sin: template class for function 'std::sin'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_sin {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::sin(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::sin(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::sin")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_sin")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_cos: template class for function 'std::cos'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_cos {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::cos(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::cos(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::cos")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_cos")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_tan: template class for function 'std::tan'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_tan {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::tan(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::tan(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::tan")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_tan")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_asin: template class for function 'std::asin'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_asin {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::asin(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::asin(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::asin")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_asin")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_acos: template class for function 'std::acos'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_acos {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::acos(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::acos(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::acos")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_acos")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_atan: template class for function 'std::atan'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_atan {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::atan(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::atan(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::atan")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_atan")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_sinh: template class for function 'std::sinh'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_sinh {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::sinh(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::sinh(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::sinh")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_sinh")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_cosh: template class for function 'std::cosh'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_cosh {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::cosh(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::cosh(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::cosh")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_cosh")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_tanh: template class for function 'std::tanh'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_tanh {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::tanh(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::tanh(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::tanh")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_tanh")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_asinh: template class for function 'std::asinh'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_asinh {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::asinh(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::asinh(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::asinh")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_asinh")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_acosh: template class for function 'std::acosh'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_acosh {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::acosh(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::acosh(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::acosh")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_acosh")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_atanh: template class for function 'std::atanh'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_atanh {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::atanh(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::atanh(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::atanh")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_atanh")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_sqrt: template class for function 'std::sqrt'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_sqrt {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::sqrt(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::sqrt(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::sqrt")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_sqrt")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_cbrt: template class for function 'std::cbrt'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_cbrt {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::cbrt(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::cbrt(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::cbrt")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_cbrt")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_sqr: template class for function 'mathq::sqr'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_sqr {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return mathq::sqr(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = mathq::sqr(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("mathq::sqr")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_sqr")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_cube: template class for function 'mathq::cube'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_cube {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return mathq::cube(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = mathq::cube(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("mathq::cube")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_cube")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_exp: template class for function 'std::exp'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_exp {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::exp(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::exp(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::exp")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_exp")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_exp2: template class for function 'std::exp2'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_exp2 {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::exp2(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::exp2(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::exp2")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_exp2")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_expm1: template class for function 'std::expm1'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_expm1 {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::expm1(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::expm1(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::expm1")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_expm1")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_log: template class for function 'std::log'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_log {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::log(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::log(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::log")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_log")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_log10: template class for function 'std::log10'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_log10 {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::log10(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::log10(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::log10")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_log10")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_log2: template class for function 'std::log2'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_log2 {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::log2(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::log2(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::log2")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_log2")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_log1p: template class for function 'std::log1p'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_log1p {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::log1p(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::log1p(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::log1p")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_log1p")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_logb: template class for function 'std::logb'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_logb {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::logb(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::logb(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::logb")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_logb")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_sgn: template class for function 'mathq::sgn'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_sgn {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return mathq::sgn(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = mathq::sgn(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("mathq::sgn")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_sgn")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_ceil: template class for function 'std::ceil'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_ceil {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::ceil(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::ceil(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::ceil")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_ceil")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_floor: template class for function 'std::floor'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_floor {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::floor(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::floor(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::floor")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_floor")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_round: template class for function 'std::round'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_round {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::round(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::round(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::round")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_round")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_trunc: template class for function 'std::trunc'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_trunc {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::trunc(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::trunc(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::trunc")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_trunc")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_erf: template class for function 'std::erf'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_erf {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::erf(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::erf(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::erf")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_erf")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_erfc: template class for function 'std::erfc'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_erfc {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::erfc(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::erfc(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::erfc")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_erfc")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_tgamma: template class for function 'std::tgamma'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_tgamma {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::tgamma(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::tgamma(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::tgamma")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_tgamma")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_lgamma: template class for function 'std::lgamma'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_lgamma {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::lgamma(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::lgamma(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::lgamma")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_lgamma")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_expint: template class for function 'std::expint'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_expint {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::expint(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::expint(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::expint")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_expint")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_riemann_zeta: template class for function 'std::riemann_zeta'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_riemann_zeta {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::riemann_zeta(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::riemann_zeta(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::riemann_zeta")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_riemann_zeta")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_comp_ellint_1: template class for function 'std::comp_ellint_1'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_comp_ellint_1 {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::comp_ellint_1(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::comp_ellint_1(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::comp_ellint_1")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_comp_ellint_1")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_comp_ellint_2: template class for function 'std::comp_ellint_2'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_comp_ellint_2 {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::comp_ellint_2(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::comp_ellint_2(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::comp_ellint_2")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_comp_ellint_2")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_zero: template class for function 'mathq::zero'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_zero {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return mathq::zero(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = mathq::zero(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("mathq::zero")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_zero")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_ilogb: template class for function 'std::ilogb'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_ilogb {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return std::ilogb(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = std::ilogb(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("std::ilogb")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_ilogb")+display::getBracketedTypeName(e); 
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_imaginary: template class for function 'mathq::Imaginary'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

template <class E, class EOUT, class DIN, class DOUT> class FUNCTOR_imaginary {	
public:								
  typedef DIN DType;							
  typedef DOUT DoutType;						
  typedef E EType;							
  typedef EOUT EoutType;
  static DOUT apply(const DIN d) {					
    return mathq::Imaginary(d);		
  }									
  template <class T=E>						
  static  typename std::enable_if<!std::is_same<T,DIN>::value, EOUT& >::type 
  apply(const E& e) {						
    EOUT *e2 = new EOUT();						
    *e2 = mathq::Imaginary(e);						
    return *e2;							
  }									
  static std::string expression(const std::string& sa) {		
    using namespace display;						
    std::string sout = "";						
    sout = functor_style.apply("mathq::Imaginary")+"("+ sa + ")";	
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E e;								
    return functor_namestyle.apply("FUNCTOR_imaginary")+display::getBracketedTypeName(e); 
  }									
};




//********************************************************************
//--------------------------------------------------------------------
//                           Functions
//--------------------------------------------------------------------
//********************************************************************




// ----------------------------------------------------------------
// pos
// template functions for 'pos'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// pos 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto operator+(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_pos<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// neg
// template functions for 'neg'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// neg 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto operator-(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_neg<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// not
// template functions for 'not'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// not 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto operator!(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_not<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// sin
// template functions for 'sin'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// sin 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto sin(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_sin<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// cos
// template functions for 'cos'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// cos 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto cos(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_cos<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// tan
// template functions for 'tan'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// tan 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto tan(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_tan<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// asin
// template functions for 'asin'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// asin 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto asin(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_asin<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// acos
// template functions for 'acos'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// acos 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto acos(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_acos<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// atan
// template functions for 'atan'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// atan 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto atan(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_atan<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// sinh
// template functions for 'sinh'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// sinh 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto sinh(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_sinh<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// cosh
// template functions for 'cosh'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// cosh 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto cosh(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_cosh<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// tanh
// template functions for 'tanh'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// tanh 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto tanh(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_tanh<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// asinh
// template functions for 'asinh'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// asinh 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto asinh(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_asinh<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// acosh
// template functions for 'acosh'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// acosh 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto acosh(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_acosh<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// atanh
// template functions for 'atanh'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// atanh 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto atanh(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_atanh<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// sqrt
// template functions for 'sqrt'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// sqrt 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto sqrt(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_sqrt<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// cbrt
// template functions for 'cbrt'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// cbrt 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto cbrt(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_cbrt<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// sqr
// template functions for 'sqr'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// sqr 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto sqr(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_sqr<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// cube
// template functions for 'cube'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// cube 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto cube(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_cube<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// exp
// template functions for 'exp'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// exp 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto exp(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_exp<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// exp2
// template functions for 'exp2'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// exp2 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto exp2(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_exp2<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// expm1
// template functions for 'expm1'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// expm1 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto expm1(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_expm1<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// log
// template functions for 'log'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// log 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto log(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_log<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// log10
// template functions for 'log10'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// log10 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto log10(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_log10<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// log2
// template functions for 'log2'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// log2 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto log2(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_log2<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// log1p
// template functions for 'log1p'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// log1p 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto log1p(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_log1p<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// logb
// template functions for 'logb'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// logb 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto logb(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_logb<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// sgn
// template functions for 'sgn'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// sgn 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto sgn(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_sgn<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// ceil
// template functions for 'ceil'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// ceil 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto ceil(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_ceil<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// floor
// template functions for 'floor'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// floor 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto floor(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_floor<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// round
// template functions for 'round'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// round 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto round(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_round<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// trunc
// template functions for 'trunc'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// trunc 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto trunc(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_trunc<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// erf
// template functions for 'erf'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// erf 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto erf(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_erf<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// erfc
// template functions for 'erfc'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// erfc 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto erfc(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_erfc<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// tgamma
// template functions for 'tgamma'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// tgamma 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto tgamma(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_tgamma<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// lgamma
// template functions for 'lgamma'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// lgamma 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto lgamma(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_lgamma<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// expint
// template functions for 'expint'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// expint 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto expint(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_expint<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// riemann_zeta
// template functions for 'riemann_zeta'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// riemann_zeta 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto riemann_zeta(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_riemann_zeta<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// comp_ellint_1
// template functions for 'comp_ellint_1'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// comp_ellint_1 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto comp_ellint_1(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_comp_ellint_1<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// comp_ellint_2
// template functions for 'comp_ellint_2'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// comp_ellint_2 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto comp_ellint_2(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_comp_ellint_2<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// zero
// template functions for 'zero'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// zero 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto zero(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_zero<E,EOUT,D,D>>(x); 
}


// ----------------------------------------------------------------
// ilogb
// template functions for 'ilogb'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// ilogb 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto ilogb(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,int>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,int,M,R, FUNCTOR_ilogb<E,EOUT,D,int>>(x); 
}


// ----------------------------------------------------------------
// imaginary
// template functions for 'imaginary'
//
//    Note: generated from template file 'fun_unary_functor.hpp'
//          using Python script 'fun_unary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// imaginary 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto imaginary(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,mathq::Imaginary<D>>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,mathq::Imaginary<D>,M,R, FUNCTOR_imaginary<E,EOUT,D,mathq::Imaginary<D>>>(x); 
}
}; // namespace mathq 
#endif // MATHQ__FUN_UNARY_AUTO_H