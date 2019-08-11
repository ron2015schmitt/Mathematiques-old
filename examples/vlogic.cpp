
// flag for run-time bounds and size checking
#define MATRICKS_CAREFUL


#include "matricks.hpp"
using namespace Matricks;

#include <iostream>
using namespace std;





int main()
{

  LAvector<double> v1(4,"v1");

  cout << "initialize v1" << endl;
  v1 = range<double>(1,4);
  cout << v1 << endl<<endl;

  cout << "test v1==1 and store in q1" << endl;
  LAvector<bool> q1(4,"q1");
  q1 = (v1==1);
  cout <<"q1="<< q1;
  // the "boolalpha" flag allows display of boolean value as true/false
  cout <<boolalpha;
  // redisplay q1
  cout <<"="<< q1 << endl<<endl;

  cout << "test v1>=3 and store in q1" << endl;
  q1 = (v1>=3);
  cout <<"q1="<< q1<<endl<<endl;

  cout << "initialize v2" << endl;
  LAvector<double> v2(4,"v2");
  double data[4] = {-3.0, 0, 3.0, 10};
  v2 = vcast<double>(data,4);
  cout << v2 << endl<<endl;

  cout << "test v1==v2 and store in q2" << endl;
  LAvector<bool> q2(4,"q2");
  q2 = (v1==v2);
  cout <<"q2="<< q2<<endl<<endl;

  cout << "logical OR: q3 = q1 || q2" << endl;
  LAvector<bool> q3(4,"q3");
  q3 = (q1||q2);
  cout <<"q3="<< q3<<endl<<endl;

  cout << "logical AND: q3 = q1 && q2" << endl;
  q3 = (q1&&q2);
  cout <<"q3="<< q3<<endl<<endl;

  cout << "logical NOT: q3 = !q1" << endl;
  q3 = !q1;
  cout <<"q3="<< q3<<endl<<endl;


  cout << "count the number of true results in a boolean vector: n=numtrue(q1)" << endl;
  int n = numtrue(q3);
  cout <<"n="<< n<<endl<<endl;

  cout << "find the indices of the true results: j1=findtrue(q1)" << endl;
  LAvector<uint> j1 = findtrue(q1);
  cout <<"j1="<< j1 <<endl<<endl;

  cout << "determine if ANY values in a vector are zero: " << endl;
  bool Q = anytrue(v1==0);
  cout <<"Q=anytrue(v1==0) = "<< Q <<endl<<endl;
  Q = anytrue(v2==0);
  cout <<"Q=anytrue(v2==0) = "<< Q <<endl<<endl;

  cout << "determine if ALL values in a vector are positive: " << endl;
  Q = alltrue(v1>0);
  cout <<"Q=alltrue(v1>0) = "<< Q <<endl<<endl;
  Q = alltrue(v2>0);
  cout <<"Q=alltrue(v2>0) = "<< Q <<endl<<endl;

  cout << "collect all the negative values in a vector: " << endl;
  LAvector<double> v4(0);
  v4.resize() = v1[v1<0];
  cout <<"v4.resize() = v1[v1<0] = "<< v4 <<endl<<endl;
  v4.resize() = v2[v2<0];
  cout <<"v4.resize() = v2[v2<0] = "<< v4 <<endl<<endl;


  return 0;
}
