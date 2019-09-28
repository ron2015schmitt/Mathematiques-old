#ifndef MATRICKS__TENSOR_H
#define MATRICKS__TENSOR_H 1

#include <stdarg.h>



namespace matricks {

 
 
  
  /****************************************************************************
   * Tensor -- mathematical vector class.
   ****************************************************************************   
   */

  template <class D> class Tensor : public TensorRW<D,Tensor<D> > {
  private:

    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
    
    std::valarray<D>* data_;
    Dimensions* dims_;

  public:     
    typedef D DataType;
    typedef typename GetDataType<D>::Type PrimDataType;



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************



    // --------------------- constant=0 CONSTRUCTOR ---------------------

    explicit Tensor<D>(const Dimensions& dims) 
    {
      dims_ = new Dimensions(dims);
      data_ = new std::valarray<D>(dims.size());
      constructorHelper();
    }


    // --------------------- constant CONSTRUCTOR ---------------------

    explicit Tensor<D>(const Dimensions& dims, const D val) 
    {
      dims_ = new Dimensions(dims);
      data_ = new std::valarray<D>(val, dims.size());
      constructorHelper();
    }


    



    // --------------------- constructorHelper() --------------------
    
    void constructorHelper() {
    }







    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~Tensor<D>() {
      delete  data_ ;

      //remove from directory
    }
  

    //**********************************************************************
    //************************** Size related  ******************************
    //**********************************************************************

    // --------------------- RESIZE ---------------------

    // These allow the user to resize a vector


    // *** this is used for recon by assignment ***

    TERW_Resize<D>  resize(void) { 
      return  TERW_Resize<D>(*this);
    }



    inline size_type size(void) const {
      return data_->size();
    }
    size_type ndims(void) const {
      return dimensions->size();
    }
    Dimensions dims(void) const {
      return *dimensions_;
    }
    bool isExpression(void) const {
      return false;
    }
    Tensors getEnum() const {
      return T_TENSOR;
    }

    TensorofPtrs getAddresses(void) const  {
      TensorofPtrs myaddr((void*)this);
      return myaddr;
    }

    // index - "row major"
    // TODO: test this code
    
    index_type index(const index_type M, ...) const {
      // TODO: error if M is different from our ndims()
      index_type k = 0;
      va_list val;
      va_start(val, M);
      for(index_type n = 0; n < M; n++) {
	size_type N = (*dimensions_)[n];
	index_type x = va_arg(val, index_type); 
	k = N*k + x;
      }
      va_end(val);
      return k;
    }
   
    
    // indices - This is the inverse of the above function
    // TODO: test this code
    // TODO: bounds check on k
    
    inline Vector<index_type>& indices(const index_type k) const {
      Vector<index_type>& myinds = *(new Vector<index_type>(ndims()));
      index_type prev = k;
      for(index_type n = ndims()-1; n > 0 ; n--) {
	size_type N = (*dimensions_)[n];
	index_type temp = prev/N;
	myinds[n] = prev - N*temp;
	prev = temp;
      }
      myinds[0] = prev;
      return myinds;
    }


    
    //**********************************************************************
    //************************** ACCESSS[] ***********************************
    //**********************************************************************

    // -------------------- valarray ACCESS --------------------


    // "read/write" to the wrapped valarray
    inline std::valarray<D>& getValArray()  {
      return *data_; 
    }
    inline Tensor<D,N>>& setValArray(std::valarray<D>* valptr)  {
      delete  data_ ;
      const size_t N = valptr->size();
      data_ = valptr;
      return *this;
    }

    // -------------------- ELEMENT ACCESS --------------------

    // "read/write" access signed index
    inline D& operator[](const index_type i)  {
      index_type index = i;
      if (i < 0) {
	index += size();
      }
      return (*data_)[index]; 
    }


    // "read only" access igned index
    inline const D operator[](const index_type i) const {
      return (const D)(*data_)[i]; 
    }


    //**********************************************************************
    //************************** ACCESS() ***********************************
    //**********************************************************************


    // -------------------- ELEMENT ACCESS --------------------

    
    //**********************************************************************
    //************************** ASSIGNMENT **************************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to TensorRW for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions




    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************

    
    
    Tensor<D>&  roundzero(D tolerance = MatricksHelper<D>::tolerance) { 
      for(register index_type i=size(); i--;) {
	(*data_)[i] = matricks::roundzero((*data_)[i], tolerance);
      }
      return *this;
    }



    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      D d;
      return "Tensor"+getBracketedTypename(d);
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
    }
#endif




    // stream << operator

    // TODO: implement

    friend std::ostream& operator<<(std::ostream &stream, const Tensor<D>& v) {
      using namespace display;
      return stream;
    }


    //template <class D>	
    friend inline std::istream& operator>>(const std::string s,  Tensor<D>& x) {
      std::istringstream st(s);
      return (st >> x);
    }


    // stream >> operator
    // TODO: implement

    friend std::istream& operator>>(std::istream& stream,  Tensor<D>& x) {	
      return stream;
    }

    // --------------------- FRIENDS ---------------------

  

  };




};


#endif 

