
#ifndef MVEXPR_H
#define MVEXPR_H 

#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>


namespace matricks {

  template <class A> 
  inline Matrix<index_type> findtrue( const MorE<bool,A>& a );

  template <class A> 
  inline Vector<index_type> findtruesi( const MorE<bool,A>& a );


  /****************************************************************************
   * Mexpr -- Matrix Expression template abstract class
   ****************************************************************************
   */
  template<class D, class EXP> 
  class Mexpr : public MorE<D,Mexpr<D,EXP> > {
  private:
    typedef  D DataT;
    inline EXP& derived() {
      return static_cast<EXP&>(*this);
    }
    inline const  EXP& derived() const {
      return static_cast<const EXP&>(*this);
    }

  public:

    inline const D operator()(const index_type i) const {
      return derived()(i);
    }

    inline const D operator()(const index_type r, const index_type c) const {
      return r*Ncols() + c;
    }


    inline size_type Nrows(void) const {
      return derived().Nrows();
    }
    
    inline size_type Ncols(void) const {
      return derived().Ncols();
    }

    inline size_type size(void) const {
      return derived().size();
    }

    inline METypes metype(void) const {
      return derived().metype();
    }


    std::string debugtxt(void) const {
      return derived().debugtxt();
    }

    void outputglossary(void) const {
      derived().outputglossary();
    }


    bool mustcopy(const void* maddr) const {
      return derived().mustcopy(maddr);
    }

    bool addrmatch(const void *maddr) const {
      return derived().addrmatch(maddr);
    }



  };










  /****************************************************************************
   * VWrapperObj Expression Template 
   *
   * abstract class 
   ****************************************************************************
   */
  template <class D, class DERIVED>
  class MWrapperObj : public  Mexpr<D,MWrapperObj<D,DERIVED> > {
  private:
    inline DERIVED& derived() {
      return static_cast<DERIVED&>(*this);
    }
    inline const  DERIVED& derived() const {
      return static_cast<const DERIVED&>(*this);
    }

  public:

    inline const D operator()(const index_type i) const {  
      const index_type index = derived().index(i);
      return derived().data(index);
    }

    inline D& operator()(const index_type i) {  
      const index_type index = derived().index(i);
      return derived().data(index);
    }

    inline index_type index(void) const {
      return derived().index();
    }

    inline size_type size(void) const {
      return derived().size();
    }

    inline size_type Nrows(void) const {
      return derived().Nrows();
    }

    inline size_type Ncols(void) const {
      return  derived().Ncols();
    }

    inline size_type asize(void) const {
      return derived().asize();
    }
    inline size_type aID(void) const {
      return derived().aID();
    }

    inline size_type aNrows(void) const {
      return derived().aNrows();
    }

    inline size_type aNcols(void) const {
      return  derived().aNcols();
    }



    inline METypes metype(void) const {
      return derived().metype();
    }


    // Assign to constant value
    DERIVED& equals(const D d) { 
      for(index_type i=0; i<size(); i++) 
	(*this)(i)=d; 
      return derived();
    }

    // assign to recon object (issue error)
    DERIVED& equals(const MReconObj<D>& b) { 
#ifdef MATRICKS_DEBUG
      mbad_reconassignment(derived().objectID(), b);
#endif
      return derived();
    }


    //assign to vector(expression)
    
    template <class B>
    DERIVED& equals(const VorE<D,B>& rhs) { 
      
      const size_type N =size();

#ifdef MATRICKS_DEBUG
      const size_type NR = Nrows();
      const size_type NC = Ncols();
      if ( ( N !=  rhs.size() ) 
	   || ( (NR!=1) && (NC!=1) ) ){ 
	mbad_wrapper_assignment_vec(derived().debugtxt(),rhs.debugtxt());
	derived().outputglossary();
	rhs.outputglossary();
	return derived();
      }
#endif

      if ( rhs.addrmatch(derived().addr()) ) {    
#ifdef MATRICKS_DEBUG
	Vector<D> y(N,debugtxt());
#else
	Vector<D> y(N);
#endif
	for(register index_type i=0; i<N; i++) 
	  y[i] = rhs[i]; 
	for(register index_type i=0; i<N; i++) 
	  derived()(i) = y[i]; 
      } else {
	for(register index_type i=0; i<N; i++) 
	  derived()(i) = rhs[i]; 
      }
      return derived();
    }



