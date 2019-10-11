#define MATRICKS_DEBUG 1


#include "matricks.h"
#include "gitmd.h"

#include <iostream>
#include <string>
#include <tgmath.h>
// used to demonstrate how to convert to C++ vectors
#include <vector>






namespace test {
template <class D>
D pos(D x) {
  return ((x>=0) ? x : 0);
}
};

char pos_str[] = "\
template <class D> \n\
D pos(D x) {\n\
  return (x>=0) ? x : 0;\n\
}";



namespace matricks {

  template <class D> class Fun_Pos {
  public:
    Fun_Pos() { }

    static inline D apply(D a) { 
      return (a>=0) ? a : 0; 
    }

    static std::string expression( const std::string& sa) {
      std::string sout = "pos(" + sa + ")";
      return sout;
    }

    static std::string classname( const std::string& sa) {
      std::string sout = "pos(" + sa + ")";
      return sout;
    }

  };


  template <class D, class A> 
  inline TER_Unary<D,TensorR<D,A>,Fun_Pos<D> > 
  pos(const TensorR<D,A>& a)
  {
    return  TER_Unary<D,TensorR<D,A>,Fun_Pos<D> >(a);
  }

}


char matrickspos_str[] = "\
namespace matricks { \n\
  template <class D> class Fun_Pos {\n\
  public:\n\
    Fun_Pos() { }\n\
\n\
    static inline D apply(D a) { \n\
      return (a>=0) ? a : 0; \n\
    }\n\
\n\
    static std::string expression( const std::string& sa) {\n\
      std::string sout = pos(\" + sa + \")\";\n\
      return sout;\n\
    }\n\
\n\
    static std::string classname( const std::string& sa) {\n\
      std::string sout = \"pos(\" + sa + \")\";\n\
      return sout;\n\
    }\n\
\n\
  };\n\
\n\
  template <class D, class A> \n\
  inline TER_Unary<D,TensorR<D,A>,Fun_Pos<D> > \n\
  pos(const TensorR<D,A>& a)\n\
  {\n\
    return  TER_Unary<D,TensorR<D,A>,Fun_Pos<D> >(a);\n\
  }\n\
};\n";




int main()
{
  using namespace matricks;
  using namespace std;
  using namespace display;
  using namespace md;

  int Nex = 1;


    
  matricks_toc();
  cr();cr();
  mdtitle("Applying User-defined functions");
  matricks_preamble();


  text("As an example, consider the following user-defined function `pos`, which forces negative values to zero.  Mathematically this is x*u(x), where u(x) is the (_Heaviside_) unit step function. ");

  {
    cr();
    codestart("C++");
    text(pos_str);
    codeend();

    cr();
    using namespace test;
    resultstart2(": `pos` function");
    cr();
    resultmulti( pos(-5)  );
    resultmulti( pos(5)  );
    resultend();
  }

  cr();
  header3("Applying User-defined functions via `op1`");
  {
    cr();
    text("* The simplest way to apply a user-defined function is to use the function `op1<D,funcname>(Vector<D> v)`.");
    text("* This form can be used in `Vector` expressions");
    cr();
    example(Nex++,"Applying User-defined function `pos` via `op1`");
    cr();
    codestart("C++");
    codemulti(using namespace std );
    codemulti( Vector<double> v1(linspace<double>(-1,1,11) ) );
    codemulti( Vector<int> v2(range<int>(-2,2))  );
    codeend();
    cr();
    using namespace test;
    resultstart2(": Applying User-defined function `pos` via `op1`");
    resultmulti( op1<double,pos>(v1)  );
    resultmulti( op1<int,pos>(v2)  );
    resultmulti( 2*v1 + op1<double,pos>( 2.3*sin(M_PI*v1) ) );
    resultend();
  }
	    
  cr();
  header3("Applying User-defined binary functions via `op2`");
  {
    cr();
    text("* A similar function exists for binary user-defined functions: `op2<D,funcname>(Vector<D> v1, Vector<D> v2)`.");
    text("* This form can be used in `Vector` expressions as well.");
    cr();
    example(Nex++,"Applying `stdlib` function `fmax` via `op2`");
    codestart("C++");
    codemulti(using namespace std );
    codemulti( Vector<double> v1(linspace<double>(-1,1,11) ) );
    codemulti( Vector<double> v2(11,0.25) );
    codeend();
    cr();
    using namespace test;
    resultstart();
    resultmulti( v1  );
    resultmulti( v2  );
    resultmulti( op2<double,fmax>(v1,v2) );
    resultend();
  }
	    

  header3("Applying User-defined functions using the `valarray` inside");
  text("* Another technique is to use method `getValArray()` and `std::valarray.apply(func)`");
 
  {
    cr();
    example(Nex++,"Applying User-defined function `pos` via `valarray` access");
    codestart("C++");
    codemulti(using namespace std );
    using namespace test;
    codemulti( Vector<double> v1(linspace<double>(-1,1,11) ) );
    codemulti( Vector<double> v2  );
    codemulti( v2 = v1.getValArray().apply(pos) );
    codeend();
    cr();
    resultstart();
    resultmulti( v1  );
    resultmulti( v2  );
    resultend();
    cr();
  }
  
 
  cr();
  header3("Creating new mātricks functions--Under the hood of mātricks");
  {
    cr();
    text("User-defined function can be bound into the `matricks` namespace as vector functions.");
    cr();
    text("place the following code in your file:");
    codestart("C++");
    text(matrickspos_str);
    codeend();
    example(Nex++,"Applying User-defined function `pos`");
    codestart("C++");
    codemulti(using namespace std );
    codemulti( Vector<double> v1(linspace<double>(-1,1,11) ) );
    codemulti( Vector<int> v2(range<int>(-2,2))  );
    codeend();
    cr();
    resultstart2(": Applying User-defined bound-in function `pos` ");
    resultmulti( pos(v1)  );
    resultmulti( pos(v2)  );
    resultmulti( 2*v1 + pos( 2.3*sin(M_PI*v1) ) );
    resultend();
  }
	    

  
  matricks_toc();
  return 0;
}
