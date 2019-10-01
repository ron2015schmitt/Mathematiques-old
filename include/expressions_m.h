#ifndef MATRICKS__EXPRESSIONS_M_H
#define MATRICKS__EXPRESSIONS_M_H



namespace matricks {



  /****************************************************************************
   * TERW_Transpose
   *
   * 
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
    class TERW_Transpose  : public  TensorRW<D,TERW_Transpose<D,A,FUNC> > {
  
  private:
    A& a_;
    VectorofPtrs *vptrs;
  
  public:



  TERW_Transpose(A& a) : a_(a) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      disp(a);
    }
    
    ~TERW_Transpose() {
      delete vptrs;
    }

    const D operator[](const index_type i) const {
      disp(i);
      const index_type ti = a_.dims().getTranspose().transposeIndex(i);
      disp(ti);
      return a_[ti];
    }
    D& operator[](const index_type i) {
      disp(i);
      const index_type ti = a_.dims().getTranspose().transposeIndex(i);
      disp(ti);
      return a_[ti];
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
    std::string classname() const {
      return "TERW_Transpose";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      std::string sa = a_.expression();
      return FUNC::expression(sa);
    }
#endif


  };





  /*************************************************************************
   * TER_Transpose
   *
   * 
   *************************************************************************
   */

  template<class D, class A, class FUNC>
    class TER_Transpose  : public  TensorR<D,TER_Transpose<D,A,FUNC> > {
  
  private:
    const A& a_;
    VectorofPtrs *vptrs;
  
  public:



  TER_Transpose(const A& a) : a_(a) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      disp(a);
    }
    
    ~TER_Transpose() {
      delete vptrs;
    }

    const D operator[](const index_type i) const {
      disp(i);
      const index_type ti = a_.dims().getTranspose().transposeIndex(i);
      disp(ti);
      return a_[ti];
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
    std::string classname() const {
      return "TER_Transpose";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      std::string sa = a_.expression();
      return FUNC::expression(sa);
    }
#endif


  };







};  //namespace matricks

#endif 