    // assignment to matrix (expression)
    template <class B>
    DERIVED& equals(const MorE<D,B>& rhs) {

      const size_type N =size();
      const size_type NR = Nrows();
      const size_type NC = Ncols();
#ifdef MATRICKS_DEBUG
      if ( ( N !=  rhs.size() ) || (NR != rhs.Nrows()) || (NC != rhs.Ncols()) )  { 
	mbad_wrapper_assignment(debugtxt(),rhs.debugtxt());
	outputglossary();
	rhs.outputglossary();
	return derived();
      }
#endif


      if ( rhs.addrmatch(derived().addr()) ) {    
#ifdef MATRICKS_DEBUG
	Matrix<D> y(NR,NC,debugtxt());
#else
	Matrix<D> y(NR,NC);
#endif
	for(register index_type i=0; i<N; i++) 
	  y(i) = rhs(i); 
	for(register index_type i=0; i<N; i++) 
	  derived()(i) = y(i); 
      } else {
	for(register index_type i=0; i<N; i++) 
	  derived()(i) = rhs(i); 
      }
      return derived();
    }


    std::string debugtxt(void) const {
      return derived().debugtxt();
    }

    void outputglossary(void) const {
      return derived().outputglossary();
    }

    bool mustcopy(const void *maddr) const {
      return derived().mustcopy(maddr);
    }

    bool addrmatch(const void *maddr) const {
      return derived().addrmatch(maddr);
    }

    const void *addr(void) const {
      return derived().addr();
    }
    
  };



  /****************************************************************************
   * MSubmatObj Expression Template 
   *
   * wrapper for submatrices
   ****************************************************************************
   */
  template<class D>
  class MSubmatObj : public   MWrapperObj<D,MSubmatObj<D> >{
  private:
    Matrix<D>& a_;
    const size_type a_NC;
    const index_type rstart_;
    const index_type rend_;
    const index_type cstart_;
    const index_type cend_;
    const size_type NR_;
    const size_type NC_;

  public:
    explicit MSubmatObj(Matrix<D>& a, 
	       const index_type rstart, const index_type rend, 
	       const index_type cstart, const index_type cend)
      : a_(a), a_NC(a.Ncols()),
	rstart_(rstart), rend_(rend), 
	cstart_(cstart), cend_(cend),
	NR_(rend_-rstart_+1), NC_(cend_-cstart_+1)
    { 
    }

    inline const D data(index_type i) const{
      return a_(i);
    }
    inline D& data(index_type i) {
      return a_(i);
    }

    inline index_type index(index_type i) const{
      const std::div_t result = std::div(int(i),int(Ncols()));
      const index_type r = static_cast<index_type>(rstart_ + result.quot);
      const index_type c = static_cast<index_type>(cstart_ + result.rem);
      const index_type ind = r*a_NC + c;
#ifdef MATRICKS_DEBUG
      if ( (r>=aNrows())||(c>=aNcols()) ){
	mwrapper_out_of_bounds_rc(debugtxt(),r,c,Nrows(),Ncols(),size(),aID());
	return 0;
      }
#endif
      return ind;
    }

    inline size_type Nrows(void) const {
      return NR_;
    }

    inline size_type Ncols(void) const {
      return NC_;
    }

    inline size_type size(void) const {
#ifdef MATRICKS_DEBUG
      if  ( (rstart_>rend_) || (cstart_>cend_)) {
	mbad_submat(a_.objectID(), rstart_ ,rend_, cstart_, cend_);
	return badsize;
      }else {
	return NR_*NC_;
      }
#endif
      return NR_*NC_;
    }

    inline size_type aNrows(void) const {
      return a_.Nrows();
    }
    inline size_type aNcols(void) const {
      return a_.Ncols();
    }
    inline size_type asize(void) const {
      return a_.size();
    }
    inline size_type aID(void) const {
      return a_.objectID();
    }


    inline METypes metype(void) const {
      return ME_MSubmatObj;
    }

    template <class B>
    MSubmatObj<D>& operator=(const B& b) { 
      return equals(b);
    }

    MSubmatObj<D>& operator=(const MSubmatObj<D>& b) { 
      return equals(b);
    }

    std::string debugtxt(void) const {
      return debugtxt_submat(a_.objectID(), rstart_ ,rend_, cstart_, cend_);
    }

    void outputglossary(void) const {
      outputglossary_M1(debugtxt(),Nrows(),Ncols(),size());
      a_.outputglossary();
    }
    bool mustcopy(const void *maddr) const {
      return addrmatch(maddr);
    }


    bool addrmatch(const void *maddr) const {
      return (maddr==static_cast<const void*>(&a_)) ;
    }


    const void *addr(void) const {
      return &a_;
    }

  };


  /****************************************************************************
   * MRangeObj Expression Template 
   *
   * wrapper for single index matrix ranges  
   ****************************************************************************
   */
 
  template <class D>
  class MRangeObj : public  MWrapperObj<D,MRangeObj<D> > {
  private:
    Matrix<D>& a_;
    const slc& i_;

  public:
    explicit MRangeObj(Matrix<D>& a, const slc& i)
      :  a_(a), i_(i)
    { 
    }

    inline const D data(index_type i) const{
      return a_(i);
    }
    inline D& data(index_type i) {
      return a_(i);
    }

