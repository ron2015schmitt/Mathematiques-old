#ifndef MATRICKS__EXPRESSIONS_H
#define MATRICKS__EXPRESSIONS_H



namespace matricks {

  template <class A>
    inline Vector<index_type> findtrue( const TensorR<bool,A>& a );


  /****************************************************************************
   * TERW_Subset Expression Template 
   *
   * wrapper for a vector subset
   ****************************************************************************
   */
  template<class D>
    class TERW_Subset :  public  TExpressionRW<D,TERW_Subset<D> > {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& a_;
    const Vector<index_type>& ii_;
    const bool delete_ii_;
    VectorofPtrs *vptrs;
  public:

  TERW_Subset(Vector<D>& a, const Vector<index_type>& ii)
    : a_(a), ii_(ii), delete_ii_(false) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&ii_);
    }
#if CPP11 == 1    
  TERW_Subset(Vector<D>& a, const std::initializer_list<index_type>& list)
    : a_(a), ii_(*(new Vector<index_type>(list))), delete_ii_(true) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&ii_);
    }
#endif // C++11
    
    ~TERW_Subset() {
      if (delete_ii_) delete &ii_;
      delete vptrs;
    }


    inline const D operator[](const index_type i) const{
      index_type ind = ii_[i];
      if (ind < 0) {
	ind = a_.size() + ind;
      }
      return a_[ind];
    }
    inline  D& operator[](const index_type i) {
      index_type ind = ii_[i];
      if (ind < 0) {
	ind = a_.size() + ind;
      }
      return a_[ind];
    }


    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return ii_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "TERW_Subset";
    }


    TERW_Subset<D>& operator=(TERW_Resize<D>& b) { 
      return this->equals(b);
    }

    template <class B>
      TERW_Subset<D>& operator=(const TensorR<D,B>& rhs) { 
      return this->equals(rhs);
    }

    TERW_Subset<D>& operator=(const D d) { 
      return this->equals(d);
    }
    
    TERW_Subset<D>& operator=(const TERW_Subset<D>& b) { 
      return this->equals(b);
    }

    
#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //return expression_TERW_Subset(a_.expression(),ii_.expression());
    }
#endif



  };








  


  /****************************************************************************
   * TERW_Submask Expression Template 
   *
   * wrapper for a vector submask
   ****************************************************************************
   */
  template<class D>
    class TERW_Submask :  public  TExpressionRW<D,TERW_Submask<D> > {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& a_;
    const Vector<index_type>* ii_;
    VectorofPtrs *vptrs;

  public:


  TERW_Submask(Vector<D>& a, const Vector<bool>& mask)
    : a_(a), ii_(new Vector<index_type>(findtrue(mask))) { 
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&ii_);
    }


    ~TERW_Submask(){ 
      delete  ii_;
      delete vptrs;
    }

    inline const D operator[](const index_type i) const{
      index_type ind = (*ii_)[i];
      return a_[ind];
    }
    inline  D& operator[](const index_type i) {
      index_type ind = (*ii_)[i];
      return a_[ind];
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return ii_->size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "TERW_Submask";
    }


    TERW_Submask<D>& operator=(TERW_Resize<D>& b) { 
      return this->equals(b);
    }

    template <class B>
      TERW_Submask<D>& operator=(const TensorR<D,B>& rhs) { 
      return this->equals(rhs);
    }

    TERW_Submask<D>& operator=(const D d) { 
      return this->equals(d);
    }
    
    TERW_Submask<D>& operator=(const TERW_Submask<D>& b) { 
      return this->equals(b);
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //      return expression_TERW_Submask(a_.expression(),ii_->expression());
    }
