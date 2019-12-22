#ifndef MATHQ__FUN_BINARY_AUTO_H
#define MATHQ__FUN_BINARY_AUTO_H 1

// THIS FILE WAS *AUTO-GENERATED* BY PYTHON SCRIPT 'fun_binary.py'

namespace mathq { 



//********************************************************************
//--------------------------------------------------------------------
//                           Functors
//--------------------------------------------------------------------
//********************************************************************


  
// ----------------------------------------------------------------
// FUNCTOR_add: template class for operator '+'
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_add { 
public:								
  static D3 apply(const D1 d1, const D2 d2) {				
    return d1 + d2;							
  }									
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = e1 + e2;							
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2) {					
    E3 *e3 = new E3();							
    *e3 = e1 + d2;							
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = d1 + e2;							
    return *e3;								
  }									
  static std::string expression(const std::string& sa, const std::string& sb) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" + "+ sb;					
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;								
    D1 d1;								
    D2 d2;								
    D3 d3;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_add)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_subtract: template class for operator '-'
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_subtract { 
public:								
  static D3 apply(const D1 d1, const D2 d2) {				
    return d1 - d2;							
  }									
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = e1 - e2;							
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2) {					
    E3 *e3 = new E3();							
    *e3 = e1 - d2;							
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = d1 - e2;							
    return *e3;								
  }									
  static std::string expression(const std::string& sa, const std::string& sb) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" - "+ sb;					
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;								
    D1 d1;								
    D2 d2;								
    D3 d3;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_subtract)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_multiply: template class for operator '*'
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_multiply { 
public:								
  static D3 apply(const D1 d1, const D2 d2) {				
    return d1 * d2;							
  }									
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = e1 * e2;							
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2) {					
    E3 *e3 = new E3();							
    *e3 = e1 * d2;							
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = d1 * e2;							
    return *e3;								
  }									
  static std::string expression(const std::string& sa, const std::string& sb) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" * "+ sb;					
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;								
    D1 d1;								
    D2 d2;								
    D3 d3;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_multiply)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_divide: template class for operator '/'
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_divide { 
public:								
  static D3 apply(const D1 d1, const D2 d2) {				
    return d1 / d2;							
  }									
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = e1 / e2;							
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2) {					
    E3 *e3 = new E3();							
    *e3 = e1 / d2;							
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = d1 / e2;							
    return *e3;								
  }									
  static std::string expression(const std::string& sa, const std::string& sb) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" / "+ sb;					
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;								
    D1 d1;								
    D2 d2;								
    D3 d3;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_divide)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_equals: template class for operator '=='
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_equals { 
public:								
  static D3 apply(const D1 d1, const D2 d2) {				
    return d1 == d2;							
  }									
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = e1 == e2;							
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2) {					
    E3 *e3 = new E3();							
    *e3 = e1 == d2;							
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = d1 == e2;							
    return *e3;								
  }									
  static std::string expression(const std::string& sa, const std::string& sb) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" == "+ sb;					
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;								
    D1 d1;								
    D2 d2;								
    D3 d3;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_equals)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_notequals: template class for operator '!='
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_notequals { 
public:								
  static D3 apply(const D1 d1, const D2 d2) {				
    return d1 != d2;							
  }									
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = e1 != e2;							
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2) {					
    E3 *e3 = new E3();							
    *e3 = e1 != d2;							
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = d1 != e2;							
    return *e3;								
  }									
  static std::string expression(const std::string& sa, const std::string& sb) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" != "+ sb;					
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;								
    D1 d1;								
    D2 d2;								
    D3 d3;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_notequals)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_greater: template class for operator '>'
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_greater { 
public:								
  static D3 apply(const D1 d1, const D2 d2) {				
    return d1 > d2;							
  }									
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = e1 > e2;							
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2) {					
    E3 *e3 = new E3();							
    *e3 = e1 > d2;							
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = d1 > e2;							
    return *e3;								
  }									
  static std::string expression(const std::string& sa, const std::string& sb) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" > "+ sb;					
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;								
    D1 d1;								
    D2 d2;								
    D3 d3;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_greater)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_greatereq: template class for operator '>='
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_greatereq { 
public:								
  static D3 apply(const D1 d1, const D2 d2) {				
    return d1 >= d2;							
  }									
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = e1 >= e2;							
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2) {					
    E3 *e3 = new E3();							
    *e3 = e1 >= d2;							
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = d1 >= e2;							
    return *e3;								
  }									
  static std::string expression(const std::string& sa, const std::string& sb) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" >= "+ sb;					
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;								
    D1 d1;								
    D2 d2;								
    D3 d3;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_greatereq)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_less: template class for operator '<'
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_less { 
public:								
  static D3 apply(const D1 d1, const D2 d2) {				
    return d1 < d2;							
  }									
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = e1 < e2;							
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2) {					
    E3 *e3 = new E3();							
    *e3 = e1 < d2;							
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = d1 < e2;							
    return *e3;								
  }									
  static std::string expression(const std::string& sa, const std::string& sb) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" < "+ sb;					
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;								
    D1 d1;								
    D2 d2;								
    D3 d3;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_less)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_lesseq: template class for operator '<='
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_lesseq { 
public:								
  static D3 apply(const D1 d1, const D2 d2) {				
    return d1 <= d2;							
  }									
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = e1 <= e2;							
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2) {					
    E3 *e3 = new E3();							
    *e3 = e1 <= d2;							
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = d1 <= e2;							
    return *e3;								
  }									
  static std::string expression(const std::string& sa, const std::string& sb) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" <= "+ sb;					
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;								
    D1 d1;								
    D2 d2;								
    D3 d3;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_lesseq)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_and: template class for operator '&&'
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_and { 
public:								
  static D3 apply(const D1 d1, const D2 d2) {				
    return d1 && d2;							
  }									
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = e1 && e2;							
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2) {					
    E3 *e3 = new E3();							
    *e3 = e1 && d2;							
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = d1 && e2;							
    return *e3;								
  }									
  static std::string expression(const std::string& sa, const std::string& sb) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" && "+ sb;					
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;								
    D1 d1;								
    D2 d2;								
    D3 d3;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_and)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};

  
