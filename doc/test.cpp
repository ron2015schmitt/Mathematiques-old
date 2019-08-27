#define MATRICKS_DEBUG 2


#include "matricks.hpp"

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
 
  using namespace matricks;
  using namespace std;
  using namespace style;
  int Nex = 1;

  
  dispcr(Terminal::getSupportsColor());
  print_matricks_info();
  print1("DEBUG level 1 enabled \n");
  print2("DEBUG level 2 enabled \n");

  printf("MATRICKS_DEBUG=%d\n",MATRICKS_DEBUG);
  printf("EXPAND(MATRICKS_DEBUG)=%d\n",EXPAND(MATRICKS_DEBUG));

  cout << "error string   ="<<StyledString::get(ERROR)<<endl;
  cout << "warning string ="<<StyledString::get(WARNING)<<endl;
  
  double d = 3.4;
  Any<double> x(d);

  Any<index_type> y(Nex);
  Vector<double> ron(5);
  Any<Vector<double> > z(ron);

  Vector<Vector<double> > ronnie;
  Any<Vector<Vector<double> > > zz(ronnie);
  
  Style bold(BOLD,"bold");
  dispcr(bold);
  dispcr(bold.apply("hello"));

  Style dim(DIM,"dim");  // doesn't work
  dispcr(dim);

  Style underline(UNDERLINE,"underline");
  dispcr(underline);

  Style crossedout(CROSSEDOUT,"crossedout");
  dispcr(crossedout);

  Style font2(FONT2,"font2"); // doesn;t work
  dispcr(font2);

  Style framed(FRAMED,"framed"); // doesn;t work
  dispcr(framed);

  Style encircled(ENCIRCLED,"encircled"); // doesn;t work
  dispcr(encircled);

  Style overline(OVERLINE,"overline");
  dispcr(overline);

  Style gray1(GRAY1,"gray1");
  dispcr(gray1);

  Style blue(BLUE,"blue");
  dispcr(blue);
  Style blue1(BLUE1,"blue1");
  dispcr(blue1);
  Style blue2(BLUE2,"blue2");
  dispcr(blue2);
  Style blue3(BLUE3,"blue3");
  dispcr(blue3);
  Style cyan(CYAN,"cyan");
  dispcr(cyan);

  Style magenta(MAGENTA,"magenta");
  dispcr(magenta);
  Style magenta1(MAGENTA1,"magenta1");
  dispcr(magenta1);

  StyledString ss(bold+magenta1, "Hello");
  dispcr(ss);

  Format<double> formatdouble("%f");
  dispcr(formatdouble);
  dispcr(formatdouble.getName());
  dispcr(formatdouble.get());
  dispcr(formatdouble.apply(3.4));
  printf("formatdouble.setFormatStr(\"%%12.5f\")\n");
  formatdouble.set("%12.5f");
  dispcr(formatdouble.get());
  dispcr(formatdouble.apply(3.4));
  
  printf("formatdouble.setFormatStr(\"%%parbage\")\n");
  formatdouble.set("%parbage");
  dispcr(formatdouble.get());
  dispcr(formatdouble.apply(3.4));

  int ronny = 5;
  double q = 5.5;
  double boots;
  dispcr(boots);
  log("matricks","Vector","resize","()");

  //  string s1 = print2str("%15.8f\n",3.141592649);

  string s1 = print2str("%15.8f\n",3.141592649);
  dispcr(s1);
  s1 = print2str("%15.8f\n",1.);
  dispcr(s1);

  return 0;
}