#endif 



  };






  /****************************************************************************
   * TERW_Resize Expression Template 
   *
   * reallocate store
   ****************************************************************************
   */
  template<class D>
    class TERW_Resize :  public  TExpressionR<D,TERW_Resize<D> > {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& a_;
    VectorofPtrs *vptrs;

  public:


  TERW_Resize(Vector<D>& a)
    : a_(a)
    { 
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~TERW_Resize() {
      delete vptrs;
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    // TODO:  not sure what to use for this
    inline size_type size(void) const {
      return a_->size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "TERW_Resize";
    }

    template <class A>
      Vector<D>& operator=(const TensorR<D,A>& x) { 
      size_type N = x.size();
      if ( common(*this,x) ) {    
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

    Vector<D>& operator=(const TERW_Resize<D>& b) { 

      return a_;
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return  a_.expression() +".resize()";
    }
#endif 


  };





  /****************************************************************************
   * TER_Unary Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
    class TER_Unary  : public  TExpressionR<D,TER_Unary<D,A,FUNC> > {
  
  private:
    const A& a_;
    VectorofPtrs *vptrs;
  
  public:



  TER_Unary(const A& a) : a_(a) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }
    
    ~TER_Unary() {
      delete vptrs;
    }

    inline const D operator[](const index_type i) const
    { return FUNC::apply(a_[i]); }
    
    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "TER_Unary";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      std::string sa = a_.expression();
      return FUNC::expression(sa);
    }
#endif


  };







  /****************************************************************************
   * TER_Binary Operator Expression Template 
   *
   * vector/vector binary operator expressions
   ****************************************************************************
   */
  template<class D, class A, class B, class OP>
    class TER_Binary : public  TExpressionR<D,TER_Binary<D,A,B,OP> > {

  private:
    const A& a_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:


  TER_Binary(const A& a, const B& b)
    : a_(a), b_(b) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
    }

    ~TER_Binary() {
      delete vptrs;
    }

    inline const D operator[](const index_type i) const {  
      return OP::apply(a_[i], b_[i]); 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      if ( a_.size() != b_.size() ) {
	return badsize;
      } else {
	return a_.size();
      }
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "TER_Binary";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::string sb = b_.expression(); */
      /* if (b_.vetype() != VE_Vector)  */
      /* 	sb = "(" + sb + ")"; */
      /* return OP::expression(sa,sb); */
      // use typeof or typeid isnteadof  the above
      return "";
    }
#endif 


  };


  /************************************************************
   *               Templates for Binary+scalar Operators 
   *
   * D = data type, e.g. double
   * A = either an Vector or a TExpressionR
   * B = either an Vector or a TExpressionR
   * N = int
   ************************************************************
   */

  template<class D, class A, class X>
    class TER_Series : public  TExpressionR<D,TER_Series<D,A,X> > {

  private:
    const A& a_;
    const X& x_;
    const int N_;
    const D x0_;
    VectorofPtrs *vptrs;
    
  public:


  TER_Series(const A& a, const X& x, const int N, const D x0)
    : a_(a), x_(x), N_(N), x0_(x0) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(x_.getAddresses());
    }
  TER_Series(const A& a, const X& x, const int N)
    : a_(a), x_(x), N_(N), x0_(0) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(x_.getAddresses());
    }

    ~TER_Series() {
      delete vptrs;
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

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return x_.size();
      // TODO: check a_.size >= N
    }

    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "TER_Series";
    }
  

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      // TODO: get this working
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::string sx = x_.expression(); */
      /* if (x_.vetype() != VE_Vector)  */
      /* 	sx = "(" + sx + ")"; */
      /* std::string sN = display::printf2str("%d",N_); */
      return "";
    }
#endif 


  };



  template<class D, class A, class B, class X, class OP1, class OP2>
    class TER_Series2 : public  TExpressionR<D,TER_Series2< D, A, B, X, OP1, OP2> > {

  private:
    const A& a_;
    const B& b_;
    const X& x_;
    const int N_;
    const D k1_;
    Vector<D>& k_;
    bool initialized;
    VectorofPtrs *vptrs;
    
  public:


  TER_Series2(const A& a, const A& b, const X& x, const int N, const D k1)
    : a_(a), b_(b), x_(x), N_(N), k1_(k1), k_(*(new Vector<D>(N))) {
      
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
      vptrs->add(x_.getAddresses());
      vptrs->add(k_.getAddresses());
      
      for (int n = 0; n < N_ ; n++) {
	k_[n] = n*k1_;
      }
    }
    ~TER_Series2(){
      delete &k_;
      delete vptrs;
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

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return x_.size();
    }
    size_type ndims(void) const {
      return x_.ndims();
    }
    Dimensions dims(void) const {
      return x_.dims();
    }
    static std::string classname(void)  {
      return "TER_Series2";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      // TODO: get this working
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::string sx = x_.expression(); */
      /* if (x_.vetype() != VE_Vector)  */
      /* 	sx = "(" + sx + ")"; */
      /* std::string sN = display::printf2str("%d",N_); */
      /* return OP1::expression(sx); */
      return "";
    }
#endif 


  };




  /****************************************************************************
   * TER_TensorOpScalar Operator Template 
   *
   * vector/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
    class TER_TensorOpScalar : public TExpressionR<D,TER_TensorOpScalar<D,A,OP> > {

  private:
    const A& a_;
    D val_;
    VectorofPtrs *vptrs;

  public:


  TER_TensorOpScalar(const A& a, const D b)
    : a_(a), val_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }

    ~TER_TensorOpScalar() {
      delete vptrs;
    }

    inline const D operator[](const index_type i) const { 
      return OP::apply(a_[i], val_); 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "TER_TensorOpScalar";
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::ostringstream stream; */
      /* stream << val_; */
      /* std::string sb = stream.str(); */
      /* return OP::expression(sa,sb); */
      return "";
    }
