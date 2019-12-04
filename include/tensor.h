#ifndef MATHQ__TENSOR_H
#define MATHQ__TENSOR_H 1

#include <stdarg.h>


namespace mathq {


  

 
   /********************************************************************
   * Tensor<E>      -- Tensor of 0 dimension (scalar)
   *                   E  = type for elements
   * Tensor<E,NDIM> -- Tensor of NDIM dimension 
   *                   NDIM = number of dimensions (0=scalar,1=vector,2=matrix,etc)
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
 

  template <class E, int R,   typename D, int M> class
    Tensor : public TensorRW<Tensor<E,R,D,M>,E,D,M,R> {
  private:

    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight

    // always use valarray
    typedef typename ArrayType<E,0>::Type MyArrayType;

    MyArrayType data_;
    Dimensions* dimensions_;

  public:     



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************


    // --------------------- default CONSTRUCTOR ---------------------

    explicit Tensor<E,R,D,M>() 
    {
      std::vector<size_type> dv(R);
      dimensions_ = new Dimensions(dv);
      data_.resize(dimensions_->datasize());
      constructorHelper();
    }


    // --------------------- constant=0 CONSTRUCTOR ---------------------

    explicit Tensor<E,R,D,M>(const Dimensions& dims) 
    {
      dimensions_ = new Dimensions(dims);
      data_.resize(dimensions_->datasize());
      constructorHelper();
    }


    // --------------------- constant CONSTRUCTOR ---------------------

    explicit Tensor<E,R,D,M>(const Dimensions& dims, const E e) 
    {
      dimensions_ = new Dimensions(dims);
      data_.resize(dimensions_->datasize());
      constructorHelper();
    }


  // ************* C++11 initializer_list CONSTRUCTOR---------------------
    Tensor<E,R,D,M>(const NestedInitializerList<D,R>& mylist)  {
      std::vector<size_type> dv(R);
      dimensions_ = new Dimensions(dv);
      //mout << "constructor: ";
      //tdisp(mylist);
      *this = mylist;
      constructorHelper();
    }


    // --------------------- constructorHelper() --------------------
    
    void constructorHelper() {
    }







    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~Tensor<E,R,D,M>() {
      //remove from directory
    }
  

    //**********************************************************************
    //************************** Size related  ******************************
    //**********************************************************************





    inline size_type size(void) const {
      return data_.size();
    }
    size_type ndims(void) const {
      return dimensions_->ndims();
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

    VectorofPtrs getAddresses(void) const  {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
    }

    size_type tdims(void) const {
      return dims();
    }

    inline size_type depth(void) const {
      return M;
    }

    // the size of each element
    inline size_type elsize(void) const {
      if constexpr(M<2) {
	  return 1;
	} else {
	const size_type Nelements = this->size();
	if (Nelements==0) {
	  return 0;
	} else {
	  return data_[0].size();
	}
      }
    }
    
    // the deep size of an element: the total number of numbers in an element
    inline size_type eldeepsize(void) const {
      if constexpr(M<2) {
        return 1;
      } else {
      const size_type Nelements = this->size();
      if (Nelements==0) {
	return 0;
      } else {
	return data_[0].deepsize();
      }
    }
  }

  // the total number of numbers in this data structure
  size_type deepsize(void) const {
    if constexpr(M<2) {
      return this->size();
    } else {
      return (this->size())*(this->eldeepsize());
    }
  }
  std::vector<Dimensions>& deepdims(void) const {
    std::vector<Dimensions>& ddims = *(new std::vector<Dimensions>);
    return deepdims(ddims);
  }
  std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
    parentdims.push_back(dims());
    if constexpr(M>1) {
	if (size()>0) {
	  data_[0].deepdims(parentdims);
	}
    }
    return parentdims;
  }
 

    


    //**********************************************************************
    //********************* Resize ********************** ******************
    //**********************************************************************

    Tensor& resize(Dimensions& dims) {
      while (dims.rank() < R) {
	dims.push_back(0);
      }
      dimensions_ = new Dimensions(dims);
      data_.resize(dimensions_->datasize());
      return *this;
    }

    Tensor<E,R,D,M>& resize(std::vector<Dimensions>& deepdims) {
    Dimensions newdims = deepdims[0];
    resize(newdims);
    if constexpr(M>1) {
      deepdims.erase(deepdims.begin());
      for(index_type i = 0; i < size(); i++) {
	data_[i].resize(deepdims);
      }
    }
    return *this;
  }


    
    //**********************************************************************
    //*********************  Accesss to Internal valarray ******************
    //**********************************************************************


  //**********************************************************************
  //******************** DEEP ACCESS: x.dat(n) ***************************
  //**********************************************************************
  // NOTE: indexes over [0] to [deepsize()] and note return type
  
  // "read/write"
  D& dat(const index_type n) {
    using namespace::display;
    //    mout << createStyle(BOLD).apply("operator["+num2string(n)+"] #1")<<std::endl;
    if constexpr(M < 2) {
      int k = n;
      if (k < 0) {
	  k += size();
      }
      return data_[k];
    } else {
      const int Ndeep = this->eldeepsize();
      const int j = n / Ndeep;
      const int k = n % Ndeep;
      return data_[j].dat(k);
    }
  }

  // read
  const D& dat(const index_type n)  const {
    using namespace::display;
    //    mout << createStyle(BOLD).apply("operator["+num2string(n)+"] #2")<<std::endl;
    if constexpr(M < 2) {
      int k = n;
      if (k < 0) {
	  k += size();
      }
      return data_[k];
    } else {
      const int Ndeep = this->eldeepsize();
      const int j = n / Ndeep;
      const int k = n % Ndeep;
      return data_[j].dat(k);
    }
  }

  

  //**********************************************************************
  //************* Array-style Element Access: x[n] ***********************
  //**********************************************************************

  // "read/write"
  E& operator[](const index_type n) {
    int k = n;
    if (k < 0) {
      k += size();
    }
    return data_[k];
  }

  // read
  const E& operator[](const index_type n)  const {
    int k = n;
    if (k < 0) {
      k += size();
    }
    return data_[k];
  }


  //**********************************************************************
  //*******Tensor-style Element Access: A(i,j,k,...) *********************
  //**********************************************************************
    
    
    index_type indexOf(const Indices& inds) const {
      return dimensions_->index(inds);
    }

    /* template<typename... Ts> index_type index(int i, const Ts... args){ */
    /* const int size = sizeof...(args); */
    /* int argarray[size] = {args...}; */
    /*   Indices& inds = *(new Indices(ndims())); */
    /*   const index_type M = this->ndims(); */
    /*   inds[0] = i;  */
    /*   for(index_type n = 1; n < M; n++) { */
    /* 	inds[n] = argarray[n];  */
    /*   } */
    /*   index_type k = this->index(inds); */
    /*   return k; */
    /* } */

