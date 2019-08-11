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



#ifndef MERROR_H
#define MERROR_H 1

#include <sstream>
#include <iostream>
#include <string>

namespace COOLL {

  void mbad_input_stream_size(const std::string& name, const std::string& line, 
			      const unsigned int NR1, const unsigned int NC1,
			      const unsigned int NR2, const unsigned int NC2);

  void minput_stream_size_too_small(const std::string& name, const std::string& line, 
				    const unsigned int N1, 
				    const unsigned int NR, const unsigned int NC);
  void msyntax_error(const std::string& name, const std::string& line, 
		     const unsigned int N1, 
		     const unsigned int NR, const unsigned int NC, 
		     const unsigned int Nlines, const unsigned int Nchars,
		     const char c, 
		    const std::string& info, TextFormat textformat);

  void mcol_number_error(const std::string& name, const std::string& line, 
			 const unsigned int NR, const unsigned int NC, const unsigned int NCbad, 
			 const unsigned int Nlines, 
			 TextFormat textformat);


  /****************************************************************************
   * Some Error-Checking and Error-Printing functions
   ****************************************************************************   
   */


#ifdef COOLL_CAREFUL







  template <class D, class A> 
  void mbad_assignment_expr(const unsigned int id, const MorE<D,A>& me) {
    std::string s1= CoollDirectory::matrixname(id);
    std::string s2= me.debugtxt();
    std::cout << error_str << "matrix assignment to expression of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    CoollDirectory::moutputglossary(id);
    me.outputglossary();
  }


  template <class D, class A> 
  void mbad_assignment_expr_warning(const unsigned int id, const MorE<D,A>& me) {
    std::string s1= CoollDirectory::matrixname(id);
    std::string s2= me.debugtxt();
    std::cout << warn_str << "matrix assignment to expression of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    CoollDirectory::moutputglossary(id);
    me.outputglossary();
    std::cout << indent_str<< "Matrix "<<s1<<" was resized accordingly."<<std::endl;
    std::cout << indent_str<< "To avoid this warning, explicitly resize using .resize(int,int) method"<<std::endl;
  }

  template <class D, class A> 
  void mbad_expr_in_assignment(const unsigned int id, const MorE<D,A>& me) {
    std::string s1= CoollDirectory::matrixname(id);
    std::string s2= me.debugtxt();
    std::cout << error_str << "expression formed between matrices of different sizes" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    CoollDirectory::moutputglossary(id);
    me.outputglossary();
  }


   template <class D, class A> 
  void mbad_expr_in_reconassignment(const unsigned int id, const MorE<D,A>& me) {
    std::string s1= CoollDirectory::matrixname(id);
    std::string s2= me.debugtxt();
    std::cout << error_str << "expression formed between matrices of different sizes" << std::endl;
    std::cout << indent_str  <<s1 << ".resize() = " << s2 << std::endl;
    CoollDirectory::moutputglossary(id);
    me.outputglossary();
  }


  template <class D1, class D2, class A, class B> 
  void mbad_expr_in_binary(const MorE<D1,A>& me1, const MorE<D2,B>& me2, const char* fname, const char* seperator) {
    std::string s1= me1.debugtxt();
    std::string s2= me2.debugtxt();
    if (me1.metype() != ME_Matrix) 
      s1 = "(" + s1 + ")";
    if (me2.metype() != ME_Matrix) 
      s2 = "(" + s2 + ")";
    std::cout << error_str << "expression formed between matrices of different sizes" << std::endl;
    std::cout << indent_str << fname << "("  <<s1 << seperator << s2 << ")" <<std::endl;
    me1.outputglossary();
    me2.outputglossary();
  }




  template <class D1,class D2, class A, class B> 
  void mbad_dot_product(const MorE<D1,A>& me1, const MorE<D2,B>& me2) {
    std::string s1= me1.debugtxt();
    std::string s2= me2.debugtxt();
    if (me1.metype() != ME_Matrix) 
      s1 = "(" + s1 + ")";
    if (me2.metype() != ME_Matrix) 
      s2 = "(" + s2 + ")";
    std::cout << error_str << "dot product formed between incompatibly-sized matrices" << std::endl;
    std::cout << indent_str  << "("  <<s1 << "|" << s2 << ")" <<std::endl;
    me1.outputglossary();
    me2.outputglossary();
  }


  template <class D1,class D2, class A, class B> 
  void mvbad_dot_product(const MorE<D1,A>& me1, const VorE<D2,B>& ve2) {
    std::string s1= me1.debugtxt();
    std::string s2= ve2.debugtxt();
    if (me1.metype() != ME_Matrix) 
      s1 = "(" + s1 + ")";
    if (ve2.vetype() != VE_LAvector) 
      s2 = "(" + s2 + ")";
    std::cout << error_str << "dot product formed between incompatibly-sized objects" << std::endl;
    std::cout << indent_str  << "("  <<s1 << "|" << s2 << ")" <<std::endl;
    me1.outputglossary();
    ve2.outputglossary();
  }


