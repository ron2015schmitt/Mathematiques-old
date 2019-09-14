#ifndef MCOMPLEXOPS_H
#define MCOMPLEXOPS_H



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
  inline MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,FunAddCR<D> > 
  operator+(const MorE<std::complex<D>,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,FunAddCR<D> >(a,b);
  }
  // realmatrix + complexmatrix 

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,FunAddRC<D> > 
  operator+(const MorE<D,A>& a, const MorE<std::complex<D>,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,FunAddRC<D> >(a,b);
  }

  // complexmatrix - realmatrix

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,FunSubtractCR<D> > 
  operator-(const MorE<std::complex<D>,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,FunSubtractCR<D> >(a,b);
  }
  // realmatrix - complexmatrix 

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,FunSubtractRC<D> > 
  operator-(const MorE<D,A>& a, const MorE<std::complex<D>,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,FunSubtractRC<D> >(a,b);
  }
  // complexmatrix * realmatrix

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,FunMultiplyCR<D> > 
  operator*(const MorE<std::complex<D>,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,FunMultiplyCR<D> >(a,b);
  }
  // realmatrix * complexmatrix 

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,FunMultiplyRC<D> > 
  operator*(const MorE<D,A>& a, const MorE<std::complex<D>,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,FunMultiplyRC<D> >(a,b);
  }

  // complexmatrix / realmatrix

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,FunDivideCR<D> > 
  operator/(const MorE<std::complex<D>,A>& a, const MorE<D,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<std::complex<D>,A>,MorE<D,B>,FunDivideCR<D> >(a,b);
  }
  // realmatrix / complexmatrix 

  template <class D, class A, class B> 
  inline MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,FunDivideRC<D> > 
  operator/(const MorE<D,A>& a, const MorE<std::complex<D>,B>& b)
  {
    return  MBinOp<std::complex<D>,MorE<D,A>,MorE<std::complex<D>,B>,FunDivideRC<D> >(a,b);
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
  inline MatOpScal<std::complex<D>,MorE<D,A>,FunAddRC<D> > 
  operator+(const MorE<D,A>& a, const std::complex<D> b)
  {
    return  
      MatOpScal<std::complex<D>,MorE<D,A>,FunAddRC<D> >( a,b );
  }

  // complexscalar +  realmatrix 
  template <class D, class B> 
  inline ScalOpMat<std::complex<D>,MorE<D,B>,FunAddCR<D> > 
  operator+(const std::complex<D> a, const MorE<D,B>& b)
  {
    return  
      ScalOpMat<std::complex<D>,MorE<D,B>,FunAddCR<D> >( a, b );
  }
  // complexmatrix + realscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,FunAddCR<D> > 
  operator+(const MorE<std::complex<D>,A>& a, const D b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,FunAddCR<D> >(a,b);  
  }
  // complexmatrix + intscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,FunAddCR<D> > 
  operator+(const MorE<std::complex<D>,A>& a, const int b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,FunAddCR<D> >(a,static_cast<D>(b));  
  }
  // realscalar + complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,FunAddRC<D> > 
  operator+(const D a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,FunAddRC<D> >(a,b);  
  }
  // intscalar + complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,FunAddRC<D> > 
  operator+(const int a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,FunAddRC<D > >(static_cast<D>(a),b);  
  }



  // realmatrix - complexscalar
  template <class D, class A> 
  inline MatOpScal<std::complex<D>,MorE<D,A>,FunSubtractRC<D> > 
  operator-(const MorE<D,A>& a, const std::complex<D> b)
  {
    return  
      MatOpScal<std::complex<D>,MorE<D,A>,FunSubtractRC<D> >( a,b );
  }

  // complexscalar -  realmatrix 
  template <class D, class B> 
  inline ScalOpMat<std::complex<D>,MorE<D,B>,FunSubtractCR<D> > 
  operator-(const std::complex<D> a, const MorE<D,B>& b)
  {
    return  
      ScalOpMat<std::complex<D>,MorE<D,B>,FunSubtractCR<D> >( a, b );
  }
  // complexmatrix - realscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,FunSubtractCR<D> > 
  operator-(const MorE<std::complex<D>,A>& a, const D b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,FunSubtractCR<D> >(a,b);  
  }
  // complexmatrix - intscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,FunSubtractCR<D> > 
  operator-(const MorE<std::complex<D>,A>& a, const int b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,FunSubtractCR<D> >(a,static_cast<D>(b));  
  }
  // realscalar - complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,FunSubtractRC<D> > 
  operator-(const D a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,FunSubtractRC<D> >(a,b);  
  }
  // intscalar - complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,FunSubtractRC<D> > 
  operator-(const int a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,FunSubtractRC<D > >(static_cast<D>(a),b);  
  }


  // realmatrix * complexscalar
  template <class D, class A> 
  inline MatOpScal<std::complex<D>,MorE<D,A>,FunMultiplyRC<D> > 
  operator*(const MorE<D,A>& a, const std::complex<D> b)
  {
    return  
      MatOpScal<std::complex<D>,MorE<D,A>,FunMultiplyRC<D> >( a,b );
  }

  // complexscalar *  realmatrix 
  template <class D, class B> 
  inline ScalOpMat<std::complex<D>,MorE<D,B>,FunMultiplyCR<D> > 
  operator*(const std::complex<D> a, const MorE<D,B>& b)
  {
    return  
      ScalOpMat<std::complex<D>,MorE<D,B>,FunMultiplyCR<D> >( a, b );
  }
  // complexmatrix * realscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,FunMultiplyCR<D> > 
  operator*(const MorE<std::complex<D>,A>& a, const D b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,FunMultiplyCR<D> >(a,b);  
  }
  // complexmatrix * intscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,FunMultiplyCR<D> > 
  operator*(const MorE<std::complex<D>,A>& a, const int b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,FunMultiplyCR<D> >(a,static_cast<D>(b));  
  }
  // realscalar * complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,FunMultiplyRC<D> > 
  operator*(const D a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,FunMultiplyRC<D> >(a,b);  
  }
  // intscalar * complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,FunMultiplyRC<D> > 
  operator*(const int a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,FunMultiplyRC<D > >(static_cast<D>(a),b);  
  }


  // division

  // realmatrix / complexscalar
  template <class D, class A> 
  inline MatOpScal<std::complex<D>, MorE<D,A>,FunDivideRC<D> > 
  operator/(const MorE<D,A>& a, const std::complex<D> b)
  {
    return  
      MatOpScal<std::complex<D> ,MorE<D,A>,FunDivideRC<D> >( a,b );
  }

  // complexscalar /  realmatrix 
  template <class D, class B> 
  inline ScalOpMat<std::complex<D>,MorE<D,B>,FunDivideCR<D> > 
  operator/(const std::complex<D> a, const MorE<D,B>& b)
  {
    return  
      ScalOpMat<std::complex<D>,MorE<D,B>,FunDivideCR<D> >( a, b );
  }
  // complexmatrix / realscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,FunDivideCR<D> > 
  operator/(const MorE<std::complex<D>,A>& a, const D b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,FunDivideCR<D> >(a,b);  
  }
  // complexmatrix / intscalar
  template <class D, class A> 
  inline CMatOpScal<D,MorE<std::complex<D>,A>,FunDivideCR<D> > 
  operator/(const MorE<std::complex<D>,A>& a, const int b)
  {
    return  
      CMatOpScal<D,MorE<std::complex<D>,A>,FunDivideCR<D> >(a,static_cast<D>(b));  
  }
  // realscalar / complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,FunDivideRC<D> > 
  operator/(const D a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,FunDivideRC<D> >(a,b);  
  }
  // intscalar / complexmatrix
  template <class D, class B> 
  inline CScalOpMat<D,MorE<std::complex<D>,B>,FunDivideRC<D> > 
  operator/(const int a, const MorE<std::complex<D>,B>& b)
  {
    return  
      CScalOpMat<D,MorE<std::complex<D>,B>,FunDivideRC<D > >(static_cast<D>(a),b);  
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

    Matrix<std::complex<D> > y(NR,NC);

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

    Matrix<std::complex<D> > y(NR,NC);


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


    Matrix<std::complex<D> > y(NC,NR);

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
