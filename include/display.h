#ifndef DISPLAY_H
#define DISPLAY_H




namespace matricks {
  // do away with
  extern const char* error_str;
  extern const char* warn_str;
  extern const char* indent_str;
  extern const char* where_str;
  extern const char* bug_str;

  //****************************************************************************
  //                          Some declarations. 
  //****************************************************************************


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
  
};

namespace display {



  extern const char blankline[];


  //****************************************************************************
  //                          Some declarations. Definitions below
  //****************************************************************************


  
  inline void log(const std::string spaceName, const std::string className, const std::string funcName, const std::string s);
  inline void log1(const std::string spaceName, const std::string className, const std::string funcName, const std::string s);
  inline void log2(const std::string spaceName, const std::string className, const std::string funcName, const std::string s);
  inline void log3(const std::string spaceName, const std::string className, const std::string funcName, const std::string s);
  inline void print1(const std::string s);
  inline void print2(const std::string s);
  inline void print3(const std::string s);


#if MATRICKS_DEBUG>=1
  #define printf1(...) printf(__VA_ARGS__)
#else
  #define printf1(...) {}
#endif

#if MATRICKS_DEBUG>=2
  #define printf2(...) printf(__VA_ARGS__)
#else
  #define printf2(...) {}
#endif

#if MATRICKS_DEBUG>=3
  #define printf3(...) printf(__VA_ARGS__)
#else
  #define printf3(...) {}
#endif


  //****************************************************************************
  //                          Terminal
  //****************************************************************************

  
  class Terminal {
  private:
    static bool isInitialized;
    static bool supportsColor;
  public:
    static bool getSupportsColor();
  };


  //****************************************************************************
  //                       Terminal escape codes for color etc
  //****************************************************************************

  
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
  const std::string REDBACK  = BACK+"5;201m";      
  const std::string ORANGE  = FORE+"5;208m";      
  const std::string GRAY1  = FORE+"5;240m";      

  const std::string BLUE1  = FORE+"5;18m";      
  const std::string BLUE2  = FORE+"5;21m";      
  const std::string BLUE3  = FORE+"5;27m";      

  const std::string MAGENTA1  = FORE+"5;129m";      
  const std::string VIOLET1  = FORE+"5;17m";      
  const std::string GREEN1  = FORE+"5;22m";      



  const size_t BUFFER_SIZE = 512;
  extern char Buffer[BUFFER_SIZE];

  // this definition is crafty, but probably better to make into a function
  
#define print2str(...) (new std::string())->erase(0*std::snprintf(display::Buffer,display::BUFFER_SIZE, __VA_ARGS__)).append(display::Buffer)


  //****************************************************************************
  //                       Style
  //****************************************************************************
  
  
  class Style {
  private:
    std::string stylestr_;
    std::string stylename_;
  public:
    static Style& create(const std::string stylestr, const std::string stylename);

    static Style& create(const unsigned int n) {
      Style* style = new Style(n);
      return *style;
    }

    inline Style()  : stylestr_(""), stylename_("") {
    }
    inline Style(const std::string stylestr)  : stylestr_(stylestr), stylename_("") {
    }
    inline Style(const std::string stylestr, const std::string stylename) : stylestr_(stylestr), stylename_(stylename){
    }
    inline Style(const Style& style) : stylestr_(style.getStyleString()), stylename_(style.getName()){
    }
    inline Style(const unsigned int n)  {
      stylestr_ = FORE+print2str("5;%um",n);
      stylename_ = "";
    }
    inline std::string apply(const std::string s) const {
      if (Terminal::getSupportsColor()) {
	return stylestr_ + s +RESET;
      } else {
	return s;
      }
    }
    inline std::string getStyleString() const {
      return stylestr_;
    }

    inline std::string getName() const {
      return stylename_;
    }

