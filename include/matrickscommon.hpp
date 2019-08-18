#ifndef MATRICKSCOMMON_H
#define MATRICKSCOMMON_H

#include <typeinfo>
#include <sstream>
#include <complex>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <tgmath.h>
//#include <cfloat>
//#include <cmath>
#include <limits>
#include <valarray>




namespace matricks {


  typedef std::vector<double>::size_type   size_type;
  typedef unsigned int   uint;


  
  

  inline std::istream& restore_stream(std::istream& tostream, std::istream& fromstream) {
    std::string s="";
    char c;
    while(fromstream.get(c)) 
      s += c;

    size_t len = s.length();
    if (len >0) {
      if (tostream.eof())
	tostream.clear();
      std::ostringstream tempstrm;
      tempstrm<<std::endl;
      tostream.putback(tempstrm.str()[0]);
      for (size_t i = len;i>0; i--) 
	tostream.putback(s[i-1]);
    }
    return tostream;
  }



  /****************************************************************************
   * Some typedefs and constants
   ****************************************************************************   
   */
  typedef long double extended;
  // maximum subcript size for vectors and matrices
  const size_type maxsize = std::numeric_limits<int>::max();
  //  const size_type maxsize = std::numeric_limits<uint>::max() -1;
  const size_type badsize = std::numeric_limits<uint>::max();


  enum TextFormat {text_braces,text_nobraces};

  void cant_open_file(const std::string& name);


  /****************************************************************************
   * Rounding
   ****************************************************************************   
   */

  // complex rounding
 template <typename D> std::complex<D> round(const std::complex<D>& x) {
   return std::complex<D>(round(x.real()), round(x.imag()));
 }
  

  /****************************************************************************
   * sgn(x) function
   ****************************************************************************   
   */
#define SGN_MACRO(D)  inline D sgn(const D x) {if (x>0) return static_cast<D>(1); else if (x<0) return static_cast<D>(-1); else return static_cast<D>(0);}
#define SGN_MACRO_US(D)  inline D sgn(const D x) {if (x>0) return static_cast<D>(1);else return static_cast<D>(0);}

  SGN_MACRO(float);
  SGN_MACRO(double);
  SGN_MACRO(long double);
  SGN_MACRO(char);
  SGN_MACRO_US(unsigned char);
  SGN_MACRO(short);
  SGN_MACRO_US(unsigned short);
  SGN_MACRO(int);
  SGN_MACRO_US(unsigned int);
  SGN_MACRO(long);
  SGN_MACRO_US(unsigned long);
#if LONGLONG_EXISTS
  SGN_MACRO(long long);
  SGN_MACRO_US(unsigned long long);
#endif


  /****************************************************************************
   * miscellaneous functions
   ****************************************************************************   
   */
  template <class I>
  inline const std::string uint2string(I i) {
    char buffer[10];
    char* ptr = &buffer[9];
    *ptr=0;
    do {
      unsigned lsd = i % 10;      
      i /= 10;                     
      *(--ptr)='0'+static_cast<char>(lsd);                          // Move back
    } while(i != 0);
    return std::string(ptr);
  } 

  inline int gcd(int a, int b) {
    int r;
    do {
      r = a % b;
      a = b;
      b = r;
    } while (r != 0);
    
    return a;
  }

  /****************************************************************************
   * error reporting string definitions
   ****************************************************************************   
   */



  extern const char* error_str;
  extern const char* warn_str;
  extern const char* indent_str;
  extern const char* where_str;
  extern const char* bug_str;


  void bug_report(const std::string& fname,const size_type linenum);


  /****************************************************************************
   * execution mode string and display
   ****************************************************************************   
   */

#ifdef MATRICKS_DEBUG
  inline std::string execution_mode(void) {
    return "DEBUG";
  }
#else
  inline std::string execution_mode(void) {
    return "fast";
  }
#endif

  inline void display_execution_mode(void) {
    std::cout << "matricks execution mode = "<< execution_mode() << std::endl;
  }






