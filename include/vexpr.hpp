#ifndef VEXPR_H
#define VEXPR_H


#include <string>
#include <sstream>



namespace matricks {

  template <class A>
  inline Vector<index_type> findtrue( const VorE<bool,A>& a );






  /****************************************************************************
   * Vexpr -- Vector Expression template abstract class
   ****************************************************************************
   */
  template<class D, class EXP> 
  class Vexpr : public VorE<D,Vexpr<D,EXP> > {
  private:
    typedef  D DataT;
    inline EXP& derived() {
      return static_cast<EXP&>(*this);
    }
    inline const  EXP& derived() const {
      return static_cast<const EXP&>(*this);
    }

  public:

    inline const D operator[](const size_type i) const {
      return derived()[i];
    }

    inline size_type size(void) const {
      return derived().size();
    }

    inline VETypes vetype(void) const {
      return derived().vetype();
    }




    std::string debugtxt(void) const {
      return derived().debugtxt();
    }

    void outputglossary(void) const {
      derived().outputglossary();
    }

    std::vector<const void*> getAddresses(void) const {
      return derived().getAddresses();
    }
    bool checkAddresses(const std::vector<const void*> addrs) const {
      return derived().checkAddresses(addrs);
    }
    void addAddress(const void* addr) {
      derived().addAddress(addr);
    }
    void addAddresses(const std::vector<const void*> addrs) {
      derived().addAddresses(addrs);
    }


  };

  
  /****************************************************************************
   * VWrapperObj Expression Template 
   *
   * abstract class 
   * This is used for expressions that can be placed on the left hand side
   * of an assignment
   ****************************************************************************
   */
  template <class D, class DERIVED>
  class VWrapperObj : public  Vexpr<D,VWrapperObj<D,DERIVED> > {
  private:
    inline DERIVED& derived() {
      return static_cast<DERIVED&>(*this);
    }
    inline const  DERIVED& derived() const {
      return static_cast<const DERIVED&>(*this);
    }

  public:

    inline const D operator[](const size_type i) const {  
      const size_type index = derived().index(i);
#ifdef MATRICKS_DEBUG
      if (index>=derived().sizetotal()) {
	vwrapper_out_of_bounds(debugtxt(),i,size());
	return derived().data(0);
      }
#endif
      return derived().data(index);
    }

    inline D& operator[](const size_type i) {  
      const size_type index = derived().index(i);
#ifdef MATRICKS_DEBUG
      if (index>=derived().sizetotal()) {
	vwrapper_out_of_bounds(debugtxt(),i,size());
	return derived().data(0);
      }
#endif
      return derived().data(index);
    }

    inline size_type index(void) const {
      return derived().index();
    }

    inline size_type size(void) const {
      return derived().size();
    }

    inline VETypes vetype(void) const {
      return derived().vetype();
    }


    // Assign to constant value
    DERIVED& equals(const D d) { 
      for(size_type i=0; i<size(); i++) 
	(*this)[i]=d; 
      return derived();
    }
    // assign to recon object (issue error)
    DERIVED& equals(const VReconObj<D>& b) { 
#ifdef MATRICKS_DEBUG
      vbad_reconassignment(derived().a_.objectID(), b);
#endif
      return derived();
    }
    


    // assign to vector or expression
    template <class B>
    DERIVED& equals(const VorE<D,B>& rhs) { 

      const size_type N =size();
      //      printf("size=%lu\n",N);

#ifdef MATRICKS_DEBUG
      if ( size() !=  rhs.size() ){ 
	vbad_wrapper_assignment(debugtxt(),rhs.debugtxt());
	outputglossary();
	rhs.outputglossary();
	return derived();
      }
#endif

      if ( rhs.checkAddresses(getAddresses()) ) {    
#ifdef MATRICKS_DEBUG
	//	Vector<D> y(N,debugtxt());
	Vector<D> y(N);
#else
	Vector<D> y(N);
#endif
	for(register size_type i=0; i<N; i++) 
	  y[i] = rhs[i]; 
	for(register size_type i=0; i<N; i++) 
	  derived()[i] = y[i]; 
      } else {
	for(register size_type i=0; i<N; i++) 
	  derived()[i] = rhs[i]; 
      }
      return derived();
    }




