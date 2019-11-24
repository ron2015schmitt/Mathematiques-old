#ifndef MATRICKS__VECTOR_H
#define MATRICKS__VECTOR_H 1




namespace matricks {

 
 
  
  /****************************************************************************
   * Vector -- mathematical vector class.
   ****************************************************************************   
   */

  // NOTE: Do NOT specify M.  The default is defined in the declaration in
  //       preface.h

  template <class D, int NN, int M> class Vector :
    public TensorRW<D,Vector<D,NN,M> > {


  public:     
  typedef D DataType;
  typedef typename NumberType<D>::Type MyNumberType;
  typedef typename ArrayType<D,NN>::Type MyArrayType;


  // *********************** OBJECT DATA ***********************************
  //
  // do NOT declare any other storage.
  // keep the instances lightweight
  //**********************************************************************

    
  private:
    MyArrayType data_;


  public:
    
  //**********************************************************************
  //************************** CONSTRUCTORS ******************************
  //**********************************************************************


  // TODO: never use new. just resize the valarray  
    

  // -------------------  DEFAULT  CONSTRUCTOR: Vector()  --------------------
  explicit Vector<D,NN,M>() {
    constructorHelper();
  }


  // --------------------- Vector(N)  ---------------------

  template<size_t NN1 = NN, EnableConstructorIf<NN1 == 0> = 0>

  explicit Vector<D,NN,M>(const size_type N) { 
    data_.resize(N);
    constructorHelper();
  }


  // --------------------- Vector(N,value)  ---------------------

  template<size_t NN1 = NN, EnableConstructorIf<NN1 == 0> = 0>

    explicit Vector<D,NN,M>(const size_type N, const D val) {
    data_.resize(N);
    *this = val;
    constructorHelper();
  }

  // --------------------- Vector(value)  ---------------------

  template<size_t NN1 = NN, EnableConstructorIf<(NN1 > 0)> = 0>

  explicit Vector<D,NN,M>(const D val) {
    *this = val;
    constructorHelper();
  }
  

  // --------------------- array[]  CONSTRUCTOR ---------------------
  template<size_t NN1 = NN, EnableConstructorIf<NN1 == 0> = 0>

  Vector<D,NN,M>(const size_type N, const D (vals)[]) {
    data_.resize(N);
    *this = vals;
    constructorHelper();
  }

  // ************* C++11 initializer_list CONSTRUCTOR---------------------
  Vector<D,NN,M>(std::initializer_list<D> mylist) {
    if constexpr(NN==0) {
      this->resize(mylist.size());
    }
    *this = mylist;
    constructorHelper();
  }



  // --------------------- Vector(valarray)  ---------------------
  Vector<D,NN,M>(const std::valarray<D>& valar) {
    if constexpr(NN==0) {
      this->resize(valar.size());
    }
    *this = valar;
    constructorHelper();
  }




  // --------------------- Vector(Vector) --------------------

  Vector<D,NN,M>(const Vector<D,NN,M>& v2) {
    if constexpr(NN==0) {
      this->resize(v2.size());
    }
    *this = v2;
    constructorHelper();
  }


  // --------------------- EXPRESSION CONSTRUCTOR --------------------

  template <class A>
  Vector<D,NN,M>(const TensorR<D,A>& x) 
  {
    if constexpr(NN==0) {
      this->resize(x.size());
    }
    
    *this = x;
    constructorHelper();
  }




  // --------------------- constructorHelper() --------------------
    
  void constructorHelper() {
  }







  //**********************************************************************
  //************************** DESTRUCTOR ******************************
  //**********************************************************************

  ~Vector<D,NN,M>() {
  }
  

  //**********************************************************************
  //************************** SIZE ******************************
  //**********************************************************************


  bool isExpression(void) const {
    return false;
  }
  Tensors getEnum() const {
    return T_VECTOR;
  }
  VectorofPtrs getAddresses(void) const  {
    VectorofPtrs myaddr((void*)this);
    return myaddr;
  }

  inline size_type size(void) const {
    return data_.size();
  }
  size_type ndims(void) const {
    return 1;
  }
  Dimensions dims(void) const {
    Dimensions dimensions(size());
    return dimensions;
  }
  Dimensions tdims(void) const {
    Dimensions dimensions(NN);
    return dimensions;
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
 
 
  


    
  //**********************************************************************
  //************************** RESIZE & REHSAPCE ******************************
  //**********************************************************************

  // --------------------- .resize() ---------------------

  // These allow the user to resize a vector


  // *** this is used for resize-by-assignment ***
  template<size_t NN1 = NN, EnableConstructorIf<NN1 == 0> = 0>
    
  TERW_Resize<D>  resize(void) { 
    return  TERW_Resize<D>(*this);
  }

  // this is used to empty the vector of its datastore
  template<size_t NN1 = NN, EnableConstructorIf<NN1 == 0> = 0>
    
  TERW_Resize<D>  resize(void) const {
    this->resize(0);
    return  TERW_Resize<D>(*this);
  }

  // --------------------- .resize(N) ---------------------

  template<size_t NN1 = NN, EnableConstructorIf<NN1 == 0> = 0>

    Vector<D,NN,M>&  resize(const size_type N) { 
    if (N==this->size())
      return *this;
    // reallocate store
    //      delete  data_ ;
    //      data_ = new std::valarray<D>(N);
    data_.resize(N);
    return *this;
  }



  //**********************************************************************
  //************************** ACCESS() ***********************************
  //**********************************************************************


  // -------------------- deep access[] --------------------
  // NOTE: indexes over [0] to [deepsize()]
  // -------------------------------------------------------------
  
  // "read/write"
  MyNumberType& operator[](const index_type n) {
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
      return data_[j][k];
    }
  }

  // read
  const MyNumberType& operator[](const index_type n)  const {
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
      return data_[j][k];
    }
  }


