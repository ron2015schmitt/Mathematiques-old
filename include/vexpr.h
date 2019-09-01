#ifndef VEXPR_H
#define VEXPR_H


#include <string>
#include <sstream>
#include <complex>



namespace matricks {


  /****************************************************************************
   * Vexpr -- Vector Expression template abstract class
   ****************************************************************************
   */
  template<class D, class EXP> 
    class Vexpr : public VorE<D,Vexpr<D,EXP> > {
  private:
    typedef  D DataT;
    inline EXP& derived() {
      return static_cast<EXP&>(*this);
    }
    inline const  EXP& derived() const {
      return static_cast<const EXP&>(*this);
    }

  public:

    inline const D operator[](const size_type i) const {
      return derived()[i];
    }

    inline size_type size(void) const {
      return derived().size();
    }

    inline VETypes vetype(void) const {
      return derived().vetype();
    }




    std::string debugtxt(void) const {
      return derived().debugtxt();
    }

    void outputglossary(void) const {
      derived().outputglossary();
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


  };

  


};  //namespace matricks

#endif 
