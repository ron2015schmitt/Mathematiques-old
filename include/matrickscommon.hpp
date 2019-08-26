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
#include <queue>



namespace style {
  class Terminal {
  private:
    static bool isInitialized;
    static bool supportsColor;
  public:
    static bool getSupportsColor();
    
  };

  const std::string ESC = "\033[";
  const std::string FORE = ESC+"38;";
  const std::string BACK = ESC+"48;";
  
  const std::string RESET   = ESC+"0m";
  const std::string BOLD    = ESC+"1m";
  const std::string DIM     = ESC+"2m"; // not widely supported
  const std::string ITALIC  = ESC+"3m"; // not widely supported
  const std::string UNDERLINE  = ESC+"4m";
  const std::string SLOWBLINK  = ESC+"5m";
  const std::string RAPIDBLINK = ESC+"6m";
  const std::string REVERSED   = ESC+"7m";
  const std::string CROSSEDOUT = ESC+"9m";
  const std::string FONT2      = ESC+"11m"; // not widely supported
  const std::string FRAKTUR    = ESC+"20m"; // not widely supported
  const std::string FRAMED     = ESC+"51m"; // not widely supported
  const std::string ENCIRCLED  = ESC+"52m"; // not widely supported
  const std::string OVERLINE   = ESC+"53m";

  const std::string BLACK   = ESC+"30m";      
  const std::string RED     = ESC+"31m";      
  const std::string GREEN   = ESC+"32m";      
  const std::string GREENBRIGHT   = ESC+"92m";      
  const std::string YELLOW  = ESC+"33m";      
  const std::string YELLOWBRIGHT  = ESC+"93m";      
  const std::string BLUE    = ESC+"34m";      
  const std::string BLUEBRIGHT    = ESC+"94m";      
  const std::string MAGENTA = ESC+"35m";      
  const std::string CYAN    = ESC+"36m";      
  const std::string WHITE   = ESC+"37m";

  const std::string GREENBACK  =  BACK+"5;46m";      
  const std::string YELLOWBACK  = BACK+"5;226m";      
  const std::string ORANGEBACK  = BACK+"5;208m";      
  const std::string ORANGE  = FORE+"5;208m";      
  const std::string GRAY1  = FORE+"5;240m";      

  const std::string BLUE1  = FORE+"5;18m";      
  const std::string BLUE2  = FORE+"5;21m";      
  const std::string BLUE3  = FORE+"5;27m";      

  const std::string MAGENTA1  = FORE+"5;129m";      


  class Style {
  private:
    std::string stylestr_;
    std::string stylename_;
  public:
    inline Style() {
      stylestr_ = "";
    }
    inline Style(const std::string stylestr) {
      stylestr_ = stylestr;
    }
    inline Style(const std::string stylestr, const std::string name) {
      stylestr_ = stylestr;
      stylename_ = name;
    }
    inline std::string apply(const std::string s) const {
      if (Terminal::getSupportsColor()) {
	return stylestr_ + s +RESET;
      } else {
	return s;
      }
    }
    inline Style& setStyle(const std::string stylestr) {
      stylestr_ = stylestr;
      return *this;
    }
    inline std::string getStyle() const {
      return stylestr_;
    }

    inline Style& setName(const std::string name) {
      stylename_ = name;
      return *this;
    }
    inline std::string getName() const {
      return stylename_;
    }

    inline Style& operator+(const Style& style2) const {
      Style* style3 = new Style(this->getStyle() + style2.getStyle(), this->getName() + "+"+style2.getName() );
      return *style3;
    }
    
    inline friend std::ostream& operator<<(std::ostream &stream, const Style& style) {
      std::string s = style.getName();
      if (s.empty()) {
	s = "style";
      }
      stream << style.apply(s);
      return stream;
    }

  };


