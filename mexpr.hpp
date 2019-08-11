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




#ifndef MEXPR_H
#define MEXPR_H 1


#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>


namespace COOLL {



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

    inline const D operator()(const unsigned int i) const {
      return derived()(i);
    }

    inline const D operator()(const unsigned int r, const unsigned int c) const {
      return r*Ncols() + c;
    }


    inline unsigned int Nrows(void) const {
      return derived().Nrows();
    }
    
    inline unsigned int Ncols(void) const {
      return derived().Ncols();
    }

    inline unsigned int size(void) const {
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

    inline const D operator()(const unsigned int i) const {  
      const unsigned int index = derived().index(i);
      return derived().data(index);
    }

    inline D& operator()(const unsigned int i) {  
      const unsigned int index = derived().index(i);
      return derived().data(index);
    }

    inline const unsigned int index(void) const {
      return derived().index();
    }

    inline unsigned int size(void) const {
      return derived().size();
    }

    inline unsigned int Nrows(void) const {
      return derived().Nrows();
    }

    inline unsigned int Ncols(void) const {
      return  derived().Ncols();
    }

    inline unsigned int asize(void) const {
      return derived().asize();
    }
    inline unsigned int aID(void) const {
      return derived().aID();
    }

    inline unsigned int aNrows(void) const {
      return derived().aNrows();
    }

    inline unsigned int aNcols(void) const {
      return  derived().aNcols();
    }



    inline METypes metype(void) const {
      return derived().metype();
    }


    // Assign to constant value
    DERIVED& equals(const D d) { 
      for(unsigned int i=0; i<size(); i++) 
	(*this)(i)=d; 
      return derived();
    }

    // assign to recon object (issue error)
    DERIVED& equals(const MReconObj<D>& b) { 
#ifdef COOLL_CAREFUL
      mbad_reconassignment(a_.objectID(), b);
#endif
      return derived();
    }


    //assign to vector(expression)
    
    template <class B>
    DERIVED& equals(const VorE<D,B>& rhs) { 
      
      const unsigned int N =size();

#ifdef COOLL_CAREFUL
      const unsigned int NR = Nrows();
      const unsigned int NC = Ncols();
      if ( ( N !=  rhs.size() ) 
	   || ( (NR!=1) && (NC!=1) ) ){ 
	mbad_wrapper_assignment_vec(derived().debugtxt(),rhs.debugtxt());
	derived().outputglossary();
	rhs.outputglossary();
	return derived();
      }
#endif

      if ( rhs.addrmatch(derived().addr()) ) {    
#ifdef COOLL_CAREFUL
	LAvector<D> y(N,debugtxt());
#else
	LAvector<D> y(N);
#endif
	for(register unsigned int i=0; i<N; i++) 
	  y[i] = rhs[i]; 
	for(register unsigned int i=0; i<N; i++) 
	  derived()(i) = y[i]; 
      } else {
	for(register unsigned int i=0; i<N; i++) 
	  derived()(i) = rhs[i]; 
      }
      return derived();
    }



    // assignment to matrix (expression)
    template <class B>
    DERIVED& equals(const MorE<D,B>& rhs) {

      const unsigned int N =size();
      const unsigned int NR = Nrows();
      const unsigned int NC = Ncols();
#ifdef COOLL_CAREFUL
      if ( ( N !=  rhs.size() ) || (NR != rhs.Nrows()) || (NC != rhs.Ncols()) )  { 
	mbad_wrapper_assignment(debugtxt(),rhs.debugtxt());
	outputglossary();
	rhs.outputglossary();
	return derived();
      }
#endif


      if ( rhs.addrmatch(derived().addr()) ) {    
#ifdef COOLL_CAREFUL
	Matrix<D> y(NR,NC,debugtxt());
#else
	Matrix<D> y(NR,NC);
#endif
	for(register unsigned int i=0; i<N; i++) 
	  y(i) = rhs(i); 
	for(register unsigned int i=0; i<N; i++) 
	  derived()(i) = y(i); 
      } else {
	for(register unsigned int i=0; i<N; i++) 
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
    const unsigned int a_NC;
    const unsigned int rstart_;
    const unsigned int rend_;
    const unsigned int cstart_;
    const unsigned int cend_;
    const unsigned int NR_;
    const unsigned int NC_;

  public:
    explicit MSubmatObj(Matrix<D>& a, 
	       const unsigned int rstart, const unsigned int rend, 
	       const unsigned int cstart, const unsigned int cend)
      : a_(a), a_NC(a.Ncols()),
	rstart_(rstart), rend_(rend), 
	cstart_(cstart), cend_(cend),
	NR_(rend_-rstart_+1), NC_(cend_-cstart_+1)
    { 
    }

    inline const D data(unsigned int i) const{
      return a_(i);
    }
    inline D& data(unsigned int i) {
      return a_(i);
    }

    inline const unsigned int index(unsigned int i) const{
      const std::div_t result = std::div(int(i),int(Ncols()));
      const unsigned int r = static_cast<unsigned int>(rstart_ + result.quot);
      const unsigned int c = static_cast<unsigned int>(cstart_ + result.rem);
      const unsigned int ind = r*a_NC + c;
#ifdef COOLL_CAREFUL
      if ( (r>=aNrows())||(c>=aNcols()) ){
	mwrapper_out_of_bounds_rc(debugtxt(),r,c,Nrows(),Ncols(),size(),aID());
	return 0;
      }
#endif
      return ind;
    }

    inline unsigned int Nrows(void) const {
      return NR_;
    }

    inline unsigned int Ncols(void) const {
      return NC_;
    }

    inline unsigned int size(void) const {
#ifdef COOLL_CAREFUL
      if  ( (rstart_>rend_) || (cstart_>cend_)) {
	mbad_submat(a_.objectID(), rstart_ ,rend_, cstart_, cend_);
	return badsize;
      }else {
	return NR_*NC_;
      }
#endif
      return NR_*NC_;
    }

    inline unsigned int aNrows(void) const {
      return a_.Nrows();
    }
    inline unsigned int aNcols(void) const {
      return a_.Ncols();
    }
    inline unsigned int asize(void) const {
      return a_.size();
    }
    inline unsigned int aID(void) const {
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
    const seq& i_;

  public:
    explicit MRangeObj(Matrix<D>& a, const seq& i)
      :  a_(a), i_(i)
    { 
    }

    inline const D data(unsigned int i) const{
      return a_(i);
    }
    inline D& data(unsigned int i) {
      return a_(i);
    }


    inline const unsigned int index(unsigned int i) const{
      const unsigned int ind = i_[i];
#ifdef COOLL_CAREFUL
      if (ind>=asize()) {
	mwrapper_out_of_bounds(debugtxt(),ind,Nrows(),Ncols(),size(),aID());
	return 0;
      }
#endif
      return ind;
    }


    inline unsigned int size(void) const {
      return i_.size();      
    }

    inline unsigned int asize(void) const {
      return a_.size();
    }

    inline unsigned int Nrows(void) const {
      return size();
    }

    inline unsigned int Ncols(void) const {
      return  1;
    }
    inline unsigned int aNrows(void) const {
      return a_.Nrows();
    }
    inline unsigned int aNcols(void) const {
      return a_.Ncols();
    }
    inline unsigned int aID(void) const {
      return a_.objectID();
    }


    inline METypes metype(void) const {
      return ME_MRangeObj;
    }

    template <class B>
    MRangeObj<D>& operator=(const B& b) { 
      return equals(b);
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
    const LAvector<unsigned int>* iiptr_;
    const LAvector<unsigned int>& ii_;
    const unsigned int indID_;
    const bool indisvector;
  public:
    explicit MSetObj(Matrix<D>& a, const LAvector<unsigned int>& ii)
      : a_(a), 
	iiptr_(0), 
	ii_(ii),
	indID_(ii.objectID()),
	indisvector(true)
    {
    }
    explicit MSetObj(Matrix<D>& a, const Matrix<bool>& mask)
      : a_(a), 
	iiptr_(new LAvector<unsigned int>(findtruesi(mask))), 
	ii_(*iiptr_),
	indID_(mask.objectID()),
	indisvector(false)
    {
    }
    explicit MSetObj(Matrix<D>& a, const LAvector<bool>& mask)
      : a_(a), 
	iiptr_(new LAvector<unsigned int>(findtrue(mask))), 
	ii_(*iiptr_),
	indID_(mask.objectID()),
	indisvector(true)
    {
    }
    explicit MSetObj(Matrix<D>& a, const Matrix<unsigned int>& subs)
      : a_(a), 
	iiptr_(new LAvector<unsigned int>(sub2ind(subs,a.Ncols()))), 
	ii_(*iiptr_),
	indID_(subs.objectID()),
	indisvector(false)
    {
    }

    ~MSetObj()
    { 
      delete  iiptr_;
    }

    inline const D data(unsigned int i) const{
      return a_(i);
    }
    inline  D& data(unsigned int i) {
      return a_(i);
    }

    inline const unsigned int index(unsigned int i) const{
      const unsigned int ind = ii_[i];
#ifdef COOLL_CAREFUL
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

    inline unsigned int size(void) const {
      return ii_.size();
    }

    inline unsigned int Nrows(void) const {
      return size();
    }

    inline unsigned int Ncols(void) const {
      return  1;
    }

    inline unsigned int aNrows(void) const {
      return a_.Nrows();
    }
    inline unsigned int aNcols(void) const {
      return a_.Ncols();
    }
    inline unsigned int asize(void) const {
      return a_.size();
    }
    inline unsigned int aID(void) const {
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
    const unsigned int a_NC;
    const LAvector<unsigned int>* iiptr_;
    const LAvector<unsigned int>& ii_;
    const LAvector<unsigned int>* jjptr_;
    const LAvector<unsigned int>& jj_;

  public:
    explicit MDualSetObj(Matrix<D>& a, const LAvector<unsigned int>& ii,  const LAvector<unsigned int>& jj)
      : a_(a), 
	a_NC(a.Ncols()),
	iiptr_(0), 
	ii_(ii),
	jjptr_(0), 
	jj_(jj)
    { }
    explicit MDualSetObj(Matrix<D>& a, const LAvector<unsigned int>& ii,  const unsigned int j)
      : a_(a), 
	a_NC(a.Ncols()),
	iiptr_(0), 
	ii_(ii),
	jjptr_(new LAvector<unsigned int>(1,j,"") ), 
	jj_(*jjptr_)
    {     }
    explicit MDualSetObj(Matrix<D>& a, const unsigned int i, const LAvector<unsigned int>& jj)
      : a_(a), 
	a_NC(a.Ncols()),
	iiptr_(new LAvector<unsigned int>(1,i,"") ), 
	ii_(*iiptr_),
	jjptr_(0), 
	jj_(jj)
    {     }

    ~MDualSetObj()
    { 
      delete  iiptr_;
      delete  jjptr_;
    }

    inline const D data(unsigned int i) const{
      return a_(i);
    }
    inline  D& data(unsigned int i) {
      return a_(i);
    }

    inline const unsigned int index(unsigned int k) const{
      const std::div_t result = std::div(int(k),int(Ncols()));
      const int i = result.quot;
      const int j = result.rem;
      const unsigned int r = ii_[i];
      const unsigned int c = jj_[j];
      const unsigned int ind =  r*a_NC + c;
#ifdef COOLL_CAREFUL
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

    inline unsigned int size(void) const {
#ifdef COOLL_CAREFUL
      if  ( (ii_.size()==badsize) || ( jj_.size()==badsize) ) {
	return badsize;
      }
#endif
      return Nrows()*Ncols();
    }
    
    inline unsigned int Nrows(void) const {
      return ii_.size();
    }
    
    inline unsigned int Ncols(void) const {
      return jj_.size();
    }

    inline unsigned int aNrows(void) const {
      return a_.Nrows();
    }
    inline unsigned int aNcols(void) const {
      return a_.Ncols();
    }
    inline unsigned int asize(void) const {
      return a_.size();
    }
    inline unsigned int aID(void) const {
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
	s1= uint2string(ii_[0]);
      if (jjptr_==0) 
	s2= jj_.debugtxt();
      else
	s2= uint2string(jj_[0]);
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
    const unsigned int a_NC;
    const seq& i_;
    const seq& j_;

  public:
    explicit MDualRangeObj(Matrix<D>& a, const seq& i,  const seq& j )
      : a_(a), 
	a_NC(a.Ncols()),
	i_(i),
	j_(j)
    { }

    ~MDualRangeObj()
    { 
    }

    inline const D data(unsigned int i) const{
      return a_(i);
    }
    inline  D& data(unsigned int i) {
      return a_(i);
    }

    inline const unsigned int index(unsigned int k) const{
      const std::div_t result = std::div(int(k),int(Ncols()));
      const int i = result.quot;
      const int j = result.rem;
      const unsigned int r = i_[i];
      const unsigned int c = j_[j];
      const unsigned int ind =  r*a_NC + c;
#ifdef COOLL_CAREFUL
      if ( (r>=aNrows())||(c>=aNcols()) ){
	mwrapper_out_of_bounds_rc(debugtxt(),r,c,Nrows(),Ncols(),size(),aID());
	return 0;
      }
#endif
      return ind;
    }

    inline METypes metype(void) const {
      return ME_MDualRangeObj;
    }

    inline unsigned int size(void) const {
#ifdef COOLL_CAREFUL
      if  ( (i_.size()==badsize) || ( j_.size()==badsize) ) {
	return badsize;
      }
#endif
      return Nrows()*Ncols();
    }
    
    inline unsigned int Nrows(void) const {
      return i_.size();
    }
    
    inline unsigned int Ncols(void) const {
      return j_.size();
    }

    inline unsigned int aNrows(void) const {
      return a_.Nrows();
    }
    inline unsigned int aNcols(void) const {
      return a_.Ncols();
    }
    inline unsigned int asize(void) const {
      return a_.size();
    }
    inline unsigned int aID(void) const {
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
    const unsigned int a_NC;
    const LAvector<unsigned int>* iiptr_;
    const LAvector<unsigned int>& ii_;
    const seq& j_;

  public:
    explicit MSetRangeObj(Matrix<D>& a, const LAvector<unsigned int>& ii, const seq& j )
      : a_(a), 
	a_NC(a.Ncols()),
	iiptr_(0), 
	ii_(ii),
	j_(j)
    { }
    explicit MSetRangeObj(Matrix<D>& a, const unsigned int i, const seq& j)
      : a_(a), 
	a_NC(a.Ncols()),
	iiptr_(new LAvector<unsigned int>(1,i,"") ), 
	ii_(*iiptr_),
	j_(j)
    { }

    ~MSetRangeObj()
    { 
      delete  iiptr_;
    }

    inline const D data(unsigned int i) const{
      return a_(i);
    }
    inline  D& data(unsigned int i) {
      return a_(i);
    }

    inline const unsigned int index(unsigned int k) const{
      const std::div_t result = std::div(int(k),int(Ncols()));
      const int i = result.quot;
      const int j = result.rem;
      const unsigned int r = ii_[i];
      const unsigned int c = j_[j];
      const unsigned int ind =  r*a_NC + c;
#ifdef COOLL_CAREFUL
      if ( (r>=aNrows())||(c>=aNcols()) ){
	mwrapper_out_of_bounds_rc(debugtxt(),r,c,Nrows(),Ncols(),size(),aID());
	return 0;
      }
#endif
      return ind;
    }

    inline METypes metype(void) const {
      return ME_MSetRangeObj;
    }

    inline unsigned int size(void) const {
#ifdef COOLL_CAREFUL
      if  ( (ii_.size()==badsize) || ( j_.size()==badsize) ) {
	return badsize;
      }
#endif
      return Nrows()*Ncols();
    }
    
    inline unsigned int Nrows(void) const {
      return ii_.size();
    }
    
    inline unsigned int Ncols(void) const {
      return j_.size();
    }

    inline unsigned int aNrows(void) const {
      return a_.Nrows();
    }
    inline unsigned int aNcols(void) const {
      return a_.Ncols();
    }
    inline unsigned int asize(void) const {
      return a_.size();
    }
    inline unsigned int aID(void) const {
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
	s= uint2string(ii_[0]);
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
    const unsigned int a_NC;
    const seq& i_;
    const LAvector<unsigned int>* jjptr_;
    const LAvector<unsigned int>& jj_;

  public:
    explicit MRangeSetObj(Matrix<D>& a, const seq& i, const LAvector<unsigned int>& jj )
      : a_(a), 
	a_NC(a.Ncols()),
	i_(i),
	jjptr_(0), 
	jj_(jj)
    { }
    explicit MRangeSetObj(Matrix<D>& a, const seq& i, const unsigned int j)
      : a_(a), 
	a_NC(a.Ncols()),
	i_(i),
	jjptr_(new LAvector<unsigned int>(1,j,"") ), 
	jj_(*jjptr_)
    { }

    ~MRangeSetObj()
    { 
      delete  jjptr_;
    }

    inline const D data(unsigned int i) const{
      return a_(i);
    }
    inline  D& data(unsigned int i) {
      return a_(i);
    }

    inline const unsigned int index(unsigned int k) const{
      const std::div_t result = std::div(int(k),int(Ncols()));
      const int i = result.quot;
      const int j = result.rem;
      const unsigned int r = i_[i];
      const unsigned int c = jj_[j];
      const unsigned int ind =  r*a_NC + c;
#ifdef COOLL_CAREFUL
      if ( (r>=aNrows())||(c>=aNcols()) ){
	mwrapper_out_of_bounds_rc(debugtxt(),r,c,Nrows(),Ncols(),size(),aID());
	return 0;
      }
#endif
      return ind;
    }

    inline METypes metype(void) const {
      return ME_MRangeSetObj;
    }

    inline unsigned int size(void) const {
#ifdef COOLL_CAREFUL
      if  ( (i_.size()==badsize) || ( jj_.size()==badsize) ) {
	return badsize;
      }
#endif
      return Nrows()*Ncols();
    }
    
    inline unsigned int Nrows(void) const {
      return i_.size();
    }
    
    inline unsigned int Ncols(void) const {
      return jj_.size();
    }

    inline unsigned int aNrows(void) const {
      return a_.Nrows();
    }
    inline unsigned int aNcols(void) const {
      return a_.Ncols();
    }
    inline unsigned int asize(void) const {
      return a_.size();
    }
    inline unsigned int aID(void) const {
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
	s= uint2string(jj_[0]);
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
      unsigned int NR = x.Nrows();
      unsigned int NC = x.Ncols();


#ifdef COOLL_CAREFUL
      unsigned int N = x.size();
      if ( N==badsize ){ 
	mbad_expr_in_reconassignment(a_.objectID(), x);
	return a_;
      }
#endif

      if ( x.addrmatch(&a_)) {    
#ifdef COOLL_CAREFUL
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

#ifdef COOLL_CAREFUL
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

    inline const D operator()(const unsigned int i) const {
      return OP::apply(a_(i), b_(i));
    }


    inline unsigned int Nrows(void) const {
      if  (a_.Nrows() !=  b_.Nrows() ) {
	return badsize;
      } else {
	return a_.Nrows();
      }
    }

    inline unsigned int Ncols(void) const {
      if  (a_.Ncols() !=  b_.Ncols() ) {
	return badsize;
      } else {
	return a_.Ncols();
      }
    }


    inline unsigned int size(void) const {
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

    inline const D operator()(const unsigned int i) const {
      return OP::apply(a_(i), val_);
    }


    inline unsigned int Nrows(void) const {
      return a_.Nrows();
    }

    inline unsigned int Ncols(void) const {
      return a_.Ncols();
    }

    inline unsigned int size(void) const {
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

    inline const D operator()(const unsigned int i) const {
      return OP::apply(val_, b_(i));
    }

    inline unsigned int Nrows(void) const {
      return b_.Nrows();
    }

    inline unsigned int Ncols(void) const {
      return b_.Ncols();
    }

    inline unsigned int size(void) const {
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

    inline const D operator()(const unsigned int i) const {
      return FUNC::apply(a_(i));
    }

    inline unsigned int Nrows(void) const {
      return a_.Nrows();
    }

    inline unsigned int Ncols(void) const {
      return a_.Ncols();
    }

    inline unsigned int size(void) const {
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
    const unsigned int NR_; 
    const unsigned int NC_;
  public:
    explicit MFuncVec(const A& a, const unsigned int NR, const unsigned int NC) : a_(a), NR_(NR), NC_(NC){ }

    inline const D operator()(const unsigned int i) const {
      return FUNC::apply(a_[i]);
    }

    inline unsigned int Nrows(void) const {
      return NR_;
    }

    inline unsigned int Ncols(void) const {
      return NC_;
    }

    inline unsigned int size(void) const {
#ifdef COOLL_CAREFUL
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
    const unsigned int NR_; 
    const unsigned int NC_;
  
  public:
    explicit MFuncReshape(const A& a, const unsigned int NR, const unsigned int NC) : a_(a), NR_(NR), NC_(NC){ }

    inline const D operator()(const unsigned int i) const {
      return FUNC::apply(a_(i));
    }


    inline unsigned int Nrows(void) const {
      return NR_;
    }

    inline unsigned int Ncols(void) const {
      return NC_;
    }

    inline unsigned int size(void) const {
#ifdef COOLL_CAREFUL
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