#endif 





  };





  /****************************************************************************
   * TER_ScalarOpTensor Operator Template 
   *
   * scalar/vector binary operators
   ****************************************************************************
   */


  template<class D, class B, class OP>
    class TER_ScalarOpTensor : public TExpressionR<D,TER_ScalarOpTensor<D,B,OP> > {

  private:
    D val_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:



  TER_ScalarOpTensor(const D a, const B& b)
    :  val_(a), b_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(b_.getAddresses());
    }
    ~TER_ScalarOpTensor() {
      delete vptrs;
    }

    inline const D operator[](const index_type i) const { 
      return OP::apply(val_,b_[i]); 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return b_.size();
    }
    size_type ndims(void) const {
      return b_.ndims();
    }
    Dimensions dims(void) const {
      return b_.dims();
    }
    static std::string classname(void)  {
      return "TER_ScalarOpTensor";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::ostringstream stream; */
      /* stream << val_; */
      /* std::string sa = stream.str(); */
      /* std::string sb = b_.expression(); */
      /* if (b_.vetype() != VE_Vector)  */
      /* 	sb = "(" + sb + ")"; */
      /* return OP::expression(sa,sb); */
      return "";
    }
#endif 



  };






  /****************************************************************************
   * TER_Bool_Unary Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
    class TER_Bool_Unary  : public  TExpressionR<bool,TER_Bool_Unary<D,A,FUNC> >{
  
  private:
    const A& a_;
    VectorofPtrs *vptrs;
  
  public:


  TER_Bool_Unary(const A& a) : a_(a) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~TER_Bool_Unary() {
      delete vptrs;
    }

    inline bool operator[](const index_type i) const
    { return FUNC::apply(a_[i]); }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "TER_Bool_Unary";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      std::string sa = a_.expression();
      return FUNC::expression(sa);
    }
#endif 

  };







  /****************************************************************************
   * TER_Bool_Binary Operator Expression Template 
   *
   * vector/vector binary operator expressions
   ****************************************************************************
   */
  template<class D, class A, class B, class OP>
    class TER_Bool_Binary : public  TExpressionR<bool,TER_Bool_Binary<D,A,B,OP> > {

  private:
    const A& a_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:


  TER_Bool_Binary(const A& a, const B& b)
    : a_(a), b_(b) { 
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&b_);
    }

    ~TER_Bool_Binary() {
      delete vptrs;
    }


    inline bool operator[](const index_type i) const {  
      return OP::apply(a_[i], b_[i]); 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      if ( a_.size() != b_.size() ) {
	return badsize;
      } else {
	return a_.size();
      }
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "TER_Bool_Binary";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::string sb = b_.expression(); */
      /* if (b_.vetype() != VE_Vector)  */
      /* 	sb = "(" + sb + ")"; */
      /* return OP::expression(sa,sb); */
      return "";
    }
#endif 

  };







  /****************************************************************************
   * TER_Bool_TensorOpScalar Operator Template 
   *
   * vector/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
    class TER_Bool_TensorOpScalar : public TExpressionR<bool,TER_Bool_TensorOpScalar<D,A,OP> > {

  private:
    const A& a_;
    D val_;
    VectorofPtrs *vptrs;

  public:



  TER_Bool_TensorOpScalar(const A& a, const D b)
    : a_(a), val_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~TER_Bool_TensorOpScalar() {
      delete vptrs;
    }

    inline bool operator[](const index_type i) const { 
      return OP::apply(a_[i], val_); 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "TER_Bool_TensorOpScalar";
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::ostringstream stream; */
      /* stream << val_; */
      /* std::string sb = stream.str(); */
      /* return OP::expression(sa,sb); */
      return "";
    }
#endif 

  };





  /****************************************************************************
   * TER_Bool_ScalarOpTensor Operator Template 
   *
   * scalar/vector binary operators
   ****************************************************************************
   */


  template<class D, class B, class OP>
    class TER_Bool_ScalarOpTensor : public TExpressionR<bool,TER_Bool_ScalarOpTensor<D,B,OP> > {

  private:
    D val_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:


  TER_Bool_ScalarOpTensor(const D a, const B& b)
    :  val_(a), b_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(&b_);
    }

    ~TER_Bool_ScalarOpTensor() {
      delete vptrs;
    }

    inline bool operator[](const index_type i) const { 
      return OP::apply(val_,b_[i]); 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return b_.size();
    }
    size_type ndims(void) const {
      return b_.ndims();
    }
    Dimensions dims(void) const {
      return b_.dims();
    }
    static std::string classname(void)  {
      return "TER_Bool_ScalarOpTensor";
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::ostringstream stream; */
      /* stream << val_; */
      /* std::string sa = stream.str(); */
      /* std::string sb = b_.expression(); */
      /* if (b_.vetype() != VE_Vector)  */
      /* 	sb = "(" + sb + ")"; */
      /* return OP::expression(sa,sb); */
      return "";
    }
