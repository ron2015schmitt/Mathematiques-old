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




#define COOLL_CAREFUL
#include "cooll.hpp"





namespace COOLL {


  
  /****************************************************************************
   * error reporting string definitions
   ****************************************************************************   
   */



  const char* error_str =   "**COOLL *ERROR*: ";
  const char* warn_str =    "**COOLL warning: ";
  const char* indent_str  = "                 ";
  const char* where_str  =  "          where  ";
  const char* bug_str =     "**COOLL  *BUG* : ";

  void bug_report(const std::string& fname,const unsigned int linenum) {
    std::cerr << bug_str<< "Bug occured in file '"<<fname<<"' at line #"<<linenum<<std::endl;
    std::cerr << indent_str<<"Sorry. Please report."<<std::endl<<std::endl;
    return;
  }


  void vduplicate_name(const unsigned int id, const std::string& name, const std::string& newname) {
    std::cout << warn_str << "Duplicate debug name \""<<name <<"\" requested for vector with ID="<<id<< std::endl;
    std::cout << indent_str << "The Name \""<<newname <<"\" was used instead"<< std::endl;
  }

  void mduplicate_name(const unsigned int id, const std::string& name, const std::string& newname) {
    std::cout << warn_str << "Duplicate debug name \""<<name <<"\" requested for matrix with ID="<<id<< std::endl;
    std::cout << indent_str << "The Name \""<<newname <<"\" was used instead"<< std::endl;
  }



  void cant_open_file(const std::string& name) {
    std::cerr << error_str<< "unable to open file '"<<name<<"'"<<std::endl;
    return;
  }	    




  // VECTOR DIRECTORY IMPLEMENTATIONS


  unsigned int CoollDirectory::NextVectorID_ = 1; 
  std::map<unsigned int,std::string> CoollDirectory::vectorName_ ; 
  std::map<unsigned int,std::string> CoollDirectory::vectorClass_ ; 
  std::map<unsigned int,std::string> CoollDirectory::vectorDatatype_ ; 
  std::map<unsigned int,unsigned int> CoollDirectory::vectorSize_ ; 

  unsigned int CoollDirectory::addvector(const std::string name, const std::string classname, 
			       const std::string datatype, const unsigned int size, const bool checkname) {
    unsigned int id = NextVectorID_++;
    
    vadd_name(name, id, checkname);
    
    vectorClass_[id] = classname;
    vectorDatatype_[id] = datatype;
    vectorSize_[id] = size;
    
    return id;
  }



  void CoollDirectory::removevector(const unsigned int id) {

    vectorName_.erase(id);
    vectorClass_.erase(id);
    vectorDatatype_.erase(id);
    vectorSize_.erase(id);

  }




  std::string CoollDirectory::vectorname(const unsigned int id) {
    return (vectorName_.find(id))->second;
  }


  std::string CoollDirectory::vadd_name(const std::string& name, const unsigned int id, const bool checkname) {

    std::string newname = name;

    if (newname == "") {
      std::ostringstream stream;
      stream << "Vector" << id;
      newname = stream.str();
    } else if (checkname) {
	
      std::string basename = newname;

      // name was given by user
      // check to see if name already exists
      static std::map<unsigned int,std::string>::iterator p; 
      p = vectorName_.begin();
      int i = 1;
      bool dupe = false;
      while (p != vectorName_.end()) {
	if (p->second == newname) {
	  dupe = true;
	  p = vectorName_.begin();
	  std::ostringstream stream;
	  stream << basename << "_" << ++i;
	  newname = stream.str();
	} else {
	  p++;
	}
      }
      
#ifdef COOLL_CAREFUL
      if (dupe) 
	vduplicate_name(id,name,newname);
#endif     
    }

    vectorName_[id] = newname;
    return newname;
      
  }




  void CoollDirectory::vchange_name(const unsigned int id, const std::string& name, const bool checkname) {
    vectorName_.erase(id);
    vadd_name(name, id, checkname);
  }
  void CoollDirectory::vchange_size(const unsigned int id, const unsigned int size) {
    vectorSize_[id] = size;
  }



  void CoollDirectory::voutputglossary(const unsigned int id) {
    std::string s = where_str + vectorName_[id] + " is " + vectorClass_[id] + "<" + vectorDatatype_[id] + ">";
    std::cout << s << "[size=" << vectorSize_[id] << "], ID=" << id << std::endl;;
  }    


  // MATRIX IMPLEMENTATIONS


  unsigned int CoollDirectory::NextMatrixID_ = 1; 
  std::map<unsigned int,std::string> CoollDirectory::matrixName_ ; 
  std::map<unsigned int,std::string> CoollDirectory::matrixClass_ ; 
  std::map<unsigned int,std::string> CoollDirectory::matrixDatatype_ ; 
  std::map<unsigned int,unsigned int> CoollDirectory::matrixNrows_ ; 
  std::map<unsigned int,unsigned int> CoollDirectory::matrixNcols_ ; 

  unsigned int CoollDirectory::addmatrix(const std::string name, const std::string classname, 
			       const std::string datatype, const unsigned int NR, const unsigned int NC, const bool checkname) {
    unsigned int id = NextMatrixID_++;
    
    madd_name(name, id, checkname);
    
    matrixClass_[id] = classname;
    matrixDatatype_[id] = datatype;
    matrixNrows_[id] = NR;
    matrixNcols_[id] = NC;
    
    return id;
  }



  void CoollDirectory::removematrix(const unsigned int id) {

    matrixName_.erase(id);
    matrixClass_.erase(id);
    matrixDatatype_.erase(id);
    matrixNrows_.erase(id);
    matrixNcols_.erase(id);

  }




  std::string CoollDirectory::matrixname(const unsigned int id) {
    return (matrixName_.find(id))->second;
  }
  unsigned int CoollDirectory::matrixNrows(const unsigned int id) {
    return (matrixNrows_.find(id))->second;
  }
  unsigned int CoollDirectory::matrixNcols(const unsigned int id) {
    return (matrixNcols_.find(id))->second;
  }



  std::string CoollDirectory::madd_name(const std::string name, const unsigned int id, const bool checkname) {

    std::string newname = name;

    if (newname == "") {
      std::ostringstream stream;
      stream << "Matrix" << id;
      newname = stream.str();
    } else  if (checkname){
	
      std::string basename = newname;

      // name was given by user
      // check to see if name already exists
      static std::map<unsigned int,std::string>::iterator p; 
      p = matrixName_.begin();
      int i = 1;
      bool dupe = false;
      while (p != matrixName_.end()) {
	if (p->second == newname) {
	  dupe = true;
	  p = matrixName_.begin();
	  std::ostringstream stream;
	  stream << basename << "_" << ++i;
	  newname = stream.str();
	} else {
	  p++;
	}
      }

#ifdef COOLL_CAREFUL
      if (dupe) 
	mduplicate_name(id,name,newname);
#endif     
    }

    matrixName_[id] = newname;
    return newname;
      
  }

  void CoollDirectory::mchange_name(const unsigned int id, const std::string& name, const bool checkname) {
    matrixName_.erase(id);
    madd_name(name, id, checkname);
  }
  void CoollDirectory::mchange_size(const unsigned int id, const unsigned int NR, const unsigned int NC) {
    matrixNrows_[id] = NR;
    matrixNcols_[id] = NC;
  }




  void CoollDirectory::moutputglossary(const unsigned int id) {
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


