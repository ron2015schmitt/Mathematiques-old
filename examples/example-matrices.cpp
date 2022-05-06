#include <iostream>
#include <fstream>
#include <string>

#include "mathq.h"
#include "macros.h"

void printoptsfile() {
  std::ifstream myfile;
  myfile.open("example.g++_copts");
  std::string myline;
  if (myfile.is_open()) {
    while (myfile) {
      std::getline(myfile, myline);
      std::cout << myline << '\n';
    }
  } else {
    std::cout << "Couldn't open file\n";
  }
}

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
  mout << "running: " << createStyle(BOLD).apply(myname) << std::endl;

  mout << "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;
  print_mathq_info();
  printoptsfile();

  Vector<double> v1({2, -1});
  Vector<double> v2;
  v2 = 10 * sin(pi / 2 * v1) + 5;

  disp(v1);
  disp(v2);
  disp(v1 + v2);

  // FormatDataVector::max_elements_per_line = 10;
  // FormatDataVector::string_opening = "[\n  ";
  // FormatDataVector::string_delimeter = "\n  ";
  // FormatDataVector::string_endofline = "";
  // FormatDataVector::string_closing = "\n]";

  FormatDataMatrix::max_elements_per_line = 10;
  FormatDataMatrix::string_opening = "[\n";
  FormatDataMatrix::string_delimeter = ", ";
  FormatDataMatrix::string_row_opening = "    ";
  FormatDataMatrix::string_row_closing = "\n";
  FormatDataMatrix::string_lastrow_closing = "";
  FormatDataMatrix::string_endofline = "\n";
  FormatDataMatrix::string_closing = "\n]";

  Matrix<double> m1(2, 2);
  m1 = {10, 20, 30, 40};
  Matrix<double> m2(2, 2);
  m2 = {-1, -2, -3, -4};

  Matrix<double> m3({{1, 2}, {3, 4}, {5, 6}});
  // m3 = {{1, 2}, {3, 4}, {5, 6}};
  // dot product
  disp(v1 | v2);

  disp(v1);
  disp(m3);
  disp((m3 | v1));

  disp(m1);
  disp(m2);
  disp(m1 + m2);

  disp(m1 | v1);
  disp(v1 | m1);

  disp(m1 | m2);

  disp(m3 | m1);
  disp(m2 | m3.transpose());

  Vector<double> v({2, -1});
  Vector<double> u({1, -2, 4});
  Matrix<double> A({{1, 2}, {3, 4}, {5, 6}});

  disp(v);
  disp(A);
  disp(A | v);

  disp(u);
  disp(v);
  disp(A);
  disp(u | A | v);
  disp(u | (2 * A - 1) | (10 * sin(pi / 2 * v) + 5));

  cr();
  mout << "done: " << createStyle(BOLD).apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();

  return 0;
}
