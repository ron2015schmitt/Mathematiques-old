#ifndef VOREVORW_H
#define VOREVORW_H



namespace matricks {



  /****************************************************************************
   * Enumeration for different subclasses of VorE class
   ****************************************************************************   
   */
  enum VETypes {VE_Vector, VE_VScalObj,
		VE_VSliceExpr,
		VE_VSliceObj, 
		VE_VSubsetObj, VE_VSubMaskObj,
		VE_VReconObj,
		VE_VJoinExpr, VE_VJoinObj,
		VE_VRepExpr, 
		VE_VBinOp, VE_VecOpScal, VE_ScalOpVec, VE_VFuncOp,
		VE_VSeriesOp, VE_VSeriesOp2,
		VE_VBoolBinOp, VE_BoolVecOpScal, VE_BoolScalOpVec, VE_VBoolFuncOp,
		VE_CVecOpScal, VE_CScalOpVec,VE_VRealFromComplex, VE_p3vector};



  /****************************************************************************
   * VorE -- Abstract class that represents either a vector or a vector expression
   ****************************************************************************   
   */

  template <class D, class VE> class VorE {
  public:
    inline VE& derived() {
      return static_cast<VE&>(*this);
    }
    inline const  VE& derived() const {
      return static_cast<const VE&>(*this);
    }

    typedef  D DataT;

    inline const D operator[](const index_type i) const {
      return derived()[i];
    }

    inline size_type size(void) const {
      return derived().size();
    }

    std::string debugtxt(void) const {
      return derived().debugtxt();
    }

    void outputglossary(void) const {
      derived().outputglossary();
    }

    inline VETypes vetype(void) const {
      return derived().vetype();
    }


    std::vector<const void*> getAddresses(void) const {
      return derived().getAddresses();
    }
    bool checkAddresses(const std::vector<const void*> addrs) const {
      return derived().checkAddresses(addrs);
    }
    void addAddress(const void* addr) {
      derived().addAddress(addr);
    }
    void addAddresses(const std::vector<const void*> addrs) {
      derived().addAddresses(addrs);
    }
    
    
    friend std::ostream& operator<<(std::ostream &stream, const VorE<D,VE>& ve) {
      Vector<D> v = ve.derived();
      stream << v;
      return stream;
    }
  };



  /****************************************************************************
   * Vector or Wrapper
   **************************************************************************** 
   */
  
  template <class D, class VW> class VorW {
  public:
    inline VW& derived() {
      return static_cast<VW&>(*this);
    }
    inline  D& operator[](const index_type i)  {
      return derived()[i];
    }
  };






};
#endif
