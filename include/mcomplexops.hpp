


#ifndef MCOMPLEXOPS_H
#define MCOMPLEXOPS_H

#include <complex>


namespace matricks {



  /************************************************************
   *               Templates for Binary Operators
   *
   * D = data type, e.g. double
   * A = either an Matrix or a Mexpr
   * B = either an Matrix or a Mexpr
   ************************************************************
   */

  // complexmatrix + realmatrix

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,ApAddCR<D> > 
  operator+(const MorE<std::complex<D>,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,ApAddCR<D> >(a,b);
  }
  // realmatrix + complexmatrix 

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,ApAddRC<D> > 
  operator+(const MorE<D,A>& a, const MorE<std::complex<D>,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,ApAddRC<D> >(a,b);
  }

  // complexmatrix - realmatrix

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,ApSubtractCR<D> > 
  operator-(const MorE<std::complex<D>,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,ApSubtractCR<D> >(a,b);
  }
  // realmatrix - complexmatrix 

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,ApSubtractRC<D> > 
  operator-(const MorE<D,A>& a, const MorE<std::complex<D>,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,ApSubtractRC<D> >(a,b);
  }
  // complexmatrix * realmatrix

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,ApMultiplyCR<D> > 
  operator*(const MorE<std::complex<D>,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,ApMultiplyCR<D> >(a,b);
  }
  // realmatrix * complexmatrix 

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,ApMultiplyRC<D> > 
  operator*(const MorE<D,A>& a, const MorE<std::complex<D>,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,ApMultiplyRC<D> >(a,b);
  }

  // complexmatrix / realmatrix

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,ApDivideCR<D> > 
  operator/(const MorE<std::complex<D>,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,ApDivideCR<D> >(a,b);
  }
  // realmatrix / complexmatrix 

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,ApDivideRC<D> > 
  operator/(const MorE<D,A>& a, const MorE<std::complex<D>,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,ApDivideRC<D> >(a,b);
  }




  // *** functions that return a complex matrix from 2 real matrixs ***

  // mpolar(r,phi)

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<D,A>,MorE<D,B>,ApPolar<D> > 
  mpolar(const MorE<D,A>& r, const MorE<D,B>& phi)
  {
    return  MBinOp<std::complex<D>,MorE<D,A>,MorE<D,B>,ApPolar<D> >(r,phi);
  }


  // mcomplex(x,y)

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<D,A>,MorE<D,B>,ApComplex<D> > 
  mcomplex(const MorE<D,A>& x, const MorE<D,B>& y)
  {
    return  MBinOp<std::complex<D>,MorE<D,A>,MorE<D,B>,ApComplex<D> >(x,y);
  }




  /************************************************************
   *               Templates for matrix/scalar Operators
   *
   * D = data type, e.g. double (matrix and scalar must be of same data type)
   * A = either an Matrix or a Mexpr
   ************************************************************
   */

  //elementwise powers
  // pow_el(complexmatrix,realscalar)

  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,ApPowCR<D> > 
  pow_el(const MorE<std::complex<D>,A>& a, const D b)
  {
    return  CMatOpScal<D,MorE<std::complex<D>,A>,ApPowCR<D> >(a,b);
  }

  // pow_el(complexmatrix,intscalar)

  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,ApPowCR<D> > 
  pow_el(const MorE<std::complex<D>,A>& a, const int b)
  {
    return  CMatOpScal<D,MorE<std::complex<D>,A>,ApPowCR<D> >(a,static_cast<D>(b));
  }

  // pow_el(realscalar,complexmatrix)

  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,ApPowRC<D> > 
  pow_el(const D a, const MorE<std::complex<D>,B>& b)
  {
    return  CScalOpMat<D,MorE<std::complex<D>,B>,ApPowRC<D> >(a,b);
  }

  // pow_el(intscalar,complexmatrix)

  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,ApPowRC<D> > 
  pow_el(const int a, const MorE<std::complex<D>,B>& b)
  {
    return  CScalOpMat<D,MorE<std::complex<D>,B>,ApPowRC<D> >(static_cast<D>(a),b);
  }


 

  // mcomplex(matrix,realscalar)

  template <class D, class A> 
  inline CMatOpScal<D,MorE<D,A>,ApComplex<D > > 
  mcomplex(const MorE<D,A>& a, const D b)
  {
    return  CMatOpScal<D,MorE<D,A>,ApComplex<D > >(a,b);
  }
  // mcomplex(matrix,intscalar)

