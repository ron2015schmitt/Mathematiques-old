
//#define COOLL_CAREFUL


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
typedef LAvector<double> VectorT;
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
    
  

  printf("v3 = sin(v1) + cos(v2), size= %d\n",N);
  t.start_timer_verbose();
  v3 = sin(v1) + cos(v2);
  t.stop_timer_verbose();

  printf("v3 = sin(3.0*v1) + cos(4.0*v2) + v1, size= %d\n",N);
  t.start_timer_verbose();
  v3 = sin(3.0*v1) + cos(4.0*v2) + v1;
  t.stop_timer_verbose();

  printf("v3 = 25.1*exp(v1), size= %d\n",N);
  t.start_timer_verbose();
  v3 = 25.1*exp(v1);
  t.stop_timer_verbose();


  printf("v3 = 25.1*exp(v1), size= %d\n",N);
  t.start_timer_verbose();
  v3 = 25.1*exp(v1);
  t.stop_timer_verbose();

  // Matrices

  const int NR = 3000;
  const int NC = 3000;
  const int NN = NR*NC;

  printf("allocate matrix, size= %dx%d=%d\n",NR,NC,NN);
  t.start_timer_verbose();
  Matrix<double> M1(NR,NC);
  t.stop_timer_verbose();


  printf("fill math matrix, size= %dx%d=%d\n",NR,NC,NN);
  t.start_timer_verbose();
  for(int i=0; i<NN; i++)
      M1(i) = 3.14;
  t.stop_timer_verbose();

  printf("allocate matrix and fill math matrix, size= %dx%d=%d\n",NR,NC,NN);
  t.start_timer_verbose();
  Matrix<double> M2(NR,NC);
  for(int i=0; i<NN; i++)
      M2(i) = 21.1;
  t.stop_timer_verbose();


  Matrix<double> M3(NR,NC);
  printf("M3 = M1 + M2, size= %dx%d=%d\n",NR,NC,NN);
  t.start_timer_verbose();
  M3 = M1 + M2;
  t.stop_timer_verbose();
  
  printf("M3 = 1.4*M1 + 5.0*M2, size= %dx%d=%d\n",NR,NC,NN);
  t.start_timer_verbose();
  M3 = 1.4*M1 + 5.0*M2;
  t.stop_timer_verbose();

  printf("M3 = 1.4*M1 + 5.0*M2 + M1/(M1 +M2), size= %dx%d=%d\n",NR,NC,NN);
  t.start_timer_verbose();
  M3 = 1.4*M1 + 5.0*M2 + M1/(M1+M2);
  t.stop_timer_verbose();
  

  printf("M3 = M1, size= %dx%d=%d\n",NR,NC,NN);
  t.start_timer_verbose();
  M3=M1;
  t.stop_timer_verbose();

  printf("M3 = ~(M1), size= %dx%d=%d\n",NR,NC,NN);
  t.start_timer_verbose();
  asm("RON1:");
  M3=~(M1);
  asm("RON1end:");
  t.stop_timer_verbose();

  const int NR2 = 400;
  const int NC2 = 400;
  const int NN2 = NR2*NC2;
  Matrix<double> M4(NR2,NC2);
  Matrix<double> M5(NR2,NC2);
  Matrix<double> M6(NR2,NC2);

  printf("fill math matrix, size= %dx%d=%d\n",NR2,NC2,NN2);
  t.start_timer_verbose();
  register int j =0;
  for(int r=0; r < NR2; r++) 
    for(int c=0; c < NC2; c++) 
      M4(j++) = 1000.0;
  t.stop_timer_verbose();

  printf("fill math matrix, size= %dx%d=%d\n",NR2,NC2,NN2);
  t.start_timer_verbose();
  for(int i=NN2; i--;)
      M5(i) = 81.1;
  t.stop_timer_verbose();


  printf("M6 = (M4|M5), size= %dx%d=%d\n",NR2,NC2,NN2);
  t.start_timer_verbose();
  M6=(M4|M5);
  t.stop_timer_verbose();

  printf("M6 = (M4|M4|M5), size= %dx%d=%d\n",NR2,NC2,NN2);
  t.start_timer_verbose();
  M4=M4|M4|M5;
  t.stop_timer_verbose();
    
  printf("M6 = (M4|M6), size= %dx%d=%d\n",NR2,NC2,NN2);
  t.start_timer_verbose();
  M6=M4|M6;
  t.stop_timer_verbose();

  VectorT v5(NR2);
  VectorT v6(NC2);
  printf("v5 = (M6|v6), size= %d\n",NR2);
  t.start_timer_verbose();
  v5=(M6|v6);
  t.stop_timer_verbose();


  tfull.stop_timer();
  cout << endl;
  printf("TOTAL TIME ELAPSED (including text display) = %f sec\n",tfull.cputime());
  cout << endl;
  cout << "-------------------------------------------------------"<<endl;

  return 0;
}