#endif 




  };









  /****************************************************************************
   * TER_Cplx_TensorOpScalar Operator Template 
   *
   * complex vector = binfunc(ComplexOrRealVector,RealScalar) binary operators 
   ****************************************************************************
   */
  template<class D, class A, class OP>
    class TER_Cplx_TensorOpScalar : public TExpressionR<std::complex<D>, TER_Cplx_TensorOpScalar<D,A,OP> > {

  private:
    const A& a_;
    const D val_;
    VectorofPtrs *vptrs;

  public:


  TER_Cplx_TensorOpScalar(const A& a, const D b)
    : a_(a), val_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~TER_Cplx_TensorOpScalar() {
      delete vptrs;
    }

    inline const std::complex<D> operator[](const index_type i) const { 
      return OP::apply(a_[i], val_); 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "TER_Cplx_TensorOpScalar";
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::string sa = a_.expression(); */
      /* if (a_.vetype() != VE_Vector)  */
      /* 	sa = "(" + sa + ")"; */
      /* std::ostringstream stream; */
      /* stream << val_; */
      /* std::string sb = stream.str(); */
      /* return OP::expression(sa,sb); */
      return "";
    }
#endif 



  };






  /****************************************************************************
   * TER_Cplx_ScalarOpTensor Operator Template 
   *
   * complex vector = binfunc(RealScalar,ComplexOrRealVector) binary operators 
   ****************************************************************************
   */
  template<class D, class B, class OP>
    class TER_Cplx_ScalarOpTensor : public TExpressionR<std::complex<D>,TER_Cplx_ScalarOpTensor<D,B,OP> > {
  private:
    const D val_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:


  TER_Cplx_ScalarOpTensor(const D a, const B& b)
    : val_(a), b_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(&b_);
    }

    ~TER_Cplx_ScalarOpTensor() {
      delete vptrs;
    }

    inline const std::complex<D> operator[](const index_type i) const { 
      return OP::apply(val_,b_[i]); 
    }

    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return b_.size();
    }
    size_type ndims(void) const {
      return b_.ndims();
    }
    Dimensions dims(void) const {
      return b_.dims();
    }
    static std::string classname(void)  {
      return "TER_Cplx_ScalarOpTensor";
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      /* std::ostringstream stream; */
      /* stream << val_; */
      /* std::string sa = stream.str(); */
      /* std::string sb = b_.expression(); */
      /* if (b_.vetype() != VE_Vector)  */
      /* 	sb = "(" + sb + ")"; */
      /* return OP::expression(sa,sb); */
      return "";
    }
#endif 


  };





  /****************************************************************************
   * TER_RealFromComplex Expression Template 
   *
   * used for accessing real/imag part of complex vector
   ****************************************************************************
   */
  template <class D, class OP>
    class TER_RealFromComplex : public  TExpressionRW<D,TER_RealFromComplex<D,OP> > {
  private:
    Vector<std::complex<D> >& a_;
    VectorofPtrs *vptrs;

  public:


  TER_RealFromComplex(Vector<std::complex<D> >& a)
    :   a_(a) { 
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~TER_RealFromComplex() {
      delete vptrs;
    }

    inline const D operator[](index_type i) const{
      return OP::give(a_[i]);
    }
    inline D& operator[](index_type i) {
      return OP::give(a_[i]);
    }



    inline VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    inline size_type size(void) const {
      return a_.size();
    }
    size_type ndims(void) const {
      return a_.ndims();
    }
    Dimensions dims(void) const {
      return a_.dims();
    }
    static std::string classname(void)  {
      return "TER_RealFromComplex";
    }


    template <class B>
      TER_RealFromComplex<D,OP>& operator=(const B& b) { 
      return equals(b);
    }

    template <class OP2>
      TER_RealFromComplex<D,OP>& operator=(const TER_RealFromComplex<D,OP2>& b) { 
      return equals(b);
    }

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return a_.expression();
      //      return expression_VSliceObj(a_.expression(),start_,end_,step_);
    }
#endif 

  };




};  //namespace matricks

#endif 
