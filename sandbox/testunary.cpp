
//#define MATHQ_DEBUG

#include "mathq.h" 

#include <fstream>





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
  mout << bold.apply("Scalar") << endl;
  {
    cr();
    Scalar<double> s = 1.1;
    tdisp(s);
    tdisp(s());
    tdisp(s.dims());
    tdisp(s.size());
    Scalar<double> s2;
    s2 = -s;
    tdisp(s2);
  }

  cr();
  cr();
  mout << bold.apply("Vector") << endl;
  {
    cr();
    Vector<double> v {1.1,2.2};
    tdisp(v);
    tdisp(v(0));
    tdisp(v.dims());
    tdisp(v.size());
    Vector<double> v2;
    v2 = -v;
    tdisp(v2);
  }

  {
    cr();
    Vector<double,2> v {1,2};
    tdisp(v);
    Vector<double,2> v2;
    v2 = -v;
    tdisp(v2);
  }

  cr();
  cr();
  mout << bold.apply("Matrix") << endl;
  {
    cr();
    Matrix<double> m0;
    tdisp(m0);
    
    Matrix<double> m {{1,2},{3,4}};
    tdisp(m);
    tdisp(m(0,0));
    tdisp(m.Nrows());
    tdisp(m.Ncols());
    tdisp(m.dims());
    Matrix<double> m2;
    tdisp(m2);
    m2 = -m;
    tdisp(m2);
  }
  cr();
  {
    Matrix<double,2,2> m {{1.1,2.2},{3.3,4.4}};
    tdisp(m);
    Matrix<double,2,2> m2;
    m2 = -m;
    tdisp(m2);
  }


  cr();
  cr();
  mout << bold.apply("Tensor -- Initializer lists") << endl;
  {
    cr();
    std::initializer_list<double> x1 {1,2};
    tdisp(x1);

    std::initializer_list<std::initializer_list<double>> x2 {{1,2},{3,4}};
    tdisp(x2);

    NestedInitializerList<double,1> y1 {1,2};
    tdisp(y1);

    NestedInitializerList<double,2> y2 {{1,2},{3,4}};
    tdisp(y2);
  }

  cr();
  cr();
  mout << bold.apply("Tensor") << endl;
  {
    cr();
    Tensor<double> t0;
    tdisp(t0.dims());
    tdisp(t0.eldims());
    tdisp(t0);
    Tensor<double,3> t1;
    tdisp(t1.dims());
    tdisp(t1.deepdims());
    tdisp(t1.deepsize());
    tdisp(t1.depth());
    tdisp(t1);
    Dimensions dims(3,2,5);
    Tensor<double,3> t2(dims);
    tdisp(t2.dims());
    tdisp(t2);
    for (int i = 0; i < t2.size(); i++) {
      t2[i] = double(i);
    }
    tdisp(t2);
    for (int i = 0; i < t2.dims()[0]; i++) {
      for (int j = 0; j < t2.dims()[1]; j++) {
	for (int k = 0; k < t2.dims()[2]; k++) {
	  t2(i,j,k) = double(100*i)+double(10*j)+double(k);
	  // mdisp(i,j,k,t2(i,j,k));
	}
      }
    }
    tdisp(t2);

    Tensor<double,1> t3 {1,2,3}; 
    tdisp(t3.dims());
    tdisp(t3.eldims());
    tdisp(t3);


    Tensor<double,2> t4 {{1.1,2.2},{3.3,4.4}};
    tdisp(t4.dims());
    tdisp(t4);

    Tensor<double,3> t5 {
      {{0, 1, 2, 3, 4},{10, 11, 12, 13, 14}},
    	{{100, 101, 102, 103, 104},{110, 111, 112, 113, 114}},
    	  {{200, 201, 202, 203, 204},{210, 211, 212, 213, 214}  } };
    
    tdisp(t5.dims());
    tdisp(t5(2,1,3));
    tdisp(t5);
  }

    
  cr();
  {
    Tensor<double,2> t {{1.1,2.2},{3.3,4.4}};
    tdisp(t);
    Tensor<double,2> t2;
    t2 = -t;
    tdisp(t2);
  }



  cr();
  cr();
  cr();
  cr();


  mout << blue.apply("Two-level tests") << endl;
  

  // -------------------------------------------------
  // two level tests
  // -------------------------------------------------

  cr();
  cr();
  mout << bold.apply("Two-Level Scalar tests") << endl;

  {
    cr();
    Scalar<Scalar<double>> s {{1.1}};
    tdisp(s);
    tdisp(s());
    tdisp(s()());
    tdisp(s.dims());
    tdisp(s.size());
    tdisp(s.deepdims());
    Scalar<Scalar<double>> s2;
    s2 = -s;
    tdisp(s2);
  }

  {
    cr();
    Scalar<Vector<double>> s {{1.,2.,3.}};
    tdisp(s);
    tdisp(s()(2));
    tdisp(s.dims());
    tdisp(s.size());
    tdisp(s.deepdims());
    Scalar<Vector<double>> s2;
    s2 = -s;  
    tdisp(s2);  
  }

  {   
    cr();
    Scalar<Matrix<double>> s {{{1,2},{3,4}}};
    tdisp(s);
    tdisp(s()(0,1));
    tdisp(s.dims());
    tdisp(s.size());
    tdisp(s.deepdims());

    Scalar<Matrix<double>> s2;
    s2 = -s;  
    tdisp(s2);  
  }

  {   
    cr();
    Scalar<Tensor<double,2>> s {{{1,2},{3,4}}};
    tdisp(s);
    tdisp(s());
    tdisp(s()(0,1));
    tdisp(s.dims());
    tdisp(s.size());
    tdisp(s().dims());
    tdisp(s.depth());
    tdisp(s.deepdims());

    Scalar<Tensor<double,2>> s2;
    s2 = -s;  
    tdisp(s2);
    
  }

  cr();
  cr();
  mout << bold.apply("Two-Level Vector tests") << endl;
  {
    cr();
    Vector<Scalar<double>> v {{1.},{2.}};
    tdisp(v);
    tdisp(v(0));
    tdisp(v(0)());
    tdisp(v.dims());
    tdisp(v.size());
    tdisp(v.deepdims());
    Vector<Scalar<double>> v2;
    v2 = -v;
    tdisp(v2);
  }

  {
    cr();
    Vector<Vector<double>> v {{1.,2.,3.},{4.,5.,6.}};
    tdisp(v);
    tdisp(v(0));
    tdisp(v(0)(2));
    tdisp(v.dims());
    tdisp(v.size());
    tdisp(v.deepdims());
    Vector<Vector<double>> v2;
    mout << "v2 = -v;" << endl;
    v2 = -v;
    tdisp(v2);
  }
  {
    cr();
    Vector<Matrix<double>> v { {{1,2},{3,4}}, {{5,6},{7,8}}, {{9,10},{11,12}} };
    tdisp(v);
    tdisp(v(0));
    tdisp(v(1)(0,1));
    tdisp(v.dims());
    tdisp(v.size());
    tdisp(v.deepdims());
    Vector<Matrix<double>> v2;
    mout << "v2 = -v;" << endl;
    v2 = -v;
    tdisp(v2);
  }
  {
    cr();
    Vector<Tensor<double,2>> v { {{1,2},{3,4}}, {{5,6},{7,8}}, {{9,10},{11,12}} };
    tdisp(v);
    tdisp(v(0));
    tdisp(v(2)(1,1));
    tdisp(v.dims());
    tdisp(v.size());
    tdisp(v.deepdims());
    Vector<Tensor<double,2>> v2;
    mout << "v2 = -v;" << endl;
    v2 = -v;
    tdisp(v2);
  }


  cr();
  cr();
  mout << bold.apply("Two-Level Matrix tests") << endl;
  {
    cr();
    Matrix<Scalar<double>> m {{{1},{2}},{{3},{4}}};;
    tdisp(m);
    tdisp(m(0,0));
    tdisp(m(0,0)());
    tdisp(m.Nrows());
    tdisp(m.Ncols());
    tdisp(m.dims());
    tdisp(m.deepdims());
    Matrix<Scalar<double>> m2;
    m2 = -m;
    tdisp(m2);
  }

  {
    cr();
    Matrix<Vector<double>> m {{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
    tdisp(m);
    tdisp(m(0,0));
    tdisp(m(0,0)(1));
    tdisp(m.Nrows());
    tdisp(m.Ncols());
    tdisp(m.dims());
    tdisp(m.deepdims());
    Matrix<Vector<double>> m2;
    mout << "m2 = -m;" << endl;
    m2 = -m; 
    tdisp(m2);
  }

  {
    cr();
    Matrix<Matrix<double>> m  {
      { {{1,2},{3,4}}, {{5,6},{7,8}} },
	{ {{9,10},{11,12}}, {{13,14},{15,16}} }
    };
    tdisp(m);
    tdisp(m(0,0));
    tdisp(m(0,0)(1,1));
    tdisp(m.dims());
    tdisp(m.size());
    tdisp(m.deepdims());
    Matrix<Matrix<double>> m2;
    mout << "m2 = -m;" << endl;
    m2 = -m;
    tdisp(m2);
  }

  {
    cr();
    Matrix<Tensor<double,3>,2,2> m1;
    tdisp(m1);
    tdisp(m1.dims());
    tdisp(m1.size());
    tdisp(m1.deepdims());
    Dimensions tdims(2,3,2);

    for (int i = 0; i < m1.dims()[0]; i++) {
      for (int j = 0; j < m1.dims()[1]; j++) {
	m1(i,j).resize(tdims);
	for (int k = 0; k < tdims[0]; k++) {
	  for (int l = 0; l < tdims[1]; l++) {
	    for (int m = 0; m < tdims[2]; m++) {
	      m1(i,j)(k,l,m) = double(10000*i)+double(1000*j)+double(100*k)+double(10*l)+double(m);
	    }
	  }
	}
      }
    }
    tdisp(m1);
    tdisp(m1(0,1));
    tdisp(m1(1,0)(1,2,0));
    tdisp(m1.dims());
    tdisp(m1.size());
    tdisp(m1.deepdims());


    Matrix<Tensor<double,3>> m2;
    mout << "m2 = -m1;" << endl;
    m2 = -m1;
    tdisp(m2);
  }

  {
    cr();
    Matrix<Tensor<double,3>,2,2> m1 { {
	{
	  {
	    {-0, -1},
	      {-10, -11},
		{-20, -21}
	  },
	    {
	      {-100, -101},
		{-110, -111},
		  {-120, -121}
	    }
	}, 
	  {
	    {
	      {-1000, -1001},
		{-1010, -1011},
		  {-1020, -1021}
	    },
	      {
		{-1100, -1101},
		  {-1110, -1111},
		    {-1120, -1121}
	      }
	  }}, {
	{
	  {
	    {-10000, -10001},
	      {-10010, -10011},
		{-10020, -10021}
	  },
	    {
	      {-10100, -10101},
		{-10110, -10111},
		  {-10120, -10121}
	    }
	}, 
	  {
	    {
	      {-11000, -11001},
		{-11010, -11011},
		  {-11020, -11021}
	    },
	      {
		{-11100, -11101},
		  {-11110, -11111},
		    {-11120, -11121}
	      }
	  }} };

    tdisp(m1);
    tdisp(m1.dims());
    tdisp(m1.size());
    tdisp(m1.deepdims());
    
  }


  /////////////////////////////////////////////////////////////////


  
  cr();
  cr();
  mout << bold.apply("Two-Level Tensor tests") << endl;
  {
    cr();
    Tensor<Scalar<double>,2> t;
    tdisp(t);
    tdisp(t.dims());
    tdisp(t.deepdims());
    Dimensions tdims(2,2);
    t.resize(tdims);
    t(0,0) = 1;
    t(0,1) = 2;
    t(1,0) = 3;
    t(1,1) = 4;
    tdisp(t);
    tdisp(t.dims());
    tdisp(t.deepdims());
    tdisp(t.eldims());
  }
  {
    
    cr();
    Tensor<Scalar<double>,2> t {{{1},{2}},{{3},{4}}};
    tdisp(t);
    tdisp(t(1,0));
    tdisp(t(1,0)());
    tdisp(t.dims());
    tdisp(t.deepdims());
    tdisp(t.eldims());
    typename decltype(t)::DType d;
    tdisp(d);
    typename decltype(t)::EType e;
    tdisp(e);

    Tensor<Scalar<double>,2> t2;
    typename Tensor<Scalar<double>,2>::DType d2a;
    tdisp(d2a);
    typename Tensor<Scalar<double>,2>::EType e2a;
    tdisp(e2a);
    typename decltype(t2)::DType d2b;
    tdisp(d2b);
    typename decltype(t2)::EType e2b;
    tdisp(e2b);
    t2 = -t;
    tdisp(t2);
  }

  {
    cr();
    Tensor<Vector<double>,2> t {{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
    tdisp(t);
    tdisp(t(0,0));
    tdisp(t(0,0)(1));
    tdisp(t.dims());
    tdisp(t.deepdims());
    Tensor<Vector<double>,2> t2;
    mout << "t2 = -t;" << endl;
    t2 = -t; 
    tdisp(t2);
  }

  {
    cr();
    Tensor<Matrix<double,2,2>,2> m  {
      { {{1,2},{3,4}}, {{5,6},{7,8}} },
  	{ {{9,10},{11,12}}, {{13,14},{15,16}} }
    };
    tdisp(m);
    tdisp(m(0,0));
    tdisp(m(0,0)(1,1));
    tdisp(m.dims());
    tdisp(m.size());
    tdisp(m.deepdims());
    Tensor<Matrix<double,2,2>,2> m2;
    mout << "m2 = -m;" << endl;
    m2 = -m;
    tdisp(m2);
  }

  {
    cr();
    Tensor<Tensor<double,3>,2> m1;
    tdisp(m1);
    tdisp(m1.dims());
    tdisp(m1.size());
    tdisp(m1.deepdims());
    Dimensions tdims1(2,2);
    m1.resize(tdims1);
    Dimensions tdims2(2,3,2);

    for (int i = 0; i < m1.dims()[0]; i++) {
      for (int j = 0; j < m1.dims()[1]; j++) {
  	m1(i,j).resize(tdims2);
  	for (int k = 0; k < tdims2[0]; k++) {
  	  for (int l = 0; l < tdims2[1]; l++) {
  	    for (int m = 0; m < tdims2[2]; m++) {
  	      m1(i,j)(k,l,m) = double(10000*i)+double(1000*j)+double(100*k)+double(10*l)+double(m);
  	    }
  	  }
  	}
      }
    }
    tdisp(m1);
    tdisp(m1(0,1));
    tdisp(m1(1,0)(1,2,0));
    tdisp(m1.dims());
    tdisp(m1.size());
    tdisp(m1.deepdims());


    Tensor<Tensor<double,3>,2> m2;
    mout << "m2 = -m1;" << endl;
    m2 = -m1;
    tdisp(m2);
  }

  {
    cr();
    Tensor<Tensor<double,3>,2> m1 { {
  	{
  	  {
  	    {-0, -1},
  	      {-10, -11},
  		{-20, -21}
  	  },
  	    {
  	      {-100, -101},
  		{-110, -111},
  		  {-120, -121}
  	    }
  	}, 
  	  {
  	    {
  	      {-1000, -1001},
  		{-1010, -1011},
  		  {-1020, -1021}
  	    },
  	      {
  		{-1100, -1101},
  		  {-1110, -1111},
  		    {-1120, -1121}
  	      }
  	  }}, {
  	{
  	  {
  	    {-10000, -10001},
  	      {-10010, -10011},
  		{-10020, -10021}
  	  },
  	    {
  	      {-10100, -10101},
  		{-10110, -10111},
  		  {-10120, -10121}
  	    }
  	}, 
  	  {
  	    {
  	      {-11000, -11001},
  		{-11010, -11011},
  		  {-11020, -11021}
  	    },
  	      {
  		{-11100, -11101},
  		  {-11110, -11111},
  		    {-11120, -11121}
  	      }
  	  }} };

    tdisp(m1);
    tdisp(m1.dims());
    tdisp(m1.size());
    tdisp(m1.deepdims());
    
  }

  


  
  
  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  
  return 0;
}
