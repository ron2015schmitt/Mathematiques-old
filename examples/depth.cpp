#define MATRICKS_DEBUG 1
#include "matricks.h"

#include <vector>

#include "TypeTraits.h"
#include <string>


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
    Vector<double> vd {1,2,3,4};
    tdisp(vd);
    tdisp(DepthType<double>::value());
    tdisp(DepthType<Vector<double>>::value());
    FundamentalType<typeof(vd)>::Type d = 0.1;
    tdisp(d);
    NumberType<typeof(vd)>::Type d2 = 0.2;
    tdisp(d2);
  }
  {
    cr();
    mout << bold.apply("Vector<ComplexDouble> testing") << std::endl;
    Vector<ComplexDouble> vd {ComplexDouble(0.1,1), ComplexDouble(0.2,2), ComplexDouble(3,0.3)};
    tdisp(vd);
    tdisp(DepthType<ComplexDouble>::value());
    tdisp(DepthType<Vector<ComplexDouble>>::value());
    FundamentalType<typeof(vd)>::Type d = 3.14;
    tdisp(d);
    NumberType<typeof(vd)>::Type d2 = ComplexDouble(0.1,0.2);
    tdisp(d2);

  }
  {
    cr();
    mout << bold.apply("Vector<Vector<double> > testing") << std::endl;
    Vector<Vector<double>> vd {{1.1,1.2},{2.1,2.2},{3.1,3.2}};
    tdisp(vd);
    FundamentalType<typeof(vd)>::Type d = 0.1;
    tdisp(d);
    NumberType<typeof(vd)>::Type d2 = 0.2;
    tdisp(d2);
  }
 

  //------------------------------------------------------
  
  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  return 0;
}
