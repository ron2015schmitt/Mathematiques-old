
#define MATHQ_DEBUG 0
#include "mathq.h"


int main(int argc, char *argv[]) {

  const double pi = M_PI;
  std::string myname = argv[0];
  using namespace mathq;
  using namespace display;
  using namespace std;

  Style bold = CREATESTYLE(BOLD);
  Style blue = CREATESTYLE(BOLD + BLUE2);


  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  CR();
  CR();
  MOUT << StyledString::get(HORLINE);
  MOUT << "running: " << bold.apply(myname) << std::endl;
  print_mathq_info();

  CR();
  MOUT << blue.apply("MatrixZero") << std::endl;
  CR();
  {
    MatrixZero<double> a;
    tdisp(a);
    a.resize(2, 2);
    tdisp(a);
  }
  CR();
  {
    MatrixZero<double, 3, 2> a;
    tdisp(a);
    tdisp(exp(a));
  }

  CR();
  MOUT << blue.apply("MatrixIdentity") << std::endl;
  CR();
  {
    MatrixIdentity<double> a;
    tdisp(a);
    a.resize(2, 2);
    tdisp(a);
  }
  CR();
  {
    MatrixIdentity<double, 3, 2> a;
    tdisp(a);
    tdisp(exp(a));
  }

  CR();
  MOUT << blue.apply("MatrixExchange") << std::endl;
  CR();
  {
    MatrixExchange<double> a;
    tdisp(a);
    a.resize(2, 2);
    tdisp(a);
  }
  CR();
  {
    MatrixExchange<double, 3, 2> a;
    tdisp(a);
    tdisp(exp(a));
  }

  CR();
  MOUT << blue.apply("MatrixConstDiag") << std::endl;
  CR();
  {
    MatrixConstDiag<double> a(2, 2, 8);
    tdisp(a);
    a.setValue(44);
    tdisp(a);
  }
  CR();
  {
    MatrixConstDiag<double, 3, 2> a(8);
    tdisp(a);
    tdisp(pow(2, a));
  }

  CR();
  MOUT << blue.apply("MatrixDiagonal") << std::endl;
  CR();
  {
    MatrixDiagonal<double> a(2, 2, 8);
    tdisp(a);
    a(0, 0) = -2;
    a(1, 1) = 2;
    a(1, 0) = 3;
    tdisp(a);
  }
  CR();
  {
    MatrixDiagonal<double, 3, 2> a(8);
    tdisp(a);
    tdisp(pow(2, a));
  }


  CR();
  MOUT << blue.apply("MatrixRevDiag") << std::endl;
  CR();
  {
    MatrixRevDiag<double> a(2, 2, 8);
    tdisp(a);
    a(0, 1) = -2;
    a(1, 0) = 2;
    a(1, 1) = 3;
    tdisp(a);
  }
  CR();
  {
    MatrixRevDiag<double, 3, 2> a(8);
    tdisp(a);
    tdisp(pow(2, a));
  }


  CR();
  MOUT << blue.apply("MatrixRepCol") << std::endl;
  CR();
  {
    Vector<double> v1{1, 2, 3, 4};
    MatrixRepCol<double> a(v1, 2);
    tdisp(v1);
    tdisp(a);
    a(0, 1) = -1;
    a(1, 0) = -2;
    a(2, 1) = -3;
    a(3, 0) = -4;
    tdisp(a);
  }
  CR();
  {
    MatrixRepCol<double, 3, 2> a(8);
    tdisp(a);
    tdisp(pow(2, a));
  }


  CR();
  MOUT << blue.apply("MatrixRepRow") << std::endl;
  CR();
  {
    Vector<double> v1{1, 2, 3, 4};
    MatrixRepRow<double> a(v1, 2);
    tdisp(v1);
    tdisp(a);
    a(0, 1) = -1;
    a(1, 0) = -2;
    a(2, 1) = -3;
    a(3, 0) = -4;
    tdisp(a);
  }
  CR();
  {
    MatrixRepRow<double, 3, 2> a(8);
    tdisp(a);
    tdisp(pow(2, a));
  }


  CR();
  MOUT << blue.apply("MatrixVandermonde") << std::endl;
  CR();
  {
    Vector<double> v1{1, 2, 3, 4};
    MatrixVandermonde<double> a(v1, 3);
    tdisp(v1);
    tdisp(a);
    a(0, 1) = -5;
    a(1, 0) = -2;
    a(2, 1) = -10;
    a(3, 0) = -4;
    tdisp(a);
  }
  CR();
  {
    MatrixVandermonde<double, 3, 4> a(3);
    tdisp(a);
    tdisp(pow(2, a));
  }


  CR();
  MOUT << blue.apply("MatrixToeplitz") << std::endl;
  CR();
  {
    // vector size is Nrows + Ncols + 1
    Vector<double> v1{1, 2, 3, 4, 5};
    MatrixToeplitz<double> a(v1, 3, 3);
    tdisp(v1);
    tdisp(a);
    a(0, 1) = -5;
    a(1, 0) = -2;
    a(2, 1) = -10;
    a(2, 0) = -4;
    tdisp(a);
  }
  CR();
  {
    Vector<double> v1{1, 2, 3, 4};
    MatrixToeplitz<double, 3, 2> a(v1);
    tdisp(a);
    tdisp(pow(2, a));
  }
  CR();
  {
    Vector<double> v1{1, 2, 3, 4};
    MatrixToeplitz<double, 2, 3> a(v1);
    tdisp(a);
    tdisp(2 * a);
  }


  CR();
  MOUT << blue.apply("MatrixUpperTriangle") << std::endl;
  CR();
  {
    MatrixUpperTriangle<double, 3> a(9);
    tdisp(a);
    a(0, 0) = 1;
    a(0, 1) = 2;
    a(0, 2) = 3;
    a(1, 0) = -2;
    a(1, 1) = 4;
    a(1, 2) = 5;
    a(2, 0) = -4;
    a(2, 1) = -12;
    a(2, 2) = 6;
    tdisp(a);
  }
  CR();
  {
    Vector<double> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    MatrixUpperTriangle<double> a(v);
    tdisp(a);
    Matrix<double> b = transpose(a);
    tdisp(b);
  }

  CR();
  MOUT << blue.apply("MatrixLowerTriangle") << std::endl;
  CR();
  CR();
  {
    MatrixLowerTriangle<double, 3> a(9);
    tdisp(a);
    a(0, 0) = 1;
    a(0, 1) = -1;
    a(0, 2) = -2;
    a(1, 0) = 2;
    a(1, 1) = 3;
    a(1, 2) = -3;
    a(2, 0) = 4;
    a(2, 1) = 5;
    a(2, 2) = 6;
    tdisp(a);
  }
  CR();
  {
    Vector<double> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    MatrixLowerTriangle<double> a(v);
    tdisp(a);
    Matrix<double> b;
    b = transpose(a);
    tdisp(b);
  }


  CR();
  MOUT << blue.apply("MatrixSymmetric") << std::endl;
  CR();
  CR();
  {
    MatrixSymmetric<double, 3> a(9);
    tdisp(a);
    a(0, 0) = 1;
    a(0, 1) = 2;
    a(0, 2) = 3;
    a(1, 1) = 1;
    a(1, 2) = 4;
    a(2, 2) = 1;
    tdisp(a);
  }
  CR();
  {
    Vector<double> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    MatrixSymmetric<double> a(v);
    tdisp(a);
    Matrix<double> b;
    b = transpose(a);
    tdisp(b);
  }


  CR();
  MOUT << blue.apply("MatrixSkewSymmetric") << std::endl;
  CR();
  CR();
  {
    MatrixSkewSymmetric<double, 3> a(9);
    tdisp(a);
    a(0, 0) = -1;
    a(0, 1) = 1;
    a(0, 2) = 2;
    a(1, 0) = -1;
    a(1, 1) = -1;
    a(1, 2) = 3;
    a(2, 0) = -1;
    a(2, 1) = -1;
    a(2, 2) = -1;
    tdisp(a);
  }
  CR();

  CR();
  MOUT << blue.apply("MatrixHermitian") << std::endl;
  CR();
  CR();
  {
    MatrixHermitian<double, 3> a(9);
    tdisp(a);
    a(0, 0) = 1;
    a(0, 1) = 2;
    a(0, 2) = 3;
    a(1, 1) = 1;
    a(1, 2) = 4;
    a(2, 2) = 1;
    tdisp(a);
  }
  CR();

  CR();
  CR();
  {
    MatrixHermitian<ComplexDouble, 3> a(9);
    tdisp(a);
    a(0, 0) = 1;
    a(0, 1) = 2 + 20i;
    a(0, 2) = 3 + 30i;
    a(1, 1) = 1;
    a(1, 2) = 4 + 40i;
    a(2, 2) = 1;
    tdisp(a);
  }
  CR();

  CR();
  MOUT << blue.apply("MatrixSkewHermitian") << std::endl;
  CR();
  CR();
  {
    MatrixSkewHermitian<double, 3> a(9);
    tdisp(a);
    a(0, 0) = 1;
    a(0, 1) = 2;
    a(0, 2) = 3;
    a(1, 1) = 1;
    a(1, 2) = 4;
    a(2, 2) = 1;
    tdisp(a);
  }
  CR();

  CR();
  CR();
  {
    MatrixSkewHermitian<ComplexDouble, 3> a(9);
    tdisp(a);
    a(0, 0) = 1;
    a(0, 1) = 2 + 20i;
    a(0, 2) = 3 + 30i;
    a(1, 1) = 1;
    a(1, 2) = 4 + 40i;
    a(2, 2) = 1;
    tdisp(a);
  }
  CR();


  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();
  return 0;
}
