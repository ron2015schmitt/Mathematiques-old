
//#define MATRICKS_DEBUG


#import <sys/types.h>
#import <unistd.h>

#import <vector>
#import <iostream>
#import <cstdio>





// COMPILEOPTS MACRO SHOULD BE DEFINED AT COMPILE TIME by call to g++ using -D option
char compile_opts[] = COMPILEOPTS;



// START: NUMERICAL LIBRARY SPECIFIC STUFF 
#import "cooll.hpp"
using namespace COOLL;
typedef Vector<double> VectorT;
char mathlib[] = "cooll";
// END: NUMERICAL LIBRARY SPECIFIC STUFF


using namespace std;


const int N = 10000000;
double tdata[N];

int main()
{

  double* temp1 = new double[N];

  Timer tfull, t;
  cout << "-------------------------------------------------------"<<endl;
  // execl("/bin/date","date", NULL);
  cout << endl << "LIBRARY TESTED = "<< mathlib << endl;
  cout << "g++ compiler options used = " << compile_opts << endl<<endl;
  cout << "-------------------------------------------------------"<<endl;
  cout << "MACHINE DETAILS" <<endl;
  //    execl("/bin/hostname","hostname", NULL);
  // execl("/bin/uname","uname","-a", NULL);
  //  execl("","","", NULL);
  cout << "-------------------------------------------------------"<<endl;

  tfull.start_timer();
  
  VectorT v1(N);
  VectorT v2(N);
  VectorT v3(N);

  printf("fill dynamic array, size= %d\n",N);
  t.start_timer_verbose();
  for(int i=0; i<N; i++)
      temp1[i] = 3.14;
  t.stop_timer_verbose();

  printf("fill static array, size= %d\n",N);
  t.start_timer_verbose();
  for(int i=0; i<N; i++)
      tdata[i] = 3.14;
  t.stop_timer_verbose();

  printf("fill STL vector, size= %d\n",N);
  t.start_timer_verbose();
  vector<double> vstl(N);
  for(int i=0; i<N; i++)
      vstl[i] = 3.14;
  t.stop_timer_verbose();

  cout << "-------------------------------------------------------"<<endl;

  printf("fill math vector, size= %d\n",N);
  t.start_timer_verbose();
  for(int i=0; i<N; i++)
      v1[i] = 3.14;
  t.stop_timer_verbose();

  printf("fill math vector, size= %d\n",N);
  t.start_timer_verbose();
  for(int i=N; i--;)
      v2[i] = 2.73;
  t.stop_timer_verbose();


  printf("v3 = v1 + v2, size= %d\n",N);
  t.start_timer_verbose();
  v3 = v1 + v2;
  t.stop_timer_verbose();
  
  printf("v3 = 1.4*v1 + 5.0*v2, size= %d\n",N);
  t.start_timer_verbose();
  v3 = 1.4*v1 + 5.0*v2;
  t.stop_timer_verbose();

  printf("v3 = 1.4*v1 + 5.0*v2 + v1/(v1 +v2), size= %d\n",N);
  t.start_timer_verbose();
  v3 = 1.4*v1 + 5.0*v2 + v1/(v1+v2);
  t.stop_timer_verbose();
  

  VectorT v4(N);
  printf("v4 = v3, size= %d\n",N);
    t.start_timer_verbose();
     
  v4=v3;
    t.stop_timer_verbose();
    
  
  /*
  printf("v3 = sin(v1) + cos(v2), size= %d\n",N);
  t.start_timer_verbose();
  v3 = sin(v1) + cos(v2);
  t.stop_timer_verbose();

  printf("v3 = sin(3.0*v1) + cos(4.0*v2) + v1, size= %d\n",N);
  t.start_timer_verbose();
  v3 = sin(3.0*v1) + cos(4.0*v2) + v1;
  t.stop_timer_verbose();
*/


  tfull.stop_timer();
  cout << endl;
  printf("TOTAL TIME ELAPSED = %f sec\n",tfull.cputime());
  cout << endl;
  cout << "-------------------------------------------------------"<<endl;

  return 0;
}
