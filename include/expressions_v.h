#ifndef MATRICKS__EXPRESSIONS_V_H
#define MATRICKS__EXPRESSIONS_V_H



namespace matricks {


  /****************************************************************************
   * VJoinExpr Expression Template 
   *
   * expression for joining two TensorR (RHS only)
   ****************************************************************************
   */

  template<class D, class A, class B>
    class VJoinExpr : public  TExpressionR<D,VJoinExpr<D,A,B> > {

  private:
    const A& a_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:


  VJoinExpr(const A& a, const B& b)
    : a_(a), b_(b) { 

      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
      
    }

    ~VJoinExpr() {
      delete vptrs;
    }
    
    inline const D operator[](const index_type i) const{
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }
    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return a_.size() +b_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "VJoinExpr";
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //      return expression_VJoinExpr(a_.expression(),ii_.expression());
    }
#endif 

    
  };


  /****************************************************************************
   * VJoinObj Expression Template 
   *
   * expression for joining two TensorR (RHS only)
   ****************************************************************************
   */

  template<class D, class A, class B>
    class VJoinObj : public  TExpressionRW<D,VJoinObj<D,A,B> > {

  private:
    A& a_;
    B& b_;
    VectorofPtrs *vptrs;

  public:


  VJoinObj(A& a, B& b)
    : a_(a), b_(b) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
    }

    ~VJoinObj() {
      delete vptrs;
    }


    inline const D operator[](const index_type i) const{
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }
    inline  D& operator[](const index_type i) {
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }

    
    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return a_.size() +b_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "VJoinObj";
    }

    VJoinObj<D,A,B>& operator=(VReconObj<D>& b) { 
      return this->equals(b);
    }

    template <class C>
      VJoinObj<D,A,B>& operator=(const TensorR<D,C>& rhs) { 
      printf2("VJoinObj<D,A,B>& operator=(const TensorR<D,C>& rhs)\n");
      return this->equals(rhs);
    }


    VJoinObj<D,A,B>& operator=(const D d) { 
      return this->equals(d);
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //      return expression_VJoinExpr(a_.expression(),ii_.expression());
    }
#endif 


  };


  





  /****************************************************************************
   * VRepExpr Expression Template 
   *
   * expression for repeating a TensorR (RHS only)
   ****************************************************************************
   */

  template<class D, class A>
    class VRepExpr : public  TExpressionR<D,VRepExpr<D,A> > {

  private:
    const A& a_;
    const size_type m_;
    const size_type N_;
    VectorofPtrs *vptrs;

  public:


  VRepExpr(const A& a, const size_type m)
    : a_(a), m_(m), N_(a_.size()) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }


    ~VRepExpr() {
      delete vptrs;
    }


    inline const D operator[](const index_type i) const{
      index_type index = index_type(i % N_);
      printf3("  i=%d, m_=%lu, i%%N_=%d\n",i,m_,index);
      return a_[index];
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return m_*a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "VRepExpr";
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //      return expression_VJoinExpr(a_.expression(),ii_.expression());
    }
#endif 

  };




};  //namespace matricks

#endif 
