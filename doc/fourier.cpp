#define MATRICKS_DEBUG 1


#include "matricks.h"
#include "TypeTraits.h"
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
  mdtitle0("Calculating a function via Fourier series and plotting the results in Matlab");
  matricks_preamble();

  header2("Fourier Series for the Clausen Functions");
  text("As our example, we'll use the [Clausen functions](http://mathworld.wolfram.com/ClausenFunction.html). The Clausen function of order _n_ has Fourier series: ");
  text("![Clausen Functions](ClausenDefinition.png)");


  header3("Clausen function of order _n=1_");

  {
    cr();
    cr();
    text("Set up the output format so that we can copy and paste into Matlab");
    codestart("C++");
    codemulti( using namespace display  );
    codemulti( FormatDataVector::string_opening =  "[ ...\n    "  );
    codemulti( FormatDataVector::string_delimeter = ", "  );
    codemulti( FormatDataVector::max_elements_per_line = 5  );
    codemulti( FormatDataVector::string_endofline = " ...\n    "  );
    codemulti( FormatDataVector::string_closing =   " ...\n]"  );
    codemulti( setFormatString<double>("% 10.8e")  );
    codemulti(  FormatData<double>::tens = false );
    codeend();
    cr();


    text("Define the coefficient vectors: ");
    cr();

    
    codestart("C++");
    codemulti( const size_type N = 20 );
    codemulti( Vector<double> k = range<double>(0,N-1)  );
    codemulti( Vector<double> An = 1/k );
    codemulti( An[0] = 0. );
    codemulti( Vector<double> Bn = Vector<double>(N,0.) );
    codeend();
    cr();


    text("Define the coordinate vector `t` as 51 points over the interval [0,+2pi]: ");
    cr();
    
    codestart("C++");
    codemulti(   const double pi = M_PI  );
    codemulti(   Vector<double> t = linspace<double>(0,2*pi,51) );
    codeend();
    cr();


    text("Calculate the Fourier series and store the results in vector `Cl1`: ");
    cr();
    codestart("C++");
    codemulti(     const double T = 2*pi );
    codemulti(     const double omega = 2*pi/T );
    codemulti(     Vector<double> CL1 = ifourier(An,Bn, t, An.size(), omega ) );
    codeend();
    cr();

    
    text("The results `t` and `Cl1` are:");
    cr();
    codestart("Matlab");
    disp(t);
    disp(CL1);
    codeend();

    text("Cut and paste the above data for `t` and `CL1` into Matlab as well as the following commands");
    cr();
    codestart("Matlab");
    text("N=10000;");
    text("dt=2*pi/N;");
    text("tt=linspace(dt,2*pi-dt,10000);");
    text("y1=-log(2*sin(tt/2));");
    text("plot(t,CL1,'r.',tt,y1)");
    codeend();

    text("The above matlab code calculates the first Clausen function using the following equation (refer to the link earlier for more about this).  We exclude the end points, 0 and pi, because the function is infinite at these points.");

    text("![Closed form for CL1(t)](ClausenFormula_n1.png)");

    text("This yields the following plot comparing the Fourier series [red dots] to the exact function [solid blue].");

    text("![Fourier Series for CL1</sub>(t)](ClausenFourierSeries_n1.png)");

  }

  header3("Clausen function of order _n=2_");

  {
    cr();
    cr();
    text("Set up the output format so that we can copy and paste into Matlab, this time using the function `set_matlab_var_format()`");
    codestart("C++");
    codemulti( set_matlab_var_format()  );
    codeend();
    cr();


    text("Define the coefficient vectors: ");
    cr();

    
    codestart("C++");
    codemulti( const size_type N = 20 );
    codemulti( Vector<double> k = range<double>(0,N-1)  );
    codemulti( Vector<double> An = Vector<double>(N,0.) );
    codemulti( Vector<double> Bn = 1./sqr(k) );
    codemulti( Bn[0] = 0. );
    codeend();
    cr();


    text("Define the coordinate vector `t` as 51 points over the interval [0,+2pi]: ");
    cr();
    
    codestart("C++");
    codemulti(   const double pi = M_PI  );
    codemulti(   Vector<double> t = linspace<double>(0,2*pi,51) );
    codeend();
    cr();


    text("Calculate the Fourier series and store the results in vector `Cl1`: ");
    cr();
    codestart("C++");
    codemulti(     const double T = 2*pi );
    codemulti(     const double omega = 2*pi/T );
    codemulti(     Vector<double> CL2 = ifourier(An,Bn, t, An.size(), omega ) );
    codeend();
    cr();

    
    text("The results `t` and `CL2` are:");
    cr();
    codestart("Matlab");
    disp(t);
    disp(CL2);
    codeend();

    text("Cut and paste the above data for t and CL2 into Matlab as well as the following commands.");
    cr();
    codestart("Matlab");
    text("N=10000;");
    text("dt=2*pi/N;");
    text("tt=linspace(dt,2*pi-dt,10000);");
    text("y2=cumtrapz(-log(2*sin(tt/2)))*dt;");
    text("plot(t,CL2,'r.',tt,y2)");
    codeend();

    text("The above matlab code calculates the second Clausen function using the following integral (refer to the link earlier for more about this).  We exclude the end points, 0 and pi, because the integrand is infinite at these points.");

    text("![Closed form for CL2(t)](ClausenFormula_n2.png)");

    text("This yields the following plot comparing the Fourier series [red dots] to the exact function [solid blue].");

    text("![Fourier Series for CL2(t)](ClausenFourierSeries_n2.png)");

  }

  matricks_toc();

  
  return 0;
}
