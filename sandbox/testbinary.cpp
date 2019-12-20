
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
  mout << bold.apply("Scalar") << endl;
  {

    bool a = true;
    tdisp(std::is_arithmetic<bool>::value);
    tdisp(NumberType<double>::value);
    tdisp(NumberType<std::complex<float>>::value);
    tdisp(NumberType<Imaginary<long double>>::value);
    tdisp(NumberType<Scalar<double>>::value);
    
    cr();
    mout << blue.apply("Boolean Scalar") << endl;

    cr();
    Scalar<bool> sb1 = true;
    Scalar<bool> sb2 = false;
    tdisp(sb1);
    tdisp(sb2);
    //    tdisp(sb1 && sb2);
    
  }

  {
    cr();
    mout << blue.apply("Scalar<double>") << endl;

    Scalar<double> sr1 = 0.25;
    Scalar<double> sr2 = 0.2;
    tdisp(sr1);
    tdisp(sr2);
    tdisp(sr1+sr2);
    tdisp(sr1+3.);
    tdisp(1.+sr1);
  }
  {
    cr();
    mout << blue.apply("Scalar<float>, Scalar<long double>") << endl;

    Scalar<float> sr1 = 0.25;
    Scalar<long double> sr2 = 0.2;
    tdisp(sr1);
    tdisp(sr2);
    tdisp(sr1+sr2);
    tdisp(sr1+3);
    tdisp(2+sr1);
  }
  {
    cr();
    mout << blue.apply("Imag Scalar") << endl;
    Scalar<Imaginary<double>> si1;
    si1() = Imaginary<double>(0.25);
    Scalar<Imaginary<double>> si2 = Imaginary<double>(0.75);

    tdisp(si1);
    tdisp(si2);
    tdisp(si1+si2);
    tdisp(si1+3);
    tdisp(1+si1);
    
    cr();
    mout << blue.apply("Complex Scalar") << endl;
    Scalar<ComplexDouble> sc {ComplexDouble(0.25,0.5)};
    tdisp(sc);
  }

  cr();
  cr();
  mout << bold.apply("Vector") << endl;
  {
    cr();
    mout << bold.apply("Vector") <<" - "<<blue.apply("Real Scalar") << endl;
    cr();
    Vector<double> vr {1.1,2.2};
    tdisp(vr);
    
  }

  cr();
  cr();
  mout <<  bold.apply("Matrix") << endl;
  {
    cr();
    mout <<  bold.apply("Matrix") <<" - "<<blue.apply("Real Scalar") << endl;
    Matrix<double> mr {{1,2},{3,4}};
    tdisp(mr);
  }


  cr();
  cr();
  mout << bold.apply("Tensor") << endl;
  {
    cr();
    mout <<  bold.apply("Tensor") <<" - "<<blue.apply("Real Scalar") << endl;
    cr();
    Tensor<double,3> tr {
      {{0, 1, 2, 3, 4},{10, 11, 12, 13, 14}},
     	{{100, 101, 102, 103, 104},{110, 111, 112, 113, 114}},
     	  {{200, 201, 202, 203, 204},{210, 211, 212, 213, 214}  } };
    
    tdisp(tr);
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
    mout << blue.apply("Boolean Scalar") << endl;
    Scalar<Scalar<bool>> sb = true;
    tdisp(sb);

    cr();
    mout << blue.apply("Real Scalar Scalar") << endl;
    Scalar<Scalar<double>> sr = {{1.1}};
    tdisp(sr);


    cr();
    mout << blue.apply("Imaginary Scalar Scalar") << endl;
    Scalar<Scalar<Imaginary<double>>> si;
    si()() = Imaginary<double>(3);
    tdisp(si);

    cr();
    mout << blue.apply("Complex Scalar") << endl;
    Scalar<Scalar<ComplexDouble>> sc {{ComplexDouble(1,2)}};
    tdisp(sc);

  }


  {
    cr();
    Scalar<Scalar<double>> s {{1.1}};
    tdisp(s);
  }
  {
    cr();
    Scalar<Vector<double>> s {{1.,2.,3.}};
    tdisp(s);
  }
  {   
    cr();
    Scalar<Matrix<double>> s {{{1,2},{3,4}}};
    tdisp(s);
  }

  {   
    cr();
    Scalar<Tensor<double,2>> s {{{1,2},{3,4}}};
    tdisp(s);
  }

  cr();
  cr();
  mout << bold.apply("Two-Level Vector tests") << endl;
  {
    cr();
    Vector<Scalar<double>> v {{1.},{2.}};
    tdisp(v);
  }

  {
    cr();
    cr();
    
    Vector<Vector<double>> v1 {{1,2,3},{4,5,6}};
    Vector<double> v0 {10,20,30};
    string s;
    mout << blue.apply("Given:") << endl;
    mout<<"  ";tdisp(v1);
    mout<<"  ";tdisp(v0);
    cr();
    mout << "By analysing the dimensions element-wise addition is chosen" << endl;
    mout<<"  ";tdisp(v1+v0);
    //    tdisp((v1+v0)[1]);
    mout<<"  ";tdisp(v0+v1);
    //    tdisp((v0+v1)[1]);

    cr();
    cr();
    Vector<double> v00 {100,200};
    mout << blue.apply("Given:") << endl;

    mout<<"  ";tdisp(v1);
    mout<<"  ";tdisp(v00);
    cr();
    mout << "By analysing the dimensions top-level addition is chosen" << endl;
    mout<<"  ";tdisp(v1+v00);
    //    tdisp((v1+v00)[1]);
    mout<<"  ";tdisp(v00+v1);
    //    tdisp((v00+v1)[1]);
  }


  cr();
    cr();
  mout << bold.apply("When dimensions and rank are the same, the result depends on order, ie non-commutative") << endl;
  {
    cr();
    Vector<Vector<double>> v1 {{1,2},{4,5}};
    tdisp(v1);
    Vector<double> v0 {10,20};
    tdisp(v0);
    cr();
    mout << "Element-wise: add v0 to each element of v1" << endl;
    tdisp(v1+v0);
    tdisp((v1+v0)[1]);
    cr();
    mout << "Top-level: add v0[0] to vector v1[0], add v0[1] to vector v1[1]" << endl;
    //    tdisp(v0+v1);
    //    tdisp((v0+v1)[1]);
    cr();
    cr();
  }

  
  {
    cr();
    Vector<Matrix<double>> v1 { {{1,2},{3,4}}, {{5,6},{7,8}}, {{9,10},{11,12}} };
    tdisp(v1);
    tdisp(v1[1]);
    Vector<double> v0 {100,200,300};
    tdisp(v0);
    tdisp(v1+v0);
    tdisp((v1+v0)[1]);
    // tdisp(v0+v1);
    // tdisp((v0+v1)[1]);
  }
  {
    cr();
    Vector<Tensor<double,2>> v { {{1,2},{3,4}}, {{5,6},{7,8}}, {{9,10},{11,12}} };
    tdisp(v);
  }


  cr();
  cr();
  mout << bold.apply("Two-Level Matrix tests") << endl;
  {
    cr();
    Matrix<Scalar<double>> m {{{1},{2}},{{3},{4}}};;
    tdisp(m);
  }

  {
    cr();
    Matrix<Vector<double>> m1 {{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
    tdisp(m1);
    tdisp(m1[0]);
    Vector<double> v0 {100,200,300};
    tdisp(v0);
    tdisp(m1+v0);
    tdisp((m1+v0)[0]);
    // tdisp(v0+m1);
    // tdisp((v0+m1)[0]);
  }
  return 0;
  {
    cr();
    Matrix<Matrix<double>> m  {
      { {{1,2},{3,4}}, {{5,6},{7,8}} },
  	{ {{9,10},{11,12}}, {{13,14},{15,16}} }
    };
    tdisp(m);
  }

  {
    cr();
    Matrix<Tensor<double,3>,2,2> m { {
  	{
  	  {
  	    {-0, -1},
  	      {-10, -11},
  		{-20, -21}
  	  },
  	    {
  	      {-100, -101},
  		{-110, -111},
  		  {-120, -121}
  	    }
  	}, 
  	  {
  	    {
  	      {-1000, -1001},
  		{-1010, -1011},
  		  {-1020, -1021}
  	    },
  	      {
  		{-1100, -1101},
  		  {-1110, -1111},
  		    {-1120, -1121}
  	      }
  	  }}, {
  	{
  	  {
  	    {-10000, -10001},
  	      {-10010, -10011},
  		{-10020, -10021}
  	  },
  	    {
  	      {-10100, -10101},
  		{-10110, -10111},
  		  {-10120, -10121}
  	    }
  	}, 
  	  {
  	    {
  	      {-11000, -11001},
  		{-11010, -11011},
  		  {-11020, -11021}
  	    },
  	      {
  		{-11100, -11101},
  		  {-11110, -11111},
  		    {-11120, -11121}
  	      }
  	  }} };

    tdisp(m);
    
  }

  
 
  
  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  
  return 0;
}
