#define MATRICKS_DEBUG 1
#include "matricks.h"

#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif

#include <type_traits>
#include <string>

template <class, template <class> class>
struct is_instance : public std::false_type {};

template <class T, template <class> class U>
struct is_instance<U<T>, U> : public std::true_type {};

int main()
{
  using namespace matricks;
  using namespace display;

  const double pi = M_PI;
  int n = 45;
  unsigned int m = 256;
  double x = 3.14;
  double vals[] = {1.1,2.2,3.3};
  bool done = true;
  Vector<double> v = range<double>(1,10);
  char str[] = "hello";
  std::string s = "world";
  std::complex<double> z(1,-1);


  cr();cr();
  disp(n);
  disp(m);
  disp(x);
  disp(vals);
  disp(done);
  disp(v);
  disp(str);
  disp(s);
  disp(z);

  cr();cr();
  tdisp(n);
  tdisp(m);
  tdisp(x);
  tdisp(vals);
  tdisp(done);
  tdisp(v);
  tdisp(str);
  tdisp(s);
  tdisp(z);

  cr();cr();
  mdisp(n,m,x,vals,done,str,s,z);

  cr();cr();
  dispval(n);
  dispval(m);
  
  cr();cr();
  disp(n+3);
  disp(10*x-1);
  disp(!done);
  disp( round(10*sin(pi/10*v) + 10) );
  disp(s+" tour");
  mout << std::endl;

  mout << createStyle(GRAY1) << "  ";
  mout << createStyle(GRAY2) << "  ";
  mout << createStyle(WHITE+BLACKBACK) << "  ";
  mout << std::endl;
  
  mout << createStyle(RED) << "  ";
  mout << std::endl;
  mout << createStyle(ORANGE) << "  ";
  mout << std::endl;
  mout << createStyle(YELLOW) << "  ";
  mout << createStyle(YELLOWBRIGHT) << "  ";
  mout << std::endl;
  mout << createStyle(GREEN) << "  ";
  mout << createStyle(GREENBRIGHT) << "  ";
  mout << createStyle(GREEN1) << "  ";
  mout << std::endl;
  mout << createStyle(CYAN) << "  ";
  mout << createStyle(BLUE) << "  ";
  mout << createStyle(BLUEBRIGHT) << "  ";
  mout << createStyle(BLUE1) << "  ";
  mout << createStyle(BLUE2) << "  ";
  mout << createStyle(BLUE3) << "  ";
  mout << std::endl;
  mout << createStyle(MAGENTA) << "  ";
  mout << createStyle(MAGENTA1) << "  ";
  mout << createStyle(VIOLET1) << "  ";
  mout << std::endl;
  mout << createStyle(BOLD) << "  ";
  mout << createStyle(UNDERLINE) << "  ";
  mout << createStyle(CROSSEDOUT) << "  ";
  mout << createStyle(OVERLINE) << "  ";
  mout << createStyle(SLOWBLINK) << "  ";
  mout << std::endl;

  mout << createStyle(REDBACK) << "  ";
  mout << createStyle(ORANGEBACK) << "  ";
  mout << createStyle(YELLOWBACK) << "  ";
  mout << createStyle(GREENBACK) << "  ";
  mout << std::endl;
  mout << std::endl;
  mout << std::endl;

  mout << createStyle(BOLD+UNDERLINE+VIOLET1) << "  ";
  mout << std::endl;
  mout << std::endl;
  mout << std::endl;
  mout << std::endl;

  {
    Style mystyle = createStyle(BOLD+RED);
    mout << mystyle.apply("with style") + " without style " << std::endl;
  }
  mout << std::endl;
  mout << std::endl;
  mout << std::endl;

  {
    int nf = 27;  // color for foreground
    int nb = 227; // color for background 
    Style mystyle(nf, nb);
    mout << mystyle.apply("Hello World") << std::endl;

    mout << std::endl;
    mout << std::endl;
    mout << std::endl;


    Style bold(BOLD); 
    Style mybold = bold + mystyle; 
    mout << mybold.apply("Hello World") << std::endl;

    Style black(BLACK); 
    mout <<"XXX"<< black.apply("XXX")<<"XXX" << std::endl;
    
  }
  
  cr();cr();

  using namespace std;

  double d;

  mout << Fun_Plus_base::expression("x") << endl;

  mout << Fun_Plus<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Plus<double>::expression("x") << endl;
  
  mout << Fun_Minus<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Minus<double>::expression("x") << endl;

  mout << Fun_Cast<double,int>::classname() << " ";
  mout << Fun_Cast<double,int>::expression("n") << endl;
  
  mout << Fun_Add<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Add<double>::expression("x","y") << endl;

  mout << Fun_Subtract<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Subtract<double>::expression("x","y") << endl;
  mout << Fun_Multiply<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Multiply<double>::expression("x","y") << endl;

  mout << Fun_Divide<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Divide<double>::expression("x","y") << endl;


  mout << Fun_Pow<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Pow<double>::expression("x","y") << endl;

  mout << Fun_Monomial<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Monomial<double>::expression("x","y") << endl;

  mout << Fun_Atan2<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Atan2<double>::expression("x","y") << endl;

  

  mout << is_instance<Fun_Multiply<double>, Fun_Divide>{} <<endl;
  
  
  return 0;
}