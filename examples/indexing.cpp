#define MATRICKS_DEBUG 1
#include "matricks.h"

#include <vector>

#include "TypeTraits.h"
#include <string>




enum IndexType {IND_SIGNED,IND_UNSIGNED};
class Index {
public:
  int n_;
  unsigned int u_;
  IndexType type_;
  Index(unsigned int u) : n_(-9999), u_(u), type_(IND_UNSIGNED) {
  }
  Index(int n) : n_(n), u_(99999), type_(IND_SIGNED) {
  }
 
  
  inline std::string classname() const {
    return "Index";
  }

  inline IndexType getType() const {
    return type_;
  }
  inline unsigned int value(unsigned int N) const {
    switch (type_) {
    case IND_SIGNED:
      if (n_<0) {
	return N+n_;
      } else {
	return n_;
      }
    case IND_UNSIGNED:
      return u_;
    }      
  }    

  inline int getn() const {
    return n_;
  }
  inline unsigned int getu() const {
    return u_;
  }


  inline friend std::ostream& operator<<(std::ostream &stream, const Index& index) {
    using namespace display;

    switch (IndexType t = index.getType()) {
    case IND_SIGNED:
      stream << "IND_SIGNED ";
      dispval_strm(stream, index.getn());
      break;
    case IND_UNSIGNED:
      stream << "IND_UNSIGNED ";
      dispval_strm(stream, index.getu());
      break;
    }      
    return stream;
  }
};


class Holder {
private:
  std::valarray<double>* data_;
  
public:
  Holder()  {
    data_ = new std::valarray<double>(5); 
  }

      // "read/write": 
  double& operator[](const Index& index)  {
    return (*data_)[index.value(size())]; 
    }

    // "read only":
  const double& operator[](const Index& index) const {
    return (*data_)[index.value(size())]; 
    }

  inline int size() const {
    return data_->size();
  }
  
  inline std::string classname() const {
    return "Holder";
  }

    inline friend std::ostream& operator<<(std::ostream &stream, const Holder& h) {
      using namespace display;
      dispval_strm(stream, "(");
      for (int i = 0; i < h.size(); i++) {
	if (i>0) {
	  dispval_strm(stream, ", ");
	}
	dispval_strm(stream, h[i]);
      }
      dispval_strm(stream, ")");
      
      return stream;
    }
};




int main(int argc, char *argv[])
{


  
  const double pi = M_PI;
  std::string myname = argv[0];
  using namespace matricks;
  using namespace display;
  using namespace std;
  
  Style bold = createStyle(BOLD);
  
  // force color even if piped to more,less or a file
  Terminal::setColorOverride(true);
  Terminal::setOverrideValue(true);

  cr();
  cr();
  mout << StyledString::get(HORLINE);
  mout << "running: " <<bold.apply(myname) << std::endl;
  print_matricks_info();
  


  {
    Holder h;
    tdisp(h);

    Index ind(-1);
    tdisp(ind);
    h[ind] = 4.4;
    tdisp(h);

    Index ind2(1u);
    tdisp(ind2);
    h[ind2] = 1.1;
    tdisp(h);

    tdisp(2u);
    h[2u] = 2.2;
    tdisp(h);

    tdisp(-2);
    h[-2] = 3.3;
    tdisp(h);

  }




  
  cr();
  mout << "done: " << bold.apply(myname) << std::endl;
  mout << StyledString::get(HORLINE);
  cr();
  return 0;
}
