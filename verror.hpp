#ifndef VERROR_H
#define VERROR_H 1

#include <sstream>
#include <iostream>
#include <string>

namespace Matricks {


  /****************************************************************************
   * Some Error-Checking and Error-Printing functions
   ****************************************************************************   
   */


  // These should always be compiled in



  void vbad_input_stream_size(const std::string& name, const std::string& line, 
			     const size_type N1, const size_type N2);

  void vinput_stream_size_too_small(const std::string& name, const std::string& line, 
				   const size_type N1, const size_type N2);

  void vsyntax_error(const std::string& name, const std::string& line, 
		     const size_type N1, const size_type N2, 
		     const size_type Nlines, const size_type Nchars, 
		     const char c,
		     const std::string& info, TextFormat textformat);

  //These are only used in CAREFUL mode
#ifdef Matricks_CAREFUL




  template <class D>
  void vbadrange(const D start, const D end, const D step) {
    std::cout << warn_str << "range vector of zero length created" << std::endl;
    std::cout << indent_str  << "(start,end,step) = ";
    std::cout << "(" << start << "," << end << "," << step <<")" << std::endl;
  }    


  template <class D>
  void vbadlinspace(const D start, const D end, const size_type N) {
    std::cout << error_str << "linspace requires N>=2" << std::endl;
    std::cout << indent_str  << "(start,end,N) = ";
    std::cout << "(" << start << "," << end << "," << N <<")" << std::endl;
  }    



 template <class D, class A> 
  void vbad_assignment_expr(const size_type id, const VorE<D,A>& ve) {
    std::string s1= MatricksObjectPool::vectorname(id);
    std::string s2= ve.debugtxt();
    std::cout << error_str << "vector assignment to expression of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    //    std::cout << where_str  << s2 << "has size="<<ve.size()<< std::endl;
    MatricksObjectPool::voutputglossary(id);
    ve.outputglossary();
  }
 template <class D, class A> 
  void vbad_assignment_expr_warning(const size_type id, const VorE<D,A>& ve) {
    std::string s1= MatricksObjectPool::vectorname(id);
    std::string s2= ve.debugtxt();
    std::cout << warn_str << "vector assignment to expression of different size" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    //    std::cout << where_str  << s2 << "has size="<<ve.size()<< std::endl;
    MatricksObjectPool::voutputglossary(id);
    ve.outputglossary();
    std::cout << indent_str<< "Vector "<<s1<<" was resized accordingly."<<std::endl;
    std::cout << indent_str<< "To avoid this warning, explicitly resize using .resize(int) method"<<std::endl;
  }




   template <class D, class A> 
  void vbad_expr_in_assignment(const size_type id, const VorE<D,A>& ve) {
    std::string s1= MatricksObjectPool::vectorname(id);
    std::string s2= ve.debugtxt();
    std::cout << error_str << "expression formed between vectors of different sizes" << std::endl;
    std::cout << indent_str  <<s1 << "=" << s2 << std::endl;
    MatricksObjectPool::voutputglossary(id);
    ve.outputglossary();
  }

   template <class D, class A> 
  void vbad_expr_in_reconassignment(const size_type id, const VorE<D,A>& ve) {
    std::string s1= MatricksObjectPool::vectorname(id);
    std::string s2= ve.debugtxt();
    std::cout << error_str << "expression formed between vectors of different sizes" << std::endl;
    std::cout << indent_str  <<s1 << ".resize() = " << s2 << std::endl;
    MatricksObjectPool::voutputglossary(id);
    ve.outputglossary();
  }


   template <class D, class A> 
   void vbad_reconassignment(const size_type id, const VorE<D,A>& ve) {
    std::string s1= MatricksObjectPool::vectorname(id);
    std::string s2= ve.debugtxt();
    std::cout << error_str << ".resize() objects are not permitted on the right hand side of an expression" << std::endl;
    std::cout << indent_str  <<s1 << " = " << s2<< ".resize()" << std::endl;
    MatricksObjectPool::voutputglossary(id);
    ve.outputglossary();
  }


   template <class D, class A> 
   void vbad_mask(const size_type id, const VorE<D,A>& ve) {
    std::string s1= MatricksObjectPool::vectorname(id);
    std::string s2= ve.debugtxt();
    std::cout << error_str << "mask size does not match vector size" << std::endl;
    std::cout << indent_str  <<s1 <<"[" <<s2<<"]"<< std::endl;
    MatricksObjectPool::voutputglossary(id);
    ve.outputglossary();
  }


   template <class D1, class D2, class A, class B> 
  void vbad_expr_in_binary(const VorE<D1,A>& ve1, const VorE<D2,B>& ve2, const char* fname, const char* seperator) {
    std::string s1= ve1.debugtxt();
    std::string s2= ve2.debugtxt();
    if (ve1.vetype() != VE_Vector) 
      s1 = "(" + s1 + ")";
    if (ve2.vetype() != VE_Vector) 
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


  void vout_of_bounds(const size_type id, const size_type i);

  void vbad_size(const size_type id, const size_type n);

  void mbad_vcast(const std::string s,  const size_type nr, const size_type nc,  const size_type N);

  void vbad_assignment(const size_type id1, const size_type id2);
  void vbad_assignment_warning(const size_type id1, const size_type id2);

  void vbadtype_assignment(const size_type id1, const size_type id2);

  void vbad_assignment_mat(const size_type id1, const size_type NR, const size_type NC);

  void vbad_wrapper_assignment(const std::string& s1, const std::string& s2);

  void vbad_wrapper_assignment_mat(const std::string& s1, const std::string& s2);

  void vwrapper_out_of_bounds(const std::string& s1, const size_type i, const size_type sz);



  std::string debugtxt_VRangeObj(const std::string s, const size_type start_,
				 const size_type end_,const  int step_);
  void outputglossary_VRangeObj(const size_type id, const std::string s, const size_type sz);

  std::string debugtxt_VSetObj(const std::string s1, const std::string s2);
  void outputglossary_VSetObj(const size_type id1, const size_type id2, const std::string s, const size_type sz);

  std::string debugtxt_VMaskObj(const std::string s1, const std::string s2);
  void settext_VMaskObj(const Vector<size_type>& ii,const  Vector<bool>& mask);
  void outputglossary_VMaskObj(const size_type id1, const size_type id2, const std::string s, const size_type sz);





#endif


  


};
#endif
