

//#include <cstdlib>
#include <cmath>
#include <limits>
#include <iostream>




// round in base10
template <class D> 
D roundN(D x, unsigned int SigificantDigits=0) {
  using namespace std;
  const D ep = numeric_limits<D>::epsilon();
  int d = int(SigificantDigits);
  D y=0.0;
  if (x!=0.0) {
    D temp = std::log10(std::abs(x));
    if (temp>0.0)
      temp = floor(temp);
    else
      temp = ceil(temp);
    int N=int(temp);
    int M = d-N;
    D mant10=COOLL::round(x*std::pow(10.0,M))+ep;
    M = N-d;
    y = mant10*std::pow(10.0,M);
  }
  return y;
}


template <class D>
std::complex<D> roundN(std::complex<D> x, unsigned int SigificantDigits=0) {
  using namespace std;
  const D ep = numeric_limits<D>::epsilon();
  D xR = x.real();
  D xI = x.imag();
  D yR = 0.0;
  D yI = 0.0;

  if (xR!=0.0){
    int d = int(SigificantDigits);
    D temp = std::log10(std::abs(xR));
    if (temp>0.0)
      temp = floor(temp);
    else
      temp = ceil(temp);
    int NR=int(temp);
    int MR = d-NR;
    D mant10R=COOLL::round(xR*std::pow(10.0,MR))+ep;
    MR = NR-d;
    yR = mant10R*std::pow(10.0,MR);
  }

  if (xI!=0.0){
    int d = int(SigificantDigits);
    D temp = std::log10(std::abs(xI));
    if (temp>0.0)
      temp = floor(temp);
    else
      temp = ceil(temp);
    int NI=int(temp);
    int MI = d-NI;
    D mant10I=COOLL::round(xI*std::pow(10.0,MI))+ep;
    MI = NI-d;
    yI = mant10I*std::pow(10.0,MI);
  }

  return complex<D>(yR,yI);
}




// compare two values and return if they are equal to within appropriate error
template <class D> 
bool valuesqual(D x1, D x2) {
  return (x1==x2);
}
template <> 
bool valuesqual<float>(float x1, float x2) {
  using namespace std;
  const float ep = numeric_limits<float>::epsilon();
  float diff = x1-x2;
  if (diff<0.0)
    diff=-diff;
  return (diff<=2.9*ep);
}
template <> 
bool valuesqual<double>(double x1, double x2) {
  using namespace std;
  const double ep = numeric_limits<double>::epsilon();
  double diff = x1-x2;
  if (diff<0.0)
    diff=-diff;
  return (diff<=2.9*ep);
}
template <> 
bool valuesqual<long double>(long double x1, long double x2) {
  using namespace std;
  const long double ep = numeric_limits<long double>::epsilon();
  long double diff = x1-x2;
  if (diff<0.0)
    diff=-diff;
  return (diff<=2.9*ep);
}
template <class D>
bool valuesqual(std::complex<D> x1, std::complex<D> x2) {
  using namespace std;
  const float ep = numeric_limits<D>::epsilon();
  D diffR = x1.real()-x2.real();
  D diffI = x1.imag()-x2.imag();
  if (diffR<0.0)
    diffR=-diffR;
  if (diffI<0.0)
    diffI=-diffI;
  return ( (diffR<=2.9*ep) && (diffI<=2.9*ep));
}



template <class D> 
bool _compare(D v, D ans, char *filename, int linenum) {
  
  bool match =  valuesqual<D>(v,ans);
  using namespace std;

  if (!match) {
    cerr.precision(15);
    string s = filename;
    cerr << endl << "********test in "<<s<<" at line# " << linenum << " FAILED!!!********"<<endl;  
    cerr << "got="<<v<<";  correctanswer="<<ans<<";"<<endl;
    cerr << "ABORTING TESTS"<<endl;
    abort();
  }
  return match;

}

#define compare(v,ans) _compare(v,ans,__FILE__,__LINE__)


template <class D> 
bool _softcompare(D v, D ans, unsigned int d, char *filename, int linenum) {
  using namespace std;
  cout.precision(15);
  D v_rnd=roundN(v,d);
  D ans_rnd=roundN(ans,d);
  bool match = valuesqual(v_rnd,ans_rnd);

  if (!match) {
    cerr.precision(15);
    string s = filename;
    cerr  << "********test in "<<s<<" at line# " << linenum << " FAILED!!!********"<<endl;  
    cerr<<"Values rounded to "<<d<<" significant digits  before error checking"<<endl;
    cerr << "raw values were: calculated="<<v<<";  correctanswer="<<ans<<";"<<endl;
    cerr << "rounded values were: calculated="<<v_rnd<<";  correctanswer="<<ans_rnd<<";"<<endl;
    cerr << "ABORTING TESTS"<<endl;
    abort();
  }

  //debug code
  /*   if (match) {
    cerr<<"Values rounded to "<<d<<" digits  for error checking"<<endl;
    cerr << "raw values were: calculated="<<v<<";  correctanswer="<<ans<<";"<<endl;
    cerr << "rounded values were: calcilated="<<v_rnd<<";  correctanswer="<<ans_rnd<<";"<<endl;
    cerr << "passed"<<endl;
    }
  */
  return match;

}
#define softcompare(v,ans,d) _softcompare(v,ans,d,__FILE__,__LINE__)


