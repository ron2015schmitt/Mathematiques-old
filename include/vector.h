#ifndef VECTOR_H
#define VECTOR_H 1




namespace matricks {

 
 
  
  /****************************************************************************
   * Vector -- mathematical vector class.
   ****************************************************************************   
   */

  template <class D> class Vector : public VorE<D,Vector<D> >, public VectorofPtrs, public VorW<D,Vector<D> > {
  private:

    // *********************** OBJECT DATA ***********************************
    size_type objectID_;
    size_type perline_;
    size_type width_;   // for display  (std::setw uses int as its size)
    TextFormat textformat_;
    std::valarray<D>* data_;

#if MATRICKS_DEBUG>0
    D dummy_;
#endif
    mutable std::string name_;

  public:     
    using VectorofPtrs::getAddresses;
    using VectorofPtrs::checkAddresses;
    using VectorofPtrs::addAddress;
    using VectorofPtrs::addAddresses;

    typedef D element_type;
    typedef typename RealVersionOfType<D>::Type DREAL;



    //**********************************************************************
    //************************** CONSTRUCTORS ******************************
    //**********************************************************************


    // -------------------  DEFAULT  CONSTRUCTOR: empty --------------------
    explicit Vector<D>() 
    {
      data_ = new std::valarray<D>(0); 
      constructorHelper();
    }


    // --------------------- constant=0 CONSTRUCTOR ---------------------

    explicit Vector<D>(const size_type N) 
    { 
      data_ = new std::valarray<D>(N);
      constructorHelper();
    }


    // --------------------- constant CONSTRUCTOR ---------------------

    explicit Vector<D>(const size_type N, const D val) 
    {
      
      data_ = new std::valarray<D>(N); 
      *this = val;
      constructorHelper();
    }


    // ************* C++11 initializer_list CONSTRUCTOR---------------------
#if CPP11 == 1
    explicit Vector<D>(const std::initializer_list<D> list) 
    {

      const size_type N =  list.size();
      data_ = new std::valarray<D>(N); 

      index_type i = 0;
      typename std::initializer_list<D>::iterator it; 
      for (it = list.begin(); it != list.end(); ++it)  { 
	(*this)[i++] = *it;
      }

      constructorHelper();
    }

#endif


    // --------------------- valarray CONSTRUCTOR ---------------------
    explicit Vector<D>(const std::valarray<D>& valar) 
    {

      data_ = new std::valarray<D>(valar); 
      constructorHelper();

    }



    // --------------------- array[]  CONSTRUCTOR ---------------------
    explicit Vector<D>(const size_type N, const D (vals)[]) 
    {
      v_array_warning(objectID());

      // allocate store
      data_ = new std::valarray<D>(vals, N); 
      constructorHelper();
    }


    

    // --------------------- COPY CONSTRUCTOR --------------------

    Vector<D>(const Vector<D>& v2) 
    {
      const size_type N = v2.size();
      data_ = new std::valarray<D>(N); 
      *this = v2;
      constructorHelper();
    }


    // --------------------- EXPRESSION CONSTRUCTOR --------------------


    template <class A>
    Vector<D>(const Vexpr<D,A>& x) 
    {

      const size_type N = x.size();
      data_ = new std::valarray<D>(N); 
      *this = x;
      constructorHelper();
    }




    // --------------------- constructorHelper() --------------------
    
    void constructorHelper() {
      perline_ = size()+1;
      width_ = 0;
      textformat_=text_braces;
      name_ = "Vector";
      addAddress(this);
      
#if MATRICKS_DEBUG>0
      dummy_ = D();
      // add this vector to the directory
      //      Any<Vector<D> > me;
      //      objectID_ = MatricksObjectManager::addObject(this);
#endif      
    }







    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~Vector<D>() {
      delete  data_ ;

      //remove from directory
#if MATRICKS_DEBUG>0
      MatricksObjectManager::removeObject(objectID_);
#endif
    }
  

    //**********************************************************************
    //************************** Size related  ******************************
    //**********************************************************************

    // --------------------- RESIZE ---------------------

    // These allow the user to resize a vector


    // *** this is used for recon by assignment ***

    VReconObj<D>  resize(void) { 
      return  VReconObj<D>(*this);
    }

    // *** resize from given integer *** 

    Vector<D>&  resize(const size_type n) { 
      if (n==this->size())
	return *this;
      size_type N;
      if (n>maxsize) 
	N=0;
      else 
	N=n;
      // reallocate store
      //      delete  data_ ;
      //      data_ = new std::valarray<D>(N);
      data_->resize(N);
      perline_ = N+1;
      width_ = 0;
#if MATRICKS_DEBUG>0
      // update the directory
      if (n>maxsize) 
	vbad_size(objectID_, n);
#endif      
      return *this;
    }


    inline size_type size(void) const {
      return data_->size();
    }

    //**********************************************************************
    //************************** ACCESSS ***********************************
    //**********************************************************************

    // -------------------- valarray ACCESS --------------------


    // "read/write" to the wrapped valarray
    inline std::valarray<D>& getValArray()  {
      return *data_; 
    }
    inline Vector<D>& setValArray(std::valarray<D>* valptr)  {
      delete  data_ ;
      const size_t N = valptr->size();
      data_ = valptr;
      perline_ = N+1;
      return *this;
    }

    // -------------------- ELEMENT ACCESS --------------------

    // "read/write" access signed index
    inline D& operator[](const index_type i)  {
      index_type index = i;
      if (i < 0) {
	index += size();
      }
#if MATRICKS_DEBUG>0
      if ( (index < 0) || (index >= size()) ) {
	vout_of_bounds(objectID_,index);
	return dummy_; 
      }
#endif    
      return (*data_)[index]; 
    }


    // "read only" access igned index
    inline const D operator[](const index_type i) const {
      return (const D)(*data_)[i]; 
    }




    // Accessing a slice of values
    
    VSubsetObj<D> operator[](const slc& slice)  { 
      return (*this)[slice.toIndexVector(size())];
    }
    const VSubsetObj<D>  operator[](const slc& slice) const  {
      display::log3("Vector","operator[]","(const slc& slice)\n");
      return (*this)[slice.toIndexVector(size())];
    }
      
    

    // Accessing a SET of values using a vector of ints

    VSubsetObj<D> operator[](const Vector<index_type>& ii) {
      return VSubsetObj<D>(*this, ii);
    }
    const VSubsetObj<D> operator[](const Vector<index_type>& ii) const {
      return VSubsetObj<D>(*this, ii);
    }



    
    // Accessing a SET of values using a MASK
    
    VSubMaskObj<D> operator[](const Vector<bool>& mask)  {
#if MATRICKS_DEBUG>0
      if (size()!=mask.size()) {
	vbad_mask(objectID_,mask);
      }
#endif    
      return  VSubMaskObj<D>(*this,mask);
    }
    const VSubMaskObj<D> operator[](const Vector<bool>& mask)  const {
#if MATRICKS_DEBUG>0
      if (size()!=mask.size()) {
	vbad_mask(objectID_,mask);
      }
#endif    
      return  VSubMaskObj<D>(*this,mask);
    }



    //Accessing a SET of values using a list

    #if CPP11 == 1
    VSubsetObj<D> operator[](const std::initializer_list<index_type>& list) {
      return  VSubsetObj<D>(*this, list);
    }
    const VSubsetObj<D> operator[](const std::initializer_list<index_type>& list) const {
      return  VSubsetObj<D>(*this, list);
    }
    #endif



    
    //**********************************************************************
    //************************** ASSIGNMENT **************************************
    //**********************************************************************

    // Any new assignment operators should also be addedc to VWrapper for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions

    // Assign all elements to the same constant value
    Vector<D>& equals(const D d) { 
      for(index_type i=size(); i--;) 
	(*data_)[i]=d; 
      return *this;
    }
    Vector<D>& operator=(const D d) { 
      return equals(d);
    }


    // Assignment to a vector expression
    template <class A>  Vector<D>& equals(const Vexpr<D,A>& x) {  
#if MATRICKS_DEBUG>0
      std::string s1 = debugtxt();
      std::string s2 = x.debugtxt();
      if ( vexpr_is_size_bad(x) ){ 
	vbad_expr_in_assignment(objectID(), x);
	return *this;
      } else if ( (size()>0) && ( size() !=  x.size() ) ){ 
	vbad_assignment_expr_warning(objectID(), x);
      } else if (size() !=  x.size() ){
	// if size=0, just silently resize this vector
	//vbad_assignment_expr_warning(objectID(),x);
      }

#endif

      // resize to avoid segmentation faults
      resize(x.size());

      if (x.checkAddresses(this->getAddresses())) {    
#if MATRICKS_DEBUG>0
	//	Vector<D> vtemp(size(),x.debugtxt());
	Vector<D> vtemp(size());
#else
	Vector<D> vtemp(size());
#endif
	for (register index_type i = size(); i--;)
	  vtemp[i] = x[i];   // Inlined expression
	for (register index_type i = size(); i--;)
	  (*data_)[i] = vtemp[i];
      } else {
	for (register index_type i = size(); i--;)
	  (*data_)[i] = x[i];   // Inlined expression
      }
      return *this; 
    }

    template <class A>  Vector<D>& operator=(const Vexpr<D,A>& x) {  
      return equals(x);
    }



    
    template <class A>  Vector<D>& equals(const VorE<D,A>& x) {  
#if MATRICKS_DEBUG>0
      std::string s1 = debugtxt();
      std::string s2 = x.debugtxt();
      if ( vexpr_is_size_bad(x) ){ 
	vbad_expr_in_assignment(objectID(), x);
	return *this;
      } else if ( (size()>0) && ( size() !=  x.size() ) ){ 
	vbad_assignment_expr_warning(objectID(), x);
      } else if (size() !=  x.size() ){
	// if size=0, just silently resize this vector
	//vbad_assignment_expr_warning(objectID(),x);
      }

#endif

      // resize to avoid segmentation faults
      resize(x.size());

      if (x.checkAddresses(this->getAddresses())) {    
#if MATRICKS_DEBUG>0
	//	Vector<D> vtemp(size(),x.debugtxt());
	Vector<D> vtemp(size());
#else
	Vector<D> vtemp(size());
#endif
	for (register index_type i = size(); i--;)
	  vtemp[i] = x[i];   // Inlined expression
	for (register index_type i = size(); i--;)
	  (*data_)[i] = vtemp[i];
      } else {
	for (register index_type i = size(); i--;)
	  (*data_)[i] = x[i];   // Inlined expression
      }
      return *this; 
    }

    
    template <class A>  Vector<D>& operator=(const VorE<D,A>& x) {  
      return equals(x);
    }



    // assignment to an array
    Vector<D>& equals(const D array[]) {
      
#if MATRICKS_DEBUG>0
      v_array_warning(objectID());
#endif      

      for (index_type i; i < size(); i++)  { 
	(*this)[i++] = array[i];
      }

      return *this;
    }


    Vector<D>& operator=(const D array[]) {
      return equals(array);
    }




    

    // Copy asignment
    Vector<D>& equals(const Vector<D>& v2) {

#if MATRICKS_DEBUG>0
      if ( (size()>0) && ( size() !=  v2.size() ) ){ 
	vbad_assignment_warning(objectID(),v2.objectID());
      } else if (size() !=  v2.size() ){
	// if size=0, just silently resize this vector
	//	vbad_assignment_warning(objectID(),v2.objectID());
      }
 
#endif
      // resize to avoid segmentation faults
      resize(v2.size());

      for(register index_type i=size(); i--;)
	(*data_)[i] = v2[i];    
      return *this;
    }



    Vector<D>& operator=(const Vector<D>& v2) {
      return equals(v2);
    }



    // assignment to matrix or submatrix
    // one of the two dimensions must have single element width
    template <class A>
    Vector<D>& operator=(const MorE<D,A>& m) {

#if MATRICKS_DEBUG>0
      const size_type NR = m.Nrows();
      const size_type NC = m.Ncols();
      if ( size() !=  m.size() ){ 
	vbad_assignment_mat(objectID(),NR,NC);
	return *this;
      }
      if ((NR!=1) && (NC!=1)) { 
	vbad_assignment_mat(objectID(),NR,NC);
	return *this;
      }
#endif
      for(register index_type i=size(); i--;)
	(*data_)[i] = m(i);    
      return *this;
    }



    template <class B>
    Vector<D>& operator=(const VReconObj<D>& b) { 
#if MATRICKS_DEBUG>0
      vbad_reconassignment(objectID(), b);
#endif
      return *this;
    }


    Vector<D>& equals(const std::list<D> mylist) {
      
#if MATRICKS_DEBUG>0
      if ( (size()>0) && ( size() !=  mylist.size() ) ){ 
	vbad_assignment_general_warning(objectID(),mylist.size(), "std::list<D>");
      } else if (size() !=  mylist.size() ){
	// if size=0, just silently resize this vector
	//	vbad_assignment_warning(objectID(),v2.objectID());
      }      
#endif      

      // resize to avoid segmentation faults
      resize(mylist.size());

      index_type i = 0;
      for (typename std::list<D>::const_iterator it = mylist.begin(); it != mylist.end(); ++it)  { 
	(*this)[i++] = *it;
      }

      return *this;
    }


    Vector<D>& operator=(const std::list<D> mylist) {
      return equals(mylist);
    }

    
    // assignment to a C++11 list
#if CPP11 == 1
    Vector<D>& equals(const std::initializer_list<D> mylist) {
      
#if MATRICKS_DEBUG>0
      if ( (size()>0) && ( size() !=  mylist.size() ) ){ 
	vbad_assignment_general_warning(objectID(),mylist.size(), "std::initializer_list<D>");
      } else if (size() !=  mylist.size() ){
	// if size=0, just silently resize this vector
	//	vbad_assignment_warning(objectID(),v2.objectID());
      }      
#endif      

      // resize to avoid segmentation faults
      resize(mylist.size());

      size_type i = 0;
      typename std::initializer_list<D>::iterator it; 
      for (it = mylist.begin(); it != mylist.end(); ++it)  { 
	(*this)[i++] = *it;
      }

      return *this;
    }


    Vector<D>& operator=(const std::initializer_list<D> mylist) {
      return equals(mylist);
    }
#endif



    // assignment to a std::vector
    Vector<D>& equals(const std::vector<D> vstd) {
      
#if MATRICKS_DEBUG>0
      if ( (size()>0) && ( size() !=  vstd.size() ) ){ 
	vbad_assignment_general_warning(objectID(),vstd.size(), "std::vector<D>");
      } else if (size() !=  vstd.size() ){
	// if size=0, just silently resize this vector
	//	vbad_assignment_warning(objectID(),v2.objectID());
      }      
#endif      

      // resize to avoid segmentation faults
      resize(vstd.size());

      for(register size_type i=size(); i--;)
	(*data_)[i] = vstd[i];    

      return *this;
    }


    Vector<D>& operator=(const std::vector<D> vstd) {
      return equals(vstd);
    }



    // assignment to a std::array
    template <std::size_t N>
    Vector<D>& equals(const struct std::array<D,N> varray) {
      
#if MATRICKS_DEBUG>0
      if ( (size()>0) && ( size() !=  N) ) { 
	vbad_assignment_general_warning(objectID(), N, "std::array<D,N>");
      } else if (size() !=  N ){
	// if size=0, just silently resize this vector
	//	vbad_assignment_warning(objectID(),v2.objectID());
      }      
#endif      

      // resize to avoid segmentation faults
      resize(N);

      for(register size_type i=size(); i--;)
	(*data_)[i] = varray[i];    

      return *this;
    }


    template <std::size_t N>
    Vector<D>& operator=(const struct std::array<D,N> varray) {
      return equals(varray);
    }



    // assignment to a std::val_array
    Vector<D>& equals(const std::valarray<D> varray) {
      
#if MATRICKS_DEBUG>0
      if ( (size()>0) && ( size() !=  varray.size() ) ){ 
	vbad_assignment_general_warning(objectID(),varray.size(), "std::valarray<D>");
      } else if (size() !=  varray.size() ){
	// if size=0, just silently resize this vector
	//	vbad_assignment_warning(objectID(),v2.objectID());
      }      
#endif      

      // resize to avoid segmentation faults
      resize(varray.size());

      for(register size_type i=size(); i--;)
	(*data_)[i] = varray[i];    

      return *this;
    }

    Vector<D>& operator=(const std::valarray<D> varray) {
      return equals(varray);
    }




    //**********************************************************************
    //************************** MATH **************************************
    //**********************************************************************

    
    Vector<D>&  clear(void) { 
      return resize(0);
    }

    
    Vector<D>&  roundzero(D tolerance = MatricksHelper<D>::tolerance) { 
      for(register index_type i=size(); i--;) {
	(*data_)[i] = matricks::roundzero((*data_)[i], tolerance);
      }
      return *this;
    }


    //**********************************************************************
    //***************** in-place modification********************************
    //**********************************************************************

    // .sort()
    //         sorts in place and returns the permuted indices

    Vector<index_type>& sort() {

      const size_type N = size();
      Vector<index_type> &ivec = *(new Vector<index_type>(N));

      if (N==0)
	return ivec;
    
      std::vector<pair<D> > temp(N);

      for (register index_type i = 0; i < N ; i++ ) {
	temp[i].index = i;
	temp[i].data = (*data_)[i];
      }
    
    
      std::sort(temp.begin(),temp.end());
    
    
      for (register index_type i = 0; i < N ; i++ ) {
	ivec[i] = temp[i].index;
	(*data_)[i] = temp[i].data;
      }
    
      return ivec;

    }


    // .quniq()
    //         removes adjacent duplicates

    Vector<index_type>& quniq() {

      const size_type N = size();

      if (N==0)
	return *(new Vector<index_type>(0));
    
      std::queue<pair<D> > unique;
	
      pair<D> prevpair(0, (*data_)[0]);
      unique.push(prevpair);
      for (register index_type i = 1; i < N ; i++ ) {
	pair<D> mypair(i, (*data_)[i]);
	if (mypair.data != prevpair.data) {
	  unique.push(mypair);
	  prevpair = mypair;
	} 
      }

      const size_type Nnew = unique.size();
      Vector<index_type> &indexvec = *(new Vector<index_type>(Nnew));
      resize(Nnew);
      for (register index_type i = 0; i < Nnew ; i++ ) {
	pair<D> mypair = unique.front();
	unique.pop();
	indexvec[i] = mypair.index;
	(*data_)[i] = mypair.data;
      }

      return indexvec;
    }


    // .uniq()
    //         removes all duplicates

    Vector<index_type>& uniq() {

      const size_type N = size();

      if (N==0)
	return *(new Vector<index_type>(0));
    
      std::map<index_type,D> mymap;
      for (register index_type j = 0; j < N ; j++ ) {
	mymap[j] = (*data_)[j];
      }

      for (register index_type j = 0; j < N ; j++ ) {
	if (mymap.find(j) == mymap.end()) continue;
	pair<D> pair1(j, (*data_)[j]);
	for (register index_type k = j+1; k < N ; k++ ) {
	  if (mymap.find(k) == mymap.end()) continue;
	  pair<D> pair2(k, (*data_)[k]);
	  if (pair1.data == pair2.data) {
	    mymap.erase(k);
	  } 
	}
      }

      const size_type Nnew = mymap.size();
      Vector<index_type> &indexvec = *(new Vector<index_type>(Nnew));
      resize(Nnew);
      index_type k = 0;
      for (typename std::map<index_type,D>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
	indexvec[k] = it->first;
	(*data_)[k++] = it->second;
      }

      return indexvec;
    }


    Vector<D>& reverse() {

      const size_type N = size();
      if (N==0)
	return *this;
   
      for (register index_type i = 0; i < N/2 ; i++ ) {
	D temp = (*data_)[i];
	(*data_)[i] = (*data_)[N-i-1];
	(*data_)[N-i-1] = temp;
      }
      
      return *this;
      
    }


    // .cumsum() -- cumulative sum

    Vector<D>& cumsum() {
      const size_type N = size();
      D sum = 0;
      for (register index_type i = 0; i < N ; i++ ) {
	sum += (*data_)[i];
	(*data_)[i] = sum;
      }
      return *this;
    }

    // .cumprod()  --  cumulative product

    Vector<D>& cumprod() {
      const size_type N = size();
      D prod = 1;
      for (register index_type i = 0; i < N ; i++ ) {
	prod *= (*data_)[i];
	(*data_)[i] = prod;
      }
      return *this;
    }


    // .cumtrapz() -- cumulative trapezoidal summation

    Vector<D>& cumtrapz() {
      const size_type N = size();
      if (N==0) return *this;
      D sum = (*data_)[0]/2;
      (*data_)[0] = 0;
      for (register index_type i = 1; i < N ; i++ ) {
	sum += (*data_)[i];
	(*data_)[i] = sum - (*data_)[i]/2;
      }
      return *this;
    }

    // integrate_a2x(order)
    // order  name
    //     0  rectangular
    //     1  trapazoidal
    Vector<D>& integrate_a2x(const D a, const D b, const int order=1) {
      std::valarray<D> &mydata = *data_;

      const size_type N = size();

      if (order == 0) {
	this->cumsum();
	const D dx = (b-a)/D(N);
	for (register index_type i = 0; i < N ; i++ ) {
	  mydata[i] *= dx;
	}
      } else if (order == 1) {
	this->cumtrapz();
	const D dx = (b-a)/D(N-1);
	for (register index_type i = 0; i < N ; i++ ) {
	  mydata[i] *= dx;
	}
      }  else {
	//TODO: issue error
      }
      return *this;
    }


    // .cumsumrev() -- cumulative sum -- from last to first

    Vector<D>& cumsum_rev() {
      std::valarray<D> &mydata = *data_;
      const size_type N = size();

      D sum = 0;
      for (register index_type i = 0; i < N ; i++ ) {
	sum += mydata[N-1-i];
	mydata[N-1-i] = sum;
      }
      return *this;
    }

    // .cumprodrev()  --  cumulative product  -- from last to first

    Vector<D>& cumprod_rev() {
      std::valarray<D> &mydata = *data_;
      const size_type N = size();

      D prod = 1;
      for (register index_type i = 0; i < N ; i++ ) {
	prod *= mydata[N-1-i];
	mydata[N-1-i] = prod;
      }
      return *this;
    }


    // .cumtrapz() -- cumulative trapezoidal summation -- from last to first

    Vector<D>& cumtrapz_rev() {
      std::valarray<D> &mydata = *data_;
      const size_type N = size();
      if (N==0) return *this;

      D sum = mydata[N-1]/2;
      mydata[N-1] = 0;
      for (register index_type i = 1; i < N ; i++ ) {
	sum += mydata[N-1-i];
	mydata[N-1-i] = sum - mydata[N-1-i]/2;
      }
      return *this;
    }



    // integrate_x2b
    // order  name
    //     0  rectangular
    //     1  trapazoidal
    Vector<D>& integrate_x2b(const D a, const D b, const int order=1) {
      std::valarray<D> &mydata = *data_;
      const size_type N = size();

      if (order == 0) {
	this->cumsum_rev();
	const D dx = (b-a)/(N);
	for (register index_type i = 0; i < N ; i++ ) {
	  mydata[N-1-i] *= dx;
	}
      } else if (order == 1) {
	this->cumtrapz_rev();
	const D dx = (b-a)/(N-1);
	for (register index_type i = 0; i < N ; i++ ) {
	  mydata[N-1-i] *= dx;
	}
      }  else {
	//TODO: issue error
      }
      return *this;
    }



    // diff   (v[n] = v[n] - v[n-1])
    Vector<D>& diff(const bool periodic=false) {
      std::valarray<D> &mydata = *data_;
      const size_type N = size();
      if (N<=1) return *this;

      D temp;
      if (periodic) {
	temp = mydata[0] - mydata[N-1];
      } else {
	temp = mydata[1] - mydata[0];
      }

      for (register index_type i = 0; i < N-1 ; i++ ) {
	mydata[N-1-i] = mydata[N-1-i] - mydata[N-2-i];
      }

      mydata[0] = temp;
      return *this;
    }

    // diff_rev   (v[n] = v[n+1] - v[n])
    Vector<D>& diff_rev(const bool periodic=false) {
      const size_type N = size();
      std::valarray<D> &mydata = *data_;
      if (N<=1) return *this;

      D temp;
      if (periodic) {
	temp = mydata[0] - mydata[N-1];
      } else {
	temp = mydata[N-1] - mydata[N-2];
      }

      for (register index_type i = 0; i < N-1 ; i++ ) {
	mydata[i] = mydata[i+1] - mydata[i];
      }

      mydata[N-1] = temp;
      return *this;
    }


    // deriv -  derivative

    Vector<D>& deriv(const D a, const D b, int Dpts=3, const int n=1, const bool periodic=false) {
      std::valarray<D> &mydata = *data_;
      const size_type N = size();
      if (N<=1) return *this;

      const D dx = (b-a)/D(N-1);

      if (Dpts > N ) {
	//TODO: error or warning
	Dpts = N;
      }

      if (Dpts == 2) {
	this->diff(periodic);
	for (register index_type i = 0; i < N ; i++ ) {
	  mydata[i] /= dx;
	}
	
      } else if (Dpts == 3) {
	D prev;
	D curr;
	D last;
	if (periodic) {
	  // first point
	  prev = mydata[1] - mydata[N-1];
	  // last
	  last = mydata[0] - mydata[N-2];
	} else {
	  // first point
	  prev = -3*mydata[0] + 4*mydata[1] - mydata[2];
	  // last
	  last = 3*mydata[N-1] - 4*mydata[N-2] + mydata[N-3];
	}
	
	const D c0 = 0.5/dx;
	for (register index_type i = 1; i < N-1 ; i++ ) {
	  curr = mydata[i+1] - mydata[i-1];
	  mydata[i-1] = c0*prev;
	  prev = curr;
	}
	mydata[N-2] = c0*prev;
	mydata[N-1] = c0*last;
	
      }  else {
	//TODO: issue error
      }
      if (n>1) {
	return this->deriv(a,b,Dpts,periodic,n-1);
      } 
      return *this;
    }


    
    //**********************************************************************
    //************************** Text and debugging ************************
    //**********************************************************************


    size_type objectID(void) const { 
      return objectID_;
    }

    size_type perline(const size_type Nline)  { 
      return (perline_=Nline);
    }
    size_type perline(void)  const { 
      return perline_;
    }

    size_type width(const size_type w)  { 
      return (width_=w);
    }
    size_type width(void)  const { 
      return width_;
    }


    inline VETypes vetype(void) const {
      return VE_Vector;
    }

    TextFormat textformat(void) const {
      return textformat_;
    }

    TextFormat textformat(TextFormat newformat) {
      return textformat_ = newformat;
    }

    static std::string classname(void)  {
      using namespace display;
      Style style = FormatDataVector::style_for_type_name;		
      std::string s =  style.apply("Vector");				
      D d;								
      s = s+"<"+getTypeName(d)+">";					
      return s;
    }


    std::string debugtxt(void) const {
#if MATRICKS_DEBUG>0
      return ""; //MatricksObjectManager::vectorname(objectID_); 
#else
      return name_;
#endif
    }

    void debugtxt(const char* newname) const {
      std::string s = newname;
#if MATRICKS_DEBUG>0
      //      MatricksObjectManager::vchange_name(objectID_,s); 
#else
      name_=s;
#endif
    }

    void debugtxt(const std::string newname) const {
#if MATRICKS_DEBUG>0
      // MatricksObjectManager::vchange_name(objectID_,newname); 
#else
      name_=name;
#endif
    }

    std::string name(void) const {
      return debugtxt();
    }

    void name(const char* newname) const {
      debugtxt(newname);
    }

    void name(const std::string newname) const {
      debugtxt(newname);
    }


    static std::string datatype(void) {
      D dummy = D();
      return getTypeString(dummy);
    }

    void outputglossary(void) const {
#if MATRICKS_DEBUG>0
      MatricksObjectManager::outputGlossary(objectID_);
#endif
    }

    // stream << operator

    friend std::ostream& operator<<(std::ostream &stream, const Vector<D>& v) {
      using namespace display;

      Style& style = FormatDataVector::style_for_punctuation;
      stream << style.apply(FormatDataVector::string_opening);
      const matricks::index_type N = FormatDataVector::max_elements_per_line;
      matricks::index_type k = 0;
      for (matricks::index_type ii = 0; ii < v.size(); ii++, k++) {
	if (k >= N)  {
	  stream << style.apply(FormatDataVector::string_endofline);
	  k = 0;
	}
	printObj(v[ii]);
	if (ii < v.size()-1)  {
	  stream << style.apply(FormatDataVector::string_delimeter);
	}
      }
      stream << style.apply(FormatDataVector::string_closing);
      return stream;
    }


    //template <class D>	
    friend inline std::istream& operator>>(const std::string s,  Vector<D>& x) {	
      std::istringstream st(s);
      return (st >> x);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream,  Vector<D>& x) {	
      const size_type LINESZ = 32768;
      char line[LINESZ];
      std::vector<D> v;
      size_type N = 0;
      const size_type Nold = x.size();
      D temp;
      size_type Nlines = 0;
      std::istringstream strmline;

      switch (x.textformat()) {
      case text_braces: 
	{
	  enum States {begin, invec, waitingforcomma, end};
	  States state = begin;

	  while( (state!=end) && stream.getline(line,LINESZ)){
	    Nlines++;
	    strmline.clear();
	    strmline.str(line);
	
	    char c;
	    size_type Nchars=0;
	    while((state!=end) && strmline.get(c) ){
	      Nchars++;
	      if (isspace(c))
		continue;
	      if (c=='%')
		break; // ignore rest of line "%" signifies a comment
	  
	      switch (state) {
	      case begin:
		if  (c=='{')  {
		  state = invec;
		  break;
		}else {
		  std::string extrastr = "Expecting an opening brace.";
		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
		  return stream;
		}
		break;
	      case invec:
		if  (c=='}') {
		  state = end;
		  break;
		}
		strmline.putback(c);
		if (strmline>>temp){
		  v.push_back(temp);
		  N++;
		  state = waitingforcomma;
		  break;
		}else {
		  std::string extrastr = "Expecting a vector element.";
		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
		  return stream;
		}
		return stream;
	      case waitingforcomma:
		if  (c=='}') {
		  state = end;
		  break;
		}
		if  (c==',') {
		  state = invec;
		  break;
		}else {
		  std::string extrastr = "Expecting a comma.";
		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
		  return stream;
		}
		break;
	      case end:
		{
		  std::string extrastr = "Expecting a closing brace.";
		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
		}
		return stream;
		break;
	      default:
		bug_report(__FILE__,__LINE__);
		return stream;
		break;
	      }
	    }
	  }
	  if (Nold==0) {
	    x.resize(N);
	  } else if (N != Nold) {
	    vbad_input_stream_size(x.name(),line,N,Nold);
	    return stream;
	  }
	}
	break;
      case text_nobraces: 
	{
	  std::string oldline = line;
	  if (Nold==0) { // read until stream ends
	    while( stream.getline(line,LINESZ) ){
	      Nlines++;
	      strmline.clear();
	      strmline.str(line);
	      char c;
	      size_type Nchars=0;
	      while(strmline.get(c)){
		Nchars++;
		if (isspace(c))
		  continue;
		if (c=='%')
		  break; // ignore rest of line "%" signifies a comment
		
		strmline.putback(c);
		if (strmline>>temp){
		  v.push_back(temp);
		  N++;
		} else { 
		  std::string extrastr ="";
		  if ( (c=='{') || (c=='}')||(c==','))
		    extrastr = "Braces and commas are not allowed in 'text_nobraces' mode";
		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
		  return stream;
		}
	      }
	    }
	    x.resize(N);
	  } else { // just read in N elements and stop
	    while( (N<Nold) && stream.getline(line,LINESZ) ){
	      Nlines++;
	      strmline.clear();
	      strmline.str(line);
	      char c;
	      size_type Nchars=0;
	      while((N<Nold) && strmline.get(c) ){
		Nchars++;
		std::string stemp = strmline.str();
		if (isspace(c))
		  continue;
		if (c=='%')
		  break; // ignore rest of line "%" signifies a comment
		
		strmline.putback(c);
		if (strmline>>temp){
		  v.push_back(temp);
		  N++;
		} else { 
		  std::string extrastr ="";
		  if ( (c=='{') || (c=='}')||(c==','))
		    extrastr = "Braces and commas are not allowed in 'text_nobraces' mode";
		  vsyntax_error(x.name(),line,N,Nold,Nlines,Nchars,c,extrastr,x.textformat());
		  return stream;
		}
	      }
	      oldline = line;
	    }
	    if (N != Nold) {
	      vinput_stream_size_too_small(x.name(),oldline,N,Nold);
	      return stream;
	    }
	  }
	}
	break;
      default:
	bug_report(__FILE__,__LINE__);
	break;
      } //switch

      for(size_type i=0; i<N; i++)
	x[i] = v[i];
      
      return restore_stream(stream,strmline);
  
    }

    // --------------------- FRIENDS ---------------------



    

  };






};


#endif 