// ----------------------------------------------------------------
// FUNCTOR_or: template class for operator '||'
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

  
template <class E1, class E2, class E3, class D1, class D2, class D3> class FUNCTOR_or { 
public:								
  static D3 apply(const D1 d1, const D2 d2) {				
    return d1 || d2;							
  }									
  template <class T1=E1, class T2=E2>						
  static typename std::enable_if<!std::is_same<T1,D1>::value&&!std::is_same<T2,D2>::value, E3& >::type 
  apply(const E1& e1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = e1 || e2;							
    return *e3;								
  }									
  template <class T1=E1>						
  static typename std::enable_if<!std::is_same<T1,D1>::value, E3& >::type 
  apply(const E1& e1, const D2 d2) {					
    E3 *e3 = new E3();							
    *e3 = e1 || d2;							
    return *e3;								
  }									
  template <class T2=E2>						
  static typename std::enable_if<!std::is_same<T2,D2>::value, E3& >::type 
  apply(const D1 d1, const E2& e2) {					
    E3 *e3 = new E3();							
    *e3 = d1 || e2;							
    return *e3;								
  }									
  static std::string expression(const std::string& sa, const std::string& sb) {	
    using namespace display;						
    std::string sout = "";						
    sout = sa +" || "+ sb;					
    return sout;							
  }									
  static std::string classname() {					
    using namespace display;						
    E1 e1;								
    E2 e2;								
    E3 e3;								
    D1 d1;								
    D2 d2;								
    D3 d3;								
    std::string comma =  StyledString::get(COMMA).get();		
    std::string s = functor_namestyle.apply(stringify(FUNCTOR_or)); 
    s += StyledString::get(BRACKET1).get();				
    s += getTypeName(e1);						
    s += comma + getTypeName(e2);					
    s += comma + getTypeName(e3);					
    s += comma + getTypeName(d1);					
    s += comma + getTypeName(d2);					
    s += comma + getTypeName(d3);					
    s += StyledString::get(BRACKET2).get();				
    return s;								
  }									
};




//********************************************************************
//--------------------------------------------------------------------
//                           Functions
//--------------------------------------------------------------------
//********************************************************************




// ----------------------------------------------------------------
// Addition
// template function classes for operator '+'
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Addition (+)
//----------------------------------------------

// (1) Tensor<E1(D1)> + Tensor<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
auto operator+(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2) {
  typedef typename AddType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<TensorR<A,E1,D1,M,R>,
		     TensorR<B,E2,D2,M,R>,
		     E1,E2,E3,D1,D2,D3,M,M,M,R,R,R,
		     FUNCTOR_add<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// (2A) Tensor<E(D1)> + D2

template <class A, class D2, class E, class D1, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>> 
auto operator+(const TensorR<A,E,D1,M,R>& x1, const D2& x2) {
  typedef typename AddType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<TensorR<A,E,D1,M,R>,
		     D2,
		     E,Null,E3,D1,D2,D3,M,0,M,R,R,R,
		     FUNCTOR_add<E,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// (2B) D1 + Tensor<E(D2)>

template <class D1, class B, class E, class D2, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>> 
auto operator+(const D1& x1, const TensorR<B,E,D2,M,R>& x2) {
  typedef typename AddType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     TensorR<B,E,D2,M,R>,
		     Null,E,E3,D1,D2,D3,0,M,M,R,R,R,
		     FUNCTOR_add<Null,E,E3,D1,D2,D3> >(x1,x2); 
}


  
// (3A) element-wise Addition: x1[i] + x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<TensorAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator+(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename AddType<D1,D2>::Type D3;
  typedef E1 E;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;
  //    mout << "A" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_add<E,E,E3,D1,D2,D3> >(x1,x2); 
}


// (3B) element-wise Addition: x1 + x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<TensorAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator+(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename AddType<D1,D2>::Type D3;
  typedef E2 E;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;  
  //    mout << "B" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_add<E,E,E3,D1,D2,D3> >(x1,x2); 
}

    
// (4A) Tensor<D1,R,M> + Tensor<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Addition
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<TensorAbstract,E1>::value)> = 0  >
auto operator+(const TensorR<A,E1,D1,M1,R>& x1, const TensorR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef TensorR<B,D2,D2,M2,R> E2;  

  typedef typename AddType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    mout << "C" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R>,
		     TensorR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_add<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// (4B) Tensor<D1,R,1> + Tensor<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Addition
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<TensorAbstract,E2>::value)> = 0  >
auto operator+(const TensorR<A,D1,D1,M1,R>& x1, const TensorR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef TensorR<A,D1,D1,M1,R> E1;  
  typedef typename AddType<D1,D2>::Type D3;
  typedef typename NumberType<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    mout << "D" <<std::endl;
  return  TER_Binary<TensorR<A,D1,D1,M1,R>,
		     TensorR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_add<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}





