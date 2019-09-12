
#define MATRICKS_DEBUG 1

#include "matricks.h"
#include <unistd.h>



namespace matricks {

  
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
      
    // mout<< where_str << a->variableName << " is " << endl;
    // mout<< where_str << "obj:"<< id << " is: " << endl;
    // mout<< indent_str << "class name: "<< a->className << endl;
    // mout<< indent_str << "datatype name: "<< a->dataTypeName << endl;
    // mout<< indent_str << "variable name: "<< a->variableName << endl;
    // mout<< indent_str << "defined in function name: "<< a->functionName << endl;
    // mout<< indent_str << "           at line "<< a->lineNumber << " in file "<< 
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
    mout << warn_str << "Duplicate debug name \""<<name <<"\" requested for vector with ID="<<id<< std::endl;
    mout << indent_str << "The Name \""<<newname <<"\" was used instead"<< std::endl;
  }

  void mduplicate_name(const size_type id, const std::string& name, const std::string& newname) {
    mout << warn_str << "Duplicate debug name \""<<name <<"\" requested for matrix with ID="<<id<< std::endl;
    mout << indent_str << "The Name \""<<newname <<"\" was used instead"<< std::endl;
  }



  void cant_open_file(const std::string& name) {
    std::cerr << error_str<< "unable to open file '"<<name<<"'"<<std::endl;
    return;
  }	    


};
