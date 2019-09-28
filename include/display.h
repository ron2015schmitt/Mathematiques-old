#ifndef MATRICKS__DISPLAY
#define MATRICKS__DISPLAY

#include <unistd.h>
#include <stdarg.h>
#include <functional>


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





  //****************************************************************************
  //                        String functions
  //****************************************************************************

  inline std::string  replaceAll(std::string  s, std::string s1, std::string s2) {
    size_t pos = s.find(s1);
    while( pos != std::string::npos) {
      s.replace(pos, s1.size(), s2);
      pos = s.find(s1, pos + s2.size());
    }
    return s;
  }


  //------------------------------------------------------------
  //                        printf2str
  //------------------------------------------------------------


  inline std::string printf2str(const char *format, ...) {
    const size_t BUFFER_SIZE = 256;
    static char buffer[BUFFER_SIZE];
    va_list args;
    va_start(args, format);
    size_t n = vsnprintf(buffer,BUFFER_SIZE,format,args);
    if (n<0) {
      // TODO: format error and throw
    } else if (n>=BUFFER_SIZE) {
      // TODO: string too long error and throw
    }
    va_end(args);
    return std::string(buffer);
  }





  //------------------------------------------------------------
  //                        num2string
  //------------------------------------------------------------


  template <class D>
    inline std::string num2string(D x) {
    std::ostringstream strm;
    strm << x;
    return strm.str();
  } 



  //------------------------------------------------------------
  // The scope of a macros is where it is used!!!
  //------------------------------------------------------------

#if MATRICKS_DEBUG>=1
#define printf1(...) mout << display::printf2str(__VA_ARGS__)
#else
#define printf1(...) {}
#endif

#if MATRICKS_DEBUG>=2
#define printf2(...) mout << display::printf2str(__VA_ARGS__)
#else
#define printf2(...) {}
#endif

#if MATRICKS_DEBUG>=3
#define printf3(...) mout << display::printf2str(__VA_ARGS__)
#else
#define printf3(...) {}
#endif

  
  //****************************************************************************
  //                          Terminal
  //****************************************************************************

  
  class Terminal {
  private:
    static bool isInitialized;
    static bool colorOverride;
    static bool overrideValue;
    static std::ostream* outputstream;
  public:
    Terminal() {
      // for initializing the class
      if (!isInitialized) {
	outputstream = &std::cout;
      }
      isInitialized = true;
    }
    
    inline static bool getUseColor() {
      bool useColor = false;
      if (Terminal::outputstream == &std::cout) {
	useColor = ( isatty(STDOUT_FILENO) == 1 );
      } else if (Terminal::outputstream == &std::cerr) {
	useColor = ( isatty(STDERR_FILENO) == 1 );
      }
      if (colorOverride) {
	return overrideValue;
      } else {
	return useColor;
      }
    }

    inline static void setColorOverride(bool val) {
      colorOverride = val;
    }
    inline static void setOverrideValue(bool val) {
      overrideValue = val;
    }      
    inline static void setmout(std::ostream& os) {
      outputstream = &os;
    }      
    inline static bool getColorOverride() {
      return colorOverride;
    }
    inline static bool getOverrideValue() {
      return overrideValue;
    }
    inline static std::ostream& getmout() {
      return *outputstream;
    }      
  };


