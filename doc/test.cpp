#define MATRICKS_DEBUG 2


#include "matricks.h"
#include "TypeTraits.h"
#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif

template <class D, int I>
class Mets {
public:
  static void test() {
    printf("I = %d\n",I);
  }
};

template <class D>
class Mets<D,4> {
public:
  static void test2() {
    printf("I is 4\n");
  }
};


namespace display {




  


  template <typename D> 
  inline bool checkFormatString(const std::string formatstr, const D& x = D(1)) {
    using namespace std;
    if (formatstr.empty()) {
      return false;
    }
    
    int ret = 0;
    bool passed = true;
    try {
      ret = snprintf(Buffer, BUFFER_SIZE, formatstr.c_str(), x);
      if (ret<0) passed = false;
    } catch (...) {
      string classname = "";
      passed = false;
    }
    string s = string(Buffer);
    size_t found = s.find("(nil)");
    if (found!=string::npos) 	passed = false;
    
    D x2 = D(0);
    D *x2ptr = &x2;
    ret = std::sscanf(Buffer, "%lg", x2ptr);
    if (ret != 1) passed = false;
    if (x2 != x)  passed = false;
    
    if (!passed) {
      cout << StyledString::get(HORLINE);
      cout << StyledString::get(ERROR);
      cout << " illegal format string";
      cout << createStyle(BOLD).apply(string(" \"") + formatstr + "\"");
      cout << " passed to Format";
      cout << "<" << display::getTypeName(x) << ">";
      cout << endl;
      cout << StyledString::get(HORLINE);
      return false;
    }     
    return true;
  }


  

  template <typename T>
  inline void setFormatString(const std::string fstring) {
    T* xptr = new T(25);
    bool valid = checkFormatString<T>(fstring, *xptr);
    if (valid) {
      FormatData<T>::format_string = fstring;
    }
  }


  //---------------------------------------------------------------------------------
  //       specialize for double
  //---------------------------------------------------------------------------------
  

  template <>
  class FormatData<double> {
  public:
    static Style style_for_type_name;
    static Style style_for_value;
    static Style style_for_zero;
    const static std::string format_string_default; 
    static std::string format_string;  
  };

  Style FormatData<double>::style_for_type_name = createStyle(MAGENTA);
  Style FormatData<double>::style_for_value = createStyle(RESET);
  Style FormatData<double>::style_for_zero = createStyle(GRAY1);
  const std::string FormatData<double>::format_string_default = "%lg";  // used for scanf so do NOT change
  std::string FormatData<double>::format_string = format_string_default;
  
  template <>
  inline std::string getTypeName(const double& var) {
    return FormatData<double>::style_for_type_name.apply("double");
  }
  
  
  template <>
  inline void printObj(const double& d) {
    using namespace std;
    printf(getFormatString<double>().c_str(),d);
  }
  


  //---------------------------------------------------------------------------------
  //       specialize for complex<double>
  //---------------------------------------------------------------------------------

  template <>
  class FormatData<std::complex<double> > {
  public:
    static Style style_for_type_name;
    static Style style_for_value;
    static Style style_for_zero;
    static std::string format_string;  
    const static std::string format_string_default; 
  };

  Style FormatData<std::complex<double> >::style_for_type_name = createStyle(GREEN);
  Style FormatData<std::complex<double> >::style_for_value = createStyle(RESET);
  Style FormatData<std::complex<double> >::style_for_zero = createStyle(GRAY1);
  const std::string FormatData<std::complex<double> >::format_string_default = "%s + i*%s";
  std::string FormatData<std::complex<double> >::format_string = format_string_default;
  
  template <>
  inline std::string getTypeName(const std::complex<double> & var) {
    std::string s = FormatData<std::complex<double> >::style_for_type_name.apply("std::complex ");
    s += "<" + getTypeName(var.real())+ +"> ";
    return s;
  }
  
  
  

