#define MATRICKS_DEBUG 3
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
    Dimensions d1;
    Dimensions d2;
    disp(d1==d2);
  }
  {
    // scalar + scalar

    printStart(++testnum);
    Scalar<int> s1 = 10;
    Scalar<int> s2 = -1;
    Scalar<int> expected = 9;
    Scalar<int> result;
    mdisp(s1,s2);
    disp(s1());
    s1() = 44;
    disp(s1);
    disp(s1[0]);
    disp(s2[0]);
    disp(-s1);
    disp(+s1);
    result = s1 + s2;
    //testcode( result = v1 + v2 );
    // bool pass = equal(result,expected);
    // printEnd(pass);
    // allpass = allpass && pass;
    // failnum += (!pass);
  }

  // {
  //   // scalar - scalar

  //   printStart(++testnum);
  //   Scalar<int> v1 = 10;
  //   Scalar<int> v2 = -1;
  //   Scalar<int> expected = 11;
  //   Scalar<int> result;
  //   testcode( result = v1 - v2 );
  //   bool pass = equal(result,expected);
  //   printEnd(pass);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   // scalar * scalar

  //   printStart(++testnum);
  //   Scalar<int> v1 = 10;
  //   Scalar<int> v2 = 3;
  //   Scalar<int> expected = 30;
  //   Scalar<int> result;
  //   testcode( result = v1 * v2 );
  //   bool pass = equal(result,expected);
  //   printEnd(pass);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  // {
  //   // scalar / scalar

  //   printStart(++testnum);
  //   Scalar<int> v1 = 27;
  //   Scalar<int> v2 = 9;
  //   Scalar<int> expected = 3;
  //   Scalar<int> result;
  //   testcode( result = v1 / v2 );
  //   bool pass = equal(result,expected);
  //   printEnd(pass);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

  
  // {
  //   // Test of a large scalar math expression

  //   printStart(++testnum);
  //   Scalar<double> v1 = 40;
  //   Scalar<double> v2 = -4;
  //   Scalar<double> expected = 25;
  //   Scalar<double>  result;
  //   testcode( result = 2*log10(abs(v1/v2)*100) + 3 + pow(-v2,2.));
  //   bool pass = approx(result,expected,tol);
  //   printEnd(pass);
  //   allpass = allpass && pass;
  //   failnum += (!pass);
  // }

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