    template <typename... U> typename std::enable_if<(std::is_same<U, index_type>::value && ...), index_type>::type index(const U... args) {
  
      const int size = sizeof...(args);
      int argarray[size] = {args...};
      Indices& inds = *(new Indices(ndims()));
      const index_type NN = this->ndims();
      for(index_type n = 0; n < NN; n++) {
    	inds[n] = argarray[n]; 
      }
      index_type k = this->indexOf(inds);
      return k;
    }

    
    index_type indexl(const std::initializer_list<size_type>& mylist) const {
      // TODO: check size
      const index_type NN = this->ndims();
      const size_type N =  mylist.size();
      index_type k = 0;
      index_type n = 0;
      typename std::initializer_list<size_type>::iterator it; 
      for (it = mylist.begin(); it != mylist.end(); ++it, n++)  { 
	size_type N = (*dimensions_)[n];
	index_type j = *it;
	k = N*k + j;
      }
      return k;
    }

   
    
    // indices - This is the inverse of the above function
    // TODO: test this code
    // TODO: bounds check on k
    
    inline Indices& indices(const index_type k) const {
      return dimensions_->indices(k);
    }



    //**********************************************************************
    //************************** ACCESS() ***********************************
    //**********************************************************************

    
    // ---------------- tensor(Indices)--------------
    E& operator()(const Indices& inds) {
      index_type k = this->index(inds);
      return (*this)[k];
    }
    const E operator()(const Indices& inds) const {
      index_type k = this->index(inds);
      return (*this)[k];
    }


    
    // ---------------- tensor(i,j,...)--------------

    template <typename... U> typename std::enable_if<(std::is_same<U, index_type>::value && ...), E&>::type operator()(const U... args) {

      //const int size = sizeof...(args);
      //int argarray[size] = {args...};
      index_type k = this->index(args...);
      
      return (*this)[k];
    }
    template <typename... U> typename std::enable_if<(std::is_same<U, index_type>::value && ...), const E>::type operator()(const U... args) const  {
    return (*this)(args...);
    }



    // ---------------- tensor({i,j,...})--------------
    E& operator()(const std::initializer_list<size_type>& mylist) {
      index_type k = this->index(mylist);
      return (*this)[k];
    }
    const E operator()(const std::initializer_list<size_type>& mylist) const {
      index_type k = this->index(mylist);
      return (*this)[k];
    }

    
    //**********************************************************************
    //************************** ASSIGNMENT **************************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to TensorRW for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions


    // ----------------- tensor = e ----------------
    Tensor<E,R,D,M>&
      operator=(const E e) { 
      for(index_type i=size(); i--;) 
	data_[i]=e; 
      return *this;
    }