  // -------------------- D element access() --------------------
  // NOTE: indexes over (0) to (size())
  // -------------------------------------------------------------


  
  // "read/write"
  D& operator()(const index_type n)  {
    disp(n);
    disp(data_[n]);
    return data_[n]; 
  }

  // "read only"
  const D& operator()(const index_type n)  const{
    return data_[n]; 
  }




    // Accessing a slice of values
    
    TERW_Subset<D> operator[](const slc& slice)  { 
      return (*this)[slice.toIndexVector(size())];
    }
    const TERW_Subset<D>  operator[](const slc& slice) const  {
      //      display::log3("Vector","operator[]","(const slc& slice)\n");
      return (*this)[slice.toIndexVector(size())];
    }


    // Accessing a SET of values using a vector of ints

    TERW_Subset<D> operator[](const Vector<index_type>& ii) {
      return TERW_Subset<D>(*this, ii);
    }
    const TERW_Subset<D> operator[](const Vector<index_type>& ii) const {
      return TERW_Subset<D>(*this, ii);
    }



    
    // Accessing a SET of values using a MASK
    
    TERW_Submask<D> operator[](const Vector<bool>& mask)  {
      return  TERW_Submask<D>(*this,mask);
    }
    const TERW_Submask<D> operator[](const Vector<bool>& mask)  const {
      return  TERW_Submask<D>(*this,mask);
    }


  //Accessing a SET of values using a list

  TERW_Subset<D> operator[](const std::initializer_list<index_type>& list) {
    return  TERW_Subset<D>(*this, list);
  }
  const TERW_Subset<D> operator[](const std::initializer_list<index_type>& list) const {
    return  TERW_Subset<D>(*this, list);
  }





  //**********************************************************************
  //********************* Direct access to data_  ***********************************
  //**********************************************************************

  // -------------------- getArray() --------------------
  // "read/write" to the wrapped valarray/aray
  auto& getValArray()  {
    return data_; 
  }

    
  //**********************************************************************
  //************************** ASSIGNMENT **************************************
  //**********************************************************************

  // Any new assignment operators should also be addedc to TensorRW for consistency.
  // For this reason, in most cases, its preferred to overload the function vcast()
  // equals functions are included so that derived classes can call these functions

  // Assign all elements to the same constant value
  Vector<D,NN,M>& equals(const D d) { 
    for (index_type i = 0; i < size(); i++) 
      (*this)(i)=d; 
    return *this;
  }
  Vector<D,NN,M>& operator=(const D d) { 
    return equals(d);
  }


  // Assignment to a vector expression
  template <class A>  Vector<D,NN,M>& equals(const TensorR<D,A>& x) {  

    // resize to avoid segmentation faults
    // TODO: issue warning if resize neede, deepsize()?
    if constexpr(NN==0) {
	if (this->size() != x.size()) {
	  resize(x.size());
	}
    }

    //      mout<<std::endl<< "inside normal Vector operator=" <<std::endl;
    if (common(*this,x)){
      //mout<< "  common addresses found" <<std::endl;
      Vector<MyNumberType> vtemp(deepsize());
      for (index_type i = 0; i < deepsize(); i++) 
	vtemp[i] = x[i];   
      for (index_type i = 0; i < deepsize(); i++) 
	(*this)[i] = vtemp[i];
    } else {
      //mout<< "  NO common addresses found" <<std::endl;
      for (index_type i = 0; i < deepsize(); i++)
	(*this)[i] = x[i];   
    }
    //mout<<std::endl<< "DONE normal Vector operator=" <<std::endl;  
    return *this; 
  }
    
