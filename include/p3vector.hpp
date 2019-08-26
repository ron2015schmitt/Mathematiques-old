
#ifndef P3VECTOR_H
#define P3VECTOR_H


#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <vector>

namespace matricks {

  class p3vectorformat {
  private:
    static TextFormat textformat_;
    static size_type width_;  
  public:
    static TextFormat textformat(void);
    static TextFormat textformat(const TextFormat newformat);
    static size_type width(void);
    static size_type width(const size_type newwidth);

  };



  /*************************************************************************
   * p3vector -- Physical 3 vector (1st rank tensor in 3D)
   ************************************************************************* 
   */

  template <class D>
  class p3vector : public VorE<D,p3vector<D> > {
  private:
    D data_[3];
  public:

    // ************************** CONSTRUCTORS *****************************

    explicit p3vector(const std::string name = "") {
    };
    explicit p3vector(const D c) {
      data_[0]=c;
      data_[1]=c;
      data_[2]=c;
    }
    explicit p3vector(const D *array) {
      data_[0]=array[0];
      data_[1]=array[1];
      data_[2]=array[2];
    }

    explicit p3vector(const D x, const D y, const D z ) {
      data_[0]=x;
      data_[1]=y;
      data_[2]=z;
    }
    p3vector(const p3vector& v2, const std::string name = "") {
      *this = v2;
    }
    template <class A>
    p3vector(const Vexpr<D,A>& x, const std::string name = "") {
      *this = x;
    }

    // **************************** DESTRUCTOR ******************************** 
    ~p3vector(void) {
    }


    // ************************* ELEMENT ACCESS *************************
    p3vector& data(const D x, const D y, const D z ) {
      data_[0]=x;
      data_[1]=y;
      data_[2]=z;
      return *this;
    }
    inline  D x(const D xnew) {
      data_[0]=xnew;
      return xnew;
    }
    inline  D y(const D ynew) {
      data_[1]=ynew;
      return ynew;
    }
    inline  D z(const D znew) {
      data_[2]=znew;
      return znew;
    }
    inline const D x(void) const {
      return(data_[0]);
    }
    inline const  D y(void) const {
      return(data_[1]);
    }
    inline const D z(void) const {
      return(data_[2]);
    }
    inline  D& x(void)  {
      return(data_[0]);
    }
    inline   D& y(void) {
      return(data_[1]);
    }
    inline  D& z(void)  {
      return(data_[2]);
    }
    inline  const D operator[](const index_type i)const  {
#if MATRICKS_DEBUG>0
      if ((i<0) || (i>2)) {
	std::cerr << "SOFTWARE ERROR: index to p3vector out of bounds: i=" << i << ", &v=" <<this << ", v[]=" << *this << std::endl;
	return D();
      }
#endif
      return data_[i];
    }

    inline  D &operator[](const index_type i) {
#if MATRICKS_DEBUG>0
      if ((i<0) || (i>2)) {
	std::cerr << "SOFTWARE ERROR: index to p3vector out of bounds: i=" << i << ", &v=" <<this << ", v[]=" << *this << std::endl;
	return data_[0];
      }
#endif
      return data_[i];
    }




    // ************************** ATTRIBUTE ACCESS ************************
    inline VETypes vetype(void) const {
      return VE_p3vector;
    }

    bool mustcopy(const void *vaddr) const {
      return false;
    }

    bool addrmatch(const void *vaddr) const {
      return vaddr==static_cast<const void*>(this);
    }

    inline size_type size(void) const {
      return 3;
    }

    size_type objectID(void) const { 
      return 0;
    }


    // ******************** ASSIGNMENT OPERATORS *******************

    // Assign all elements to the same constant value
    p3vector<D>& equals(const D d) { 
      for(index_type i=size(); i--;) 
	data_[i]=d; 
      return *this;
    }
    p3vector<D>& operator=(const D d) { 
      return equals(d);
    }


    // Assignment to a vector expression
    template <class A>  p3vector<D>& equals(const Vexpr<D,A>& x) {  
      if (x.mustcopy(this)) {    
	p3vector<D> vtemp;
	vtemp[0] = x[0];  
	vtemp[1] = x[1];  
	vtemp[2] = x[2];  
	data_[0] = vtemp[0];
	data_[1] = vtemp[1];
	data_[2] = vtemp[2];
      } else {
	data_[0] = x[0]; 
	data_[1] = x[1]; 
	data_[2] = x[2]; 
      }
      return *this; 
    }
    template <class A>  p3vector<D>& operator=(const Vexpr<D,A>& x) {  
      return equals(x);
    }


    // Copy asignment
    p3vector<D>& equals(const p3vector<D>& v2) {
      data_[0] = v2[0]; 
      data_[1] = v2[1]; 
      data_[2] = v2[2]; 
      return *this;
    }
    p3vector<D>& operator=(const p3vector<D>& v2) {
      return equals(v2);
    }


