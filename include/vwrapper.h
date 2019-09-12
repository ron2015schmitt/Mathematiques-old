#ifndef VWRAPPER_H
#define VWRAPPER_H




namespace matricks {



  
  /****************************************************************************
   * VWrapper Expression Template 
   *
   * abstract class 
   * This is used for expressions that can be placed on the left hand side
   * of an assignment
   ****************************************************************************
   */
  template <class D, class DERIVED>
    class VWrapper : public  Vexpr<D,VWrapper<D,DERIVED> >, public VorW<D,VWrapper<D,DERIVED> > {
  private:
    inline DERIVED& derived() {
      return static_cast<DERIVED&>(*this);
    }
    inline const  DERIVED& derived() const {
      return static_cast<const DERIVED&>(*this);
    }

  public:

    inline const D operator[](const size_type i) const {  
      const size_type index = derived().index(i);
      return derived().data(index);
    }

    inline D& operator[](const size_type i) {  
      const size_type index = derived().index(i);
      return derived().data(index);
    }

    inline size_type index(void) const {
      return derived().index();
    }

    inline size_type size(void) const {
      return derived().size();
    }

    inline VETypes vetype(void) const {
      return derived().vetype();
    }


    // Assign to constant value
    DERIVED& equals(const D d) { 
      for(size_type i=0; i<size(); i++) 
	(*this)[i]=d; 
      return derived();
    }
    // assign to recon object (issue error)
    DERIVED& equals(const VReconObj<D>& b) { 
      return derived();
    }
    


    // assign to vector or expression
    template <class B>
      DERIVED& equals(const VorE<D,B>& rhs) { 

      const size_type N =size();


      if ( rhs.checkAddresses(getAddresses()) ) {    
	Vector<D> y(N);

	for(register size_type i=0; i<N; i++) 
	  y[i] = rhs[i]; 
	for(register size_type i=0; i<N; i++) 
	  derived()[i] = y[i]; 
      } else {
	for(register size_type i=0; i<N; i++) 
	  derived()[i] = rhs[i]; 
      }
      return derived();
    }




    // assignment to matrix or submatrix (must be 1xN or Nx1)
    template <class B>
      DERIVED& equals(const MorE<D,B>& rhs) {

      const size_type N =size();


      if ( rhs.checkAddresses(getAddresses()) ) {    
	Vector<D> y(N);

	y=rhs;
	for(register size_type i=0; i<N; i++) 
	  derived()[i] = y[i]; 
      } else {
	for(register size_type i=0; i<N; i++) 
	  derived()[i] = rhs(i); 
      }
      return derived();
    }





    std::string debugtxt(void) const {
      return derived().debugtxt();
    }

    void outputglossary(void) const {
      return derived().outputglossary();
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