// ----------------------------------------------------------------
// Subtraction
// template function classes for operator '-'
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Subtraction (-)
//----------------------------------------------

// (1) Tensor<E1(D1)> - Tensor<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
auto operator-(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2) {
  typedef typename SubType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<TensorR<A,E1,D1,M,R>,
		     TensorR<B,E2,D2,M,R>,
		     E1,E2,E3,D1,D2,D3,M,M,M,R,R,R,
		     FUNCTOR_subtract<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// (2A) Tensor<E(D1)> - D2

template <class A, class D2, class E, class D1, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>> 
auto operator-(const TensorR<A,E,D1,M,R>& x1, const D2& x2) {
  typedef typename SubType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<TensorR<A,E,D1,M,R>,
		     D2,
		     E,Null,E3,D1,D2,D3,M,0,M,R,R,R,
		     FUNCTOR_subtract<E,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// (2B) D1 - Tensor<E(D2)>

template <class D1, class B, class E, class D2, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>> 
auto operator-(const D1& x1, const TensorR<B,E,D2,M,R>& x2) {
  typedef typename SubType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     TensorR<B,E,D2,M,R>,
		     Null,E,E3,D1,D2,D3,0,M,M,R,R,R,
		     FUNCTOR_subtract<Null,E,E3,D1,D2,D3> >(x1,x2); 
}


  
// (3A) element-wise Subtraction: x1[i] - x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<TensorAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator-(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename SubType<D1,D2>::Type D3;
  typedef E1 E;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;
  //    mout << "A" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_subtract<E,E,E3,D1,D2,D3> >(x1,x2); 
}


// (3B) element-wise Subtraction: x1 - x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<TensorAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator-(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename SubType<D1,D2>::Type D3;
  typedef E2 E;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;  
  //    mout << "B" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_subtract<E,E,E3,D1,D2,D3> >(x1,x2); 
}

    
// (4A) Tensor<D1,R,M> - Tensor<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Subtraction
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<TensorAbstract,E1>::value)> = 0  >
auto operator-(const TensorR<A,E1,D1,M1,R>& x1, const TensorR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef TensorR<B,D2,D2,M2,R> E2;  

  typedef typename SubType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    mout << "C" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R>,
		     TensorR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_subtract<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// (4B) Tensor<D1,R,1> - Tensor<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Subtraction
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<TensorAbstract,E2>::value)> = 0  >
auto operator-(const TensorR<A,D1,D1,M1,R>& x1, const TensorR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef TensorR<A,D1,D1,M1,R> E1;  
  typedef typename SubType<D1,D2>::Type D3;
  typedef typename NumberType<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    mout << "D" <<std::endl;
  return  TER_Binary<TensorR<A,D1,D1,M1,R>,
		     TensorR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_subtract<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}





// ----------------------------------------------------------------
// Multiplication
// template function classes for operator '*'
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Multiplication (*)
//----------------------------------------------

// (1) Tensor<E1(D1)> * Tensor<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
auto operator*(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2) {
  typedef typename MultType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<TensorR<A,E1,D1,M,R>,
		     TensorR<B,E2,D2,M,R>,
		     E1,E2,E3,D1,D2,D3,M,M,M,R,R,R,
		     FUNCTOR_multiply<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// (2A) Tensor<E(D1)> * D2

template <class A, class D2, class E, class D1, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>> 
auto operator*(const TensorR<A,E,D1,M,R>& x1, const D2& x2) {
  typedef typename MultType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<TensorR<A,E,D1,M,R>,
		     D2,
		     E,Null,E3,D1,D2,D3,M,0,M,R,R,R,
		     FUNCTOR_multiply<E,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// (2B) D1 * Tensor<E(D2)>

template <class D1, class B, class E, class D2, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>> 
auto operator*(const D1& x1, const TensorR<B,E,D2,M,R>& x2) {
  typedef typename MultType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     TensorR<B,E,D2,M,R>,
		     Null,E,E3,D1,D2,D3,0,M,M,R,R,R,
		     FUNCTOR_multiply<Null,E,E3,D1,D2,D3> >(x1,x2); 
}


  
// (3A) element-wise Multiplication: x1[i] * x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<TensorAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator*(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename MultType<D1,D2>::Type D3;
  typedef E1 E;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;
  //    mout << "A" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_multiply<E,E,E3,D1,D2,D3> >(x1,x2); 
}


// (3B) element-wise Multiplication: x1 * x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<TensorAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator*(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename MultType<D1,D2>::Type D3;
  typedef E2 E;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;  
  //    mout << "B" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_multiply<E,E,E3,D1,D2,D3> >(x1,x2); 
}

    
// (4A) Tensor<D1,R,M> * Tensor<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Multiplication
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<TensorAbstract,E1>::value)> = 0  >
auto operator*(const TensorR<A,E1,D1,M1,R>& x1, const TensorR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef TensorR<B,D2,D2,M2,R> E2;  

  typedef typename MultType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    mout << "C" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R>,
		     TensorR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_multiply<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// (4B) Tensor<D1,R,1> * Tensor<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Multiplication
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<TensorAbstract,E2>::value)> = 0  >
auto operator*(const TensorR<A,D1,D1,M1,R>& x1, const TensorR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef TensorR<A,D1,D1,M1,R> E1;  
  typedef typename MultType<D1,D2>::Type D3;
  typedef typename NumberType<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    mout << "D" <<std::endl;
  return  TER_Binary<TensorR<A,D1,D1,M1,R>,
		     TensorR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_multiply<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}





