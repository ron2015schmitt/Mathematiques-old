
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
    InversionType<Scalar<double>,Null>::Type s {4};
    tdisp(s);
    InversionType<Vector<double>,Null>::Type v {1,2,3,4};
    tdisp(v);
    InversionType<Scalar<Vector<double>>,Null>::Type vs {{1},{2},{3},{4}};
    tdisp(vs);
    Scalar<Vector<double>> sv  {{1,2,3,4}};
    tdisp(sv);
    InversionType<decltype(sv),Null>::Type vs2;
    tdisp(vs2);
  }
  

  


  
  
  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  
  return 0;
}
