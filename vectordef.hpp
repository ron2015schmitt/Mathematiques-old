// START-OF-NOTICE
// Copyright 2003, Columbia University
// Authors: Ron Schmitt
//
//
// This file is part of the Columbia Object Oriented 
// Linear-algebra Library (COOLL).
//
// You should have received a copy of the License Agreement for the
// COOLL along with the software;  see the file LICENSE.  
// If not, contact
// Department of Applied Physics and Applied Mathematics
// Columbia Univeristy 
// New York, NY 10027
//
// Permission to modify the code and to distribute modified code is
// granted, provided the text of this NOTICE is retained, a notice that
// the code was modified is included with the above COPYRIGHT NOTICE and
// with the COPYRIGHT NOTICE in the LICENSE file, and that the LICENSE
// file is distributed with the modified code.
//
// LICENSOR MAKES NO REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED.
// By way of example, but not limitation, Licensor MAKES NO
// REPRESENTATIONS OR WARRANTIES OF MERCHANTABILITY OR FITNESS FOR ANY
// PARTICULAR PURPOSE OR THAT THE USE OF THE LICENSED SOFTWARE COMPONENTS
// OR DOCUMENTATION WILL NOT INFRINGE ANY PATENTS, COPYRIGHTS, TRADEMARKS
// OR OTHER RIGHTS.
//
// END-OF-NOTICE
//===========================================================================


#ifndef VECTORDEF_H
#define VECTORDEF_H 1

#include <typeinfo>
#include <iostream>
#include <sstream>
#include <complex>
#include <valarray>
#include <vector>
#include <string>





namespace COOLL {

  template <class D> void sort(LAvector<D>& a );

  /****************************************************************************
   * LAvector -- mathematical vector class.
   ****************************************************************************   
   */