// ----------------------------------------------------------------
// Division
// template function classes for operator '/'
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Division (/)
//----------------------------------------------

// (1) Tensor<E1(D1)> / Tensor<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
auto operator/(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2) {
  typedef typename DivType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<TensorR<A,E1,D1,M,R>,
		     TensorR<B,E2,D2,M,R>,
		     E1,E2,E3,D1,D2,D3,M,M,M,R,R,R,
		     FUNCTOR_divide<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// (2A) Tensor<E(D1)> / D2

template <class A, class D2, class E, class D1, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>> 
auto operator/(const TensorR<A,E,D1,M,R>& x1, const D2& x2) {
  typedef typename DivType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<TensorR<A,E,D1,M,R>,
		     D2,
		     E,Null,E3,D1,D2,D3,M,0,M,R,R,R,
		     FUNCTOR_divide<E,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// (2B) D1 / Tensor<E(D2)>

template <class D1, class B, class E, class D2, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>> 
auto operator/(const D1& x1, const TensorR<B,E,D2,M,R>& x2) {
  typedef typename DivType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     TensorR<B,E,D2,M,R>,
		     Null,E,E3,D1,D2,D3,0,M,M,R,R,R,
		     FUNCTOR_divide<Null,E,E3,D1,D2,D3> >(x1,x2); 
}


  
// (3A) element-wise Division: x1[i] / x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<TensorAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator/(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename DivType<D1,D2>::Type D3;
  typedef E1 E;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;
  //    mout << "A" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_divide<E,E,E3,D1,D2,D3> >(x1,x2); 
}


// (3B) element-wise Division: x1 / x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<TensorAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator/(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename DivType<D1,D2>::Type D3;
  typedef E2 E;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;  
  //    mout << "B" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_divide<E,E,E3,D1,D2,D3> >(x1,x2); 
}

    
// (4A) Tensor<D1,R,M> / Tensor<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Division
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<TensorAbstract,E1>::value)> = 0  >
auto operator/(const TensorR<A,E1,D1,M1,R>& x1, const TensorR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef TensorR<B,D2,D2,M2,R> E2;  

  typedef typename DivType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    mout << "C" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R>,
		     TensorR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_divide<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// (4B) Tensor<D1,R,1> / Tensor<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Division
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<TensorAbstract,E2>::value)> = 0  >
auto operator/(const TensorR<A,D1,D1,M1,R>& x1, const TensorR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef TensorR<A,D1,D1,M1,R> E1;  
  typedef typename DivType<D1,D2>::Type D3;
  typedef typename NumberType<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    mout << "D" <<std::endl;
  return  TER_Binary<TensorR<A,D1,D1,M1,R>,
		     TensorR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_divide<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}





// ----------------------------------------------------------------
// Equal to
// template function classes for operator '=='
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Equal to (==)
//----------------------------------------------

// (1) Tensor<E1(D1)> == Tensor<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
auto operator==(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<TensorR<A,E1,D1,M,R>,
		     TensorR<B,E2,D2,M,R>,
		     E1,E2,E3,D1,D2,D3,M,M,M,R,R,R,
		     FUNCTOR_equals<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// (2A) Tensor<E(D1)> == D2

template <class A, class D2, class E, class D1, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>> 
auto operator==(const TensorR<A,E,D1,M,R>& x1, const D2& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<TensorR<A,E,D1,M,R>,
		     D2,
		     E,Null,E3,D1,D2,D3,M,0,M,R,R,R,
		     FUNCTOR_equals<E,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// (2B) D1 == Tensor<E(D2)>

template <class D1, class B, class E, class D2, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>> 
auto operator==(const D1& x1, const TensorR<B,E,D2,M,R>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     TensorR<B,E,D2,M,R>,
		     Null,E,E3,D1,D2,D3,0,M,M,R,R,R,
		     FUNCTOR_equals<Null,E,E3,D1,D2,D3> >(x1,x2); 
}


  
// (3A) element-wise Equal to: x1[i] == x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<TensorAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator==(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef E1 E;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;
  //    mout << "A" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_equals<E,E,E3,D1,D2,D3> >(x1,x2); 
}


// (3B) element-wise Equal to: x1 == x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<TensorAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator==(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef E2 E;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;  
  //    mout << "B" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_equals<E,E,E3,D1,D2,D3> >(x1,x2); 
}

    
// (4A) Tensor<D1,R,M> == Tensor<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Equal to
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<TensorAbstract,E1>::value)> = 0  >
auto operator==(const TensorR<A,E1,D1,M1,R>& x1, const TensorR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef TensorR<B,D2,D2,M2,R> E2;  

  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    mout << "C" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R>,
		     TensorR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_equals<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// (4B) Tensor<D1,R,1> == Tensor<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Equal to
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<TensorAbstract,E2>::value)> = 0  >
auto operator==(const TensorR<A,D1,D1,M1,R>& x1, const TensorR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef TensorR<A,D1,D1,M1,R> E1;  
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    mout << "D" <<std::endl;
  return  TER_Binary<TensorR<A,D1,D1,M1,R>,
		     TensorR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_equals<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}