    // assignment to matrix or submatrix (must be 1xN or Nx1)
    template <class B>
    DERIVED& equals(const MorE<D,B>& rhs) {

      const size_type N =size();
#ifdef MATRICKS_DEBUG
      const size_type NR = rhs.Nrows();
      const size_type NC = rhs.Ncols();
      if ( ( N !=  rhs.size() ) 
	   || ( (NR!=1) && (NC!=1) ) ){ 
	vbad_wrapper_assignment_mat(derived().debugtxt(),rhs.debugtxt());
	derived().outputglossary();
	rhs.outputglossary();
	return derived();
      }
#endif


      if ( rhs.checkAddresses(getAddresses()) ) {    
#ifdef MATRICKS_DEBUG
	Vector<D> y(N,debugtxt());
#else
	Vector<D> y(N);
#endif
	y=rhs;
	for(register size_type i=0; i<N; i++) 
	  derived()[i] = y[i]; 
      } else {
	for(register size_type i=0; i<N; i++) 
	  derived()[i] = rhs(i); 
      }
      return derived();
    }


    std::string debugtxt(void) const {
      return derived().debugtxt();
    }

    void outputglossary(void) const {
      return derived().outputglossary();
    }

    std::vector<const void*> getAddresses(void) const {
      return derived().getAddresses();
    }
    bool checkAddresses(const std::vector<const void*> addrs) const {
      return derived().checkAddresses(addrs);
    }
    void addAddress(const void* addr) {
      derived().addAddress(addr);
    }
    void addAddresses(const std::vector<const void*> addrs) {
      derived().addAddresses(addrs);
    }
    
  };



  /****************************************************************************
   * VSubsetObj Expression Template 
   *
   * wrapper for a vector subset
   ****************************************************************************
   */
  template<class D>
  class VSubsetObj :  public  VWrapperObj<D,VSubsetObj<D> >, VectorofPtrs {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& a_;
    const Vector<index_type>& ii_;
    const bool delete_ii_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;
    VSubsetObj(Vector<D>& a, const Vector<index_type>& ii)
      : a_(a), ii_(ii), delete_ii_(false)
    { 
      addAddress(&a_);
      addAddress(&ii_);
    }
#if CPP11 == 1    
    VSubsetObj(Vector<D>& a, const std::initializer_list<index_type>& list)
      : a_(a), ii_(*(new Vector<index_type>(list))), delete_ii_(true)
    {
      addAddress(&a_);
      addAddress(&ii_);
    }
#endif
    ~VSubsetObj() {
      if (delete_ii_) delete &ii_;
    }

    inline const D data(const index_type i) const{
      return a_[i];
    }
    inline  D& data(const index_type i) {
      return a_[i];
    }

    inline index_type index(index_type i) const{
      index_type ind = ii_[i];
      //dispcr(ind);
      //dispcr(sizetotal());
      if (ind < 0) {
	ind = sizetotal() + ind;
      }
      //dispcr(ind);
      return ind;
    }


    inline VETypes vetype(void) const {
      return VE_VSubsetObj;
    }

    inline size_type size(void) const {
      return ii_.size();
    }

    inline size_type sizetotal(void) const {
      return a_.size();
    }

    VSubsetObj<D>& operator=(VReconObj<D>& b) { 
      return this->equals(b);
    }

    template <class B>
    VSubsetObj<D>& operator=(const VorE<D,B>& rhs) { 
      return this->equals(rhs);
    }

    template <class B>
    VSubsetObj<D>& operator=(const MorE<D,B>& rhs) { 
      return this->equals(rhs);
    }

    VSubsetObj<D>& operator=(const D d) { 
      return this->equals(d);
    }
    
    VSubsetObj<D>& operator=(const VSubsetObj<D>& b) { 
      return this->equals(b);
    }


    
    std::string debugtxt(void) const {
      return debugtxt_VSubsetObj(a_.debugtxt(),ii_.debugtxt());
    }

