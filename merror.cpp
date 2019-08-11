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
#include "coollcommon.hpp"
#include "merror.hpp"

#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>

namespace COOLL {


  /****************************************************************************
   * Some Error-Checking and Error-Printing functions
   ****************************************************************************   
   */


  void mbad_input_stream_size(const std::string& name, const std::string& line, 
			      const unsigned int NR1, const unsigned int NC1,
			      const unsigned int NR2, const unsigned int NC2) {
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
				    const unsigned int N1, 
				    const unsigned int NR, const unsigned int NC) {
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
		     const unsigned int N1, 
		     const unsigned int NR, const unsigned int NC, 
		     const unsigned int Nlines, const unsigned int Nchars,
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
			 const unsigned int NR, const unsigned int NC, const unsigned int NCbad, 
			 const unsigned int Nlines, 
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


  bool mexpr_is_size_bad(const unsigned int sz) {
    // check for ill formed expression
    if ( sz == badsize ) { 
      return true;
    }
    return false;
  }

  void mbad_size(const unsigned int id,  const unsigned int nr, const unsigned int nc) {
    using namespace std;
    std::cout << error_str <<  CoollDirectory::matrixname(id) << " size="<<nr<<"x"<<nc<<"=";
    cout.precision(15);
    cout.setf(ios::fixed);
    std::cout << double(nr)*double(nc);
    std::cout <<" is too large. Limits are: 0 <= size <= " << maxsize << std::endl;
    CoollDirectory::moutputglossary(id);
  }

  void mbad_reshape(const unsigned int id,  const unsigned int nr, const unsigned int nc,  const unsigned int NR, const unsigned int NC) {
    using namespace std;
    std::cout << error_str <<  "Cannot reshape matrix "<<CoollDirectory::matrixname(id)<<std::endl;
    std::cout << indent_str << "The number of elements in the reshaped matrix ("<< nr<<"x"<<nc<<"=" <<nr*nc<<")"<<std::endl;
    std::cout <<indent_str<< "does not match the number of elements in the"<<std::endl;
    std::cout << indent_str<<"orginal matrix ("<< NR<<"x"<<NC<<"=" <<NR*NC<<")"<<std::endl;
    CoollDirectory::moutputglossary(id);
  }


  void mout_of_bounds(const unsigned int id, const unsigned int i) {
    std::cout << error_str << "single index access="<<i<<" out of bounds for " << CoollDirectory::matrixname(id) << std::endl;
    CoollDirectory::moutputglossary(id);
  }


  void mout_of_bounds2(const unsigned int id, const unsigned int r, const unsigned int c) {
    std::cout << error_str << "index=("<<r<<","<<c <<") out of bounds for " << CoollDirectory::matrixname(id) << std::endl;
    CoollDirectory::moutputglossary(id);
  }

  void mwrapper_out_of_bounds(const std::string& wSTR, 
			      const unsigned int aindex, const unsigned int wNR, 
			      const unsigned int wNC,  const unsigned int wSZ,
			      const unsigned int aID
			      ) {
    const std::string aSTR =  CoollDirectory::matrixname(aID);

    std::cout << error_str << "out of bounds access "; 
    std::cout <<aSTR<<"("<<aindex<<")"<< std::endl;
    std::cout <<indent_str<<"encountered in statement: " << wSTR << std::endl;
    std::cout << where_str << wSTR <<" has size="<<wNR<<"x"<<wNC<<"="<< wSZ << std::endl;
    CoollDirectory::moutputglossary(aID);
  }

  void mwrapper_out_of_bounds_rc(const std::string& wSTR, 
				 const unsigned int r,   const unsigned int c, 
				 const unsigned int wNR, const unsigned int wNC,  const unsigned int wSZ,
				 const unsigned int aID
				 ) {
    const std::string aSTR =  CoollDirectory::matrixname(aID);

    std::cout << error_str << "out of bounds access "; 
    std::cout <<aSTR<<"("<<r<<","<<c<<")"<< std::endl;
    std::cout <<indent_str<<"encountered in statement: " << wSTR << std::endl;
    std::cout << where_str << wSTR <<" has size="<<wNR<<"x"<<wNC<<"="<< wSZ << std::endl;
    CoollDirectory::moutputglossary(aID);
  }




  void mbad_assignment(const unsigned int id1, const unsigned int id2) {
    std::string s1= CoollDirectory::matrixname(id1);
    std::string s2= CoollDirectory::matrixname(id2);
    std::cout << error_str << "matrix assignment to matrix of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    CoollDirectory::moutputglossary(id1);
    CoollDirectory::moutputglossary(id2);
  }

  void mbad_assignment_warning(const unsigned int id1, const unsigned int id2) {
    std::string s1= CoollDirectory::matrixname(id1);
    std::string s2= CoollDirectory::matrixname(id2);
    std::cout << warn_str << "matrix assignment to matrix of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    CoollDirectory::moutputglossary(id1);
    CoollDirectory::moutputglossary(id2);
    std::cout << indent_str<< "Matrix "<<s1<<" was resized accordingly."<<std::endl;
    std::cout << indent_str<< "To avoid this warning, explicitly resize using .resize(int,int) method"<<std::endl;
  }

  void mbad_assignment_std(const unsigned int id1, const unsigned int sz2) {
    std::string s1= CoollDirectory::matrixname(id1);
    std::string s2= "<matrix>";
    std::cout << error_str << "matrix assignment to std::matrix of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    CoollDirectory::moutputglossary(id1);
    std::cout << where_str << "<matrix> is std::matrix" << "[size=" << sz2 << "]" << std::endl;
  }

  void mbad_wrapper_assignment(const std::string& s1, const std::string& s2) {
    std::cout << error_str << "matrix subset assignment to matrix (expression) of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
  }

  void mbad_wrapper_assignment_vec(const std::string& s1, const std::string& s2) {
    std::cout << error_str << "matrix subset assignment to vector (expression) of incompatible size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
  }


  void vbad_mcast(const std::string& s,  const unsigned int nr, const unsigned int nc,  const unsigned int N) {
    std::cout << error_str  << s<<std::endl;
    std::cout <<"matrix (expression) size="<<nr<<"x"<<nc<<"can not be cast to " << std::endl;
    std::cout << indent_str <<"size="<< N<<" vector because sizes are not compatible" << std::endl;
  }


  void mbad_submat( const unsigned int id, const unsigned int rstart, const unsigned int rend, 
		    const unsigned int cstart, const unsigned int cend) {
    std::string s= CoollDirectory::matrixname(id);
    std::ostringstream stream;
    std::cout << error_str << "bad submatrix indices given" << std::endl;
    if (rstart>rend) 
      std::cout << indent_str << "ending row cannot be smaller than starting row" << std::endl;
    if (cstart>cend)
      std::cout << indent_str << "ending col cannot be smaller than starting col" << std::endl;
    std::cout << indent_str << "use "<<s<<"(";
    std::cout << "seq(" << rstart << "," << rend <<"), seq(" << cstart << "," << cend << "))"<< std::endl;
    std::cout  << indent_str << "instead if this is what you intended"<< std::endl;
    std::cout <<indent_str << s << ".submat(" << rstart << "," << rend <<"," << cstart << "," << cend << ")";
    CoollDirectory::moutputglossary(id);
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
  std::string debugtxt_paren1b(const std::string& s1, const unsigned int id, const bool isvector){  
    std::string s2;
    if (isvector)
      s2 = CoollDirectory::vectorname(id);
    else
      s2 = CoollDirectory::matrixname(id);
    return s1 + "(" + s2+ ")";
  }
  std::string debugtxt_paren2(const std::string& s1, const std::string& s2, const std::string& s3){  
    return s1 + "(" + s2 +"," + s3+ ")";
  }
  std::string debugtxt_submat(const unsigned int id,  const unsigned int rstart, const unsigned int rend, 
			      const unsigned int cstart, const unsigned int cend) {
    std::string s= CoollDirectory::matrixname(id);
    std::ostringstream stream;
    stream << s << ".submat(" << rstart << "," << rend <<"," << cstart << "," << cend << ")";
    return stream.str();
  }




  void outputglossary_M1(const std::string& s,  const unsigned int nr, const unsigned int nc, const unsigned int sz) { 
    std::cout << where_str << s <<" has size="<<nr<<"x"<<nc<<"="<<  sz << std::endl;
  }
  


  void svd_bad_U(const unsigned int id,const unsigned int M) {
    std::string s1= CoollDirectory::matrixname(id);
    std::cout << warn_str << "'U' matrix ("<<s1<<") of SVD is not of proper size" << std::endl;
    CoollDirectory::moutputglossary(id);
    std::cout << indent_str << "resizing to "<<M<<"x"<<M << std::endl;
  }


  void svd_bad_S(const unsigned int id,const unsigned int minMN) {
    std::string s1= CoollDirectory::vectorname(id);
    std::cout << warn_str << "'S' vector ("<<s1<<") of SVD is not of proper size" << std::endl;
    CoollDirectory::voutputglossary(id);
    std::cout << indent_str << "resizing to size="<<minMN << std::endl;
  }

  void svd_bad_V(const unsigned int id,const unsigned int N) {
    std::string s1= CoollDirectory::matrixname(id);
    std::cout << warn_str << "'V' matrix ("<<s1<<") of SVD is not of proper size" << std::endl;
    CoollDirectory::moutputglossary(id);
    std::cout << indent_str << "resizing to "<<N<<"x"<<N << std::endl;
  }



};
