

#include "cooll.hpp"
using namespace COOLL;

#include "../testbed/testlib.hpp"

#include <iostream>
using namespace std;


// error found 2004/04/30
// status: unresolved

int main()
{

  LAvector<double> v1(3,"v1");
  LAvector<double> v2(3,"v2");

  v1 = range<double>(1,3);
  v2 = range<double>(100,300,100);
  dispcr(v1);
  dispcr(v2);

  Matrix<complex<double> > M(3,3,"M");
  
  dispcr(M);

  // this should produce a COOLL error but doesn't
  // operation seems to have no effect: M is left as all zeros
  M = vcomplex(v1,v2);
  
  dispcr(M);


  // this works
  M.col(0) = vcomplex(v1,v2);
  dispcr(M);

  // this works
  LAvector<complex<double> > vc(3,"vc");
  vc = vcomplex(v1,v2)*3.5;
  dispcr(vc);

  // BUG--->this causes segmentation fault
  M.col(0) = vcomplex(v1,v2)*3.5;
  dispcr(M);



}
