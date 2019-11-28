
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





int main(int argc, char *argv[])
{

  const double pi = M_PI;
  std::string myname = argv[0];

  using namespace std;
  using namespace matricks;
  using namespace display;
  using namespace matricks::unit_imaginary;

  Style bold = createStyle(BOLD);
  
  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  cr();
  cr();
  mout << StyledString::get(HORLINE);
  mout << "running: " <<bold.apply(myname) << std::endl;

  
  mout<< "MATRICKS_DEBUG=" << MATRICKS_DEBUG << std::endl;
  
  print_matricks_info();



  Timer tfull, t;

  tfull.start_timer_verbose();
  cr();


  {
    const int N1 = 2;
    const int N2 = 3;



    cr();
    mout << "" << createStyle(BOLD).apply("Vector<Vector<double>> + Vector<Vector<double>>") << ", N1="<<N1<< ", N2="<<N2<<std::endl;
    
    mout << "  " << createStyle(BLUE2+BOLD).apply("matricks::Vector") <<std::endl;
    Vector<Vector<double>> v1(N1);
    Vector<Vector<double>> v2(N1);
    Vector<Vector<double>> v3(N1);
    Vector<Vector<double>> v4(N1);
    for (int i = 0; i < N1; i++) {
      v1[i].resize(N2);
      v2[i].resize(N2);
      v3[i].resize(N2);
      v4[i].resize(N2);
    }
    v1[0][0] = 0.01;
    v1[0][1] = 0.02;
    v1[0][2] = 0.03;
    v1[1][0] = 1.;
    v1[1][1] = 2.;
    v1[1][2] = 3.;

    v2[0][0] = 10;
    v2[0][1] = 20;
    v2[0][2] = 30;
    v2[1][0] = 100;
    v2[1][1] = 200;
    v2[1][2] = 300;

    tdisp(v1);
    tdisp(v2);

    // not working
    mout << std::endl;
    mout << "Recursive add (add1)" << std::endl;
    v3[0][0] = -1;
    v3[0][1] = -1;
    v3[0][2] = -1;
    v3[1][0] = -1;
    v3[1][1] = -1;
    v3[1][2] = -1;
    tdisp(v3);
    t.start_timer_silent();
    v3.equals1( add1(v1,v2) );
    t.stop_timer_curt();
    tdisp(v3);

    // working
    mout << std::endl;
    mout << "Deep add (add2)" << std::endl;
    t.start_timer_silent();
    v4.equals2( add2(v1,v2) );
    t.stop_timer_curt();
    tdisp(v4);

    
  }


    {
    const int N1 = 100000;
    const int n1 = 1000;
    const int N2 = 3;



    cr();
    mout << "" << createStyle(BOLD).apply("Vector<Vector<double>> + Vector<Vector<double>>") << ", N1="<<N1<< ", N2="<<N2<<std::endl;
    
    mout << "  " << createStyle(BLUE2+BOLD).apply("matricks::Vector") <<std::endl;
    Vector<Vector<double>> v1(N1);
    Vector<Vector<double>> v2(N1);
    Vector<Vector<double>> v3(N1);
    Vector<Vector<double>> v4(N1);
    for (int i = 0; i < N1; i++) {
      v1[i].resize(N2);
      v1[i][0] = 1;
      v1[i][1] = 2;
      v1[i][2] = 3;
      v2[i].resize(N2);
      v2[i][0] = i;
      v2[i][1] = i;
      v2[i][2] = i;
      v3[i].resize(N2);
      v4[i].resize(N2);
    }
    tdisp(v1[n1]);
    tdisp(v2[n1]);

    // not working
    mout << std::endl;
    mout << "Recursive add (add1)" << std::endl;
    t.start_timer_silent();
    v3.equals1( add1(v1,v2) );
    t.stop_timer_curt();
    tdisp(v3[n1]);

    // working
    mout << std::endl;
    mout << "Deep add (add2)" << std::endl;
    t.start_timer_silent();
    v4.equals2( add2(v1,v2) );
    t.stop_timer_curt();
    tdisp(v4[n1]);

    
  }



  tfull.stop_timer_silent();
  cr();
  printf("TOTAL TIME ELAPSED (including text display) = %f sec\n",tfull.cputime());
  cr();
  mout << StyledString::get(HORLINE);cr();
  //------------------------------------------------------
  
  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  
  return 0;
}
