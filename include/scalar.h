#ifndef MATRICKS__SCALAR_H
#define MATRICKS__SCALAR_H 1




namespace matricks {

 

  
  /****************************************************************************
   * Scalar -- mathematical vector class.
   ****************************************************************************   
   */

  // NOTE: Do NOT specify M.  The default is defined in the declaration in
  //       preface.h
  
  template <class D, int M> class Scalar :
    public TensorRW<D, Scalar<D,M> > {
  private:

  // *********************** OBJECT DATA ***********************************
  //
  // do NOT declare any other storage.
  // keep the instances lightweight
    
  D data_;


  public:     

  typedef D DataType;
  typedef typename NumberType<D>::Type MyNumberType;



  //**********************************************************************
  //************************** CONSTRUCTORS ******************************
  //**********************************************************************


  // -------------------  DEFAULT  CONSTRUCTOR: zero --------------------
  Scalar<D,M>() 
  {
    data_ = D(0); 
    constructorHelper();
  }

  // --------------------- constant CONSTRUCTOR ---------------------

  Scalar<D,M>(const D val) 
  {
      
    data_ = val;
    constructorHelper();
  }


  // --------------------- EXPRESSION CONSTRUCTOR --------------------


  template <class A>
  Scalar<D,M>(const TensorR<D,A>& x) 
  {
    *this = x;
    constructorHelper();
  }


  // ************* C++11 initializer_list CONSTRUCTOR---------------------
  Scalar<D,M>(std::initializer_list<D> mylist) {
    *this = mylist;
    constructorHelper();
  }


  // --------------------- constructorHelper() --------------------
    
  void constructorHelper() {
    //add to TensorPool
  }



    

  //**********************************************************************
  //************************** DESTRUCTOR ******************************
  //**********************************************************************

  ~Scalar<D,M>() {
    //remove from TensorPool
  }
  

  //**********************************************************************
  //************************** Size related  ******************************
  //**********************************************************************


  inline size_type size(void) const {
    return 1;
  }
  inline size_type depth(void) const {
    return M;
  }

  inline size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return data_.size();
    }
  }
  inline size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return data_.deepsize();
    }
  }
  size_type deepsize(void) const {
    if constexpr(M<2) {
      return this->size();
    } else {
      return (this->size())*(this->eldeepsize());
    }
  }
 

  
  size_type ndims(void) const {
    return 0;
  }
  Dimensions dims(void) const {
    Dimensions dimensions;
    return dimensions;
  }
  Dimensions tdims(void) const {
    Dimensions dimensions;
    return dimensions;
  }
  bool isExpression(void) const {
    return false;
  }
  virtual Tensors getEnum(void) const {
    return T_SCALAR;
  }
  VectorofPtrs getAddresses(void) const  {
    VectorofPtrs myaddr((void*)this);
    return myaddr;
  }


  //**********************************************************************
  //************************** DEEP ACCESS *******************************
  //**********************************************************************

  // -------------------- NumberType access[] --------------------
  // NOTE: indexes over [0] to [deepsize()]
  // -------------------------------------------------------------
  
  // "read/write": unsigned
  MyNumberType& dat(const index_type n) {
    if constexpr(M < 2) {
      return data_;
    } else {
      return (data_)[n];
    }
  }

  // "read/write": signed
  const MyNumberType& dat(const index_type n)  const {
    if constexpr(M < 2) {
      return data_;
    } else {
      return (data_)[n];
    }
  }



  

  //**********************************************************************
  //***************** Element ACCESS as an array *************************
  //**********************************************************************

  // "read/write": unsigned
  D& operator[](const index_type n) {
    return data_;
  }

  // "read/write": signed
  const D& operator[](const index_type n)  const {
    return data_;
  }

  
  //**********************************************************************
  //***************** Element ACCESS as a tensor *************************
  //**********************************************************************


  
  // "read/write"
  D& operator()()  {
    return data_; 
  }

  // "read only"
  const D& operator()()  const{
    return data_; 
  }




  
  //**********************************************************************
  //************************** ASSIGNMENT **************************************
  //**********************************************************************

  Scalar<D,M>& equals(const D d) { 
    data_=d; 
    return *this;
  }
  Scalar<D,M>& operator=(const D d) {
    return equals(d);
  }
    


  Scalar<D,M>& operator=(const Scalar<D,M>& s2) {
    if constexpr(M<2) {
      data_ = s2();    
    } else {
      for (index_type i = 0; i < deepsize(); i++) 
	(*this).dat(i) = s2.dat(i);   
    }
    return *this;
  }


  
  Scalar<D,M>& operator=(const std::initializer_list<D>& mylist) {
    // TODO: check size
    typename std::initializer_list<D>::iterator it  = mylist.begin(); 
    data_ = *it;

    return *this;
  }

  
  

  template<class A, class D2> 
    Scalar<D,M>& operator=(const TensorR<D2,A>& y) {
    if constexpr(M<2) {
	 data_ = y[0];
    } else {
      for (index_type i = 0; i < deepsize(); i++)  {
	this->dat(i) = y.dat(i);
      }
    } 
  }



  //**********************************************************************
  //************************** MATH **************************************
  //**********************************************************************

  //----------------- .roundzero(tol) ---------------------------
  // NOTE: in-place

    
  Scalar<D,M>&  roundzero(typename Realify<D>::Type tolerance = MatricksHelper<typename Realify<D>::Type>::tolerance) { 
    data_ = matricks::roundzero(data_, tolerance);
    return *this;
  }

  //----------------- .conj() ---------------------------
  // NOTE: in-place. Don't allow if not complex.
  //----------------------------------------------------
  template< typename T=D >
  typename std::enable_if<is_complex<T>{}, Scalar<T>& >::type conj() {
    using std::conj;
    data_ = conj(data_);
    return *this;
  }



    

    

  //**********************************************************************
  //************************** Text and debugging ************************
  //**********************************************************************

  inline std::string classname() const {
    using namespace display;
    std::string s = "Scalar";		
    s += StyledString::get(ANGLE1).get();
    D d;
    s += getTypeName(d);
    if (M>1) {
      s += StyledString::get(COMMA).get();
      s += "M=";
      s += num2string(M);
    }
    s += StyledString::get(ANGLE2).get();			
    return s;	
  }


#if MATRICKS_DEBUG>=1
  std::string expression(void) const {
    return "";
  }
#endif


  // stream << operator

  friend std::ostream& operator<<(std::ostream &stream, const Scalar<D,M>& s) {
    using namespace display;
    dispval_strm(stream, s());
    return stream;
  }


  //template <class D>	
  friend inline std::istream& operator>>(const std::string s,  Scalar<D,M>& x) {	
    std::istringstream st(s);
    return (st >> x);
  }


  // stream >> operator

  // TODO: implement this
  friend std::istream& operator>>(std::istream& stream,  Scalar<D,M>& x) {	
    return stream;
  }

  // --------------------- FRIENDS ---------------------

  

  };




};


#endif 