  template <class A>  Vector<D,NN,M>& operator=(const TensorR<D,A>& x) {  
    return equals(x);
  }
    


  template <class X, class Y>  Vector<D,NN,M>& operator=(const TensorR<X,Y>& x) {
    //TODO: what is the deal with this function?
    
    mout << __FUNCTION__ <<" ";
    //      return *this;
    const Y& y = x.derived();
    disp(y.classname());
    disp(y.isExpression());
    cr();
    Vector<double> v(2);
    y[0];  
      
    return *this;
            
    //tdisp(b0);
    for (index_type i = 0; i<size(); i--) {
      //	Object<D> q = y[i];
      //	for (index_type j = 0; j<y[i].size(); j--) {
      //	  mdisp(i,j,q[j]);
      //	}
    }
    return *this; 
  }


  std::string bottom(){
    typename FundamentalType<D>::Type d;
    return display::getTypeName(d);
  }



  // ------------------------ Vector = array[] ----------------

  Vector<D,NN,M>& equals(const D array[]) {
    for (index_type i = 0; i < size(); i++)  { 
      (*this)(i) = array[i];
    }
    return *this;
  }
  Vector<D,NN,M>& operator=(const D array[]) {
    return equals(array);
  }




    

  // Copy asignment
  Vector<D,NN,M>& equals(const Vector<D,NN,M>& v2) {

    // resize to avoid segmentation faults
    // TODO: chekc deepsize
    if constexpr(NN==0) {
	if (this->size() != v2.size()) {
	  resize(v2.size());
	}
    }

    for(index_type i=0; i<deepsize(); i++ )
      data_[i] = v2[i];    
    return *this;
  }



  Vector<D,NN,M>& operator=(const Vector<D,NN,M>& v2) {
    return equals(v2);
  }
  template <class B>
  Vector<D,NN,M>& operator=(const TERW_Resize<D>& b) { 
    return *this;
  }


  Vector<D,NN,M>& equals(const std::list<D>& mylist) {
    // resize to avoid segmentation faults
    if constexpr(NN==0) {
	if (this->size() != mylist.size()) {
	  resize(mylist.size());
	}
    }
    index_type i = 0;
    for (typename std::list<D>::const_iterator it = mylist.begin(); it != mylist.end(); ++it)  { 
      (*this)(i++) = *it;
    }
    return *this;
  }
  Vector<D,NN,M>& operator=(const std::list<D>& mylist) {
    return equals(mylist);
  }

    
  // assignment to a C++11 list
  Vector<D,NN,M>& equals(const std::initializer_list<D>& mylist) {
    // resize to avoid segmentation faults
    if constexpr(NN==0) {
	if (this->size() != mylist.size()) {
	  resize(mylist.size());
	}
    }
    size_type k = 0;
    typename std::initializer_list<D>::iterator it; 
    for (it = mylist.begin(); it != mylist.end(); ++it)  { 
      (*this)(k++) = *it;
    }

    return *this;
  }
  Vector<D,NN,M>& operator=(const std::initializer_list<D>& mylist) {
    return equals(mylist);
  }




  // assignment to a std::vector
  Vector<D,NN,M>& equals(const std::vector<D>& vstd) {
      

    // resize to avoid segmentation faults
    if constexpr(NN==0) {
	if (this->size() != vstd.size()) {
	  resize(vstd.size());
	}
    }

    for(size_type i = 0; i < size(); i++)
      (*this)(i) = vstd[i];    

    return *this;
  }


  Vector<D,NN,M>& operator=(const std::vector<D>& vstd) {
    return equals(vstd);
  }



  // assignment to a std::array
  template <std::size_t N>
  Vector<D,NN,M>& equals(const std::array<D,N>& varray) {
      

    // resize to avoid segmentation faults
    if constexpr(NN==0) {
	if (this->size() != varray.size()) {
	  resize(varray.size());
	}
    }

    for(size_type i = 0; i < size(); i++)
      (*this)(i) = varray[i];    

    return *this;
  }


  template <std::size_t n>
  Vector<D,NN,M>& operator=(const std::array<D,n>& varray) {
    return equals(varray);
  }