    void outputglossary(void) const {
      outputglossary_VSubsetObj(a_.objectID(),ii_.objectID(),debugtxt(),size());
    }



  };






  /****************************************************************************
   * VJoinObj Expression Template 
   *
   * wrapper for joining two vectors
   ****************************************************************************
   */
  template<class D, class A, class B>
  class VJoinObj : public  VWrapperObj<D,VJoinObj<D,A,B> >, VectorofPtrs {

  private:
    // can't be constant since we alow to be on left hand side
    A& a_;
    B& b_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

    VJoinObj(A& a, B& b)
      : a_(a), b_(b)
    { 
      addAddresses(a_.getAddresses());
      addAddresses(b_.getAddresses());
    }


    inline const D data(const index_type i) const{
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }
    inline  D& data(const index_type i) {
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }

    inline index_type index(index_type i) const{
      return i;
    }



    inline VETypes vetype(void) const {
      return VE_VJoinObj;
    }

    inline size_type size(void) const {
      return a_.size() +b_.size();
    }

    inline size_type sizetotal(void) const {
      return a_.size() +b_.size();
    }

    VJoinObj<D,A,B>& operator=(VReconObj<D>& c) { 
      return this->equals(c);
    }

    template <class B2>
    VJoinObj<D,A,B>& operator=(const VorE<D,B2>& rhs) { 
      return this->equals(rhs);
    }

    template <class B2>
    VJoinObj<D,A,B>& operator=(const MorE<D,B2>& rhs) { 
      return this->equals(rhs);
    }

    VJoinObj<D,A,B>& operator=(const D d) { 
      return this->equals(d);
    }
    

  
    std::string debugtxt(void) const {
      return "";
      //      return debugtxt_VJoinObj(a_.debugtxt(),ii_.debugtxt());
    }

    void outputglossary(void) const {
      return ;
      //      outputglossary_VJoinObj(a_.objectID(),ii_.objectID(),debugtxt(),size());
    }



  };



  


  /****************************************************************************
   * VSubMaskObj Expression Template 
   *
   * wrapper for a vector submask
   ****************************************************************************
   */
  template<class D>
  class VSubMaskObj :  public  VWrapperObj<D,VSubMaskObj<D> >, VectorofPtrs {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& a_;
    const Vector<index_type>* ii_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

#ifdef MATRICKS_DEBUG
    VSubMaskObj(Vector<D>& a, const Vector<bool>& mask)
      : a_(a), ii_(new Vector<index_type>(findtrue(mask)))
    { 
      //      settext_VSubMaskObj(*ii_,mask);
      addAddress(&a_);
      addAddress(&ii_);
    }
#else
    VSubMaskObj(Vector<D>& a, const Vector<bool>& mask)
      : a_(a), ii_(new Vector<index_type>(findtrue(mask)))
    { 
      addAddress(&a_);
      addAddress(&ii_);
    }
#endif

    ~VSubMaskObj()
    { 
      delete  ii_;
    }

    inline const D data(const index_type i) const{
      return a_[i];
    }
    inline  D& data(const index_type i) {
      return a_[i];
    }

    inline index_type index(index_type i) const{
      return (*ii_)[i];
    }

    inline VETypes vetype(void) const {
      return VE_VSubMaskObj;
    }

    inline size_type size(void) const {
      return ii_->size();
    }

    inline size_type sizetotal(void) const {
      return a_.size();
    }

    VSubMaskObj<D>& operator=(VReconObj<D>& b) { 
      return this->equals(b);
    }

    template <class B>
    VSubMaskObj<D>& operator=(const VorE<D,B>& rhs) { 
      return this->equals(rhs);
    }

    template <class B>
    VSubMaskObj<D>& operator=(const MorE<D,B>& rhs) { 
      return this->equals(rhs);
    }

    VSubMaskObj<D>& operator=(const D d) { 
      return this->equals(d);
    }
    