    // TODO: **FIX THIS**
    inline index_type index(index_type i) const{
//       //      const index_type ind = i_[i];
// #ifdef MATRICKS_DEBUG
//       if (ind>=asize()) {
// 	mwrapper_out_of_bounds(debugtxt(),ind,Nrows(),Ncols(),size(),aID());
// 	return 0;
//       }
// #endif
//       return i;
      return 0;
    }


    inline size_type size(void) const {
      return 0;
      //      return i_.size();      
    }

    inline size_type asize(void) const {
      return a_.size();
    }

    inline size_type Nrows(void) const {
      return size();
    }

    inline size_type Ncols(void) const {
      return  1;
    }
    inline size_type aNrows(void) const {
      return a_.Nrows();
    }
    inline size_type aNcols(void) const {
      return a_.Ncols();
    }
    inline size_type aID(void) const {
      return a_.objectID();
    }


    inline METypes metype(void) const {
      return ME_MRangeObj;
    }


    MRangeObj<D>& operator=(const MRangeObj<D>& b) { 
      return equals(b);
    }

    std::string debugtxt(void) const {
      return debugtxt_paren1(a_.debugtxt(),i_.debugtxt());
    }

    void outputglossary(void) const {
      outputglossary_M1(debugtxt(),Nrows(),Ncols(),size());
      a_.outputglossary();
    }

    bool mustcopy(const void *maddr) const {
      return addrmatch(maddr);
    }


    bool addrmatch(const void *maddr) const {
      return maddr==static_cast<const void*>(&a_);
    }

    const void *addr(void) const {
      return &a_;
    }


  };

 



  /****************************************************************************
   * MSetObj Expression Template 
   *
   * wrapper for a  single index matrix subset
   ****************************************************************************
   */
  template<class D>
  class MSetObj :  public  MWrapperObj<D,MSetObj<D> > {
  private:
    Matrix<D>& a_;
    const Vector<index_type>* iiptr_;
    const Vector<index_type>& ii_;
    const size_type indID_;
    const bool indisvector;
  public:
    explicit MSetObj(Matrix<D>& a, const Vector<index_type>& ii)
      : a_(a), 
	iiptr_(0), 
	ii_(ii),
	indID_(ii.objectID()),
	indisvector(true)
    {
    }
    explicit MSetObj(Matrix<D>& a, const Matrix<bool>& mask)
      : a_(a), 
	iiptr_(new Vector<index_type>(findtruesi(mask))), 
	ii_(*iiptr_),
	indID_(mask.objectID()),
	indisvector(false)
    {
    }
    explicit MSetObj(Matrix<D>& a, const Vector<bool>& mask)
      : a_(a), 
	iiptr_(new Vector<index_type>(findtrue(mask))), 
	ii_(*iiptr_),
	indID_(mask.objectID()),
	indisvector(true)
    {
    }
    explicit MSetObj(Matrix<D>& a, const Matrix<index_type>& subs)
      : a_(a), 
	iiptr_(new Vector<index_type>(sub2ind(subs,a.Ncols()))), 
	ii_(*iiptr_),
	indID_(subs.objectID()),
	indisvector(false)
    {
    }

    ~MSetObj()
    { 
      delete  iiptr_;
    }

    inline const D data(index_type i) const{
      return a_(i);
    }
    inline  D& data(index_type i) {
      return a_(i);
    }

    inline index_type index(index_type i) const{
      const index_type ind = ii_[i];
#ifdef MATRICKS_DEBUG
      if (ind>=asize()) {
	mwrapper_out_of_bounds(debugtxt(),ind,Nrows(),Ncols(),size(),aID());
	return 0;
      }
#endif
      return ind;
    }

    inline METypes metype(void) const {
      return ME_MSetObj;
    }

    inline size_type size(void) const {
      return ii_.size();
    }

    inline size_type Nrows(void) const {
      return size();
    }

    inline size_type Ncols(void) const {
      return  1;
    }

    inline size_type aNrows(void) const {
      return a_.Nrows();
    }
    inline size_type aNcols(void) const {
      return a_.Ncols();
    }
    inline size_type asize(void) const {
      return a_.size();
    }
    inline size_type aID(void) const {
      return a_.objectID();
    }

    template <class B>
    MSetObj<D>& operator=(const B& b) { 
      return equals(b);
    }
    MSetObj<D>& operator=(const MSetObj<D>& b) { 
      return equals(b);
    }


    std::string debugtxt(void) const {
      return debugtxt_paren1b(a_.debugtxt(),indID_,indisvector);
    }

    void outputglossary(void) const {
      outputglossary_M1(debugtxt(),Nrows(),Ncols(),size());
      ii_.outputglossary();
      a_.outputglossary();
    }

    bool mustcopy(const void *maddr) const {
      return addrmatch(maddr);
    }


    bool addrmatch(const void *maddr) const {
      return (maddr==static_cast<const void*>(&a_)) ||(maddr==static_cast<const void*>(&ii_)) ;
    }


    const void *addr(void) const {
      return &a_;
    }


  };