template <class D, class A> 
bool _vcompare(A& v, D* ans, unsigned int N, char *filename, int linenum) {
  
  bool match = true;
  using namespace std;

  for(unsigned int i=0; i<N; i++)
    match = match && (v[i]==ans[i]);

  if (!match) {
    cerr.precision(15);
    string s = filename;
    cerr << endl << "********test in "<<s<<" at line# " << linenum << " FAILED!!!********"<<endl;  
    for(unsigned int i=0; i<N; i++)
      cerr << "got[" << i<<"]="<<v[i]<<";  correctanswer["<<i<<"]="<<ans[i]<<";"<<endl;
    cerr << "ABORTING TESTS"<<endl;
    abort();
  }
  return match;

}


#define vcompare(v,ans) _vcompare(v,ans,int(sizeof(ans)/sizeof(ans[0])),__FILE__,__LINE__)



template <class D, class A> 
bool _vsoftcompare(A& v, D* ans, unsigned int d, unsigned int N, char *filename, int linenum) {
  using namespace std;
  bool match = true;
  cout.precision(15);

  LAvector<D> v_rnd(N,"v_rnd");
  LAvector<D> ans_rnd(N,"ans_rnd");
  for(unsigned int i=0; i<N; i++) {
    v_rnd[i]=roundN(v[i],d);
    ans_rnd[i]=roundN(ans[i],d);
    match = match && valuesqual(v_rnd[i],ans_rnd[i]);
  }

  if (!match) {
    cerr.precision(15);
    string s = filename;
    cerr  << "********test in "<<s<<" at line# " << linenum << " FAILED!!!********"<<endl;  
    cerr<<"Values rounded to "<<d<<" significant digits  before error checking"<<endl;
    cerr << "raw values were: "<<endl;
    for(unsigned int i=0; i<N; i++)
      cerr << "  calculated[" << i<<"]="<<v[i]<<";  correctanswer["<<i<<"]="<<ans[i]<<";"<<endl;
    cerr << "rounded values were: "<<endl;
    for(unsigned int i=0; i<N; i++)
      cerr << "  calculated[" << i<<"]="<<v_rnd[i]<<";  correctanswer["<<i<<"]="<<ans_rnd[i]<<";"<<endl;
    cerr << "ABORTING TESTS"<<endl;
    abort();
  }

  return match;
}
#define vsoftcompare(v,ans,d) _vsoftcompare(v,ans,d,int(sizeof(ans)/sizeof(ans[0])),__FILE__,__LINE__)





template <class D, class A> 
bool _mcompare(A& m, D* ans, unsigned int N, char *filename, int linenum) {
  
  bool match = true;
  using namespace std;
  unsigned int NR = m.Nrows(); 
  unsigned int NC = m.Ncols(); 

  if (NR*NC != N) {
    string s = filename;
    cerr << endl << "********test in "<<s<<" at line# " << linenum << " FAILED!!!********"<<endl;  
  }

  unsigned int i=0;
  for(unsigned int r=0; r<NR; r++)
    for(unsigned int c=0; c<NC; c++,i++)
      match = match && (m(r,c)==ans[i]);

  if (!match) {
    cerr.precision(15);
    string s = filename;
    cerr << endl << "********test in "<<s<<" at line# " << linenum << " FAILED!!!********"<<endl;  
    unsigned int i=0;
    for(unsigned int r=0; r<NR; r++)
      for(unsigned int c=0; c<NC; c++,i++)
	cerr << "got(" << r<<","<<c<<")="<<m(r,c)<<";  correctanswer["<<i<<"]="<<ans[i]<<";"<<endl;
    cerr << "ABORTING TESTS"<<endl;
    abort();
  }
  return match;

}


#define mcompare(m,ans) _mcompare(m,ans,int(sizeof(ans)/sizeof(ans[0])),__FILE__,__LINE__)