    VSubMaskObj<D>& operator=(const VSubMaskObj<D>& b) { 
      return this->equals(b);
    }

    std::string debugtxt(void) const {
      return debugtxt_VSubMaskObj(a_.debugtxt(),ii_->debugtxt());
    }

    void outputglossary(void) const {
      outputglossary_VSubMaskObj(a_.objectID(),ii_->objectID(),debugtxt(),size());
    }


  };






  /****************************************************************************
   * VReconObj Expression Template 
   *
   * reallocate store
   ****************************************************************************
   */
  template<class D>
  class VReconObj :  public  Vexpr<D,VReconObj<D> >, VectorofPtrs {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& a_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

    VReconObj(Vector<D>& a)
      : a_(a)
    { 
      addAddress(&a_);
    }

    inline VETypes vetype(void) const {
      return VE_VReconObj;
    }

    template <class A>
    Vector<D>& operator=(const VorE<D,A>& x) { 
      size_type N = x.size();
      
#ifdef MATRICKS_DEBUG
      if ( N==badsize ){ 
	vbad_expr_in_reconassignment(a_.objectID(), x);
	return a_;
      }
#endif
      
      if ( x.addrmatch(&a_)) {    
#ifdef MATRICKS_DEBUG
	//	Vector<D> y(N,debugtxt());
	Vector<D> y(N);
#else
	Vector<D> y(N);
#endif
	y = x.derived();
	a_.resize(N);
	a_ = y;
	return a_;
      } else {
	a_.resize(N);
	a_ = x.derived();
	return a_;
      }
    }

    Vector<D>& operator=(const VReconObj<D>& b) { 

#ifdef MATRICKS_DEBUG
      vbad_reconassignment(a_.objectID(), b);
#endif
      return a_;
    }

    std::string debugtxt(void) const {
      return  a_.debugtxt() +".resize()";
    }

    void outputglossary(void) const {
      a_.outputglossary();
    }




  };










  /****************************************************************************
   * VSliceObj Expression Template 
   *
   * wrapper for vector ranges  (slices)
   ****************************************************************************
   */
 
  template <class D>
  class VSliceObj : public  VWrapperObj<D, VSliceObj<D> >, VectorofPtrs {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& a_;

    const index_type start_;
    const index_type end_;
    const index_type step_;
    const bool increasing_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

    VSliceObj(Vector<D>& a, const index_type start, const index_type end, const int step)
      :   a_(a),  start_(start), end_(end), 
	  step_((step>=0)?step:-step), 
	  increasing_((end>=start)?true:false)
    { 
      addAddress(&a_);
    }

    inline const D data(const index_type i) const{
      return a_[i];
    }
    inline D& data(const index_type i) {
      return a_[i];
    }


    // could improve speed for step=1 and step=-1 by creating a separate
    // function or template class that doesn't include the step multiply
    inline index_type index(index_type i) const{
     if (increasing_) 
       return start_ + i * step_;
     else 
       return start_ - i * step_;      
    }


    inline size_type size(void) const {
     if (increasing_) 
       return (end_-start_)/step_ + 1;
     else 
       return (start_-end_)/step_ + 1;      
    }

    inline size_type sizetotal(void) const {
      return a_.size();
    }

    inline VETypes vetype(void) const {
      return VE_VSliceObj;
    }


    VSliceObj<D>& operator=(VReconObj<D>& b) { 
      return this->equals(b);
    }

    template <class B>
    VSliceObj<D>& operator=(const VorE<D,B>& rhs) { 
      return this->equals(rhs);
    }

    template <class B>
    VSliceObj<D>& operator=(const MorE<D,B>& rhs) { 
      return this->equals(rhs);
    }

    VSliceObj<D>& operator=(const D d) { 
      return this->equals(d);
    }
    
    VSliceObj<D>& operator=(const VSliceObj<D>& b) { 
      return this->equals(b);
    }

    std::string debugtxt(void) const {
      return debugtxt_VSliceObj(a_.debugtxt(),start_,end_,step_);
    }

    void outputglossary(void) const {
      outputglossary_VSliceObj(a_.objectID(),debugtxt(),size());
    }



  };







