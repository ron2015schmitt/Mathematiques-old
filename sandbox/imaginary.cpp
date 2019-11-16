#define MATRICKS_DEBUG 1
#include "matricks.h"

#include <vector>
#include <string>


int main(int argc, char *argv[])
{
  const double pi = M_PI;
  std::string myname = argv[0];

  using namespace matricks;
  using namespace display;
  using namespace matricks::unit_imaginary;

  Style bold = createStyle(BOLD);
  
  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  cr();
  cr();
  mout << StyledString::get(HORLINE);
  mout << "running: " <<bold.apply(myname) << std::endl;

  
  mout<< "MATRICKS_DEBUG=" << MATRICKS_DEBUG << std::endl;
  
  print_matricks_info();


  {
    cr();
    tdisp(i);
    Imaginary<double> x = 2;
    tdisp(x);

    tdisp(x+3*i);

    tdisp(x+3*i + 1);

    tdisp(i*i);
    tdisp(x/i);
    
  }


  //------------------------------------------------------
  
  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  return 0;
}
