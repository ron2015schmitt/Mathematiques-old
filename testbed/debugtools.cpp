
// flag for run-time bounds and size checking
 


#include "cooll.hpp"
using namespace COOLL;

#include "testlib.hpp"

#include <iostream>
#include <complex>

using namespace std;



int main()
{

  string s;

  //floating point types

  double x1=0;
  s =  make_type_string(x1);
  string ans1 = "double";
  compare(s,ans1);
 
  float  x2=0;
  s =  make_type_string(x2);
  string ans2 = "float";
  compare(s,ans2);

  long double x3=0;
  s =  make_type_string(x3);
  string ans3 = "long double";
  compare(s,ans3);


  // bool

  bool x4=0;
  s =  make_type_string(x4);
  string ans4 = "bool";
  compare(s,ans4);

  //integer types

  short int x5=0;
  s =  make_type_string(x5);
  string ans5 = "short";
  compare(s,ans5);

  signed short int x6=0;
  s =  make_type_string(x6);
  string ans6 = "short";
  compare(s,ans6);

  unsigned short int x7=0;
  s =  make_type_string(x7);
  string ans7 = "unsigned short";
  compare(s,ans7);

  int x8=0;
  s =  make_type_string(x8);
  string ans8 = "int";
  compare(s,ans8);

  signed int x9=0;
  s =  make_type_string(x9);
  string ans9 = "int";
  compare(s,ans9);

  unsigned  int x10=0;
  s =  make_type_string(x10);
  string ans10 = "unsigned int";
  compare(s,ans10);

  long int x11=0;
  s =  make_type_string(x11);
  string ans11 = "long";
  compare(s,ans11);

  signed long int x12=0;
  s =  make_type_string(x12);
  string ans12 = "long";
  compare(s,ans12);

  unsigned long int x13=0;
  s =  make_type_string(x13);
  string ans13 = "unsigned long";
  compare(s,ans13);


  // complex floating point types

  complex<double> x20=0;
  s =  make_type_string(x20);
  string ans20 = "std::complex<double> ";
  compare(s,ans20);
 
  complex<float>  x21=0;
  s =  make_type_string(x21);
  string ans21 = "std::complex<float> ";
  compare(s,ans21);

  complex<long double> x22=0;
  s =  make_type_string(x22);
  string ans22 = "std::complex<long double> ";
  compare(s,ans22);


  // LAvectors
  LAvector<double> x30;
  s =  x30.classname();
  string ans30a = "LAvector";
  compare(s,ans30a);
  s =  x30.fullclassname();
  string ans30b = "LAvector<double> ";
  compare(s,ans30b);

  LAvector<complex<double> > x31;
  s =  x31.classname();
  string ans31a = "LAvector";
  compare(s,ans31a);
  s =  x31.fullclassname();
  string ans31b = "LAvector<std::complex<double> > ";
  compare(s,ans31b);
 

  // Matrices
  Matrix<double> x40;
  s =  x40.classname();
  string ans40a = "Matrix";
  compare(s,ans40a);
  s =  x40.fullclassname();
  string ans40b = "Matrix<double> ";
  compare(s,ans40b);

  Matrix<complex<double> > x41;
  s =  x41.classname();
  string ans41a = "Matrix";
  compare(s,ans41a);
  s =  x41.fullclassname();
  string ans41b = "Matrix<std::complex<double> > ";
  compare(s,ans41b);
 
   // p3vectors
  p3vector<double> x50;
  s =  x50.classname();
  string ans50a = "p3vector";
  compare(s,ans50a);
  s =  x50.fullclassname();
  string ans50b = "p3vector<double> ";
  compare(s,ans50b);

  p3vector<complex<double> > x51;
  s =  x51.classname();
  string ans51a = "p3vector";
  compare(s,ans51a);
  s =  x51.fullclassname();
  string ans51b = "p3vector<std::complex<double> > ";
  compare(s,ans51b);
 

  //combinations
  LAvector<LAvector<p3vector<complex<double> > > > x61(1);
  s =  x61.classname();
  string ans61a = "LAvector";
  compare(s,ans61a);
  s =  x61.fullclassname();
  string ans61b = "LAvector<LAvector<p3vector<std::complex<double> > > > ";
  compare(s,ans61b);

  s =  x61[0].fullclassname();
  string ans61c = "LAvector<p3vector<std::complex<double> > > ";
  compare(s,ans61c);

  cout << "<Basic tests for debugging tools passed>"<<endl;
  return 0;



}
