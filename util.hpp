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




#ifndef COOLLUTIL_H
#define COOLLUTIL_H


#include <iostream>
#include <ctime>
#include <cstring>

namespace COOLL {


 
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




