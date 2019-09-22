#ifndef VOREVORW_H
#define VOREVORW_H



namespace matricks {





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

#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return derived().expression();
    }
#else
    std::string expression(void) const {
      return "";
    }
#endif
    VectorofPtrs getAddresses(void) const {
      return derived().getAddresses();
    }

    
    friend std::ostream& operator<<(std::ostream &stream, const VorE<D,VE>& ve) {
      stream << ve.derived();
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
