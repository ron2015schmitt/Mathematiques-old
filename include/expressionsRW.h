#ifndef MATHQ__EXPRESSIONSRW_H
#define MATHQ__EXPRESSIONSRW_H


namespace mathq {


  //---------------------------------------------------------------------------
  // VERW_Join  join two tensors
  //---------------------------------------------------------------------------


  //   template<class D, class A, class B, int M>
  //     class VERW_Join : public  TensorRW<D,VERW_Join<D,A,B,M> > {

  //   private:
  //     A& a_;
  //     B& b_;
  //     VectorofPtrs *vptrs;

  //   public:
  //     typedef typename NumberType<D>::Type MyNumberType;


  //   VERW_Join(A& a, B& b)
  //     : a_(a), b_(b) { 
  //       vptrs = new VectorofPtrs();
  //       vptrs->add(a_.getAddresses());
  //       vptrs->add(b_.getAddresses());
  //     }

  //     ~VERW_Join() {
  //       delete vptrs;
  //     }


  //     const D operator[](const index_type i) const{
  //       if ( i < a_.size() ) {
  // 	return a_[i];
  //       } else {
  // 	return b_[i-a_.size()];
  //       }
  //     }
  //      D& operator[](const index_type i) {
  //       if ( i < a_.size() ) {
  // 	return a_[i];
  //       } else {
  // 	return b_[i-a_.size()];
  //       }
  //     }

  //     VectorofPtrs getAddresses(void) const {
  //       return *vptrs;
  //     }
  //     size_type size(void) const {
  //       return a_.size() +b_.size();
  //     }
  //     size_type ndims(void) const {
  //       return a_.ndims();
  //     }
  //     Dimensions dims(void) const {
  //       return a_.dims();
  //     }
  //     bool isExpression(void) const {
  //       return true;
  //     }
  //   size_type depth(void) const {
  //       return M;
  //     }
  //   size_type elsize(void) const {
  //     if constexpr(M<2) {
  //       return 1;
  //     } else {
  //       return a_.elsize();
  //     }
  //   }
  //   size_type eldeepsize(void) const {
  //     if constexpr(M<2) {
  //       return 1;
  //     } else {
  //       return a_.eldeepsize();
  //     }
  //   }
  //     size_type deepsize(void) const {
  //       if constexpr(M<2) {
  // 	  return this->size();
  // 	} else {
  // 	return (this->size())*(this->eldeepsize());
  //       }
  //     }
  //     std::string classname() const {
  //       return "VERW_Join";
  //     }

  //     VERW_Join<D,A,B>& operator=(TERW_Resize<D>& b) { 
  //       return this->equals(b);
  //     }

  //     template <class C>
  //       VERW_Join<D,A,B>& operator=(const TensorR<D,C>& rhs) { 
  //       printf2("VERW_Join<D,A,B>& operator=(const TensorR<D,C>& rhs)\n");
  //       return this->equals(rhs);
  //     }


  //     template <class D2, class C>
  //       VERW_Join<D,A,B>& operator=(const TensorR<D2,C>& rhs) { 
  //       return this->equals(rhs);
  //     }
    
  //     VERW_Join<D,A,B>& operator=(const MyNumberType d) { 
  //       return this->equals(d);
  //     }
    

    
  // #if MATRICKS_DEBUG>=1
  //     std::string expression(void) const {
  //       return "";
  //       //      return expression_VER_Join(a_.expression(),ii_.expression());
  //     }
  // #endif 


  //   };


  
  

  //---------------------------------------------------------------------------
  // TERW_Subset   Subset Expression
  //---------------------------------------------------------------------------
  template<class D>
  class TERW_Subset : public  TensorRW<TERW_Subset<D>, D,D,1,1> {
  public:
    constexpr static int Rvalue = 1;
    constexpr static int Mvalue = 1;
    typedef Materialize<D,D,Mvalue,Rvalue> XType;
    typedef D EType;
    typedef D DType;
          
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& x_;
    const Vector<index_type>& ii_;
    const bool delete_ii_;
    VectorofPtrs *vptrs;
  public:
    typedef typename NumberType<D>::Type MyNumberType;

