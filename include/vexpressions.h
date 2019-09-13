#ifndef VEXPRESSIONS_H
#define VEXPRESSIONS_H



namespace matricks {

  template <class A>
    inline Vector<index_type> findtrue( const VorE<bool,A>& a );





  /****************************************************************************
   * VSubsetObj Expression Template 
   *
   * wrapper for a vector subset
   ****************************************************************************
   */
  template<class D>
    class VSubsetObj :  public  VWrapper<D,VSubsetObj<D> >, public VectorofPtrs {
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
	//	printf2("  VSubsetObj(Vector<D>& a, const std::initializer_list<index_type>& list)\n");  
      }
#endif // C++11
    
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
      //disp(ind);
      //disp(sizetotal());
      if (ind < 0) {
	ind = sizetotal() + ind;
      }
      //disp(ind);
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
      return "";
      //return debugtxt_VSubsetObj(a_.debugtxt(),ii_.debugtxt());
    }




  };







  /****************************************************************************
   * VJoinExpr Expression Template 
   *
   * expression for joining two VorE (RHS only)
   ****************************************************************************
   */

  template<class D, class A, class B>
    class VJoinExpr : public  Vexpr<D,VJoinExpr<D,A,B> >, public VectorofPtrs {

  private:
    const A& a_;
    const B& b_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

  VJoinExpr(const A& a, const B& b)
    : a_(a), b_(b)
    { 
      addAddresses(a_.getAddresses());
      addAddresses(b_.getAddresses());
    }

    inline const D operator[](const index_type i) const {  
      return this->data(i); 
    }

    inline const D data(const index_type i) const{
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
      return VE_VJoinExpr;
    }
    inline size_type size(void) const {
      return a_.size() +b_.size();
    }
    inline size_type sizetotal(void) const {
      return a_.size() +b_.size();
    }
    std::string debugtxt(void) const {
      return "";
      //      return debugtxt_VJoinExpr(a_.debugtxt(),ii_.debugtxt());
    }
  };


  /****************************************************************************
   * VJoinObj Expression Template 
   *
   * expression for joining two VorE (RHS only)
   ****************************************************************************
   */

  template<class D, class A, class B>
    class VJoinObj : public  VWrapper<D,VJoinObj<D,A,B> >, public VectorofPtrs {

  private:
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



    inline const D operator[](const index_type i) const {  
      return this->data(i); 
    }

    inline D& operator[](const index_type i) {  
      return this->data(i); 
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

    VJoinObj<D,A,B>& operator=(VReconObj<D>& b) { 
      return this->equals(b);
    }

    template <class C>
      VJoinObj<D,A,B>& operator=(const VorE<D,C>& rhs) { 
      printf2("VJoinObj<D,A,B>& operator=(const VorE<D,C>& rhs)\n");
      return this->equals(rhs);
    }

    template <class C>
      VJoinObj<D,A,B>& operator=(const MorE<D,C>& rhs) { 
      return this->equals(rhs);
    }

    VJoinObj<D,A,B>& operator=(const D d) { 
      return this->equals(d);
    }



    std::string debugtxt(void) const {
      return "";
      //      return debugtxt_VJoinExpr(a_.debugtxt(),ii_.debugtxt());
    }
  };


  


  /****************************************************************************
   * VSubMaskObj Expression Template 
   *
   * wrapper for a vector submask
   ****************************************************************************
   */
  template<class D>
    class VSubMaskObj :  public  VWrapper<D,VSubMaskObj<D> >, public VectorofPtrs {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& a_;
    const Vector<index_type>* ii_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

  VSubMaskObj(Vector<D>& a, const Vector<bool>& mask)
    : a_(a), ii_(new Vector<index_type>(findtrue(mask)))
      { 
	addAddress(&a_);
	addAddress(&ii_);
      }


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
      return "";
      //      return debugtxt_VSubMaskObj(a_.debugtxt(),ii_->debugtxt());
    }



  };






  /****************************************************************************
   * VReconObj Expression Template 
   *
   * reallocate store
   ****************************************************************************
   */
  template<class D>
    class VReconObj :  public  Vexpr<D,VReconObj<D> >, public VectorofPtrs {
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
      
      
      if ( x.addrmatch(&a_)) {    
	Vector<D> y(N);

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

      return a_;
    }

    std::string debugtxt(void) const {
      return  a_.debugtxt() +".resize()";
    }


  };








  /****************************************************************************
   * VRepExpr Expression Template 
   *
   * expression for repeating a VorE (RHS only)
   ****************************************************************************
   */

  template<class D, class A>
    class VRepExpr : public  Vexpr<D,VRepExpr<D,A> >, public VectorofPtrs {

  private:
    const A& a_;
    const size_type m_;
    const size_type N_;
  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

  VRepExpr(const A& a, const size_type m)
    : a_(a), m_(m), N_(a_.size())
      { 
	addAddresses(a_.getAddresses());
      }

    inline const D operator[](const index_type i) const {  
      return this->data(i); 
    }

    inline const D data(const index_type i) const{
      index_type index = index_type(i % N_);
      printf2("  i=%d, m_=%lu, i%%N_=%d\n",i,m_,index);
      return a_[index];
    }
    inline index_type index(index_type i) const{
      return i;
    }
    inline VETypes vetype(void) const {
      return VE_VRepExpr;
    }
    inline size_type size(void) const {
      return m_*a_.size();
    }
    inline size_type sizetotal(void) const {
      return m_*a_.size();
    }
    std::string debugtxt(void) const {
      return "";
      //      return debugtxt_VJoinExpr(a_.debugtxt(),ii_.debugtxt());
    }
  };




  /****************************************************************************
   * VBinOp Operator Expression Template 
   *
   * vector/vector binary operator expressions
   ****************************************************************************
   */
  template<class D, class A, class B, class OP>
    class VBinOp : public  Vexpr<D,VBinOp<D,A,B,OP> >, public VectorofPtrs {

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


  };


  /************************************************************
   *               Templates for Binary+scalar Operators 
   *
   * D = data type, e.g. double
   * A = either an Vector or a Vexpr
   * B = either an Vector or a Vexpr
   * N = int
   ************************************************************
   */

  template<class D, class A, class X>
    class VSeriesOp : public  Vexpr<D,VSeriesOp<D,A,X> >, public VectorofPtrs {

  private:
    const A& a_;
    const X& x_;
    const int N_;
    const D x0_;
    
  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

  VSeriesOp(const A& a, const X& x, const int N, const D x0)
    : a_(a), x_(x), N_(N), x0_(x0)
    { 
      addAddresses(a_.getAddresses());
      addAddresses(x_.getAddresses());
    }
  VSeriesOp(const A& a, const X& x, const int N)
    : a_(a), x_(x), N_(N), x0_(0)
    { 
      addAddresses(a_.getAddresses());
      addAddresses(x_.getAddresses());
    }

    inline const D operator[](const index_type i) const {
      const D x = x_[i] - x0_;
      D sum = 0;
      // TODO: check a_.size >= N
      D xpow = 1;
      for (int n = 0; n <= N_ ; n++) {
	D an = a_[n];
	if (an!=D(0)) {
	  sum += an*xpow;
	}
	//	if (i==2) {
	//	  mdisp(x0_,x_[i],x,sum,xpow,N_,n,an);
	//	}
	xpow *= x;
      }
      return sum; 
    }

    inline size_type size(void) const {
      return x_.size();
      // TODO: check a_.size >= N
    }

    inline VETypes vetype(void) const {
      return VE_VSeriesOp;
    }

    std::string debugtxt(void) const {
      // TODO: get this working
      std::string sa = a_.debugtxt();
      if (a_.vetype() != VE_Vector) 
	sa = "(" + sa + ")";
      std::string sx = x_.debugtxt();
      if (x_.vetype() != VE_Vector) 
	sx = "(" + sx + ")";
      std::string sN = printf2str("%d",N_);
      return "";
    }


  };



  template<class D, class A, class B, class X, class OP1, class OP2>
    class VSeriesOp2 : public  Vexpr<D,VSeriesOp2< D, A, B, X, OP1, OP2> >, public VectorofPtrs {

  private:
    const A& a_;
    const B& b_;
    const X& x_;
    const int N_;
    const D k1_;
    Vector<D>& k_;
    bool initialized;
    
  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

  VSeriesOp2(const A& a, const A& b, const X& x, const int N, const D k1)
    : a_(a), b_(b), x_(x), N_(N), k1_(k1), k_(*(new Vector<D>(N)))
      {
	addAddresses(a_.getAddresses());
	addAddresses(b_.getAddresses());
	addAddresses(x_.getAddresses());
	addAddresses(k_.getAddresses());
	for (int n = 0; n < N_ ; n++) {
	  k_[n] = n*k1_;
	}
      }
    ~VSeriesOp2(){
      delete &k_;
    }
    inline const D operator[](const index_type i) const {
      D sum = 0;
      // TODO: check a_.size >= N
      for (int n = 0; n < N_ ; n++) {
	D kx = k_[n]*x_[i];
	D an = a_[n];
	if (an != D(0)) {
	  sum += an*OP1::apply(kx);
	}
	D bn = b_[n];
	if (bn != D(0)) {
	  sum += bn*OP2::apply(kx);
	}
      }
      return sum; 
    }

    inline size_type size(void) const {
      return x_.size();
      // TODO: check a_.size >= N
      // TODO: check b_.size >= N
    }

    inline VETypes vetype(void) const {
      return VE_VSeriesOp2;
    }

    std::string debugtxt(void) const {
      // TODO: get this working
      std::string sa = a_.debugtxt();
      if (a_.vetype() != VE_Vector) 
	sa = "(" + sa + ")";
      std::string sx = x_.debugtxt();
      if (x_.vetype() != VE_Vector) 
	sx = "(" + sx + ")";
      std::string sN = printf2str("%d",N_);
      return OP1::debugtxt(sx);
    }


  };




  /****************************************************************************
   * VecOpScal Operator Template 
   *
   * vector/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
    class VecOpScal : public Vexpr<D,VecOpScal<D,A,OP> >, public VectorofPtrs {

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





  };





  /****************************************************************************
   * ScalOpVec Operator Template 
   *
   * scalar/vector binary operators
   ****************************************************************************
   */


  template<class D, class B, class OP>
    class ScalOpVec : public Vexpr<D,ScalOpVec<D,B,OP> >, public VectorofPtrs {

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



  };




  /****************************************************************************
   * VFuncOp Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
    class VFuncOp  : public  Vexpr<D,VFuncOp<D,A,FUNC> >, public VectorofPtrs {
  
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



  };





  /****************************************************************************
   * VBoolBinOp Operator Expression Template 
   *
   * vector/vector binary operator expressions
   ****************************************************************************
   */
  template<class D, class A, class B, class OP>
    class VBoolBinOp : public  Vexpr<bool,VBoolBinOp<D,A,B,OP> >, VectorofPtrs {

  private:
    const A& a_;
    const B& b_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

  VBoolBinOp(const A& a, const B& b)
    : a_(a), b_(b)
    { 
      addAddress(&a_);
      addAddress(&b_);
    }

    inline bool operator[](const index_type i) const {  
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
      return VE_VBoolBinOp;
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






  };







  /****************************************************************************
   * BoolVecOpScal Operator Template 
   *
   * vector/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
    class BoolVecOpScal : public Vexpr<bool,BoolVecOpScal<D,A,OP> >, VectorofPtrs {

  private:
    const A& a_;
    D val_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;


  BoolVecOpScal(const A& a, const D b)
    : a_(a), val_(b)
    {
      addAddress(&a_);
    }

    inline bool operator[](const index_type i) const { 
      return OP::apply(a_[i], val_); 
    }

    inline size_type size(void) const {
      return a_.size();
    }

    inline VETypes vetype(void) const {
      return VE_BoolVecOpScal;
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






  };





  /****************************************************************************
   * BoolScalOpVec Operator Template 
   *
   * scalar/vector binary operators
   ****************************************************************************
   */


  template<class D, class B, class OP>
    class BoolScalOpVec : public Vexpr<bool,BoolScalOpVec<D,B,OP> >, VectorofPtrs {

  private:
    D val_;
    const B& b_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

  BoolScalOpVec(const D a, const B& b)
    :  val_(a), b_(b)
    {
      addAddress(&b_);
    }

    inline bool operator[](const index_type i) const { 
      return OP::apply(val_,b_[i]); 
    }

    inline size_type size(void) const {
      return b_.size();
    }

    inline VETypes vetype(void) const {
      return VE_BoolScalOpVec;
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




  };




  /****************************************************************************
   * VBoolFuncOp Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
    class VBoolFuncOp  : public  Vexpr<bool,VBoolFuncOp<D,A,FUNC> >, VectorofPtrs{
  
  private:
    const A& a_;
  
  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

  VBoolFuncOp(const A& a) : a_(a) {
      addAddress(&a_);
    }


    inline bool operator[](const index_type i) const
    { return FUNC::apply(a_[i]); }

    inline size_type size(void) const {
      return a_.size();
    }

    inline VETypes vetype(void) const {
      return VE_VBoolFuncOp;
    }

    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      return FUNC::debugtxt(sa);
    }




  };













  /****************************************************************************
   * CVecOpScal Operator Template 
   *
   * complex vector = binfunc(ComplexOrRealVector,RealScalar) binary operators 
   ****************************************************************************
   */
  template<class D, class A, class OP>
    class CVecOpScal : public Vexpr<std::complex<D>, CVecOpScal<D,A,OP> >, VectorofPtrs {

  private:
    const A& a_;
    const D val_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

  CVecOpScal(const A& a, const D b)
    : a_(a), val_(b)
    {
      addAddress(&a_);
    }

    inline const std::complex<D> operator[](const index_type i) const { 
      return OP::apply(a_[i], val_); 
    }

    inline size_type size(void) const {
      return a_.size();
    }

    inline VETypes vetype(void) const {
      return VE_CVecOpScal;
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



  };






  /****************************************************************************
   * CScalOpVec Operator Template 
   *
   * complex vector = binfunc(RealScalar,ComplexOrRealVector) binary operators 
   ****************************************************************************
   */
  template<class D, class B, class OP>
    class CScalOpVec : public Vexpr<std::complex<D>,CScalOpVec<D,B,OP> >, VectorofPtrs {
  private:
    const D val_;
    const B& b_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

  CScalOpVec(const D a, const B& b)
    : val_(a), b_(b)
    {
      addAddress(&b_);
    }

    inline const std::complex<D> operator[](const index_type i) const { 
      return OP::apply(val_,b_[i]); 
    }

    inline size_type size(void) const {
      return b_.size();
    }

    inline VETypes vetype(void) const {
      return VE_CScalOpVec;
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


  };





  /****************************************************************************
   * VRealFromComplex Expression Template 
   *
   * used for accessing real/imag part of complex vector
   ****************************************************************************
   */
  template <class D, class OP>
    class VRealFromComplex : public  VWrapper<D,VRealFromComplex<D,OP> >, VectorofPtrs {
  private:
    Vector<std::complex<D> >& a_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

  VRealFromComplex(Vector<std::complex<D> >& a)
    :   a_(a)
    { 
      addAddress(&a_);
    }

    inline const D data(index_type i) const{
      return OP::give(a_[i]);
    }
    inline D& data(index_type i) {
      return OP::give(a_[i]);
    }


    inline index_type index(index_type i) const{
      return i;
    }


    inline size_type size(void) const {
      return a_.size();
    }

    inline size_type asize(void) const {
      return a_.size();
    }

    inline VETypes vetype(void) const {
      return VE_VRealFromComplex;
    }

    template <class B>
      VRealFromComplex<D,OP>& operator=(const B& b) { 
      return equals(b);
    }

    template <class OP2>
      VRealFromComplex<D,OP>& operator=(const VRealFromComplex<D,OP2>& b) { 
      return equals(b);
    }

    std::string debugtxt(void) const {
      return a_.debugtxt();
      //      return debugtxt_VSliceObj(a_.debugtxt(),start_,end_,step_);
    }




  };




};  //namespace matricks

#endif 
