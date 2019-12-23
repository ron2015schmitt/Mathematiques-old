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
}; // namespace mathq 
#endif // MATHQ__FUN_UNARY_AUTO_H