  /****************************************************************************
   * MDualSetObj Expression Template 
   *
   * wrapper for a  single index matrix subset
   ****************************************************************************
   */
  template<class D>
  class MDualSetObj :  public  MWrapperObj<D,MDualSetObj<D> > {
  private:
    Matrix<D>& a_;
    const size_type a_NC;
    const Vector<index_type>* iiptr_;
    const Vector<index_type>& ii_;
    const Vector<index_type>* jjptr_;
    const Vector<index_type>& jj_;

  public:
    explicit MDualSetObj(Matrix<D>& a, const Vector<index_type>& ii,  const Vector<index_type>& jj)
      : a_(a), 
	a_NC(a.Ncols()),
	iiptr_(0), 
	ii_(ii),
	jjptr_(0), 
	jj_(jj)
    { }
    explicit MDualSetObj(Matrix<D>& a, const Vector<index_type>& ii,  const index_type j)
      : a_(a), 
	a_NC(a.Ncols()),
	iiptr_(0), 
	ii_(ii),
	jjptr_(new Vector<index_type>(1,j) ), 
	jj_(*jjptr_)
    {     }
    explicit MDualSetObj(Matrix<D>& a, const index_type i, const Vector<index_type>& jj)
      : a_(a), 
	a_NC(a.Ncols()),
	iiptr_(new Vector<index_type>(1,i) ), 
	ii_(*iiptr_),
	jjptr_(0), 
	jj_(jj)
    {     }

    ~MDualSetObj()
    { 
      delete  iiptr_;
      delete  jjptr_;
    }

    inline const D data(index_type i) const{
      return a_(i);
    }
    inline  D& data(index_type i) {
      return a_(i);
    }

    inline index_type index(index_type k) const{
      const std::div_t result = std::div(int(k),int(Ncols()));
      const int i = result.quot;
      const int j = result.rem;
      const index_type r = ii_[i];
      const index_type c = jj_[j];
      const index_type ind =  r*a_NC + c;
#ifdef MATRICKS_DEBUG
      if ( (r>=aNrows())||(c>=aNcols()) ){
	mwrapper_out_of_bounds_rc(debugtxt(),r,c,Nrows(),Ncols(),size(),aID());
	return 0;
      }
#endif
      return ind;
    }

    inline METypes metype(void) const {
      return ME_MDualSetObj;
    }

    inline size_type size(void) const {
#ifdef MATRICKS_DEBUG
      if  ( (ii_.size()==badsize) || ( jj_.size()==badsize) ) {
	return badsize;
      }
#endif
      return Nrows()*Ncols();
    }
    
    inline size_type Nrows(void) const {
      return ii_.size();
    }
    
    inline size_type Ncols(void) const {
      return jj_.size();
    }

    inline size_type aNrows(void) const {
      return a_.Nrows();
    }
    inline size_type aNcols(void) const {
      return a_.Ncols();
    }
    inline size_type asize(void) const {
      return a_.size();
    }
    inline size_type aID(void) const {
      return a_.objectID();
    }

    template <class B>
    MDualSetObj<D>& operator=(const B& b) { 
      return equals(b);
    }
    MDualSetObj<D>& operator=(const MDualSetObj<D>& b) { 
      return equals(b);
    }


    std::string debugtxt(void) const {
      std::string s1,s2;
      if (iiptr_==0) 
	s1= ii_.debugtxt();
      else
	s1= num2string(ii_[0]);
      if (jjptr_==0) 
	s2= jj_.debugtxt();
      else
	s2= num2string(jj_[0]);
      return debugtxt_paren2(a_.debugtxt(),s1,s2);
    }

    void outputglossary(void) const {
      outputglossary_M1(debugtxt(),Nrows(),Ncols(),size());
      if (iiptr_==0) 
	ii_.outputglossary();
      if (jjptr_==0) 
	jj_.outputglossary();
      a_.outputglossary();
    }

    bool mustcopy(const void *maddr) const {
      return addrmatch(maddr);
    }


    bool addrmatch(const void *maddr) const {
      return (maddr==static_cast<const void*>(&a_)) 
	|| (maddr==static_cast<const void*>(&ii_)) 
	|| (maddr==static_cast<const void*>(&jj_));
    }


    const void *addr(void) const {
      return &a_;
    }


  };






  /****************************************************************************
   * MDualRangeObj Expression Template 
   *
   * wrapper for a  single index matrix subset
   ****************************************************************************
   */
  template<class D>
  class MDualRangeObj :  public  MWrapperObj<D,MDualRangeObj<D> > {
  private:
    Matrix<D>& a_;
    const size_type a_NC;
    const slc& i_;
    const slc& j_;

  public:
    explicit MDualRangeObj(Matrix<D>& a, const slc& i,  const slc& j )
      : a_(a), 
	a_NC(a.Ncols()),
	i_(i),
	j_(j)
    { }

    ~MDualRangeObj()
    { 
    }