  template <class D1,class D2, class A, class B> 
  void vmbad_dot_product(const VorE<D1,A>& ve1, const MorE<D2,B>& me2) {
    std::string s1= ve1.debugtxt();
    std::string s2= me2.debugtxt();
    if (ve1.vetype() != VE_LAvector) 
      s1 = "(" + s1 + ")";
    if (me2.metype() != ME_Matrix) 
      s2 = "(" + s2 + ")";
    std::cout << error_str << "dot product formed between incompatibly-sized objects" << std::endl;
    std::cout << indent_str  << "("  <<s1 << "|" << s2 << ")" <<std::endl;
    ve1.outputglossary();
    me2.outputglossary();
  }



  template <class D, class A> 
  void mbad_expr_in_unary(const MorE<D,A>& me, const char* fname) {
    std::string s1= me.debugtxt();
    std::cout << error_str << "expression formed between matrices of different sizes" << std::endl;
    std::cout << indent_str << fname << "("  <<s1 << ")" <<std::endl;
    me.outputglossary();
  }



  bool mexpr_is_size_bad(const unsigned int sz);



  template <class D, class A> 
   void mbad_subsmatrix(const unsigned int id, const MorE<D,A>& me) {
    std::string s1= CoollDirectory::matrixname(id);
    std::string s2= me.debugtxt();
    std::cout << error_str << "subscript matrices must have exactly 2 columns" << std::endl;
    std::cout << indent_str  <<"Matrix "<<s2<<" is not of this form"<< std::endl;
    std::cout << indent_str  <<s1 <<"[" <<s2<<"]"<< std::endl;
    CoollDirectory::moutputglossary(id);
    me.outputglossary();
  }


  template <class D, class A> 
   void mbad_mask(const unsigned int id, const MorE<D,A>& me) {
    std::string s1= CoollDirectory::matrixname(id);
    std::string s2= me.debugtxt();
    std::cout << error_str << "mask size does not match maxtrix size" << std::endl;
    std::cout << indent_str  <<s1 <<"[" <<s2<<"]"<< std::endl;
    CoollDirectory::moutputglossary(id);
    me.outputglossary();
  }

  
  template <class D, class A> 
   void mbad_maskv(const unsigned int id, const VorE<D,A>& ve) {
    std::string s1= CoollDirectory::matrixname(id);
    std::string s2= ve.debugtxt();
    std::cout << error_str << "mask size does not match maxtrix size" << std::endl;
    std::cout << indent_str  <<s1 <<"[" <<s2<<"]"<< std::endl;
    CoollDirectory::moutputglossary(id);
    ve.outputglossary();
  }

   template <class D, class A> 
   void mbad_reconassignment(const unsigned int id, const MorE<D,A>& me) {
    std::string s1= CoollDirectory::matrixname(id);
    std::string s2= me.debugtxt();
    std::cout << error_str << ".resize() objects are not permitted on the right hand side of an expression" << std::endl;
    std::cout << indent_str  <<s1 << " = " << s2 << std::endl;
    CoollDirectory::moutputglossary(id);
    me.outputglossary();
  }


  

  void mbad_reshape(const unsigned int id,  const unsigned int nr, const unsigned int nc,  const unsigned int NR, const unsigned int NC);
  void mout_of_bounds(const unsigned int id, const unsigned int i);


  void mout_of_bounds2(const unsigned int id, const unsigned int r, const unsigned int c);

  void mwrapper_out_of_bounds(const std::string& wSTR, 
			      const unsigned int aindex, const unsigned int wNR, 
			      const unsigned int wNC,  const unsigned int wSZ,
			      const unsigned int aID
			      );
  void mwrapper_out_of_bounds_rc(const std::string& wSTR, 
				 const unsigned int r,   const unsigned int c, 
				 const unsigned int wNR, const unsigned int wNC,  const unsigned int wSZ,
				 const unsigned int aID
				 );
  void mbad_assignment(const unsigned int id1, const unsigned int id2);

  void mbad_assignment_warning(const unsigned int id1, const unsigned int id2);

  void mbad_assignment_std(const unsigned int id1, const unsigned int sz2);

  void mbad_wrapper_assignment(const std::string& s1, const std::string& s2);

  void mbad_wrapper_assignment_vec(const std::string& s1, const std::string& s2);

  void mbad_size(const unsigned int id,  const unsigned int nr, const unsigned int nc);

  void vbad_mcast(const std::string& s,  const unsigned int nr, const unsigned int nc,  const unsigned int N);

  void mbad_submat( const unsigned int id, const unsigned int rstart, const unsigned int rend, 
		    const unsigned int cstart, const unsigned int cend);


  std::string debugtxt_paren(const std::string& s, METypes mt);
  std::string debugtxt_paren1(const std::string& s1, const std::string& s2);
  std::string debugtxt_paren1b(const std::string& s1, const unsigned int id, const bool isvector);
  std::string debugtxt_paren2(const std::string& s1, const std::string& s2, const std::string& s3);
  std::string debugtxt_submat(const unsigned int id,  const unsigned int rstart, const unsigned int rend, 
			      const unsigned int cstart, const unsigned int cend);
  void outputglossary_M1(const std::string& s,  const unsigned int nr, const unsigned int nc, const unsigned int sz);


  void svd_bad_U(const unsigned int id,const unsigned int M);
  void svd_bad_S(const unsigned int id,const unsigned int minMN);
  void svd_bad_V(const unsigned int id,const unsigned int N);



#endif


  


};
#endif
