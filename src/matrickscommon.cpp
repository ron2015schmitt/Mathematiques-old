
#define MATRICKS_DEBUG 3

#include "matricks.hpp"
#include <unistd.h>

namespace display {

  const char blankline[] = "                                                                               \n";
  char Buffer[BUFFER_SIZE];
  
  bool Terminal::isInitialized = false;
  bool Terminal::supportsColor = false;
    
  bool Terminal::getSupportsColor() {
    if (!isInitialized) {
      supportsColor = ( isatty(STDOUT_FILENO) == 1 );
      isInitialized = true;
    }
    return supportsColor;
  }


  Style& Style::create(const std::string stylestr, const std::string stylename) {
    return *( new Style(stylestr, stylename) );
  }





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




  

  Style Log::style_log0;
  Style Log::style_log1;
  Style Log::style_log2;
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
      cout << Log::style_log2.apply("log3:");
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


  bool Display::isInitialized = false;
  StyledString* Display::expression = 0;
  StyledString* Display::equals = 0;
  StyledString* Display::terminator = 0;
  Display display_dummy = *(new Display());
  
  

};


namespace matricks {


  std::string  replaceAll(std::string  s, std::string s1, std::string s2) {
    size_t pos = s.find(s1);
    while( pos != std::string::npos) {
      s.replace(pos, s1.size(), s2);
      pos = s.find(s1, pos + s2.size());
    }
    return s;
  }


  // TODO: delete these
  const char* error_str =    "**mātricks ERROR: ";
  const char* warn_str =    "**mātricks warning: ";
  const char* indent_str  = "                 ";
  const char* where_str  =  "           where  ";
  const char* bug_str =     "**mātricks *BUG* : ";




  
  // VECTOR DIRECTORY IMPLEMENTATIONS


  class ObjectInfo {
  public:
    AnyIF& object;
    std::string className;
    std::string dataTypeName;
    std::string variableName;
    std::string functionName;
    size_type lineNumber;
    std::string fileName;
    ObjectInfo(AnyIF& obj) : object(obj) {}
  };


  size_type MatricksObjectManager::NextObjectID_ = 1; 
  std::map<size_type, ObjectInfo* > MatricksObjectManager::objectPool;
  

  size_type MatricksObjectManager::addObject(AnyIF& obj) {
    size_type id = NextObjectID_++;
    ObjectInfo* infoptr = new ObjectInfo(obj);
    objectPool.at(id) = infoptr;
    
  }
  // size_type MatricksObjectManager::addObject(
  // 					     //const std::unique_ptr<VariableWrapperInterface> > obj,
  // 					     const std::string variableName,
  // 					     const std::string functionName,
  // 					     const size_type lineNumber,
  // 					     const std::string fileName
  // 					     ) {
  //   size_type id = NextObjectID_++;
  //   ObjectInfo  *myAttrs = new ObjectInfo();
  //   myAttrs->className = "ClassName";
  //   myAttrs->dataTypeName = "D";
  //   myAttrs->variableName = variableName;
  //   myAttrs->functionName = functionName;
  //   myAttrs->lineNumber = lineNumber;
  //   myAttrs->fileName = fileName;

  //   attributePool[id]= myAttrs;
  //   //    objectPool_.add(id, obj);

  //   return id;
  // }


  ObjectInfo* MatricksObjectManager::getObjectInfo(const size_type id) {
    std::map<size_type, ObjectInfo* >::iterator it = objectPool.find(id);
    if (it != objectPool.end()) {
      return objectPool[id];
    } else {
      return 0;
    }
  }

  void MatricksObjectManager::removeObject(const size_type id) {
    ObjectInfo* ptr = getObjectInfo(id);
    if (ptr != 0) {
      objectPool.erase(id);
      delete ptr;
    }
  }

