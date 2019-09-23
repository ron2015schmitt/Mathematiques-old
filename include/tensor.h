#ifndef MATRICKS__TENSOR_H
#define MATRICKS__TENSOR_H



namespace matricks {



    /****************************************************************************
   * std::vector related functions
   **************************************************************************** 
   */

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

    inline static std::string classname() {
      return "VectorofPtrs";
    }

    inline friend std::ostream& operator<<(std::ostream &stream, const VectorofPtrs& vptrs) {
      using namespace display;

      // TODO: use streamval function once written and get rid of the mout stuff
      
      std::ostream& os = mout;
      display::Terminal::setmout(stream);

      stream << "{";
      for (size_type ii = 0; ii < vptrs.size(); ii++) {
	if (ii>0)  stream << ", ";
	dispval(vptrs[ii]);
      }
      stream << "}";

      display::Terminal::setmout(os);
      return stream;
    }

    
  };    

  // true if the two vectors have a value in common

  inline bool common(const VectorofPtrs& addrs1, const VectorofPtrs& addrs2) {
    return addrs1.common(addrs2);
  }
   
  //***********************************************************************
  //      Pair class
  //***********************************************************************

  template <class DAT> class Pair {
  public:
    index_type index;
    DAT data;
  Pair(index_type index_, DAT data_) : index(index_), data(data_) {}
  Pair() : index(0), data(DAT(0)) {}
    bool operator<(const Pair<DAT>& pair2) const {
      return ((*this).data < pair2.data);
    }
  };



    // -------------------------------------------------------------------
    //
    // Dimensions - class to hold dimensions of Tensors
    // -------------------------------------------------------------------
  

  class Dimensions : public std::vector<size_type> {
  public:
    typedef typename std::vector<size_type> Parent;
    typedef typename Parent::iterator Iterator;
    Dimensions() {
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
      mdisp3(dim1,dim2,dim3);
      resize(3,0);
      disp3(size());
      (*this)[0] = dim1;
      (*this)[1] = dim2;
      (*this)[2] = dim3;
     }

    //TODO: constructor for arbitrary rank


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


    inline static std::string classname() {
      return "Dimensions";
    }


    inline friend std::ostream& operator<<(std::ostream &stream, const Dimensions& dims) {
      using namespace display;

      // TODO: use streamval function once written and get rid of the mout stuff
      
      std::ostream& os = mout;
      display::Terminal::setmout(stream);

      stream << "{";
      for (size_type ii = 0; ii < dims.size(); ii++) {
	if (ii>0)  stream << ", ";
	dispval(dims[ii]);
      }
      stream << "}";

      display::Terminal::setmout(os);
      return stream;
    }
      

  };


  inline bool equiv(const Dimensions& dims1, const Dimensions& dims2) {
    return dims1.equiv(dims2);
  }


  

    // -------------------------------------------------------------------
    //
    // TensorAbstract  - abstract class that allows us to put tensors of
    //           any rank into a contianer.  Use ndims() dim()
    //           to dertermined rank (ie Scalar Vector, Matrix, Tensor)
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
#if MATRICKS_DEBUG>=1
    virtual VectorofPtrs getAddresses(void) const = 0;
#endif
  };
    


  // -------------------------------------------------------------------
  //
  // TensorR -- Abstract class that represents 
  //            either a tensor or a tensor expression that is "read only"
  // -------------------------------------------------------------------

  template <class D, class DERIVED> class TensorR : public TensorAbstract {
  public:
    inline DERIVED& derived() {
      return static_cast<DERIVED&>(*this);
    }
    inline const  DERIVED& derived() const {
      return static_cast<const DERIVED&>(*this);
    }

    typedef D DataType;

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

    
    friend std::ostream& operator<<(std::ostream &stream, const TensorR<D,DERIVED>& ve) {
      stream << ve.derived();
      return stream;
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
    typedef  D DataType;
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

    
    friend std::ostream& operator<<(std::ostream &stream, const TensorRW<D,DERIVED>& vw) {
      stream << vw.derived();
      return stream;
    }
    
  };


};
#endif
