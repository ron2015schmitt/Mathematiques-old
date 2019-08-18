#define MATRICKS_DEBUG


#include "matricks.hpp"
using namespace Matricks;

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif


std::string  replaceAll(std::string  s, std::string s1, std::string s2) {
  size_t pos = s.find(s1);
  while( pos != std::string::npos) {
    s.replace(pos, s1.size(), s2);
    pos = s.find(s1, pos + s2.size());
  }
  return s;
}






template <class D>
D pos(D x) {
  return (x>=0) ? x : 0;
}

char pos_str[] = " \
template <class D> \n\
D pos(D x) {\n\
  return (x>=0) ? x : 0;\n\
}";



int main()
{

  int Nex = 1;


    
  cr();
  mdtitle("Applying User-defined functions");
  matricks_preamble();


  text("As an example, consider the following user-defined function `pos`, which forces negative values to zero.  Mathematically this is x*u(x), where u(x) is the (_Heaviside_) unit step function. ");

  cr();
  codestart("C++");
  text(pos_str);
  codeend();

  cr();
  resultstart2(": `pos` function");
  resultmulti( pos(-5)  );
  resultmulti( pos(5)  );
  resultend();

  cr();
  header3("Applying User-defined functions using `op1`");
  {
    cr();
    text("* The simplest way to apply a user-defined function is to use the function `op1<D,funcname>(Vector<D> v)`.");
    text("* This form can be used in `Vector` expressions");
    example(Nex++,"Applying User-defined function `pos` using `op1`");
    codestart("C++");
    codemulti(using namespace std );
    codemulti( Vector<double> v1(linspace<double>(-1,1,11) ) );
    codemulti( Vector<int> v2(range<int>(-1,0,1))  );
    codeend();
    cr();
    resultstart();
    resultmulti( op1<double,pos>(v1)  );
    resultmulti( op1<int,pos>(v2)  );
    resultmulti( 2*v1 + op1<double,pos>( 2.3*sin(M_PI*v1) ) );
    resultend();
  }
	    
  header3("Applying User-defined functions using the `valarray` inside");
  text("Since ");
 
  {
  codestart("C++");
  codemulti(struct X {static double increment (double x) {return (x+1);}});
  codemulti( Vector<double> v1(CARRAY({1,2,3,4}) ) ) ;
  codemulti( Vector<double> v2 );
  codemulti( v2 = v1.getValArray().apply(X::increment) );
  codeend();
  resultstart();
  resultmulti( v1  );
  resultmulti( v2  );
  resultmulti( sin(v1)  );
  //  resultmulti( f<incr>(v2)  );

  resultend();
  cr();
  }
  

  matricks_toc();


  return 0;
}
