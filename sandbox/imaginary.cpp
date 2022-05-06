#include <vector>
#include <string>

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

  Style bold = createStyle(BOLD);

  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  cr();
  cr();
  mout << StyledString::get(HORLINE);
  mout << "running: " << bold.apply(myname) << std::endl;


  mout << "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;

  print_mathq_info();


  {
    cr();
    tdisp(i);
    Imaginary<double> x(2);
    Imaginary<int> y(3);
    std::complex<float> z(1, 1);

    tdisp(x);
    tdisp(y);
    tdisp(numbercast<Imaginary<float>>(y));

    tdisp(+x);
    tdisp(-x);



    tdisp(x + 3 * i);
    tdisp(x - 3 * i);
    tdisp(i * i);
    tdisp(x * i);
    tdisp(x / i);

    tdisp(4 * i + x);
    tdisp(4 * i - x);
    tdisp(i * x);
    tdisp(i / x);

    tdisp(x + 3);
    tdisp(x - 3);
    tdisp(x * 4);
    tdisp(x / 2);

    tdisp(3 + x);
    tdisp(3 - x);
    tdisp(4 * x);
    tdisp(2 / x);


    tdisp(x + z);
    tdisp(x - z);
    tdisp(x * z);
    tdisp(x / z);

    tdisp(z + x);
    tdisp(z - x);
    tdisp(z * x);
    tdisp(z / x);



    tdisp(x += i);
    tdisp(x -= 2 * i);
    tdisp(x *= 4);
    tdisp(x /= 4);

    tdisp(x += 5 * i);

    tdisp(x + y);
    tdisp(x - y);
    tdisp(x * y);
    tdisp(x / y);


    tdisp(Complex(x));

    tdisp(real(x));
    tdisp(imag(x));
    tdisp(arg(x));

    tdisp(abs(x));
    tdisp(normsqr(x));
    tdisp(conj(x));
    tdisp(~x);
    tdisp(polar(x));

    tdisp(exp(x));

    tdisp(log(x));
    tdisp(log10(x));
    tdisp(log2(x));

    tdisp(x);
    tdisp(y);
    tdisp(pow(x, y));
    tdisp(pow(x, 2));
    tdisp(pow(2, x));
    tdisp(pow(x, z));
    tdisp(pow(z, x));

    tdisp(sqrt(x));
    tdisp(sqr(x));
    tdisp(cube(x));

    Imaginary<double> w(1.9);
    tdisp(w);
    tdisp(round(w));
    tdisp(sgn(-w));
    tdisp(floor(w));
    tdisp(ceil(w));

    w = 0.009 * i;
    tdisp(w);
    tdisp(roundzero(w, 0.01));
    tdisp(roundzero(w, 0.001));
    tdisp(approx(i, 1.009 * i, 0.01));
    tdisp(approx(i, 1.009 * i, 0.001));


    tdisp(sin(x));
    tdisp(cos(x));
    tdisp(tan(x));

    tdisp(sinh(x));
    tdisp(cosh(x));
    tdisp(tanh(x));


    tdisp(asin(x));
    tdisp(acos(x));
    tdisp(atan(x));

    w = 0.9 * i;
    tdisp(w);
    tdisp(atan(w));



    tdisp(asinh(w));
    tdisp(acosh(w));
    tdisp(atanh(w));
  }


  //------------------------------------------------------

  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  return 0;
}
