
// flag for run-time bounds and size checking
#define COOLL_CAREFUL


#include "cooll.hpp"
using namespace COOLL;

#include <iostream>
using namespace std;


#include <vector>


int main()
{
  const int N = 4;
  LAvector<double> v1(N,"v1");
  LAvector<double> v2(N,"v2");
  LAvector<double> v3(N,"v3");


  cout <<endl<< "initialize each element of v1" << endl;
  v1[0] = 1.0;
  v1[1] = 2.0;
  v1[2] = 3.0;
  v1[3] = 4.0;
  dispcr(v1);
  

  cout <<endl<< "initialize v2 using range<" << endl;
  v2 = range<double>(5,8);
  dispcr(v2);

  cout << endl << "initialize v2 using range<" << endl;
  v2 = range<double>(4,1);
  dispcr(v2);

  cout << endl << "initialize v2 using range<" << endl;
  v2 = range<double>(400,100,-100);
  dispcr(v2);



  cout << endl << "initialize v2 using linspace" << endl;
  v2 = linspace<double>(100,400,4);
  dispcr(v2);

  cout << endl << "initialize v2 using linspace" << endl;
  v2 = linspace<double>(6,3,4);
  dispcr(v2);

  cout << endl << "initialize v2 from C-array (careful, no bounds checking!)" << endl;
  double ans7[4] = {1.234, 101.3, 0, -23.4};
  v2 = vcast<double>(ans7,4);
  dispcr(v2);

  cout << endl << "initialize v2 from std::vector" << endl;
  vector<double> vstd(4);
  vstd[0] = -1;
  vstd[1] = -2;
  vstd[2] = -3;
  vstd[3] = -4;
  v2 = vcast<double>(vstd);
  dispcr(v2);

  cout << endl << "initialize v2 from std::valarray" << endl;
  valarray<double> val(4);
  val[0] = -11;
  val[1] = -12;
  val[2] = -13;
  val[3] = -14;
  v2 = vcast<double>(val);
  dispcr(v2);

  cout << endl << "initialize v2 using range<" << endl;
  v2 = range<double>(100,400,100);
  dispcr(v2);

  cout << endl << "addition of vectors" << endl;
  v3 = v1 + v2;
  cout << " v3 = v1 + v2 = " <<v3<<endl;

  cout << endl << "vector subtraction" << endl;
  v3 = v2 - v1;
  cout << " v3 = v2 - v1 = " <<v3<<endl;

  cout << endl << "vector (element-wise) multiplication" << endl;
  v3 = v1 * v2;
  cout << " v3 = v1 * v2 = " <<v3<<endl;

  cout << endl << "vector (element-wise) division" << endl;
  v3 =  v2/v1;
  cout << " v3 = v2 / v1 = " <<v3<<endl;



  cout << endl << "vector + scalar" << endl;
  v3 =  v2/v1;
  cout << " v3 = v2 / v1 = " <<v3<<endl;


  cout << endl << "complicated example#1" << endl;
  v3 = 3*(v1+v2) + 1000;
  cout << " v3 =  3*(v1+v2) + 1000 = " <<v3<<endl;


  cout << endl << "complicated example#2" << endl;
  v3 = -200 + 100*v1;
  cout << " v3 =  -200 + 100*v1 = " <<v3<<endl;


  cout << endl << "intitialize elements of v2 to the same value" << endl;
  v2 = 1;
  cout <<"v2 = 1 = "<< v2<< endl;
  

  cout << "dot product" << endl;
  double d = (v1|v2);
  cout <<d << endl;

  cout << "dot product" << endl;
  d = (v1|v1+3*v2) + 1.0;
  cout <<d << endl;

  cout << "maximum" << endl;
  d = max(v1+v2);
  cout <<d << endl;

  cout << "minimum" << endl;
  d = min(v3);
  cout <<d << endl;

  cout << "sum" << endl;
  d = sum(v1);
  cout <<d << endl;

  cout << "norm" << endl;
  d = norm(v1);
  cout <<d << endl;

  LAvector<int> v4(N,"v4");
  v4 = range<int>(20,17);   
  cout << "vector of integers" << endl;
  cout <<v4 << endl;


  LAvector<unsigned int> v4u(N,"v4u");
  v4u = range<uint>(5,8);
  cout << "vector of unsigned integers" << endl;
  cout <<v4u << endl;

  LAvector<float> v5(N,"v5");
  cout << "converting integer vector to single precision vector and adding a constant" << endl;
  v5 = vcast<float>(v4) + 0.5F;
  cout << v5 << endl;


  LAvector<extended> v6(N,"v6");
  cout << "converting double precision vector to extended precision vector and addign a constant" << endl;
  v6 = vcast<extended>(v1) + 1e-18L;
  cout.precision(19);
  cout << v6 << endl;

  cout.precision(0);



  cout<<endl << "resize v1: v1.resize(3). Note that all data that as in v1 is lost." << endl;
  v1.resize(3);
  cout <<"v1 = "<< v1<< endl;


  cout<<endl << "resize to zero to release the memory: v1.resize(0)" << endl;
  cout << "this can be used for efficient memory management when working with large vectors" << endl;
  v1.resize(0);
  cout <<"v1 = "<< v1<< endl;

  cout<<endl << "resize and set v1 froma vector expression" << endl;
  v1.resize() = 2*v2;
  cout <<"v1.resize() = 2*v2 = "<< v1<< endl;


  cout<<endl << "reinitialize v1" << endl;
  v1[0] = -1.5;
  v1[1] = -1.1;
  v1[2] = 0.1;
  v1[3] = 0.5;
  cout << v1 << endl;


  cout <<endl<< "convert v1 to a C-style array of floats" << endl;
  float* dat1 = toCarray<float>(v1);
  cout << "*dat1={";
  for(unsigned int i = 0; i<N-1; i++) 
    cout <<dat1[i]<<",";
  cout <<dat1[N-1] << "}"<<endl;
  // YOU MUST DELETE THE MEMORY THAT WAS CREATED AT SOME POINT BEFORE 
  // THE END OF YOUR CODE 
  delete [] dat1;


  cout <<endl<< "round and convert v1 to a std::vector of ints" << endl;
  vector<int> vstd2 = tostdvector<int>(round(v1));
  cout << "vstd2={";
  for(unsigned int i = 0; i<N-1; i++) 
    cout <<vstd2[i]<<",";
  cout <<vstd2[N-1] << "}"<<endl;


  cout <<endl<< "convert v1 to a std::valarray of doubles" << endl;
  valarray<double> val2 = tovalarray<double>(v1);
  cout << "val2={";
  for(unsigned int i = 0; i<N-1; i++) 
    cout <<val2[i]<<",";
  cout <<val2[N-1] << "}"<<endl;

    


  cout <<endl<< "accessing a range of elements using the seq(start,end)" << endl;
  LAvector<double> v7(0,"v7");
  v7.resize() = v1[seq(1,3)];
  cout <<"v7.resize() = v1[seq(1,3)]=" << v7<<endl;

  cout <<endl<< "zero teh first two elements of v7" << endl;
  v7[seq(0,1)]=0;
  cout <<"v7[seq(0,1)]=0; v7=" << v7<<endl;


  cout <<endl<< "reverse the order of a vector" << endl;
  v1 = v1[seq(3,0)];
  cout <<"v1 = v1[seq(3,0)]=" << v1<<endl;


  return 0;
}