    inline const D data(index_type i) const{
      return a_(i);
    }
    inline  D& data(index_type i) {
      return a_(i);
    }

    inline index_type index(index_type k) const{
//       const std::div_t result = std::div(int(k),int(Ncols()));
//       const int i = result.quot;
//       const int j = result.rem;
//       const index_type r = i_[i];
//       const index_type c = j_[j];
//       const index_type ind =  r*a_NC + c;
// #ifdef MATRICKS_DEBUG
//       if ( (r>=aNrows())||(c>=aNcols()) ){
// 	mwrapper_out_of_bounds_rc(debugtxt(),r,c,Nrows(),Ncols(),size(),aID());
// 	return 0;
//       }
// #endif
//       return ind;
      return 0;
    }

    inline METypes metype(void) const {
      return ME_MDualRangeObj;
    }

    inline size_type size(void) const {
// #ifdef MATRICKS_DEBUG
//       if  ( (i_.size()==badsize) || ( j_.size()==badsize) ) {
// 	return badsize;
//       }
// #endif
      return Nrows()*Ncols();
    }
    
    inline size_type Nrows(void) const {
      //      return i_.size();
      return 0;
    }
    
    inline size_type Ncols(void) const {
      //      return j_.size();
      return 0;
    }

    inline size_type aNrows(void) const {
      return a_.Nrows();
    }
    inline size_type aNcols(void) const {
      return a_.Ncols();
    }
    inline size_type asize(void) const {
      return a_.size();
    }
    inline size_type aID(void) const {
      return a_.objectID();
    }

    template <class B>
    MDualRangeObj<D>& operator=(const B& b) { 
      return equals(b);
    }
    MDualRangeObj<D>& operator=(const MDualRangeObj<D>& b) { 
      return equals(b);
    }

    std::string debugtxt(void) const {
      return debugtxt_paren2(a_.debugtxt(),i_.debugtxt(),j_.debugtxt());
    }

    void outputglossary(void) const {
      outputglossary_M1(debugtxt(),Nrows(),Ncols(),size());
      i_.outputglossary();
      j_.outputglossary();
      a_.outputglossary();
    }

    bool mustcopy(const void *maddr) const {
      return addrmatch(maddr);
    }


    bool addrmatch(const void *maddr) const {
      return (maddr==static_cast<const void*>(&a_));
    }

    const void *addr(void) const {
      return &a_;
    }


  };





  /****************************************************************************
   * MSetRangeObj Expression Template 
   *
   * wrapper for a  single index matrix subset
   ****************************************************************************
   */

  template<class D>
  class MSetRangeObj :  public  MWrapperObj<D,MSetRangeObj<D> > {
  private:
    Matrix<D>& a_;
    const size_type a_NC;
    const Vector<index_type>* iiptr_;
    const Vector<index_type>& ii_;
    const slc& j_;

  public:
    explicit MSetRangeObj(Matrix<D>& a, const Vector<index_type>& ii, const slc& j )
      : a_(a), 
	a_NC(a.Ncols()),
	iiptr_(0), 
	ii_(ii),
	j_(j)
    { }
    explicit MSetRangeObj(Matrix<D>& a, const index_type i, const slc& j)
      : a_(a), 
	a_NC(a.Ncols()),
	iiptr_(new Vector<index_type>(1,i) ), 
	ii_(*iiptr_),
	j_(j)
    { }

    ~MSetRangeObj()
    { 
      delete  iiptr_;
    }

    inline const D data(index_type i) const{
      return a_(i);
    }
    inline  D& data(index_type i) {
      return a_(i);
    }

    inline index_type index(index_type k) const{
//       const std::div_t result = std::div(int(k),int(Ncols()));
//       const int i = result.quot;
//       const int j = result.rem;
//       const index_type r = ii_[i];
//       const index_type c = j_[j];
//       const index_type ind =  r*a_NC + c;
// #ifdef MATRICKS_DEBUG
//       if ( (r>=aNrows())||(c>=aNcols()) ){
// 	mwrapper_out_of_bounds_rc(debugtxt(),r,c,Nrows(),Ncols(),size(),aID());
// 	return 0;
//       }
// #endif
//       return ind;
      return 0;
    }

    inline METypes metype(void) const {
      return ME_MSetRangeObj;
    }

    inline size_type size(void) const {
// #ifdef MATRICKS_DEBUG
//       if  ( (ii_.size()==badsize) || ( j_.size()==badsize) ) {
// 	return badsize;
//       }
// #endif
      return Nrows()*Ncols();
    }
    
    inline size_type Nrows(void) const {
      //return ii_.size();
      return 0;
    }
    
    inline size_type Ncols(void) const {
      //return j_.size();
      return 0;
    }

    inline size_type aNrows(void) const {
      return a_.Nrows();
    }
    inline size_type aNcols(void) const {
      return a_.Ncols();
    }
    inline size_type asize(void) const {
      return a_.size();
    }
    inline size_type aID(void) const {
      return a_.objectID();
    }

