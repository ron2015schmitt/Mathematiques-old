#ifndef VCOMPLEXEXPR_H
#define VCOMPLEXEXPR_H

#include <string>
#include <sstream>
#include <complex>

namespace matricks {


  /****************************************************************************
   * CVecOpScal Operator Template 
   *
   * complex vector = binfunc(ComplexOrRealVector,RealScalar) binary operators 
   ****************************************************************************
   */
  template<class D, class A, class OP>
  class CVecOpScal : public Vexpr<std::complex<D>, CVecOpScal<D,A,OP> > {

  private:
    const A& a_;
    const D val_;

  public:
    CVecOpScal(const A& a, const D b)
      : a_(a), val_(b)
    { }

    inline const std::complex<D> operator[](const index_type i) const { 
      return OP::apply(a_[i], val_); 
    }

    inline size_type size(void) const {
      return a_.size();
    }

    inline VETypes vetype(void) const {
      return VE_CVecOpScal;
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
   * CScalOpVec Operator Template 
   *
   * complex vector = binfunc(RealScalar,ComplexOrRealVector) binary operators 
   ****************************************************************************
   */
  template<class D, class B, class OP>
  class CScalOpVec : public Vexpr<std::complex<D>,CScalOpVec<D,B,OP> > {
  private:
    const D val_;
    const B& b_;

  public:
    CScalOpVec(const D a, const B& b)
      : val_(a), b_(b)
    { }

    inline const std::complex<D> operator[](const index_type i) const { 
      return OP::apply(val_,b_[i]); 
    }

    inline size_type size(void) const {
      return b_.size();
    }

    inline VETypes vetype(void) const {
      return VE_CScalOpVec;
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
   * VRealFromComplex Expression Template 
   *
   * used for accessing real/imag part of complex vector
   ****************************************************************************
   */
  template <class D, class OP>
  class VRealFromComplex : public  VWrapperObj<D,VRealFromComplex<D,OP> > {
  private:
    Vector<std::complex<D> >& a_;

  public:
    VRealFromComplex(Vector<std::complex<D> >& a)
      :   a_(a)
    { 
    }

    inline const D data(index_type i) const{
      return OP::give(a_[i]);
    }
    inline D& data(index_type i) {
      return OP::give(a_[i]);
    }


    inline index_type index(index_type i) const{
      return i;
    }


    inline size_type size(void) const {
      return a_.size();
    }

    inline size_type asize(void) const {
      return a_.size();
    }

    inline VETypes vetype(void) const {
      return VE_VRealFromComplex;
    }

    template <class B>
    VRealFromComplex<D,OP>& operator=(const B& b) { 
      return equals(b);
    }

    template <class OP2>
    VRealFromComplex<D,OP>& operator=(const VRealFromComplex<D,OP2>& b) { 
      return equals(b);
    }

    std::string debugtxt(void) const {
      return a_.debugtxt();
      //      return debugtxt_VSliceObj(a_.debugtxt(),start_,end_,step_);
    }

    void outputglossary(void) const {
      return a_.outputglossary();
      //      outputglossary_VSliceObj(a_.objectID(),debugtxt(),size());
    }

    bool mustcopy(const void *vaddr) const {
       return addrmatch(vaddr);
    }


    bool addrmatch(const void *vaddr) const {
      return vaddr==static_cast<const void*>(&a_);
    }

    const void *addr(void) const {
      return &a_;
    }


  };






};

#endif 
