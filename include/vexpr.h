#ifndef VEXPR_H
#define VEXPR_H


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
  protected:
    VectorofPtrs vaddresses_;
    
  public:

    inline const D operator[](const size_type i) const {
      return derived()[i];
    }

    inline size_type size(void) const {
      return derived().size();
    }


    VectorofPtrs getAddresses(void) const {
      return vaddresses_;
    }
    void initAddresses() {
      vaddresses_ = new VectorofPtrs();
    }
    void addAddress(const void* addr) {
      vaddresses_.add(addr);
    }
    void addAddresses(const VectorofPtrs addrs) {
      vaddresses_.add(addrs);
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return derived().expression();
    }
#endif

    std::string classname() const {
      return derived().expression();
    }


    friend std::ostream& operator<<(std::ostream &stream, const Vexpr<D,EXP>& ve) {
      Vector<D> v(ve);
      stream << v;
      return stream;
    }

  };

  


};  //namespace matricks

#endif 
