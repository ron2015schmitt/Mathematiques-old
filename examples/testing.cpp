#define MATRICKS_DEBUG 1
#include "matricks.h"

#include <vector>


#if CPP11 == 1
#include <initializer_list>
#endif

#include "TypeTraits.h"
#include <string>

  


// template bag of tricks

template <class T> class Experiment {
public:
  typedef T Type;
  static std::string TypeName;
};


template <typename T> std::string Experiment<T>::TypeName = typeid(Experiment<T>::Type).name();

template <> std::string Experiment<long int>::TypeName = "long int";


template <class, template <class> class>
struct is_instance : public std::false_type {};

template <class T, template <class> class U>
struct is_instance<U<T>, U> : public std::true_type {};


  double f1(double x) {
    return ((x>=0) ? x : 0);
  }

double f2(double x, double y) {
    return ((x>=0) ? x : 0);
  }


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

  mout << is_instance<Fun_Multiply<double>, Fun_Divide>{} <<endl;
  mout << is_instance<Fun_Multiply<double>, Fun_Multiply>{} <<endl;

  short var_short;
  int var_int;
  long int var_long;
  long long var_longlong;
  std::string var_string;
  mout << getTypeName(var_short) << endl;
  mout << getTypeName(var_int) << endl;
  mout << getTypeName(var_long) << endl;
  mout << getTypeName(var_longlong) << endl;
  mout << getTypeName(var_string) << endl;
  mout << "sizeof(char) = " << sizeof(char) << endl;
  mout << "sizeof(short) = " << sizeof(short) << endl;
  mout << "sizeof(int) = " << sizeof(int) << endl;
  mout << "sizeof(long) = " << sizeof(long) << endl;
  mout << "sizeof(long long) = " << sizeof(long long) << endl;
  mout << endl;
  mout << "sizeof(float) = " << sizeof(float) << endl;
  mout << "sizeof(double) = " << sizeof(double) << endl;
  mout << "sizeof(long double) = " << sizeof(long double) << endl;
  mout << endl;
  mout << "sizeof(bool) = " << sizeof(bool) << endl;
  mout << "sizeof(std::complex<float>) = " << sizeof(std::complex<float>) << endl;

  char var_char;
  unsigned char var_unsigned_char;
  signed char var_signed_char;
  unsigned int var_unsigned_int;
  signed int var_signed_int;
  mout << (typeid(var_char) == typeid(var_unsigned_char)) << endl;
  mout << (typeid(var_char) == typeid(var_signed_char)) << endl;

  mout << (typeid(var_int) == typeid(var_unsigned_int)) << endl;
  mout << (typeid(var_int) == typeid(var_signed_int)) << endl;

  mout << Fun_Plus_Base::expression("x") << endl;

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
  mout << Fun_Monomial<double>::expression("x","n") << endl;

  mout << Fun_Atan2<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Atan2<double>::expression("x","y") << endl;

  mout << Fun_Sin<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Sin<double>::expression("x") << endl;

  mout << Fun_Cos<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Cos<double>::expression("x") << endl;

  mout << Fun_Tan<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Tan<double>::expression("x") << endl;

  mout << Fun_Sqrt<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Sqrt<double>::expression("x") << endl;

  mout << Fun_Sqr<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Sqr<double>::expression("x") << endl;

  mout << Fun_Cube<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Cube<double>::expression("x") << endl;

  mout << Fun_Exp<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Exp<double>::expression("x") << endl;

  mout << Fun_Abs<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Abs<double>::expression("x") << endl;

  mout << Fun_Sgn<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Sgn<double>::expression("x") << endl;

  mout << Fun_Log<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Log<double>::expression("x") << endl;

  mout << Fun_Log2<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Log2<double>::expression("x") << endl;

  mout << Fun_Log10<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Log10<double>::expression("x") << endl;

  mout << Fun_Asin<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Asin<double>::expression("x") << endl;

  mout << Fun_Acos<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Acos<double>::expression("x") << endl;

  mout << Fun_Atan<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Atan<double>::expression("x") << endl;

  mout << Fun_Ceil<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Ceil<double>::expression("x") << endl;

  mout << Fun_Round<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Round<double>::expression("x") << endl;

  mout << Fun_Sinh<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Sinh<double>::expression("x") << endl;

  mout << Fun_Cosh<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Cosh<double>::expression("x") << endl;

  mout << Fun_Tanh<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Tanh<double>::expression("x") << endl;

  mout << Fun_Roundzero<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Roundzero<double>::expression("x","y") << endl;


  s = StyledString::get(ANGLE1).get() + getTypeName(d) + StyledString::get(COMMA).get() + "function(.,.)" + StyledString::get(ANGLE2).get();
  mout << Fun_UnaryUser<double,f1>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_UnaryUser<double,f1>::expression("x") << endl;
  mout << Fun_BinaryUser<double,f2>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_BinaryUser<double,f2>::expression("x","y") << endl;


  mout << Fun_Not::classname() << getBracketedTypeName(true) << " ";
  mout << Fun_Not::expression("x") << endl;
  mout << Fun_And::classname() << getBracketedTypeName(true) << " ";
  mout << Fun_And::expression("x","y") << endl;
  mout << Fun_Or::classname() << getBracketedTypeName(true) << " ";
  mout << Fun_Or::expression("x","y") << endl;


  mout << Fun_Equal<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Equal<double>::expression("x","y") << endl;
  mout << Fun_NotEqual<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_NotEqual<double>::expression("x","y") << endl;
  mout << Fun_LessOrEqual<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_LessOrEqual<double>::expression("x","y") << endl;
  mout << Fun_GreaterOrEqual<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_GreaterOrEqual<double>::expression("x","y") << endl;
  mout << Fun_Less<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Less<double>::expression("x","y") << endl;
  mout << Fun_Greater<double>::classname() << getBracketedTypeName(d) << " ";
  mout << Fun_Greater<double>::expression("x","y") << endl;

  mout << typeid(&f1).name() <<endl;
  mout << typeid(f2).name() <<endl;
  mout << typeid(FunctionTypes<double>::unary_func).name() <<endl;
  mout << getTypeName(f1) <<endl;
  return 0;
}
