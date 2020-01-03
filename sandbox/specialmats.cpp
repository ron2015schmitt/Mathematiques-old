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
    Style blue = createStyle(BOLD+BLUE2);

  
    // force color even if piped to more,less or a file
    Terminal::setColorOverride(true);
    Terminal::setOverrideValue(true);

    cr();
    cr();
    mout << StyledString::get(HORLINE);
    mout << "running: " <<bold.apply(myname) << std::endl;
    print_mathq_info();
  
    cr();
    mout << blue.apply("ZeroMatrix") << std::endl;
    cr();
    {
      ZeroMatrix<double> a;
      tdisp(a);
      a.resize(2,2);
      tdisp(a);
    } 
    cr();
    {
      ZeroMatrix<double,3,2> a;
      tdisp(a);
      tdisp(exp(a));
    } 

    cr();
    mout << blue.apply("IdentityMatrix") << std::endl;
    cr();
    {
      IdentityMatrix<double> a;
      tdisp(a);
      a.resize(2,2);
      tdisp(a);
    } 
    cr();
    {
      IdentityMatrix<double,3,2> a;
      tdisp(a);
      tdisp(exp(a));
    } 

    cr();
    mout << blue.apply("ExchangeMatrix") << std::endl;
    cr();
    {
      ExchangeMatrix<double> a;
      tdisp(a);
      a.resize(2,2);
      tdisp(a);
    } 
    cr();
    {
      ExchangeMatrix<double,3,2> a;
      tdisp(a);
      tdisp(exp(a));
    } 

    cr();
    mout << blue.apply("ConstDiagMatrix") << std::endl;
    cr();
    {
      ConstDiagMatrix<double> a(2,2,8);
      tdisp(a);
      a.setValue(44);
      tdisp(a);
    } 
    cr();
    {
      ConstDiagMatrix<double,3,2> a(8);
      tdisp(a);
      tdisp(pow(2,a));
    } 
    
  
    cr();
    mout << "done: " << bold.apply(myname) << std::endl;
    mout << StyledString::get(HORLINE);
    cr();
    return 0;
  }
