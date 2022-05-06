#include <vector>
#include <string>

#define MATHQ_DEBUG 0
#include "mathq.h"


template <typename T>
T adder(T v) {
  return v;
}

template <typename T, typename... Args>
T adder(T first, Args... args) {
  return first + adder(args...);
}


template <class D, template <typename> class F>
void printUnary() {
  MOUT << F<D>::classname() << " ";
  MOUT << F<D>::expression("x") << std::endl;
}

template <class F>
void printUnary() {
  MOUT << F::classname() << " ";
  MOUT << F::expression("x") << std::endl;
}





// template bag of tricks

template <class T>
class Experiment {
public:
  typedef T Type;
  static std::string TypeName;
};


template <typename T>
std::string Experiment<T>::TypeName = typeid(Experiment<T>::Type).name();

template <>
std::string Experiment<long int>::TypeName = "long int";




double f1(double x) {
  return ((x >= 0) ? x : 0);
}

double f2(double x, double y) {
  return ((x >= 0) ? x : 0);
}

int main(int argc, char *argv[]) {


  typedef typename mathq::Vector<double> VectorDouble;

  const double pi = M_PI;
  std::string myname = argv[0];
  using namespace mathq;
  using namespace display;
  using namespace std;

  Style bold = CREATESTYLE(BOLD);

  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  CR();
  CR();
  MOUT << StyledString::get(HORLINE);
  MOUT << "running: " << bold.apply(myname) << std::endl;


  MOUT << "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;

  print_mathq_info();

  int n = 45;
  unsigned int m = 256;
  double x = 3.14;
  double vals[] = {1.1, 2.2, 3.3};
  bool done = true;
  Vector<double> v = range<double>(1, 10);
  char str[] = "hello";
  std::string s = "world";
  ComplexDouble z(1, -1);
  Vector<ComplexDouble> vc(2);
  vc[0] = ComplexDouble(2.0, 3.0);
  vc[1] = ComplexDouble(-2.0, 7.0);

  CR();
  CR();
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

  CR();
  CR();
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

  CR();
  CR();
  mdisp(n, m, x, vals, done, str, s, z);

  CR();
  CR();
  dispval(n);
  dispval(m);

  CR();
  CR();
  disp(n + 3);
  disp(10 * x - 1);
  disp(!done);
  disp(round(10 * sin(pi / 10 * v) + 10));
  disp(s + " tour");
  MOUT << std::endl;

  MOUT << CREATESTYLE(GRAY1) << "  ";
  MOUT << CREATESTYLE(GRAY2) << "  ";
  MOUT << CREATESTYLE(WHITE + BLACKBACK) << "  ";
  MOUT << std::endl;

  MOUT << CREATESTYLE(RED) << "  ";
  MOUT << std::endl;
  MOUT << CREATESTYLE(ORANGE) << "  ";
  MOUT << std::endl;
  MOUT << CREATESTYLE(YELLOW) << "  ";
  MOUT << CREATESTYLE(YELLOWBRIGHT) << "  ";
  MOUT << std::endl;
  MOUT << CREATESTYLE(GREEN) << "  ";
  MOUT << CREATESTYLE(GREENBRIGHT) << "  ";
  MOUT << CREATESTYLE(GREEN1) << "  ";
  MOUT << std::endl;
  MOUT << CREATESTYLE(CYAN) << "  ";
  MOUT << CREATESTYLE(BLUE) << "  ";
  MOUT << CREATESTYLE(BLUEBRIGHT) << "  ";
  MOUT << CREATESTYLE(BLUE1) << "  ";
  MOUT << CREATESTYLE(BLUE2) << "  ";
  MOUT << CREATESTYLE(BLUE3) << "  ";
  MOUT << std::endl;
  MOUT << CREATESTYLE(MAGENTA) << "  ";
  MOUT << CREATESTYLE(MAGENTA1) << "  ";
  MOUT << CREATESTYLE(VIOLET1) << "  ";
  MOUT << std::endl;
  MOUT << bold << "  ";
  MOUT << CREATESTYLE(UNDERLINE) << "  ";
  MOUT << CREATESTYLE(CROSSEDOUT) << "  ";
  MOUT << CREATESTYLE(OVERLINE) << "  ";
  MOUT << CREATESTYLE(SLOWBLINK) << "  ";
  MOUT << std::endl;

  MOUT << CREATESTYLE(REDBACK) << "  ";
  MOUT << CREATESTYLE(ORANGEBACK) << "  ";
  MOUT << CREATESTYLE(YELLOWBACK) << "  ";
  MOUT << CREATESTYLE(GREENBACK) << "  ";
  MOUT << std::endl;
  MOUT << std::endl;
  MOUT << std::endl;

  MOUT << CREATESTYLE(BOLD + UNDERLINE + VIOLET1) << "  ";
  MOUT << std::endl;
  MOUT << std::endl;
  MOUT << std::endl;
  MOUT << std::endl;

  {
    Style mystyle = CREATESTYLE(BOLD + RED);
    MOUT << mystyle.apply("with style") + " without style " << std::endl;
  }
  MOUT << std::endl;
  MOUT << std::endl;
  MOUT << std::endl;

  {
    int nf = 27;  // color for foreground
    int nb = 227; // color for background
    Style mystyle(nf, nb);
    MOUT << mystyle.apply("Hello World") << std::endl;

    MOUT << std::endl;
    MOUT << std::endl;
    MOUT << std::endl;


    Style bold(BOLD);
    Style mybold = bold + mystyle;
    MOUT << mybold.apply("Hello World") << std::endl;

    Style black(BLACK);
    MOUT << "XXX" << black.apply("XXX") << "XXX" << std::endl;
  }

  CR();
  CR();

  double d;

  // MOUT << is_instance<Fun_Multiply<double,int>, Fun_Divide>{} <<endl;
  // MOUT << is_instance<Fun_Multiply<double,float>, Fun_Multiply>{} <<endl;


  // The following causes a compiler error.
  // I think because vector has two template arguments with the second having
  // a default value

  //  MOUT <<  is_instance<std::vector<int>, std::vector>{}  << endl;


  short var_short;
  int var_int;
  long int var_long;
  long long var_longlong;
  std::string var_string;
  MOUT << getTypeName(var_short) << endl;
  MOUT << getTypeName(var_int) << endl;
  MOUT << getTypeName(var_long) << endl;
  MOUT << getTypeName(var_longlong) << endl;
  MOUT << getTypeName(var_string) << endl;
  MOUT << "sizeof(char) = " << sizeof(char) << endl;
  MOUT << "sizeof(short) = " << sizeof(short) << endl;
  MOUT << "sizeof(int) = " << sizeof(int) << endl;
  MOUT << "sizeof(long) = " << sizeof(long) << endl;
  MOUT << "sizeof(long long) = " << sizeof(long long) << endl;
  MOUT << endl;
  MOUT << "sizeof(float) = " << sizeof(float) << endl;
  MOUT << "sizeof(double) = " << sizeof(double) << endl;
  MOUT << "sizeof(long double) = " << sizeof(long double) << endl;
  MOUT << endl;
  MOUT << "sizeof(bool) = " << sizeof(bool) << endl;
  MOUT << "sizeof(ComplexFloat) = " << sizeof(ComplexFloat) << endl;

  char var_char;
  unsigned char var_unsigned_char;
  signed char var_signed_char;
  unsigned int var_unsigned_int;
  signed int var_signed_int;
  MOUT << (typeid(var_char) == typeid(var_unsigned_char)) << endl;
  MOUT << (typeid(var_char) == typeid(var_signed_char)) << endl;

  MOUT << (typeid(var_int) == typeid(var_unsigned_int)) << endl;
  MOUT << (typeid(var_int) == typeid(var_signed_int)) << endl;

  MOUT << typeid(&f1).name() << endl;
  MOUT << typeid(f2).name() << endl;
  MOUT << typeid(FunctionType1<double, double>::type).name() << endl;
  MOUT << getTypeName(f1) << endl;





  Vector<double> vv({1, 2, 3});
  disp(vv);
  Vector<double> ww({0, 0, 0});
  disp(ww);
  disp(dimequiv(vv, ww));
  disp(common(vv, ww));
  disp(common(vv, vv));

  double x1 = 1;
  double x2 = x1 + 3e-16;
  disp(approx(x1, x2, 0.));
  disp(approx(x1, x2, 3.5e-16));


  TensorAbstract *t = new Scalar<int>(22);
  Scalar<int> *t2 = static_cast<Scalar<int> *>(t);

  disp(*t2);
  MOUT << "t=" << *t2 << endl;


  disp(typeid(*t).name());
  disp(typeid(*t2).name());
  // disp(is_instance<decltype(*t), Scalar>{});
  // disp(is_instance<decltype(*t2), Scalar>{});

  Scalar<int> s1 = 12;
  Scalar<int> s2 = 10;
  disp(s1 + s2);
  tdisp(s1 + s2);

  Vector<int> v1 = {1, 2};
  Vector<int> v2 = {10, 20};
  disp(v1 + v2);
  tdisp(v1 + v2);



  Matrix<double> A(2, 3);
  A = {{1, 2, 3}, {4, 5, 6}};
  tdisp(A);
  A.transpose();
  tdisp(A);

  {
    Dimensions dims1(2, 1, 7);
    disp(dims1);
    disp(dims1.reduce());
    Dimensions dims2(2, 3);
    disp(dims2);
    disp(dims2.reduce());
    disp(dims1 == dims2);
    disp(dims1.reduce() == dims2.reduce());
    disp(equiv(dims1, dims2));
    Dimensions dims3(2, 5);
    disp(dims3);
    disp(equiv(dims1, dims3));
    disp(equiv(dims2, dims3));

    VectorofPtrs addrs1((void *)&dims1);
    addrs1.add((void *)&dims2);
    disp(addrs1);

    VectorofPtrs addrs2((void *)&dims3);
    addrs2.add((void *)&x);
    disp(addrs2);
    disp(common(addrs1, addrs2));
    addrs2.add((void *)&dims1);
    disp(addrs2);
    disp(common(addrs1, addrs2));
  }
  {
    Dimensions dims3(2, 2, 2);
    disp(dims3);
    Tensor<double> T(dims3);
    disp(T.dims());
    disp(T.index(0, 0, 0));
    disp(T.index(0, 0, 1));
    disp(T.index(0, 1, 0));
    disp(T.index(0, 1, 1));
    disp(T.index(1, 0, 0));
    disp(T.index(1, 0, 1));
    disp(T.index(1, 1, 0));
    disp(T.index(1, 1, 1));


    for (int k = 0; k < T.size(); k++) {
      mdisp(k, T.indices(k));
      T[k] = k;
    }
    disp(T(0, 0, 0));
    disp(T(0, 0, 1));
    disp(T(0, 1, 0));
    disp(T(0, 1, 1));
    disp(T(1, 0, 0));
    disp(T(1, 0, 1));
    disp(T(1, 1, 0));
    disp(T(1, 1, 1));
    disp(42);
    tdisp(T);

    Dimensions dims4(13, 17, 11, 14);
    disp(dims4);
    Dimensions dims6({22, 45, 11, 18, 12, 11});
    disp(dims6);
  }
  {
    Dimensions dims(3, 2, 1, 6);
    disp(dims);
    double c = 0;
    Tensor<double> T(dims);
    for (int i = 0; i < T.dims()[0]; i++) {
      for (int j = 0; j < T.dims()[1]; j++) {
        for (int k = 0; k < T.dims()[2]; k++) {
          for (int m = 0; m < T.dims()[3]; m++) {
            T(i, j, k, m) = 100 + c++;
          }
        }
      }
    }
    disp(T);
  }
  {
    Dimensions dims(3, 2, 3, 6);
    disp(dims);
    double c = 0;
    Tensor<double> T(dims);
    for (int i = 0; i < T.dims()[0]; i++) {
      for (int j = 0; j < T.dims()[1]; j++) {
        for (int k = 0; k < T.dims()[2]; k++) {
          for (int m = 0; m < T.dims()[3]; m++) {
            T(i, j, k, m) = c++;
          }
        }
      }
    }
    disp(T);
  }
  {
    Dimensions dims(3, 2);
    disp(dims);
    double c = 0;
    Tensor<double> T(dims);
    for (int i = 0; i < T.dims()[0]; i++) {
      for (int j = 0; j < T.dims()[1]; j++) {
        T(i, j) = c++;
      }
    }
    disp(T);
  }

  {
    Vector<double> q = {21, 22};
    tdisp(q);
    double x10 = q(0);
    double x11 = q(1);
    mdisp(x10, x11);
    CR();
    x10 = q((size_type)0);
  }


  disp(sizeof(size_type));
  disp(sizeof(index_type));

  {
    AddType<double, float>::Type x;
    tdisp(x);
  }
  {
    AddType<double, int>::Type x;
    tdisp(x);
    double y = 3.1;
    int n = 10;
    AddType<double, int>::Type z = y + n;
    tdisp(y);
    tdisp(n);
    tdisp(z);
  }


  // mixed complex adding

  {
    CR();
    MOUT << bold.apply("complex<double> + complex<float>") << endl;
    MOUT << "AddType<double,float>::Type=" << AddType<double, float>::name() << endl;
    ComplexDouble z = ComplexDouble(1, 2);
    ComplexFloat x = ComplexFloat(4, -3);
    tdisp(z);
    tdisp(x);
    tdisp((z + x));
    AddType<ComplexDouble, ComplexFloat>::Type q = z + x;
    tdisp(q);
  }
  {
    CR();
    MOUT << bold.apply("complex<int> + complex<float>") << endl;
    MOUT << "AddType<int,float>::Type=" << AddType<int, float>::name() << endl;
    ComplexInt z = ComplexInt(1, 2);
    ComplexFloat x = ComplexFloat(4, -3);
    tdisp(z);
    tdisp(x);
    tdisp((z + x));
    AddType<ComplexInt, ComplexFloat>::Type q = z + x;
    tdisp(q);
  }
  {
    CR();
    MOUT << bold.apply("complex<float> + complex<int>") << endl;
    MOUT << "AddType<float,int>::Type=" << AddType<float, int>::name() << endl;
    ComplexFloat z = ComplexFloat(1, 2);
    ComplexInt x = ComplexInt(4, -3);
    tdisp(z);
    tdisp(x);
    tdisp((z + x));
    AddType<ComplexFloat, ComplexInt>::Type q = z + x;
    tdisp(q);
  }


  // mixed complex SUBTRACT
  {
    CR();
    MOUT << bold.apply("complex<double> - complex<float>") << endl;
    ComplexDouble z = ComplexDouble(1, 2);
    ComplexFloat x = ComplexFloat(4, -3);
    tdisp(z);
    tdisp(x);
    tdisp((z - x));
    SubType<ComplexDouble, ComplexFloat>::Type q = z - x;
    tdisp(q);
  }
  {
    CR();
    MOUT << bold.apply("complex<int> - complex<float>") << endl;
    ComplexInt z = ComplexInt(1, 2);
    ComplexFloat x = ComplexFloat(4, -3);
    tdisp(z);
    tdisp(x);
    tdisp((z - x));
    SubType<ComplexInt, ComplexFloat>::Type q = z - x;
    tdisp(q);
  }
  {
    CR();
    MOUT << bold.apply("complex<float> - complex<int>") << endl;
    ComplexFloat z = ComplexFloat(1, 2);
    ComplexInt x = ComplexInt(4, -3);
    tdisp(z);
    tdisp(x);
    tdisp((z - x));
    SubType<ComplexFloat, ComplexInt>::Type q = z - x;
    tdisp(q);
  }



  // mixed complex MULTIPLY
  {
    CR();
    MOUT << bold.apply("complex<double> * complex<float>") << endl;
    ComplexDouble z = ComplexDouble(1, 2);
    ComplexFloat x = ComplexFloat(4, -3);
    tdisp(z);
    tdisp(x);
    tdisp((z * x));
    MultType<ComplexDouble, ComplexFloat>::Type q = z * x;
    tdisp(q);
  }
  {
    CR();
    MOUT << bold.apply("complex<int> * complex<float>") << endl;
    ComplexInt z = ComplexInt(1, 2);
    ComplexFloat x = ComplexFloat(4, -3);
    tdisp(z);
    tdisp(x);
    tdisp((z * x));
    MultType<ComplexInt, ComplexFloat>::Type q = z * x;
    tdisp(q);
  }
  {
    CR();
    MOUT << bold.apply("complex<float> * complex<int>") << endl;
    ComplexFloat z = ComplexFloat(1, 2);
    ComplexInt x = ComplexInt(4, -3);
    tdisp(z);
    tdisp(x);
    tdisp((z * x));
    MultType<ComplexFloat, ComplexInt>::Type q = z * x;
    tdisp(q);
  }


  // mixed complex DIVIDE
  {
    CR();
    MOUT << bold.apply("complex<double> / complex<float>") << endl;
    ComplexDouble z = ComplexDouble(1, 2);
    ComplexFloat x = ComplexFloat(4, -3);
    tdisp(z);
    tdisp(x);
    tdisp((z / x));
    DivType<ComplexDouble, ComplexFloat>::Type q = z / x;
    tdisp(q);
  }
  {
    CR();
    MOUT << bold.apply("complex<int> / complex<float>") << endl;
    ComplexInt z = ComplexInt(1, 2);
    ComplexFloat x = ComplexFloat(4, -3);
    tdisp(z);
    tdisp(x);
    tdisp((z / x));
    DivType<ComplexInt, ComplexFloat>::Type q = z / x;
    tdisp(q);
  }
  {
    CR();
    MOUT << bold.apply("complex<float> / complex<int>") << endl;
    ComplexFloat z = ComplexFloat(1, 2);
    ComplexInt x = ComplexInt(4, -3);
    tdisp(z);
    tdisp(x);
    tdisp((z / x));
    DivType<ComplexFloat, ComplexInt>::Type q = z / x;
    tdisp(q);
  }



  // complex<D> + D : inherently suppoerd by C++

  {
    CR();
    ComplexDouble z = ComplexDouble(1, 2);
    double x = 6.5;
    tdisp(z);
    tdisp(x);
    MOUT << bold.apply("complex<double> + double") << endl;
    tdisp((z + x));
    MOUT << bold.apply("complex<double> + double") << endl;
    tdisp((x + z));
  }


  // complex<D1> + D2

  {
    CR();
    ComplexDouble z = ComplexDouble(1, 2);
    float x = 6.5;
    tdisp(z);
    tdisp(x);
    MOUT << bold.apply("complex<double> + float") << endl;
    tdisp((z + x));
    MOUT << bold.apply("float + complex<float>") << endl;
    tdisp((x + z));
    MOUT << bold.apply("complex<double> - float") << endl;
    tdisp((z - x));
    MOUT << bold.apply("float - complex<float>") << endl;
    tdisp((x - z));
    MOUT << bold.apply("complex<double> * float") << endl;
    tdisp((z * x));
    MOUT << bold.apply("float * complex<float>") << endl;
    tdisp((x * z));
    MOUT << bold.apply("complex<double> / float") << endl;
    tdisp((z / x));
    MOUT << bold.apply("float / complex<float>") << endl;
    tdisp((x / z));
  }


  {
    CR();
    MOUT << bold.apply("conj(D)") << endl;
    ComplexDouble z = ComplexDouble(1, 2);
    double x = 6.5;
    tdisp(z);
    tdisp(x);
    tdisp(mathq::conj(z));
    tdisp(mathq::conj(x));
    tdisp(mathq::real(x));
    tdisp(mathq::imag(x));
  }



  {
    CR();
    MOUT << bold.apply("Imaginary<double> + Imaginary<float>") << endl;
    ImDouble z = ImDouble(1.1);
    ImFloat x = ImFloat(10.01);
    tdisp(z);
    tdisp(x);
    tdisp((z + x));
    AddType<ImDouble, ImFloat>::Type q = z + x; // TODO: NOTICE THAT ADDTYPE WORKS FOR IMAGINARY WORKS! use for Tensor functions
    tdisp(q);
  }

  {
    CR();
    MOUT << bold.apply("Imaginary<double> * Imaginary<float>") << endl;
    ImDouble z = ImDouble(1.12);
    ImFloat x = ImFloat(100);
    tdisp(z);
    tdisp(x);
    tdisp((z * x));
    MultType<ImDouble, ImFloat>::Type q = z * x; // TODO: NOTICE THAT ADDTYPE WORKS FOR IMAGINARY WORKS! use for Tensor functions
    tdisp(q);
  }



  CR();
  disp(is_base_of<ComplexDouble, ComplexDouble>::value);
  disp(is_base_of<Scalar<double>, Scalar<double>>::value);

  CR();
  disp(is_arithmetic<double>::value);
  disp(is_arithmetic<ComplexDouble>::value);
  disp(is_arithmetic<Scalar<double>>::value);

  CR();
  disp(is_floating_point<double>::value);
  disp(is_floating_point<ComplexDouble>::value);
  disp(is_floating_point<Scalar<double>>::value);

  CR();
  disp(is_complex<double>{});
  disp(is_complex<ComplexDouble>{});
  // disp(is_complex<Scalar<double> >{});
  // disp(is_complex<Scalar<ComplexDouble> >{});




  // {
  //   CR();
  //   MOUT << bold.apply("Complexify") << endl;
  //   Complexify<double>::Type double_;
  //   tdisp(double_);
  //   Complexify<std::complex<double> >::Type complexdouble_;
  //   tdisp(complexdouble_);
  //   // Complexify<Scalar<double> >::Type scalardouble_;
  //   // tdisp(scalardouble_);
  //   // Complexify<Scalar<std::complex<double> > >::Type scalarcomplexdouble_;
  //   // tdisp(scalarcomplexdouble_);
  // }

  //   {
  //   CR();
  //   MOUT << bold.apply("Realify") << endl;
  //   Realify<double>::Type double_;
  //   tdisp(double_);
  //   Realify<std::complex<double> >::Type complexdouble_;
  //   tdisp(complexdouble_);
  //   // Realify<Scalar<double> >::Type scalardouble_;
  //   // tdisp(scalardouble_);
  //   // Realify<Scalar<std::complex<double> > >::Type scalarcomplexdouble_;
  //   // tdisp(scalarcomplexdouble_);
  // }


  {
    CR();
    MOUT << bold.apply("conj(Scalar<D>)") << endl;
    Scalar<ComplexDouble> z = ComplexDouble(1, 2);
    Scalar<double> x = 6.5;
    tdisp(z);
    tdisp(x);
    tdisp(conj(z));
    tdisp(conj(x));
    tdisp(real(z));
    tdisp(imag(z));
    tdisp(real(x));
    tdisp(imag(x));
    tdisp(z.conj());
    // tdisp(x.conj());
  }

  // {
  //   CR();
  //   MOUT << bold.apply("TypeTraits<T>::ParameterType") << endl;
  //   Loki::TypeTraits<int>::ParameterType n = 1;
  //   tdisp(n);
  //   disp(Loki::TypeTraits<decltype(n)>::isReference);

  //   Loki::TypeTraits<long>::ParameterType longo = *(new long(123456789));
  //   tdisp(longo);
  //   disp(Loki::TypeTraits<decltype(longo)>::isReference);

  //   Loki::TypeTraits<long long>::ParameterType llongo = *(new long long(12345678));
  //   tdisp(llongo);
  //   disp(Loki::TypeTraits<decltype(llongo)>::isReference);

  //   Loki::TypeTraits<double>::ParameterType x = 2.13;
  //   tdisp(x);
  //   disp(Loki::TypeTraits<decltype(x)>::isReference);

  //   Loki::TypeTraits<long double>::ParameterType big = 2.13;
  //   tdisp(big);
  //   disp(Loki::TypeTraits<decltype(big)>::isReference);

  //   Loki::TypeTraits<std::complex<double>>::ParameterType z = *(new std::complex<double>(1.2,3.4));
  //   tdisp(z);
  //   disp(Loki::TypeTraits<decltype(z)>::isReference); // doesnt work
  //   disp(Loki::TypeTraits<decltype(z)>::isReference); // works
  //   disp(Loki::TypeTraits<Loki::TypeTraits<std::complex<double> >>::isReference);
  //   disp(Loki::TypeTraits<Loki::TypeTraits<std::complex<double>>::ParameterType>::isReference);


  //   Loki::TypeTraits<Imaginary<double>>::ParameterType w = *(new Imaginary<double>(1.2));
  //   tdisp(w);
  //   disp(Loki::TypeTraits<decltype(z)>::isReference); // works


  // }



  {
    CR();
    MOUT << bold.apply("initializer_list") << endl;
    Vector<int> v1 = {1, 2, 3, 4};
    tdisp(v1);
    int n = 5;
    Vector<int> v2 = {1, 2, 3, 4, n};
    tdisp(v2);

    Scalar<int> s = 5;

    // DOESNT WORK
    //    Vector<int> v3 = initializer_list<int>{1,2,3,4,s};//
    //^^^^^^^^^^^^^^^

    Vector<Scalar<int>> v3 = {1, 2, 3, 4, s}; //  TODO: use this concept with slices lists
    //   Use lists instead of variadic
    // make a subclass of slice that uses a list of vectors, or just has as part of slice


    tdisp(v3);
  }



  {
    CR();
    MOUT << bold.apply("Vector<double>+ Vector<double>") << std::endl;
    Vector<double> v1 = {11, 22};
    Vector<double> v2 = {100, 200};
    tdisp(v1);
    tdisp(v2);
    tdisp(v1 + v2);
  }
  {
    CR();
    MOUT << bold.apply("Vector<int>+ Vector<double>") << std::endl;
    Vector<int> v1 = {11, 22};
    Vector<double> v2 = {0.1, 0.2};
    tdisp(v1);
    tdisp(v2);
    tdisp(v1 + v2);
  }
  {
    CR();
    MOUT << bold.apply("Vector<double> + double ") << std::endl;
    Vector<double> v = {11, 22};
    double x = 0.5;
    tdisp(v);
    tdisp(x);
    tdisp(v + x);
  }
  {
    CR();
    MOUT << bold.apply("Vector<int> + double ") << std::endl;
    Vector<int> vz = {11, 22};
    double x = .5;
    tdisp(vz);
    tdisp(x);
    tdisp(vz + x);
  }
  {
    CR();
    MOUT << bold.apply("Vector<double> + int ") << std::endl;
    Vector<double> v = {11.1, 22.2};
    int n = 900;
    tdisp(v);
    tdisp(n);
    tdisp(v + n);
  }

  {
    CR();
    MOUT << bold.apply("Vector<complex<double> > + Vector<complex<double> >") << std::endl;
    Vector<ComplexDouble> vz1 = {ComplexDouble(0.1, 1.1), ComplexDouble(0.2, 2.2)};
    Vector<ComplexDouble> vz2 = {ComplexDouble(10.5, 20.5), ComplexDouble(30.5, 40.5)};
    tdisp(vz1);
    tdisp(vz2);
    tdisp(vz1 + vz2);
  }

  {
    CR();
    MOUT << bold.apply("Vector<complex<double> > + Vector<complex<int> >") << std::endl;
    Vector<ComplexDouble> vz1 = {ComplexDouble(0.1, 1.1), ComplexDouble(0.2, 2.2)};
    Vector<ComplexInt> vz2 = {ComplexInt(10, 20), ComplexInt(30, 40)};
    tdisp(vz1);
    tdisp(vz2);
    tdisp(vz1 + vz2);
  }

  {
    CR();
    MOUT << bold.apply("Vector<complex<double> > + Vector<double>") << std::endl;
    Vector<ComplexDouble> vz = {ComplexDouble(0.1, 0.2), ComplexDouble(0.3, 2.4)};
    Vector<double> v = {0.01, 0.02};
    tdisp(vz);
    tdisp(v);
    tdisp(vz + v);
  }

  {
    CR();
    MOUT << bold.apply("Vector<complex<double> > + Vector<int>") << std::endl;
    Vector<ComplexDouble> vz1 = {ComplexDouble(0.1, 0.2), ComplexDouble(0.3, 2.4)};
    Vector<int> vz2 = {1, 2};
    tdisp(vz1);
    tdisp(vz2);
    tdisp(vz1 + vz2);
  }

  {
    CR();
    MOUT << bold.apply("Vector<complex<int> > + Vector<double>") << std::endl;
    Vector<ComplexInt> vzn = {ComplexInt(10, 20), ComplexInt(30, 40)};
    Vector<double> vx = {0.01, 0.02};
    tdisp(vzn);
    tdisp(vx);
    tdisp(vzn + vx);
  }



  {
    CR();
    MOUT << bold.apply("Vector<complex<double> > + double ") << std::endl;
    Vector<ComplexDouble> vz = {ComplexDouble(0.1, 1.1), ComplexDouble(0.2, 2.2)};
    double x = 0.5;
    tdisp(vz);
    tdisp(x);
    tdisp(vz + x);
  }


  {
    CR();
    MOUT << bold.apply("Vector<complex<double> > + double ") << std::endl;
    Vector<ComplexDouble> vz = {ComplexDouble(0.1, 1.1), ComplexDouble(0.2, 2.2)};
    double x = 0.5;
    tdisp(vz);
    tdisp(x);
    tdisp(vz + x);
  }
  {
    CR();
    MOUT << bold.apply("Vector<complex<int> > + double ") << std::endl;
    Vector<ComplexInt> vz = {ComplexInt(1, 2), ComplexInt(3, 4)};
    double x = .5;
    tdisp(vz);
    tdisp(x);
    tdisp(vz + x);
  }
  {
    CR();
    MOUT << bold.apply("Vector<complex<double> > + int ") << std::endl;
    Vector<ComplexDouble> vz = {ComplexDouble(0.1, 1.1), ComplexDouble(0.2, 2.2)};
    int n = 900;
    tdisp(vz);
    tdisp(n);
    tdisp(vz + n);
  }




  {
    CR();
    MOUT << bold.apply("Vector<Vector<double> > testing") << std::endl;

    // NOTE: no equals sign
    std::vector<std::vector<double>> ss{{1, 2}, {3, 4}};
    tdisp(ss);
    // Vector<std::vector<double>> vs {{1,2},{3,4}};
    // tdisp(vs);
    std::vector<Vector<double>> sv{{1, 2}, {3, 4}};
    tdisp(sv);
    Vector<Vector<double>> vv{{1, 2}, {3, 4}};
    tdisp(vv);
    Vector<Vector<double>> vv2{{1, -1}, {3, 4}};
    tdisp(vv2);
    Vector<Vector<double>> vv3{{1, -1}, {2, 4}};
    tdisp(vv3);
    Vector<Vector<double>> vv4{{1, -1}, {2, -2}};
    tdisp(vv4);
  }


  {
    CR();
    MOUT << bold.apply("Vector<Vector<double> > + Vector<Vector<double> >") << std::endl;
    Vector<Vector<double>> v1{{1, 2}, {3, 4}};
    Vector<Vector<double>> v2{{0.1, 0.2}, {0.3, 0.4}};
    tdisp(v1);
    tdisp(v2);
    // tdisp(v1+v2);
    Vector<Vector<double>> v3{{0, 0}, {0, 0}};
    tdisp(v3);
    //    v3 = v1;
    tdisp(v3);
    // tdisp(-v3);
    //     v3 = {{0,0},{0,0}};
    tdisp(v3);
    CR();
    //    typename AddType<Vector<double>,Vector<double>>::Type v4 {{6,7},{8,0}};
    //    v1+v2;
    //    disp(v1.bottom());
    CR();
    disp(typeid(AddType<Vector<double>, Vector<double>>::Type).name());
    // fails:
    //    v3 = v1+v2;
    disp(v3);
  }
  //------------------------------------------------------


  {
    MultType<int, ComplexDouble>::Type x;
    tdisp(x);
  }



  {
    Scalar<ComplexDouble> s1 = ComplexDouble(2, 3);
    Scalar<ComplexDouble> s2 = ComplexDouble(10, 3);
    Scalar<ComplexDouble> result;
    //    result = 20*log10(abs(s1/s2)*100) + 3 + pow(-s2,2);
    tdisp(s1 * 2.);
    tdisp(s1 * 2);
    // tdisp(2.*s1);
    //     tdisp(2*s1);
  }

  CR();
  MOUT << "done: " << bold.apply(myname) << std::endl;
  MOUT << StyledString::get(HORLINE);
  CR();
  return 0;
}