#define mout (display::Terminal::getmout())
  

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
  const std::string RAPIDBLINK = ESC+"6m"; // not widely supported
  const std::string REVERSED   = ESC+"7m";
  const std::string CROSSEDOUT = ESC+"9m";
  const std::string FONT2      = ESC+"11m"; // not widely supported
  const std::string FRAKTUR    = ESC+"20m"; // not widely supported
  const std::string FRAMED     = ESC+"51m"; // not widely supported
  const std::string ENCIRCLED  = ESC+"52m"; // not widely supported
  const std::string OVERLINE   = ESC+"53m";

  const std::string BLACK   = FORE+"5;232m";  // in Ubuntu color=0 is sloghtly gray
  const std::string GRAY2   = ESC+"30m";      
  const std::string GRAY1  = FORE+"5;240m";      
  const std::string WHITE   = ESC+"37m";

  // organized per ROYGBIV
  const std::string RED     = ESC+"31m";      
  const std::string ORANGE  = FORE+"5;208m";      
  const std::string ORANGE1  = FORE+"5;172m";      
  const std::string ORANGE2  = FORE+"5;166m";      
  const std::string YELLOW  = ESC+"33m";      
  const std::string YELLOWBRIGHT  = ESC+"93m";      
  const std::string GREEN   = ESC+"32m";      
  const std::string GREENBRIGHT   = ESC+"92m";      
  const std::string GREEN1  = FORE+"5;22m";      
  const std::string CYAN    = ESC+"36m";      
  const std::string BLUE    = ESC+"34m";      
  const std::string BLUEBRIGHT    = ESC+"94m";      
  const std::string BLUE1  = FORE+"5;18m";      
  const std::string BLUE2  = FORE+"5;21m";      
  const std::string BLUE3  = FORE+"5;27m";      
  const std::string MAGENTA = ESC+"35m";      
  const std::string MAGENTA1  = FORE+"5;129m";      
  const std::string VIOLET1  = FORE+"5;54m";      



  
  const std::string BLACKBACK  = BACK+"5;16m";      
  const std::string REDBACK  = BACK+"5;160m";      
  const std::string ORANGEBACK  = BACK+"5;208m";      
  const std::string YELLOWBACK  = BACK+"5;226m";      
  const std::string GREENBACK  =  BACK+"5;46m";      







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
      stylestr_ = FORE+printf2str("5;%um",n);
      stylename_ = "";
    }
    inline Style(const unsigned int n, const unsigned int m)  {
      stylestr_ = FORE+printf2str("5;%um",n)+BACK+printf2str("5;%um",m);
      stylename_ = "";
    }
    inline Style(const std::string attributestr, const unsigned int n, const unsigned int m)  {
      stylestr_ = attributestr+FORE+printf2str("5;%um",n)+BACK+printf2str("5;%um",m);
      stylename_ = "";
    }
    inline std::string apply(const std::string s) const {
      if (Terminal::getUseColor()) {
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

    inline std::string classname() const {
      return "Style";
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

  
  
  enum SSEnum {INDENT, ERROR, WARNING, MATRICKS, VERSION, DLEVEL0, DLEVEL1, DLEVEL2, DLEVEL3, HORLINE, ANGLE1, ANGLE2, PAREN1, PAREN2, BRACKET1, BRACKET2, BRACE1, BRACE2, COMMA, COLON, SEMICOLON, PERIOD};

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

    inline std::string classname() const {
      return "StyledString";
    }

    inline friend std::ostream& operator<<(std::ostream &stream, const StyledString& ss) {
      stream << ss.get();
      return stream;
    }
      
  };




  //---------------------------------------------------------------------------------
  //       getTypeStyle
  //---------------------------------------------------------------------------------


  template <typename T> inline Style getTypeStyle(const T& var) {
    return createStyle(CYAN);    
  }
  template <> inline Style getTypeStyle(const std::string& var) {
    return createStyle(GREEN);    
  }

  
#define SPECIALIZE_getTypeStyle(TYPE)				\
  template <> inline Style getTypeStyle(const TYPE& var) {	\
    return createStyle(MAGENTA);				\
  }

  SPECIALIZE_getTypeStyle(float);
  SPECIALIZE_getTypeStyle(double);
  SPECIALIZE_getTypeStyle(long double);

  SPECIALIZE_getTypeStyle(char);
  SPECIALIZE_getTypeStyle(signed char);
  SPECIALIZE_getTypeStyle(short);
  SPECIALIZE_getTypeStyle(int);
  SPECIALIZE_getTypeStyle(long);
  SPECIALIZE_getTypeStyle(long long);

  SPECIALIZE_getTypeStyle(unsigned char);
  SPECIALIZE_getTypeStyle(unsigned short);
  SPECIALIZE_getTypeStyle(unsigned int);
  SPECIALIZE_getTypeStyle(unsigned long);
  SPECIALIZE_getTypeStyle(unsigned long long);

  SPECIALIZE_getTypeStyle(wchar_t);
  SPECIALIZE_getTypeStyle(bool);


  // container type
  template <typename D, template<typename> typename C> inline Style getTypeStyle(const C<const D>& var) {
    Style style = createStyle(CYAN); 
    return style;    
  }

  // container type2
  template <typename D1, typename D2, template<typename,typename> typename C> inline Style getTypeStyle(const C<const D1, const D2>& var) {
    Style style = createStyle(CYAN); 
    return style;    
  }


  inline Style getFunctionTypeStyle() {
    return createStyle(BLUE);
  }
    

  
  //---------------------------------------------------------------------------------
  //       getTypeName
  //---------------------------------------------------------------------------------

  // TODO: implement a way to print out typeid(var).name() if classname does not
  //       exist.  There are ways with macros, but not pretty
  // https://stackoverflow.com/questions/87372/check-if-a-class-has-a-member-function-of-a-given-signature
  // perhaps implement as added feature if C++11 compiler:
  // https://stackoverflow.com/questions/41936763/type-traits-to-check-if-class-has-member-function
  
  template <class T> inline std::string getTypeName(const T& var) {
    return getTypeStyle(var).apply(var.classname());
  }

  template <typename T> inline std::string getBracketedTypeName(const T& var){
    std::string name = getTypeName<T>(var);
    return StyledString::get(ANGLE1).get() + getTypeStyle(var).apply(name) + StyledString::get(ANGLE2).get();
  }


#define SPECIALIZE_getTypeName(TYPE)				\
  template <>							\
    inline std::string getTypeName(const TYPE& var) {		\
    return getTypeStyle(var).apply(#TYPE);			\
  }

  SPECIALIZE_getTypeName(float);
  SPECIALIZE_getTypeName(double);
  SPECIALIZE_getTypeName(long double);

  SPECIALIZE_getTypeName(char);
  SPECIALIZE_getTypeName(signed char);
  SPECIALIZE_getTypeName(short);
  SPECIALIZE_getTypeName(int);
  SPECIALIZE_getTypeName(long);
  SPECIALIZE_getTypeName(long long);

  SPECIALIZE_getTypeName(unsigned char);
  SPECIALIZE_getTypeName(unsigned short);
  SPECIALIZE_getTypeName(unsigned int);
  SPECIALIZE_getTypeName(unsigned long);
  SPECIALIZE_getTypeName(unsigned long long);

  SPECIALIZE_getTypeName(wchar_t);

  SPECIALIZE_getTypeName(std::string);
  SPECIALIZE_getTypeName(bool);

  //std::complex
  template <class D>
    inline std::string getTypeName(const std::complex<D> & var) {
    std::string s = getTypeStyle(var).apply("std::complex");
    s += getBracketedTypeName(var.real());
    return s;
  }

  
  // T[]
  template <typename T, size_t N>
    inline std::string getTypeName(const T (&a)[N]) {
    std::string tname = getTypeName(a[0]);
    std::ostringstream stream;
    stream << tname << StyledString::get(BRACKET1).get() << N << StyledString::get(BRACKET2).get();
    return stream.str();
  }



  // This does not overridfe the default
  //  template <class D>
  //  inline std::string getTypeName(typename matricks::FunctionTypes<D>::unary_func var) {
  //  std::string s = display::getFunctionTypeStyle().apply("userfunc");
  //  double d = 0;
  //  std::string sd = display::getTypeName(d);
  //  s = sd + "(*"+s+")"+"("+sd+")";
  //  return s;
  //}


  // this works
  inline std::string getTypeName(typename matricks::FunctionTypes<double>::unary_func var) {
    std::string sfunc = display::getFunctionTypeStyle().apply("func");
    double d;
    std::string sd = display::getTypeName(d);
    return sd + " "+sfunc+ StyledString::get(PAREN1).get()+sd+","+sd+StyledString::get(PAREN2).get();
  }



#define SPECIALIZE_getTypeName_CONTAINER(TYPE)			\
  template <typename D>						\
    inline std::string getTypeName(const TYPE<D>& var) {	\
    std::string s = getTypeStyle(var).apply(#TYPE);		\
    D d;							\
    s = s+getBracketedTypeName(d);				\
    return s;							\
  }

  SPECIALIZE_getTypeName_CONTAINER(std::vector);
  SPECIALIZE_getTypeName_CONTAINER(std::valarray);
  SPECIALIZE_getTypeName_CONTAINER(std::list);
  SPECIALIZE_getTypeName_CONTAINER(std::queue);
#if CPP11 == 1
  SPECIALIZE_getTypeName_CONTAINER(std::initializer_list);
#endif

#define SPECIALIZE_getTypeName_CONTAINER2(TYPE)			\
  template <typename D1, typename D2>				\
    inline std::string getTypeName(const TYPE<D1,D2>& var) {	\
    std::string s = getTypeStyle(var).apply(#TYPE);		\
    D1 d1;							\
    D2 d2;							\
    s += StyledString::get(BRACKET1).get();			\
    s += getTypeName(d1);					\
    s += StyledString::get(COMMA).get();			\
    s += getTypeName(d2);					\
    s += StyledString::get(BRACKET2).get();			\
    return s;							\
  }

  SPECIALIZE_getTypeName_CONTAINER2(std::map);


  

  
  

  //****************************************************************************
  //                       FormatData
  //****************************************************************************




  
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
    return FormatData<T>::format_string_default;
  }


  
#define SPECIALIZE_FormatData_mathtype(TYPE)		\
  template <>  class FormatData<TYPE> {			\
  public:						\
    static Style style_for_value;			\
    static Style style_for_zero;			\
    const static std::string format_string_default;	\
    static std::string format_string;			\
  };

  SPECIALIZE_FormatData_mathtype(short);
  SPECIALIZE_FormatData_mathtype(int);
  SPECIALIZE_FormatData_mathtype(long);
  SPECIALIZE_FormatData_mathtype(long long);

  SPECIALIZE_FormatData_mathtype(unsigned short);
  SPECIALIZE_FormatData_mathtype(unsigned int);
  SPECIALIZE_FormatData_mathtype(unsigned long);
  SPECIALIZE_FormatData_mathtype(unsigned long long);



#define SPECIALIZE_FormatData_floating(TYPE)		\
  template <>  class FormatData<TYPE> {			\
  public:						\
    static Style style_for_type_name;			\
    static Style style_for_value;			\
    static Style style_for_zero;			\
    const static std::string format_string_default;	\
    static std::string format_string;			\
    static bool tens;					\
  };

  SPECIALIZE_FormatData_floating(float);
  SPECIALIZE_FormatData_floating(double);
  SPECIALIZE_FormatData_floating(long double);

  
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
    static Style style_for_punctuation;
    static std::string string_opening;
    static std::string string_delimeter;
    static std::string string_endofline;
    static std::string string_closing;
  };

  // Matrix
  class FormatDataMatrix {
  public: 
    static matricks::index_type max_elements_per_line;
    static Style style_for_punctuation;
    static std::string string_opening;
    static std::string string_delimeter;
    static std::string string_row_opening;
    static std::string string_row_closing;
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
    
    bool passed = true;
    std::string s("");
    try {
      s = printf2str(formatstr.c_str(), x);
    } catch (...) {
      // rethrow
      passed = false;
    }
    size_t found = s.find("(nil)");
    if (found != string::npos) 	passed = false;
    D x2 = D(0);
    D *x2ptr = &x2;
    string format = FormatData<D>::format_string_default;
    int ret = std::sscanf(s.c_str(), format.c_str(), x2ptr);
    if (ret != 1) passed = false;
    if (x2 != x)  passed = false;
    
    if (!passed) {
      mout << StyledString::get(HORLINE);
      mout << StyledString::get(ERROR);
      mout << " illegal format string";
      mout << createStyle(BOLD).apply(string(" \"") + formatstr + "\"");
      mout << " passed to Format";
      mout << display::getBracketedTypeName(x);
      mout << endl;
      mout << StyledString::get(HORLINE);
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
  //       sendval
  //---------------------------------------------------------------------------------

  template <typename T>
    inline void sendval(std::ostream &stream, const T& d) {
    stream << d;
  }

    
  
#define SPECIALIZE_mathtypes_sendval(TYPE)				\
  template <>								\
    inline void sendval<TYPE >(std::ostream &stream, const TYPE& d) {	\
    using namespace std;						\
    string sval = printf2str(FormatData<TYPE>::format_string.c_str(), d ); \
    Style style = FormatData<TYPE >::style_for_value;			\
    TYPE zero = 0;							\
    if (d == zero) {							\
      style = FormatData<TYPE >::style_for_zero;			\
    }									\
    stream << style.apply(sval);					\
  }
  

  SPECIALIZE_mathtypes_sendval(short);
  SPECIALIZE_mathtypes_sendval(int);
  SPECIALIZE_mathtypes_sendval(long);
  SPECIALIZE_mathtypes_sendval(long long);

  SPECIALIZE_mathtypes_sendval(unsigned short);
  SPECIALIZE_mathtypes_sendval(unsigned int);
  SPECIALIZE_mathtypes_sendval(unsigned long);
  SPECIALIZE_mathtypes_sendval(unsigned long long);



#define SPECIALIZE_floating_sendval(TYPE)				\
  template <>								\
    inline void sendval<TYPE >(std::ostream &stream, const TYPE& d) {				\
    using namespace std;						\
    string sval = printf2str(FormatData<TYPE>::format_string.c_str(), d ); \
    if (FormatData<TYPE>::tens)  {					\
      sval = replaceAll(sval,"E"," 10^");				\
      sval = replaceAll(sval,"e"," 10^");				\
    }									\
    Style style = FormatData<TYPE >::style_for_value;			\
    TYPE zero = 0;							\
    if (d == zero) {							\
      style = FormatData<TYPE >::style_for_zero;			\
    }									\
    stream << style.apply(sval);						\
  }
  
  SPECIALIZE_floating_sendval(float);
  SPECIALIZE_floating_sendval(double);
  SPECIALIZE_floating_sendval(long double);



  // string
  template <>							
    inline void sendval<std::string>(std::ostream &stream, const std::string& str) {	
    using namespace std;						
    string s = printf2str(FormatData<std::string>::format_string.c_str(), str.c_str() ); \
    Style style = FormatData<std::string>::style_for_value;		
    stream << style.apply(s);						
  }

  // char
  template <>							
    inline void sendval<char>(std::ostream &stream, const char& c) {			
    using namespace std;					
    string s = printf2str(FormatData<char>::format_string.c_str(), c ); \
    Style style = FormatData<char>::style_for_value;		
    stream << style.apply(s);					
  }


  // bool
  template <>				
    inline void sendval<bool>(std::ostream &stream, const bool& b) {
    using namespace std;
    if (b) {
      Style style = FormatData<bool>::style_for_true;
      string s = FormatData<bool>::string_for_true;
      stream << style.apply(s);
    } else {
      Style style = FormatData<bool>::style_for_false;
      string s = FormatData<bool>::string_for_false;
      stream << style.apply(s);
    }
  }
  

  // T[N]
  template <typename T,  size_t N>
    inline void sendval(std::ostream &stream, const T (&a)[N]) {
    stream << "{";
    for (size_t ii = 0; ii < N; ii++) {
      if (ii>0)  stream << ", ";
      sendval(stream, a[ii]);
    }
    stream << "}";
  }

  // char[N]
  template <size_t N>
    inline void sendval(std::ostream &stream, const char (&a)[N]) {
    stream << a;
  }


  // std::vector
  template <typename D>							
    inline void sendval(std::ostream &stream, const std::vector<D>& var) {
    stream << "{";
    for (size_t ii = 0; ii < var.size(); ii++) {
      if (ii>0)  stream << ", ";
      sendval(stream, var[ii]);
    }
    stream << "}";
  }

  // std::valarray
  template <typename D>							
    inline void sendval(std::ostream &stream, const std::valarray<D>& var) {
    stream << "{";
    for (size_t ii = 0; ii < var.size(); ii++) {
      if (ii>0)  stream << ", ";
      sendval(stream, var[ii]);
    }
    stream << "}";
  }


  // std::list
  template <typename D>							
    inline void sendval(std::ostream &stream, const std::list<D>& var) {
    stream << "{";
    size_t ii = 0;
    for(typename std::list<D>::const_iterator it = var.begin(); it != var.end(); ++it) {
      if (ii++>0)  stream << ", ";
      sendval(stream, *it);
    }
    stream << "}";
  }

  // std::initializer_list
#if CPP11 == 1
  template <typename D>							
    inline void sendval(std::ostream &stream, const std::initializer_list<D>& var) {
    stream << "{";
    size_t ii = 0;
    for(typename std::initializer_list<D>::const_iterator it = var.begin(); it != var.end(); ++it) {
      if (ii++>0)  stream << ", ";
      sendval(stream, *it);
    }
    stream << "}";
  }
#endif

  // std::queue
  template <typename D>							
    void sendval(std::ostream &stream, const std::queue<D>& var) {
    // ** We have to copy the queue to iterate through contents since this is a desrtuctive process
    std::queue<D> myq = var;
      
    stream << "{";
    const size_t N = myq.size();
    for (size_t ii = 0; ii < N; ii++) {
      if (ii>0)  stream << ", ";
      D val = myq.front();
      myq.pop();
      sendval(stream, val);
    }
    stream << "}";
  }

    
  // std::map
  template <typename D1, typename D2>					
    void sendval(std::ostream &stream, const std::map<D1,D2>& mymap) {
    stream << "{" << std::endl;
    for (typename std::map<D1,D2>::const_iterator it = mymap.begin(); it != mymap.end(); it++ ) {
      stream <<" "<< it->first << ":" << it->second << std::endl;
    }
    stream << "}";
  }


  
  //---------------------------------------------------------------------------------
  //       specialize for complex
  //---------------------------------------------------------------------------------

  class FormatDataComplex {
  public:
    static Style style_for_punctuation;
    static std::string format_string;  
    const static std::string format_string_default; 
  };


    

  inline bool checkFormatStringComplex(const std::string formatstr) {
    using namespace std;
    if (formatstr.empty()) {
      return false;
    }
    
    bool passed = true;
    string sr = string("%f");
    string si = string("%f");
    string s;
    try {
      s = printf2str(formatstr.c_str(), sr.c_str(), si.c_str());
    } catch (...) {
      passed = false;
    }
    size_t found = s.find("(nil)");
    if (found!=string::npos) 	passed = false;

    string formatfloats = s;
    float xreal = 3.1415;
    float ximag = 2.72;
    try {
      s = printf2str(formatfloats.c_str(), xreal, ximag);
    } catch (...) {
      passed = false;
    }
    found = s.find("(nil)");
    if (found!=string::npos) 	passed = false;

    
    //    printf("formatstr = %s\n",formatstr.c_str());
    //    printf("formatfloats = %s\n",formatfloats.c_str());

    float xreal2 = 3.1415;
    float ximag2 = 2.72;
    int ret = std::sscanf(s.c_str(), formatfloats.c_str() , &xreal2, &ximag2);
    //    printf("xreal2=%f ximag2=%f\n",xreal2,ximag2);
    if (ret != 2) passed = false;
    if (xreal2 != xreal)  passed = false;
    if (ximag2 != ximag)  passed = false;
    
    if (!passed) {
      mout << StyledString::get(HORLINE);
      mout << StyledString::get(ERROR);
      mout << " illegal format string";
      mout << createStyle(BOLD).apply(string(" \"") + formatstr + "\"");
      mout << " passed to setFormatStringComplex";
      mout << endl;
      mout << StyledString::get(HORLINE);
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
    void sendval(std::ostream &stream, const std::complex<D>& d) {
    using namespace std;
    using namespace matricks;

    // print the real and imaginary parts to strings
    string sr = printf2str(getFormatString<D>().c_str(), d.real() );
    string si = printf2str(getFormatString<D>().c_str(), d.imag() );

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
    stream << printf2str(fs.c_str(), sr.c_str(), si.c_str());
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
    //    mout << __PRETTY_FUNCTION__;
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
      //      log3("display","Display","initialize","()");
      
      Display::isInitialized = true;
      Display::expression = new StyledString(createStyle(BOLD),"");
      Display::equals = new StyledString(createStyle(GRAY1)," = ");
      Display::terminator = new StyledString(createStyle(GRAY1),"; ");
    }
    Display(){
      if (!isInitialized) {
	Display::initialize();
      }
    }

    // NOTE: do NOT try to combine mydisp_notype and mydisp_type
    //       this wil causes compilation failure if X.classname() does not
    //       exists, EVEN if you put getTypeName(x) inside an if clause
    
    template <typename X>
      static void mydisp_notype(std::ostream &stream, const X& x, const std::string name, const bool issueCR) {
      using namespace std;
      //      log3("display","Display","mydisp","(const X& x, const std::string name)");
      expression->setString(name);
      stream << *expression;
      stream << *equals;
      sendval(stream, x);
      stream << *terminator;
      if (issueCR) {
	stream << endl;
      }
    }
    template <typename X>
      static void mydisp(std::ostream &stream, const X& x, const std::string name) {
      using namespace std;
      mydisp_notype(stream, x, name, false);
    }
    template <typename X>
      static void mydispcr(std::ostream &stream, const X& x, const std::string name) {
      using namespace std;
      mydisp_notype(stream, x, name, true);
    }

    template <typename X>
      static void mydisp_type(std::ostream &stream, const X& x, const std::string name, const bool issueCR) {
      using namespace std;
      //      log3("display","Display","mydisp","(const X& x, const std::string name)");
      stream << getTypeName(x) << " ";
      expression->setString(name);
      stream << *expression;
      stream << *equals;
      sendval(stream, x);
      stream << *terminator;
      if (issueCR) {
	stream << endl;
      }
    }
    template <typename X>
      static void tmydisp(std::ostream &stream, const X& x, const std::string name) {
      using namespace std;
      mydisp_type(stream, x, name, false);
    }
    template <typename X>
      static void tmydispcr(std::ostream &stream, const X& x, const std::string name) {
      using namespace std;
      mydisp_type(stream, x, name, true);
    }

    static void issuecr(std::ostream &stream) {
      stream << std::endl;
    }
  };  // class Display


#define send(stream, ...) display::Display::mydispcr(stream, __VA_ARGS__, #__VA_ARGS__)
#define tsend(stream, ...) display::Display::tmydispcr(stream, __VA_ARGS__, #__VA_ARGS__)
#define sendcr(stream)  display::Display::issuecr(stream)

#define dispval(...) display::sendval(mout, __VA_ARGS__)
#define disp(...) display::Display::mydispcr(mout, __VA_ARGS__, #__VA_ARGS__)
#define tdisp(...) display::Display::tmydispcr(mout, __VA_ARGS__, #__VA_ARGS__)
#define cr()  display::Display::issuecr(mout)


  // for how this works, refer to
  //https://stackoverflow.com/questions/3046889/optional-parameters-with-c-macros
#define disp_0(stream)  display::Display::issuecr(stream)
#define disp_1(stream,A)  display::Display::mydisp(stream, A, #A)
#define disp_2(stream,A,B)   disp_1(stream,A);disp_1(stream,B)
#define disp_3(stream,A,B,C)  disp_1(stream,A);disp_1(stream,B);disp_1(stream,C)
#define disp_4(stream,A,B,C,D) disp_1(stream,A);disp_1(stream,B);disp_1(stream,C);disp_1(stream,D)
#define disp_5(stream,A,B,C,D,E) disp_1(stream,A);disp_1(stream,B);disp_1(stream,C);disp_1(stream,D);disp_1(stream,E)
#define disp_6(stream,A,B,C,D,E,F) disp_1(stream,A);disp_1(stream,B);disp_1(stream,C);disp_1(stream,D);disp_1(stream,E);disp_1(stream,F)
#define disp_7(stream,A,B,C,D,E,F,G) disp_1(stream,A);disp_1(stream,B);disp_1(stream,C);disp_1(stream,D);disp_1(stream,E);disp_1(stream,F);disp_1(stream,G)
#define disp_8(stream,A,B,C,D,E,F,G,H) disp_1(stream,A);disp_1(stream,B);disp_1(stream,C);disp_1(stream,D);disp_1(stream,E);disp_1(stream,F);disp_1(stream,G);disp_1(stream,H)
#define disp_9(stream,A,B,C,D,E,F,G,H,I) disp_1(stream,A);disp_1(stream,B);disp_1(stream,C);disp_1(stream,D);disp_1(stream,E);disp_1(stream,F);disp_1(stream,G);disp_1(stream,H);disp_1(stream,I)
#define disp_10(stream,A,B,C,D,E,F,G,H,I,J) disp_1(stream,A);disp_1(stream,B);disp_1(stream,C);disp_1(stream,D);disp_1(stream,E);disp_1(stream,F);disp_1(stream,G);disp_1(stream,H);disp_1(stream,I);disp_1(stream,J)

  // The interim macro that simply strips the excess and ends up with the required macro
#define mdisp_X(x,A,B,C,D,E,F,G,H,I,J,FUNC, ...)    FUNC;

  // The macro that the programmer uses 
#define mdisp(...)   mdisp_X(,##__VA_ARGS__, disp_10(mout,__VA_ARGS__), disp_9(mout,__VA_ARGS__), disp_8(mout,__VA_ARGS__), disp_7(mout,__VA_ARGS__), disp_6(mout,__VA_ARGS__), disp_5(mout,__VA_ARGS__), disp_4(mout,__VA_ARGS__), disp_3(mout,__VA_ARGS__), disp_2(mout,__VA_ARGS__), disp_1(mout,__VA_ARGS__), disp_0(mout)) 

#define msend(stream,...)   mdisp_X(,##__VA_ARGS__, disp_10(stream,__VA_ARGS__), disp_9(stream,__VA_ARGS__), disp_8(stream,__VA_ARGS__), disp_7(stream,__VA_ARGS__), disp_6(stream,__VA_ARGS__), disp_5(stream,__VA_ARGS__), disp_4(stream,__VA_ARGS__), disp_3(stream,__VA_ARGS__), disp_2(stream,__VA_ARGS__), disp_1(stream,__VA_ARGS__), disp_0(stream)) 




#if MATRICKS_DEBUG>=1
#define mdisp1(...) mdisp(__VA_ARGS__)
#define disp1(...) disp(__VA_ARGS__)
#define tdisp1(...) tdisp(__VA_ARGS__)
#else
#define mdisp1(...) {}
#define disp1(...) {}
#define tdisp1(...) {}
#endif

#if MATRICKS_DEBUG>=2
#define mdisp2(...) mdisp(__VA_ARGS__)
#define disp2(...) disp(__VA_ARGS__)
#define tdisp2(...) tdisp(__VA_ARGS__)
#else
#define mdisp2(...) {}
#define disp2(...) {}
#define tdisp2(...) {}
#endif

#if MATRICKS_DEBUG>=3
#define mdisp3(...) mdisp(__VA_ARGS__)
#define disp3(...) disp(__VA_ARGS__)
#define tdisp3(...) tdisp(__VA_ARGS__)
#else
#define mdisp3(...) {}
#define disp3(...) {}
#define tdisp3(...) {}
#endif




  
  //****************************************************************************
  //                       print_matricks_info
  //****************************************************************************


  inline void print_debug_level(void) {
    StyledString ss;
#if (MATRICKS_DEBUG==0)
    ss = StyledString::get(SSEnum::DLEVEL0);
#elif (MATRICKS_DEBUG==1)
    ss = StyledString::get(SSEnum::DLEVEL1);
#elif (MATRICKS_DEBUG==2)
    ss = StyledString::get(SSEnum::DLEVEL2);
#elif (MATRICKS_DEBUG>=3)
    ss = StyledString::get(SSEnum::DLEVEL3);
#endif
    mout << "  "<< ss << " " << std::endl;
  }


  inline void print_matricks_info(void) {
    using namespace std;
    using namespace display;
    mout << StyledString::get(HORLINE);
    mout << StyledString::get(MATRICKS) << " ";
    mout << StyledString::get(VERSION) << " ";
    mout << endl << endl;
    mout << "compile-time settings" << endl;
    print_debug_level();
    mout << createStyle(BOLD).apply("  C++ version: ");
    mout << createStyle(CYAN).apply(printf2str("%lu",__cplusplus)) << endl;
    mout << createStyle(BOLD).apply("  OPTIMIZE: ");
    mout << createStyle(CYAN).apply(string(COMPILE_OPTIMIZE)) << endl;
    mout << StyledString::get(HORLINE);
      
  }

    

  inline void set_default_format() {
    using namespace display;
    // TODO: include all default styles


    // TODO: put these into an intilization and share it here as well as in cpp file
    FormatDataVector::style_for_punctuation = createStyle(GRAY1);
    FormatDataVector::string_endofline = "\n";
    FormatDataVector::string_opening =  "{";
    FormatDataVector::string_delimeter = ",";
    FormatDataVector::max_elements_per_line = matricks::maxsize;
    FormatDataVector::string_closing =   "}";

    // TODO: put these into an intilization and share it here as well as in cpp file
    FormatDataMatrix::max_elements_per_line = matricks::maxsize;
    FormatDataMatrix::string_endofline = "\n";
    FormatDataMatrix::style_for_punctuation = createStyle(GRAY1);
    FormatDataMatrix::string_opening = "{";
    FormatDataMatrix::string_delimeter = ", ";
    FormatDataMatrix::string_row_opening = "{";
    FormatDataMatrix::string_row_closing = "}\n";
    FormatDataMatrix::string_closing = "}";

    
    setFormatStringComplex("(%s, %s)");

    FormatData<double>::format_string = FormatData<double>::format_string_default;
    FormatData<double>::tens = false;
    FormatData<float>::format_string = FormatData<float>::format_string_default;
    FormatData<long double>::format_string = FormatData<long double>::format_string_default;
    FormatData<short>::format_string = FormatData<short>::format_string_default;
    FormatData<int>::format_string = FormatData<int>::format_string_default;
    FormatData<long>::format_string = FormatData<long>::format_string_default;
    FormatData<unsigned short>::format_string = FormatData<unsigned short>::format_string_default;
    FormatData<unsigned int>::format_string = FormatData<unsigned int>::format_string_default;
    FormatData<unsigned long>::format_string = FormatData<unsigned long>::format_string_default;
    FormatData<char>::format_string = FormatData<char>::format_string_default;

    FormatData<std::string>::format_string = FormatData<std::string>::format_string_default;

    FormatData<bool>::string_for_true = "1";
    FormatData<bool>::string_for_false = "0";
    
  }

  inline void set_mathematica_var_format() {
    using namespace display;
    FormatDataVector::string_opening =  "{\n    ";
    FormatDataVector::string_delimeter = ", ";
    FormatDataVector::max_elements_per_line = 5;
    FormatDataVector::string_endofline = "\n    ";
    FormatDataVector::string_closing =   "\n}";
    setFormatString<double>("% 10.8e");
    setFormatStringComplex("%s + I*%s");
    FormatData<double>::tens = true;
  }


  inline void set_matlab_var_format() {
    using namespace display;
    FormatDataVector::string_opening =  "[ ...\n    ";
    FormatDataVector::string_delimeter = ", ";
    FormatDataVector::max_elements_per_line = 5;
    FormatDataVector::string_endofline = " ...\n    ";
    FormatDataVector::string_closing =   " ...\n]";
    setFormatString<double>("% 10.8e");
    setFormatStringComplex("%s + i*%s");
    FormatData<double>::tens = false;
  }
  
}; // namespace display


#endif
