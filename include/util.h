
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


  /****************************************************************************
   * std::vector related functions
   **************************************************************************** 
   */
    template <typename T>
    std::vector<T> mergeVectors(const std::vector<T> v1, const std::vector<T> v2) {
    std::vector<T> v3 = v1;
    v3.insert( v3.end(), v2.begin(), v2.end() );
    return v3;
  }

  template <typename T>
    std::vector<T> createVector(const T x) {
    std::vector<T> v1;
    v1.push_back(x);
    return v1;
  }


  /**********************************************************************
   *  VectorofPtrs
   ********************************************************************** 
   */

  class VectorofPtrs {

  public:
    std::vector<const void*> myaddrs;


    VectorofPtrs() {
    }
    VectorofPtrs(const void* addr) {
      addAddress(addr);
    }
    VectorofPtrs(const std::vector<const void*> addrs) {
      addAddresses(addrs);
    }
    
    
    std::vector<const void*> getAddresses(void) const {
      std::vector<const void*> vec;
      for (std::vector<const void*>::const_iterator  it = myaddrs.begin() ; it != myaddrs.end(); ++it) {
	vec.push_back(*it);
      }
      return vec;
    }

    bool checkAddresses(const std::vector<const void*> addrs) const {
      for (size_type i = 0; i < addrs.size(); i++){
	const void* addr = addrs[i];
	if ( std::find(myaddrs.begin(), myaddrs.end(), addr) != myaddrs.end() ) {
	  return true;
	}
      }
      return false;
    }

    void addAddress(const void* addr) {
      myaddrs.push_back(addr);
    }

    void addAddresses(const std::vector<const void*> addrs) {
      myaddrs.insert(myaddrs.end(), addrs.begin(), addrs.end());
    }
    
  };

    
  inline std::istream& restore_stream(std::istream& tostream, std::istream& fromstream) {
    std::string s="";
    char c;
    while(fromstream.get(c)) 
      s += c;
    
    size_t len = s.length();
    if (len >0) {
      if (tostream.eof())
	tostream.clear();
      std::ostringstream tempstrm;
      tempstrm<<std::endl;
      tostream.putback(tempstrm.str()[0]);
      for (size_t i = len;i>0; i--) 
	tostream.putback(s[i-1]);
    }
    return tostream;
  }



  /************************************************************************
   * Class type querying/manipulation
   ************************************************************************      */
  template <typename T> class GetDataType {
  public:
    typedef T Type;
  };
  template <typename D> class GetDataType<std::complex<D> > {
  public:
    typedef D Type;
  };
  template <typename D> class GetDataType<Vector<D> > {
  public:
    typedef Vector<typename GetDataType<D>::Type> Type;
  };
  template <typename D> class GetDataType<Matrix<D> > {
  public:
    typedef Matrix<typename GetDataType<D>::Type> Type;
  };




};


#endif




