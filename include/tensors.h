#ifndef MATHQ__TENSORS_H
#define MATHQ__TENSORS_H



namespace mathq {

  //-------------------------------------------------------------------
  //                  Classes etc defined in this file
  //-------------------------------------------------------------------
  
  class VectorofPtrs;
  template <class DAT> class Pair;
  class Dimensions;
  class Indices;
  enum Tensors : unsigned int;
  enum TensorOrExpression : unsigned int;
  template <Tensors, class D> struct TensorType;


  // **************************************************************************
  // * std::vector related functions
  // ************************************************************************** 

  template <class D, int NN> class ArrayType {
  public:
    typedef std::array<D,NN> Type;
  };

  template <class D> class ArrayType<D,0> {
  public:
    typedef std::valarray<D> Type;
  };


  // **************************************************************************
  // * std::vector related functions
  // ************************************************************************** 
  

  // TODO: do we need these?  move inside the class
  template <typename T>
    std::vector<T> mergeVectors(const std::vector<T> v1, const std::vector<T> v2) {
    std::vector<T> v3 = v1;
    v3.insert( v3.end(), v2.begin(), v2.end() );
    return v3;
  }

  template <typename T>
    std::vector<T> createVector(const T x) {
    std::vector<T> v1;
    v1.push_back(x);
    return v1;
  }


  /**********************************************************************
   *  VectorofPtrs
   ********************************************************************** 
   */

  class VectorofPtrs : public std::vector<const void*> {
   
  public:
    typedef typename std::vector<const void*> Parent;

    VectorofPtrs() {
    }
    VectorofPtrs(const void* addr) {
      VectorofPtrs();
      this->add(addr);
    }
    VectorofPtrs(const std::vector<const void*> addrs) {
      VectorofPtrs();
      this->add(addrs);
    }
        
    inline void add(const void* addr) {
      this->push_back(addr);
    }
    
    inline void add(const VectorofPtrs& addrs) {
      this->insert(this->end(), addrs.begin(), addrs.end());
    }
    
    // true if this vector and another share an element in common (ie same value)

    inline bool common(const VectorofPtrs& addrs) const {
      for (size_type i = 0; i < addrs.size(); i++){
	const void* addr = addrs[i];
	if ( std::find(this->begin(), this->end(), addr) != this->end() ) {
	  return true;
	}
      }
      return false;
    }

    inline std::string classname() const {
      return "VectorofPtrs";
    }

    inline friend std::ostream& operator<<(std::ostream &stream, const VectorofPtrs& vptrs) {
      using namespace display;

      stream << "{";
      for (size_type ii = 0; ii < vptrs.size(); ii++) {
	if (ii>0)  stream << ", ";
	dispval_strm(stream, vptrs[ii]);
      }
      stream << "}";

      return stream;
    }

    
  };    

  // true if the two vectors have a value in common

  inline bool common(const VectorofPtrs& addrs1, const VectorofPtrs& addrs2) {
    return addrs1.common(addrs2);
  }
   
  //***********************************************************************
  //      Pair class:  each pair is (index, data)
  //                   index = int
  //                   data equals DAT
  //***********************************************************************

  // TODO: add classname() as well as << stream
  
  template <class DAT> class Pair {
  public:
    index_type index;
    DAT data;
  Pair(index_type index_, DAT data_) : index(index_), data(data_) {}
  Pair() : index(0), data(DAT(0)) {}
    bool operator<(const Pair<DAT>& pair2) const {
      return ((*this).data < pair2.data);
    }
    inline std::string classname() const {
      return "Pair";
    }
    inline friend std::ostream& operator<<(std::ostream &stream, const Pair<DAT>& pair) {
      using namespace display;

      stream << "(";
      stream << pair.index;
      stream << " : ";
      stream << pair.data;
      stream << ")";

      return stream;
    }
  };

  // -------------------------------------------------------------------
  //
  // Indices - class to hold dimensions of Tensors
  // -------------------------------------------------------------------


  class Indices : public std::vector<index_type> {
  private:
  public:
    typedef typename std::vector<index_type> Parent;
    typedef typename Parent::iterator Iterator;
    Indices(const Indices& inds);
    Indices();
    Indices(const index_type n);
    Indices(const Parent& inds);    
    Indices(const std::initializer_list<index_type> list);
    bool equiv(const Indices& inds) const;
    Indices& getReverse() const;
    inline std::string classname() const;
    friend std::ostream& operator<<(std::ostream &stream, const Indices& inds);

  };


  inline bool equiv(const Indices& inds1, const Indices& inds2) {
    return inds1.equiv(inds2);
  }


  // -------------------------------------------------------------------
  //
  // Dimensions - class to hold dimensions of Tensors
  // -------------------------------------------------------------------

