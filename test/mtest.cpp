
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


  printSummary(testnum, failnum);
  return failnum;
}
