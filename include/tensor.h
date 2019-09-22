#ifndef MATRICKS__TENSOR_H
#define MATRICKS__TENSOR_H



namespace matricks {



  class Dimensions : public std::vector<size_type> {
  };

  class Tensor {
    // DO NOT define any storage: we want to
    //        be able to define "light-weight" vectors and matrices
    //        light-weight in that they are small from 1 to 4 elements
  public:
    virtual size_type size(void) const = 0;
    virtual size_type ndims(void) const = 0;
    virtual Dimensions dims(void) const = 0;
    virtual std::string classname(void) const = 0;
#if MATRICKS_DEBUG>=1
    virtual VectorofPtrs&  getAddresses(void) const = 0;
#endif
  };
    




};
#endif
