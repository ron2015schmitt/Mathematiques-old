#define MATRICKS_DEBUG 1


#include "matricks.h"
#include "TypeTraits.h"
#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif





int main()
{
 
  using namespace matricks;
  using namespace std;
  using namespace display;
  using namespace md;

  int Nex = 1;
  
  cr();
  mdtitle0("Calculating a Fourier series and plotting the results in Matlab");
  matricks_preamble();

  header2("Fourier Series for the Claussen Function");
  text("The (Claussen function)[http://mathworld.wolfram.com/ClausenFunction.html] or order 1 is defined by");


  // CLuasen function

  const size_type N = 20;
  Vector<double> An = Vector<double>(N,0.);

  Vector<double> Bn = 1./sqr(range<double>(0,N-1));
  Bn[0] = 0.0;

  const double pi = M_PI;
  Vector<double> t = linspace<double>(-2*pi,2*pi,201);
  const double T = 2*pi;
  const double omega = 1;
  Vector<double> y2 = fourier(An,Bn, t, An.size(), omega );
  disp(An);
  disp(Bn);
  disp(y2);

  matricks_toc();

  
  return 0;
}
