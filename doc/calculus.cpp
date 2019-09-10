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

   
    text("Integrating f(x), as given above, yields the [Euler–Mascheroni](http://mathworld.wolfram.com/Euler-MascheroniConstant.html) constant whose exact value is `0.577215664901532...`.  The function _f_(_x_) is singular at both x=0 and x=1.  Thus we omitted these points. As the results show, many points are needed to achieve even a few digits of accuracy, due to the singularities. ");
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
  text("* For the integral\n");
  text("![Semi-Definite Integral a2x](SemiDefinite_a2x.PNG)\n");
  text("use the method `f.integrate_a2x(a, b)` or the function `integrate_a2x(f, a, b)`.");
  cr();
  cr();
  text("* For the integral\n");
  text("![Semi-Definite Integral x2b](SemiDefinite_x2b.PNG)\n");
  text("use the method `f.integrate_x2b(a, b)` or the function `integrate_x2b(f, a, b)`.");
  cr();
  cr();
  text("Where [`a`,`b`] defines the interval being used\n");
  
  cr();
  cr();
  text("A semi-definite integral yields a function as its output.");
  
  text("Integration requires a cumulative sum.  Thus the caculation can not be accomplished via element-wise operations.  For this reasons these functions can be performed: ");
  text("  * on a Vector in place using `f.integrate_a2x(a, b)`, mimizing both memory usage and computation time.");
  text("  * on a Vector or expression using the function `integrate_a2x(f, a, b)`,  in which case a `new Vector` is created inside the function and returned. ");

  text("All of the remaining functions discussed in this page can be called in either manner.");
  

  {
    cr();
    cr();
    example(Nex++," The error function integral");
    text("The [error function](http://mathworld.wolfram.com/Erf.html) is the following semi-definite integral of a Gaussian function (with zero mean and variance of 1/2).");
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
    codemulti( erf.integrate_a2x(a,b) ) ;
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


  header3("Semi-Definite Integrals: optional parameters");


  text("The optional `order` parameter specifies the integration method order: \n");
  text("* 0 for rectangular integration\n");
  text("* 1 for trapezoidal integration (DEFAULT).\n");

  text("Usage: \n");
  text("* `f.integrate_x2b(a, b, order)`");
  text("* `integrate_x2b(f, a, b, order)`");
  
  header2("Differentiation");
  text("* Differentiation requires points around it.   The derivative can be performed :");
  text("  * on a Vector in place using `f.deriv(a, b)`, mimizing both memory usage and computation time.");
  text("  * on a Vector or expression using the function `deriv(f, a, b)`,  in which case a `new Vector` is created inside the function and returned. ");


  {
    cr();
    cr();
    example(Nex++,"Derivative of the function _f_(_x_) = 5 _x_");
    cr();
    cr();
    text("The derivative of the function _f_(_x_) = is the constant 5");
    codestart("C++");
    codemulti( set_default_format() );
    codemulti( const double pi = M_PI );
    codemulti( const size_type N = 11 );
    codemulti( const double a = 0 );
    codemulti( const double b = 1 );
    codemulti( Vector<double> x( linspace<double>(a,b,N) ) );
    codeend();
    cr();

    resultstart3("");
    resultmulti(x);
    resultmulti(deriv(5*x,a,b));

    // resultmulti(deriv(5*x,a,b,1,2));
    // resultmulti(deriv(5*x,a,b,1,3));
    // resultmulti(deriv(5*x,a,b,1,5));
    // resultmulti(deriv(5*x,a,b,1,7));

    // resultmulti(deriv(x*x,a,b,1,2));
    // resultmulti(deriv(x*x,a,b,1,3));
    // resultmulti(deriv(x*x,a,b,1,5));
    // resultmulti(deriv(x*x,a,b,1,7));

    resultend();
  }


    header2("Differentiation: optional parameters");
    text("* The differentiation method/function has 3 optional parameters:");
    text("  * `f.deriv(a, b, n, Dpts, periodic)` or `deriv(f, a, b, n, Dpts, periodic)`");
    text("* The optional parameters are:");
    text("  * `n` [DEFAULT=`1`] is the number of derivatives to compute: ");
    text("  * `Dpts` [DEFAULT=`7`] is the number of points to use in the calculation: 2,3,5, or 7.  More points yield better accuracy. ");
    text("  * `periodic` [DEFAULT=`false`]. When set to `true` the derivative at the end points will be of higher accuracy for periodic function.");

    header2("Differentiation: taking multiple derivatives in one call");
    
  {
    cr();
    cr();
    example(Nex++,"The fourth derivative of sin _x_");
    cr();
    cr();
    text("Here we take the 4th derivative of sin _x_ using `Dpts`=2,3,5, and 7 points. The result for all should be sin _x_:");
    cr();
    cr();
    text("![4th derivative of sin(x)](fourthDerivativeOfSin.png)");
    cr();
    cr();
    text("We also set `periodic=true` since sin _x_ is periodic over [0,2pi)");
    codestart("C++");
    codemulti( set_mathematica_var_format() );
    codemulti( const double pi = M_PI );
    codemulti( const size_type N = 25 );
    codemulti( const double a = 0 );
    codemulti( const double b = 2*pi*(1 - 1/double(N)) );
    codemulti( Vector<double> x( linspace<double>(a,b,N) ) );
    codemulti( Vector<double> f = sin(x) );
    codemulti( Vector<double> f2 = deriv(f,a,b,4,2,true )  );
    codemulti( Vector<double> f3 = deriv(f,a,b,4,3,true )  );
    codemulti( Vector<double> f5 = deriv(f,a,b,4,5,true )  );
    codemulti( Vector<double> f7 = deriv(f,a,b,4,7,true )  );
    codeend();
    cr();

    codestart("Mathematica");
    disp(x);
    disp(f2);
    disp(f3);
    disp(f5);
    disp(f7);
    codeend();

    text("Cut and paste the above data for `x`, `f2`, `f3`,...  into Mathematica as well as the following commands");
    cr();
    codestart("Mathematica");
    text("p2=ListPlot[Partition[Riffle[x,f2],2],PlotStyle->Red];");
    text("p3=ListPlot[Partition[Riffle[x,f3],2],PlotStyle->Orange];");
    text("p5=ListPlot[Partition[Riffle[x,f5],2],PlotStyle->Yellow];");
    text("p7=ListPlot[Partition[Riffle[x,f7],2],PlotStyle->Green];");
    text("p=Plot[Sin[x],{x,0,2*Pi}];");
    text("Show[p,p2,p3,p5,p7]");
    codeend();

    text("This yields the following plot comparing the results above [dots] to the exact function [solid blue].");

    text("![The Fourth Derivative of Sin(x)](FourthDerivativeSinPlot.png)");

  }




  
  header2("Various functions related to integration and differentiation");
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
