
// flag for run-time bounds and size checking
#define COOLL_CAREFUL


#include "cooll.hpp"
using namespace COOLL;

#include <iostream>
#include <iomanip>
using namespace std;





int main()
{
  
  const int N = 4;

  LAvector<double> v1(N,"v1");
  "{10,20,30,40}">>v1;
  LAvector<double> v2(N,"v2");
  "{11,22,33,44}">>v2;

  dispcr(v1);
  dispcr(v2);

  cout<<endl << "--Input vector is of wrong size--"<<endl;
  "{1,2,3}">>v1;

  v1.textformat(text_nobraces);
  cout<<endl << "--not enough elements--"<<endl;
  "15.1 1">>v1;

  v1.textformat(text_nobraces);
  cout<<endl << "--braces received in 'no braces' mode--"<<endl;
  "{1,2,3,4}">>v1;

  v1.textformat(text_nobraces);
  cout<<endl << "--bad character received--"<<endl;
  "1 2 x 4 5">>v1;

  v1.textformat(text_nobraces);
  cout<<endl << "--bad character received in 2nd line--"<<endl;
  "1 2 4\n hello 5">>v1;


  v1.textformat(text_nobraces);
  v1.clear();
  cout<<endl << "--bad character received in 2nd line--"<<endl;
  "1 2 \n 4 saywhat 5">>v1;

  v1.resize(4);
  v1.textformat(text_braces);
  cout<<endl << "-- no opening brace in braces mode--"<<endl;
  "1{1,2,3,4}">>v1;


  cout<<endl << "--bad character received in braces mode--"<<endl;
  "{1,2,3,n4}">>v1;

  cout<<endl << "--missing comma in braces mode--"<<endl;
  "{1 2 3,4}">>v1;

  cout<<endl << "--bad charcter--"<<endl;
  "{w1, 2, 3,4}">>v1;

  cout<<endl << "--bad character--"<<endl;
  "{1, 2, 3,4 e}">>v1;


  return 0;
}