  class StyledString {
  private:
    Style style_;
    std::string text_;
  public:
    inline StyledString(const Style style, const std::string text) {
      style_ = style;
      text_ = text;
    }
    inline std::string get() const {
      return style_.apply(text_);
    }
    inline std::string getStr() const {
      return text_;
    }
    inline StyledString& setStyle(const Style style) {
      style_ = style;
      return *this;
    }
    inline Style& getStyle()  {
      return style_;
    }
    inline friend std::ostream& operator<<(std::ostream &stream, const StyledString& ss) {
      stream << ss.get();
      return stream;
    }
      
  };



  template <typename D>
  class Format {
  public:
    typedef D MYTYPE;
    inline Format() {
    }

    inline std::string apply(const MYTYPE var) const {
      std::ostringstream stream;
      stream << var;
      return stream.str();
    }
    inline std::string getName() const {
      std::ostringstream stream;
      stream << typeid(MYTYPE).name();
      return stream.str();
    }
  };


  // TODO add style for both name and value
  template <>
  class Format<double> {
  private:
    static char buffer_[2048];
    std::string formatstr_ = "%f";
  public:
    typedef double MYTYPE;
    inline Format() {
      printf("Format::Format \n");
    }
    inline Format(const std::string formatstr) {
      printf("Format::Format(const std::string formatstr) \n");
      setFormatStr(formatstr);
    }

    inline Format& setFormatStr(const std::string formatstr) {
      // TODO: test with try and catch
      formatstr_ = formatstr;
      return *this;
    }
    inline std::string getFormatStr() const {
      return formatstr_;
    }
    inline std::string apply(const MYTYPE var) const {
      const char *fstr = formatstr_.c_str();
      std::sprintf(Format<double>::buffer_,fstr,var);
      return std::string(Format<double>::buffer_);
    }
    inline std::string getName() const {
      return "double";
    }
    inline friend std::ostream& operator<<(std::ostream &stream, const Format<double>& format) {
      stream << "Format<"<<format.getName()<< "> = " << format.getFormatStr();
      return stream;
    }
  };




  
  
};


namespace matricks {


  typedef std::vector<double>::size_type   size_type;
  typedef unsigned int   uint;
  typedef int index_type;
  typedef long double extended;
  // maximum subcript size for vectors and matrices (since we allow negative indexing)
  const size_type maxsize = std::numeric_limits<index_type>::max();
  //  const size_type maxsize = std::numeric_limits<uint>::max() -1;
  const size_type badsize = std::numeric_limits<size_type>::max();


    /****************************************************************************
   * execution mode string and display
   ****************************************************************************   
   */

#if (MATRICKS_DEBUG==0)
  inline std::string execution_mode(void) {
    return "normal (fast)";
  }
  inline std::string execution_color(void) {
    return style::GREENBACK + style::BOLD;
  }
#elif (MATRICKS_DEBUG==1)
  inline std::string execution_mode(void) {
    return "DEBUG Level 1";
  }
  inline std::string execution_color(void) {
    return style::YELLOWBACK+ style::BOLD;
  }
#elif (MATRICKS_DEBUG==2)
  inline std::string execution_mode(void) {
    return "DEBUG Level 2";
  }
  inline std::string execution_color(void) {
    return style::ORANGEBACK+ style::BOLD;
  }
#endif

  inline void display_execution_mode(void) {
    using namespace std;
    using namespace style;
    string s = "";
    if (Terminal::getSupportsColor()) {
      s = s+ BLUE2+BOLD+"mātricks "+vers_matricks+": "+RESET
	+ " execution mode = "
	+ execution_color() + execution_mode() + RESET;
    } else {
      s =s+ "mātricks "+vers_matricks+": "+" execution mode = " + execution_mode();
    }
    cout <<  s << endl;
  }

  extern const char* error_str;
  extern const char* warn_str;
  extern const char* indent_str;
  extern const char* where_str;
  extern const char* bug_str;

  class Strings {
  public:
    static std::string error;
    static std::string warn;
    Strings();
  };


