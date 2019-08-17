
// flag for run-time bounds and size checking
#define MATRICKS_DEBUG


#include "matricks.hpp"
using namespace Matricks;

#include <iostream>
#include <iomanip>
using namespace std;





int main()
{
  
  const int N = 4;

  Vector<double> v1(N,"vec1");
  Vector<double> v2(N,"vec2");
  Vector<double> v3(N,"vec3");

  dispcr(v1);
  dispcr(v2);
  dispcr(v3);


  // intitiliaze a vector using a string
  "{1,2,3,4}">>v1;
  dispcr(v1);


  // once the vector is filled, the oepration ends
  "{100,200,300,400} {1,2,3,3,4,5,5,6,6}">>v1;
  dispcr(v1);


  // so you can initialize several vectors at once
  "{1,2,3,4} {5,6,7,8}{9,10,11,12}">>v1>>v2>>v3;
  dispcr(v1);
  dispcr(v2);
  dispcr(v3);

  // white space is irrelavent
  " {  -1, -2 ,   -3,  -4} \n{ 21 ,   22,\n23,24 }  ">>v1>>v2;
  dispcr(v1);
  dispcr(v2);


  // of course you can use any stream to intialize
  istringstream strm;
  strm.str("{11,12,13,14}");
  strm >> v1;
  dispcr(v1);


  // can input strings of numbers separated by white space "no braces or commas"
  v1.textformat(text_nobraces);
  "1 2.2 3.3 4.4">>v1;
  dispcr(v1);
  v1.textformat(text_braces);
  dispcr(v1);


  v1.textformat(text_nobraces);
  v2.textformat(text_nobraces);
  " -1  -2 -3 -4 56 57 58 59 100 101 ">>v1>>v2;
  dispcr(v1);
  dispcr(v2);
  

  // can also use streams from files; see examples in fileio.cpp




  return 0;
}
