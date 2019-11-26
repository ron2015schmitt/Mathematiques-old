#ifndef MATRICKS__EXPRESSIONS_H
#define MATRICKS__EXPRESSIONS_H



namespace matricks {

  template <class A> Vector<index_type> findtrue( const TensorR<bool,A>& a );


  /****************************************************************************
   * TERW_Subset Expression Template 
   *
   * wrapper for a vector subset
   ****************************************************************************
   */
  template<class D, int M>
    class TERW_Subset :  public  TensorRW<D,TERW_Subset<D,M> > {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& a_;
    const Vector<index_type>& ii_;
    const bool delete_ii_;
    VectorofPtrs *vptrs;
  public:
    typedef typename NumberType<D>::Type MyNumberType;

  TERW_Subset(Vector<D>& a, const Vector<index_type>& ii)
    : a_(a), ii_(ii), delete_ii_(false) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&ii_);
    }
  TERW_Subset(Vector<D>& a, const std::initializer_list<index_type>& list)
    : a_(a), ii_(*(new Vector<index_type>(list))), delete_ii_(true) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&ii_);
    }
    
    ~TERW_Subset() {
      if (delete_ii_) delete &ii_;
      delete vptrs;
    }


    const MyNumberType operator[](const index_type i) const{
      index_type ind = ii_[i];
      if (ind < 0) {
	ind = a_.size() + ind;
      }
      return a_[ind];
    }
     MyNumberType& operator[](const index_type i) {
      index_type ind = ii_[i];
      if (ind < 0) {
	ind = a_.size() + ind;
      }
      return a_[ind];
    }


    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return ii_.size();
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
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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
  template<class D, int M>
    class TERW_Submask :  public  TensorRW<D,TERW_Submask<D,M> > {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& a_;
    const Vector<index_type>* ii_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


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

    const MyNumberType operator[](const index_type i) const{
      index_type ind = (*ii_)[i];
      return a_[ind];
    }
     MyNumberType& operator[](const index_type i) {
      index_type ind = (*ii_)[i];
      return a_[ind];
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return ii_->size();
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
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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
  template<class D, int M>
    class TERW_Resize :  public  TensorR<D,TERW_Resize<D,M> > {
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& a_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  TERW_Resize(Vector<D>& a)
    : a_(a)
    { 
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~TERW_Resize() {
      delete vptrs;
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    // TODO:  not sure what to use for this
    size_type size(void) const {
      return a_->size();
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
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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
   * TER_RealFromComplex Expression Template 
   *
   * used for accessing real/imag part of complex vector
   ****************************************************************************
   */
  template <class D, class OP, int M>
    class TER_RealFromComplex : public  TensorRW<D,TER_RealFromComplex<D,OP,M> > {
  private:
    Vector<std::complex<D> >& a_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  TER_RealFromComplex(Vector<std::complex<D> >& a)
    :   a_(a) { 
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~TER_RealFromComplex() {
      delete vptrs;
    }

    const MyNumberType operator[](index_type i) const{
      return OP::give(a_[i]);
    }
    MyNumberType& operator[](index_type i) {
      return OP::give(a_[i]);
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
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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


  /****************************************************************************
   * TER_Unary Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC, int M>
    class TER_Unary  : public  TensorR<D,TER_Unary<D,A,FUNC,M>> {
  
  private:
    const A& a_;
    VectorofPtrs *vptrs;
  
  public:
    typedef typename NumberType<D>::Type MyNumberType;



  TER_Unary(const A& a) : a_(a) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      disp3(a);
    }
    
  ~TER_Unary() {
      delete vptrs;
    }

  // -------------------- deep access[] --------------------
  // NOTE: indexes over [0] to [deepsize()]
  // -------------------------------------------------------------
  
  const MyNumberType operator[](const index_type i) const {
    return FUNC::apply(a_[i]);
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
  Dimensions tdims(void) const {
      return this->dims();
    }
  bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
  size_type deepsize(void) const {
    if constexpr(M<2) {
      return this->size();
    } else {
      return (this->size())*(this->eldeepsize());
    }
  }


  std::string classname() const {
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
  template<class D, class A, class B, class OP, int M>
    class TER_Binary : public  TensorR<D,TER_Binary<D,A,B,OP,M> > {

  private:
    const A* a_;
    const B* b_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;
    typedef D TypeD;
    typedef A TypeA;
    typedef B TypeB;
    TER_Binary()
      : a_(nullptr), b_(nullptr)
      {
	vptrs=nullptr;
      }

  TER_Binary(const A& a, const B& b)
    : a_(&a), b_(&b) {
      vptrs = new VectorofPtrs();
      vptrs->add(a.getAddresses());
      vptrs->add(b.getAddresses());
    }

    ~TER_Binary() {
      delete vptrs;
    }

    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************
    const MyNumberType dat(const index_type i) const {
      return OP::apply((*a_).dat(i), (*b_).dat(i));
    }

    //**********************************************************************
    //***************** Element ACCESS as an array *************************
    //**********************************************************************
    const MyNumberType operator[](const index_type i) const {
      return OP::apply((*a_)[i], (*b_)[i]);
    }

    
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return (*a_).size();
    }
    size_type ndims(void) const {
      return (*a_).ndims();
    }
    Dimensions dims(void) const {
      return (*a_).dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_->elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_->eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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
   * A = either an Vector or a TensorR
   * B = either an Vector or a TensorR
   * N = int
   ************************************************************
   */

  template<class D, class A, class X, int M>
    class TER_Series : public  TensorR<D,TER_Series<D,A,X,M> > {

  private:
    const A& a_;
    const X& x_;
    const int N_;
    const D x0_;
    VectorofPtrs *vptrs;
    
  public:
    typedef typename NumberType<D>::Type MyNumberType;


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

    const MyNumberType operator[](const index_type i) const {
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

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return x_.size();
      // TODO: check a_.size >= N
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
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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





  
  template<class D, class A, class B, class X, class OP1, class OP2, int M>
    class TER_Series2 : public  TensorR<D,TER_Series2< D, A, B, X, OP1, OP2> > {

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
    typedef typename NumberType<D>::Type MyNumberType;


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

    const MyNumberType operator[](const index_type i) const {
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

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return x_.size();
    }
    size_type ndims(void) const {
      return x_.ndims();
    }
    Dimensions dims(void) const {
      return x_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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


  template<class D, class A, class OP, int M>
    class TER_TensorOpScalar : public TensorR<D,TER_TensorOpScalar<D,A,OP,M> > {

  private:
    const A& a_;
    D val_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  TER_TensorOpScalar(const A& a, const D b)
    : a_(a), val_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }

    ~TER_TensorOpScalar() {
      delete vptrs;
    }

    const MyNumberType operator[](const index_type i) const { 
      return OP::apply(a_[i], val_); 
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
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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


  template<class D, class B, class OP, int M>
    class TER_ScalarOpTensor : public TensorR<D,TER_ScalarOpTensor<D,B,OP,M> > {

  private:
    D val_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;



  TER_ScalarOpTensor(const D a, const B& b)
    :  val_(a), b_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(b_.getAddresses());
    }
    ~TER_ScalarOpTensor() {
      delete vptrs;
    }

    const MyNumberType operator[](const index_type i) const { 
      return OP::apply(val_,b_[i]); 
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return b_.size();
    }
    size_type ndims(void) const {
      return b_.ndims();
    }
    Dimensions dims(void) const {
      return b_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return b_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return b_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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




  //================== NEW PARDGM  ===================================

    /****************************************************************************
   * TER_TensorOpScalar_New Operator Template 
   *
   * vector/scalar binary operators
   ****************************************************************************
   */


  template <class DOUT, class A, class D, class OP, int M>
    class TER_TensorOpScalar_New : public TensorR<DOUT,TER_TensorOpScalar_New<DOUT,A,D,OP,M> > {

  private:
    const A& a_;
    D val_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  TER_TensorOpScalar_New(const A& a, const D b)
    : a_(a), val_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }

    ~TER_TensorOpScalar_New() {
      delete vptrs;
    }

    const DOUT operator[](const index_type i) const { 
      return OP::apply(a_[i], val_); 
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
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
      return "TER_TensorOpScalar_New";
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
   * TER_ScalarOpTensor_New Operator Template 
   *
   * scalar/vector binary operators
   ****************************************************************************
   */


  template <class DOUT, class D, class B, class OP, int M>
    class TER_ScalarOpTensor_New : public TensorR<DOUT,TER_ScalarOpTensor_New<DOUT,D,B,OP,M> > {

  private:
    D val_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;



  TER_ScalarOpTensor_New(const D a, const B& b)
    :  val_(a), b_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(b_.getAddresses());
    }
    ~TER_ScalarOpTensor_New() {
      delete vptrs;
    }

    const DOUT operator[](const index_type i) const { 
      return OP::apply(val_,b_[i]); 
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return b_.size();
    }
    size_type ndims(void) const {
      return b_.ndims();
    }
    Dimensions dims(void) const {
      return b_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return b_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return b_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
      return "TER_ScalarOpTensor_New";
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


  // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^NEW PARDIGM^^^^^^^^^^^^^^^^^^^^
  




  /****************************************************************************
   * TER_Bool_Unary Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC, int M>
    class TER_Bool_Unary  : public  TensorR<bool,TER_Bool_Unary<D,A,FUNC,M> >{
  
  private:
    const A& a_;
    VectorofPtrs *vptrs;
  
  public:
    typedef typename NumberType<D>::Type MyNumberType;


  TER_Bool_Unary(const A& a) : a_(a) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~TER_Bool_Unary() {
      delete vptrs;
    }

    bool operator[](const index_type i) const
    { return FUNC::apply(a_[i]); }

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
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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
  template<class D, class A, class B, class OP, int M>
    class TER_Bool_Binary : public  TensorR<bool,TER_Bool_Binary<D,A,B,OP,M> > {

  private:
    const A& a_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  TER_Bool_Binary(const A& a, const B& b)
    : a_(a), b_(b) { 
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&b_);
    }

    ~TER_Bool_Binary() {
      delete vptrs;
    }


    bool operator[](const index_type i) const {  
      return OP::apply(a_[i], b_[i]); 
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
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
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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
   * TER_Bool_Binary2 Operator Expression Template 
   *
   * vector/vector tertiary operator expressions
   ****************************************************************************
   */
  template<class D, class A, class B, class OP, int M>
    class TER_Bool_Binary2 : public  TensorR<bool,TER_Bool_Binary2<D,A,B,OP,M> > {

  public:
    typedef typename FundamentalType<D>::Type DREAL;

    
  private:
    const A& a_;
    const B& b_;
    const DREAL d_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  TER_Bool_Binary2(const A& a, const B& b, const DREAL& d)
    : a_(a), b_(b), d_(d) { 
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
      vptrs->add(&b_);
    }

    ~TER_Bool_Binary2() {
      delete vptrs;
    }


    bool operator[](const index_type i) const {  
      return OP::apply(a_[i], b_[i], d_); 
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
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
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
      return "TER_Bool_Binary2";
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


  template<class D, class A, class OP, int M>
    class TER_Bool_TensorOpScalar : public TensorR<bool,TER_Bool_TensorOpScalar<D,A,OP,M> > {

  private:
    const A& a_;
    D val_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;



  TER_Bool_TensorOpScalar(const A& a, const D b)
    : a_(a), val_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~TER_Bool_TensorOpScalar() {
      delete vptrs;
    }

    bool operator[](const index_type i) const { 
      return OP::apply(a_[i], val_); 
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
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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


  template<class D, class B, class OP, int M>
    class TER_Bool_ScalarOpTensor : public TensorR<bool,TER_Bool_ScalarOpTensor<D,B,OP,M> > {

  private:
    D val_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  TER_Bool_ScalarOpTensor(const D a, const B& b)
    :  val_(a), b_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(&b_);
    }

    ~TER_Bool_ScalarOpTensor() {
      delete vptrs;
    }

    bool operator[](const index_type i) const { 
      return OP::apply(val_,b_[i]); 
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return b_.size();
    }
    size_type ndims(void) const {
      return b_.ndims();
    }
    Dimensions dims(void) const {
      return b_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return b_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return b_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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
  template<class D, class A, class OP, int M>
    class TER_Cplx_TensorOpScalar : public TensorR<std::complex<D>, TER_Cplx_TensorOpScalar<D,A,OP,M> > {

  private:
    const A& a_;
    const D val_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  TER_Cplx_TensorOpScalar(const A& a, const D b)
    : a_(a), val_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(&a_);
    }

    ~TER_Cplx_TensorOpScalar() {
      delete vptrs;
    }

    const std::complex<D> operator[](const index_type i) const { 
      return OP::apply(a_[i], val_); 
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
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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
  template<class D, class B, class OP, int M>
    class TER_Cplx_ScalarOpTensor : public TensorR<std::complex<D>,TER_Cplx_ScalarOpTensor<D,B,OP,M> > {
  private:
    const D val_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  TER_Cplx_ScalarOpTensor(const D a, const B& b)
    : val_(a), b_(b) {
      vptrs = new VectorofPtrs();
      vptrs->add(&b_);
    }

    ~TER_Cplx_ScalarOpTensor() {
      delete vptrs;
    }

    const std::complex<D> operator[](const index_type i) const { 
      return OP::apply(val_,b_[i]); 
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return b_.size();
    }
    size_type ndims(void) const {
      return b_.ndims();
    }
    Dimensions dims(void) const {
      return b_.dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return b_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return b_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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
   * TERW_Transpose
   *
   * 
   ****************************************************************************
   */

  template<class D, class A, class FUNC, int M>
    class TERW_Transpose  : public  TensorRW<D,TERW_Transpose<D,A,FUNC,M> > {
  
  private:
    A& a_;
    VectorofPtrs *vptrs;
    Dimensions *rdims;
  public:
    typedef typename NumberType<D>::Type MyNumberType;



  TERW_Transpose(A& a) : a_(a) {
      rdims = &(a_.dims().getReverse());
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }
    
    ~TERW_Transpose() {
      delete rdims;
      delete vptrs;
    }

    const MyNumberType operator[](const index_type index1) const {
      const Indices inds1 = rdims->indices(index1);
      const Indices inds2 = inds1.getReverse();
      const index_type index2 = a_.dims().index(inds2);
      return FUNC::apply(a_[index2]);
    }
    MyNumberType& operator[](const index_type index1) {
      const Indices inds1 = rdims->indices(index1);
      const Indices inds2 = inds1.getReverse();
      const index_type index2 = a_.dims().index(inds2);
      return FUNC::apply(a_[index2]);
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return rdims->datasize();
    }
    size_type ndims(void) const {
      return rdims->ndims();
    }
    Dimensions dims(void) const {
      return *rdims;
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
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

  template<class D, class A, class FUNC, int M>
    class TER_Transpose  : public  TensorR<D,TER_Transpose<D,A,FUNC,M> > {
  
  private:
    const A& a_;
    VectorofPtrs *vptrs;
    Dimensions *rdims;
  
  public:
    typedef typename NumberType<D>::Type MyNumberType;



  TER_Transpose(const A& a) : a_(a) {
      rdims = &(a_.dims().getReverse());
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }
    
    ~TER_Transpose() {
      delete rdims;
      delete vptrs;
    }

    const MyNumberType operator[](const index_type index1) const {
      const Indices inds1 = rdims->indices(index1);
      const Indices inds2 = inds1.getReverse();
      const index_type index2 = a_.dims().index(inds2);
      return FUNC::apply(a_[index2]);
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return rdims->datasize();
    }
    size_type ndims(void) const {
      return rdims->ndims();
    }
    Dimensions dims(void) const {
      return *rdims;
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
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



  /****************************************************************************
   * VER_Join Expression Template 
   *
   * expression for joining two TensorR (RHS only)
   ****************************************************************************
   */

  template<class D, class A, class B, int M>
    class VER_Join : public  TensorR<D,VER_Join<D,A,B,M> > {

  private:
    const A& a_;
    const B& b_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  VER_Join(const A& a, const B& b)
    : a_(a), b_(b) { 

      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
      
    }

    ~VER_Join() {
      delete vptrs;
    }
    
    const MyNumberType operator[](const index_type i) const{
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return a_.size() +b_.size();
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
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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

  template<class D, class A, class B, int M>
    class VERW_Join : public  TensorRW<D,VERW_Join<D,A,B,M> > {

  private:
    A& a_;
    B& b_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  VERW_Join(A& a, B& b)
    : a_(a), b_(b) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      vptrs->add(b_.getAddresses());
    }

    ~VERW_Join() {
      delete vptrs;
    }


    const MyNumberType operator[](const index_type i) const{
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }
     MyNumberType& operator[](const index_type i) {
      if ( i < a_.size() ) {
	return a_[i];
      } else {
	return b_[i-a_.size()];
      }
    }

    
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return a_.size() +b_.size();
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
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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

  template<class D, class A, int M>
    class VER_Rep : public  TensorR<D,VER_Rep<D,A,M> > {

  private:
    const A& a_;
    const size_type m_;
    const size_type N_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;


  VER_Rep(const A& a, const size_type m)
    : a_(a), m_(m), N_(a_.size()) { 
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
    }


    ~VER_Rep() {
      delete vptrs;
    }


    const MyNumberType operator[](const index_type i) const{
      index_type index = index_type(i % N_);
      //      printf3("  i=%d, m_=%lu, i%%N_=%d\n",i,m_,index);
      return a_[index];
    }

    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return m_*a_.size();
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
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_.eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
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
