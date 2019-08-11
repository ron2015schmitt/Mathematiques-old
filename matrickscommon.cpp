
#include "matricks.hpp"



namespace Matricks {


  
  /****************************************************************************
   * error reporting string definitions
   ****************************************************************************   
   */



  const char* error_str =   "**Matricks *ERROR*: ";
  const char* warn_str =    "**Matricks warning: ";
  const char* indent_str  = "                 ";
  const char* where_str  =  "          where  ";
  const char* bug_str =     "**Matricks  *BUG* : ";

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




  // VECTOR DIRECTORY IMPLEMENTATIONS


  size_type MatricksObjectPool::NextVectorID_ = 1; 
  std::map<size_type,std::string> MatricksObjectPool::vectorName_ ; 
  std::map<size_type,std::string> MatricksObjectPool::vectorClass_ ; 
  std::map<size_type,std::string> MatricksObjectPool::vectorDatatype_ ; 
  std::map<size_type,size_type> MatricksObjectPool::vectorSize_ ; 

  size_type MatricksObjectPool::addvector(const std::string name, const std::string classname, 
			       const std::string datatype, const size_type size, const bool checkname) {
    size_type id = NextVectorID_++;
    
    vadd_name(name, id, checkname);
    
    vectorClass_[id] = classname;
    vectorDatatype_[id] = datatype;
    vectorSize_[id] = size;
    
    return id;
  }



  void MatricksObjectPool::removevector(const size_type id) {

    vectorName_.erase(id);
    vectorClass_.erase(id);
    vectorDatatype_.erase(id);
    vectorSize_.erase(id);

  }




  std::string MatricksObjectPool::vectorname(const size_type id) {
    return (vectorName_.find(id))->second;
  }


  std::string MatricksObjectPool::vadd_name(const std::string& name, const size_type id, const bool checkname) {

    std::string newname = name;

    if (newname == "") {
      std::ostringstream stream;
      stream << "Vector" << id;
      newname = stream.str();
    } else if (checkname) {
	
      std::string basename = newname;

      // name was given by user
      // check to see if name already exists
      static std::map<size_type,std::string>::iterator p; 
      p = vectorName_.begin();
      int i = 1;

#ifdef Matricks_CAREFUL
      bool dupe = false;
#endif     

      while (p != vectorName_.end()) {
	if (p->second == newname) {

#ifdef Matricks_CAREFUL
	  dupe = true;
#endif     
	  p = vectorName_.begin();
	  std::ostringstream stream;
	  stream << basename << "_" << ++i;
	  newname = stream.str();
	} else {
	  p++;
	}
      }
      
#ifdef Matricks_CAREFUL
      if (dupe) {
	vduplicate_name(id,name,newname);
      }
#endif     
    }

    vectorName_[id] = newname;
    return newname;
      
  }




  void MatricksObjectPool::vchange_name(const size_type id, const std::string& name, const bool checkname) {
    vectorName_.erase(id);
    vadd_name(name, id, checkname);
  }
  void MatricksObjectPool::vchange_size(const size_type id, const size_type size) {
    vectorSize_[id] = size;
  }



  void MatricksObjectPool::voutputglossary(const size_type id) {
    std::string s = where_str + vectorName_[id] + " is " + vectorClass_[id] + "<" + vectorDatatype_[id] + ">";
    std::cout << s << "[size=" << vectorSize_[id] << "], ID=" << id << std::endl;;
  }    


  // MATRIX IMPLEMENTATIONS


  size_type MatricksObjectPool::NextMatrixID_ = 1; 
  std::map<size_type,std::string> MatricksObjectPool::matrixName_ ; 
  std::map<size_type,std::string> MatricksObjectPool::matrixClass_ ; 
  std::map<size_type,std::string> MatricksObjectPool::matrixDatatype_ ; 
  std::map<size_type,size_type> MatricksObjectPool::matrixNrows_ ; 
  std::map<size_type,size_type> MatricksObjectPool::matrixNcols_ ; 

  size_type MatricksObjectPool::addmatrix(const std::string name, const std::string classname, 
			       const std::string datatype, const size_type NR, const size_type NC, const bool checkname) {
    size_type id = NextMatrixID_++;
    
    madd_name(name, id, checkname);
    
    matrixClass_[id] = classname;
    matrixDatatype_[id] = datatype;
    matrixNrows_[id] = NR;
    matrixNcols_[id] = NC;
    
    return id;
  }



