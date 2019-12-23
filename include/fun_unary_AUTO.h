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
inline auto operatorstd::sin(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::cos(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::tan(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::asin(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::acos(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::atan(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::sinh(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::cosh(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::tanh(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_tanh<E,EOUT,D,D>>(x); 
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
inline auto operatorstd::asinh(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,D>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,D,M,R, FUNCTOR_asin<E,EOUT,D,D>>(x); 
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
inline auto operatorstd::acosh(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::atanh(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::sqrt(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::cbrt(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatormathq::sqr(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatormathq::cube(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::exp(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::exp2(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::expm1(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::log(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::log10(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::log2(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::log1p(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::logb(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatormathq::sgn(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::ceil(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::floor(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::round(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::trunc(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::erf(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::erfc(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::tgamma(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::lgamma(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::expint(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::riemann_zeta(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::comp_ellint_1(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::comp_ellint_2(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatormathq::zero(const TensorR<X,E,D,M,R>& x) {		
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
inline auto operatorstd::ilogb(const TensorR<X,E,D,M,R>& x) {		
  typedef typename NumberType<E,int>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,D,M,R>,EOUT,int,M,R, FUNCTOR_ilogb<E,EOUT,D,int>>(x); 
}
}; // namespace mathq 
#endif // MATHQ__FUN_UNARY_AUTO_H