  template <class D, class A> 
  inline CMatOpScal<D,MorE<D,A>,ApComplex<D > > 
  mcomplex(const MorE<D,A>& a, const int b)
  {
    return  CMatOpScal<D,MorE<D,A>,ApComplex<D > >(a,static_cast<D>(b));
  }

  // mcomplex(realscalar,matrix)

  template <class D, class B> 
  inline CScalOpMat<D,MorE<D,B>,ApComplex<D > > 
  mcomplex(const D a, const MorE<D,B>& b)
  {
    return  CScalOpMat<D,MorE<D,B>,ApComplex<D > >(a,b);
  }
  // mcomplex(intscalar,matrix)

  template <class D, class B> 
  inline CScalOpMat<D,MorE<D,B>,ApComplex<D > > 
  mcomplex(const int a, const MorE<D,B>& b)
  {
    return  CScalOpMat<D,MorE<D,B>,ApComplex<D > >(static_cast<D>(a),b);
  }




  




  /************************************************************
   *               Templates for matrix/scalar Operators
   *
   * D = data type, e.g. double (matrix and scalar must be of same data type)
   * A = either an Matrix or a Mexpr
   ************************************************************
   */

  // realmatrix + complexscalar
  template <class D, class A> 
  inline MatOpScal<std::complex<D>,MorE<D,A>,ApAddRC<D> > 
  operator+(const MorE<D,A>& a, const std::complex<D> b)
  {
    return  
      MatOpScal<std::complex<D>,MorE<D,A>,ApAddRC<D> >( a,b );
  }

  // complexscalar +  realmatrix 
  template <class D, class B> 
  inline ScalOpMat<std::complex<D>,MorE<D,B>,ApAddCR<D> > 
  operator+(const std::complex<D> a, const MorE<D,B>& b)
  {
    return  
      ScalOpMat<std::complex<D>,MorE<D,B>,ApAddCR<D> >( a, b );
  }
  // complexmatrix + realscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,ApAddCR<D> > 
  operator+(const MorE<std::complex<D>,A>& a, const D b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,ApAddCR<D> >(a,b);  
  }
  // complexmatrix + intscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,ApAddCR<D> > 
  operator+(const MorE<std::complex<D>,A>& a, const int b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,ApAddCR<D> >(a,static_cast<D>(b));  
  }
  // realscalar + complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,ApAddRC<D> > 
  operator+(const D a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,ApAddRC<D> >(a,b);  
  }
  // intscalar + complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,ApAddRC<D> > 
  operator+(const int a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,ApAddRC<D > >(static_cast<D>(a),b);  
  }



  // realmatrix - complexscalar
  template <class D, class A> 
  inline MatOpScal<std::complex<D>,MorE<D,A>,ApSubtractRC<D> > 
  operator-(const MorE<D,A>& a, const std::complex<D> b)
  {
    return  
      MatOpScal<std::complex<D>,MorE<D,A>,ApSubtractRC<D> >( a,b );
  }

  // complexscalar -  realmatrix 
  template <class D, class B> 
  inline ScalOpMat<std::complex<D>,MorE<D,B>,ApSubtractCR<D> > 
  operator-(const std::complex<D> a, const MorE<D,B>& b)
  {
    return  
      ScalOpMat<std::complex<D>,MorE<D,B>,ApSubtractCR<D> >( a, b );
  }
  // complexmatrix - realscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,ApSubtractCR<D> > 
  operator-(const MorE<std::complex<D>,A>& a, const D b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,ApSubtractCR<D> >(a,b);  
  }
  // complexmatrix - intscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,ApSubtractCR<D> > 
  operator-(const MorE<std::complex<D>,A>& a, const int b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,ApSubtractCR<D> >(a,static_cast<D>(b));  
  }
  // realscalar - complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,ApSubtractRC<D> > 
  operator-(const D a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,ApSubtractRC<D> >(a,b);  
  }
  // intscalar - complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,ApSubtractRC<D> > 
  operator-(const int a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,ApSubtractRC<D > >(static_cast<D>(a),b);  
  }


  // realmatrix * complexscalar
  template <class D, class A> 
  inline MatOpScal<std::complex<D>,MorE<D,A>,ApMultiplyRC<D> > 
  operator*(const MorE<D,A>& a, const std::complex<D> b)
  {
    return  
      MatOpScal<std::complex<D>,MorE<D,A>,ApMultiplyRC<D> >( a,b );
  }

