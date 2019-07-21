
// flag for run-time bounds and size checking
 


#include "cooll.hpp"
using namespace COOLL;

#include "testlib.hpp"

#include <iostream>
using namespace std;


#include <vector>


int main()
{

  typedef complex<double> cd;


  LAvector<LAvector<double> > v1(2,"v1");
  for(unsigned int i = 0; i<v1.size(); i++)
    v1[i].resize(3);
  "{{0.1,0.2,0.3},{0.4,0.5,0.6}}" >> v1;
  double ans1[] = {0.1,0.2,0.3,0.4,0.5,0.6};
  vcompare2d(v1,ans1);

  v1[0][2]=25.0;
 
  LAvector<LAvector<double> > v2;
  v2.resize(2);
  for(unsigned int i = 0; i<v2.size(); i++)
    v2[i].resize(3);
  v2=v1;  
  double ans2[] = {0.1,0.2,25.0,0.4,0.5,0.6};
  vcompare2d(v2,ans2);


  LAvector<LAvector<double> > v2b=v1;
  double ans2b[] = {0.1,0.2,25.0,0.4,0.5,0.6};
  vcompare2d(v2b,ans2b);

  v2b.clear();
  v2b = v1;
  double ans2c[] = {0.1,0.2,25.0,0.4,0.5,0.6};
  vcompare2d(v2b,ans2c);

  v2b.clear();
  v2b = v1*v1;
  double ans2d[] = {0.1*0.1, 0.2*0.2, 25.0*25.0, 0.4*0.4, 0.5*0.5, 0.6*0.6};
  vcompare2d(v2b,ans2d);

  LAvector<LAvector<double> > v2c = v1+v1;
  double ans2e[] = {0.1+0.1, 0.2+0.2, 25.0+25.0, 0.4+0.4, 0.5+0.5, 0.6+0.6};
  vcompare2d(v2c,ans2e);

  "{{1,2,3},{4,5,6}}" >> v2;
  double ans3[] = {1.0,2.0,3.0,4.0,5.0,6.0};
  vcompare2d(v2,ans3);


  v2.clear();
  "{{1,2,3},{4,5,6}}" >> v2;
  double ans3b[] = {1.0,2.0,3.0,4.0,5.0,6.0};
  vcompare2d(v2,ans3b);

  LAvector<LAvector<double> > v3(2,"v3");
  for(unsigned int i = 0; i<v3.size(); i++)
    v3[i].resize(3);
  v3=v1 +v2;
  double ans4[] = {1.0+0.1, 2.0+0.2, 3.0+25.0, 4.0+0.4, 5.0+0.5, 6.0+0.6};
  vcompare2d(v3,ans4);


  v3[0]=v1[1];
  double ans5[] = {0.4, 0.5, 0.6, 4.0+0.4, 5.0+0.5, 6.0+0.6};
  vcompare2d(v3,ans5);
                                                                                
  v3[0]=1.0;
  v3[1]=-1.0;
  double ans6[] = {1.0,1.0,1.0,-1.0,-1.0,-1.0};
  vcompare2d(v3,ans6);

  
  LAvector<LAvector<p3vector<std::complex<double> > > > v4(2,"v4");
  for(unsigned int i = 0; i<v4.size(); i++)
    v4[i].resize(2);
  "{ {{(1,10),(2,20),(3,30)},{(4,40),(5,50),(6,60)}}, {{(7,70),(8,80),(9,90)},{(10,100),(11,110),(12,120)}} }" >> v4;
  cd ans10[] = { cd(1.0,10.0), cd(2.0,20.0), cd(3.0,30.0), cd(4.0,40.0), cd(5.0,50.0), cd(6.0,60.0), 
		 cd(7.0,70.0), cd(8.0,80.0), cd(9.0,90.0), cd(10.0,100.0), cd(11.0,110.0), cd(12.0,120.0) };
  vcompare3d(v4,ans10);

  LAvector<LAvector<p3vector<double> > > v5(2,"v5");
  for(unsigned int i = 0; i<v5.size(); i++)
    v5[i].resize(2);
  "{ {{0.1,0.2,0.3},{0.4,0.5,0.6}}, {{0.7,0.8,0.9},{0.01,0.011,0.012}} }" >> v5;
  double ans11[]={ 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.01, 0.011, 0.012 };
  vcompare3d(v5,ans11);

  cout << "<Basic multivector tests passed>"<<endl;
  return 0;



}
