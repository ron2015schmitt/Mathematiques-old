
//#define MATHQ_DEBUG

#include "mathq.h" 

#include <fstream>

  using namespace mathq;


// TODO: 1. shoul define a type TensorObject that all actual tensors
//       inherit from and use that instead of X.
//       2. pass an index and use constant-size vectors instead of lists

template <class X, class E, typename D, int M, int R> 
void insideout_(const TensorRW<X,E,D,M,R>& tf,
		typename  InversionType<X,Null>::Type& tr,
		const std::vector<index_type>& flatdims,
		const std::vector<index_type>& flatrdims,
		std::list<index_type>& flist,
		std::list<index_type>& rlist		 
		 ) {
  const X& t = tf.derived();
  const index_type N = flatdims.size();

  mout << "insideout_: ";
  mdisp(flist.size(), N);
  tdisp(flatdims);
  tdisp(flatrdims);
  tdisp(tr.deepdims());

  
  if (flist.size() == N) {
    mout<<"*********"<<std::endl;
    Indices finds2(flist);
    Indices rinds2(rlist);
    tdisp(finds2);
    tdisp(rinds2);
    Indices finds(flist);
    Indices rinds(rlist);
    tr.dat(rinds) = t.dat(finds);
    return;
  }

  index_type n = flatdims[flist.size()];
  for(index_type i = 0; i < n; i++) {
    flist.push_back(i);
    rlist.push_front(n-i-1);
    insideout_(t,tr,flatdims,flatrdims,flist,rlist);
    flist.pop_back();
    rlist.pop_front();
  }

  return;
  
}

template <class X, class E, typename D, int M, int R> 
auto& insideout(const TensorRW<X,E,D,M,R>& t) {
  
  typedef typename InversionType<X,Null>::Type Type;
  Type* tout = new Type();
  std::vector<Dimensions> ddims= t.deepdims();
  std::vector<Dimensions> rdims;

  // need to create the reverse dimensions
  for(int j=0; j < ddims.size(); j++) {
    rdims.push_back(ddims[ddims.size()-j-1]);
  }  
  tdisp(ddims);
  tdisp(rdims);
  tout->resize(rdims);
  tdisp(ddims);
  tdisp(rdims);

  
  //  flatten sizes into one vector
  std::vector<index_type> flatdims;
  for(int i=0; i < M; i++) {
    Dimensions dims = ddims[i];
    for(int j=0; j < dims.size(); j++) {
      flatdims.push_back(dims[j]);
    }
  }
  //  flatten sizes into one vector
  std::vector<index_type> flatrdims;
  for(int i=0; i < M; i++) {
    Dimensions dims = rdims[i];
    for(int j=0; j < dims.size(); j++) {
      flatrdims.push_back(dims[j]);
    }
  }
  tdisp(ddims);
  tdisp(rdims);
  tdisp(flatdims);
  tdisp(flatrdims);
  
  std::list<index_type> finds;
  std::list<index_type> rinds;
  insideout_(t.derived(),*tout,flatdims,flatrdims,finds,rinds);
  return *tout;
}

//  int Nindices = 0;
//  for(int i=0; i<ddims.size(); i++) {
//    Nindices += ddims[i].rank();
//  }


