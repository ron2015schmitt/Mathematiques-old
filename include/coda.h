#ifndef MATRICKS__CODA
#define MATRICKS__CODA


namespace matricks {


  //--------------------------------------------------------------
  //   method for slc class
  //--------------------------------------------------------------
  
  inline Vector<index_type>& slc::toIndexVector(const size_type N) const {
    //    printf3("slc::toIndexVector(N=%lu)\n",N);
    index_type mystart = start_;
    if (mystart < 0) {
      mystart += N;
    }
    index_type myend = end_;
    if (myend < 0) {
      myend += N;
    }

    index_type mystep = step_;

    std::queue<index_type> indices;
	
    if (myend-mystart >= 0) {
      if (mystep > 0) {
	for (index_type k = mystart; k <= myend; k += mystep){
	  if (k < 0) continue;
	  if (k >= N) break;
	  indices.push(k);
	}
      }
    } else {
      if (mystep < 0) {
	for (index_type k = mystart; k >= myend; k += mystep){
	  if (k >= N) continue;
	  if (k < 0)  break;
	  indices.push(k);
	}
      }
    }
  
    const size_type Nnew = indices.size();
    Vector<index_type> &indexvec = *(new Vector<index_type>(Nnew));
    for (register index_type i = 0; i < Nnew ; i++ ) {
      indexvec[i] = indices.front();
      indices.pop();
    }
      
    return indexvec;
  }

  
};


#endif
