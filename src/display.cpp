
#define MATRICKS_DEBUG 1


#include "matricks.h"






namespace display {
  
  const char blankline[] = "                                                                               \n";
  char Buffer[display::BUFFER_SIZE];
  
  
  //****************************************************************************
  //                          Terminal
  //****************************************************************************

  std::ostream* Terminal::outputstream;

  bool Terminal::isInitialized = false;
  bool Terminal::colorOverride = false;
  bool Terminal::overrideValue = false;
    

  Terminal Terminal_dummy = *(new Terminal());

  //****************************************************************************
  //                       Style
  //****************************************************************************
  

  Style& Style::create(const std::string stylestr, const std::string stylename) {
    return *( new Style(stylestr, stylename) );
  }



  //****************************************************************************
  //                       StyledString
  //****************************************************************************

  

  bool StyledString::isInitialized = false;
  std::map<SSEnum, StyledString> StyledString::Map = *(new std::map<SSEnum, StyledString>());
  void StyledString::add(const SSEnum sse, StyledString& styledString) {
    StyledString::Map.insert(std::pair<SSEnum, StyledString>(sse, styledString));
  }
  void StyledString::del(const SSEnum sse) {
    StyledString::Map.erase(sse);
  }
  StyledString& StyledString::get(const SSEnum sse) {
    return StyledString::Map[sse];
  }
  void StyledString::initialize() {
    StyledString::isInitialized = true;
    StyledString *indent = new StyledString(createStyle(RESET), "                     ");
    StyledString::add(SSEnum::INDENT, *indent);
    StyledString *error = new StyledString(createStyle(BOLD+RED),"** mātricks ERROR:   ");
    StyledString::add(SSEnum::ERROR, *error);;
    StyledString *warning = new StyledString(createStyle(BOLD+ORANGE),"** mātricks WARNING: ");
    StyledString::add(SSEnum::WARNING, *warning);
    StyledString *matricks = new StyledString(createStyle(BOLD+BLUE2),"mātricks");
    StyledString::add(SSEnum::MATRICKS, *matricks);
    StyledString *version = new StyledString(createStyle(BOLD+BLUE2),vers_matricks);
    StyledString::add(SSEnum::VERSION, *version);
    StyledString *dlevel0 = new StyledString(createStyle(BOLD+GREENBACK),"MATRICKS_DEBUG 0 (off/fast)");
    StyledString::add(SSEnum::DLEVEL0, *dlevel0);
    StyledString *dlevel1 = new StyledString(createStyle(BOLD+YELLOWBACK),"MATRICKS_DEBUG 1 (errors/warnings)");
    StyledString::add(SSEnum::DLEVEL1, *dlevel1);
    StyledString *dlevel2 = new StyledString(createStyle(BOLD+ORANGEBACK),"MATRICKS_DEBUG 2 (verbose)");
    StyledString::add(SSEnum::DLEVEL2, *dlevel2);
    StyledString *dlevel3 = new StyledString(createStyle(BOLD+REDBACK),"MATRICKS_DEBUG 3 (developer)");
    StyledString::add(SSEnum::DLEVEL3, *dlevel3);
    
#if (MATRICKS_DEBUG==0)
    StyledString::add(SSEnum::DEBUG_LEVEL, *dlevel0);
#elif (MATRICKS_DEBUG==1)
    StyledString::add(SSEnum::DEBUG_LEVEL, *dlevel1);
#elif (MATRICKS_DEBUG==2)
    StyledString::add(SSEnum::DEBUG_LEVEL, *dlevel2);
#elif (MATRICKS_DEBUG==3)
    StyledString::add(SSEnum::DEBUG_LEVEL, *dlevel3);
#endif

    StyledString *horline = new StyledString(createStyle(CROSSEDOUT),blankline);
    StyledString::add(SSEnum::HORLINE, *horline);
    StyledString *angle1 = new StyledString(createStyle(GRAY1),"<");
    StyledString::add(SSEnum::ANGLE1, *angle1);
    StyledString *angle2 = new StyledString(createStyle(GRAY1),">");
    StyledString::add(SSEnum::ANGLE2, *angle2);

    StyledString *paren1 = new StyledString(createStyle(GRAY1),"(");
    StyledString::add(SSEnum::PAREN1, *paren1);
    StyledString *paren2 = new StyledString(createStyle(GRAY1),")");
    StyledString::add(SSEnum::PAREN2, *paren2);

    StyledString *bracket1 = new StyledString(createStyle(GRAY1),"[");
    StyledString::add(SSEnum::BRACKET1, *bracket1);
    StyledString *bracket2 = new StyledString(createStyle(GRAY1),"]");
    StyledString::add(SSEnum::BRACKET2, *bracket2);

    StyledString *brace1 = new StyledString(createStyle(GRAY1),"{");
    StyledString::add(SSEnum::BRACE1, *brace1);
    StyledString *brace2 = new StyledString(createStyle(GRAY1),"}");
    StyledString::add(SSEnum::BRACE2, *brace2);

    StyledString *comma = new StyledString(createStyle(GRAY1),"{");
    StyledString::add(SSEnum::COMMA, *comma);

    StyledString *colon = new StyledString(createStyle(GRAY1),"{");
    StyledString::add(SSEnum::COLON, *colon);

    StyledString *semicolon = new StyledString(createStyle(GRAY1),"{");
    StyledString::add(SSEnum::SEMICOLON, *semicolon);

    StyledString *period = new StyledString(createStyle(GRAY1),"{");
    StyledString::add(SSEnum::PERIOD, *period);

    
  }


#define TypeClass_name(TYPE) template <> std::string TypeClass<TYPE>::name() {return #TYPE;}