  // assignment to a std::val_array
  Vector<D,NN,M>& equals(const std::valarray<D>& varray) {
      

    // resize to avoid segmentation faults
    if constexpr(NN==0) {
	if (this->size() != varray.size()) {
	  resize(varray.size());
	}
    }

    for(size_type i = 0; i < size(); i++)
      (*this)(i) = varray[i];    

    return *this;
  }

  Vector<D,NN,M>& operator=(const std::valarray<D>& varray) {
    return equals(varray);
  }




  //**********************************************************************
  //************************** MATH **************************************
  //**********************************************************************


  //----------------- .roundzero(tol) ---------------------------
  // NOTE: in-place
    
  Vector<D,NN,M>&  roundzero(D tolerance = MatricksHelper<D>::tolerance) { 
    for(index_type i=size(); i--;) {
      data_[i] = matricks::roundzero(data_[i], tolerance);
    }
    return *this;
  }


  //----------------- .conj() ---------------------------
  // NOTE: in-place

  template<typename T=D> EnableMethodIf<is_complex<T>{}, Vector<T>&> 

  conj() {
    using std::conj;
    for(index_type i=size(); i--;) {
      data_[i] = conj(data_[i]);
    }
    return *this;
  }



  //**********************************************************************
  //***************** in-place modification********************************
  //**********************************************************************

  // .sort()
  //         sorts in place and returns the permuted indices

  Vector<index_type>& sort() {

    const size_type N = size();
    Vector<index_type> &ivec = *(new Vector<index_type>(N));

    if (N==0)
      return ivec;
    
    std::vector<Pair<D> > temp(N);

    for (index_type i = 0; i < N ; i++ ) {
      temp[i].index = i;
      temp[i].data = data_[i];
    }
    
    
    std::sort(temp.begin(),temp.end());
    
    
    for (index_type i = 0; i < N ; i++ ) {
      ivec(i) = temp[i].index;
      data_[i] = temp[i].data;
    }
    
    return ivec;

  }


  // .quniq()
  //         removes adjacent duplicates
  //  template<typename T=D> EnableMethodIf<is_complex<T>{}, Vector<T>&> 
  template<typename T=index_type> EnableMethodIf<NN==0, Vector<T>& > 

  quniq() {

    const size_type N = size();

    if (N==0)
      return *(new Vector<index_type>(0));
    
    std::queue<Pair<D> > unique;
	
    Pair<D> prevpair(0, data_[0]);
    unique.push(prevpair);
    for (index_type i = 1; i < N ; i++ ) {
      Pair<D> mypair(i, data_[i]);
      if (mypair.data != prevpair.data) {
	unique.push(mypair);
	prevpair = mypair;
      } 
    }

    const size_type Nnew = unique.size();
    Vector<index_type> &indexvec = *(new Vector<index_type>(Nnew));
    resize(Nnew);
    for (index_type i = 0; i < Nnew ; i++ ) {
      Pair<D> mypair = unique.front();
      unique.pop();
      indexvec(i) = mypair.index;
      data_[i] = mypair.data;
    }

    return indexvec;
  }


  // .uniq()
  //         removes all duplicates
  template<typename T=index_type> EnableMethodIf<NN==0, Vector<T>& > 

  uniq() {

    const size_type N = size();

    if (N==0)
      return *(new Vector<index_type>(0));
    
    std::map<index_type,D> mymap;
    for (index_type j = 0; j < N ; j++ ) {
      mymap[j] = data_[j];
    }

    for (index_type j = 0; j < N ; j++ ) {
      if (mymap.find(j) == mymap.end()) continue;
      Pair<D> pair1(j, data_[j]);
      for (index_type k = j+1; k < N ; k++ ) {
	if (mymap.find(k) == mymap.end()) continue;
	Pair<D> pair2(k, data_[k]);
	if (pair1.data == pair2.data) {
	  mymap.erase(k);
	} 
      }
    }

    const size_type Nnew = mymap.size();
    Vector<index_type> &indexvec = *(new Vector<index_type>(Nnew));
    resize(Nnew);
    index_type k = 0;
    for (typename std::map<index_type,D>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
      indexvec(k) = it->first;
      data_[k++] = it->second;
    }

    return indexvec;
  }


  Vector<D,NN,M>& reverse() {

    const size_type N = size();
    if (N==0)
      return *this;
   
    for (index_type i = 0; i < N/2 ; i++ ) {
      D temp = data_[i];
      data_[i] = data_[N-i-1];
      data_[N-i-1] = temp;
    }
      
    return *this;
      
  }


