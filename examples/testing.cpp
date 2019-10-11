#define MATRICKS_DEBUG 1
#include "matricks.h"

#include <vector>


#if CPP11 == 1
#include <initializer_list>
#endif

#include "TypeTraits.h"
#include <string>

template<typename T>
T adder(T v) {
  return v;
}

template<typename T, typename... Args>
T adder(T first, Args... args) {
  return first + adder(args...);
}


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

int main(int argc, char *argv[])
{
  const double pi = M_PI;
  std::string myname = argv[0];
  using namespace matricks;
  using namespace display;
  using namespace std;
  
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
  
  int n = 45;
  unsigned int m = 256;
  double x = 3.14;
  double vals[] = {1.1,2.2,3.3};
  bool done = true;
  Vector<double> v = range<double>(1,10);
  char str[] = "hello";
  std::string s = "world";
  ComplexDouble z(1,-1);
  Vector<ComplexDouble > vc(2);
  vc[0] = ComplexDouble(2.0,3.0);
  vc[1] = ComplexDouble(-2.0,7.0);
  
  cr();cr();
  disp(n);
  disp(m);
  disp(x);
  disp(vals);
  disp(done);
  disp(v);
  disp(vc);
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
  tdisp(vc);
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
  mout << bold << "  ";
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
  mout << "sizeof(ComplexFloat) = " << sizeof(ComplexFloat) << endl;

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
   

  TensorAbstract* t = new Scalar<int>(22);
  Scalar<int>* t2 = static_cast<Scalar<int>* >(t);

  disp(*t2);
  mout << "t="<<*t2<<endl;


  disp(typeid(*t).name());
  disp(typeid(*t2).name());
  disp(is_instance<typeof(*t), Scalar>{});
  disp(is_instance<typeof(*t2), Scalar>{});

  Scalar<int> s1 = 12;
  Scalar<int> s2 = 10;
  disp(s1+s2);
  tdisp(s1+s2);

  Vector<int> v1 = {1,2};
  Vector<int> v2 = {10,20};
  disp(v1+v2);
  tdisp(v1+v2);


  TensorType<T_SCALAR,int>::MyType s3 = s2;

  disp(s3);

  Matrix<double> A(2,3);
  A= {{1,2,3},{4,5,6}};
  tdisp(A);
  A.transpose();
  tdisp(A);

  {
    Dimensions dims1(2,1,7);
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
  }
  {
    Dimensions dims3(2,2,2);
    disp(dims3);
    Tensor<double> T(dims3);
    disp(T.dims());
    disp(T.index(0,0,0));
    disp(T.index(0,0,1));
    disp(T.index(0,1,0));
    disp(T.index(0,1,1));
    disp(T.index(1,0,0));
    disp(T.index(1,0,1));
    disp(T.index(1,1,0));
    disp(T.index(1,1,1));

    
    for(int k = 0; k < T.size(); k++) {
      mdisp(k,T.indices(k));
      T[k] = k;
    }
    disp(T(0,0,0));
    disp(T(0,0,1));
    disp(T(0,1,0));
    disp(T(0,1,1));
    disp(T(1,0,0));
    disp(T(1,0,1));
    disp(T(1,1,0));
    disp(T(1,1,1));
    disp(42);
    tdisp(T);
    
    Dimensions dims4(13,17,11,14);
    disp(dims4);
    Dimensions dims6({22,45,11,18,12,11});
    disp(dims6);
  }
  {
    Dimensions dims(3,2,1,6);
    disp(dims);
    double c = 0;
    Tensor<double> T(dims);
    for(int i = 0; i < T.dims()[0]; i++) {
      for(int j = 0; j < T.dims()[1]; j++) {
	for(int k = 0; k < T.dims()[2]; k++) {
	  for(int m = 0; m < T.dims()[3]; m++) {
	    T(i,j,k,m) = 100+c++;
	  }
	}
      }
    }
    disp(T);
  }
  {
    Dimensions dims(3,2,3,6);
    disp(dims);
    double c = 0;
    Tensor<double> T(dims);
    for(int i = 0; i < T.dims()[0]; i++) {
      for(int j = 0; j < T.dims()[1]; j++) {
	for(int k = 0; k < T.dims()[2]; k++) {
	  for(int m = 0; m < T.dims()[3]; m++) {
	    T(i,j,k,m) = c++;
	  }
	}
      }
    }
    disp(T);
  }
  {
    Dimensions dims(3,2);
    disp(dims);
    double c = 0;
    Tensor<double> T(dims);
    for(int i = 0; i < T.dims()[0]; i++) {
      for(int j = 0; j < T.dims()[1]; j++) {
	T(i,j) = c++;
      }
    }
    disp(T);
  }

  {
    Vector<double> q = {21,22};
    tdisp(q);
    double x10 = q(0);
    double x11 = q(1);
    mdisp(x10,x11);cr();
    x10 = q((size_type)0);
  }


  disp(sizeof(size_type));
  disp(sizeof(index_type));

  {
    AddType<double,float>::Type x;
    tdisp(x);
  }
  {
    AddType<double,int>::Type x;
    tdisp(x);
    double y = 3.1;
    int n = 10;
    AddType<double,int>::Type z = y + n;
    tdisp(y);
    tdisp(n);
    tdisp(z);

  }


  // mixed complex adding
  
  {
    cr();
    mout << bold.apply("complex<double> + complex<float>") << endl; 
    mout << "AddType<double,float>::Type=" << AddType<double,float>::name() << endl;
    ComplexDouble z = ComplexDouble(1,2);
    ComplexFloat x = ComplexFloat(4,-3);
    tdisp(z);
    tdisp(x);
    tdisp((z+x));
    AddType<ComplexDouble,ComplexFloat>::Type q = z+x;
    tdisp(q);
  }
  {
    cr();
    mout << bold.apply("complex<int> + complex<float>") << endl; 
    mout << "AddType<int,float>::Type=" << AddType<int,float>::name() << endl;
    ComplexInt z = ComplexInt(1,2);
    ComplexFloat x = ComplexFloat(4,-3);
    tdisp(z);
    tdisp(x);
    tdisp((z+x));
    AddType<ComplexInt,ComplexFloat>::Type q = z+x;
    tdisp(q);
  }
  {
    cr();
    mout << bold.apply("complex<float> + complex<int>") << endl; 
    mout << "AddType<float,int>::Type=" << AddType<float,int>::name() << endl;
    ComplexFloat z = ComplexFloat(1,2);
    ComplexInt x = ComplexInt(4,-3);
    tdisp(z);
    tdisp(x);
    tdisp((z+x));
    AddType<ComplexFloat,ComplexInt>::Type q = z+x;
    tdisp(q);
  }


  // mixed complex SUBTRACT
  {
    cr();
    mout << bold.apply("complex<double> - complex<float>") << endl; 
    ComplexDouble z = ComplexDouble(1,2);
    ComplexFloat x = ComplexFloat(4,-3);
    tdisp(z);
    tdisp(x);
    tdisp((z-x));
    SubType<ComplexDouble,ComplexFloat>::Type q = z-x;
    tdisp(q);
  }
  {
    cr();
    mout << bold.apply("complex<int> - complex<float>") << endl; 
    ComplexInt z = ComplexInt(1,2);
    ComplexFloat x = ComplexFloat(4,-3);
    tdisp(z);
    tdisp(x);
    tdisp((z-x));
    SubType<ComplexInt,ComplexFloat>::Type q = z-x;
    tdisp(q);
  }
  {
    cr();
    mout << bold.apply("complex<float> - complex<int>") << endl; 
    ComplexFloat z = ComplexFloat(1,2);
    ComplexInt x = ComplexInt(4,-3);
    tdisp(z);
    tdisp(x);
    tdisp((z-x));
    SubType<ComplexFloat,ComplexInt>::Type q = z-x;
    tdisp(q);
  }


  
  // mixed complex MULTIPLY
  {
    cr();
    mout << bold.apply("complex<double> * complex<float>") << endl; 
    ComplexDouble z = ComplexDouble(1,2);
    ComplexFloat x = ComplexFloat(4,-3);
    tdisp(z);
    tdisp(x);
    tdisp((z*x));
    MultType<ComplexDouble,ComplexFloat>::Type q = z*x;
    tdisp(q);
  }
  {
    cr();
    mout << bold.apply("complex<int> * complex<float>") << endl; 
    ComplexInt z = ComplexInt(1,2);
    ComplexFloat x = ComplexFloat(4,-3);
    tdisp(z);
    tdisp(x);
    tdisp((z*x));
    MultType<ComplexInt,ComplexFloat>::Type q = z*x;
    tdisp(q);
  }
  {
    cr();
    mout << bold.apply("complex<float> * complex<int>") << endl; 
    ComplexFloat z = ComplexFloat(1,2);
    ComplexInt x = ComplexInt(4,-3);
    tdisp(z);
    tdisp(x);
    tdisp((z*x));
    MultType<ComplexFloat,ComplexInt>::Type q = z*x;
    tdisp(q);
  }
    

  // mixed complex DIVIDE
  {
    cr();
    mout << bold.apply("complex<double> / complex<float>") << endl; 
    ComplexDouble z = ComplexDouble(1,2);
    ComplexFloat x = ComplexFloat(4,-3);
    tdisp(z);
    tdisp(x);
    tdisp((z/x));
    DivType<ComplexDouble,ComplexFloat>::Type q = z/x;
    tdisp(q);
  }
  {
    cr();
    mout << bold.apply("complex<int> / complex<float>") << endl; 
    ComplexInt z = ComplexInt(1,2);
    ComplexFloat x = ComplexFloat(4,-3);
    tdisp(z);
    tdisp(x);
    tdisp((z/x));
    DivType<ComplexInt,ComplexFloat>::Type q = z/x;
    tdisp(q);
  }
  {
    cr();
    mout << bold.apply("complex<float> / complex<int>") << endl; 
    ComplexFloat z = ComplexFloat(1,2);
    ComplexInt x = ComplexInt(4,-3);
    tdisp(z);
    tdisp(x);
    tdisp((z/x));
    DivType<ComplexFloat,ComplexInt>::Type q = z/x;
    tdisp(q);
  }
    



    
  // {
  //   cr();
  //   ComplexDouble z = ComplexDouble(1,2);
  //   ComplexFloat x = ComplexFloat(1,2);
  //   tdisp(z);
  //   tdisp(x);
  //   tdisp((z+x));
  //   ArithmeticType<ComplexDouble,ComplexFloat>::Type q;
  //   tdisp(q);
  // }
  // {
  //   cr();
  //   ComplexFloat z = ComplexFloat(1,2);
  //   float x = 10;
  //   tdisp(z);
  //   tdisp(x);
  //   tdisp((z+x));
  //   ArithmeticType<ComplexFloat,float>::Type q;
  //   tdisp(q);
  // }
  // {
  //   cr();
  //   ComplexFloat z = ComplexFloat(1,2);
  //   double x = 10;
  //   tdisp(z);
  //   tdisp(x);
  //   tdisp((z+x));
  //   ArithmeticType<ComplexFloat,double>::Type r;
  //   tdisp(r);
  // }
  // {
  //   cr();
  //   ComplexDouble z = ComplexDouble(1,2);
  //   float x = 10;
  //   tdisp(z);
  //   tdisp(x);
  //   tdisp((z+x));
  //   ArithmeticType<ComplexDouble,float>::Type r;
  //   tdisp(r);
  // }
  // {
  //   cr();
  //   ComplexDouble z = ComplexDouble(1,2);
  //   float x = 10;
  //   tdisp(z);
  //   tdisp(x);
  //   tdisp((x+z));
  //   ArithmeticType<float,ComplexDouble>::Type r;
  //   tdisp(r);
  // }

  // {
  //   cr();
  //   ComplexDouble z = ComplexDouble(1,2);
  //   int x = 10;
  //   tdisp(z);
  //   tdisp(x);
  //   tdisp((x+z));
  //   ArithmeticType<int,ComplexDouble>::Type r;
  //   tdisp(r);
  // }
  // {
  //   cr();
  //   ComplexDouble z = ComplexDouble(1,2);
  //   int x = 10;
  //   tdisp(z);
  //   tdisp(x);
  //   tdisp((x+z));
  //   ArithmeticType<int,ComplexDouble>::Type r;
  //   tdisp(r);
  // }

  // {
  //   cr();
  //   mout << bold.apply("ContainedType usage") << std::endl;
  //   typename ContainedType<int>::Type x1;
  //   mout << "ContainedType<int>::Type x1 = ";
  //   tdisp(x1);
  //   typename ContainedType<std::complex<int> >::Type x2;
  //   mout << "ContainedType<std::complex<int> >::Type x2 = ";
  //   tdisp(x2);
  //   typename ContainedType<std::complex<std::complex<int> > >::Type x3;
  //   mout << "ContainedType<std::complex<std::complex<int> > >::Type x3 = ";
  //   tdisp(x3);
  // }
  // {
  //   cr();
  //   mout <<  bold.apply("BaseType usage") << std::endl;
  //   typename BaseType<int>::Type x1;
  //   mout << "BaseType<int>::Type x1 =  ";
  //   tdisp(x1);
  //   typename BaseType<std::complex<int> >::Type x2;
  //   mout << "BaseType<std::complex<int> >::Type x2 =  ";
  //   tdisp(x2);
  //   typename BaseType<std::complex<std::complex<int> >>::Type x3;
  //   mout << "BaseType<std::complex<std::complex<int> >>::Type x3 = ";
  //   tdisp(x3);
  // }


  // // complex mixed addition
  // {
  //   cr();
  //   mout <<  bold.apply("complex mixed addition") << std::endl;
  //   ComplexDouble x = ComplexDouble(1,2);
  //   ComplexFloat y = ComplexFloat(1,2);
  //   tdisp(x);
  //   tdisp(y);
  //   tdisp(x+y);
  //   tdisp(y+x);
  // }
  // {
  //   cr();
  //   ComplexDouble x = ComplexDouble(1,2);
  //   float y = 4;
  //   tdisp(x);
  //   tdisp(y);
  //   tdisp(x+y);
  //   tdisp(y+x);
  // }
  // {
  //   cr();
  //   ComplexFloat x = ComplexFloat(1,2);
  //   double y = 4;
  //   tdisp(x);
  //   tdisp(y);
  //   tdisp(x+y);
  //   tdisp(y+x);
  // }

  // // complex mixed subtraction
  // {
  //   cr();
  //   mout <<  bold.apply("complex mixed subtraction") << std::endl;
  //   ComplexDouble x = ComplexDouble(1,2);
  //   ComplexFloat y = ComplexFloat(1,2);
  //   tdisp(x);
  //   tdisp(y);
  //   tdisp(x-y);
  //   tdisp(y-x);
  // }
  // {
  //   cr();
  //   ComplexDouble x = ComplexDouble(1,2);
  //   float y = 4;
  //   tdisp(x);
  //   tdisp(y);
  //   tdisp(x-y);
  //   tdisp(y-x);
  // }
  // {
  //   cr();
  //   ComplexFloat x = ComplexFloat(1,2);
  //   double y = 4;
  //   tdisp(x);
  //   tdisp(y);
  //   tdisp(x-y);
  //   tdisp(y-x);
  // }

  // // complex mixed multiplication
  // {
  //   cr();
  //   mout <<  bold.apply("complex mixed multiplication") << std::endl;
  //   ComplexDouble x = ComplexDouble(1,2);
  //   ComplexFloat y = ComplexFloat(3,-5);
  //   tdisp(x);
  //   tdisp(y);
  //   tdisp(x*y);
  //   tdisp(y*x);
  // }
  // {
  //   cr();
  //   ComplexDouble x = ComplexDouble(1,2);
  //   float y = 4;
  //   tdisp(x);
  //   tdisp(y);
  //   tdisp(x*y);
  //   tdisp(y*x);
  // }
  // {
  //   cr();
  //   ComplexFloat x = ComplexFloat(1,2);
  //   double y = 4;
  //   tdisp(x);
  //   tdisp(y);
  //   tdisp(x*y);
  //   tdisp(y*x);
  // }

  // // complex mixed division
  // {
  //   cr();
  //   mout <<  bold.apply("complex mixed division") << std::endl;
  //   ComplexDouble x = ComplexDouble(1,2);
  //   ComplexFloat y = ComplexFloat(3,-5);
  //   tdisp(x);
  //   tdisp(y);
  //   tdisp(x/y);
  //   tdisp(y/x);
  // }
  // {
  //   cr();
  //   ComplexDouble x = ComplexDouble(1,2);
  //   float y = 4;
  //   tdisp(x);
  //   tdisp(y);
  //   tdisp(x/y);
  //   tdisp(y/x);
  // }
  // {
  //   cr();
  //   ComplexFloat x = ComplexFloat(1,2);
  //   double y = 4;
  //   tdisp(x);
  //   tdisp(y);
  //   tdisp(x/y);
  //   tdisp(y/x);
  // }
  // {
  //   cr();

  //   // float 
  //   cr();
  //   mout << createStyle(BOLD+BLUE1).apply("float") << std::endl;
  //   mout << "ContainedType" << std::endl;
  //   ContainedType<float>::Type x1;
  //   tdisp(x1);
  //   float s2 = 0;
  //   ContainedType<typeof(s2)>::Type x2;
  //   tdisp(x2);

  //   mout << "BaseType" << std::endl;
  //   BaseType<float>::Type x3;
  //   tdisp(x3);
  //   float s4 = 0;
  //   BaseType<typeof(s4)>::Type x4;
  //   tdisp(x4);
  // }
  // {
  //   // complex<float>
  //   cr();
  //   mout << createStyle(BOLD+BLUE1).apply("complex<float>") << std::endl;
  //   mout << "ContainedType" << std::endl;
  //   ContainedType<ComplexFloat>::Type x1;
  //   tdisp(x1);
  //   ComplexFloat s2 = 0;
  //   ContainedType<typeof(s2)>::Type x2;
  //   tdisp(x2);

  //   mout << "BaseType" << std::endl;
  //   BaseType<ComplexFloat>::Type x3;
  //   tdisp(x3);
  //   ComplexFloat s4 = 0;
  //   BaseType<typeof(s4)>::Type x4;
  //   tdisp(x4);
  // }
  // {
  //   // complex<complex<float>>
  //   cr();
  //   mout << createStyle(BOLD+BLUE1).apply("complex<complex<float>>") << std::endl;
  //   mout << "ContainedType" << std::endl;
  //   ContainedType<std::complex<std::complex<float> > >::Type x1;
  //   tdisp(x1);
  //   std::complex<std::complex<float> >  s2;
  //   ContainedType<typeof(s2)>::Type x2;
  //   tdisp(x2);

  //   mout << "BaseType" << std::endl;
  //   BaseType<std::complex<std::complex<float> > >::Type x3;
  //   tdisp(x3);
  //   std::complex<std::complex<float> >  s4;
  //   BaseType<typeof(s4)>::Type x4;
  //   tdisp(x4);
  // }
  // {
  //   // Vector<float>
  //   cr();
  //   mout << createStyle(BOLD+BLUE1).apply("Vector<float>") << std::endl;
  //   mout << "ContainedType" << std::endl;
  //   ContainedType<Vector<float> >::Type x1;
  //   tdisp(x1);
  //   Vector<float> s2;
  //   ContainedType<typeof(s2)>::Type x2;
  //   tdisp(x2);

  //   mout << "BaseType" << std::endl;
  //   BaseType<Vector<float> >::Type x3;
  //   tdisp(x3);
  //   Vector<float> s4;
  //   BaseType<typeof(s4)>::Type x4;
  //   tdisp(x4);
  // }
  // {
  //   // Vector<complex<float>>
  //   cr();
  //   mout << createStyle(BOLD+BLUE1).apply("Vector<complex<float>>") << std::endl;
  //   mout << "ContainedType" << std::endl;
  //   ContainedType<Vector<std::complex<float> > >::Type x1;
  //   tdisp(x1);
  //   Vector<std::complex<float> >  s2;
  //   ContainedType<typeof(s2)>::Type x2;
  //   tdisp(x2);

  //   mout << "BaseType" << std::endl;
  //   BaseType<Vector<std::complex<float> > >::Type x3;
  //   tdisp(x3);
  //   Vector<std::complex<float> >  s4;
  //   BaseType<typeof(s4)>::Type x4;
  //   tdisp(x4);
  // }



  // complex mixed addition
  // {
  //   cr();
  //   ComplexDouble x = ComplexDouble(1,2);
  //   Vector<ComplexDouble> y(2);
  //   tdisp(x);
  //   tdisp(y);
  //   tdisp(x*y);
  // }

  
  // complex mixed addition with vector
  // {
  //   cr();
  //   mout <<  bold.apply("complex mixed addition with vector") << std::endl;
    // ComplexDouble x = ComplexDouble(1,2);
    // Vector<ComplexDouble> v(2);
    // tdisp(x);
    // tdisp(v);
    // tdisp(x+v);
  //}


  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  return 0;
}