template <class D, class A> 
bool _msoftcompare(A& m, D* ans, unsigned int d, unsigned int N, char *filename, int linenum) {

  bool match = true;
  using namespace std;
  unsigned int NR = m.Nrows(); 
  unsigned int NC = m.Ncols(); 

  if (NR*NC != N) {
    string s = filename;
    cerr << endl << "********test in "<<s<<" at line# " << linenum << " FAILED!!!********"<<endl;  
  }

  Matrix<D> m_rnd(NR,NC,"m_rnd");
  Matrix<D> ans_rnd(NR,NC,"ans_rnd");


  unsigned int i=0;
  for(unsigned int r=0; r<NR; r++) {
    for(unsigned int c=0; c<NC; c++,i++) {
      m_rnd(r,c)=roundN(m(r,c),d);
      ans_rnd(r,c)=roundN(ans[i],d);
      match = match && valuesqual(m_rnd(r,c),ans_rnd(r,c));
    }
  }
  
  if (!match) {
    string s = filename;
    cerr.precision(15);
    cerr << endl << "********test in "<<s<<" at line# " << linenum << " FAILED!!!********"<<endl;  
    unsigned int i=0;

    cerr<<"Values rounded to "<<d<<" significant digits  before error checking"<<endl;

    cerr << "raw values were: "<<endl;
    for(unsigned int r=0; r<NR; r++) 
      for(unsigned int c=0; c<NC; c++,i++) 
	cerr << "  calculated(" << r<<","<<c<<")="<<m(r,c)<<";  correctanswer(" << r<<","<<c<<")="<<ans[i]<<";"<<endl;

    cerr << "rounded values were: "<<endl;
    for(unsigned int r=0; r<NR; r++) 
      for(unsigned int c=0; c<NC; c++,i++) 
	cerr << "  calculated(" << r<<","<<c<<")="<<m_rnd(r,c)<<";  correctanswer(" << r<<","<<c<<")="<<ans_rnd(r,c)<<";"<<endl;

    cerr << "ABORTING TESTS"<<endl;
    abort();
  }
  return match;

}
#define msoftcompare(m,ans,d) _msoftcompare(m,ans,d,int(sizeof(ans)/sizeof(ans[0])),__FILE__,__LINE__)




template <class D, class A> 
bool _vcompare2d(A& v, D* ans, unsigned int N, char *filename, int linenum) {
  
  bool match = true;
  using namespace std;
  const unsigned int L = v.size();
  unsigned int M=0;
  unsigned int n=0;
  for(unsigned int i=0; i<L; i++) {
    M = v[i].size();
    for(unsigned int j=0; j<M; j++,n++) {
      match = (v[i][j]==ans[n]);

      if (n>=N) {
	cerr << endl << "********test in "<<string(filename)<<" at line# " << linenum << " FAILED!!!********"<<endl;  
	cerr<< "test object and answer have different size"<<endl;
	cerr<< " answer size ="<<N<<endl;
	cerr << "ABORTING TESTS"<<endl;
	abort();
      }
      if (!match) {
	cerr.precision(15);
	string s = filename;
	cerr << endl << "********test in "<<s<<" at line# " << linenum << " FAILED!!!********"<<endl;  
	cerr << "got[" << i<<"][";
	cerr <<j<<"]=";
	cerr <<(v[i][j]);
	cerr <<";  correctanswer["<<n<<"]="<<ans[n]<<";"<<endl;
	cerr << "ABORTING TESTS"<<endl;
	abort();
      }
    }
  }
  return match;
  
}


#define vcompare2d(v,ans) _vcompare2d(v,ans,int(sizeof(ans)/sizeof(ans[0])),__FILE__,__LINE__)
 



template <class D, class A> 
bool _vcompare3d(A& v, D* ans, unsigned int N, char *filename, int linenum) {
  
  bool match = true;
  using namespace std;
  const unsigned int I = v.size();
  unsigned int J=0;
  unsigned int K=0;
  unsigned int n=0;
  for(unsigned int i=0; i<I; i++) {
    J = v[i].size();
    for(unsigned int j=0; j<J; j++) {
      K = v[i][j].size();
      for(unsigned int k=0; k<K; k++, n++) {
	match = (v[i][j][k]==ans[n]);

	if (n>=N) {
	  cerr << endl << "********test in "<<string(filename)<<" at line# " << linenum << " FAILED!!!********"<<endl;  
	  cerr<< "test object and answer have different size"<<endl;
	  cerr<< " answer size ="<<N<<endl;
	  cerr << "ABORTING TESTS"<<endl;
	  abort();
	}
	if (!match) {
	  cerr.precision(15);
	  string s = filename;
	  cerr << endl << "********test in "<<s<<" at line# " << linenum << " FAILED!!!********"<<endl;  
	  cerr << "got[" << i<<"]["<<j<<"["<<k<<"]=";
	  cerr <<(v[i][j][k]);
	  cerr <<";  correctanswer["<<n<<"]="<<ans[n]<<";"<<endl;
	  cerr << "ABORTING TESTS"<<endl;
	  abort();
	}
      }
    }
  }
  return match;
}


#define vcompare3d(v,ans) _vcompare3d(v,ans,int(sizeof(ans)/sizeof(ans[0])),__FILE__,__LINE__)
 
