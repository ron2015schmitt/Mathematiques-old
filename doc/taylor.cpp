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
  mdtitle("Calculating a Taylor series and plotting the results in Mathematica");
  matricks_preamble();

  header2("Taylor Series for the Bessel Function J<sub>0</sub>(x)");
  text("The first 20 (n=0,1,...19) coefficients for the [Bessel Function of the first kind](http://mathworld.wolfram.com/BesselFunctionoftheFirstKind.html) of order 0, J<sub>0</sub>(x) are:\n");


  {  
    using namespace display;
    FormatDataVector::string_opening =  "{\n    ";
    FormatDataVector::string_delimeter = ", ";
    FormatDataVector::max_elements_per_line = 5;
    FormatDataVector::string_endofline = "\n    ";
    FormatDataVector::string_closing =   "\n}";
    setFormatString<double>("% 10.6e");
    Vector<double> J0Coeffs =  Vector<double>({1.,0.,-0.25,0.,0.015625,0.,-0.000434028,0.,6.78168e-6,0.,-6.78168e-8,0.,4.7095e-10,0.,-2.40281e-12,0.,9.38597e-15,0.,-2.8969e-17,0.});

    codestart("C++");
    disp(J0Coeffs);
    codeend();
  
  }
  text("These were determined using the `Mathematica` command");
  cr();

  codestart("Mathematica");
  text("N[Table[SeriesCoefficient[BesselJ[0,x],{x,0,n}],{n,0,19}]]");
  cr();
  codeend();
  
  {
    cr();
    cr();
    text("Set up the output format so that we can copy and paste into Mathematica");
    codestart("C++");
    codemulti(  );
    codemulti( using namespace display  );
    codemulti( FormatDataVector::string_opening =  "{\n    "  );
    codemulti( FormatDataVector::string_delimeter = ", "  );
    codemulti( FormatDataVector::max_elements_per_line = 5  );
    codemulti( FormatDataVector::string_endofline = "\n    "  );
    codemulti( FormatDataVector::string_closing =   "\n}"  );
    codemulti( setFormatString<double>("% 10.6e")  );
    codemulti(  FormatData<double>::tens = true );
    codeend();
    cr();

   

    text("Define the Vector of coefficients: ");
    cr();

    codestart("C++");
    codemulti( Vector<double> J0Coeffs =  Vector<double>({1.,0.,-0.25,0.,0.015625,0.,-0.000434028,0.,6.78168e-6,0.,-6.78168e-8,0.,4.7095e-10,0.,-2.40281e-12,0.,9.38597e-15,0.,-2.8969e-17,0.})  );
    codeend();
    cr();


    text("Define the coordinate vector `r` as 101 points over the interval [0,10]: ");
    cr();
    
    codestart("C++");
    codemulti( Vector<double> r = linspace<double>(0,10,101)  );
    codeend();
    cr();

    text("Calculate the Taylor series and store the results in vector `y`: ");
    cr();
    codestart("C++");
    codemulti( Vector<double> y = taylor(J0Coeffs, r, 19)  );
    codeend();
    cr();

    
    text("The results `r` and `y` are:");
    cr();
    codestart("Mathematica");
    disp(r);
    disp(y);
    codeend();

    text("Cut and paste the above data for r and y into Mathematica as well as the following commands");
    cr();
    codestart("Mathematica");
    text("p1=ListPlot[Partition[Riffle[r,y],2],PlotStyle->Red];");
    text("p2=Plot[BesselJ[0,r],{r,0,10}];");
    text("Show[p1,p2]");
    codeend();

    text("This yields the following plot comparing the Taylor series [red dots] to the exact function [solid blue].");

    text("![Taylor Series for Jo(x)](BesselTaylorSeries.png)");

  }

  matricks_toc();

  return 0;
}
