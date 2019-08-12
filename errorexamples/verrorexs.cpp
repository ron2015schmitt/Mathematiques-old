
#import <iostream>

#define COOLL_CAREFUL


#import "cooll.hpp"

using namespace COOLL;


using namespace std;


int main()
{
  const int N = 7;

 

 
  Vector<double> v1(N,"v1");
  Vector<double> v2(N,"v2");
  Vector<double> v3(N,"v3");


  Vector<double> v4(N,"v4");
       
  
  double d = 0;
  Vector<bool> q(N);



// explicit name testing
  Vector<double> r(N,"r");
  r=100;
  cout << r.name() <<"="<<r << endl;
  Vector<double> rr(N,"r");
  rr=200;
  cout << rr.name() <<"="<<rr << endl;
  Vector<double> rrr(N,"r");
  rrr=300;
  cout << rrr.name() <<"="<<rrr << endl;
  rrr.name("rrr");
  cout << rrr.name() <<"="<<rrr << endl;

  // *** RUNTIME ERROR TESTING** ALL FOLLOWING SHOULD CAUSE RUNTIME ERRORS

  cout << endl<< "too large of a vector" << endl;
  Vector<double> b(maxsize+1,"b");

  int M=N-1;
  Vector<double> vv(M,"vv");
  vv=1;
  cout <<endl << vv.name() <<"="<<vv << endl;

  cout << endl<< "RHS access beyond bounds vv[M]" << endl;
  double x = vv[M]; 
  disp(x);dispcr(vv);

  cout << endl<< "LHS access beyond bounds vv[M]" << endl;
  vv[M] = 1.5; 
  dispcr(vv);

  int ii = -1;
  cout << endl<< "access beyond bounds vv[-1]" << endl;
  vv[ii] = 1.5; 

  cout<< endl << "assigment to vector of different size" << endl;
  vv = v4;

  cout<< endl << "assigment to vector expression of different size" << endl;
  vv = v1+v2;

  cout<< endl << "addition between vectors of different size" << endl;
  v4 = vv + v1;

  std::vector<double> stdv2(N+1);

  cout<< endl << "assignment to std::vector of different size" << endl;
  v4=vcast<double>(stdv2);


  cout<< endl << "dot product between vectors of different size" << endl;
  d=(v1|vv);


  cout<< endl << "sum of ill-formed vector expression" << endl;
  d=sum(2.0*vv+v1);

  cout<< endl << "comparison between vectors of different size" << endl; 
  q=(v1==vv);

  cout<< endl << "comparison between vector and expression of different size" << endl; 
  q=(v1==(2.0*vv+v1));

  cout<< endl << "range< of zero size" << endl; 
  v2 = range<double>(10,20,-1);
  cout<< endl << "linspace with less than two points" << endl; 
  v2 = linspace<double>(10,20,1);
  cout<< endl << "linspace with less than two points" << endl; 
  v2 = linspace<double>(10,20,0);

  cout<< endl << "assignment of different size vector expression to range" << endl; 
  v1[seq(0,4)] = 2*v2;

  cout<< endl << "assignment of different size vector to range" << endl; 
  v1[seq(0,4)] = vcast<double>(stdv2);
  
  Vector<double> vv2(N+1,"vv2");
  cout<< endl << "assignment of different size vector to range" << endl; 
  v1[seq(0,7)] = vv2;

  Matrix<double> M1(5,2,"A1");
  cout<< endl << "assignment of incomatible matrix to range" << endl; 
  v1[seq(0,4)] = M1;

  cout<< endl << "assignment of different size vector to mask " << endl; 
  v1=range<double>(-3,3);
  cout<<"v1="<<v1<<endl;
  v1[v1<0.0] = v2;


  Vector<uint> vi(N+1,"vi");
  cout<< endl << "assignment of different size vector to set " << endl; 
  v1 = v1[vi];

  Vector<uint> vj(N,"vj");
  vj = range<uint>(2,N+1);
  cout<< endl << "assignment of vector to set that contains out of bounds value" << endl; 
  v1 = v1[vj];




  Vector<bool> b1(8,"b1");
  cout<< endl << "MASK SIZE DOES NOT MATCH VECTOR SIZE" << endl; 
  v1 = v1[b1];



  Vector<double> vzero(0,"vzero");
  cout<< endl << "assigment to vector of different size (WARNING)" << endl;
  v4 = linspace<double>(1,7,7);
  vzero = v4;
  dispcr(vzero);

  Vector<double> vzero2;
  cout<< endl << "assigment to vector expression of different size (WARNING)" << endl;
  v1 = linspace<double>(300,900,7);
  v2 = linspace<double>(3,9,7);
  vzero2 = v1+v2;
  dispcr(vzero2);


  return 0;
}