  // .cumsum() -- cumulative sum

  Vector<D,NN,M>& cumsum() {
    const size_type N = size();
    D sum = 0;
    for (index_type i = 0; i < N ; i++ ) {
      sum += data_[i];
      data_[i] = sum;
    }
    return *this;
  }

  // .cumprod()  --  cumulative product

  Vector<D,NN,M>& cumprod() {
    const size_type N = size();
    D prod = 1;
    for (index_type i = 0; i < N ; i++ ) {
      prod *= data_[i];
      data_[i] = prod;
    }
    return *this;
  }


  // .cumtrapz() -- cumulative trapezoidal summation

  Vector<D,NN,M>& cumtrapz() {
    const size_type N = size();
    if (N==0) return *this;
    D sum = data_[0]/2;
    data_[0] = 0;
    for (index_type i = 1; i < N ; i++ ) {
      sum += data_[i];
      data_[i] = sum - data_[i]/2;
    }
    return *this;
  }

  // integrate_a2x(order)
  // order  name
  //     0  rectangular
  //     1  trapazoidal
  Vector<D,NN,M>& integrate_a2x(const D a, const D b, const int order=1) {

    const size_type N = size();

    if (order == 0) {
      this->cumsum();
      const D dx = (b-a)/D(N);
      for (index_type i = 0; i < N ; i++ ) {
	data_[i] *= dx;
      }
    } else if (order == 1) {
      this->cumtrapz();
      const D dx = (b-a)/D(N-1);
      for (index_type i = 0; i < N ; i++ ) {
	data_[i] *= dx;
      }
    }  else {
      //TODO: issue error
    }
    return *this;
  }


  // .cumsumrev() -- cumulative sum -- from last to first

  Vector<D,NN,M>& cumsum_rev() {
    const size_type N = size();

    D sum = 0;
    for (index_type i = 0; i < N ; i++ ) {
      sum += data_[N-1-i];
      data_[N-1-i] = sum;
    }
    return *this;
  }

  // .cumprodrev()  --  cumulative product  -- from last to first

  Vector<D,NN,M>& cumprod_rev() {
    const size_type N = size();

    D prod = 1;
    for (index_type i = 0; i < N ; i++ ) {
      prod *= data_[N-1-i];
      data_[N-1-i] = prod;
    }
    return *this;
  }


  // .cumtrapz() -- cumulative trapezoidal summation -- from last to first

  Vector<D,NN,M>& cumtrapz_rev() {
    const size_type N = size();
    if (N==0) return *this;

    D sum = data_[N-1]/2;
    data_[N-1] = 0;
    for (index_type i = 1; i < N ; i++ ) {
      sum += data_[N-1-i];
      data_[N-1-i] = sum - data_[N-1-i]/2;
    }
    return *this;
  }



  // integrate_x2b
  // order  name
  //     0  rectangular
  //     1  trapazoidal
  Vector<D,NN,M>& integrate_x2b(const D a, const D b, const int order=1) {
    const size_type N = size();

    if (order == 0) {
      this->cumsum_rev();
      const D dx = (b-a)/(N);
      for (index_type i = 0; i < N ; i++ ) {
	data_[N-1-i] *= dx;
      }
    } else if (order == 1) {
      this->cumtrapz_rev();
      const D dx = (b-a)/(N-1);
      for (index_type i = 0; i < N ; i++ ) {
	data_[N-1-i] *= dx;
      }
    }  else {
      //TODO: issue error
    }
    return *this;
  }



  // diff   (v[n] = v[n] - v[n-1])
  Vector<D,NN,M>& diff(const bool periodic=false) {
    const size_type N = size();
    if (N<=1) return *this;

    D temp;
    if (periodic) {
      temp = data_[0] - data_[N-1];
    } else {
      temp = data_[1] - data_[0];
    }

    for (index_type i = 0; i < N-1 ; i++ ) {
      data_[N-1-i] = data_[N-1-i] - data_[N-2-i];
    }

    data_[0] = temp;
    return *this;
  }

  // diff_rev   (v[n] = v[n+1] - v[n])
  Vector<D,NN,M>& diff_rev(const bool periodic=false) {
    const size_type N = size();
    if (N<=1) return *this;

    D temp;
    if (periodic) {
      temp = data_[0] - data_[N-1];
    } else {
      temp = data_[N-1] - data_[N-2];
    }

    for (index_type i = 0; i < N-1 ; i++ ) {
      data_[i] = data_[i+1] - data_[i];
    }

    data_[N-1] = temp;
    return *this;
  }


