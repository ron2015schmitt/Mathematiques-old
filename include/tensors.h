#ifndef MATRICKS__TENSOR_H
#define MATRICKS__TENSOR_H



namespace matricks {

  //-------------------------------------------------------------------
  //                  Classes etc defined in this file
  //-------------------------------------------------------------------
  
  class VectorofPtrs;
  template <class DAT> class Pair;
  class Dimensions;
#if  CPP11 == 1
  enum Tensors : unsigned int;
#endif
  template <Tensors, class D> struct TensorType;
  class TensorAbstract;
  class TensorObject;
  template <class D, class DERIVED> class TensorR;
  template <class D, class DERIVED> class TensorRW;

  //-------------------------------------------------------------------
  //                  Classes defined in later files
  //-------------------------------------------------------------------
  template <class D> class Scalar;
  template <class D> class Vector;
  template <class D> class Matrix;


  // ****************************************************************************
  // * std::vector related functions
  // **************************************************************************** 
  

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
	sendval(stream, vptrs[ii]);
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
  // Dimensions - class to hold dimensions of Tensors
  // -------------------------------------------------------------------

  //TODO: should check for dimension 0, which should not be passed

  class Dimensions : public std::vector<size_type> {
  public:
    typedef typename std::vector<size_type> Parent;
    typedef typename Parent::iterator Iterator;
    Dimensions() {
      resize(0,0);
    }
    Dimensions(const size_type dim1) {
      resize(1,0);
      (*this)[0] = dim1;
    }
    Dimensions(const size_type dim1, const size_type dim2) {
      resize(2,0);
      (*this)[0] = dim1;
      (*this)[1] = dim2;
    }
    Dimensions(const size_type dim1, const size_type dim2, const size_type dim3) {
      //      mdisp3(dim1,dim2,dim3);
      resize(3,0);
      //      disp3(size());
      (*this)[0] = dim1;
      (*this)[1] = dim2;
      (*this)[2] = dim3;
    }
    Dimensions(const size_type dim1, const size_type dim2, const size_type dim3, const size_type dim4) {
      //      mdisp3(dim1,dim2,dim3);
      resize(4,0);
      //      disp3(size());
      (*this)[0] = dim1;
      (*this)[1] = dim2;
      (*this)[2] = dim3;
      (*this)[3] = dim4;
    }

    // use C++11 init list for arbitrary rank
#if CPP11 == 1
    Dimensions(const std::initializer_list<size_type> list) 
    {
      const size_type N =  list.size();
      resize(N,0);
      index_type i = 0;
      typename std::initializer_list<size_type>::iterator it; 
      for (it = list.begin(); it != list.end(); ++it)  { 
	(*this)[i++] = *it;
      }
    }
#endif // C++11



    // return this object with size 1 dimensions removed
    
    Dimensions& reduce() const {
      Dimensions* v = new Dimensions();
      for (size_type i = 0; i < this->size(); i++) {
	if ((*this)[i] != 1) {
	  v->push_back((*this)[i]);
	}
      }
      return *v;
    }
    
    bool equiv(const Dimensions& dims) const {
      return (this->reduce() == dims.reduce());
    }


    inline std::string classname() const {
      return "Dimensions";
    }


