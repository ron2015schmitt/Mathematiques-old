
#ifndef VBOOLEXPR_H
#define VBOOLEXPR_H

#include <string>
#include <sstream>


namespace matricks {







  /****************************************************************************
   * VBoolBinOp Operator Expression Template 
   *
   * vector/vector binary operator expressions
   ****************************************************************************
   */
  template<class D, class A, class B, class OP>
  class VBoolBinOp : public  Vexpr<bool,VBoolBinOp<D,A,B,OP> >, VectorofPtrs {

  private:
    const A& a_;
    const B& b_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

    VBoolBinOp(const A& a, const B& b)
      : a_(a), b_(b)
    { 
      addAddress(&a_);
      addAddress(&b_);
    }

    inline bool operator[](const index_type i) const {  
      return OP::apply(a_[i], b_[i]); 
    }

    inline size_type size(void) const {
      if ( a_.size() != b_.size() ) {
	return badsize;
      } else {
	return a_.size();
      }
    }

    inline VETypes vetype(void) const {
      return VE_VBoolBinOp;
    }

    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      if (a_.vetype() != VE_Vector) 
	sa = "(" + sa + ")";
      std::string sb = b_.debugtxt();
      if (b_.vetype() != VE_Vector) 
	sb = "(" + sb + ")";
      return OP::debugtxt(sa,sb);
    }


    void outputglossary(void) const {
      a_.outputglossary();
      b_.outputglossary();
    }

    bool mustcopy(const void *vaddr) const {
      return (a_.mustcopy(vaddr)) && (b_.mustcopy(vaddr));
    }



  };







  /****************************************************************************
   * BoolVecOpScal Operator Template 
   *
   * vector/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
  class BoolVecOpScal : public Vexpr<bool,BoolVecOpScal<D,A,OP> >, VectorofPtrs {

  private:
    const A& a_;
    D val_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;


    BoolVecOpScal(const A& a, const D b)
      : a_(a), val_(b)
    {
      addAddress(&a_);
    }

    inline bool operator[](const index_type i) const { 
      return OP::apply(a_[i], val_); 
    }

    inline size_type size(void) const {
      return a_.size();
    }

    inline VETypes vetype(void) const {
      return VE_BoolVecOpScal;
    }

    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      if (a_.vetype() != VE_Vector) 
	sa = "(" + sa + ")";
      std::ostringstream stream;
      stream << val_;
      std::string sb = stream.str();
      return OP::debugtxt(sa,sb);
    }


    void outputglossary(void) const {
      a_.outputglossary();
    }

    bool mustcopy(const void *vaddr) const {
      return a_.mustcopy(vaddr);
    }



  };





  /****************************************************************************
   * BoolScalOpVec Operator Template 
   *
   * scalar/vector binary operators
   ****************************************************************************
   */


  template<class D, class B, class OP>
  class BoolScalOpVec : public Vexpr<bool,BoolScalOpVec<D,B,OP> >, VectorofPtrs {

  private:
    D val_;
    const B& b_;

  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

    BoolScalOpVec(const D a, const B& b)
      :  val_(a), b_(b)
    {
      addAddress(&b_);
    }

    inline bool operator[](const index_type i) const { 
      return OP::apply(val_,b_[i]); 
    }

    inline size_type size(void) const {
      return b_.size();
    }

    inline VETypes vetype(void) const {
      return VE_BoolScalOpVec;
    }

    std::string debugtxt(void) const {
      std::ostringstream stream;
      stream << val_;
      std::string sa = stream.str();
      std::string sb = b_.debugtxt();
      if (b_.vetype() != VE_Vector) 
	sb = "(" + sb + ")";
      return OP::debugtxt(sa,sb);
    }

    void outputglossary(void) const {
      b_.outputglossary();
    }

    bool mustcopy(const void *vaddr) const {
      return b_.mustcopy(vaddr);
    }


  };




  /****************************************************************************
   * VBoolFuncOp Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
  class VBoolFuncOp  : public  Vexpr<bool,VBoolFuncOp<D,A,FUNC> >, VectorofPtrs{
  
  private:
    const A& a_;
  
  public:
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

    VBoolFuncOp(const A& a) : a_(a) {
      addAddress(&a_);
    }


    inline bool operator[](const index_type i) const
    { return FUNC::apply(a_[i]); }

    inline size_type size(void) const {
      return a_.size();
    }

    inline VETypes vetype(void) const {
      return VE_VBoolFuncOp;
    }

    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      return FUNC::debugtxt(sa);
    }

    void outputglossary(void) const {
      a_.outputglossary();
    }

    bool mustcopy(const void *vaddr) const {
      return a_.mustcopy(vaddr);
    }


  };










};

#endif
