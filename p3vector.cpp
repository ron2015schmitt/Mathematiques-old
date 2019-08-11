// START-OF-NOTICE
// Copyright 2003, Columbia University
// Authors: Ron Schmitt
//
//
// This file is part of the Columbia Object Oriented 
// Linear-algebra Library (COOLL).
//
// You should have received a copy of the License Agreement for the
// COOLL along with the software;  see the file LICENSE.  
// If not, contact
// Department of Applied Physics and Applied Mathematics
// Columbia Univeristy 
// New York, NY 10027
//
// Permission to modify the code and to distribute modified code is
// granted, provided the text of this NOTICE is retained, a notice that
// the code was modified is included with the above COPYRIGHT NOTICE and
// with the COPYRIGHT NOTICE in the LICENSE file, and that the LICENSE
// file is distributed with the modified code.
//
// LICENSOR MAKES NO REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED.
// By way of example, but not limitation, Licensor MAKES NO
// REPRESENTATIONS OR WARRANTIES OF MERCHANTABILITY OR FITNESS FOR ANY
// PARTICULAR PURPOSE OR THAT THE USE OF THE LICENSED SOFTWARE COMPONENTS
// OR DOCUMENTATION WILL NOT INFRINGE ANY PATENTS, COPYRIGHTS, TRADEMARKS
// OR OTHER RIGHTS.
//
// END-OF-NOTICE
//===========================================================================




//#define COOLL_CAREFUL
#include "coollcommon.hpp"
#include "p3vector.hpp"




namespace COOLL {

  


  // p3vector static variables
  TextFormat p3vectorformat::textformat_=text_braces;
  unsigned int p3vectorformat::width_;  

  TextFormat p3vectorformat::textformat(void) {
    return textformat_;
  }
  
  TextFormat p3vectorformat::textformat(const TextFormat newformat) {
    return textformat_ = newformat;
  }
  
  unsigned int  p3vectorformat::width(void) {
    return width_;
  }
  unsigned int  p3vectorformat::width(const unsigned int newwidth){
    return width_ = newwidth;
  }




};