  /****************************************************************************
   * sequence class -- for accessing subsets of vectors/matrices (like "slice")
   ****************************************************************************
   */
  class seq {
  private:
    const size_type start_;
    const size_type end_;
    const int step_; 
  public:
    seq(const size_type start, const size_type end, const int step) :
      start_(start), end_(end), 
      step_(step) {
    }
    seq(const size_type start, const size_type end) :
      start_(start), end_(end), 
      step_((end >= start)?1:-1) {
    }
    
    size_type start(void) const{ return start_;}
    size_type end(void) const{ return end_;}
    int step(void) const{ return step_;}

    // could improve speed for step=1 and step=-1 by creating a separate
    // function or template class that doesn't include the step multiply
    inline size_type operator[](const size_type i) const {
      return static_cast<uint>(start_ + i * step_);      
    }

    inline size_type size(void) const {
      // issue warning if step ==0 (size is infinite)
      if ( (step_>=0) && ( end_>=start_ ) )
	return (end_-start_)/static_cast<uint>(step_) + 1;
      else if ( (step_<0) && (end_<start_ ) )
	return (start_-end_)/static_cast<uint>(-step_) + 1;
      else
	return 1;
    }

    void outputglossary(void) const {
#ifdef MATRICKS_DEBUG
      std::cout << where_str<< debugtxt() <<" has size=" <<size()<<std::endl;
#endif
    }

    std::string debugtxt(void) const {
      std::ostringstream stream;
      stream <<  "seq(start=" << start_ << ", end=" << end_ << ", step=" << step_ << ")";
      return stream.str();
    }


    friend std::ostream& operator<<(std::ostream &stream, const seq& i) {
      stream << i.debugtxt();
      return stream;
    }
    
  };



  /****************************************************************************
   * Enumeration for different subclasses of VorE class
   ****************************************************************************   
   */
  enum VETypes {VE_Vector, VE_VScalObj, VE_VSliceObj, VE_VSubsetObj, VE_VSubMaskObj,
		VE_VReconObj, VE_VConcatOp, 
		VE_VBinOp, VE_VecOpScal, VE_ScalOpVec, VE_VFuncOp,
		VE_VBoolBinOp, VE_BoolVecOpScal, VE_BoolScalOpVec, VE_VBoolFuncOp,
		 VE_CVecOpScal, VE_CScalOpVec,VE_VRealFromComplex, VE_p3vector};



  /****************************************************************************
   * VorE -- Abstract class that represents either a vector or a vector expression
   ****************************************************************************   
   */

  template <class D, class VE> class VorE {
  public:
    inline VE& derived() {
      return static_cast<VE&>(*this);
    }
    inline const  VE& derived() const {
      return static_cast<const VE&>(*this);
    }

    typedef  D DataT;

    inline const D operator[](const size_type i) const {
      return derived()[i];
    }

    inline size_type size(void) const {
      return derived().size();
    }

    std::string debugtxt(void) const {
      return derived().debugtxt();
    }

    void outputglossary(void) const {
       derived().outputglossary();
    }

    inline VETypes vetype(void) const {
      return derived().vetype();
    }

    bool mustcopy(const void* vaddr) const {
      return derived().mustcopy(vaddr);
    }

    bool addrmatch(const void *vaddr) const {
      return derived().addrmatch(vaddr);
    }



  };




  /****************************************************************************
   * Some Classes that inherit from VorE
   ****************************************************************************   
   */

  template <class D> class Vector;
  template <class D> class p3vector;
  template <class D, class A> class Vexpr;  
  template <class D, class A> class VWrapperObj;
  template <class D> class VSliceObj;
  template <class D> class VSubsetObj;
  template <class D> class VSubMaskObj;
  template <class D> class VReconObj;


  /****************************************************************************
   * Matrix Enumerations
   ****************************************************************************   
   */


