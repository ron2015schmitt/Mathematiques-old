
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

  {
    Scalar<double> s = 1.1;
    tdisp(s);
    Scalar<double> s2;
    s2 = -s;
    tdisp(s2);
  }

  // {
  //   Vector<double> v {1.1,2.2};
  //   tdisp(v);
  //   Vector<double> v2;
  //   v2 = -v;
  //   tdisp(v2);
  // }

  // {
  //   Vector<double,2> v {1.1,2.2};
  //   tdisp(v);
  //   Vector<double,2> v2;
  //   v2 = -v;
  //   tdisp(v2);
  // }

  // {
  //   Matrix<double> m {{1.1,2.2},{3.3},{4.4}};
  //   tdisp(m);
  //   Matrix<double> m2;
  //   m2 = -m;
  //   tdisp(m2);
  // }
  
  // {
  //   Matrix<double,2,2> m {{1.1,2.2},{3.3},{4.4}};
  //   tdisp(m);
  //   Matrix<double,2,2> m2;
  //   m2 = -m;
  //   tdisp(m2);
  // }
  

  {
    Scalar<Scalar<double>> s {{1.1}};
    tdisp(s);
    Scalar<Scalar<double>> s2;
    s2 = -s;
    tdisp(s2);
  }


  
  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  
  return 0;
}
