
// flag for run-time bounds and size checking
#define MATRICKS_CAREFUL


#include "matricks.hpp"
using namespace Matricks;

#include <iostream>

// used to demonstrate how to convert to C++ vectors
#include <vector>


#define header1(x)  printf("# %s \n", x)
#define header2(x)  printf("## %s \n", x)
#define header3(x)  printf("### %s \n", x)
#define text(x)  printf("%s \n", x)

#define printexp(x)  printf("-> %s = %s\n",  #x, x)

#define codestart() printf("```C++\n")
#define codemulti(...)  printf("%s;\n",  #__VA_ARGS__); __VA_ARGS__

#define codeend() printf("```\n")
#define code(x)  codestart();codemulti(x);codeend()

#define resultstart() printf("**The result is**\n```C++\n")
#define resultmulti(...)  printf("  ");dispcr(__VA_ARGS__)
#define resultend() printf("```\n----\n")
#define result(x)  resultstart();resultmulti(x);resultend()


int main()
{
  cr();
  header1("Basic Vector Operations in mātricks");
  cr();
  header2("Declaring vectors");
  text("Declare vectors `v1`, `v2`, `v3`.");
  text("The optional second parameter is the name that will be stored with the vector in the object pool.  This name can be any string that you like.");
  codestart();
  codemulti( const int N = 4 );
  codemulti( Vector<double> v1(N,"v1") );
  codemulti( Vector<double> v2(N,"v2") );
  codemulti( Vector<double> v3(N,"vector3") );
  codeend();

  header2("Setting the values of a vector");

  header3("Directly setting the values of a vector");
  cr();
  cr();
  text("**EXAMPLE 1**: Set each element of `v1` individually");
  codestart();
  codemulti( v1[0] = 1.0 );
  codemulti( v1[1] = 2.0 );
  codemulti( v1[2] = 3.0 );
  codemulti( v1[3] = 4.0 );
  codeend();
  cr();
  result(v1);


  header3("Using the range Function");
  
  cr();
  cr();
  text("**EXAMPLE 2**: Set `v2` using the **`range`** function");
  code( v2 = range<double>(5,8) );
  cr();
  result(v2);

  cr();
  cr();
  text("**EXAMPLE 3**: Set `v2` using the **`range`** function");
  code( v2 = range<double>(4,1) );
  cr();
  result(v2);

  cr();
  cr();
  text("**EXAMPLE 4**: Set `v2` using the **`range`** function");
  code( v2 = range<double>(400,100,-100) );
  cr();
  result(v2);

  header3("Using the `linspace` function");
  cr();
  cr();
  text("**EXAMPLE 5**: Set `v2` using the **`linspace`** function");
  code( v2 = linspace<double>(100,400,4) );
  cr(); 
  result(v2);

  cr();
  cr();
  text("**EXAMPLE 6**: Set `v2` using the linspace function");
  code( v2 = linspace<double>(6,3,4) );
  cr();
  result(v2);

  cr();
  cr();
  text("**EXAMPLE 7**: initialize v2 from C-array (careful, no bounds checking!)" );
  codestart();
  codemulti( double ans7[4] = {1.234, 101.3, 0, -23.4} );
  codemulti( v2 = vcast<double>(ans7,4) );
  codeend();
  result(v2);

  std::cout << std::endl << "initialize v2 from std::vector" << std::endl;
  std::vector<double> vstd(4);
  vstd[0] = -1;
  vstd[1] = -2;
  vstd[2] = -3;
  vstd[3] = -4;
  v2 = vcast<double>(vstd);
  cr();
  result(v2);

  
  std::cout << std::endl << "initialize v2 from std::valarray" << std::endl;
  std::valarray<double> val(4);
  val[0] = -11;
  val[1] = -12;
  val[2] = -13;
  val[3] = -14;
  v2 = vcast<double>(val);
  dispcr(v2);

  std::cout << std::endl << "initialize v2 using range<" << std::endl;
  v2 = range<double>(100,400,100);
  dispcr(v2);

  std::cout << std::endl << "addition of vectors" << std::endl;
  v3 = v1 + v2;
  std::cout << " v3 = v1 + v2 = " <<v3<<std::endl;

  std::cout << std::endl << "vector subtraction" << std::endl;
  v3 = v2 - v1;
  std::cout << " v3 = v2 - v1 = " <<v3<<std::endl;

  std::cout << std::endl << "vector (element-wise) multiplication" << std::endl;
  v3 = v1 * v2;
  std::cout << " v3 = v1 * v2 = " <<v3<<std::endl;

  std::cout << std::endl << "vector (element-wise) division" << std::endl;
  v3 =  v2/v1;
  std::cout << " v3 = v2 / v1 = " <<v3<<std::endl;



  std::cout << std::endl << "vector + scalar" << std::endl;
  v3 =  v2/v1;
  std::cout << " v3 = v2 / v1 = " <<v3<<std::endl;


  std::cout << std::endl << "complicated example#1" << std::endl;
  v3 = 3*(v1+v2) + 1000;
  std::cout << " v3 =  3*(v1+v2) + 1000 = " <<v3<<std::endl;


  std::cout << std::endl << "complicated example#2" << std::endl;
  v3 = -200 + 100*v1;
  std::cout << " v3 =  -200 + 100*v1 = " <<v3<<std::endl;


  std::cout << std::endl << "intitialize elements of v2 to the same value" << std::endl;
  v2 = 1;
  std::cout <<"v2 = 1 = "<< v2<< std::endl;
  

  std::cout << "dot product" << std::endl;
  double d = (v1|v2);
  std::cout <<d << std::endl;

  std::cout << "dot product" << std::endl;
  d = (v1|(v1+3*v2)) + 1.0;
  std::cout <<d << std::endl;

  std::cout << "maximum" << std::endl;
  d = max(v1+v2);
  std::cout <<d << std::endl;

  std::cout << "minimum" << std::endl;
  d = min(v3);
  std::cout <<d << std::endl;

  std::cout << "sum" << std::endl;
  d = sum(v1);
  std::cout <<d << std::endl;

  std::cout << "norm" << std::endl;
  d = norm(v1);
  std::cout <<d << std::endl;

  Vector<int> v4(N,"v4");
  v4 = range<int>(20,17);   
  std::cout << "vector of integers" << std::endl;
  std::cout <<v4 << std::endl;


  Vector<unsigned int> v4u(N,"v4u");
  v4u = range<uint>(5,8);
  std::cout << "vector of unsigned integers" << std::endl;
  std::cout <<v4u << std::endl;

  Vector<float> v5(N,"v5");
  std::cout << "converting integer vector to single precision vector and adding a constant" << std::endl;
  v5 = vcast<float>(v4) + 0.5F;
  std::cout << v5 << std::endl;


  Vector<extended> v6(N,"v6");
  std::cout << "converting double precision vector to extended precision vector and addign a constant" << std::endl;
  v6 = vcast<extended>(v1) + 1e-18L;
  std::cout.precision(19);
  std::cout << v6 << std::endl;

  std::cout.precision(0);



  std::cout<<std::endl << "resize v1: v1.resize(3). Note that all data that as in v1 is lost." << std::endl;
  v1.resize(3);
  std::cout <<"v1 = "<< v1<< std::endl;


  std::cout<<std::endl << "resize to zero to release the memory: v1.resize(0)" << std::endl;
  std::cout << "this can be used for efficient memory management when working with large vectors" << std::endl;
  v1.resize(0);
  std::cout <<"v1 = "<< v1<< std::endl;

  std::cout<<std::endl << "resize and set v1 froma vector expression" << std::endl;
  v1.resize() = 2*v2;
  std::cout <<"v1.resize() = 2*v2 = "<< v1<< std::endl;


  std::cout<<std::endl << "reinitialize v1" << std::endl;
  v1[0] = -1.5;
  v1[1] = -1.1;
  v1[2] = 0.1;
  v1[3] = 0.5;
  std::cout << v1 << std::endl;


  std::cout <<std::endl<< "convert v1 to a C-style array of floats" << std::endl;
  float* dat1 = toCarray<float>(v1);
  std::cout << "*dat1={";
  for(unsigned int i = 0; i<N-1; i++) 
    std::cout <<dat1[i]<<",";
  std::cout <<dat1[N-1] << "}"<<std::endl;
  // YOU MUST DELETE THE MEMORY THAT WAS CREATED AT SOME POINT BEFORE 
  // THE END OF YOUR CODE 
  delete [] dat1;


  std::cout <<std::endl<< "round and convert v1 to a std::vector of ints" << std::endl;
  std::vector<int> vstd2 = tostdvector<int>(round(v1));
  std::cout << "vstd2={";
  for(unsigned int i = 0; i<N-1; i++) 
    std::cout <<vstd2[i]<<",";
  std::cout <<vstd2[N-1] << "}"<<std::endl;


  std::cout <<std::endl<< "convert v1 to a std::valarray of doubles" << std::endl;
  std::valarray<double> val2 = tovalarray<double>(v1);
  std::cout << "val2={";
  for(unsigned int i = 0; i<N-1; i++) 
    std::cout <<val2[i]<<",";
  std::cout <<val2[N-1] << "}"<<std::endl;

    


  std::cout <<std::endl<< "accessing a range of elements using the seq(start,end)" << std::endl;
  Vector<double> v7(0,"v7");
  v7.resize() = v1[seq(1,3)];
  std::cout <<"v7.resize() = v1[seq(1,3)]=" << v7<<std::endl;

  std::cout <<std::endl<< "zero teh first two elements of v7" << std::endl;
  v7[seq(0,1)]=0;
  std::cout <<"v7[seq(0,1)]=0; v7=" << v7<<std::endl;


  std::cout <<std::endl<< "reverse the order of a vector" << std::endl;
  v1 = v1[seq(3,0)];
  std::cout <<"v1 = v1[seq(3,0)]=" << v1<<std::endl;


  return 0;
}
