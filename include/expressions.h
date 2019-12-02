#ifndef MATHQ__EXPRESSIONS_H
#define MATHQ__EXPRESSIONS_H



namespace mathq {



  

  //---------------------------------------------------------------------------
  // TER_Unary    unary expressions
  //---------------------------------------------------------------------------
    
  template <class X, class E, class D, int M, int R, class FUNC, class A, class B> 
    class TER_Unary  : public  TensorR<TER_Unary<X,E,D,M,R,FUNC>, E,D,M,R> {
  public:
    typedef X XType;
    typedef E EType;
    typedef D DType;
      
  private:
    const X& x_;
    VectorofPtrs *vptrs;
      
  public:
      


  TER_Unary(const X& x) : x_(x) {
      vptrs = new VectorofPtrs();
      vptrs->add(x_.getAddresses());
      disp3(x);
    }
    
    ~TER_Unary() {
      delete vptrs;
    }

    const D dat(const index_type i) const {
      return FUNC::apply(x_.dat(i));
    }
  
    const E operator[](const index_type i) const {
      return FUNC::apply(x_[i]);
    }

    
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return x_.size();
    }
    size_type ndims(void) const {
      return R;
    }
    Dimensions dims(void) const {
      return x_.dims();
    }
    Dimensions tdims(void) const {
      return this->dims();
    }
    bool isExpression(void) const {
      return true;
    }
    size_type depth(void) const {
      return M;
    }
    size_type elsize(void) const {
      if constexpr(M<2) {
	  return 1;
	} else {
	return x_.elsize();
      }
    }
    size_type eldeepsize(void) const {
      if constexpr(M<2) {
	  return 1;
	} else {
	return x_.eldeepsize();
      }
    }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }

    std::string classname() const {
      return "TER_Unary";
    }


#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      std::string sx = x_.expression();
      return FUNC::expression(sx);
    }
#endif


  };



};  //namespace mathq

#endif 
