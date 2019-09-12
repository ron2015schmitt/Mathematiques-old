#ifndef MATRICKS__DEBUG_H
#define MATRICKS__DEBUG_H


namespace matricks {




  

  




  
  ////////////////////////////////////////////////////////////////////



  
  
  namespace debug {

    template <typename D>
      void _matricksinfo(const Vector<D>& a, std::string varname)
      {
	std::ostringstream stream;
	stream <<"SUMMARY for '" << varname << "':  "<< a.fullclassname()  << "[size=" << a.size() <<"]"<<", VectorID=" << a.objectID()<<", "<< varname<<".name() = "<<'"' << a.name()<<'"';
	mout <<  stream.str() <<std::endl;
      }

    template <typename D>
      void _matricksinfo(const p3vector<D>& a, std::string varname)
      {
	std::ostringstream stream;
	stream <<"SUMMARY for '" << varname << "': "<< a.fullclassname()  << "[size=" << a.size() <<"]";
	mout <<  stream.str() <<std::endl;
      }
    template <typename D>
      void _matricksinfo(const Matrix<D>& a, std::string varname)
      {
	std::ostringstream stream;
	stream <<"SUMMARY for '" << varname << "':  "<< a.fullclassname()  << "[size=" << a.Nrows() << "x" << a.Ncols()<<"]"<<", MatrixID=" << a.objectID()<<", "<< varname<<".name() = "<<'"' << a.name()<<'"';
	mout <<  stream.str() <<std::endl;
      }

  
  };
  
  



  /****************************************************************************
   * Some typedefs and constants
   ****************************************************************************   
   */


  enum TextFormat {text_braces,text_nobraces};

  void cant_open_file(const std::string& name);






  template <class DAT> class pair {
  public:
    index_type index;
    DAT data;
  pair(index_type index_, DAT data_) : index(index_), data(data_) {}
  pair() : index(0), data(DAT(0)) {}
    bool operator<(const pair<DAT>& pair2) const {
      return ((*this).data < pair2.data);
    }
  };


  
  


  void bug_report(const std::string& fname,const size_type linenum);








 

  










  /****************************************************************************
   * vector/matrix error reporting directory
   ****************************************************************************   
   */

  // change this to use vectors and matrices instead
  class AnyIF
  {
  };

  template <typename T>
    class Any : public AnyIF {
  public:
    typedef T MyType;
    MyType& variable; 
    explicit Any(MyType& var) : variable(var) {
      using namespace std;
    }
  };

  class ObjectInfo;
  
  class MatricksObjectManager {
  private:
    static size_type NextObjectID_; 
    static std::map<size_type, ObjectInfo* > objectPool;


  public:
    static size_type addObject(AnyIF& obj);
    static ObjectInfo* getObjectInfo(const size_type id);
    static void removeObject(const size_type id);
    static void outputGlossary(const size_type id);
  };
  

  static size_type addvector(const std::string name, const std::string classname, 
			     const std::string datatype, const  size_type size, const bool checkname=true);

  static void removevector(const size_type id);

  static std::string vectorname(const size_type id);

  static std::string vadd_name(const std::string& name, const size_type id, const bool checkname=true);

  static void vchange_name(const size_type id, const std::string& name, const bool checkname=true);
  static void vchange_size(const size_type id, const size_type size);

  static void outputGlossary(const size_type id);



  size_t NumMatrices(void);

  static size_type addmatrix(const std::string name, const std::string classname, 
			     const std::string datatype, const size_type NR, const size_type NC, const bool checkname=true);
  
  static void removematrix(const size_type id);

  static std::string matrixname(const size_type id);
  static size_type matrixNrows(const size_type id);
  static size_type matrixNcols(const size_type id);


  static std::string madd_name(const std::string name, const size_type id, const bool checkname=true);
  static void mchange_name(const size_type id, const std::string& name, const bool checkname=true);
  static void mchange_size(const size_type id, const size_type NR,  const size_type NC);

  static void moutputglossary(const size_type id);










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

  //These are only used in DEBUG mode
#if MATRICKS_DEBUG>0