    /****************************************************************************
   * Classes that inherit from VorE
   ****************************************************************************   
   */

  template <class D> class Vector;
  template <class D> class p3vector;
  template <class D, class A> class Vexpr;  
  template <class D, class A> class VWrapperObj;
  template <class D, class A> class VRepExpr;
  template <class D> class VSliceObj;
  template <class D> class VSliceExpr;
  template <class D> class VSubsetObj;
  template <class D> class VSubMaskObj;
  template <class D, class A, class B> class VJoinObj;
  template <class D, class A, class B> class VJoinExpr;
  template <class D> class VReconObj;


  class slc {
  private:
    const index_type start_;
    const index_type end_;
    const index_type step_; 
  public:
    slc(const index_type start, const index_type end, const index_type step);
    slc(const index_type start, const index_type end);
    
    index_type start(void) const;
    index_type end(void) const; 
    index_type step(void) const;

    Vector<index_type>& toIndexVector(const size_type N) const;
    void outputglossary(void) const;
    std::string debugtxt(void) const;    
    friend std::ostream& operator<<(std::ostream &stream, const slc& i) {
      stream << i.debugtxt();
      return stream;
    }
  };

  
  template <typename T>
  std::vector<T> mergeVectors(const std::vector<T> v1, const std::vector<T> v2) {
    std::vector<T> v3 = v1;
    v3.insert( v3.end(), v2.begin(), v2.end() );
    return v3;
  }

  template <typename T>
  std::vector<T> createVector(const T x) {
    std::vector<T> v1;
    v1.push_back(x);
    return v1;
  }


  class VectorofPtrs {

  public:
    std::vector<const void*> myaddrs;


    VectorofPtrs() {
    }
    VectorofPtrs(const void* addr) {
      addAddress(addr);
    }
    VectorofPtrs(const std::vector<const void*> addrs) {
      addAddresses(addrs);
    }
    
    
    std::vector<const void*> getAddresses(void) const {
      std::vector<const void*> vec;
      for (std::vector<const void*>::const_iterator  it = myaddrs.begin() ; it != myaddrs.end(); ++it) {
	vec.push_back(*it);
      }
      return vec;
    }

    bool checkAddresses(const std::vector<const void*> addrs) const {
      for (size_type i = 0; i < addrs.size(); i++){
	const void* addr = addrs[i];
	if ( std::find(myaddrs.begin(), myaddrs.end(), addr) != myaddrs.end() ) {
	  return true;
	}
      }
      return false;
    }

    void addAddress(const void* addr) {
      myaddrs.push_back(addr);
    }

    void addAddresses(const std::vector<const void*> addrs) {
      myaddrs.insert(myaddrs.end(), addrs.begin(), addrs.end());
    }
    
  };

    
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


  enum TextFormat {text_braces,text_nobraces};

  void cant_open_file(const std::string& name);



  // complex conjugate
  template <typename D> std::complex<D>
  operator~(const std::complex<D>& x) {
    return std::complex<D>(x.real(), -x.imag());
  }


  
  /****************************************************************************
   * Rounding
   ****************************************************************************   
   */

  // complex rounding
  template <typename D> std::complex<D> round(const std::complex<D>& x) {
    return std::complex<D>(std::round(x.real()), std::round(x.imag()));
  }

