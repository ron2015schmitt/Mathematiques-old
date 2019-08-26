#define MATRICKS_DEBUG 1

#include "matricks.hpp"




namespace matricks {

  


  // p3vector static variables
  TextFormat p3vectorformat::textformat_=text_braces;
  size_type p3vectorformat::width_;  

  TextFormat p3vectorformat::textformat(void) {
    return textformat_;
  }
  
  TextFormat p3vectorformat::textformat(const TextFormat newformat) {
    return textformat_ = newformat;
  }
  
  size_type  p3vectorformat::width(void) {
    return width_;
  }
  size_type  p3vectorformat::width(const size_type newwidth){
    return width_ = newwidth;
  }




};