// ----------------------------------------------------------------
// Not equal to
// template function classes for operator '!='
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Not equal to (!=)
//----------------------------------------------

// (1) Tensor<E1(D1)> != Tensor<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
auto operator!=(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<TensorR<A,E1,D1,M,R>,
		     TensorR<B,E2,D2,M,R>,
		     E1,E2,E3,D1,D2,D3,M,M,M,R,R,R,
		     FUNCTOR_notequals<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// (2A) Tensor<E(D1)> != D2

template <class A, class D2, class E, class D1, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>> 
auto operator!=(const TensorR<A,E,D1,M,R>& x1, const D2& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<TensorR<A,E,D1,M,R>,
		     D2,
		     E,Null,E3,D1,D2,D3,M,0,M,R,R,R,
		     FUNCTOR_notequals<E,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// (2B) D1 != Tensor<E(D2)>

template <class D1, class B, class E, class D2, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>> 
auto operator!=(const D1& x1, const TensorR<B,E,D2,M,R>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     TensorR<B,E,D2,M,R>,
		     Null,E,E3,D1,D2,D3,0,M,M,R,R,R,
		     FUNCTOR_notequals<Null,E,E3,D1,D2,D3> >(x1,x2); 
}


  
// (3A) element-wise Not equal to: x1[i] != x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<TensorAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator!=(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef E1 E;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;
  //    mout << "A" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_notequals<E,E,E3,D1,D2,D3> >(x1,x2); 
}


// (3B) element-wise Not equal to: x1 != x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<TensorAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator!=(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef E2 E;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;  
  //    mout << "B" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_notequals<E,E,E3,D1,D2,D3> >(x1,x2); 
}

    
// (4A) Tensor<D1,R,M> != Tensor<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Not equal to
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<TensorAbstract,E1>::value)> = 0  >
auto operator!=(const TensorR<A,E1,D1,M1,R>& x1, const TensorR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef TensorR<B,D2,D2,M2,R> E2;  

  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    mout << "C" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R>,
		     TensorR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_notequals<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// (4B) Tensor<D1,R,1> != Tensor<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Not equal to
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<TensorAbstract,E2>::value)> = 0  >
auto operator!=(const TensorR<A,D1,D1,M1,R>& x1, const TensorR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef TensorR<A,D1,D1,M1,R> E1;  
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    mout << "D" <<std::endl;
  return  TER_Binary<TensorR<A,D1,D1,M1,R>,
		     TensorR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_notequals<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}





// ----------------------------------------------------------------
// Greater than
// template function classes for operator '>'
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Greater than (>)
//----------------------------------------------

// (1) Tensor<E1(D1)> > Tensor<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
auto operator>(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<TensorR<A,E1,D1,M,R>,
		     TensorR<B,E2,D2,M,R>,
		     E1,E2,E3,D1,D2,D3,M,M,M,R,R,R,
		     FUNCTOR_greater<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// (2A) Tensor<E(D1)> > D2

template <class A, class D2, class E, class D1, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>> 
auto operator>(const TensorR<A,E,D1,M,R>& x1, const D2& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<TensorR<A,E,D1,M,R>,
		     D2,
		     E,Null,E3,D1,D2,D3,M,0,M,R,R,R,
		     FUNCTOR_greater<E,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// (2B) D1 > Tensor<E(D2)>

template <class D1, class B, class E, class D2, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>> 
auto operator>(const D1& x1, const TensorR<B,E,D2,M,R>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     TensorR<B,E,D2,M,R>,
		     Null,E,E3,D1,D2,D3,0,M,M,R,R,R,
		     FUNCTOR_greater<Null,E,E3,D1,D2,D3> >(x1,x2); 
}


  
// (3A) element-wise Greater than: x1[i] > x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<TensorAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator>(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef E1 E;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;
  //    mout << "A" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_greater<E,E,E3,D1,D2,D3> >(x1,x2); 
}


// (3B) element-wise Greater than: x1 > x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<TensorAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator>(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef E2 E;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;  
  //    mout << "B" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_greater<E,E,E3,D1,D2,D3> >(x1,x2); 
}

    
// (4A) Tensor<D1,R,M> > Tensor<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Greater than
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<TensorAbstract,E1>::value)> = 0  >
auto operator>(const TensorR<A,E1,D1,M1,R>& x1, const TensorR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef TensorR<B,D2,D2,M2,R> E2;  

  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    mout << "C" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R>,
		     TensorR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_greater<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// (4B) Tensor<D1,R,1> > Tensor<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Greater than
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<TensorAbstract,E2>::value)> = 0  >
auto operator>(const TensorR<A,D1,D1,M1,R>& x1, const TensorR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef TensorR<A,D1,D1,M1,R> E1;  
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    mout << "D" <<std::endl;
  return  TER_Binary<TensorR<A,D1,D1,M1,R>,
		     TensorR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_greater<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}





// ----------------------------------------------------------------
// Greater than or equal to
// template function classes for operator '>='
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Greater than or equal to (>=)
//----------------------------------------------

