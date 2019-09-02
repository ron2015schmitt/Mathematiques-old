
#ifndef MATRICKSUTIL_H
#define MATRICKSUTIL_H



namespace matricks {


 
  class Timer {
    time_t tm1_,tm2_;
    clock_t ckstart_, ckstop_, ckdiff_;
    double cputime_;  
    //  string name;
  public:
    void start_timer(void) {
      tm1_ = time(0);
      ckstart_ = clock();
    }
    void start_timer_verbose(void) {
      tm1_ = time(0);
      std::cout << "  The start time is: " << ctime(&tm1_);
      ckstart_ = clock();
    }
    void stop_timer(void) {
      ckstop_ = clock();
      tm2_ = time(0);
      cputime_ = double(ckstop_-ckstart_)/double(CLOCKS_PER_SEC);
    }
    void stop_timer_verbose(void) {
      ckstop_ = clock();
      tm2_ = time(0);
      ckdiff_ = ckstop_-ckstart_;
      cputime_ = double(ckstop_-ckstart_)/double(CLOCKS_PER_SEC);
      std::cout << "  Finished at: " << ctime(&tm2_);
      std::cout << "  CPU time = " << cputime_ << " sec" << std::endl;
    }

    double cputime(void)  {
      cputime_ = double(ckstop_-ckstart_)/double(CLOCKS_PER_SEC);
      return cputime_;
    }
    clock_t ckstart(void) const {
      return ckstart_;
    }
    clock_t ckstop(void) const {
      return ckstop_;
    }
    clock_t ckdiff(void) {
      ckdiff_ = ckstop_-ckstart_;
      return ckdiff_;
    }

  };



};


#endif




