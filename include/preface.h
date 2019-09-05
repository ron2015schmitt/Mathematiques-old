#ifndef MATRICKS__PREFACE_H
#define MATRICKS__PREFACE_H


#define CPP11 (__cplusplus >= 201100L)
#define CPP14 (__cplusplus >= 201400L)
#define CPP17 (__cplusplus >= 201700L)

#define _stringify(...) #__VA_ARGS__
#define stringify(...) _stringify(__VA_ARGS__)


#if CPP11 == 1
#define CARRAY(...) __VA_ARGS__
#else
#define CARRAY(...)  (const double[]) __VA_ARGS__
#endif


#define DO_EXPAND(VAL)  99##VAL
#define EXPAND(VAL)     DO_EXPAND(VAL)


#ifdef MEBUG
 #if (EXPAND(MEBUG) == 99)
  // defined but no value: set to 1
  #define MATRICKS_DEBUG 1
 #else
  #define MATRICKS_DEBUG EXPAND(MEBUG)
 #endif
#endif


#ifndef MATRICKS_DEBUG
// not defined: set to 0
   #define MATRICKS_DEBUG 0
#elif (EXPAND(MATRICKS_DEBUG) == 99)
  // defined but no value: set to 1
  #undef MATRICKS_DEBUG
  #define MATRICKS_DEBUG 1
#elif (MATRICKS_DEBUG>3)
  // no modes defined above 3
  #undef MATRICKS_DEBUG
  #define MATRICKS_DEBUG 3
#endif


// this is created by the makefile and placed in '[exec]_opt.cpp' for
// any executable the is compiled
// it contains the $(OPTIMIZE) flag with all the compile optimization options
extern char COMPILE_OPTIMIZE[];


namespace matricks {


  typedef std::vector<double>::size_type   size_type;
  typedef int index_type;

  typedef long double extended;

  // maximum subcript size for vectors and matrices (since we allow negative indexing)
  const size_type maxsize = std::numeric_limits<index_type>::max();
  const size_type badsize = std::numeric_limits<size_type>::max();



  template <class D> class Vector;
  template <class D> class p3vector;
  template <class D, class A> class Vexpr;  
  template <class D, class A> class VWrapper;
  template <class D, class A> class VRepExpr;
  template <class D> class VSliceObj;
  template <class D> class VSliceExpr;
  template <class D> class VSubsetObj;
  template <class D> class VSubMaskObj;
  template <class D, class A, class B> class VJoinObj;
  template <class D, class A, class B> class VJoinExpr;
  template <class D> class VReconObj;
  template <class D, class A, class X> class VSeriesOp;


  template <class D> class Matrix;
  
};


#endif
