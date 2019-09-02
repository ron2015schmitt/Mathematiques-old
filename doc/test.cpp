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
  tdisp(xx);
  tdisp(xxc);
  setFormatString<double>("%g");
  cout << getFormatString<std::complex<double> >().c_str() << endl;
  complex<double> zc = complex<double>(2.3,4.5);
  tdisp(zc);

  //  setFormatString<complex<double> >("%g + i*%g");
  setFormatString<complex<double> >("%s +%si");
  tdisp(zc);

  bool booly = true;
  tdisp(booly);

  int ii = -5;
  tdisp(ii);
  
  unsigned int uu = 5;
  tdisp(uu);

  unsigned int uzero = 0;
  tdisp(uzero);

  tdisp(4*uu+13);

  string s = "hello world";
  tdisp(s);
  
  char c = 'q';
  tdisp(c);

  char ronny[] = "ronny";
  tdisp(ronny);

  int ints[] = {-1,2,32};
  tdisp(ints);

  std::vector<double> vec(3);
  vec[0]=1.1;
  vec[1]=2.2;
  vec[2]=3.3;
  tdisp(vec);

  std::map<int,std::string> mymap;
  mymap[1] = "hello";
  mymap[66] = "ron";
  tdisp(mymap);

  std::valarray<double> val(3);
  val[0]=9.1;
  val[1]=9.2;
  val[2]=9.3;
  tdisp(val);

  std::list<double> lis;
  lis.push_back(33.3);
  lis.push_back(-5.5);
  tdisp(lis);

  std::initializer_list<double> l0;
  l0 = {1,2,3,4.4};
  tdisp(l0);

  std::queue<double> q;
  q.push(33.);
  q.push(-5.5);
  tdisp(q);
  tdisp(q);

  Vector<double> v( {1.1,2.2,3.3,4.4} );
  tdisp(v);

  tdisp(exp(sin(3*v+1)));
  
  return 0;
}