  /****************************************************************************
   * VBinOp Operator Expression Template 
   *
   * vector/vector binary operator expressions
   ****************************************************************************
   */
  template<class D, class A, class B, class OP>
  class VBinOp : public  Vexpr<D,VBinOp<D,A,B,OP> >, VectorofPtrs {

  private:
    const A& a_;
    const B& b_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

    VBinOp(const A& a, const B& b)
      : a_(a), b_(b)
    { 
      addAddresses(a_.getAddresses());
      addAddresses(b_.getAddresses());
    }

    inline const D operator[](const index_type i) const {  
      return OP::apply(a_[i], b_[i]); 
    }

    inline size_type size(void) const {
      if ( a_.size() != b_.size() ) {
	return badsize;
      } else {
	return a_.size();
      }
    }

    inline VETypes vetype(void) const {
      return VE_VBinOp;
    }

    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      if (a_.vetype() != VE_Vector) 
	sa = "(" + sa + ")";
      std::string sb = b_.debugtxt();
      if (b_.vetype() != VE_Vector) 
	sb = "(" + sb + ")";
      return OP::debugtxt(sa,sb);
    }


    void outputglossary(void) const {
      a_.outputglossary();
      b_.outputglossary();
    }



  };







  /****************************************************************************
   * VecOpScal Operator Template 
   *
   * vector/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
  class VecOpScal : public Vexpr<D,VecOpScal<D,A,OP> >, VectorofPtrs {

  private:
    const A& a_;
    D val_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

    VecOpScal(const A& a, const D b)
      : a_(a), val_(b)
    {
      addAddresses(a_.getAddresses());
    }

    inline const D operator[](const index_type i) const { 
      return OP::apply(a_[i], val_); 
    }

    inline size_type size(void) const {
      return a_.size();
    }

    inline VETypes vetype(void) const {
      return VE_VecOpScal;
    }

    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      if (a_.vetype() != VE_Vector) 
	sa = "(" + sa + ")";
      std::ostringstream stream;
      stream << val_;
      std::string sb = stream.str();
      return OP::debugtxt(sa,sb);
    }


    void outputglossary(void) const {
      a_.outputglossary();
    }




  };





  /****************************************************************************
   * ScalOpVec Operator Template 
   *
   * scalar/vector binary operators
   ****************************************************************************
   */


  template<class D, class B, class OP>
  class ScalOpVec : public Vexpr<D,ScalOpVec<D,B,OP> >, VectorofPtrs {

  private:
    D val_;
    const B& b_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;


    ScalOpVec(const D a, const B& b)
      :  val_(a), b_(b)
    {
      addAddresses(b_.getAddresses());
    }

    inline const D operator[](const index_type i) const { 
      return OP::apply(val_,b_[i]); 
    }

    inline size_type size(void) const {
      return b_.size();
    }

    inline VETypes vetype(void) const {
      return VE_ScalOpVec;
    }

    std::string debugtxt(void) const {
      std::ostringstream stream;
      stream << val_;
      std::string sa = stream.str();
      std::string sb = b_.debugtxt();
      if (b_.vetype() != VE_Vector) 
	sb = "(" + sb + ")";
      return OP::debugtxt(sa,sb);
    }

    void outputglossary(void) const {
      b_.outputglossary();
    }


  };




  /****************************************************************************
   * VFuncOp Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
  class VFuncOp  : public  Vexpr<D,VFuncOp<D,A,FUNC> >, VectorofPtrs {
  
  private:
    const A& a_;
  
  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;


    VFuncOp(const A& a) : a_(a) {
      addAddresses(a_.getAddresses());
    }


    inline const D operator[](const index_type i) const
    { return FUNC::apply(a_[i]); }

    inline size_type size(void) const {
      return a_.size();
    }

    inline VETypes vetype(void) const {
      return VE_VFuncOp;
    }

    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      return FUNC::debugtxt(sa);
    }

    void outputglossary(void) const {
      a_.outputglossary();
    }


  };





};

#endif