  template <class D>
    void vbadrange(const D start, const D end, const D step) {
    mout << warn_str << "range vector of zero length created" << std::endl;
    mout << indent_str  << "(start,end,step) = ";
    mout << "(" << start << "," << end << "," << step <<")" << std::endl;
  }    


  template <class D>
    void vbadlinspace(const D start, const D end, const size_type N) {
    mout << error_str << "linspace requires N>=2" << std::endl;
    mout << indent_str  << "(start,end,N) = ";
    mout << "(" << start << "," << end << "," << N <<")" << std::endl;
  }    



  template <class D, class A> 
    void vbad_assignment_expr(const size_type id, const VorE<D,A>& ve) {
    //    std::string s1= MatricksObjectManager::vectorname(id);
    std::string s1 = "";
    std::string s2= ve.debugtxt();
    mout << error_str << "vector assignment to expression of different size" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
    //    mout << where_str  << s2 << "has size="<<ve.size()<< std::endl;
    //    MatricksObjectManager::outputGlossary(id);
    ve.outputglossary();
  }
  template <class D, class A> 
    void vbad_assignment_expr_warning(const size_type id, const VorE<D,A>& ve) {
    //    std::string s1= MatricksObjectManager::vectorname(id);
    std::string s1 = "";
    std::string s2= ve.debugtxt();
    mout << warn_str << "vector assignment to expression of different size" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
    //    mout << where_str  << s2 << "has size="<<ve.size()<< std::endl;
    //    MatricksObjectManager::outputGlossary(id);
    ve.outputglossary();
    mout << indent_str<< "Vector "<<s1<<" was resized accordingly."<<std::endl;
    mout << indent_str<< "To avoid this warning, explicitly resize using .resize(int) method"<<std::endl;
  }

  



  template <class D, class A> 
    void vbad_expr_in_assignment(const size_type id, const VorE<D,A>& ve) {
    //    std::string s1= MatricksObjectManager::vectorname(id);
    std::string s1 = "";
    std::string s2= ve.debugtxt();
    mout << error_str << "expression formed between vectors of different sizes" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
    MatricksObjectManager::outputGlossary(id);
    ve.outputglossary();
  }

  template <class D, class A> 
    void vbad_expr_in_reconassignment(const size_type id, const VorE<D,A>& ve) {
    //    std::string s1= MatricksObjectManager::vectorname(id);
    std::string s1 = "";

    std::string s2= ve.debugtxt();
    mout << error_str << "expression formed between vectors of different sizes" << std::endl;
    mout << indent_str  <<s1 << ".resize() = " << s2 << std::endl;
    MatricksObjectManager::outputGlossary(id);
    ve.outputglossary();
  }


  template <class D, class A> 
    void vbad_reconassignment(const size_type id, const VorE<D,A>& ve) {
    //std::string s1= MatricksObjectManager::vectorname(id);
    std::string s1 = "";

    std::string s2= ve.debugtxt();
    mout << error_str << ".resize() objects are not permitted on the right hand side of an expression" << std::endl;
    mout << indent_str  <<s1 << " = " << s2<< ".resize()" << std::endl;
    MatricksObjectManager::outputGlossary(id);
    ve.outputglossary();
  }


  template <class D, class A> 
    void vbad_mask(const size_type id, const VorE<D,A>& ve) {
    //    std::string s1= MatricksObjectManager::vectorname(id);
    std::string s1 = "";
    std::string s2= ve.debugtxt();
    mout << error_str << "mask size does not match vector size" << std::endl;
    mout << indent_str  <<s1 <<"[" <<s2<<"]"<< std::endl;
    MatricksObjectManager::outputGlossary(id);
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
    mout << error_str << "expression formed between vectors of different sizes" << std::endl;
    mout << indent_str << fname << "("  <<s1 << seperator << s2 << ")" <<std::endl;
    ve1.outputglossary();
    ve2.outputglossary();
  }


