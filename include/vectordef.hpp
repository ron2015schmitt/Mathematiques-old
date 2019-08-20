#ifndef VECTORDEF_H
#define VECTORDEF_H 1

#include <typeinfo>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <complex>
#include <valarray>
#include <vector>
#include <list>
#include <iterator>
#include <string>

#if CPP11 == 1
#include <initializer_list>
#endif


//#define VDEBUG

namespace matricks {

  template <class D> void sort(Vector<D>& a );

  
  /****************************************************************************
   * Vector -- mathematical vector class.
   ****************************************************************************   
   */

  template <class D> class Vector : public VorE<D,Vector<D> >, VectorofPtrs {
  private:

    // *********************** OBJECT DATA ***********************************
    size_type objectID_;
    size_type perline_;
    size_type width_;   // for display  (std::setw uses int as its size)
    TextFormat textformat_;
    std::valarray<D>* data_;
#ifdef MATRICKS_DEBUG
    D dummy_;
#else
    mutable std::string name_;
#endif

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

      addAddress(this);
      
#ifdef MATRICKS_DEBUG
      dummy_ = D();
      // add this vector to the directory
      objectID_ = matricksObjectPool::addvector("", classname(), datatype(), size());
#endif      
    }







    //**********************************************************************
    //************************** DESTRUCTOR ******************************
    //**********************************************************************

    ~Vector<D>() {
      delete  data_ ;

      //remove from directory
#ifdef MATRICKS_DEBUG
      matricksObjectPool::removevector(objectID_);
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
#ifdef MATRICKS_DEBUG
      // update the directory
      matricksObjectPool::vchange_size(objectID_,N);
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
      index_type index;
      if (i < 0) {
	index = size() + i;
      } else {
	index = i;
      }
#ifdef MATRICKS_DEBUG
      if (index>=size()) {
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




    // Accessing a sequence of values
    
    VSliceObj<D>  operator[](const seq& i)  { 
      return VSliceObj<D>(*this,i.start(),i.end(),i.step());
    }
    const VSliceObj<D>  operator[](const seq& i) const  { 
      return VSliceObj<D>(*this,i.start(),i.end(),i.step());
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
#ifdef MATRICKS_DEBUG
      if (size()!=mask.size()) {
	vbad_mask(objectID_,mask);
      }
#endif    
      return  VSubMaskObj<D>(*this,mask);
    }
    const VSubMaskObj<D> operator[](const Vector<bool>& mask)  const {
#ifdef MATRICKS_DEBUG
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

    // Any new assignment operators should also be addedc to VWrapperObj for consistency.
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
#ifdef MATRICKS_DEBUG
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

      if (x.mustcopy(this)) {    
#ifdef MATRICKS_DEBUG
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




    // assignment to an array
    Vector<D>& equals(const D array[]) {
      
#ifdef MATRICKS_DEBUG
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

#ifdef MATRICKS_DEBUG
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

#ifdef MATRICKS_DEBUG
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
#ifdef MATRICKS_DEBUG
      vbad_reconassignment(objectID(), b);
#endif
      return *this;
    }


    Vector<D>& equals(const std::list<D> mylist) {
      
#ifdef MATRICKS_DEBUG
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
      
#ifdef MATRICKS_DEBUG
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
      
#ifdef MATRICKS_DEBUG
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
      
#ifdef MATRICKS_DEBUG
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
      
#ifdef MATRICKS_DEBUG
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

    // move to here
    friend  void sort<>(Vector<D>& a );


    
    //**********************************************************************
    //************************** FOR DELETION **************************************
    //**********************************************************************

    #pragma GCC diagnostic ignored "-Wunused-parameter"
    bool mustcopy(const void *vaddr) const {
      return false;
    }

    bool addrmatch(const void *vaddr) const {
      return vaddr==static_cast<const void*>(this);
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
      return "Vector";
    }

    static std::string fullclassname(void) {
      Vector<D> dummy;
      return make_type_string(dummy);
    }

    std::string debugtxt(void) const {
#ifdef MATRICKS_DEBUG
      return matricksObjectPool::vectorname(objectID_); 
#else
      return name_;
#endif
    }

    void debugtxt(const char* newname) const {
      std::string s = newname;
#ifdef MATRICKS_DEBUG
      matricksObjectPool::vchange_name(objectID_,s); 
#else
      name_=s;
#endif
    }

    void debugtxt(const std::string newname) const {
#ifdef MATRICKS_DEBUG
      matricksObjectPool::vchange_name(objectID_,newname); 
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
      return make_type_string(dummy);
    }

    void outputglossary(void) const {
#ifdef MATRICKS_DEBUG
      matricksObjectPool::voutputglossary(objectID_);
#endif
    }

    // stream << operator

    friend std::ostream& operator<<(std::ostream &stream, const Vector<D>& v) {

      const size_type N = v.size();
      const size_type w = v.width();

      switch (v.textformat()) {
      case text_braces:
	stream <<"{";
	for(size_type i=0; i < N; i++) {
	  if ( (i>0) && ((i%v.perline()) == 0 ) )
	    stream <<std::endl << " ";
	  stream <<std::setw(w)<< v[i];
	  if (i< (N-1))
	    stream << ",";
	}
	stream << "}";
	break;
      case text_nobraces:
	std::string sep;
	if (v.width()==0)
	  sep = " ";
	else
	  sep="";
	for(size_type i=0; i < N; i++) {
	  if ( (i>0) && ((i%v.perline()) == 0 ) )
	    stream <<std::endl;
	  stream <<std::setw(w)<< v[i] << sep;
	}
	break;
      }
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






  












  // The Range generating function (with step given)

  template <class D>
  inline Vector<D> range(D start, D end, D step) {
    // determine size
    size_type N = 0;
    if (step > 0) {
      for (D x =start; x<=end; x +=step)
	N +=1;
    } else {
      for (D x =start; x>=end; x +=step) 
	N +=1;
    }
#ifdef MATRICKS_DEBUG
    std::ostringstream stream;
    stream << "range(" <<start<<","<<end<<","<<step<<")";
    //    Vector<D> y(N,stream.str());
    Vector<D> y(N);
    if ( N==0 ){ 
      vbadrange<D>(start,end,step);
      return y;
    }
#else
    Vector<D> y(N);
#endif
    
    y[0] = start;
    for (size_type i =1; i<N; i++)
      y[i] = y[i-1] + step;
    
    return y;
  }


  // The Range generating function (step by +/-1)

  template <class D>
  inline Vector<D> range(D start, D end) {
    if (end >= start)
      return range<D>(start,end,static_cast<D>(1));
    else 
      return range<D>(start,end,static_cast<D>(-1));
  }





  // linspace function

  template <class D, typename = typename std::enable_if<std::is_arithmetic<D>::value, D>::type>
  inline Vector<D> linspace(D start, D end, size_type N) {
#ifdef MATRICKS_DEBUG
    std::ostringstream stream;
    stream << "linspace(" <<start<<","<<end<<","<<N<<")";
    std::string s = stream.str();
    //    Vector<D> y(N,s);
    Vector<D> y(N);
#else
    Vector<D> y(N);
#endif

#ifdef MATRICKS_DEBUG
    if (N<2) {
      vbadlinspace<D>(start,end,N);
      return y;
    } 
#endif

    const D step = (end-start)/static_cast<D>(N-1);

    y[0] = start;
    for(size_type i = 1; i<(N-1); i++) 
      y[i] = start + static_cast<D>(i)*step;
    y[N-1] = end;
    return y;


  }









};


#endif 
