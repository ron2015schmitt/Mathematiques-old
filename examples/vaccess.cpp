
// flag for run-time bounds and size checking
#define MATRICKS_CAREFUL


#include "matricks.hpp"
using namespace Matricks;

#include <iostream>
using namespace std;





int main()
{


  const int N = 10;

  LAvector<double> v1(N,"v1");

  cout << "initialize each element of v1" << endl;
  v1 = sqr(linspace<double>(1,19,N));
  cout << v1<< endl;




  cout << "access the last 3 elements of v1" << endl;
  LAvector<double> v2(3,"v2");
  v2 = v1[seq(7,9)];
  cout << v2<< endl;
  

  cout << "set the last 3 elements of v1 to zero" << endl;
  v1[seq(7,9)] = 0;
  cout << v1<< endl;


  cout << "set the last 3 elements of v1 back to original values" << endl;
  v1[seq(7,9)] =  v2;
  cout << v1<< endl;

  cout << "Set the last 3 elements of v1 to the negation of elements 5,6,7" << endl;
  v1[seq(7,9)] =  -v1[seq(5,7)];
  cout << v1<< endl;

  


  cout << "v2 = elements 3,5,0 of v1, v2=v1[v3]" << endl;
  LAvector<uint> v3(3,"v3");
  v3[0] = 3;
  v3[1] = 5;
  v3[2] = 0;
  cout <<"v3=" << v3<< endl;
  v2 = v1[v3];
  cout <<"v2="<< v2<< endl;
  

  cout << "v2 = elements 3,4,5 of v1, v2=v1[seq(3,5)]" << endl;
  v2 = v1[seq(3,5)];
  cout << v2<< endl;


  cout << "access negative elements of v1 using a mask" << endl;
  // Since, in general, one doesn't know how many elements meet conditions
  // and since the size of LAvector objects is fixed,
  // we need to place into a vector via contructor
  LAvector<bool> mask=(v1<0.0);
  mask.name("mask");
  cout <<"mask=(v1<0.0)="<<mask<< endl;    
  LAvector<double> v4(v1[mask],"v4");
  cout<<"v4=v1[mask]=" << v4 << endl;
  

  cout << "access negative elements of v1 using v1[v1<0]" << endl;
  // Since, in general, one doesn't know how many elements meet conditions
  // and since the size of LAvector objects is fixed,
  // we need to place into a vector via contructor
  LAvector<double> v5 = v1[v1<0.0];  
  cout<<"v5=v1[v1<0.0]=" << v5<< endl;

  
  cout << "Set negative elements of v1 to zero, v1[v1<0.0] = 0" << endl;
  v1[v1<0.0] = 0;
  cout << v1<< endl;
  
  cout << "Negate every other element of v1" << endl;
  LAvector<uint> ieven = range<uint>(0,N-1,2);
  v1[ieven] = -v1[ieven];
  cout << v1<< endl;
  

  LAvector<double> x1(N,"x1");
  cout<<endl << "reinitialize v1 and x1" << endl;
  v1[7]=3;
  v1[8]=2;
  v1[9]=1;
  cout<<"v1=" << v1<< endl;
  x1=v1;
  cout<<"x1=" << x1<< endl;


  cout<<endl << "sort x1 in place, using sort(x1)" << endl;
  sort(x1);
  cout<<"x1=" << x1<< endl;


  x1=v1;
  cout<<endl<<"x1=" << x1<< endl;
  cout<< "sort x1 in place and store the indices" << endl;
  LAvector<unsigned int> ii(N);
  ii = sortwind(x1);
  cout<<"ii=sortwind(x1)=" << ii<< endl;
  cout<<"x1=" << x1<< endl;

  return 0;
}
