
#include "mathq.h"
#include <iostream>
#include <fstream>
#include <string>

void printoptsfile() {
  std::ifstream myfile;
  myfile.open("example.g++_copts");
  std::string myline;
  if (myfile.is_open()) {
    while (myfile) { 
      std::getline(myfile, myline);
      std::cout << myline << '\n';
    }
  }
  else {
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

Vector<double> u( linspace<double>(-1,1,21) );
Vector<double> v;
v = 10*sin(pi/2*u) + 10;

const double N = double(v.size());
double mu = sum(v)/N;
double sigma = norm(v-mu)/sqrt(N-1);

disp(mu);
disp(sigma);

  cr();
  mout << "done: " << createStyle(BOLD).apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();

  return 0;
}
