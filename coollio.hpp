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




#ifndef COOLLIO_H
#define COOLLIO_H


#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

namespace COOLL {





  /* "save"
   * works for any objects that overload the << operator
   */

  template <class X>
  bool save(X& x, std::string fname,  unsigned int precision, std::ios_base::fmtflags flags) {
    std::ofstream out(fname.data(),std::ios::out);
    
    if (!out) {
      cant_open_file(fname);
      return 1;
    }
    
    out.flags(flags);
    out.precision(precision);
  
    out << x;
    out.close();
  
    return 0;
  }

  template <class X>
  bool save(X& x, std::string fname, std::ios_base::fmtflags flags, unsigned int precision) {
    return save(x,fname,flags,precision);
  }

  template <class X>
  bool save(X& x, std::string fname,  unsigned int precision = 16) {
    std::ios_base::fmtflags flags = std::ios_base::fmtflags();
    return save(x,fname,precision,flags);
  }

  template <class X>
  bool save(X& x, std::string fname, std::ios_base::fmtflags flags ) {
    return save(x,fname,16,flags);
  }
 



  // load  

  template <class X>
  bool load(X& x, std::string fname) {
    std::ifstream in(fname.data(),std::ios::in);
    if (!in) {
      cant_open_file(fname);
      return 1;
    }

    x.clear();
    in >> x;
    in.close();
    
    return 0;
  }


};


#endif

