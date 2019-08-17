#ifndef VEXPR_H
#define VEXPR_H


#include <string>
#include <sstream>



namespace Matricks {

  template <class A>
  inline Vector<uint> findtrue( const VorE<bool,A>& a );


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

    bool mustcopy(const void* vaddr) const {
      return derived().mustcopy(vaddr);
    }

    bool addrmatch(const void *vaddr) const {
      return derived().addrmatch(vaddr);
    }



  };






  /****************************************************************************
   * VWrapperObj Expression Template 
   *
   * abstract class 
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
      if (index>=derived().asize()) {
	vwrapper_out_of_bounds(debugtxt(),i,size());
	return derived().data(0);
      }
#endif
      return derived().data(index);
    }

    inline D& operator[](const size_type i) {  
      const size_type index = derived().index(i);
#ifdef MATRICKS_DEBUG
      if (index>=derived().asize()) {
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

#ifdef MATRICKS_DEBUG
      if ( size() !=  rhs.size() ){ 
	vbad_wrapper_assignment(debugtxt(),rhs.debugtxt());
	outputglossary();
	rhs.outputglossary();
	return derived();
      }
#endif

      if ( rhs.addrmatch(derived().addr()) ) {    
#ifdef MATRICKS_DEBUG
	Vector<D> y(N,debugtxt());
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


      if ( rhs.addrmatch(derived().addr()) ) {    
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

    bool mustcopy(const void *vaddr) const {
      return derived().mustcopy(vaddr);
    }

    bool addrmatch(const void *vaddr) const {
      return derived().addrmatch(vaddr);
    }

    const void *addr(void) const {
      return derived().addr();
    }
    
  };




  /****************************************************************************
   * VSliceObj Expression Template 
   *
   * wrapper for vector ranges  (slices)
   ****************************************************************************
   */
 
  template <class D>
  class VSliceObj : public  VWrapperObj<D,VSliceObj<D> > {
  private:
    Vector<D>& a_;
    const size_type start_;
    const size_type end_;
    const size_type step_;
    const bool increasing_;

  public:
    VSliceObj(Vector<D>& a, const size_type start, const size_type end, const int step)
      :   a_(a),  start_(start), end_(end), 
	  step_((step>=0)?step:-step), 
	  increasing_((end>=start)?true:false)
    { 
    }

    inline const D data(size_type i) const{
      return a_[i];
    }
    inline D& data(size_type i) {
      return a_[i];
    }


    // could improve speed for step=1 and step=-1 by creating a separate
    // function or template class that doesn't include the step multiply
    inline size_type index(size_type i) const{
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

    inline size_type asize(void) const {
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

    bool mustcopy(const void *vaddr) const {
       return addrmatch(vaddr);
    }


    bool addrmatch(const void *vaddr) const {
      return vaddr==static_cast<const void*>(&a_);
    }

    const void *addr(void) const {
      return &a_;
    }


  };





  /****************************************************************************
   * VSubsetObj Expression Template 
   *
   * wrapper for a vector subset
   ****************************************************************************
   */
  template<class D>
  class VSubsetObj :  public  VWrapperObj<D,VSubsetObj<D> > {
  private:
    Vector<D>& a_;
    const Vector<uint>& ii_;

  public:
    VSubsetObj(Vector<D>& a, const Vector<uint>& ii)
      : a_(a), ii_(ii)
    { 
    }

    inline const D data(size_type i) const{
      return a_[i];
    }
    inline  D& data(size_type i) {
      return a_[i];
    }

    inline size_type index(size_type i) const{
      return ii_[i];
    }


    inline VETypes vetype(void) const {
      return VE_VSubsetObj;
    }

    inline size_type size(void) const {
      return ii_.size();
    }

    inline size_type asize(void) const {
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

    bool mustcopy(const void *vaddr) const {
      return addrmatch(vaddr);
    }


    bool addrmatch(const void *vaddr) const {
      return (vaddr==static_cast<const void*>(&a_)) ||(vaddr==static_cast<const void*>(&ii_)) ;
    }


    const void *addr(void) const {
      return &a_;
    }


  };




  /****************************************************************************
   * VSubMaskObj Expression Template 
   *
   * wrapper for a vector submask
   ****************************************************************************
   */
  template<class D>
  class VSubMaskObj :  public  VWrapperObj<D,VSubMaskObj<D> > {
  private:
    Vector<D>& a_;
    const Vector<uint>* ii_;

  public:
#ifdef MATRICKS_DEBUG
    VSubMaskObj(Vector<D>& a, const Vector<bool>& mask)
      : a_(a), ii_(new Vector<uint>(findtrue(mask)))
    { 
      //      settext_VSubMaskObj(*ii_,mask);
    }
#else
    VSubMaskObj(Vector<D>& a, const Vector<bool>& mask)
      : a_(a), ii_(new Vector<uint>(findtrue(mask)))
    { 
    }
#endif

    ~VSubMaskObj()
    { 
      delete  ii_;
    }

    inline const D data(size_type i) const{
      return a_[i];
    }
    inline  D& data(size_type i) {
      return a_[i];
    }

    inline size_type index(size_type i) const{
      return (*ii_)[i];
    }

    inline VETypes vetype(void) const {
      return VE_VSubMaskObj;
    }

    inline size_type size(void) const {
      return ii_->size();
    }

    inline size_type asize(void) const {
      return a_.size();
    }

    VSubMaskObj<D>& operator=(const VSubMaskObj<D>& b) { 
      return equals(b);
    }

    std::string debugtxt(void) const {
      return debugtxt_VSubMaskObj(a_.debugtxt(),ii_->debugtxt());
    }

    void outputglossary(void) const {
      outputglossary_VSubMaskObj(a_.objectID(),ii_->objectID(),debugtxt(),size());
    }

    bool mustcopy(const void *vaddr) const {
       return addrmatch(vaddr);
    }

    bool addrmatch(const void *vaddr) const {
      return vaddr==static_cast<const void*>(&a_);
    }


    const void *addr(void) const {
      return &a_;
    }

  };






  /****************************************************************************
   * VReconObj Expression Template 
   *
   * reallocate store
   ****************************************************************************
   */
  template<class D>
  class VReconObj :  public  Vexpr<D,VReconObj<D> > {
  private:
    Vector<D>& a_;

  public:
    VReconObj(Vector<D>& a)
      : a_(a)
    { 
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
	Vector<D> y(N,debugtxt());
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

    bool mustcopy(const void *vaddr) const {
       return addrmatch(vaddr);
    }

    bool addrmatch(const void *vaddr) const {
      return vaddr==static_cast<const void*>(&a_);
    }



  };






  /****************************************************************************
   * VBinOp Operator Expression Template 
   *
   * vector/vector binary operator expressions
   ****************************************************************************
   */
  template<class D, class A, class B, class OP>
  class VBinOp : public  Vexpr<D,VBinOp<D,A,B,OP> > {

  private:
    const A& a_;
    const B& b_;

  public:
    VBinOp(const A& a, const B& b)
      : a_(a), b_(b)
    { 
    }

    inline const D operator[](const size_type i) const {  
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

    bool mustcopy(const void *vaddr) const {
      return (a_.mustcopy(vaddr)) || (b_.mustcopy(vaddr));
    }


    bool addrmatch(const void *vaddr) const {
      return (a_.addrmatch(vaddr)) || (b_.addrmatch(vaddr));
    }


  };







  /****************************************************************************
   * VecOpScal Operator Template 
   *
   * vector/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
  class VecOpScal : public Vexpr<D,VecOpScal<D,A,OP> > {

  private:
    const A& a_;
    D val_;

  public:
    VecOpScal(const A& a, const D b)
      : a_(a), val_(b)
    { }

    inline const D operator[](const size_type i) const { 
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

    bool mustcopy(const void *vaddr) const {
      return a_.mustcopy(vaddr);
    }

    bool addrmatch(const void *vaddr) const {
      return a_.addrmatch(vaddr);
    }



  };





  /****************************************************************************
   * ScalOpVec Operator Template 
   *
   * scalar/vector binary operators
   ****************************************************************************
   */


  template<class D, class B, class OP>
  class ScalOpVec : public Vexpr<D,ScalOpVec<D,B,OP> > {

  private:
    D val_;
    const B& b_;

  public:
    ScalOpVec(const D a, const B& b)
      :  val_(a), b_(b)
    { }

    inline const D operator[](const size_type i) const { 
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
    bool mustcopy(const void *vaddr) const {
      return b_.mustcopy(vaddr);
    }

    bool addrmatch(const void *vaddr) const {
      return b_.addrmatch(vaddr);
    }


  };




  /****************************************************************************
   * VFuncOp Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
  class VFuncOp  : public  Vexpr<D,VFuncOp<D,A,FUNC> >{
  
  private:
    const A& a_;
  
  public:
    VFuncOp(const A& a) : a_(a) { }


    inline const D operator[](const size_type i) const
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
    bool mustcopy(const void *vaddr) const {
      return a_.mustcopy(vaddr);
    }

    bool addrmatch(const void *vaddr) const {
      return a_.addrmatch(vaddr);
    }


  };











};

#endif