    // ----------------- tensor = d ----------------
    template <class T=E> 
      typename std::enable_if<!std::is_same<T,D>::value, Tensor<T,R,D,M>& >::type operator=(const D& d) { 
    
      for(index_type i = 0; i < deepsize(); i++) {
	data_.dat(i) = d;
      }
      return *this;
    }



    // ----------------- tensor = C++11 init list
    Tensor<E,R,D,M>& operator=(const NestedInitializerList<D,R>& mylist)  {
      //mout << "operator=: ";
      //tdisp(mylist);
      int i = 0;
      Dimensions dims = NestedInitializerListDef<D,R>::dims(mylist);
      resize(dims);
      NestedInitializerListDef<D,R>::compute(*this, mylist, i);
      return *this;
    }

    

    // ----------------- tensor = Tensor<E,R,D,M> ----------------
    Tensor<E,R,D,M>&
      operator=(const Tensor<E,R,D,M>& x) {  
      // TODO: issue warning
      resize(x.dims());
      for (index_type i = size(); i--;) {
	  data_[i] = x[i];   // Inlined expression
      }
      return *this; 
    }

    // ----------------- tensor = TensorR<D,A> ----------------
    template <class X>  Tensor<E,R,D,M>&
      operator=(const TensorR<X,E,D,M,R>& x) {  
      // TODO: issue warning
      resize(x.dims());

      if (common(*this, x)){    
	Tensor<E,R,D,M> Ttemp(this->dims());
	for (index_type i = size(); i--;)
	  Ttemp[i] = x[i];   // Inlined expression
	for (index_type i = size(); i--;)
	  data_[i] = Ttemp[i];
      } else {
	for (index_type i = size(); i--;)
	  data_[i] = x[i];   // Inlined expression
      }
      return *this; 
    }


    //*********************************************************
    //                   1D assignment
    //********************************************************
    

    // ------------- tensor = array[] ----------------
    
    Tensor<E,R,D,M>&
      operator=(const E array1[]) {
      for (index_type i = 0; i < size(); i++)  {
	(*this)[i] = array1[i];
      }
      return *this;
    }
    
    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************

    
    //----------------- .roundzero(tol) ---------------------------
    // NOTE: in-place

    Tensor<E,R,D,M>&  roundzero(typename Realify<D>::Type tolerance = MatricksHelper<typename Realify<E>::Type>::tolerance) { 
      for(index_type i=size(); i--;) {
	data_[i] = mathq::roundzero(data_[i], tolerance);
      }
      return *this;
    }

    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T=D >
      typename std::enable_if<is_complex<T>{}, Tensor<T>& >::type conj() {
      for(index_type i=size(); i--;) {
	data_[i] = std::conj(data_[i]);
      }
      return *this;
    }

    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      E d;
      return "Tensor"+display::getBracketedTypeName(d);
    }


#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return "";
    }
#endif


    std::ostream& send(std::ostream &stream, index_type& n, const Dimensions& dim) const {
      using namespace display;
      Style& style = FormatDataVector::style_for_punctuation;

      const int delta = this->ndims() - dim.ndims();
      if (delta == 0) {
	stream << std::endl;
      }
      std::string indent = "";
      for (index_type j = 0; j < delta; j++) {
	indent +=  "  ";
      }
      stream << indent << style.apply("{");
      Dimensions newdim(dim);
      newdim.erase(newdim.begin());
      
      if (dim.ndims() > 1 ) {
	stream << std::endl;
      } 

      for (index_type j = 0; j < dim[0]; j++) {
	if (dim.ndims() > 1 ) {
	  Dimensions newdim(dim);
	  newdim.erase(newdim.begin());
	  this->send(stream, n, newdim);
	  if (j < dim[0]-1)  {
	    stream << style.apply(",")<< std::endl;
	  } 
	} else {
	  dispval_strm(stream, (*this)[n++]);
	  if (j < dim[0]-1)  {
	    stream << style.apply(", ");
	  }
	}
      }
      if (dim.ndims() == 1) {
	stream << style.apply("}"); 
      } else if (dim.ndims() == this->ndims()) {
	stream << std::endl << indent << style.apply("}"); 
      } else {
	stream << std::endl << indent << style.apply("}"); 
      }
      return stream;
    }
    
    // stream << operator

    // TODO: implement format

    friend std::ostream& operator<<(std::ostream &stream, const Tensor<E,R,D,M>& t) {
      using namespace display;
      index_type n = 0;
      t.send(stream, n, t.dims());
      return stream;
    }


    //template <class D>	
    friend inline std::istream& operator>>(const std::string s,  Tensor<E,R,D,M>& x) {
      std::istringstream st(s);
      return (st >> x);
    }


    // stream >> operator
    // TODO: implement

    friend std::istream& operator>>(std::istream& stream,  Tensor<E,R,D,M>& x) {	
      return stream;
    }

    // --------------------- FRIENDS ---------------------

  

  };




};


#endif 

