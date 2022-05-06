
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

  CR();
  CR();
  MOUT << bold.apply("scalar") << endl;
  {
    CR();
    double x = 0.25;
    tdisp(x);
    tdisp(+x);
    tdisp(+(x));
    tdisp(-x);
    tdisp(mathq::real(x));
    tdisp(mathq::imag(x));
    tdisp(mathq::conj(x));
    tdisp(mathq::zero(x));
    tdisp(std::abs(x));
    tdisp(std::arg(x));
    tdisp(std::proj(x));

    Imaginary<double> y(2);
    tdisp(y);
    tdisp(mathq::real(y));
    tdisp(mathq::imag(y));
    tdisp(mathq::conj(y));


    std::complex<double> z(1, 2);
    tdisp(z);
    tdisp(std::real(z));
    tdisp(std::imag(z));
    tdisp(std::conj(z));
    tdisp(mathq::conj(z));

    tdisp(std::proj(z));
    tdisp(std::proj(ComplexDouble(5.0, 0)));
    tdisp(std::proj(ComplexDouble(0.2, 0)));
    tdisp(std::proj(ComplexDouble(0, 5.0)));
    tdisp(std::proj(ComplexDouble(0, 0.2)));
  }


  CR();
  CR();
  MOUT << bold.apply("Scalar") << endl;
  {

    CR();
    MOUT << blue.apply("Boolean Scalar") << endl;

    CR();
    Scalar<bool> sb = true;
    tdisp(sb);
    tdisp(!sb);
    tdisp(operator!(sb));
    tdisp(!(!sb));




    CR();
    MOUT << blue.apply("Real Scalar") << endl;

    Scalar<double> sr = 0.25;
    tdisp(sr);
    tdisp(-sr);
    tdisp(conj(sr));
    tdisp(real(sr));
    tdisp(imag(sr));
    tdisp(abs(sr));
    tdisp(arg(sr));
    tdisp(proj(sr));

    tdisp(exp(sr));
    tdisp(log(sr));
    tdisp(log10(sr));
    tdisp(sqrt(sr));

    tdisp(sin(sr));
    tdisp(cos(sr));
    tdisp(tan(sr));

    tdisp(asin(sr));
    tdisp(acos(sr));
    tdisp(atan(sr));

    tdisp(sinh(sr));
    tdisp(cosh(sr));
    tdisp(tanh(sr));

    tdisp(asinh(sr));
    tdisp(acosh(sr));
    tdisp(atanh(sr));


    CR();
    MOUT << blue.apply("Imag Scalar") << endl;
    Scalar<Imaginary<double>> si;
    si() = Imaginary<double>(0.25);

    tdisp(si);
    tdisp(-si);
    tdisp(conj(si));
    tdisp(real(si));
    tdisp(imag(si));
    tdisp(abs(si));
    tdisp(arg(si));
    tdisp(proj(si));

    tdisp(exp(si));
    tdisp(exp(ComplexDouble(0, 0.25)));
    tdisp(log(si));
    tdisp(log10(si));
    tdisp(sqrt(si));

    tdisp(sin(si));
    tdisp(cos(si));
    tdisp(tan(si));

    tdisp(asin(si));
    tdisp(acos(si));
    tdisp(atan(si));

    tdisp(sinh(si));
    tdisp(cosh(si));
    tdisp(tanh(si));

    tdisp(asinh(si));
    tdisp(acosh(si));
    tdisp(atanh(si));


    CR();
    MOUT << blue.apply("Complex Scalar") << endl;
    Scalar<ComplexDouble> sc{ComplexDouble(0.25, 0.5)};
    tdisp(sc);
    tdisp(-sc);
    tdisp(conj(sc));
    tdisp(real(sc));
    tdisp(imag(sc));
    tdisp(abs(sc));
    tdisp(arg(sc));
    tdisp(proj(sc));

    tdisp(exp(sc));
    tdisp(log(sc));
    tdisp(log10(sc));
    tdisp(sqrt(sc));

    tdisp(sin(sc));
    tdisp(cos(sc));
    tdisp(tan(sc));

    tdisp(asin(sc));
    tdisp(acos(sc));
    tdisp(atan(sc));

    tdisp(sinh(sc));
    tdisp(cosh(sc));
    tdisp(tanh(sc));

    tdisp(asinh(sc));
    tdisp(acosh(sc));
    tdisp(atanh(sc));

    CR();
    CR();
    // typename Realify<Scalar<double>>::Type qr;
    // tdisp(qr);

    // typename Realify<Scalar<Imaginary<double>> >::Type qi;
    // tdisp(qi);

    // typename Realify<Scalar<std::complex<double>> >::Type qc;
    // tdisp(qc);
  }


  CR();
  CR();
  MOUT << bold.apply("Vector") << endl;
  {
    CR();
    MOUT << bold.apply("Vector") << " - " << blue.apply("Real Scalar") << endl;
    CR();
    Vector<double> vr{1.1, 2.2};
    tdisp(vr);
    tdisp(-vr);
    tdisp(conj(vr));
    tdisp(real(vr));
    tdisp(imag(vr));
    tdisp(abs(vr));
    tdisp(arg(vr));
    tdisp(proj(vr));

    tdisp(exp(vr));
    tdisp(log(vr));
    tdisp(log10(vr));
    tdisp(sqrt(vr));

    tdisp(sin(vr));
    tdisp(cos(vr));
    tdisp(tan(vr));

    tdisp(asin(vr));
    tdisp(acos(vr));
    tdisp(atan(vr));

    tdisp(sinh(vr));
    tdisp(cosh(vr));
    tdisp(tanh(vr));

    tdisp(asinh(vr));
    tdisp(acosh(vr));
    tdisp(atanh(vr));
  }

  CR();
  CR();
  MOUT << bold.apply("Matrix") << endl;
  {
    CR();
    MOUT << bold.apply("Matrix") << " - " << blue.apply("Real Scalar") << endl;
    Matrix<double> mr{{1, 2}, {3, 4}};
    tdisp(mr);
    tdisp(-mr);
    tdisp(conj(mr));
    tdisp(real(mr));
    tdisp(imag(mr));
    tdisp(abs(mr));
    tdisp(arg(mr));
    tdisp(proj(mr));

    tdisp(exp(mr));
    tdisp(log(mr));
    tdisp(log10(mr));
    tdisp(sqrt(mr));

    tdisp(sin(mr));
    tdisp(cos(mr));
    tdisp(tan(mr));

    tdisp(asin(mr));
    tdisp(acos(mr));
    tdisp(atan(mr));

    tdisp(sinh(mr));
    tdisp(cosh(mr));
    tdisp(tanh(mr));

    tdisp(asinh(mr));
    tdisp(acosh(mr));
    tdisp(atanh(mr));
  }


  CR();
  CR();
  MOUT << bold.apply("Tensor") << endl;
  {
    CR();
    MOUT << bold.apply("Tensor") << " - " << blue.apply("Real Scalar") << endl;
    CR();
    Tensor<double, 3> tr{
        {{0, 1, 2, 3, 4}, {10, 11, 12, 13, 14}},
        {{100, 101, 102, 103, 104}, {110, 111, 112, 113, 114}},
        {{200, 201, 202, 203, 204}, {210, 211, 212, 213, 214}}};

    tdisp(tr);
    tdisp(-tr);
    tdisp(conj(tr));
    tdisp(real(tr));
    tdisp(imag(tr));
    tdisp(abs(tr));
    tdisp(arg(tr));
    tdisp(proj(tr));

    tdisp(exp(tr));
    tdisp(log(tr));
    tdisp(log10(tr));
    tdisp(sqrt(tr));

    tdisp(sin(tr));
    tdisp(cos(tr));
    tdisp(tan(tr));
  }



  CR();
  CR();
  CR();
  CR();


  MOUT << blue.apply("Two-level tests") << endl;

  // // -------------------------------------------------
  // // two level tests
  // // -------------------------------------------------

  CR();
  CR();
  MOUT << bold.apply("Two-Level Scalar tests") << endl;

  CR();
  CR();
  MOUT << bold.apply("Scalar") << endl;
  {
    CR();

    CR();
    MOUT << blue.apply("Boolean Scalar") << endl;
    Scalar<Scalar<bool>> sb = true;
    tdisp(sb);
    tdisp(!sb);

    CR();
    MOUT << blue.apply("Real Scalar Scalar") << endl;
    Scalar<Scalar<double>> sr = {{1.1}};
    tdisp(sr);
    tdisp(-sr);
    tdisp(sin(sr));
    tdisp(exp(sr));
    tdisp(conj(sr));


    CR();
    MOUT << blue.apply("Imaginary Scalar Scalar") << endl;
    Scalar<Scalar<Imaginary<double>>> si;
    si()() = Imaginary<double>(3);
    tdisp(si);
    tdisp(-si);
    tdisp(conj(si));
    tdisp(real(si));
    tdisp(imag(si));
    tdisp(sin(si));
    tdisp(exp(si));

    CR();
    MOUT << blue.apply("Complex Scalar") << endl;
    Scalar<Scalar<ComplexDouble>> sc{{ComplexDouble(1, 2)}};
    tdisp(sc);
    tdisp(-sc);
    tdisp(conj(sc));
    tdisp(real(sc));
    tdisp(imag(sc));
    tdisp(sin(sc));
    tdisp(exp(sc));

    CR();
    CR();

    // typename Realify<Scalar<Scalar<double>>>::Type qr;
    // tdisp(qr);

    // typename Realify<Scalar<Scalar<Imaginary<double>>>>::Type qi;
    // tdisp(qi);

    // typename Realify<Scalar<Scalar<std::complex<double>>>>::Type qc;
    // tdisp(qc);
  }


  {
    CR();
    Scalar<Scalar<double>> s{{1.1}};
    tdisp(s);
    tdisp(sin(s));
    tdisp(exp(s));
  }
  {
    CR();
    Scalar<Vector<double>> s{{1., 2., 3.}};
    tdisp(s);
    tdisp(sin(s));
    tdisp(exp(s));
  }
  {
    CR();
    Scalar<Matrix<double>> s{{{1, 2}, {3, 4}}};
    tdisp(s);
    tdisp(sin(s));
    tdisp(exp(s));
  }

  {
    CR();
    Scalar<Tensor<double, 2>> s{{{1, 2}, {3, 4}}};
    tdisp(s);
    tdisp(sin(s));
    tdisp(exp(s));
  }

  CR();
  CR();
  MOUT << bold.apply("Two-Level Vector tests") << endl;
  {
    CR();
    Vector<Scalar<double>> v{{1.}, {2.}};
    tdisp(v);
    tdisp(sin(v));
    tdisp(exp(v));
  }

  {
    CR();
    Vector<Vector<double>> v{{1., 2., 3.}, {4., 5., 6.}};
    tdisp(v);
    tdisp(sin(v));
    tdisp(exp(v));
  }
  {
    CR();
    Vector<Matrix<double>> v{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 12}}};
    tdisp(v);
    tdisp(sin(v));
    tdisp(exp(v));
  }
  {
    CR();
    Vector<Tensor<double, 2>> v{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 12}}};
    tdisp(v);
    tdisp(sin(v));
    tdisp(exp(v));
  }


  CR();
  CR();
  MOUT << bold.apply("Two-Level Matrix tests") << endl;
  {
    CR();
    Matrix<Scalar<double>> m{{{1}, {2}}, {{3}, {4}}};
    ;
    tdisp(m);
    tdisp(sin(m));
    tdisp(exp(m));
  }

  {
    CR();
    Matrix<Vector<double>> m{{{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9}, {10, 11, 12}}};
    tdisp(m);
    tdisp(sin(m));
    tdisp(exp(m));
  }

  {
    CR();
    Matrix<Matrix<double>> m{
        {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}},
        {{{9, 10}, {11, 12}}, {{13, 14}, {15, 16}}}};
    tdisp(m);
    tdisp(sin(m));
    tdisp(exp(m));
  }

  {
    CR();
    Matrix<Tensor<double, 3>, 2, 2> m{{{{{-0, -1},
                                         {-10, -11},
                                         {-20, -21}},
                                        {{-100, -101},
                                         {-110, -111},
                                         {-120, -121}}},
                                       {{{-1000, -1001},
                                         {-1010, -1011},
                                         {-1020, -1021}},
                                        {{-1100, -1101},
                                         {-1110, -1111},
                                         {-1120, -1121}}}},
                                      {{{{-10000, -10001},
                                         {-10010, -10011},
                                         {-10020, -10021}},
                                        {{-10100, -10101},
                                         {-10110, -10111},
                                         {-10120, -10121}}},
                                       {{{-11000, -11001},
                                         {-11010, -11011},
                                         {-11020, -11021}},
                                        {{-11100, -11101},
                                         {-11110, -11111},
                                         {-11120, -11121}}}}};

    tdisp(m);
    tdisp(sin(m));
    tdisp(exp(m));
  }

  // /////////////////////////////////////////////////////////////////



  // CR();
  // CR();
  // MOUT << bold.apply("Two-Level Tensor tests") << endl;
  // {
  //   CR();
  //   Tensor<Scalar<double>,2> t {{{1},{2}},{{3},{4}}};
  //   tdisp(t);
  //   tdisp(sin(t));
  //   tdisp(beta(t));
  //   tdisp(exp(t));
  //   tdisp(cyl_bessel_j(t));
  // }
  // {
  //   CR();
  //   Tensor<Vector<double>,2> t {{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
  //   tdisp(t);
  //   tdisp(sin(t));
  //   tdisp(beta(t));
  //   tdisp(exp(t));
  //   tdisp(cyl_bessel_j(t));
  // }

  // {
  //   CR();
  //   Tensor<Matrix<double,2,2>,2> t  {
  //     { {{1,2},{3,4}}, {{5,6},{7,8}} },
  // 	{ {{9,10},{11,12}}, {{13,14},{15,16}} }
  //   };
  //   tdisp(t);
  //   tdisp(sin(t));
  //   tdisp(beta(t));
  //   tdisp(exp(t));
  //   tdisp(cyl_bessel_j(t));
  // }


  // {
  //   CR();
  //   Tensor<Tensor<double,3>,2> t { {
  // 	{
  // 	  {
  // 	    {0, 1},
  // 	      {10, 11},
  // 		{20, 21}
  // 	  },
  // 	    {
  // 	      {100, 101},
  // 		{110, 111},
  // 		  {120, 121}
  // 	    }
  // 	},
  // 	  {
  // 	    {
  // 	      {1000, 1001},
  // 		{1010, 1011},
  // 		  {1020, 1021}
  // 	    },
  // 	      {
  // 		{1100, 1101},
  // 		  {1110, 1111},
  // 		    {1120, 1121}
  // 	      }
  // 	  }}, {
  // 	{
  // 	  {
  // 	    {10000, 10001},
  // 	      {10010, 10011},
  // 		{10020, 10021}
  // 	  },
  // 	    {
  // 	      {10100, 10101},
  // 		{10110, 10111},
  // 		  {10120, 10121}
  // 	    }
  // 	},
  // 	  {
  // 	    {
  // 	      {11000, 11001},
  // 		{11010, 11011},
  // 		  {11020, 11021}
  // 	    },
  // 	      {
  // 		{11100, 11101},
  // 		  {11110, 11111},
  // 		    {11120, 11121}
  // 	      }
  // 	  }} };

  //   tdisp(t);
  //   tdisp(sin(t));
  //   tdisp(beta(t));
  //   tdisp(exp(t));
  //   tdisp(cyl_bessel_j(t));

  // }





  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();

  return 0;
}