  TypeClass_name(short);
  TypeClass_name(int);
  TypeClass_name(long);
  TypeClass_name(long long);

  TypeClass_name(unsigned short);
  TypeClass_name(unsigned int);
  TypeClass_name(unsigned long);
  TypeClass_name(unsigned long long);

  TypeClass_name(float);
  TypeClass_name(double);
  TypeClass_name(long double);

  TypeClass_name(std::string);
  TypeClass_name(bool);

  
  //****************************************************************************
  //                       FormatData
  //****************************************************************************



  //---------------------------------------------------------------------------------
  //       specialize
  // ** DO NOT CHANGE THE DEFAULT TYPE BECAUSE THESE ARE USED FOR SCANNING  **
  //------------------------------------------------------------------------------

  // float
  Style FormatData<float>::style_for_type_name = createStyle(MAGENTA);
  Style FormatData<float>::style_for_value = createStyle(BLACK);
  Style FormatData<float>::style_for_zero = createStyle(GRAY1);
  const std::string FormatData<float>::format_string_default = "%g";
  std::string FormatData<float>::format_string = format_string_default;
  bool FormatData<float>::tens = false;

  // double
  Style FormatData<double>::style_for_type_name = createStyle(MAGENTA);
  Style FormatData<double>::style_for_value = createStyle(BLACK);
  Style FormatData<double>::style_for_zero = createStyle(GRAY1);
  const std::string FormatData<double>::format_string_default = "%lg";
  std::string FormatData<double>::format_string = format_string_default;
  bool FormatData<double>::tens = false;

  
  // long double
  Style FormatData<long double>::style_for_type_name = createStyle(MAGENTA);
  Style FormatData<long double>::style_for_value = createStyle(BLACK);
  Style FormatData<long double>::style_for_zero = createStyle(GRAY1);
  const std::string FormatData<long double>::format_string_default = "%llg";
  std::string FormatData<long double>::format_string = format_string_default;
  bool FormatData<long double>::tens = false;

  // short
  Style FormatData<short>::style_for_type_name = createStyle(MAGENTA);
  Style FormatData<short>::style_for_value = createStyle(BLUE2);
  Style FormatData<short>::style_for_zero = createStyle(GRAY1);
  const std::string FormatData<short>::format_string_default = "%d";
  std::string FormatData<short>::format_string = format_string_default;

  // int
  Style FormatData<int>::style_for_type_name = createStyle(MAGENTA);
  Style FormatData<int>::style_for_value = createStyle(BLUE2);
  Style FormatData<int>::style_for_zero = createStyle(GRAY1);
  const std::string FormatData<int>::format_string_default = "%d";
  std::string FormatData<int>::format_string = format_string_default;

  // long
  Style FormatData<long>::style_for_type_name = createStyle(MAGENTA);
  Style FormatData<long>::style_for_value = createStyle(BLUE2);
  Style FormatData<long>::style_for_zero = createStyle(GRAY1);
  const std::string FormatData<long>::format_string_default = "%ld";
  std::string FormatData<long>::format_string = format_string_default;


#if LONGLONG_EXISTS
  // long long
  Style FormatData<long long>::style_for_type_name = createStyle(MAGENTA);
  Style FormatData<long long>::style_for_value = createStyle(BLUE2);
  Style FormatData<long long>::style_for_zero = createStyle(GRAY1);
  const std::string FormatData<long long>::format_string_default = "%lld";
  std::string FormatData<long long>::format_string = format_string_default;
#endif

  // unsigned short
  Style FormatData<unsigned short>::style_for_type_name = createStyle(MAGENTA);
  Style FormatData<unsigned short>::style_for_value = createStyle(VIOLET1);
  Style FormatData<unsigned short>::style_for_zero = createStyle(GRAY1);
  const std::string FormatData<unsigned short>::format_string_default = "%u";
  std::string FormatData<unsigned short>::format_string = format_string_default;

  // unsigned int
  Style FormatData<unsigned int>::style_for_type_name = createStyle(MAGENTA);
  Style FormatData<unsigned int>::style_for_value = createStyle(VIOLET1);
  Style FormatData<unsigned int>::style_for_zero = createStyle(GRAY1);
  const std::string FormatData<unsigned int>::format_string_default = "%u";
  std::string FormatData<unsigned int>::format_string = format_string_default;

