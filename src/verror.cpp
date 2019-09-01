
#define MATRICKS_DEBUG 1

#include <sstream>
#include <iostream>
#include <string>

#include "matricks.h"





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


namespace matricks {


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
    std::cout << error_str << "index="<<i<<" out of bounds for obj#" << id << std::endl;
    MatricksObjectManager::outputGlossary(id);
  }

  void vbad_size(const size_type id, const size_type n) {
    std::cout << error_str <<  id << " size="<<n<<" is too large. Limits are: 0 <= size <= " << maxsize << std::endl;
    MatricksObjectManager::outputGlossary(id);
  }


  void mbad_vcast(const std::string s,  const size_type nr, const size_type nc,  const size_type N) {
    std::cout << error_str  << s<<std::endl;
    std::cout <<"vector(or expression) size="<<N<<"can not be cast to " << std::endl;
    std::cout << indent_str << nr<< "x"<<nc<<" matrix because sizes are not compatible" << std::endl;
  }


  void vbad_assignment(const size_type id1, const size_type id2) {
    std::string s1 = std::string("obj#");
    std::string s2 = std::string("obj#");
    std::cout << error_str << "vector assignment to vector of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    MatricksObjectManager::outputGlossary(id1);
    MatricksObjectManager::outputGlossary(id2);
  }


  void vbad_assignment_general_warning(const size_type id1, const size_type sz2, const std::string typeString) {
    //    std::string s1= MatricksObjectManager::vectorname(id1);
    using namespace std;
    string s1 = "";
    std::cout << warn_str << "vector assignment to "<<typeString<<" of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << typeString << std::endl;
    MatricksObjectManager::outputGlossary(id1);
    std::cout << indent_str  << "size of "<<typeString<<" = " << sz2  << std::endl;
  }


  void v_array_warning(const size_type id){
    std::string s1= std::string("obj#");
    std::cout << warn_str << "vector assignment to a C array always carries the risk of out of bounds access. Use C++11 list assignment instead." << std::endl;
    std::cout << indent_str  <<s1 << " = D[]" << std::endl;
    MatricksObjectManager::outputGlossary(id);
  }
      
  void vbad_assignment_warning(const size_type id1, const size_type id2) {
    std::string s1 = std::string("obj#");
    std::string s2 = std::string("obj#");
    std::cout << warn_str << "vector assignment to vector of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    MatricksObjectManager::outputGlossary(id1);
    MatricksObjectManager::outputGlossary(id2);
    std::cout << indent_str<< "Vector "<<s1<<" was resized accordingly."<<std::endl;
    std::cout << indent_str<< "To avoid this warning, explicitly resize using .resize(int) method"<<std::endl;
  }



  void vbadtype_assignment(const size_type id1, const size_type id2) {
    std::string s1 = std::string("obj#");
    std::string s2 = std::string("obj#");
    std::cout << warn_str << "vector assignment to vector of different data type" << std::endl;
    std::cout << indent_str << "use vcast<type>(v) function to avoid this warning" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    MatricksObjectManager::outputGlossary(id1);
    MatricksObjectManager::outputGlossary(id2);
  }


  void vbad_assignment_std(const size_type id1, const size_type sz2) {
    std::string s1 = std::string("obj#");
    std::string s2= "<vector>";
    std::cout << error_str << "vector assignment to std::vector of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    MatricksObjectManager::outputGlossary(id1);
    std::cout << where_str << "<vector> is std::vector" << "[size=" << sz2 << "]" << std::endl;
  }



  void vbad_assignment_mat(const size_type id1, const size_type NR, const size_type NC){ 
    std::string s1 = std::string("obj#");
    std::string s2= "matrix";
    std::cout << error_str << "vector assignment to matrix (expression) of incompatible size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    MatricksObjectManager::outputGlossary(id1);
    std::cout << where_str << "matrix is Matrix or Matrix expression" << 
      "[" << NR << "x" << NC << "]" << std::endl;
  }


  void vwrapper_out_of_bounds(const std::string& s1, const index_type i, const size_type sz) {
    std::cout << error_str << "out of bounds index="<<i<<" encountered during vector access"  << std::endl;
    std::cout << indent_str << s1 << std::endl;
    std::cout << where_str << s1 <<" has size="<<  sz << std::endl;
  }

  void vbad_wrapper_assignment(const std::string& s1, const std::string& s2) {
    std::cout << error_str << "vector subset assignment to vector (expression) of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
  }
  void vbad_wrapper_assignment_mat(const std::string& s1, const std::string& s2) {
    std::cout << error_str << "vector subset assignment to matrix (expression) of incompatible size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
  }




  std::string debugtxt_VSliceObj(const std::string s, const index_type start_,
				 const index_type end_,const  index_type step_){     
      std::ostringstream stream;
      stream <<s << "(start=" << start_ << ", end=" << end_ << ", step=" << step_ << ")";
      return stream.str();
  }
  void outputGlossary_VSliceObj(const size_type id, const std::string s, const size_type sz) { 
      std::cout << where_str << s <<" has size="<< sz << std::endl;
      MatricksObjectManager::outputGlossary(id);
  }


  std::string debugtxt_VSubsetObj(const std::string s1, const std::string s2){  
    return s1 +"[" + s2 + "]";   
  }
  void outputGlossary_VSubsetObj(const size_type id1, const size_type id2, const std::string s, const size_type sz) { 
      std::cout << where_str << s <<" has size="<< sz << std::endl;
      MatricksObjectManager::outputGlossary(id1);
      MatricksObjectManager::outputGlossary(id2);
  }

  std::string debugtxt_VSubMaskObj(const std::string s1, const std::string s2){  
    return s1 +"[" + s2 + "]";   
  }
  void outputGlossary_VSubMaskObj(const size_type id1, const size_type id2, const std::string s, const size_type sz) { 
      std::cout << where_str << s <<" has size="<< sz << std::endl;
      MatricksObjectManager::outputGlossary(id1);
      MatricksObjectManager::outputGlossary(id2);
  }
  void settext_VSubMaskObj(const Vector<index_type>& ii, const Vector<bool>& mask) {
    ii.debugtxt("("+mask.debugtxt()+")");
  }


};
