
// flag for run-time bounds and size checking
#define COOLL_CAREFUL


#include "cooll.hpp"
using namespace COOLL;

#include <iostream>
#include <iomanip>
using namespace std;





int main()
{

  //  p3vector is a class that is optimized for represensting Physical 3-vectors (x,y,z)
  
  p3vector<double> v1(1,2,3);
  cout << "initialize each element of v1" << endl;
  dispcr(v1);

  // can access the components in several ways
  dispcr(v1.x());
  dispcr(v1.y());
  dispcr(v1.z());

  dispcr(v1[0]);
  dispcr(v1[1]);
  dispcr(v1[2]);


  // can intialize the vector at construction
  p3vector<double> v2(100,100,100);
  dispcr(v2);


  // can set the components in several ways
  v2[0] = 10;
  v2[1] = 11;
  v2[2] = 12;
  dispcr(v2);
  v2.x() = -1;
  v2.y(21);
  dispcr(v2);


  // can perform most any expression that can be used on LAvectors
  p3vector<double> v3;

  v2=v1;
  dispcr(v2);

  v3 = 2*v1+v2;
  dispcr(v3);
  
  
  v2[0] = 3.14/4;
  v2[1] = 3.14/2;
  v2[2] = 3.14;
  v3 = sin(v2);
  dispcr(v3);

  // dot product uses a function rather than (a|b) operator
  double d = dot(v1,v2);
  dispcr(d);

  // can also calculate cross product
  v3=cross(v1,v2);

  // can set components usign a text string
  "{3.14,25,100}" >> v3;
  dispcr(v3);



  return 0;
}