  enum METypes {ME_Matrix, ME_MSubmatObj,
		ME_MRangeObj, ME_MSetObj, ME_MDualSetObj, ME_MDualRangeObj,
		ME_MSetRangeObj, ME_MRangeSetObj,
		ME_MReconObj, ME_MBinOp, ME_MDotOp,
		ME_MatOpScal, ME_ScalOpMat, 
		ME_MFuncOp, ME_MFuncVec, ME_MFuncReshape,
		ME_MBoolBinOp, ME_BoolMatOpScal, ME_BoolScalOpMat, ME_MBoolFuncOp,
		ME_CMatOpScal, ME_CScalOpMat, ME_MAdjOp};

  enum MTypes {M_Matrix}; 




  /****************************************************************************
   * MorE -- Abstract class that represents either a matrix or a matrix expression
   ****************************************************************************   
   */

  template <class D, class ME> class MorE {
  public:
    inline ME& derived() {
      return static_cast<ME&>(*this);
    }
    inline const  ME& derived() const {
      return static_cast<const ME&>(*this);
    }


    inline const D operator()(const size_type i) const {
      return derived()(i);
    }

    inline const D operator()(const size_type r, const size_type c) const {
      return derived()(r,c);
    }


    inline size_type size(void) const {
      return derived().size();
    }

    inline size_type Nrows(void) const {
      return derived().Nrows();
    }

    inline size_type Ncols(void) const {
      return derived().Ncols();
    }

    std::string debugtxt(void) const {
      return derived().debugtxt();
    }

    void outputglossary(void) const {
       derived().outputglossary();
    }

    inline METypes metype(void) const {
      return derived().metype();
    }

    bool mustcopy(const void* maddr) const {
      return derived().mustcopy(maddr);
    }

    bool addrmatch(const void *maddr) const {
      return derived().addrmatch(maddr);
    }



  };



  /****************************************************************************
   * Some Classes that inherit from MorE
   ****************************************************************************   
   */

  template <class D> class Matrix;
  template <class D, class A> class Mexpr;  
  template <class D, class A> class MWrapperObj;
  template <class D> class MSubmatObj;
  template <class D> class MRangeObj;
  template <class D> class MSetObj;
  template <class D> class MDualSetObj;
  template <class D> class MDualRangeObj;
  template <class D> class MSetRangeObj;
  template <class D> class MRangeSetObj;
  template <class D> class MReconObj;


  template <class A> 
  Vector<uint> sub2ind(const MorE<size_type,A>& subs, const size_type NR, const size_type NC);



  /****************************************************************************
   * Class type querying/manipulation
   ****************************************************************************   
   */
  template <typename T> class RealVersionOfType {
  public:
    typedef T Type;
  };
  template <typename D> class RealVersionOfType<std::complex<D> > {
  public:
    typedef D Type;
  };
  template <typename D> class RealVersionOfType<Vector<D> > {
  public:
    typedef Vector<typename RealVersionOfType<D>::Type> Type;
  };
  template <typename D> class RealVersionOfType<Matrix<D> > {
  public:
    typedef Matrix<typename RealVersionOfType<D>::Type> Type;
  };




  /****************************************************************************
   * vector/matrix error reporting directory
   ****************************************************************************   
   */


  class matricksObjectPool {
  private:
    static size_type NextVectorID_ ;
    static std::map<size_type,std::string> vectorName_ ; 
    static std::map<size_type,std::string> vectorClass_ ; 
    static std::map<size_type,std::string> vectorDatatype_ ; 
    static std::map<size_type,size_type> vectorSize_ ; 

    static size_type NextMatrixID_ ;
    static std::map<size_type,std::string> matrixName_ ; 
    static std::map<size_type,std::string> matrixClass_ ; 
    static std::map<size_type,std::string> matrixDatatype_ ; 
    static std::map<size_type,size_type> matrixNrows_ ; 
    static std::map<size_type,size_type> matrixNcols_ ; 

  public:
    inline static size_t NumVectors(void) { 
      return vectorName_.size();
    }

    static size_type addvector(const std::string name, const std::string classname, 
			 const std::string datatype, const  size_type size, const bool checkname=true);

    static void removevector(const size_type id);

    static std::string vectorname(const size_type id);

    static std::string vadd_name(const std::string& name, const size_type id, const bool checkname=true);

    static void vchange_name(const size_type id, const std::string& name, const bool checkname=true);
    static void vchange_size(const size_type id, const size_type size);

