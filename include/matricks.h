

// Including this file provides full vector/matrix functionality


#ifndef MATRICKS_H
#define MATRICKS_H

#ifdef MEBUG
#define MATRICKS_DEBUG 1
#endif

#define DO_EXPAND(VAL)  99##VAL
#define EXPAND(VAL)     DO_EXPAND(VAL)

#ifndef MATRICKS_DEBUG
// not defined: set to 0
   #define MATRICKS_DEBUG 0
#elif (EXPAND(MATRICKS_DEBUG) == 99)
  // defined but no value: set to 1
  #undef MATRICKS_DEBUG
  #define MATRICKS_DEBUG 1
#elif (MATRICKS_DEBUG>3)
  // no modes defined above 3
  #undef MATRICKS_DEBUG
  #define MATRICKS_DEBUG 3
#endif

// -------------------------------------------
//     From loki submodule
#include "TypeTraits.h"
// -------------------------------------------


#include "matricks_version.h"
#include "util.hpp"
#include "matrickscommon.hpp"
#include "print.hpp"

#include "applicative.hpp"
#include "mathapp.hpp"
#include "boolapp.hpp"
#include "complexapp.hpp"
#include "verror.hpp"
#include "merror.hpp"
#include "vectordef.hpp"
#include "matrixdef.hpp"

#include "md.hpp"

#include "vexpressions.h"
#include "mexpr.hpp"
#include "mboolexpr.hpp"
#include "mcomplexexpr.hpp"
#include "mvexpr.hpp"

#include "voperators.hpp"
#include "vmathops.hpp"
#include "vboolops.hpp"
#include "vcomplexops.hpp"
#include "moperators.hpp"
#include "mmathops.hpp"
#include "mboolops.hpp"
#include "mcomplexops.hpp"
#include "mvoperators.hpp"
#include "mvcomplexops.hpp"

#include "p3vector.hpp"

#include "matricksio.hpp"
#include "matricksutil.hpp"


#endif
