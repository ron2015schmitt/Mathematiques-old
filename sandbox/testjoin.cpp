
#include <fstream>

#define MATHQ_DEBUG 0
#include "mathq.h"
#include "macros.h"


int main(int argc, char *argv[]) {

  const double pi = M_PI;
  std::string myname = argv[0];

  using namespace std;
  using namespace mathq;
  using namespace display;
  using namespace mathq::unit_imaginary;

  Style bold = CREATESTYLE(BOLD);
  Style blue = CREATESTYLE(BOLD + BLUE2);

  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  FormatData<bool>::string_for_true = "true";
  FormatData<bool>::string_for_false = "false";


  cr();
  cr();
  mout << StyledString::get(HORLINE);
  mout << "running: " << bold.apply(myname) << std::endl;


  mout << "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;

  print_mathq_info();


  cr();
  mout << StyledString::get(HORLINE);
  cr();
  //------------------------------------------------------


  mout << bold.apply("join") << endl;
  cr();

  {
    Vector<int> Vi{11, 12, -100};
    Vector<double> Vd1{1, 2};
    Vector<double> Vd2{3, 4, 5};
    Vector<double> Vd3{6, 7, 8, 9};
    mout << blue.apply("Given:") << endl;
    mout << "  ";
    tdisp(Vi);
    mout << "  ";
    tdisp(Vd1);
    mout << "  ";
    tdisp(Vd2);
    mout << "  ";
    tdisp(Vd3);
    cr();

    mout << blue.apply("LHS tests--join") << endl;
    mout << "  ";
    tdisp(join(Vd1, Vd1));
    mout << "  ";
    tdisp(join(Vd1, Vd2));
    mout << blue.apply("LHS tests--comma") << endl;
    mout << "  ";
    tdisp((Vd1, Vd2));
    mout << "  ";
    tdisp((Vd1, Vd2, Vd3));
    mout << "  ";
    tdisp(join((Vd1, Vd2), Vd3));


    mout << blue.apply("LHS tests") << endl;
    Vector<double> Vd4 = {11, 12, 13, 14, 15};
    Vector<double> Vd5 = {21, 22, 23, 24, 25, 26, 27, 28, 29};
    mout << "Initial values: " << endl;
    mout << " ";
    mdisp(Vd1, Vd2, Vd3);
    mout << blue.apply("(Vd1,Vd2) = Vd4") << endl;
    (Vd1, Vd2) = Vd4;
    mout << " ";
    disp(Vd4);
    mout << " ";
    mdisp(Vd1, Vd2);
    mout << blue.apply("(Vd1,Vd2,Vd3) = Vd5") << endl;
    (Vd1, Vd2, Vd3) = Vd5;
    mout << " ";
    disp(Vd5);
    mout << " ";
    mdisp(Vd1, Vd2, Vd3);

    tdisp(IsTensorRW<mathq::TER_Join<mathq::TensorR<mathq::TensorRW<mathq::TERW_Subset<double>, double, double, 1, 1>, double, double, 1, 1>, mathq::TensorR<mathq::TensorRW<mathq::Vector<double>, double, double, 1, 1>, double, double, 1, 1>, double, double, 1>>::value);

    tdisp(IsTensorRW<mathq::TensorR<mathq::TensorRW<mathq::TERW_Subset<double>, double, double, 1, 1>, double, double, 1, 1>>::value);

    tdisp(IsTensorRW<mathq::TERW_Join<mathq::TensorRW<mathq::Vector<double>, double, double, 1, 1>, mathq::TensorRW<mathq::Vector<double>, double, double, 1, 1>, double, double, 1>>::value);
  }



  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();

  return 0;
}
