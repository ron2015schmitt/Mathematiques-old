
// flag for run-time bounds and size checking
#define COOLL_CAREFUL


#import "cooll.hpp"
using namespace COOLL;

#import <iostream>
#import <iomanip>
using namespace std;





int main()
{
  
  Matrix<double> A1(2,2,"A1");
  "{ {10, 20},{ 30, 40}}">>A1;

  dispcr(A1);

  cout<<endl << "--Input matrix is of wrong size--"<<endl;
  "{{1,2},{3,4},{5,6}}">>A1;

  A1.textformat(text_nobraces);
  cout<<endl << "--not enough elements--"<<endl;
  "15.1 1">>A1;

  A1.textformat(text_nobraces);
  cout<<endl << "--braces received in 'no braces' mode--"<<endl;
  "{{1,2},{3,4}}">>A1;

  A1.textformat(text_nobraces);
  cout<<endl << "--bad character received--"<<endl;
  " 10 20 w 30 40">>A1;

  A1.textformat(text_nobraces);
  cout<<endl << "--bad character received in 2nd line--"<<endl;
  "1 2 4\n hello 5">>A1;


  A1.textformat(text_nobraces);
  A1.clear();
  cout<<endl << "--bad character received in 2nd line--"<<endl;
  "1 2 \n 4 saywhat 5">>A1;

  A1.resize(2,2);
  A1.textformat(text_braces);
  cout<<endl << "-- no opening brace in braces mode--"<<endl;
  "w{{1,2},{3,4}}">>A1;


  cout<<endl << "--bad character received in braces mode--"<<endl;
  "{{y 1,2},{3,4}}">>A1;

  cout<<endl << "--missing comma in braces mode--"<<endl;
  "{{1,2},{3 4}}">>A1;

  cout<<endl << "--bad charcter--"<<endl;
  "{{1,2},r{3,4}}">>A1;

  cout<<endl << "--bad character--"<<endl;
  "{s{1,2},{3,4}}">>A1;

  cout<<endl << "--bad character--"<<endl;
  "{{1,2},{3,4}dd}">>A1;

  cout<<endl << "--bad character--"<<endl;
  "{{1,2},{3 t,4}}">>A1;

  A1.clear();
  A1.textformat(text_braces);
  cout<<endl << "--number of colums varies--"<<endl;
  "{{1,2},{3,4},{8},{10,19}">>A1;

  A1.clear();
  A1.textformat(text_braces);
  cout<<endl << "--number of colums varies--"<<endl;
  "{{1,2},{3,4},{8,7},{3,10,19}">>A1;

  A1.resize(4,2);
  A1.textformat(text_braces);
  cout<<endl << "--number of colums varies--"<<endl;
  "{{1,2},{3,4},{8,7},{3,10,19}">>A1;

  A1.textformat(text_nobraces);
  A1.clear();
  cout<<endl << "--number of colums varies--"<<endl;
  "3 4\n 5 6\n 7 8 9\n 10 11\n">>A1;

  return 0;
}
