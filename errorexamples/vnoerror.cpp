
#include <iostream>

#define COOLL_CAREFUL


#include "cooll.hpp"

using namespace COOLL;

using namespace std;


int main()
{
  const int N = 7;

 

 
  LAvector<double> v1(N);
  LAvector<double> v2(N);
  LAvector<double> v3(N);

  // should not generate any errors

  for(int i=0; i<N; i++)
      v1[i] = 3.14159265*double(i);
  dispcr(v1);

  for(int i=N; i--;)
      v2[i] = 1000.0 + i*100.0;
  dispcr(v2);



  dispcr(v3 = v1 + v2);

  dispcr(v3 = v1 + 100.0);
  

  dispcr(v3 = 2.0*v1);


  dispcr(v3 = v3 - v1*3.0);

  LAvector<double> v4(N);
       
  dispcr(v4=(v1 + v2)/3.0);
  dispcr(v4=+v3);
  dispcr(v4=-v3);

  dispcr(v4=sin(v3/4.0));
  dispcr(v4=cos(v3/4.0));

  std::vector<double> stdv(N);
  for(int i=0; i<N; i++)
      stdv[i] = double(i+1);
    
  dispcr(v4=vcast<double>(stdv));

  for(int i=N; i--;)
      v1[i] = double(i);
  dispcr(v1);

  dispcr(v3=pow(v1,2.0));
  dispcr(v3=pow(2.0,v1));
  dispcr(v3=pow(v2,v1));

  double d = 0;
  dispcr(d=(v1|v2));
  dispcr(d=(v1|2.0*v2+v1));
  dispcr(d=sum(v1));
  dispcr(d=norm(v1));
  dispcr(d=max(v1));
  dispcr(d=min(v1));

  dispcr(v1);
  LAvector<bool> q(N,"q");
  q[1] = true;
  dispcr(q);
  dispcr(q=(v1==v1));
  dispcr(q=(v1==(2.0*v1)));
  dispcr(q=(v1==(v1+v1-v1)));
  dispcr(q= (v1==3.0) );
  dispcr(q= (v1==v1[5]) );
  v2=v1;
  v2[0] = -9.0;
  v2[2] = -9.0;
  v2[4] = -9.0;
  v2[6] = -9.0;
  dispcr(v2);
  dispcr(q= (v1==v2) );

  bool Q;
  dispcr(Q= anytrue(v1==v2));
  dispcr(Q= alltrue(v1==v1));  
  dispcr(Q= alltrue(v1==v2));
  dispcr(Q= anytrue(v1==0.0));
  unsigned int n;
  dispcr(n=numtrue(v1==v2));
  dispcr(n=numtrue(v1>=1.0));
  
  dispcr(v1);
  LAvector<unsigned int> i(0);
  i.resize() = findtrue(v1>3.0);
  uint sz;
  dispcr(sz=i.size());
  


  LAvector<double> v7(4);

  dispcr(v7 = v1[seq(2,5)]);
  


  v3 = v1+v3;
  cout <<"v3=v1+v3="<< v3 << endl;


  LAvector<complex<double> > vc1(N);
  vc1 = complex<double>(0,1)*v1;
  cout <<"vc1=i*v1="<< vc1 << endl;
  vc1 = v1*complex<double>(0,1);
  cout <<"vc1=v1*i="<< vc1 << endl;
  vc1 = complex<double>(0,1)*vc1;
  cout <<"vc1=i*vc1="<< vc1 << endl;
  vc1 = vc1*complex<double>(0,1);
  cout <<"vc1=vc1*i="<< vc1 << endl;


  return 0;
}
