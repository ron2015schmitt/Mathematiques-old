#ifndef MATRICKS__EXPRESSIONS_V_H
#define MATRICKS__EXPRESSIONS_V_H



namespace matricks {


  /****************************************************************************
   * VER_Join Expression Template 
   *
   * expression for joining two TensorR (RHS only)
   ****************************************************************************
   */

  template<class D, class A, class B>
    class VER_Join : public  TExpressionR<D,VER_Join<D,A,B> > {

  private:
    const A& a_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:


  VER_Join(const A& a, const B& b)
    : a_(a), b_(b) { 

      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
      
    }

    ~VER_Join() {
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
    inline std::string classname() const {
      return "VER_Join";
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //      return expression_VER_Join(a_.expression(),ii_.expression());
    }
#endif 

    
  };


  /****************************************************************************
   * VERW_Join Expression Template 
   *
   * expression for joining two TensorR (RHS only)
   ****************************************************************************
   */

  template<class D, class A, class B>
    class VERW_Join : public  TExpressionRW<D,VERW_Join<D,A,B> > {

  private:
    A& a_;
    B& b_;
    VectorofPtrs *vptrs;

  public:


  VERW_Join(A& a, B& b)
    : a_(a), b_(b) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
    }

    ~VERW_Join() {
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
    inline std::string classname() const {
      return "VERW_Join";
    }

    VERW_Join<D,A,B>& operator=(TERW_Resize<D>& b) { 
      return this->equals(b);
    }

    template <class C>
      VERW_Join<D,A,B>& operator=(const TensorR<D,C>& rhs) { 
      printf2("VERW_Join<D,A,B>& operator=(const TensorR<D,C>& rhs)\n");
      return this->equals(rhs);
    }


    VERW_Join<D,A,B>& operator=(const D d) { 
      return this->equals(d);
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //      return expression_VER_Join(a_.expression(),ii_.expression());
    }
#endif 


  };


  





  /****************************************************************************
   * VER_Rep Expression Template 
   *
   * expression for repeating a TensorR (RHS only)
   ****************************************************************************
   */

  template<class D, class A>
    class VER_Rep : public  TExpressionR<D,VER_Rep<D,A> > {

  private:
    const A& a_;
    const size_type m_;
    const size_type N_;
    VectorofPtrs *vptrs;

  public:


  VER_Rep(const A& a, const size_type m)
    : a_(a), m_(m), N_(a_.size()) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }


    ~VER_Rep() {
      delete vptrs;
    }


    inline const D operator[](const index_type i) const{
      index_type index = index_type(i % N_);
      //      printf3("  i=%d, m_=%lu, i%%N_=%d\n",i,m_,index);
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
    inline std::string classname() const {
      return "VER_Rep";
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //      return expression_VER_Join(a_.expression(),ii_.expression());
    }
#endif 

  };




};  //namespace matricks

#endif 
