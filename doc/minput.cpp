
// flag for run-time bounds and size checking
#define MATRICKS_DEBUG 1


#include "matricks.hpp"
using namespace matricks;

#include <iostream>
#include <iomanip>
using namespace std;





int main()
{
  

  Matrix<double> A1(2,2,"A1");
  Matrix<double> A2(2,2,"A2");

  dispcr(A1);
  dispcr(A2);


  // intitiliaze a matrix using a string
  "{{1,2},{3,4}}">>A1;
  dispcr(A1);


  //  initialize several matrices at once
  "{{4,3},{2,1}}  {{3,-3},{-5,5}}">>A1>>A2;
  dispcr(A1);
  dispcr(A2);

  // white space is irrelavent
  "{{10,\n20  },{ 30 , 40 }  }">>A1;
  dispcr(A1);


  // input without braces: MUST PUT EACH ROW ON A SEPARATE LINE
  A1.textformat(text_nobraces);
  "1.1 1.2 \n 2.1 2.2">>A1;
  dispcr(A1);

  // input to a zero size matrix: matrix will change size to accomodate input
  A1.resize(0,0);
  A1.textformat(text_braces);
  "{{1,2},{3,4},{5,6}}">>A1;
  dispcr(A1);

  // nobraces and zero size causes input to continue until end of stream is reached
  A1.resize(0,0);
  A1.textformat(text_nobraces);
  "1.1 1.2 1.3\n 2.1 2.2 2.3">>A1;
  dispcr(A1);


  // can also use streams from files; see examples in fileio.cpp

  return 0;
}
