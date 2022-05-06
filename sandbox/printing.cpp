#include <vector>

#define MATHQ_DEBUG 0
#include "mathq.h"
#include "macros.h"


int main(int argc, char *argv[]) {
  const double pi = M_PI;
  std::string myname = argv[0];
  using namespace mathq;
  using namespace display;

  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  cr();
  cr();
  mout << StyledString::get(HORLINE);
  mout << "running: " << CREATESTYLE(BOLD).apply(myname) << std::endl;


  mout << "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;

  print_mathq_info();


  int n = 45;
  unsigned int m = 256;
  double x = 3.14;
  double vals[] = {1.1, 2.2, 3.3};
  bool done = true;
  Vector<double> v = range<double>(1, 10);
  Matrix<double> A(2, 2, {1, 2, 3, 4});
  char str[] = "hello";
  std::string s = "world";
  ComplexDouble z(1, -1);


  cr();
  cr();
  disp(n);
  disp(m);
  disp(x);
  disp(vals);
  disp(done);
  disp(v);
  disp(A);
  disp(str);
  disp(s);
  disp(z);

  cr();
  cr();
  tdisp(n);
  tdisp(m);
  tdisp(x);
  tdisp(vals);
  tdisp(done);
  tdisp(v);
  tdisp(A);
  tdisp(str);
  tdisp(s);
  tdisp(z);

  cr();
  cr();
  mdisp(n, m, x, vals, done, str, s, z);

  cr();
  cr();
  dispval(n);
  dispval(m);
  dispval(A);

  cr();
  cr();
  disp(n + 3);
  disp(10 * x - 1);
  disp(!done);
  disp(round(10 * sin(pi / 10 * v) + 10));
  disp(s + " tour");
  mout << std::endl;

  mout << CREATESTYLE(GRAY1) << "  ";
  mout << CREATESTYLE(GRAY2) << "  ";
  mout << CREATESTYLE(WHITE + BLACKBACK) << "  ";
  mout << std::endl;

  mout << CREATESTYLE(RED) << "  ";
  mout << std::endl;
  mout << CREATESTYLE(ORANGE) << "  ";
  mout << std::endl;
  mout << CREATESTYLE(YELLOW) << "  ";
  mout << CREATESTYLE(YELLOWBRIGHT) << "  ";
  mout << std::endl;
  mout << CREATESTYLE(GREEN) << "  ";
  mout << CREATESTYLE(GREENBRIGHT) << "  ";
  mout << CREATESTYLE(GREEN1) << "  ";
  mout << std::endl;
  mout << CREATESTYLE(CYAN) << "  ";
  mout << CREATESTYLE(BLUE) << "  ";
  mout << CREATESTYLE(BLUEBRIGHT) << "  ";
  mout << CREATESTYLE(BLUE1) << "  ";
  mout << CREATESTYLE(BLUE2) << "  ";
  mout << CREATESTYLE(BLUE3) << "  ";
  mout << std::endl;
  mout << CREATESTYLE(MAGENTA) << "  ";
  mout << CREATESTYLE(MAGENTA1) << "  ";
  mout << CREATESTYLE(VIOLET1) << "  ";
  mout << std::endl;
  mout << CREATESTYLE(BOLD) << "  ";
  mout << CREATESTYLE(UNDERLINE) << "  ";
  mout << CREATESTYLE(CROSSEDOUT) << "  ";
  mout << CREATESTYLE(OVERLINE) << "  ";
  mout << CREATESTYLE(SLOWBLINK) << "  ";
  mout << std::endl;

  mout << CREATESTYLE(REDBACK) << "  ";
  mout << CREATESTYLE(ORANGEBACK) << "  ";
  mout << CREATESTYLE(YELLOWBACK) << "  ";
  mout << CREATESTYLE(GREENBACK) << "  ";
  mout << std::endl;
  mout << std::endl;
  mout << std::endl;

  mout << CREATESTYLE(BOLD + UNDERLINE + VIOLET1) << "  ";
  mout << std::endl;
  mout << std::endl;
  mout << std::endl;
  mout << std::endl;

  {
    Style mystyle = CREATESTYLE(BOLD + RED);
    mout << mystyle.apply("with style") + " without style " << std::endl;
  }
  mout << std::endl;
  mout << std::endl;
  mout << std::endl;

  {
    int nf = 27;  // color for foreground
    int nb = 227; // color for background
    Style mystyle(nf, nb);
    mout << mystyle.apply("Hello World") << std::endl;

    mout << std::endl;
    mout << std::endl;
    mout << std::endl;


    Style bold(BOLD);
    Style mybold = bold + mystyle;
    mout << mybold.apply("Hello World") << std::endl;

    Style black(BLACK);
    mout << "XXX" << black.apply("XXX") << "XXX" << std::endl;
  }


  cr();
  mout << "done: " << CREATESTYLE(BOLD).apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();


  return 0;
}