// (1) Tensor<E1(D1)> >= Tensor<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
auto operator>=(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<TensorR<A,E1,D1,M,R>,
		     TensorR<B,E2,D2,M,R>,
		     E1,E2,E3,D1,D2,D3,M,M,M,R,R,R,
		     FUNCTOR_greatereq<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// (2A) Tensor<E(D1)> >= D2

template <class A, class D2, class E, class D1, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>> 
auto operator>=(const TensorR<A,E,D1,M,R>& x1, const D2& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<TensorR<A,E,D1,M,R>,
		     D2,
		     E,Null,E3,D1,D2,D3,M,0,M,R,R,R,
		     FUNCTOR_greatereq<E,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// (2B) D1 >= Tensor<E(D2)>

template <class D1, class B, class E, class D2, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>> 
auto operator>=(const D1& x1, const TensorR<B,E,D2,M,R>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     TensorR<B,E,D2,M,R>,
		     Null,E,E3,D1,D2,D3,0,M,M,R,R,R,
		     FUNCTOR_greatereq<Null,E,E3,D1,D2,D3> >(x1,x2); 
}


  
// (3A) element-wise Greater than or equal to: x1[i] >= x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<TensorAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator>=(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef E1 E;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;
  //    mout << "A" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_greatereq<E,E,E3,D1,D2,D3> >(x1,x2); 
}


// (3B) element-wise Greater than or equal to: x1 >= x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<TensorAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator>=(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef E2 E;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;  
  //    mout << "B" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_greatereq<E,E,E3,D1,D2,D3> >(x1,x2); 
}

    
// (4A) Tensor<D1,R,M> >= Tensor<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Greater than or equal to
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<TensorAbstract,E1>::value)> = 0  >
auto operator>=(const TensorR<A,E1,D1,M1,R>& x1, const TensorR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef TensorR<B,D2,D2,M2,R> E2;  

  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    mout << "C" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R>,
		     TensorR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_greatereq<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// (4B) Tensor<D1,R,1> >= Tensor<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Greater than or equal to
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<TensorAbstract,E2>::value)> = 0  >
auto operator>=(const TensorR<A,D1,D1,M1,R>& x1, const TensorR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef TensorR<A,D1,D1,M1,R> E1;  
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    mout << "D" <<std::endl;
  return  TER_Binary<TensorR<A,D1,D1,M1,R>,
		     TensorR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_greatereq<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}





// ----------------------------------------------------------------
// Less than
// template function classes for operator '<'
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Less than (<)
//----------------------------------------------

// (1) Tensor<E1(D1)> < Tensor<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
auto operator<(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<TensorR<A,E1,D1,M,R>,
		     TensorR<B,E2,D2,M,R>,
		     E1,E2,E3,D1,D2,D3,M,M,M,R,R,R,
		     FUNCTOR_less<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// (2A) Tensor<E(D1)> < D2

template <class A, class D2, class E, class D1, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>> 
auto operator<(const TensorR<A,E,D1,M,R>& x1, const D2& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<TensorR<A,E,D1,M,R>,
		     D2,
		     E,Null,E3,D1,D2,D3,M,0,M,R,R,R,
		     FUNCTOR_less<E,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// (2B) D1 < Tensor<E(D2)>

template <class D1, class B, class E, class D2, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>> 
auto operator<(const D1& x1, const TensorR<B,E,D2,M,R>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     TensorR<B,E,D2,M,R>,
		     Null,E,E3,D1,D2,D3,0,M,M,R,R,R,
		     FUNCTOR_less<Null,E,E3,D1,D2,D3> >(x1,x2); 
}


  
// (3A) element-wise Less than: x1[i] < x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<TensorAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator<(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef E1 E;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;
  //    mout << "A" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_less<E,E,E3,D1,D2,D3> >(x1,x2); 
}


// (3B) element-wise Less than: x1 < x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<TensorAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator<(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef E2 E;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;  
  //    mout << "B" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_less<E,E,E3,D1,D2,D3> >(x1,x2); 
}

    
// (4A) Tensor<D1,R,M> < Tensor<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Less than
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<TensorAbstract,E1>::value)> = 0  >
auto operator<(const TensorR<A,E1,D1,M1,R>& x1, const TensorR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef TensorR<B,D2,D2,M2,R> E2;  

  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    mout << "C" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R>,
		     TensorR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_less<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// (4B) Tensor<D1,R,1> < Tensor<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Less than
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<TensorAbstract,E2>::value)> = 0  >
auto operator<(const TensorR<A,D1,D1,M1,R>& x1, const TensorR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef TensorR<A,D1,D1,M1,R> E1;  
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    mout << "D" <<std::endl;
  return  TER_Binary<TensorR<A,D1,D1,M1,R>,
		     TensorR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_less<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}





// ----------------------------------------------------------------
// Less than or equal to
// template function classes for operator '<='
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Less than or equal to (<=)
//----------------------------------------------

