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
  mdtitle0("Calculating a Taylor series and plotting the results in Mathematica");
  matricks_preamble();

  header2("Taylor Series for the Bessel Function J<sub>0</sub>(r)");
  text("We can easily calculate a [Taylor Series](http://mathworld.wolfram.com/TaylorSeries.html) in matricks. As an example, let's calculate the Taylor series for the [Bessel Function of the first kind](http://mathworld.wolfram.com/BesselFunctionoftheFirstKind.html) of order 0, J<sub>0</sub>(r). ");

  text("The first 20 (n=0,1,...19) coefficients for  J<sub>0</sub>(r), are:\n");


  {  
    set_mathematica_var_format();
  Vector<double> J0Coeffs =  Vector<double>({1.,0.,-0.25,0.,0.015625,0.,-0.000434028,0.,6.78168e-6,0.,-6.78168e-8,0.,4.7095e-10,0.,-2.40281e-12,0.,9.38597e-15,0.,-2.8969e-17,0.});

    codestart("C++");
    disp(J0Coeffs);
    codeend();
  
  }
  text("These were determined using the following `Mathematica` command");
  cr();

  codestart("Mathematica");
  text("N[Table[SeriesCoefficient[BesselJ[0,r],{r,0,n}],{n,0,19}]]");
  cr();
  codeend();
  
  {
    cr();
    cr();
    text("Set up the output format so that we can copy and paste into Mathematica");
    codestart("C++");
    codemulti( using namespace display  );
    codemulti( FormatDataVector::string_opening =  "{\n    "  );
    codemulti( FormatDataVector::string_delimeter = ", "  );
    codemulti( FormatDataVector::max_elements_per_line = 5  );
    codemulti( FormatDataVector::string_endofline = "\n    "  );
    codemulti( FormatDataVector::string_closing =   "\n}"  );
    codemulti( setFormatString<double>("% 10.8e")  );
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

    text("![Taylor Series for Jo(r)](BesselTaylorSeries.png)");

  }

  
  header2("Maclaurin Series for the Bessel Function J<sub>0</sub>(x)");

  text("To acheive better accuracy, we can calculate the [Maclaurin Series](http://mathworld.wolfram.com/MaclaurinSeries.html) at the point `r=5`, which is the center of our interval of interest.");
  text("The first 20 (n=0,1,...19) coefficients for the Maclaurin Series (r<sub>0</sub>=5) for the function J<sub>0</sub>(r), are:\n");


  {  
    set_mathematica_var_format();
    Vector<double> J0Coeffs =  Vector<double>({-0.177597,0.327579,0.0560405,-0.0561487,-0.00170739,0.00252021,0.0000112022,-0.000053795,2.1333e-7,6.7811e-7,-4.88572e-9,-5.6642e-9,4.80096e-11,3.37094e-11,-2.99711e-13,-1.50298e-13,1.33856e-15,5.20979e-16,-4.54744e-18,-1.44449e-18});

    codestart("C++");
    disp(J0Coeffs);
    codeend();
  
  }
  text("These were determined using the following `Mathematica` command");
  cr();

  codestart("Mathematica");
  text("N[Table[SeriesCoefficient[BesselJ[0,r],{r,5,n}],{n,0,19}]]");
  cr();
  codeend();
  
  {
    cr();
    cr();
    text("Set up the output format so that we can copy and paste into Mathematica, this time using the function `set_mathematica_var_format`");
    codestart("C++");
    codemulti( set_mathematica_var_format()  );
    codeend();
    cr();

   

    text("Define the Vector of coefficients: ");
    cr();

    codestart("C++");
    codemulti( Vector<double> J0Coeffs =  Vector<double>( {-0.177597,0.327579,0.0560405,-0.0561487,-0.00170739,0.00252021,0.0000112022,-0.000053795,2.1333e-7,6.7811e-7,-4.88572e-9,-5.6642e-9,4.80096e-11,3.37094e-11,-2.99711e-13,-1.50298e-13,1.33856e-15,5.20979e-16,-4.54744e-18,-1.44449e-18})  );
    codeend();
    cr();


    text("Define the coordinate vector `r` as 101 points over the interval [0,10]: ");
    cr();
    
    codestart("C++");
    codemulti( Vector<double> r = linspace<double>(0,10,101)  );
    codeend();
    cr();

    text("Calculate the Maclaurin series and store the results in vector `y`: ");
    cr();
    codestart("C++");
    codemulti( Vector<double> y = maclaurin(J0Coeffs, r, 19, 5.)  );
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

    text("This yields the following plot comparing the Maclaurin series [red dots] to the exact function [solid blue].");

    text("![Maclaurin Series for Jo(x)](BesselMaclaurinSeries.png)");

  }
  matricks_toc();
  
  return 0;
}
