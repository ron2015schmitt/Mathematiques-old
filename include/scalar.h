#ifndef MATHQ__SCALAR_H
#define MATHQ__SCALAR_H 1


namespace mathq {


  /********************************************************************
   * Scalar<E>    -- variable size vector (valarray)
   *                 E  = type for elements
   *
   * DO NOT SPECIFY: D,M
   *                 The defaults are defined in the declaration in
   *                 preface.h
   *                 D = number type 
   *                   = underlying algebraic field
   *                     ex. int, double, std::complex<double>
   *                 M = tensor depth. if E=D, then M=1.
  ********************************************************************  
   */

    
  template <class E, typename D, int M> class Scalar :
    public TensorRW< Scalar<E,D,M>, E,D,M,0> {
  public:
    typedef Scalar<E,D,M> XType;
    typedef E EType;
    typedef D DType;
    constexpr static int Rvalue = 0;
    constexpr static int Mvalue = M;
    typedef typename std::conditional<M==1,E,E&>::type TypeA;

  private:

  // *********************** OBJECT DATA ***********************************
  //
  // do NOT declare any other storage.
  // keep the instances lightweight
    
  E data_;




  public:

  //**********************************************************************
  //************************** CONSTRUCTORS ******************************
  //**********************************************************************


  // -------------------  DEFAULT  CONSTRUCTOR: zero --------------------
  Scalar<E,D,M>() 
  {
    if constexpr(M==1) {
	*this = 0;
    } else {
      data_ = *(new E());
    }
    constructorHelper();
  }

  // --------------------- constant CONSTRUCTOR ---------------------

  Scalar<E,D,M>(const E e) 
  {
      
    *this = e;
    constructorHelper();
  }

  // --------------------- constant CONSTRUCTOR ---------------------

  template<int M1 = M, EnableConstructorIf<(M1>1)> = 0>

  Scalar<E,D,M>(const D d) 
  {
      
    *this = d;
    constructorHelper();
  }

  // --------------------- EXPRESSION CONSTRUCTOR --------------------


  template <class X>
    Scalar<E,D,M>(const TensorR<X,E,D,M,Rvalue>& x) 
  {
    *this = x;
    constructorHelper();
  }


  // ************* C++11 initializer_list CONSTRUCTOR---------------------
  Scalar<E,D,M>(std::initializer_list<E> mylist) {
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

  ~Scalar<E,D,M>() {
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

  // -------------------- D access[] --------------------
  // NOTE: indexes over [0] to [deepsize()]
  // -------------------------------------------------------------
  
  // "read/write": unsigned
  D& dat(const index_type n) {
    if constexpr(M < 2) {
      return data_;
    } else {
      return (data_)[n];
    }
  }

  // "read/write": signed
  const D& dat(const index_type n)  const {
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
  E& operator[](const index_type n) {
    return data_;
  }

  // "read/write": signed
  const E& operator[](const index_type n)  const {
    return data_;
  }

  
  //**********************************************************************
  //***************** Element ACCESS as a tensor *************************
  //**********************************************************************


  
  // "read/write"
  E& operator()()  {
    return data_; 
  }

  // "read only"
  const E& operator()()  const{
    return data_; 
  }




  
  //**********************************************************************
  //************************** ASSIGNMENT **************************************
  //**********************************************************************

  Scalar<E,D,M>& operator=(const E e) {
    data_=e; 
    return *this;
  }
  
  template <int M1=M> 
    typename std::enable_if<(M1>1), Scalar<E,D,M>& >::type operator=(const D& d) { 
    for (index_type i = 0; i < deepsize(); i++) {
      (*this).dat(i)=d;
    }
    return *this;
  }


  Scalar<E,D,M>& operator=(const Scalar<E,D,M>& s2) {
    if constexpr(M<2) {
      data_ = s2();    
    } else {
      for (index_type i = 0; i < deepsize(); i++) 
	(*this).dat(i) = s2.dat(i);   
    }
    return *this;
  }

  
  Scalar<E,D,M>& operator=(const std::initializer_list<E>& mylist) {
    typename std::initializer_list<E>::iterator it  = mylist.begin(); 
    data_ = *it;
    return *this;
  }


  template <class X>
    Scalar<E,D,M>& operator=(const TensorR<X,E,D,M,Rvalue>& y) {
    if constexpr(M<2) {
	 data_ = y[0];
    } else {
      for (index_type i = 0; i < deepsize(); i++)  {
	this->dat(i) = y.dat(i);
      }
    } 
  }
  template <class X>
    Scalar<E,D,M>& operator=(const TensorRW<X,E,D,M,Rvalue>& y) {
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

    
  Scalar<E,D,M>&  roundzero(typename Realify<D>::Type tolerance = MatricksHelper<typename Realify<D>::Type>::tolerance) { 
    data_ = mathq::roundzero(data_, tolerance);
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
    E e;
    s += getTypeName(e);
    //if (M>1) {
    //  s += StyledString::get(COMMA).get();
    //  s += "M=";
    //  s += num2string(M);
    //}
    s += StyledString::get(ANGLE2).get();			
    return s;	
  }


#if MATHQ_DEBUG>=1
  std::string expression(void) const {
    return "";
  }
#endif


  // stream << operator

  friend std::ostream& operator<<(std::ostream &stream, const Scalar<E,D,M>& s) {
    using namespace display;
    dispval_strm(stream, s());
    return stream;
  }


  //template <class D>	
  friend inline std::istream& operator>>(const std::string s,  Scalar<E,D,M>& x) {	
    std::istringstream st(s);
    return (st >> x);
  }


  // stream >> operator

  // TODO: implement this
  friend std::istream& operator>>(std::istream& stream,  Scalar<E,D,M>& x) {	
    return stream;
  }

  // --------------------- FRIENDS ---------------------

  

  };




};


#endif 

