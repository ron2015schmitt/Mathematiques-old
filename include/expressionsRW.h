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


  



};

#endif 
