#ifndef MATRICKS__MATRIX_H
#define MATRICKS__MATRIX_H 1




namespace matricks {




 
  
  /****************************************************************************
   * Matrix -- mathematical matrix class.
   **************************************************************************** 
   */

  template <class D, int NR, int NC, int M> class Matrix :
    public TensorRW<D,Matrix<D,NR,NC,M> >{
  private:

    // *********************** OBJECT DATA ***********************************
    //
    // do NOT declare any other storage.
    // keep the instances lightweight
    
    std::valarray<D>* data_;
    index_type Nrows_;
    index_type Ncols_;

  public:     
    typedef D DataType;
    typedef typename NumberType<D>::Type MyNumberType;

    

    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************


    // -------------------  DEFAULT  CONSTRUCTOR: empty --------------------
    explicit Matrix<D,NR,NC,M>() 
    {
      Nrows_ = 0;
      Ncols_ = 0;
      data_ = new std::valarray<D>(0); 
      constructorHelper();
    }


    // --------------------- constant=0 CONSTRUCTOR ---------------------
    explicit Matrix<D,NR,NC,M>(const size_type Nr, const size_type Nc) {
      Nrows_ = Nr;
      Ncols_ = Nc;
      data_ = new std::valarray<D>(Nr*Nc);
      constructorHelper();
    }


    // --------------------- constant CONSTRUCTOR ---------------------

    explicit Matrix<D,NR,NC,M>(const size_type Nr, const size_type Nc, const D& val) {
      Nrows_ = Nr;
      Ncols_ = Nc;
      data_ = new std::valarray<D>(val, Nr*Nc);
      *this = val;
      constructorHelper();
    }


        // --------------------- 2D array  CONSTRUCTOR ---------------------
    Matrix<D,NR,NC,M>(const size_type Nr, const size_type Nc, const D **vals) {
      
      Nrows_ = Nr;
      Ncols_ = Nc;
      data_ = new std::valarray<D>(Nr*Nc);
      *this = vals;
      constructorHelper();
    }


    // ************* C++11 initializer_list 2D CONSTRUCTOR---------------------
    Matrix<D,NR,NC,M>(const std::initializer_list<std::initializer_list<D> >& list1) {

      Nrows_ = list1.size();
      Ncols_ = (*(list1.begin())).size();
      data_ = new std::valarray<D>(Nrows_*Ncols_); 
      *this = list1;
      
      constructorHelper();
    }





    // --------------------- COPY CONSTRUCTOR --------------------

    Matrix<D,NR,NC,M>(const Matrix<D>& m2) {
	Nrows_ = m2.Nrows();
	Ncols_ = m2.Ncols();
	data_ = new std::valarray<D>(m2.size());
	*this = m2;
	constructorHelper();
      }


    // --------------------- EXPRESSION CONSTRUCTOR --------------------


    template <class A> Matrix<D,NR,NC,M>(const TensorR<D,A>& x) {
      // TODO: bounds check
      Nrows_ = x.dims()[0];
      Ncols_ = x.dims()[1];
      data_ = new std::valarray<D>(size());
      *this = x;
      constructorHelper();
      }


    // --------------------- 1D valarray CONSTRUCTOR ---------------------
    Matrix<D,NR,NC,M>(const size_type Nr, const size_type Nc, const std::valarray<D>& valar) {
      Nrows_ = Nr;
      Ncols_ = Nc;
      data_ = new std::valarray<D>(valar); 
      constructorHelper();
    }


    // --------------------- 1D array[]  CONSTRUCTOR ---------------------
    Matrix<D,NR,NC,M>(const size_type Nr, const size_type Nc, const D (vals)[]) {
      // allocate store
      Nrows_ = Nr;
      Ncols_ = Nc;
      data_ = new std::valarray<D>(vals, Nr*Nc); 
      constructorHelper();
    }

    

    
    // --------------------- constructorHelper() --------------------
    
    void constructorHelper() {
    }







    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~Matrix<D,NR,NC,M>() {
      delete  data_ ;

      //remove from directory
    }
  

    //**********************************************************************
    //************************** Size related  ******************************
    //**********************************************************************


    inline size_type size(void) const {
      return data_->size();
    }
    inline size_type Nrows(void) const {
      return Nrows_;
    }
    inline size_type Ncols(void) const {
      return Ncols_;
    }
    size_type ndims(void) const {
      return 2;
    }
    Dimensions dims(void) const {
      Dimensions dimensions(Nrows_,Ncols_);
      return dimensions;
    }
    bool isExpression(void) const {
      return false;
    }
    Tensors getEnum() const {
      return T_MATRIX;
    }

    VectorofPtrs getAddresses(void) const  {
      VectorofPtrs myaddr((void*)this);
      return myaddr;
    }

    Dimensions tdims(void) const {
      Dimensions dimensions(NR,NC);
      return dimensions;
    }

  
    inline size_type depth(void) const {
      return M;
    }

    // the size of each element
    inline size_type elsize(void) const {
      if constexpr(M<2) {
	  return 1;
	} else {
	const size_type Nelements = this->size();
	if (Nelements==0) {
	  return 0;
	} else {
	  return data_[0].size();
	}
      }
    }
    
    // the deep size of an element: the total number of numbers in an element
    inline size_type eldeepsize(void) const {
      if constexpr(M<2) {
        return 1;
      } else {
      const size_type Nelements = this->size();
      if (Nelements==0) {
	return 0;
      } else {
	return data_[0].deepsize();
      }
    }
  }

  // the total number of numbers in this data structure
  size_type deepsize(void) const {
    if constexpr(M<2) {
      return this->size();
    } else {
      return (this->size())*(this->eldeepsize());
    }
  }
 



    //**********************************************************************
    //************************** RESIZE, RESHAPE, TRANSPOSE*****************
    //**********************************************************************

    // -------------------------- resize(nr,nc) --------------------------------
    
    Matrix<D>& resize(const size_type nr, const size_type nc) {
      Nrows_ = nr;
      Ncols_ = nc;
      
      const size_type N = nr*nc;
      if (N==this->size())
	return *this;
      // reallocate store
      data_->resize(N);
      return *this;
    }

    // -------------------------- resize(Dimensions) --------------------------------
    
    Matrix<D>& resize(const Dimensions dims) {
      // TODO: check 
      Nrows_ = dims[0];
      Ncols_ = dims[1];
      
      const size_type N = Nrows_*Ncols_;
      if (N==this->size())
	return *this;
      // reallocate store
      data_->resize(N);
      return *this;
    }


    // -------------------------- resize() by assigment --------------------------------
    // usage:  m.resize() = m2;
    // -----------------------------------------------------------------------
    TERW_Resize<D> resize(void) { 
      return  TERW_Resize<D>(*this);
    }
    // -------------------------- resize() const --------------------------------
    // usage:  m.resize();
    // -----------------------------------------------------------------------
    TERW_Resize<D> resize(void) const { 
      this->resize(0,0);
      return  TERW_Resize<D>(*this);
    }

    // -------------------------- reshape(nr,nc) --------------------------------

    // the new matrix has teh same # of entries but has different number of rows/columns
    // data is left unchanged
    Matrix<D>& reshape(const size_type nr, const size_type nc) { 
      const size_type nn = nr*nc;
      if (nn == 0) {
	Nrows_ = 0;
	Ncols_ = 0; 
      } else {
	Nrows_ = nr;
	Ncols_ = nc; 
      }
      return *this;
    }

    // -------------------------- .reshape(N) --------------------------------
    // morph into a vector, pillaging this object of its data store.
    //
    Vector<D>& reshape(const size_type N) {
      // TODO: check that N==size()
      // rob the data_
      Vector<D> m = new Vector<D>(N, this->data_);
      this->data_ = new std::valarray<D>(0);
      // return the new Matrix, while we live on at zero size...
      return *m;
    }

    // -------------------------- transpose() --------------------------------
    // In-place transpose. 
    // 1) For square matrices this operation is quick and easy.
    // 2) For non-square matrices, this changes the shape and operation is time-consuming
    //    Note: Transpose function is much quicker. only use this for when memory is critical
    Matrix<D>& transpose(void) { 
      const index_type Nr = Nrows_;
      const index_type Nc = Ncols_;
      const index_type N = size();
      const index_type Nminus1 = N-1;

      // square matrix  
      if (Nc == Nr) {
	index_type r,c;
	D temp;
	for (r = 0; r < Nr; ++r)
	  for (c = r + 1; c < Nr; ++c) {
	    temp = (*this)[r + c * Nr];
	    (*this)[r + c * Nr] = (*this)[c + r * Nr];
	    (*this)[c + r * Nr] = temp;
	  }
	return *this;
      }

      reshape(Nc,Nr);

      // for "vectors" 
      if (Nc == 1 || Nr==1) {
	return *this;
      }

      // boolean array to make searching faster
      // can set Nmove=1, but this will be very slow
      // Nmove=(Nr+Nc)/2 is optimal
      const bool Nmove =(Nr+Nc)/2;
      index_type move[Nmove];
      for (index_type i = 0; i < Nmove; ++i)
	move[i] = false;


      // there are always at least 2 fixed points (at j=0 and j=Nminus1)
      index_type count = 2;		
      // find the rest of the fixed points
      if (Nc >= 3 && Nr >= 3)
	count += gcd(Nc - 1, Nr - 1) - 1;	/* # fixed points */

      index_type jstart = 1;
      index_type magicnum = Nc;

      while (1) {
	index_type jnext,jnextc;
	index_type jstartC = Nminus1 - jstart;
	index_type j = jstart;
	index_type jC = jstartC;
	D dstart = (*this)[jstart];
	D dstartC = (*this)[jstartC];

	// PROCESS THE CURRENT SEQUENcE AND ITS COMPLIMENTARY SEQUENcE
	while (1) {
	  jnext = Nc * j - Nminus1 * (j / Nr);
	  jnextc = Nminus1 - jnext;
	  if (j < Nmove)
	    move[j] = true;
	  if (jC < Nmove)
	    move[jC] = true;
	  count += 2;
	  if (jnext == jstart) {
	    (*this)[j] = dstart;
	    (*this)[jC] = dstartC;
	    break;
	  }
	  if (jnext == jstartC) {
	    (*this)[j] = dstartC;
	    (*this)[jC] = dstart;
	    break;
	  }
	  (*this)[j] = (*this)[jnext];
	  (*this)[jC] = (*this)[jnextc];
	  j = jnext;
	  jC = jnextc;
	}
	// DONE PROCESSING SEQUENcE


	// CHECK TO SEE IF WE'RE FINISHED
	if (count >= N)
	  break;	

	// FIND THE START OF THE NEXT SEQUENcE
	while (1)  {
	  // skip fixed points (jstart==magicnum)
	  do  {
	    jstart++;
	    if ((magicnum +=Nc)>Nminus1)
	      magicnum -= Nminus1;
	  } while (jstart==magicnum);
	   
	  jnext = magicnum;
	  const  index_type max = Nminus1-jstart+1;
	  if (jstart < Nmove){
	    if (!move[jstart])
	      break;
	  } else {
	    // this while loop is needed to cull out previously 
	    // processed slcuences
	    while (jnext > jstart && jnext < max) {
	      j = jnext;
	      jnext = Nc * j - Nminus1 * (j / Nr);
	    }
	  }
	  if (jnext == jstart)
	    break;
	} 
	// WE HAVE FOUND START OF THE NEXT SEQUENcE

      }
      return *this;
    }
    
    // -------------------------- adjoint() --------------------------------

    template< typename T=D >
      typename std::enable_if<is_complex<T>{}, Matrix<T>& >::type adjoint() {
      this->conj();
      this->transpose();
      return *this;
    }

  //**********************************************************************
  //******************** DEEP ACCESS: x.dat(n) ***************************
  //**********************************************************************
  // NOTE: indexes over [0] to [deepsize()] and note return type
  
  // "read/write"
  MyNumberType& dat(const index_type n) {
    using namespace::display;
    //    mout << createStyle(BOLD).apply("operator["+num2string(n)+"] #1")<<std::endl;
    if constexpr(M < 2) {
      int k = n;
      if (k < 0) {
	  k += size();
      }
      return data_[k];
    } else {
      const int Ndeep = this->eldeepsize();
      const int j = n / Ndeep;
      const int k = n % Ndeep;
      return data_[j].dat(k);
    }
  }

  // read
  const MyNumberType& dat(const index_type n)  const {
    using namespace::display;
    //    mout << createStyle(BOLD).apply("operator["+num2string(n)+"] #2")<<std::endl;
    if constexpr(M < 2) {
      int k = n;
      if (k < 0) {
	  k += size();
      }
      return data_[k];
    } else {
      const int Ndeep = this->eldeepsize();
      const int j = n / Ndeep;
      const int k = n % Ndeep;
      return data_[j].dat(k);
    }
  }

  

  //**********************************************************************
  //************* Array-style Element Access: x[n] ***********************
  //**********************************************************************

  // "read/write"
  D& operator[](const index_type n) {
    int k = n;
    if (k < 0) {
      k += size();
    }
    return data_[k];
  }

  // read
  const D& operator[](const index_type n)  const {
    int k = n;
    if (k < 0) {
      k += size();
    }
    return data_[k];
  }

  

    // matrix[slice]
    
    TERW_Subset<D> operator[](const slc& slice)  { 
      return (*this)[slice.toIndexVector(size())];
    }
    const TERW_Subset<D>  operator[](const slc& slice) const  {
      return (*this)[slice.toIndexVector(size())];
    }
      
    

    // matrix[Vector<index_type>]

    TERW_Subset<D> operator[](const Vector<index_type>& ii) {
      return TERW_Subset<D>(*this, ii);
    }
    const TERW_Subset<D> operator[](const Vector<index_type>& ii) const {
      return TERW_Subset<D>(*this, ii);
    }



    
    // matrix[mask]
    
    TERW_Submask<D> operator[](const Matrix<bool>& mask)  {
      return  TERW_Submask<D>(*this,mask);
    }
    const TERW_Submask<D> operator[](const Matrix<bool>& mask)  const {
      return  TERW_Submask<D>(*this,mask);
    }



    // matrix[initializer_list]

    TERW_Subset<D> operator[](const std::initializer_list<index_type>& list) {
      return  TERW_Subset<D>(*this, list);
    }
    const TERW_Subset<D> operator[](const std::initializer_list<index_type>& list) const {
      return  TERW_Subset<D>(*this, list);
    }


  //**********************************************************************
  //***************Tensor-style Element Access: A(r,c) *********************
  //**********************************************************************
    
    // --------------------------- index(r,c) -----------------------------
    
    index_type index(const index_type r, const index_type c) const {
      //TODO: bounds check
      return c + Ncols_*r; // row major
    }

    // --------------------------- indices(k) -----------------------------

    // This is the inverse of the above function
    Indices& indices(const index_type k) const {
      // NOTE: a divide is between 6 to 40 times more costly than a multiply
      //       https://stackoverflow.com/questions/4125033/floating-point-division-vs-floating-point-multiplication
      //       So avoid using this whenever possible
      //       simplest way to calc is (k/Ncols_, k%Ncols_)
      //       but the following guarantees that the compution is done efficently
      //TODO: bounds check
      Indices& myinds = *(new Indices(2));
      myinds[0] = k/Ncols_;      // row
      myinds[1] = k - Ncols_*myinds[0];  // column
      return myinds;
    }

    //**********************************************************************
    //************************** access (r,c) ***********************************
    //**********************************************************************


    // ----------------- matrix(r,c) ----------------
    D& operator()(const index_type r, const index_type c) {
      return (*data_)[index(r,c)]; 
    }
    const D operator()(const index_type r, const index_type c) const {
      return (*data_)[index(r,c)]; 
    }

    // TODO: slices etc.


    
    //**********************************************************************
    //************************** ASSIGNMENT **************************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to TensorRW for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions

    // ----------------- matrix = d ----------------
    Matrix<D>& equals(const D d) { 
      for(index_type i=size(); i--;) 
	(*data_)[i]=d; 
      return *this;
    }
    Matrix<D>& operator=(const D d) { 
      return equals(d);
    }


    // ----------------- matrix = TensorR<D,A> ----------------
    template <class A>  Matrix<D>& equals(const TensorR<D,A>& x) {  
      // TODO: issue warning
      resize(x.dims());

      if (common(*this, x)){    
	Matrix<D> mtemp(Nrows_,Ncols_);
	for (index_type i = size(); i--;)
	  mtemp[i] = x[i];   // Inlined expression
	for (index_type i = size(); i--;)
	  (*data_)[i] = mtemp[i];
      } else {
	for (index_type i = size(); i--;)
	  (*data_)[i] = x[i];   // Inlined expression
      }
      return *this; 
    }

   template <class A>  Matrix<D>& operator=(const TensorR<D,A>& x) {  
      return equals(x);
    }


   



    // ----------------- matrix = D[][] ----------------
    Matrix<D>& equals(const D **array) {
      index_type k = 0;
      for (index_type r = 0; r < Nrows_; r++)  { 
	for (index_type c = 0; c < Ncols_; c++)  { 
	  (*this)[k++] = array[r][c];
	}
      }
      return *this;
    }
    Matrix<D>& operator=(const D **array) {
      return equals(array);
    }




    

    // ----------------- matrix = matrix ----------------
    Matrix<D>& equals(const Matrix<D>& m2) {
      // TODO; issue warning
      this->resize(m2.dims());

      for(index_type i=size(); i--;)
	(*data_)[i] = m2[i];    
      return *this;
    }
    Matrix<D>& operator=(const Matrix<D>& m2) {
      return equals(m2);
    }



    // ----------------- matrix = matrix2.resize()  ----------------
    template <class B>
      Matrix<D>& operator=(const TERW_Resize<D>& b) {
      // do nothing
      return *this;
    }

    

    

    // ----------------- matrix = initializer_list<initializer_list>  ----------------
    Matrix<D>& equals(const std::initializer_list<std::initializer_list<D> >& mylist) {
      // TODO: size check 
      index_type i = 0;
      typename std::initializer_list<std::initializer_list<D> >::iterator itR; 
      for (itR = mylist.begin(); itR != mylist.end(); ++itR)  {
	const std::initializer_list<D>& row = *itR;
	// TODO: check that each row has same # cols
	typename std::initializer_list<D>::iterator itC; 
	for (itC = row.begin(); itC != row.end(); ++itC)  {
	  (*this)[i++] = *itC;
	}
      }

      return *this;
    }
    Matrix<D>& operator=(const std::initializer_list<std::initializer_list<D> >& mylist) {
      return equals(mylist);
    }

    //*********************************************************
    //                   1D assignment
    //********************************************************
    

    // ------------------------ matrix = array[] ----------------
    Matrix<D>& equals(const D array1[]) {
      for (index_type i = 0; i < size(); i++)  { 
	(*this)[i] = array1[i];
      }
      return *this;
    }
    Matrix<D>& operator=(const D array1[]) {
      return equals(array1);
    }


    // --------------- matrix = initializer_list ------------------
    Matrix<D>& equals(const std::initializer_list<D>& mylist) {

      // TODO: bound scheck 
      size_type i = 0;
      typename std::initializer_list<D>::iterator it; 
      for (it = mylist.begin(); it != mylist.end(); ++it)  { 
	(*this)[i++] = *it;
      }

      return *this;
    }
    Matrix<D>& operator=(const std::initializer_list<D>& mylist) {
      return equals(mylist);
    }



    //**********************************************************************
    //************************** data_ access ***********************************
    //**********************************************************************

    // -------access to the internal data valarray --------------------

    // "read/write" to the wrapped valarray
    std::valarray<D>& getValArray()  {
      return *data_; 
    }
    Matrix<D>& setValArray(std::valarray<D>* valptr)  {
      delete  data_ ;
      const size_t N = valptr->size();
      data_ = valptr;
      return *this;
    }

    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************

    //----------------- .roundzero(tol) ---------------------------
    // NOTE: in-place

    Matrix<D>&  roundzero(D tolerance = MatricksHelper<D>::tolerance) { 
      for(index_type i=size(); i--;) {
	(*data_)[i] = matricks::roundzero((*data_)[i], tolerance);
      }
      return *this;
    }


    //----------------- .conj() ---------------------------
    // NOTE: in-place

    template< typename T=D >
      typename std::enable_if<is_complex<T>{}, Matrix<T>& >::type conj() {
      for(index_type i=size(); i--;) {
	(*data_)[i] = std::conj((*data_)[i]);
      }
      return *this;
    }



    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************

    inline std::string classname() const {
      D d;
      return "Matrix"+display::getBracketedTypeName(d);
    }


#if MATRICKS_DEBUG>=1
    std::string expression(void) const {
      return "";
    }
#endif




    // stream << operator


    friend std::ostream& operator<<(std::ostream &stream, const Matrix<D>& m) {
      using namespace display;

      Style& style = FormatDataMatrix::style_for_punctuation;
      stream << style.apply(FormatDataMatrix::string_opening);
      const matricks::index_type N = FormatDataMatrix::max_elements_per_line;

      for (matricks::index_type r = 0; r < m.Nrows(); r++) {
	stream << style.apply(FormatDataMatrix::string_row_opening);
	matricks::index_type k = 0;
	for (matricks::index_type c = 0; c < m.Ncols(); c++, k++) {
	  if (k >= N)  {
	    stream << style.apply(FormatDataMatrix::string_endofline);
	    k = 0;
	  }
	  dispval_strm(stream, m(r,c));
	  if (c < m.Ncols()-1)  {
	    stream << style.apply(FormatDataMatrix::string_delimeter);
	  } else {
	    if (r < m.Nrows()-1)  {
	      stream << style.apply(FormatDataMatrix::string_row_closing);
	    } else {
	      stream << style.apply(FormatDataMatrix::string_lastrow_closing);
	    }
	  }
	}
      }
      stream << style.apply(FormatDataMatrix::string_closing);
      
      return stream;
    }


    //template <class D>	
    friend inline std::istream& operator>>(const std::string s,  Matrix<D>& m2) {	
      std::istringstream st(s);
      return (st >> m2);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream,  Matrix<D>& m2) {	
      return stream;
    }


  

  };




};


#endif 

