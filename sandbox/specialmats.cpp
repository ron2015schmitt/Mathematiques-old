#define MATHQ_DEBUG 1
#include "mathq.h"



  int main(int argc, char *argv[])
  {


  
    const double pi = M_PI;
    std::string myname = argv[0];
    using namespace mathq;
    using namespace display;
    using namespace std;
  
    Style bold = createStyle(BOLD);
  
    // force color even if piped to more,less or a file
    Terminal::setColorOverride(true);
    Terminal::setOverrideValue(true);

    cr();
    cr();
    mout << StyledString::get(HORLINE);
    mout << "running: " <<bold.apply(myname) << std::endl;
    print_mathq_info();
  
    cr();
    {
      ZeroMatrix<double> a;
      tdisp(a);
    } 
    cr();
    {
      ZeroMatrix<double,3,2> a;
      tdisp(a);
      tdisp(exp(a));
    } 

  
    cr();
    mout << "done: " << bold.apply(myname) << std::endl;
    mout << StyledString::get(HORLINE);
    cr();
    return 0;
  }
