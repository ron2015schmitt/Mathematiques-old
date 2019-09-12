#define MATRICKS_DEBUG 1


#include "matricks.h"

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif


// ************************************************************
// The output screenshots are generated by examples/printing.cpp
// ************************************************************


int main()
{
  using namespace matricks;
  using namespace std;
  using namespace display;
  using namespace md;

  int Nex = 1;
  
  cr();
  mdtitle("\\*Formatted and styled printing");
  matricks_preamble();
  text("* The examples in this section can be found in file_ `examples/printing.cpp`\n");
  text("* All of the functions decribed in this section are in the namespace `display`");
  text("* Practically speaking, this functionality is one of the most useful aspects of mātricks.");


  // disp()
  
  header2("The function `disp(x)`");
  cr();cr();

  text("The function `disp(x)` displays both the variable name (or expression) as well as its value, formatted according to the user.   This is an incredibly useful function.");
  cr();cr();
  
  example(Nex++,"simple examples of `disp(x)` usage");
  cr();cr();
  text("Define and initialize some variables:");
  cr();cr();
  codestart("C++");
  codemulti(  int n = 45 );
  codemulti(  double x = 3.14 );
  codemulti(  double vals[] = {1.1,2.2,3.3} );
  codemulti(  bool done = true );
  codemulti( Vector<double> v = range<double>(1,10) );
  codemulti(  char str[] = "hello" );
  codemulti(  std::string s = "world"  );
  codemulti(  std::complex<double> z(1,-1)  );
  codeend();

  text("display each variable using `disp`:");
  cr();cr();

  codestart("C++");
  text("disp(n);");
  text("disp(x);");
  text("disp(vals);");
  text("disp(done);");
  text("disp(v);");
  text("disp(str);");
  text("disp(s);");
  text("disp(z);");
  codeend();

  cr();cr();
  text("The actual screen-shot of the output is shown below:");
  cr();cr();
  text("![disp example 1](disp_example1.png)");
  
  // tdisp()

  header2("The function `tdisp(x)`");
  cr();cr();

  text("The function `tdisp(x)` displays the variable type, in addition to the variable name and value");
  cr();cr();
  
  example(Nex++," `tdisp(x)` usage");

  cr();cr();

  codestart("C++");
  text("tdisp(n);");
  text("tdisp(x);");
  text("tdisp(vals);");
  text("tdisp(done);");
  text("tdisp(v);");
  text("tdisp(str);");
  text("tdisp(s);");
  text("tdisp(z);");
  codeend();

  cr();cr();
  text("The actual screen-shot of the output is shown below:");
  cr();cr();
  text("![disp example 2](disp_example2.png)");


  // mdisp()

  header2("The function `mdisp(x1,x2,...)`");
  cr();cr();

  text("* The function `mdisp(x1,x2,...)` displays multiple variables (from 1 to 10) on the same line.");
  text("* Very useful for displaying:");
  text("  * the arguments passed to a function");
  text("  * the variables inside a for loop");
  cr();cr();
  

  example(Nex++," `mdisp(x1,x2,...)` usage");
  cr();cr();

  codestart("C++");
  text("mdisp(n,x,vals,done,str,s,z);");
  codeend();

  cr();cr();
  text("The actual screen-shot of the output is shown below:");
  cr();cr();
  text("![disp example 3](disp_example3.png)");

  // tried this but doesn't help with displaying at the correct scale
  // the image are always blurred by github for some reason
  //text("<img src=\"disp_example3.png\" width=\"100%\" height=\"100%\">");



  // expressions

  header2("Displaying expressions");
  cr();cr();

  text("* The functions introduced above can also be used to display expressions.");
  text("* vector and matrix expressions can be displayed in this manner.");
  cr();cr();
  

  example(Nex++," displaying expressions");
  cr();cr();

  codestart("C++");
  text("disp(n+3);");
  text("disp(10*x-1);");
  text("disp(!done);");
  text("disp( round(10*sin(pi/10*v) + 10) );");
  text("disp(s+\" tour\");");
  codeend();

  cr();cr();
  text("The actual screen-shot of the output is shown below:");
  cr();cr();
  text("![disp example 4](disp_example4.png)");


  // expressions

  header2("Supported Types");
  cr();cr();

  text("The following types are currently supported by the display commands");
  text("* **Any class** with methods `.classname()` and `operator<<` is automatically supported");
  text("* `matricks::Vector<D>` vectors");
  text("* `matricks::Matrix<D>` matrices");
  text("* `bool`");
  text("* `short`, `int`, `long`, `long long`");
  text("* `unsigned short`, `unsigned int`, `unsigned long`, `unsigned long long`");
  text("* `float`, `double`, `long double`");
  text("* `char`, `unsigned char`");
  text("* `char[]` C-style strings");
  text("* `D[]` C-style arrays");
  text("* `std::string` C++ strings");
  text("* `std::complex<D>` complex numbers");
  text("* `std::vector` C++ vectors");
  text("* `std::valarray` C++ valarrays");
  text("* `std::vector` C++ vectors");
  text("* `std::list` C++ lists");
  text("* `std::queue` C++ queues");
  text("* `std::map` C++ maps");
  text("* `std::initializer_list` C++11 ");


  // debug-only printing

  header2("Debug-only printing");
  cr();cr();

  header3("Debug-only printing: `disp[123]`, `tdisp[123]`, `mdisp[123]`");
  cr();cr();

  text("The display commands also have versions that only display when the code is compiled with the debug flag `MATRICKS_DEBUG` set.");
  text("* `disp1`, `tdisp1`, `mdisp1` will");
  text("  * when `MATRICKS_DEBUG >= 1`: behave like `disp`, `tdisp`, `mdisp`");
  text("  * when `MATRICKS_DEBUG == 0` or is undefined: compile to null statements (ie no output and no real-time hit)");

  text("* `disp2`, `tdisp2`, `mdisp2` will");
  text("  * when `MATRICKS_DEBUG >= 2`: behave like `disp`, `tdisp`, `mdisp`");
  text("  * when `MATRICKS_DEBUG < 2` or is undefined: compile to null statements (ie no output and no real-time hit)");


  text("* `disp3`, `tdisp3`, `mdisp3` will");
  text("  * when `MATRICKS_DEBUG >= 3`: behave like `disp`, `tdisp`, `mdisp`");
  text("  * when `MATRICKS_DEBUG < 3` or is undefined: compile to null statements (ie no output and no real-time hit)");


  header3("Debug-only printing: `print[123]`, `printf[123]`");
  cr();cr();
  
  text("* The functions `print1`, `print2`, `print3` each take a single std::string (or C string) as input and print the string to the stream `mout` followed by a carriage return.");

  text("* The functions `printf1`, `printf2`, `printf3` function like printf, but actually use sprintf and then output to the stream `mout` using C++ methodlogy.");


  
  header2("Controlling the output stream and color");
  text("* All output uses C++ streams (*no* `printf`)");
  text("* By default all output is sent to `std::cout`");
  text("* The output stream can be set using `Terminal::setmout(std::ostream&)`.");
  text("For example to set the output to stderr:");
  text("```C++\n");
  text("Terminal::setmout(std::cerr);");
  text("```\n");
  text("* You can use the matricks output stream via `Terminal::getmout()` or the macro `mout`");
  text("For example, you can output a string:");
  text("```C++\n");
  text("mout << \"Hello World\" << std::endl;\n");
  text("```\n");
  text("* By default, matricks uses color when it detects that the output stream is connected to a terminal.");
  text("* By default, matricks disables color when it detects that the output stream is piped to a file.");
  text("* However, the user can override this behavior as follows\n");
  text("To force matricks to use plain text, use the following settings:");
  text("```C++\n");
  text("Terminal::setColorOverride(true);");
  text("Terminal::setOverrideValue(false);");
  text("```\n");
  text("To force matricks to use color text, use the following settings:");
  text("```C++\n");
  text("Terminal::setColorOverride(true);");
  text("Terminal::setOverrideValue(true);");
  text("```\n");
  text("This latter setting can be used to print in colors to a file, which will display properly when the file is viewed via a terminal command like `more`,`less`, or `cat`.\n");
  
  cr();cr();
  header2("The `Style` class");
  text("* Color and other text attributes are controlled using the [ANSI escape codes for terminals](https://en.wikipedia.org/wiki/ANSI_escape_code).\n");
  text("* matricks defines the class `Style` for applying color and other attributes, such as **bold**\n");
  text("* The predefined styles are shown below\n");
  text("![styles](displaycolors.png)\n");
  text("You can combine the styles using the `+` sign\n");
  text("![stylescombined](displaycolorscombined.png)\n");
  text("* To use any of these, use the `createStyle` macro as the following example illustrates");
  text("```C++\n");
  text("Style mystyle = createStyle(BOLD+RED);\n");
  text("mout << mystyle.apply(\"with style\") + \" without style \" << std::endl;\n");
  text("```\n");
  text("The output from the above two lines of code is:\n");
  text("![stylesexample](displaycolorsexample.png)");
  cr();cr();
  text("* _The Style class checks to see whether or not to actually use colors, as described in the previous sub-section_\n");
  cr();cr();

  cr();cr();
  header3("Custom styles");
  text("* The user can define a style for any foreground color and background color combination as follows:\n");

  codestart("C++");
  text("int nf = 27;  // color for foreground  \n");
  text("int nb = 227; // color for background  \n");
  text("display::Style mystyle(nf,nb); \n");
  text("display::mout << mystyle.apply(\"Hello World\") << std::endl; \n");
  codeend();

  text("* Style objects can added:\n");
  codestart("C++");
  text("int nf = 27;  // color for foreground");
  text("int nb = 227; // color for background");
  text("display::Style mystyle(nf,nb);");
  text("display::Style bold(BOLD);");
  text("display::Style mybold = bold + mystyle;");
  text("display::mout << mybold.apply(\"Hello World\") << std::endl; ");
  codeend();
  text("* Place the attributes, eg `BOLD`, `UNDERLINE`, before the color styles");
  
  text("* Wikipedia lists the allowable [8-bit color definitions](https://en.wikipedia.org/wiki/ANSI_escape_code#8-bit)\n");

  
  header2("Customizing the format and colors");
  cr();cr();
  header3("Customizing number formats");
  text("**TO DO**");
  cr();cr();
  header3("Customizing complex number format");
  text("The format for complex numbers is set using the function `setFormatStringComplex`.  The default format is `\"(%s, %s)\"`\n");
  cr();cr();

  {
  example(Nex++," complex number formats");
  codestart("C++");
  codemulti( using namespace display );
  codemulti( std::complex<double> z(1,-2)  );
  codeend();

  cr();cr();
  text("Default format: `\"(%s, %s)\"`\n");
  codestart("C++");
  disp(z);
  codeend();

  cr();cr();
  text("Matlab input format `\"%s + i*%s\"`\n");
  setFormatStringComplex("%s + i*%s");
  codestart("C++");
  disp(z);
  codeend();

  cr();cr();
  text("Mathematica input format `\"%s + I*%s\"`\n");
  setFormatStringComplex("%s + I*%s");
  codestart("C++");
  disp(z);
  codeend();

  cr();cr();
  text("Matlab output format / C++14 format `\"%s + %si\"`\n");
  setFormatStringComplex("%s + %si");
  codestart("C++");
  disp(z);
  codeend();

  
  }

  header3("Customizing Vector format");
  text("**TO DO**");
  cr();cr();
  


  
  matricks_toc();

  return 0;
}