  template <class D> class LAvector : public VorE<D,LAvector<D> > {
  private:
    // *********************** OBJECT DATA ***********************************
    int objectID_;
    unsigned int perline_;
    unsigned int width_;   // for display
    TextFormat textformat_;
    std::valarray<D>* data_;
#ifdef COOLL_CAREFUL
    D dummy_;
#else
    mutable std::string name_;
#endif

  public:     

    typedef D element_type;
    typedef typename RealVersionOfType<D>::Type DREAL;


    // ************************** CONSTRUCTOR **********************************

    explicit LAvector<D>(const unsigned int n, const std::string name = "") { 

      unsigned int N;
      if (n>maxsize) 
	N=0;
      else 
	N=n;

      // allocate store
      data_ = new std::valarray<D>(N); 

      perline_ = N+1;
      width_ = 0;
      textformat_=text_braces;

#ifdef COOLL_CAREFUL
      dummy_ = D();
      // add this vector to the directory
      objectID_ = CoollDirectory::addvector(name, classname(), datatype(), size());

      if (n>maxsize) 
	vbad_size(objectID_, n);
#else
      name_=name;
#endif      
    }

    // *******************  DEFAULT  CONSTRUCTOR **********************************

    explicit LAvector<D>(const std::string name = "") { 
      
      unsigned int n=0;

      unsigned int N;
      if (n>maxsize) 
	N=0;
      else 
	N=n;

      // allocate store
      data_ = new std::valarray<D>(N); 

      perline_ = N+1;
      width_ = 0;
      textformat_=text_braces;

#ifdef COOLL_CAREFUL
      dummy_ = D();
      // add this vector to the directory
      objectID_ = CoollDirectory::addvector(name, classname(), datatype(), size());

      if (n>maxsize) 
	vbad_size(objectID_, n);
#else
      name_=name;
#endif      
    }

    // ************************** CONSTANT INIT CONSTRUCTOR **********************************

    explicit LAvector<D>(const unsigned int n, const D val, const std::string name="") { 
      
      unsigned int N;
      if (n>maxsize) 
	N=0;
      else 
	N=n;
      
      // allocate store
      data_ = new std::valarray<D>(N); 
      
      perline_ = N+1;
      width_ = 0;
      textformat_=text_braces;
      
#ifdef COOLL_CAREFUL
      dummy_ = D();
      // add this vector to the directory
      objectID_ = CoollDirectory::addvector(name, classname(), datatype(), size());
      
      if (n>maxsize) 
	vbad_size(objectID_, n);
#else
      name_=name;
#endif      

      
      *this = val;

    }
    

    // ************************** COPY CONSTRUCTOR *******************************

    LAvector<D>(const LAvector<D>& v2, const std::string name = "") {
      const unsigned int n = v2.size();
      unsigned int N;
      if (n>maxsize) 
	N=0;
      else 
	N=n;

      // allocate store
      data_ = new std::valarray<D>(N); 

      perline_ = v2.perline();
      width_ = v2.width();
      textformat_= v2.textformat();
      
#ifdef COOLL_CAREFUL
      dummy_ = D();
      std::string name2 = name;
      if (name == "") {
	name2 = "("+v2.debugtxt()+")";
	objectID_ = CoollDirectory::addvector(name2, classname(), datatype(), size(), false);
      }else {
	objectID_ = CoollDirectory::addvector(name2, classname(), datatype(), size());
      }
      if (n>maxsize) 
	vbad_size(objectID_, n);
#else
      name_=name;
#endif      

      *this = v2;
      
    }


    // ************************** EXPRESSION CONSTRUCTOR *******************************


    template <class A>
    LAvector<D>(const Vexpr<D,A>& x, const std::string name = "") {
      const unsigned int n = x.size();
      unsigned int N;
      if (n>maxsize) 
	N=0;
      else 
	N=n;

      data_ = new std::valarray<D>(N); 

      perline_ = N+1;
      width_ = 0;
      textformat_=text_braces;
      
#ifdef COOLL_CAREFUL
      dummy_ = D();
      std::string name2 = name;
      if (name == "") {
	name2 = x.debugtxt();
	objectID_ = CoollDirectory::addvector(name2, classname(), datatype(), size(), false);
      }else {
	objectID_ = CoollDirectory::addvector(name2, classname(), datatype(), size());
      }

      if (n>maxsize) 
	vbad_size(objectID_, n);
#else
      name_=name;
#endif      

      *this = x;
      
    }



    // **************************** DESTRUCTOR **********************************
    ~LAvector<D>() {
      delete  data_ ;

      //remove from directory
#ifdef COOLL_CAREFUL
      CoollDirectory::removevector(objectID_);
#endif
    }
  

    // ******************** RESIZE ********************************

    // These allow the user to resize a vector


    // *** this is used for recon by assignment ***

    VReconObj<D>  resize(void) { 
      return  VReconObj<D>(*this);
    }

    // *** resize from given integer *** 

    LAvector<D>&  resize(const unsigned int n) { 
      if (n==this->size())
	return *this;
      unsigned int N;
      if (n>maxsize) 
	N=0;
      else 
	N=n;
      // reallocate store
      delete  data_ ;
      data_ = new std::valarray<D>(N); 
      perline_ = N+1;
      width_ = 0;
#ifdef COOLL_CAREFUL
      // update the directory
      CoollDirectory::vchange_size(objectID_,N);
      if (n>maxsize) 
	vbad_size(objectID_, n);
#endif      
      return *this;
    }

    LAvector<D>&  clear(void) { 
      return resize(0);
    }


    // ************************* ELEMENT ACCESS *********************************

    // "read/write" access
    inline D& operator[](const unsigned int i)  {

#ifdef COOLL_CAREFUL
      if (i>=size()) {
	vout_of_bounds(objectID_,i);
	return dummy_; 
      }
#endif    

      return (*data_)[i]; 
    }


    // "read only" access
    inline const D operator[](const unsigned int i) const {

#ifdef COOLL_CAREFUL
      if (i>=size())  {
	vout_of_bounds(objectID_,i);
	return D(); 
      }
#endif    

      return (*data_)[i]; 
    }



    // Accessing a sequence of values
    
    inline  VRangeObj<D>  operator[](const seq& i)  { 
      return VRangeObj<D>(*this,i.start(),i.end(),i.step());
    }
    inline  const VRangeObj<D>  operator[](const seq& i) const  { 
      return VRangeObj<D>(*this,i.start(),i.end(),i.step());
    }
    



    // Accessing a SET of values 

    const VSetObj<D> operator[](const LAvector<unsigned int>& ii) const {
      return VSetObj<D>(*this, ii);
    }
    VSetObj<D> operator[](const LAvector<unsigned int>& ii) {
      return VSetObj<D>(*this, ii);
    }


    // Accessing a SET of values using a MASK
    
    VMaskObj<D> operator[](const LAvector<bool>& mask)  {
#ifdef COOLL_CAREFUL
      if (size()!=mask.size()) {
	vbad_mask(objectID_,mask);
      }
#endif    
      return  VMaskObj<D>(*this,mask);
    }
    const VMaskObj<D> operator[](const LAvector<bool>& mask)  const {
#ifdef COOLL_CAREFUL
      if (size()!=mask.size()) {
	vbad_mask(objectID_,mask);
      }
#endif    
      return  VMaskObj<D>(*this,mask);
    }




    // ************************** ATTRIBUTE ACCESS ********************************

    inline unsigned int size(void) const {
      return data_->size();
    }

    unsigned int objectID(void) const { 
      return objectID_;
    }

    unsigned int perline(const unsigned int Nline)  { 
      return (perline_=Nline);
    }
    const unsigned int perline(void)  const { 
      return perline_;
    }

    unsigned int width(const unsigned int w)  { 
      return (width_=w);
    }
    const unsigned int width(void)  const { 
      return width_;
    }


    inline VETypes vetype(void) const {
      return VE_LAvector;
    }

    bool mustcopy(const void *vaddr) const {
      return false;
    }

    bool addrmatch(const void *vaddr) const {
      return vaddr==static_cast<const void*>(this);
    }

    TextFormat textformat(void) const {
      return textformat_;
    }

    TextFormat textformat(TextFormat newformat) {
      return textformat_ = newformat;
    }


    // ******************** ASSIGNMENT OPERATORS ********************************

    // Any new assignment operators should also be addedc to VWrapperObj for consistency.
    // For this reason, in most cases, its preferred to overload the function vcast()
    // equals functions are included so that derived classes can call these functions

    // Assign all elements to the same constant value
    LAvector<D>& equals(const D d) { 
      for(int i=size(); i--;) 
	(*data_)[i]=d; 
      return *this;
    }
    LAvector<D>& operator=(const D d) { 
      return equals(d);
    }


    // Assignment to a vector expression
    template <class A>  LAvector<D>& equals(const Vexpr<D,A>& x) {  
#ifdef COOLL_CAREFUL
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
#ifdef COOLL_CAREFUL
	LAvector<D> vtemp(size(),x.debugtxt());
#else
	LAvector<D> vtemp(size());
#endif
	for (register int i = size(); i--;)
	  vtemp[i] = x[i];   // Inlined expression
	for (register int i = size(); i--;)
	  (*data_)[i] = vtemp[i];
      } else {
	for (register int i = size(); i--;)
	  (*data_)[i] = x[i];   // Inlined expression
      }
      return *this; 
    }
    template <class A>  LAvector<D>& operator=(const Vexpr<D,A>& x) {  
      return equals(x);
    }