    // ******************************* TEXT STUFF ************************
    static std::string classname(void)  {
      return "p3vector";
    }

    static std::string fullclassname(void) {
      p3vector<D> dummy;
      return getTypeString(dummy);
    }

    std::string debugtxt(void) const {
      return std::string();
    }

    void debugtxt(const char* newname) const {
    }

    void debugtxt(const std::string newname) const {
    }

    std::string name(void) const {
      return "(p3vector)";
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
    }



    inline friend std::ostream &operator<<(std::ostream &stream, const p3vector v) {
      const size_type w = p3vectorformat::width();
      std::string sep ="";
      switch (p3vectorformat::textformat()) {
      case text_braces:
	stream << "{";
	stream << std::setw(w)<<v[0] << ",";
	stream <<  std::setw(w)<< v[1] << ",";
	stream <<  std::setw(w)<< v[2] << "}";
	break;
      case text_nobraces:
	if (w==0)
	  sep = " ";
	else
	  sep="";
	stream << std::setw(w)<<v[0] << sep;
	stream <<  std::setw(w)<< v[1] << sep;
	stream <<  std::setw(w)<< v[2] <<sep;
	break;
      default:
	break;
      }
      return stream;
    }


    //template <class D>	
    friend inline std::istream& operator>>(const std::string s,  p3vector<D>& x) {	
      std::istringstream st(s);
      return (st >> x);
    }



    // stream >> operator

    friend std::istream& operator>>(std::istream& stream,  p3vector& x) {	
      const size_type LINESZ = 32768;
      char line[LINESZ];
      std::vector<D> v;
      size_type N = 0;
      D temp;
      size_type Nlines = 0;
      std::istringstream strmline;

      switch (p3vectorformat::textformat()) {
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
		  vsyntax_error(x.name(),line,N,3,Nlines,Nchars,c,extrastr,p3vectorformat::textformat());
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
		  vsyntax_error(x.name(),line,N,3,Nlines,Nchars,c,extrastr,p3vectorformat::textformat());
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
		  vsyntax_error(x.name(),line,N,3,Nlines,Nchars,c,extrastr,p3vectorformat::textformat());
		  return stream;
		}
		break;
	      case end:
		{
		  std::string extrastr = "Expecting a closing brace.";
		  vsyntax_error(x.name(),line,N,3,Nlines,Nchars,c,extrastr,p3vectorformat::textformat());
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
	  if (N != 3) {
	    vbad_input_stream_size(x.name(),line,N,3);
	    return stream;
	  }
	}
	break;
      case text_nobraces: 
	{
	  std::string oldline = line;
	  while( (N<3) && stream.getline(line,LINESZ) ){
	    Nlines++;
	    strmline.clear();
	    strmline.str(line);
	    char c;
	    size_type Nchars=0;
	    while((N<3) && strmline.get(c) ){
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
		vsyntax_error(x.name(),line,N,3,Nlines,Nchars,c,extrastr,p3vectorformat::textformat());
		return stream;
	      }
	    }
	    oldline = line;
	  }
	  if (N != 3) {
	    vinput_stream_size_too_small(x.name(),oldline,N,3);
	    return stream;
	  }
	}
	
	break;
      default:
	bug_report(__FILE__,__LINE__);
	break;
      } //switch

      for(index_type i=0; i<N; i++)
	x[i] = v[i];
      
      return restore_stream(stream,strmline);
  
    }
  



  };  //class p3vector






  // **************** FUNCTIONS ***********************

  // Vector cross product 
  // w = x cross y

  template <class D>
  inline p3vector<D> cross(const p3vector<D> A, const p3vector<D> B) {
    p3vector<D> C;
    C[0] = A.y()*B.z() - A.z()*B.y();
    C[1] = A.z()*B.x() - A.x()*B.z();
    C[2] = A.x()*B.y() - A.y()*B.x();
    return(C);
  }



  // Dot product
  // a = x dot y

  template <class D>
  inline D dot(const p3vector<D> A, const p3vector<D> B) {
    D c;
    c = A.x()*B.x() + A.y()*B.y() + A.z()*B.z();
    return(c);
  }



  // Norm
  //
  template <class D>
  inline D norm(const p3vector<D> A) {
    D q;
    q = dot(A,A);
    return std::sqrt(q);
  }
  // Normsqr
  //
  template <class D>
  inline D normsqr(const p3vector<D> A) {
    D q;
    q = dot(A,A);
    return q;
  }


  // Norm
  //
  template <class D>
  inline D norm(const p3vector<std::complex<D> > A) {
    D q;
    p3vector<std::complex<D> > Ac = conj(A);
    q = real(dot(Ac,A));
    return std::sqrt(q);
  }
  // Normsqr
  //
  template <class D>
  inline D normsqr(const p3vector<std::complex<D> > A) {
    D q;
    p3vector<std::complex<D> > Ac = conj(A);
    q = real(dot(Ac,A));
    return q;
  }










}; //namespcae matricks


#endif // p3vector_H