  // deriv -  derivative
  // any change in the default parameters must be likewise made in vfunctions.h: deriv(...)

  Vector<D,NN,M>& deriv(const D a, const D b, const int n=1, int Dpts=7, const bool periodic=false) {
    //mdisp(a,b,n,Dpts,periodic);
    const size_type N = size();
    if (N<=1) return *this;

    const D dx = (b-a)/D(N-1);

    if (Dpts > N ) {
      //TODO: error or warning
      Dpts = N;
    }

    if (Dpts == 2) {
      this->diff(periodic);
      for (index_type i = 0; i < N ; i++ ) {
	data_[i] /= dx;
      }
	
    } else if (Dpts == 3) {
      D prev;
      D curr;
      D last;
      if (periodic) {
	// first point
	prev = data_[1] - data_[N-1];
	// last
	last = data_[0] - data_[N-2];
      } else {
	// first point
	prev = -3*data_[0] + 4*data_[1] - data_[2];
	// last
	last = 3*data_[N-1] - 4*data_[N-2] + data_[N-3];
      }
	
      const D c0 = 0.5/dx;
      for (index_type i = 1; i < N-1 ; i++ ) {
	curr = data_[i+1] - data_[i-1];
	data_[i-1] = c0*prev;
	prev = curr;
      }
      data_[N-2] = c0*prev;
      data_[N-1] = c0*last;
	
    } else if (Dpts == 5) {
      D prev1;
      D prev2;
      D curr;
      D last;
      D lastminus1;
      if (periodic) {
	// second to last point
	lastminus1 = data_[N-4] - 8*data_[N-3] + 8*data_[N-1] - data_[0];
	// last
	last       = data_[N-3] - 8*data_[N-2] + 8*data_[0]   - data_[1];
	// first point
	prev2      = data_[N-2] - 8*data_[N-1] + 8*data_[1]   - data_[2];
	// second point
	prev1      = data_[N-1] - 8*data_[0]   + 8*data_[2]   - data_[3];
      } else {
	lastminus1 =   -data_[N-5] +  6*data_[N-4] - 18*data_[N-3] + 10*data_[N-2] +  3*data_[N-1];
	last       =  3*data_[N-5] - 16*data_[N-4] + 36*data_[N-3] - 48*data_[N-2] + 25*data_[N-1];
	prev2      = -3*data_[4]   + 16*data_[3]   - 36*data_[2]   + 48*data_[1]   - 25*data_[0];
	prev1      =    data_[4]   -  6*data_[3]   + 18*data_[2]   - 10*data_[1]   -  3*data_[0];
      }
	
      const D c0 = 1/(12*dx);
      for (index_type i = 2; i < N-2 ; i++ ) {
	curr = data_[i-2] - 8*data_[i-1] + 8*data_[i+1]  - data_[i+2];
	data_[i-2] = c0*prev2;
	prev2 = prev1;
	prev1 = curr;
      }
      data_[N-4] = c0*prev2;
      data_[N-3] = c0*prev1;
      data_[N-2] = c0*lastminus1;
      data_[N-1] = c0*last;
	
    } else if (Dpts == 7) {
      D prev1;
      D prev2;
      D prev3;
      D curr;
      D last;
      D lastminus1;
      D lastminus2;
      if (periodic) {
	lastminus2 = -data_[N-6] + 9*data_[N-5] - 45*data_[N-4] + 45*data_[N-2]  - 9*data_[N-1] + data_[0];
	lastminus1 = -data_[N-5] + 9*data_[N-4] - 45*data_[N-3] + 45*data_[N-1]  - 9*data_[0] + data_[1];
	last  = -data_[N-4] + 9*data_[N-3] - 45*data_[N-2] + 45*data_[0]  - 9*data_[1] + data_[2];
	prev3 = -data_[N-3] + 9*data_[N-2] - 45*data_[N-1] + 45*data_[1]  - 9*data_[2] + data_[3];
	prev2 = -data_[N-2] + 9*data_[N-1] - 45*data_[0]   + 45*data_[2]  - 9*data_[3] + data_[4];
	prev1 = -data_[N-1] + 9*data_[0]   - 45*data_[1]   + 45*data_[3]  - 9*data_[4] + data_[5];
      } else {
	lastminus2= -(  2*data_[N-1] - 24*data_[N-2] -  35*data_[N-3] +  80*data_[N-4] -  30*data_[N-5] +  8*data_[N-6] -    data_[N-7]);
	lastminus1= -(-10*data_[N-1] - 77*data_[N-2] + 150*data_[N-3] - 100*data_[N-4] +  50*data_[N-5] - 15*data_[N-6] +  2*data_[N-7]);
	last =     -(-147*data_[N-1] +360*data_[N-2]- 450*data_[N-3] + 400*data_[N-4] - 225*data_[N-5] + 72*data_[N-6] - 10*data_[N-7]);
	  
	prev3 = -147*data_[0] + 360*data_[1] - 450*data_[2] + 400*data_[3] - 225*data_[4] + 72*data_[5] - 10*data_[6];
	prev2 =  -10*data_[0] -  77*data_[1] + 150*data_[2] - 100*data_[3] +  50*data_[4] - 15*data_[5] +  2*data_[6];
	prev1 =    2*data_[0] -  24*data_[1] -  35*data_[2] +  80*data_[3] -  30*data_[4] +  8*data_[5] -    data_[6];
      }
      const D c0 = 1/(60*dx);
      for (index_type i = 3; i < N-3 ; i++ ) {
	curr = -data_[i-3] + 9*data_[i-2] - 45*data_[i-1] + 45*data_[i+1]  - 9*data_[i+2] + data_[i+3];
	data_[i-3] = c0*prev3;
	prev3 = prev2;
	prev2 = prev1;
	prev1 = curr;
      }
      data_[N-6] = c0*prev3;
      data_[N-5] = c0*prev2;
      data_[N-4] = c0*prev1;
      data_[N-3] = c0*lastminus2;
      data_[N-2] = c0*lastminus1;
      data_[N-1] = c0*last;

	
    }  else {
      //TODO: issue error
    }
    if (n>1) {
      return this->deriv(a,b,n-1,Dpts,periodic);
    } 
    return *this;
  }


    
  //**********************************************************************
  //************************** Text and debugging ************************
  //**********************************************************************

