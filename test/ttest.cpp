
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
    // tensor + tensor

    printStart(++testnum);
    Dimensions dims(2,3,4);
    Tensor<int> t1(dims);
    int c = 0;
    for (index_type i = 0; i < t1.dims()[0]; i++) {
      for (index_type j = 0; j < t1.dims()[1]; j++) {
	for (index_type k = 0; k < t1.dims()[2]; k++) {
	  t1(i,j,k) = 100 + c++;
	}
      }
    }
    Tensor<int> t2(dims);
    c = 0;
    for (index_type i = 0; i < t2.dims()[0]; i++) {
      for (index_type j = 0; j < t2.dims()[1]; j++) {
	for (index_type k = 0; k < t2.dims()[2]; k++) {
	  t2(i,j,k) = -100 + 9*c++;
	}
      }
    }
    int A[24] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230};
    Tensor<int> expected(dims);
    expected = A;
    Tensor<int> result(dims);
    testcode( result = t1 + t2 );
    bool pass = equal(result,expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  // //-------------------COMPLEX NUMBERS----------------------------
  
  {
    // conj(z)
    using namespace std;
    printStart(++testnum);
    Dimensions dims(2,3);
    
    Tensor<complex<double> > z(dims);
    z[0] = complex<double>(1,2);
    z[1] = complex<double>(-1.5,26.7);
    z[2] = complex<double>(5,-8);
    z[3] = complex<double>(4,-5.6);
    z[4] = complex<double>(-1,2.122);
    z[5] = complex<double>(-1.5,-88);
    Tensor<complex<double> > expected(dims);
    expected[0] = complex<double>(1,-2);
    expected[1] = complex<double>(-1.5,-26.7);
    expected[2] = complex<double>(5,8);
    expected[3] = complex<double>(4,5.6);
    expected[4] = complex<double>(-1,-2.122);
    expected[5] = complex<double>(-1.5,88);
    Tensor<complex<double> > result;
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
    Dimensions dims(2,3);
    
    Tensor<complex<double> > z(dims);
    z[0] = complex<double>(1,2);
    z[1] = complex<double>(-1.5,26.7);
    z[2] = complex<double>(5,-8);
    z[3] = complex<double>(4,-5.6);
    z[4] = complex<double>(-1,2.122);
    z[5] = complex<double>(-1.5,-88);
    Tensor<complex<double> > expected(dims);
    expected[0] = complex<double>(1,-2);
    expected[1] = complex<double>(-1.5,-26.7);
    expected[2] = complex<double>(5,8);
    expected[3] = complex<double>(4,5.6);
    expected[4] = complex<double>(-1,-2.122);
    expected[5] = complex<double>(-1.5,88);
    Tensor<complex<double> > result;
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
    Dimensions dims(2,3);
    Tensor<double> x(dims);
    x[0] = 1;
    x[1] = -1.5;
    x[2] = 5;
    x[3] = 4;
    x[4] = -1;
    x[5] = -1.5;
    Tensor<double> expected(dims);
    expected[0] = 1;
    expected[1] = -1.5;
    expected[2] = 5;
    expected[3] = 4;
    expected[4] = -1;
    expected[5] = -1.5;
    Tensor<double> result;
    testcode( result = x.conj() );
    bool pass = alltrue(result==expected);
    printEnd(pass,result,expected);
    allpass = allpass && pass;
    failnum += (!pass);
  }


  printSummary(testnum, failnum);
  return failnum;
}
