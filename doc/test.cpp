#define MATRICKS_DEBUG 2


#include "matricks.h"
#include "TypeTraits.h"
#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif

template <class D, int I>
class Mets {
public:
  static void test() {
    printf("I = %d\n",I);
  }
};

template <class D>
class Mets<D,4> {
public:
  static void test2() {
    printf("I is 4\n");
  }
};


namespace display {




  






  // this allows const and non-const to be treated by same class
};

#define Vector_(name,t,...) Vector<t> name(__VA_ARGS__); //MatricksObjectPool::(name.id(),std::string(#name)+"<"+stringify(t)+">"+" in "+__FUNCTION__+" at line "+stringify(__LINE__)+" in file "+__FILE__));


int main()
{
 
  using namespace matricks;
  using namespace std;
  using namespace display;
  int Nex = 1;

  
  dispcr(Terminal::getSupportsColor());
  print_matricks_info();
  print1("DEBUG level 1 enabled \n");
  print2("DEBUG level 2 enabled \n");

  printf("MATRICKS_DEBUG=%d\n",MATRICKS_DEBUG);
  printf("EXPAND(MATRICKS_DEBUG)=%d\n",EXPAND(MATRICKS_DEBUG));

  cout << "error string   ="<<StyledString::get(ERROR)<<endl;
  cout << "warning string ="<<StyledString::get(WARNING)<<endl;
  
  
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



  double xx = 5.5;
  const double xxc = 23.3;

  dispcr(getTypeName(xx));
  dispcr(getTypeName(xxc));


  setFormatString<double>("%lf");
  dispcr(xx);
  setFormatString<double>("hello");
  setFormatString<double>("%y");
  setFormatString<double>("%s");

  setFormatString<double>("% 10.5f");
  printObj(xx);cr();
  printObj(xxc);cr();
  setFormatString<double>("%g");
  cout << getFormatString<std::complex<double> >().c_str() << endl;
  complex<double> zc = complex<double>(2.3,4.5);
  printObj(zc);cr();

  //  setFormatString<complex<double> >("%g + i*%g");
  setFormatString<complex<double> >("%s +%si");
  printObj(zc);cr();
  tdisp(zc);cr();
  return 0;
}