  template <> 
  inline bool checkFormatString<std::complex<double> >(const std::string formatstr, const std::complex<double>& x) {
    using namespace std;
    if (formatstr.empty()) {
      return false;
    }
    
    int ret = 0;
    bool passed = true;
    ;
    try {
      snprintf(Buffer, BUFFER_SIZE, getFormatString<double>().c_str(), x.real() );
      string sr = string(Buffer);
      matricks::dispcr(sr);
      snprintf(Buffer, BUFFER_SIZE, getFormatString<double>().c_str(), x.imag() );
      string si = string(Buffer);
      matricks::dispcr(si);
      ret = snprintf(Buffer, BUFFER_SIZE, formatstr.c_str(), sr.c_str(), si.c_str());
      if (ret<0) passed = false;
    } catch (...) {
      string classname = "";
      passed = false;
    }
    string s = string(Buffer);
    size_t found = s.find("(nil)");
    if (found!=string::npos) 	passed = false;
    
    double xr = double(0);
    double xi = double(0);
    double *xrptr = &xr;
    double *xiptr = &xi;
    printf("s = %s\n",s.c_str());
    char chr[64];
    char chi[64];
    ret = std::sscanf(Buffer, formatstr.c_str() , chr, chi);
    printf("ret=%d chr=%s chi=%s\n",ret,chr,chi);
    if (ret != 2) passed = false;
    
    printf("ret=%d xr=%g xi=%g\n",ret,xr,xi);
    ret = std::sscanf(chr, "%lg" ,xrptr);
    if (ret != 1) passed = false;
    printf("ret=%d xr=%g xi=%g\n",ret,xr,xi);
    ret = std::sscanf(chi,  "%lg" ,xiptr);
    if (ret != 1) passed = false;
    printf("ret=%d xr=%g xi=%g\n",ret,xr,xi);
    if (ret != 1) passed = false;
    if (xr != x.real())  passed = false;
    if (xi != x.imag())  passed = false;
    
    if (!passed) {
      cout << StyledString::get(HORLINE);
      cout << StyledString::get(ERROR);
      cout << " illegal format string";
      cout << createStyle(BOLD).apply(string(" \"") + formatstr + "\"");
      cout << " passed to Format";
      cout << "<" << display::getTypeName(x) << ">";
      cout << endl;
      cout << StyledString::get(HORLINE);
      return false;
    }     
    return true;
  }

  template <>
  inline void setFormatString<std::complex<double> >(const std::string fstring) {
    std::complex<double> * xptr = new std::complex<double>(1,2);
    bool valid = checkFormatString<std::complex<double> >(fstring, *xptr);
    if (valid) {
      FormatData<std::complex<double> >::format_string = fstring;
    }
  }

  
  template <>
  inline void printObj(const std::complex<double>& d) {
    using namespace std;
    using namespace matricks;
    snprintf(Buffer, BUFFER_SIZE, getFormatString<double>().c_str(), d.real() );
    string sr = string(Buffer);
    dispcr(sr);
    snprintf(Buffer, BUFFER_SIZE, getFormatString<double>().c_str(), d.imag() );
    string si = string(Buffer);
    dispcr(si);
    printf(getFormatString<std::complex<double> >().c_str(), sr.c_str(), si.c_str());
  }
  


  // this allows const and non-const to be treated by same class
};

#define Vector_(name,t,...) Vector<t> name(__VA_ARGS__); //MatricksObjectPool::(name.id(),std::string(#name)+"<"+stringify(t)+">"+" in "+__FUNCTION__+" at line "+stringify(__LINE__)+" in file "+__FILE__));