  // complexscalar *  realmatrix 
  template <class D, class B> 
  inline ScalOpMat<std::complex<D>,MorE<D,B>,ApMultiplyCR<D> > 
  operator*(const std::complex<D> a, const MorE<D,B>& b)
  {
    return  
      ScalOpMat<std::complex<D>,MorE<D,B>,ApMultiplyCR<D> >( a, b );
  }
  // complexmatrix * realscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,ApMultiplyCR<D> > 
  operator*(const MorE<std::complex<D>,A>& a, const D b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,ApMultiplyCR<D> >(a,b);  
  }
  // complexmatrix * intscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,ApMultiplyCR<D> > 
  operator*(const MorE<std::complex<D>,A>& a, const int b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,ApMultiplyCR<D> >(a,static_cast<D>(b));  
  }
  // realscalar * complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,ApMultiplyRC<D> > 
  operator*(const D a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,ApMultiplyRC<D> >(a,b);  
  }
  // intscalar * complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,ApMultiplyRC<D> > 
  operator*(const int a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,ApMultiplyRC<D > >(static_cast<D>(a),b);  
  }


  // division

  // realmatrix / complexscalar
  template <class D, class A> 
  inline MatOpScal<std::complex<D>, MorE<D,A>,ApDivideRC<D> > 
  operator/(const MorE<D,A>& a, const std::complex<D> b)
  {
    return  
      MatOpScal<std::complex<D> ,MorE<D,A>,ApDivideRC<D> >( a,b );
  }

  // complexscalar /  realmatrix 
  template <class D, class B> 
  inline ScalOpMat<std::complex<D>,MorE<D,B>,ApDivideCR<D> > 
  operator/(const std::complex<D> a, const MorE<D,B>& b)
  {
    return  
      ScalOpMat<std::complex<D>,MorE<D,B>,ApDivideCR<D> >( a, b );
  }
  // complexmatrix / realscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,ApDivideCR<D> > 
  operator/(const MorE<std::complex<D>,A>& a, const D b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,ApDivideCR<D> >(a,b);  
  }
  // complexmatrix / intscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,ApDivideCR<D> > 
  operator/(const MorE<std::complex<D>,A>& a, const int b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,ApDivideCR<D> >(a,static_cast<D>(b));  
  }
  // realscalar / complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,ApDivideRC<D> > 
  operator/(const D a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,ApDivideRC<D> >(a,b);  
  }
  // intscalar / complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,ApDivideRC<D> > 
  operator/(const int a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,ApDivideRC<D > >(static_cast<D>(a),b);  
  }



  









  /****************************************************************
   *               Templates for Unary Operators & Unary Functions
   *
   * D = data type, e.g. double 
   * A = either an Matrix or a Mexpr
   *****************************************************************
   */

  // *** functions that return a complex matrix from a complex matrix ***

  // conj(complex matrix)

  template <class D, class A> 
  inline MFuncOp<std::complex<D>,MorE<std::complex<D>,A>,ApConj<D> > 
  conj(const MorE<std::complex<D>,A>& a)
  {
    return  MFuncOp<std::complex<D>,MorE<std::complex<D>,A>,ApConj<D> >(a);
  }



  // *** functions that return a real matrix from a complex matrix ***

  // abs(complex matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<std::complex<D>,A>,ApCAbs<D> > 
  abs(const MorE<std::complex<D>,A>& a)
  {
    return  MFuncOp<D,MorE<std::complex<D>,A>,ApCAbs<D> >(a);
  }


  // arg(complex matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<std::complex<D>,A>,ApArg<D> > 
  arg(const MorE<std::complex<D>,A>& a)
  {
    return  MFuncOp<D,MorE<std::complex<D>,A>,ApArg<D> >(a);
  }




  // real(complex matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<std::complex<D>,A>,ApReal<D> > 
  real(const MorE<std::complex<D>,A>& a)
  {
    return  MFuncOp<D,MorE<std::complex<D>,A>,ApReal<D> >(a);
  }

  // imag(complex matrix)

  template <class D, class A> 
  inline MFuncOp<D,MorE<std::complex<D>,A>,ApImag<D> > 
  imag(const MorE<std::complex<D>,A>& a)
  {
    return  MFuncOp<D,MorE<std::complex<D>,A>,ApImag<D> >(a);
  }



