
#ifndef UTIL_H
#define UTIL_H



namespace matricks {



  //***********************************************************************
  //      Time related
  //***********************************************************************

 
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
      mout << "  The start time is: " << ctime(&tm1_);
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
      mout << "  Finished at: " << ctime(&tm2_);
      mout << "  CPU time = " << cputime_ << " sec" << std::endl;
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



  
  /****************************************************************************
   * math
   **************************************************************************** 
   */

  // GCD
  inline int gcd(int a, int b) {
    int r;
    do {
      r = a % b;
      a = b;
      b = r;
    } while (r != 0);
    
    return a;
  }
  
  // complex conjugate
  template <typename D> std::complex<D>
  operator~(const std::complex<D>& x) {
    return std::complex<D>(x.real(), -x.imag());
  }



  // complex rounding
  template <typename D> std::complex<D> round(const std::complex<D>& x) {
    return std::complex<D>(std::round(x.real()), std::round(x.imag()));
  }

  template <typename D> D roundzero(const D& x, const D tolerance) {
    return (std::abs(x) < std::abs(tolerance) ? 0 : x);
  }
  template <typename D> std::complex<D> roundzero(const std::complex<D>& x, const D tolerance) {
    return std::complex<D>(roundzero(x.real(),tolerance), roundzero(x.imag(),tolerance));
  }
  

  //***********************************************************************
  //       sgn(x) function
  //***********************************************************************
  
#define SGN_MACRO(D)  inline D sgn(const D x) {if (x>0) return static_cast<D>(1); else if (x<0) return static_cast<D>(-1); else return static_cast<D>(0);}
#define SGN_MACRO_US(D)  inline D sgn(const D x) {if (x>0) return static_cast<D>(1);else return static_cast<D>(0);}

  SGN_MACRO(float);
  SGN_MACRO(double);
  SGN_MACRO(long double);
  SGN_MACRO(char);
  SGN_MACRO_US(unsigned char);
  SGN_MACRO(short);
  SGN_MACRO_US(unsigned short);
  SGN_MACRO(int);
  SGN_MACRO_US(unsigned int);
  SGN_MACRO(long);
  SGN_MACRO_US(unsigned long);
#if LONGLONG_EXISTS
  SGN_MACRO(long long);
  SGN_MACRO_US(unsigned long long);
#endif


  /****************************************************************************
   * tolerances
   **************************************************************************** 
   */

  template <typename D> struct MatricksHelper {
  public:
    static D tolerance = D(0);
  };
  template <> struct MatricksHelper<double> {
  public:
    constexpr static double tolerance = 1.5e-16;
  };
  template <> struct MatricksHelper<float> {
  public:
    constexpr static float tolerance = 3.5e-7;
  };


  

};


#endif




