#ifndef MATRICKS__TENSOR_H
#define MATRICKS__TENSOR_H 1

#include <stdarg.h>



namespace matricks {

 
 
  
  /****************************************************************************
   * Tensor -- mathematical vector class.
   ****************************************************************************   
   */

  template <class D, size_type N> class Tensor : public TensorRW<D,Tensor<D,N> > {
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

    explicit Tensor<D,N>(const Dimensions& dims) 
    {
      dims_ = new Dimensions(dims);
      data_ = new std::valarray<D>(dims.size());
      constructorHelper();
    }


    // --------------------- constant CONSTRUCTOR ---------------------

    explicit Tensor<D,N>>(const Dimensions& dims, const D val) 
    {
      dims_ = new Dimensions(dims);
      data_ = new std::valarray<D>(val, dims.size());
      constructorHelper();
    }


    

    // --------------------- COPY CONSTRUCTOR --------------------

    Tensor<D,N>>(const Tensor<D,N>>& v2) 
    {
      const size_type N = v2.size();
      data_ = new std::valarray<D>(N); 
      *this = v2;
      constructorHelper();
    }


    // --------------------- EXPRESSION CONSTRUCTOR --------------------


    template <class A>
    Tensor<D,N>>(const TensorR<D,A>& x) 
    {
      const size_type N = x.size();
      data_ = new std::valarray<D>(N);
      *this = x;
      constructorHelper();
    }


    // --------------------- 1D valarray CONSTRUCTOR ---------------------
    Matrix<D>(const size_type Nr, const size_type Nc, const std::valarray<D>& valar) {
      Nrows_ = Nr;
      Ncols_ = Nc;
      data_ = new std::valarray<D>(valar); 
      constructorHelper();
    }


    // --------------------- 1D array[]  CONSTRUCTOR ---------------------
    Matrix<D>(const size_type Nr, const size_type Nc, const D (vals)[]) {
      // allocate store
      Nrows_ = Nr;
      Ncols_ = Nc;
      data_ = new std::valarray<D>(vals, Nr*Nc); 
      constructorHelper();
    }

    
    // ************* C++11 1D initializer_list CONSTRUCTOR---------------------
#if CPP11 == 1
    Matrix<D>(const size_type Nr, const size_type Nc, const std::initializer_list<D>& mylist) 
    {
      Nrows_ = Nr;
      Ncols_ = Nc;
      data_ = new std::valarray<D>(Nr*Nc);
      *this = mylist;
      constructorHelper();
    }
#endif // C++11



    // --------------------- constructorHelper() --------------------
    
    void constructorHelper() {
    }







    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~Tensor<D,N>>() {
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

    // *** resize from given integer *** 
    // TODO: variadic fuction
    Tensor<D,N>>&  resize(const size_type n) { 
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


    // TODO:  variadic number of slices should be possible
    // https://en.cppreference.com/w/cpp/language/variadic_arguments
    // " class type arguments are allowed (except class types with non-trivial
    //   copy constructor, non-trivial move constructor, or a non-trivial
    //   destructor, which are conditionally-supported with
    //   implementation-defined semantics)"
    // but need to have a slice that defines a single index

    // Accessing a slice of values
    
    TERW_Subset<D> operator[](const slc& slice)  { 
      return (*this)[slice.toIndexTensor(size())];
    }
    const TERW_Subset<D>  operator[](const slc& slice) const  {
      //      display::log3("Tensor","operator[]","(const slc& slice)\n");
      return (*this)[slice.toIndexTensor(size())];
    }
      
    

    // Accessing a SET of values using a vector of ints

    TERW_Subset<D> operator[](const Tensor<index_type>& ii) {
      return TERW_Subset<D>(*this, ii);
    }
    const TERW_Subset<D> operator[](const Tensor<index_type>& ii) const {
      return TERW_Subset<D>(*this, ii);
    }



    
    // Accessing a SET of values using a MASK
    
    TERW_Submask<D> operator[](const Tensor<bool>& mask)  {
      return  TERW_Submask<D>(*this,mask);
    }
    const TERW_Submask<D> operator[](const Tensor<bool>& mask)  const {
      return  TERW_Submask<D>(*this,mask);
    }



    //Accessing a SET of values using a list

#if CPP11 == 1
    TERW_Subset<D> operator[](const std::initializer_list<index_type>& list) {
      return  TERW_Subset<D>(*this, list);
    }
    const TERW_Subset<D> operator[](const std::initializer_list<index_type>& list) const {
      return  TERW_Subset<D>(*this, list);
    }
#endif // C++11


    //**********************************************************************
    //************************** ACCESS() ***********************************
    //**********************************************************************

    // -------------------- valarray ACCESS --------------------

    // -------------------- ELEMENT ACCESS --------------------

    // "read/write" access signed index
    inline D& operator()(const index_type i)  {
      index_type index = i;
      if (i < 0) {
	index += size();
      }
      return (*data_)[index]; 
    }


    // "read only" access igned index
    inline const D operator()(const index_type i) const {
      return (const D)(*data_)[i]; 
    }




    // Accessing a slice of values
    
    TERW_Subset<D> operator()(const slc& slice)  { 
      return (*this)[slice.toIndexTensor(size())];
    }
    const TERW_Subset<D>  operator()(const slc& slice) const  {
      //      display::log3("Tensor","operator[]","(const slc& slice)\n");
      return (*this)[slice.toIndexTensor(size())];
    }
      
    

    // Accessing a SET of values using a vector of ints

    TERW_Subset<D> operator()(const Tensor<index_type>& ii) {
      return TERW_Subset<D>(*this, ii);
    }
    const TERW_Subset<D> operator()(const Tensor<index_type>& ii) const {
      return TERW_Subset<D>(*this, ii);
    }



    
    // Accessing a SET of values using a MASK
    
    TERW_Submask<D> operator()(const Tensor<bool>& mask)  {
      return  TERW_Submask<D>(*this,mask);
    }
    const TERW_Submask<D> operator()(const Tensor<bool>& mask)  const {
      return  TERW_Submask<D>(*this,mask);
    }



    //Accessing a SET of values using a list

#if CPP11 == 1
    TERW_Subset<D> operator()(const std::initializer_list<index_type>& list) {
      return  TERW_Subset<D>(*this, list);
    }
    const TERW_Subset<D> operator()(const std::initializer_list<index_type>& list) const {
      return  TERW_Subset<D>(*this, list);
    }
#endif // C++11


    
    //**********************************************************************
    //************************** ASSIGNMENT **************************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to TensorRW for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions

    // Assign all elements to the same constant value
    Tensor<D,N>>& equals(const D d) { 
      for(index_type i=size(); i--;) 
	(*data_)[i]=d; 
      return *this;
    }
    Tensor<D,N>>& operator=(const D d) { 
      return equals(d);
    }


    // Assignment to a vector expression
    template <class A>  Tensor<D,N>>& equals(const TensorR<D,A>& x) {  

      // resize to avoid segmentation faults
      resize(x.size());

      if (this->getAddresses().common( x.getAddresses() )  ){    
	Tensor<D,N>> vtemp(size());

	for (register index_type i = size(); i--;)
	  vtemp[i] = x[i];   // Inlined expression
	for (register index_type i = size(); i--;)
	  (*data_)[i] = vtemp[i];
      } else {
	for (register index_type i = size(); i--;)
	  (*data_)[i] = x[i];   // Inlined expression
      }
      return *this; 
    }

    template <class A>  Tensor<D,N>>& operator=(const TensorR<D,A>& x) {  
      return equals(x);
    }



    



    // assignment to an array
    Tensor<D,N>>& equals(const D array[]) {
      

      for (index_type i; i < size(); i++)  { 
	(*this)[i++] = array[i];
      }

      return *this;
    }


    Tensor<D,N>>& operator=(const D array[]) {
      return equals(array);
    }




    

    // Copy asignment
    Tensor<D,N>>& equals(const Tensor<D,N>>& v2) {

      // resize to avoid segmentation faults
      resize(v2.size());

      for(register index_type i=size(); i--;)
	(*data_)[i] = v2[i];    
      return *this;
    }



    Tensor<D,N>>& operator=(const Tensor<D,N>>& v2) {
      return equals(v2);
    }



    template <class B>
    Tensor<D,N>>& operator=(const TERW_Resize<D>& b) { 
      return *this;
    }


    Tensor<D,N>>& equals(const std::list<D> mylist) {
      

      // resize to avoid segmentation faults
      resize(mylist.size());

      index_type i = 0;
      for (typename std::list<D>::const_iterator it = mylist.begin(); it != mylist.end(); ++it)  { 
	(*this)[i++] = *it;
      }

      return *this;
    }


    Tensor<D,N>>& operator=(const std::list<D> mylist) {
      return equals(mylist);
    }

    
    // assignment to a C++11 list
#if CPP11 == 1
    Tensor<D,N>>& equals(const std::initializer_list<D> mylist) {
      

      // resize to avoid segmentation faults
      resize(mylist.size());

      size_type i = 0;
      typename std::initializer_list<D>::iterator it; 
      for (it = mylist.begin(); it != mylist.end(); ++it)  { 
	(*this)[i++] = *it;
      }

      return *this;
    }
#endif // C++11

    Tensor<D,N>>& operator=(const std::initializer_list<D> mylist) {
      return equals(mylist);
    }




    // assignment to a std::vector
    Tensor<D,N>>& equals(const std::vector<D> vstd) {
      

      // resize to avoid segmentation faults
      resize(vstd.size());

      for(register size_type i=size(); i--;)
	(*data_)[i] = vstd[i];    

      return *this;
    }


    Tensor<D,N>>& operator=(const std::vector<D> vstd) {
      return equals(vstd);
    }



    // assignment to a std::array
    template <std::size_t N>
    Tensor<D,N>>& equals(const struct std::array<D,N> varray) {
      

      // resize to avoid segmentation faults
      resize(N);

      for(register size_type i=size(); i--;)
	(*data_)[i] = varray[i];    

      return *this;
    }


    template <std::size_t N>
    Tensor<D,N>>& operator=(const struct std::array<D,N> varray) {
      return equals(varray);
    }



    // assignment to a std::val_array
    Tensor<D,N>>& equals(const std::valarray<D> varray) {
      

      // resize to avoid segmentation faults
      resize(varray.size());

      for(register size_type i=size(); i--;)
	(*data_)[i] = varray[i];    

      return *this;
    }

    Tensor<D,N>>& operator=(const std::valarray<D> varray) {
      return equals(varray);
    }




    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************

    
    
    Tensor<D,N>&  roundzero(D tolerance = MatricksHelper<D>::tolerance) { 
      for(register index_type i=size(); i--;) {
	(*data_)[i] = matricks::roundzero((*data_)[i], tolerance);
      }
      return *this;
    }


    
    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    TensorofPtrs getAddresses(void) const  {
      TensorofPtrs myaddr((void*)this);
      return myaddr;
    }


    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      return "Tensor";
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

