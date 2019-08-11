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



#ifndef VERROR_H
#define VERROR_H 1

#include <sstream>
#include <iostream>
#include <string>

namespace COOLL {


  /****************************************************************************
   * Some Error-Checking and Error-Printing functions
   ****************************************************************************   
   */


  // These should always be compiled in



  void vbad_input_stream_size(const std::string& name, const std::string& line, 
			     const unsigned int N1, const unsigned int N2);

  void vinput_stream_size_too_small(const std::string& name, const std::string& line, 
				   const unsigned int N1, const unsigned int N2);

  void vsyntax_error(const std::string& name, const std::string& line, 
		     const unsigned int N1, const unsigned int N2, 
		     const unsigned int Nlines, const unsigned int Nchars, 
		     const char c,
		     const std::string& info, TextFormat textformat);

  //These are only used in CAREFUL mode
#ifdef COOLL_CAREFUL




  template <class D>
  void vbadrange(const D start, const D end, const D step) {
    std::cout << warn_str << "range vector of zero length created" << std::endl;
    std::cout << indent_str  << "(start,end,step) = ";
    std::cout << "(" << start << "," << end << "," << step <<")" << std::endl;
  }    


  template <class D>
  void vbadlinspace(const D start, const D end, const unsigned int N) {
    std::cout << error_str << "linspace requires N>=2" << std::endl;
    std::cout << indent_str  << "(start,end,N) = ";
    std::cout << "(" << start << "," << end << "," << N <<")" << std::endl;
  }    



 template <class D, class A> 
  void vbad_assignment_expr(const unsigned int id, const VorE<D,A>& ve) {
    std::string s1= CoollDirectory::vectorname(id);
    std::string s2= ve.debugtxt();
    std::cout << error_str << "vector assignment to expression of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    //    std::cout << where_str  << s2 << "has size="<<ve.size()<< std::endl;
    CoollDirectory::voutputglossary(id);
    ve.outputglossary();
  }
 template <class D, class A> 
  void vbad_assignment_expr_warning(const unsigned int id, const VorE<D,A>& ve) {
    std::string s1= CoollDirectory::vectorname(id);
    std::string s2= ve.debugtxt();
    std::cout << warn_str << "vector assignment to expression of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    //    std::cout << where_str  << s2 << "has size="<<ve.size()<< std::endl;
    CoollDirectory::voutputglossary(id);
    ve.outputglossary();
    std::cout << indent_str<< "Vector "<<s1<<" was resized accordingly."<<std::endl;
    std::cout << indent_str<< "To avoid this warning, explicitly resize using .resize(int) method"<<std::endl;
  }




   template <class D, class A> 
  void vbad_expr_in_assignment(const unsigned int id, const VorE<D,A>& ve) {
    std::string s1= CoollDirectory::vectorname(id);
    std::string s2= ve.debugtxt();
    std::cout << error_str << "expression formed between vectors of different sizes" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    CoollDirectory::voutputglossary(id);
    ve.outputglossary();
  }

   template <class D, class A> 
  void vbad_expr_in_reconassignment(const unsigned int id, const VorE<D,A>& ve) {
    std::string s1= CoollDirectory::vectorname(id);
    std::string s2= ve.debugtxt();
    std::cout << error_str << "expression formed between vectors of different sizes" << std::endl;
    std::cout << indent_str  <<s1 << ".resize() = " << s2 << std::endl;
    CoollDirectory::voutputglossary(id);
    ve.outputglossary();
  }


   template <class D, class A> 
   void vbad_reconassignment(const unsigned int id, const VorE<D,A>& ve) {
    std::string s1= CoollDirectory::vectorname(id);
    std::string s2= ve.debugtxt();
    std::cout << error_str << ".resize() objects are not permitted on the right hand side of an expression" << std::endl;
    std::cout << indent_str  <<s1 << " = " << s2<< ".resize()" << std::endl;
    CoollDirectory::voutputglossary(id);
    ve.outputglossary();
  }


   template <class D, class A> 
   void vbad_mask(const unsigned int id, const VorE<D,A>& ve) {
    std::string s1= CoollDirectory::vectorname(id);
    std::string s2= ve.debugtxt();
    std::cout << error_str << "mask size does not match vector size" << std::endl;
    std::cout << indent_str  <<s1 <<"[" <<s2<<"]"<< std::endl;
    CoollDirectory::voutputglossary(id);
    ve.outputglossary();
  }


   template <class D1, class D2, class A, class B> 
  void vbad_expr_in_binary(const VorE<D1,A>& ve1, const VorE<D2,B>& ve2, const char* fname, const char* seperator) {
    std::string s1= ve1.debugtxt();
    std::string s2= ve2.debugtxt();
    if (ve1.vetype() != VE_LAvector) 
      s1 = "(" + s1 + ")";
    if (ve2.vetype() != VE_LAvector) 
      s2 = "(" + s2 + ")";
    std::cout << error_str << "expression formed between vectors of different sizes" << std::endl;
    std::cout << indent_str << fname << "("  <<s1 << seperator << s2 << ")" <<std::endl;
    ve1.outputglossary();
    ve2.outputglossary();
  }


   template <class D, class A> 
  void vbad_expr_in_unary(const VorE<D,A>& ve, const char* fname) {
    std::string s1= ve.debugtxt();
    std::cout << error_str << "expression formed between vectors of different sizes" << std::endl;
    std::cout << indent_str << fname << "("  <<s1 << ")" <<std::endl;
    ve.outputglossary();
  }





  template <class D, class A> 
  inline bool vexpr_is_size_bad(const VorE<D,A>& ve) {

    // check for ill formed expression
    if ( ve.size() == badsize ) { 
      return true;
    }
    return false;
  }


  void vout_of_bounds(const unsigned int id, const unsigned int i);

  void vbad_size(const unsigned int id, const unsigned int n);

  void mbad_vcast(const std::string s,  const unsigned int nr, const unsigned int nc,  const unsigned int N);

  void vbad_assignment(const unsigned int id1, const unsigned int id2);
  void vbad_assignment_warning(const unsigned int id1, const unsigned int id2);

  void vbadtype_assignment(const unsigned int id1, const unsigned int id2);

  void vbad_assignment_mat(const unsigned int id1, const unsigned int NR, const unsigned int NC);

  void vbad_wrapper_assignment(const std::string& s1, const std::string& s2);

  void vbad_wrapper_assignment_mat(const std::string& s1, const std::string& s2);

  void vwrapper_out_of_bounds(const std::string& s1, const unsigned int i, const unsigned int sz);



  std::string debugtxt_VRangeObj(const std::string s, const unsigned int start_,
				 const unsigned int end_,const  int step_);
  void outputglossary_VRangeObj(const unsigned int id, const std::string s, const unsigned int sz);

  std::string debugtxt_VSetObj(const std::string s1, const std::string s2);
  void outputglossary_VSetObj(const unsigned int id1, const unsigned int id2, const std::string s, const unsigned int sz);

  std::string debugtxt_VMaskObj(const std::string s1, const std::string s2);
  void settext_VMaskObj(const LAvector<unsigned int>& ii,const  LAvector<bool>& mask);
  void outputglossary_VMaskObj(const unsigned int id1, const unsigned int id2, const std::string s, const unsigned int sz);





#endif


  


};
#endif
