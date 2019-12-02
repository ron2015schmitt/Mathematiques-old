#define MATHQ_DEBUG 1
#include "mathq.h"
//  functor in C++ sense: a class that wraps a function
//
// Use non-template base classes for the debug code and place in cpp file.
//        this speeds up compile time tremendously.
//
// For same reason we'll let the expressions print out the <D> portion
// of the classname since they have to do such work anyway



namespace mathq {


  display::Style functor_namestyle = createStyle(display::ORANGE2);
  display::Style functor_style = createStyle(display::BOLD);
  display::Style userfunctor_style = createStyle(display::BOLD+display::BLUE1);

   
  
};

