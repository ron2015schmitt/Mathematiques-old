
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





  /****************************************************************************
   * Some Error-Checking and Error-Printing functions
   ****************************************************************************   
   */


  void mbad_input_stream_size(const std::string& name, const std::string& line, 
			      const size_type NR1, const size_type NC1,
			      const size_type NR2, const size_type NC2) {
    std::string xname = "";
    if (name.size()>0)
      xname = " '"+name+"' ";
    std::cerr << error_str<< "Matrix read from steam and"<<std::endl;
    std::cerr<< indent_str<< "destination Matrix are of different sizes."<<std::endl;
    std::cerr << indent_str<< "textformat = text_braces"<<std::endl;
    std::cerr << indent_str<< "Matrix from stream has size = "<<NR1<<"x"<<NC1<<std::endl;
    std::cerr << indent_str<< "destination matrix "<<xname<<" has size = "<<NR2<<"x"<<NC2<<std::endl;
    std::cerr << indent_str<< "last line of text in stream = "<<line<<std::endl;
    return;
  }

  void minput_stream_size_too_small(const std::string& name, const std::string& line, 
				    const size_type N1, 
				    const size_type NR, const size_type NC) {
    std::string xname = "";
    if (name.size()>0)
      xname = " '"+name+"' ";
    std::cerr << error_str<< "reached end of stream before reading enough "<<std::endl;
    std::cerr << indent_str<<"elements to fill Matrix."<<std::endl;
    std::cerr << indent_str<< "textformat = text_nobraces"<<std::endl;
    std::cerr << indent_str<< "number of elements read from stream = "<<N1<<std::endl;
    std::cerr << indent_str<< "destination Matrix"<<xname<<" has size = "<<NR<<"x"<<NC<<std::endl;
    std::cerr << indent_str<< "last line of text in stream = "<<line<<std::endl;
    return;
  }	    
  

  void msyntax_error(const std::string& name, const std::string& line, 
		     const size_type N1, 
		     const size_type NR, const size_type NC, 
		     const size_type Nlines, const size_type Nchars,
		     const char c, 
		     const std::string& info, TextFormat textformat) {
    std::string xname = "";
    if (name.size()>0)
      xname = " '"+name+"' ";
    std::string formatstring;
    std::cerr << error_str<< "Syntax error encountered while reading stream into Matrix"<<std::endl;
    if (info.size()>0)
      std::cerr << indent_str<<info<<std::endl;
    switch (textformat) {
    case text_nobraces:
      formatstring = "text_nobraces";
      break;
    case text_braces:
      formatstring = "text_braces";
      break;
    default:
      bug_report(__FILE__,__LINE__);
      break;
    }
    std::cerr << indent_str<< "textformat ="<<formatstring<<std::endl;
    std::cerr << indent_str<< "destination matrix"<<xname<<" has size = "<<NR<<"x"<<NC<<std::endl;
    std::cerr << indent_str<<N1<<" elements read from stream before error"<<std::endl;
    std::cerr << indent_str<< "error occured at character #"<<Nchars<<" ('"<<c<<"') "<<std::endl;
    std::cerr << indent_str << "in line #"<<Nlines<<": "<<std::endl;
    std::cerr << indent_str<< "'"<<line<< "'"<<std::endl;
    return;
  }	    


  void mcol_number_error(const std::string& name, const std::string& line, 
			 const size_type NR, const size_type NC, const size_type NCbad, 
			 const size_type Nlines, 
			 TextFormat textformat) {
    std::string xname = "";
    if (name.size()>0)
      xname = " '"+name+"' ";
    std::string formatstring;
    std::cerr << error_str<< "Error encountered while reading stream into Matrix"<<std::endl;
    switch (textformat) {
    case text_nobraces:
      formatstring = "text_nobraces";
      break;
    case text_braces:
      formatstring = "text_braces";
      break;
    default:
      bug_report(__FILE__,__LINE__);
      break;
    }
    std::cerr << indent_str<< "row #"<<NR<<" has "<<NCbad<<" columns ";
    std::cerr << "but previous rows had "<<NC<<" columns"<<std::endl;
    std::cerr << indent_str<< "textformat ="<<formatstring<<std::endl;
    std::cerr << indent_str << "error occured in line #"<<Nlines<<": "<<std::endl;
    std::cerr << indent_str<< "'"<<line<< "'"<<std::endl;
    return;
  }	    


  bool mexpr_is_size_bad(const size_type sz) {
    // check for ill formed expression
    if ( sz == badsize ) { 
      return true;
    }
    return false;
  }

  void mbad_size(const size_type id,  const size_type nr, const size_type nc) {
    using namespace std;
    mout << error_str <<  "matrix" << " size="<<nr<<"x"<<nc<<"=";
    mout.precision(15);
    mout.setf(ios::fixed);
    mout << double(nr)*double(nc);
    mout <<" is too large. Limits are: 0 <= size <= " << maxsize << std::endl;
    MatricksObjectManager::outputGlossary(id);
  }

  void mbad_reshape(const size_type id,  const size_type nr, const size_type nc,  const size_type NR, const size_type NC) {
    using namespace std;
    mout << error_str <<  "Cannot reshape matrix ";//<<MatricksObjectManager::matrixname(id)<<std::endl;
    mout << indent_str << "The number of elements in the reshaped matrix ("<< nr<<"x"<<nc<<"=" <<nr*nc<<")"<<std::endl;
    mout <<indent_str<< "does not match the number of elements in the"<<std::endl;
    mout << indent_str<<"orginal matrix ("<< NR<<"x"<<NC<<"=" <<NR*NC<<")"<<std::endl;
    MatricksObjectManager::outputGlossary(id);
  }


  void mout_of_bounds(const size_type id, const index_type i) {
    mout << error_str << "single index access="<<i<<" out of bounds for ";// << MatricksObjectManager::matrixname(id) << std::endl;
    MatricksObjectManager::outputGlossary(id);
  }


  void mout_of_bounds2(const size_type id, const index_type r, const index_type c) {
    mout << error_str << "index=("<<r<<","<<c <<") out of bounds for ";// << MatricksObjectManager::matrixname(id) << std::endl;
    MatricksObjectManager::outputGlossary(id);
  }

  void mwrapper_out_of_bounds(const std::string& wSTR, 
			      const index_type aindex, const size_type wNR, 
			      const size_type wNC,  const size_type wSZ,
			      const size_type aID
			      ) {
    const std::string aSTR = "";// MatricksObjectManager::matrixname(aID);

    mout << error_str << "out of bounds access "; 
    mout <<aSTR<<"("<<aindex<<")"<< std::endl;
    mout <<indent_str<<"encountered in statement: " << wSTR << std::endl;
    mout << where_str << wSTR <<" has size="<<wNR<<"x"<<wNC<<"="<< wSZ << std::endl;
    MatricksObjectManager::outputGlossary(aID);
  }

  void mwrapper_out_of_bounds_rc(const std::string& wSTR, 
				 const index_type r,   const index_type c, 
				 const size_type wNR, const size_type wNC,  const size_type wSZ,
				 const size_type aID
				 ) {
    const std::string aSTR = "";// MatricksObjectManager::matrixname(aID);

    mout << error_str << "out of bounds access "; 
    mout <<aSTR<<"("<<r<<","<<c<<")"<< std::endl;
    mout <<indent_str<<"encountered in statement: " << wSTR << std::endl;
    mout << where_str << wSTR <<" has size="<<wNR<<"x"<<wNC<<"="<< wSZ << std::endl;
    MatricksObjectManager::outputGlossary(aID);
  }




  void mbad_assignment(const size_type id1, const size_type id2) {
    //    std::string s1= MatricksObjectManager::matrixname(id1);
    //    std::string s2= MatricksObjectManager::matrixname(id2);
    std::string s1= "<matrix>";
    std::string s2= "<matrix>";

    mout << error_str << "matrix assignment to matrix of different size" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
    MatricksObjectManager::outputGlossary(id1);
    MatricksObjectManager::outputGlossary(id2);
  }

  void mbad_assignment_warning(const size_type id1, const size_type id2) {
    //    std::string s1= MatricksObjectManager::matrixname(id1);
    //    std::string s2= MatricksObjectManager::matrixname(id2);
    std::string s1= "<matrix>";
    std::string s2= "<matrix>";
    mout << warn_str << "matrix assignment to matrix of different size" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
    ///    MatricksObjectManager::moutputGlossary(id1);
    //    MatricksObjectManager::moutputGlossary(id2);
    mout << indent_str<< "Matrix "<<s1<<" was resized accordingly."<<std::endl;
    mout << indent_str<< "To avoid this warning, explicitly resize using .resize(int,int) method"<<std::endl;
  }

  void mbad_assignment_std(const size_type id1, const size_type sz2) {
    //    std::string s1= MatricksObjectManager::matrixname(id1);
    std::string s1= "<matrix>";
    std::string s2= "<matrix>";
    mout << error_str << "matrix assignment to std::matrix of different size" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
    //    MatricksObjectManager::moutputGlossary(id1);
    mout << where_str << "<matrix> is std::matrix" << "[size=" << sz2 << "]" << std::endl;
  }

  void mbad_wrapper_assignment(const std::string& s1, const std::string& s2) {
    mout << error_str << "matrix subset assignment to matrix (expression) of different size" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
  }

  void mbad_wrapper_assignment_vec(const std::string& s1, const std::string& s2) {
    mout << error_str << "matrix subset assignment to vector (expression) of incompatible size" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
  }


  void vbad_mcast(const std::string& s,  const size_type nr, const size_type nc,  const size_type N) {
    mout << error_str  << s<<std::endl;
    mout <<"matrix (expression) size="<<nr<<"x"<<nc<<"can not be cast to " << std::endl;
    mout << indent_str <<"size="<< N<<" vector because sizes are not compatible" << std::endl;
  }


  void mbad_submat( const size_type id, const index_type rstart, const index_type rend, 
		    const index_type cstart, const index_type cend) {
    //    std::string s= MatricksObjectManager::matrixname(id);
    std::string s = "<matrix>";
    std::ostringstream stream;
    mout << error_str << "bad submatrix indices given" << std::endl;
    if (rstart>rend) 
      mout << indent_str << "ending row cannot be smaller than starting row" << std::endl;
    if (cstart>cend)
      mout << indent_str << "ending col cannot be smaller than starting col" << std::endl;
    mout << indent_str << "use "<<s<<"(";
    mout << "slc(" << rstart << "," << rend <<"), slc(" << cstart << "," << cend << "))"<< std::endl;
    mout  << indent_str << "instead if this is what you intended"<< std::endl;
    mout <<indent_str << s << ".submat(" << rstart << "," << rend <<"," << cstart << "," << cend << ")";
    //    MatricksObjectManager::moutputGlossary(id);
  }

  



  std::string debugtxt_paren(const std::string& s, METypes mt){  
    if (mt == ME_Matrix) 
      return s ;
    else
      return "(" + s + ")";
  }
  std::string debugtxt_paren1(const std::string& s1, const std::string& s2){  
    return s1 + "(" + s2+ ")";
  }
  std::string debugtxt_paren1b(const std::string& s1, const size_type id, const bool isvector){  
    std::string s2 = "";
    // if (isvector)
    //   s2 = MatricksObjectManager::vectorname(id);
    // else
    //   s2 = MatricksObjectManager::matrixname(id);
    return s1 + "(" + s2+ ")";
  }
  std::string debugtxt_paren2(const std::string& s1, const std::string& s2, const std::string& s3){  
    return s1 + "(" + s2 +"," + s3+ ")";
  }
  std::string debugtxt_submat(const size_type id,  const index_type rstart, const index_type rend, 
			      const index_type cstart, const index_type cend) {
    std::string s= ""; //MatricksObjectManager::matrixname(id);
    std::ostringstream stream;
    stream << s << ".submat(" << rstart << "," << rend <<"," << cstart << "," << cend << ")";
    return stream.str();
  }




  void outputGlossary_M1(const std::string& s,  const size_type nr, const size_type nc, const size_type sz) { 
    mout << where_str << s <<" has size="<<nr<<"x"<<nc<<"="<<  sz << std::endl;
  }
  


  void svd_bad_U(const size_type id,const size_type M) {
    std::string s1=""; // MatricksObjectManager::matrixname(id);
    mout << warn_str << "'U' matrix ("<<s1<<") of SVD is not of proper size" << std::endl;
    //MatricksObjectManager::moutputGlossary(id);
    mout << indent_str << "resizing to "<<M<<"x"<<M << std::endl;
  }


  void svd_bad_S(const size_type id,const size_type minMN) {
    std::string s1="";//MatricksObjectManager::vectorname(id);
    mout << warn_str << "'S' vector ("<<s1<<") of SVD is not of proper size" << std::endl;
    //MatricksObjectManager::voutputGlossary(id);
    mout << indent_str << "resizing to size="<<minMN << std::endl;
  }

  void svd_bad_V(const size_type id,const size_type N) {
    std::string s1=""; // MatricksObjectManager::matrixname(id);
    mout << warn_str << "'V' matrix ("<<s1<<") of SVD is not of proper size" << std::endl;
    //MatricksObjectManager::moutputGlossary(id);
    mout << indent_str << "resizing to "<<N<<"x"<<N << std::endl;
  }







  /*
   * THE PROBLEM:  
   * Most of these functions could be templated. However, when they are templated
   * the compiler tries to inline them and it causes the optimizer to go through
   * fits.  This in turn causes user compilation time to increase by a factor of 
   * 3 to 10 times when in "DEBUG" mode!
   *
   * THE SOLUTION:
   * By creating actual compiled functions, the optimizer works on these 
   * functions separately and the compilation times are fast.
   * The result is not very elegant, but it works.
   * The best solution would be if C++ had a modifier that allowed one
   * to force a templated fucntion to be not inlined.
   */




  void vbad_input_stream_size(const std::string& name, const std::string& line, 
			      const size_type N1, const size_type N2) {
    std::string xname = "";
    if (name.size()>0)
      xname = " '"+name+"' ";
    std::cerr << error_str<< "size of input stream vector does not"<<std::endl;
    std::cerr<< indent_str<< "match destination vector size."<<std::endl;
    std::cerr << indent_str<< "textformat = text_braces"<<std::endl;
    std::cerr << indent_str<< "text vector has size = "<<N1<<std::endl;
    std::cerr << indent_str<< "destination vector"<<xname<<" has size = "<<N2<<std::endl;
    std::cerr << indent_str<< "last line of text in stream = "<<line<<std::endl;
    return;
  }	    

  void vinput_stream_size_too_small(const std::string& name, const std::string& line, 
				    const size_type N1, const size_type N2) {
    std::string xname = "";
    if (name.size()>0)
      xname = " '"+name+"' ";
    std::cerr << error_str<< "reached end of stream before reading enough "<<std::endl;
    std::cerr << indent_str<<"elements to fill vector."<<std::endl;
    std::cerr << indent_str<< "textformat = text_nobraces"<<std::endl;
    std::cerr << indent_str<< "text vector has size = "<<N1<<std::endl;
    std::cerr << indent_str<< "destination vector"<<xname<<" has size = "<<N2<<std::endl;
    std::cerr << indent_str<< "last line of text in stream = "<<line<<std::endl;
    return;
  }	    


  void vsyntax_error(const std::string& name, const std::string& line, 
		     const size_type N1, const size_type N2, 
		     const size_type Nlines, const size_type Nchars,
		     const char c, 
		     const std::string& info, TextFormat textformat) {
    std::string xname = "";
    if (name.size()>0)
      xname = " '"+name+"' ";
    std::string formatstring;
    std::cerr << error_str<< "Syntax error encountered while reading stream into vector"<<std::endl;
    if (info.size()>0)
      std::cerr << indent_str<<info<<std::endl;
    switch (textformat) {
    case text_nobraces:
      formatstring = "text_nobraces";
      break;
    case text_braces:
      formatstring = "text_braces";
      break;
    default:
      bug_report(__FILE__,__LINE__);
      break;
    }
    std::cerr << indent_str<< "textformat ="<<formatstring<<std::endl;
    std::cerr << indent_str<< "destination vector"<<xname<<" has size = "<<N2<<std::endl;
    std::cerr << indent_str<<N1<<" elements read from stream before error"<<std::endl;
    std::cerr << indent_str<< "error occured at character #"<<Nchars<<" ('"<<c<<"') "<<std::endl;
    std::cerr << indent_str << "in line #"<<Nlines<<": "<<std::endl;
    std::cerr << indent_str<< "'"<<line<< "'"<<std::endl;
    return;
  }	    



  /****************************************************************************
   * Some Error-Checking and Error-Printing functions
   ****************************************************************************   
   */







  void vout_of_bounds(const size_type id, const index_type i) {
    mout << error_str << "index="<<i<<" out of bounds for obj#" << id << std::endl;
    MatricksObjectManager::outputGlossary(id);
  }

  void vbad_size(const size_type id, const size_type n) {
    mout << error_str <<  id << " size="<<n<<" is too large. Limits are: 0 <= size <= " << maxsize << std::endl;
    MatricksObjectManager::outputGlossary(id);
  }


  void mbad_vcast(const std::string s,  const size_type nr, const size_type nc,  const size_type N) {
    mout << error_str  << s<<std::endl;
    mout <<"vector(or expression) size="<<N<<"can not be cast to " << std::endl;
    mout << indent_str << nr<< "x"<<nc<<" matrix because sizes are not compatible" << std::endl;
  }


  void vbad_assignment(const size_type id1, const size_type id2) {
    std::string s1 = std::string("obj#");
    std::string s2 = std::string("obj#");
    mout << error_str << "vector assignment to vector of different size" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
    MatricksObjectManager::outputGlossary(id1);
    MatricksObjectManager::outputGlossary(id2);
  }


  void vbad_assignment_general_warning(const size_type id1, const size_type sz2, const std::string typeString) {
    //    std::string s1= MatricksObjectManager::vectorname(id1);
    using namespace std;
    string s1 = "";
    mout << warn_str << "vector assignment to "<<typeString<<" of different size" << std::endl;
    mout << indent_str  <<s1 << "=" << typeString << std::endl;
    MatricksObjectManager::outputGlossary(id1);
    mout << indent_str  << "size of "<<typeString<<" = " << sz2  << std::endl;
  }


  void v_array_warning(const size_type id){
    std::string s1= std::string("obj#");
    mout << warn_str << "vector assignment to a C array always carries the risk of out of bounds access. Use C++11 list assignment instead." << std::endl;
    mout << indent_str  <<s1 << " = D[]" << std::endl;
    MatricksObjectManager::outputGlossary(id);
  }
      
  void vbad_assignment_warning(const size_type id1, const size_type id2) {
    std::string s1 = std::string("obj#");
    std::string s2 = std::string("obj#");
    mout << warn_str << "vector assignment to vector of different size" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
    MatricksObjectManager::outputGlossary(id1);
    MatricksObjectManager::outputGlossary(id2);
    mout << indent_str<< "Vector "<<s1<<" was resized accordingly."<<std::endl;
    mout << indent_str<< "To avoid this warning, explicitly resize using .resize(int) method"<<std::endl;
  }



  void vbadtype_assignment(const size_type id1, const size_type id2) {
    std::string s1 = std::string("obj#");
    std::string s2 = std::string("obj#");
    mout << warn_str << "vector assignment to vector of different data type" << std::endl;
    mout << indent_str << "use vcast<type>(v) function to avoid this warning" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
    MatricksObjectManager::outputGlossary(id1);
    MatricksObjectManager::outputGlossary(id2);
  }


  void vbad_assignment_std(const size_type id1, const size_type sz2) {
    std::string s1 = std::string("obj#");
    std::string s2= "<vector>";
    mout << error_str << "vector assignment to std::vector of different size" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
    MatricksObjectManager::outputGlossary(id1);
    mout << where_str << "<vector> is std::vector" << "[size=" << sz2 << "]" << std::endl;
  }



  void vbad_assignment_mat(const size_type id1, const size_type NR, const size_type NC){ 
    std::string s1 = std::string("obj#");
    std::string s2= "matrix";
    mout << error_str << "vector assignment to matrix (expression) of incompatible size" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
    MatricksObjectManager::outputGlossary(id1);
    mout << where_str << "matrix is Matrix or Matrix expression" << 
      "[" << NR << "x" << NC << "]" << std::endl;
  }


  void vwrapper_out_of_bounds(const std::string& s1, const index_type i, const size_type sz) {
    mout << error_str << "out of bounds index="<<i<<" encountered during vector access"  << std::endl;
    mout << indent_str << s1 << std::endl;
    mout << where_str << s1 <<" has size="<<  sz << std::endl;
  }

  void vbad_wrapper_assignment(const std::string& s1, const std::string& s2) {
    mout << error_str << "vector subset assignment to vector (expression) of different size" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
  }
  void vbad_wrapper_assignment_mat(const std::string& s1, const std::string& s2) {
    mout << error_str << "vector subset assignment to matrix (expression) of incompatible size" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
  }




  std::string debugtxt_VSliceObj(const std::string s, const index_type start_,
				 const index_type end_,const  index_type step_){     
    std::ostringstream stream;
    stream <<s << "(start=" << start_ << ", end=" << end_ << ", step=" << step_ << ")";
    return stream.str();
  }
  void outputGlossary_VSliceObj(const size_type id, const std::string s, const size_type sz) { 
    mout << where_str << s <<" has size="<< sz << std::endl;
    MatricksObjectManager::outputGlossary(id);
  }


  std::string debugtxt_VSubsetObj(const std::string s1, const std::string s2){  
    return s1 +"[" + s2 + "]";   
  }
  void outputGlossary_VSubsetObj(const size_type id1, const size_type id2, const std::string s, const size_type sz) { 
    mout << where_str << s <<" has size="<< sz << std::endl;
    MatricksObjectManager::outputGlossary(id1);
    MatricksObjectManager::outputGlossary(id2);
  }

  std::string debugtxt_VSubMaskObj(const std::string s1, const std::string s2){  
    return s1 +"[" + s2 + "]";   
  }
  void outputGlossary_VSubMaskObj(const size_type id1, const size_type id2, const std::string s, const size_type sz) { 
    mout << where_str << s <<" has size="<< sz << std::endl;
    MatricksObjectManager::outputGlossary(id1);
    MatricksObjectManager::outputGlossary(id2);
  }
  void settext_VSubMaskObj(const Vector<index_type>& ii, const Vector<bool>& mask) {
    ii.debugtxt("("+mask.debugtxt()+")");
  }


};
