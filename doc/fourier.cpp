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

  header2("Fourier Series for the Claussen Functions");
  text("As our example, we'll use the [Claussen functions](http://mathworld.wolfram.com/ClausenFunction.html). The Claussen function of order _n_ has Fourier series: ");
  text("![Claussen Functions](ClaussenDefinition.PNG)");


  header3("Claussen function of order _n=1_");

  {
    cr();
    cr();
    text("Set up the output format so that we can copy and paste into Matlab");
    codestart("C++");
    codemulti( using namespace display  );
    codemulti( FormatDataVector::string_opening =  "[\n    "  );
    codemulti( FormatDataVector::string_delimeter = ", "  );
    codemulti( FormatDataVector::max_elements_per_line = 5  );
    codemulti( FormatDataVector::string_endofline = "\n    "  );
    codemulti( FormatDataVector::string_closing =   "\n] "  );
    codemulti( setFormatString<double>("% 10.6e")  );
    codemulti(  FormatData<double>::tens = false );
    codeend();
    cr();


  




    text("Define the coefficient vectors: ");
    cr();

    
    codestart("C++");
    codemulti( const size_type N = 20 );
    codemulti( Vector<double> An = 1./range<double>(0,N-1) );
    codemulti( An[0] = 0. );
    codemulti( Vector<double> Bn = Vector<double>(N,0.) );
    codeend();
    cr();


    text("Define the coordinate vector `t` as 201 points over the interval [-2pi,+2pi]: ");
    cr();
    
    codestart("C++");
    codemulti(   const double pi = M_PI  );
    codemulti(   Vector<double> t = linspace<double>(-2*pi,2*pi,201) );
    codeend();
    cr();


    text("Calculate the Fourier series and store the results in vector `Cl1`: ");
    cr();
    codestart("C++");
    codemulti(     const double T = 2*pi );
    codemulti(     const double omega = 1 );
    codemulti(     Vector<double> Cl1 = ifourier(An,Bn, t, An.size(), omega ) );
    codeend();
    cr();

    
    text("The results `r` and `y` are:");
    cr();
    codestart("Matlab");
    disp(t);
    disp(Cl1);
    codeend();

    text("Cut and paste the above data for r and y into Matlab as well as the following commands");
    cr();
    codestart("Matlab");
    codeend();

    text("This yields the following plot comparing the Taylor series [red dots] to the exact function [solid blue].");

    text("![Taylor Series for Jo(r)](BesselTaylorSeries.png)");

  }


  matricks_toc();

  
  return 0;
}
