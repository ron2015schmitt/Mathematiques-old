
#define MATRICKS_DEBUG 1

#include <unistd.h>

#include "matricks.h"




namespace matricks {

  // TODO: delete these
  const char* error_str =    "**mātricks ERROR: ";
  const char* warn_str =    "**mātricks warning: ";
  const char* indent_str  = "                 ";
  const char* where_str  =  "           where  ";
  const char* bug_str =     "**mātricks *BUG* : ";
};


namespace display {

  const char blankline[] = "                                                                               \n";
  char Buffer[BUFFER_SIZE];


  //****************************************************************************
  //                          Terminal
  //****************************************************************************

  
  bool Terminal::isInitialized = false;
  bool Terminal::supportsColor = false;
    
  bool Terminal::getSupportsColor() {
    if (!isInitialized) {
      supportsColor = ( isatty(STDOUT_FILENO) == 1 );
      isInitialized = true;
    }
    return supportsColor;
  }


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
    
  }


  //****************************************************************************
  //                       FormatData
  //****************************************************************************


  template <typename T>
  Style FormatData<T>::style_for_type_name = createStyle(CYAN);
  template <typename T>
  Style FormatData<T>::style_for_value = createStyle(ORANGE);

  //---------------------------------------------------------------------------------
  //       specialize for double
  //---------------------------------------------------------------------------------
  

  Style FormatData<double>::style_for_type_name = createStyle(MAGENTA);
  Style FormatData<double>::style_for_value = createStyle(RESET);
  Style FormatData<double>::style_for_zero = createStyle(GRAY1);
  const std::string FormatData<double>::format_string_default = "%lg";  // used for scanf so do NOT change
  std::string FormatData<double>::format_string = format_string_default;


  //---------------------------------------------------------------------------------
  //       specialize for complex<double>
  //---------------------------------------------------------------------------------

  Style FormatData<std::complex<double> >::style_for_type_name = createStyle(GREEN);
  Style FormatData<std::complex<double> >::style_for_punctuation = createStyle(GRAY1);
  const std::string FormatData<std::complex<double> >::format_string_default = "%s + i*%s";
  std::string FormatData<std::complex<double> >::format_string = format_string_default;
  
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
    cout << s << endl;
  }

  
  void Log::log(const int level, const std::string nspaceName, const std::string className, const std::string funcName, const std::string s) {
    using namespace std;
    switch(level) {
    case 0:
      cout << Log::style_log0.apply("log:");
      break;
    case 1:
      cout << Log::style_log1.apply("log1:");
      break;
    case 2:
      cout << Log::style_log2.apply("log2:");
      break;
    case 3:
      cout << Log::style_log3.apply("log3:");
      break;
    }
    cout << " in function ";
    cout << Log::style_nspace.apply(nspaceName);
    cout << "::";
    cout << Log::style_class.apply(className);
    cout << "::";
    cout << Log::style_func.apply(funcName);
    cout << Log::style_str.apply(s);
    cout << endl;
  };


  void Log::error(const std::string s){
    using namespace std;
    cout << StyledString::get(ERROR);
    cout << s;
    cout << endl;
  }
  void Log::warning(const std::string s){
    using namespace std;
    cout << StyledString::get(WARNING);
    cout << s;
    cout << endl;
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






