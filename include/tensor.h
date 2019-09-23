#ifndef MATRICKS__TENSOR_H
#define MATRICKS__TENSOR_H



namespace matricks {



    // -------------------------------------------------------------------
    //
    // Tensor  - abstract class that allows us to put tensors of
    //           any rank into a contianer.  Use ndims() dim()
    //           to dertermined rank (ie Scalar Vector, Matrix, Tensor)
    //  rank   Subclass Name
    //    0    Scalar
    //    1    Vector
    //    2    Matrix
    //    3+   Tensor
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
    
    Dimensions& reduce() {
      Dimensions* v = new Dimensions();
      for (size_type i = 0; i < this->size(); i++) {
	if ((*this)[i] != 1) {
	  v->push_back((*this)[i]);
	}
      }
      return *v;
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
    




};
#endif