int main()
{
 
  using namespace matricks;
  using namespace std;
  using namespace display;
  int Nex = 1;

  
  dispcr(Terminal::getSupportsColor());
  print_matricks_info();
  print1("DEBUG level 1 enabled \n");
  print2("DEBUG level 2 enabled \n");

  printf("MATRICKS_DEBUG=%d\n",MATRICKS_DEBUG);
  printf("EXPAND(MATRICKS_DEBUG)=%d\n",EXPAND(MATRICKS_DEBUG));

  cout << "error string   ="<<StyledString::get(ERROR)<<endl;
  cout << "warning string ="<<StyledString::get(WARNING)<<endl;
  
  double d = 3.4;
  Any<double> x(d);

  Any<index_type> yy(Nex);
  Vector<double> ron(5);
  Any<Vector<double> > z(ron);

  Vector<Vector<double> > ronnie;
  Any<Vector<Vector<double> > > zz(ronnie);
  
  Style bold(BOLD,"bold");
  dispcr(bold);
  dispcr(bold.apply("hello"));

  Style dim(DIM,"dim");  // doesn't work
  dispcr(dim);

  Style underline(UNDERLINE,"underline");
  dispcr(underline);

  Style crossedout(CROSSEDOUT,"crossedout");
  dispcr(crossedout);

  Style font2(FONT2,"font2"); // doesn;t work
  dispcr(font2);

  Style framed(FRAMED,"framed"); // doesn;t work
  dispcr(framed);

  Style encircled(ENCIRCLED,"encircled"); // doesn;t work
  dispcr(encircled);

  Style overline(OVERLINE,"overline");
  dispcr(overline);

  Style gray1(GRAY1,"gray1");
  dispcr(gray1);

  Style blue(BLUE,"blue");
  dispcr(blue);
  Style blue1(BLUE1,"blue1");
  dispcr(blue1);
  Style blue2(BLUE2,"blue2");
  dispcr(blue2);
  Style blue3(BLUE3,"blue3");
  dispcr(blue3);
  Style cyan(CYAN,"cyan");
  dispcr(cyan);

  Style magenta(MAGENTA,"magenta");
  dispcr(magenta);
  Style magenta1(MAGENTA1,"magenta1");
  dispcr(magenta1);

  StyledString ss(bold+magenta1, "Hello");
  dispcr(ss);


  int ronny = 5;
  double q = 5.5;
  double boots;
  dispcr(boots);
  log("matricks","Vector","resize","()");

  //  string s1 = print2str("%15.8f\n",3.141592649);

  string s1 = print2str("%15.8f\n",3.141592649);
  dispcr(s1);
  s1 = print2str("%15.8f\n",1.);
  dispcr(s1);


  Vector<double> Bessel0Coeffs =  Vector<double>({1.,0.,-0.25,0.,0.015625,0.,-0.000434028,0.,6.78168e-6,0.,-6.78168e-8,0.,4.7095e-10,0.,-2.40281e-12,0.,9.38597e-15,0.,-2.8969e-17,0.,7.24226e-20,0.,-1.49633e-22,0.,2.5978e-25,0.});

  Vector<double> r = linspace<double>(0,10,101);

  Vector<double> y = taylor(Bessel0Coeffs, r, 25);

  dispcr(y);


  // CLuasen function

  const size_type N = 20;
  Vector<double> An = Vector<double>(N,0.);

  Vector<double> Bn = 1./sqr(range<double>(0,N-1));
  Bn[0] = 0.0;

  const double pi = M_PI;
  Vector<double> t = linspace<double>(-2*pi,2*pi,201);
  const double T = 2*pi;
  const double omega = 1;
  Vector<double> y2 = fourier(An,Bn, t, An.size(), omega );
  dispcr(An);
  dispcr(Bn);
  dispcr(y2);

  print1("newdispcr");
  newdisp(pi);

  Mets<double,1>::test();
  Mets<double,4>::test2();

  using namespace Loki;
  dispcr(TypeTraits<double>::isStdFloat);
  dispcr(TypeTraits<const double>::isStdFloat);
  dispcr(TypeTraits<const double>::isFloat);
  dispcr(TypeTraits<const double>::isConst);
  TypeTraits<const double>::NonConstType degrom = 9;
  newdisp(degrom);
  newdisp(0.0);
  double harvey = 0;
  newdisp(harvey);

  int inty = 25;
  newdisp(inty);

  unsigned int uny = 25;
  newdisp(uny);


  dispcr(sizeof(uny));
  dispcr(sizeof(long int));


  long int linty = 25;
  newdisp(linty);

  unsigned long int luny = 25;
  newdisp(luny);

  bool booly = 1;
  newdisp(booly);
  booly = 0;
  newdisp(booly);

  // Format<const double> formatdouble("%f");
  // dispcr(formatdouble);
  // dispcr(formatdouble.getStyledTypeName());
  // dispcr(formatdouble.get());
  // dispcr(formatdouble.apply(3.4));
  // printf("formatdouble.setFormatStr(\"%%12.5f\")\n");
  // formatdouble.set("%12.5f");
  // dispcr(formatdouble.get());
  // dispcr(formatdouble.apply(3.4));
  
  // printf("formatdouble.setFormatStr(\"%%parbage\")\n");
  // formatdouble.set("%parbage");
  // dispcr(formatdouble.get());
  // dispcr(formatdouble.apply(3.4));

  // Format<bool> formatbool =  *(new Format<bool>);
  // cout <<formatbool<<endl;
  // dispcr(formatbool);
  // Format<double> formatdub = *(new Format<double>);
  // Format<const double> formatcdub =  *(new Format<const double>);
  // cout <<formatdub<<endl;
  // dispcr(formatdub);


  double xx = 5.5;
  const double xxc = 23.3;

  dispcr(getTypeName(y2));
  dispcr(getTypeName(xx));
  dispcr(getTypeName(xxc));


  setFormatString<double>("%lf");
  dispcr(xx);
  setFormatString<double>("hello");
  setFormatString<double>("%y");
  setFormatString<double>("%s");

  setFormatString<double>("% 10.5f");
  printObj(xx);cr();
  printObj(xxc);cr();
  setFormatString<double>("%g");
  cout << getFormatString<std::complex<double> >().c_str() << endl;
  complex<double> zc = complex<double>(2.3,4.5);
  printObj(zc);cr();

  //  setFormatString<complex<double> >("%g + i*%g");
  setFormatString<complex<double> >("%s +%si");
  printObj(zc);cr();
  tdisp(zc);cr();
  return 0;
}