    inline Style& operator+(const Style& style2) const {
      Style* style3 = new Style(this->getStyleString() + style2.getStyleString(), this->getName() + "+"+style2.getName() );
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



#define createStyle(...) display::Style::create(__VA_ARGS__,#__VA_ARGS__)



  //****************************************************************************
  //                       StyledString
  //****************************************************************************

  
  
  enum SSEnum {INDENT, ERROR, WARNING, MATRICKS, VERSION, DLEVEL0, DLEVEL1, DLEVEL2, DLEVEL3, DEBUG_LEVEL, HORLINE};

  class StyledString {
  private:
    static bool isInitialized;
    static std::map<SSEnum, StyledString> Map;
    Style& style_;
    std::string text_;
  public:
    static void add(const SSEnum ss, StyledString& styledString); 
    static void del(const SSEnum ss);
    static StyledString& get(const SSEnum ss);
    static void initialize();
    static StyledString& create(Style& style, const std::string text) {
          return *( new StyledString(style, text) );
    }

    inline StyledString() :
      style_(createStyle(CROSSEDOUT)),
      text_(std::string("hello world"))
    {
      if (!StyledString::isInitialized) {
    	StyledString::initialize();
      }
    }
    inline StyledString(Style& style, const std::string text) :
      style_(style), text_(text)
    {  
    }
    inline StyledString(const StyledString& styledstring) :
      style_(styledstring.getStyle()), text_(styledstring.getString())
    {  
    }
    inline std::string get() const {
      return style_.apply(text_);
    }
    inline std::string getString() const {
      return text_;
    }
    inline StyledString& setString(const std::string text)  {
      text_ = text;
      return *this;
    }
    inline Style& getStyle()  const {
      return style_;
    }

    StyledString& operator=(const StyledString& styledstring) {
      style_ = styledstring.getStyle();
      text_ = styledstring.getString();
      return *this;
    }


    inline friend std::ostream& operator<<(std::ostream &stream, const StyledString& ss) {
      stream << ss.get();
      return stream;
    }
      
  };




  //****************************************************************************
  //                       FormatData
  //****************************************************************************


  template <typename T> inline std::string getTypeName(const T& var);

  class FormatBase {
  };

  template <typename T>
  class FormatData {
  public:
  };


  template <typename T>
  inline std::string getFormatString() {
    return FormatData<T>::format_string;
  }
  template <typename T>
  inline std::string getDefaultFormatString() {
    return FormatData<T>::default_format_string;
  }


  
#define SPECIALIZE_FormatData_mathtype(TYPE) \
  template <>  class FormatData<TYPE> { \
  public: \
    static Style style_for_type_name;\
    static Style style_for_value;\
    static Style style_for_zero;\
    const static std::string format_string_default;\
    static std::string format_string;\
  };

  SPECIALIZE_FormatData_mathtype(float);
  SPECIALIZE_FormatData_mathtype(double);
  SPECIALIZE_FormatData_mathtype(long double);

  SPECIALIZE_FormatData_mathtype(short);
  SPECIALIZE_FormatData_mathtype(int);
  SPECIALIZE_FormatData_mathtype(long);
#if LONGLONG_EXISTS
  SPECIALIZE_FormatData_mathtype(long long);
#endif

  SPECIALIZE_FormatData_mathtype(unsigned short);
  SPECIALIZE_FormatData_mathtype(unsigned int);
  SPECIALIZE_FormatData_mathtype(unsigned long);
#if LONGLONG_EXISTS
  SPECIALIZE_FormatData_mathtype(unsigned long long);
#endif


  // string
  template <>  class FormatData<std::string> {
  public: 
    static Style style_for_type_name;	    
    static Style style_for_value;
    const static std::string format_string_default;
    static std::string format_string;
  };

  // char
  template <>  class FormatData<char> {
  public: 
    static Style style_for_type_name;	    
    static Style style_for_value;
    const static std::string format_string_default;
    static std::string format_string;
  };


  // bool
  template <>  class FormatData<bool> {
  public: 
    static Style style_for_type_name;	    
    static Style style_for_true;
    static Style style_for_false;
    static std::string string_for_true;
    static std::string string_for_false;
  };


  // Vector
  class FormatDataVector {
  public: 
    static matricks::index_type max_elements_per_line;
    static Style style_for_type_name;	    
    static Style style_for_punctuation;
    static std::string string_opening;
    static std::string string_delimeter;
    static std::string string_endofline;
    static std::string string_closing;
  };


  //****************************************************************************
  //       FormatString
  //****************************************************************************



  template <typename D> 
  inline bool checkFormatString(const std::string formatstr, const D& x = D(1)) {
    using namespace std;
    if (formatstr.empty()) {
      return false;
    }
    
    int ret = 0;
    bool passed = true;
    try {
      ret = snprintf(Buffer, BUFFER_SIZE, formatstr.c_str(), x);
      if (ret<0) passed = false;
    } catch (...) {
      string classname = "";
      passed = false;
    }
    string s = string(Buffer);
    size_t found = s.find("(nil)");
    if (found!=string::npos) 	passed = false;
    
    D x2 = D(0);
    D *x2ptr = &x2;
    ret = std::sscanf(Buffer, "%lg", x2ptr);
    if (ret != 1) passed = false;
    if (x2 != x)  passed = false;
    
    if (!passed) {
      cout << StyledString::get(HORLINE);
      cout << StyledString::get(ERROR);
      cout << " illegal format string";
      cout << createStyle(BOLD).apply(string(" \"") + formatstr + "\"");
      cout << " passed to Format";
      cout << "<" << display::getTypeName(x) << ">";
      cout << endl;
      cout << StyledString::get(HORLINE);
      return false;
    }     
    return true;
  }


  

  template <typename T>
  inline void setFormatString(const std::string fstring) {
    T* xptr = new T(25);
    bool valid = checkFormatString<T>(fstring, *xptr);
    if (valid) {
      FormatData<T>::format_string = fstring;
    }
  }


  //---------------------------------------------------------------------------------
  //       getTypeName
  //---------------------------------------------------------------------------------

  template <typename T>
  inline std::string getTypeName(const T& var) {
    return var.classname();
  }

#define SPECIALIZE_getTypeName(TYPE) \
  template <> \
  inline std::string getTypeName(const TYPE& var) { \
    return FormatData<TYPE>::style_for_type_name.apply(#TYPE);\
  }

  SPECIALIZE_getTypeName(float);
  SPECIALIZE_getTypeName(double);
  SPECIALIZE_getTypeName(long double);

  SPECIALIZE_getTypeName(short);
  SPECIALIZE_getTypeName(int);
  SPECIALIZE_getTypeName(long);
#if LONGLONG_EXISTS
  SPECIALIZE_getTypeName(long long);
#endif

  SPECIALIZE_getTypeName(unsigned short);
  SPECIALIZE_getTypeName(unsigned int);
  SPECIALIZE_getTypeName(unsigned long);
#if LONGLONG_EXISTS
  SPECIALIZE_getTypeName(unsigned long long);
#endif


  SPECIALIZE_getTypeName(std::string);
  SPECIALIZE_getTypeName(char);
  SPECIALIZE_getTypeName(bool);


  // T[]
  template <typename T, size_t N>
    inline std::string getTypeName(const T (&a)[N]) {
    std::string tname = getTypeName(a[0]);
    std::ostringstream stream;
    stream << tname << "[" << N << "]";
    return stream.str();
  }


#define SPECIALIZE_getTypeName_CONTAINER(TYPE)				\
  template <typename D>							\
    inline std::string getTypeName(const TYPE<D>& var) {		\
    Style style = createStyle(CYAN);					\
    std::string s =  style.apply(#TYPE);				\
    D d;								\
    s = s+"<"+getTypeName(d)+">";					\
    return s;								\
  }



  SPECIALIZE_getTypeName_CONTAINER(std::vector);
  SPECIALIZE_getTypeName_CONTAINER(std::valarray);
  SPECIALIZE_getTypeName_CONTAINER(std::list);
  SPECIALIZE_getTypeName_CONTAINER(std::queue);
#if CPP11 == 1
  SPECIALIZE_getTypeName_CONTAINER(std::initializer_list);
#endif

#define SPECIALIZE_getTypeName_CONTAINER2(TYPE)				\
  template <typename D1, typename D2>						\
    inline std::string getTypeName(const TYPE<D1,D2>& var) {		\
    Style style = createStyle(CYAN);					\
    std::string s =  style.apply(#TYPE);				\
    D1 d1;								\
    D2 d2;								\
    s = s+"<"+getTypeName(d1)+","+getTypeName(d2)+">";					\
    return s;								\
  }

  SPECIALIZE_getTypeName_CONTAINER2(std::map);



  


  //---------------------------------------------------------------------------------
  //       printObj
  //---------------------------------------------------------------------------------

  template <typename T>
  inline void printObj(const T& d) {
    std::cout << d;
  }

    
  
#define SPECIALIZE_mathtypes_printObj(TYPE)					\
  template <>								\
    inline void printObj<TYPE >(const TYPE& d) {			\
    using namespace std;						\
    snprintf(Buffer, BUFFER_SIZE, getFormatString<TYPE >().c_str(), d ); \
    string sval = string(Buffer);					\
    Style style = FormatData<TYPE >::style_for_value;			\
    TYPE zero = 0;							\
    if (d == zero) {							\
      style = FormatData<TYPE >::style_for_zero;			\
    }									\
    cout << style.apply(sval);						\
  }
  
  SPECIALIZE_mathtypes_printObj(float);
  SPECIALIZE_mathtypes_printObj(double);
  SPECIALIZE_mathtypes_printObj(long double);

  SPECIALIZE_mathtypes_printObj(short);
  SPECIALIZE_mathtypes_printObj(int);
  SPECIALIZE_mathtypes_printObj(long);
#if LONGLONG_EXISTS
  SPECIALIZE_mathtypes_printObj(long long);
#endif

  SPECIALIZE_mathtypes_printObj(unsigned short);
  SPECIALIZE_mathtypes_printObj(unsigned int);
  SPECIALIZE_mathtypes_printObj(unsigned long);
#if LONGLONG_EXISTS
  SPECIALIZE_mathtypes_printObj(unsigned long long);
#endif

  // string
  template <>				
    inline void printObj<std::string>(const std::string& str) {
    using namespace std;
    snprintf(Buffer, BUFFER_SIZE, getFormatString<std::string>().c_str(), str.c_str() );
    string s = string(Buffer);
    Style style = FormatData<std::string>::style_for_value;
    cout << style.apply(s);
  }

  // char
  template <>				
    inline void printObj<char>(const char& c) {
    using namespace std;					
    snprintf(Buffer, BUFFER_SIZE, getFormatString<char>().c_str(), c );
    string s = string(Buffer);
    Style style = FormatData<char>::style_for_value;
    cout << style.apply(s);
  }


  // bool
  template <>				
    inline void printObj<bool>(const bool& b) {
    using namespace std;
    if (b) {
      Style style = FormatData<bool>::style_for_true;
      string s = FormatData<bool>::string_for_true;
      cout << style.apply(s);
    } else {
      Style style = FormatData<bool>::style_for_false;
      string s = FormatData<bool>::string_for_false;
      cout << style.apply(s);
    }
  }
  

  // T[N]
  template <typename T,  size_t N>
    inline void printObj(const T (&a)[N]) {
    std::cout << "{";
    for (size_t ii = 0; ii < N; ii++) {
      if (ii>0)  std::cout << ", ";
      printObj(a[ii]);
    }
    std::cout << "}";
  }

  // char[N]
  template <size_t N>
    inline void printObj(const char (&a)[N]) {
    std::cout << a;
  }


  // std::vector
  template <typename D>							
    inline void printObj(const std::vector<D>& var) {
    std::cout << "{";
    for (size_t ii = 0; ii < var.size(); ii++) {
      if (ii>0)  std::cout << ", ";
      printObj(var[ii]);
    }
    std::cout << "}";
  }

  // std::valarray
  template <typename D>							
    inline void printObj(const std::valarray<D>& var) {
    std::cout << "{";
    for (size_t ii = 0; ii < var.size(); ii++) {
      if (ii>0)  std::cout << ", ";
      printObj(var[ii]);
    }
    std::cout << "}";
  }


  // std::list
  template <typename D>							
    inline void printObj(const std::list<D>& var) {
    std::cout << "{";
    size_t ii = 0;
    for(typename std::list<D>::const_iterator it = var.begin(); it != var.end(); ++it) {
      if (ii++>0)  std::cout << ", ";
      printObj(*it);
    }
    std::cout << "}";
  }

    // std::initializer_list
#if CPP11 == 1
  template <typename D>							
    inline void printObj(const std::initializer_list<D>& var) {
    std::cout << "{";
    size_t ii = 0;
    for(typename std::initializer_list<D>::const_iterator it = var.begin(); it != var.end(); ++it) {
      if (ii++>0)  std::cout << ", ";
      printObj(*it);
    }
    std::cout << "}";
  }
#endif

    // std::queue
  template <typename D>							
    inline void printObj(const std::queue<D>& var) {
    // ** We have to copy the queue to iterate through contents since this is a desrtuctive process
    std::queue<D> myq = var;
      
    std::cout << "{";
    const size_t N = myq.size();
    for (size_t ii = 0; ii < N; ii++) {
      if (ii>0)  std::cout << ", ";
      D val = myq.front();
      myq.pop();
      printObj(val);
    }
    std::cout << "}";
  }

    
  // std::map
  template <typename D1, typename D2>					
    inline void printObj(const std::map<D1,D2>& mymap) {
    std::cout << "{" << std::endl;
    for (typename std::map<D1,D2>::const_iterator it = mymap.begin(); it != mymap.end(); it++ ) {
      std::cout <<" "<< it->first << ":" << it->second << std::endl;
    }
    std::cout << "}";
  }


  
  //---------------------------------------------------------------------------------
  //       specialize for complex<double>
  //---------------------------------------------------------------------------------

  class FormatDataComplex {
  public:
    static Style style_for_type_name;
    static Style style_for_punctuation;
    static std::string format_string;  
    const static std::string format_string_default; 
  };


  template <class D>
  inline std::string getTypeName(const std::complex<D> & var) {
    std::string s = FormatDataComplex::style_for_type_name.apply("std::complex");
    s += "<" + getTypeName(var.real())+ +"> ";
    return s;
  }
  
    

  inline bool checkFormatStringComplex(const std::string formatstr) {
    using namespace std;
    if (formatstr.empty()) {
      return false;
    }
    
    int ret = 0;
    bool passed = true;
    string sr = string("%f");
    string si = string("%f");
    try {
      ret = snprintf(Buffer, BUFFER_SIZE, formatstr.c_str(), sr.c_str(), si.c_str());
      if (ret<0) passed = false;
    } catch (...) {
      passed = false;
    }
    string s = string(Buffer);
    size_t found = s.find("(nil)");
    if (found!=string::npos) 	passed = false;

    string formatfloats = s;
    float xreal = 3.1415;
    float ximag = 2.72;
    try {
      ret = snprintf(Buffer, BUFFER_SIZE, formatfloats.c_str(), xreal, ximag);
      if (ret<0) passed = false;
    } catch (...) {
      passed = false;
    }
    s = string(Buffer);
    found = s.find("(nil)");
    if (found!=string::npos) 	passed = false;

    
    //    printf("formatstr = %s\n",formatstr.c_str());
    //    printf("formatfloats = %s\n",formatfloats.c_str());

    float xreal2 = 3.1415;
    float ximag2 = 2.72;
    ret = std::sscanf(Buffer, formatfloats.c_str() , &xreal2, &ximag2);
    //    printf("xreal2=%f ximag2=%f\n",xreal2,ximag2);
    if (ret != 2) passed = false;
    if (xreal2 != xreal)  passed = false;
    if (ximag2 != ximag)  passed = false;
    
    if (!passed) {
      cout << StyledString::get(HORLINE);
      cout << StyledString::get(ERROR);
      cout << " illegal format string";
      cout << createStyle(BOLD).apply(string(" \"") + formatstr + "\"");
      cout << " passed to setFormatStringComplex";
      cout << endl;
      cout << StyledString::get(HORLINE);
      return false;
    }     
    return true;
  }

  inline std::string getFormatStringComplex() {
    return FormatDataComplex::format_string;
  }

  inline void setFormatStringComplex(const std::string fstring) {
    bool valid = checkFormatStringComplex(fstring);
    if (valid) {
      FormatDataComplex::format_string = fstring;
    }
  }

  
  template <class D>
  inline void printObj(const std::complex<D>& d) {
    using namespace std;
    using namespace matricks;

    // print the real and imaginary parts to strings
    snprintf(Buffer, BUFFER_SIZE, getFormatString<D>().c_str(), d.real() );
    string sr = string(Buffer);
    snprintf(Buffer, BUFFER_SIZE, getFormatString<D>().c_str(), d.imag() );
    string si = string(Buffer);

    // decompose the format string so we can apply style to the punctuation
    string fs = getFormatStringComplex();
    int m1 = fs.find("%s");
    string fs1 = fs.substr(0,m1);
    int m2 = fs.find("%s",m1+2);
    string fs2 = fs.substr(m1+2,m2-m1-2);
    string fs3 = fs.substr(m2+2,fs.size()-m2-2);
    Style style = FormatDataComplex::style_for_punctuation;
    fs = style.apply(fs1) + "%s" + style.apply(fs2) + "%s" + style.apply(fs3);

    // put it all together
    printf(fs.c_str(), sr.c_str(), si.c_str());
  }
  

  
  //****************************************************************************
  //                       Log
  //****************************************************************************

  
  class Log {
  public:
    static  Style style_log0;
    static  Style style_log1;
    static  Style style_log2;
    static  Style style_log3;
    static  Style style_nspace;
    ;    static  Style style_class;
    static  Style style_func;
    static  Style style_str;

    static void log(const int level, const std::string spaceName, const std::string className, const std::string funcName, const std::string s = "");
    static void print(const int level, std::string s);
    static void warning(const std::string s);
    static void error(const std::string s);
    static void indent(const std::string s);

    
    Log();

  }; // class  Log

  inline void log(const std::string spaceName, const std::string className, const std::string funcName, const std::string s = "") {
    display::Log::log(0, spaceName, className, funcName, s);
    //    std::cout << __PRETTY_FUNCTION__;
  }

  inline void log1(const std::string spaceName, const std::string className, const std::string funcName, const std::string s = "") {
#if MATRICKS_DEBUG>=1
    display::Log::log(1, spaceName, className, funcName, s);
#endif
  }

  inline void log2(const std::string spaceName, const std::string className, const std::string funcName, const std::string s = "") {
#if MATRICKS_DEBUG>=2
    display::Log::log(2, spaceName, className, funcName, s);
#endif
  }

  inline void log3(const std::string spaceName, const std::string className, const std::string funcName, const std::string s = "") {
#if MATRICKS_DEBUG>=3
    display::Log::log(3, spaceName, className, funcName, s);
#endif
  }


  inline void print1(const std::string s) {
#if MATRICKS_DEBUG>=1
    display::Log::print(1,s);
#endif
  }
  inline void print2(const std::string s) {
#if MATRICKS_DEBUG>=2
    display::Log::print(2,s);
#endif
  }
  inline void print3(const std::string s) {
#if MATRICKS_DEBUG>=3
    display::Log::print(3,s);
#endif
  }



  //****************************************************************************
  //                       Display
  //****************************************************************************


  
  // add class variable that if defined overrides the default, taken from the Format class
  class Display {
  private:
    static bool isInitialized;
    static StyledString* expression;
    static StyledString* equals;
    static StyledString* terminator;
  public:
    static void initialize() {
      log3("display","Display","initialize","()");
      
      Display::isInitialized = true;
      Display::expression = new StyledString(createStyle(BOLD),"");
      Display::equals = new StyledString(createStyle(GRAY1)," = ");
      Display::terminator = new StyledString(createStyle(GRAY1),";");
    }
    Display(){
      if (!isInitialized) {
	Display::initialize();
      }
    }
    template <typename X>
    static void mydisp(const X& x, const std::string name, const bool displayType, const bool issueCR) {
      using namespace std;
      log3("display","Display","mydisp","(const X& x, const std::string name)");
      if (displayType) {
	cout << getTypeName(x) << " ";
      }
      expression->setString(name);
      cout << *expression;
      cout << *equals;
      printObj(x);
      cout << *terminator;
      if (issueCR) {
	cout << endl;
      }
    }
    template <typename X>
    static void mydispcr(const X& x, const std::string name) {
      using namespace std;
      mydisp(x, name,false, true);
    }
    template <typename X>
    static void tmydispcr(const X& x, const std::string name) {
      using namespace std;
      mydisp(x, name, true, true);
    }
  };  // class Display


#define newdisp(...) display::Display::mydispcr(__VA_ARGS__,#__VA_ARGS__)
#define tdisp(...) display::Display::tmydispcr(__VA_ARGS__,#__VA_ARGS__)


      

  //****************************************************************************
  //                       print_matricks_info
  //****************************************************************************


  inline void print_matricks_info(void) {
    using namespace std;
    using namespace display;
    cout << StyledString::get(HORLINE);
    cout << StyledString::get(MATRICKS) << " ";
    cout << StyledString::get(VERSION) << " ";
    cout << endl << endl;
    cout << "compile-time settings:" << endl;
    cout << "  "<<StyledString::get(DEBUG_LEVEL) << " " << endl;
    cout << createStyle(BOLD).apply("  C++ version: ");
    cout << createStyle(CYAN).apply(print2str("%lu",__cplusplus)) << endl;
    cout << createStyle(BOLD).apply("  OPTIMIZE: ");
    cout << createStyle(CYAN).apply(string(COMPILE_OPTIMIZE)) << endl;
    cout << StyledString::get(HORLINE);
      
  }

    
 

  
}; // namespace display


#endif
