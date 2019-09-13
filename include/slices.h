#ifndef MATRICKS__SLICES
#define MATRICKS__SLICES





namespace matricks {
  class slc {
  private:
    const index_type start_;
    const index_type end_;
    const index_type step_; 
  public:
    inline slc(const index_type start, const index_type end, const index_type step) 
      : start_(start), end_(end), step_(step)
    {
      printf3("slc::slc(start=%d, end=%d, step=%d)\n",start, end, step);
    }

    inline slc(const index_type start, const index_type end) 
      : start_(start), end_(end), step_(1)
      {
	printf3("slc::slc(start=%d, end=%d)\n",start, end);
      }
  

	

    inline index_type start(void) const {
      return start_;
    }
    inline index_type end(void) const {
      return end_;
    }
    inline index_type step(void) const {
      return step_;
    }

    // vector isn't defined yet, so just declare this here
    inline Vector<index_type>& toIndexVector(const size_type N) const;

    inline std::string expression() const {
      std::stringstream  ss;
      ss << *this;
      return ss.str();
    }


    friend std::ostream& operator<<(std::ostream &stream, const slc& slice) {
      using namespace display;
      Style name_style = createStyle(CYAN);
      Style punct_style = createStyle(GRAY1);
      Style num_style = createStyle(BOLD);
      stream << num_style.apply(num2string(slice.start()));
      stream << punct_style.apply(":");
      stream << num_style.apply(num2string(slice.end()));
      stream << punct_style.apply(":");
      stream << num_style.apply(num2string(slice.step()));
      return stream;
    }
  };
};





namespace SLC {
  const matricks::slc all(0,-1,1);
  const matricks::slc rev(-1,0,-1);
  const matricks::slc eve(0,-1,2);
  const matricks::slc odd(1,-1,2);
};

  
    



#endif