  class Dimensions : public std::vector<size_type> {
  private:
    size_type datasize_;


  public:
    typedef typename std::vector<size_type> Parent;
    typedef typename Parent::iterator Iterator;
    typedef size_type ElementType;
    Dimensions(const Dimensions& dims) {
      resize(dims.rank(),0);
      for(int k = 0; k < dims.rank(); k++) {
	(*this)[k] = dims[k];
      }
      calcSize();
    }
    // TODO: use parmpack instead, to handle any number of dimensions as input
    
    Dimensions() {
      resize(0,0);
      calcSize();
    }
    Dimensions(const size_type dim1) {
      resize(1,0);
      (*this)[0] = dim1;
      calcSize();
    }
    Dimensions(const size_type dim1, const size_type dim2) {
      resize(2,0);
      (*this)[0] = dim1;
      (*this)[1] = dim2;
      calcSize();
    }
    Dimensions(const size_type dim1, const size_type dim2, const size_type dim3) {
      //      mdisp3(dim1,dim2,dim3);
      resize(3,0);
      //      disp3(size());
      (*this)[0] = dim1;
      (*this)[1] = dim2;
      (*this)[2] = dim3;
      calcSize();
    }
    Dimensions(const size_type dim1, const size_type dim2, const size_type dim3, const size_type dim4) {
      //      mdisp3(dim1,dim2,dim3);
      resize(4,0);
      //      disp3(size());
      (*this)[0] = dim1;
      (*this)[1] = dim2;
      (*this)[2] = dim3;
      (*this)[3] = dim4;
      calcSize();
    }

    // C++11 init list 
    Dimensions(const std::initializer_list<size_type>& list) {
      const size_type N =  list.size();
      resize(N,0);
      index_type i = 0;
      typename std::initializer_list<size_type>::iterator it; 
      for (it = list.begin(); it != list.end(); ++it)  { 
	(*this)[i++] = *it;
      }
      calcSize();
    }
    
    Dimensions(const Parent& vec) {
      resize(vec.size(),0);
      for(int k = 0; k < vec.size(); k++) {
	(*this)[k] = vec[k];
      }
      calcSize();
    }
    

    // return this object with size 1 dimensions removed
    
    Dimensions& reduce() const {
      Dimensions* v = new Dimensions();
      for (size_type i = 0; i < this->rank(); i++) {
	if ((*this)[i] != 1) {
	  v->push_back((*this)[i]);
	}
      }
      return *v;
    }
    
    bool equiv(const Dimensions& dims) const {
      return (this->reduce() == dims.reduce());
    }

    size_type rank() const {
      return Parent::size();
    }
    size_type ndims() const {
      return Parent::size();
    }
    size_type datasize() const {
      return datasize_;
    }


    index_type index(const Indices& inds) const {
      const index_type M = this->ndims();
      index_type k = 0;
      for(index_type n = 0; n < M; n++) {
	size_type N = (*this)[n];
	index_type j = inds[n];
	k = N*k + j;
      }
      return k;
    }


    inline Indices& indices(const index_type k) const {
      Indices& myinds = *(new Indices(ndims()));
      index_type prev = k;
      // This loop must go in reverse order.  Do NOT change.
      for(index_type n = ndims()-1; n > 0 ; n--) {
	size_type N = (*this)[n];
	index_type temp = prev/N;
	myinds[n] = prev - N*temp;
	prev = temp;
      }
      if (ndims()>0) {
	myinds[0] = prev;
      }
      return myinds;
    }


    // getTranspose() - this reverses the order of the dimensions

    Dimensions& getReverse() const {
      Dimensions* tdims = new Dimensions();
      // reverse order
      for(int k = this->ndims()-1; k >= 0 ; k--) {
	tdims->push_back((*this)[k]);
      }
      return *tdims;
    }

  
    Iterator erase(const Iterator iterator) {
      Iterator newit = Parent::erase(iterator);
      this->calcSize();
      return newit;
    }

    void push_back(const ElementType n) {
      Parent::push_back(n);
      this->calcSize();
    }
    void pop_back() {
      Parent::pop_back();
      this->calcSize();
    }

    void calcSize() {
      datasize_ = 1;
      for (int k = 0; k < this->rank(); k++) {
	datasize_ *= (*this)[k];
      }
    }
        
    inline std::string classname() const {
      return "Dimensions";
    }


    inline friend std::ostream& operator<<(std::ostream &stream, const Dimensions& dims) {
      using namespace display;
      stream << "{";
      for (size_type ii = 0; ii < dims.rank(); ii++) {
	if (ii>0)  stream << ", ";
	dispval_strm(stream, dims[ii]);
      }
      stream << "}";
      return stream;
    }
  };