  // unsigned long
  Style FormatData<unsigned long>::style_for_type_name = createStyle(MAGENTA);
  Style FormatData<unsigned long>::style_for_value = createStyle(VIOLET1);
  Style FormatData<unsigned long>::style_for_zero = createStyle(GRAY1);
  const std::string FormatData<unsigned long>::format_string_default = "%lu";
  std::string FormatData<unsigned long>::format_string = format_string_default;


#if LONGLONG_EXISTS
  // unsigned long long
  Style FormatData<unsigned long long>::style_for_type_name = createStyle(MAGENTA);
  Style FormatData<unsigned long long>::style_for_value = createStyle(VIOLET1);
  Style FormatData<unsigned long long>::style_for_zero = createStyle(GRAY1);
  const std::string FormatData<unsigned long long>::format_string_default = "%llu";
  std::string FormatData<unsigned long long>::format_string = format_string_default;
#endif


  // string
  Style FormatData<std::string>::style_for_type_name = createStyle(GREEN);
  Style FormatData<std::string>::style_for_value = createStyle(BLACK);
  const std::string FormatData<std::string>::format_string_default = "%s";
  std::string FormatData<std::string>::format_string = format_string_default;

  // char
  Style FormatData<char>::style_for_type_name = createStyle(MAGENTA);
  Style FormatData<char>::style_for_value = createStyle(BLACK);
  const std::string FormatData<char>::format_string_default = "%c";
  std::string FormatData<char>::format_string = format_string_default;


  // bool
  Style FormatData<bool>::style_for_type_name = createStyle(MAGENTA);
  Style FormatData<bool>::style_for_true = createStyle(GREEN1);
  Style FormatData<bool>::style_for_false = createStyle(GRAY1);
  std::string FormatData<bool>::string_for_true = "1";
  std::string FormatData<bool>::string_for_false = "0";


  // Vector
  matricks::index_type FormatDataVector::max_elements_per_line = matricks::maxsize;
  Style FormatDataVector::style_for_type_name = createStyle(CYAN);	    
  Style FormatDataVector::style_for_punctuation = createStyle(GRAY1);
  std::string FormatDataVector::string_opening = "{";
  std::string FormatDataVector::string_delimeter = ", ";
  std::string FormatDataVector::string_endofline = "\n";
  std::string FormatDataVector::string_closing = "}";

  //---------------------------------------------------------------------------------
  //       specialize for complex<double>
  //---------------------------------------------------------------------------------

  Style FormatDataComplex::style_for_type_name = createStyle(GREEN);
  Style FormatDataComplex::style_for_punctuation = createStyle(GRAY1);
  const std::string FormatDataComplex::format_string_default = "(%s,%s)";
  std::string FormatDataComplex::format_string = format_string_default;
  
  //****************************************************************************
  //                       Log
  //****************************************************************************

  Style Log::style_log0;
  Style Log::style_log1;
  Style Log::style_log2;
  Style Log::style_log3;
  Style Log::style_nspace;
  Style Log::style_class;
  Style Log::style_func;
  Style Log::style_str;
    
  Log::Log() {
    using namespace std;
    using namespace display;
    Log::style_log0 = createStyle(BOLD+BLUE1);
    Log::style_log1 = createStyle(BOLD+BLUE2);
    Log::style_log2 = createStyle(BOLD+BLUE3);
    Log::style_log3 = createStyle(BOLD+CYAN);
    Log::style_nspace =  createStyle(MAGENTA1);
    Log::style_class = createStyle(CYAN);
    Log::style_func =  createStyle(BLUE1);
    Log::style_str = createStyle(BLACK);
  };


  void Log::print(const int level, std::string s) {
    using namespace std;
    switch(level) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    }
    mout << s << endl;
  }

  
  void Log::log(const int level, const std::string nspaceName, const std::string className, const std::string funcName, const std::string s) {
    using namespace std;
    switch(level) {
    case 0:
      mout << Log::style_log0.apply("log:");
      break;
    case 1:
      mout << Log::style_log1.apply("log1:");
      break;
    case 2:
      mout << Log::style_log2.apply("log2:");
      break;
    case 3:
      mout << Log::style_log3.apply("log3:");
      break;
    }
    mout << " in function ";
    mout << Log::style_nspace.apply(nspaceName);
    mout << "::";
    mout << Log::style_class.apply(className);
    mout << "::";
    mout << Log::style_func.apply(funcName);
    mout << Log::style_str.apply(s);
    mout << endl;
  };


  void Log::error(const std::string s){
    using namespace std;
    mout << StyledString::get(ERROR);
    mout << s;
    mout << endl;
  }
  void Log::warning(const std::string s){
    using namespace std;
    mout << StyledString::get(WARNING);
    mout << s;
    mout << endl;
  }
  
  Log Log_dummy = *(new Log());


  
  //****************************************************************************
  //                       Display
  //****************************************************************************


  bool Display::isInitialized = false;
  StyledString* Display::expression = 0;
  StyledString* Display::equals = 0;
  StyledString* Display::terminator = 0;
  Display display_dummy = *(new Display());
  
  

};




