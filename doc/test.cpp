#define MATRICKS_DEBUG 2


#include "matricks.hpp"
using namespace matricks;

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif


#define Vector_(name,t,...) Vector<t> name(__VA_ARGS__); //MatricksObjectPool::(name.id(),std::string(#name)+"<"+stringify(t)+">"+" in "+__FUNCTION__+" at line "+stringify(__LINE__)+" in file "+__FILE__));


int main()
{
 
  using namespace std;
  using namespace style;
  int Nex = 1;

  
  dispcr(Terminal::getSupportsColor());
  display_execution_mode();
  print1("DEBUG level 1 enabled \n");
  print2("DEBUG level 2 enabled \n");

  printf("MATRICKS_DEBUG=%d\n",MATRICKS_DEBUG);
  printf("EXPAND(MATRICKS_DEBUG)=%d\n",EXPAND(MATRICKS_DEBUG));

  cout << "error string   ="<<Strings::error<<endl;
  cout << "warning string ="<<Strings::warn<<endl;
  
  double d = 3.4;
  Any<double> x(d);

  Any<index_type> y(Nex);
  Vector<double> ron(5);
  Any<Vector<double> > z(ron);

  Vector<Vector<double> > ronnie;
  Any<Vector<Vector<double> > > zz(ronnie);
  


  return 0;
}
