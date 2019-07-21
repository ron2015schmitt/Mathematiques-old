
/

#include "cooll.hpp"
using namespace COOLL;

#include "../testbed/testlib.hpp"

#include <iostream>
using namespace std;



// errors found 2004/06/10
// status: unresolved
//MULTIVECTOR EXPRESSIONS

int main()
{

  //this works
  LAvector<LAvector<double> > v1(2,"v1");
  for(unsigned int i = 0; i<v1.size(); i++)
    v1[i].resize(3);
  "{{0.1,0.2,0.3},{0.4,0.5,0.6}}" >> v1;
  dispcr(v1); 

  //this works
  LAvector<LAvector<double> > v2(2);
  for(unsigned int i = 0; i<v1.size(); i++)
    v2[i].resize(3);
  "{{1.0,2.0,3.0},{4.0,5.0,6.0}}" >> v2;
  dispcr(v2);

  //this works
  LAvector<LAvector<double> > v3(2,"v3");
  for(unsigned int i = 0; i<v3.size(); i++)
    v3[i].resize(3);

  // this works
  v3=v1+v2; 
  dispcr(v3);


  // this works
  v3[0]=v1[1]; 
  dispcr(v3);

  // this works
  v3[0]=1.0; 
  v3[1]=-1.0; 
  dispcr(v3);

  // this wont compile
  //  v3=1.0;
  dispcr(v3);

  //wont compile cause no operator for D*LAvector<LAvector<D> >
  //v3=2.0*v2; 
  dispcr(v3);

  //wont compile 
  //v3=v1+2.0*v2;  
  dispcr(v3);

  // this works
  LAvector<LAvector<p3vector<std::complex<double> > > > v4(2,"v4");
  for(unsigned int i = 0; i<v4.size(); i++)
    v4[i].resize(2);
  "{ {{(1,10),(2,20),(3,30)},{(4,40),(5,50),(6,60)}}, {{(7,70),(8,80),(9,90)},{(10,100),(11,110),(12,120)}} }" >> v4;
  dispcr(v4);

  // this works
  LAvector<LAvector<p3vector<double> > > v5(2,"v5");
  for(unsigned int i = 0; i<v5.size(); i++)
    v5[i].resize(2);
  "{ {{0.1,0.2,0.3},{0.4,0.5,0.6}}, {{0.7,0.8,0.9},{0.01,0.011,0.012}} }" >> v5;
  dispcr(v5);
 

  LAvector<LAvector<p3vector<std::complex<double> > > > v6(2,"v6");
  for(unsigned int i = 0; i<v6.size(); i++)
    v6[i].resize(2);
  //  v6=v4+v5; wont compile
  dispcr(v6);

}