    // Copy asignment
    LAvector<D>& equals(const LAvector<D>& v2) {

#ifdef COOLL_CAREFUL
      if ( (size()>0) && ( size() !=  v2.size() ) ){ 
	vbad_assignment_warning(objectID(),v2.objectID());
      } else if (size() !=  v2.size() ){
	  // if size=0, just silently resize this vector
	//	vbad_assignment_warning(objectID(),v2.objectID());
      }
 
#endif
      // resize to avoid segmentation faults
      resize(v2.size());

      for(register unsigned int i=size(); i--;)
	(*data_)[i] = v2[i];    
      return *this;
    }
    LAvector<D>& operator=(const LAvector<D>& v2) {
      return equals(v2);
    }



    // assignment to matrix or submatrix
    // one of the two dimensions must have single element width
    template <class A>
    LAvector<D>& operator=(const MorE<D,A>& m) {

#ifdef COOLL_CAREFUL
      const unsigned int NR = m.Nrows();
      const unsigned int NC = m.Ncols();
      if ( size() !=  m.size() ){ 
	vbad_assignment_mat(objectID(),NR,NC);
	return *this;
      }
      if ((NR!=1) && (NC!=1)) { 
	vbad_assignment_mat(objectID(),NR,NC);
	return *this;
      }
#endif
      for(register unsigned int i=size(); i--;)
	(*data_)[i] = m(i);    
      return *this;
    }



    template <class B>
    LAvector<D>& operator=(const VReconObj<D>& b) { 
#ifdef COOLL_CAREFUL
      vbad_reconassignment(a_.objectID(), b);
#endif
      return *this;
    }


    // ******************************* TEXT STUFF *******************************


