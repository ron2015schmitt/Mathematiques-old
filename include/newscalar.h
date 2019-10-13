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
  typedef typename FundamentalType<D>::Type PrimDataType;



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
    const size_type Nelements = this->nelements();;
    if (M>1) {
      return Nelements*NumberType<D>::size(data_);
    } else {
      return Nelements;
    }
  }
  

  inline size_type nelements(void) const {
    return 1;
  }

  
  inline size_type depth(void) const {
    return M;
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
  //************************** CONVERSION  ***********************************
  //**********************************************************************

    

  // -------------------- ELEMENT ACCESS --------------------

  // "read/write" access signed index
  inline D& operator[](const index_type i)  {
    return data_; 
  }


  // "read only" access igned index
  inline const D operator[](const index_type i) const {
    return (const D)data_; 
  }


  // "read/write" access signed index
  inline D& operator()()  {
    return data_; 
  }

  // "read only" access igned index
  inline const D operator()() const {
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

