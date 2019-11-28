
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

    // working
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

    // working
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

  {
    const int N1 = 3;
    const int n1 = 1;
    const int N2 = 100000;



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
    for (int j = 0; j < N2; j++) {
      v1[0][j] = 1;
      v1[1][j] = 2;
      v1[2][j] = 3;
      v2[0][j] = j;
      v2[1][j] = j;
      v2[2][j] = j;
    }
    mdisp(v1[0][100],v1[1][100],v1[2][100]);
    mdisp(v2[0][100],v2[1][100],v2[2][100]);

    
    // working
    mout << std::endl;
    mout << "Recursive add (add1)" << std::endl;
    t.start_timer_silent();
    v3.equals1( add1(v1,v2) );
    t.stop_timer_curt();
    mdisp(v3[0][100],v3[1][100],v3[2][100]);

    // working
    mout << std::endl;
    mout << "Deep add (add2)" << std::endl;
    t.start_timer_silent();
    v4.equals2( add2(v1,v2) );
    t.stop_timer_curt();
    mdisp(v4[0][100],v4[1][100],v4[2][100]);

    
  }




  
  {
    // fixed length Vectors
    mout << std::endl;
    mout << "Fixed Length Vectors" << std::endl;
    Vector<double,3> v1(5.);
    tdisp(v1);
    Vector< Vector<double,3>, 2>  v2 {{1.,2.,3.},{4.,5.,6.}};
    tdisp(v2);
  }


  {
    const int N1 = 100000;
    const int n1 = 1000;
    const int N2 = 3;


    // NOTE: We can't make the our vector fixed because then the executable size will be too big for the loader
    cr();
    mout << "" << createStyle(BOLD).apply("Vector<Vector<double,3>> + Vector<Vector<double,3>>") << ", N1="<<N1<< ", N2="<<N2<<std::endl;
    
    mout << "  " << createStyle(BLUE2+BOLD).apply("matricks::Vector") <<std::endl;
    Vector<Vector<double,N2>> v1;
    Vector<Vector<double,N2>> v2;
    Vector<Vector<double,N2>> v3;
    Vector<Vector<double,N2>> v4;
    v1.resize(N1);
    v2.resize(N1);
    v3.resize(N1);
    v4.resize(N1);
    for (int i = 0; i < N1; i++) {
      v1[i][0] = 1;
      v1[i][1] = 2;
      v1[i][2] = 3;
      v2[i][0] = i;
      v2[i][1] = i;
      v2[i][2] = i;
    }
    tdisp(v1[n1]);
    tdisp(v2[n1]);

    // working
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