  template <typename D> D roundzero(const D& x, const D tolerance) {
    return (std::abs(x) < std::abs(tolerance) ? 0 : x);
  }
  template <typename D> std::complex<D> roundzero(const std::complex<D>& x, const D tolerance) {
    return std::complex<D>(roundzero(x.real(),tolerance), roundzero(x.imag(),tolerance));
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
  template <class D>
  inline std::string num2string(D x) {
    std::ostringstream strm;
    strm << x;
    return strm.str();
    
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



  template <class DAT> class pair {
  public:
    index_type index;
    DAT data;
    pair(index_type index_, DAT data_) : index(index_), data(data_) {}
    pair() : index(0), data(DAT(0)) {}
    bool operator<(const pair<DAT>& pair2) const {
      return ((*this).data < pair2.data);
    }
  };

  /****************************************************************************
   * error reporting string definitions
   ****************************************************************************   
   */


  template <typename T>
  inline std::string getTypeString(T var) {
    std::ostringstream stream;
    stream << typeid(T).name();
    return stream.str();
  };


  inline std::string getTypeString(void) {  return std::string("void"); }
  
#define SPECIALIZE_GETTYPESTRING(T) template <> inline std::string getTypeString(T var) {  return std::string(#T); }
  
  SPECIALIZE_GETTYPESTRING(std::string);

  SPECIALIZE_GETTYPESTRING(float);
  SPECIALIZE_GETTYPESTRING(double);
  SPECIALIZE_GETTYPESTRING(long double);
  
  SPECIALIZE_GETTYPESTRING(bool);
  SPECIALIZE_GETTYPESTRING(char);
  SPECIALIZE_GETTYPESTRING(unsigned char);
  SPECIALIZE_GETTYPESTRING(signed char);
  
  SPECIALIZE_GETTYPESTRING(short);
  SPECIALIZE_GETTYPESTRING(unsigned short);
  SPECIALIZE_GETTYPESTRING(int);
  SPECIALIZE_GETTYPESTRING(long);
  SPECIALIZE_GETTYPESTRING(unsigned long);
#if LONGLONG_EXISTS
  SPECIALIZE_GETTYPESTRING(long long);
  SPECIALIZE_GETTYPESTRING(unsigned long long);
#endif


#define SPECIALIZE_GETTYPESTRING_CONTAINER(TYPE)  template <typename D> inline std::string getTypeString(const TYPE<D>& x) {return (std::string(# TYPE) + "<" +  getTypeString(D()) +"> "); }

  
  SPECIALIZE_GETTYPESTRING_CONTAINER(Vector);
  SPECIALIZE_GETTYPESTRING_CONTAINER(std::vector);
  SPECIALIZE_GETTYPESTRING_CONTAINER(std::complex)
  SPECIALIZE_GETTYPESTRING_CONTAINER(std::valarray);
  SPECIALIZE_GETTYPESTRING_CONTAINER(std::initializer_list);

  
  


  void bug_report(const std::string& fname,const size_type linenum);








 

  

  /****************************************************************************
   * Enumeration for different subclasses of VorE class
   ****************************************************************************   
   */
  enum VETypes {VE_Vector, VE_VScalObj,
		VE_VSliceExpr,
		VE_VSliceObj, 
		VE_VSubsetObj, VE_VSubMaskObj,
		VE_VReconObj,
		VE_VJoinExpr, VE_VJoinObj,
		VE_VRepExpr, 
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

    inline const D operator[](const index_type i) const {
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


    std::vector<const void*> getAddresses(void) const {
      return derived().getAddresses();
    }
    bool checkAddresses(const std::vector<const void*> addrs) const {
      return derived().checkAddresses(addrs);
    }
    void addAddress(const void* addr) {
      derived().addAddress(addr);
    }
    void addAddresses(const std::vector<const void*> addrs) {
      derived().addAddresses(addrs);
    }
    
    
    friend std::ostream& operator<<(std::ostream &stream, const VorE<D,VE>& ve) {
      Vector<D> v = ve.derived();
      stream << v;
      return stream;
    }
  };



  /****************************************************************************
   * Vector or Wrapper
   **************************************************************************** 
   */
  
  template <class D, class VW> class VorW {
  public:
    inline VW& derived() {
      return static_cast<VW&>(*this);
    }
    inline  D& operator[](const index_type i)  {
      return derived()[i];
    }
  };




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


    inline const D operator()(const index_type i) const {
      return derived()(i);
    }

    inline const D operator()(const index_type r, const index_type c) const {
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
  Vector<index_type> sub2ind(const MorE<index_type,A>& subs, const size_type NR, const size_type NC);



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

  template <typename D> struct MatricksHelper {
  public:
    static D tolerance = D(0);
  };
  template <> struct MatricksHelper<double> {
  public:
    constexpr static double tolerance = 1.5e-16;
  };
  template <> struct MatricksHelper<float> {
  public:
    constexpr static float tolerance = 3.5e-7;
  };



  /****************************************************************************
   * vector/matrix error reporting directory
   ****************************************************************************   
   */


  class AnyIF
  {
  };

  template <typename T>
  class Any : public AnyIF {
  public:
    typedef T MyType;
    MyType& variable; 
    explicit Any(MyType& var) : variable(var) {
      using namespace std;
      printf("function Any::Any(const MyType& var): MyType = %s, var = ",getTypeString(var).c_str());
      cout << var << endl;
    }
  };

  class ObjectInfo;
  
  class MatricksObjectManager {
  private:
    static size_type NextObjectID_; 
    static std::map<size_type, ObjectInfo* > objectPool;


  public:
    static size_type addObject(AnyIF& obj);
    static ObjectInfo* getObjectInfo(const size_type id);
    static void removeObject(const size_type id);
    static void outputGlossary(const size_type id);
  };
  

  static size_type addvector(const std::string name, const std::string classname, 
			     const std::string datatype, const  size_type size, const bool checkname=true);

  static void removevector(const size_type id);

  static std::string vectorname(const size_type id);

  static std::string vadd_name(const std::string& name, const size_type id, const bool checkname=true);

  static void vchange_name(const size_type id, const std::string& name, const bool checkname=true);
  static void vchange_size(const size_type id, const size_type size);

  static void outputGlossary(const size_type id);



  size_t NumMatrices(void);

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









// #define MTS_CONTAINER_MACRO(T) template <typename D>  std::string getTypeString(const T<D>& x) {return (std::string(# T) + "<" +  getTypeString(D()) +"> "); }


// MTS_CONTAINER_MACRO(std::complex);
// MTS_CONTAINER_MACRO(std::vector);
// MTS_CONTAINER_MACRO(std::valarray);
  
// MTS_CONTAINER_MACRO(Vector);
// MTS_CONTAINER_MACRO(Matrix);
// MTS_CONTAINER_MACRO(p3vector);

// // the following are instantiated to reduce compile time

// #define  MTS_MACRO_DECL2(T)  std::string getTypeString(const T&);

// MTS_MACRO_DECL2(std::complex<float>);
// MTS_MACRO_DECL2(std::complex<double>);
// MTS_MACRO_DECL2(std::complex<long double>);
// MTS_MACRO_DECL2(Vector<float>);
// MTS_MACRO_DECL2(Vector<double>);
// MTS_MACRO_DECL2(Vector<long double>);
// MTS_MACRO_DECL2(Vector<std::complex<double> >);
// MTS_MACRO_DECL2(Vector<Vector<double> >);
// MTS_MACRO_DECL2(Vector<Vector<std::complex<double> > >);
// MTS_MACRO_DECL2(Matrix<float>);
// MTS_MACRO_DECL2(Matrix<double>);
// MTS_MACRO_DECL2(Matrix<long double>);
// MTS_MACRO_DECL2(Matrix<std::complex<double> >);
// MTS_MACRO_DECL2(p3vector<float>);
// MTS_MACRO_DECL2(p3vector<double>);
// MTS_MACRO_DECL2(p3vector<long double>);
// MTS_MACRO_DECL2(p3vector<std::complex<double> >);

/*
  MTS_MACRO_DECL2(Vector<double>);
  MTS_MACRO_DECL2(std::complex<double>);
*/

/* template <typename D, template <typename> class T>  std::string getTypeString(const T<D>& x) {
   return (x.classname() + "<" +  getTypeString(D()) +"> "); 
   }
*/


};
#endif
