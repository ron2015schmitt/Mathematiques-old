
//#define MATHQ_DEBUG

#include "mathq.h" 

#include <fstream>


int main(int argc, char *argv[])
{

  const double pi = M_PI;
  std::string myname = argv[0];

  using namespace std;
  using namespace mathq;
  using namespace display;
  using namespace mathq::unit_imaginary;

  Style bold = createStyle(BOLD);
  Style blue = createStyle(BOLD+BLUE2);
  
  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  FormatData<bool>::string_for_true = "true";
  FormatData<bool>::string_for_false = "false";
  

  cr();
  cr();
  mout << StyledString::get(HORLINE);
  mout << "running: " <<bold.apply(myname) << std::endl;

  
  mout<< "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;
  
  print_mathq_info();


  cr();
  mout << StyledString::get(HORLINE);cr();
  //------------------------------------------------------


  mout << bold.apply("Addition tests") << endl;
  cr();

  {
    int s = -10;
    unsigned int u = 5;
    
    tdisp(s);
    tdisp(u);
    tdisp(s+u);
    cr();
  }
  mout << blue.apply("Vector-Vector tests") << endl;
  {
    using namespace mathq::unit_imaginary;
    cr();
    Vector<short> Vshort {-11,-12,13};
    Vector<int> Vint1 {11,12,-13};
    Vector<int> Vint2 {11,12,-100};
    Vector<long> vLong {1000,2000,-3000};
    Vector<unsigned> Vunsigned {70,80,90};
    Vector<double> Vdouble1 {10,20,30};
    Vector<double> Vdouble2 {1,2,3};
    Vector<float> Vfloat {0.1,.2,.3};
    Vector<long double> Vextended {0.01,.02,.03};
    Vector<Imaginary<double>> vImagDouble {1*i,2*i,3*i};
    Vector<Imaginary<long double>> vImagExtended {10*iL,20*iL,30*iL};
    Vector<complex<double>> VcomplexDouble {complex<double>(0.1,0.001),complex<double>(0.2,0.002),complex<double>(0.3,0.003)};
    Vector<complex<int>> VcomplexInt {complex<int>(1,-2),complex<int>(1,0),complex<int>(0,1)};
    mout << blue.apply("Given:") << endl;
    mout<<"  ";tdisp(Vshort);
    mout<<"  ";tdisp(Vint1);
    mout<<"  ";tdisp(Vint2);
    mout<<"  ";tdisp(vLong);
    mout<<"  ";tdisp(Vunsigned);
    mout<<"  ";tdisp(Vdouble1);
    mout<<"  ";tdisp(Vdouble2);
    mout<<"  ";tdisp(Vfloat);
    mout<<"  ";tdisp(Vextended);
    mout<<"  ";tdisp(vImagDouble);
    mout<<"  ";tdisp(vImagExtended);
    mout<<"  ";tdisp(VcomplexDouble);
    mout<<"  ";tdisp(VcomplexInt);
    cr();
    mout << blue.apply("Vector+Vector Addition:") << endl;
    mout<<"  ";tdisp(Vshort + Vshort);
    mout<<"  ";tdisp(Vint1 + Vshort);
    mout<<"  ";tdisp(Vint1 + vLong);
    mout<<"  ";tdisp(vLong + Vshort);
    mout<<"  ";tdisp(Vint1 + Vunsigned);
    mout<<"  ";tdisp(Vint2 + Vunsigned);
    mout<<"  ";tdisp(Vdouble1 + Vdouble2);
    mout<<"  ";tdisp(Vint1 + Vdouble2);
    mout<<"  ";tdisp(Vdouble1 + Vunsigned);
    mout<<"  ";tdisp(vLong + Vdouble2);
    mout<<"  ";tdisp(Vfloat + Vint1);
    mout<<"  ";tdisp(Vextended + Vfloat);
    mout<<"  ";tdisp(Vint1 + Vextended);
    mout<<"  ";tdisp(vImagDouble + vImagExtended);
    mout<<"  ";tdisp(Vint1 + vImagDouble);
    mout<<"  ";tdisp(vImagDouble + Vdouble2);
    mout<<"  ";tdisp(Vfloat + vImagDouble);
    mout<<"  ";tdisp(vLong + vImagDouble);
    mout<<"  ";tdisp(Vdouble1 + VcomplexDouble);
    mout<<"  ";tdisp(Vint1 + VcomplexInt);
    mout<<"  ";tdisp(VcomplexDouble + vImagExtended);
    mout<<"  ";tdisp(VcomplexInt + vImagDouble);

    cr();

    short sh = 2;
    int n = 10;
    long longo = 1000;
    unsigned u = 5;
    double dub = 0.5;
    float f = 0.001;
    long double e = 3.14;
    Imaginary<double> imag_d = 5*i;
    Imaginary<long double> imag_e = 30*iL;
    complex<double> c_dub = complex<double>(-10.1,-10.2);
    complex<int> c_int = complex<int>(1,-2);

    mout << blue.apply("Given:") << endl;
    mout<<"  ";tdisp(sh);
    mout<<"  ";tdisp(n);
    mout<<"  ";tdisp(longo);
    mout<<"  ";tdisp(u);
    mout<<"  ";tdisp(dub);
    mout<<"  ";tdisp(f);
    mout<<"  ";tdisp(e);
    mout<<"  ";tdisp(imag_d);
    mout<<"  ";tdisp(imag_e);
    mout<<"  ";tdisp(c_dub);
    mout<<"  ";tdisp(c_int);

    cr();
    mout << blue.apply("Vector+scalar Addition:") << endl;
    mout<<"  ";tdisp(Vshort + sh);
    mout<<"  ";tdisp(Vint1 + sh);
    mout<<"  ";tdisp(n + vLong);
    mout<<"  ";tdisp(vLong + longo);
    mout<<"  ";tdisp(Vint1 + u);
    mout<<"  ";tdisp(u + Vint2);
    mout<<"  ";tdisp(dub + Vdouble2);
    mout<<"  ";tdisp(f + Vint1);
    mout<<"  ";tdisp(e + Vdouble2);
    mout<<"  ";tdisp(Vfloat + n);
    mout<<"  ";tdisp(Vextended + f);
    mout<<"  ";tdisp(vImagDouble + imag_e);
    mout<<"  ";tdisp(Vint1 + imag_d);
    mout<<"  ";tdisp(vImagDouble + dub);
    mout<<"  ";tdisp(f + vImagDouble);
    mout<<"  ";tdisp(longo + vImagDouble);
    mout<<"  ";tdisp(VcomplexDouble + dub);
    mout<<"  ";tdisp(sh + VcomplexInt);
    mout<<"  ";tdisp(VcomplexDouble + imag_e);
    mout<<"  ";tdisp(VcomplexInt + imag_d);
    mout<<"  ";tdisp(VcomplexInt + c_int);
    mout<<"  ";tdisp(c_dub + VcomplexInt);
    
  }



  cr();
  cr();
  mout << bold.apply("Two-Level Vector tests") << endl;



  cr();
  cr();

  {
    cr();
    Matrix<Vector<double>> m1 {{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
    Vector<double> v0 {100,200,300};
    mout << blue.apply("Given:") << endl;
    mout<<"  ";tdisp(m1);
    mout<<"  ";tdisp(v0);
    cr();

    mout << "element-wise addition is chosen, since the elements are Vectors" << endl;
    mout<<"  ";tdisp(m1+v0);
    mout<<"  ";tdisp(v0+m1);

    cr();
    mout << "Element-access:" << endl;
    mout<<"  ";tdisp(m1[0]);
    //mout<<"  ";tdisp((m1+v0)[0]);
    //mout<<"  ";tdisp((v0+m1)[0]);
  }
  

  {
    cr();
    Vector<Matrix<double>> v1 { {{1,2},{3,4}}, {{5,6},{7,8}}, {{9,10},{11,12}} };
    Vector<double> v0 {100,200,300};

    mout << blue.apply("Given:") << endl;
    mout<<"  ";tdisp(v1);
    mout<<"  ";tdisp(v0);

    cr();
    mout << "Top-level addition is chosen, since the top-level is a vector" << endl;
    mout<<"  ";tdisp(v1+v0);
    mout<<"  ";tdisp(v0+v1);

    cr();
    mout << "Element-access:" << endl;
    mout<<"  ";tdisp(v1[1]);
    //mout<<"  ";tdisp((v1+v0)[1]);
    //mout<<"  ";tdisp((v0+v1)[1]);
  }


  
  {
    cr();
    cr();
    
    Vector<Vector<double>> v1 {{1,2,3},{4,5,6}};
    Vector<double> v0 {10,20,30};
    string s;
    mout << blue.apply("Given:") << endl;
    mout<<"  ";tdisp(v1);
    mout<<"  ";tdisp(v0);
    cr();
    mout << "By analysing the dimensions element-wise addition is chosen" << endl;
    mout<<"  ";tdisp(v1+v0);
    mout<<"  ";tdisp(v0+v1);

    cr();
    mout << "Element-access:" << endl;
    mout<<"  ";tdisp(v1[1]);
    //mout<<"  ";tdisp((v1+v0)[1]);
    //mout<<"  ";tdisp((v0+v1)[1]);

    cr();
    cr();
    Vector<double> v00 {100,200};
    mout << blue.apply("Given:") << endl;

    mout<<"  ";tdisp(v1);
    mout<<"  ";tdisp(v00);
    cr();
    mout << "By analysing the dimensions top-level addition is chosen" << endl;
    mout<<"  ";tdisp(v1+v00);
    mout<<"  ";tdisp(v00+v1);

    cr();
    mout << "Element-access:" << endl;
    mout<<"  ";tdisp(v1[1]);
    //mout<<"  ";tdisp((v00+v1)[1]);
    //mout<<"  ";tdisp((v1+v00)[1]);
  }


  cr();
    cr();
  mout << bold.apply("When dimensions and rank are the same, the result depends on order, ie non-commutative") << endl;
  {
    cr();
    Vector<Vector<double>> v1 {{1,2},{4,5}};
    mout<<"  ";tdisp(v1);
    Vector<double> v0 {10,20};
    mout<<"  ";tdisp(v0);
    cr();
    mout << "Adding from the right yields element-wise: each element of v1 is added with v0" << endl;
    mout<<"  ";tdisp(v1+v0);
    cr();
    mout << "Adding from the left yields Top-level: add v0[0] to vector v1[0], add v0[1] to vector v1[1]" << endl;
    mout<<"  ";tdisp(v0+v1);

    cr();
    mout << "Element-access:" << endl;
    mout<<"  ";tdisp(v1[1]);
    //mout<<"  ";tdisp((v1+v0)[1]);
    //mout<<"  ";tdisp((v0+v1)[1]);
    cr();
  }

  
 
  
  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  
  return 0;
}