    TERW_Subset(Vector<D>& x, const Vector<index_type>& ii)
      : x_(x), ii_(ii), delete_ii_(false) {
      vptrs = new VectorofPtrs();
      vptrs->add(&x_);
      vptrs->add(&ii_);
    }
    TERW_Subset(Vector<D>& x, const std::initializer_list<index_type>& list)
      : x_(x), ii_(*(new Vector<index_type>(list))), delete_ii_(true) {
      vptrs = new VectorofPtrs();
      vptrs->add(&x_);
      vptrs->add(&ii_);
    }
    
    ~TERW_Subset() {
      if (delete_ii_) delete &ii_;
      delete vptrs;
    }


    const D dat(const index_type i) const {
      index_type ind = ii_[i];
      if (ind < 0) {
	ind = x_.size() + ind;
      }
      return x_.dat(ind);
    }
    MyNumberType& dat(const index_type i)  {
      index_type ind = ii_[i];
      if (ind < 0) {
	ind = x_.size() + ind;
      }
      return x_.dat(ind);
    }
  
    const D operator[](const index_type i) const {
      index_type ind = ii_[i];
      if (ind < 0) {
	ind = x_.size() + ind;
      }
      return x_[ind];
    }
    D& operator[](const index_type i)  {
      index_type ind = ii_[i];
      if (ind < 0) {
	ind = x_.size() + ind;
      }
      return x_[ind];
    }

    
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return ii_.size();
    }
    size_type ndims(void) const {
      return x_.ndims();
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
      return Mvalue;
    }
    size_type elsize(void) const {
      if constexpr(Mvalue<=1) {
	  return 1;
	} else {
	return x_.elsize();
      }
    }
    size_type eldeepsize(void) const {
      if constexpr(Mvalue<=1) {
	  return 1;
	} else {
	return x_.eldeepsize();
      }
    }
    size_type deepsize(void) const {
      if constexpr(Mvalue<=1) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
      return "TERW_Subset";
    }


    template <class Y, class D2>
    TERW_Subset<D>& operator=(const TensorR<Y,D2,D2,Mvalue,Rvalue>& rhs) { 
      return this->equals(rhs);
    }
    
    TERW_Subset<D>& operator=(const D d) { 
      return this->equals(d);
    }
    
   
#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //return expression_TERW_Subset(a_.expression(),ii_.expression());
    }
#endif
  };



  //--------------------------------------------------------------------------
  // TERW_Submask   Submask Expression
  //--------------------------------------------------------------------------
  template<class D>
  class TERW_Submask : public  TensorRW<TERW_Submask<D>, D,D,1,1> {
  public:
    constexpr static int Rvalue = 1;
    constexpr static int Mvalue = 1;
    typedef Materialize<D,D,Mvalue,Rvalue> XType;
    typedef D EType;
    typedef D DType;
          
  private:
    // can't be constant since we alow to be on left hand side
    Vector<D>& x_;
    const Vector<index_type>& ii_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;

    TERW_Submask(Vector<D>& x, const Vector<bool>& mask)
      : x_(x), ii_(*(new Vector<index_type>(findtrue(mask)))) { 
        vptrs = new VectorofPtrs();
        vptrs->add(&x_);
        vptrs->add(&ii_);
      }
    ~TERW_Submask() {
      delete &ii_;
      delete vptrs;
    }


    const D dat(const index_type i) const {
      index_type ind = ii_[i];
      return x_.dat(ind);
    }
    MyNumberType& dat(const index_type i)  {
      index_type ind = ii_[i];
      return x_.dat(ind);
    }
  
    const D operator[](const index_type i) const {
      index_type ind = ii_[i];
      return x_[ind];
    }
    D& operator[](const index_type i)  {
      index_type ind = ii_[i];
      return x_[ind];
    }

    
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return ii_.size();
    }
    size_type ndims(void) const {
      return x_.ndims();
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
      return Mvalue;
    }
    size_type elsize(void) const {
      if constexpr(Mvalue<=1) {
	  return 1;
	} else {
	return x_.elsize();
      }
    }
    size_type eldeepsize(void) const {
      if constexpr(Mvalue<=1) {
	  return 1;
	} else {
	return x_.eldeepsize();
      }
    }
    size_type deepsize(void) const {
      if constexpr(Mvalue<=1) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
    std::string classname() const {
      return "TERW_Submask";
    }


    template <class Y, class D2>
    TERW_Submask<D>& operator=(const TensorR<Y,D2,D2,Mvalue,Rvalue>& rhs) { 
      return this->equals(rhs);
    }
    
    TERW_Submask<D>& operator=(const D d) { 
      return this->equals(d);
    }
    
   
#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
      //return expression_TERW_Submask(a_.expression(),ii_.expression());
    }