// (1) Tensor<E1(D1)> <= Tensor<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
auto operator<=(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<TensorR<A,E1,D1,M,R>,
		     TensorR<B,E2,D2,M,R>,
		     E1,E2,E3,D1,D2,D3,M,M,M,R,R,R,
		     FUNCTOR_lesseq<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// (2A) Tensor<E(D1)> <= D2

template <class A, class D2, class E, class D1, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>> 
auto operator<=(const TensorR<A,E,D1,M,R>& x1, const D2& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<TensorR<A,E,D1,M,R>,
		     D2,
		     E,Null,E3,D1,D2,D3,M,0,M,R,R,R,
		     FUNCTOR_lesseq<E,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// (2B) D1 <= Tensor<E(D2)>

template <class D1, class B, class E, class D2, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>> 
auto operator<=(const D1& x1, const TensorR<B,E,D2,M,R>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     TensorR<B,E,D2,M,R>,
		     Null,E,E3,D1,D2,D3,0,M,M,R,R,R,
		     FUNCTOR_lesseq<Null,E,E3,D1,D2,D3> >(x1,x2); 
}


  
// (3A) element-wise Less than or equal to: x1[i] <= x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<TensorAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator<=(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef E1 E;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;
  //    mout << "A" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_lesseq<E,E,E3,D1,D2,D3> >(x1,x2); 
}


// (3B) element-wise Less than or equal to: x1 <= x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<TensorAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator<=(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename RelType<D1,D2>::Type D3;
  typedef E2 E;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;  
  //    mout << "B" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_lesseq<E,E,E3,D1,D2,D3> >(x1,x2); 
}

    
// (4A) Tensor<D1,R,M> <= Tensor<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Less than or equal to
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<TensorAbstract,E1>::value)> = 0  >
auto operator<=(const TensorR<A,E1,D1,M1,R>& x1, const TensorR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef TensorR<B,D2,D2,M2,R> E2;  

  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    mout << "C" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R>,
		     TensorR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_lesseq<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// (4B) Tensor<D1,R,1> <= Tensor<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Less than or equal to
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<TensorAbstract,E2>::value)> = 0  >
auto operator<=(const TensorR<A,D1,D1,M1,R>& x1, const TensorR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef TensorR<A,D1,D1,M1,R> E1;  
  typedef typename RelType<D1,D2>::Type D3;
  typedef typename NumberType<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    mout << "D" <<std::endl;
  return  TER_Binary<TensorR<A,D1,D1,M1,R>,
		     TensorR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_lesseq<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}





// ----------------------------------------------------------------
// And
// template function classes for operator '&&'
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// And (&&)
//----------------------------------------------

// (1) Tensor<E1(D1)> && Tensor<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
auto operator&&(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2) {
  typedef typename AndType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<TensorR<A,E1,D1,M,R>,
		     TensorR<B,E2,D2,M,R>,
		     E1,E2,E3,D1,D2,D3,M,M,M,R,R,R,
		     FUNCTOR_and<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// (2A) Tensor<E(D1)> && D2

template <class A, class D2, class E, class D1, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>> 
auto operator&&(const TensorR<A,E,D1,M,R>& x1, const D2& x2) {
  typedef typename AndType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<TensorR<A,E,D1,M,R>,
		     D2,
		     E,Null,E3,D1,D2,D3,M,0,M,R,R,R,
		     FUNCTOR_and<E,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// (2B) D1 && Tensor<E(D2)>

template <class D1, class B, class E, class D2, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>> 
auto operator&&(const D1& x1, const TensorR<B,E,D2,M,R>& x2) {
  typedef typename AndType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     TensorR<B,E,D2,M,R>,
		     Null,E,E3,D1,D2,D3,0,M,M,R,R,R,
		     FUNCTOR_and<Null,E,E3,D1,D2,D3> >(x1,x2); 
}


  
// (3A) element-wise And: x1[i] && x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<TensorAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator&&(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename AndType<D1,D2>::Type D3;
  typedef E1 E;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;
  //    mout << "A" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_and<E,E,E3,D1,D2,D3> >(x1,x2); 
}


// (3B) element-wise And: x1 && x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<TensorAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator&&(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename AndType<D1,D2>::Type D3;
  typedef E2 E;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;  
  //    mout << "B" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_and<E,E,E3,D1,D2,D3> >(x1,x2); 
}

    
// (4A) Tensor<D1,R,M> && Tensor<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise And
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<TensorAbstract,E1>::value)> = 0  >
auto operator&&(const TensorR<A,E1,D1,M1,R>& x1, const TensorR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef TensorR<B,D2,D2,M2,R> E2;  

  typedef typename AndType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    mout << "C" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R>,
		     TensorR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_and<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// (4B) Tensor<D1,R,1> && Tensor<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise And
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<TensorAbstract,E2>::value)> = 0  >
auto operator&&(const TensorR<A,D1,D1,M1,R>& x1, const TensorR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef TensorR<A,D1,D1,M1,R> E1;  
  typedef typename AndType<D1,D2>::Type D3;
  typedef typename NumberType<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    mout << "D" <<std::endl;
  return  TER_Binary<TensorR<A,D1,D1,M1,R>,
		     TensorR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_and<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}





// ----------------------------------------------------------------
// Or
// template function classes for operator '||'
//
//    Note: generated from template file 'fun_binary_op_functor.hpp'
//          using Python script 'fun_binary.py'
// ----------------------------------------------------------------

//----------------------------------------------
// Or (||)
//----------------------------------------------

// (1) Tensor<E1(D1)> || Tensor<E2(D2)>

// TODO: realtime check that deep dimensions of E1 and E2 are the same

template <class A, class B, class E1, class E2, class D1, class D2, int M, int R> 
auto operator||(const TensorR<A,E1,D1,M,R>& x1, const TensorR<B,E2,D2,M,R>& x2) {
  typedef typename OrType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  return  TER_Binary<TensorR<A,E1,D1,M,R>,
		     TensorR<B,E2,D2,M,R>,
		     E1,E2,E3,D1,D2,D3,M,M,M,R,R,R,
		     FUNCTOR_or<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}


  

