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
  

  class Dimensions : public std::valarray<size_type> {
  public:
    typedef typename std::valarray<size_type> Parent;
    Dimensions() {
      Parent(0);
    }
    Dimensions(const size_type dim1) {
      Parent(1);
      (*this)[0] = dim1;
    }
    Dimensions(const size_type dim1, const size_type dim2) {
      Parent(2);
      (*this)[0] = dim1;
      (*this)[1] = dim2;
     }
    Dimensions(const size_type dim1, const size_type dim2, const size_type dim3) {
      Parent(3);
      (*this)[0] = dim1;
      (*this)[1] = dim2;
      (*this)[2] = dim3;
     }

    //TODO: constructor for arbitrary rank
  };



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
  
  class Tensor {
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
