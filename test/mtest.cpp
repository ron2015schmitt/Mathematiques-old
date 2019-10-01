
#define MATRICKS_DEBUG 0
#include "matricks.h" 
#include "test.h" 


int main()
{

  using namespace matricks;
  using namespace display;

  print_matricks_info();
  mout << createStyle(BOLD+MAGENTA1).apply(__FILE__) << " - matrix tests" <<std::endl;
  cr();
  cr();
  
  bool allpass = true;
  int testnum = 0;
  int failnum = 0;
  double tol = 5e-16;
  
  // TODO: add a test for every function and functionality
  //       check math with matlab or mathematica


  {
    // matrix + matrix
    using namespace std;  // need this recognize lists
    printStart(++testnum);
    Matrix<int> m1(2,2);
    m1 = AORLIST({10,20,30,40});
    Matrix<int> m2(2,2);
    m2 = AORLIST({-1,-2,-3,-4});
    Matrix<int> expected(2,2);
    expected = AORLIST({9, 18, 27, 36});
    Matrix<int> result;
    testcode( result = m1 + m2 );
    bool pass = equal(result,expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


    //-------------------COMPLEX NUMBERS----------------------------
  
  {
    // conj(z)
    using namespace std;
    printStart(++testnum);
    Matrix<complex<double> > z(2,3);
    z[0] = complex<double>(1,2);
    z[1] = complex<double>(-1.5,26.7);
    z[2] = complex<double>(5,-8);
    z[3] = complex<double>(4,-5.6);
    z[4] = complex<double>(-1,2.122);
    z[5] = complex<double>(-1.5,-88);
    Matrix<complex<double> > expected(2,3);
    expected[0] = complex<double>(1,-2);
    expected[1] = complex<double>(-1.5,-26.7);
    expected[2] = complex<double>(5,8);
    expected[3] = complex<double>(4,5.6);
    expected[4] = complex<double>(-1,-2.122);
    expected[5] = complex<double>(-1.5,88);
    Matrix<complex<double> > result;
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
    Matrix<complex<double> > z(2,3);
    z[0] = complex<double>(1,2);
    z[1] = complex<double>(-1.5,26.7);
    z[2] = complex<double>(5,-8);
    z[3] = complex<double>(4,-5.6);
    z[4] = complex<double>(-1,2.122);
    z[5] = complex<double>(-1.5,-88);
    Matrix<complex<double> > expected(2,3);
    expected[0] = complex<double>(1,-2);
    expected[1] = complex<double>(-1.5,-26.7);
    expected[2] = complex<double>(5,8);
    expected[3] = complex<double>(4,5.6);
    expected[4] = complex<double>(-1,-2.122);
    expected[5] = complex<double>(-1.5,88);
    Matrix<complex<double> > result;
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
    Matrix<double> x(2,3);
    x[0] = 1;
    x[1] = -1.5;
    x[2] = 5;
    x[3] = 4;
    x[4] = -1;
    x[5] = -1.5;
    Matrix<double> expected(2,3);
    expected[0] = 1;
    expected[1] = -1.5;
    expected[2] = 5;
    expected[3] = 4;
    expected[4] = -1;
    expected[5] = -1.5;
    Matrix<double> result;
    testcode( result = x.conj() );
    bool pass = alltrue(result==expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  //-------------------Transpose and adjoint----------------------------
  {
    // transpose(x)
    using namespace std;
    printStart(++testnum);
    Matrix<double> x(2,3);
    x[0] = 1;
    x[1] = -2.5;
    x[2] = 5;
    x[3] = 4;
    x[4] = -1;
    x[5] = -1.5;
    Matrix<double> expected(3,2);
    expected[0] = 1;
    expected[1] = 4;
    expected[2] = -2.5;
    expected[3] = -1;
    expected[4] = 5;
    expected[5] = -1.5;
    Matrix<double> result;
    testcode( result = x.transpose());
    bool pass = alltrue(result==expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }
  {
    // x.transpose()
    using namespace std;
    printStart(++testnum);
    Matrix<double> x(2,3);
    x[0] = 1;
    x[1] = -2.5;
    x[2] = 5;
    x[3] = 4;
    x[4] = -1;
    x[5] = -1.5;
    Matrix<double> expected(3,2);
    expected[0] = 1;
    expected[1] = 4;
    expected[2] = -2.5;
    expected[3] = -1;
    expected[4] = 5;
    expected[5] = -1.5;
    Matrix<double> result;
    testcode( result = transpose(x));
    bool pass = alltrue(result==expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  printSummary(testnum, failnum);
  return failnum;
}
