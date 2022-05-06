#define MATHQ_DEBUG 1


#include "mathq.h"

#include <iostream>
#include <string>
#include <tgmath.h>
// used to demonstrate how to convert to C++ vectors
#include <vector>






template <class D>
D pos(D x) {
  return ((x>=0) ? x : 0);
}

double poly(double x, double y) {
  return 5*x - 3*y*y*y;
}

char pos_str[] = "\
template <class D> \n\
D pos(D x) {\n\
  return (x>=0) ? x : 0;\n\
}";

char poly_str[] = "\
double poly(double x, double y) { \n\
  return 5*x - 3*y*y*y;\n\
}";







int main()
{
  using namespace mathq;
  using namespace std;
  using namespace display;
  

  int Nex = 1;


    
  mathq_toc();
  CR();CR();
  mdtitle("Applying User-defined functions");
  mathq_preamble();


  text("As an example, consider the following user-defined function `pos`, which forces negative values to zero.  Mathematically this is x*u(x), where u(x) is the (_Heaviside_) unit step function. ");

  {
    CR();
    codestart("C++");
    text(pos_str);
    codeend();

    CR();
    resultstart2(": `pos` function");
    CR();
    resultmulti( pos(-5)  );
    resultmulti( pos(5)  );
    resultend();
  }

  CR();
  header3("Applying User-defined functions via `op1`");
  {
    CR();
    text("* The simplest way to apply a user-defined function is to use the function `op1<D,funcname>(Vector<D> v)`.");
    text("* This form can be used in `Vector` expressions");
    CR();
    EXAMPLE(Nex++,"Applying User-defined function `pos` via `op1`");
    CR();
    codestart("C++");
    codemulti(using namespace std );
    codemulti( Vector<double> v1(linspace<double>(-1,1,11) ) );
    codemulti( Vector<int> v2(range<int>(-2,2))  );
    codeend();
    CR();
    resultstart2(": Applying User-defined function `pos` via `op1`");
    resultmulti( op1(pos<double>,v1)  );
    resultmulti( op1(pos<int>,v2)  );
    resultmulti( 2*v1 + op1(pos<double>, 2.3*sin(M_PI*v1) ) );
    resultend();
  }
	    
  CR();
  header3("Applying User-defined binary functions via `op2`");
  {
    CR();
    text("* A similar function exists for binary user-defined functions: `op2<D,funcname>(Vector<D> v1, Vector<D> v2)`.");
    text("* This form can be used in `Vector` expressions as well.");
    CR();
    EXAMPLE(Nex++,"Applying a function `ploy` via `op2`");
    CR();

    codestart("C++");
    text(poly_str);
    codemulti( Vector<double> v1(linspace<double>(-1,1,11) ) );
    codemulti( Vector<double> v2(11,0.25) );
    codeend();
    CR();
    resultstart();
    resultmulti( v1  );
    resultmulti( v2  );
    resultmulti( op2(poly,v1,v2) );
    resultend();
  }
	    

  
  mathq_toc();
  return 0;
}
