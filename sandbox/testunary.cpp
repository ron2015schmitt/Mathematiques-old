
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
    mout << "Scalar" << endl;
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
    mout << "Vector" << endl;
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
  mout << "Scalar" << endl;
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
  


  // -------------------------------------------------
  // two level tests
  // -------------------------------------------------

    cr();
    cr();
    mout << "Two-Level Scalar tests" << endl;

  {
    cr();
    Scalar<Scalar<double>> s {{1.1}};
    tdisp(s);
    tdisp(s());
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
    tdisp(s());
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
    tdisp(s());
    tdisp(s.dims());
    tdisp(s.size());
    tdisp(s.deepdims());

    Scalar<Matrix<double>> s2;
    s2 = -s;  
    tdisp(s2);  
  }


    cr();
    cr();
    mout << "Two-Level Vector tests" << endl;
  {
    cr();
    Vector<Scalar<double>> v {{1.},{2.}};
    tdisp(v);
    tdisp(v(0));
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
    tdisp(v.dims());
    tdisp(v.size());
    tdisp(v.deepdims());
    Vector<Matrix<double>> v2;
    mout << "v2 = -v;" << endl;
    v2 = -v;
    tdisp(v2);
  }

    cr();
    cr();
    mout << "Two-Level Matrix tests" << endl;
  {
    cr();
    Matrix<Scalar<double>> m {{{1},{2}},{{3},{4}}};;
    tdisp(m);
    tdisp(m(0,0));
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
    tdisp(m.dims());
    tdisp(m.size());
    tdisp(m.deepdims());
    Matrix<Matrix<double>> m2;
    mout << "m2 = -m;" << endl;
    m2 = -m;
    tdisp(m2);
  }

  
  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  
  return 0;
}
