#ifndef MATHQ__EXPRESSIONSR_H
#define MATHQ__EXPRESSIONSR_H



// "READ ONLY"  expressions


namespace mathq {

  
  

  //---------------------------------------------------------------------------
  // TER_Unary    unary expressions
  //---------------------------------------------------------------------------


  // NOTE: D and E are the output types!
  //       only the function/functor needs the input types
  
  template <class X, class E, class D, int M, int R, class FUNC> 
    class TER_Unary  : public  TensorR<TER_Unary<X,E,D,M,R,FUNC>, E,D,M,R> {
  public:
    typedef X XType;
    typedef E EType;
    typedef D DType;
    constexpr static int Rvalue = R;
    constexpr static int Mvalue = M;
      
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
    std::vector<Dimensions>& deepdims(void) const {
      return x_.deepdims();
    }
    std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
      return x_.deepdims(parentdims);
    }
    bool isExpression(void) const {
      return true;
    }
    size_type depth(void) const {
      return M;
    }
    Dimensions eldims(void) const {
      return x_.eldims();
    }
    size_type elsize(void) const {
      if constexpr(M<=1) {
	  return 1;
	} else {
	return x_.elsize();
      }
    }
    size_type eldeepsize(void) const {
      if constexpr(M<=1) {
	  return 1;
	} else {
	return x_.eldeepsize();
      }
    }
    size_type deepsize(void) const {
      if constexpr(M<=1) {
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






  
  //---------------------------------------------------------------------------
  // TER_Binary    binary expressions
  //---------------------------------------------------------------------------

  
  template <class A, class B, class E1, class E2, class E3, class D1, class D2, class D3, int M1, int M2, int M3, int R1, int R2, int R3, class OP> 
  class TER_Binary  : public  TensorR<TER_Binary<A,B,E1,E2,E3,D1,D2,D3,M1,M2,M3,R1,R2,R3,OP>, E3,D3,M3,R3> {
  public:
    typedef E3 EType;
    typedef D3 DType;
    typedef typename ResultType<A,B,D3>::Type XType;
    constexpr static int Mvalue = M3;
    constexpr static int Rvalue = R3;

    typedef typename std::conditional<M1==0,const A,const A&>::type TypeA;
    typedef typename std::conditional<M2==0,const B,const B&>::type TypeB;

      
  private:
    TypeA a_;
    TypeB b_;
    VectorofPtrs *vptrs;
      
  public:
  


    TER_Binary(const A& a, const B& b) : a_(a), b_(b) {
      vptrs = new VectorofPtrs();
      if constexpr(M1>0) {
        vptrs->add(a_.getAddresses());
      }
      if constexpr(M2>0) {
        vptrs->add(b_.getAddresses());
	}
      disp3(a);
      disp3(b);
    }
    
    ~TER_Binary() {
      delete vptrs;
    }

    //**********************************************************************
    //******************** DEEP ACCESS: x.dat(n) ***************************
    //**********************************************************************

    const D3 dat(const index_type i) const {
      if constexpr((M1==0)&&(M2==0)) {
	return OP::apply(a_, b_);
      } else if constexpr((M1==0)&&(M2>0)) {
	return OP::apply(a_, b_.dat(i));
      } else if constexpr((M1>0)&&(M2==0)) {
	return OP::apply(a_.dat(i), b_);
      } else {
	if constexpr(M1==M2) {
	  return OP::apply(a_.dat(i), b_.dat(i));
	} else if constexpr(M1==M2+1) {
	  if constexpr((M2==1)&&(R2==R1)) {
	    index_type j = i / a_.elsize();
	    return OP::apply(a_.dat(i), b_.dat(j));
	  } else if constexpr(R2==E1::Rvalue) {
	    index_type j = i % b_.deepsize();
	    return OP::apply(a_.dat(i), b_.dat(j));
	  } else {
	    // TODO: error
	  }
	} else if constexpr(M1==M2+1) {
	  if constexpr((M1==1)&&(R1==R2)) {
	    index_type j = i / b_.elsize();
	    return OP::apply(a_.dat(j), b_.dat(i));
	  } else if constexpr(R1==E2::Rvalue) {
	    index_type j = i % a_.deepsize();
	    return OP::apply(a_.dat(j), b_.dat(i));
	  } else {
	    // TODO: error
	  }
	}
      }
    }
      //**********************************************************************
    //************* Array-style Element Access: x[n] ***********************
    //**********************************************************************
    const E3 operator[](const index_type i) const {
      if constexpr((M1==0)&&(M2==0)) {
	return OP::apply(a_, b_);
      } else if constexpr((M1==0)&&(M2>0)) {
	return OP::apply(a_, b_[i]);
      } else if constexpr((M1>0)&&(M2==0)) {
	return OP::apply(a_[i], b_);
      } else {
	if constexpr(M1==M2) {
	  return OP::apply(a_[i], b_[i]);
	} else if constexpr(M1==M2+1) {
	  if constexpr((M2==1)&&(R2==R1)) {
	    return OP::apply(a_[i], b_[i]);
	  } else if constexpr(R2==E1::Rvalue) {
	      return OP::apply(a_[i], b_);
	  } else {
	    // TODO: error
	  }
	} else if constexpr(M1==M2+1) {
	  if constexpr((M1==1)&&(R1==R2)) {
	    return OP::apply(a_[i], b_[i]);
	  } else if constexpr(R1==E2::Rvalue) {
	    return OP::apply(a_, b_[i]);
	  } else {
	    // TODO: error
	  }
	}
      }
    }

   

       
    
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      if constexpr(M1>=M2) {
        return a_.size();
      } else {
        return b_.size();
      }
    }
    size_type ndims(void) const {
      return dims().size();
    }
    Dimensions dims(void) const {
      if constexpr(M1>=M2) {
        return a_.dims();
      } else {
        return b_.dims();
      }
    }
    std::vector<Dimensions>& deepdims(void) const {
      if constexpr(M1>=M2) {
        return a_.deepdims();
      } else {
        return b_.deepdims();
      }
    }
    std::vector<Dimensions>& deepdims(std::vector<Dimensions>& parentdims) const {
      if constexpr(M1>=M2) {
        return a_.deepdims(parentdims);
      } else {
        return b_.deepdims(parentdims);
      }
    }
    bool isExpression(void) const {
      return true;
    }
    size_type depth(void) const {
      if constexpr(M1>=M2) {
        return M1;
      } else {
        return M2;
      }
    }
    size_type elsize(void) const {
      if constexpr(M1>=M2) {
        return a_.elsize();
      } else {
        return b_.elsize();
      }
    }
    size_type eldeepsize(void) const {
      if constexpr(M1>=M2) {
        return a_.eldeepsize();
      } else {
        return b_.eldeepsize();
      }
    }
    size_type deepsize(void) const {
      if constexpr(M1>=M2) {
        return a_.deepsize();
      } else {
        return b_.deepsize();
      }
    }

    std::string classname() const {
      return "TER_Binary";
    }


#if MATHQ_DEBUG>=1
    std::string expression(void) const {
      std::string sx = a_.expression();
      std::string sy = a_.expression();
      return OP::expression(sx,sy);
    }
#endif

  };






  
};  //namespace mathq

#endif 