// (2A) Tensor<E(D1)> || D2

template <class A, class D2, class E, class D1, int M, int R, typename = std::enable_if_t<NumberType<D2>::value>> 
auto operator||(const TensorR<A,E,D1,M,R>& x1, const D2& x2) {
  typedef typename OrType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<TensorR<A,E,D1,M,R>,
		     D2,
		     E,Null,E3,D1,D2,D3,M,0,M,R,R,R,
		     FUNCTOR_or<E,Null,E3,D1,D2,D3> >(x1,x2); 
}


  
// (2B) D1 || Tensor<E(D2)>

template <class D1, class B, class E, class D2, int M, int R, typename = std::enable_if_t<NumberType<D1>::value>> 
auto operator||(const D1& x1, const TensorR<B,E,D2,M,R>& x2) {
  typedef typename OrType<D1,D2>::Type D3;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;   
  return  TER_Binary<D1,
		     TensorR<B,E,D2,M,R>,
		     Null,E,E3,D1,D2,D3,0,M,M,R,R,R,
		     FUNCTOR_or<Null,E,E3,D1,D2,D3> >(x1,x2); 
}


  
// (3A) element-wise Or: x1[i] || x2

// TODO: run-time check (deep dimensions of E1 == deepdimensions of x2)
  
  
template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1==M2+1)&&(std::is_base_of<TensorAbstract,E1>::value)&&(E1::Rvalue==R2)> = 0 >
auto operator||(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename OrType<D1,D2>::Type D3;
  typedef E1 E;   // see TODO note above
  constexpr int R3 = R1;
  constexpr int M3 = M1;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;
  //    mout << "A" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_or<E,E,E3,D1,D2,D3> >(x1,x2); 
}


// (3B) element-wise Or: x1 || x2[i]

// TODO: run-time check (deep dimensions of x1 == deepdimensions of E2)

template <class A, class B, class E1, class E2, class D1, class D2, int M1, int M2, int R1, int R2,
	  EnableIf<(M1+1==M2)&&(std::is_base_of<TensorAbstract,E2>::value)&&(E2::Rvalue==R1)> = 0 >
auto operator||(const TensorR<A,E1,D1,M1,R1>& x1, const TensorR<B,E2,D2,M2,R2>& x2) {
  typedef typename OrType<D1,D2>::Type D3;
  typedef E2 E;   // see TODO note above
  constexpr int R3 = R2;
  constexpr int M3 = M2;
  typedef typename NumberType<E,D3>::ReplaceTypeE E3;  
  //    mout << "B" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R1>,
		     TensorR<B,E2,D2,M2,R2>,
		     E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,
		     FUNCTOR_or<E,E,E3,D1,D2,D3> >(x1,x2); 
}

    
// (4A) Tensor<D1,R,M> || Tensor<D2,R,1>

// Depending on rank and dimensions, this may be top-level or element wise Or
// Note: M2==1 -> E2==D2

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of E1  equal dimensions of x2
  
template <class A, class B, class E1, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1>=2)&&(M2==1)&&(std::is_base_of<TensorAbstract,E1>::value)> = 0  >
auto operator||(const TensorR<A,E1,D1,M1,R>& x1, const TensorR<B,D2,D2,M2,R>& x2) {

  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename B::XType E2;  
  //    typedef B E2;  
  typedef TensorR<B,D2,D2,M2,R> E2;  

  typedef typename OrType<D1,D2>::Type D3;
  typedef typename NumberType<E1,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M1;
  //    mout << "C" <<std::endl;
  return  TER_Binary<TensorR<A,E1,D1,M1,R>,
		     TensorR<B,D2,D2,M2,R>,
		     E1,D2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_or<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}

// (4B) Tensor<D1,R,1> || Tensor<D2,R,M>

// Depending on rank and dimensions, this may be top-level or element wise Or
// Note: M1==1 -> E1==D1

// TODO: if top-level: run-timecheck dimesions of x1  equal dimensions of x2
// TODO: if element-wise: run-timecheck dimesions of x1  equal dimensions of E2

template <class A, class B, class E2, class D1, class D2, int M1, int M2, int R,
	  EnableIf<(M1==1)&&(M2>=2)&&(std::is_base_of<TensorAbstract,E2>::value)> = 0  >
auto operator||(const TensorR<A,D1,D1,M1,R>& x1, const TensorR<B,E2,D2,M2,R>& x2) {
  // NOT SURE WHICH OF THE THREE IS BEST
  //    typedef typename A::XType E1;  
  //    typedef A E1;  
  typedef TensorR<A,D1,D1,M1,R> E1;  
  typedef typename OrType<D1,D2>::Type D3;
  typedef typename NumberType<E2,D3>::ReplaceTypeE E3;   // see TODO note above
  constexpr int M3 = M2;
  //    mout << "D" <<std::endl;
  return  TER_Binary<TensorR<A,D1,D1,M1,R>,
		     TensorR<B,E2,D2,M2,R>,
		     D1,E2,E3,D1,D2,D3,M1,M2,M3,R,R,R,
		     FUNCTOR_or<E1,E2,E3,D1,D2,D3> >(x1,x2); 
}



}; // namespace mathq 
#endif // MATHQ__FUN_BINARY_AUTO_H