  inline std::string classname() const {
    using namespace display;
    std::string s = "Vector";		
    s += StyledString::get(ANGLE1).get();
    D d;
    s += getTypeName(d);
    if (NN!=0) {
      s += StyledString::get(COMMA).get();
      s += "NN=";
      s += num2string(NN);
    }
    //    if (M>1) {
    //      s += StyledString::get(COMMA).get();
    //      s += "M=";
    //      s += num2string(M);
    //    }
    s += StyledString::get(ANGLE2).get();			
    return s;	
  }


#if MATRICKS_DEBUG>=1
  std::string expression(void) const {
    return "";
  }
#endif




  // stream << operator

  friend std::ostream& operator<<(std::ostream &stream, const Vector<D,NN,M>& v) {
    using namespace display;
    Style& style = FormatDataVector::style_for_punctuation;
    stream << style.apply(FormatDataVector::string_opening);
    const matricks::index_type N = FormatDataVector::max_elements_per_line;
    matricks::index_type k = 0;
    for (matricks::index_type ii = 0; ii < v.size(); ii++, k++) {
      if (k >= N)  {
	stream << style.apply(FormatDataVector::string_endofline);
	k = 0;
      }
      dispval_strm(stream, v(ii));
      if (ii < v.size()-1)  {
	stream << style.apply(FormatDataVector::string_delimeter);
      }
    }
    stream << style.apply(FormatDataVector::string_closing);

    return stream;
  }


  //template <class D>	
  friend inline std::istream& operator>>(const std::string s,  Vector<D,NN,M>& x) {	
    std::istringstream st(s);
    return (st >> x);
  }


  // stream >> operator