int main(int argc, char *argv[])
{

  const double pi = M_PI;
  std::string myname = argv[0];

  using namespace std;
  using namespace mathq;
  using namespace display;
  using namespace mathq::unit_imaginary;

  Style bold = createStyle(BOLD);
  Style blue = createStyle(BOLD+BLUE2);
  
  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  cr();
  cr();
  mout << StyledString::get(HORLINE);
  mout << "running: " <<bold.apply(myname) << std::endl;

  
  mout<< "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;
  
  print_mathq_info();



  



  cr();
  mout << StyledString::get(HORLINE);cr();
  //------------------------------------------------------

  cr();
  cr();
  mout << blue.apply("4- deep tests") << endl;

  {
    cr();
    mout << bold.apply("Scalar<Vector<Matrix<Tensor<double,3>,3,2>,4>>") << endl;
    Scalar<Vector<Matrix<Tensor<double,3>,3,2>,4>> x;
    tdisp(x);
    tdisp(x.dims());
    tdisp(x.size());
    tdisp(x.deepdims());
    Dimensions tdims(2,1,2);

    for (int h = 0; h < x().size(); h++) {
      const index_type NR = x()(h).Nrows();
      const index_type NC = x()(h).Ncols();
      for (int i = 0; i < NR; i++) {
	for (int j = 0; j < NC; j++) {
	  x()(h)(i,j).resize(tdims);
	  for (int k = 0; k < tdims[0]; k++) {
	    for (int l = 0; l < tdims[1]; l++) {
	      for (int m = 0; m < tdims[2]; m++) {
		x()(h)(i,j)(k,l,m) = double(100000*h)+double(10000*i)+double(1000*j)+double(100*k)+double(10*l)+double(m);
	      }
	    }
	  }
	}
      }
    }
    tdisp(x);
    tdisp(x.dims());
    tdisp(x.size());
    tdisp(x.deepdims());

    
  }
      
  {
    cr();
    cr();
 
    mout << "set via initializer_list" << endl;
    Scalar<Vector<Matrix<Tensor<double,3>,3,2>,4>> x {{{ {
{
  {
    {0, 1}
  },
  {
    {100, 101}
  }
}, 
{
  {
    {1000, 1001}
  },
  {
    {1100, 1101}
  }
}}, {
{
  {
    {10000, 10001}
  },
  {
    {10100, 10101}
  }
}, 
{
  {
    {11000, 11001}
  },
  {
    {11100, 11101}
  }
}}, {
{
  {
    {20000, 20001}
  },
  {
    {20100, 20101}
  }
}, 
{
  {
    {21000, 21001}
  },
  {
    {21100, 21101}
  }
}} }, { {
{
  {
    {100000, 100001}
  },
  {
    {100100, 100101}
  }
}, 
{
  {
    {101000, 101001}
  },
  {
    {101100, 101101}
  }
}}, {
{
  {
    {110000, 110001}
  },
  {
    {110100, 110101}
  }
}, 
{
  {
    {111000, 111001}
  },
  {
    {111100, 111101}
  }
}}, {
{
  {
    {120000, 120001}
  },
  {
    {120100, 120101}
  }
}, 
{
  {
    {121000, 121001}
  },
  {
    {121100, 121101}
  }
}} }, { {
{
  {
    {200000, 200001}
  },
  {
    {200100, 200101}
  }
}, 
{
  {
    {201000, 201001}
  },
  {
    {201100, 201101}
  }
}}, {
{
  {
    {210000, 210001}
  },
  {
    {210100, 210101}
  }
}, 
{
  {
    {211000, 211001}
  },
  {
    {211100, 211101}
  }
}}, {
{
  {
    {220000, 220001}
  },
  {
    {220100, 220101}
  }
}, 
{
  {
    {221000, 221001}
  },
  {
    {221100, 221101}
  }
}} }, { {
{
  {
    {300000, 300001}
  },
  {
    {300100, 300101}
  }
}, 
{
  {
    {301000, 301001}
  },
  {
    {301100, 301101}
  }
}}, {
{
  {
    {310000, 310001}
  },
  {
    {310100, 310101}
  }
}, 
{
  {
    {311000, 311001}
  },
  {
    {311100, 311101}
  }
}}, {
{
  {
    {320000, 320001}
  },
  {
    {320100, 320101}
  }
}, 
{
  {
    {321000, 321001}
  },
  {
    {321100, 321101}
  }
}} }}}; 

    tdisp(x);
    tdisp(x.dims());
    tdisp(x.size());
    tdisp(x.deepdims());


    Vector<Matrix<Tensor<double,3>,3,2>,4> v;
    v = x();
    tdisp(v);

    Matrix<Tensor<double,3>,3,2> m;
    m = x()(1);
    tdisp(m);

    Tensor<double,3> t;
    t = x()(1)(2,1);
    tdisp(t);
    tdisp(t.dims());
    tdisp(t(1,0,0));

    tdisp(x()(1)(2,1)(1,0,0));

    Indices inds({1,2,1,1,0,0});
    tdisp(inds);
    double y = x.dat(inds);
    tdisp(y);

    Vector<Scalar<double>,4> g1;
    tdisp(g1);
    Matrix<Vector<Scalar<double>,4>,3,2> g2;
    tdisp(g2);
    Tensor<Matrix<Vector<Scalar<double>,4>,3,2>,3> g3;
    tdisp(g3);
    tdisp(x.deepdims());
 
    g3 = insideout(x);
    tdisp(g3);

    for (int h = 0; h < x().size(); h++) {
      const index_type NR = x()(h).Nrows();
      const index_type NC = x()(h).Ncols();
      for (int i = 0; i < NR; i++) {
	for (int j = 0; j < NC; j++) {
	  Dimensions tdims =  x()(h)(i,j).dims();
	  for (int k = 0; k < tdims[0]; k++) {
	    for (int l = 0; l < tdims[1]; l++) {
	      for (int m = 0; m < tdims[2]; m++) {
		mdisp(h,i,j,k,l,m, x()(h)(i,j)(k,l,m), g3(k,l,m)(i,j)(h)());
	      }
	    }
	  }
	}
      }
    }
  }
  
  
    cr();
    mout << "done: " << bold.apply(myname) << std::endl;
    mout << StyledString::get(HORLINE);
    cr();
  
  return 0;
}