    inline friend std::ostream& operator<<(std::ostream &stream, const Dimensions& dims) {
      using namespace display;

      stream << "{";
      for (size_type ii = 0; ii < dims.size(); ii++) {
	if (ii>0)  stream << ", ";
	sendval(stream, dims[ii]);
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

  
  enum Tensors : unsigned int {T_SCALAR, T_VECTOR, T_MATRIX, T_TENSOR, T_EXPRESSION_R, T_EXPRESSION_RW};
  template <Tensors, class D> struct TensorType;

  template <class D> struct TensorType<T_SCALAR,D> {
    typedef Scalar<D> MyType;
  };
  template <class D> struct TensorType<T_VECTOR,D> {
    typedef Vector<D> MyType;
  };
  template <class D> struct TensorType<T_MATRIX,D> {
    typedef Matrix<D> MyType;
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
    virtual size_type ndims(void) const = 0;
    virtual Dimensions dims(void) const = 0;
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
  // TensorObject
  //
  // signifies it's an object, not an expression
  // As of V2.19  I have found no use for this, but I'll leave it in.
  // It may bear fruit at some point.
  // -------------------------------------------------------------------

  class TensorObject {
  public:
  };
  
  
  // -------------------------------------------------------------------
  //
  // printTensorExpression
  //
  // Basically this is the vistor design pattern.
  // -------------------------------------------------------------------
  


  template <class D, class A>
    std::ostream& printTensorExpression(std::ostream &stream, const TensorR<D,A>& te) {
    const size_type ndims = te.ndims();
    switch (ndims) {
    case 0: {
      Scalar<D> s = te;
      stream << s;
      return stream;
      break;
    }
    case 1: {
      Vector<D> v = te;
      stream << v;
      return stream;
      break;
    }
    case 2:{
      // TODO: add code for Matrix
      return stream;
      break;
    }
    default:{
      // TODO: add code for Tensor
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

  
  template <class D, class DERIVED> class TensorR : public TensorAbstract {
  public:
    typedef D DataType;

    inline DERIVED& derived() {
      return static_cast<DERIVED&>(*this);
    }
    inline const  DERIVED& derived() const {
      return static_cast<const DERIVED&>(*this);
    }

    inline const D operator[](const index_type i) const {
      return derived()[i];
    }

    inline size_type size(void) const {
      return derived().size();
    }

    size_type ndims(void) const {
      return derived().ndims();
    }
    Dimensions dims(void) const {
      return derived().dims();
    }
    bool isExpression(void) const {
      return derived().isExpression();
    }
    virtual Tensors getEnum(void) const {
      return T_EXPRESSION_R;
    }

#if MATRICKS_DEBUG>=1
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
    
    friend std::ostream& operator<<(std::ostream &stream, const TensorR<D,DERIVED>& te) {
      const DERIVED& td = te.derived();
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


  template <class D, class DERIVED> class TensorRW : public TensorR<D,TensorRW<D,DERIVED> > {
  public:
    typedef D DataType;

    inline DERIVED& derived() {
      return static_cast<DERIVED&>(*this);
    }
    inline const  DERIVED& derived() const {
      return static_cast<const DERIVED&>(*this);
    }

    inline const D operator[](const index_type i) const {
      return derived()[i];
    }
    inline  D& operator[](const index_type i)  {
      return derived()[i];
    }

    inline size_type size(void) const {
      return derived().size();
    }

    size_type ndims(void) const {
      return derived().ndims();
    }
    Dimensions dims(void) const {
      return derived().dims();
    }
    bool isExpression(void) const {
      return derived().isExpression();
    }
    virtual Tensors getEnum(void) const {
      return T_EXPRESSION_RW;
    }
    

#if MATRICKS_DEBUG>=1
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

    friend std::ostream& operator<<(std::ostream &stream, const TensorRW<D,DERIVED>& te) {
      const DERIVED& td = te.derived();
      if (td.isExpression()) {
	return printTensorExpression(stream,te);
      } else {
	stream << te.derived();
	return stream;
      }
    }


    // Assign to constant value
    DERIVED& equals(const D d) { 
      for(size_type i=0; i<size(); i++) 
	(*this)[i]=d; 
      return derived();
    }
    // assign to recon object (issue error)
    DERIVED& equals(const TERW_Resize<D>& b) { 
      return derived();
    }
    


    // assign to vector or expression
    template <class B>
      DERIVED& equals(const TensorR<D,B>& rhs) { 

      const size_type N =size();


      if ( common(*this, rhs) ) {
	// if a vector appears on both the right hand and left hand side,
	// we need to make a copy of the rhs first
	Vector<D> y(N);
	
	for(register size_type i=0; i<N; i++) 
	  y[i] = rhs[i]; 
	for(register size_type i=0; i<N; i++) 
	  derived()[i] = y[i]; 
      } else {
	for(register size_type i=0; i<N; i++) 
	  derived()[i] = rhs[i]; 
      }
      return derived();
    }

    
    
  };


  
};
#endif