  friend std::istream& operator>>(std::istream& stream,  Vector<D,NN,M>& x) {	
    // const size_type LINESZ = 32768;
    // char line[LINESZ];
    // std::vector<D> v;
    // size_type N = 0;
    // const size_type Nold = x.size();
    // D temp;
    // size_type Nlines = 0;
    // std::istringstream strmline;

    // switch (x.textformat()) {
    // case text_braces: 
    // 	{
    // 	  enum States {begin, invec, waitingforcomma, end};
    // 	  States state = begin;

    // 	  while( (state!=end) && stream.getline(line,LINESZ)){
    // 	    Nlines++;
    // 	    strmline.clear();
    // 	    strmline.str(line);
	
    // 	    char c;
    // 	    size_type Nchars=0;
    // 	    while((state!=end) && strmline.get(c) ){
    // 	      Nchars++;
    // 	      if (isspace(c))
    // 		continue;
    // 	      if (c=='%')
    // 		break; // ignore rest of line "%" signifies a comment
	  
    // 	      switch (state) {
    // 	      case begin:
    // 		if  (c=='{')  {
    // 		  state = invec;
    // 		  break;
    // 		}else {
    // 		  std::string extrastr = "Expecting an opening brace.";
    // 		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
    // 		  return stream;
    // 		}
    // 		break;
    // 	      case invec:
    // 		if  (c=='}') {
    // 		  state = end;
    // 		  break;
    // 		}
    // 		strmline.putback(c);
    // 		if (strmline>>temp){
    // 		  v.push_back(temp);
    // 		  N++;
    // 		  state = waitingforcomma;
    // 		  break;
    // 		}else {
    // 		  std::string extrastr = "Expecting a vector element.";
    // 		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
    // 		  return stream;
    // 		}
    // 		return stream;
    // 	      case waitingforcomma:
    // 		if  (c=='}') {
    // 		  state = end;
    // 		  break;
    // 		}
    // 		if  (c==',') {
    // 		  state = invec;
    // 		  break;
    // 		}else {
    // 		  std::string extrastr = "Expecting a comma.";
    // 		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
    // 		  return stream;
    // 		}
    // 		break;
    // 	      case end:
    // 		{
    // 		  std::string extrastr = "Expecting a closing brace.";
    // 		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
    // 		}
    // 		return stream;
    // 		break;
    // 	      default:
    // 		bug_report(__FILE__,__LINE__);
    // 		return stream;
    // 		break;
    // 	      }
    // 	    }
    // 	  }
    // 	  if (Nold==0) {
    // 	    x.resize(N);
    // 	  } else if (N != Nold) {
    // 	    vbad_input_stream_size(x.name(),line,N,Nold);
    // 	    return stream;
    // 	  }
    // 	}
    // 	break;
    // case text_nobraces: 
    // 	{
    // 	  std::string oldline = line;
    // 	  if (Nold==0) { // read until stream ends
    // 	    while( stream.getline(line,LINESZ) ){
    // 	      Nlines++;
    // 	      strmline.clear();
    // 	      strmline.str(line);
    // 	      char c;
    // 	      size_type Nchars=0;
    // 	      while(strmline.get(c)){
    // 		Nchars++;
    // 		if (isspace(c))
    // 		  continue;
    // 		if (c=='%')
    // 		  break; // ignore rest of line "%" signifies a comment
		
    // 		strmline.putback(c);
    // 		if (strmline>>temp){
    // 		  v.push_back(temp);
    // 		  N++;
    // 		} else { 
    // 		  std::string extrastr ="";
    // 		  if ( (c=='{') || (c=='}')||(c==','))
    // 		    extrastr = "Braces and commas are not allowed in 'text_nobraces' mode";
    // 		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
    // 		  return stream;
    // 		}
    // 	      }
    // 	    }
    // 	    x.resize(N);
    // 	  } else { // just read in N elements and stop
    // 	    while( (N<Nold) && stream.getline(line,LINESZ) ){
    // 	      Nlines++;
    // 	      strmline.clear();
    // 	      strmline.str(line);
    // 	      char c;
    // 	      size_type Nchars=0;
    // 	      while((N<Nold) && strmline.get(c) ){
    // 		Nchars++;
    // 		std::string stemp = strmline.str();
    // 		if (isspace(c))
    // 		  continue;
    // 		if (c=='%')
    // 		  break; // ignore rest of line "%" signifies a comment
		
    // 		strmline.putback(c);
    // 		if (strmline>>temp){
    // 		  v.push_back(temp);
    // 		  N++;
    // 		} else { 
    // 		  std::string extrastr ="";
    // 		  if ( (c=='{') || (c=='}')||(c==','))
    // 		    extrastr = "Braces and commas are not allowed in 'text_nobraces' mode";
    // 		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
    // 		  return stream;
    // 		}
    // 	      }
    // 	      oldline = line;
    // 	    }
    // 	    if (N != Nold) {
    // 	      vinput_stream_size_too_small(x.name(),oldline,N,Nold);
    // 	      return stream;
    // 	    }
    // 	  }
    // 	}
    // 	break;
    // default:
    // 	bug_report(__FILE__,__LINE__);
    // 	break;
    // } //switch

    // for(size_type i=0; i<N; i++)
    // 	x[i] = v[i];
      
    // return restore_stream(stream,strmline);
    return stream;
  }

  // --------------------- FRIENDS ---------------------

  

  };




};


#endif 

