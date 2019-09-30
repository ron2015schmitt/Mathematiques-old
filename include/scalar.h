#ifndef MATRICKS__SCALAR_H
#define MATRICKS__SCALAR_H 1




namespace matricks {

 
 
  
  /****************************************************************************
   * Scalar -- mathematical vector class.
   ****************************************************************************   
   */

  template <class D> class Scalar : public TensorRW<D,Scalar<D> >, public  TensorObject{
  private:

    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
    
    D data_;


  public:     

    typedef D DataType;
    typedef typename GetDataType<D>::Type PrimDataType;



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************


    // -------------------  DEFAULT  CONSTRUCTOR: zero --------------------
    explicit Scalar<D>() 
    {
      data_ = D(0); 
      constructorHelper();
    }

    // --------------------- constant CONSTRUCTOR ---------------------

    Scalar<D>(const D val) 
      {
      
	data_ = val;
	constructorHelper();
      }


    // --------------------- EXPRESSION CONSTRUCTOR --------------------


    template <class A>
      Scalar<D>(const TensorR<D,A>& x) 
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

    ~Scalar<D>() {
      //remove from directory
    }
  

    //**********************************************************************
    //************************** Size related  ******************************
    //**********************************************************************


    inline size_type size(void) const {
      return 1;
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

    
    //**********************************************************************
    //************************** ACCESSS ***********************************
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

    Scalar<D>& equals(const D d) { 
      data_=d; 
      return *this;
    }
    Scalar<D>& operator=(const D d) {
      return equals(d);
    }
    

    // Copy asignment
    Scalar<D>& equals(const Scalar<D>& s2) {
      disp3(s2);
      data_ = s2();    
      return *this;
    }

    Scalar<D>& operator=(const Scalar<D>& s2) {
      return equals(s2);
    }



    // TensorExpression
    template<class A> 
    Scalar<D>& equals(const TensorR<D,A>& s2) {
      disp3(s2);
      data_ = s2[0];    
      return *this;
    }

    template<class A> 
      Scalar<D>& operator=(const TensorR<D,A>& s2) {
      return equals(s2);
    }




    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************

    
    
    Scalar<D>&  roundzero(D tolerance = MatricksHelper<D>::tolerance) { 
      data_ = matricks::roundzero(data_, tolerance);
      return *this;
    }


    Scalar<D>&  conj() {
      // C++ does not have "instanceof" type guarding so even if it
      // can't get to the code it will produce a compile error
      if (is_complex<typeof(data_)>{}) {
	data_ = matricksconj(data_);
      }
      return *this;
    }
    
    

    
    //**********************************************************************
    //************************** Adressess          ************************
    //**********************************************************************

    VectorofPtrs getAddresses(void) const  {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
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

    friend std::ostream& operator<<(std::ostream &stream, const Scalar<D>& s) {
      using namespace display;
      dispval_strm(stream, s());
      return stream;
    }


    //template <class D>	
    friend inline std::istream& operator>>(const std::string s,  Scalar<D>& x) {	
      std::istringstream st(s);
      return (st >> x);
    }


    // stream >> operator

    // TODO: implement this
    friend std::istream& operator>>(std::istream& stream,  Scalar<D>& x) {	
      return stream;
    }

    // --------------------- FRIENDS ---------------------

  

  };




};


#endif 

