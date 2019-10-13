#define MATRICKS_DEBUG 1
#include "matricks.h"

#include <vector>

#include "TypeTraits.h"
#include <string>



template <typename D, int M = 1+matricks::NumberType<D>::depth()> class Test : public matricks::TensorRW<D,Test<D>> {
public:
  typedef D Type;
  Test() {
  }
  constexpr inline int depth() {
    return M;
  }
 
};



template <typename D> class Test2 : public matricks::TensorRW<D,Test<D>> {
public:
  typedef D Type;
  D d_;
  Test2() {
  }
  Test2(D d): d_(d) {
  }
  constexpr inline int depth() {
    return matricks::NumberType<typeof(*this)>::depth();
  }
 
};


int main(int argc, char *argv[])
{


  typedef typename matricks::Vector<double> VectorDouble;
  
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
  

  
  

  {
    cr();
    mout << bold.apply("Complexify") << endl; 
    Complexify<double>::Type double_;
    tdisp(double_);
    Complexify<std::complex<double> >::Type complexdouble_;
    tdisp(complexdouble_);
    Complexify<Scalar<double> >::Type scalardouble_;
    tdisp(scalardouble_);
    Complexify<Scalar<std::complex<double> > >::Type scalarcomplexdouble_;
    tdisp(scalarcomplexdouble_);
  }

    {
    cr();
    mout << bold.apply("Realify") << endl; 
    Realify<double>::Type double_;
    tdisp(double_);
    Realify<std::complex<double> >::Type complexdouble_;
    tdisp(complexdouble_);
    Realify<Scalar<double> >::Type scalardouble_;
    tdisp(scalardouble_);
    Realify<Scalar<std::complex<double> > >::Type scalarcomplexdouble_;
    tdisp(scalarcomplexdouble_);
  }


  {
    cr();
    mout << bold.apply("conj(Scalar<D>)") << endl; 
    Scalar<ComplexDouble> z = ComplexDouble(1,2);
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
    //tdisp(x.conj());
  }


  {
    cr();
    mout << bold.apply("Vector<double> testing") << std::endl;
    tdisp(NumberType<double>::depth());
    Vector<double> vd {1,2,3,4};
    tdisp(vd);

    tdisp(FundamentalType<typeof(vd)>::depth());
    FundamentalType<typeof(vd)>::Type d = 0.1;
    tdisp(d);

    tdisp(NumberType<typeof(vd)>::depth());
    NumberType<typeof(vd)>::Type d2 = 0.2;
    tdisp(d2);
  }
  {
    cr();
    mout << bold.apply("Vector<ComplexDouble> testing") << std::endl;
    tdisp(NumberType<ComplexDouble>::depth());
    Vector<ComplexDouble> vd {ComplexDouble(0.1,1), ComplexDouble(0.2,2), ComplexDouble(3,0.3)};
    tdisp(vd);
    tdisp(FundamentalType<typeof(vd)>::depth());
    FundamentalType<typeof(vd)>::Type d = 3.14;
    tdisp(d);
    tdisp(NumberType<typeof(vd)>::depth());
    NumberType<typeof(vd)>::Type d2 = ComplexDouble(0.1,0.2);
    tdisp(d2);

  }
  {
    cr();
    mout << bold.apply("Vector<Vector<double> > testing") << std::endl;
    Vector<Vector<double>> vd {{1.1,1.2},{2.1,2.2},{3.1,3.2}};
    tdisp(vd);
    tdisp(FundamentalType<typeof(vd)>::depth());
    FundamentalType<typeof(vd)>::Type d = 0.1;
    tdisp(d);
    tdisp(NumberType<typeof(vd)>::depth());
    NumberType<typeof(vd)>::Type d2 = 0.2;
    tdisp(d2);
  }
  {
    using namespace std;
    // this work sbut disp() doesn't work because it doesn't recurse formats
    cr();
    mout << bold.apply("complex<Vector<double>> testing") << std::endl;
    tdisp(NumberType<complex<Vector<double>>>::depth());
    complex<Vector<double>> vd = complex<Vector<double>>({1.1,1.2,1.3},{2.1,2.2,2.3});
    mout << vd << endl;
    tdisp(FundamentalType<typeof(vd)>::depth());
    FundamentalType<typeof(vd)>::Type d = 43;
    tdisp(d);
    tdisp(NumberType<typeof(vd)>::depth());
    NumberType<typeof(vd)>::Type v2 = vd;
    mout << v2 << endl;

    //  TODO: need to define operator+=
    //    NumberType<typeof(vd)>::Type v3 = vd+v2;
    //    mout << v3 << endl;

  }

    {
      cr();
      mout << bold.apply("Test class testing") << std::endl;
      Test<double> t0;
      tdisp(NumberType<typeof(t0)>::depth());
      tdisp(t0.depth());
      Test<Test<double>> t1;
      tdisp(NumberType<typeof(t1)>::depth());
      tdisp(t1.depth());
      Test<Test<Test<double>>> t2;
      tdisp(NumberType<typeof(t2)>::depth());
      tdisp(t2.depth());
    }

    {
      cr();
      mout << bold.apply("Test2 class testing") << std::endl;
      Test2<double> t0(0);
      tdisp(NumberType<typeof(t0)>::depth());
      tdisp(t0.depth());
      Test2<Test2<double>> t1 {1};
      tdisp(NumberType<typeof(t1)>::depth());
      tdisp(t1.depth());
      Test2<Test2<Test2<double>>> t2 {{2}};
      tdisp(NumberType<typeof(t2)>::depth());
      tdisp(t2.depth());
    }


    {
      cr();
      mout << bold.apply("NewScalar class testing") << std::endl;
      NewScalar<double> t1(1.1);
      tdisp(t1);
      tdisp(NumberType<typeof(t1)>::depth());
      tdisp(t1.depth());
      tdisp(t1.size());
      
      mout << bold.apply("NewScalar class testing") << std::endl;
      NewScalar<NewScalar<double>> t2 {2.2};
      tdisp(t2);
      tdisp(NumberType<typeof(t2)>::depth());
      tdisp(t2.depth());
      tdisp(t2.size());

    }

  //------------------------------------------------------
  
  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  return 0;
}
