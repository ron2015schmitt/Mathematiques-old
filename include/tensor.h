#ifndef MATRICKS__TENSOR_H
#define MATRICKS__TENSOR_H



namespace matricks {



  class Dimensions : public std::vector<size_type> {
  };

  class Tensor {
  public:
    virtual size_type size(void) const = 0;
    virtual size_type ndims(void) const = 0;
    virtual Dimensions dims(void) const = 0;
    virtual std::string classname(void) const = 0;
    virtual std::vector<const void*> getAddresses(void) = 0;
  };
    




};
#endif
