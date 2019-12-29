
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

  FormatData<bool>::string_for_true = "true";
  FormatData<bool>::string_for_false = "false";
  

  cr();
  cr();
  mout << StyledString::get(HORLINE);
  mout << "running: " <<bold.apply(myname) << std::endl;

  
  mout<< "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;
  
  print_mathq_info();


  cr();
  mout << StyledString::get(HORLINE);cr();
  //------------------------------------------------------


  mout << bold.apply("join") << endl;
  cr();

  {
    Vector<int> Vi {11,12,-100};
    Vector<double> Vd1 {1,2,3};
    Vector<double> Vd2 {3.1,4.1,5.1,6.1};
    mout << blue.apply("Given:") << endl;
    mout<<"  ";tdisp(Vi);
    mout<<"  ";tdisp(Vd1);
    mout<<"  ";tdisp(Vd2);
    cr();

    mout << blue.apply("LHS tests--join") << endl;
    mout<<"  ";tdisp(join(Vd1,Vd1));
    mout<<"  ";tdisp(join(Vd1,Vd2));
    mout << blue.apply("LHS tests--comma") << endl;
    mout<<"  ";tdisp((Vd1,Vd2));
    mout<<"  ";tdisp((Vd2,Vd1,Vd2));
    
    mout << blue.apply("LHS tests") << endl;
    Vector<double> Vd4 = {21,22,23,24,25,26,27};
    mdisp(Vd1,Vd2);
    (Vd1,Vd2) = Vd4;
    mdisp(Vd1,Vd2);

    
  }


  
  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  
  return 0;
}
