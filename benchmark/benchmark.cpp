
//#define MATRICKS_DEBUG

#include "matricks.h" 

#include <fstream>

bool printCPUInfo () {
  using namespace std;
  ifstream file;
  file.open("/proc/cpuinfo", ifstream::in);

  if (!file.is_open()) {
    return false;
  }
  
  string label, value;
  map<string,string> mymap;
  while (std::getline(file, label, ':') && std::getline(file, value) ) {
    if (label.find("model name") != std::string::npos) {
      mymap[label] = value;
    } else if (label.find("cpu MHz") != std::string::npos) {
      mymap[label] = value;
    } else if (label.find("cache size") != std::string::npos) {
      mymap[label] = value;
    } 
  }
  file.close();

  map<string,string>::iterator it = mymap.begin();
  while (it != mymap.end()) {
    mout << it->first << "="<< it->second << std::endl;
    it++;
  }
      
  return true;
}


bool printMemInfo () {
  using namespace std;
  ifstream file;
  file.open("/proc/meminfo", ifstream::in);

  if (!file.is_open()) {
    return false;
  }
  
  string label, value;
  map<string,string> mymap;
  while (std::getline(file, label, ':') && std::getline(file, value) ) {
    if (label.find("MemTotal") != std::string::npos) {
      mymap[label] = value;
    } 
  }
  file.close();

  map<string,string>::iterator it = mymap.begin();
  while (it != mymap.end()) {
    mout << it->first << "="<< it->second << std::endl;
    it++;
  }
      
  return true;
}





int main()
{

  using namespace matricks;
  using namespace display;

  print_matricks_info();

  mout << createStyle(BLUE2+BOLD).apply("MACHINE INFO") << std::endl;
  printCPUInfo();
  printMemInfo();
  mout << StyledString::get(HORLINE);cr();




  Timer tfull, t;

  tfull.start_timer_verbose();
  cr();
  
  const int N = 2000000;
  const double pi = M_PI;


  mout << "" << createStyle(BOLD).apply("Fill with a constant value") << ", N="<<N<<std::endl;


  // In these two cases, storgae is reserved and filled at compile time,
  // so it doesn;t make sense to test. There is nothing to test.
  // {
  //   mout << "  " << createStyle(BLUE2+BOLD).apply("double[N]") <<std::endl;
  //   double tdata[N];
  //   t.start_timer_silent();
  //   for(int i=0; i<N; i++)
  //     tdata[i] = 3.14;
  //   t.stop_timer_curt();
  // }
  // {
  //   mout << "  " << createStyle(BLUE2+BOLD).apply("std::array")<<std::endl;
  //   std::array<double,N> v;
  //   t.start_timer_silent();
  //   for(int i=0; i<N; i++)
  //     v[i] = 3.14;
  //   t.stop_timer_curt();
  // }
  
  {
    mout << "  " << createStyle(BLUE2+BOLD).apply("new double[N]") <<std::endl;
    double* temp1 = new double[N];
    t.start_timer_silent();
    for(int i=0; i<N; i++)
      temp1[i] = 3.14;
    t.stop_timer_curt();
  }
  {
    mout << "  " << createStyle(BLUE2+BOLD).apply("std::vector") <<std::endl;
    std::vector<double> vstl(N);
    t.start_timer_silent();
    for(int i=0; i<N; i++)
      vstl[i] = 3.14;
    t.stop_timer_curt();
  }
  {
    mout << "  " << createStyle(BLUE2+BOLD).apply("std::valarray") <<std::endl;
    std::valarray<double> v(N);
    t.start_timer_silent();
    for(int i=0; i<N; i++)
      v[i] = 3.14;
    t.stop_timer_curt();
  }
  {
    mout << "  " << createStyle(BLUE2+BOLD).apply("matricks::Vector") <<std::endl;
    Vector<double> v1(N);
    t.start_timer_silent();
    for(int i=0; i<N; i++)
      v1[i] = 3.14;
    t.stop_timer_curt();
  }

  cr();
  mout << "" << createStyle(BOLD).apply("cos(2*pi + pi*sin(2*pi*x + pi/6))") << ", N="<<N<<std::endl;

  {
    mout << "  " << createStyle(BLUE2+BOLD).apply("std::valarray")<<std::endl;
    std::valarray<double> x(N);
    for(int i=0; i<N; i++)
      x[i] = double(i)/double(N-1);
    std::valarray<double> f(N);
    t.start_timer_silent();
    for(int i=0; i<N; i++)
      f[i] = cos(2*pi + pi*sin(2*pi*x[i] + pi/6));
    t.stop_timer_curt();
  }
  {
    mout << "  " << createStyle(BLUE2+BOLD).apply("matricks::Vector") <<std::endl;
    Vector<double> x(N);
    Vector<double> f(N);
    x = linspace<double>(0,1,N);
    t.start_timer_silent();
    f = cos(2*pi + pi*sin(2*pi*x + pi/6));
    t.stop_timer_curt();
  }



  tfull.stop_timer_silent();
  cr();
  printf("TOTAL TIME ELAPSED (including text display) = %f sec\n",tfull.cputime());
  cr();
  mout << StyledString::get(HORLINE);cr();
  
  return 0;
}