  void MatricksObjectPool::removematrix(const size_type id) {

    matrixName_.erase(id);
    matrixClass_.erase(id);
    matrixDatatype_.erase(id);
    matrixNrows_.erase(id);
    matrixNcols_.erase(id);

  }




  std::string MatricksObjectPool::matrixname(const size_type id) {
    return (matrixName_.find(id))->second;
  }
  size_type MatricksObjectPool::matrixNrows(const size_type id) {
    return (matrixNrows_.find(id))->second;
  }
  size_type MatricksObjectPool::matrixNcols(const size_type id) {
    return (matrixNcols_.find(id))->second;
  }



  std::string MatricksObjectPool::madd_name(const std::string name, const size_type id, const bool checkname) {

    std::string newname = name;

    if (newname == "") {
      std::ostringstream stream;
      stream << "Matrix" << id;
      newname = stream.str();
    } else  if (checkname){
	
      std::string basename = newname;

      // name was given by user
      // check to see if name already exists
      static std::map<size_type,std::string>::iterator p; 
      p = matrixName_.begin();
      int i = 1;
#ifdef Matricks_CAREFUL
      bool dupe = false;
#endif     

      while (p != matrixName_.end()) {
	if (p->second == newname) {
#ifdef Matricks_CAREFUL
	  dupe = true;
#endif     


	  p = matrixName_.begin();
	  std::ostringstream stream;
	  stream << basename << "_" << ++i;
	  newname = stream.str();
	} else {
	  p++;
	}
      }

#ifdef Matricks_CAREFUL
      if (dupe) 
	mduplicate_name(id,name,newname);
#endif     
    }

    matrixName_[id] = newname;
    return newname;
      
  }

  void MatricksObjectPool::mchange_name(const size_type id, const std::string& name, const bool checkname) {
    matrixName_.erase(id);
    madd_name(name, id, checkname);
  }
  void MatricksObjectPool::mchange_size(const size_type id, const size_type NR, const size_type NC) {
    matrixNrows_[id] = NR;
    matrixNcols_[id] = NC;
  }




  void MatricksObjectPool::moutputglossary(const size_type id) {
    std::string s = where_str + matrixName_[id] + " is " + matrixClass_[id] + "<" + matrixDatatype_[id] + ">";
    std::cout << s << "[size=" << matrixNrows_[id] << "x" << matrixNcols_[id] << "], ID=" << id << std::endl;;
  }    




#define MTS_MACRO(T)  std::string make_type_string(T) {return std::string(# T); }

  MTS_MACRO(void);
  MTS_MACRO(float);
  MTS_MACRO(double);
  MTS_MACRO(long double);

  MTS_MACRO(bool);
  MTS_MACRO(char);
  MTS_MACRO(unsigned char);
  MTS_MACRO(signed char);

  MTS_MACRO(short);
  MTS_MACRO(unsigned short);
  MTS_MACRO(int);
  MTS_MACRO(unsigned int);
  MTS_MACRO(long);
  MTS_MACRO(unsigned long);
#if LONGLONG_EXISTS
  MTS_MACRO(long long);
  MTS_MACRO(unsigned long long);
#endif

  MTS_MACRO(std::string);

#define MTS_MACRO2(T)  std::string make_type_string(const T&) { return (std::string(# T)+" "); }

  MTS_MACRO2(std::complex<float>);
  MTS_MACRO2(std::complex<double>);
  MTS_MACRO2(std::complex<long double>);
  MTS_MACRO2(LAvector<float>);
  MTS_MACRO2(LAvector<double>);
  MTS_MACRO2(LAvector<long double>);
  MTS_MACRO2(LAvector<std::complex<double> >);
  MTS_MACRO2(LAvector<LAvector<double> >);
  MTS_MACRO2(LAvector<LAvector<std::complex<double> > >);
  MTS_MACRO2(Matrix<float>);
  MTS_MACRO2(Matrix<double>);
  MTS_MACRO2(Matrix<long double>);
  MTS_MACRO2(Matrix<std::complex<double> >);
  MTS_MACRO2(p3vector<float>);
  MTS_MACRO2(p3vector<double>);
  MTS_MACRO2(p3vector<long double>);
  MTS_MACRO2(p3vector<std::complex<double> >);


};


