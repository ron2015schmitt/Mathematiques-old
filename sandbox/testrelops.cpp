
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


  mout << bold.apply("Relational operator tests") << endl;
  cr();

  mout << blue.apply("Vector-Vector tests") << endl;
  {
    using namespace mathq::unit_imaginary;
    cr();
    Vector<int> Vint1 {11,12,-13};
    Vector<int> Vint2 {1,12,6};
    Vector<int> Vint3 {11,12,-13};
    Vector<int> Vint4 {10,11,-14};
    Vector<double> Vd1 {0.1,1,10};
    Vector<double> Vd2 {3.14,2.2,10};
    Vector<double> Vf1 {0.1,1,10};
    mout << blue.apply("Given:") << endl;
    mout<<"  ";tdisp(Vint1);
    mout<<"  ";tdisp(Vint2);
    mout<<"  ";tdisp(Vint3);
    mout<<"  ";tdisp(Vint4);
    mout<<"  ";tdisp(Vd1);
    mout<<"  ";tdisp(Vd2);
    mout<<"  ";tdisp(Vf1);
    cr();
    mout << blue.apply("Vector==Vector") << endl;
    mout<<"  ";tdisp(Vint1 == Vint2);
    mout<<"  ";tdisp(Vint1 != Vint2);
    mout<<"  ";tdisp(Vint1 > Vint2);
    mout<<"  ";tdisp(Vint1 >= Vint2);
    mout<<"  ";tdisp(Vint1 < Vint2);
    mout<<"  ";tdisp(Vint1 <= Vint2);
    mout<<"  ";tdisp(Vint1 == Vint3);
    mout<<"  ";tdisp(Vint3 == Vint1);
    mout<<"  ";tdisp(Vint1 == Vint1);
    mout<<"  ";tdisp(Vd1 == Vf1);
    mout<<"  ";tdisp(Vd1 > 1);

    cr();
    mout<<"  ";tdisp(Vd1 == Vd2);
    mout<<"  ";tdisp(Vint1 == 12);
    mout<<"  ";tdisp( (Vd1 == Vd2) && (Vint1 == 12));
    mout<<"  ";tdisp( (Vd1 == Vd2) || (Vint1 == 12));
    cr();
    mout<<"  ";tdisp(Vint1 == (Vint4+1));
    mout<<"  ";tdisp((Vint1 + Vint2) + (Vint3 +Vint4));
    
    cr();
    mout<<"  ";tdisp(pow(Vd1,2));
    mout<<"  ";tdisp(pow(Vd1,2.3));
    mout<<"  ";tdisp(pow(Vd1,Vint1));
    mout<<"  ";tdisp(pow((Vint1 + Vint2) + (Vint3 +Vint4),2));

    
  }

  return 0;

  
 
  
  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  
  return 0;
}
