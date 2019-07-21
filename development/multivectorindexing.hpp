
//NEED TO GENERALIZE FOR P3VECTORS
// if we want to add these as members, we should be able to read and write
// would need to wrapper them


//return v[i][][][]...
template < typename T > T left(LAvector<T>& v,  const unsigned int i) {
  return v[i];
}


// return v[][][]...[][j]
template < typename T > T right(LAvector<LAvector<T> >& v,  const unsigned int j) {
  unsigned int N = v.size();
  // need a return type finding function
  // this only work siwth all LAvectors
  LAvector<T> _right(N,"_right");
  for (unsigned int i =0; i<N; i++)
    _right[i] = right(v[i],j);
    
  return _right;
}

template < typename T > T right(LAvector<T>& v, const  unsigned int j) {
  return v[j];
}




// return v[][][].[j]..[][]
template <unsigned int kprime =0, typename T > T slice(LAvector<T>& v, const unsigned int j, const unsigned int k) {

  if ((int(kprime)-int(k)) <=0) {
    return v[j];
  }

  unsigned int N = v.size();

  // need a return type finding function
  // this only work siwth all LAvectors
  T _slice(N,"_slice");
  for (unsigned int i =0; i<N; i++)
    _slice[i] = slice<kprime+1>(v[i],j,k);
    
  return _slice;
}

