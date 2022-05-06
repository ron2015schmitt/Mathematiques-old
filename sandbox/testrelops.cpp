#include <fstream>

#define MATHQ_DEBUG 0
#include "mathq.h"


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


  CR();
  CR();
  MOUT << StyledString::get(HORLINE);
  MOUT << "running: " << bold.apply(myname) << std::endl;


  MOUT << "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;

  print_mathq_info();


  CR();
  MOUT << StyledString::get(HORLINE);
  CR();
  //------------------------------------------------------


  MOUT << bold.apply("Relational operator tests") << endl;
  CR();

  MOUT << blue.apply("Vector-Vector tests") << endl;
  {
    using namespace mathq::unit_imaginary;
    CR();
    Vector<int> Vint1{11, 12, -13};
    Vector<int> Vint2{1, 12, 6};
    Vector<int> Vint3{11, 12, -13};
    Vector<int> Vint4{10, 11, -14};
    Vector<double> Vd1{0.1, 1, 10};
    Vector<double> Vd2{3.14, 2.2, 10};
    Vector<double> Vf1{0.1, 1, 10};
    MOUT << blue.apply("Given:") << endl;
    MOUT << "  ";
    tdisp(Vint1);
    MOUT << "  ";
    tdisp(Vint2);
    MOUT << "  ";
    tdisp(Vint3);
    MOUT << "  ";
    tdisp(Vint4);
    MOUT << "  ";
    tdisp(Vd1);
    MOUT << "  ";
    tdisp(Vd2);
    MOUT << "  ";
    tdisp(Vf1);
    CR();
    MOUT << blue.apply("Vector==Vector") << endl;
    MOUT << "  ";
    tdisp(Vint1 == Vint2);
    MOUT << "  ";
    tdisp(Vint1 != Vint2);
    MOUT << "  ";
    tdisp(Vint1 > Vint2);
    MOUT << "  ";
    tdisp(Vint1 >= Vint2);
    MOUT << "  ";
    tdisp(Vint1 < Vint2);
    MOUT << "  ";
    tdisp(Vint1 <= Vint2);
    MOUT << "  ";
    tdisp(Vint1 == Vint3);
    MOUT << "  ";
    tdisp(Vint3 == Vint1);
    MOUT << "  ";
    tdisp(Vint1 == Vint1);
    MOUT << "  ";
    tdisp(Vd1 == Vf1);
    MOUT << "  ";
    tdisp(Vd1 > 1);

    CR();
    MOUT << "  ";
    tdisp(Vd1 == Vd2);
    MOUT << "  ";
    tdisp(Vint1 == 12);
    MOUT << "  ";
    tdisp((Vd1 == Vd2) && (Vint1 == 12));
    MOUT << "  ";
    tdisp((Vd1 == Vd2) || (Vint1 == 12));
    CR();
    MOUT << "  ";
    tdisp(Vint1 == (Vint4 + 1));
    MOUT << "  ";
    tdisp((Vint1 + Vint2) + (Vint3 + Vint4));

    CR();
    MOUT << "  ";
    tdisp(pow(Vd1, 2));
    MOUT << "  ";
    tdisp(pow(Vd1, 2.3));
    MOUT << "  ";
    tdisp(pow(Vd1, Vint1));
    MOUT << "  ";
    tdisp(pow((Vint1 + Vint2) + (Vint3 + Vint4), 2));
  }
  MOUT << bold.apply("binary function tests") << endl;
  CR();

  MOUT << blue.apply("Vector-Vector tests") << endl;
  {
    using namespace mathq::unit_imaginary;
    CR();
    Vector<int> Vint1{1, 2, 3};
    Vector<double> Vd1{0.1, 0.5, 0.2};
    Vector<double> Vd2{0.1, 0.25, 0.4};

    CR();
    MOUT << "  ";
    tdisp(atan2(Vd1, Vd2));
    MOUT << "  ";
    tdisp(beta(Vd1, Vd2));

    MOUT << "  ";
    tdisp(ellint_1(0.25, Vd2));
    MOUT << "  ";
    tdisp(ellint_2(0.1, Vd2));

    MOUT << "  ";
    tdisp(legendre(2, Vd2));
    MOUT << "  ";
    tdisp(laguerre(2, Vd2));
    MOUT << "  ";
    tdisp(hermite(2, Vd2));

    MOUT << "  ";
    tdisp(sph_bessel(2, Vd2));
    MOUT << "  ";
    tdisp(sph_neumann(2, Vd2));

    MOUT << "  ";
    tdisp(cyl_bessel_i(2, Vd2));
    MOUT << "  ";
    tdisp(cyl_bessel_j(2, Vd2));
    MOUT << "  ";
    tdisp(cyl_bessel_k(2, Vd2));
  }
  return 0;




  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