#endif
  };










  //   //---------------------------------------------------------------------------
  //   // TERW_RealFromComplex  used for accessing real/imag part of complex vector
  //   //---------------------------------------------------------------------------
  //   template <class D, class OP, int M>
  //     class TERW_RealFromComplex : public  TensorRW<D,TERW_RealFromComplex<D,OP,M> > {
  //   private:
  //     Vector<std::complex<D> >& a_;
  //     VectorofPtrs *vptrs;

  //   public:
  //     typedef typename NumberType<D>::Type MyNumberType;


  //   TERW_RealFromComplex(Vector<std::complex<D> >& a)
  //     :   a_(a) { 
  //       vptrs = new VectorofPtrs();
  //       vptrs->add(&a_);
  //     }

  //     ~TERW_RealFromComplex() {
  //       delete vptrs;
  //     }

  //     const D operator[](index_type i) const{
  //       return OP::give(a_[i]);
  //     }
  //     D& operator[](index_type i) {
  //       return OP::give(a_[i]);
  //     }
  //     const MyNumberType dat(const index_type i) const {
  //       return OP::give(a_.dat(i));
  //     }
  //     MyNumberType& dat(const index_type i)  {
  //       return OP::give(a_.dat(i));
  //     }



  //     VectorofPtrs getAddresses(void) const {
  //       return *vptrs;
  //     }
  //     size_type size(void) const {
  //       return a_.size();
  //     }
  //     size_type ndims(void) const {
  //       return a_.ndims();
  //     }
  //     Dimensions dims(void) const {
  //       return a_.dims();
  //     }
  //     bool isExpression(void) const {
  //       return true;
  //     }
  //   size_type depth(void) const {
  //       return M;
  //     }
  //   size_type elsize(void) const {
  //     if constexpr(M<2) {
  //       return 1;
  //     } else {
  //       return a_.elsize();
  //     }
  //   }
  //   size_type eldeepsize(void) const {
  //     if constexpr(M<2) {
  //       return 1;
  //     } else {
  //       return a_.eldeepsize();
  //     }
  //   }
  //     size_type deepsize(void) const {
  //       if constexpr(M<2) {
  // 	  return this->size();
  // 	} else {
  // 	return (this->size())*(this->eldeepsize());
  //       }
  //     }
  //     std::string classname() const {
  //       return "TERW_RealFromComplex";
  //     }


  //     template <class D2, class B>
  //       TERW_RealFromComplex<D,OP,M>& operator=(const TensorR<D2,B>& rhs) { 
  //       return this->equals(rhs);
  //     }
    
  //     TERW_RealFromComplex<D,OP,M>& operator=(const MyNumberType d) { 
  //       return this->equals(d);
  //     }
    

  // #if MATRICKS_DEBUG>=1
  //     std::string expression(void) const {
  //       return a_.expression();
  //       //      return expression_VSliceObj(a_.expression(),start_,end_,step_);
  //     }
  // #endif 

  //   };




};

#endif 