  inline bool equiv(const Dimensions& dims1, const Dimensions& dims2) {
    return dims1.equiv(dims2);
  }


  

  // -------------------------------------------------------------------
  //
  // Tensors enum - one enum for each actual Tensor:
  //                Scalar, Vector, Matrix, etc. And then two expressions.
  //                return type of getEnum
  //
  // TensorType struct - this returns the corresponding type for
  //                     a given enum, which allows to create a new
  //                     varieble that is of the same class as a variable
  //                     that was passed to the code
  //
  // NOTE: by combining this enum functionality with the dims() method,
  //       we can determine what type of tensor is returned by an expression
  //       and even create a new object of the same type!
  //       Another technique that can be used is the vistor design pattern,
  //       as described below.
  // -------------------------------------------------------------------


  enum TensorOrExpression : unsigned int {T_TENSOR_OBJ, T_TENSOR_EXP};

  
  enum Tensors : unsigned int {T_SCALAR, T_VECTOR, T_MATRIX, T_TENSOR, T_EXPRESSION_R, T_EXPRESSION_RW};



  template <class D> struct TensorType<T_SCALAR,D> {
    typedef Scalar<D> MyType;
  };

  // TODO: do we need to include a version with N?
  template <class D> struct TensorType<T_VECTOR,D> {
    typedef Vector<D> MyType;
  };
  template <class D> struct TensorType<T_MATRIX,D> {
    typedef Matrix<D> MyType;
  };
  template <class D> struct TensorType<T_TENSOR,D> {
    typedef Tensor<D> MyType;
  };
  

  // -------------------------------------------------------------------
  //
  // TensorAbstract  - abstract class that allows us to put tensors of
  //           any rank and data type into the same contianer.
  //           Use ndims() dim() or getEnum()
  //           to determined rank (ie Scalar Vector, Matrix, Tensor)
  //  rank   Subclass Name
  //    0    Scalar
  //    1    Vector
  //    2    Matrix
  //    3+   Tensor
  // -------------------------------------------------------------------
  
  class TensorAbstract {
    // DO NOT define any storage: we want to
    //        be able to define "light-weight" vectors and matrices
    //        light-weight in that they are small from 1 to 4 elements
  public:
    virtual size_type size(void) const = 0;
    virtual size_type depth(void) const = 0;
    virtual size_type ndims(void) const = 0;
    virtual Dimensions dims(void) const = 0;
    virtual std::vector<Dimensions>& deepdims(void) const = 0;
    virtual std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const = 0;
    virtual bool isExpression(void) const = 0;     // NOTE: with the intrudction of getEnum, this function redundant
    virtual Tensors getEnum(void) const = 0;
    virtual VectorofPtrs getAddresses(void) const = 0;
    virtual std::string classname(void) const = 0;  // NOTE: *not* static
  };
    

  inline bool dimequiv(const TensorAbstract& tensor1, const TensorAbstract& tensor2) {
    return equiv(tensor1.dims(), tensor2.dims());
  }

  inline bool common(const TensorAbstract& tensor1, const TensorAbstract& tensor2) {
    return common(tensor1.getAddresses(), tensor2.getAddresses());
  }

  
  
  // -------------------------------------------------------------------
  //
  // printTensorExpression
  //
  // Basically this is the vistor design pattern.
  // -------------------------------------------------------------------
  


  template <class X, class E, class D, int M, int R>
    std::ostream& printTensorExpression(std::ostream &stream, const TensorR<X,E,D,M,R>& te) {
    switch (R) {
    case 0: {
      Scalar<E> s = te;
      stream << "" +display::getTypeName(s)+" ";
      stream << s;
      return stream;
      break;
    }
    case 1: {
      Vector<E> v = te;
      stream << "" +display::getTypeName(v)+" ";
      stream << v;
      return stream;
      break;
    }
    case 2:{
      Matrix<E> v = te;
      stream << "" +display::getTypeName(v)+" ";
      stream << v;
      return stream;
      break;
    }
    default:{
      Tensor<E,R> v = te;
      stream << "" +display::getTypeName(v)+" ";
      stream << v;
      return stream;
      break;
    } // default
    } // switch
  }


  
  // -------------------------------------------------------------------
  //
  // TensorR -- Abstract class that represents 
  //            either a tensor or a tensor expression that is "read only"
  // -------------------------------------------------------------------