    static void voutputglossary(const size_type id);



    inline static size_t NumMatrices(void) { 
      return matrixName_.size();
    }

    static size_type addmatrix(const std::string name, const std::string classname, 
			 const std::string datatype, const size_type NR, const size_type NC, const bool checkname=true);
  
    static void removematrix(const size_type id);

    static std::string matrixname(const size_type id);
    static size_type matrixNrows(const size_type id);
    static size_type matrixNcols(const size_type id);


    static std::string madd_name(const std::string name, const size_type id, const bool checkname=true);
    static void mchange_name(const size_type id, const std::string& name, const bool checkname=true);
    static void mchange_size(const size_type id, const size_type NR,  const size_type NC);

    static void moutputglossary(const size_type id);


  };





  /****************************************************************************
   * type string creation
   ****************************************************************************   
   */

  
  template <typename T>
  std::string make_type_string(T) {
    std::ostringstream stream;
    stream << typeid(T).name();
    return stream.str();
  }


#define MTS_MACRO_DECL(T)  std::string make_type_string(T);

  MTS_MACRO_DECL(void);
  MTS_MACRO_DECL(float);
  MTS_MACRO_DECL(double);
  MTS_MACRO_DECL(long double);

  MTS_MACRO_DECL(bool);
  MTS_MACRO_DECL(char);
  MTS_MACRO_DECL(unsigned char);
  MTS_MACRO_DECL(signed char);

  MTS_MACRO_DECL(short);
  MTS_MACRO_DECL(unsigned short);
  MTS_MACRO_DECL(int);
  MTS_MACRO_DECL(size_type);
  MTS_MACRO_DECL(long);
  MTS_MACRO_DECL(unsigned long);
#if LONGLONG_EXISTS
  MTS_MACRO_DECL(long long);
  MTS_MACRO_DECL(unsigned long long);
#endif

  MTS_MACRO_DECL(std::string);



#define MTS_CONTAINER_MACRO(T) template <typename D>  std::string make_type_string(const T<D>& x) {return (std::string(# T) + "<" +  make_type_string(D()) +"> "); }


  MTS_CONTAINER_MACRO(std::complex);
  MTS_CONTAINER_MACRO(std::vector);
  MTS_CONTAINER_MACRO(std::valarray);
  
  MTS_CONTAINER_MACRO(Vector);
  MTS_CONTAINER_MACRO(Matrix);
  MTS_CONTAINER_MACRO(p3vector);

  // the following are instantiated to reduce compile time

#define  MTS_MACRO_DECL2(T)  std::string make_type_string(const T&);

  MTS_MACRO_DECL2(std::complex<float>);
  MTS_MACRO_DECL2(std::complex<double>);
  MTS_MACRO_DECL2(std::complex<long double>);
  MTS_MACRO_DECL2(Vector<float>);
  MTS_MACRO_DECL2(Vector<double>);
  MTS_MACRO_DECL2(Vector<long double>);
  MTS_MACRO_DECL2(Vector<std::complex<double> >);
  MTS_MACRO_DECL2(Vector<Vector<double> >);
  MTS_MACRO_DECL2(Vector<Vector<std::complex<double> > >);
  MTS_MACRO_DECL2(Matrix<float>);
  MTS_MACRO_DECL2(Matrix<double>);
  MTS_MACRO_DECL2(Matrix<long double>);
  MTS_MACRO_DECL2(Matrix<std::complex<double> >);
  MTS_MACRO_DECL2(p3vector<float>);
  MTS_MACRO_DECL2(p3vector<double>);
  MTS_MACRO_DECL2(p3vector<long double>);
  MTS_MACRO_DECL2(p3vector<std::complex<double> >);

  /*
  MTS_MACRO_DECL2(Vector<double>);
  MTS_MACRO_DECL2(std::complex<double>);
  */

  /* template <typename D, template <typename> class T>  std::string make_type_string(const T<D>& x) {
    return (x.classname() + "<" +  make_type_string(D()) +"> "); 
  }
  */


};
#endif
