#define MATRICKS_DEBUG 1
#include "matricks.h"

#include <vector>


#if CPP11 == 1
#include <initializer_list>
#endif

#include "TypeTraits.h"
#include <string>

  

template <class D, template<typename> class F> void printUnary() {
  mout << F<D>::classname()  << " ";
  mout << F<D>::expression("x") << std::endl;
}

template <class F> void printUnary() {
  mout << F::classname()  << " ";
  mout << F::expression("x") << std::endl;
}

template <class D, template<typename> class F> void printBinary() {
  mout << F<D>::classname()  << " ";
  mout << F<D>::expression("x","y") << std::endl;
}
template <class F> void printBinary() {
  mout << F::classname()  << " ";
  mout << F::expression("x","y") << std::endl;
}


// template bag of tricks

template <class T> class Experiment {
public:
  typedef T Type;
  static std::string TypeName;
};


template <typename T> std::string Experiment<T>::TypeName = typeid(Experiment<T>::Type).name();

template <> std::string Experiment<long int>::TypeName = "long int";




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
  using namespace std;
  using namespace matricks;
  using namespace display;



  print_matricks_info();

  
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

  double d;

  mout << is_instance<Fun_Multiply<double>, Fun_Divide>{} <<endl;
  mout << is_instance<Fun_Multiply<double>, Fun_Multiply>{} <<endl;


  // The following causes a compiler error.
  // I think because vector has two template arguments with the second having
  // a default value
  
  //  mout <<  is_instance<std::vector<int>, std::vector>{}  << endl;
  
  
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

  mout << typeid(&f1).name() <<endl;
  mout << typeid(f2).name() <<endl;
  mout << typeid(FunctionTypes<double>::unary_func).name() <<endl;
  mout << getTypeName(f1) <<endl;



    
  printUnary<double,Fun_Plus>();
  printUnary<double,Fun_Minus>();
  mout << Fun_Cast<double,int>::classname() << " ";
  mout << Fun_Cast<double,int>::expression("n") << endl;
  printBinary<double,Fun_Add>();
  printBinary<double,Fun_Subtract>();
  printBinary<double,Fun_Multiply>();
  printBinary<double,Fun_Divide>();
  printBinary<double,Fun_Pow>();
  printBinary<double,Fun_Monomial>();

  printUnary<double,Fun_Sqr>();
  printUnary<double,Fun_Cube>();
  printUnary<double,Fun_Sqrt>();
  printUnary<double,Fun_Exp>();
  printUnary<double,Fun_Log>();
  printUnary<double,Fun_Log2>();
  printUnary<double,Fun_Log10>();
  printUnary<double,Fun_Sin>();
  printUnary<double,Fun_Cos>();
  printUnary<double,Fun_Tan>();
  printUnary<double,Fun_Asin>();
  printUnary<double,Fun_Acos>();
  printUnary<double,Fun_Atan>();
  printBinary<double,Fun_Atan2>();
  printUnary<double,Fun_Sinh>();
  printUnary<double,Fun_Cosh>();
  printUnary<double,Fun_Tanh>();

  printUnary<double,Fun_Abs>();
  printUnary<double,Fun_Sgn>();
  printUnary<double,Fun_Ceil>();
  printUnary<double,Fun_Floor>();
  printUnary<double,Fun_Round>();
  printBinary<double,Fun_Roundzero>();

  mout << Fun_UnaryUser<double,f1>::classname()  << " ";
  mout << Fun_UnaryUser<double,f1>::expression("x") << endl;
  mout << Fun_BinaryUser<double,f2>::classname()  << " ";
  mout << Fun_BinaryUser<double,f2>::expression("x","y") << endl;

  // s = StyledString::get(ANGLE1).get() + getTypeName(d) + StyledString::get(COMMA).get() + "function(.,.)" + StyledString::get(ANGLE2).get();
  // mout << Fun_UnaryUser<double,f1>::classname()  << " ";
  // mout << Fun_UnaryUser<double,f1>::expression("x") << endl;
  // mout << Fun_BinaryUser<double,f2>::classname()  << " ";
  // mout << Fun_BinaryUser<double,f2>::expression("x","y") << endl;


  printUnary<Fun_Not>();
  printBinary<Fun_And>();
  printBinary<Fun_Or>();


  printBinary<double,Fun_Equal>();
  printBinary<double,Fun_NotEqual>();
  printBinary<double,Fun_LessOrEqual>();
  printBinary<double,Fun_GreaterOrEqual>();
  printBinary<double,Fun_Less>();
  printBinary<double,Fun_Greater>();


  printBinary<double,Fun_Polar>();
  printBinary<double,Fun_Complex>();
  printBinary<double,Fun_AddCR>();
  printBinary<double,Fun_AddRC>();
  printBinary<double,Fun_SubtractCR>();
  printBinary<double,Fun_SubtractRC>();
  printBinary<double,Fun_MultiplyCR>();
  printBinary<double,Fun_MultiplyRC>();
  printBinary<double,Fun_DivideCR>();
  printBinary<double,Fun_DivideRC>();
  printBinary<double,Fun_PowCR>();
  printBinary<double,Fun_PowRC>();
  printUnary<double,Fun_CAbs>();
  printUnary<double,Fun_Arg>();
  printUnary<double,Fun_Conj>();
  printUnary<double,Fun_Real>();
  printUnary<double,Fun_Imag>();
  printUnary<double,Fun_RoundCplx>();

  
  
   Dimensions dims1(2,1,3);
   disp(dims1);
   disp(dims1.reduce());
   Dimensions dims2(2,3);
   disp(dims2);
   disp(dims2.reduce());
   disp(dims1 == dims2);
   disp(dims1.reduce() == dims2.reduce());
   disp(equiv(dims1,dims2));
   Dimensions dims3(2,5);
   disp(dims3);
   disp(equiv(dims1,dims3));
   disp(equiv(dims2,dims3));

   VectorofPtrs addrs1((void*)&dims1);
   addrs1.add((void*)&dims2);
   disp(addrs1);
   
   VectorofPtrs addrs2((void*)&dims3);
   addrs2.add((void*)&x);
   disp(addrs2);
   disp(common(addrs1,addrs2));
   addrs2.add((void*)&dims1);
   disp(addrs2);
   disp(common(addrs1,addrs2));


  Vector<double> vv({1,2,3});
  disp(vv);
  Vector<double> ww({0,0,0});
  disp(ww);
  disp(dimequiv(vv,ww));
  disp(common(vv,ww));
  disp(common(vv,vv));

  double x1 = 1;
  double x2 = x1 + 3e-16;
  disp(approx(x1,x2,0.));
  disp(approx(x1,x2,3.5e-16));
   
   
  return 0;
}