  template <class X, class E, typename D, int M, int R> class
    TensorR : public TensorAbstract {
  public:
    typedef X XType;
    typedef E EType;
    typedef D DType;

    X& derived() {
      return static_cast<X&>(*this);
    }
    const  X& derived() const {
      return static_cast<const X&>(*this);
    }

    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************
    const D dat(const index_type i) const {
      return derived().dat(i);
    }
    
    //**********************************************************************
    //***************** Element ACCESS as an array *************************
    //**********************************************************************
    
    const E operator[](const index_type i) const {
      return derived()[i];
    }


    
    size_type size(void) const {
      return derived().size();
    }

    size_type ndims(void) const {
      return derived().ndims();
    }
    Dimensions dims(void) const {
      return derived().dims();
    }
    std::vector<Dimensions>& deepdims(void) const {
      return derived().deepdims();
    }
    std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
      return derived().deepdims(parentdims);
    }
    bool isExpression(void) const {
      return derived().isExpression();
    }
    virtual Tensors getEnum(void) const {
      return T_EXPRESSION_R;
    }
    size_type depth(void) const {
      return derived().depth();
    }
    size_type elsize(void) const {
      return derived().elsize();
    }
    size_type eldeepsize(void) const {
      return derived().eldeepsize();
    }
    size_type deepsize(void) const {
      return derived().deepsize();
    }

#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return derived().expression();
    }
#else
    std::string expression(void) const {
      return "";
    }
#endif
    VectorofPtrs getAddresses(void) const {
      return derived().getAddresses();
    }


    inline std::string classname() const {
      return derived().classname();
    }
    
    friend std::ostream& operator<<(std::ostream &stream, const TensorR<E,X,D,M,R>& te) {
      const X& td = te.derived();
      if (td.isExpression()) {
	return printTensorExpression(stream,te);
      } else {
	stream << te.derived();
	return stream;
      }
    }
    
  };



  

  // -------------------------------------------------------------------
  //
  // TensorRW -- Abstract class that represents 
  //             either a tensor or a tensor expression that can be
  //             both read and written
  // -------------------------------------------------------------------


  template <class X, class E, typename D, int M, int R> class
    TensorRW : public TensorR<TensorRW<X,E,D,M,R>, E,D,M,R> {
  public:
    typedef X XType;
    typedef E EType;
    typedef D DType;

    X& derived() {
      return static_cast<X&>(*this);
    }
    const X& derived() const {
      return static_cast<const X&>(*this);
    }


    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************
    const D dat(const index_type i) const {
      return derived().dat(i);
    }
    D& dat(const index_type i)  {
      return derived().dat(i);
    }
    
    //**********************************************************************
    //***************** Element ACCESS as an array *************************
    //**********************************************************************
    const E operator[](const index_type i) const {
      return derived()[i];
    }
    E& operator[](const index_type i)  {
      return derived()[i];
    }


    size_type size(void) const {
      return derived().size();
    }

    size_type ndims(void) const {
      return derived().ndims();
    }
    Dimensions dims(void) const {
      return derived().dims();
    }
    std::vector<Dimensions>& deepdims(void) const {
      return derived().deepdims();
    }
    std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
      return derived().deepdims(parentdims);
    }
    bool isExpression(void) const {
      return derived().isExpression();
    }
    virtual Tensors getEnum(void) const {
      return T_EXPRESSION_RW;
    }
    size_type depth(void) const {
      return derived().depth();
    }
    size_type elsize(void) const {
      return derived().elsize();
    }
    size_type eldeepsize(void) const {
      return derived().eldeepsize();
    }
    size_type deepsize(void) const {
      return derived().deepsize();
    }
    

#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      return derived().expression();
    }
#else
    std::string expression(void) const {
      return "";
    }
#endif
    VectorofPtrs getAddresses(void) const {
      return derived().getAddresses();
    }

    
    std::string classname() const {
      return derived().classname();
    }

    friend std::ostream& operator<<(std::ostream &stream, const TensorRW<X,E,D,M,R>& te) {
      const X& td = te.derived();
      if (td.isExpression()) {
	return printTensorExpression(stream,te);
      } else {
	stream << te.derived();
	return stream;
      }
    }


    // Assign to constant value
    X& equals(const E e) { 
      for(size_type i=0; i<size(); i++) 
	(*this)[i]=e; 
      return derived();
    }
    // assign to recon object (issue error)
    X& equals(const TERW_Resize<E>& b) { 
      return derived();
    }
    


    // assign to vector or expression
    template <class Y>
      X& equals(const TensorR<Y,E,D,M,R>& rhs) { 

      const size_type N =size();


      if ( common(*this, rhs) ) {
	// if a vector appears on both the right hand and left hand side,
	// we need to make a copy of the rhs first
	Vector<D> y(N);
	
	for(size_type i=0; i<N; i++) 
	  y[i] = rhs[i]; 
	for(size_type i=0; i<N; i++) 
	  derived()[i] = y[i]; 
      } else {
	for(size_type i=0; i<N; i++) 
	  derived()[i] = rhs[i]; 
      }
      return derived();
    }

    
    
  };


  
};
#endif