  /****************************************************************************
   * Binary Functions/Operators that return complex matrices
   ****************************************************************************
   */



  // dotproduct operator (areal|bcomplex)

  template <class D, class A, class B> 
  inline  Matrix<std::complex<D> >  operator|( const MorE<D,A>& a, const  MorE<std::complex<D>,B>& b ) {
    const size_type NR = a.Nrows();
    const size_type NC = b.Ncols();
    const size_type M = a.Ncols();
    const size_type C1 = NR*M;

#ifdef MATRICKS_DEBUG
    std::string name= a.debugtxt() + "|"+  b.debugtxt();
    const size_type Mb = b.Nrows();
    if ( (mexpr_is_size_bad(a.size())) || (mexpr_is_size_bad(b.size())) ){ 
      mbad_expr_in_binary(a,b,"","|");
      Matrix<std::complex<D> > y(0,0,name);
      return y;
    } else if (M!=Mb) {
      mbad_dot_product(a,b);
      Matrix<std::complex<D> > y(0,0,name);
      return y;
    }
    Matrix<std::complex<D> > y(NR,NC,name);
#else
    Matrix<std::complex<D> > y(NR,NC);
#endif

    register index_type i = 0;
    for(register index_type n=0; n < C1; n+=M) 
      for(register index_type c=0; c < NC; c++,i++) {
	index_type j = n;
	index_type k = c;
	const index_type C2 = n+M-1;
	// using a local variable for the accumation saves a lot of CPU Time!!
	std::complex<D> result = a(j) * b(k);
	while (j<C2){
	  result += a((j+=1)) * b((k+=NC));
	} 
	y(i) = result;   
      }
    return  y;
  }

  template <class D, class A, class B> 
  inline  Matrix<std::complex<D> >  operator|( const MorE<std::complex<D>,A>& a, const  MorE<D,B>& b ) {
    const size_type NR = a.Nrows();
    const size_type NC = b.Ncols();
    const size_type M = a.Ncols();
    const size_type C1 = NR*M;

#ifdef MATRICKS_DEBUG
    std::string name= a.debugtxt() + "|"+  b.debugtxt();
    const size_type Mb = b.Nrows();
    if ( (mexpr_is_size_bad(a.size())) || (mexpr_is_size_bad(b.size())) ){ 
      mbad_expr_in_binary(a,b,"","|");
      Matrix<std::complex<D> > y(0,0,name);
      return y;
    } else if (M!=Mb) {
      mbad_dot_product(a,b);
      Matrix<std::complex<D> > y(0,0,name);
      return y;
    }
    Matrix<std::complex<D> > y(NR,NC,name);
#else
    Matrix<std::complex<D> > y(NR,NC);
#endif


    register index_type i = 0;
    for(register index_type n=0; n < C1; n+=M) 
      for(register index_type c=0; c < NC; c++,i++) {
	index_type j = n;
	index_type k = c;
	const index_type C2 = n+M-1;
	// using a local variable for the accumation saves a lot of CPU Time!!
	std::complex<D> result = a(j) * b(k);
	while (j<C2){
	  result += a((j+=1)) * b((k+=NC));
	} 
	y(i) = result;   
      }
    return  y;
  }





  /****************************************************************************
   * Unary Functions/Operators that return matrices
   ****************************************************************************
   */
  // adjoint adj(a)=conjugate(transpose(A))

  template <class D, class A>
  inline Matrix<std::complex<D> >
  adj(const MorE<std::complex<D>,A>& a)
  {
    const size_type NR = a.Nrows();
    const size_type NC = a.Ncols();
    const size_type NN = a.size();
    const size_type C1 = NN-NC;


#ifdef MATRICKS_DEBUG
    std::string name="adj(" +a.debugtxt() +")";
    if ( mexpr_is_size_bad(a.size()) ){ 
      mbad_expr_in_unary(a,"adj");
      Matrix<std::complex<D> > y(0,0,name);
      return y;
    }
    Matrix<std::complex<D> > y(NC,NR,name);
#else
    Matrix<std::complex<D> > y(NC,NR);
#endif

    register index_type i = 0;
    for(register index_type c = 0; c < NC; c++, i++) {
      register index_type k = c;
      y(i) = conj(a(k));
      do {
        y((i+=1)) = conj(a((k+=NC)));
      } while (k<C1);
    }
    return  y;
  }



  /****************************************************************************
   * Unary Functions/Operators that return scalars
   ****************************************************************************
   */







};

#endif 
