

#ifndef MERROR_H
#define MERROR_H

#include <sstream>
#include <iostream>
#include <string>

namespace Matricks {

  void mbad_input_stream_size(const std::string& name, const std::string& line, 
			      const size_type NR1, const size_type NC1,
			      const size_type NR2, const size_type NC2);

  void minput_stream_size_too_small(const std::string& name, const std::string& line, 
				    const size_type N1, 
				    const size_type NR, const size_type NC);
  void msyntax_error(const std::string& name, const std::string& line, 
		     const size_type N1, 
		     const size_type NR, const size_type NC, 
		     const size_type Nlines, const size_type Nchars,
		     const char c, 
		    const std::string& info, TextFormat textformat);

  void mcol_number_error(const std::string& name, const std::string& line, 
			 const size_type NR, const size_type NC, const size_type NCbad, 
			 const size_type Nlines, 
			 TextFormat textformat);


  /****************************************************************************
   * Some Error-Checking and Error-Printing functions
   ****************************************************************************   
   */


#ifdef Matricks_CAREFUL







  template <class D, class A> 
  void mbad_assignment_expr(const size_type id, const MorE<D,A>& me) {
    std::string s1= MatricksObjectPool::matrixname(id);
    std::string s2= me.debugtxt();
    std::cout << error_str << "matrix assignment to expression of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    MatricksObjectPool::moutputglossary(id);
    me.outputglossary();
  }


  template <class D, class A> 
  void mbad_assignment_expr_warning(const size_type id, const MorE<D,A>& me) {
    std::string s1= MatricksObjectPool::matrixname(id);
    std::string s2= me.debugtxt();
    std::cout << warn_str << "matrix assignment to expression of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    MatricksObjectPool::moutputglossary(id);
    me.outputglossary();
    std::cout << indent_str<< "Matrix "<<s1<<" was resized accordingly."<<std::endl;
    std::cout << indent_str<< "To avoid this warning, explicitly resize using .resize(int,int) method"<<std::endl;
  }

  template <class D, class A> 
  void mbad_expr_in_assignment(const size_type id, const MorE<D,A>& me) {
    std::string s1= MatricksObjectPool::matrixname(id);
    std::string s2= me.debugtxt();
    std::cout << error_str << "expression formed between matrices of different sizes" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    MatricksObjectPool::moutputglossary(id);
    me.outputglossary();
  }


   template <class D, class A> 
  void mbad_expr_in_reconassignment(const size_type id, const MorE<D,A>& me) {
    std::string s1= MatricksObjectPool::matrixname(id);
    std::string s2= me.debugtxt();
    std::cout << error_str << "expression formed between matrices of different sizes" << std::endl;
    std::cout << indent_str  <<s1 << ".resize() = " << s2 << std::endl;
    MatricksObjectPool::moutputglossary(id);
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
    if (ve2.vetype() != VE_Vector) 
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
    if (ve1.vetype() != VE_Vector) 
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



  bool mexpr_is_size_bad(const size_type sz);



  template <class D, class A> 
   void mbad_subsmatrix(const size_type id, const MorE<D,A>& me) {
    std::string s1= MatricksObjectPool::matrixname(id);
    std::string s2= me.debugtxt();
    std::cout << error_str << "subscript matrices must have exactly 2 columns" << std::endl;
    std::cout << indent_str  <<"Matrix "<<s2<<" is not of this form"<< std::endl;
    std::cout << indent_str  <<s1 <<"[" <<s2<<"]"<< std::endl;
    MatricksObjectPool::moutputglossary(id);
    me.outputglossary();
  }


  template <class D, class A> 
   void mbad_mask(const size_type id, const MorE<D,A>& me) {
    std::string s1= MatricksObjectPool::matrixname(id);
    std::string s2= me.debugtxt();
    std::cout << error_str << "mask size does not match maxtrix size" << std::endl;
    std::cout << indent_str  <<s1 <<"[" <<s2<<"]"<< std::endl;
    MatricksObjectPool::moutputglossary(id);
    me.outputglossary();
  }

  
  template <class D, class A> 
   void mbad_maskv(const size_type id, const VorE<D,A>& ve) {
    std::string s1= MatricksObjectPool::matrixname(id);
    std::string s2= ve.debugtxt();
    std::cout << error_str << "mask size does not match maxtrix size" << std::endl;
    std::cout << indent_str  <<s1 <<"[" <<s2<<"]"<< std::endl;
    MatricksObjectPool::moutputglossary(id);
    ve.outputglossary();
  }

   template <class D, class A> 
   void mbad_reconassignment(const size_type id, const MorE<D,A>& me) {
    std::string s1= MatricksObjectPool::matrixname(id);
    std::string s2= me.debugtxt();
    std::cout << error_str << ".resize() objects are not permitted on the right hand side of an expression" << std::endl;
    std::cout << indent_str  <<s1 << " = " << s2 << std::endl;
    MatricksObjectPool::moutputglossary(id);
    me.outputglossary();
  }


  

  void mbad_reshape(const size_type id,  const size_type nr, const size_type nc,  const size_type NR, const size_type NC);
  void mout_of_bounds(const size_type id, const size_type i);


  void mout_of_bounds2(const size_type id, const size_type r, const size_type c);

  void mwrapper_out_of_bounds(const std::string& wSTR, 
			      const size_type aindex, const size_type wNR, 
			      const size_type wNC,  const size_type wSZ,
			      const size_type aID
			      );
  void mwrapper_out_of_bounds_rc(const std::string& wSTR, 
				 const size_type r,   const size_type c, 
				 const size_type wNR, const size_type wNC,  const size_type wSZ,
				 const size_type aID
				 );
  void mbad_assignment(const size_type id1, const size_type id2);

  void mbad_assignment_warning(const size_type id1, const size_type id2);

  void mbad_assignment_std(const size_type id1, const size_type sz2);

  void mbad_wrapper_assignment(const std::string& s1, const std::string& s2);

  void mbad_wrapper_assignment_vec(const std::string& s1, const std::string& s2);

  void mbad_size(const size_type id,  const size_type nr, const size_type nc);

  void vbad_mcast(const std::string& s,  const size_type nr, const size_type nc,  const size_type N);

  void mbad_submat( const size_type id, const size_type rstart, const size_type rend, 
		    const size_type cstart, const size_type cend);


  std::string debugtxt_paren(const std::string& s, METypes mt);
  std::string debugtxt_paren1(const std::string& s1, const std::string& s2);
  std::string debugtxt_paren1b(const std::string& s1, const size_type id, const bool isvector);
  std::string debugtxt_paren2(const std::string& s1, const std::string& s2, const std::string& s3);
  std::string debugtxt_submat(const size_type id,  const size_type rstart, const size_type rend, 
			      const size_type cstart, const size_type cend);
  void outputglossary_M1(const std::string& s,  const size_type nr, const size_type nc, const size_type sz);


  void svd_bad_U(const size_type id,const size_type M);
  void svd_bad_S(const size_type id,const size_type minMN);
  void svd_bad_V(const size_type id,const size_type N);



#endif


  


};
#endif
