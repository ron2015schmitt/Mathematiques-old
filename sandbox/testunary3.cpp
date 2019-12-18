
//#define MATHQ_DEBUG

#include "mathq.h" 

#include <fstream>


int main(int argc, char *argv[])
{

  const double pi = M_PI;
  std::string myname = argv[0];

  using namespace std;
  using namespace mathq;
  using namespace display;
  using namespace mathq::unit_imaginary;

  Style bold = createStyle(BOLD);
  Style blue = createStyle(BOLD+BLUE2);
  
  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  FormatData<bool>::string_for_true = "true";
  FormatData<bool>::string_for_false = "false";
  

  cr();
  cr();
  mout << StyledString::get(HORLINE);
  mout << "running: " <<bold.apply(myname) << std::endl;

  
  mout<< "MATHQ_DEBUG=" << MATHQ_DEBUG << std::endl;
  
  print_mathq_info();


  cr();
  mout << StyledString::get(HORLINE);cr();
  //------------------------------------------------------

  cr();
  cr();
  mout << bold.apply("scalar") << endl;
  {
    cr();
    double x = 0.25;
    tdisp(x);
    tdisp(+x);
    tdisp(+(x));
    tdisp(-x);
    tdisp(std::real(x));
    tdisp(std::imag(x));
    tdisp(std::conj(x));
    tdisp(mathq::conj(x));
    tdisp(mathq::zero(x));
    
    Imaginary<double> y(2);
    tdisp(y);
    tdisp(mathq::real(y));
    tdisp(mathq::imag(y));
    tdisp(mathq::conj(y));


    std::complex<double> z(1,2);
    tdisp(z);
    tdisp(std::real(z));
    tdisp(std::imag(z));
    tdisp(std::conj(z));
    tdisp(mathq::conj(z));
    
  }

  
  cr();
  cr();
  mout << bold.apply("Scalar") << endl;
  {

    cr();
    Scalar<bool> sb = true;
    tdisp(sb);
    tdisp(!sb);
    tdisp(operator!(sb));

    
    cr();
    Scalar<double> sr = 0.25;
    double x = sr();
    tdisp(sr);
    tdisp(+sr);
    tdisp(-sr);
    tdisp(sin(sr));
    // tdisp(exp(sr));
    
    // tdisp(std::expint(x));  
    // tdisp(expint(sr));  

    // tdisp(std::comp_ellint_1(x));  
    // tdisp(comp_ellint_1(sr));  

    // tdisp(std::comp_ellint_2(x));  
    // tdisp(comp_ellint_2(sr));  


    // double k = 0.1;
    // double q = 0.1;
    // // tdisp(std::comp_ellint_3(k,q,x));  
    // // tdisp(comp_ellint_3(k,q,sr)); 
    

    // tdisp(std::ellint_1(k,x));  
    // tdisp(ellint_1(k,sr));  

    // tdisp(std::ellint_2(k,x));  
    // tdisp(ellint_2(k,sr));  



    // tdisp(std::legendre(2,x));  
    // tdisp(legendre(2,sr));  

    // tdisp(std::laguerre(2,x));  
    // tdisp(laguerre(2,sr));  

    // tdisp(std::hermite(4,x));  
    // tdisp(hermite(4,sr));  

    


    cr();
    typename NumberType<Imaginary<double>>::Type ww;
    tdisp(ww);


    Scalar<Imaginary<double>> si;
    si() = Imaginary<double>(3);


    cr();
    mout << blue.apply("Real Scalar") << endl;
    tdisp(sr);
    tdisp(-sr);
    tdisp(conj(sr));
    tdisp(real(sr));
    tdisp(imag(sr));

    cr();
    mout << blue.apply("Imag Scalar") << endl;
    tdisp(si);
    tdisp(-si);
    tdisp(conj(si));
    tdisp(real(si));
    tdisp(imag(si));

    cr();
    mout << blue.apply("Complex Scalar") << endl;
    Scalar<ComplexDouble> sc {ComplexDouble(1,2)};
    tdisp(sc);
    tdisp(-sc);
    tdisp(conj(sc));
    tdisp(real(sc));
    tdisp(imag(sc));

    cr();
    cr();
    typename Realify<Scalar<double>>::Type qr;
    tdisp(qr);

    typename Realify<Scalar<Imaginary<double>> >::Type qi;
    tdisp(qi);
    
    typename Realify<Scalar<std::complex<double>> >::Type qc;
    tdisp(qc);
  }

  return 0;
  
  cr();
  cr();
  mout << bold.apply("Vector") << endl;
  {
    cr();
    Vector<double> v {1.1,2.2};
    tdisp(v);
    tdisp(-v);
    tdisp(sin(v));
    //   tdisp(exp(v));
  //   tdisp(expint(v));  // C++17 special function
    
  }

   cr();
   cr();
   mout << bold.apply("Matrix") << endl;
   {
     Matrix<double> m {{1,2},{3,4}};
     tdisp(m);
     tdisp(-m);
     tdisp(sin(m));
  //   tdisp(exp(m));
  //   tdisp(expint(m));  // C++17 special function
   }


   cr();
   cr();
   mout << bold.apply("Tensor") << endl;
   {
     cr();
     Tensor<double,3> t {
       {{0, 1, 2, 3, 4},{10, 11, 12, 13, 14}},
     	{{100, 101, 102, 103, 104},{110, 111, 112, 113, 114}},
     	  {{200, 201, 202, 203, 204},{210, 211, 212, 213, 214}  } };
    
     tdisp(t);
     tdisp(-t);
     tdisp(sin(t));
  //   tdisp(exp(t));
  //   tdisp(expint(t));  // C++17 special function
   }



   cr();
   cr();
   cr();
   cr();


  mout << blue.apply("Two-level tests") << endl;
  

  // // -------------------------------------------------
  // // two level tests
  // // -------------------------------------------------

  cr();
  cr();
  mout << bold.apply("Two-Level Scalar tests") << endl;

  cr();
  cr();
  mout << bold.apply("Scalar") << endl;
  {
    cr();
    
    cr();
    Scalar<Scalar<bool>> sb = true;
    tdisp(sb);
    tdisp(!sb);

    Scalar<Scalar<double>> sr = {{1.1}};
    tdisp(sr);
    tdisp(-sr);
    tdisp(sin(sr));
    // tdisp(exp(sr));
    // tdisp(expint(sr));  // C++17 special function
    //    tdisp(conj(sr));


    Scalar<Scalar<ComplexDouble>> sc {{ComplexDouble(1,2)}};


    Scalar<Scalar<Imaginary<double>>> si;
    si()() = Imaginary<double>(3);

    cr();
    typename NumberType<Imaginary<double>>::Type ww;
    tdisp(ww);

    cr();
    mout << blue.apply("Real Scalar") << endl;
    tdisp(sr);
    tdisp(-sr);
    // tdisp(conj(sr));
    // tdisp(real(sr));
    // tdisp(imag(sr));

    cr();
    mout << blue.apply("Imag Scalar") << endl;
    tdisp(si);
    tdisp(-si);
    // tdisp(conj(si));
    // tdisp(real(si));
    // tdisp(imag(si));

    cr();
    mout << blue.apply("Complex Scalar") << endl;
    tdisp(sc);
    tdisp(-sc);
    // tdisp(conj(sc));
    // tdisp(real(sc));
    // tdisp(imag(sc));

    cr();
    cr();

    typename Realify<Scalar<Scalar<double>>>::Type qr;
    tdisp(qr);

    typename Realify<Scalar<Scalar<Imaginary<double>>>>::Type qi;
    tdisp(qi);
    
    typename Realify<Scalar<Scalar<std::complex<double>>>>::Type qc;
    tdisp(qc);
  }


  // {
  //   cr();
  //   Scalar<Scalar<double>> s {{1.1}};
  //   tdisp(s);
  //   tdisp(sin(s));
  //   tdisp(beta(s));
  //   tdisp(exp(s));
  //   tdisp(cyl_bessel_j(s));
  // }
  // {
  //   cr();
  //   Scalar<Vector<double>> s {{1.,2.,3.}};
  //   tdisp(s);
  //   tdisp(sin(s));
  //   tdisp(beta(s));
  //   tdisp(exp(s));
  //   tdisp(cyl_bessel_j(s));
  // }
  // {   
  //   cr();
  //   Scalar<Matrix<double>> s {{{1,2},{3,4}}};
  //   tdisp(s);
  //   tdisp(sin(s));
  //   tdisp(beta(s));
  //   tdisp(exp(s));
  //   tdisp(cyl_bessel_j(s));

  // }

  // {   
  //   cr();
  //   Scalar<Tensor<double,2>> s {{{1,2},{3,4}}};
  //   tdisp(s);
  //   tdisp(sin(s));
  //   tdisp(beta(s));
  //   tdisp(exp(s));
  //   tdisp(cyl_bessel_j(s));
  // }

  // cr();
  // cr();
  // mout << bold.apply("Two-Level Vector tests") << endl;
  // {
  //   cr();
  //   Vector<Scalar<double>> v {{1.},{2.}};
  //   tdisp(v);
  //   tdisp(sin(v));
  //   tdisp(beta(v));
  //   tdisp(exp(v));
  //   tdisp(cyl_bessel_j(v));
  // }

  // {
  //   cr();
  //   Vector<Vector<double>> v {{1.,2.,3.},{4.,5.,6.}};
  //   tdisp(v);
  //   tdisp(sin(v));
  //   tdisp(beta(v));
  //   tdisp(exp(v));
  //   tdisp(cyl_bessel_j(v));
  // }
  // {
  //   cr();
  //   Vector<Matrix<double>> v { {{1,2},{3,4}}, {{5,6},{7,8}}, {{9,10},{11,12}} };
  //   tdisp(v);
  //   tdisp(sin(v));
  //   tdisp(beta(v));
  //   tdisp(exp(v));
  //   tdisp(cyl_bessel_j(v));
  // }
  // {
  //   cr();
  //   Vector<Tensor<double,2>> v { {{1,2},{3,4}}, {{5,6},{7,8}}, {{9,10},{11,12}} };
  //   tdisp(v);
  //   tdisp(sin(v));
  //   tdisp(beta(v));
  //   tdisp(exp(v));
  //   tdisp(cyl_bessel_j(v));
  // }


  // cr();
  // cr();
  // mout << bold.apply("Two-Level Matrix tests") << endl;
  // {
  //   cr();
  //   Matrix<Scalar<double>> m {{{1},{2}},{{3},{4}}};;
  //   tdisp(m);
  //   tdisp(sin(m));
  //   tdisp(beta(m));
  //   tdisp(exp(m));
  //   tdisp(cyl_bessel_j(m));
  // }

  // {
  //   cr();
  //   Matrix<Vector<double>> m {{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
  //   tdisp(m);
  //   tdisp(sin(m));
  //   tdisp(beta(m));
  //   tdisp(exp(m));
  //   tdisp(cyl_bessel_j(m));
  // }

  // {
  //   cr();
  //   Matrix<Matrix<double>> m  {
  //     { {{1,2},{3,4}}, {{5,6},{7,8}} },
  // 	{ {{9,10},{11,12}}, {{13,14},{15,16}} }
  //   };
  //   tdisp(m);
  //   tdisp(sin(m));
  //   tdisp(beta(m));
  //   tdisp(exp(m));
  //   tdisp(cyl_bessel_j(m));
  // }

  // {
  //   cr();
  //   Matrix<Tensor<double,3>,2,2> m { {
  // 	{
  // 	  {
  // 	    {-0, -1},
  // 	      {-10, -11},
  // 		{-20, -21}
  // 	  },
  // 	    {
  // 	      {-100, -101},
  // 		{-110, -111},
  // 		  {-120, -121}
  // 	    }
  // 	}, 
  // 	  {
  // 	    {
  // 	      {-1000, -1001},
  // 		{-1010, -1011},
  // 		  {-1020, -1021}
  // 	    },
  // 	      {
  // 		{-1100, -1101},
  // 		  {-1110, -1111},
  // 		    {-1120, -1121}
  // 	      }
  // 	  }}, {
  // 	{
  // 	  {
  // 	    {-10000, -10001},
  // 	      {-10010, -10011},
  // 		{-10020, -10021}
  // 	  },
  // 	    {
  // 	      {-10100, -10101},
  // 		{-10110, -10111},
  // 		  {-10120, -10121}
  // 	    }
  // 	}, 
  // 	  {
  // 	    {
  // 	      {-11000, -11001},
  // 		{-11010, -11011},
  // 		  {-11020, -11021}
  // 	    },
  // 	      {
  // 		{-11100, -11101},
  // 		  {-11110, -11111},
  // 		    {-11120, -11121}
  // 	      }
  // 	  }} };

  //   tdisp(m);
  //   tdisp(sin(m));
  //   tdisp(beta(m));
  //   tdisp(exp(m));
  //   tdisp(cyl_bessel_j(m));
    
  // }

  // /////////////////////////////////////////////////////////////////


  
  // cr();
  // cr();
  // mout << bold.apply("Two-Level Tensor tests") << endl;
  // {    
  //   cr();
  //   Tensor<Scalar<double>,2> t {{{1},{2}},{{3},{4}}};
  //   tdisp(t);
  //   tdisp(sin(t));
  //   tdisp(beta(t));
  //   tdisp(exp(t));
  //   tdisp(cyl_bessel_j(t));
  // }
  // {
  //   cr();
  //   Tensor<Vector<double>,2> t {{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
  //   tdisp(t);
  //   tdisp(sin(t));
  //   tdisp(beta(t));
  //   tdisp(exp(t));
  //   tdisp(cyl_bessel_j(t));
  // }

  // {
  //   cr();
  //   Tensor<Matrix<double,2,2>,2> t  {
  //     { {{1,2},{3,4}}, {{5,6},{7,8}} },
  // 	{ {{9,10},{11,12}}, {{13,14},{15,16}} }
  //   };
  //   tdisp(t);
  //   tdisp(sin(t));
  //   tdisp(beta(t));
  //   tdisp(exp(t));
  //   tdisp(cyl_bessel_j(t));
  // }


  // {
  //   cr();
  //   Tensor<Tensor<double,3>,2> t { {
  // 	{
  // 	  {
  // 	    {0, 1},
  // 	      {10, 11},
  // 		{20, 21}
  // 	  },
  // 	    {
  // 	      {100, 101},
  // 		{110, 111},
  // 		  {120, 121}
  // 	    }
  // 	}, 
  // 	  {
  // 	    {
  // 	      {1000, 1001},
  // 		{1010, 1011},
  // 		  {1020, 1021}
  // 	    },
  // 	      {
  // 		{1100, 1101},
  // 		  {1110, 1111},
  // 		    {1120, 1121}
  // 	      }
  // 	  }}, {
  // 	{
  // 	  {
  // 	    {10000, 10001},
  // 	      {10010, 10011},
  // 		{10020, 10021}
  // 	  },
  // 	    {
  // 	      {10100, 10101},
  // 		{10110, 10111},
  // 		  {10120, 10121}
  // 	    }
  // 	}, 
  // 	  {
  // 	    {
  // 	      {11000, 11001},
  // 		{11010, 11011},
  // 		  {11020, 11021}
  // 	    },
  // 	      {
  // 		{11100, 11101},
  // 		  {11110, 11111},
  // 		    {11120, 11121}
  // 	      }
  // 	  }} };

  //   tdisp(t);
  //   tdisp(sin(t));
  //   tdisp(beta(t));
  //   tdisp(exp(t));
  //   tdisp(cyl_bessel_j(t));
    
  // }

  


  
  
  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  
  return 0;
}