    static std::string classname(void)  {
      return "LAvector";
    }

    static std::string fullclassname(void) {
      LAvector<D> dummy;
      return make_type_string(dummy);
    }

    std::string debugtxt(void) const {
#ifdef COOLL_CAREFUL
      return CoollDirectory::vectorname(objectID_); 
#else
      return name_;
#endif
    }

    void debugtxt(const char* newname) const {
      std::string s = newname;
#ifdef COOLL_CAREFUL
      CoollDirectory::vchange_name(objectID_,s); 
#else
      name_=s;
#endif
    }

    void debugtxt(const std::string newname) const {
#ifdef COOLL_CAREFUL
      CoollDirectory::vchange_name(objectID_,newname); 
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
#ifdef COOLL_CAREFUL
      CoollDirectory::voutputglossary(objectID_);
#endif
    }

    // stream << operator

    friend std::ostream& operator<<(std::ostream &stream, const LAvector<D>& v) {

      const unsigned int N = v.size();
      const unsigned int w = v.width();

      switch (v.textformat()) {
      case text_braces:
	stream <<"{";
	for(unsigned int i=0; i < N; i++) {
	  if ( (i>0) && ((i%v.perline()) == 0 ) )
	    stream <<std::endl << " ";
	  stream <<setw(w)<< v[i];
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
	for(unsigned int i=0; i < N; i++) {
	  if ( (i>0) && ((i%v.perline()) == 0 ) )
	    stream <<std::endl;
	  stream <<setw(w)<< v[i] << sep;
	}
	break;
      }
      return stream;
    }


    //template <class D>	
    friend inline std::istream& operator>>(const std::string s,  LAvector<D>& x) {	
      std::istringstream st(s);
return (st >> x);
    }


    // stream >> operator

    friend std::istream& operator>>(std::istream& stream,  LAvector<D>& x) {	
      const unsigned int LINESZ = 32768;
      char line[LINESZ];
      std::vector<D> v;
      unsigned int N = 0;
      const unsigned int Nold = x.size();
      D temp;
      unsigned int Nlines = 0;
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
	    unsigned int Nchars=0;
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
	      unsigned int Nchars=0;
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
	      unsigned int Nchars=0;
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

      for(unsigned int i=0; i<N; i++)
	x[i] = v[i];
      
      return restore_stream(stream,strmline);
  
    }

    // ******************** FRIENDS ********************************

    friend  void sort<>(LAvector<D>& a );



    

  };








  














  // The Range generating function (step by +/-1)

  template <class D>
  inline LAvector<D> range(D start, D end) {
    if (end >= start)
      return range<D>(start,end,static_cast<D>(1));
    else 
      return range<D>(start,end,static_cast<D>(-1));
  }

  // The Range generating function (with step given)

  template <class D>
  inline LAvector<D> range(D start, D end, D step) {
    // determine size
    unsigned int N = 0;
    if (step > 0) {
      for (D x =start; x<=end; x +=step)
	N +=1;
    } else {
      for (D x =start; x>=end; x +=step) 
	N +=1;
    }
#ifdef COOLL_CAREFUL
    std::ostringstream stream;
    stream << "range(" <<start<<","<<end<<","<<step<<")";
    LAvector<D> y(N,stream.str());
    if ( N==0 ){ 
      vbadrange<D>(start,end,step);
      return y;
    }
#else
    LAvector<D> y(N);
#endif
    
    y[0] = start;
    for (unsigned int i =1; i<N; i++)
      y[i] = y[i-1] + step;
    
    return y;
  }




  // linspace function

  template <class D>
  inline LAvector<D> linspace(D start, D end, unsigned int N) {
#ifdef COOLL_CAREFUL
    std::ostringstream stream;
    stream << "linspace(" <<start<<","<<end<<","<<N<<")";
    std::string s = stream.str();
    LAvector<D> y(N,s);
#else
    LAvector<D> y(N);
#endif

    // checking, ala make_string type and give error here if not: float, double or extended
#ifdef COOLL_CAREFUL
    if (N<2) {
      vbadlinspace<D>(start,end,N);
      return y;
    } 
#endif

    const D step = (end-start)/static_cast<D>(N-1);

    y[0] = start;
    for(unsigned int i = 1; i<(N-1); i++) 
      y[i] = start + static_cast<D>(i)*step;
    y[N-1] = end;
    return y;


  }









};


#endif 
