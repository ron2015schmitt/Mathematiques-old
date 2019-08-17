
/

#include "cooll.hpp"
using namespace COOLL;

#include "../testbed/testlib.hpp"

#include <iostream>
using namespace std;


// errors found 2004/06/10
// status: fixed in COOLL V1.9
//MULTIVECTOR copy contructor and copy assignment (when size=0)bugs

int main()
{


  LAvector<LAvector<double> > v1(2,"v1");
  for(unsigned int i = 0; i<v1.size(); i++)
    v1[i].resize(3);
  "{{0.1,0.2,0.3},{0.4,0.5,0.6}}" >> v1;
  dispcr(v1);

  // this works only in DEBUG mode
  printcr("this works only in DEBUG mode");
  LAvector<LAvector<double> > v2=v1;
  dispcr(v2);

  // this doesn't work
  printcr("this doesnt work (note that size of v3 is 0");
  LAvector<LAvector<double> >  v3;
  v3=v1;
  dispcr(v3);

  // this works only in DEBUG mode
  printcr("this works only in DEBUG mode");
  LAvector<LAvector<double> >  v4;
  "{{1,2,3},{4,5,6}}" >> v4; 
  dispcr(v4);





}