  template <class D, class A> 
    void vbad_expr_in_unary(const VorE<D,A>& ve, const char* fname) {
    std::string s1= ve.debugtxt();
    mout << error_str << "expression formed between vectors of different sizes" << std::endl;
    mout << indent_str << fname << "("  <<s1 << ")" <<std::endl;
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


  void vout_of_bounds(const size_type id, const index_type i);

  void vbad_size(const size_type id, const size_type n);

  void mbad_vcast(const std::string s,  const size_type nr, const size_type nc,  const size_type N);

  void vbad_assignment(const size_type id1, const size_type id2);
  void vbad_assignment_warning(const size_type id1, const size_type id2);

  void vbad_assignment_general_warning(const size_type id1, const size_type sz2, const std::string typeString);

  void v_array_warning(const size_type id);

  void vbadtype_assignment(const size_type id1, const size_type id2);

  void vbad_assignment_mat(const size_type id1, const size_type NR, const size_type NC);

  void vbad_wrapper_assignment(const std::string& s1, const std::string& s2);

  void vbad_wrapper_assignment_mat(const std::string& s1, const std::string& s2);

  void vwrapper_out_of_bounds(const std::string& s1, const index_type i, const size_type sz);



  std::string debugtxt_VSliceObj(const std::string s, const index_type start_,
				 const index_type end_,const  index_type step_);
  void outputglossary_VSliceObj(const size_type id, const std::string s, const size_type sz);

  std::string debugtxt_VSubsetObj(const std::string s1, const std::string s2);
  void outputglossary_VSubsetObj(const size_type id1, const size_type id2, const std::string s, const size_type sz);

  std::string debugtxt_VSubMaskObj(const std::string s1, const std::string s2);
  void settext_VSubMaskObj(const Vector<index_type>& ii,const  Vector<bool>& mask);
  void outputglossary_VSubMaskObj(const size_type id1, const size_type id2, const std::string s, const size_type sz);

#endif  //MATRICKS_DEBUG>0


  


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


#if MATRICKS_DEBUG>0
  template <class D, class A> 
    void mbad_assignment_expr(const size_type id, const MorE<D,A>& me) {
    //    std::string s1= MatricksObjectManager::matrixname(id);
    std::string s1 = "";
    std::string s2= me.debugtxt();
    mout << error_str << "matrix assignment to expression of different size" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
    //    MatricksObjectManager::moutputglossary(id);
    me.outputglossary();
  }


  template <class D, class A> 
    void mbad_assignment_expr_warning(const size_type id, const MorE<D,A>& me) {
    //    std::string s1= MatricksObjectManager::matrixname(id);
    std::string s1 = "";
    std::string s2= me.debugtxt();
    mout << warn_str << "matrix assignment to expression of different size" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
    //    MatricksObjectManager::moutputglossary(id);
    me.outputglossary();
    mout << indent_str<< "Matrix "<<s1<<" was resized accordingly."<<std::endl;
    mout << indent_str<< "To avoid this warning, explicitly resize using .resize(int,int) method"<<std::endl;
  }

  template <class D, class A> 
    void mbad_expr_in_assignment(const size_type id, const MorE<D,A>& me) {
    //    std::string s1= MatricksObjectManager::matrixname(id);
    std::string s1 = "";
    std::string s2= me.debugtxt();
    mout << error_str << "expression formed between matrices of different sizes" << std::endl;
    mout << indent_str  <<s1 << "=" << s2 << std::endl;
    //    MatricksObjectManager::moutputglossary(id);
    me.outputglossary();
  }


  template <class D, class A> 
    void mbad_expr_in_reconassignment(const size_type id, const MorE<D,A>& me) {
    //    std::string s1= MatricksObjectManager::matrixname(id);
    std::string s1 = "";
    std::string s2= me.debugtxt();
    mout << error_str << "expression formed between matrices of different sizes" << std::endl;
    mout << indent_str  <<s1 << ".resize() = " << s2 << std::endl;
    //    MatricksObjectManager::moutputglossary(id);
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
    mout << error_str << "expression formed between matrices of different sizes" << std::endl;
    mout << indent_str << fname << "("  <<s1 << seperator << s2 << ")" <<std::endl;
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
    mout << error_str << "dot product formed between incompatibly-sized matrices" << std::endl;
    mout << indent_str  << "("  <<s1 << "|" << s2 << ")" <<std::endl;
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
    mout << error_str << "dot product formed between incompatibly-sized objects" << std::endl;
    mout << indent_str  << "("  <<s1 << "|" << s2 << ")" <<std::endl;
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
    mout << error_str << "dot product formed between incompatibly-sized objects" << std::endl;
    mout << indent_str  << "("  <<s1 << "|" << s2 << ")" <<std::endl;
    ve1.outputglossary();
    me2.outputglossary();
  }



  template <class D, class A> 
    void mbad_expr_in_unary(const MorE<D,A>& me, const char* fname) {
    std::string s1= me.debugtxt();
    mout << error_str << "expression formed between matrices of different sizes" << std::endl;
    mout << indent_str << fname << "("  <<s1 << ")" <<std::endl;
    me.outputglossary();
  }



  bool mexpr_is_size_bad(const size_type sz);



  template <class D, class A> 
    void mbad_subsmatrix(const size_type id, const MorE<D,A>& me) {
    //    std::string s1= MatricksObjectManager::matrixname(id);
    std::string s1 = "";
    std::string s2= me.debugtxt();
    mout << error_str << "subscript matrices must have exactly 2 columns" << std::endl;
    mout << indent_str  <<"Matrix "<<s2<<" is not of this form"<< std::endl;
    mout << indent_str  <<s1 <<"[" <<s2<<"]"<< std::endl;
    //    MatricksObjectManager::moutputglossary(id);
    me.outputglossary();
  }


  template <class D, class A> 
    void mbad_mask(const size_type id, const MorE<D,A>& me) {
    //    std::string s1= MatricksObjectManager::matrixname(id);
    std::string s1 = "";
    std::string s2= me.debugtxt();
    mout << error_str << "mask size does not match maxtrix size" << std::endl;
    mout << indent_str  <<s1 <<"[" <<s2<<"]"<< std::endl;
    //    MatricksObjectManager::moutputglossary(id);
    me.outputglossary();
  }

  
  template <class D, class A> 
    void mbad_maskv(const size_type id, const VorE<D,A>& ve) {
    //    std::string s1= MatricksObjectManager::matrixname(id);
    std::string s1 = "";
    std::string s2= ve.debugtxt();
    mout << error_str << "mask size does not match maxtrix size" << std::endl;
    mout << indent_str  <<s1 <<"[" <<s2<<"]"<< std::endl;
    //    MatricksObjectManager::moutputglossary(id);
    ve.outputglossary();
  }

  template <class D, class A> 
    void mbad_reconassignment(const size_type id, const MorE<D,A>& me) {
    std::string s1 = "";
    //    std::string s1= MatricksObjectManager::matrixname(id);
    std::string s2= me.debugtxt();
    mout << error_str << ".resize() objects are not permitted on the right hand side of an expression" << std::endl;
    mout << indent_str  <<s1 << " = " << s2 << std::endl;
    //    MatricksObjectManager::moutputglossary(id);
    me.outputglossary();
  }


  

  void mbad_reshape(const size_type id,  const size_type nr, const size_type nc,  const size_type NR, const size_type NC);
  void mout_of_bounds(const size_type id, const size_type i);


  void mout_of_bounds2(const size_type id, const index_type r, const index_type c);

  void mwrapper_out_of_bounds(const std::string& wSTR, 
			      const index_type aindex, const size_type wNR, 
			      const size_type wNC,  const size_type wSZ,
			      const size_type aID
			      );
  void mwrapper_out_of_bounds_rc(const std::string& wSTR, 
				 const index_type r,   const index_type c, 
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

  void mbad_submat( const size_type id, const index_type rstart, const index_type rend, 
		    const index_type cstart, const index_type cend);


  std::string debugtxt_paren(const std::string& s, METypes mt);
  std::string debugtxt_paren1(const std::string& s1, const std::string& s2);
  std::string debugtxt_paren1b(const std::string& s1, const size_type id, const bool isvector);
  std::string debugtxt_paren2(const std::string& s1, const std::string& s2, const std::string& s3);
  std::string debugtxt_submat(const size_type id,  const index_type rstart, const index_type rend, 
			      const index_type cstart, const index_type cend);
  void outputglossary_M1(const std::string& s,  const size_type nr, const size_type nc, const size_type sz);


  void svd_bad_U(const size_type id,const size_type M);
  void svd_bad_S(const size_type id,const size_type minMN);
  void svd_bad_V(const size_type id,const size_type N);
#endif  //MATRICKS_DEBUG>0

  
};


#endif
