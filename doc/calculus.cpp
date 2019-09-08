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

  header3("Integration");
  text("");


  {
    cr();
    cr();
    example(Nex++,"Integration");
    codestart("C++");
    codemulti( const size_type N = 100000 );
    codemulti( const double a = 0 + 1/double(N) );
    codemulti( const double b = 1 - 1/double(N) );
    codemulti( Vector<double> x(linspace<double>(a,b,N-1)) );
    codemulti( Vector<double> f; );
    codemulti( f=-log(log(1/x)) );
    codeend();
    cr();

   
    text("Integrating f(x) yields the [Euler–Mascheroni](http://mathworld.wolfram.com/Euler-MascheroniConstant.html) constant whose exact value is `0.577215664901532...`.  The function _f_(_x_) is singular at both x=0 and x=1.  Thus we omitted these points. As the results show, this simple approach to the integral isn't particularly accurate. ");
    cr();
    text(" [!Euler–Mascheron Integral](EulerMascheroniConstant.PNG)");
    cr();
    resultstart2("");
    resultmulti( N );
    resultmulti( a );
    resultmulti( 1-b );
    resultmulti( integrate_a2b(f,a,b,0) );
    resultmulti( integrate_a2b(f,a,b,1) );
    resultmulti( integrate_a2b(f,a,b,2) );
    resultend();
  }



  {
    cr();
    cr();
    example(Nex++,"Differentiation");
    codestart("C++");
    codemulti( Vector<double> v1(5) );
    codeend();
    cr();

   
    resultstart2("");
    resultend();
  }

  {
    cr();
    cr();
    example(Nex++,"Various functions: `cumsum`, `cumprod`, `cumtrapz`, `diff`, etc");
    codestart("C++");
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

  matricks_toc();


  return 0;
}
