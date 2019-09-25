#ifndef MATRICKS__TEST_H
#define MATRICKS__TEST_H 1


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

#define testtext(...)  printCode(stringify(__VA_ARGS__))


void printSummary(const int testnum, const int failnum) {
  using namespace display;

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


#endif
