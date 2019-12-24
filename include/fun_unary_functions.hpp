

// ----------------------------------------------------------------
// ##COMMENTNAME##
// template functions for '##NAME##'
//
//    Note: generated from template file '##MYFILENAME##'
//          using Python script '##SCRIPTNAME##'
// ----------------------------------------------------------------

//----------------------------------------------
// ##COMMENTNAME## 
//----------------------------------------------

template <class X, class E, class D, int M, int R>			
inline auto ##FUNCTION##(const TensorR<X,E,##DIN##,M,R>& x) {		
  typedef typename NumberType<E,##DOUT##>::ReplaceTypeE EOUT;		
  return  TER_Unary<TensorR<X,E,##DIN##,M,R>,EOUT,##DOUT##,M,R, ##FUNCTOR##<E,EOUT,##DIN##,##DOUT##>>(x); 
}