
#define MATRICKS_DEBUG 0
#include "matricks.h" 
#include "test.h" 


int main()
{

  using namespace matricks;
  using namespace display;

  print_matricks_info();
  mout << createStyle(BOLD+MAGENTA1).apply(__FILE__) << " - vector tests" <<std::endl;
  cr();
  cr();
  bool allpass = true;
  int testnum = 0;
  int failnum = 0;
  double tol = 5e-16;
  
  // TODO: add a test for every function and functionality
  //       check math with matlab or mathematica


  {
    // vector + vector

    printStart(++testnum);
    Vector<int> v1 = CARRAY({10,20,30,40});
    Vector<int> v2 = CARRAY({-1,-2,-3,-4});
    Vector<int> expected = CARRAY({9, 18, 27, 36});
    Vector<int> result;
    testcode( result = v1 + v2 );
    bool pass = equal(result,expected);
    printEnd(pass);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // vector - vector

    printStart(++testnum);
    Vector<int> v1 = CARRAY({10,20,30,40});
    Vector<int> v2 = CARRAY({-1,-2,-3,-4});
    Vector<int> expected = CARRAY({11, 22, 33, 44});
    Vector<int> result;
    testcode( result = v1 - v2 );
    bool pass = equal(result,expected);
    printEnd(pass);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // vector * vector

    printStart(++testnum);
    Vector<int> v1 = CARRAY({10,20,30,40});
    Vector<int> v2 = CARRAY({-1,-2, 3, 0});
    Vector<int> expected = CARRAY({-10, -40, 90, 0});
    Vector<int> result;
    testcode( result = v1 * v2 );
    bool pass = equal(result,expected);
    printEnd(pass);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  {
    // vector / vector

    printStart(++testnum);
    Vector<int> v1 = CARRAY({10,20,30,40});
    Vector<int> v2 = CARRAY({-1,-2, 3, 10});
    Vector<int> expected = CARRAY({-10, -10, 10, 4});
    Vector<int> result;
    testcode( result = v1 / v2 );
    bool pass = equal(result,expected);
    printEnd(pass);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  
  {
    // Test of a large vector math expression

    printStart(++testnum);
    Vector<double> v1 = CARRAY({10.,20.,30.,40.});
    Vector<double> v2 = CARRAY({-1,-2,-3,-4});
    Vector<double> expected = CARRAY({10, 13, 18, 25});
    Vector<double>  result;
    testcode( result = 2*log10(abs(v1/v2)*100) + 3 + pow(-v2,2.));
    bool pass = approx(result,expected,tol);
    printEnd(pass);
    allpass = allpass && pass;
    failnum += (!pass);
  }

  printSummary(testnum, failnum);
  return failnum;
}