    template <class B>
    MSetRangeObj<D>& operator=(const B& b) { 
      return equals(b);
    }
    MSetRangeObj<D>& operator=(const MSetRangeObj<D>& b) { 
      return equals(b);
    }


    std::string debugtxt(void) const {
      std::string s;
      if (iiptr_==0) 
	s= ii_.debugtxt();
      else
	s= num2string(ii_[0]);
      return debugtxt_paren2(a_.debugtxt(),s,j_.debugtxt());
     }

    void outputglossary(void) const {
      outputglossary_M1(debugtxt(),Nrows(),Ncols(),size());
      if (iiptr_==0) 
	ii_.outputglossary();
      j_.outputglossary();
      a_.outputglossary();
    }

    bool mustcopy(const void *maddr) const {
      return addrmatch(maddr);
    }


    bool addrmatch(const void *maddr) const {
      return (maddr==static_cast<const void*>(&a_)) 
	|| (maddr==static_cast<const void*>(&ii_));
    }


    const void *addr(void) const {
      return &a_;
    }


  };





  /****************************************************************************
   * MRangeSetObj Expression Template 
   *
   * wrapper for a  single index matrix subset
   ****************************************************************************
   */

  template<class D>
  class MRangeSetObj :  public  MWrapperObj<D,MRangeSetObj<D> > {
  private:
    Matrix<D>& a_;
    const size_type a_NC;
    const slc& i_;
    const Vector<index_type>* jjptr_;
    const Vector<index_type>& jj_;

  public:
    explicit MRangeSetObj(Matrix<D>& a, const slc& i, const Vector<index_type>& jj )
      : a_(a), 
	a_NC(a.Ncols()),
	i_(i),
	jjptr_(0), 
	jj_(jj)
    { }
    explicit MRangeSetObj(Matrix<D>& a, const slc& i, const index_type j)
      : a_(a), 
	a_NC(a.Ncols()),
	i_(i),
	jjptr_(new Vector<index_type>(1,j) ), 
	jj_(*jjptr_)
    { }

    ~MRangeSetObj()
    { 
      delete  jjptr_;
    }

    inline const D data(index_type i) const{
      return a_(i);
    }
    inline  D& data(index_type i) {
      return a_(i);
    }

    inline index_type index(index_type k) const{
//       const std::div_t result = std::div(int(k),int(Ncols()));
//       const int i = result.quot;
//       const int j = result.rem;
//       const index_type r = i_[i];
//       const index_type c = jj_[j];
//       const index_type ind =  r*a_NC + c;
// #ifdef MATRICKS_DEBUG
//       if ( (r>=aNrows())||(c>=aNcols()) ){
// 	mwrapper_out_of_bounds_rc(debugtxt(),r,c,Nrows(),Ncols(),size(),aID());
// 	return 0;
//       }
// #endif
//       return ind;
      return 0;
    }

    inline METypes metype(void) const {
      return ME_MRangeSetObj;
    }

    inline size_type size(void) const {
// #ifdef MATRICKS_DEBUG
//       if  ( (i_.size()==badsize) || ( jj_.size()==badsize) ) {
// 	return badsize;
//       }
// #endif
      return Nrows()*Ncols();
    }
    
    inline size_type Nrows(void) const {
      //      return i_.size();
      return 0;
    }
    
    inline size_type Ncols(void) const {
      //      return jj_.size();
      return 0;
    }

    inline size_type aNrows(void) const {
      return a_.Nrows();
    }
    inline size_type aNcols(void) const {
      return a_.Ncols();
    }
    inline size_type asize(void) const {
      return a_.size();
    }
    inline size_type aID(void) const {
      return a_.objectID();
    }

    template <class B>
    MRangeSetObj<D>& operator=(const B& b) { 
      return equals(b);
    }
    MRangeSetObj<D>& operator=(const MRangeSetObj<D>& b) { 
      return equals(b);
    }


    std::string debugtxt(void) const {
      std::string s;
      if (jjptr_==0) 
	s= jj_.debugtxt();
      else
	s= num2string(jj_[0]);
      return debugtxt_paren2(a_.debugtxt(),i_.debugtxt(),s);
    }

    void outputglossary(void) const {
      outputglossary_M1(debugtxt(),Nrows(),Ncols(),size());
      i_.outputglossary();
      if (jjptr_==0) 
	jj_.outputglossary();
      a_.outputglossary();
    }

    bool mustcopy(const void *maddr) const {
      return addrmatch(maddr);
    }


    bool addrmatch(const void *maddr) const {
      return (maddr==static_cast<const void*>(&a_)) 
	|| (maddr==static_cast<const void*>(&jj_));
    }


    const void *addr(void) const {
      return &a_;
    }


  };








