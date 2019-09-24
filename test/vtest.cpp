
#define MATRICKS_DEBUG 0

#include "matricks.h" 


void printStart(const int n) {
  using namespace display;
  std::string s = "Test#" + num2string(n)+":";
  s = printf2str("%-10s",s.c_str());
  mout << createStyle(BLUE2+BOLD).apply(s);
}

void printEnd_(const bool pass, const int linenum) {
  using namespace display;
  mout << "          ";
  if (pass) {
    mout << createStyle(GREEN1+BOLD).apply("Passed")  << std::endl;
  } else {
    mout << createStyle(RED+BOLD).apply("FAILED") ;
    std::string s = createStyle(BOLD).apply(num2string(linenum));
    mout << createStyle(BLUE2).apply("  Refer to line#"+s ) << std::endl;
  }
    mout << std::endl;
}

#define printEnd(pass) printEnd_(pass, __LINE__)



void printCode(const std::string& str) {
  using namespace display;
  mout<<  createStyle(GRAY1).apply(str) << std::endl;
}

#define testcode(...)  printCode(stringify(__VA_ARGS__)); __VA_ARGS__







int main()
{

  using namespace matricks;
  using namespace display;

  print_matricks_info();

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

  {
  mout << StyledString::get(HORLINE);
  mout << createStyle(BLUE2+BOLD).apply("SUMMARY:");

  std::string s = printf2str("%-4d",testnum);
  mout << "  "<< createStyle(BOLD).apply(s);
  mout << createStyle(BOLD).apply("TOTAL") << std::endl;

  s = printf2str("%-4d",(testnum-failnum));
  mout << "          "<< createStyle(GREEN1+BOLD).apply(s);
  mout << createStyle(GREEN1+BOLD).apply("PASSED") << std::endl;

  if (failnum > 0) {
    s = printf2str("%-4d",(failnum));
    mout << "          "<< createStyle(RED+BOLD).apply(s);
    mout << createStyle(RED+BOLD).apply("FAILED") << std::endl;
  }
  
  mout << StyledString::get(HORLINE);
  cr();
  }
  return failnum;
}
