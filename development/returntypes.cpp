
#include "../cooll.hpp"
using namespace COOLL;
using namespace std;

// rt1 is used for operations that reduce a p3vector<D> to a D
// stop at any non-vector type
template <typename T> class rt1 {
public:
  typedef T type;
};


// contract the p3vector
template <typename T> class rt1<p3vector<T> > {
public:
  typedef typename rt1<T>::type type;
};


// just skip over LAvectors
template <typename T> class rt1<LAvector<T> > {
public:
  typedef LAvector<typename rt1<T>::type> type;
};




// 1) NEED TO GENERALIZE FOR P3VECTORS (need a return type class)
// 2) if we want to add these as members, we should be able to read and write
// would need to wrapper them


//return v[i][][][]...
template < typename T > T left(LAvector<T>& v,  const unsigned int i) {
  return v[i];
}


// return v[][][]...[][j]
template < typename T > LAvector<T> right(LAvector<LAvector<T> >& v,  const unsigned int j) {
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



int main(void) {

  p3vector<double> v1(1.0,2.0,3.0);
  print(make_type_string(v1));
  dispcr(v1);

  rt1<typeof(v1)>::type x;
  x = sum(v1);
  print(make_type_string(x));
  dispcr(x);


  LAvector<p3vector<double> > v2(2);
  "{ {1,2,3}, {4,5,6} }">> v2;
  print(make_type_string(v2));
  dispcr(v2);

  rt1<typeof(v2)>::type x2(2);
  LAvector<double> temp(2);
  "{100,200}" >> temp;
  print(make_type_string(temp));
  dispcr(temp);
  x2 = temp;
  print(make_type_string(x2));
  dispcr(x2);

  typedef typeof(v2) ttype;
  ttype::element_type x3;
  x3 = left(v2,1);
  print(make_type_string(x3));
  dispcr(x3);

  LAvector<double>  v4sub(2);
  "{55,56}" >> v4sub;
  print(make_type_string(v4sub));
  dispcr(v4sub);
  double x4 = right(v4sub,1);
  print(make_type_string(x4));
  dispcr(x4);


  LAvector<LAvector<double> > v4(2);
  v4[0].resize(3);
  v4[1].resize(3);
  "{ {1,2,3}, {4,5,6} }">> v4;
  print(make_type_string(v4));
  dispcr(v4);
  
  v4sub = right(v4,1);
  print(make_type_string(v4sub));
  dispcr(v4sub);
 

  return 0;
}

