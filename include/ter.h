#ifndef MATRICKS__TER_H
#define MATRICKS__TER_H


namespace matricks {


  /****************************************************************************
   * TER -- Read-only Tensor Expression template abstract class
   ****************************************************************************
   */
  template<class D, class EXP> 
    class TER : public VorE<D, TER<D,EXP> > {
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



    VectorofPtrs getAddresses(void) const {
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


    std::string classname() const {
      return derived().classname();
    }
    static inline std::string expression() {
      return derived().expression();
    }
    static inline std::string expression(const std::string& sa) {
      return derived().expression(sa);
    }
    static inline std::string expression(const std::string& sa, const std::string& sb) {
      return derived().expression(sa,sb);
    }

    friend std::ostream& operator<<(std::ostream &stream, const Vexpr<D,EXP>& ve) {
      Vector<D> v(ve);
      stream << v;
      return stream;
    }

  };

  


};  //namespace matricks

#endif 
