#ifndef MATRICKS__NEWSCALAR_H
#define MATRICKS__NEWSCALAR_H 1




namespace matricks {

 

  
  /****************************************************************************
   * NewScalar -- mathematical vector class.
   ****************************************************************************   
   */

  template <class D, int M = 1+matricks::NumberType<D>::depth()> class NewScalar :
    public TensorRW<D, NewScalar<D,M> > {
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
  NewScalar<D,M>() 
  {
    data_ = D(0); 
    constructorHelper();
  }

  // --------------------- constant CONSTRUCTOR ---------------------

  NewScalar<D,M>(const D val) 
  {
      
    data_ = val;
    constructorHelper();
  }


  // --------------------- EXPRESSION CONSTRUCTOR --------------------


  template <class A>
  NewScalar<D,M>(const TensorR<D,A>& x) 
  {
    *this = x;
    constructorHelper();
  }


  // ************* C++11 initializer_list CONSTRUCTOR---------------------
  NewScalar<D,M>(std::initializer_list<D> mylist) {
    *this = mylist;
    constructorHelper();
  }


  // --------------------- constructorHelper() --------------------
    
  void constructorHelper() {
  }



    

  //**********************************************************************
  //************************** DESTRUCTOR ******************************
  //**********************************************************************

  ~NewScalar<D,M>() {
    //remove from directory
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
      return data_.size();
    }
  }
  inline size_type deepsize(void) const {
    return (this->size())*(this->eldeepsize());
  }
 

  
  size_type ndims(void) const {
    return 0;
  }
  Dimensions dims(void) const {
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
  //************************** ACCESS() ***********************************
  //**********************************************************************


  // -------------------- NumberType access[] --------------------
  // NOTE: indexes over [0] to [deepsize()]
  // -------------------------------------------------------------
  
  // "read/write": unsigned
  MyNumberType& operator[](const index_type n) {
    if constexpr(M < 2) {
      return data_;
    } else {
      return (*data_)[n];
    }
  }

  // "read/write": signed
  const MyNumberType& operator[](const index_type n)  const {
    if constexpr(M < 2) {
      return data_;
    } else {
      return (*data_)[n];
    }
  }


  // -------------------- D element access() --------------------
  // NOTE: indexes is void ie () 
  // -------------------------------------------------------------


  
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

  NewScalar<D,M>& equals(const D d) { 
    data_=d; 
    return *this;
  }
  NewScalar<D,M>& operator=(const D d) {
    return equals(d);
  }
    

  // Copy asignment
  NewScalar<D,M>& equals(const NewScalar<D,M>& s2) {
    data_ = s2();    
    return *this;
  }

  NewScalar<D,M>& operator=(const NewScalar<D,M>& s2) {
    return equals(s2);
  }



  // TensorExpression
  template<class A> 
  NewScalar<D,M>& equals(const TensorR<D,A>& s2) {
    data_ = s2[0];    
    return *this;
  }

  template<class A> 
  NewScalar<D,M>& operator=(const TensorR<D,A>& s2) {
    return equals(s2);
  }


  
  NewScalar<D,M>& equals(const std::initializer_list<D>& mylist) {
    // TODO: check size
    typename std::initializer_list<D>::iterator it  = mylist.begin(); 
    data_ = *it;

    return *this;
  }
  NewScalar<D,M>& operator=(const std::initializer_list<D>& mylist) {
    return equals(mylist);
  }



  //**********************************************************************
  //************************** MATH **************************************
  //**********************************************************************

  //----------------- .roundzero(tol) ---------------------------
  // NOTE: in-place

    
  NewScalar<D,M>&  roundzero(D tolerance = MatricksHelper<D>::tolerance) { 
    data_ = matricks::roundzero(data_, tolerance);
    return *this;
  }

  //----------------- .conj() ---------------------------
  // NOTE: in-place. Don't allow if not complex.
  //----------------------------------------------------
  template< typename T=D >
  typename std::enable_if<is_complex<T>{}, NewScalar<T>& >::type conj() {
    using std::conj;
    data_ = conj(data_);
    return *this;
  }



    

    

  //**********************************************************************
  //************************** Text and debugging ************************
  //**********************************************************************

  inline std::string classname() const {
    D d;
    return "Scalar"+display::getBracketedTypeName(d);
  }


#if MATRICKS_DEBUG>=1
  std::string expression(void) const {
    return "";
  }
#endif


  // stream << operator

  friend std::ostream& operator<<(std::ostream &stream, const NewScalar<D,M>& s) {
    using namespace display;
    dispval_strm(stream, s());
    return stream;
  }


  //template <class D>	
  friend inline std::istream& operator>>(const std::string s,  NewScalar<D,M>& x) {	
    std::istringstream st(s);
    return (st >> x);
  }


  // stream >> operator

  // TODO: implement this
  friend std::istream& operator>>(std::istream& stream,  NewScalar<D,M>& x) {	
    return stream;
  }

  // --------------------- FRIENDS ---------------------

  

  };




};


#endif 
