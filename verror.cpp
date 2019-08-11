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


#include <sstream>
#include <iostream>
#include <string>



/*
 * THE PROBLEM:  
 * Most of these functions could be templated. However, when they are templated
 * the compiler tries to inline them and it causes the optimizer to go through
 * fits.  This in turn causes user compilation time to increase by a factor of 
 * 3 to 10 times when in "CAREFUL" mode!
 *
 * THE SOLUTION:
 * By creating actual compiled functions, the optimizer works on these 
 * functions separately and the compilation times are fast.
 * The result is not very elegant, but it works.
 * The best solution would be if C++ had a modifier that allowed one
 * to force a templated fucntion to be not inlined.
 */


namespace COOLL {


  void vbad_input_stream_size(const std::string& name, const std::string& line, 
			     const unsigned int N1, const unsigned int N2) {
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
				   const unsigned int N1, const unsigned int N2) {
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
		     const unsigned int N1, const unsigned int N2, 
		     const unsigned int Nlines, const unsigned int Nchars,
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







  void vout_of_bounds(const unsigned int id, const unsigned int i) {
    std::cout << error_str << "index="<<i<<" out of bounds for " << CoollDirectory::vectorname(id) << std::endl;
    CoollDirectory::voutputglossary(id);
  }

  void vbad_size(const unsigned int id, const unsigned int n) {
    std::cout << error_str <<  CoollDirectory::vectorname(id) << " size="<<n<<" is too large. Limits are: 0 <= size <= " << maxsize << std::endl;
    CoollDirectory::voutputglossary(id);
  }


  void mbad_vcast(const std::string s,  const unsigned int nr, const unsigned int nc,  const unsigned int N) {
    std::cout << error_str  << s<<std::endl;
    std::cout <<"vector(or expression) size="<<N<<"can not be cast to " << std::endl;
    std::cout << indent_str << nr<< "x"<<nc<<" matrix because sizes are not compatible" << std::endl;
  }


  void vbad_assignment(const unsigned int id1, const unsigned int id2) {
    std::string s1= CoollDirectory::vectorname(id1);
    std::string s2= CoollDirectory::vectorname(id2);
    std::cout << error_str << "vector assignment to vector of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    CoollDirectory::voutputglossary(id1);
    CoollDirectory::voutputglossary(id2);
  }

  void vbad_assignment_warning(const unsigned int id1, const unsigned int id2) {
    std::string s1= CoollDirectory::vectorname(id1);
    std::string s2= CoollDirectory::vectorname(id2);
    std::cout << warn_str << "vector assignment to vector of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    CoollDirectory::voutputglossary(id1);
    CoollDirectory::voutputglossary(id2);
    std::cout << indent_str<< "Vector "<<s1<<" was resized accordingly."<<std::endl;
    std::cout << indent_str<< "To avoid this warning, explicitly resize using .resize(int) method"<<std::endl;
  }



  void vbadtype_assignment(const unsigned int id1, const unsigned int id2) {
    std::string s1= CoollDirectory::vectorname(id1);
    std::string s2= CoollDirectory::vectorname(id2);
    std::cout << warn_str << "vector assignment to vector of different data type" << std::endl;
    std::cout << indent_str << "use vcast<type>(v) function to avoid this warning" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    CoollDirectory::voutputglossary(id1);
    CoollDirectory::voutputglossary(id2);
  }


  void vbad_assignment_std(const unsigned int id1, const unsigned  int sz2) {
    std::string s1= CoollDirectory::vectorname(id1);
    std::string s2= "<vector>";
    std::cout << error_str << "vector assignment to std::vector of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    CoollDirectory::voutputglossary(id1);
    std::cout << where_str << "<vector> is std::vector" << "[size=" << sz2 << "]" << std::endl;
  }



  void vbad_assignment_mat(const unsigned int id1, const unsigned int NR, const unsigned int NC){
    std::string s1= CoollDirectory::vectorname(id1);
    std::string s2= "matrix";
    std::cout << error_str << "vector assignment to matrix (expression) of incompatible size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    CoollDirectory::voutputglossary(id1);
    std::cout << where_str << "matrix is Matrix or Matrix expression" << 
      "[" << NR << "x" << NC << "]" << std::endl;
  }


  void vwrapper_out_of_bounds(const std::string& s1, const unsigned int i, const unsigned int sz) {
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




  std::string debugtxt_VRangeObj(const std::string s, const unsigned int start_,
				 const unsigned int end_,const  int step_){     
      std::ostringstream stream;
      stream <<s << "(start=" << start_ << ", end=" << end_ << ", step=" << step_ << ")";
      return stream.str();
  }
  void outputglossary_VRangeObj(const unsigned int id, const std::string s, const unsigned int sz) { 
      std::cout << where_str << s <<" has size="<< sz << std::endl;
      CoollDirectory::voutputglossary(id);
  }


  std::string debugtxt_VSetObj(const std::string s1, const std::string s2){  
    return s1 +"[" + s2 + "]";   
  }
  void outputglossary_VSetObj(const unsigned int id1, const unsigned int id2, const std::string s, const unsigned int sz) { 
      std::cout << where_str << s <<" has size="<< sz << std::endl;
      CoollDirectory::voutputglossary(id1);
      CoollDirectory::voutputglossary(id2);
  }

  std::string debugtxt_VMaskObj(const std::string s1, const std::string s2){  
    return s1 +"[" + s2 + "]";   
  }
  void outputglossary_VMaskObj(const unsigned int id1, const unsigned int id2, const std::string s, const unsigned int sz) { 
      std::cout << where_str << s <<" has size="<< sz << std::endl;
      CoollDirectory::voutputglossary(id1);
      CoollDirectory::voutputglossary(id2);
  }
  void settext_VMaskObj(const LAvector<unsigned int>& ii, const LAvector<bool>& mask) {
    ii.debugtxt("("+mask.debugtxt()+")");
  }


};
