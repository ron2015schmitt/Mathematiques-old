#define MATRICKS_DEBUG 0

#include "matricks.h" 
#include "test.h"






int main()
{

  using namespace matricks;
  using namespace display;
  

  print_matricks_info();
  mout << createStyle(BOLD+MAGENTA1).apply(__FILE__) << " - scalar tests" <<std::endl;
  cr();
  cr();

  bool allpass = true;
  int testnum = 0;
  int failnum = 0;
  double tol = 5e-16;
  const double pi = M_PI;

  
  // TODO: add a test for every function and functionality
  //       check math with matlab or mathematica


  {
    // dynamic cast
    printStart(++testnum);
    Scalar<int> s1 = 1;
    testtext( "dynamic casting" );
    TensorRW<int,Scalar<int> > &s2 = s1;
    Scalar<int> *sp1 = dynamic_cast<Scalar<int>*>(&s2);
    void* result = (void*)&s1;
    void* expected = (void*)sp1;
    bool pass = (result==expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  

   {
    // 
    printStart(++testnum);
    Scalar<int> s1 = 1;
    testtext( "is_instance test #1" );
    bool result = is_instance<typeof(s1), Scalar>{};
    bool expected = true;
    bool pass = (result==expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


   {
    //  dimensions and size
    printStart(++testnum);

    Scalar<int> s1 = 1;
    bool result;
    testcode( result = (s1.size()==1) && (s1.dims().size()==0) && (s1.ndims()==0) );
    bool expected = true;
    bool pass = result;
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }



   {
    //  element access ()
    printStart(++testnum);
    Scalar<int> s = 14;
    int expected = 14;
    int result;
    testcode( result = s() );
    bool pass = (result==expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

   {
    //  element access [0]
    printStart(++testnum);
    Scalar<int> s = 24;
    int expected = 24;
    int result;
    testcode( result = s[0] );
    bool pass = (result==expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
   
   
   
  {
    // scalar + scalar
    printStart(++testnum);
    Scalar<int> s1 = 10;
    Scalar<int> s2 = -1;
    Scalar<int> expected = 9;
    Scalar<int> result;
    testcode( result = s1 + s2 );
    bool pass = equal(result,expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // scalar - scalar
    printStart(++testnum);
    Scalar<int> s1 = 10;
    Scalar<int> s2 = -1;
    Scalar<int> expected = 11;
    Scalar<int> result;
    testcode( result = s1 - s2 );
    bool pass = equal(result,expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // scalar * scalar
    printStart(++testnum);
    Scalar<int> s1 = 10;
    Scalar<int> s2 = 3;
    Scalar<int> expected = 30;
    Scalar<int> result;
    testcode( result = s1 * s2 );
    bool pass = equal(result,expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // scalar / scalar
    printStart(++testnum);
    Scalar<int> s1 = 27;
    Scalar<int> s2 = 9;
    Scalar<int> expected = 3;
    Scalar<int> result;
    testcode( result = s1 / s2 );
    bool pass = equal(result,expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }



  {
    // +(s)
    printStart(++testnum);
    Scalar<double> s = pi;
    Scalar<double> expected = pi;
    Scalar<double> result;
    testcode( result = +s );
    bool pass = equal(result,expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // -(s)
    printStart(++testnum);
    Scalar<double> s = pi;
    Scalar<double> expected = -pi;
    Scalar<double> result;
    testcode( result = -s );
    bool pass = equal(result,expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // sin(s)
    printStart(++testnum);
    Scalar<double> s = pi/6;
    Scalar<double> expected = 0.5;
    Scalar<double> result;
    testcode( result = sin(s) );
    bool pass = approx(result,expected,tol);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // cos(s)
    printStart(++testnum);
    Scalar<double> s = pi/6;
    Scalar<double> expected = 0.866025403784439;
    Scalar<double> result;
    testcode( result = cos(s) );
    bool pass = approx(result,expected,tol);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // tan(s)
    printStart(++testnum);
    Scalar<double> s = pi/6;
    Scalar<double> expected = 0.577350269189626;
    Scalar<double> result;
    testcode( result = tan(s) );
    bool pass = approx(result,expected,tol);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // sinh(s)
    printStart(++testnum);
    Scalar<double> s = pi/6;
    Scalar<double> expected = 0.547853473888040;
    Scalar<double> result;
    testcode( result = sinh(s) );
    bool pass = approx(result,expected,tol);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // cosh(s)
    printStart(++testnum);
    Scalar<double> s = pi/6;
    Scalar<double> expected = 1.140238321076429;
    Scalar<double> result;
    testcode( result = cosh(s) );
    bool pass = approx(result,expected,tol);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // tanh(s)
    printStart(++testnum);
    Scalar<double> s = pi/6;
    Scalar<double> expected = 0.480472778156452;
    Scalar<double> result;
    testcode( result = tanh(s) );
    bool pass = approx(result,expected,tol);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // exp(s)
    printStart(++testnum);
    Scalar<double> s = pi/6;
    Scalar<double> expected = 1.688091794964469;
    Scalar<double> result;
    testcode( result = exp(s) );
    bool pass = approx(result,expected,tol);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // log(s)
    printStart(++testnum);
    Scalar<double> s = pi/6;
    Scalar<double> expected = -0.647029583378655;
    Scalar<double> result;
    testcode( result = log(s) );
    bool pass = approx(result,expected,tol);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // log2(s)
    printStart(++testnum);
    Scalar<double> s = pi/6;
    Scalar<double> expected = -0.933466371248838;
    Scalar<double> result;
    testcode( result = log2(s) );
    bool pass = approx(result,expected,tol);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // log10(s)
    printStart(++testnum);
    Scalar<double> s = pi/6;
    Scalar<double> expected = -0.281001377689510;
    Scalar<double> result;
    testcode( result = log10(s) );
    bool pass = approx(result,expected,tol);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // round(s)
    printStart(++testnum);
    Scalar<double> s = pi/6;
    Scalar<double> expected = 1;
    Scalar<double> result;
    testcode( result = round(s) );
    bool pass = approx(result,expected,tol);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // floor(s)
    printStart(++testnum);
    Scalar<double> s = pi/6;
    Scalar<double> expected = 0;
    Scalar<double> result;
    testcode( result = floor(s) );
    bool pass = approx(result,expected,tol);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // ceil(s)
    printStart(++testnum);
    Scalar<double> s = pi/8;
    Scalar<double> expected = 1;
    Scalar<double> result;
    testcode( result = ceil(s) );
    bool pass = approx(result,expected,tol);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // roundzero(s,0.01)
    printStart(++testnum);
    Scalar<double> s = 0.0099999999;
    Scalar<double> expected = 0;
    Scalar<double> result;
    testcode( result = roundzero(s,0.01) );
    bool pass = alltrue(result==expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  
  
  {
    // Test of a large scalar math expression

    printStart(++testnum);
    Scalar<double> s1 = 40;
    Scalar<double> s2 = -4;
    Scalar<double> expected = 25;
    Scalar<double>  result;
    testcode( result = 2*log10(abs(s1/s2)*100) + 3 + pow(-s2,2.));
    bool pass = approx(result,expected,tol);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


    {
    // transpose(z)
    using namespace std;
    printStart(++testnum);
    Scalar<complex<double> > z = complex<double>(1,2);
    Scalar<complex<double> > expected = complex<double>(1,2);
    Scalar<complex<double> > result;
    testcode( result = transpose(z) );
    bool pass = alltrue(result==expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

    {
    // transpose(x)
    using namespace std;
    printStart(++testnum);
    Scalar<double> x = 25.1;
    Scalar<double> expected = 25.1;
    Scalar<double> result;
    testcode( result = transpose(x) );
    bool pass = alltrue(result==expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
    }

  

  //-------------------COMPLEX NUMBERS----------------------------
  
  {
    // conj(z)
    using namespace std;
    printStart(++testnum);
    Scalar<complex<double> > z = complex<double>(1,2);
    Scalar<complex<double> > expected = complex<double>(1,-2);
    Scalar<complex<double> > result;
    testcode( result = conj(z) );
    bool pass = alltrue(result==expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // z.conj()
    using namespace std;
    printStart(++testnum);
    Scalar<complex<double> > z = complex<double>(1,2);
    Scalar<complex<double> > expected = complex<double>(1,-2);
    Scalar<complex<double> > result;
    testcode( result = z.conj() );
    bool pass = alltrue(result==expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);

  }
  {
    // x.conj()
    using namespace std;
    printStart(++testnum);
    Scalar<double> x = 22;
    Scalar<double> expected = 22;
    Scalar<double> result;
    testcode( result = x.conj() );
    bool pass = alltrue(result==expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);

  }

  {
    // adjoint(z)
    using namespace std;
    printStart(++testnum);
    Scalar<complex<double> > z = complex<double>(1,2);
    Scalar<complex<double> > expected = complex<double>(1,-2);
    Scalar<complex<double> > result;
    testcode( result = adjoint(z) );
    bool pass = alltrue(result==expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // ~z
    using namespace std;
    printStart(++testnum);
    Scalar<complex<double> > z = complex<double>(1,2);
    Scalar<complex<double> > expected = complex<double>(1,-2);
    Scalar<complex<double> > result;
    testcode( result = ~z );
    bool pass = alltrue(result==expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  
  printSummary(testnum, failnum);
  return failnum;
}
