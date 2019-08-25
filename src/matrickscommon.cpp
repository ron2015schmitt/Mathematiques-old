
#define MATRICKS_DEBUG 1

#include "matricks.hpp"



namespace matricks {


  std::string  replaceAll(std::string  s, std::string s1, std::string s2) {
    size_t pos = s.find(s1);
    while( pos != std::string::npos) {
      s.replace(pos, s1.size(), s2);
      pos = s.find(s1, pos + s2.size());
    }
    return s;
  }


  const char* error_str =   "**matricks *ERROR*: ";
  const char* warn_str =    "**matricks warning: ";
  const char* indent_str  = "                 ";
  const char* where_str  =  "          where  ";
  const char* bug_str =     "**matricks  *BUG* : ";




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
    print2("slc::slc(start=%d, end=%d, step=%d)\n",start, end, step);
  }
  slc::slc(const index_type start, const index_type end) :
    start_(start), end_(end), 
    step_(1) {
    print2("slc::slc(start=%d, end=%d)\n",start, end);
  }
    
  index_type slc::start(void) const{ return start_;}
  index_type slc::end(void) const{ return end_;}
  index_type slc::step(void) const{ return step_;}

  Vector<index_type>& slc::toIndexVector(const size_type N) const {
    print2("slc::toIndexVector(N=%lu)\n",N);
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
#ifdef MATRICKS_DEBUG
    //      std::cout << where_str<< debugtxt() <<" has size=" <<size()<<std::endl;
#endif
  }

  std::string slc::debugtxt(void) const {
    std::ostringstream stream;
    stream <<  "slc(start=" << start_ << ", end=" << end_ << ", step=" << step_ << ")";
    return stream.str();
  }



};




