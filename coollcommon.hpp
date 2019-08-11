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



#ifndef COOLLCOMMON_H
#define COOLLCOMMON_H 1

#include <typeinfo>
#include <sstream>
#include <complex>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
//#include <cfloat>
#include <limits>
#include <valarray>





namespace COOLL {



  inline std::istream& restore_stream(std::istream& tostream, std::istream& fromstream) {
    std::string s="";
    char c;
    while(fromstream.get(c)) 
      s += c;

    unsigned int len = s.length();
    if (len >0) {
      if (tostream.eof())
	tostream.clear();
      std::ostringstream tempstrm;
      tempstrm<<std::endl;
      tostream.putback(tempstrm.str()[0]);
      for (unsigned int i = len;i>0; i--) 
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
  const unsigned int maxsize = std::numeric_limits<int>::max();
  //  const unsigned int maxsize = std::numeric_limits<unsigned int>::max() -1;
  const unsigned int badsize = std::numeric_limits<unsigned int>::max();


  enum TextFormat {text_braces,text_nobraces};

  void cant_open_file(const std::string& name);


  /****************************************************************************
   * Rounding
   ****************************************************************************   
   */
#define ROUND_MACRO(D) inline D round(const D x) {return (x > 0.0) ? std::floor(x + 0.5) : std::ceil(x - 0.5);}
#define ROUND_MACRO_INT(D) inline D round(const D x){return x;}
  ROUND_MACRO(float);
  ROUND_MACRO(double);
  ROUND_MACRO(long double);
  ROUND_MACRO_INT(char);
  ROUND_MACRO_INT(unsigned char);
  ROUND_MACRO_INT(short);
  ROUND_MACRO_INT(unsigned short);
  ROUND_MACRO_INT(int);
  ROUND_MACRO_INT(unsigned int);
  ROUND_MACRO_INT(long);
  ROUND_MACRO_INT(unsigned long);
#if LONGLONG_EXISTS
  ROUND_MACRO_INT(long long);
  ROUND_MACRO_INT(unsigned long long);
#endif

 template <typename D> std::complex<D> round(const std::complex<D>& x) {
   return std::complex<D>(COOLL::round(x.real()),COOLL::round(x.imag()));
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


  void bug_report(const std::string& fname,const unsigned int linenum);


  /****************************************************************************
   * execution mode string and display
   ****************************************************************************   
   */

#ifdef COOLL_CAREFUL
  inline std::string execution_mode(void) {
    return "CAREFUL";
  }
#else
  inline std::string execution_mode(void) {
    return "fast";
  }
#endif

  inline void display_execution_mode(void) {
    std::cout << "COOLL execution mode = "<< execution_mode() << std::endl;
  }






  /****************************************************************************
   * sequence class -- for accessing subsets of vectors/matrices (like "slice")
   ****************************************************************************
   */
  class seq {
  private:
    const unsigned int start_;
    const unsigned int end_;
    const int step_; 
  public:
    seq(const unsigned int start, const unsigned int end, const int step) :
      start_(start), end_(end), 
      step_(step) {
    }
    seq(const unsigned int start, const unsigned int end) :
      start_(start), end_(end), 
      step_((end >= start)?1:-1) {
    }
    
    const unsigned int start(void) const{ return start_;}
    const unsigned int end(void) const{ return end_;}
    const  int step(void) const{ return step_;}

    // could improve speed for step=1 and step=-1 by creating a separate
    // function or template class that doesn't include the step multiply
    inline const unsigned int operator[](const unsigned int i) const {
      return static_cast<unsigned int>(start_ + i * step_);      
    }

    inline unsigned int size(void) const {
      // issue warning if step ==0 (size is infinite)
      if ( (step_>=0) && ( end_>=start_ ) )
	return (end_-start_)/static_cast<unsigned int>(step_) + 1;
      else if ( (step_<0) && (end_<start_ ) )
	return (start_-end_)/static_cast<unsigned int>(-step_) + 1;
      else
	return 1;
    }

    void outputglossary(void) const {
#ifdef COOLL_CAREFUL
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
  enum VETypes {VE_LAvector, VE_VScalObj, VE_VRangeObj, VE_VSetObj, VE_VMaskObj,
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

    inline const D operator[](const unsigned int i) const {
      return derived()[i];
    }

    inline unsigned int size(void) const {
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

  template <class D> class LAvector;
  template <class D> class p3vector;
  template <class D, class A> class Vexpr;  
  template <class D, class A> class VWrapperObj;
  template <class D> class VRangeObj;
  template <class D> class VSetObj;
  template <class D> class VMaskObj;
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


    inline const D operator()(const unsigned int i) const {
      return derived()(i);
    }

    inline const D operator()(const unsigned int r, const unsigned int c) const {
      return derived()(r,c);
    }


    inline unsigned int size(void) const {
      return derived().size();
    }

    inline unsigned int Nrows(void) const {
      return derived().Nrows();
    }

    inline unsigned int Ncols(void) const {
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
  LAvector<unsigned int> sub2ind(const MorE<unsigned int,A>& subs, const unsigned int NR, const unsigned int NC);



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
  template <typename D> class RealVersionOfType<LAvector<D> > {
  public:
    typedef LAvector<typename RealVersionOfType<D>::Type> Type;
  };
  template <typename D> class RealVersionOfType<Matrix<D> > {
  public:
    typedef Matrix<typename RealVersionOfType<D>::Type> Type;
  };




  /****************************************************************************
   * vector/matrix error reporting directory
   ****************************************************************************   
   */


  class CoollDirectory {
  private:
    static unsigned int NextVectorID_ ;
    static std::map<unsigned int,std::string> vectorName_ ; 
    static std::map<unsigned int,std::string> vectorClass_ ; 
    static std::map<unsigned int,std::string> vectorDatatype_ ; 
    static std::map<unsigned int,unsigned int> vectorSize_ ; 

    static unsigned int NextMatrixID_ ;
    static std::map<unsigned int,std::string> matrixName_ ; 
    static std::map<unsigned int,std::string> matrixClass_ ; 
    static std::map<unsigned int,std::string> matrixDatatype_ ; 
    static std::map<unsigned int,unsigned int> matrixNrows_ ; 
    static std::map<unsigned int,unsigned int> matrixNcols_ ; 

  public:
    inline static unsigned int NumVectors(void) { 
      return vectorName_.size();
    }

    static unsigned int addvector(const std::string name, const std::string classname, 
			 const std::string datatype, const  unsigned int size, const bool checkname=true);

    static void removevector(const unsigned int id);

    static std::string vectorname(const unsigned int id);

    static std::string vadd_name(const std::string& name, const unsigned int id, const bool checkname=true);

    static void vchange_name(const unsigned int id, const std::string& name, const bool checkname=true);
    static void vchange_size(const unsigned int id, const unsigned  int size);

    static void voutputglossary(const unsigned int id);



    inline static unsigned int NumMatrices(void) { 
      return matrixName_.size();
    }

    static unsigned int addmatrix(const std::string name, const std::string classname, 
			 const std::string datatype, const unsigned  int NR, const unsigned int NC, const bool checkname=true);
  
    static void removematrix(const unsigned int id);

    static std::string matrixname(const unsigned int id);
    static unsigned int CoollDirectory::matrixNrows(const unsigned int id);
    static unsigned int CoollDirectory::matrixNcols(const unsigned int id);


    static std::string madd_name(const std::string name, const unsigned int id, const bool checkname=true);
    static void mchange_name(const unsigned int id, const std::string& name, const bool checkname=true);
    static void mchange_size(const unsigned int id, const unsigned int NR,  const unsigned int NC);

    static void moutputglossary(const unsigned int id);


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
  MTS_MACRO_DECL(unsigned int);
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
  
  MTS_CONTAINER_MACRO(LAvector);
  MTS_CONTAINER_MACRO(Matrix);
  MTS_CONTAINER_MACRO(p3vector);

  // the following are instantiated to reduce compile time

#define  MTS_MACRO_DECL2(T)  std::string make_type_string(const T&);

  MTS_MACRO_DECL2(std::complex<float>);
  MTS_MACRO_DECL2(std::complex<double>);
  MTS_MACRO_DECL2(std::complex<long double>);
  MTS_MACRO_DECL2(LAvector<float>);
  MTS_MACRO_DECL2(LAvector<double>);
  MTS_MACRO_DECL2(LAvector<long double>);
  MTS_MACRO_DECL2(LAvector<std::complex<double> >);
  MTS_MACRO_DECL2(LAvector<LAvector<double> >);
  MTS_MACRO_DECL2(LAvector<LAvector<std::complex<double> > >);
  MTS_MACRO_DECL2(Matrix<float>);
  MTS_MACRO_DECL2(Matrix<double>);
  MTS_MACRO_DECL2(Matrix<long double>);
  MTS_MACRO_DECL2(Matrix<std::complex<double> >);
  MTS_MACRO_DECL2(p3vector<float>);
  MTS_MACRO_DECL2(p3vector<double>);
  MTS_MACRO_DECL2(p3vector<long double>);
  MTS_MACRO_DECL2(p3vector<std::complex<double> >);

  /*
  MTS_MACRO_DECL2(LAvector<double>);
  MTS_MACRO_DECL2(std::complex<double>);
  */

  /* template <typename D, template <typename> class T>  std::string make_type_string(const T<D>& x) {
    return (x.classname() + "<" +  make_type_string(D()) +"> "); 
  }
  */


};
#endif
