#define MATRICKS_DEBUG 1


#include "matricks.h"

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif



int main()
{
  using namespace matricks;
  using namespace std;
  using namespace display;
  using namespace md;

  int Nex = 1;
  
  cr();
  mdtitle("Calculus");
  matricks_preamble();

  header2("Integration");
  header3("Definite integrals");

  text("Integrating over an interval [a,b] yields a single number--the area under the curve.");
  cr();
  text("![Definite Integral](DefiniteIntegral.PNG)");

  
  {
    cr();
    cr();
    example(Nex++,"Definite integrals");
    codestart("C++");
    codemulti( const size_type N = 100000 );
    codemulti( const double a = 0 + 1/double(N) );
    codemulti( const double b = 1 - 1/double(N) );
    codemulti( Vector<double> x(linspace<double>(a,b,N-1)) );
    codemulti( Vector<double> f );
    codemulti( f=-log(log(1/x)) );
    codeend();
    cr();

   
    text("Integrating f(x), as given above, yields the [Euler–Mascheroni](http://mathworld.wolfram.com/Euler-MascheroniConstant.html) constant whose exact value is `0.577215664901532...`.  The function _f_(_x_) is singular at both x=0 and x=1.  Thus we omitted these points. As the results show, this simple approach to the integral isn't particularly accurate. ");
    cr();
    text(" ![Euler–Mascheron Integral](EulerMascheroniConstant.PNG)");
    cr();
    resultstart3("");
    resultmulti( N );
    resultmulti( a );
    resultmulti( b );
    resultmulti( integrate_a2b(f,a,b,0) );
    resultmulti( integrate_a2b(f,a,b,1) );
    resultmulti( integrate_a2b(f,a,b,2) );
    resultend();
  }


  header3("Semi-Definite Integrals");
  text("A semi-definite integral is created by replacing one of the end points with _x_.");
  cr();
  text("For the integral\n");
  text("![Semi-Definite Integral a2x](SemiDefinite_a2x.PNG)\n");
  text("use the method `integrate_a2x`.");
  cr();
  cr();
  text("For the integral\n");
  text("![Semi-Definite Integral x2b](SemiDefinite_x2b.PNG)\n");
  text("use the method `integrate_x2b`.");
  cr();
  cr();
  text("A semi-definite integral yields a function as its output.");
  
  text("Integration requires a cumulative sum.  Thus the caculation can not be accomplished via element-wise operations.  For this reasons these functions are performed in place, mimizing both memory usage and computation time.");
  text("All of the remaining functions discussed in this section modify the vector _in place_.");
  

    {
    cr();
    cr();
    example(Nex++," The error function integral");
    text("The [error function](http://mathworld.wolfram.com/Erf.html) is the following semi-definite integral of a Gaussian function (with zero mean and vairance of 1/2).");
    cr();
    text("![ErrorFunction](ErrorFunction.PNG)");
    codestart("C++");
    codemulti( const size_type N = 101 );
    codemulti( const double a = 0 );
    codemulti( const double b = 4 );
    codemulti( const double pi = M_PI );
    codemulti( Vector<double> x( linspace<double>(a,b,N) ) );
    codemulti( Vector<double> gauss );
    codemulti( gauss = 2/sqrt(pi)*exp(-sqr(x)) );
    codemulti( Vector<double> erf = gauss );
    codemulti( erf.integrate_a2x(a,b,1) ) ;
    codemulti( set_mathematica_var_format() );
    codeend();
    cr();

    text("The results _x_ and _erf_(_x_) are:");
    cr();
    codestart("Mathematica");
    disp(x);
    disp(erf);
    codeend();

    text("Cut and paste the above data for `x` and `erf` into Mathematica as well as the following commands");
    cr();
    codestart("Mathematica");
    text("p1=ListPlot[Partition[Riffle[x,erf],2],PlotStyle->Red];");
    text("p2=Plot[Erf[0,x],{x,0,4}];");
    text("Show[p1,p2]");
    codeend();

    text("This yields the following plot comparing the results above [red dots] to the exact function [solid blue].");

    text("![ErrorFunctionPlot](ErrorFunctionPlot.png)");

   
  }

      header2("Differentiation");
  text(" Differentiation requires points around it. For this reasons these functions are performed in place, mimizing both memory usage and computation time.");

  {
    cr();
    cr();
    example(Nex++,"Derivatives");
    codestart("C++");
    codemulti( Vector<double> v1(5) );
    codeend();
    cr();

   
    resultstart2("");
    resultend();
  }

  
  header2("Various related functions");
  text("All of these functions modify the vector _in place_.");

  {
    cr();
    cr();
    example(Nex++,"Various functions: `cumsum`, `cumprod`, `cumtrapz`, `diff`, etc");
    codestart("C++");
    codemulti( set_default_format() );
    codemulti( Vector<double> v1(5) );
    codeend();
    cr();

   
    resultstart2("");
    resultmulti( v1 = CARRAY({1,4,9,16,25})  );
    resultmulti( v1.cumsum()  );
    resultmulti( v1 = CARRAY({1,4,9,16,25})  );
    resultmulti( v1.cumtrapz()  );
    resultmulti( v1 = CARRAY({1,2,3,4,5})  );
    resultmulti( v1.cumprod()  );
    resultmulti( v1 = CARRAY({1,4,9,16,25})  );
    resultmulti( v1.diff()  );
    resultmulti( v1 = CARRAY({1,4,9,16,25})  );
    resultmulti( v1.diff(true)  );
    resultmulti( v1 = CARRAY({25,16,9,4,1})  );
    resultmulti( v1.cumsum_rev()  );
    resultmulti( v1 = CARRAY({25,16,9,4,1})  );
    resultmulti( v1.cumtrapz_rev()  );
    resultmulti( v1 = CARRAY({5,4,3,2,1})  );
    resultmulti( v1.cumprod_rev()  );
    resultmulti( v1 = CARRAY({1,4,9,16,25})  );
    resultmulti( v1.diff_rev()  );
    resultmulti( v1 = CARRAY({1,4,9,16,25})  );
    resultmulti( v1.diff_rev(true)  );
    resultend();
  }

  text("The suffix `_rev` denote that the function starts at the highest element instead of the lowest element. Passing `true` to diff signifies that the function is periodic over the interval [a,b]. ");
  
  matricks_toc();


  return 0;
}