  /****************************************************************************
   * MReconObj Expression Template 
   *
   * reallocate store
   ****************************************************************************
   */
  template<class D>
  class MReconObj :  public  Mexpr<D,MReconObj<D> > {
  private:
    Matrix<D>& a_;

  public:
    explicit MReconObj(Matrix<D>& a)
      : a_(a)
    { 
    }

    inline METypes metype(void) const {
      return ME_MReconObj;
    }

    template <class A>
    Matrix<D>& operator=(const MorE<D,A>& x) { 
      size_type NR = x.Nrows();
      size_type NC = x.Ncols();


#ifdef MATRICKS_DEBUG
      size_type N = x.size();
      if ( N==badsize ){ 
	mbad_expr_in_reconassignment(a_.objectID(), x);
	return a_;
      }
#endif

      if ( x.addrmatch(&a_)) {    
#ifdef MATRICKS_DEBUG
	Matrix<D> y(NR,NC,debugtxt());
#else
	Matrix<D> y(NR,NC);
#endif
	y = x.derived();
	a_.resize(NR,NC);
	a_ = y;
	return a_;
      } else {
	a_.resize(NR,NC);
	a_ = x.derived();
	return a_;
      }
    }
    

    Matrix<D>& operator=(const MReconObj<D>& b) { 

#ifdef MATRICKS_DEBUG
      mbad_reconassignment(a_.objectID(), b);
#endif
      return a_;
    }


    std::string debugtxt(void) const {
      return  a_.debugtxt() +".resize()";
    }

    void outputglossary(void) const {
      a_.outputglossary();
    }

    bool mustcopy(const void *maddr) const {
      return addrmatch(maddr);
    }
    bool addrmatch(const void *maddr) const {
      return maddr==static_cast<const void*>(&a_);
    }


  };




  /****************************************************************************
   * MBinOp Operator Expression Template 
   *
   * matrix/matrix binary operator expressions
   ****************************************************************************
   */
  template<class D, class A, class B, class OP>
  class MBinOp : public  Mexpr<D,MBinOp<D,A,B,OP> > {

  private:
    const A& a_;
    const B& b_;

  public:
    explicit MBinOp(const A& a, const B& b)
      : a_(a), b_(b)
    { 
    }

    inline const D operator()(const index_type i) const {
      return OP::apply(a_(i), b_(i));
    }


    inline size_type Nrows(void) const {
      if  (a_.Nrows() !=  b_.Nrows() ) {
	return badsize;
      } else {
	return a_.Nrows();
      }
    }

    inline size_type Ncols(void) const {
      if  (a_.Ncols() !=  b_.Ncols() ) {
	return badsize;
      } else {
	return a_.Ncols();
      }
    }


    inline size_type size(void) const {
      if ( (Nrows()==badsize) || (Ncols()==badsize) )
	return badsize;
      else
	return a_.size();
    }


    bool mustcopy(const void *maddr) const {
      return (a_.mustcopy(maddr)) || (b_.mustcopy(maddr));
    }
 
    bool addrmatch(const void *maddr) const {
      return a_.addrmatch(maddr) ||  b_.addrmatch(maddr);
    }

    inline static METypes metype(void)  {
      return ME_MBinOp;
    }

    std::string debugtxt(void) const {
      std::string sa = debugtxt_paren(a_.debugtxt(),a_.metype());
      std::string sb = debugtxt_paren(b_.debugtxt(),b_.metype());
      return OP::debugtxt(sa,sb);
    }

    void outputglossary(void) const {
      a_.outputglossary();
      b_.outputglossary();
    }


  };








  /****************************************************************************
   * MatOpScal Operator Template 
   *
   * matrix/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
  class MatOpScal : public Mexpr<D,MatOpScal<D,A,OP> > {

  private:
    const A& a_;
    const D val_;

  public:
    explicit MatOpScal(const A& a, const D b)
      : a_(a), val_(b)
    { }

    inline const D operator()(const index_type i) const {
      return OP::apply(a_(i), val_);
    }


    inline size_type Nrows(void) const {
      return a_.Nrows();
    }

    inline size_type Ncols(void) const {
      return a_.Ncols();
    }

    inline size_type size(void) const {
      return a_.size();
    }


    bool mustcopy(const void *maddr) const {
      return a_.mustcopy(maddr);
    }
    bool addrmatch(const void *maddr) const {
      return a_.addrmatch(maddr);
    }

    inline METypes metype(void) const {
      return ME_MatOpScal;
    }

    std::string debugtxt(void) const {
      std::string s;
      return s;
      std::ostringstream stream;
      stream << val_;
      std::string sb = stream.str();
      std::string sa = debugtxt_paren(a_.debugtxt(),a_.metype());
      return OP::debugtxt(sa,sb);
    }


    void outputglossary(void) const {
      a_.outputglossary();
    }


  };





  /****************************************************************************
   * ScalOpMat Operator Template 
   *
   * scalar/matrix binary operators
   ****************************************************************************
   */


