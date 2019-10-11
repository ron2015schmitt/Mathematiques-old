#define MATRICKS_DEBUG 1
#include "matricks.h"



namespace matricks {

  // -------------------------------------------------------------------
  //
  // Indices - class to hold dimensions of Tensors
  // -------------------------------------------------------------------


  Indices::Indices(const Indices& inds) {
    resize(inds.size(),0);
    for(int k = 0; k < inds.size(); k++) {
      (*this)[k] = inds[k];
    }
  }
  Indices::Indices() {
    resize(0,0);
  }
  Indices::Indices(const index_type n) {
    resize(n,0);
  }
  // arbitrary size. can alos use "push_back"
  Indices::Indices(const Parent& inds) {
    resize(inds.size(),0);
    for(int k = 0; k < inds.size(); k++) {
      (*this)[k] = inds[k];
    }
  }
    
  // use C++11 init list for arbitrary rank
  Indices::Indices(const std::initializer_list<index_type> list) 
  {
    const index_type N =  list.size();
    resize(N,0);
    index_type i = 0;
    typename std::initializer_list<index_type>::iterator it; 
    for (it = list.begin(); it != list.end(); ++it)  { 
      (*this)[i++] = *it;
    }
  }



    
  bool Indices::equiv(const Indices& inds) const {
    return (*this == inds);
  }

  Indices& Indices::getReverse() const {
    Indices& revinds = *(new Indices());
    for(int k = this->size()-1; k >= 0 ; k--) {
      revinds.push_back((*this)[k]);
    }
    return revinds;
  }

  
  std::string Indices::classname() const {
    return "Indices";
  }


  std::ostream& operator<<(std::ostream &stream, const Indices& inds) {
    using namespace display;
    
    stream << "{";
    for (index_type ii = 0; ii < inds.size(); ii++) {
      if (ii>0)  stream << ", ";
      dispval_strm(stream, inds[ii]);
    }
    stream << "}";
    
    return stream;
  }
  
  


};