  void MatricksObjectManager::outputGlossary(const size_type id) {
      
    // cout<< where_str << a->variableName << " is " << endl;
    // cout<< where_str << "obj:"<< id << " is: " << endl;
    // cout<< indent_str << "class name: "<< a->className << endl;
    // cout<< indent_str << "datatype name: "<< a->dataTypeName << endl;
    // cout<< indent_str << "variable name: "<< a->variableName << endl;
    // cout<< indent_str << "defined in function name: "<< a->functionName << endl;
    // cout<< indent_str << "           at line "<< a->lineNumber << " in file "<< 
    //  a->fileName << endl;
    
  }    




  
  /****************************************************************************
   * error reporting string definitions
   ****************************************************************************   
   */




  void bug_report(const std::string& fname,const size_type linenum) {
    std::cerr << bug_str<< "Bug occured in file '"<<fname<<"' at line #"<<linenum<<std::endl;
    std::cerr << indent_str<<"Sorry. Please report."<<std::endl<<std::endl;
    return;
  }


  void vduplicate_name(const size_type id, const std::string& name, const std::string& newname) {
    std::cout << warn_str << "Duplicate debug name \""<<name <<"\" requested for vector with ID="<<id<< std::endl;
    std::cout << indent_str << "The Name \""<<newname <<"\" was used instead"<< std::endl;
  }

  void mduplicate_name(const size_type id, const std::string& name, const std::string& newname) {
    std::cout << warn_str << "Duplicate debug name \""<<name <<"\" requested for matrix with ID="<<id<< std::endl;
    std::cout << indent_str << "The Name \""<<newname <<"\" was used instead"<< std::endl;
  }



  void cant_open_file(const std::string& name) {
    std::cerr << error_str<< "unable to open file '"<<name<<"'"<<std::endl;
    return;
  }	    














  /****************************************************************************
   * slice class -- for accessing subsets of vectors/matrices 
   ****************************************************************************
   */
  slc::slc(const index_type start, const index_type end, const index_type step) :
    start_(start), end_(end), 
    step_(step) {
    printf2("slc::slc(start=%d, end=%d, step=%d)\n",start, end, step);
  }
  slc::slc(const index_type start, const index_type end) :
    start_(start), end_(end), 
    step_(1) {
    printf2("slc::slc(start=%d, end=%d)\n",start, end);
  }
    
  index_type slc::start(void) const{ return start_;}
  index_type slc::end(void) const{ return end_;}
  index_type slc::step(void) const{ return step_;}

  Vector<index_type>& slc::toIndexVector(const size_type N) const {
    printf2("slc::toIndexVector(N=%lu)\n",N);
    index_type mystart = start_;
    if (mystart < 0) {
      mystart += N;
    }
    index_type myend = end_;
    if (myend < 0) {
      myend += N;
    }

    index_type mystep = step_;

    std::queue<index_type> indices;
	
    if (myend-mystart >= 0) {
      if (mystep > 0) {
	for (index_type k = mystart; k <= myend; k += mystep){
	  if (k < 0) continue;
	  if (k >= N) break;
	  indices.push(k);
	}
      }
    } else {
      if (mystep < 0) {
	for (index_type k = mystart; k >= myend; k += mystep){
	  if (k >= N) continue;
	  if (k < 0)  break;
	  indices.push(k);
	}
      }
    }
    
    const size_type Nnew = indices.size();
    Vector<index_type> &indexvec = *(new Vector<index_type>(Nnew));
    for (register index_type i = 0; i < Nnew ; i++ ) {
      indexvec[i] = indices.front();
      indices.pop();
    }
      
    return indexvec;
  }

  void slc::outputglossary(void) const {
#if MATRICKS_DEBUG>0
    //      std::cout << where_str<< debugtxt() <<" has size=" <<size()<<std::endl;
#endif
  }

  std::string slc::debugtxt(void) const {
    std::ostringstream stream;
    stream <<  "slc(start=" << start_ << ", end=" << end_ << ", step=" << step_ << ")";
    return stream.str();
  }



};




