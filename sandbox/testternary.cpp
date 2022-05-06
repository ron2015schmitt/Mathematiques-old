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


  MOUT << bold.apply("Addition tests") << endl;
  CR();

  {
    int s = -10;
    unsigned int u = 5;

    tdisp(s);
    tdisp(u);
    tdisp(s + u);
    CR();
  }
  MOUT << blue.apply("Vector-Vector tests") << endl;
  {
    using namespace mathq::unit_imaginary;
    CR();
    Vector<short> Vshort{-11, -12, 13};
    Vector<int> Vint1{11, 12, -13};
    Vector<int> Vint2{11, 12, -100};
    Vector<long> vLong{1000, 2000, -3000};
    Vector<unsigned> Vunsigned{70, 80, 90};
    Vector<unsigned> Vl{3, 2, 4};
    Vector<int> Vm{0, 1, 3};
    Vector<double> Vdouble1{1.1, 0.5, M_PI / 4};
    Vector<double> Vdouble2{1, 2, 3};
    Vector<float> Vfloat{0.1, .2, .3};
    Vector<long double> Vextended{0.01, .02, .03};
    Vector<Imaginary<double>> vImagDouble{1 * i, 2 * i, 3 * i};
    Vector<Imaginary<long double>> vImagExtended{10 * iL, 20 * iL, 30 * iL};
    Vector<complex<double>> VcomplexDouble{complex<double>(0.1, 0.001), complex<double>(0.2, 0.002), complex<double>(0.3, 0.003)};
    Vector<complex<int>> VcomplexInt{complex<int>(1, -2), complex<int>(1, 0), complex<int>(0, 1)};
    MOUT << blue.apply("Given:") << endl;
    MOUT << "  ";
    tdisp(Vshort);
    MOUT << "  ";
    tdisp(Vint1);
    MOUT << "  ";
    tdisp(Vint2);
    MOUT << "  ";
    tdisp(vLong);
    MOUT << "  ";
    tdisp(Vunsigned);
    MOUT << "  ";
    tdisp(Vl);
    MOUT << "  ";
    tdisp(Vm);
    MOUT << "  ";
    tdisp(Vdouble1);
    MOUT << "  ";
    tdisp(Vdouble2);
    MOUT << "  ";
    tdisp(Vfloat);
    MOUT << "  ";
    tdisp(Vextended);
    CR();
    MOUT << blue.apply("Vector,Vector,Vector") << endl;
    tdisp(std::sph_legendre(3, 0, 1.2345));
    tdisp(sph_legendre(Vl, Vm, Vdouble1));
    tdisp(sph_legendre(Vl, Vm, 1.2345));
    tdisp(sph_legendre(Vl, 0, Vdouble1));
    tdisp(sph_legendre(Vl, 3, 1.2345));
    tdisp(sph_legendre(3, Vm, Vdouble1));
    tdisp(sph_legendre(3, 0, Vdouble1));
    tdisp(sph_legendre(3, Vm, 1.2345));
    //    tdisp(sph_legendre(3,Vm,Vdouble1));
    CR();

    short sh = 2;
    int n = 10;
    long longo = 1000;
    unsigned u = 5;
    double dub = 0.5;
    float f = 0.001;
    long double e = 3.14;

    MOUT << blue.apply("Given:") << endl;
    MOUT << "  ";
    tdisp(sh);
    MOUT << "  ";
    tdisp(n);
    MOUT << "  ";
    tdisp(longo);
    MOUT << "  ";
    tdisp(u);
    MOUT << "  ";
    tdisp(dub);
    MOUT << "  ";
    tdisp(f);
    MOUT << "  ";
    tdisp(e);

    CR();
    MOUT << blue.apply("Vector,Vector,scalar :") << endl;
  }



  CR();
  CR();
  MOUT << bold.apply("Two-Level Vector tests") << endl;



  CR();
  CR();

  {
    CR();
    Matrix<Vector<double>> m1{{{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9}, {10, 11, 12}}};
    Vector<double> v0{100, 200, 300};
    MOUT << blue.apply("Given:") << endl;
    MOUT << "  ";
    tdisp(m1);
    MOUT << "  ";
    tdisp(v0);
    CR();

    MOUT << "element-wise addition is chosen, since the elements are Vectors" << endl;
    MOUT << "  ";
    tdisp(m1 + v0);
    MOUT << "  ";
    tdisp(v0 + m1);

    CR();
    MOUT << "Element-access:" << endl;
    MOUT << "  ";
    tdisp(m1[0]);
    MOUT << "  ";
    tdisp((m1 + v0)[0]);
    MOUT << "  ";
    tdisp((v0 + m1)[0]);
  }


  {
    CR();
    Vector<Matrix<double>> v1{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 12}}};
    Vector<double> v0{100, 200, 300};

    MOUT << blue.apply("Given:") << endl;
    MOUT << "  ";
    tdisp(v1);
    MOUT << "  ";
    tdisp(v0);

    CR();
    MOUT << "Top-level addition is chosen, since the top-level is a vector" << endl;
    MOUT << "  ";
    tdisp(v1 + v0);
    MOUT << "  ";
    tdisp(v0 + v1);

    CR();
    MOUT << "Element-access:" << endl;
    MOUT << "  ";
    tdisp(v1[1]);
    MOUT << "  ";
    tdisp((v1 + v0)[1]);
    MOUT << "  ";
    tdisp((v0 + v1)[1]);
  }



  // {
  //   CR();
  //   CR();

  //   Vector<Vector<double>> v1 {{1,2,3},{4,5,6}};
  //   Vector<double> v0 {10,20,30};
  //   string s;
  //   MOUT << blue.apply("Given:") << endl;
  //   MOUT<<"  ";tdisp(v1);
  //   MOUT<<"  ";tdisp(v0);
  //   CR();
  //   MOUT << "By analysing the dimensions element-wise addition is chosen" << endl;
  //   MOUT<<"  ";tdisp(v1+v0);
  //   MOUT<<"  ";tdisp(v0+v1);

  //   CR();
  //   MOUT << "Element-access:" << endl;
  //   MOUT<<"  ";tdisp(v1[1]);
  //   MOUT<<"  ";tdisp((v1+v0)[1]);
  //   MOUT<<"  ";tdisp((v0+v1)[1]);

  //   CR();
  //   CR();
  //   Vector<double> v00 {100,200};
  //   MOUT << blue.apply("Given:") << endl;

  //   MOUT<<"  ";tdisp(v1);
  //   MOUT<<"  ";tdisp(v00);
  //   CR();
  //   MOUT << "By analysing the dimensions top-level addition is chosen" << endl;
  //   MOUT<<"  ";tdisp(v1+v00);
  //   MOUT<<"  ";tdisp(v00+v1);

  //   CR();
  //   MOUT << "Element-access:" << endl;
  //   MOUT<<"  ";tdisp(v1[1]);
  //   MOUT<<"  ";tdisp((v1+v00)[1]);
  //   MOUT<<"  ";tdisp((v00+v1)[1]);
  // }


  // CR();
  //   CR();
  // MOUT << bold.apply("When dimensions and rank are the same, the result depends on order, ie non-commutative") << endl;
  // {
  //   CR();
  //   Vector<Vector<double>> v1 {{1,2},{4,5}};
  //   MOUT<<"  ";tdisp(v1);
  //   Vector<double> v0 {10,20};
  //   MOUT<<"  ";tdisp(v0);
  //   CR();
  //   MOUT << "Adding from the right yields element-wise: each element of v1 is added with v0" << endl;
  //   MOUT<<"  ";tdisp(v1+v0);
  //   CR();
  //   MOUT << "Adding from the left yields Top-level: add v0[0] to vector v1[0], add v0[1] to vector v1[1]" << endl;
  //   MOUT<<"  ";tdisp(v0+v1);

  //   CR();
  //   MOUT << "Element-access:" << endl;
  //   MOUT<<"  ";tdisp(v1[1]);
  //   MOUT<<"  ";tdisp((v1+v0)[1]);
  //   MOUT<<"  ";tdisp((v0+v1)[1]);
  //   CR();
  // }




  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
