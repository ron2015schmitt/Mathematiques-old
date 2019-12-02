#ifndef MATRICKS__EXPRESSIONS_H
#define MATRICKS__EXPRESSIONS_H



namespace matricks {



  

  //---------------------------------------------------------------------------
  // TER_Unary    unary expressions
  //---------------------------------------------------------------------------
    
  template <class E, class A, class D, int M, int R, class FUNC> 
    class TER_Unary  : public  TensorR<E, TER_Unary<E,A,D,M,R,FUNC>, D,M,R> {
  public:
    typedef TensorR<E,A,D,M,R> TIN;
      
  private:
    const TIN& a_;
    VectorofPtrs *vptrs;
      
  public:
      


  TER_Unary(const TIN& a) : a_(a) {
      vptrs = new VectorofPtrs();
      vptrs->add(a_.getAddresses());
      disp3(a);
    }
    
    ~TER_Unary() {
      delete vptrs;
    }

    const D dat(const index_type i) const {
      return FUNC::apply(a_.dat(i));
    }
  
    const E operator[](const index_type i) const {
      return FUNC::apply(a_[i]);
    }

    
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return a_.size();
    }
    size_type ndims(void) const {
      return R;
    }
    Dimensions dims(void) const {
      return a_.dims();
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
	return a_.elsize();
      }
    }
    size_type eldeepsize(void) const {
      if constexpr(M<2) {
	  return 1;
	} else {
	return a_.eldeepsize();
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


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      std::string sa = a_.expression();
      return FUNC::expression(sa);
    }
#endif


  };



};  //namespace matricks

#endif 
