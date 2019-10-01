#ifndef MATRICKS__SLICES_H
#define MATRICKS__SLICES_H


namespace matricks {



  class slc {
  private:
    const index_type start_;
    const index_type end_;
    const index_type step_; 
  public:
    slc(const index_type start, const index_type end, const index_type step);
    slc(const index_type start, const index_type end);
    index_type start(void) const;
    index_type end(void) const;
    index_type step(void) const;
    Vector<index_type>& toIndexVector(const size_type N) const;
    std::string expression() const;
    std::string classname() const;
    friend std::ostream& operator<<(std::ostream &stream, const slc& slice);
  };

  namespace SLC {
    const matricks::slc all(0,-1,1);
    const matricks::slc rev(-1,0,-1);
    const matricks::slc even(0,-1,2);
    const matricks::slc odd(1,-1,2);
  };

};


#endif
