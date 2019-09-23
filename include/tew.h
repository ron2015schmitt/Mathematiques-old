#ifndef MATRICKS__TEW_H
#define MATRICKS__TEW_H




namespace matricks {



  
  /****************************************************************************
   * TEW = Tensor Expresssion Writable, a writable tenspr expressiom
   * abstract class 
   * This is used for expressions that can be placed on the left hand side
   * of an assignment
   ****************************************************************************
   */
  template <class D, class DERIVED>
    class TEW : public  TensorReadable<D,TEW<D,DERIVED> >, public TensorWritable<D,TEW<D,DERIVED> > {
  private:
    inline DERIVED& derived() {
      return static_cast<DERIVED&>(*this);
    }
    inline const  DERIVED& derived() const {
      return static_cast<const DERIVED&>(*this);
    }

  public:

    inline const D operator[](const size_type i) const {  
      return derived()[i];
    }

    inline D& operator[](const size_type i) {  
      return derived()[i];
    }

    inline size_type size(void) const {
      return derived().size();
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

    static inline std::string classname() {
      return derived().classname();
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
      DERIVED& equals(const TensorR<D,B>& rhs) { 
      
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



    
  };

  
};  //namespace matricks

#endif 