  template<class D, class B, class OP>
  class ScalOpMat : public Mexpr<D,ScalOpMat<D,B,OP> > {

  private:
    const D val_;
    const B& b_;

  public:
    explicit ScalOpMat(const D a, const B& b)
      :  val_(a), b_(b)
    { }

    inline const D operator()(const index_type i) const {
      return OP::apply(val_, b_(i));
    }

    inline size_type Nrows(void) const {
      return b_.Nrows();
    }

    inline size_type Ncols(void) const {
      return b_.Ncols();
    }

    inline size_type size(void) const {
      return b_.size();
    }


    bool mustcopy(const void *maddr) const {
      return b_.mustcopy(maddr);
    }
    bool addrmatch(const void *maddr) const {
      return b_.addrmatch(maddr);
    }

    inline METypes metype(void) const {
      return ME_ScalOpMat;
    }

    std::string debugtxt(void) const {
      std::ostringstream stream;
      stream << val_;
      std::string sa = stream.str();
      std::string sb = debugtxt_paren(b_.debugtxt(),b_.metype());
      return OP::debugtxt(sa,sb);
    }

    void outputglossary(void) const {
      b_.outputglossary();
    }


  };




  /****************************************************************************
   * MFuncOp Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
  class MFuncOp  : public  Mexpr<D,MFuncOp<D,A,FUNC> >{
  
  private:
    const A& a_;
  
  public:
    explicit MFuncOp(const A& a) : a_(a) { }

    inline const D operator()(const index_type i) const {
      return FUNC::apply(a_(i));
    }

    inline size_type Nrows(void) const {
      return a_.Nrows();
    }

    inline size_type Ncols(void) const {
      return a_.Ncols();
    }

    inline size_type size(void) const {
      return a_.size();
    }

    inline METypes metype(void) const {
      return ME_MFuncOp;
    }

    bool mustcopy(const void *maddr) const {
      return a_.mustcopy(maddr);
    }
    bool addrmatch(const void *maddr) const {
      return a_.addrmatch(maddr);
    }


    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      return FUNC::debugtxt(sa);
    }

    void outputglossary(void) const {
      a_.outputglossary();
    }

  };






  /****************************************************************************
   * MFuncVec Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
  class MFuncVec  : public  Mexpr<D,MFuncVec<D,A,FUNC> >{
  
  private:
    const A& a_;
    const size_type NR_; 
    const size_type NC_;
  public:
    explicit MFuncVec(const A& a, const size_type NR, const size_type NC) : a_(a), NR_(NR), NC_(NC){ }

    inline const D operator()(const index_type i) const {
      return FUNC::apply(a_[i]);
    }

    inline size_type Nrows(void) const {
      return NR_;
    }

    inline size_type Ncols(void) const {
      return NC_;
    }

    inline size_type size(void) const {
#ifdef MATRICKS_DEBUG
      if ( a_.size() != NR_*NC_ ){ 
	vbad_mcast(debugtxt(), NR_, NC_, a_.size() );
	outputglossary();
	return badsize;
      }
#endif
      return a_.size();
    }

    inline METypes metype(void) const {
      return ME_MFuncVec;
    }

    bool mustcopy(const void *maddr) const {
      return a_.mustcopy(maddr);
    }
    bool addrmatch(const void *maddr) const {
      return a_.addrmatch(maddr);
    }


    std::string debugtxt(void) const {
      std::string sa =  a_.debugtxt();
      return FUNC::debugtxt(sa);
    }

    void outputglossary(void) const {
      a_.outputglossary();
    }

  };




  /****************************************************************************
   * MFuncReshape Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
  class MFuncReshape  : public  Mexpr<D,MFuncReshape<D,A,FUNC> >{
  
  private:
    const A& a_;
    const size_type NR_; 
    const size_type NC_;
  
  public:
    explicit MFuncReshape(const A& a, const size_type NR, const size_type NC) : a_(a), NR_(NR), NC_(NC){ }

    inline const D operator()(const index_type i) const {
      return FUNC::apply(a_(i));
    }


    inline size_type Nrows(void) const {
      return NR_;
    }

    inline size_type Ncols(void) const {
      return NC_;
    }

    inline size_type size(void) const {
#ifdef MATRICKS_DEBUG
      if ( a_.size() != NR_*NC_ ){ 
	vbad_mcast(debugtxt(), NR_, NC_, a_.size() );
	outputglossary();
	return badsize;
      }
#endif
      return a_.size();
    }


    inline METypes metype(void) const {
      return ME_MFuncReshape;
    }

    bool mustcopy(const void *maddr) const {
      return a_.mustcopy(maddr);
    }
    bool addrmatch(const void *maddr) const {
      return a_.addrmatch(maddr);
    }


    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      return FUNC::debugtxt(sa);
    }

    void outputglossary(void) const {
      outputglossary_M1(debugtxt(),Nrows(),Ncols(),size());
      a_.outputglossary();
    }

  };




};

#endif
